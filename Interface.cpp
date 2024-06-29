
/**
 * @file Interface.cpp
 * @author ���ǲ��� & Zhangjie
 * @brief
 * @version 0.1
 * @date 2023-05-15
 *
 * @copyright Copyright (c) 2023
 *
 */
/*
 *�������
 *111
 */
#include "Define.h"

/// @brief ���þֲ���ɫ
/// @param color_index ʮ������ɫֵ
void color(unsigned short color_index)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_index);//���������ɫ
}

/// @brief ���ÿ���̨��С
/// @param uCol ��
/// @param uLine ��
void SetSize(unsigned uCol, unsigned uLine)
{
    char cmd[64];
    sprintf(cmd, "mode con cols=%d lines=%d", uCol, uLine);
    system(cmd);
}

/// @brief ��������̨����
/// @param lpTitle �ַ���
/// @return ��
VOID SetTitle(LPCSTR lpTitle)
{
    SetConsoleTitle(lpTitle);//���ÿ���̨����
}

/// @brief ��ӡ�ַ���
/// @param t "\t"������
/// @param n �ַ�c������
/// @param c �ַ�
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
/// @brief ָ�������������,ԭ��Ϊ����̨���Ͻ�
/// @param x ԭ������Ϊx��
/// @param y ԭ������Ϊy��
/// @return ��
VOID SetPos(short int x, short int y)
{ // set cursor2
    COORD pos = {x,y};
    SetPosC(pos);
}

/// @brief ָ������̨λ�ã�����4����
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

/// @brief ���������
/// @param Visible �Ƿ�
void HideCursor(bool Visible)
{
    CONSOLE_CURSOR_INFO Cursor;
    Cursor.bVisible = !Visible;
    Cursor.dwSize = sizeof(Cursor);
    HANDLE Hand = GetStdHandle(STD_OUTPUT_HANDLE); // STD_OUTPUT_HANDLE=-11��
    SetConsoleCursorInfo(Hand, &Cursor);//���ÿ���̨���״̬
}
/// @brief ��ʾ��ǰ����ʱ��
void _time()
{
    SYSTEMTIME lt;
    while (!kbhit()) //kbhit()Ϊ����û����̺��������û�����1����һ������Ϊ�˷�ֹ������ѭ������ʹ���ܽ�����һ������
    {
        GetLocalTime(&lt);//��ȡ����ʱ�����lt
        SetPos(25, 0);//����һ���������õ�x=25,y=0�����Ӧλ��
        color(189);//����ǰ��������ɫ
        printf("��ǰʱ��: %04d/%02d/%02d-����%01d-%02d:%02d:%02d\n", lt.wYear, lt.wMonth, lt.wDay, lt.wDayOfWeek, lt.wHour, lt.wMinute, lt.wSecond);
        Sleep(1000);//��ʱ1s
    }
}
