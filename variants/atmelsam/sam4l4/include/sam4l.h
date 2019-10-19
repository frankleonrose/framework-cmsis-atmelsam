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

#if   defined(__SAM4LC2A__) || defined(__ATSAM4LC2A__)
  #include "sam4lc2a.h"
#elif defined(__SAM4LC2B__) || defined(__ATSAM4LC2B__)
  #include "sam4lc2b.h"
#elif defined(__SAM4LC2C__) || defined(__ATSAM4LC2C__)
  #include "sam4lc2c.h"
#elif defined(__SAM4LC4A__) || defined(__ATSAM4LC4A__)
  #include "sam4lc4a.h"
#elif defined(__SAM4LC4B__) || defined(__ATSAM4LC4B__)
  #include "sam4lc4b.h"
#elif defined(__SAM4LC4C__) || defined(__ATSAM4LC4C__)
  #include "sam4lc4c.h"
#elif defined(__SAM4LS2A__) || defined(__ATSAM4LS2A__)
  #include "sam4ls2a.h"
#elif defined(__SAM4LS2B__) || defined(__ATSAM4LS2B__)
  #include "sam4ls2b.h"
#elif defined(__SAM4LS2C__) || defined(__ATSAM4LS2C__)
  #include "sam4ls2c.h"
#elif defined(__SAM4LS4A__) || defined(__ATSAM4LS4A__)
  #include "sam4ls4a.h"
#elif defined(__SAM4LS4B__) || defined(__ATSAM4LS4B__)
  #include "sam4ls4b.h"
#elif defined(__SAM4LS4C__) || defined(__ATSAM4LS4C__)
  #include "sam4ls4c.h"
#else
  #error Library does not support the specified device.
#endif

#endif /* _SAM4L_ */
