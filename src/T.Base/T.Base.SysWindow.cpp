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

#include "T.h"
#include "T/Input.h"

#ifdef T_PLATFORM_WINDOWS
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include "T/Common/SysWindowWin32.h"

LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
#endif

tSysWindow::tSysWindow(tSysWindowCallback* cb, int32_t sx, int32_t sy)
{
#ifdef T_PLATFORM_WINDOWS
    tSysWindowWin32* w32 = (tSysWindowWin32*)tMemory::Malloc(sizeof(tSysWindowWin32));
    m_data.m_implementation = w32;

    WNDCLASSEXW wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = GetModuleHandle(0);
    wcex.hIcon = 0;// LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_WIN32TEST));
    wcex.hCursor = LoadCursor(0, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = 0;

    static int windowCount = 0;
    wsprintf(w32->m_className, L"w%i", windowCount++);
    wcex.lpszClassName = w32->m_className;
    wcex.hIconSm = 0;// LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
    RegisterClassExW(&wcex);

    w32->m_hWnd = CreateWindowExW(
        0,
        w32->m_className,
        L"tSysWindow",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        sx,
        sy,
        0,
        0,
        wcex.hInstance,
        this
    );

    w32->m_style = GetWindowLongPtr(w32->m_hWnd, GWL_STYLE);

    int padding = GetSystemMetrics(SM_CXPADDEDBORDER);
    m_data.m_borderSize.x = GetSystemMetrics(SM_CXFRAME) + padding;
    m_data.m_borderSize.y = (GetSystemMetrics(SM_CYFRAME) + GetSystemMetrics(SM_CYCAPTION) + padding);
    m_data.m_borderSizeCurrent = m_data.m_borderSize;

    m_data.m_creationSize.x = (float)sx;
    m_data.m_creationSize.y = (float)sy;
    //m_data.m_currentSize = m_data.m_creationSize;
    RECT rc;
    GetClientRect(w32->m_hWnd, &rc);
    GetCurrentSize()->x = (float)(rc.right - rc.left);
    GetCurrentSize()->y = (float)(rc.bottom - rc.top);

    RAWINPUTDEVICE device;
    device.usUsagePage = 0x01;
    device.usUsage = 0x02;
    device.dwFlags = 0;
    device.hwndTarget = 0;
    RegisterRawInputDevices(&device, 1, sizeof device);

#endif

    m_data.m_cb = cb;
}

tSysWindow::~tSysWindow()
{
    if (m_data.m_implementation)
    {
#ifdef T_PLATFORM_WINDOWS
        tSysWindowWin32* w32 = (tSysWindowWin32*)m_data.m_implementation;
        if (w32->m_hWnd)
        {
            DestroyWindow((HWND)w32->m_hWnd);
            UnregisterClass(w32->m_className, GetModuleHandle(0));
        }
#endif

        tMemory::Free(m_data.m_implementation);
    }
}

void tSysWindow::SetTitle(const char* s)
{
    T_ASSERT_ST(s);
    T_ASSERT_ST(m_data.m_implementation);
#ifdef T_PLATFORM_WINDOWS
    tSysWindowWin32* w32 = (tSysWindowWin32*)m_data.m_implementation;
    if (w32->m_hWnd)
        SetWindowTextA(w32->m_hWnd, s);
#endif
}

void tSysWindow::SetVisible(bool v)
{
    T_ASSERT_ST(m_data.m_implementation);
    m_data.m_isVisible = v;
#ifdef T_PLATFORM_WINDOWS
    tSysWindowWin32* w32 = (tSysWindowWin32*)m_data.m_implementation;
    if (w32->m_hWnd)
        ShowWindow(w32->m_hWnd, v ? SW_SHOW : SW_HIDE);
#endif
}

bool tSysWindow::IsVisible()
{
    return m_data.m_isVisible;
}

void tSysWindow::Maximize()
{
    T_ASSERT_ST(m_data.m_implementation);
#ifdef T_PLATFORM_WINDOWS
    tSysWindowWin32* w32 = (tSysWindowWin32*)m_data.m_implementation;
    ShowWindow(w32->m_hWnd, SW_MAXIMIZE);
#endif
}

void tSysWindow::Minimize()
{
    T_ASSERT_ST(m_data.m_implementation);
#ifdef T_PLATFORM_WINDOWS
    tSysWindowWin32* w32 = (tSysWindowWin32*)m_data.m_implementation;
    ShowWindow(w32->m_hWnd, SW_MINIMIZE);
#endif
}

void tSysWindow::Restore()
{
    T_ASSERT_ST(m_data.m_implementation);
#ifdef T_PLATFORM_WINDOWS
    tSysWindowWin32* w32 = (tSysWindowWin32*)m_data.m_implementation;
    ShowWindow(w32->m_hWnd, SW_RESTORE);
#endif
}

void tSysWindow::SetBorderless(bool v)
{
    T_ASSERT_ST(m_data.m_implementation);

#ifdef T_PLATFORM_WINDOWS
    tSysWindowWin32* w32 = (tSysWindowWin32*)m_data.m_implementation;
    if (v)
        SetWindowLongPtr(w32->m_hWnd, GWL_STYLE, WS_POPUP);
    else
        SetWindowLongPtr(w32->m_hWnd, GWL_STYLE, w32->m_style);
    SetWindowPos(w32->m_hWnd, 0, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);
    ShowWindow(w32->m_hWnd, SW_NORMAL);
#endif
}

void tSysWindow::SetNoResize(bool v)
{
    T_ASSERT_ST(m_data.m_implementation);

#ifdef T_PLATFORM_WINDOWS
    tSysWindowWin32* w32 = (tSysWindowWin32*)m_data.m_implementation;
    if (v)
    {
        w32->m_style &= ~WS_THICKFRAME;
        w32->m_style &= ~WS_MAXIMIZEBOX;
    }
    else
        w32->m_style |= WS_THICKFRAME | WS_MAXIMIZEBOX;
    SetWindowLongPtr(w32->m_hWnd, GWL_STYLE, w32->m_style);
    SetWindowPos(w32->m_hWnd, 0, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);
    ShowWindow(w32->m_hWnd, SW_NORMAL);
#endif
}

void tSysWindow::SetNoMinimize(bool v)
{
    T_ASSERT_ST(m_data.m_implementation);

#ifdef T_PLATFORM_WINDOWS
    tSysWindowWin32* w32 = (tSysWindowWin32*)m_data.m_implementation;
    if (v)
    {
        w32->m_style &= ~WS_MINIMIZEBOX;
    }
    else
        w32->m_style |= WS_MINIMIZEBOX;
    SetWindowLongPtr(w32->m_hWnd, GWL_STYLE, w32->m_style);
    SetWindowPos(w32->m_hWnd, 0, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);
    ShowWindow(w32->m_hWnd, SW_NORMAL);
#endif
}

void tSysWindow::ToFullscreenMode()
{
    T_ASSERT_ST(m_data.m_implementation);
    if (m_data.m_isFullscreen)
        return;

#ifdef T_PLATFORM_WINDOWS
    tSysWindowWin32* w32 = (tSysWindowWin32*)m_data.m_implementation;
    w32->m_stylePreFullscreen = GetWindowLong(w32->m_hWnd, GWL_STYLE);
    MONITORINFO mi = { sizeof(mi) };

    if (GetWindowPlacement(w32->m_hWnd, &w32->m_wndPlcmnt) &&
        GetMonitorInfo(MonitorFromWindow(w32->m_hWnd, MONITOR_DEFAULTTOPRIMARY), &mi))
    {
        m_data.m_sizePreFullscreen = m_data.m_currentSize;

        m_data.m_currentSize.x = (float)(mi.rcMonitor.right - mi.rcMonitor.left);
        m_data.m_currentSize.y = (float)(mi.rcMonitor.bottom - mi.rcMonitor.top);
        //   _set_current_rect();

        SetWindowLong(w32->m_hWnd, GWL_STYLE, WS_POPUP);
        SetWindowPos(w32->m_hWnd, HWND_TOP,
            mi.rcMonitor.left, mi.rcMonitor.top,
            mi.rcMonitor.right - mi.rcMonitor.left,
            mi.rcMonitor.bottom - mi.rcMonitor.top,
            SWP_NOOWNERZORDER | SWP_FRAMECHANGED);
        m_data.m_isFullscreen = true;
        ShowWindow(w32->m_hWnd, SW_NORMAL);
    }
#endif
}

void tSysWindow::ToWindowMode()
{
    T_ASSERT_ST(m_data.m_implementation);
    if (!m_data.m_isFullscreen)
        return;
#ifdef T_PLATFORM_WINDOWS
    tSysWindowWin32* w32 = (tSysWindowWin32*)m_data.m_implementation;
    SetWindowLong(w32->m_hWnd, GWL_STYLE, w32->m_stylePreFullscreen);

    m_data.m_currentSize = m_data.m_sizePreFullscreen;

    //  _set_current_rect();

    SetWindowPlacement(w32->m_hWnd, &w32->m_wndPlcmnt);
    SetWindowPos(w32->m_hWnd, NULL, 0, 0, 0, 0,
        SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER |
        SWP_NOOWNERZORDER | SWP_FRAMECHANGED);
    m_data.m_isFullscreen = false;
    ShowWindow(w32->m_hWnd, SW_NORMAL);
#endif
}

void tSysWindow::OnActivate()
{
    T_ASSERT_ST(m_data.m_cb);
    m_data.m_cb->OnActivate(this);
}

void tSysWindow::OnDeactivate()
{
    T_ASSERT_ST(m_data.m_cb);
    m_data.m_cb->OnDeactivate(this);
}

tVec2i* tSysWindow::GetSizeMinimum()
{
    return &m_data.m_sizeMinimum;
}

tVec2i* tSysWindow::GetBorderSize()
{
    return &m_data.m_borderSize;
}

tVec2i* tSysWindow::GetCurrentSize()
{
    return &m_data.m_currentSize;
}

void tSysWindow::OnSize()
{
    T_ASSERT_ST(m_data.m_cb);
    m_data.m_cb->OnSize(this);
}

void tSysWindow::OnSizing()
{
    T_ASSERT_ST(m_data.m_cb);
    m_data.m_cb->OnSizing(this);
}

void tSysWindow::OnMinimize()
{
    T_ASSERT_ST(m_data.m_cb);
    m_data.m_isVisible = false;
    m_data.m_cb->OnMinimize(this);
}

void tSysWindow::OnMaximize()
{
    T_ASSERT_ST(m_data.m_cb);
    m_data.m_isVisible = true;
    m_data.m_cb->OnMaximize(this);
}

void tSysWindow::OnRestore()
{
    T_ASSERT_ST(m_data.m_cb);
    m_data.m_isVisible = true;
    m_data.m_cb->OnRestore(this);
}

void tSysWindow::OnDraw()
{
    T_ASSERT_ST(m_data.m_cb);
    m_data.m_cb->OnDraw(this);
}

void tSysWindow::OnMove()
{
    T_ASSERT_ST(m_data.m_cb);
    m_data.m_cb->OnMove(this);
}

void tSysWindow::OnClose()
{
    T_ASSERT_ST(m_data.m_cb);
    m_data.m_cb->OnClose(this);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

    int wmId = LOWORD(wParam);
    tSysWindow* pW = 0;
    if (message == WM_NCCREATE)
    {
        pW = static_cast<tSysWindow*>(reinterpret_cast<CREATESTRUCT*>(lParam)->lpCreateParams);
        SetLastError(0);
        if (!SetWindowLongPtr(hWnd, -21, reinterpret_cast<LONG_PTR>(pW)))
        {
            if (GetLastError() != 0)
                return FALSE;
        }
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    else
        pW = reinterpret_cast<tSysWindow*>(GetWindowLongPtr(hWnd, -21));

    switch (message)
    {
    case WM_NCMOUSEMOVE:
    case WM_MOUSEMOVE:
        //  printf("%i\n", HIWORD(lParam));
        break;
        /*case WM_CREATE: {
            pW->Rebuild();
            break;
        }*/

    case WM_ACTIVATE:
    {
        switch (wmId)
        {
        case WA_ACTIVE:
        case WA_CLICKACTIVE:
        {
            if (pW)
                pW->OnActivate();
            return DefWindowProc(hWnd, message, wParam, lParam);
        }break;
        case WA_INACTIVE:
            if (pW)
                pW->OnDeactivate();
            break;
        }
        break;
    }
    //case WM_DROPFILES:
    //{
    //    if (pW->m_onDropFiles)
    //    {
    //        //printf("DROP FILES\n");
    //        HDROP hDrop = (HDROP)wParam;
    //        if (hDrop)
    //        {
    //            UINT num = DragQueryFileW(hDrop, 0xFFFFFFFF, 0, 0);
    //            //printf("%u FILES\n", num);

    //            wchar_t* buf = new wchar_t[0xffff];
    //            for (UINT i = 0; i < num; ++i)
    //            {
    //                DragQueryFileW(hDrop, i, buf, 0xffff);
    //                buf[0xffff - 1] = 0;

    //                POINT pt;
    //                DragQueryPoint(hDrop, &pt);

    //                pW->m_onDropFiles(num, i, buf, pt.x, pt.y);
    //                //wprintf(L"FILE: %s\n", buf);
    //            }
    //            delete[] buf;

    //            DragFinish(hDrop);
    //        }
    //    }

    //    return 0;
    //}break;
    case WM_GETMINMAXINFO:
    {
        if (pW)
        {
            LPMINMAXINFO lpMMI = (LPMINMAXINFO)lParam;
            lpMMI->ptMinTrackSize.x = pW->GetSizeMinimum()->x;
            lpMMI->ptMinTrackSize.y = pW->GetSizeMinimum()->y;
        }
    }
    break;
    case WM_SIZE:
    {
        if (pW)
        {
            int wmId = LOWORD(wParam);
            switch (wmId)
            {
            case SIZE_MINIMIZED:
                pW->OnMinimize();
                break;
            case SIZE_RESTORED:
                pW->OnRestore();
                break;
            case SIZE_MAXIMIZED:
                pW->OnMaximize();
                break;
            }

            RECT rc;
            GetClientRect(hWnd, &rc);
            pW->GetCurrentSize()->x = (float)(rc.right - rc.left);
            pW->GetCurrentSize()->y = (float)(rc.bottom - rc.top);

            pW->OnSize();
        }

    }return DefWindowProc(hWnd, message, wParam, lParam);
    case WM_SIZING:
    {
        if (pW)
        {
            RECT rc;
            GetClientRect(hWnd, &rc);
            pW->GetCurrentSize()->x = (float)(rc.right - rc.left);
            pW->GetCurrentSize()->y = (float)(rc.bottom - rc.top);

            pW->OnSizing();
        }
    }break;
    case WM_COMMAND:
    {
        /*int wmId = LOWORD(wParam);
        switch (wmId)
        {
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }*/
    }
    break;

    case WM_ERASEBKGND:
    case WM_PAINT:
    {
        if (pW)
            pW->OnDraw();
    }break;
    case WM_MOVE:
    {
        if (pW)
            pW->OnMove();
    }break;
    case WM_INPUT:
    {
        if (pW)
        {
            HRAWINPUT hRawInput = (HRAWINPUT)lParam;
            UINT dataSize;
            GetRawInputData(hRawInput, RID_INPUT, NULL, &dataSize, sizeof(RAWINPUTHEADER));

            if (dataSize == 0 || dataSize > 0xff)
                break;

            tSysWindowWin32* w32 = (tSysWindowWin32*)pW->GetData()->m_implementation;


            void* dataBuf = &w32->m_rawInputData[0];
            GetRawInputData(hRawInput, RID_INPUT, dataBuf, &dataSize, sizeof(RAWINPUTHEADER));

            const RAWINPUT* raw = (const RAWINPUT*)dataBuf;
            if (raw->header.dwType == RIM_TYPEMOUSE)
            {
                HANDLE deviceHandle = raw->header.hDevice;

                const RAWMOUSE& mouseData = raw->data.mouse;

                USHORT flags = mouseData.usButtonFlags;
                short wheelDelta = (short)mouseData.usButtonData;
                LONG x = mouseData.lLastX, y = mouseData.lLastY;

                /*wprintf(
                    L"Mouse: Device=0x%08X, Flags=%04x, WheelDelta=%d, X=%d, Y=%d\n",
                    deviceHandle, flags, wheelDelta, x, y);*/

                tInputData* id = tInput::GetData();

                if (wheelDelta)
                    id->mouseWheelDelta = (float)wheelDelta / (float)WHEEL_DELTA;

                RECT rct;
                GetWindowRect(hWnd, &rct);

                POINT cursorPoint;
                GetCursorPos(&cursorPoint);
                //ScreenToClient(hWnd, &cursorPoint);
                id->mousePosition.x = (float)(cursorPoint.x - rct.left - pW->GetBorderSize()->x);
                id->mousePosition.y = (float)(cursorPoint.y - rct.top - pW->GetBorderSize()->y);

                // printf("%i %i\n", cursorPoint.x, cursorPoint.y);

                if (flags)
                {
                    if ((flags & 0x1) == 0x1)
                    {
                        tInput::EnableLMBDown();
                        tInput::EnableLMBHold();
                    }

                    if ((flags & 0x2) == 0x2)
                    {
                        tInput::EnableLMBUp();
                        tInput::DisableLMBHold();
                    }

                    if ((flags & 0x4) == 0x4)
                    {
                        tInput::EnableRMBDown();
                        tInput::EnableRMBHold();
                    }
                    if ((flags & 0x8) == 0x8)
                    {
                        tInput::EnableRMBUp();
                        tInput::DisableRMBHold();
                    }

                    if ((flags & 0x10) == 0x10)
                    {
                        tInput::EnableMMBDown();
                        tInput::EnableMMBHold();
                    }
                    if ((flags & 0x20) == 0x20)
                    {
                        tInput::EnableMMBUp();
                        tInput::DisableMMBHold();
                    }

                    if ((flags & 0x100) == 0x100)
                    {
                        tInput::EnableX1MBDown();
                        tInput::EnableX1MBHold();
                    }
                    if ((flags & 0x200) == 0x200)
                    {
                        tInput::EnableX1MBUp();
                        tInput::DisableX1MBHold();
                    }

                    if ((flags & 0x40) == 0x40)
                    {
                        tInput::EnableX2MBDown();
                        tInput::EnableX2MBHold();
                    }
                    if ((flags & 0x80) == 0x80)
                    {
                        tInput::EnableX2MBUp();
                        tInput::DisableX2MBHold();
                    }

                }

            }
        }
    }break;
    case WM_CLOSE:
        if (pW)
            pW->OnClose();
        return 0;

        // I don't know how to work with this in right way
    /*case WM_SETCURSOR: {
        if (pW->m_context)
        {
            int id = LOWORD(lParam);
            switch (id)
            {
            default:
                mgSetCursor(pW->m_context->m_gui_context, pW->m_context->m_gui_context->currentCursors[mgCursorType_Arrow], mgCursorType_Arrow);
                return TRUE;
            case HTLEFT:
                mgSetCursor(pW->m_context->m_gui_context, pW->m_context->m_gui_context->currentCursors[mgCursorType_SizeWE], mgCursorType_SizeWE);
                return TRUE;
            case HTRIGHT:
                mgSetCursor(pW->m_context->m_gui_context, pW->m_context->m_gui_context->currentCursors[mgCursorType_SizeWE], mgCursorType_SizeWE);
                return TRUE;
            case HTTOP:
                mgSetCursor(pW->m_context->m_gui_context, pW->m_context->m_gui_context->currentCursors[mgCursorType_SizeNS], mgCursorType_SizeNS);
                return TRUE;
            case HTBOTTOM:
                mgSetCursor(pW->m_context->m_gui_context, pW->m_context->m_gui_context->currentCursors[mgCursorType_SizeNS], mgCursorType_SizeNS);
                return TRUE;
            case HTTOPLEFT:
                mgSetCursor(pW->m_context->m_gui_context, pW->m_context->m_gui_context->currentCursors[mgCursorType_SizeNWSE], mgCursorType_SizeNWSE);
                return TRUE;
            case HTBOTTOMRIGHT:
                mgSetCursor(pW->m_context->m_gui_context, pW->m_context->m_gui_context->currentCursors[mgCursorType_SizeNWSE], mgCursorType_SizeNWSE);
                return TRUE;
            case HTBOTTOMLEFT:
                mgSetCursor(pW->m_context->m_gui_context, pW->m_context->m_gui_context->currentCursors[mgCursorType_SizeNESW], mgCursorType_SizeNESW);
                return TRUE;
            case HTTOPRIGHT:
                mgSetCursor(pW->m_context->m_gui_context, pW->m_context->m_gui_context->currentCursors[mgCursorType_SizeNESW], mgCursorType_SizeNESW);
                return TRUE;
            case HTHELP:
                mgSetCursor(pW->m_context->m_gui_context, pW->m_context->m_gui_context->currentCursors[mgCursorType_Help], mgCursorType_Help);
                return TRUE;
            }
        }
    }break;*/
    case WM_SYSKEYDOWN:
    case WM_SYSKEYUP:
    case WM_KEYDOWN:
    case WM_KEYUP:
    {
        bool isPress = true;

        unsigned char key = (unsigned char)wParam;

        if (message == WM_SYSKEYUP) isPress = false;
        if (message == WM_KEYUP) isPress = false;

        const UINT MY_MAPVK_VSC_TO_VK_EX = 3;

        if (key == tInput::KEY_SHIFT)
        { // shift -> lshift rshift
            key = static_cast<unsigned char>(MapVirtualKey((static_cast<UINT>(lParam >> 16) & 255u), MY_MAPVK_VSC_TO_VK_EX));
        }
        if (key == tInput::KEY_CTRL)
        { // ctrl -> lctrl rctrl
            key = static_cast<unsigned char>(MapVirtualKey((static_cast<UINT>(lParam >> 16) & 255), MY_MAPVK_VSC_TO_VK_EX));
            if (lParam & 0x1000000)
                key = static_cast<unsigned char>(163);
        }

        if (key == tInput::KEY_ALT)
        { // alt -> lalt ralt
            key = static_cast<unsigned char>(MapVirtualKey((static_cast<UINT>(lParam >> 16) & 255), MY_MAPVK_VSC_TO_VK_EX));
            if (lParam & 0x1000000)
                key = static_cast<unsigned char>(165);
            //printf("alt = %i\n",(int)ev.keyboardEvent.key);
        }

        if (isPress)
        {
            if (key < 256)
            {
                tInput::SetKeyHold(key, true);
                tInput::SetKeyHit(key, true);
            }
        }
        else
        {
            if (key < 256)
            {
                tInput::SetKeyHold(key, false);
                tInput::SetKeyRelease(key, true);
            }
        }

        if (message == WM_SYSKEYDOWN || message == WM_SYSKEYUP)
        {
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
        else
        {
            return 0;
        }
    }break;
    case WM_CHAR:
    {
        tInputData* id = tInput::GetData();
        id->character = wParam;
    }break;

    case WM_SYSCOMMAND:
        if ((wParam & 0xFFF0) == SC_SCREENSAVE ||
            (wParam & 0xFFF0) == SC_MONITORPOWER ||
            (wParam & 0xFFF0) == SC_KEYMENU
            )
        {
            return 0;
        }
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}
