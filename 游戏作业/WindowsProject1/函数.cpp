//cpp
#include <windows.h>
#include "stdafx.h"
#include "推箱子 丁辛夷.h"
#define WINDOW_WIDTH    750
#define WINDOW_HEIGHT   700
#define MAX_LOADSTRING  100
#define BOX 50.5
HINSTANCE hInst;     
HWND hWnd;
WCHAR szTitle[MAX_LOADSTRING];  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名
HDC hdc;
bool Wait = true;
short level = 6;
int Gamelevel = 1;
int Gamelevelf = 1;
int base = 1;
bool next1 = true;
bool next2 = true;
bool text = false;
int ii = 0;
int jj = 0;
COORD coord = { 0,0 };
int map[10][10] = {};
int map1[10][10] = { 0 },
map2[10][10] = { 0 },
map3[10][10] = { 0 },
map4[10][10] = { 0 },
map5[10][10] = { 0 },
map6[10][10] = { 0 },
map7[10][10] = { 0 };


void writeMap(int n)
{
	int i = 0, j = 0;
	if (n == 1)
	{
		for (j = 3; j <= 5; j++)
			map1[0][j] = 1;
		map1[1][3] = 1;
		map1[1][5] = 1;
		map1[2][3] = 1;
		for (j = 5; j <= 8; j++)
			map1[2][j] = 1;
		for (j = 1; j <= 3; j++)
			map1[3][j] = 1;
		map1[3][8] = 1;
		map1[4][1] = 1;
		for (j = 6; j <= 8; j++)
			map1[4][j] = 1;
		for (j = 1; j <= 4; j++)
			map1[5][j] = 1;
		map1[5][6] = 1;
		map1[6][6] = 1;
		map1[6][4] = 1;
		for (j = 4; j <= 6; j++)
			map1[7][j] = 1;
		map1[4][5] = 5;
		map1[3][4] = 4;
		map1[3][6] = 4;
		map1[4][4] = 4;
		map1[5][5] = 4;
		map1[1][4] = 3;
		map1[3][7] = 3;
		map1[4][2] = 3;
		map1[6][5] = 3;
	}
	if (n == 2)
	{
		for (i = 0; i <= 4; i++)
			map2[i][0] = 1;
		for (j = 0; j <= 4; j++)
			map2[0][j] = 1;
		for (i = 0; i <= 4; i++)
			map2[i][4] = 1;
		for (i = 4; i <= 8; i++)
			map2[i][1] = 1;
		map2[4][2] = 1;
		map2[5][2] = 1;
		for (j = 1; j <= 5; j++)
			map2[8][j] = 1;
		for (j = 4; j <= 6; j++)
			map2[4][j] = 1;
		for (i = 6; i <= 8; i++)
			map2[i][5] = 1;
		for (i = 2; i <= 4; i++)
			map2[i][6] = 1;
		for (j = 5; j <= 8; j++)
			map2[8][j] = 1;
		map2[6][5] = 1;
		for (i = 2; i <= 7; i++)
			map2[i][8] = 1;
		for (j = 6; j <= 8; j++)
			map2[2][j] = 1;
		for (i = 3; i <= 5; i++)
			map2[i][7] = 3;
		map2[3][2] = 4;
		map2[5][5] = 4;
		map2[2][2] = 4;
		map2[1][1] = 5;
	}
	if (n == 3)
	{
		map3[3][2] = 1;
		for (j = 1; j <= 7; j++)
			map3[0][j] = 1;
		for (i = 0; i <= 3; i++)
			map3[i][1] = 1;
		for (i = 3; i <= 7; i++)
			map3[i][0] = 1;
		for (j = 0; j <= 4; j++)
			map3[7][j] = 1;
		for (i = 4; i <= 7; i++)
			map3[i][4] = 1;
		map3[1][7] = 1;
		for (j = 5; j <= 8; j++)
			map3[2][j] = 1;
		map3[4][6] = 1;
		for (j = 4; j <= 8; j++)
			map3[6][j] = 1;
		for (i = 2; i <= 6; i++)
			map3[i][8] = 1;
		for (j = 4; j <= 6; j++)
			map3[1][j] = 3;
		map3[3][3] = 4;
		map3[4][5] = 4;
		map3[5][2] = 4;
		map3[1][3] = 5;
	}
	if (n == 4)
	{
		for (j = 2; j <= 5; j++)
			map4[0][j] = 1;
		map4[1][2] = 1;
		for (j = 5; j <= 7; j++)
			map4[1][j] = 1;
		map4[2][2] = 1;
		map4[2][7] = 1;
		for (j = 1; j <= 3; j++)
			map4[3][j] = 1;
		map4[3][5] = 1;
		map4[3][7] = 1;
		map4[3][8] = 1;
		map4[4][1] = 1;
		map4[4][3] = 1;
		map4[4][5] = 1;
		map4[4][8] = 1;
		map4[5][1] = 1;
		map4[5][6] = 1;
		map4[5][8] = 1;
		map4[6][1] = 1;
		map4[6][8] = 1;
		for (j = 1; j <= 8; j++)
			map4[7][j] = 1;
		map4[1][3] = 5;
		map4[2][4] = 4;
		map4[5][3] = 4;
		map4[6][6] = 4;
		for (i = 4;i <= 6; i++)
			map4[i][2] = 3;
	}
	if (n == 5)
	{
		for (j = 1; j <= 7; j++)
			map5[1][j] = 1;
		map5[2][1] = 1;
		map5[2][7] = 1;
		map5[2][8] = 1;
		map5[2][9] = 1;
		map5[3][0] = 1;
		map5[3][1] = 1;
		map5[3][3] = 1;
		map5[3][4] = 1;
		map5[3][5] = 1;
		map5[3][9] = 1;
		map5[4][0] = 1;
		map5[4][9] = 1;
		map5[5][0] = 1;
		map5[5][4] = 1;
		map5[5][8] = 1;
		map5[5][9] = 1;
		map5[6][0] = 1;
		map5[6][1] = 1;
		map5[6][4] = 1;
		map5[6][8] = 1;
		for (j = 1; j <= 8; j++)
			map5[7][j] = 1;
		map5[4][2] = 5;
		map5[5][2] = 3;
		map5[5][3] = 3;
		map5[6][2] = 3;
		map5[6][3] = 3;
		map5[3][2] = 4;
		map5[4][4] = 4;
		map5[4][7] = 4;
		map5[5][6] = 4;
	}
	if (n == 6)
	{
		for (j = 0; j <= 6; j++)
			map6[1][j] = 1;
		map6[2][0] = 1;
		map6[2][6] = 1;
		map6[3][0] = 1;
		map6[3][5] = 1;
		map6[3][6] = 1;
		map6[4][0] = 1;
		map6[4][3] = 1;
		map6[4][6] = 1;
		map6[4][7] = 1;
		map6[4][8] = 1;
		map6[5][0] = 1;
		map6[5][1] = 1;
		map6[5][8] = 1;
		map6[6][1] = 1;
		map6[6][8] = 1;
		for (j = 1; j <= 8; j++)
			map6[7][j] = 1;
		for (j = 2; j <= 4; j++)
			map6[3][j] = 4;
		map6[5][6] = 4;
		map6[6][3] = 5;
		map6[4][4] = 3;
		map6[4][5] = 3;
		map6[5][4] = 3;
		map6[5][5] = 3;
	}
}
void nextDrawMapBase()
{
	if (Wait)
	{
		for (int m = 0; m < 10; m++)
		{
			for (int n = 0; n < 10; n++)
			{
				switch (Gamelevel)
				{
				case 1:
					map[m][n] = map1[m][n];
					break;
				case 2:
					map[m][n] = map2[m][n];
					break;
				case 3:
					map[m][n] = map3[m][n];
					break;
				case 4:
					map[m][n] = map4[m][n];
					break;
				case 5:
					map[m][n] = map5[m][n];
					break;
				case 6:
					map[m][n] = map6[m][n];
					break;
				}
			}
		}
		Wait = false;
	}
}

void DrawBox(HDC hdc, int i, int x, int y)
{
	HPEN hPen1 = CreatePen(PS_SOLID, 2, RGB(139 ,69, 19));
	HPEN hPen2 = CreatePen(PS_SOLID, 2, RGB(230,230, 250));
	HPEN hPen3 = CreatePen(PS_SOLID, 2, RGB(255 ,222, 173));
	HPEN hPen4 = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	HPEN hPen5 = CreatePen(PS_SOLID, 2, RGB(139 ,125, 107));
	HBRUSH hbrush1 = CreateSolidBrush(RGB(222, 185, 129));
	HBRUSH hbrush2 = CreateSolidBrush(RGB(217, 105, 68));
	HBRUSH hbrush3 = CreateHatchBrush(HS_DIAGCROSS, RGB(230, 230, 250));
	HBRUSH hbrush4 = CreateSolidBrush(RGB(139,115, 85));
	HBRUSH hbrush5= CreateSolidBrush(RGB(155 ,48 ,255));
	HBRUSH hbrush6 = CreateSolidBrush(RGB(205, 197, 191));
	if (i == 0)
	{
		SelectObject(hdc, hPen2);
		SelectObject(hdc, hbrush3);
		Rectangle(hdc, x, y, x + BOX, y + BOX);
	}
	if (i == 1)
	{
		SelectObject(hdc, hPen5);
		SelectObject(hdc, hbrush1);
		Rectangle(hdc, x, y, x + BOX, y + BOX);
		SelectObject(hdc, hbrush6);
		Rectangle(hdc, x, y, x + BOX, y + BOX);
	}
	if (i == 3)
	{
		SelectObject(hdc, hPen4);
		SelectObject(hdc, hbrush1);
		MoveToEx(hdc, x + BOX/2, y + 8, NULL);
		LineTo(hdc, x + BOX / 2, y + BOX - 8);
		MoveToEx(hdc, x + 8, y + BOX / 2, NULL);
		LineTo(hdc, x + BOX-8, y + BOX / 2);
	}
	if (i == 4)
	{
		SelectObject(hdc, hPen3);
		SelectObject(hdc, hbrush4);
		Rectangle(hdc, x, y, x + BOX, y + BOX);
		MoveToEx(hdc, x, y, NULL);
		LineTo(hdc, x + BOX-1, y + BOX-1);
		MoveToEx(hdc, x + BOX-1, y, NULL);
		LineTo(hdc, x, y + BOX-1);
	}
	if (i == 5)
	{
		SelectObject(hdc, hPen1);
		SelectObject(hdc, hbrush5);
		Ellipse(hdc, x + 10, y + 18, x + 40, y + 48);
		Ellipse(hdc, x + 1.5, y + 10, x + 18.5, y + 27);
		Ellipse(hdc, x + 32, y + 10, x + 49, y + 27);
	}
	if (i == 7)
	{
		SelectObject(hdc, hPen1);
		SelectObject(hdc, hbrush2);
		Rectangle(hdc, x, y, x + BOX, y + BOX);
		MoveToEx(hdc, x, y, NULL);
		LineTo(hdc, x + BOX-1, y + BOX-1);
		MoveToEx(hdc, x + BOX-1, y, NULL);
		LineTo(hdc, x, y + BOX-1);
	}

	DeleteObject(hPen1);
	DeleteObject(hPen2);
	DeleteObject(hPen3);
	DeleteObject(hPen4);
	DeleteObject(hPen5);
	DeleteObject(hbrush1);
	DeleteObject(hbrush2);
	DeleteObject(hbrush3);
	DeleteObject(hbrush4);
	DeleteObject(hbrush5);
	DeleteObject(hbrush6);
}
void DrawMap(HDC hdc)
{
	for (int i = 0; i < 10; i++)
	{
		coord.X = 0;
		coord.Y = i * BOX;
		MoveToEx(hdc, coord.X, coord.Y, NULL);
		for (int j = 0; j < 10; j++)
		{
			switch (map[i][j])
			{
			case 0:
				MoveToEx(hdc, coord.X + j * BOX, coord.Y, NULL);
				DrawBox(hdc, 0, coord.X + j * BOX, coord.Y);
				break;
			case 1:
				MoveToEx(hdc, coord.X + j * BOX, coord.Y, NULL);
				DrawBox(hdc, 1, coord.X + j * BOX, coord.Y);
				break;
			case 3:
				MoveToEx(hdc, coord.X + j * BOX, coord.Y, NULL);
				DrawBox(hdc, 0, coord.X + j * BOX, coord.Y);
				DrawBox(hdc, 3, coord.X + j * BOX, coord.Y);
				break;
			case 4:
				MoveToEx(hdc, coord.X + j * BOX, coord.Y, NULL);
				DrawBox(hdc, 4, coord.X + j * BOX, coord.Y);
				break;
			case 5:
				MoveToEx(hdc, coord.X + j * BOX, coord.Y, NULL);
				DrawBox(hdc, 0, coord.X + j * BOX, coord.Y);
				DrawBox(hdc, 5, coord.X + j * BOX, coord.Y);
				break;
			case 7:
				MoveToEx(hdc, coord.X + j * BOX, coord.Y, NULL);
				DrawBox(hdc, 0, coord.X + j * BOX, coord.Y);
				DrawBox(hdc, 7, coord.X + j * BOX, coord.Y);
				break;
			case 8:
				MoveToEx(hdc, coord.X + j * BOX, coord.Y, NULL);
				DrawBox(hdc, 0, coord.X + j * BOX, coord.Y);
				DrawBox(hdc, 5, coord.X + j * BOX, coord.Y);
				break;
			}
		}
	}
}

void nextMap()
{
	if (next1)
	{
		for (int m = 0; m < 10; m++)
		{
			for (int n = 0; n < 10; n++)
			{
				if (map[m][n] == 3 || map[m][n] == 7)
				{
					ii++;
				}
			}
		}
		next1 = false;
	}
	if (next2)
	{
		jj = 0;
		for (int i = 0; i < 10; i++)
		{

			for (int j = 0; j < 10; j++)
			{
				if (map[i][j] == 7)
				{
					jj++;
				}
			}
		}
	}
	if (jj == ii)
	{
		if (Gamelevel <= 6)
			Gamelevel++;
		Gamelevelf = Gamelevel;
		Wait = true;
		next1 = true;
		next2 = true;
		ii = 0;
		text = true;
		Sleep(2000);
	}

}

void TextFix(HDC hdc)
{
	HFONT hFont1 = CreateFont(25, 0, 0, 700, 0, 0, 0, 0, DEFAULT_CHARSET,
		OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS, DEFAULT_QUALITY, FF_DONTCARE, TEXT("微软雅黑"));
	SelectObject(hdc, hFont1);
	SetBkMode(hdc, TRANSPARENT);    
	//WCHAR c1[]=L"游戏进程：轻轻一推，开启推箱子之旅！";
	WCHAR c2[] = L"游戏说明：所有箱子推至“十”。共有六关，难度递增。快开始游戏吧！！";
	WCHAR c3[] = L"游戏操作：按键↑↓→←移动箱子。";
	WCHAR hehe[] = L"点这俩按钮后游戏默认暂停";
	WCHAR haha[] = L"之后按回车键恢复游戏";
	//WCHAR c7[]=L"关卡：第一关";

	SetTextColor(hdc, RGB(67,110 ,238));
	//TextOut(hdc,4+12,476+4,c1,wcslen(c1));
	TextOut(hdc, 4 + 12, 476 + 45, c2, wcslen(c2));
	TextOut(hdc, 4 + 12, 476 + 72, c3, wcslen(c3));
	SetTextColor(hdc, RGB(255, 0, 0));
	TextOut(hdc, 508, 24 + 301, hehe, wcslen(hehe));
	TextOut(hdc, 508 , 24 + 325, haha, wcslen(haha));
	//TextOut(hdc,520+10,24+30,c4,wcslen(c4));
	DeleteObject(hFont1);

	HFONT hFont = CreateFont(32/*高*/, 0/*宽*/, 0, 0, 700 /*700表示粗体*/,
		FALSE/*斜体?*/, FALSE/*下划线?*/, FALSE/*删除线?*/, DEFAULT_CHARSET,
		OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS, DEFAULT_QUALITY,
		FF_DONTCARE, TEXT("微软雅黑")
	);
	SelectObject(hdc, hFont);
	SetBkMode(hdc, TRANSPARENT);  
	WCHAR ce[] = L" ◣◣◣推箱子♦小游戏◢◢◢                [作者:17信安丁辛夷]";
	SetTextColor(hdc, RGB(0,0 , 0));
	TextOut(hdc, 150, 0, ce, wcslen(ce));
	DeleteObject(hFont);
}
void TextChange(HDC hdc)
{
	HPEN hPen1 = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	HFONT hFont1 = CreateFont(28,0, 0, 0, 700, 0, 0, 0, GB2312_CHARSET, 0, 0, 0, 0, L"微软雅黑");
	HBRUSH hbrush2 = CreateSolidBrush(RGB(154, 205, 141));
	HBRUSH hbrush1 = CreateSolidBrush(RGB(255, 250, 205));

	SetBkMode(hdc, TRANSPARENT); 
	WCHAR d11[] = L"▶▷▶▷▶▷▶▷▶▷游戏进程：轻轻一推，开启推箱子之旅！◁◀◁◀◁◀◁◀◁◀";
	WCHAR d14[] = L"关卡：第一关";
	WCHAR d15[] = L"【还有五关】";
	WCHAR d21[] = L"▶▷▶▷▶▷▶▷▶▷游戏进程：已经入门，继续努力！◁◀◁◀◁◀◁◀◁◀";
	WCHAR d24[] = L"关卡：第二关";
	WCHAR d25[] = L"【还有四关】";
	WCHAR d31[] = L"▶▷▶▷▶▷▶▷▶▷游戏进程：动动脑，是不是轻而易举？◁◀◁◀◁◀◁◀◁◀";
	WCHAR d34[] = L"关卡：第三关";
	WCHAR d35[] = L"【还有三关】";
	WCHAR d41[] = L"▶▷▶▷▶▷▶游戏进程：过了这关，是迈向成功的一大步！◀◁◀◁◀◁◀";
	WCHAR d44[] = L"关卡：第四关";
	WCHAR d45[] = L"【还有二关】";
	WCHAR d51[] = L"▶▷▶▷▶▷游戏进程：行百里者半九十！加油！我看好你哦！◁◀◁◀◁◀";
	WCHAR d54[] = L"关卡：第五关";
	WCHAR d55[] = L"【还有一关】";
	WCHAR d61[] = L"▶▷▶▷▶游戏进程：马上就要出师了！不忘初心，方得始终！◀◁◀◁◀";
	WCHAR d64[] = L"关卡：第六关";
	WCHAR d65[] = L"【游戏结束！】";

	if (text)
	{
		switch (Gamelevel)
		{
		case 1:
			SelectObject(hdc, hPen1);
			SelectObject(hdc, hbrush1);
			RoundRect(hdc, 0, 476 + 10, 750, 476 + 38 ,25,25);
			SelectObject(hdc, hPen1);
			SelectObject(hdc, WHITE_BRUSH);
		    RoundRect(hdc, 520 + 10, 24 + 46, 750, 24 + 51 +73,25,25);
			SelectObject(hdc, hFont1);
			SetTextColor(hdc, RGB(203, 136, 82));
			SetBkMode(hdc, TRANSPARENT);
			TextOut(hdc, 4 + 12, 476 + 8, d11, wcslen(d11));
			SetTextColor(hdc, RGB(255,0, 0));
			TextOut(hdc, 520 + 40, 24 + 51, d14, wcslen(d14));
			TextOut(hdc, 520 + 40, 24 + 90, d15, wcslen(d15));
			break;
		case 2:
			SelectObject(hdc, hPen1);
			SelectObject(hdc, hbrush1);
			RoundRect(hdc, 0, 476 + 10, 750, 476 + 38, 25, 25);
			SelectObject(hdc, WHITE_BRUSH);
			RoundRect(hdc, 520 + 10, 24 + 46, 750, 24 + 51 + 73, 25, 25);
			SelectObject(hdc, hFont1);
			SetTextColor(hdc, RGB(203, 136, 82));
			SetBkMode(hdc, TRANSPARENT);
			TextOut(hdc, 4 + 12, 476 + 8, d21, wcslen(d21));
			SetTextColor(hdc, RGB(255, 0, 0));
			TextOut(hdc, 520 + 40, 24 + 51, d24, wcslen(d24));
			TextOut(hdc, 520 + 40, 24 + 90, d25, wcslen(d25));
			break;
		case 3:
			SelectObject(hdc, hPen1);
			SelectObject(hdc, hbrush1);
			RoundRect(hdc, 0, 476 + 10, 750, 476 + 38, 25, 25);
			SelectObject(hdc, WHITE_BRUSH);
			RoundRect(hdc, 520 + 10, 24 + 46, 750, 24 + 51 + 73, 25, 25);
			SelectObject(hdc, hFont1);
			SetTextColor(hdc, RGB(203, 136, 82));
			SetBkMode(hdc, TRANSPARENT);
			TextOut(hdc, 4 + 12, 476 + 8, d31, wcslen(d31));
			SetTextColor(hdc, RGB(255, 0, 0));
			TextOut(hdc, 520 + 40, 24 + 51, d34, wcslen(d34));
			TextOut(hdc, 520 + 40, 24 + 90, d35, wcslen(d35));
			break;
		case 4:
			SelectObject(hdc, hPen1);
			SelectObject(hdc, hbrush1);
			RoundRect(hdc, 0, 476 + 10, 750, 476 + 38, 25, 25);
			SelectObject(hdc, WHITE_BRUSH);
			RoundRect(hdc, 520 + 10, 24 + 46, 750, 24 + 51 + 73, 25, 25);
			SelectObject(hdc, hFont1);
			SetTextColor(hdc, RGB(203, 136, 82));
			SetBkMode(hdc, TRANSPARENT);
			TextOut(hdc, 4 + 12, 476 +8, d41, wcslen(d41));
			SetTextColor(hdc, RGB(255, 0, 0));
			TextOut(hdc, 520 + 40, 24 + 51, d44, wcslen(d44));
			TextOut(hdc, 520 + 40, 24 + 90, d45, wcslen(d45));
			break;
		case 5:
			SelectObject(hdc, hPen1);
			SelectObject(hdc, hbrush1);
			RoundRect(hdc, 0, 476 + 10, 750, 476 + 38, 25, 25);
			SelectObject(hdc, WHITE_BRUSH);
			RoundRect(hdc, 520 + 10, 24 + 46, 750, 24 + 51 + 73, 25, 25);
			SelectObject(hdc, hFont1);
			SetTextColor(hdc, RGB(203, 136, 82));
			SetBkMode(hdc, TRANSPARENT);
			TextOut(hdc, 4 + 12, 476 + 8, d51, wcslen(d51));
			SetTextColor(hdc, RGB(255, 0, 0));
			TextOut(hdc, 520 + 40, 24 + 51, d54, wcslen(d54));
			TextOut(hdc, 520 + 40, 24 + 90, d55, wcslen(d55));
			break;
		case 6:
			SelectObject(hdc, hPen1);
			SelectObject(hdc, hbrush1);
			RoundRect(hdc, 0, 476 + 10, 750, 476 + 38, 25, 25);
			SelectObject(hdc, WHITE_BRUSH);
			RoundRect(hdc, 520 + 10, 24 + 46, 750, 24 + 51 + 73, 25, 25);
			SelectObject(hdc, hFont1);
			SetTextColor(hdc, RGB(203, 136, 82));
			SetBkMode(hdc, TRANSPARENT);
			TextOut(hdc, 4 + 12, 476 +8, d61, wcslen(d61));
			SetTextColor(hdc, RGB(255, 0, 0));
			TextOut(hdc, 520 + 40, 24 + 51, d64, wcslen(d64));
			TextOut(hdc, 520 + 40, 24 + 90, d65, wcslen(d65));
			break;
		}
		DeleteObject(hPen1);
		DeleteObject(hFont1);
		DeleteObject(hbrush1);
		DeleteObject(hbrush2);
		text = false;
	}
}

bool Clean(HWND hwnd)
{
	ReleaseDC(hwnd, hdc);
	DeleteDC(hdc);
	return TRUE;
}
bool Init(HWND hwnd)
{
	hdc = GetDC(hwnd);
	TextFix(hdc);
	TextChange(hdc);
	Clean(hwnd);
	return true;
}

void PlayGame(WPARAM wParam)
{
	int pRow, pCol;//人的行和列
	int i, j;
	int wmId;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (map[i][j] == 5 || map[i][j] == 8)
			{
				pRow = i;
				pCol = j;
				break;
			}
		}
		if (map[i][j] == 5 || map[i][j] == 8)
			break;
	}

	switch (wParam)
	{
	case VK_UP:
		if (map[pRow - 1][pCol] == 0 || map[pRow - 1][pCol] == 3)
		{
			map[pRow - 1][pCol] += 5;
			map[pRow][pCol] -= 5;
		}
		else if (map[pRow - 1][pCol] == 4 || map[pRow - 1][pCol] == 7)//人的前面是箱子
		{
			if (map[pRow - 2][pCol] == 0 || map[pRow - 2][pCol] == 3)//判断箱子的前面为空或目标
			{
				map[pRow - 2][pCol] += 4;
				map[pRow - 1][pCol] += 1;
				map[pRow][pCol] -= 5;
			}
		}
		break;
	case VK_DOWN:
		if (map[pRow + 1][pCol] == 0 || map[pRow + 1][pCol] == 3)
		{
			map[pRow + 1][pCol] += 5;
			map[pRow][pCol] -= 5;
		}
		else if (map[pRow + 1][pCol] == 4 || map[pRow + 1][pCol] == 7)
		{
			if (map[pRow + 2][pCol] == 0 || map[pRow + 2][pCol] == 3)
			{
				map[pRow + 2][pCol] += 4;
				map[pRow + 1][pCol] += 1;
				map[pRow][pCol] -= 5;
			}
		}
		break;
	case VK_LEFT:
		if (map[pRow][pCol - 1] == 0 || map[pRow][pCol - 1] == 3)
		{
			map[pRow][pCol - 1] += 5;
			map[pRow][pCol] -= 5;
		}
		else if (map[pRow][pCol - 1] == 4 || map[pRow][pCol - 1] == 7)
		{
			if (map[pRow][pCol - 2] == 0 || map[pRow][pCol - 2] == 3)
			{
				map[pRow][pCol - 2] += 4;
				map[pRow][pCol - 1] += 1;
				map[pRow][pCol] -= 5;
			}
		}
		break;
	case VK_RIGHT:
		if (map[pRow][pCol + 1] == 0 || map[pRow][pCol + 1] == 3)
		{
			map[pRow][pCol + 1] += 5;
			map[pRow][pCol] -= 5;
		}
		else if (map[pRow][pCol + 1] == 4 || map[pRow][pCol + 1] == 7)
		{
			if (map[pRow][pCol + 2] == 0 || map[pRow][pCol + 2] == 3)
			{
				map[pRow][pCol + 2] += 4;
				map[pRow][pCol + 1] += 1;
				map[pRow][pCol] -= 5;
			}
		}
		break;
	case 'P':
		Gamelevel = Gamelevelf;
		Wait = true;
		next1 = true;
		ii = 0;
		break;
	case 'N':
		next2 = false;
		jj = ii;
		break;
	default:
		break;
	}
	return;
}



