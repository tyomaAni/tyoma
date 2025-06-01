#define T_EXPORT
#include "T.h"
#include "T/Math.h"

#include "math_private.h"
#pragma comment(lib, "T.Base.lib")

float32_t tMath::DegToRad(float32_t degrees)
{
	return degrees * (PIf / 180.f);
}

float64_t tMath::DegToRad(float64_t degrees)
{
	return degrees * (PI / 180.0);
}

float32_t tMath::RadToDeg(float32_t radians)
{
	return radians * (180.f / PIf);
}

float64_t tMath::RadToDeg(float64_t radians)
{
	return radians * (180.0 / PI);
}

float32_t tMath::Abs(float32_t x)
{
	uint32_t ix;
	GET_FLOAT_WORD(ix, x);
	SET_FLOAT_WORD(x, ix & 0x7fffffff);
	return x;
}

float64_t tMath::Abs(float64_t x)
{
	uint32_t high;
	GET_HIGH_WORD(high, x);
	SET_HIGH_WORD(x, high & 0x7fffffff);
	return x;
}

int32_t tMath::Abs(int32_t v)
{
	return(v < 0 ? -v : v);
}

float32_t tMath::Clamp(float32_t v, float32_t mn, float32_t mx)
{
	if (v < mn)
		return mn;
	else if (v > mx)
		return mx;
	return v;
}

float64_t tMath::Clamp(float64_t v, float64_t mn, float64_t mx)
{
	if (v < mn)
		return mn;
	else if (v > mx)
		return mx;
	return v;
}

void tMath::Cross(const tVec3& v1, const tVec3& v2, tVec3& r)
{
	r.x = (v1.y * v2.z) - (v1.z * v2.y);
	r.y = (v1.z * v2.x) - (v1.x * v2.z);
	r.z = (v1.x * v2.y) - (v1.y * v2.x);
}

void tMath::Cross(const tVec3f& v1, const tVec3f& v2, tVec3f& r)
{
	r.x = (v1.y * v2.z) - (v1.z * v2.y);
	r.y = (v1.z * v2.x) - (v1.x * v2.z);
	r.z = (v1.x * v2.y) - (v1.y * v2.x);
}

void tMath::Cross(const tVec4& v1, const tVec4& v2, tVec4& r)
{
	r.x = (v1.y * v2.z) - (v1.z * v2.y);
	r.y = (v1.z * v2.x) - (v1.x * v2.z);
	r.z = (v1.x * v2.y) - (v1.y * v2.x);
}

void tMath::Cross(const tVec4f& v1, const tVec4f& v2, tVec4f& r)
{
	r.x = (v1.y * v2.z) - (v1.z * v2.y);
	r.y = (v1.z * v2.x) - (v1.x * v2.z);
	r.z = (v1.x * v2.y) - (v1.y * v2.x);
}

void tMath::Cross(const tVec3& v1, const tVec4& v2, tVec3& r)
{
	r.x = (v1.y * v2.z) - (v1.z * v2.y);
	r.y = (v1.z * v2.x) - (v1.x * v2.z);
	r.z = (v1.x * v2.y) - (v1.y * v2.x);
}

void tMath::Cross(const tVec3f& v1, const tVec4f& v2, tVec3f& r)
{
	r.x = (v1.y * v2.z) - (v1.z * v2.y);
	r.y = (v1.z * v2.x) - (v1.x * v2.z);
	r.z = (v1.x * v2.y) - (v1.y * v2.x);
}

real_t tMath::Distance(const tVec3& v1, const tVec3& v2)
{
	real_t xx = v2.x - v1.x;
	real_t yy = v2.y - v1.y;
	real_t zz = v2.z - v1.z;

	return sqrt((xx * xx) + (yy * yy) + (zz * zz));
}

real_t tMath::Distance(const tVec4& v1, const tVec4& v2)
{
	real_t xx = v2.x - v1.x;
	real_t yy = v2.y - v1.y;
	real_t zz = v2.z - v1.z;

	return sqrt((xx * xx) + (yy * yy) + (zz * zz));
}

real_t tMath::Distance(const tVec3& v1, const tVec4& v2)
{
	real_t xx = v2.x - v1.x;
	real_t yy = v2.y - v1.y;
	real_t zz = v2.z - v1.z;

	return sqrt((xx * xx) + (yy * yy) + (zz * zz));
}

float32_t tMath::Distance(const tVec3f& v1, const tVec3f& v2)
{
	float32_t xx = v2.x - v1.x;
	float32_t yy = v2.y - v1.y;
	float32_t zz = v2.z - v1.z;

	return sqrtf((xx * xx) + (yy * yy) + (zz * zz));
}

float32_t tMath::Distance(const tVec4f& v1, const tVec4f& v2)
{
	float32_t xx = v2.x - v1.x;
	float32_t yy = v2.y - v1.y;
	float32_t zz = v2.z - v1.z;

	return sqrtf((xx * xx) + (yy * yy) + (zz * zz));
}

float32_t tMath::Distance(const tVec3f& v1, const tVec4f& v2)
{
	float32_t xx = v2.x - v1.x;
	float32_t yy = v2.y - v1.y;
	float32_t zz = v2.z - v1.z;

	return sqrtf((xx * xx) + (yy * yy) + (zz * zz));
}

real_t tMath::Dot(const tVec3& v1, const tVec3& v2)
{
	return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

real_t tMath::Dot(const tVec4& v1, const tVec4& v2)
{
	return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z) + (v1.w * v2.w);
}

real_t tMath::Dot(const tVec3& v1, const tVec4& v2)
{
	return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

float32_t tMath::Dot(const tVec3f& v1, const tVec3f& v2)
{
	return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

float32_t tMath::Dot(const tVec4f& v1, const tVec4f& v2)
{
	return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z) + (v1.w * v2.w);
}

float32_t tMath::Dot(const tVec3f& v1, const tVec4f& v2)
{
	return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

float32_t tMath::Dot(const tQuaternion& v1, const tQuaternion& v2)
{
	return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z) + (v1.w * v2.w);
}

real_t tMath::Length(const tVec3& v)
{
	return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}

real_t tMath::Length(const tVec4& v)
{
	return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w));
}

float32_t tMath::Length(const tVec3f& v)
{
	return sqrtf((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}

float32_t tMath::Length(const tVec4f& v)
{
	return sqrtf((v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w));
}

float32_t tMath::Length(const tQuaternion& v)
{
	return sqrtf((v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w));
}

float32_t tMath::Lerp1(float32_t x, float32_t y, float32_t t)
{
	return x + t * (y - x);
}

float64_t tMath::Lerp1(float64_t x, float64_t y, float64_t t)
{
	return x + t * (y - x);
}

void tMath::Lerp1(const tVec3& x, const tVec3& y, float64_t t, tVec3& r)
{
	r.x = x.x + t * (y.x - x.x);
	r.y = x.y + t * (y.y - x.y);
	r.z = x.z + t * (y.z - x.z);
}

void tMath::Lerp1(const tVec3& x, const tVec4& y, float64_t t, tVec3& r)
{
	r.x = x.x + t * (y.x - x.x);
	r.y = x.y + t * (y.y - x.y);
	r.z = x.z + t * (y.z - x.z);
}

void tMath::Lerp1(const tVec4& x, const tVec4& y, float64_t t, tVec4& r)
{
	r.x = x.x + t * (y.x - x.x);
	r.y = x.y + t * (y.y - x.y);
	r.z = x.z + t * (y.z - x.z);
	r.w = x.w + t * (y.w - x.w);
}

void tMath::Lerp1(const tVec3f& x, const tVec3f& y, float32_t t, tVec3f& r)
{
	r.x = x.x + t * (y.x - x.x);
	r.y = x.y + t * (y.y - x.y);
	r.z = x.z + t * (y.z - x.z);
}

void tMath::Lerp1(const tVec3f& x, const tVec4f& y, float32_t t, tVec3f& r)
{
	r.x = x.x + t * (y.x - x.x);
	r.y = x.y + t * (y.y - x.y);
	r.z = x.z + t * (y.z - x.z);
}

void tMath::Lerp1(const tVec4f& x, const tVec4f& y, float32_t t, tVec4f& r)
{
	r.x = x.x + t * (y.x - x.x);
	r.y = x.y + t * (y.y - x.y);
	r.z = x.z + t * (y.z - x.z);
	r.w = x.w + t * (y.w - x.w);
}

void tMath::Lerp1(const tQuaternion& x, const tQuaternion& y, float32_t t, tQuaternion& r)
{
	r.x = x.x + t * (y.x - x.x);
	r.y = x.y + t * (y.y - x.y);
	r.z = x.z + t * (y.z - x.z);
	r.w = x.w + t * (y.w - x.w);
}

float32_t tMath::Lerp2(float32_t x, float32_t y, float32_t t)
{
	return (1.f - t) * x + t * y;
}

float64_t tMath::Lerp2(float64_t x, float64_t y, float64_t t)
{
	return (1.0 - t) * x + t * y;
}

void tMath::Lerp2(const tVec3& x, const tVec3& y, float64_t t, tVec3& r)
{
	r.x = (1.0 - t) * x.x + t * y.x;
	r.y = (1.0 - t) * x.y + t * y.y;
	r.z = (1.0 - t) * x.z + t * y.z;
}

void tMath::Lerp2(const tVec3& x, const tVec4& y, float64_t t, tVec3& r)
{
	r.x = (1.0 - t) * x.x + t * y.x;
	r.y = (1.0 - t) * x.y + t * y.y;
	r.z = (1.0 - t) * x.z + t * y.z;
}

void tMath::Lerp2(const tVec4& x, const tVec4& y, float64_t t, tVec4& r)
{
	r.x = (1.0 - t) * x.x + t * y.x;
	r.y = (1.0 - t) * x.y + t * y.y;
	r.z = (1.0 - t) * x.z + t * y.z;
	r.w = (1.0 - t) * x.w + t * y.w;
}

void tMath::Lerp2(const tVec3f& x, const tVec3f& y, float32_t t, tVec3f& r)
{
	r.x = (1.0f - t) * x.x + t * y.x;
	r.y = (1.0f - t) * x.y + t * y.y;
	r.z = (1.0f - t) * x.z + t * y.z;
}

void tMath::Lerp2(const tVec3f& x, const tVec4f& y, float32_t t, tVec3f& r)
{
	r.x = (1.0f - t) * x.x + t * y.x;
	r.y = (1.0f - t) * x.y + t * y.y;
	r.z = (1.0f - t) * x.z + t * y.z;
}

void tMath::Lerp2(const tVec4f& x, const tVec4f& y, float32_t t, tVec4f& r)
{
	r.x = (1.0f - t) * x.x + t * y.x;
	r.y = (1.0f - t) * x.y + t * y.y;
	r.z = (1.0f - t) * x.z + t * y.z;
	r.w = (1.0f - t) * x.w + t * y.w;
}

void tMath::Lerp2(const tQuaternion& x, const tQuaternion& y, float32_t t, tQuaternion& r)
{
	r.x = (1.0f - t) * x.x + t * y.x;
	r.y = (1.0f - t) * x.y + t * y.y;
	r.z = (1.0f - t) * x.z + t * y.z;
	r.w = (1.0f - t) * x.w + t * y.w;
}

void tMath::Normalize(tVec3& v)
{
	float64_t len = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
	if (len > 0)
		len = 1.0f / len;
	v.x *= len;
	v.y *= len;
	v.z *= len;
}

void tMath::Normalize(tVec3f& v)
{
	float32_t len = sqrtf((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
	if (len > 0)
		len = 1.0f / len;
	v.x *= len;
	v.y *= len;
	v.z *= len;
}

void tMath::Normalize(tVec4& v)
{
	float64_t len = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w));
	if (len > 0)
		len = 1.0f / len;
	v.x *= len;
	v.y *= len;
	v.z *= len;
	v.w *= len;
}

void tMath::Normalize(tVec4f& v)
{
	float32_t len = sqrtf((v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w));
	if (len > 0)
		len = 1.0f / len;
	v.x *= len;
	v.y *= len;
	v.z *= len;
	v.w *= len;
}

void tMath::Normalize(tQuaternion& v)
{
	float32_t len = sqrtf((v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w));
	if (len > 0)
		len = 1.0f / len;
	v.x *= len;
	v.y *= len;
	v.z *= len;
	v.w *= len;
}

void tMath::SetRotation(tQuaternion& q, float32_t x, float32_t y, float32_t z)
{
	x *= 0.5f;
	y *= 0.5f;
	z *= 0.5f;
	float32_t c1 = ::cosf(x);
	float32_t c2 = ::cosf(y);
	float32_t c3 = ::cosf(z);
	float32_t s1 = ::sinf(x);
	float32_t s2 = ::sinf(y);
	float32_t s3 = ::sinf(z);
	q.w = (c1 * c2 * c3) + (s1 * s2 * s3);
	q.x = (s1 * c2 * c3) - (c1 * s2 * s3);
	q.y = (c1 * s2 * c3) + (s1 * c2 * s3);
	q.z = (c1 * c2 * s3) - (s1 * s2 * c3);
}

void tMath::SetRotation(tQuaternion& q, const tVec3& axis, const real_t& _angle)
{
	real_t d = (real_t)Length(axis);
	real_t s = std::sin(_angle * 0.5f) / d;
	q.x = (float32_t)(axis.x * s);
	q.y = (float32_t)(axis.y * s);
	q.z = (float32_t)(axis.z * s);
	q.w = (float32_t)std::cos(_angle * 0.5);
}

void tMath::SetRotation(tQuaternion& q, const tVec3f& axis, const float32_t& _angle)
{
	float32_t d = Length(axis);
	float32_t s = std::sin(_angle * 0.5f) / d;
	q.x = axis.x * s;
	q.y = axis.y * s;
	q.z = axis.z * s;
	q.w = std::cos(_angle * 0.5f);
}

void tMath::SetRotation(tQuaternion& q, const tVec4& axis, const real_t& _angle)
{
	real_t d = (real_t)Length(axis);
	real_t s = std::sin(_angle * 0.5f) / d;
	q.x = (float32_t)(axis.x * s);
	q.y = (float32_t)(axis.y * s);
	q.z = (float32_t)(axis.z * s);
	q.w = (float32_t)std::cos(_angle * 0.5f);
}

void tMath::SetRotation(tQuaternion& q, const tVec4f& axis, const float32_t& _angle)
{
	float32_t d = Length(axis);
	float32_t s = std::sin(_angle * 0.5f) / d;
	q.x = axis.x * s;
	q.y = axis.y * s;
	q.z = axis.z * s;
	q.w = std::cos(_angle * 0.5f);
}

void tMath::SetRotation(tMat4& m, const tQuaternion& q)
{
	real_t d = Length(q);
	real_t s = 2.0f / d;
	real_t xs = q.x * s, ys = q.y * s, zs = q.z * s;
	real_t wx = q.w * xs, wy = q.w * ys, wz = q.w * zs;
	real_t xx = q.x * xs, xy = q.x * ys, xz = q.x * zs;
	real_t yy = q.y * ys, yz = q.y * zs, zz = q.z * zs;
	m.Set(
		1.0f - (yy + zz), xy - wz, xz + wy,
		xy + wz, 1.0f - (xx + zz), yz - wx,
		xz - wy, yz + wx, 1.0f - (xx + yy));
}

// irrlicht?
void tMath::Slerp(tQuaternion& q1, tQuaternion& q2, float32_t time, float32_t threshold, tQuaternion& r)
{
	float32_t angle = Dot(q1, q2);
	// make sure we use the short rotation
	if (angle < 0.0f)
	{
		q1 = q1 * -1.0f;
		angle *= -1.0f;
	}

	if (angle <= (1 - threshold)) // spherical interpolation
	{
		const float32_t theta = ::acosf(angle);
		const float32_t invsintheta = 1.f / (::sinf(theta));
		const float32_t scale = ::sinf(theta * (1.0f - time)) * invsintheta;
		const float32_t invscale = ::sinf(theta * time) * invsintheta;
		r = (q1 * scale) + (q2 * invscale);
	}
	else // linear interploation
		Lerp1(q1, q2, time, r);
}

void tMath::Mul(const tMat4& m1, const tMat4& m2, tMat4& r)
{
	r.m_data[0].x = m1.m_data[0].x * m2.m_data[0].x + m1.m_data[1].x * m2.m_data[0].y + m1.m_data[2].x * m2.m_data[0].z + m1.m_data[3].x * m2.m_data[0].w;
	r.m_data[0].y = m1.m_data[0].y * m2.m_data[0].x + m1.m_data[1].y * m2.m_data[0].y + m1.m_data[2].y * m2.m_data[0].z + m1.m_data[3].y * m2.m_data[0].w;
	r.m_data[0].z = m1.m_data[0].z * m2.m_data[0].x + m1.m_data[1].z * m2.m_data[0].y + m1.m_data[2].z * m2.m_data[0].z + m1.m_data[3].z * m2.m_data[0].w;
	r.m_data[0].w = m1.m_data[0].w * m2.m_data[0].x + m1.m_data[1].w * m2.m_data[0].y + m1.m_data[2].w * m2.m_data[0].z + m1.m_data[3].w * m2.m_data[0].w;

	r.m_data[1].x = m1.m_data[0].x * m2.m_data[1].x + m1.m_data[1].x * m2.m_data[1].y + m1.m_data[2].x * m2.m_data[1].z + m1.m_data[3].x * m2.m_data[1].w;
	r.m_data[1].y = m1.m_data[0].y * m2.m_data[1].x + m1.m_data[1].y * m2.m_data[1].y + m1.m_data[2].y * m2.m_data[1].z + m1.m_data[3].y * m2.m_data[1].w;
	r.m_data[1].z = m1.m_data[0].z * m2.m_data[1].x + m1.m_data[1].z * m2.m_data[1].y + m1.m_data[2].z * m2.m_data[1].z + m1.m_data[3].z * m2.m_data[1].w;
	r.m_data[1].w = m1.m_data[0].w * m2.m_data[1].x + m1.m_data[1].w * m2.m_data[1].y + m1.m_data[2].w * m2.m_data[1].z + m1.m_data[3].w * m2.m_data[1].w;

	r.m_data[2].x = m1.m_data[0].x * m2.m_data[2].x + m1.m_data[1].x * m2.m_data[2].y + m1.m_data[2].x * m2.m_data[2].z + m1.m_data[3].x * m2.m_data[2].w;
	r.m_data[2].y = m1.m_data[0].y * m2.m_data[2].x + m1.m_data[1].y * m2.m_data[2].y + m1.m_data[2].y * m2.m_data[2].z + m1.m_data[3].y * m2.m_data[2].w;
	r.m_data[2].z = m1.m_data[0].z * m2.m_data[2].x + m1.m_data[1].z * m2.m_data[2].y + m1.m_data[2].z * m2.m_data[2].z + m1.m_data[3].z * m2.m_data[2].w;
	r.m_data[2].w = m1.m_data[0].w * m2.m_data[2].x + m1.m_data[1].w * m2.m_data[2].y + m1.m_data[2].w * m2.m_data[2].z + m1.m_data[3].w * m2.m_data[2].w;

	r.m_data[3].x = m1.m_data[0].x * m2.m_data[3].x + m1.m_data[1].x * m2.m_data[3].y + m1.m_data[2].x * m2.m_data[3].z + m1.m_data[3].x * m2.m_data[3].w;
	r.m_data[3].y = m1.m_data[0].y * m2.m_data[3].x + m1.m_data[1].y * m2.m_data[3].y + m1.m_data[2].y * m2.m_data[3].z + m1.m_data[3].y * m2.m_data[3].w;
	r.m_data[3].z = m1.m_data[0].z * m2.m_data[3].x + m1.m_data[1].z * m2.m_data[3].y + m1.m_data[2].z * m2.m_data[3].z + m1.m_data[3].z * m2.m_data[3].w;
	r.m_data[3].w = m1.m_data[0].w * m2.m_data[3].x + m1.m_data[1].w * m2.m_data[3].y + m1.m_data[2].w * m2.m_data[3].z + m1.m_data[3].w * m2.m_data[3].w;
}

void tMath::Mul(const tMat4& m, const tVec3& v, tVec3& r)
{
	r.x = v.x * m.m_data[0].x + v.y * m.m_data[1].x + v.z * m.m_data[2].x;
	r.y = v.x * m.m_data[0].y + v.y * m.m_data[1].y + v.z * m.m_data[2].y;
	r.z = v.x * m.m_data[0].z + v.y * m.m_data[1].z + v.z * m.m_data[2].z;
}

void tMath::Mul(const tMat4& m, const tVec3f& v, tVec3f& r)
{
	r.x = v.x * (float32_t)m.m_data[0].x + v.y * (float32_t)m.m_data[1].x + v.z * (float32_t)m.m_data[2].x;
	r.y = v.x * (float32_t)m.m_data[0].y + v.y * (float32_t)m.m_data[1].y + v.z * (float32_t)m.m_data[2].y;
	r.z = v.x * (float32_t)m.m_data[0].z + v.y * (float32_t)m.m_data[1].z + v.z * (float32_t)m.m_data[2].z;
}

void tMath::Mul(const tMat4& m, const tVec4& v, tVec4& r)
{
	r.x = v.x * m.m_data[0].x + v.y * m.m_data[1].x + v.z * m.m_data[2].x + v.w * m.m_data[3].x;
	r.y = v.x * m.m_data[0].y + v.y * m.m_data[1].y + v.z * m.m_data[2].y + v.w * m.m_data[3].y;
	r.z = v.x * m.m_data[0].z + v.y * m.m_data[1].z + v.z * m.m_data[2].z + v.w * m.m_data[3].z;
	r.w = v.x * m.m_data[0].w + v.y * m.m_data[1].w + v.z * m.m_data[2].w + v.w * m.m_data[3].w;
}

void tMath::Mul(const tQuaternion& q1, const tQuaternion& q2, tQuaternion& r)
{
	r.x = q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y;
	r.x = q1.w * q2.y + q1.y * q2.w + q1.z * q2.x - q1.x * q2.z;
	r.x = q1.w * q2.z + q1.z * q2.w + q1.x * q2.y - q1.y * q2.x;
	r.x = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;
}

void tMath::Transpose(tMat4& m)
{
	tMat4 tmp;
	tmp[0u].x = m.m_data[0u].x;
	tmp[0u].y = m.m_data[1u].x;
	tmp[0u].z = m.m_data[2u].x;
	tmp[0u].w = m.m_data[3u].x;

	tmp[1u].x = m.m_data[0u].y;
	tmp[1u].y = m.m_data[1u].y;
	tmp[1u].z = m.m_data[2u].y;
	tmp[1u].w = m.m_data[3u].y;

	tmp[2u].x = m.m_data[0u].z;
	tmp[2u].y = m.m_data[1u].z;
	tmp[2u].z = m.m_data[2u].z;
	tmp[2u].w = m.m_data[3u].z;

	m.m_data[0u] = tmp[0u];
	m.m_data[1u] = tmp[1u];
	m.m_data[2u] = tmp[2u];
	m.m_data[3u] = tmp[3u];
}

//https://www.scratchapixel.com/lessons/mathematics-physics-for-computer-graphics/matrix-inverse
void tMath::Invert(tMat4& m)
{
	tMat4 mat;
	auto ptr = m.Data();
	for (unsigned column = 0; column < 4; ++column)
	{
		// Swap row in case our pivot point is not working
		auto column_data = m.m_data[column].Data();
		if (column_data[column] == 0)
		{
			unsigned big = column;
			for (unsigned row = 0; row < 4; ++row)
			{
				auto row_data = m.m_data[row].Data();
				auto big_data = m.m_data[big].Data();
				if (fabs(row_data[column]) > fabs(big_data[column]))
					big = row;
			}
			// Print this is a singular matrix, return identity ?
			if (big == column)
				fprintf(stderr, "Singular matrix\n");
			// Swap rows                               
			else for (unsigned j = 0; j < 4; ++j)
			{
				auto big_data = m.m_data[big].Data();
				std::swap(column_data[j], big_data[j]);

				auto other_column_data = mat.m_data[column].Data();
				auto other_big_data = mat.m_data[big].Data();
				std::swap(other_column_data[j], other_big_data[j]);
			}
		}

		// Set each row in the column to 0  
		for (unsigned row = 0; row < 4; ++row)
		{
			if (row != column)
			{
				auto row_data = m.m_data[row].Data();
				real_t coeff = row_data[column] / column_data[column];
				if (coeff != 0)
				{
					for (unsigned j = 0; j < 4; ++j)
					{
						row_data[j] -= coeff * column_data[j];

						auto other_row_data = mat.m_data[row].Data();
						auto other_column_data = mat.m_data[column].Data();
						other_row_data[j] -= coeff * other_column_data[j];
					}
					// Set the element to 0 for safety
					row_data[column] = 0;
				}
			}
		}
	}

	// Set each element of the diagonal to 1
	for (unsigned row = 0; row < 4; ++row)
	{
		for (unsigned column = 0; column < 4; ++column)
		{
			auto other_row_data = mat.m_data[row].Data();
			auto row_data = m.m_data[row].Data();
			other_row_data[column] /= row_data[row];
		}
	}
	m = mat;
}

void tMath::PerspectiveLH(tMat4& m, real_t FOV, real_t aspect, real_t Near, real_t Far)
{
	T_ASSERT_ST(FOV != 0.f);
	T_ASSERT_ST(aspect != 0.f);

	real_t S = ::sin(0.5 * FOV);
	real_t C = ::cos(0.5 * FOV);
	real_t H = C / S;
	real_t W = H / aspect;
	m.m_data[0] = tVec4(W, 0., 0., 0.);
	m.m_data[1] = tVec4(0., H, 0., 0.);
	m.m_data[2] = tVec4(0., 0., Far / (Far - Near), 1.);
	m.m_data[3] = tVec4(0., 0., -m.m_data[2].z * Near, 0.);
}

void tMath::PerspectiveRH(tMat4& m, real_t FOV, real_t aspect, real_t Near, real_t Far)
{
	T_ASSERT_ST(FOV != 0.f);
	T_ASSERT_ST(aspect != 0.f);

	real_t S = ::sin(0.5 * FOV);
	real_t C = ::cos(0.5 * FOV);
	real_t H = C / S;
	real_t W = H / aspect;
	m.m_data[0] = tVec4(W, 0., 0., 0.);
	m.m_data[1] = tVec4(0., H, 0., 0.);
	m.m_data[2] = tVec4(0., 0., Far / (Near - Far), -1.);
	m.m_data[3] = tVec4(0., 0., m.m_data[2].z * Near, 0.);
}

void tMath::LookAtLH(tMat4& m, const tVec4& eye, const tVec4& center, const tVec4& up)
{
	tVec4 f(center - eye);
	Normalize(f);

	tVec4 s;
	Cross(f, up, s);
	Normalize(s);

	tVec4 u;
	Cross(s, f, u);

	m.m_data[0].x = s.x;
	m.m_data[1].x = s.y;
	m.m_data[2].x = s.z;
	m.m_data[0].y = u.x;
	m.m_data[1].y = u.y;
	m.m_data[2].y = u.z;
	m.m_data[0].z = f.x;
	m.m_data[1].z = f.y;
	m.m_data[2].z = f.z;
	m.m_data[3].x = -Dot(s, eye);
	m.m_data[3].y = -Dot(u, eye);
	m.m_data[3].z = -Dot(f, eye);
}

void tMath::LookAtRH(tMat4& m, const tVec4& eye, const tVec4& center, const tVec4& up)
{
	tVec4 f(center - eye);
	Normalize(f);

	tVec4 s;
	Cross(f, up, s);
	Normalize(s);

	tVec4 u;
	Cross(s, f, u);

	m.m_data[0].x = s.x;
	m.m_data[1].x = s.y;
	m.m_data[2].x = s.z;
	m.m_data[0].y = u.x;
	m.m_data[1].y = u.y;
	m.m_data[2].y = u.z;
	m.m_data[0].z = -f.x;
	m.m_data[1].z = -f.y;
	m.m_data[2].z = -f.z;
	m.m_data[3].x = -Dot(s, eye);
	m.m_data[3].y = -Dot(u, eye);
	m.m_data[3].z = Dot(f, eye);
}

float32_t tMath::CoordToUV(float32_t value, float32_t textureSz)
{
	T_ASSERT_ST(textureSz != 0.f);
	return value * (1.f / textureSz);
}

//bool tMath::pointInRect(const slPoint& p, const slRect& r)
//{
//	if ((p.x >= r.left) && (p.x <= r.right) && (p.y >= r.top) && (p.y <= r.bottom))
//		return true;
//	return false;
//}
//
//bool tMath::pointInRect(const slPoint& p, const tVec4f& r)
//{
//	if ((p.x >= r.x) && (p.x <= r.z) && (p.y >= r.y) && (p.y <= r.w))
//		return true;
//	return false;
//}

bool tMath::PointInRect(const tVec2f& p, const tVec4f& r)
{
	if ((p.x >= r.x) && (p.x <= r.z) && (p.y >= r.y) && (p.y <= r.w))
		return true;
	return false;
}

void tMath::OrthoLH(tMat4& out, float32_t width, float32_t height, float32_t near, float32_t far)
{
	T_ASSERT_ST(width != 0.f);
	T_ASSERT_ST(height != 0.f);
	T_ASSERT_ST(near != 0.f);
	T_ASSERT_ST(far != 0.f);

	float32_t fRange = 1.0f / (far - near);
	out.m_data[0u].Set(2.f / width, 0.f, 0.f, 0.f);
	out.m_data[1u].Set(0.f, 2.f / height, 0.f, 0.f);
	out.m_data[2u].Set(0.f, 0.f, fRange, 0.f);
	out.m_data[3u].Set(0.f, 0.f, -fRange * near, 1.f);
}

void tMath::OrthoRH(tMat4& out, float32_t width, float32_t height, float32_t near, float32_t far)
{
	T_ASSERT_ST(width != 0.f);
	T_ASSERT_ST(height != 0.f);
	T_ASSERT_ST(near != 0.f);
	T_ASSERT_ST(far != 0.f);

	out.m_data[0u].Set(2.f / width, 0.f, 0.f, 0.f);
	out.m_data[1u].Set(0.f, 2.f / height, 0.f, 0.f);
	out.m_data[2u].Set(0.f, 0.f, 1.f / (near - far), 0.f);
	out.m_data[3u].Set(0.f, 0.f, out[2u].z * near, 1.f);
}

// based on XNA math library
void tMath::OrthoOfCenterLH(tMat4& out, float32_t left, float32_t right, float32_t top, float32_t bottom, float32_t near, float32_t far)
{
	float32_t    ReciprocalWidth;
	float32_t    ReciprocalHeight;

	ReciprocalWidth = 1.0f / (right - left);
	ReciprocalHeight = 1.0f / (top - bottom);

	out.m_data[0].Set(ReciprocalWidth + ReciprocalWidth, 0.0f, 0.0f, 0.0f);
	out.m_data[1].Set(0.0f, ReciprocalHeight + ReciprocalHeight, 0.0f, 0.0f);
	out.m_data[2].Set(0.0f, 0.0f, 1.0f / (far - near), 0.0f);
	out.m_data[3].Set(
		-(left + right) * ReciprocalWidth,
		-(top + bottom) * ReciprocalHeight,
		-out.m_data[2].z * near,
		1.0f);
}
// based on XNA math library
void tMath::OrthoOfCenterRH(tMat4& out, float32_t left, float32_t right, float32_t top, float32_t bottom, float32_t near, float32_t far)
{
	float32_t    ReciprocalWidth;
	float32_t    ReciprocalHeight;

	ReciprocalWidth = 1.0f / (right - left);
	ReciprocalHeight = 1.0f / (top - bottom);

	out.m_data[0].Set(ReciprocalWidth + ReciprocalWidth, 0.0f, 0.0f, 0.0f);
	out.m_data[1].Set(0.0f, ReciprocalHeight + ReciprocalHeight, 0.0f, 0.0f);
	out.m_data[2].Set(0.0f, 0.0f, 1.0f / (near - far), 0.0f);
	out.m_data[3].Set(
		-(left + right) * ReciprocalWidth,
		-(top + bottom) * ReciprocalHeight,
		out.m_data[2].z * near,
		1.0f);
}


