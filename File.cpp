
/**
 * @file File.cpp
 * @author ���ǲ��� & Zhangjie
 * @brief
 * @version 0.1
 * @date 2023-05-15
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "Define.h"
extern struct User *user;
extern int nuser;
extern int login;
extern int *plog;
extern int *npuser;

/// @brief ����Ʒ��Ϣ�ļ�
/// @param fp �ļ�ָ��
/// @param p ��Ʒ��Ϣ�ṹ��ָ��
/// @return ��ȡ������Ʒ��
int Readpro(FILE *fp, struct Product *p)
{
    int num;
    for (num = 0; feof(fp) == 0; num++, p++)
        fscanf(fp, "%d %s %s %f %s %f", &p->num, p->place, p->merchant, &p->distance, p->prod, &p->prize);

    return num;
}

/// @brief ��������Ϣ�ļ�
/// @param fp �ļ�ָ��
/// @param p ������Ϣ�ṹ��
/// @return ��ȡ���ĸ�����Ϣ��
int Readuser(FILE *fp, struct User *p)
{
    int num;
    for (num = 0; feof(fp) == 0; num++, p++)
        fscanf(fp, "%s %s %s %s %f %f", p->username, p->uid, p->password, p->adr, &p->balance, &p->points);
    return num;
}

/// @brief д�ļ�����
/// @param p ������Ϣ�ṹ��
/// @return ����
int Writeuser(struct User *p)
{
    int num;
    FILE *fp = fopen(FILENAME1, "r+");
    if (!(fp == NULL))
    {
        // fprintf(fp, "%s %s %s %s %f %f", user.username, user.uid, user.password, user.adr, user.balance, user.points);
        for (num = 0; num < *npuser - 1; num++, p++)
            fprintf(fp, "%9s %10s %12s %19s %6.2f %.2f\n", p->username, p->uid, p->password, p->adr, p->balance, p->points);
        fprintf(fp, "%9s %10s %12s %19s %6.2f %.2f", p->username, p->uid, p->password, p->adr, p->balance, p->points);
    }
    fclose(fp);
    return num;
}
