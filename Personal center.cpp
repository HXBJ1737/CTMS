
/**
 * @file Personal center.cpp
 * @author 恒星不见 & Zhangjie
 * @brief
 * @version 0.1
 * @date 2023-05-15
 *
 * @copyright Copyright (c) 2023
 *
 */
/*
 *4.个人中心
 *210+70
 */
#include "Define.h"

/// @brief 个人中心
/// @param pro 商品结构体
/// @param user 个人信息结构体
/// @param Item 商品属性字符串
/// @param nppro 商品数指针
/// @param npuser 个人信息数
/// @param plog 登录的个人信息数组下标
void cas4(struct Product *pro, struct User *user, char Item[][PRODUCT_NAME], int *nppro, int *npuser, int *plog)
{

    char ch;
    while (1)
    {
        system("CLS");
        system("color 7F");
        color(121);
        // per();
        SetPos(0, 2);
        line(0, 60, '=');
        color(112);
        cout << "\t\t    "
             << "用户名:" << user[*plog].username << endl
             << "\t\t    "
             << "UID:" << user[*plog].uid << endl
             << "\t\t    "
             << "地址:" << user[*plog].adr << endl
             << "\t\t    "
             << "余额:" << user[*plog].balance << endl
             << "\t\t    "
             << "积分:" << user[*plog].points << endl;
        // Writeuser(user);
        color(121);
        line(0, 60, '=');
        color(23);
        cout << "充值1        " << endl
             << "个人信息修改2" << endl
             << "商品信息修改3" << endl
             << "彩蛋4        ";

        SetPos(0, 0);
        color(23);
        cout << "返回0";
        SetPos(0, 22);
        color(117);
        printf("            --------------------------------------\n");
        printf("            |您的账号可用积分为：%.2f          |\n", user[*plog].points);
        printf("            |积分                  兑换物品      |\n");
        printf("            |100                   口香糖        |\n");
        printf("            |200                   饮料一瓶      |\n");
        printf("            |400                   冰箱贴纸      |\n");
        printf("            |600                   牙膏一瓶      |\n");
        printf("            |800                   学校周年笔记本|\n");
        printf("            |1000                  校长的抚摸    |\n");
        printf("            |10000                 2-112宿舍任选 |\n");
        printf("            --------------------------------------\n");

        ch = getch();
        if (ch == '0')
            Selectmenu(pro, user, Item, nppro, npuser);
        else if (ch == '1')
            cas41(pro, user, Item, nppro, npuser, plog);
        else if (ch == '2')
            cas42(pro, user, Item, nppro, npuser, plog);
        else if (ch == '3')
            cas43(pro, user, Item, nppro, npuser, plog);
        else if (ch == '4')
            cas45(pro, user, Item, nppro, npuser, plog);
        else
            ctms1();
    }
}

/// @brief 我的->充值页面
/// @param pro 商品信息结构体
/// @param user 个人信息
/// @param Item 商品属性字符串
/// @param nppro 商品数
/// @param npuser 个人信息数
/// @param plog 登录的个人信息数组下标
void cas41(struct Product *pro, struct User *user, char Item[][PRODUCT_NAME], int *nppro, int *npuser, int *plog)
{
    char ch;
    while (1)
    {
        system("CLS");
        system("color 7F");
        color(23);
        SetPos(0, 0);
        cout << "返回0\t\t\t";
        color(30);
        cout << "余额:" << user[*plog].balance << endl;
        color(228); // 228
        cout << "*********************充值20元 请按1*************************" << endl;
        cout << "                                                            " << endl;
        cout << "*********************充值50元 请按2*************************" << endl;
        cout << "                                                            " << endl;
        cout << "*********************充值100元 请按3************************" << endl;
        cout << "                                                            " << endl;
        cout << "*********************充值200元 请按4************************" << endl;
        cout << "                                                            " << endl;
        cout << "*********************充值500元 请按5************************" << endl;
        cout << "                                                            " << endl;
        cout << "****************活动特惠:充值1000元送100元 请按6************" << endl;
        cout << "                                                            " << endl;
        cout << "****************活动特惠:充值2000元送300元 请按7************" << endl;
        cout << "                                                            " << endl;
        cout << "****************活动特惠:充值5000元送1000元 请按8***********" << endl;
        cout << "                                                            " << endl;
        cout << "****************活动特惠:充值10000元送3000元 请按9**********" << endl;
        cout << "                                                            " << endl;
        cout << "**************对程序员的鼓励:打赏100元 请按 # **************" << endl;
        cout << "                                                            " << endl;
        cout << "**************对程序员的鼓励:打赏2000元 请按 $ *************" << endl;
        cout << "                                                            " << endl;
        cout << "**************对程序员的鼓励:打赏10000元 请按 % ************" << endl;
        color(71);
        cout << "                 谨防上当受骗，请适度消费                   " << endl;
        color(191);
        cout << "                                                            " << endl;
        cout << "                                                            " << endl;
        cout << "                                                            " << endl;
        cout << "                                                            " << endl;
        cout << "                                                            " << endl;
        cout << "                                                            " << endl;
        cout << "                                                            " << endl;
        cout << "                   如在充值时出现错误,请打电话,19935589218  " << endl;
        color(206);
        cout << "              感谢康老板，张老板，孟小哥，宋老弟，辛老弟赞助\n";

        ch = getch();
        if (ch == '1')
            user[*plog].balance += 20;
        else if (ch == '2')
            user[*plog].balance += 50;
        else if (ch == '3')
            user[*plog].balance += 100;
        else if (ch == '4')
            user[*plog].balance += 200;
        else if (ch == '5')
            user[*plog].balance += 500;
        else if (ch == '6')
            user[*plog].balance += 1100;
        else if (ch == '7')
            user[*plog].balance += 2300;
        else if (ch == '8')
            user[*plog].balance += 6000;
        else if (ch == '9')
            user[*plog].balance += 13000;
        else if (ch == '#' && user[*plog].balance >= 100) // 限制余额不为负
            user[*plog].balance -= 100;
        else if (ch == '$' && user[*plog].balance >= 2000) // 限制余额不为负
            user[*plog].balance -= 2000;
        else if (ch == '%' && user[*plog].balance >= 10000) // 限制余额不为负
            user[*plog].balance -= 10000;
        else if (ch == '0')
            cas4(pro, user, Item, nppro, npuser, plog);
        Writeuser(user); // 将已更改信息写入文件，防止失效
    }
}
/// @brief 我的->个人信息修改
/// @param pro 商品信息结构体
/// @param user 个人信息
/// @param Item 商品属性字符串
/// @param nppro 商品数
/// @param npuser 个人信息数
/// @param plog 登录的个人信息数组下标
void cas42(struct Product *pro, struct User *user, char Item[][60], int *nppro, int *npuser, int *plog)
{

    char ch;
    char u[60] = "\0";
    while (1)
    {
        system("CLS");
        system("color 7F");
        color(23);
        SetPos(0, 0);
        cout << "返回0\t用户名1\t密码2\t地址3" << endl;
        ch = getch();
        if (ch == '1')
        {
            color(241);
            cout << "请输入新用户名：";
            cin >> u;
            memset(user[*plog].username, '\0', sizeof(user[*plog].username));
            strcpy(user[*plog].username, u);
            memset(u, '\0', sizeof(u));

            Sleep(300);

            Writeuser(user);
            cas4(pro, user, Item, nppro, npuser, plog);
        }
        else if (ch == '2')
        {

            color(241);
            cout << "请输入新密码：";
            cin >> u;
            strcpy(user[*plog].password, u);
            memset(u, '\0', sizeof(u));
            cout << "\n\t\t修改成功";
            Sleep(300);
            Writeuser(user);
            cas4(pro, user, Item, nppro, npuser, plog);
        }
        else if (ch == '3')
        {
            color(241);
            cout << "请输入新地址：";
            cin >> u;
            strcpy(user[*plog].adr, u);
            memset(u, '\0', sizeof(u));
            cout << "\n\t\t修改成功";
            Sleep(300);
            Writeuser(user);
            cas4(pro, user, Item, nppro, npuser, plog);
        }
        if (ch == '0')
        {
            Writeuser(user); // 将已更改信息写入文件，防止失效
            cas4(pro, user, Item, nppro, npuser, plog);
        }
    }
}
/// @brief 我的->商品信息修改（需管理员权限）
/// @param pro 商品信息结构体
/// @param user 个人信息
/// @param Item 商品属性字符串
/// @param nppro 商品数
/// @param npuser 个人信息数
/// @param plog 登录的个人信息数组下标
void cas43(struct Product *pro, struct User *user, char Item[][60], int *nppro, int *npuser, int *plog)
{
    char ch;
    int i;
    char pass[15] = "\0";
    char realpass[15] = "ctms2023";
    int cod;
    while (1)
    {
        system("CLS");
        system("color 7F");
        color(23);
        SetPos(0, 0);
        printf("返回Esc\n");
        SetPos(21, 15);
        color(144);
        printf("您正处于管理员模式\n");
        color(113);
        printf("\t\t\tUID:20230322\n");
        printf("\t\t请输入8位管理员密码:");
    here:
        for (i = 0; i < 8; i++)
        {
            ch = getch();
            if (ch != 13 && ch != 27)
            {
                pass[i] = ch;
                cout << "*";
            }
            else if (ch == 27) // Esc
                cas4(pro, user, Item, nppro, npuser, plog);
            else
                break;
        }
        if (strcmp(pass, realpass) == 0) // 判断输入密码与注册密码是否一致
            goto there;                  // 短暂延时后退出此函数
        else
        {
            memset(pass, '\0', sizeof(pass));
            printf("\n\t\t密码错误,请重新输入:");
            goto here; // 到输入密码处重新输入
        }
    }
there:
    while (1)
    {
        system("CLS");
        system("color 7F");
        color(113);
        printf("您可修改商品价格\n");
        printf("请输入商品代码并回车：");
        scanf("%d", &cod);
        for (i = 0; i < *nppro; i++)
            if (pro[i].num == cod)
                break;
        if (i == *nppro){
            printf("\n\t\tThis item does not exist");
            getch();
            }
        else
        {
            printf("此商品原价为%.1f,\n请输入修改后价格:", pro[i].prize);
            scanf("%f", &pro[i].prize);
            printf("\n\t修改成功，将于1.5s后返回个人中心");
            Sleep(1500);
            cas4(pro, user, Item, nppro, npuser, plog);
        }
    }
}

/// @brief 我的->彩蛋页面
/// @param pro 商品信息
/// @param user 个人信息
/// @param Item 商品属性字符串
/// @param nppro 商品数
/// @param npuser 个人信息数
/// @param plog 登录的个人信息数组下标
void cas45(struct Product *pro, struct User *user, char Item[][PRODUCT_NAME], int *nppro, int *npuser, int *plog)
{
    char ch;
    while (1)
    {
        system("CLS");
        system("color 7F");
        {
            SetSize(80, 35); /// 将控制台的宽设置为原来的2倍以显示菜单
            HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleScreenBufferSize(hOut, {80, 35});
        }
        SetPos(0, 0);
        color(23);
        cout << "返回0" << endl;
        color(127);
        float y, x, z;                            // 定义浮点型变量
        printf("孤独时想起你\n");                   // 提示语句
        printf("落泪时想搂住你\n");               // 提示语句
        printf("开心时想扑向你\n");               // 提示语句
        printf("兴奋时想吻你\n");                 // 提示语句
        printf("一切尽在这三个字签名没有签上\n"); // 提示语句
        printf("\n");                             // 换行
        for (double y = 2.5; y >= -1.6; y = y - 0.2)
        {
            for (double x = -3; x <= 4.8; x = x + 0.1)
            {
                // 下面是个三目运算，读者请仔细看下
                (pow((x * x + y * y - 1), 3) <= 3.6 * x * x * y * y * y || (x > -2.4 && x < -2.1 && y < 1.5 && y > -1) || (((x < 2.5 && x > 2.2) || (x > 3.4 && x < 3.7)) && y > -1 && y < 1.5) || (y > -1 && y < -0.6 && x < 3.7 && x > 2.2)) ? printf("*") : printf(" ");
            }
            printf("\n"); // 换行
        }
        ch = getch();
        if (ch == '0')
        {
            SetSize(63, 35);                                                 // 宽x=63列，高y=35行
            HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);                   // 获取控制台标准io的句柄
            SetConsoleScreenBufferSize(hOut, {63, (short int)(*nppro + 6)}); // 设置控制台缓冲区大小,npro+6可使控制台根据菜单长度动态变化,确保返回上一级界面正常显示
            cas4(pro, user, Item, nppro, npuser, plog);
        }
    }
}