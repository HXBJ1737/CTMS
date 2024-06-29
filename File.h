
/**
 * @file File.h
 * @author 恒星不见 & Zhangjie
 * @brief
 * @version 0.1
 * @date 2023-05-15
 *
 * @copyright Copyright (c) 2023
 *
 */
/*
 *文件
 *7
 */

#ifndef __FILE_H__
#define __FILE_H__
// 函数说明请见对应源程序文件（.cpp）
int Readpro(FILE *fp, struct Product *p) ;
int Readuser(FILE *fp,struct User *p);
int Writeuser(struct User *p);

#endif