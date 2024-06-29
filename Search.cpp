/**
 * @file Search.cpp
 * @author 恒星不见 & Zhangjie
 * @brief
 * @version 0.1
 * @date 2023-05-15
 *
 * @copyright Copyright (c) 2023
 *
 */
/*
 *2.分类
 *130
 */
#include "Define.h"

/// @brief 分类
/// @param s 商品结构体
/// @param Item 商品属性字符串
/// @param lk 选项
/// @param nppro 商品数
/// @return 暂无
void fenlei(struct Product *s, char Item[][60], char lk, int *nppro)
{
    int i;
    struct Product x[*nppro];
    struct Product l[*nppro];
    struct Product q;
    for (i = 0; i < 60; i++)
    {
        x[i] = s[i];
    }
    if (lk == '1') /*紫荆苑食谱*/
    {
        for (i = 0; i < 60; i++)
        {
            if (s[i].num <= 2220)
                printf("%9s %14s %9.1fkm %12s %6.1f元\n", s[i].place, s[i].merchant, s[i].distance, s[i].prod, s[i].prize);
        }
    }
    else if (lk == '2') /*玉兰苑食谱*/
    {
        for (i = 0; i < 60; i++)
        {
            if (s[i].num <= 2240 && s[i].num > 2220)
                printf("%9s %14s %9.1fkm %12s %6.1f元\n", s[i].place, s[i].merchant, s[i].distance, s[i].prod, s[i].prize);
        }
    }
    else if (lk == '3') /*民族食食谱*/
    {
        for (i = 0; i < 60; i++)
        {
            if (s[i].num <= 2260 && s[i].num > 2240)
                printf("%9s %14s %9.1fkm %12s %6.1f元\n", s[i].place, s[i].merchant, s[i].distance, s[i].prod, s[i].prize);
        }
    }
    else if (lk == '4') /*主食*/
    {
        for (i = 0; i < 60; i++)
        {
            if (s[i].num <= 2220 || (s[i].num <= 2260 && s[i].num > 2240))
                printf("%9s %14s %9.1fkm %12s %6.1f元\n", s[i].place, s[i].merchant, s[i].distance, s[i].prod, s[i].prize);
        }
    }
    else if (lk == '5') /*饮品*/
    {
        for (i = 0; i < 60; i++)
        {
            if (s[i].num <= 2240 && s[i].num > 2220)
                printf("%9s %14s %9.1fkm %12s %6.1f元\n", s[i].place, s[i].merchant, s[i].distance, s[i].prod, s[i].prize);
        }
    }
    else if (lk == '6') /*距离从远到近*/
    { 
        for (i = 0; i <*nppro-1; i++)
        {
            for (int j = i+1; j < *nppro; j++)
            {
                if (x[i].distance < x[j].distance)
                {
                     q= x[i];
                    x[i] = x[j];
                    x[j] = q;
                }
            }
        }
        for (i = 0; i < 60; i++)
            printf("%9s %14s %9.1fkm %12s %6.1f元\n", x[i].place, x[i].merchant, x[i].distance, x[i].prod, x[i].prize);
    }
    else if (lk == '7') /*距离从近到远*/
    {
        for (i = 0; i < 60; i++)
        {
            for (int j = 0; j < 59; j++)
            {
                if (x[j].distance > x[j + 1].distance)
                {
                    l[j] = x[j];
                    x[j] = x[j + 1];
                    x[j + 1] = l[j];
                }
            }
        }
        for (i = 0; i < 60; i++)
            printf("%9s %14s %9.1fkm %12s %6.1f元\n", x[i].place, x[i].merchant, x[i].distance, x[i].prod, x[i].prize);
    }
    else if (lk == '8') /*价格从高到低*/
    {
        for (i = 0; i < 60; i++)
        {
            for (int j = 0; j < 59; j++)
            {
                if (x[j].prize < x[j + 1].prize)
                {
                    l[j] = x[j];
                    x[j] = x[j + 1];
                    x[j + 1] = l[j];
                }
            }
        }
        for (i = 0; i < 60; i++)
            printf("%9s %14s %9.1fkm %12s %6.1f元\n", x[i].place, x[i].merchant, x[i].distance, x[i].prod, x[i].prize);
    }
    else if (lk == '9') /*价格从低到高*/
    {
        for (i = 0; i < 60; i++)
        {
            for (int j = 0; j < 59; j++)
            {
                if (x[j].prize > x[j + 1].prize)
                {
                    l[j] = x[j];
                    x[j] = x[j + 1];
                    x[j + 1] = l[j];
                }
            }
        }
        for (i = 0; i < 60; i++)
            printf("%9s %14s %9.1fkm %12s %6.1f元\n", x[i].place, x[i].merchant, x[i].distance, x[i].prod, x[i].prize);
    }
}