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

#ifndef _TY_MATH_Q_H_
#define _TY_MATH_Q_H_

class T_API tQuaternion
{
public:
	tQuaternion();
	tQuaternion(const tQuaternion& o);
	tQuaternion(float32_t ax, float32_t ay, float32_t az);
	tQuaternion(float32_t x, float32_t y, float32_t z, float32_t w);
	void Set(const tVec4& v);
	void Set(const tVec4f& v);
	void Set(float32_t _x, float32_t _y, float32_t _z);
	void Identity();
	float32_t Length()const;
	tQuaternion& operator=(const tQuaternion& o);
	tQuaternion operator*(const tQuaternion& q)const;
	tQuaternion operator*(float32_t s) const;
	void operator*=(const tQuaternion& q);
	bool operator!=(const tQuaternion& q)const;
	bool operator==(const tQuaternion& q)const;
	tQuaternion operator+(const tQuaternion& o) const;
	tQuaternion operator-(const tQuaternion& o) const;
	tQuaternion operator-();
	float32_t operator[](uint32_t index) const;
	float32_t& operator[](uint32_t index);
	void Normalize();

	float32_t x, y, z, w;
	float32_t* Data() { return &x; }
};

#endif

