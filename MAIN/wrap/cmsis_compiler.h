/*
 * Copyright (C) 2019-2020 Zach Lee.
 *
 * Licensed under the MIT License, you may not use this file except in
 * compliance with the License.
 *
 * MIT License:
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * ----------------------------------------------------------------------
 *
 * $Date:        11. August 2019
 * $Revision:    V0.0.0
 *
 * Project:      CMSIS-DAP Examples STM32F103
 * Title:        cmsis_compiler.h CMSIS-DAP Wrap module for STM32
 *
 *---------------------------------------------------------------------------*/
#ifndef _CMSIS_COMPILER_H_
#define _CMSIS_COMPILER_H_

/**
  * I don't like the original header file from CMSIS package because it
  * will include a bunch of unrelated header files.
  */

#if defined(__GNUC__)
  #define __WEAK                  __attribute__((weak))
  #define __NO_RETURN             __attribute__((noreturn))
  #define __STATIC_INLINE         static inline
  #define __STATIC_FORCEINLINE    static inline
  #define __nop()                 __NOP()

  typedef _Bool                   bool;
  #define true                    1
  #define false                   0

  #include <stdint.h>
#endif

#if defined(__ICCARM__)           /* for IAR EWARM */
  #define __NO_RETURN             __noreturn
  #define __STATIC_INLINE         static inline
  #define __STATIC_FORCEINLINE    static inline
  
  typedef _Bool                   bool;
  #define true                    1
  #define false                   0
#endif

#if defined(__CC_ARM)             /* for Keil MDK */
	#define __WEAK                  __weak
	#define __NO_RETURN             __declspec(noreturn)
  #define __STATIC_FORCEINLINE    static __inline

  typedef _Bool                   bool;
  #define true                    1
  #define false                   0

	/**
	  * I don't know how to omit "-D_RTX_" from the command line parameters
	  * so I insert my header file hear.
	  */
	#include "device.h"
#endif

#endif
