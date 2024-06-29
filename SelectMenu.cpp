/**
 * @file SelectMenu.cpp
 * @author 恒星不见 & Zhangjie
 * @brief
 * @version 0.1
 * @date 2023-05-15
 *
 * @copyright Copyright (c) 2023
 *
 */
/*
 *主界面
 *710
 */
#include "Define.h"

extern int npro;
extern int nuser;
int login;
int *plog = &login;
int co = 0; //
int *pco = &co;
int *nppro = &npro;
int *npuser = &nuser;
float pr = 0;
float *pr0 = &pr;      // 已选商品总价
int rod[PRONUM] = {0}; // 定义为局部变量存在潜在风险，故在函数外定义

/// @brief 控制台初始化
void Init()
{
    SetTitle("CTMS (食堂外卖管理系统)");						   //设置标题 
    MoveWindow2(GetConsoleWindow(), 200, 40, TRUE);                // 把控制台拖到(300,40) 重绘窗口
    HideCursor(1);                                                 // 隐藏光标
    SetSize(63, 35);                                               // 设置控制台宽x=63列，高y=35行
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);                 // 获取控制台标准io的句柄
    SetConsoleScreenBufferSize(hOut, {63, (short int)(npro + 6)}); // 设置控制台缓冲区大小,npro+5可使控制台根据菜单长度动态变化
    system("color F7");                                            // 初始化控制台前景背景颜色
}
/// @brief 2.0新增，注册与登录，可自动检测已注册账号
/// @param p 个人信息
/// @param npuser 个人数
void register_login(struct User *p, int *npuser)
{

    char ch, _login[1] = {'0'};
    int i, j, _login1;
    int randuid;
    char pass[PASSWORD] = "\0"; // 暂存登录密码
    char reg1[PASSWORD] = "\0"; // 暂存注册密码
    char reg2[PASSWORD] = "\0"; // 暂存注册密码（第二次输入）
    SYSTEMTIME t0;
    GetLocalTime(&t0); // 获取当地时间，以生成伪随机数 
here:                  /// 注册后返回此处，进行登录。
    FILE *fp = fopen(FILENAME1, "r+");
    *npuser = Readuser(fp, p);
    fclose(fp);

    while (1)
    {
        system("CLS");
        system("color 7F");
        color(23);
        cout << "注册0\t"
             << "免密登录1\t"
             << "登录2—n(n<10)" << endl;
        color(113);
        cout << "检测到以下已注册账号:" << endl;
        line(2, 20, '-');
        cout << "\t\t    "
             << "序号:1" << endl
             << "\t\t    "
             << "用户名:" << p->username << endl
             << "\t\t    "
             << "UID:" << p->uid << endl
             << "\t\t(公共账号，免密登录)" << endl; // 先输出免密登录的公共账号
        line(2, 20, '-');
        for (i = 1; i < *npuser; i++)
        {
            cout << "\t\t    "
                 << "序号:" << i + 1 << endl
                 << "\t\t    "
                 << "用户名:" << (p + i)->username << endl
                 << "\t\t    "
                 << "UID:" << (p + i)->uid << endl;
            line(2, 20, '-');
        }
        cout << endl
             << "您可输入对应序号登录或按0注册";
    here3:
        _login[0] = getch();
        if (_login[0] > 47 && _login[0] < 58) // 48对应'0',57对应'9'
            _login1 = atoi(_login);           /// atoi()函数将数字字符串转成数字<-stdlib.h 
        else
            goto here3;                        // 否则程序从here3处重新执行
        if (_login1 > 0 && _login1 <= *npuser) // 判断是否进入登录
        {
            *plog = _login1 - 1; // 将登录序号-1得到已登录个人信息数组下标
            if (*plog == 0)      // 若为公共账号，免密登录
                break;
            else
            {
                while (1)//登录 
                {

                    system("CLS");
                    system("color 7F");
                    color(23);
                    cout << "返回Esc\t";
                    color(113);
                    cout << "按回车键结束密码输入";
                    SetPos(12, 10);
                    cout << "    用户名:" << p[*plog].username << endl;
                    cout << "\t\t请输入密码:";
                here1:
                    for (i = 0;; i++)
                    {
                        ch = getch();
                        if (ch != 13 && ch != 27)
                        {
                            pass[i] = ch;
                            cout << "*";
                        }
                        else if (ch == 27)
                            goto here;
                        else
                            break;
                    }
                    if (strcmp(pass, p[*plog].password) == 0) // 判断输入密码与注册密码是否一致
                        goto there;                           // 短暂延时后退出此函数
                    else
                    {
                        memset(pass, '\0', sizeof(pass));
                        cout << "\n\t\t密码错误,请重新输入:";
                        goto here1; // 到输入密码处重新输入
                    }
                }
            }
        }
        /// 判断注册信号
        else if (_login1 == 0)
        {
            while (1)
            {
                system("CLS");
                system("color 7F");
                color(241);
                cout << "按回车键结束密码输入";
                color(113);

                SetPos(12, 10);
                HideCursor(0); // 显示鼠标光标
                cout << "\t\t注册" << endl;
                cout << "\t\t请输入一个用户名(如:XXXX):";
                cin >> p[*npuser].username;
                cout << endl
                     << "\t\t请输入密码:";
                for (i = 0;; i++)
                {
                    ch = getch();
                    if (ch != 13)
                    {
                        reg1[i] = ch;
                        cout << "*";
                    }
                    else
                        break;
                }
            here2:
                cout << endl
                     << "\t\t请再次输入密码：";
                for (i = 0;; i++)
                {
                    ch = getch();
                    if (ch != 13)
                    {
                        reg2[i] = ch;
                        cout << "*";
                    }
                    else
                        break;
                }
                if (strcmp(reg1, reg2) == 0)
                    strcpy(p[*npuser].password, reg2);
                else
                {
                    cout << "\n\t\t密码不一致";
                    goto here2;
                }
                cout << endl
                     << "\t\t请输入收货地址:";
                cin >> p[*npuser].adr;
                p[*npuser].balance = 100;
                p[*npuser].points = 100;
            rerand:
                randuid = t0.wMinute * t0.wSecond + 210000000 + rand() % (999990000 - 210000000); // 生成9位随机UID
                /// 下面这一步防止UID重复
                for (j = 0; j < *npuser; j++)
                    if (randuid == atoi(p[j].uid))
                        goto rerand;

                itoa(randuid, p[*npuser].uid, 10); /// itoa()函数，将数字转为数字字符串（进制为10进制）
                FILE *f2 = fopen(FILENAME1, "a+"); // 以追加写入方式打开此文件
                /// 写入本次注册信息
                fprintf(f2, "\n%s %s %s %s %.2f %.2f", p[*npuser].username, p[*npuser].uid, p[*npuser].password, p[*npuser].adr, p[*npuser].balance, p[*npuser].points);
                fclose(f2);
                HideCursor(1); // 隐藏鼠标光标

                cout << "\t注册成功,您的UID为" << p[*npuser].uid << ",3s后返回登录界面";
                *npuser += 1;
                Sleep(3000); /// 短暂延时后返回登录界面
                goto here;
            }
        }
        else
            continue;
    }
there:
    Sleep(100);
}
/// @brief 主界面
/// @param pro 商品信息结构体
/// @param user 个人信息结构体
/// @param Item 商品属性字符串
/// @param nppro 商品数指针
/// @param npuser 个人信息数
void Selectmenu(struct Product *pro, struct User *user, char Item[][PRODUCT_NAME], int *nppro, int *npuser)
{
    char ch;
    system("CLS");
    system("color F7"); // 设置整体颜色
    SetPos(0, 0);       // 将下一步输入设置到x=0,y=0坐标对应位置
    while (1)
    {
        char name[40];
        color(23); // 更新此后输出颜色
        cout << "退出0";
        color(249); // 更新此后输出颜色

        SetPos(0, 1);     // 将下一步输入设置到x=0,y=1坐标对应位置
        line(0, 60, '='); // 打印一行（60列）‘=’
        color(244);       // 更新此后输出颜色
        cout << "CTMS (Canteen Takeaway Management System)(食堂外卖管理系统)" << endl;
        color(249); // 更新此后输出颜色
        line(0, 60, '=');
        SetPos(0, 4); // 将下一步输入设置到x=0,y=4坐标对应位置
        color(176);   // 更新此后输出颜色
        ctms();
        color(23);
        SetPos(0, 33);
        cout << "菜单1\t\t";
        cout << "分类2";
        SetPos(37, 33);
        cout << "订单3";
        SetPos(55, 33);
        cout << "我的4" << endl;
        color(62);
        cout << "(输入对应数字跳转页面,不需要回车) 跳转时有一点延迟，请等待  ";
        _time(); // 显示当前时间
        ch = getch();
        if ((ch == '1') || (ch == '2') || (ch == '3') || (ch == '4') || (ch == '0'))
        {
            switch (ch)
            {
            case '1':
                /// 菜单
                cas1(pro, user, Item, nppro, npuser);
                break;
            case '2':
                /// 分类
                cas2(pro, user, Item, nppro, npuser);
                break;
            case '3':
                /// 订单
                cas3(pro, user, Item, nppro, rod, npuser);
                break;
            case '4':
                /// 个人中心
                cas4(pro, user, Item, nppro, npuser, plog);
                break;
            case '0':
                /// 退出
                casesc();
                break;
            default:
                break;
            }
        }
    }
}
/// @brief 退出主界面
void casesc()
{

    int t = 3;
    system("CLS");
    system("color 7F");
    ctms2(); // THANKS FOR USING CTMS
    color(116);
    while (t--)
    {

        SetPos(20, 28);
        cout << "将在" << t << "s后自动退出" << endl
             << endl;
        cout << "\t\t若您使用DEVC ++，则不能自动退出";
        Sleep(1000);
    }
    exit(0);
}

/// @brief 菜单界面
/// @param pro 商品结构体
/// @param user 个人信息结构体
/// @param Item 商品属性选项
/// @param nppro 商品数指针
/// @param npuser 个人信息数
void cas1(struct Product *pro, struct User *user, char Item[][PRODUCT_NAME], int *nppro, int *npuser)
{

    char ch;
    int n = *nppro;
    // int page = 0, rest = 0;
    while (1)
    {
        system("CLS");
        system("color 7F");

        int i;
        color(113);

        SetPos(0, 1);
        for (i = 0; i < ITEMS; i++)
            cout << Item[i] << "      ";
        SetPos(0, 2);
        line(0, 60, '=');
        for (i = 0; i < *nppro; i++) // setw()函数设置输出数据格式（宽度）
        {
            cout << setw(4) << pro[i].num << setw(9) << pro[i].place << setw(14) << pro[i].merchant << setw(9) << pro[i].distance << "km" << setw(12) << pro[i].prod << setw(6) << pro[i].prize << "元" << endl;
        };
        cout << endl
             << "共计"
             << *nppro
             << "种商品供您选择";

        SetPos(0, 0);
        color(23);
        cout << "返回0"
             << "\t"
             << "点餐1";
        color(228);
        cout << "\t使用鼠标滚轮以查看全部内容";

        while (1)
        {

            ch = getch();
            if (ch == '0')
                /// 返回菜单
                Selectmenu(pro, user, Item, nppro, npuser);
            if (ch == '1')
                /// 进入点餐界面
                cas11(pro, user, Item, nppro, npuser);
        }
    }
}

/// @brief 菜单->点餐界面
/// @param pro 商品结构体
/// @param Item 商品属性字符串
/// @param nppro 商品数指针
/// @param npuser 个人信息数
/// @return 已选商品代码数组
int *cas11(struct Product *pro, struct User *user, char Item[][PRODUCT_NAME], int *nppro, int *npuser)
{

    int i2;
    SetSize(120, 35);
    for (i2 = 0; i2 < *nppro; i2++)
    {
        // 设置y=i2+1控制换行后输出的正确位置
        SetPos(62, i2 + 1);
        /// setw(int __n)控制数据输出格式
        cout << setw(4) << pro[i2].num
             << setw(9) << pro[i2].place
             << setw(14) << pro[i2].merchant
             << setw(9) << pro[i2].distance << "km"
             << setw(12) << pro[i2].prod
             << setw(6) << pro[i2].prize << "元" << endl;
    }
    char ch;
    // float pr = 0;
    int i, j, k;
    int od[PRONUM] = {0}; // 输入的商品代码（包含不存在的）
    int flag;
    HideCursor(0); // 显示光标，便于输入
    while (1)
    {
        system("CLS");
        system("color 7F");
        color(125);
        /// 2.0新增，用户可在点餐时查看菜单
        {
            int i2;
            SetSize(126, 35); /// 将控制台的宽设置为原来的2倍以显示菜单
            HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleScreenBufferSize(hOut, {126, (short int)(npro + 6)}); // 将控制台缓冲区的宽设置为原来的2倍以正常显示菜单
            SetPos(61, 1);
            for (i2 = 0; i2 < ITEMS; i2++)
                cout << Item[i2] << "      ";
            SetPos(61, 2);
            line(0, 60, '=');
            for (i2 = 0; i2 < *nppro; i2++)
            {
                SetPos(62, i2 + 3); // 将欲输出内容设置在x=62,y=i2+3位置，保持界面整齐
                cout << setw(4) << pro[i2].num
                     << setw(9) << pro[i2].place
                     << setw(14) << pro[i2].merchant
                     << setw(9) << pro[i2].distance << "km"
                     << setw(12) << pro[i2].prod
                     << setw(6) << pro[i2].prize << "元" << endl;
            }
        }
        SetPos(0, 0);
        cout << "输入4位代码(2201-"
             << 2200 + *nppro
             << ")进行点餐(如:2201)  ";
        color(23);
        cout << "停止点餐/返回菜单0"
             << endl
             << endl;
        color(125);
        /// 2.0新增，可以记忆已点餐但未付款的商品，以便用户在点餐时可返回菜单，查看商品代码而不会使已点商品数据消失
        if (*pr0 != 0)
        {
            cout << "检测到您上次点餐后有未付款的商品，如下:" << endl;
            int i1, k1;
            for (i1 = 0; rod[i1] != 0; i1++)
                for (k1 = 0; k1 < *nppro; k1++)
                    if (rod[i1] == pro[k1].num)
                        cout << "      " << pro[k1].prod << "  " << pro[k1].prize << "元" << endl;
            cout << "      以上共计:" << *pr0 << "元" << endl;
            cout << "您可继续点餐，稍后一同付款" << endl;
        }
        ///

        char num[4] = {'0'};
        for (i = 0;; i++)
        {
            flag = 1;
            for (j = 0; j < 4; j++)
            {
                num[j] = getche();
                if (num[0] == '0') // 检测第一位 输入0直接退出循环
                {
                    color(116);
                    cout << "\n\t\t已选择商品共计" << *pr0 << "元" << endl
                         << "\t您可在订单页面查看已选购商品信息并结账" << endl
                         << "\t\t按0返回菜单,按1查看订单" << endl;
                    HideCursor(1); // 隐藏鼠标光标
                    color(23);
                    cout << "\t\t\t查看订单1";
                    ch = getch();

                    if (ch == '0' || ch != '1')
                    {
                        SetSize(63, 35);
                        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleScreenBufferSize(hOut, {63, (short int)(npro + 6)});
                        cas1(pro, user, Item, nppro, npuser);
                    }
                    if (ch == '1') /// 2.0新增，可在点餐后直接进入订单页面
                    {
                        SetSize(63, 35);
                        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleScreenBufferSize(hOut, {63, (short int)(npro + 6)});
                        cas3(pro, user, Item, nppro, rod, npuser);
                    }
                }
            }
            od[i] = atoi(num); // atoi()函数将数字字符串转为数字

            for (k = 0; k < *nppro; k++)
                if (od[i] == pro[k].num)
                    break;
            if (k == *nppro)
                flag = 0;

            if (flag == 1)
            {
                rod[(*pco)++] = od[i];
                *pr0 += pro[k].prize;
                cout << "  " << pro[k].prod << "  " << pro[k].prize << "元\t以上共计:"
                     << *pr0 << "元"
                     << endl;
            }
            else
                cout << "  "
                     << "无此商品"
                     << endl;
        }
    }

    return rod; // 输入的商品代码（不包含不存在的）
}

/// @brief 分类界面
/// @param pro 商品结构体
/// @param user 个人信息结构体
/// @param Item 商品属性
/// @param nppro 商品数指针
/// @param npuser 个人信息数
void cas2(struct Product *pro, struct User *user, char Item[][PRODUCT_NAME], int *nppro, int *npuser)
{
    char ch;
    int lk;
    while (1)
    {
        system("CLS");
        system("color 7F");
        color(23);
        SetPos(0, 0);
        cout << "返回0"
             << "\t"
             << "紫荆苑  1"
             << "\t"
             << "玉兰苑  2"
             << "\t"
             << "民族餐厅3"
             << "\n"
             << "\t食物    4"
             << "\t"
             << "饮品    5"
             << "\t"
             << "距我最远6"
             << endl
             << "\t距我最近7\t"
             << "价格最贵8\t"
             << "价格最低9\n";
        color(121);
        cout << "\t(1-5)点一下显示，再点一下隐藏" << endl;
        color(113);
        line(0, 60, '=');
        color(125);
        ch = getch();

        if (ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9')
        {
            fenlei(pro, Item, ch, nppro);
            SetPos(0, 0);
            ch = getch();
            if (ch == '0')
                Selectmenu(pro, user, Item, nppro, npuser);
        }
        if (ch == '0')
            Selectmenu(pro, user, Item, nppro, npuser);
    }
}

/// @brief 订单界面
/// @param pro 商品信息结构体
/// @param user 个人信息
/// @param Item 商品属性字符串
/// @param nppro 商品数指针
/// @param rod 已选商品代码数组
/// @param npuser 个人信息数
/// @return 价格
float *cas3(struct Product *pro, struct User *user, char Item[][PRODUCT_NAME], int *nppro, int *rod, int *npuser)
{
    // *pr0 = 0;
    float r0;
    SYSTEMTIME t;
    char discounts[7][60] = {"无门槛减5元", "8折付款", "无门槛减5元", "5折付款", "积分额外加8", "积分额外加10", "6折付款"};
    char ch;
    int i, j, k;
    // float pr = 0;
    while (1)
    {
        system("CLS");
        system("color 7F");
        color(113);
        SetPos(0, 4);

        for (i = 0; i < *nppro; i++)
        {
            for (j = 0; *(rod + j) != 0; j++)
            {
                if (pro[i].num == rod[j])
                {

                    cout << setw(4) << pro[i].num << setw(9) << pro[i].place << setw(14) << pro[i].merchant << setw(9) << pro[i].distance << "km" << setw(12) << pro[i].prod << setw(6) << pro[i].prize << "元" << endl;
                    //*pr0 += pro[i].prize;
                }
            }
        }

        if (*pr0 != 0)
        {

            cout << "\n\t\t\t以上共计" << *pr0 << "元" << endl;
            color(189);
            GetLocalTime(&t);
            r0 = *pr0; /// 2.0新增，防止多次进出订单页面导致*pr0被优惠政策多次优惠（1.0版本无需考虑此BUG，因为1.0不能多次进出订单页面）
            if (t.wDayOfWeek == 0)
                r0 -= 5; /// 1.0版本此处为*pr0-=5,以下以此类推
            if (t.wDayOfWeek == 1)
                r0 *= 0.8;
            if (t.wDayOfWeek == 2)
                r0 -= 5;
            if (t.wDayOfWeek == 3)
                r0 *= 0.5;
            if (t.wDayOfWeek == 4)
                user[*plog].points += 8;
            if (t.wDayOfWeek == 5)
                user[*plog].points += 10;
            if (t.wDayOfWeek == 6)
                r0 *= 0.6;
            cout << "\n\n\t\t今天是 星期" << t.wDayOfWeek << " 您可享受" << discounts[t.wDayOfWeek] << endl
                 << "\t\t优惠后您需支付" << r0 << "元"; // t.wDayOfWeek为星期信息
            SetPos(0, 0);
            color(23);
            cout << "返回0"
                 << "\t"
                 << "付款1" << endl;
            color(121);
            line(0, 60, '=');
            for (i = 0; i < ITEMS; i++)
                cout << Item[i] << "      ";
            SetPos(0, 3);
            line(0, 60, '=');
        }
        else
        {
            SetPos(0, 0);
            color(23);
            cout << "返回0";
            color(116);
            cout << "\t\t您还没有在菜单的点餐页面中点餐";
        }

        ch = getch();

        if (ch == '1' && (*pr0 != 0))
        {
            *pr0 = r0; /// 2.0新增
            cas31(pro, user, Item, nppro, npuser);
        }
        else
            Selectmenu(pro, user, Item, nppro, npuser);
    }
    return pr0;
}

/// @brief 订单->付款界面     ，由于为页面cas3的下一页，故取名cas31
/// @param pro 商品结构体
/// @param user 个人信息结构体
/// @param Item 商品属性字符串
/// @param nppro 商品数
/// @param npuser 个人信息数
/// @return 暂无
float *cas31(struct Product *pro, struct User *user, char Item[][60], int *nppro, int *npuser)
{
    /// void *memset (void *, int, size_t);此函数可直接清空数组内容，免去逐一赋值
    memset(rod, 0, sizeof(rod)); // 清空rod数组(存储上次选购的商品代码）
    *pco = 0;                    // 将已点商品计数器清零
    char ch;
    system("CLS");
    system("color 7F");
    color(125);
    SetPos(0, 12);
    line(2, 30, '=');
    cout << "\t\t您当前余额为:" << user[*plog].balance << endl;
    user[*plog].balance -= *pr0;
    cout << "\t\t付款后余额剩余:" << user[*plog].balance << endl;
    cout << "\t\t本次积分:" << *pr0 * 0.5 << endl;
    user[*plog].points += *pr0 * 0.5;
    cout << "\t\t总积分:" << user[*plog].points << endl;
    Writeuser(user);//将个人信息及时存入文件
    line(2, 30, '=');
    *pr0 = 0;
    rod[0] = 0;
    SetPos(0, 0);
    color(23);
    cout << "返回菜单0";
    while (1)
    {
        ch = getch();
        if (ch == '0')
        {
            Selectmenu(pro, user, Item, nppro, npuser);
        }
    }
}
/// cas4及其子页面已移出此文件，请往Personal center.cpp查看

/// @brief 初始化，仅修饰页面实际无作用，
void cas0()
{
    int t = 4, p = 21, i;
    system("CLS");
    system("color 7F");
    color(23);

    SetPos(5, 19);
    cout << "初始化中，请稍等";
    while (t--)
    {
        /*SetPos(21, 17);
        cout << "将于" << t << "s后进入" << endl
             << endl;*/
        for (i = 0; i < 10; i++)
        {
            SetPos(p, 19);
            Sleep(50);
            cout << ".";
            p += 1;
        }
    }
}
