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
#ifndef _TY_CLR_H_
#define _TY_CLR_H_

#include <math.h>

// I don't know how to call it
#define T_ColorDivider 0.00392156862745f

class tColorBytes
{
public:
	tColorBytes()
		:
		r(0),
		g(0),
		b(0),
		a(255)
	{
	}
	tColorBytes(uint8_t R, uint8_t G, uint8_t B, uint8_t A)
		:
		r(R),
		g(G),
		b(B),
		a(A)
	{
	}

	tColorBytes(uint32_t uint_data) // 0xFF112233 ARGB
	{
		r = static_cast<uint8_t>(uint_data >> 16u);
		g = static_cast<uint8_t>(uint_data >> 8u);
		b = static_cast<uint8_t>(uint_data);
		a = static_cast<uint8_t>(uint_data >> 24u);
	}

	uint8_t r, g, b, a;

	bool	operator==(const tColorBytes& v) const
	{
		if (r != v.r) return false;
		if (g != v.g) return false;
		if (b != v.b) return false;
		if (a != v.a) return false;
		return true;
	}

	bool	operator!=(const tColorBytes& v) const
	{
		if (r != v.r) return true;
		if (g != v.g) return true;
		if (b != v.b) return true;
		if (a != v.a) return true;
		return false;
	}
};

class tColor
{
public:
	float	m_data[4];

	tColor()
	{
		m_data[0] = m_data[1] = m_data[2] = 0.f;
		m_data[3] = 1.f;
	}

	tColor(float v)
	{
		m_data[0] = m_data[1] = m_data[2] = v;
		m_data[3] = 1.f;
	}

	tColor(float r, float g, float b, float a = 1.f)
	{
		m_data[0] = r;
		m_data[1] = g;
		m_data[2] = b;
		m_data[3] = a;
	}

	tColor(int32_t r, int32_t g, int32_t b, int32_t a = 255)
	{
		this->SetAsByteAlpha(a);
		this->SetAsByteRed(r);
		this->SetAsByteGreen(g);
		this->SetAsByteBlue(b);
	}

	tColor(uint32_t uint_data) // 0xFF112233 ARGB
	{
		SetAsInteger(uint_data);
	}

	tColor(int32_t int_data) // 0xFF112233 ARGB
	{
		SetAsInteger(0xFF000000 | (uint32_t)int_data);
	}

	float X() { return m_data[0]; }
	float Y() { return m_data[1]; }
	float Z() { return m_data[2]; }
	float W() { return m_data[3]; }

	const float* Data() const { return &m_data[0u]; }

	const float GetRed() const { return m_data[0u]; }
	const float GetGreen() const { return m_data[1u]; }
	const float GetBlue() const { return m_data[2u]; }
	const float GetAlpha() const { return m_data[3u]; }

	const uint8_t GetAsByteRed() const { return static_cast<uint8_t>(m_data[0u] * 255.); }
	const uint8_t GetAsByteGreen() const { return static_cast<uint8_t>(m_data[1u] * 255.); }
	const uint8_t GetAsByteBlue() const { return static_cast<uint8_t>(m_data[2u] * 255.); }
	const uint8_t GetAsByteAlpha() const { return static_cast<uint8_t>(m_data[3u] * 255.); }

	bool	operator==(const tColor& v) const
	{
		if (m_data[0] != v.m_data[0]) return false;
		if (m_data[1] != v.m_data[1]) return false;
		if (m_data[2] != v.m_data[2]) return false;
		if (m_data[3] != v.m_data[3]) return false;
		return true;
	}

	bool	operator!=(const tColor& v) const
	{
		if (m_data[0] != v.m_data[0]) return true;
		if (m_data[1] != v.m_data[1]) return true;
		if (m_data[2] != v.m_data[2]) return true;
		if (m_data[3] != v.m_data[3]) return true;
		return false;
	}

	void Normalize()
	{
		float len = sqrtf((m_data[0] * m_data[0]) + (m_data[1] * m_data[1]) + (m_data[2] * m_data[2]));
		if (len > 0)
		{
			len = 1.0f / len;
		}
		m_data[0] *= len;
		m_data[1] *= len;
		m_data[2] *= len;
	}

	// 0xff112233
	uint32_t GetAsInteger()
	{
		return T_MAKEFOURCC(
			this->getAsByteBlue(),
			this->getAsByteGreen(),
			this->getAsByteRed(),
			this->getAsByteAlpha()
		);
	}

	void SetAlpha(float v) { m_data[3] = v; }
	void SetRed(float v) { m_data[0] = v; }
	void SetGreen(float v) { m_data[1] = v; }
	void SetBlue(float v) { m_data[2] = v; }

	void SetAsByteAlpha(int32_t v) { m_data[3] = static_cast<float>(v) * T_ColorDivider; }
	void SetAsByteRed(int32_t v) { m_data[0] = static_cast<float>(v) * T_ColorDivider; }
	void SetAsByteGreen(int32_t v) { m_data[1] = static_cast<float>(v) * T_ColorDivider; }
	void SetAsByteBlue(int32_t v) { m_data[2] = static_cast<float>(v) * T_ColorDivider; }

	void SetAsInteger(uint32_t v)
	{
		this->SetAsByteRed(static_cast<uint8_t>(v >> 16));
		this->SetAsByteGreen(static_cast<uint8_t>(v >> 8));
		this->SetAsByteBlue(static_cast<uint8_t>(v));
		this->SetAsByteAlpha(static_cast<uint8_t>(v >> 24));
	}

	void Set(float r, float g, float b, float a = 1.)
	{
		SetAlpha(a);
		SetRed(r);
		SetGreen(g);
		SetBlue(b);
	}

	void Set(float v, float a = 1.)
	{
		SetAlpha(a);
		SetRed(v);
		SetGreen(v);
		SetBlue(v);
	}

	void Set(const tColor& other)
	{
		*this = other;
	}
};

//	HTML colors
const tColor ColorAliceBlue = 0xffF0F8FF;
const tColor ColorAntiqueWhite = 0xffFAEBD7;
const tColor ColorAqua = 0xff00FFFF;
const tColor ColorAquamarine = 0xff7FFFD4;
const tColor ColorAzure = 0xffF0FFFF;
const tColor ColorBeige = 0xffF5F5DC;
const tColor ColorBisque = 0xffFFE4C4;
const tColor ColorBlack = 0xff000000;
const tColor ColorBlanchedAlmond = 0xffFFEBCD;
const tColor ColorBlue = 0xff0000FF;
const tColor ColorBlueViolet = 0xff8A2BE2;
const tColor ColorBrown = 0xffA52A2A;
const tColor ColorBurlyWood = 0xffDEB887;
const tColor ColorCadetBlue = 0xff5F9EA0;
const tColor ColorChartreuse = 0xff7FFF00;
const tColor ColorChocolate = 0xffD2691E;
const tColor ColorCoral = 0xffFF7F50;
const tColor ColorCornflowerBlue = 0xff6495ED;
const tColor ColorCornsilk = 0xffFFF8DC;
const tColor ColorCrimson = 0xffDC143C;
const tColor ColorCyan = 0xff00FFFF;
const tColor ColorDarkBlue = 0xff00008B;
const tColor ColorDarkCyan = 0xff008B8B;
const tColor ColorDarkGoldenRod = 0xffB8860B;
const tColor ColorDarkGray = 0xffA9A9A9;
const tColor ColorDarkGrey = 0xffA9A9A9;
const tColor ColorDarkGreen = 0xff006400;
const tColor ColorDarkKhaki = 0xffBDB76B;
const tColor ColorDarkMagenta = 0xff8B008B;
const tColor ColorDarkOliveGreen = 0xff556B2F;
const tColor ColorDarkOrange = 0xffFF8C00;
const tColor ColorDarkOrchid = 0xff9932CC;
const tColor ColorDarkRed = 0xff8B0000;
const tColor ColorDarkSalmon = 0xffE9967A;
const tColor ColorDarkSeaGreen = 0xff8FBC8F;
const tColor ColorDarkSlateBlue = 0xff483D8B;
const tColor ColorDarkSlateGray = 0xff2F4F4F;
const tColor ColorDarkSlateGrey = 0xff2F4F4F;
const tColor ColorDarkTurquoise = 0xff00CED1;
const tColor ColorDarkViolet = 0xff9400D3;
const tColor ColorDeepPink = 0xffFF1493;
const tColor ColorDeepSkyBlue = 0xff00BFFF;
const tColor ColorDimGray = 0xff696969;
const tColor ColorDimGrey = 0xff696969;
const tColor ColorDodgerBlue = 0xff1E90FF;
const tColor ColorFireBrick = 0xffB22222;
const tColor ColorFloralWhite = 0xffFFFAF0;
const tColor ColorForestGreen = 0xff228B22;
const tColor ColorFuchsia = 0xffFF00FF;
const tColor ColorGainsboro = 0xffDCDCDC;
const tColor ColorGhostWhite = 0xffF8F8FF;
const tColor ColorGold = 0xffFFD700;
const tColor ColorGoldenRod = 0xffDAA520;
const tColor ColorGray = 0xff808080;
const tColor ColorGrey = 0xff808080;
const tColor ColorGreen = 0xff008000;
const tColor ColorGreenYellow = 0xffADFF2F;
const tColor ColorHoneyDew = 0xffF0FFF0;
const tColor ColorHotPink = 0xffFF69B4;
const tColor ColorIndianRed = 0xffCD5C5C;
const tColor ColorIndigo = 0xff4B0082;
const tColor ColorIvory = 0xffFFFFF0;
const tColor ColorKhaki = 0xffF0E68C;
const tColor ColorLavender = 0xffE6E6FA;
const tColor ColorLavenderBlush = 0xffFFF0F5;
const tColor ColorLawnGreen = 0xff7CFC00;
const tColor ColorLemonChiffon = 0xffFFFACD;
const tColor ColorLightBlue = 0xffADD8E6;
const tColor ColorLightCoral = 0xffF08080;
const tColor ColorLightCyan = 0xffE0FFFF;
const tColor ColorLightGoldenRodYellow = 0xffFAFAD2;
const tColor ColorLightGray = 0xffD3D3D3;
const tColor ColorLightGrey = 0xffD3D3D3;
const tColor ColorLightGreen = 0xff90EE90;
const tColor ColorLightPink = 0xffFFB6C1;
const tColor ColorLightSalmon = 0xffFFA07A;
const tColor ColorLightSeaGreen = 0xff20B2AA;
const tColor ColorLightSkyBlue = 0xff87CEFA;
const tColor ColorLightSlateGray = 0xff778899;
const tColor ColorLightSlateGrey = 0xff778899;
const tColor ColorLightSteelBlue = 0xffB0C4DE;
const tColor ColorLightYellow = 0xffFFFFE0;
const tColor ColorLime = 0xff00FF00;
const tColor ColorLimeGreen = 0xff32CD32;
const tColor ColorLinen = 0xffFAF0E6;
const tColor ColorMagenta = 0xffFF00FF;
const tColor ColorMaroon = 0xff800000;
const tColor ColorMediumAquaMarine = 0xff66CDAA;
const tColor ColorMediumBlue = 0xff0000CD;
const tColor ColorMediumOrchid = 0xffBA55D3;
const tColor ColorMediumPurple = 0xff9370DB;
const tColor ColorMediumSeaGreen = 0xff3CB371;
const tColor ColorMediumSlateBlue = 0xff7B68EE;
const tColor ColorMediumSpringGreen = 0xff00FA9A;
const tColor ColorMediumTurquoise = 0xff48D1CC;
const tColor ColorMediumVioletRed = 0xffC71585;
const tColor ColorMidnightBlue = 0xff191970;
const tColor ColorMintCream = 0xffF5FFFA;
const tColor ColorMistyRose = 0xffFFE4E1;
const tColor ColorMoccasin = 0xffFFE4B5;
const tColor ColorNavajoWhite = 0xffFFDEAD;
const tColor ColorNavy = 0xff000080;
const tColor ColorOldLace = 0xffFDF5E6;
const tColor ColorOlive = 0xff808000;
const tColor ColorOliveDrab = 0xff6B8E23;
const tColor ColorOrange = 0xffFFA500;
const tColor ColorOrangeRed = 0xffFF4500;
const tColor ColorOrchid = 0xffDA70D6;
const tColor ColorPaleGoldenRod = 0xffEEE8AA;
const tColor ColorPaleGreen = 0xff98FB98;
const tColor ColorPaleTurquoise = 0xffAFEEEE;
const tColor ColorPaleVioletRed = 0xffDB7093;
const tColor ColorPapayaWhip = 0xffFFEFD5;
const tColor ColorPeachPuff = 0xffFFDAB9;
const tColor ColorPeru = 0xffCD853F;
const tColor ColorPink = 0xffFFC0CB;
const tColor ColorPlum = 0xffDDA0DD;
const tColor ColorPowderBlue = 0xffB0E0E6;
const tColor ColorPurple = 0xff800080;
const tColor ColorRebeccaPurple = 0xff663399;
const tColor ColorRed = 0xffFF0000;
const tColor ColorRosyBrown = 0xffBC8F8F;
const tColor ColorRoyalBlue = 0xff4169E1;
const tColor ColorSaddleBrown = 0xff8B4513;
const tColor ColorSalmon = 0xffFA8072;
const tColor ColorSandyBrown = 0xffF4A460;
const tColor ColorSeaGreen = 0xff2E8B57;
const tColor ColorSeaShell = 0xffFFF5EE;
const tColor ColorSienna = 0xffA0522D;
const tColor ColorSilver = 0xffC0C0C0;
const tColor ColorSkyBlue = 0xff87CEEB;
const tColor ColorSlateBlue = 0xff6A5ACD;
const tColor ColorSlateGray = 0xff708090;
const tColor ColorSlateGrey = 0xff708090;
const tColor ColorSnow = 0xffFFFAFA;
const tColor ColorSpringGreen = 0xff00FF7F;
const tColor ColorSteelBlue = 0xff4682B4;
const tColor ColorTan = 0xffD2B48C;
const tColor ColorTeal = 0xff008080;
const tColor ColorThistle = 0xffD8BFD8;
const tColor ColorTomato = 0xffFF6347;
const tColor ColorTurquoise = 0xff40E0D0;
const tColor ColorViolet = 0xffEE82EE;
const tColor ColorWheat = 0xffF5DEB3;
const tColor ColorWhite = 0xffffffff;
const tColor ColorWhiteSmoke = 0xffF5F5F5;
const tColor ColorYellow = 0xffFFFF00;
const tColor ColorYellowGreen = 0xff9ACD32;


#endif
