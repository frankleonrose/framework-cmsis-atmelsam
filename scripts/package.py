import os
import re
import requests
from html.parser import HTMLParser
import zipfile
import tempfile
import functools
import glob, shutil

WORK_DIR = '.downloads'
LD_SCRIPT_DIR = "platformio/ldscripts/atmelsam"

MCU_FAMILY_SELECTORS = {
  'sam3a': r'^sam3a.*$',
  'sam3n': r'^sam3n.*$',
  'sam3s': r'^sam3s[^8]*$',
  'sam3sd8': r'^sam3sd?[8].?$',
  'sam3x': r'^sam3x.*$',
  'sam3u': r'^sam3u.*$',
  'sam3x': r'^(at91)?sam3x.*$',
  'sam4c32': r'^sam4c32.*$',
  'sam4cm32': r'^sam4cm.*32.*$',
  'sam4cm': r'^sam4cm[^3]*$',
  'sam4cp': r'^sam4cp.*$',
  'sam4c': r'^sam4c[^mp3]*$',
  'sam4e': r'^sam4e(.*[ce])?$',
  'sam4ecb': r'^sam4e\d+cb$',
  'sam4l4': r'^sam4l[cs][24][abc]$',
  'sam4l8': r'^sam4l[cs]8[abc]$',
  'sam4n': r'^sam4n.*$',
  'sam4sp': r'^sam4sp.*$',
  'sam4s': r'^sam4s[^p]*$',
  'samb11': r'^samb11$',
  'samc20': r'^samc20[^n]*$',
  'samc20n': r'^samc20n.*$',
  'samc21': r'^samc21[^n]*$',
  'samc21n': r'^samc21n.*$',
  'samd09': r'^samd09.*$',
  'samd10': r'^samd10.*$',
  'samd11': r'^samd11.*$',
  'samd20': r'^samd20[^b]*$',
  'samd21a': r'^samd21.1[5678].*au?$',
  'samd20b': r'^samd20.*b$',
  'samd21b': r'^samd21.*bu$',
  'samd21c': r'^samd21.1[56].*$',
  'samd21d': r'^samd21.17.*$',
  'samd51a': r'^samd51.*$',
  'samda1': r'^samda1.*a$',
  'samda1b': r'^samda1.*b$',
  'same51': r'^same51.*$',
  'same53': r'^same53.*$',
  'same54': r'^same54.*$',
  'same70a': r'^same70[^b]*$',
  'same70b': r'^same70.*b$',
  'samg51': r'^samg51.*$',
  'samg53': r'^samg53.*$',
  'samg54': r'^samg54.*$',
  'samg55': r'^samg55.*$',
  'samha1a': r'^samha1.*a$',
  'samha1ab': r'^samha1.*b$',
  'saml10': r'^saml10.*$',
  'saml11': r'^saml11.*$',
  'saml21a1': r'^saml21.*a$',
  'saml21b': r'^saml21.*bu?$',
  'saml22': r'^saml22.*$',
  'samr21': r'^samr21.*$',
  'samr30': r'^samr30.*$',
  'samr34': r'^samr34.*$',
  'samr35': r'^samr35.*$',
  'sams70a': r'^sams70[^b]+$',
  'sams70b': r'^sams70.*b$',
  'samv70': r'^samv70[^b]+$',
  'samv70b': r'^samv70.*b$',
  'samv71': r'^samv71[^b]+$',
  'samv71b': r'^samv71.*b$',
}

def get_mcu_family(mcu):
    mcu = mcu.lower()
    for variant_family, match in MCU_FAMILY_SELECTORS.items():
        if re.match(match, mcu):
            return variant_family

    return None

def download(url, filename):
    r = requests.get(url, allow_redirects=True)
    open(filename, 'wb').write(r.content)

def unzip(filename, directory):
    with zipfile.ZipFile(filename, 'r') as zip_ref:
        zip_ref.extractall(directory)

class PackParser(HTMLParser):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.packs = []

    def handle_starttag(self, tag, attrs):
        if tag=='button':
            try:
                pack = [pack for typ,pack in attrs if typ == "data-link"][0]
                if pack.startswith('Atmel.SAM'):
                    self.packs.append(pack)
            except:
                pass

def read_packs():
    response = requests.get('http://packs.download.atmel.com/')
    html = response.text
    # print(html)

    parser = PackParser()
    parser.feed(html)
    return parser.packs

def enrich(pack):
    "Convert Atmel.SAMXYZ_DFP.1.2.3.atpack into {family: 'samxyz', version: '1.2.3', sort_version: '001002003'}"
    # tokens = pack.split('.')
    m = re.search('Atmel\\.(SAM.+)_DFP\\.((\\d+)\\.(\\d+)\\.(\\d+))\\.atpack', pack)
    if m is None:
        return None
    def pad(x):
        return "00000"[:5-len(x)] + x
    return {
      'name': pack,
      'family': m.group(1),
      'version': m.group(2),
      'sort_version': f"{pad(m.group(3))}.{pad(m.group(4))}.{pad(m.group(5))}"
    }

def enrich_packs(packs):
    def enricher(packs, pack):
        enriched = enrich(pack)
        if enriched is not None:
            family = enriched['family']
            if family not in packs or enriched['sort_version'] > packs[family]['sort_version']:
                packs[family] = enriched
        return packs
    return functools.reduce(enricher, packs, {})

def move_files(pack_family, src_dir):
    print(f"Moving files for: {pack_family}")
    family_dir = os.path.join('variants', 'atmelsam', pack_family)
    os.makedirs(family_dir, exist_ok=True)

    dst = os.path.join(family_dir, 'include')
    shutil.rmtree(dst, ignore_errors=True)
    os.rename(os.path.join(src_dir, 'include'), dst)

    dst_source = os.path.join(family_dir, 'gcc')
    shutil.rmtree(dst_source, ignore_errors=True)
    os.makedirs(dst_source, exist_ok=True)
    for file in glob.glob(os.path.join(src_dir, 'gcc', '*.c')):
        shutil.move(file, dst_source)
    for file in glob.glob(os.path.join(src_dir, 'gcc', 'gcc', '*.c')):
        shutil.move(file, dst_source)

    variants = []
    for file in glob.glob(os.path.join(src_dir, 'gcc', '*.ld')):
        dst_name = os.path.join(LD_SCRIPT_DIR, os.path.basename(file))
        shutil.move(file, dst_name)
        if "_flash" in file:
            variants.append(os.path.basename(file).replace('_flash.ld', ''))
    for file in glob.glob(os.path.join(src_dir, 'gcc', 'gcc', '*.ld')):
        dst_name = os.path.join(LD_SCRIPT_DIR, os.path.basename(file))
        shutil.move(file, dst_name)
        if "_flash" in file:
            variants.append(os.path.basename(file).replace('_flash.ld', ''))
    return variants

def move_files_for_packs(pack_family, src_dir):
    "Handle some packs which have multiple families in subdirs and others with just one."
    family_variants = {}
    for family_dir in glob.glob(f"{src_dir}/sam*"):
        family_name = os.path.basename(family_dir)
        family_variants[family_name] = move_files(family_name, family_dir)
    for family_dir in glob.glob(f"{src_dir}/ic.sam*"):
        family_name = os.path.basename(family_dir)[3:]
        family_variants[family_name] = move_files(family_name, family_dir)
    if len(family_variants)==0:
        family_name = pack_family.lower()
        family_variants[family_name] = move_files(family_name, src_dir)
    # print(family_variants)
    return family_variants

def process_pack(pack, download_dir, temp_dir):
    print("Processing pack: ", pack['name'])
    url = 'http://packs.download.atmel.com/' + pack['name']
    filename = os.path.join(download_dir, pack['name'] + '.zip')
    if not os.path.exists(filename):
        download(url, filename)

    pack_dir = os.path.join(temp_dir, pack['name'])
    unzip(filename, pack_dir)
    return move_files_for_packs(pack['family'], pack_dir)

def invert_variants(family_variants):
    variant_to_family = {}
    for f, mcu_list in family_variants.items():
      for mcu in mcu_list:
        if mcu in variant_to_family:
          print("MCU '%s' appears in multiple families"  % mcu)
        variant_to_family[mcu] = f

    return variant_to_family

def check_variants(variant_to_family):
    """Ensure that map of family -> regexp (MCU_FAMILY_SELECTORS) correctly replicates
        map of mcu -> family (VARIANT_DIRS, generated by CMSIS downloader script.)"""
    err = False
    for mcu, family in variant_to_family.items():
        f = get_mcu_family(mcu)
        if family!=f:
            err = True
            print(f"Error: Failed to match family for: '{mcu}' -> '{f}' vs '{family}'")
    if err:
        print(f"Error: MCU_FAMILY_SELECTORS map needs to be updated to resolve errors above.\n"
                          "Please update it in https://github.com/platformio/platform-atmelsam/tree/develop/builder/frameworks/cmsis.py")

def package_atmelsam():
    os.makedirs(LD_SCRIPT_DIR, exist_ok=True)
    os.makedirs(WORK_DIR, exist_ok=True)

    print('Reading packs from Atemel site...')
    packs = read_packs()
    # print('Packs: ', packs)
    epacks = enrich_packs(packs)
    print(f"Processing {len(epacks)} packs...")

    family_variants = {}
    with tempfile.TemporaryDirectory() as temp_directory:
        # temp_directory = ".temporary"
        # os.makedirs(temp_directory, exist_ok=True)
        for family, pack in epacks.items():
            variants = process_pack(pack, WORK_DIR, temp_directory)
            family_variants.update(variants)

    check_variants(invert_variants(family_variants))

if __name__=='__main__':
    package_atmelsam()

