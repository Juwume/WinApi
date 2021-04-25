#pragma once

#include "framework.h"
#include <Windows.h>
#include <tchar.h>

void OnDestroy(HWND hWnd);
void OnRButtonDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags);
void OnLButtonDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags);
BOOL OnCreate(HWND hWnd, LPCREATESTRUCT lpCreateStruct);
void OnPaint(HWND hWnd);



