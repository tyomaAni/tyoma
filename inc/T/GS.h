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

#ifndef _TY_GS_H_
#define _TY_GS_H_

#include "T/Common/UserData.h"

/// Graphics System
class tGS : public tUserData
{
public:
	tGS() {}
	virtual ~tGS() {}

	/// Init GPU things.
	/// `parameters` is optional thing, it depends on library implementation.
	virtual bool Init(tSysWindow*, const char* parameters) = 0;
	virtual void Shutdown() = 0;

	/// Init more window. For drawing in many windows.
	virtual bool InitWindow(tSysWindow*) = 0;
	
	/// For drawing in many windows.
	virtual void SetActiveWindow(tSysWindow*) = 0;

	/// Get name
	virtual tString GetName() = 0;

	/// Get all other info in text.
	virtual tString GetTextInfo() = 0;

	/// Get unique ID
	virtual tUID GetUID() = 0;

	//virtual void UseVSync(bool) = 0;
	//virtual bool UseDepth(bool) = 0; // return old
	//virtual bool UseBlend(bool) = 0; // return old
	virtual void EnableVSync() = 0;
	virtual void EnableDepth() = 0;
	virtual void EnableBlend() = 0;
	virtual void DisableVSync() = 0;
	virtual void DisableDepth() = 0;
	virtual void DisableBlend() = 0;
	virtual void IsVSync() = 0;
	virtual void IsDepth() = 0;
	virtual void IsBlend() = 0;

	/// use x and y
	virtual void GetDepthRange(tVec2f*) = 0;

	/// Color for `canvas`
	virtual void SetClearColor(float32_t r, float32_t g, float32_t b, float32_t a) = 0;

	/// Call before drawing
	virtual void BeginDraw() = 0;
	virtual void ClearDepth() = 0;
	virtual void ClearColor() = 0;
	virtual void ClearAll() = 0;    // ClearDepth и ClearColor
	/// Call after drawing
	virtual void EndDraw() = 0;
	virtual void SwapBuffers() = 0;

	/// Call this when window resized.
	/// x and y
	virtual void UpdateMainRenderTarget(const tVec2f&) = 0;

	virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;
	virtual void SetScissorRect(const tVec4f& rect, tVec4f* old) = 0;

	virtual void DrawLine3D(const tVec4& p1, const tVec4& p2, const tColor& c) = 0;

	virtual tGPUMesh* CreateMesh(tMesh*) = 0;

	virtual void SetShader(tShader*) = 0;
	virtual void SetMesh(tGPUMesh*) = 0;
	virtual void SetMaterial(tMaterial*) = 0;
	virtual void Draw() = 0;

	virtual tTexture* CreateTexture(tImage*, const tTextureInfo&) = 0;

	virtual void SetRenderTarget(tTexture*) = 0;
	virtual tTexture* CreateRenderTargetTexture(const tVec2i& size, const tTextureInfo&) = 0;

	// GUI drawing must be outside BeginDraw EndDraw
	virtual void BeginGUI() = 0;
	// t and UVs is optional
	virtual void DrawGUIRectangle(const tVec4i& rect, const tColor& color1, const tColor& color2,
		tTexture* t, tVec4f* UVs) = 0;
	virtual void DrawGUIRectangle(const tVec4i& rect, const tColor& color1, const tColor& color2,
		tTexture* t, tVec4f* UVs) = 0;
	virtual void DrawGUICharacter(char32_t, tGUIFont*, const tVec2i& position, const tColor&) = 0;
	virtual void DrawGUIText(const char32_t* text, uint32_t textSz, const tVec2i& position) = 0;
	virtual void EndGUI() = 0;

	virtual void DrawSprite(tSprite*) = 0;
	// Must be implemented DrawSprite
	virtual void DrawText3D(const tVec3& position, const char32_t* t, size_t tsz, tGUIFont* f, const tColor& c, float sizeMultipler = 0.1f) = 0;

	// Draw occluders between this
	virtual void OcclusionBegin() = 0;
	virtual void OcclusionEnd() = 0;
	virtual tGPUOcclusionObject* CreateOcclusionObject() = 0;
	// Set mesh using SetMesh
	// cullStep = false for first step
	// cullStep = true for second step
	virtual void OcclusionDraw(tGPUOcclusionObject*, bool cullStep) = 0;
};


#endif

