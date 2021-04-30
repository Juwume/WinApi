#include <Windows.h>
#include <tchar.h>
#include<Strsafe.h>

#define ID_STATIC 1
#define MAX_STR_LEN 20

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

TCHAR WinName[] = _T("Lab3");

TCHAR StaticString[40] = _T("             ");
int StaticStringCount = 0;

void MoveString(TCHAR* str) {
	for (int i = 0; i < _tcslen(str); i++)
	{
		str[i] = str[i + 1];
	}
	
}
void AddMoveString(TCHAR* str) {
	for (int i = _tcslen(str); i > 0; i--)
	{
		str[i] = str[i - 1];
	}
	str[0] = _T(' ');

}

void DelSpace(TCHAR *str, TCHAR *out) {
	int i,j=0;
	for (i = 0; i < _tcslen(str); i++)
	{
		if (str[i] != ' ') {
			out[j] = str[i];
			j++;
		}
	}
	out[j] = '\0';
}

void OnButtClick(HWND hWnd, TCHAR Symb) {
	if (StaticStringCount < MAX_STR_LEN) {
		if (StaticStringCount % 2 == 0) {
			MoveString(StaticString);
		}
		StaticString[_tcslen(StaticString)] = Symb;
		StaticStringCount++;
		SetDlgItemText(hWnd, ID_STATIC, StaticString);
	}
	else
		MessageBox(NULL, _T("Слишком много символов"), _T("ОШИБКА"), MB_DEFAULT_DESKTOP_ONLY);
}

int WINAPI _tWinMain(HINSTANCE This,		 // Дескриптор текущего приложения 
	HINSTANCE Prev, 	// В современных системах всегда 0 
	LPTSTR cmd, 		// Командная строка 
	int mode) 		// Режим отображения окна
{
	HWND hWnd;		// Дескриптор главного окна программы 
	MSG msg; 		// Структура для хранения сообщения 
	WNDCLASS wc; 	// Класс окна
	// Определение класса окна 
	wc.hInstance = This;
	wc.lpszClassName = WinName; 				// Имя класса окна 
	wc.lpfnWndProc = WndProc; 					// Функция окна 
	wc.style = CS_HREDRAW | CS_VREDRAW; 			// Стиль окна 
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); 		// Стандартная иконка 
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); 		// Стандартный курсор 
	wc.lpszMenuName = NULL; 					// Нет меню 
	wc.cbClsExtra = 0; 						// Нет дополнительных данных класса 
	wc.cbWndExtra = 0; 						// Нет дополнительных данных окна 
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); 	// Заполнение окна белым цветом 


	// Регистрация класса окна
	if (!RegisterClass(&wc)) return 0;

	// Создание окна 
	hWnd = CreateWindow(WinName,			// Имя класса окна 
		WinName, 		// Заголовок окна 
		WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME, 		// Стиль окна 
		CW_USEDEFAULT,				// x 
		CW_USEDEFAULT, 				// y	 Размеры окна 
		360, 				// width 
		490, 				// Height 
		HWND_DESKTOP, 				// Дескриптор родительского окна 
		NULL, 						// Нет меню 
		This, 						// Дескриптор приложения 
		NULL); 					// Дополнительной информации нет 

	ShowWindow(hWnd, mode); 				// Показать окно
	UpdateWindow(hWnd);
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

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	HINSTANCE hInst;
	PAINTSTRUCT ps;

	static HWND hButton_1;
	static HWND hButton_2;
	static HWND hButton_3;
	static HWND hButton_4;
	static HWND hButton_5;
	static HWND hButton_6;
	static HWND hButton_7;
	static HWND hButton_8;
	static HWND hButton_9;
	static HWND hButton_0;
	static HWND hButton_hash;
	static HWND hButton_plus;
	static HWND hButton_call;
	static HWND hButton_del;
	static HWND hField;
	static HWND hStat;

	switch (message)		 // Обработчик сообщений
	{
	case WM_PAINT:
		break;
	case WM_CREATE: {
		hInst = ((LPCREATESTRUCT)lParam)->hInstance;

		hStat = CreateWindow(_T("STATIC"), _T(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTERIMAGE,
			13, 20, 320, 70, hWnd, (HMENU)ID_STATIC, hInst, NULL);
		HFONT hFont = CreateFont(30, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, L"Arial");
		SendMessage(hStat, WM_SETFONT, WPARAM(hFont), TRUE);
		ShowWindow(hStat, SW_SHOW);

		hButton_1 = CreateWindow(_T("BUTTON"), _T("1"),
			WS_CHILD | WS_VISIBLE | WS_BORDER,
			13, 110, 100, 50, hWnd, 0, hInst, NULL);
		ShowWindow(hButton_1, SW_SHOW);

		hButton_2 = CreateWindow(_T("BUTTON"), _T("2"),
			WS_CHILD | WS_VISIBLE | WS_BORDER,
			123, 110, 100, 50, hWnd, 0, hInst, NULL);
		ShowWindow(hButton_2, SW_SHOW);

		hButton_3 = CreateWindow(_T("BUTTON"), _T("3"),
			WS_CHILD | WS_VISIBLE | WS_BORDER,
			233, 110, 100, 50, hWnd, 0, hInst, NULL);
		ShowWindow(hButton_3, SW_SHOW);

		hButton_4 = CreateWindow(_T("BUTTON"), _T("4"),
			WS_CHILD | WS_VISIBLE | WS_BORDER,
			13, 180, 100, 50, hWnd, 0, hInst, NULL);
		ShowWindow(hButton_4, SW_SHOW);

		hButton_5 = CreateWindow(_T("BUTTON"), _T("5"),
			WS_CHILD | WS_VISIBLE | WS_BORDER,
			123, 180, 100, 50, hWnd, 0, hInst, NULL);
		ShowWindow(hButton_5, SW_SHOW);

		hButton_6 = CreateWindow(_T("BUTTON"), _T("6"),
			WS_CHILD | WS_VISIBLE | WS_BORDER,
			233, 180, 100, 50, hWnd, 0, hInst, NULL);
		ShowWindow(hButton_6, SW_SHOW);

		hButton_7 = CreateWindow(_T("BUTTON"), _T("7"),
			WS_CHILD | WS_VISIBLE | WS_BORDER,
			13, 250, 100, 50, hWnd, 0, hInst, NULL);
		ShowWindow(hButton_7, SW_SHOW);

		hButton_8 = CreateWindow(_T("BUTTON"), _T("8"),
			WS_CHILD | WS_VISIBLE | WS_BORDER,
			123, 250, 100, 50, hWnd, 0, hInst, NULL);
		ShowWindow(hButton_8, SW_SHOW);

		hButton_9 = CreateWindow(_T("BUTTON"), _T("9"),
			WS_CHILD | WS_VISIBLE | WS_BORDER,
			233, 250, 100, 50, hWnd, 0, hInst, NULL);
		ShowWindow(hButton_9, SW_SHOW);

		hButton_0 = CreateWindow(_T("BUTTON"), _T("0"),
			WS_CHILD | WS_VISIBLE | WS_BORDER,
			123, 320, 100, 50, hWnd, 0, hInst, NULL);
		ShowWindow(hButton_0, SW_SHOW);

		hButton_hash = CreateWindow(_T("BUTTON"), _T("#"),
			WS_CHILD | WS_VISIBLE | WS_BORDER,
			233, 320, 100, 50, hWnd, 0, hInst, NULL);
		ShowWindow(hButton_hash, SW_SHOW);

		hButton_plus = CreateWindow(_T("BUTTON"), _T("+"),
			WS_CHILD | WS_VISIBLE | WS_BORDER,
			13, 320, 100, 50, hWnd, 0, hInst, NULL);
		ShowWindow(hButton_plus, SW_SHOW);

		hButton_call = CreateWindow(_T("BUTTON"), _T("📞"),
			WS_CHILD | WS_VISIBLE | WS_BORDER,
			123, 390, 100, 50, hWnd, 0, hInst, NULL);
		ShowWindow(hButton_call, SW_SHOW);

		hButton_del = CreateWindow(_T("BUTTON"), _T("⌫"),
			WS_CHILD | WS_VISIBLE | WS_BORDER,
			233, 390, 100, 50, hWnd, 0, hInst, NULL);
		ShowWindow(hButton_del, SW_SHOW);
		break; 
	}
	case WM_COMMAND:
		if (lParam == (LPARAM)hButton_1)
			OnButtClick(hWnd, _T('1'));
		else if (lParam == (LPARAM)hButton_2)
			OnButtClick(hWnd, _T('2'));
		else if (lParam == (LPARAM)hButton_3)
			OnButtClick(hWnd, _T('3'));
		else if (lParam == (LPARAM)hButton_4)
			OnButtClick(hWnd, _T('4'));
		else if (lParam == (LPARAM)hButton_5)
			OnButtClick(hWnd, _T('5'));
		else if (lParam == (LPARAM)hButton_6)
			OnButtClick(hWnd, _T('6'));
		else if (lParam == (LPARAM)hButton_7)
			OnButtClick(hWnd, _T('7'));
		else if (lParam == (LPARAM)hButton_8)
			OnButtClick(hWnd, _T('8'));
		else if (lParam == (LPARAM)hButton_9)
			OnButtClick(hWnd, _T('9'));
		else if (lParam == (LPARAM)hButton_0)
			OnButtClick(hWnd, _T('0'));
		else if (lParam == (LPARAM)hButton_plus)
			OnButtClick(hWnd, _T('+'));
		else if (lParam == (LPARAM)hButton_hash)
			OnButtClick(hWnd, _T('#'));
		else if (lParam == (LPARAM)hButton_call) {
			TCHAR Answer[70] = _T("Вы позвонили на номер ");
			TCHAR temp[50];
			DelSpace(StaticString, temp);
			for (int i = 0; i < 14; i++)
			{
				StaticString[i] = _T(' ');
			}
			StaticString[14] = _T('\0');
			StaticStringCount = 0;
			SetDlgItemText(hWnd, ID_STATIC, StaticString);
			StringCchCat(Answer, STRSAFE_MAX_CCH, temp);
			MessageBox(NULL, Answer, _T("Происходит вызов"), MB_DEFAULT_DESKTOP_ONLY);
		} 
		else if (lParam == (LPARAM)hButton_del) {
			if (StaticStringCount >= 0) {
				StaticString[_tcslen(StaticString) - 1] = '\0';
				StaticStringCount--;
				if (StaticStringCount % 2 == 0)
					AddMoveString(StaticString);
				SetDlgItemText(hWnd, ID_STATIC, StaticString);
			}
		}


			
		
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break; 			// Завершение программы 
	default: 			// Обработка сообщения по умолчанию 
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}