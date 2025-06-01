﻿/*
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

#define T_EXPORT
#include "T.h"
#include "T/Memory.h"

#ifdef TY_PLATFORM_WINDOWS
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
static HANDLE g_processHeap = GetProcessHeap();
#endif

void* tMemory::Malloc(size_t size)
{
#ifdef TY_PLATFORM_WINDOWS
	return HeapAlloc(g_processHeap, 0, size);
#else
	return ::malloc(size);
#endif
}

void* tMemory::Calloc(size_t size)
{
#ifdef TY_PLATFORM_WINDOWS
	return HeapAlloc(g_processHeap, HEAP_ZERO_MEMORY, size);
#else
	return ::calloc(1, size);
#endif
}

void tMemory::Free(void* ptr)
{
#ifdef TY_PLATFORM_WINDOWS
	HeapFree(g_processHeap, 0, ptr);
#else
	::free(ptr);
#endif
}

void* tMemory::ReAlloc(void* ptr, size_t size)
{
#ifdef TY_PLATFORM_WINDOWS
	return HeapReAlloc(g_processHeap, HEAP_ZERO_MEMORY, ptr, size);
#else
	return ::realloc(ptr, size);
#endif
}


