// Lab1_win32.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Lab2_win32.h"
#include <Windows.h>
#include <windowsx.h>
#include <tchar.h>
#include "Events.h" 

LRESULT CALLBACK WndProcFir(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndProcSec(HWND, UINT, WPARAM, LPARAM);

TCHAR WinNameFir[] = _T("FirstWin");
TCHAR WinNameSec[] = _T("SecondWin");

int WINAPI _tWinMain(HINSTANCE This,		 // Дескриптор текущего приложения 
	HINSTANCE Prev, 	// В современных системах всегда 0 
	LPTSTR cmd, 		// Командная строка 
	int mode) 		// Режим отображения окна
{
	HWND hWndFir;	// Дескриптор первого окна
	MSG msg; 		// Структура для хранения сообщения 
	
	WNDCLASS wcf; 	// Класс окна
	wcf.hInstance = This;
	wcf.lpszClassName = WinNameFir; 				// Имя класса окна 
	wcf.lpfnWndProc = WndProcFir; 					// Функция окна 
	wcf.style = CS_HREDRAW | CS_VREDRAW; 			// Стиль окна 
	wcf.hIcon = LoadIcon(NULL, IDI_APPLICATION); 		// Стандартная иконка 
	wcf.hCursor = LoadCursor(NULL, IDC_ARROW); 		// Стандартный курсор 
	wcf.lpszMenuName = NULL; 					// Нет меню 
	wcf.cbClsExtra = 0; 						// Нет дополнительных данных класса 
	wcf.cbWndExtra = 0; 						// Нет дополнительных данных окна 
	wcf.hbrBackground = CreateSolidBrush(RGB(255, 255, 255)); 	// Заполнение окна белым цветом 


	// Регистрация класса окна
	if (!RegisterClass(&wcf)) return 30;
	

	// Создание окна 
	hWndFir = CreateWindow(WinNameFir,			// Имя класса окна 
		_T("Окно 1"), 		// Заголовок окна 
		WS_OVERLAPPEDWINDOW, 		// Стиль окна 
		CW_USEDEFAULT,				// x 
		CW_USEDEFAULT, 				// y	 Размеры окна 
		CW_USEDEFAULT, 				// width 
		CW_USEDEFAULT, 				// Height 
		HWND_DESKTOP, 				// Дескриптор родительского окна 
		NULL, 						// Нет меню 
		This, 						// Дескриптор приложения 
		NULL);						// Дополнительной информации нет 



	ShowWindow(hWndFir, mode); 				// Показать окно

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

LRESULT CALLBACK WndProcFir(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)		 // Обработчик сообщений
	{

		HANDLE_MSG(hWnd, WM_DESTROY, OnDestroy);
		HANDLE_MSG(hWnd, WM_RBUTTONDOWN, OnRButtonDown);
		HANDLE_MSG(hWnd, WM_LBUTTONDOWN, OnLButtonDown);
		HANDLE_MSG(hWnd, WM_PAINT, OnPaint);
		/*HANDLE_MSG(hWnd, WM_CREATE, OnCreate);*/

	default: 			// Обработка сообщения по умолчанию 
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}



