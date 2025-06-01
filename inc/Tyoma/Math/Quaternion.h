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

class tyQuaternion
{
public:
	tyQuaternion() 
	{
		Identity();
	}

	tyQuaternion(const tyQuaternion& o) :
		x(o.x),
		y(o.y),
		z(o.z),
		w(o.w)
	{
	}

	tyQuaternion(float32_t ax, float32_t ay, float32_t az)
	{
		this->Set(ax, ay, az);
	}

	tyQuaternion(float32_t x, float32_t y, float32_t z, float32_t w) :
		x(x),
		y(y),
		z(z),
		w(w)
	{
	}

	void Set(const tyVec4& v) { Set((float32_t)v.x, (float32_t)v.y, (float32_t)v.z); }
	void Set(const tyVec4f& v) { Set(v.x, v.y, v.z); }
	void Set(float32_t _x, float32_t _y, float32_t _z)
	{
		_x *= 0.5f;
		_y *= 0.5f;
		_z *= 0.5f;
		float32_t c1 = cos(_x);
		float32_t c2 = cos(_y);
		float32_t c3 = cos(_z);
		float32_t s1 = sin(_x);
		float32_t s2 = sin(_y);
		float32_t s3 = sin(_z);
		w = (c1 * c2 * c3) + (s1 * s2 * s3);
		x = (s1 * c2 * c3) - (c1 * s2 * s3);
		y = (c1 * s2 * c3) + (s1 * c2 * s3);
		z = (c1 * c2 * s3) - (s1 * s2 * c3);
	}

	void Identity()
	{
		x = y = z = 0.f;
		w = 1.f;
	}

	float32_t Length()const
	{
		return (x * x) + (y * y) + (z * z) + (w * w);
	}

	tyQuaternion& operator=(const tyQuaternion& o)
	{
		x = o.x;
		y = o.y;
		z = o.z;
		w = o.w;
		return *this;
	}

	tyQuaternion operator*(const tyQuaternion& q)const
	{
		return tyQuaternion(
			w * q.x + x * q.w + y * q.z - z * q.y,
			w * q.y + y * q.w + z * q.x - x * q.z,
			w * q.z + z * q.w + x * q.y - y * q.x,
			w * q.w - x * q.x - y * q.y - z * q.z);
	}

	tyQuaternion operator*(float32_t s) const
	{
		return tyQuaternion(s * x, s * y, s * z, s * w);
	}

	void operator*=(const tyQuaternion& q)
	{
		x = w * q.x + x * q.w + y * q.z - z * q.y;
		y = w * q.y + y * q.w + z * q.x - x * q.z;
		z = w * q.z + z * q.w + x * q.y - y * q.x;
		w = w * q.w - x * q.x - y * q.y - z * q.z;
	}

	bool operator!=(const tyQuaternion& q)const
	{
		if (x != q.x) return true;
		if (y != q.y) return true;
		if (z != q.z) return true;
		if (w != q.w) return true;
		return false;
	}

	bool operator==(const tyQuaternion& q)const
	{
		if (x != q.x) return false;
		if (y != q.y) return false;
		if (z != q.z) return false;
		if (w != q.w) return false;
		return true;
	}

	tyQuaternion operator+(const tyQuaternion& o) const
	{
		return tyQuaternion(
			x + o.x,
			y + o.y,
			z + o.z,
			w + o.w);
	}

	tyQuaternion operator-(const tyQuaternion& o) const
	{
		return tyQuaternion(
			x - o.x,
			y - o.y,
			z - o.z,
			w - o.w);
	}

	tyQuaternion operator-()
	{
		x = -x;
		y = -y;
		z = -z;
		return tyQuaternion(x, y, z, w);
	}

	float32_t operator[](uint32_t index) const
	{
		TY_ASSERT_ST((index >= 0) && (index < 4));
		return (&x)[index];
	}

	float32_t& operator[](uint32_t index)
	{
		TY_ASSERT_ST((index >= 0) && (index < 4));
		return (&x)[index];
	}

	void Normalize()
	{
		float32_t len = this->Length();
		if (len) {
			float32_t len2 = 1.f / len;
			x *= len2;
			y *= len2;
			z *= len2;
			w *= len2;
		}
	}

	float32_t x, y, z, w;
	float32_t* Data() { return &x; }
};

#endif

