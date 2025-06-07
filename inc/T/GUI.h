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

#ifndef _TY_GUI_H_
#define _TY_GUI_H_

#include "T/GUI/Style.h"
#include "T/GUI/Font.h"

enum class tGUIDefaultIconID : uint32_t
{
	CheckboxUncheck = 1,
	CheckboxCheck,
	RadioUncheck,
	RadioCheck,
	Plus,
	Minus,
	ArrowUp,
	ArrowDonw,
	ArrowRight,
	ArrowLeft,
};

//class tGUIDrawTextCallback : public tUserData
//{
//public:
//	tGUIDrawTextCallback() {}
//	virtual ~tGUIDrawTextCallback() {}
//
//	virtual tGUIFont* OnFont(char32_t) = 0;
//	virtual tColor* OnColor(char32_t) = 0;
//
//	virtual tVec2f GetTextSize(const char32_t* text)
//	{
//		tVec2f sz, position;
//		tVec4f rct;
//		if (text)
//		{
//			if (text[0] != 0)
//			{
//				const char32_t* p = &text[0u];
//				while ((size_t)*p)
//				{
//					auto font = OnFont( *p);
//					tGUIFontGlyph* g = font->GetGlyphMap()[*p];
//
//					rct.x = position.x;
//					rct.y = position.y;
//
//					rct.z = rct.x + g->m_width;
//					rct.w = rct.y + g->m_height;
//
//					position.x += g->m_width + g->m_overhang + g->m_underhang + font->m_characterSpacing;
//
//					switch (*p)
//					{
//					case U' ':
//						position.x += font->m_spaceSize;
//						break;
//					case U'\t':
//						position.x += font->m_tabSize;
//						break;
//					case U'\n':
//						position.y += font->GetMaxSize().y;
//						position.x = 0.f;
//						break;
//					}
//
//					if (position.x > sz.x) sz.x = position.x;
//					if (position.y > sz.y) sz.y = position.y;
//					if (g->m_height > sz.y) sz.y = (float)g->m_height;
//
//					++p;
//				}
//			}
//		}
//		return sz;
//	}
//};


#include "T/GUI/Element.h"
#include "T/GUI/Window.h"
#include "T/GUI/Button.h"
#include "T/GUI/CheckRadioBox.h"
#include "T/GUI/TextEditor.h"
#include "T/GUI/StaticText.h"
#include "T/GUI/ListBox.h"
#include "T/GUI/Slider.h"


struct tGUIState
{
	tGUIWindow* m_windowUnderCursor = 0;
	tGUIWindow* m_activeWindow = 0;
	//tGUIElement* m_elementUnderCursor = 0;
	bool m_scrollBlock = false;
};

//class tGUIRootElement : public tGUIElement
//{
//public:
//	tGUIRootElement(tGUIWindow*, const tVec2f& position, const tVec2f& size);
//	virtual ~tGUIRootElement();
//	virtual void Rebuild() final;
//	virtual void Update() final;
//	virtual void Draw(tGS* gs, float dt) final;
//
//	virtual void UpdateContentSize() final;
//};
//

#endif

