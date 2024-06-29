
/**
 * @file main.cpp
 * @author ���ǲ��� & Zhangjie
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

int npro = 0; // �Ѷ���Ʒ��
struct User user[N];//������Ϣ
struct Product pro[PRONUM];//��Ʒ��Ϣ
int nuser = 0;//�Ѷ�������Ϣ��


int main()
{
	char Item[PRONUM][PRODUCT_NAME] = {"����", "��ַ", "�̼�����", "����", "��Ʒ", "�۸�"};//��Ʒ�����ַ������� 
	FILE *f1 = fopen(FILENAME2, "r+");//��Ʒ 
	FILE *f0 = fopen(FILENAME1, "r+");//���� 
	if ((f1 == NULL) || (f0 == NULL))
		perror("open file error");
	else
	{
		npro = Readpro(f1, pro); // ��ȡ��Ʒ��Ϣ������Ʒ����ֵ��npro
		fclose(f1);
		nuser = Readuser(f0, user);//��ȡ������Ϣ������Ʒ����ֵ��nuser
		fclose(f0);
	}
	
	Init(); // ����̨��ʼ��
	cas0();//��������Ч
	register_login(user,&nuser);//ע�����¼
	Selectmenu(pro, user, Item, &npro, &nuser); // ����������

	// system("pause");
}
