/*
 *������
 *20
 */
#ifndef __SELECTMENU_H__
#define __SELECTMENU_H__
// ����˵�������ӦԴ�����ļ���.cpp��
void Init();
void register_login(struct User *p,int *npuser);
void Selectmenu(struct Product *pro, struct User *user, char Item[][60], int *nppro, int *npuser);
void casesc();
void cas1(struct Product *pro, struct User *user, char Item[][60], int *nppro, int *npuser);
void cas2(struct Product *pro, struct User *user, char Item[][60], int *nppro, int *npuser);
float *cas3(struct Product *pro, struct User *user, char Item[][60], int *nppro, int *rod, int *npuser);
int *cas11(struct Product *pro, struct User *user, char Item[][60], int *nppro, int *npuser); // cas1����һҳ��
float *cas31(struct Product *pro, struct User *user, char Item[][60], int *nppro, int *npuser); // cas3����һҳ��

void cas0();

#endif