
/**
 * @file File.h
 * @author ���ǲ��� & Zhangjie
 * @brief
 * @version 0.1
 * @date 2023-05-15
 *
 * @copyright Copyright (c) 2023
 *
 */
/*
 *�ļ�
 *7
 */

#ifndef __FILE_H__
#define __FILE_H__
// ����˵�������ӦԴ�����ļ���.cpp��
int Readpro(FILE *fp, struct Product *p) ;
int Readuser(FILE *fp,struct User *p);
int Writeuser(struct User *p);

#endif