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
class tyVec2
{
public:
	tyVec2() {}
	tyVec2(T v) : x(v), y(v) {}
	tyVec2(T _x, T _y) : x(_x), y(_y) {}
	tyVec2(const tyVec2& o) : x(o.x), y(o.y){}
	~tyVec2() {}
	template<typename other_type>
	void Set(other_type v) { x = y = static_cast<T>(v); }
	template<typename other_type>
	void Set(other_type _x, other_type _y) { x = static_cast<T>(_x); y = static_cast<T>(_y); }
	template<typename T2>
	tyVec2<T2> operator*(T2 v)const { tyVec2<T2> r; r.x = x * v; r.y = y * v; return r; }
	template<typename T2>
	tyVec2<T2> operator+(const tyVec2<T2>& v)const { tyVec2<T2> r(x + v.x, y + v.y); return r; }
	template<typename T2>
	tyVec2<T2> operator-(const tyVec2<T2>& v)const { tyVec2<T2> r(x - v.x, y - v.y); return r; }
	template<typename T2>
	tyVec2<T2> operator*(const tyVec2<T2>& v)const { tyVec2<T2> r(x * v.x, y * v.y); return r; }
	template<typename T2>
	tyVec2<T2> operator/(const tyVec2<T2>& v)const { tyVec2<T2> r(x / v.x, y / v.y); return r; }
	tyVec2<T> operator-()const { tyVec2<T> r(-x, -y); return r; }
	template<typename T2>
	tyVec2<T>& operator=(const tyVec2<T2>& v) { x = static_cast<T>(v.x); y = static_cast<T>(v.y); }
	template<typename T2>
	void operator+=(const tyVec2<T2>& v) { x += static_cast<T>(v.x); y += static_cast<T>(v.y); }
	template<typename T2>
	void operator-=(const tyVec2<T2>& v) { x -= static_cast<T>(v.x); y -= static_cast<T>(v.y); }
	template<typename T2>
	void operator*=(const tyVec2<T2>& v) { x *= static_cast<T>(v.x); y *= static_cast<T>(v.y); }
	template<typename T2>
	void operator/=(const tyVec2<T2>& v) { x /= static_cast<T>(v.x); y /= static_cast<T>(v.y); }
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
using tyVec2f = tyVec2<float32_t>;
using tyVec2i = tyVec2<int32_t>;
using tyVec2u = tyVec2<uint32_t>;

template<typename T>
class tyVec3
{
public:
	tyVec3() {}
	tyVec3(T v) : x(v), y(v), z(v) {}
	tyVec3(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}
	tyVec3(const tyVec3& o) : x(o.x), y(o.y), z(o.z) {}
	~tyVec3() {}
	template<typename other_type>
	void Set(other_type v) { x = y = z = static_cast<T>(v); }
	template<typename other_type>
	void Set(other_type _x, other_type _y, other_type _z) {
		x = static_cast<T>(_x); y = static_cast<T>(_y); z = static_cast<T>(_z);
	}
	template<typename T2>
	tyVec3<T2> operator*(T2 v)const { return tyVec3<T2>(x * v, y * v, z * v); }
	template<typename T2>
	tyVec3<T2> operator+(const tyVec3<T2>& v)const { return tyVec3<T2>(x + v, y + v, z + v); }
	template<typename T2>
	tyVec3<T2> operator-(const tyVec3<T2>& v)const { return tyVec3<T2>(x - v, y - v, z - v); }
	template<typename T2>
	tyVec3<T2> operator*(const tyVec3<T2>& v)const { return tyVec3<T2>(x * v, y * v, z * v); }
	template<typename T2>
	tyVec3<T2> operator/(const tyVec3<T2>& v)const { return tyVec3<T2>(x / v, y / v, z / v); }
	tyVec3<T> operator-()const { return tyVec3<T>(-x, -y, -z); }
	template<typename T2>
	tyVec3<T2>& operator=(const tyVec3<T2>& v)
	{
		x = static_cast<T>(v.x);
		y = static_cast<T>(v.y);
		z = static_cast<T>(v.z);
		return *this;
	}
	template<typename T2>
	void operator+=(const tyVec3<T2>& v)
	{
		x += static_cast<T>(v.x);
		y += static_cast<T>(v.y);
		z += static_cast<T>(v.z);
	}
	template<typename T2>
	void operator-=(const tyVec3<T2>& v)
	{
		x -= static_cast<T>(v.x);
		y -= static_cast<T>(v.y);
		z -= static_cast<T>(v.z);
	}
	template<typename T2>
	void operator*=(const tyVec3<T2>& v)
	{
		x *= static_cast<T>(v.x);
		y *= static_cast<T>(v.y);
		z *= static_cast<T>(v.z);
	}
	template<typename T2>
	void operator/=(const tyVec3<T2>& v)
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
	void Cross(const tyVec3<T2>& a, tyVec3<T>& out)const {
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
	T Dot(const tyVec3<T>& v)const { return (x * v.x) + (y * v.y) + (z * v.z); }
	T Length() const { return std::sqrt((x * x) + (y * y) + (z * z)); }

	T x = static_cast<T>(0);
	T y = static_cast<T>(0);
	T z = static_cast<T>(0);
	T* Data() { return &x; }
};
using tyVec3f = tyVec3<float32_t>;
using tyVec3i = tyVec3<int32_t>;
using tyVec3u = tyVec3<uint32_t>;

template<typename T>
class tyVec4
{
public:
	tyVec4() {}
	tyVec4(T v) : x(v), y(v), z(v), w(v) {}
	tyVec4(T _x, T _y, T _z, T _w) : x(_x), y(_y), z(_z), w(_w) {}
	tyVec4(const tyVec4& o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
	~tyVec4() {}
	template<typename other_type>
	void Set(other_type v) { x = y = z = w = static_cast<T>(v); }
	template<typename other_type>
	void Set(other_type _x, other_type _y, other_type _z, other_type _w) {
		x = static_cast<T>(_x); y = static_cast<T>(_y); z = static_cast<T>(_z); w = static_cast<T>(_w);
	}
	template<typename T2>
	tyVec4<T2> operator*(T2 v)const { return tyVec4<T2>(x * v, y * v, z * v); }
	template<typename T2>
	tyVec4<T2> operator+(const tyVec4<T2>& v)const { return tyVec4<T2>(x + v, y + v, z + v, w + v); }
	template<typename T2>
	tyVec4<T2> operator-(const tyVec4<T2>& v)const { return tyVec4<T2>(x - v, y - v, z - v, w - v); }
	template<typename T2>
	tyVec4<T2> operator*(const tyVec4<T2>& v)const { return tyVec4<T2>(x * v, y * v, z * v, w * v); }
	template<typename T2>
	tyVec4<T2> operator/(const tyVec4<T2>& v)const { return tyVec4<T2>(x / v, y / v, z / v, w / v); }
	tyVec4<T> operator-()const { return tyVec4<T>(-x, -y, -z, -w); }
	template<typename T2>
	tyVec4<T>& operator=(const tyVec4<T2>& v)
	{
		x = static_cast<T>(v.x);
		y = static_cast<T>(v.y);
		z = static_cast<T>(v.z);
		w = static_cast<T>(v.w);
		return *this;
	}
	template<typename T2>
	void operator+=(const tyVec4<T2>& v)
	{
		x += static_cast<T>(v.x);
		y += static_cast<T>(v.y);
		z += static_cast<T>(v.z);
		w += static_cast<T>(v.w);
	}
	template<typename T2>
	void operator-=(const tyVec4<T2>& v)
	{
		x -= static_cast<T>(v.x);
		y -= static_cast<T>(v.y);
		z -= static_cast<T>(v.z);
		w -= static_cast<T>(v.w);
	}
	template<typename T2>
	void operator*=(const tyVec4<T2>& v)
	{
		x *= static_cast<T>(v.x);
		y *= static_cast<T>(v.y);
		z *= static_cast<T>(v.z);
		w *= static_cast<T>(v.w);
	}
	template<typename T2>
	void operator/=(const tyVec4<T2>& v)
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
	void Cross(const tyVec4<T2>& a, tyVec4<T>& out)const {
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
	T Dot(const tyVec4<T>& v)const { return (x * v.x) + (y * v.y) + (z * v.z) + (w * v.w); }
	T Length() const { return std::sqrt((x * x) + (y * y) + (z * z) + (w * w)); }
	T x = static_cast<T>(0);
	T y = static_cast<T>(0);
	T z = static_cast<T>(0);
	T w = static_cast<T>(0);
	T* Data() { return &x; }
};
using tyVec4f = tyVec4<float32_t>;
using tyVec4i = tyVec4<int32_t>;
using tyVec4u = tyVec4<uint32_t>;

const tyVec4f tyVec4fFltMax = tyVec4f(FLT_MAX);
const tyVec4f tyVec4fFltMaxNeg = tyVec4f(-FLT_MAX);

#endif

