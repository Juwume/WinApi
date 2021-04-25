#include "Events.h"

int CountClick = 0;
void OnDestroy(HWND hWnd) {
	PostQuitMessage(0);
}
void OnRButtonDown(HWND hWnd, BOOL fDoubleClick, int x, int y, UINT keyFlags) {
	HWND hWndSec = FindWindow(_T("SecondWin"), NULL);
	if (!hWndSec) {
		MessageBox(NULL, _T("Äåñêðèïòîð íå íàéäåí, çàïóñêàþ ïðèëîæåíèå"), _T("Error"), MB_DEFAULT_DESKTOP_ONLY);
		STARTUPINFO si = { 0 };
		PROCESS_INFORMATION pi = { 0 };
		TCHAR czCommandLine[] = TEXT("");

		CreateProcess(L"C:\\Users\\makss\\source\\repos\\lab2.2_win32\\Debug\\lab2.2_win32.exe",
			czCommandLine,
			NULL,
			NULL,
			FALSE,
			NULL,
			NULL,
			NULL,
			&si,
			&pi);
		hWndSec = FindWindow(_T("SecondWin"), NULL);
	}
	else {

		MessageBox(NULL, _T("Äåñêðèïòîð íàéäåí"), _T("Ok"), MB_DEFAULT_DESKTOP_ONLY);
		PostMessage(hWndSec, WM_USER + 2, (WPARAM)hWnd, NULL);
	}
	

}
BOOL OnCreate(HWND hWnd, LPCREATESTRUCT lpCreateStruct) {
		
		return true;
}
void OnPaint(HWND hWnd) {
	

}

void OnLButtonDown(HWND hWnd, BOOL fDoubleClick, int x, int y, UINT keyFlags) {
	HWND hWndSec = FindWindow(_T("SecondWin"), NULL);
	if (!hWndSec) {
		MessageBox(NULL, _T("Äåñêðèïòîð íå íàéäåí, çàïóñêàþ ïðèëîæåíèå"), _T("Error"), MB_DEFAULT_DESKTOP_ONLY);
		STARTUPINFO si = { 0 };
		PROCESS_INFORMATION pi = { 0 };
		TCHAR czCommandLine[] = TEXT("");

		CreateProcess(L"C:\\Users\\makss\\source\\repos\\lab2.2_win32\\Debug\\lab2.2_win32.exe",
			czCommandLine,
			NULL,
			NULL,
			FALSE,
			NULL,
			NULL,
			NULL,
			&si,
			&pi);
		hWndSec = FindWindow(_T("SecondWin"), NULL);
	}
	else {

		MessageBox(NULL, _T("Äåñêðèïòîð íàéäåí"), _T("Ok"), MB_DEFAULT_DESKTOP_ONLY);
		PostMessage(hWndSec, WM_USER + 1, (WPARAM)hWnd, NULL);
	}
	
}

