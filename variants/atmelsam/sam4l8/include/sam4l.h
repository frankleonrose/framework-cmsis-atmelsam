/**
 * \file
 *
 * \brief Top header file for SAM4L
 *
 * Copyright (c) 2016 Atmel Corporation,
 *                    a wholly owned subsidiary of Microchip Technology Inc.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the Licence at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * \asf_license_stop
 *
 */

#ifndef _SAM4L_
#define _SAM4L_

/**
 * \defgroup SAM4L_definitions SAM4L Device Definitions
 * \brief SAM4L CMSIS Definitions.
 */

#if   defined(__SAM4LC8A__) || defined(__ATSAM4LC8A__)
  #include "sam4lc8a.h"
#elif defined(__SAM4LC8B__) || defined(__ATSAM4LC8B__)
  #include "sam4lc8b.h"
#elif defined(__SAM4LC8C__) || defined(__ATSAM4LC8C__)
  #include "sam4lc8c.h"
#elif defined(__SAM4LS8A__) || defined(__ATSAM4LS8A__)
  #include "sam4ls8a.h"
#elif defined(__SAM4LS8B__) || defined(__ATSAM4LS8B__)
  #include "sam4ls8b.h"
#elif defined(__SAM4LS8C__) || defined(__ATSAM4LS8C__)
  #include "sam4ls8c.h"
#else
  #error Library does not support the specified device.
#endif

#endif /* _SAM4L_ */
