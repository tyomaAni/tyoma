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

#include "Tyoma.h"

#ifndef TY_EXPORT
#define TY_EXPORT
#endif

#include "Tyoma/String.h"
#include "Tyoma/Memory.h"

#include <string>

#include "Tyoma.String.Internal.h"

#pragma comment(lib, "Tyoma.Memory.lib")

template<typename other_type>
size_t ty_string_getlen(const other_type* str)
{
	unsigned int len = 0u;
	if (str[0] != 0)
	{
		const other_type* p = &str[0u];
		while ((size_t)*p++)
			len++;
	}
	return len;
}

void tyStringA::Reallocate(size_t new_allocated)
{
	char8_t* new_data = (char8_t*)tyMemory::Malloc(new_allocated * sizeof(char8_t));
	if (m_data)
	{
		memcpy(new_data, m_data, m_size * sizeof(char8_t));
		tyMemory::Free(m_data);
	}
	else
	{
		memset(new_data, 0, new_allocated);
	}
	m_data = new_data;
	m_allocated = new_allocated;
}
tyStringA::tyStringA() {}
tyStringA::tyStringA(const char* s) : tyStringA() { Assign(s); }
tyStringA::tyStringA(const char8_t* s) : tyStringA() { Assign(s); }
tyStringA::tyStringA(const tyStringA& s) : tyStringA() { Assign(s); }
tyStringA::tyStringA(tyStringA&& s) : tyStringA() { this->operator=(std::move(s)); }
tyStringA::~tyStringA() { if (m_data) tyMemory::Free(m_data); }
void tyStringA::PushBack(char8_t c)
{
	size_t new_size = m_size + 1u;
	if ((new_size + 1u) > m_allocated)
		Reallocate((new_size + 1u) + (1 + (size_t)(m_size * 0.5f)));
	m_data[m_size] = c;
	m_size = new_size;
	m_data[m_size] = 0;
}
void tyStringA::Clear() { m_size = 0; }
void tyStringA::Assign(const tyStringA& s) {
	Clear();
	Append(s);
}
void tyStringA::Assign(const char* s) {
	Clear();
	Append(s);
}
void tyStringA::Assign(const char8_t* s) {
	Clear();
	Append(s);
}
void tyStringA::Append(const tyStringA& s) {
	for (size_t i = 0; i < s.m_size; ++i)
	{
		PushBack(s.m_data[i]);
	}
}
void tyStringA::Append(const char* s) {
	size_t l = strlen(s);
	for (size_t i = 0; i < l; ++i)
	{
		PushBack(s[i]);
	}
}
void tyStringA::Append(const char8_t* s) {
	size_t l = strlen((const char*)s);
	for (size_t i = 0; i < l; ++i)
	{
		PushBack(s[i]);
	}
}
void tyStringA::Append(float f) {
	char buf[32u];
	int nob = sprintf_s(buf, 32, "%.4f", f);
	if (nob)
	{
		for (int i = 0; i < nob; ++i)
		{
			PushBack((char32_t)buf[i]);
		}
	}
}

void tyStringA::Append(double f) {
	char buf[32u];
	int nob = sprintf_s(buf, 32, "%.12f", f);
	if (nob)
	{
		for (int i = 0; i < nob; ++i)
		{
			PushBack((char32_t)buf[i]);
		}
	}
}

void tyStringA::Append(uint32_t i)
{
	char buf[32u];
	int nob = sprintf_s(buf, 32, "%u", i);
	if (nob)
	{
		for (int i = 0; i < nob; ++i)
		{
			PushBack((char32_t)buf[i]);
		}
	}
}

tyStringA& tyStringA::operator=(const tyStringA& s) {
	Clear();
	Append(s);
	return *this;
}
tyStringA& tyStringA::operator=(tyStringA&& s) {
	if (m_data)
		tyMemory::Free(m_data);
	m_data = s.m_data;
	m_allocated = s.m_allocated;
	m_size = s.m_size;

	s.m_data = 0;
	s.m_allocated = 0;
	s.m_size = 0;
	return *this;
}

void tyStringW::Reallocate(size_t new_allocated)
{
	char16_t* new_data = (char16_t*)tyMemory::Malloc(new_allocated * sizeof(char16_t));
	if (m_data)
	{
		memcpy(new_data, m_data, m_size * sizeof(char16_t));
		tyMemory::Free(m_data);
	}
	else
	{
		memset(new_data, 0, new_allocated);
	}
	m_data = new_data;
	m_allocated = new_allocated;
}
tyStringW::tyStringW() {}
tyStringW::~tyStringW() { if (m_data) tyMemory::Free(m_data); }
void tyStringW::PushBack(char16_t c)
{
	size_t new_size = m_size + 1u;
	if ((new_size + 1u) > m_allocated)
		Reallocate((new_size + 1u) + (1 + (size_t)(m_size * 0.5f)));
	m_data[m_size] = c;
	m_size = new_size;
	m_data[m_size] = 0;
}
void tyStringW::Clear() { m_size = 0; }
tyStringW::tyStringW(const tyStringW& s) : tyStringW() { Assign(s); }
tyStringW::tyStringW(tyStringW&& s) : tyStringW() { this->operator=(std::move(s)); }
void tyStringW::Assign(const tyStringW& s) {
	Clear();
	Append(s);
}
void tyStringW::Append(const tyStringW& s) {
	for (size_t i = 0; i < s.m_size; ++i)
	{
		PushBack(s.m_data[i]);
	}
}
tyStringW& tyStringW::operator=(const tyStringW& s) {
	Clear();
	Append(s);
	return *this;
}
tyStringW& tyStringW::operator=(tyStringW&& s) {
	if (m_data)
		tyMemory::Free(m_data);
	m_data = s.m_data;
	m_allocated = s.m_allocated;
	m_size = s.m_size;

	s.m_data = 0;
	s.m_allocated = 0;
	s.m_size = 0;
	return *this;
}

void tyString::Reallocate(size_t new_allocated)
{
	char32_t* new_data = (char32_t*)tyMemory::Malloc(new_allocated * sizeof(char32_t));
	if (m_data)
	{
		memcpy(new_data, m_data, m_size * sizeof(char32_t));
		tyMemory::Free(m_data);
	}
	else
	{
		memset(new_data, 0, new_allocated);
	}
	m_data = new_data;
	m_allocated = new_allocated;
}

tyString::tyString()
{
	m_allocated = g_stringWordSize;
	Reallocate(m_allocated);
}

tyString::tyString(const char* s) : tyString()
{
	Assign(s);
}

tyString::tyString(const wchar_t* s) : tyString()
{
	Assign(s);
}

tyString::tyString(const char8_t* s) : tyString()
{
	Assign(s);
}

tyString::tyString(const char16_t* s) : tyString()
{
	Assign(s);
}

tyString::tyString(const char32_t* s) : tyString()
{
	Assign(s);
}

tyString::tyString(const tyString& s) : tyString()
{
	Assign(s);
}

tyString::tyString(tyString&& s) : tyString()
{
	this->operator=(std::move(s));
}

tyString::~tyString()
{
	if (m_data)
		tyMemory::Free(m_data);
}

const char32_t* tyString::C_Str() const
{
	return m_data;
}

size_t tyString::Size() const
{
	return m_size;
}

void tyString::Reserve(size_t Size)
{
	if (Size > m_allocated)
	{
		Reallocate(Size);
		m_data[m_size] = 0;
	}
}

void tyString::Clear()
{
	m_data[0] = 0;
	m_size = 0;
}

void tyString::Assign(const char* s)
{
	Clear();
	Append(s);
}

void tyString::Assign(const wchar_t* s)
{
	Clear();
	Append(s);
}

void tyString::Assign(const char8_t* s)
{
	Clear();
	Append(s);
}

void tyString::Assign(const char16_t* s)
{
	Clear();
	Append(s);
}

void tyString::Assign(const char32_t* s)
{
	Clear();
	Append(s);
}

void tyString::Assign(const tyString& s)
{
	Clear();
	Append(s);
}

void tyString::Append(const char* str)
{
	size_t len = ty_string_getlen(str);

	unsigned char c1 = 0;
	unsigned char c2 = 0;
	unsigned char c3 = 0;
	unsigned char c4 = 0;
	for (size_t i = 0; i < len; ++i)
	{
		c1 = str[i];

		if (c1 <= 0x7F)
		{
			PushBack((char32_t)c1);
		}
		else
		{
			if ((c1 & 0xE0) == 0xC0) //2 bytes
			{
				++i;
				if (i < len)
				{
					c2 = str[i];
					if ((c2 & 0xC0) == 0x80)
					{
						char16_t wch = (c1 & 0x1F) << 6;
						wch |= (c2 & 0x3F);
						PushBack((char32_t)wch);
					}
				}
			}
			else if ((c1 & 0xF0) == 0xE0) //3
			{
				++i;
				if (i < len)
				{
					c2 = str[i];
					if ((c2 & 0xC0) == 0x80)
					{
						++i;
						if (i < len)
						{
							c3 = str[i];
							if ((c3 & 0xC0) == 0x80)
							{
								char16_t wch = (c1 & 0xF) << 12;
								wch |= (c2 & 0x3F) << 6;
								wch |= (c3 & 0x3F);
								PushBack((char32_t)wch);
							}
						}
					}
				}
			}
			else if ((c1 & 0xF8) == 0xF0) //4
			{
				++i;
				if (i < len)
				{
					c2 = str[i];
					if ((c2 & 0xC0) == 0x80)
					{
						++i;
						if (i < len)
						{
							c3 = str[i];
							if ((c3 & 0xC0) == 0x80)
							{
								++i;
								if (i < len)
								{
									c4 = str[i];
									if ((c4 & 0xC0) == 0x80)
									{
										uint32_t u = (c1 & 0x7) << 18;
										u |= (c2 & 0x3F) << 12;
										u |= (c3 & 0x3F) << 6;
										u |= (c4 & 0x3F);

										PushBack((char32_t)u);
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

void tyString::Append(const wchar_t* str)
{
	size_t len = ty_string_getlen(str);
	for (size_t i = 0u; i < len; ++i)
	{
		char16_t ch16 = str[i];
		if (ch16 < 0x80)
		{
			PushBack((char32_t)ch16);
		}
		else if (ch16 < 0x800)
		{
			PushBack((char32_t)ch16); //????
		}
		else if ((ch16 & 0xFC00) == 0xD800)
		{
			++i;
			if (i < len)
			{
				char16_t ch16_2 = str[i];
				if ((ch16_2 & 0xFC00) == 0xDC00)
				{
					uint32_t u = (ch16 - 0xD800) * 0x400;
					u += (ch16_2 - 0xDC00) + 0x10000;

					PushBack((char32_t)u);
				}
			}
		}
		else
		{
			PushBack((char32_t)ch16);
		}
	}
}

void tyString::Append(const char8_t* s)
{
	Append((const char*)s);
}

void tyString::Append(const char16_t* s)
{
	Append((const wchar_t*)s);
}

void tyString::Append(const char32_t* s)
{
	size_t len = ty_string_getlen(s);

	for (size_t i = 0; i < len; ++i)
	{
		PushBack(s[i]);
	}
}

void tyString::Append(const tyString& s)
{
	for (size_t i = 0; i < s.m_size; ++i)
	{
		PushBack(s.m_data[i]);
	}
}

void tyString::Append(int8_t i)
{
	char buf[32u];
	int nob = sprintf_s(buf, 32, "%i", i);
	if (nob)
	{
		for (int i = 0; i < nob; ++i)
		{
			PushBack((char32_t)buf[i]);
		}
	}
}

void tyString::Append(int16_t i)
{
	char buf[32u];
	int nob = sprintf_s(buf, 32, "%i", i);
	if (nob)
	{
		for (int i = 0; i < nob; ++i)
		{
			PushBack((char32_t)buf[i]);
		}
	}
}

void tyString::Append(int32_t i)
{
	char buf[32u];
	int nob = sprintf_s(buf, 32, "%i", i);
	if (nob)
	{
		for (int i = 0; i < nob; ++i)
		{
			PushBack((char32_t)buf[i]);
		}
	}
}

void tyString::Append(int64_t i)
{
	char buf[32u];
	int nob = sprintf_s(buf, 32, "%lli", i);
	if (nob)
	{
		for (int i = 0; i < nob; ++i)
		{
			PushBack((char32_t)buf[i]);
		}
	}
}

void tyString::Append(uint8_t i)
{
	char buf[32u];
	int nob = sprintf_s(buf, 32, "%u", i);
	if (nob)
	{
		for (int i = 0; i < nob; ++i)
		{
			PushBack((char32_t)buf[i]);
		}
	}
}

void tyString::Append(uint16_t i)
{
	char buf[32u];
	int nob = sprintf_s(buf, 32, "%u", i);
	if (nob)
	{
		for (int i = 0; i < nob; ++i)
		{
			PushBack((char32_t)buf[i]);
		}
	}
}
void tyString::Append(uint32_t i)
{
	char buf[32u];
	int nob = sprintf_s(buf, 32, "%u", i);
	if (nob)
	{
		for (int i = 0; i < nob; ++i)
		{
			PushBack((char32_t)buf[i]);
		}
	}
}
void tyString::Append(uint64_t i)
{
	char buf[32u];
	int nob = sprintf_s(buf, 32, "%llu", i);
	if (nob)
	{
		for (int i = 0; i < nob; ++i)
		{
			PushBack((char32_t)buf[i]);
		}
	}
}

void tyString::Append_hex(uint64_t i)
{
	char buf[32u];
	int nob = sprintf_s(buf, 32, "%jx", i);
	if (nob)
	{
		for (int i = 0; i < nob; ++i)
		{
			PushBack((char32_t)buf[i]);
		}
	}
}

void tyString::Append(float f)
{
	char buf[32u];
	int nob = sprintf_s(buf, 32, "%.7f", f);
	if (nob)
	{
		for (int i = 0; i < nob; ++i)
		{
			PushBack((char32_t)buf[i]);
		}
	}
}

void tyString::Append(double f)
{
	char buf[32u];
	int nob = sprintf_s(buf, 32, "%.12f", f);
	if (nob)
	{
		for (int i = 0; i < nob; ++i)
		{
			PushBack((char32_t)buf[i]);
		}
	}
}

void tyString::PushBack(char c)
{
	PushBack((char32_t)c);
}

void tyString::PushBack(wchar_t c)
{
	PushBack((char32_t)c);
}

void tyString::PushBack(char8_t c)
{
	PushBack((char32_t)c);
}

void tyString::PushBack(char16_t c)
{
	PushBack((char32_t)c);
}

void tyString::PushBack(char32_t c)
{
	size_t new_size = m_size + 1u;
	if ((new_size + 1u) > m_allocated)
		Reallocate((new_size + 1u) + (1 + (size_t)(m_size * 0.5f)));
	m_data[m_size] = c;
	m_size = new_size;
	m_data[m_size] = 0;
}

void tyString::PopBack()
{
	if (m_size)
	{
		--m_size;
		m_data[m_size] = 0;
	}
}

char32_t tyString::PopBackReturn()
{
	char32_t r = '?';
	if (m_size)
	{
		--m_size;
		r = m_data[m_size];
		m_data[m_size] = 0;
	}
	return r;
}

void tyString::PopBackBefore(char32_t before_this)
{
	if (Size())
		PopBack();

	if (Size())
	{
		for (size_t i = Size() - 1u; i >= 0u; --i)
		{
			if (m_data[i] == before_this)
				break;
			else
				PopBack();
			if (!i)
				break;
		}
	}
}

void tyString::PopFront()
{
	Erase(0u, 0u);
}

void tyString::Replace(char32_t a, char32_t b)
{
	for (size_t i = 0; i < m_size; ++i)
	{
		if (m_data[i] == a)
			m_data[i] = b;
	}
}

void tyString::ShrinkToFit()
{
	if (m_size)
	{
		if (m_allocated > (m_size + (1 + (uint32_t)(m_size * 0.5f))))
		{
			Reallocate(m_size + 1u);
			m_data[m_size] = 0;
		}
	}
}

void tyString::Erase(size_t begin, size_t end)
{
	size_t numCharsToDelete = end - begin + 1u; // delete first char: 0 - 0 + 1
	size_t next = end + 1u;
	for (size_t i = begin; i < m_size; ++i)
	{
		if (next < m_size)
		{
			m_data[i] = m_data[next];
			++next;
		}
	}
	m_size -= numCharsToDelete;
	m_data[m_size] = 0;
}

void tyString::Insert(const char32_t* str, size_t where)
{
	size_t str_len = ty_string_getlen(str);
	size_t new_size = str_len + m_size;
	if ((new_size + 1u) > m_allocated)
		Reallocate((new_size + 1u) + (1 + (uint32_t)(m_size * 0.5f)));

	size_t i = m_size;
	while (i >= where)
	{
		m_data[i + str_len] = m_data[i];
		if (i == 0)
			break;
		--i;
	}
	for (size_t i = 0; i < str_len; ++i)
	{
		m_data[i + where] = str[i];
	}
	m_size = new_size;
	m_data[m_size] = 0;
}

// Only for ASCII
void tyString::TrimSpaces()
{
	while (true)
	{
		if (isspace(m_data[0]))
			PopFront();
		else
			break;
	}

	while (true)
	{
		if (isspace(m_data[m_size - 1]))
			PopBack();
		else
			break;
	}
}

void tyString::ToLower()
{
	if (!m_size)
		return;
	for (size_t i = 0u; i < m_size; ++i)
	{
		auto c = m_data[i];
		if (c <= 'Z' && c >= 'A')
			m_data[i] += 32;
	}
}

void tyString::ToUpper()
{
	if (!m_size)
		return;
	for (size_t i = 0u; i < m_size; ++i)
	{
		auto c = m_data[i];
		if (c <= 'z' && c >= 'a')
			m_data[i] -= 32;
	}
}

void tyString::Flip()
{
	if (!m_size)
		return;
	tyString flippedStr;
	for (size_t i = m_size - 1u; i >= 0u; --i)
	{
		flippedStr += m_data[i];
		if (!i)
			break;
	}
	this->operator=(flippedStr);
}

void tyString::FlipSlash()
{
	if (!m_size)
		return;
	for (size_t i = 0u; i < m_size; ++i)
	{
		if (m_data[i] == '\\')
			m_data[i] = '/';
	}
}

void tyString::FlipBackslash()
{
	if (!m_size)
		return;
	for (size_t i = 0u; i < m_size; ++i)
	{
		if (m_data[i] == '/')
			m_data[i] = '\\';
	}
}

int32_t tyString::ToInt()
{
	size_t len = m_size;
	int32_t result = 0;
	int mul_val = 1;
	bool is_neg = m_data[0] == U'-';
	for (size_t i = 0, last = len - 1; i < len; ++i)
	{
		int char_value = (int)m_data[last] - 0x30;
		if (char_value >= 0 && char_value <= 9)
		{
			result += char_value * mul_val;
			mul_val *= 10;
		}
		--last;
	}
	if (is_neg)
		result = -result;
	return result;
}

int64_t tyString::ToIntll()
{
	size_t len = m_size;
	int64_t result = 0;
	int mul_val = 1;
	bool is_neg = m_data[0] == U'-';
	for (size_t i = 0, last = len - 1; i < len; ++i)
	{
		int char_value = (int)m_data[last] - 0x30;
		if (char_value >= 0 && char_value <= 9)
		{
			result += char_value * mul_val;
			mul_val *= 10;
		}
		--last;
	}
	if (is_neg)
		result = -result;
	return result;
}

uint32_t tyString::ToUint()
{
	size_t len = m_size;
	uint32_t result = 0;
	int mul_val = 1;
	bool is_neg = m_data[0] == U'-';
	for (size_t i = 0, last = len - 1; i < len; ++i)
	{
		int char_value = (int)m_data[last] - 0x30;
		if (char_value >= 0 && char_value <= 9)
		{
			result += char_value * mul_val;
			mul_val *= 10;
		}
		--last;
	}
	return result;
}

uint64_t tyString::ToUintll()
{
	size_t len = m_size;
	uint64_t result = 0;
	int mul_val = 1;
	bool is_neg = m_data[0] == U'-';
	for (size_t i = 0, last = len - 1; i < len; ++i)
	{
		int char_value = (int)m_data[last] - 0x30;
		if (char_value >= 0 && char_value <= 9)
		{
			result += char_value * mul_val;
			mul_val *= 10;
		}
		--last;
	}
	return result;
}

float tyString::ToFloat()
{
	float result = 0.f;
	auto ptr = m_data;
	bool is_negative = *ptr == U'-';

	if (is_negative)
		++ptr;

	int i = 0;
	while (*ptr >= U'0' && *ptr <= U'9')
	{
		i *= 10;
		i += *ptr - U'0';
		++ptr;
	}
	result = (float)i;

	i = 0;

	if (*ptr == U'.')
		++ptr;

	int part_2_count = 0;
	while (*ptr >= U'0' && *ptr <= U'9')
	{
		i *= 10;
		i += *ptr - U'0';
		++ptr;
		++part_2_count;
	}
	result += (float)i * (float)_internal::string_to_float_table[part_2_count];

	return is_negative ? -result : result;
}

double tyString::ToDouble()
{
	double result = 0.f;
	auto ptr = m_data;
	bool is_negative = *ptr == U'-';

	if (is_negative)
		++ptr;

	int i = 0;
	while (*ptr >= U'0' && *ptr <= U'9')
	{
		i *= 10;
		i += *ptr - U'0';
		++ptr;
	}
	result = (double)i;

	i = 0;

	if (*ptr == U'.')
		++ptr;

	int part_2_count = 0;
	while (*ptr >= U'0' && *ptr <= U'9')
	{
		i *= 10;
		i += *ptr - U'0';
		++ptr;
		++part_2_count;
	}
	result += (double)i * _internal::string_to_float_table[part_2_count];

	return is_negative ? -result : result;
}

tyString& tyString::operator=(const char* s)
{
	Clear();
	Append(s);
	return *this;
}

tyString& tyString::operator=(const wchar_t* s)
{
	Clear();
	Append(s);
	return *this;
}

tyString& tyString::operator=(const char8_t* s)
{
	Clear();
	Append(s);
	return *this;
}

tyString& tyString::operator=(const char16_t* s)
{
	Clear();
	Append(s);
	return *this;
}

tyString& tyString::operator=(const char32_t* s)
{
	Clear();
	Append(s);
	return *this;
}

tyString& tyString::operator=(const tyString& s)
{
	Clear();
	Append(s);
	return *this;
}

tyString& tyString::operator=(tyString&& s)
{
	if (m_data)
		tyMemory::Free(m_data);
	m_data = s.m_data;
	m_allocated = s.m_allocated;
	m_size = s.m_size;

	s.m_data = 0;
	s.m_allocated = 0;
	s.m_size = 0;
	return *this;
}

const char32_t& tyString::operator[](size_t i) const
{
	return m_data[i];
}

char32_t& tyString::operator[](size_t i)
{
	return m_data[i];
}

const char32_t& tyString::at(size_t i) const
{
	return m_data[i];
}

char32_t& tyString::at(size_t i)
{
	return m_data[i];
}

void tyString::operator+=(const char* s)
{
	Append(s);
}

void tyString::operator+=(const wchar_t* s)
{
	Append(s);
}

void tyString::operator+=(const char8_t* s)
{
	Append(s);
}

void tyString::operator+=(const char16_t* s)
{
	Append(s);
}

void tyString::operator+=(const char32_t* s)
{
	Append(s);
}

void tyString::operator+=(int8_t i)
{
	Append(i);
}

void tyString::operator+=(int16_t i)
{
	Append(i);
}

void tyString::operator+=(int32_t i)
{
	Append(i);
}

void tyString::operator+=(int64_t i)
{
	Append(i);
}

void tyString::operator+=(uint8_t i)
{
	Append(i);
}

void tyString::operator+=(uint16_t i)
{
	Append(i);
}

void tyString::operator+=(uint32_t i)
{
	Append(i);
}

void tyString::operator+=(uint64_t i)
{
	Append(i);
}

void tyString::operator+=(float f)
{
	Append(f);
}

void tyString::operator+=(double f)
{
	Append(f);
}

bool tyString::operator==(const tyString& other) const
{
	if (other.Size() != m_size)
		return false;

	const size_t sz = other.Size();
	const auto* ptr = other.m_data;
	for (size_t i = 0u; i < sz; ++i)
	{
		if (ptr[i] != m_data[i])
			return false;
	}

	return true;
}

bool tyString::operator!=(const tyString& other) const
{
	if (other.Size() != m_size)
		return true;

	const size_t sz = other.Size();
	const auto* ptr = other.m_data;
	for (size_t i = 0u; i < sz; ++i)
	{
		if (ptr[i] != m_data[i])
			return true;
	}

	return false;
}

void tyString::ToUtf8(tyStringA& stra) const
{
	stra.Clear();
	UC uc;
	auto ut = &g_UnicodeChars[0];
	for (size_t i = 0; i < m_size; ++i)
	{
		char32_t c = m_data[i];
		if (c >= 0x32000)
			c = '?';

		uc.integer = ut[c].m_utf8;

		if (uc.bytes[3]) stra.PushBack(uc.bytes[3]);
		if (uc.bytes[2]) stra.PushBack(uc.bytes[2]);
		if (uc.bytes[1]) stra.PushBack(uc.bytes[1]);
		if (uc.bytes[0]) stra.PushBack(uc.bytes[0]);
	}
}

void tyString::ToUtf16(tyStringW& strw) const
{
	strw.Clear();
	UC uc;
	auto ut = &g_UnicodeChars[0];
	for (size_t i = 0; i < m_size; ++i)
	{
		char32_t c = m_data[i];
		if (c >= 0x32000)
			c = '?';

		uc.integer = ut[c].m_utf16;

		if (uc.shorts[1]) strw.PushBack(uc.shorts[1]);
		if (uc.shorts[0]) strw.PushBack(uc.shorts[0]);
	}
}

tyString tyString::operator+(const char* v)
{
	tyString s = *this;
	s += v;
	return s;
}

tyString tyString::operator+(const wchar_t* v)
{
	tyString s = *this;
	s += v;
	return s;
}

tyString tyString::operator+(const char8_t* v)
{
	tyString s = *this;
	s += v;
	return s;
}

tyString tyString::operator+(const char16_t* v)
{
	tyString s = *this;
	s += v;
	return s;
}

tyString tyString::operator+(const char32_t* v)
{
	tyString s = *this;
	s += v;
	return s;
}

tyString tyString::operator+(int8_t v)
{
	tyString s = *this;
	s += v;
	return s;
}

tyString tyString::operator+(int16_t v)
{
	tyString s = *this;
	s += v;
	return s;
}

tyString tyString::operator+(int32_t v)
{
	tyString s = *this;
	s += v;
	return s;
}

tyString tyString::operator+(int64_t v)
{
	tyString s = *this;
	s += v;
	return s;
}

tyString tyString::operator+(uint8_t v)
{
	tyString s = *this;
	s += v;
	return s;
}

tyString tyString::operator+(uint16_t v)
{
	tyString s = *this;
	s += v;
	return s;
}

tyString tyString::operator+(uint32_t v)
{
	tyString s = *this;
	s += v;
	return s;
}

tyString tyString::operator+(uint64_t v)
{
	tyString s = *this;
	s += v;
	return s;
}

tyString tyString::operator+(float v)
{
	tyString s = *this;
	s += v;
	return s;
}

tyString tyString::operator+(double v)
{
	tyString s = *this;
	s += v;
	return s;
}


