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
    print("Variant to family map (used in platform-atmelsam/builder/frameworks/cmsis.py):", invert_variants(family_variants))

if __name__=='__main__':
    package_atmelsam()

