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

#ifndef _TY_STRING_H_
#define _TY_STRING_H_

// just Data and Size
// it will use in tyString
class TY_API tyStringA
{
	void Reallocate(size_t new_allocated);
public:
	tyStringA();
	~tyStringA();
	tyStringA(const char*);
	tyStringA(const char8_t*);
	tyStringA(const tyStringA&);
	tyStringA(tyStringA&&);
	void Assign(const tyStringA&);
	void Assign(const char*);
	void Assign(const char8_t*);
	void Append(const tyStringA&);
	void Append(const char*);
	void Append(const char8_t*);
	void Append(float);
	void Append(double);
	void Append(uint32_t);
	void PushBack(char8_t);
	void Clear();
	const char8_t& operator[](size_t i) const { return m_data[i]; }
	char8_t& operator[](size_t i) { return m_data[i]; }
	size_t Size() const { return m_size; }
	char* Data() { return (char*)m_data; }
	const char* C_Str() { return (const char*)m_data; }
	bool operator==(const tyStringA& other) const {
		if (other.Size() != m_size)
			return false;
		const size_t sz = other.Size();
		const auto* ptr = other.m_data;
		for (size_t i = 0u; i < sz; ++i) {
			if (ptr[i] != m_data[i])
				return false;
		}
		return true;
	}
	bool operator!=(const tyStringA& other) const {
		if (other.Size() != m_size)
			return true;
		const size_t sz = other.Size();
		const auto* ptr = other.m_data;
		for (size_t i = 0u; i < sz; ++i) {
			if (ptr[i] != m_data[i])
				return true;
		}
		return false;
	}
	tyStringA& operator=(const tyStringA&);
	tyStringA& operator=(tyStringA&&);
	size_t m_allocated = 0;
	size_t m_size = 0;
	char8_t* m_data = nullptr;
};

class TY_API tyStringW
{
	void Reallocate(size_t new_allocated);
public:
	tyStringW();
	~tyStringW();
	tyStringW(const tyStringW&);
	tyStringW(tyStringW&&);
	void Assign(const tyStringW&);
	void Append(const tyStringW&);
	void PushBack(char16_t);
	void Clear();
	const char16_t& operator[](size_t i) const { return m_data[i]; }
	char16_t& operator[](size_t i) { return m_data[i]; }
	size_t Size() const { return m_size; }
	bool operator==(const tyStringW& other) const {
		if (other.Size() != m_size)
			return false;
		const size_t sz = other.Size();
		const auto* ptr = other.m_data;
		for (size_t i = 0u; i < sz; ++i) {
			if (ptr[i] != m_data[i])
				return false;
		}
		return true;
	}
	bool operator!=(const tyStringW& other) const {
		if (other.Size() != m_size)
			return true;
		const size_t sz = other.Size();
		const auto* ptr = other.m_data;
		for (size_t i = 0u; i < sz; ++i) {
			if (ptr[i] != m_data[i])
				return true;
		}
		return false;
	}
	tyStringW& operator=(const tyStringW&);
	tyStringW& operator=(tyStringW&&);
	size_t m_allocated = 0;
	size_t m_size = 0;
	char16_t* m_data = nullptr;
};

// Unicode string.
class TY_API tyString
{
	size_t m_size = 0;
	size_t m_allocated = 0;
	char32_t* m_data = nullptr;

	void Reallocate(size_t new_allocated);
public:
	tyString();
	tyString(const char*);
	tyString(const wchar_t*);
	tyString(const char8_t*);
	tyString(const char16_t*);
	tyString(const char32_t*);
	tyString(const tyString&);
	tyString(tyString&&);
	~tyString();

	const char32_t* C_Str()const;
	size_t Size() const;
	void Reserve(size_t Size);
	void Clear();

	void Assign(const char*);
	void Assign(const wchar_t*);
	void Assign(const char8_t*);
	void Assign(const char16_t*);
	void Assign(const char32_t*);
	void Assign(const tyString&);

	void Append(const char*);
	void Append(const wchar_t*);
	void Append(const char8_t*);
	void Append(const char16_t*);
	void Append(const char32_t*);
	void Append(const tyString&);
	void Append(int8_t);
	void Append(int16_t);
	void Append(int32_t);
	void Append(int64_t);
	void Append(uint8_t);
	void Append(uint16_t);
	void Append(uint32_t);
	void Append(uint64_t);
	void Append_hex(uint64_t);
	void Append(float);
	void Append(double);

	void PushBack(char);
	void PushBack(wchar_t);
	void PushBack(char8_t);
	void PushBack(char16_t);
	void PushBack(char32_t);

	void PopBack();
	char32_t PopBackReturn();
	void PopBackBefore(char32_t before_this);
	void PopFront();
	void Replace(char32_t a, char32_t b);
	void ShrinkToFit();

	void Erase(size_t begin, size_t end);
	void Insert(const char32_t* str, size_t where);
	void TrimSpaces();

	// Only for ASCII
	void ToLower();
	void ToUpper();
	void Flip();
	void FlipSlash();
	void FlipBackslash();
	int32_t ToInt();
	int64_t ToIntll();
	uint32_t ToUint();
	uint64_t ToUintll();
	float ToFloat();
	double ToDouble();

	tyString& operator=(const char*);
	tyString& operator=(const wchar_t*);
	tyString& operator=(const char8_t*);
	tyString& operator=(const char16_t*);
	tyString& operator=(const char32_t*);
	tyString& operator=(const tyString&);
	tyString& operator=(tyString&&);

	const char32_t& operator[](size_t i) const;
	char32_t& operator[](size_t i);
	const char32_t& at(size_t i) const;
	char32_t& at(size_t i);

	void operator+=(const char*);
	void operator+=(const wchar_t*);
	void operator+=(const char8_t*);
	void operator+=(const char16_t*);
	void operator+=(const char32_t*);
	void operator+=(int8_t);
	void operator+=(int16_t);
	void operator+=(int32_t);
	void operator+=(int64_t);
	void operator+=(uint8_t);
	void operator+=(uint16_t);
	void operator+=(uint32_t);
	void operator+=(uint64_t);
	void operator+=(float);
	void operator+=(double);

	tyString operator+(const char*);
	tyString operator+(const wchar_t*);
	tyString operator+(const char8_t*);
	tyString operator+(const char16_t*);
	tyString operator+(const char32_t*);
	tyString operator+(int8_t);
	tyString operator+(int16_t);
	tyString operator+(int32_t);
	tyString operator+(int64_t);
	tyString operator+(uint8_t);
	tyString operator+(uint16_t);
	tyString operator+(uint32_t);
	tyString operator+(uint64_t);
	tyString operator+(float);
	tyString operator+(double);

	bool operator==(const tyString& other) const;
	bool operator!=(const tyString& other) const;

	void ToUtf8(tyStringA&) const;
	void ToUtf16(tyStringW&) const;
};


#endif

