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

#ifndef _TY_MATH_V_H_
#define _TY_MATH_V_H_

template<typename T>
class tVec2_t
{
public:
	tVec2_t() {}
	tVec2_t(T v) : x(v), y(v) {}
	tVec2_t(T _x, T _y) : x(_x), y(_y) {}
	tVec2_t(const tVec2_t& o) : x(o.x), y(o.y){}
	~tVec2_t() {}
	template<typename other_type>
	void Set(other_type v) { x = y = static_cast<T>(v); }
	template<typename other_type>
	void Set(other_type _x, other_type _y) { x = static_cast<T>(_x); y = static_cast<T>(_y); }
	template<typename T2>
	tVec2_t<T2> operator*(T2 v)const { tVec2_t<T2> r; r.x = x * v; r.y = y * v; return r; }
	template<typename T2>
	tVec2_t<T2> operator+(const tVec2_t<T2>& v)const { tVec2_t<T2> r(x + v.x, y + v.y); return r; }
	template<typename T2>
	tVec2_t<T2> operator-(const tVec2_t<T2>& v)const { tVec2_t<T2> r(x - v.x, y - v.y); return r; }
	template<typename T2>
	tVec2_t<T2> operator*(const tVec2_t<T2>& v)const { tVec2_t<T2> r(x * v.x, y * v.y); return r; }
	template<typename T2>
	tVec2_t<T2> operator/(const tVec2_t<T2>& v)const { tVec2_t<T2> r(x / v.x, y / v.y); return r; }
	tVec2_t<T> operator-()const { tVec2_t<T> r(-x, -y); return r; }
	template<typename T2>
	tVec2_t<T>& operator=(const tVec2_t<T2>& v) { x = static_cast<T>(v.x); y = static_cast<T>(v.y); }
	template<typename T2>
	void operator+=(const tVec2_t<T2>& v) { x += static_cast<T>(v.x); y += static_cast<T>(v.y); }
	template<typename T2>
	void operator-=(const tVec2_t<T2>& v) { x -= static_cast<T>(v.x); y -= static_cast<T>(v.y); }
	template<typename T2>
	void operator*=(const tVec2_t<T2>& v) { x *= static_cast<T>(v.x); y *= static_cast<T>(v.y); }
	template<typename T2>
	void operator/=(const tVec2_t<T2>& v) { x /= static_cast<T>(v.x); y /= static_cast<T>(v.y); }
	template<typename T2>
	void operator+=(T2 v) { x += static_cast<T>(v); y += static_cast<T>(v); }
	template<typename T2>
	void operator-=(T2 v) { x -= static_cast<T>(v); y -= static_cast<T>(v); }
	template<typename T2>
	void operator/=(T2 v) { x /= static_cast<T>(v); y /= static_cast<T>(v); }
	template<typename T2>
	void operator*=(T2 v) { x *= static_cast<T>(v); y *= static_cast<T>(v); }
	void Normalize() {
		T len = std::sqrt(Dot());
		if (len > 0)
			len = 1.0 / len;
		x *= static_cast<T>(len);
		y *= static_cast<T>(len);
	}
	T Dot()const { return (x * x) + (y * y); }
	T Length() const { return std::sqrt((x * x) + (y * y)); }

	T x = static_cast<T>(0);
	T y = static_cast<T>(0);
	T* Data() { return &x; }
};
using tVec2 = tVec2_t<float64_t>;
using tVec2f = tVec2_t<float32_t>;
using tVec2i = tVec2_t<int32_t>;
using tVec2u = tVec2_t<uint32_t>;

template<typename T>
class tVec3_t
{
public:
	tVec3_t() {}
	tVec3_t(T v) : x(v), y(v), z(v) {}
	tVec3_t(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}
	tVec3_t(const tVec3_t& o) : x(o.x), y(o.y), z(o.z) {}
	~tVec3_t() {}
	template<typename other_type>
	void Set(other_type v) { x = y = z = static_cast<T>(v); }
	template<typename other_type>
	void Set(other_type _x, other_type _y, other_type _z) {
		x = static_cast<T>(_x); y = static_cast<T>(_y); z = static_cast<T>(_z);
	}
	template<typename T2>
	tVec3_t<T2> operator*(T2 v)const { return tVec3_t<T2>(x * v, y * v, z * v); }
	template<typename T2>
	tVec3_t<T2> operator+(const tVec3_t<T2>& v)const { return tVec3_t<T2>(x + v.x, y + v.y, z + v.z); }
	template<typename T2>
	tVec3_t<T2> operator-(const tVec3_t<T2>& v)const { return tVec3_t<T2>(x - v.x, y - v.y, z - v.z); }
	template<typename T2>
	tVec3_t<T2> operator*(const tVec3_t<T2>& v)const { return tVec3_t<T2>(x * v.x, y * v.y, z * v.z); }
	template<typename T2>
	tVec3_t<T2> operator/(const tVec3_t<T2>& v)const { return tVec3_t<T2>(x / v.x, y / v.y, z / v.z); }
	tVec3_t<T> operator-()const { return tVec3_t<T>(-x, -y, -z); }
	template<typename T2>
	tVec3_t<T2>& operator=(const tVec3_t<T2>& v)
	{
		x = static_cast<T>(v.x);
		y = static_cast<T>(v.y);
		z = static_cast<T>(v.z);
		return *this;
	}
	template<typename T2>
	void operator+=(const tVec3_t<T2>& v)
	{
		x += static_cast<T>(v.x);
		y += static_cast<T>(v.y);
		z += static_cast<T>(v.z);
	}
	template<typename T2>
	void operator-=(const tVec3_t<T2>& v)
	{
		x -= static_cast<T>(v.x);
		y -= static_cast<T>(v.y);
		z -= static_cast<T>(v.z);
	}
	template<typename T2>
	void operator*=(const tVec3_t<T2>& v)
	{
		x *= static_cast<T>(v.x);
		y *= static_cast<T>(v.y);
		z *= static_cast<T>(v.z);
	}
	template<typename T2>
	void operator/=(const tVec3_t<T2>& v)
	{
		x /= static_cast<T>(v.x);
		y /= static_cast<T>(v.y);
		z /= static_cast<T>(v.z);
	}

	template<typename T2>
	void operator+=(T2 v)
	{
		x += static_cast<T>(v);
		y += static_cast<T>(v);
		z += static_cast<T>(v);
	}
	template<typename T2>
	void operator-=(T2 v)
	{
		x -= static_cast<T>(v);
		y -= static_cast<T>(v);
		z -= static_cast<T>(v);
	}
	template<typename T2>
	void operator/=(T2 v)
	{
		x /= static_cast<T>(v);
		y /= static_cast<T>(v);
		z /= static_cast<T>(v);
	}
	template<typename T2>
	void operator*=(T2 v)
	{
		x *= static_cast<T>(v);
		y *= static_cast<T>(v);
		z *= static_cast<T>(v);
	}

	template<typename T2>
	void Cross(const tVec3_t<T2>& a, tVec3_t<T>& out)const {
		out.x = (y * static_cast<T>(a.z)) - (z * static_cast<T>(a.y));
		out.y = (z * static_cast<T>(a.x)) - (x * static_cast<T>(a.z));
		out.z = (x * static_cast<T>(a.y)) - (y * static_cast<T>(a.x));
	}

	void Normalize()
	{
		T len = std::sqrt(Dot());
		if (len > 0)
			len = static_cast<T>(1.0) / len;
		x *= static_cast<T>(len);
		y *= static_cast<T>(len);
		z *= static_cast<T>(len);
	}

	T Dot()const { return (x * x) + (y * y) + (z * z); }
	T Dot(const tVec3_t<T>& v)const { return (x * v.x) + (y * v.y) + (z * v.z); }
	T Length() const { return std::sqrt((x * x) + (y * y) + (z * z)); }

	T x = static_cast<T>(0);
	T y = static_cast<T>(0);
	T z = static_cast<T>(0);
	T* Data() { return &x; }
};
using tVec3 = tVec3_t<float64_t>;
using tVec3f = tVec3_t<float32_t>;
using tVec3i = tVec3_t<int32_t>;
using tVec3u = tVec3_t<uint32_t>;

template<typename T>
class tVec4_t
{
public:
	tVec4_t() {}
	tVec4_t(T v) : x(v), y(v), z(v), w(v) {}
	tVec4_t(T _x, T _y, T _z, T _w) : x(_x), y(_y), z(_z), w(_w) {}
	tVec4_t(const tVec4_t& o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
	~tVec4_t() {}
	template<typename other_type>
	void Set(other_type v) { x = y = z = w = static_cast<T>(v); }
	void Set(T _x, T _y, T _z, T _w) {
		x = _x; y = _y; z = _z; w = _w;
	}
	template<typename T2>
	tVec4_t<T2> operator*(T2 v)const { return tVec4_t<T2>(x * v, y * v, z * v, w * v); }
	template<typename T2>
	tVec4_t<T2> operator+(const tVec4_t<T2>& v)const { return tVec4_t<T2>(x + v.x, y + v.y, z + v.z, w + v.z); }
	template<typename T2>
	tVec4_t<T2> operator-(const tVec4_t<T2>& v)const { return tVec4_t<T2>(x - v.x, y - v.y, z - v.z, w - v.z); }
	template<typename T2>
	tVec4_t<T2> operator*(const tVec4_t<T2>& v)const { return tVec4_t<T2>(x * v.x, y * v.y, z * v.z, w * v.z); }
	template<typename T2>
	tVec4_t<T2> operator/(const tVec4_t<T2>& v)const { return tVec4_t<T2>(x / v.x, y / v.y, z / v.z, w / v.z); }
	tVec4_t<T> operator-()const { return tVec4_t<T>(-x, -y, -z, -w); }
	template<typename T2>
	tVec4_t<T>& operator=(const tVec4_t<T2>& v)
	{
		x = static_cast<T>(v.x);
		y = static_cast<T>(v.y);
		z = static_cast<T>(v.z);
		w = static_cast<T>(v.w);
		return *this;
	}
	template<typename T2>
	void operator+=(const tVec4_t<T2>& v)
	{
		x += static_cast<T>(v.x);
		y += static_cast<T>(v.y);
		z += static_cast<T>(v.z);
		w += static_cast<T>(v.w);
	}
	template<typename T2>
	void operator-=(const tVec4_t<T2>& v)
	{
		x -= static_cast<T>(v.x);
		y -= static_cast<T>(v.y);
		z -= static_cast<T>(v.z);
		w -= static_cast<T>(v.w);
	}
	template<typename T2>
	void operator*=(const tVec4_t<T2>& v)
	{
		x *= static_cast<T>(v.x);
		y *= static_cast<T>(v.y);
		z *= static_cast<T>(v.z);
		w *= static_cast<T>(v.w);
	}
	template<typename T2>
	void operator/=(const tVec4_t<T2>& v)
	{
		x /= static_cast<T>(v.x);
		y /= static_cast<T>(v.y);
		z /= static_cast<T>(v.z);
		w /= static_cast<T>(v.w);
	}

	template<typename T2>
	void operator+=(T2 v)
	{
		x += static_cast<T>(v);
		y += static_cast<T>(v);
		z += static_cast<T>(v);
		w += static_cast<T>(v);
	}
	template<typename T2>
	void operator-=(T2 v)
	{
		x -= static_cast<T>(v);
		y -= static_cast<T>(v);
		z -= static_cast<T>(v);
		w -= static_cast<T>(v);
	}
	template<typename T2>
	void operator/=(T2 v)
	{
		x /= static_cast<T>(v);
		y /= static_cast<T>(v);
		z /= static_cast<T>(v);
		w /= static_cast<T>(v);
	}
	template<typename T2>
	void operator*=(T2 v)
	{
		x *= static_cast<T>(v);
		y *= static_cast<T>(v);
		z *= static_cast<T>(v);
		w *= static_cast<T>(v);
	}

	template<typename T2>
	void Cross(const tVec4_t<T2>& a, tVec4_t<T>& out)const {
		out.x = (y * static_cast<T>(a.z)) - (z * static_cast<T>(a.y));
		out.y = (z * static_cast<T>(a.x)) - (x * static_cast<T>(a.z));
		out.z = (x * static_cast<T>(a.y)) - (y * static_cast<T>(a.x));
	}

	void Normalize()
	{
		T len = std::sqrt(Dot());
		if (len > 0)
			len = static_cast<T>(1.0) / len;
		x *= static_cast<T>(len);
		y *= static_cast<T>(len);
		z *= static_cast<T>(len);
		w *= static_cast<T>(len);
	}

	T Dot()const { return (x * x) + (y * y) + (z * z) + (w * w); }
	T Dot(const tVec4_t<T>& v)const { return (x * v.x) + (y * v.y) + (z * v.z) + (w * v.w); }
	T Length() const { return std::sqrt((x * x) + (y * y) + (z * z) + (w * w)); }
	T x = static_cast<T>(0);
	T y = static_cast<T>(0);
	T z = static_cast<T>(0);
	T w = static_cast<T>(0);
	T* Data() { return &x; }
};
using tVec4 = tVec4_t<float64_t>;
using tVec4f = tVec4_t<float32_t>;
using tVec4i = tVec4_t<int32_t>;
using tVec4u = tVec4_t<uint32_t>;

const tVec4f tVec4fFltMax = tVec4f(FLT_MAX);
const tVec4f tVec4fFltMaxNeg = tVec4f(-FLT_MAX);

T_FORCEINLINE tVec4f operator*(const float32_t& s, const tVec4f& v) { return v * s; }

#endif

