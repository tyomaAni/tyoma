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
#ifndef _TY_F_H_
#define _TY_F_H_

// Some callbacks. Some information from framework will be here.
class tFrameworkCallback
{
public:
	tFrameworkCallback() {}
	virtual ~tFrameworkCallback() {}

	virtual void OnMessage() = 0;
};

enum class tMatrixType : uint32_t
{
	World,
	View,
	Projection,
	ViewProjection, //For 3d line
	WorldViewProjection,
	ViewInvert,
	//GUIProjection,
	_count
};

// Main API for framework.
// It will be static methods.
class tFramework
{
public:
	//allocate implementation
	static void Start(tFrameworkCallback*);

	//deallocate implementation
	static void Stop();

	//calculate deltatime, update input, update GUI, update window
	static void Update();

	//create window. CreateWindow is winapi function so I will use word `summon`
	static tSysWindow* CreateWindow(tSysWindowCallback*, int sx, int sy);

	// Get number of Graphics Systems
	static uint32_t GetGSNum();
	static tString GetGSName(uint32_t);
	static tUID GetGSUID(uint32_t);
	// Create GS using slUID
	static tGS* CreateGS(tUID);
	// Create GS using it's name
	static tGS* CreateGS(const char*);
	// Both
	static tGS* CreateGS(tUID, const char*);

	static uint32_t GetMeshLoadersNum();
	static tMeshLoader* GetMeshLoader(uint32_t);
	static void CreateMesh(const char*, tMeshLoaderCallback*);

	static float* GetDeltaTime();

	static bool PointInRect(tVec4i* r, tVec2i* p);
	static void PointSet(tVec2i* p, int32_t x, int32_t y);
	static void RectSet(tVec4i* rct, int32_t l, int32_t t, int32_t r, int32_t b);

	static bool CompareUIDs(const tUID&, const tUID&);

	static tMat4* GetMatrix(tMatrixType);
	static void SetMatrix(tMatrixType, tMat4*);

	static tMat4* GetMatrixAni();
	static void SetMatrixAni(const tMat4&, uint32_t slot);

	static tSceneCamera* CreateSceneCamera();

	static bool FileExist(const char*);
	static bool FileExist(const tString&);

	static uint64_t FileSize(const char*);
	static uint64_t FileSize(const tString&);

	static tPolygonMesh* CreatePolygonMesh();

	static tString GetAppPath();

	// app path + `path`
	// if file not exist, pop_front removing . \\ / from `path` and return it.
	// so we can use files from zip archive
	static tStringA GetPathA(const tString& path);

	static uint32_t GetImageLoadersNum();
	static tImageLoader* GetImageLoader(uint32_t);
	static tImage* CreateImage(const char*);

	// read or unzip file into buffer
	// if isText then will be added ' ' and 0 at the end
	// Use tMemory::Free of tFramework::Destroy
	static uint8_t* CreateFileBuffer(const char* path, uint32_t* szOut, bool isText);

	static void SetImageLoaderConvertToRGBA8(bool);
	static bool GetImageLoaderConvertToRGBA8();

	static tGUIFont* CreateFont();

	static tGUIStyle* GetGUIStyle(const tGUIStyleTheme&);
	static tGUIWindow* CreateGUIWindow(const tVec2i& position, const tVec2i& size);
	// Destroy GUI window and all elements in this window
	static void Destroy(tGUIWindow*);
	// also will be destroyed all children
	static void Destroy(tGUIElement*);
	static tGUIState* GetGUIState();

	static void DrawGUI(tGS*);
	static void RebuildGUI();
	//static slGUIButton* SummonGUIButton(slGUIWindow*);

	static void InitDefaultFonts(tGS*);
	static tGUIFont* GetDefaultFont(const tGUIDefaultFont&);
	static tGUIDrawTextCallback* GetDefaultDrawTextCallback();
	static tVec2i GetTextSize(const char32_t* text, tGUIFont*);

	static tSprite* CreateSprite(tTexture*);
};



#endif
