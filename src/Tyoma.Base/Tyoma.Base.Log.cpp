#include "Tyoma.h"

#include <stdarg.h>

void tyLogDefaultCallbackA(const char* s)
{
	printf(s);
}

void tyLogDefaultCallbackW(const wchar_t* s)
{
	wprintf(s);
}

class tyLogImpl
{
public:
	tyLogImpl()
	{
		m_cba = tyLogDefaultCallbackA;
		m_cbw = tyLogDefaultCallbackW;
	}

	void vprintf(const char* s, va_list vl);
	void vwprintf(const wchar_t* s, va_list vl);

	void(*m_cba)(const char*);
	void(*m_cbw)(const wchar_t*);
};

void tyLogImpl::vprintf(const char* s, va_list vl)
{
	char buffer[1000];
	vsnprintf_s(buffer, 1000, s, vl);
	m_cba(buffer);
}

void tyLogImpl::vwprintf(const wchar_t* s, va_list vl)
{
	wchar_t buffer[1000];
	vswprintf_s(buffer, 1000, s, vl);
	m_cbw(buffer);
}

static tyLogImpl g_log;

void tyLog::Print(const char* s, ...)
{
	va_list vl;
	va_start(vl, s);
	g_log.vprintf(s, vl);
	va_end(vl);
}

void tyLog::Print(const wchar_t* s, ...)
{
	va_list vl;
	va_start(vl, s);
	g_log.vwprintf(s, vl);
	va_end(vl);
}

void tyLog::PrintInfo(const char* s, ...)
{
	Print("%s", "Info: ");

	va_list vl;
	va_start(vl, s);
	g_log.vprintf(s, vl);
	va_end(vl);
}

void tyLog::PrintInfo(const wchar_t* s, ...)
{
	Print("%s", "Info: ");
	va_list vl;
	va_start(vl, s);
	g_log.vwprintf(s, vl);
	va_end(vl);
}

void tyLog::PrintWarning(const char* s, ...)
{
	Print("%s", "Warning: ");
	va_list vl;
	va_start(vl, s);
	g_log.vprintf(s, vl);
	va_end(vl);
}

void tyLog::PrintWarning(const wchar_t* s, ...)
{
	Print("%s", "Warning: ");
	va_list vl;
	va_start(vl, s);
	g_log.vwprintf(s, vl);
	va_end(vl);
}

void tyLog::PrintError(const char* s, ...)
{
	Print("%s", "Error: ");
	va_list vl;
	va_start(vl, s);
	g_log.vprintf(s, vl);
	va_end(vl);
}

void tyLog::PrintError(const wchar_t* s, ...)
{
	Print("%s", "Error: ");
	va_list vl;
	va_start(vl, s);
	g_log.vwprintf(s, vl);
	va_end(vl);
}

void tyLog::SetCallbackA(void(*cb)(const char*))
{
	if (cb)
		g_log.m_cba = cb;
	else
		g_log.m_cba = tyLogDefaultCallbackA;
}

void tyLog::SetCallbackW(void(*cb)(const wchar_t*))
{
	if (cb)
		g_log.m_cbw = cb;
	else
		g_log.m_cbw = tyLogDefaultCallbackW;
}

