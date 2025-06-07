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
#ifndef __T_BASEGUIFONT_H__
#define __T_BASEGUIFONT_H__

#include "T/Containers/Array.h"

struct tGUIFontGlyph
{
	char32_t m_symbol = U' ';
	tVec4f m_UV;
	tVec4i m_rect;
	int32_t m_underhang = 0;
	int32_t m_overhang = 0;
	uint32_t m_width = 0;
	uint32_t m_height = 0;
	uint32_t m_textureSlot = 0;
};

enum class tGUIDefaultFont
{
	Text,
	Icons
};

class tGUIFont
{
	//uint32_t m_textureNum = 0;
	tArray<tTexture*> m_textures;

	tArray<tGUIFontGlyph*> m_glyphs;

	tVec2i m_maxSize;

	tGUIFontGlyph* m_glyphMap[0x32000];
public:
	tGUIFont();
	~tGUIFont();

	void AddTexture(tTexture*);
	void AddGlyph(const tGUIFontGlyph&);
	void AddGlyph(char32_t ch, const tVec2i& leftTop, const tVec2i& charSz, uint32_t texture, const tVec2i& texSz)
	{
		tGUIFontGlyph glyph;
		glyph.m_symbol = ch;
		glyph.m_width = charSz.x;
		glyph.m_height = charSz.y;
		glyph.m_textureSlot = texture;
		glyph.m_UV.x = tMath::CoordToUV(leftTop.x, (float)texSz.x);
		glyph.m_UV.y = tMath::CoordToUV(leftTop.y, (float)texSz.y);
		glyph.m_UV.z = tMath::CoordToUV(leftTop.x + (float)charSz.x, (float)texSz.x);
		glyph.m_UV.w = tMath::CoordToUV(leftTop.y + (float)charSz.y, (float)texSz.y);
		AddGlyph(glyph);
	}

	const tVec2i& GetMaxSize() { return m_maxSize; }
	tGUIFontGlyph** GetGlyphMap() { return m_glyphMap; }
	tTexture* GetTexture(uint32_t i) { return m_textures.m_data[i]; }

	int32_t m_characterSpacing = 1;
	int32_t m_spaceSize = 1;
	int32_t m_tabSize = 12;
};


#endif
