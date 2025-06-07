﻿/*
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
#ifndef __T_GUISLIDER_H__
#define __T_GUISLIDER_H__

class tGUISlider : public tGUIElement
{
protected:
	float m_controlWidth = 10.f;
	
	double m_valueFloat = 0.0;
	uint32_t m_valueUint = 0;
	int32_t m_valueInt = 0;

	double m_valueMinFloat = 0.0;
	double m_valueMaxFloat = 100.0;

	uint32_t m_valueMinUint = 0;
	uint32_t m_valueMaxUint = 100;

	int32_t m_valueMinInt = -100;
	int32_t m_valueMaxInt = 100;

	tVec4i m_axisRect;
	tVec4i m_axisRectFill;
	float m_axisHeight = 5.f;
	
	float m_axisWidth= 0.f;
	
	tVec4i m_controlRect;
	bool m_isClicked = false;

	float m_axisIndent = 15.f;

	tString m_text;

	void findAxisRectFill();
public:
	tGUISlider(tGUIWindow*, const tVec2i& position, const tVec2i& size);
	virtual ~tGUISlider();
	
	virtual void Rebuild() override;
	virtual void Update() override;
	virtual void Draw(tGS* gs, float dt) override;

	double* GetFloat() { return &m_valueFloat; }
	uint32_t* GetUint() { return &m_valueUint; }
	int32_t* GetInt() { return &m_valueInt; }

	virtual void OnChangeValue() {}

	enum class ValueType
	{
		Float,
		Uint,
		Int
	};
	ValueType m_valueType = ValueType::Float;

	void SetMinMaxFloat(double mn, double mx);
	void SetMinMaxUint(uint32_t mn, uint32_t mx);
	void SetMinMaxInt(int32_t mn, int32_t mx);

	bool m_drawText = true;
	
	bool m_morePrecise = false;
	float m_multiplerNormal = 1.f;
	float m_multiplerSlow = 0.01f;
	float m_multiplerFast = 100.0f;

	// will call m_text.pop_back(); number of times
	uint32_t m_truncateFloatByThisNumOfChars = 10;
};

#endif
