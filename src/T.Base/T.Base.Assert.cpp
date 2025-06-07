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
#define T_EXPORT

#include "T.h"
#include "T/String.h"

#include <stdio.h>

#ifdef T_PLATFORM_WINDOWS
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#endif

void OnAssert_default(const char* message, const char* file, uint32_t line, uint32_t flags)
{
#ifdef T_DEBUG
    if ((flags & tAssert::flag_onAssert_useStackTrace) == tAssert::flag_onAssert_useStackTrace)
    {
        tStackTracer::Print();
    }

    if ((flags & tAssert::flag_onAssert_useDefaultSystemWindow) == tAssert::flag_onAssert_useDefaultSystemWindow)
    {
        tString str_msg(message);
        tString str_file(file);

        tStringW str1;
        str_msg.ToUtf16(str1);

        tStringW str2;
        str_file.ToUtf16(str2);

#ifdef T_PLATFORM_WINDOWS
        _wassert((const wchar_t*)str1.m_data, (const wchar_t*)str2.m_data, line);
#endif
    }
    else
    {
        //printf("%s %s %i\n", message, file, line);
        tLog::PrintError("%s in %s [%i]\n", message, file, line);
#ifdef TY_PLATFORM_WINDOWS
        DebugBreak();
#endif
    }
#endif
}

static void(*g_onAssert)(const char* message, const char* file, uint32_t line, uint32_t flags) = OnAssert_default;


void tAssert::OnAssert(const char* message, const char* file, uint32_t line, uint32_t flags)
{
    g_onAssert(message, file, line, flags);
}

//extern "C"
//{
//    void SL_CDECL slSetOnAssert(void(*f)(const char* message, const char* file, uint32_t line, uint32_t flags))
//    {
//        g_onAssert = f ? f : onAssert_default;
//    }
//}


