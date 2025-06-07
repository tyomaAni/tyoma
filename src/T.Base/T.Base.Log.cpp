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

#include "T.h"

#include <stdarg.h>

void tLogDefaultCallbackA(const char* s)
{
	printf(s);
}

void tLogDefaultCallbackW(const wchar_t* s)
{
	wprintf(s);
}

class tLogImpl
{
public:
	tLogImpl()
	{
		m_cba = tLogDefaultCallbackA;
		m_cbw = tLogDefaultCallbackW;
	}

	void vprintf(const char* s, va_list vl);
	void vwprintf(const wchar_t* s, va_list vl);

	void(*m_cba)(const char*);
	void(*m_cbw)(const wchar_t*);
};

void tLogImpl::vprintf(const char* s, va_list vl)
{
	char buffer[1000];
	vsnprintf_s(buffer, 1000, s, vl);
	m_cba(buffer);
}

void tLogImpl::vwprintf(const wchar_t* s, va_list vl)
{
	wchar_t buffer[1000];
	vswprintf_s(buffer, 1000, s, vl);
	m_cbw(buffer);
}

static tLogImpl g_log;

void tLog::Print(const char* s, ...)
{
	va_list vl;
	va_start(vl, s);
	g_log.vprintf(s, vl);
	va_end(vl);
}

void tLog::Print(const wchar_t* s, ...)
{
	va_list vl;
	va_start(vl, s);
	g_log.vwprintf(s, vl);
	va_end(vl);
}

void tLog::PrintInfo(const char* s, ...)
{
	Print("%s", "Info: ");

	va_list vl;
	va_start(vl, s);
	g_log.vprintf(s, vl);
	va_end(vl);
}

void tLog::PrintInfo(const wchar_t* s, ...)
{
	Print("%s", "Info: ");
	va_list vl;
	va_start(vl, s);
	g_log.vwprintf(s, vl);
	va_end(vl);
}

void tLog::PrintWarning(const char* s, ...)
{
	Print("%s", "Warning: ");
	va_list vl;
	va_start(vl, s);
	g_log.vprintf(s, vl);
	va_end(vl);
}

void tLog::PrintWarning(const wchar_t* s, ...)
{
	Print("%s", "Warning: ");
	va_list vl;
	va_start(vl, s);
	g_log.vwprintf(s, vl);
	va_end(vl);
}

void tLog::PrintError(const char* s, ...)
{
	Print("%s", "Error: ");
	va_list vl;
	va_start(vl, s);
	g_log.vprintf(s, vl);
	va_end(vl);
}

void tLog::PrintError(const wchar_t* s, ...)
{
	Print("%s", "Error: ");
	va_list vl;
	va_start(vl, s);
	g_log.vwprintf(s, vl);
	va_end(vl);
}

void tLog::SetCallbackA(void(*cb)(const char*))
{
	if (cb)
		g_log.m_cba = cb;
	else
		g_log.m_cba = tLogDefaultCallbackA;
}

void tLog::SetCallbackW(void(*cb)(const wchar_t*))
{
	if (cb)
		g_log.m_cbw = cb;
	else
		g_log.m_cbw = tLogDefaultCallbackW;
}

