#include "Events.h"

int CountClick = 0;
void OnDestroy(HWND hWnd) {
	PostQuitMessage(0);
}
void OnRButtonDown(HWND hWnd, BOOL fDoubleClick, int x, int y, UINT keyFlags){
	
	if (!IsIconic(hWnd))
		ShowWindow(hWnd, SW_MINIMIZE);
	else
		ShowWindow(hWnd, SW_SHOWNORMAL);
}
BOOL OnCreate(HWND hWnd, LPCREATESTRUCT lpCreateStruct) {
	
	return true;
}
void OnPaint(HWND hWnd) {
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hWnd, &ps);
	/*HPEN hPen = CreatePen(PS_DASHDOTDOT, 2, NULL);*/
	
	HBRUSH hBrush;
	
	switch(CountClick) {
	case 0:
		hBrush = CreateSolidBrush(RGB(0, 0, 0));
		SelectObject(hdc, hBrush);
		Ellipse(hdc, 350, 100, 450, 200);

		hBrush = CreateSolidBrush(RGB(255, 0, 0));
		SelectObject(hdc, hBrush);
		Ellipse(hdc, 350, 200, 450, 300);

		hBrush = CreateSolidBrush(RGB(255, 255, 255));
		SelectObject(hdc, hBrush);
		Ellipse(hdc, 350, 300, 450, 400);	
		break;
	case 1:
		hBrush = CreateSolidBrush(RGB(255, 0, 0));
		SelectObject(hdc, hBrush);
		Ellipse(hdc, 350, 200, 450, 300);

		hBrush = CreateSolidBrush(RGB(255, 255, 255));
		SelectObject(hdc, hBrush);
		Ellipse(hdc, 350, 300, 450, 400);
		break;
	case 2:
		hBrush = CreateSolidBrush(RGB(255, 255, 255));
		SelectObject(hdc, hBrush);
		Ellipse(hdc, 350, 300, 450, 400);
		break;

	}
	ValidateRect(hWnd, NULL);
	EndPaint(hWnd, &ps);
	
}

void OnLButtonDown(HWND hWnd, BOOL fDoubleClick, int x, int y, UINT keyFlags) {
	CountClick++;
	InvalidateRect(hWnd, NULL, TRUE);
}

