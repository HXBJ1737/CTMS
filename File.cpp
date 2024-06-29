
/**
 * @file File.cpp
 * @author 恒星不见 & Zhangjie
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

/// @brief 读商品信息文件
/// @param fp 文件指针
/// @param p 商品信息结构体指针
/// @return 读取到的商品数
int Readpro(FILE *fp, struct Product *p)
{
    int num;
    for (num = 0; feof(fp) == 0; num++, p++)
        fscanf(fp, "%d %s %s %f %s %f", &p->num, p->place, p->merchant, &p->distance, p->prod, &p->prize);

    return num;
}

/// @brief 读个人信息文件
/// @param fp 文件指针
/// @param p 个人信息结构体
/// @return 读取到的个人信息数
int Readuser(FILE *fp, struct User *p)
{
    int num;
    for (num = 0; feof(fp) == 0; num++, p++)
        fscanf(fp, "%s %s %s %s %f %f", p->username, p->uid, p->password, p->adr, &p->balance, &p->points);
    return num;
}

/// @brief 写文件操作
/// @param p 个人信息结构体
/// @return 暂无
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
