#pragma once
#include "resource.h"
#define  WINDOW_WIDTH    750
#define  WINDOW_HEIGHT   700
#define  MAX_LOADSTRING  100
extern HINSTANCE hInst;     // 当前实例
extern HWND hWnd;
extern WCHAR szTitle[MAX_LOADSTRING];  // 标题栏文本
extern WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名
extern HDC hdc;
extern int map[10][10];
extern bool Wait ;//地图关卡数
extern int Gamelevel ;//地图关卡数
extern int Gamelevelf ;//地图关卡数副本
extern int base;
extern bool next1;
extern bool text ;
extern bool next2;
extern int iox;
extern int ii;
extern int jj;
extern short;//关卡设置
extern COORD coord ;
extern int map1[10][10],
map2[10][10] ,
map3[10][10] ,
map4[10][10],
map5[10][10],
map6[10][10];

void writeMap(int i);


void nextDrawMapBase();
void DrawMap(HDC hdc);
void DrawBox(HDC hdc, int i, int x, int y);
void nextMap();

void TextFix(HDC hdc);
void TextChange(HDC hdc);

bool Init(HWND hwnd);

void PlayGame(WPARAM wParam);

bool Clean(HWND hwnd);
