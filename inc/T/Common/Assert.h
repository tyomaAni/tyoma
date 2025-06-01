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
#ifndef _TY_AST_H_
#define _TY_AST_H_
/// Tyoma.Base

// Custom assert()

class T_API tAssert
{
public:
    enum flag_onAssert
    {
        flag_onAssert_useDefaultSystemWindow = 0x1,
        flag_onAssert_useStackTrace = 0x2,
    };
    static void OnAssert(const char* message, const char* file, uint32_t line, uint32_t flags = 0);
};

#ifdef T_DEBUG
#define T_ASSERT(expression) if((expression) == 0){tAssert::OnAssert(#expression, T_FILE, T_LINE, 0);}
#define T_ASSERT_ST(expression) if((expression) == 0){tAssert::OnAssert(#expression, T_FILE, T_LINE, tAssert::flag_onAssert_useDefaultSystemWindow | tAssert::flag_onAssert_useStackTrace);}
#else
#define T_ASSERT(expression) ((void)0)
#define T_ASSERT_ST(expression) ((void)0)
#endif


#endif
