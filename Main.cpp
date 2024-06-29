
/**
 * @file main.cpp
 * @author 恒星不见 & Zhangjie
 * @brief
 * @version 0.1
 * @date 2023-05-15
 *
 * @copyright Copyright (c) 2023
 *
 */
/*
 *CTMS (Canteen Takeaway Management System)
 *34
 */
#include "Define.h"

int npro = 0; // 已读商品数
struct User user[N];//个人信息
struct Product pro[PRONUM];//商品信息
int nuser = 0;//已读个人信息数


int main()
{
	char Item[PRONUM][PRODUCT_NAME] = {"代码", "地址", "商家名称", "距离", "商品", "价格"};//商品属性字符串数组 
	FILE *f1 = fopen(FILENAME2, "r+");//商品 
	FILE *f0 = fopen(FILENAME1, "r+");//个人 
	if ((f1 == NULL) || (f0 == NULL))
		perror("open file error");
	else
	{
		npro = Readpro(f1, pro); // 读取商品信息，将商品数赋值给npro
		fclose(f1);
		nuser = Readuser(f0, user);//读取个人信息，将商品数赋值给nuser
		fclose(f0);
	}
	
	Init(); // 控制台初始化
	cas0();//进度条动效
	register_login(user,&nuser);//注册与登录
	Selectmenu(pro, user, Item, &npro, &nuser); // 进入主界面

	// system("pause");
}
