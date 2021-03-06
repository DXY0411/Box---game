//WindowsProject1.cpp: 定义应用程序的入口点。
//
#include <windows.h>
#include "stdafx.h"
#include "推箱子 丁辛夷.h"
#include "Resource.h"
//hahahaha
// 此代码模块中包含的函数的前向声明: 
ATOM               MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_WINDOWSPROJECT1, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	for (int i = 1; i <= 6; i++)
		writeMap(i);

	// 执行应用程序初始化: 
	if (!InitInstance(hInstance, nCmdShow))
		return FALSE;

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT1));

	MSG msg = { 0 };
	hdc = GetDC(hWnd);
	int fGotMessage;


	// 主消息循环: 
	while ((fGotMessage = GetMessage(&msg, (HWND)NULL, 0, 0)) != 0
		&& fGotMessage != -1)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}


//
//  函数: MyRegisterClass()
//
//  目的: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT1));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = CreateSolidBrush(RGB(240, 248, 255));
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT1);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目的: 保存实例句柄并创建主窗口
//
//   注释: 
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; 
	hWnd = CreateWindowW(
		szTitle,
		TEXT("推箱子游戏---丁辛夷"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		nullptr,
		nullptr,
		hInstance,
		nullptr);

	if (!hWnd)
		return FALSE;

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}


//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的:    处理主窗口的消息。
//
//  WM_COMMAND  - 处理应用程序菜单
//  WM_PAINT    - 绘制主窗口
//  WM_DESTROY  - 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HFONT hFont;
	static HBRUSH hSolidBrush;
	static HBRUSH hHatchBrush;
	static HWND hBtn1;
	static HWND hBtn2;
	int wmId;
	switch (message)
	{
	case WM_CREATE:
		hBtn1 = CreateWindow(L"Button", L"重玩本关", WS_CHILD | WS_VISIBLE | WS_BORDER,
			520 + 55, 24 + 251, 100, 50, hWnd, (HMENU)1, hInst, NULL);
		hBtn2 = CreateWindow(TEXT("BUTTON"), TEXT("跳过本关"), WS_CHILD | WS_VISIBLE | WS_BORDER,
			520 + 55, 24 + 350, 100 , 50, hWnd, (HMENU)2, hInst, NULL);
		ShowWindow(hBtn1, SW_SHOW);
		ShowWindow(hBtn2, SW_SHOW);
		break;
	case WM_KEYDOWN:
		PlayGame(wParam);
		break;
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		switch (wmId)
		{
		case 1:
			PlayGame('P');
			MessageBox(NULL, L"已重新开始本关!", L"提示", MB_OK| MB_SYSTEMMODAL);
			break;
		case 2:
			PlayGame('N');
			MessageBox(NULL, L"已跳过本关", L"提示", MB_OK | MB_SYSTEMMODAL);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		text = true;
		HDC hMemDC;
		PAINTSTRUCT ps;			
		HBITMAP hbmMem, hbmOld;

	    BeginPaint(hWnd, &ps);
		hMemDC = CreateCompatibleDC(hdc);	
		hbmMem = CreateCompatibleBitmap(hdc, WINDOW_WIDTH, WINDOW_HEIGHT);
		hbmOld = (HBITMAP)SelectObject(hMemDC, hbmMem);
		nextDrawMapBase();
		DrawMap(hMemDC);
		BitBlt(hdc, 4, 33, 504, 446, hMemDC, 0, 0, SRCCOPY);
		SelectObject(hMemDC, hbmOld);
		DeleteObject(hbmMem);
		DeleteDC(hMemDC);
		EndPaint(hWnd, &ps);

		nextMap();
		TextFix(hdc);
		TextChange(hdc);

		InvalidateRect(hWnd, NULL, false);
		UpdateWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}




