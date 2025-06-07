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
#ifndef __T_GUILISTBOX_H_
#define __T_GUILISTBOX_H_

struct tGUIListBoxItem
{
	tString m_text;
	uint32_t m_id = 0;
	void* m_data = 0;

	bool m_isSelected = false;
};

class tGUIListBox : public tGUIElement
{
	tArray<tGUIListBoxItem*> m_items;
	float m_lineHeight = 0.f;
	size_t m_firstItemIndexForDraw = 0;
	size_t m_numberOfVisibleLines = 0;

public:
	tGUIListBox(tGUIWindow*, const tVec2i& position, const tVec2i& size);
	virtual ~tGUIListBox();

	virtual void Rebuild() override;
	virtual void Update() override;
	virtual void Draw(tGS* gs, float dt) override;	
	
	virtual void UpdateContentSize() override;

	tGUIListBoxItem* AddItem(const char32_t*, uint32_t id, void* data);
	void RemoveItem(tGUIListBoxItem*);

	tArray<tGUIListBoxItem*>* GetItems() { return &m_items; }

	bool m_drawItemBG = true;
	bool m_multiSelect = false;

	// return true if need to select
	virtual bool OnSelect(tGUIListBoxItem*) { return true; }
	// return true if need to deselect
	virtual bool OnDeSelect(tGUIListBoxItem*) { return true; }
};

#endif
