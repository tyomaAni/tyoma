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
#ifndef __Е_BASEGUISTYLE_H__
#define __Е_BASEGUISTYLE_H__

#include "T/Common/Color.h"

enum class tGUIStyleTheme
{
	Light,
	Dark
};

struct tGUIStyle
{
	tColor m_colorWhite = ColorWhite;

	tColor m_windowActiveBGColor1;
	tColor m_windowActiveBGColor2;
	tColor m_windowActiveBorderColor;
	tColor m_windowActiveTitleBGColor1;
	tColor m_windowActiveTitleBGColor2;
	tColor m_windowActiveTitleTextColor;

	tColor m_buttonBGColor1;
	tColor m_buttonBGColor2;
	tColor m_buttonBorderColor;
	tColor m_buttonTextColor;
	tColor m_buttonDisabledBGColor1;
	tColor m_buttonDisabledBGColor2;
	tColor m_buttonDisabledBorderColor;
	tColor m_buttonDisabledTextColor;
	tColor m_buttonMouseHoverBGColor1;
	tColor m_buttonMouseHoverBGColor2;
	tColor m_buttonMouseHoverTextColor;
	tColor m_buttonMousePressBGColor1;
	tColor m_buttonMousePressBGColor2;
	tColor m_buttonMousePressTextColor;

	tColor m_chkradioTextColor;
	tColor m_chkradioDisabledTextColor;
	tColor m_chkradioMouseHoverTextColor;
	tColor m_chkradioMousePressTextColor;
	
	tColor m_textEditorBGColor;
	tColor m_textEditorLine1BGColor;
	tColor m_textEditorLine2BGColor;
	tColor m_textEditorTextColor;
	tColor m_textEditorSelectedTextColor;
	tColor m_textEditorSelectedTextBGColor;
	tColor m_textEditorCursorColor;
	
	tColor m_staticTextBGColor;
	tColor m_staticTextTextColor;
	
	tColor m_listboxBGColor;
	tColor m_listboxLine1BGColor;
	tColor m_listboxLine2BGColor;
	tColor m_listboxSelectedLineBGColor;
	
	tColor m_sliderTextColor;
	tColor m_sliderAxisEmtpyColor;
	tColor m_sliderAxisFillColor;
	tColor m_sliderControlColor;

};

#endif
