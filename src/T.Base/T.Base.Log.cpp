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

