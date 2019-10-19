/* ---------------------------------------------------------------------------- */
/*                  Atmel Microcontroller Software Support                      */
/*                       SAM Software Package License                           */
/* ---------------------------------------------------------------------------- */
/* Copyright (c) %copyright_year%, Atmel Corporation                                        */
/*                                                                              */
/* All rights reserved.                                                         */
/*                                                                              */
/* Redistribution and use in source and binary forms, with or without           */
/* modification, are permitted provided that the following condition is met:    */
/*                                                                              */
/* - Redistributions of source code must retain the above copyright notice,     */
/* this list of conditions and the disclaimer below.                            */
/*                                                                              */
/* Atmel's name may not be used to endorse or promote products derived from     */
/* this software without specific prior written permission.                     */
/*                                                                              */
/* DISCLAIMER:  THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR   */
/* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE   */
/* DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,      */
/* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT */
/* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,  */
/* OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF    */
/* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING         */
/* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, */
/* EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                           */
/* ---------------------------------------------------------------------------- */

#ifndef _SAM4C_USBFS_INSTANCE_
#define _SAM4C_USBFS_INSTANCE_

/* ========== Register definition for USBFS peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
  #define REG_USBFS_DEVCTRL                         (0x40020000U) /**< \brief (USBFS) Device General Control Register */
  #define REG_USBFS_DEVISR                          (0x40020004U) /**< \brief (USBFS) Device Global Interrupt Status Register */
  #define REG_USBFS_DEVICR                          (0x40020008U) /**< \brief (USBFS) Device Global Interrupt Clear Register */
  #define REG_USBFS_DEVIFR                          (0x4002000CU) /**< \brief (USBFS) Device Global Interrupt Set Register */
  #define REG_USBFS_DEVIMR                          (0x40020010U) /**< \brief (USBFS) Device Global Interrupt Mask Register */
  #define REG_USBFS_DEVIDR                          (0x40020014U) /**< \brief (USBFS) Device Global Interrupt Disable Register */
  #define REG_USBFS_DEVIER                          (0x40020018U) /**< \brief (USBFS) Device Global Interrupt Enable Register */
  #define REG_USBFS_DEVEPT                          (0x4002001CU) /**< \brief (USBFS) Device Endpoint Register */
  #define REG_USBFS_DEVFNUM                         (0x40020020U) /**< \brief (USBFS) Device Frame Number Register */
  #define REG_USBFS_DEVEPTCFG                       (0x40020100U) /**< \brief (USBFS) Device Endpoint Configuration Register (n = 0) */
  #define REG_USBFS_DEVEPTISR                       (0x40020130U) /**< \brief (USBFS) Device Endpoint Status Register (n = 0) */
  #define REG_USBFS_DEVEPTICR                       (0x40020160U) /**< \brief (USBFS) Device Endpoint Clear Register (n = 0) */
  #define REG_USBFS_DEVEPTIFR                       (0x40020190U) /**< \brief (USBFS) Device Endpoint Set Register (n = 0) */
  #define REG_USBFS_DEVEPTIMR                       (0x400201C0U) /**< \brief (USBFS) Device Endpoint Mask Register (n = 0) */
  #define REG_USBFS_DEVEPTIER                       (0x400201F0U) /**< \brief (USBFS) Device Endpoint Enable Register (n = 0) */
  #define REG_USBFS_DEVEPTIDR                       (0x40020220U) /**< \brief (USBFS) Device Endpoint Disable Register (n = 0) */
  #define REG_USBFS_DEVDMANXTDSC1                   (0x40020310U) /**< \brief (USBFS) Device DMA Channel Next Descriptor Address Register (n = 1) */
  #define REG_USBFS_DEVDMAADDRESS1                  (0x40020314U) /**< \brief (USBFS) Device DMA Channel Address Register (n = 1) */
  #define REG_USBFS_DEVDMACONTROL1                  (0x40020318U) /**< \brief (USBFS) Device DMA Channel Control Register (n = 1) */
  #define REG_USBFS_DEVDMASTATUS1                   (0x4002031CU) /**< \brief (USBFS) Device DMA Channel Status Register (n = 1) */
  #define REG_USBFS_DEVDMANXTDSC2                   (0x40020320U) /**< \brief (USBFS) Device DMA Channel Next Descriptor Address Register (n = 2) */
  #define REG_USBFS_DEVDMAADDRESS2                  (0x40020324U) /**< \brief (USBFS) Device DMA Channel Address Register (n = 2) */
  #define REG_USBFS_DEVDMACONTROL2                  (0x40020328U) /**< \brief (USBFS) Device DMA Channel Control Register (n = 2) */
  #define REG_USBFS_DEVDMASTATUS2                   (0x4002032CU) /**< \brief (USBFS) Device DMA Channel Status Register (n = 2) */
  #define REG_USBFS_DEVDMANXTDSC3                   (0x40020330U) /**< \brief (USBFS) Device DMA Channel Next Descriptor Address Register (n = 3) */
  #define REG_USBFS_DEVDMAADDRESS3                  (0x40020334U) /**< \brief (USBFS) Device DMA Channel Address Register (n = 3) */
  #define REG_USBFS_DEVDMACONTROL3                  (0x40020338U) /**< \brief (USBFS) Device DMA Channel Control Register (n = 3) */
  #define REG_USBFS_DEVDMASTATUS3                   (0x4002033CU) /**< \brief (USBFS) Device DMA Channel Status Register (n = 3) */
  #define REG_USBFS_DEVDMANXTDSC4                   (0x40020340U) /**< \brief (USBFS) Device DMA Channel Next Descriptor Address Register (n = 4) */
  #define REG_USBFS_DEVDMAADDRESS4                  (0x40020344U) /**< \brief (USBFS) Device DMA Channel Address Register (n = 4) */
  #define REG_USBFS_DEVDMACONTROL4                  (0x40020348U) /**< \brief (USBFS) Device DMA Channel Control Register (n = 4) */
  #define REG_USBFS_DEVDMASTATUS4                   (0x4002034CU) /**< \brief (USBFS) Device DMA Channel Status Register (n = 4) */
  #define REG_USBFS_HSTCTRL                         (0x40020400U) /**< \brief (USBFS) Host General Control Register */
  #define REG_USBFS_HSTISR                          (0x40020404U) /**< \brief (USBFS) Host Global Interrupt Status Register */
  #define REG_USBFS_HSTICR                          (0x40020408U) /**< \brief (USBFS) Host Global Interrupt Clear Register */
  #define REG_USBFS_HSTIFR                          (0x4002040CU) /**< \brief (USBFS) Host Global Interrupt Set Register */
  #define REG_USBFS_HSTIMR                          (0x40020410U) /**< \brief (USBFS) Host Global Interrupt Mask Register */
  #define REG_USBFS_HSTIDR                          (0x40020414U) /**< \brief (USBFS) Host Global Interrupt Disable Register */
  #define REG_USBFS_HSTIER                          (0x40020418U) /**< \brief (USBFS) Host Global Interrupt Enable Register */
  #define REG_USBFS_HSTPIP                          (0x4002041CU) /**< \brief (USBFS) Host Pipe Register */
  #define REG_USBFS_HSTFNUM                         (0x40020420U) /**< \brief (USBFS) Host Frame Number Register */
  #define REG_USBFS_HSTADDR1                        (0x40020424U) /**< \brief (USBFS) Host Address 1 Register */
  #define REG_USBFS_HSTADDR2                        (0x40020428U) /**< \brief (USBFS) Host Address 2 Register */
  #define REG_USBFS_HSTADDR3                        (0x4002042CU) /**< \brief (USBFS) Host Address 3 Register */
  #define REG_USBFS_HSTPIPCFG                       (0x40020500U) /**< \brief (USBFS) Host Pipe Configuration Register (n = 0) */
  #define REG_USBFS_HSTPIPISR                       (0x40020530U) /**< \brief (USBFS) Host Pipe Status Register (n = 0) */
  #define REG_USBFS_HSTPIPICR                       (0x40020560U) /**< \brief (USBFS) Host Pipe Clear Register (n = 0) */
  #define REG_USBFS_HSTPIPIFR                       (0x40020590U) /**< \brief (USBFS) Host Pipe Set Register (n = 0) */
  #define REG_USBFS_HSTPIPIMR                       (0x400205C0U) /**< \brief (USBFS) Host Pipe Mask Register (n = 0) */
  #define REG_USBFS_HSTPIPIER                       (0x400205F0U) /**< \brief (USBFS) Host Pipe Enable Register (n = 0) */
  #define REG_USBFS_HSTPIPIDR                       (0x40020620U) /**< \brief (USBFS) Host Pipe Disable Register (n = 0) */
  #define REG_USBFS_HSTPIPINRQ                      (0x40020650U) /**< \brief (USBFS) Host Pipe IN Request Register (n = 0) */
  #define REG_USBFS_HSTPIPERR                       (0x40020680U) /**< \brief (USBFS) Host Pipe Error Register (n = 0) */
  #define REG_USBFS_HSTDMANXTDSC1                   (0x40020710U) /**< \brief (USBFS) Host DMA Channel Next Descriptor Address Register (n = 1) */
  #define REG_USBFS_HSTDMAADDRESS1                  (0x40020714U) /**< \brief (USBFS) Host DMA Channel Address Register (n = 1) */
  #define REG_USBFS_HSTDMACONTROL1                  (0x40020718U) /**< \brief (USBFS) Host DMA Channel Control Register (n = 1) */
  #define REG_USBFS_HSTDMASTATUS1                   (0x4002071CU) /**< \brief (USBFS) Host DMA Channel Status Register (n = 1) */
  #define REG_USBFS_HSTDMANXTDSC2                   (0x40020720U) /**< \brief (USBFS) Host DMA Channel Next Descriptor Address Register (n = 2) */
  #define REG_USBFS_HSTDMAADDRESS2                  (0x40020724U) /**< \brief (USBFS) Host DMA Channel Address Register (n = 2) */
  #define REG_USBFS_HSTDMACONTROL2                  (0x40020728U) /**< \brief (USBFS) Host DMA Channel Control Register (n = 2) */
  #define REG_USBFS_HSTDMASTATUS2                   (0x4002072CU) /**< \brief (USBFS) Host DMA Channel Status Register (n = 2) */
  #define REG_USBFS_HSTDMANXTDSC3                   (0x40020730U) /**< \brief (USBFS) Host DMA Channel Next Descriptor Address Register (n = 3) */
  #define REG_USBFS_HSTDMAADDRESS3                  (0x40020734U) /**< \brief (USBFS) Host DMA Channel Address Register (n = 3) */
  #define REG_USBFS_HSTDMACONTROL3                  (0x40020738U) /**< \brief (USBFS) Host DMA Channel Control Register (n = 3) */
  #define REG_USBFS_HSTDMASTATUS3                   (0x4002073CU) /**< \brief (USBFS) Host DMA Channel Status Register (n = 3) */
  #define REG_USBFS_HSTDMANXTDSC4                   (0x40020740U) /**< \brief (USBFS) Host DMA Channel Next Descriptor Address Register (n = 4) */
  #define REG_USBFS_HSTDMAADDRESS4                  (0x40020744U) /**< \brief (USBFS) Host DMA Channel Address Register (n = 4) */
  #define REG_USBFS_HSTDMACONTROL4                  (0x40020748U) /**< \brief (USBFS) Host DMA Channel Control Register (n = 4) */
  #define REG_USBFS_HSTDMASTATUS4                   (0x4002074CU) /**< \brief (USBFS) Host DMA Channel Status Register (n = 4) */
  #define REG_USBFS_CTRL                            (0x40020800U) /**< \brief (USBFS) General Control Register */
  #define REG_USBFS_SR                              (0x40020804U) /**< \brief (USBFS) General Status Register */
  #define REG_USBFS_SCR                             (0x40020808U) /**< \brief (USBFS) General Status Clear Register */
  #define REG_USBFS_SFR                             (0x4002080CU) /**< \brief (USBFS) General Status Set Register */
#else
  #define REG_USBFS_DEVCTRL        (*(__IO uint32_t*)0x40020000U) /**< \brief (USBFS) Device General Control Register */
  #define REG_USBFS_DEVISR         (*(__I  uint32_t*)0x40020004U) /**< \brief (USBFS) Device Global Interrupt Status Register */
  #define REG_USBFS_DEVICR         (*(__O  uint32_t*)0x40020008U) /**< \brief (USBFS) Device Global Interrupt Clear Register */
  #define REG_USBFS_DEVIFR         (*(__O  uint32_t*)0x4002000CU) /**< \brief (USBFS) Device Global Interrupt Set Register */
  #define REG_USBFS_DEVIMR         (*(__I  uint32_t*)0x40020010U) /**< \brief (USBFS) Device Global Interrupt Mask Register */
  #define REG_USBFS_DEVIDR         (*(__O  uint32_t*)0x40020014U) /**< \brief (USBFS) Device Global Interrupt Disable Register */
  #define REG_USBFS_DEVIER         (*(__O  uint32_t*)0x40020018U) /**< \brief (USBFS) Device Global Interrupt Enable Register */
  #define REG_USBFS_DEVEPT         (*(__IO uint32_t*)0x4002001CU) /**< \brief (USBFS) Device Endpoint Register */
  #define REG_USBFS_DEVFNUM        (*(__I  uint32_t*)0x40020020U) /**< \brief (USBFS) Device Frame Number Register */
  #define REG_USBFS_DEVEPTCFG      (*(__IO uint32_t*)0x40020100U) /**< \brief (USBFS) Device Endpoint Configuration Register (n = 0) */
  #define REG_USBFS_DEVEPTISR      (*(__I  uint32_t*)0x40020130U) /**< \brief (USBFS) Device Endpoint Status Register (n = 0) */
  #define REG_USBFS_DEVEPTICR      (*(__O  uint32_t*)0x40020160U) /**< \brief (USBFS) Device Endpoint Clear Register (n = 0) */
  #define REG_USBFS_DEVEPTIFR      (*(__O  uint32_t*)0x40020190U) /**< \brief (USBFS) Device Endpoint Set Register (n = 0) */
  #define REG_USBFS_DEVEPTIMR      (*(__I  uint32_t*)0x400201C0U) /**< \brief (USBFS) Device Endpoint Mask Register (n = 0) */
  #define REG_USBFS_DEVEPTIER      (*(__O  uint32_t*)0x400201F0U) /**< \brief (USBFS) Device Endpoint Enable Register (n = 0) */
  #define REG_USBFS_DEVEPTIDR      (*(__O  uint32_t*)0x40020220U) /**< \brief (USBFS) Device Endpoint Disable Register (n = 0) */
  #define REG_USBFS_DEVDMANXTDSC1  (*(__IO uint32_t*)0x40020310U) /**< \brief (USBFS) Device DMA Channel Next Descriptor Address Register (n = 1) */
  #define REG_USBFS_DEVDMAADDRESS1 (*(__IO uint32_t*)0x40020314U) /**< \brief (USBFS) Device DMA Channel Address Register (n = 1) */
  #define REG_USBFS_DEVDMACONTROL1 (*(__IO uint32_t*)0x40020318U) /**< \brief (USBFS) Device DMA Channel Control Register (n = 1) */
  #define REG_USBFS_DEVDMASTATUS1  (*(__IO uint32_t*)0x4002031CU) /**< \brief (USBFS) Device DMA Channel Status Register (n = 1) */
  #define REG_USBFS_DEVDMANXTDSC2  (*(__IO uint32_t*)0x40020320U) /**< \brief (USBFS) Device DMA Channel Next Descriptor Address Register (n = 2) */
  #define REG_USBFS_DEVDMAADDRESS2 (*(__IO uint32_t*)0x40020324U) /**< \brief (USBFS) Device DMA Channel Address Register (n = 2) */
  #define REG_USBFS_DEVDMACONTROL2 (*(__IO uint32_t*)0x40020328U) /**< \brief (USBFS) Device DMA Channel Control Register (n = 2) */
  #define REG_USBFS_DEVDMASTATUS2  (*(__IO uint32_t*)0x4002032CU) /**< \brief (USBFS) Device DMA Channel Status Register (n = 2) */
  #define REG_USBFS_DEVDMANXTDSC3  (*(__IO uint32_t*)0x40020330U) /**< \brief (USBFS) Device DMA Channel Next Descriptor Address Register (n = 3) */
  #define REG_USBFS_DEVDMAADDRESS3 (*(__IO uint32_t*)0x40020334U) /**< \brief (USBFS) Device DMA Channel Address Register (n = 3) */
  #define REG_USBFS_DEVDMACONTROL3 (*(__IO uint32_t*)0x40020338U) /**< \brief (USBFS) Device DMA Channel Control Register (n = 3) */
  #define REG_USBFS_DEVDMASTATUS3  (*(__IO uint32_t*)0x4002033CU) /**< \brief (USBFS) Device DMA Channel Status Register (n = 3) */
  #define REG_USBFS_DEVDMANXTDSC4  (*(__IO uint32_t*)0x40020340U) /**< \brief (USBFS) Device DMA Channel Next Descriptor Address Register (n = 4) */
  #define REG_USBFS_DEVDMAADDRESS4 (*(__IO uint32_t*)0x40020344U) /**< \brief (USBFS) Device DMA Channel Address Register (n = 4) */
  #define REG_USBFS_DEVDMACONTROL4 (*(__IO uint32_t*)0x40020348U) /**< \brief (USBFS) Device DMA Channel Control Register (n = 4) */
  #define REG_USBFS_DEVDMASTATUS4  (*(__IO uint32_t*)0x4002034CU) /**< \brief (USBFS) Device DMA Channel Status Register (n = 4) */
  #define REG_USBFS_HSTCTRL        (*(__IO uint32_t*)0x40020400U) /**< \brief (USBFS) Host General Control Register */
  #define REG_USBFS_HSTISR         (*(__I  uint32_t*)0x40020404U) /**< \brief (USBFS) Host Global Interrupt Status Register */
  #define REG_USBFS_HSTICR         (*(__O  uint32_t*)0x40020408U) /**< \brief (USBFS) Host Global Interrupt Clear Register */
  #define REG_USBFS_HSTIFR         (*(__O  uint32_t*)0x4002040CU) /**< \brief (USBFS) Host Global Interrupt Set Register */
  #define REG_USBFS_HSTIMR         (*(__I  uint32_t*)0x40020410U) /**< \brief (USBFS) Host Global Interrupt Mask Register */
  #define REG_USBFS_HSTIDR         (*(__O  uint32_t*)0x40020414U) /**< \brief (USBFS) Host Global Interrupt Disable Register */
  #define REG_USBFS_HSTIER         (*(__O  uint32_t*)0x40020418U) /**< \brief (USBFS) Host Global Interrupt Enable Register */
  #define REG_USBFS_HSTPIP         (*(__IO uint32_t*)0x4002041CU) /**< \brief (USBFS) Host Pipe Register */
  #define REG_USBFS_HSTFNUM        (*(__IO uint32_t*)0x40020420U) /**< \brief (USBFS) Host Frame Number Register */
  #define REG_USBFS_HSTADDR1       (*(__IO uint32_t*)0x40020424U) /**< \brief (USBFS) Host Address 1 Register */
  #define REG_USBFS_HSTADDR2       (*(__IO uint32_t*)0x40020428U) /**< \brief (USBFS) Host Address 2 Register */
  #define REG_USBFS_HSTADDR3       (*(__IO uint32_t*)0x4002042CU) /**< \brief (USBFS) Host Address 3 Register */
  #define REG_USBFS_HSTPIPCFG      (*(__IO uint32_t*)0x40020500U) /**< \brief (USBFS) Host Pipe Configuration Register (n = 0) */
  #define REG_USBFS_HSTPIPISR      (*(__I  uint32_t*)0x40020530U) /**< \brief (USBFS) Host Pipe Status Register (n = 0) */
  #define REG_USBFS_HSTPIPICR      (*(__O  uint32_t*)0x40020560U) /**< \brief (USBFS) Host Pipe Clear Register (n = 0) */
  #define REG_USBFS_HSTPIPIFR      (*(__O  uint32_t*)0x40020590U) /**< \brief (USBFS) Host Pipe Set Register (n = 0) */
  #define REG_USBFS_HSTPIPIMR      (*(__I  uint32_t*)0x400205C0U) /**< \brief (USBFS) Host Pipe Mask Register (n = 0) */
  #define REG_USBFS_HSTPIPIER      (*(__O  uint32_t*)0x400205F0U) /**< \brief (USBFS) Host Pipe Enable Register (n = 0) */
  #define REG_USBFS_HSTPIPIDR      (*(__O  uint32_t*)0x40020620U) /**< \brief (USBFS) Host Pipe Disable Register (n = 0) */
  #define REG_USBFS_HSTPIPINRQ     (*(__IO uint32_t*)0x40020650U) /**< \brief (USBFS) Host Pipe IN Request Register (n = 0) */
  #define REG_USBFS_HSTPIPERR      (*(__IO uint32_t*)0x40020680U) /**< \brief (USBFS) Host Pipe Error Register (n = 0) */
  #define REG_USBFS_HSTDMANXTDSC1  (*(__IO uint32_t*)0x40020710U) /**< \brief (USBFS) Host DMA Channel Next Descriptor Address Register (n = 1) */
  #define REG_USBFS_HSTDMAADDRESS1 (*(__IO uint32_t*)0x40020714U) /**< \brief (USBFS) Host DMA Channel Address Register (n = 1) */
  #define REG_USBFS_HSTDMACONTROL1 (*(__IO uint32_t*)0x40020718U) /**< \brief (USBFS) Host DMA Channel Control Register (n = 1) */
  #define REG_USBFS_HSTDMASTATUS1  (*(__IO uint32_t*)0x4002071CU) /**< \brief (USBFS) Host DMA Channel Status Register (n = 1) */
  #define REG_USBFS_HSTDMANXTDSC2  (*(__IO uint32_t*)0x40020720U) /**< \brief (USBFS) Host DMA Channel Next Descriptor Address Register (n = 2) */
  #define REG_USBFS_HSTDMAADDRESS2 (*(__IO uint32_t*)0x40020724U) /**< \brief (USBFS) Host DMA Channel Address Register (n = 2) */
  #define REG_USBFS_HSTDMACONTROL2 (*(__IO uint32_t*)0x40020728U) /**< \brief (USBFS) Host DMA Channel Control Register (n = 2) */
  #define REG_USBFS_HSTDMASTATUS2  (*(__IO uint32_t*)0x4002072CU) /**< \brief (USBFS) Host DMA Channel Status Register (n = 2) */
  #define REG_USBFS_HSTDMANXTDSC3  (*(__IO uint32_t*)0x40020730U) /**< \brief (USBFS) Host DMA Channel Next Descriptor Address Register (n = 3) */
  #define REG_USBFS_HSTDMAADDRESS3 (*(__IO uint32_t*)0x40020734U) /**< \brief (USBFS) Host DMA Channel Address Register (n = 3) */
  #define REG_USBFS_HSTDMACONTROL3 (*(__IO uint32_t*)0x40020738U) /**< \brief (USBFS) Host DMA Channel Control Register (n = 3) */
  #define REG_USBFS_HSTDMASTATUS3  (*(__IO uint32_t*)0x4002073CU) /**< \brief (USBFS) Host DMA Channel Status Register (n = 3) */
  #define REG_USBFS_HSTDMANXTDSC4  (*(__IO uint32_t*)0x40020740U) /**< \brief (USBFS) Host DMA Channel Next Descriptor Address Register (n = 4) */
  #define REG_USBFS_HSTDMAADDRESS4 (*(__IO uint32_t*)0x40020744U) /**< \brief (USBFS) Host DMA Channel Address Register (n = 4) */
  #define REG_USBFS_HSTDMACONTROL4 (*(__IO uint32_t*)0x40020748U) /**< \brief (USBFS) Host DMA Channel Control Register (n = 4) */
  #define REG_USBFS_HSTDMASTATUS4  (*(__IO uint32_t*)0x4002074CU) /**< \brief (USBFS) Host DMA Channel Status Register (n = 4) */
  #define REG_USBFS_CTRL           (*(__IO uint32_t*)0x40020800U) /**< \brief (USBFS) General Control Register */
  #define REG_USBFS_SR             (*(__I  uint32_t*)0x40020804U) /**< \brief (USBFS) General Status Register */
  #define REG_USBFS_SCR            (*(__O  uint32_t*)0x40020808U) /**< \brief (USBFS) General Status Clear Register */
  #define REG_USBFS_SFR            (*(__O  uint32_t*)0x4002080CU) /**< \brief (USBFS) General Status Set Register */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#endif /* _SAM4C_USBFS_INSTANCE_ */
