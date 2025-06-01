#define T_EXPORT
#include "T.h"
#include "T/Math.h"

tQuaternion::tQuaternion()
{
	Identity();
}

tQuaternion::tQuaternion(const tQuaternion& o) :
	x(o.x),
	y(o.y),
	z(o.z),
	w(o.w)
{
}

tQuaternion::tQuaternion(float32_t ax, float32_t ay, float32_t az)
{
	this->Set(ax, ay, az);
}

tQuaternion::tQuaternion(float32_t x, float32_t y, float32_t z, float32_t w) :
	x(x),
	y(y),
	z(z),
	w(w)
{
}

void tQuaternion::Set(const tVec4& v) 
{
	Set((float32_t)v.x, (float32_t)v.y, (float32_t)v.z); 
}

void tQuaternion::Set(const tVec4f& v) 
{
	Set(v.x, v.y, v.z); 
}

void tQuaternion::Set(float32_t _x, float32_t _y, float32_t _z)
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

void tQuaternion::Identity()
{
	x = y = z = 0.f;
	w = 1.f;
}

float32_t tQuaternion::Length() const
{
	return (x * x) + (y * y) + (z * z) + (w * w);
}

tQuaternion& tQuaternion::operator=(const tQuaternion& o)
{
	x = o.x;
	y = o.y;
	z = o.z;
	w = o.w;
	return *this;
}

tQuaternion tQuaternion::operator*(const tQuaternion& q) const
{
	return tQuaternion(
		w * q.x + x * q.w + y * q.z - z * q.y,
		w * q.y + y * q.w + z * q.x - x * q.z,
		w * q.z + z * q.w + x * q.y - y * q.x,
		w * q.w - x * q.x - y * q.y - z * q.z);
}

tQuaternion tQuaternion::operator*(float32_t s) const
{
	return tQuaternion(s * x, s * y, s * z, s * w);
}

void tQuaternion::operator*=(const tQuaternion& q)
{
	x = w * q.x + x * q.w + y * q.z - z * q.y;
	y = w * q.y + y * q.w + z * q.x - x * q.z;
	z = w * q.z + z * q.w + x * q.y - y * q.x;
	w = w * q.w - x * q.x - y * q.y - z * q.z;
}

bool tQuaternion::operator!=(const tQuaternion& q) const
{
	if (x != q.x) return true;
	if (y != q.y) return true;
	if (z != q.z) return true;
	if (w != q.w) return true;
	return false;
}

bool tQuaternion::operator==(const tQuaternion& q) const
{
	if (x != q.x) return false;
	if (y != q.y) return false;
	if (z != q.z) return false;
	if (w != q.w) return false;
	return true;
}

tQuaternion tQuaternion::operator+(const tQuaternion& o) const
{
	return tQuaternion(
		x + o.x,
		y + o.y,
		z + o.z,
		w + o.w);
}

tQuaternion tQuaternion::operator-(const tQuaternion& o) const
{
	return tQuaternion(
		x - o.x,
		y - o.y,
		z - o.z,
		w - o.w);
}

tQuaternion tQuaternion::operator-()
{
	x = -x;
	y = -y;
	z = -z;
	return tQuaternion(x, y, z, w);
}

float32_t tQuaternion::operator[](uint32_t index) const
{
	return (&x)[index];
}

float32_t& tQuaternion::operator[](uint32_t index)
{
	return (&x)[index];
}

void tQuaternion::Normalize()
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
