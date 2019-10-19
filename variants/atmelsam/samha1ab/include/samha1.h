/**
 * \file
 *
 * \brief Top header file for SAMHA1
 *
 * Copyright (c) 2018 Microchip Technology Inc.
 *
 * \asf_license_start
 *
 * \page License
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the Licence at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * \asf_license_stop
 *
 */

#ifndef _SAMHA1_
#define _SAMHA1_

/**
 * \defgroup SAMHA1_definitions SAMHA1 Device Definitions
 * \brief SAMHA1 CMSIS Definitions.
 */

#if   defined(__SAMHA1E14AB__) || defined(__ATSAMHA1E14AB__)
  #include "samha1e14ab.h"
#elif defined(__SAMHA1E15AB__) || defined(__ATSAMHA1E15AB__)
  #include "samha1e15ab.h"
#elif defined(__SAMHA1E16AB__) || defined(__ATSAMHA1E16AB__)
  #include "samha1e16ab.h"
#elif defined(__SAMHA1G14AB__) || defined(__ATSAMHA1G14AB__)
  #include "samha1g14ab.h"
#elif defined(__SAMHA1G14RB__) || defined(__ATSAMHA1G14RB__)
  #include "samha1g14rb.h"
#elif defined(__SAMHA1G14WB__) || defined(__ATSAMHA1G14WB__)
  #include "samha1g14wb.h"
#elif defined(__SAMHA1G15AB__) || defined(__ATSAMHA1G15AB__)
  #include "samha1g15ab.h"
#elif defined(__SAMHA1G15RB__) || defined(__ATSAMHA1G15RB__)
  #include "samha1g15rb.h"
#elif defined(__SAMHA1G15WB__) || defined(__ATSAMHA1G15WB__)
  #include "samha1g15wb.h"
#elif defined(__SAMHA1G16AB__) || defined(__ATSAMHA1G16AB__)
  #include "samha1g16ab.h"
#elif defined(__SAMHA1G16RB__) || defined(__ATSAMHA1G16RB__)
  #include "samha1g16rb.h"
#elif defined(__SAMHA1G16WB__) || defined(__ATSAMHA1G16WB__)
  #include "samha1g16wb.h"
#else
  #error Library does not support the specified device.
#endif

#endif /* _SAMHA1_ */
