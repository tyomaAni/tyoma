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

#ifndef _TY_MATH_H_
#define _TY_MATH_H_

#include <cmath>
#include <limits>
#define tInfinity std::numeric_limits<real_t>::infinity()
#define tEpsilon std::numeric_limits<real_t>::epsilon()

const float32_t PIf = static_cast<float32_t>(3.14159265358979323846);
const float32_t PIfHalf = static_cast<float32_t>(3.14159265358979323846 * 0.5);
const float32_t PIfPIf = 6.2831853f;
const float64_t PI = 3.14159265358979323846;
const float64_t PIHalf = 3.14159265358979323846 * 0.5;
const float64_t PIPI = 6.283185307179586476925286766559;

#include "Math/Vector.h"
#include "Math/Quaternion.h"
#include "Math/Matrix.h"

class T_API tMath
{
public:
	static float32_t DegToRad(float32_t degrees);
	static float64_t DegToRad(float64_t degrees);
	static float32_t RadToDeg(float32_t radians);
	static float64_t RadToDeg(float64_t radians);

	static float32_t Abs(float32_t);
	static float64_t Abs(float64_t);
	static int32_t Abs(int32_t);

	// Expect value form -1 to +1
	//static float32_t Acos(float32_t);
	//static float64_t Acos(float64_t);

	//// Expect value form -1 to +1
	//static float32_t Asin(float32_t);
	//static float64_t Asin(float64_t);

	//// Expect value form -2 to +2
	//static float32_t Atan(float32_t);
	//static float64_t Atan(float64_t);

	//// Expect value form -1 to +1
	//static float32_t Atan2(float32_t y, float32_t x);
	//static float64_t Atan2(float64_t y, float64_t x);

	static float32_t Clamp(float32_t, float32_t mn, float32_t mx);
	static float64_t Clamp(float64_t, float64_t mn, float64_t mx);

	// Expect value from -PI to +PI
	// It will do this
	// if (v > 3.141f) v = 3.141f;
	// if (v < -3.141f) v = -3.141f;
	/*static float32_t cos(float32_t);
	static float64_t cos(float64_t);
	static float32_t sin(float32_t);
	static float64_t sin(float64_t);
	static float32_t tan(float32_t);
	static float64_t tan(float64_t);*/

	static void Cross(const tVec3& v1, const tVec3& v2, tVec3& r);
	static void Cross(const tVec3f& v1, const tVec3f& v2, tVec3f& r);
	static void Cross(const tVec4& v1, const tVec4& v2, tVec4& r);
	static void Cross(const tVec4f& v1, const tVec4f& v2, tVec4f& r);
	static void Cross(const tVec3& v1, const tVec4& v2, tVec3& r);
	static void Cross(const tVec3f& v1, const tVec4f& v2, tVec3f& r);

	static real_t Distance(const tVec3& v1, const tVec3& v2);
	static real_t Distance(const tVec4& v1, const tVec4& v2);
	static real_t Distance(const tVec3& v1, const tVec4& v2);
	static float32_t Distance(const tVec3f& v1, const tVec3f& v2);
	static float32_t Distance(const tVec4f& v1, const tVec4f& v2);
	static float32_t Distance(const tVec3f& v1, const tVec4f& v2);

	static real_t Dot(const tVec3& v1, const tVec3& v2);
	static real_t Dot(const tVec4& v1, const tVec4& v2);
	static real_t Dot(const tVec3& v1, const tVec4& v2);
	static float32_t Dot(const tVec3f& v1, const tVec3f& v2);
	static float32_t Dot(const tVec4f& v1, const tVec4f& v2);
	static float32_t Dot(const tVec3f& v1, const tVec4f& v2);
	static float32_t Dot(const tQuaternion& v1, const tQuaternion& v2);

	static real_t Length(const tVec3& v);
	static real_t Length(const tVec4& v);
	static float32_t Length(const tVec3f& v);
	static float32_t Length(const tVec4f& v);
	static float32_t Length(const tQuaternion& v);

	// wikipedia:
	// Imprecise method, which does not guarantee v = v1 when t = 1, due to floating-point arithmetic error.
	// This method is monotonic. This form may be used when the hardware has a native fused multiply-add instruction.
	// 
	//  ... it has only 1 multiplication. lerp2 has 2 multiplications.
	static float32_t Lerp1(float32_t x, float32_t y, float32_t t);
	static float64_t Lerp1(float64_t x, float64_t y, float64_t t);
	static void Lerp1(const tVec3& x, const tVec3& y, real_t t, tVec3& r);
	static void Lerp1(const tVec3& x, const tVec4& y, real_t t, tVec3& r);
	static void Lerp1(const tVec4& x, const tVec4& y, real_t t, tVec4& r);
	static void Lerp1(const tVec3f& x, const tVec3f& y, float32_t t, tVec3f& r);
	static void Lerp1(const tVec3f& x, const tVec4f& y, float32_t t, tVec3f& r);
	static void Lerp1(const tVec4f& x, const tVec4f& y, float32_t t, tVec4f& r);
	static void Lerp1(const tQuaternion& x, const tQuaternion& y, float32_t t, tQuaternion& r);

	// wikipedia:
	// Precise method, which guarantees v = v1 when t = 1. This method is monotonic only when v0 * v1 < 0.
	// Lerping between same values might not produce the same value
	static float32_t Lerp2(float32_t x, float32_t y, float32_t t);
	static float64_t Lerp2(float64_t x, float64_t y, float64_t t);
	static void Lerp2(const tVec3& x, const tVec3& y, real_t t, tVec3& r);
	static void Lerp2(const tVec3& x, const tVec4& y, real_t t, tVec3& r);
	static void Lerp2(const tVec4& x, const tVec4& y, real_t t, tVec4& r);
	static void Lerp2(const tVec3f& x, const tVec3f& y, float32_t t, tVec3f& r);
	static void Lerp2(const tVec3f& x, const tVec4f& y, float32_t t, tVec3f& r);
	static void Lerp2(const tVec4f& x, const tVec4f& y, float32_t t, tVec4f& r);
	static void Lerp2(const tQuaternion& x, const tQuaternion& y, float32_t t, tQuaternion& r);

	static void Normalize(tVec3& v);
	static void Normalize(tVec3f& v);
	static void Normalize(tVec4& v);
	static void Normalize(tVec4f& v);
	static void Normalize(tQuaternion& v);

	static void SetRotation(tQuaternion&, float32_t x, float32_t y, float32_t z);
	static void SetRotation(tQuaternion&, const tVec3& axis, const real_t& _angle);
	static void SetRotation(tQuaternion&, const tVec3f& axis, const float32_t& _angle);
	static void SetRotation(tQuaternion&, const tVec4& axis, const real_t& _angle);
	static void SetRotation(tQuaternion&, const tVec4f& axis, const float32_t& _angle);
	static void SetRotation(tMat4&, const tQuaternion&);
	// from irrlicht?
	static void Slerp(tQuaternion& q1, tQuaternion& q2, float32_t time, float32_t threshold, tQuaternion& r);

	static void Mul(const tMat4&, const tMat4&, tMat4&);
	static void Mul(const tMat4&, const tVec3&, tVec3&);
	static void Mul(const tMat4&, const tVec4&, tVec4&);
	static void Mul(const tMat4&, const tVec3f&, tVec3f&);
	static void Mul(const tQuaternion&, const tQuaternion&, tQuaternion&);

	static void Transpose(tMat4&);

	static void Invert(tMat4&);

	static void PerspectiveLH(tMat4&, real_t FOV, real_t aspect, real_t Near, real_t Far);
	static void PerspectiveRH(tMat4&, real_t FOV, real_t aspect, real_t Near, real_t Far);
	static void LookAtLH(tMat4&, const tVec4& eye, const tVec4& center, const tVec4& up);
	static void LookAtRH(tMat4&, const tVec4& eye, const tVec4& center, const tVec4& up);
	static void OrthoLH(tMat4&, float32_t width, float32_t height, float32_t near, float32_t far);
	static void OrthoRH(tMat4&, float32_t width, float32_t height, float32_t near, float32_t far);
	static void OrthoOfCenterLH(tMat4&, float32_t left, float32_t right, float32_t top, float32_t bottom, float32_t near, float32_t far);
	static void OrthoOfCenterRH(tMat4&, float32_t left, float32_t right, float32_t top, float32_t bottom, float32_t near, float32_t far);

	static float32_t CoordToUV(float32_t value, float32_t textureSz);

	//static bool PointInRect(const slPoint&, const slRect&);
	//static bool PointInRect(const slPoint&, const tVec4f&);
	static bool PointInRect(const tVec2f&, const tVec4f&);
};

#endif

