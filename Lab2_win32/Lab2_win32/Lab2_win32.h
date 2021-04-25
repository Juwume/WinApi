#pragma once

#include "resource.h"

#define RGB(r, g, b) ((COLORREF)(((BYTE)(r) | ((WORD)(g) << 8)) | ((DWORD)(BYTE)(b)) << 16))
#define HANDLE_MSG(hWnd, message, fn); case (message): return HANDLE_##message ((hWnd), (wParam), (lParam), (fn));

#define HANDLE_WM_DESTROY(hWnd,wParam,lParam,fn)((fn)(hWnd),0L)
#define HANDLE_WM_RBUTTONDOWN(hWnd, wParam, lParam, fn)((fn)(hWnd,0,GET_X_LPARAM(lParam),GET_Y_LPARAM(lParam),0),0)
#define HANDLE_WM_LBUTTONDOWN(hWnd, wParam, lParam, fn)((fn)(hWnd,0,GET_X_LPARAM(lParam),GET_Y_LPARAM(lParam),0),0)
#define HANDLE_WM_CREATE(hWnd,wParam,lParam,fn)((fn)(hWnd,(LPCREATESTRUCT) lParam),0L)
#define HANDLE_WM_PAINT(hWnd,wParam,lParam,fn)((fn)(hWnd),0L)

