/*
 *宏定义及头文件等预编译指令
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
#define N 10            // 个人信息人数
#define PRONUM 100      // 商品数量
#define USERNAME 30     // 用户名字符串长度
#define UID 15          // UID长度
#define PASSWORD 15     // 密码长度
#define PRODUCT_NAME 60 // 商家或商品名称字符串长度
#define ITEMS 6         // 商品属性个数

#define FILENAME1 "./1.txt" // 个人信息
#define FILENAME2 "./2.txt" // 商品信息
#define FILENAME3

struct User
{
    char username[USERNAME]; // 用户名
    char uid[UID];            // uid
    char password[PASSWORD]; // 密码
    char adr[PRODUCT_NAME];  // 地址
    float balance;           // 余额
    float points;            // 积分
};

struct Product
{
    int num;                     // 代码
    char place[PRODUCT_NAME];    // 地点
    char merchant[PRODUCT_NAME]; // 商家
    float distance;              // 距离
    char prod[PRODUCT_NAME];     // 商品名
    float prize;                 // 价格
};

#endif
