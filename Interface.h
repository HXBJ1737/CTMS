
/**
 * @file Interface.H
 * @author 恒星不见 & Zhangjie
 * @brief
 * @version 0.1
 * @date 2023-05-15
 *
 * @copyright Copyright (c) 2023
 *
 */
/*
 *界面
 *24
 */
#ifndef __INTERFACE_H__
#define __INTERFACE_H__

//函数具体说明请见源文件
void line(int t,int n, char c);
void color(unsigned short color_index);
void SetSize(unsigned uCol, unsigned uLine);
VOID SetTitle(LPCSTR lpTitle);

VOID SetPosC(COORD a);
VOID SetPos(short int x, short int y);

RECT GetWindowRect2(HWND hwnd);
LONG GetWindowWidth(HWND hwnd);
LONG GetWindowHeight(HWND hwnd);
WINBOOL MoveWindow2(HWND hwnd,int X, int Y,BOOL bRepaint);

void HideCursor(bool Visible);
void _time();

#endif