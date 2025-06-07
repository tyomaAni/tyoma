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

#ifndef _TY_SW_H_
#define _TY_SW_H_

#include "T/Math.h"

class tSysWindowCallback
{
public:
	tSysWindowCallback() {}
	virtual ~tSysWindowCallback() {}
	T_PLACEMENT_ALLOCATOR(tSysWindowCallback);

	virtual void OnActivate(tSysWindow*) {}
	virtual void OnDeactivate(tSysWindow*) {}
	virtual void OnSize(tSysWindow*) {}   // after resizing
	virtual void OnSizing(tSysWindow*) {} // when resizing
	virtual void OnMinimize(tSysWindow*) {}
	virtual void OnMaximize(tSysWindow*) {}
	virtual void OnRestore(tSysWindow*) {}
	virtual void OnDraw(tSysWindow*) {}
	virtual void OnMove(tSysWindow*) {}
	virtual void OnClose(tSysWindow*) {}
};

struct tSysWindowCommonData
{
	tSysWindowCallback* m_cb = 0;
	tVec2i m_borderSize;
	tVec2i m_borderSizeCurrent;
	tVec2i m_sizeMinimum;
	tVec2i m_currentSize;
	tVec2i m_creationSize;
	tVec2i m_sizePreFullscreen;
	bool m_isVisible = false;
	bool m_isFullscreen = false;

	void* m_implementation = 0;
};

class tSysWindow : public tUserData
{
	tSysWindowCommonData m_data;
public:
	tSysWindow(tSysWindowCallback* cb, int32_t sx, int32_t sy);
	virtual ~tSysWindow();
	T_PLACEMENT_ALLOCATOR(tSysWindow);

	void SetTitle(const char*);
	void SetVisible(bool v);
	bool IsVisible();
	void Maximize();
	void Minimize();
	void Restore();
	void SetBorderless(bool);
	void SetNoResize(bool);
	void SetNoMinimize(bool);
	tVec2i* GetSizeMinimum();
	tVec2i* GetBorderSize();
	tVec2i* GetCurrentSize();

	void ToFullscreenMode();
	void ToWindowMode();

	// it will call callback functions
	void OnActivate();
	void OnDeactivate();
	void OnSize();
	void OnSizing();
	void OnMinimize();
	void OnMaximize();
	void OnRestore();
	void OnDraw();
	void OnMove();
	void OnClose();

	tSysWindowCommonData* GetData() { return &m_data; }
};

#endif

