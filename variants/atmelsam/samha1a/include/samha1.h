/**
 * \file
 *
 * \brief Top header file for SAMHA1
 *
 * Copyright (c) 2017 Microchip Technology Inc.
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

#if   defined(__SAMHA1E14A__) || defined(__ATSAMHA1E14A__)
  #include "samha1e14a.h"
#elif defined(__SAMHA1E15A__) || defined(__ATSAMHA1E15A__)
  #include "samha1e15a.h"
#elif defined(__SAMHA1E16A__) || defined(__ATSAMHA1E16A__)
  #include "samha1e16a.h"
#elif defined(__SAMHA1G14A__) || defined(__ATSAMHA1G14A__)
  #include "samha1g14a.h"
#elif defined(__SAMHA1G14R__) || defined(__ATSAMHA1G14R__)
  #include "samha1g14r.h"
#elif defined(__SAMHA1G14W__) || defined(__ATSAMHA1G14W__)
  #include "samha1g14w.h"
#elif defined(__SAMHA1G15A__) || defined(__ATSAMHA1G15A__)
  #include "samha1g15a.h"
#elif defined(__SAMHA1G15R__) || defined(__ATSAMHA1G15R__)
  #include "samha1g15r.h"
#elif defined(__SAMHA1G15W__) || defined(__ATSAMHA1G15W__)
  #include "samha1g15w.h"
#elif defined(__SAMHA1G16A__) || defined(__ATSAMHA1G16A__)
  #include "samha1g16a.h"
#elif defined(__SAMHA1G16R__) || defined(__ATSAMHA1G16R__)
  #include "samha1g16r.h"
#elif defined(__SAMHA1G16W__) || defined(__ATSAMHA1G16W__)
  #include "samha1g16w.h"
#else
  #error Library does not support the specified device.
#endif

#endif /* _SAMHA1_ */
