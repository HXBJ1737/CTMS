/*
 *�궨�弰ͷ�ļ���Ԥ����ָ��
 *56
 */
#ifndef __DEFINE_H__
#define __DEFINE_H__

#include <iostream>
#include <fstream>
using namespace std;
#include <cmath>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <iomanip>
#include "Personal center.h"
#include "Search.h"
#include "SelectMenu.h"
#include "Interface.h"
#include "File.h"
#include "Dot matrix.h"
//
#define N 10            // ������Ϣ����
#define PRONUM 100      // ��Ʒ����
#define USERNAME 30     // �û����ַ�������
#define UID 15          // UID����
#define PASSWORD 15     // ���볤��
#define PRODUCT_NAME 60 // �̼һ���Ʒ�����ַ�������
#define ITEMS 6         // ��Ʒ���Ը���

#define FILENAME1 "./1.txt" // ������Ϣ
#define FILENAME2 "./2.txt" // ��Ʒ��Ϣ
#define FILENAME3

struct User
{
    char username[USERNAME]; // �û���
    char uid[UID];            // uid
    char password[PASSWORD]; // ����
    char adr[PRODUCT_NAME];  // ��ַ
    float balance;           // ���
    float points;            // ����
};

struct Product
{
    int num;                     // ����
    char place[PRODUCT_NAME];    // �ص�
    char merchant[PRODUCT_NAME]; // �̼�
    float distance;              // ����
    char prod[PRODUCT_NAME];     // ��Ʒ��
    float prize;                 // �۸�
};

#endif
