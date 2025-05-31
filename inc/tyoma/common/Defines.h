/*
BSD 2-Clause License

Copyright (c) 2025, tyomaAni
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#pragma once
#ifndef _TY_DEFS_H_
#define _TY_DEFS_H_

/// That libraries that export something must
/// use TY_EXPORT macro
#ifdef _MSC_VER
#ifdef TY_EXPORT
#define TY_API _declspec(dllexport)
#else
#define TY_API _declspec(dllimport)
#endif
#else
#define TY_API
#endif

#ifdef _MSC_VER
#define TY_FORCEINLINE __forceinline
#else
#define TY_FORCEINLINE inline
#endif

#include <stddef.h> // NULL, size_t
#include <stdlib.h>
#include <assert.h> 
#include <stdint.h> // int32_t uint32_t and other
#include <ctype.h>  // isspace
#include <utility>  // std::move

using real_t = double;
using float32_t = float;
using float64_t = double;

/// Detect platform
#if defined(WIN32) | defined(_WIN64) | defined(_WIN32)
#define TY_PLATFORM_WINDOWS
#else
#error Please, write code for other platform
#endif

/// For C inside C++
#ifdef TY_PLATFORM_WINDOWS
#define TY_CDECL _cdecl
#else
#error Please, write code for other platform
#endif

/// Our own _DEBUG
#ifdef _DEBUG
#define TY_DEBUG
#endif

/// `pack` 4 bytes into 1 uint32_t
/// I don't know about speed.
/// uint32_i magic = SL_MAKEFOURCC('‰', 'P', 'N', 'G');
///    //magic must be `1196314761`
#define TY_MAKEFOURCC( ch0, ch1, ch2, ch3 )\
	((uint32_t)(uint8_t)(ch0)|((uint32_t)(uint8_t)(ch1)<<8)|\
	((uint32_t)(uint8_t)(ch2)<<16)|((uint32_t)(uint8_t)(ch3)<<24))

/// Need to know if this is 64 bit configuration
#ifdef TY_PLATFORM_WINDOWS
#if defined _WIN64 || defined __x86_64__
#define TY_BIT_64
#endif
#else
#error Please, write code for other platform
#endif

/// Show file name, line and function
/// printf("%s %i %s\n", SL_FILE, SL_LINE, SL_FUNCTION);
#ifdef TY_PLATFORM_WINDOWS
#define TY_FILE __FILE__
#define TY_LINE __LINE__
#define TY_FUNCTION __FUNCTION__
#else
#error Please, write code for other platform
#endif

/// For example if you have 0xAABBCCDD
/// You can get 0xAABB and 0xCCDD using this macros
#define TY_LO32(l) ((uint16_t)(((uint32_t)(l)) & 0xffff))
#define TY_HI32(l) ((uint16_t)((((uint32_t)(l)) >> 16) & 0xffff))

#define tyZeroDecl(t,n) t n; memset(&n, 0, sizeof(n))

#define TYSAFE_DESTROY(x) if(x){slFramework::Destroy(x);x=0;}

#endif
