// Lab1_win32.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Lab2.2_win32.h"
#include <Windows.h>
#include <windowsx.h>
#include <tchar.h>
#include "Events.h" 

LRESULT CALLBACK WndProcSec(HWND, UINT, WPARAM, LPARAM);

TCHAR WinNameFir[] = _T("FirstWin");
TCHAR WinNameSec[] = _T("SecondWin");

BOOL NeedRepaint = FALSE;


int WINAPI _tWinMain(HINSTANCE This,		 // Дескриптор текущего приложения 
	HINSTANCE Prev, 	// В современных системах всегда 0 
	LPTSTR cmd, 		// Командная строка 
	int mode) 		// Режим отображения окна
{
	HWND hWndSec;	// Дескриптор второго окна 
	MSG msg; 		// Структура для хранения сообщения 

	
	WNDCLASS wcs; 	// Класс окна
	wcs.hInstance = This;
	wcs.lpszClassName = WinNameSec; 				// Имя класса окна 
	wcs.lpfnWndProc = WndProcSec; 					// Функция окна 
	wcs.style = CS_HREDRAW | CS_VREDRAW; 			// Стиль окна 
	wcs.hIcon = LoadIcon(NULL, IDI_APPLICATION); 		// Стандартная иконка 
	wcs.hCursor = LoadCursor(NULL, IDC_ARROW); 		// Стандартный курсор 
	wcs.lpszMenuName = NULL; 					// Нет меню 
	wcs.cbClsExtra = 0; 						// Нет дополнительных данных класса 
	wcs.cbWndExtra = 0; 						// Нет дополнительных данных окна 
	wcs.hbrBackground = CreateSolidBrush(RGB(255, 255, 255)); 	// Заполнение окна белым цветом 


	if (!RegisterClass(&wcs)) return 25;
	hWndSec = CreateWindow(WinNameSec,			// Имя класса окна 
		_T("Окно 2"), 		// Заголовок окна 
		WS_OVERLAPPEDWINDOW, 		// Стиль окна 
		CW_USEDEFAULT,				// x 
		CW_USEDEFAULT, 				// y	 Размеры окна 
		CW_USEDEFAULT, 				// width 
		CW_USEDEFAULT, 				// Height 
		HWND_DESKTOP, 				// Дескриптор родительского окна 
		NULL, 						// Нет меню 
		This, 						// Дескриптор приложения 
		NULL); 					// Дополнительной информации нет 

		
	ShowWindow(hWndSec, mode);

	// Цикл обработки сообщений 
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg); 		// Функция трансляции кодов нажатой клавиши 
		DispatchMessage(&msg); 		// Посылает сообщение функции WndProc() 
	}
	return 0;
}

// Оконная функция вызывается операционной системой
// и получает сообщения из очереди для данного приложения



LRESULT CALLBACK WndProcSec(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)		 // Обработчик сообщений
	{

		HANDLE_MSG(hWnd, WM_DESTROY, OnDestroy);
		HANDLE_MSG(hWnd, WM_RBUTTONDOWN, OnRButtonDown);
		HANDLE_MSG(hWnd, WM_LBUTTONDOWN, OnLButtonDown);
	case WM_PAINT:
		if (NeedRepaint) {
			HBRUSH brush = CreateSolidBrush(RGB(rand() % 256, rand() % 256, rand() % 256));               // <---
			SetClassLong(hWnd, GCL_HBRBACKGROUND, (LONG)brush);
		}
		NeedRepaint = FALSE;
		break;
	case WM_USER + 1: {
		HWND hWndOther = (HWND)wParam;
		if (!hWndOther) {
			MessageBox(NULL, _T("Чел ты, у меня нет ничего"), _T("FATAL ERROR"), MB_DEFAULT_DESKTOP_ONLY);
		}
		else {
			MessageBox(NULL, _T("Дескриптор принял"), _T("Ok"), MB_DEFAULT_DESKTOP_ONLY);
			NeedRepaint = TRUE;
			InvalidateRect(hWnd, NULL, TRUE);
		}
		break;
	}
	case WM_USER + 2: {
		HWND hWndOther = (HWND)wParam;
		if (!hWndOther) {
			MessageBox(NULL, _T("Чел ты, у меня нет ничего"), _T("FATAL ERROR"), MB_DEFAULT_DESKTOP_ONLY);
		}
		else {
			MessageBox(NULL, _T("Дескриптор принял"), _T("Ok"), MB_DEFAULT_DESKTOP_ONLY);
			ShowWindow(hWnd, SW_MAXIMIZE);
		}
		break; 
	}
		/*HANDLE_MSG(hWnd, WM_CREATE, OnCreate);*/

	default: 			// Обработка сообщения по умолчанию 
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

