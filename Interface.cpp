
/**
 * @file Interface.cpp
 * @author 恒星不见 & Zhangjie
 * @brief
 * @version 0.1
 * @date 2023-05-15
 *
 * @copyright Copyright (c) 2023
 *
 */
/*
 *界面相关
 *111
 */
#include "Define.h"

/// @brief 设置局部颜色
/// @param color_index 十进制颜色值
void color(unsigned short color_index)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_index);//设置输出颜色
}

/// @brief 设置控制台大小
/// @param uCol 长
/// @param uLine 宽
void SetSize(unsigned uCol, unsigned uLine)
{
    char cmd[64];
    sprintf(cmd, "mode con cols=%d lines=%d", uCol, uLine);
    system(cmd);
}

/// @brief 更换控制台标题
/// @param lpTitle 字符串
/// @return 无
VOID SetTitle(LPCSTR lpTitle)
{
    SetConsoleTitle(lpTitle);//设置控制台标题
}

/// @brief 打印字符串
/// @param t "\t"的数量
/// @param n 字符c的数量
/// @param c 字符
void line(int t,int n,char c)
{
    int i;
    for(i=0;i<t;i++)
        cout<<'\t';
    for(i=0;i<n;i++)
        cout<<c;
    cout<<endl;
}

VOID SetPosC(COORD a)
{ // set cursor
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleCursorPosition(out, a);
}
/// @brief 指定文字输出坐标,原点为控制台左上角
/// @param x 原点以右为x轴
/// @param y 原点以下为y轴
/// @return 无
VOID SetPos(short int x, short int y)
{ // set cursor2
    COORD pos = {x,y};
    SetPosC(pos);
}

/// @brief 指定控制台位置（以下4个）
RECT GetWindowRect2(HWND hwnd)
{ 
    RECT rt;
    GetWindowRect(hwnd, &rt);
    return rt;
}

LONG GetWindowWidth(HWND hwnd)
{
    RECT rect = GetWindowRect2(hwnd);
    return (rect.right - rect.left);
}
LONG GetWindowHeight(HWND hwnd)
{
    RECT rect = GetWindowRect2(hwnd);
    return (rect.bottom - rect.top);
}
WINBOOL MoveWindow2(HWND hwnd,int X, int Y,BOOL bRepaint) 
{
    LONG w, h;
    w = GetWindowWidth(hwnd);
    h = GetWindowHeight(hwnd);
    MoveWindow(hwnd, X, Y, w, h, bRepaint);
    return TRUE;
}

/// @brief 隐藏鼠标光标
/// @param Visible 是否
void HideCursor(bool Visible)
{
    CONSOLE_CURSOR_INFO Cursor;
    Cursor.bVisible = !Visible;
    Cursor.dwSize = sizeof(Cursor);
    HANDLE Hand = GetStdHandle(STD_OUTPUT_HANDLE); // STD_OUTPUT_HANDLE=-11；
    SetConsoleCursorInfo(Hand, &Cursor);//设置控制台光标状态
}
/// @brief 显示当前北京时间
void _time()
{
    SYSTEMTIME lt;
    while (!kbhit()) //kbhit()为检测敲击键盘函数，若敲击返回1，这一步操作为了防止产生死循环，致使不能进入下一步操作
    {
        GetLocalTime(&lt);//获取当地时间存入lt
        SetPos(25, 0);//将下一步输入设置到x=25,y=0坐标对应位置
        color(189);//更新前景背景颜色
        printf("当前时间: %04d/%02d/%02d-星期%01d-%02d:%02d:%02d\n", lt.wYear, lt.wMonth, lt.wDay, lt.wDayOfWeek, lt.wHour, lt.wMinute, lt.wSecond);
        Sleep(1000);//延时1s
    }
}
