/**
 * @file SelectMenu.cpp
 * @author ���ǲ��� & Zhangjie
 * @brief
 * @version 0.1
 * @date 2023-05-15
 *
 * @copyright Copyright (c) 2023
 *
 */
/*
 *������
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
float *pr0 = &pr;      // ��ѡ��Ʒ�ܼ�
int rod[PRONUM] = {0}; // ����Ϊ�ֲ���������Ǳ�ڷ��գ����ں����ⶨ��

/// @brief ����̨��ʼ��
void Init()
{
    SetTitle("CTMS (ʳ����������ϵͳ)");						   //���ñ��� 
    MoveWindow2(GetConsoleWindow(), 200, 40, TRUE);                // �ѿ���̨�ϵ�(300,40) �ػ洰��
    HideCursor(1);                                                 // ���ع��
    SetSize(63, 35);                                               // ���ÿ���̨��x=63�У���y=35��
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);                 // ��ȡ����̨��׼io�ľ��
    SetConsoleScreenBufferSize(hOut, {63, (short int)(npro + 6)}); // ���ÿ���̨��������С,npro+5��ʹ����̨���ݲ˵����ȶ�̬�仯
    system("color F7");                                            // ��ʼ������̨ǰ��������ɫ
}
/// @brief 2.0������ע�����¼�����Զ������ע���˺�
/// @param p ������Ϣ
/// @param npuser ������
void register_login(struct User *p, int *npuser)
{

    char ch, _login[1] = {'0'};
    int i, j, _login1;
    int randuid;
    char pass[PASSWORD] = "\0"; // �ݴ��¼����
    char reg1[PASSWORD] = "\0"; // �ݴ�ע������
    char reg2[PASSWORD] = "\0"; // �ݴ�ע�����루�ڶ������룩
    SYSTEMTIME t0;
    GetLocalTime(&t0); // ��ȡ����ʱ�䣬������α����� 
here:                  /// ע��󷵻ش˴������е�¼��
    FILE *fp = fopen(FILENAME1, "r+");
    *npuser = Readuser(fp, p);
    fclose(fp);

    while (1)
    {
        system("CLS");
        system("color 7F");
        color(23);
        cout << "ע��0\t"
             << "���ܵ�¼1\t"
             << "��¼2��n(n<10)" << endl;
        color(113);
        cout << "��⵽������ע���˺�:" << endl;
        line(2, 20, '-');
        cout << "\t\t    "
             << "���:1" << endl
             << "\t\t    "
             << "�û���:" << p->username << endl
             << "\t\t    "
             << "UID:" << p->uid << endl
             << "\t\t(�����˺ţ����ܵ�¼)" << endl; // ��������ܵ�¼�Ĺ����˺�
        line(2, 20, '-');
        for (i = 1; i < *npuser; i++)
        {
            cout << "\t\t    "
                 << "���:" << i + 1 << endl
                 << "\t\t    "
                 << "�û���:" << (p + i)->username << endl
                 << "\t\t    "
                 << "UID:" << (p + i)->uid << endl;
            line(2, 20, '-');
        }
        cout << endl
             << "���������Ӧ��ŵ�¼��0ע��";
    here3:
        _login[0] = getch();
        if (_login[0] > 47 && _login[0] < 58) // 48��Ӧ'0',57��Ӧ'9'
            _login1 = atoi(_login);           /// atoi()�����������ַ���ת������<-stdlib.h 
        else
            goto here3;                        // ��������here3������ִ��
        if (_login1 > 0 && _login1 <= *npuser) // �ж��Ƿ�����¼
        {
            *plog = _login1 - 1; // ����¼���-1�õ��ѵ�¼������Ϣ�����±�
            if (*plog == 0)      // ��Ϊ�����˺ţ����ܵ�¼
                break;
            else
            {
                while (1)//��¼ 
                {

                    system("CLS");
                    system("color 7F");
                    color(23);
                    cout << "����Esc\t";
                    color(113);
                    cout << "���س���������������";
                    SetPos(12, 10);
                    cout << "    �û���:" << p[*plog].username << endl;
                    cout << "\t\t����������:";
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
                    if (strcmp(pass, p[*plog].password) == 0) // �ж�����������ע�������Ƿ�һ��
                        goto there;                           // ������ʱ���˳��˺���
                    else
                    {
                        memset(pass, '\0', sizeof(pass));
                        cout << "\n\t\t�������,����������:";
                        goto here1; // ���������봦��������
                    }
                }
            }
        }
        /// �ж�ע���ź�
        else if (_login1 == 0)
        {
            while (1)
            {
                system("CLS");
                system("color 7F");
                color(241);
                cout << "���س���������������";
                color(113);

                SetPos(12, 10);
                HideCursor(0); // ��ʾ�����
                cout << "\t\tע��" << endl;
                cout << "\t\t������һ���û���(��:XXXX):";
                cin >> p[*npuser].username;
                cout << endl
                     << "\t\t����������:";
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
                     << "\t\t���ٴ��������룺";
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
                    cout << "\n\t\t���벻һ��";
                    goto here2;
                }
                cout << endl
                     << "\t\t�������ջ���ַ:";
                cin >> p[*npuser].adr;
                p[*npuser].balance = 100;
                p[*npuser].points = 100;
            rerand:
                randuid = t0.wMinute * t0.wSecond + 210000000 + rand() % (999990000 - 210000000); // ����9λ���UID
                /// ������һ����ֹUID�ظ�
                for (j = 0; j < *npuser; j++)
                    if (randuid == atoi(p[j].uid))
                        goto rerand;

                itoa(randuid, p[*npuser].uid, 10); /// itoa()������������תΪ�����ַ���������Ϊ10���ƣ�
                FILE *f2 = fopen(FILENAME1, "a+"); // ��׷��д�뷽ʽ�򿪴��ļ�
                /// д�뱾��ע����Ϣ
                fprintf(f2, "\n%s %s %s %s %.2f %.2f", p[*npuser].username, p[*npuser].uid, p[*npuser].password, p[*npuser].adr, p[*npuser].balance, p[*npuser].points);
                fclose(f2);
                HideCursor(1); // ���������

                cout << "\tע��ɹ�,����UIDΪ" << p[*npuser].uid << ",3s�󷵻ص�¼����";
                *npuser += 1;
                Sleep(3000); /// ������ʱ�󷵻ص�¼����
                goto here;
            }
        }
        else
            continue;
    }
there:
    Sleep(100);
}
/// @brief ������
/// @param pro ��Ʒ��Ϣ�ṹ��
/// @param user ������Ϣ�ṹ��
/// @param Item ��Ʒ�����ַ���
/// @param nppro ��Ʒ��ָ��
/// @param npuser ������Ϣ��
void Selectmenu(struct Product *pro, struct User *user, char Item[][PRODUCT_NAME], int *nppro, int *npuser)
{
    char ch;
    system("CLS");
    system("color F7"); // ����������ɫ
    SetPos(0, 0);       // ����һ���������õ�x=0,y=0�����Ӧλ��
    while (1)
    {
        char name[40];
        color(23); // ���´˺������ɫ
        cout << "�˳�0";
        color(249); // ���´˺������ɫ

        SetPos(0, 1);     // ����һ���������õ�x=0,y=1�����Ӧλ��
        line(0, 60, '='); // ��ӡһ�У�60�У���=��
        color(244);       // ���´˺������ɫ
        cout << "CTMS (Canteen Takeaway Management System)(ʳ����������ϵͳ)" << endl;
        color(249); // ���´˺������ɫ
        line(0, 60, '=');
        SetPos(0, 4); // ����һ���������õ�x=0,y=4�����Ӧλ��
        color(176);   // ���´˺������ɫ
        ctms();
        color(23);
        SetPos(0, 33);
        cout << "�˵�1\t\t";
        cout << "����2";
        SetPos(37, 33);
        cout << "����3";
        SetPos(55, 33);
        cout << "�ҵ�4" << endl;
        color(62);
        cout << "(�����Ӧ������תҳ��,����Ҫ�س�) ��תʱ��һ���ӳ٣���ȴ�  ";
        _time(); // ��ʾ��ǰʱ��
        ch = getch();
        if ((ch == '1') || (ch == '2') || (ch == '3') || (ch == '4') || (ch == '0'))
        {
            switch (ch)
            {
            case '1':
                /// �˵�
                cas1(pro, user, Item, nppro, npuser);
                break;
            case '2':
                /// ����
                cas2(pro, user, Item, nppro, npuser);
                break;
            case '3':
                /// ����
                cas3(pro, user, Item, nppro, rod, npuser);
                break;
            case '4':
                /// ��������
                cas4(pro, user, Item, nppro, npuser, plog);
                break;
            case '0':
                /// �˳�
                casesc();
                break;
            default:
                break;
            }
        }
    }
}
/// @brief �˳�������
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
        cout << "����" << t << "s���Զ��˳�" << endl
             << endl;
        cout << "\t\t����ʹ��DEVC ++�������Զ��˳�";
        Sleep(1000);
    }
    exit(0);
}

/// @brief �˵�����
/// @param pro ��Ʒ�ṹ��
/// @param user ������Ϣ�ṹ��
/// @param Item ��Ʒ����ѡ��
/// @param nppro ��Ʒ��ָ��
/// @param npuser ������Ϣ��
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
        for (i = 0; i < *nppro; i++) // setw()��������������ݸ�ʽ����ȣ�
        {
            cout << setw(4) << pro[i].num << setw(9) << pro[i].place << setw(14) << pro[i].merchant << setw(9) << pro[i].distance << "km" << setw(12) << pro[i].prod << setw(6) << pro[i].prize << "Ԫ" << endl;
        };
        cout << endl
             << "����"
             << *nppro
             << "����Ʒ����ѡ��";

        SetPos(0, 0);
        color(23);
        cout << "����0"
             << "\t"
             << "���1";
        color(228);
        cout << "\tʹ���������Բ鿴ȫ������";

        while (1)
        {

            ch = getch();
            if (ch == '0')
                /// ���ز˵�
                Selectmenu(pro, user, Item, nppro, npuser);
            if (ch == '1')
                /// �����ͽ���
                cas11(pro, user, Item, nppro, npuser);
        }
    }
}

/// @brief �˵�->��ͽ���
/// @param pro ��Ʒ�ṹ��
/// @param Item ��Ʒ�����ַ���
/// @param nppro ��Ʒ��ָ��
/// @param npuser ������Ϣ��
/// @return ��ѡ��Ʒ��������
int *cas11(struct Product *pro, struct User *user, char Item[][PRODUCT_NAME], int *nppro, int *npuser)
{

    int i2;
    SetSize(120, 35);
    for (i2 = 0; i2 < *nppro; i2++)
    {
        // ����y=i2+1���ƻ��к��������ȷλ��
        SetPos(62, i2 + 1);
        /// setw(int __n)�������������ʽ
        cout << setw(4) << pro[i2].num
             << setw(9) << pro[i2].place
             << setw(14) << pro[i2].merchant
             << setw(9) << pro[i2].distance << "km"
             << setw(12) << pro[i2].prod
             << setw(6) << pro[i2].prize << "Ԫ" << endl;
    }
    char ch;
    // float pr = 0;
    int i, j, k;
    int od[PRONUM] = {0}; // �������Ʒ���루���������ڵģ�
    int flag;
    HideCursor(0); // ��ʾ��꣬��������
    while (1)
    {
        system("CLS");
        system("color 7F");
        color(125);
        /// 2.0�������û����ڵ��ʱ�鿴�˵�
        {
            int i2;
            SetSize(126, 35); /// ������̨�Ŀ�����Ϊԭ����2������ʾ�˵�
            HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleScreenBufferSize(hOut, {126, (short int)(npro + 6)}); // ������̨�������Ŀ�����Ϊԭ����2����������ʾ�˵�
            SetPos(61, 1);
            for (i2 = 0; i2 < ITEMS; i2++)
                cout << Item[i2] << "      ";
            SetPos(61, 2);
            line(0, 60, '=');
            for (i2 = 0; i2 < *nppro; i2++)
            {
                SetPos(62, i2 + 3); // �����������������x=62,y=i2+3λ�ã����ֽ�������
                cout << setw(4) << pro[i2].num
                     << setw(9) << pro[i2].place
                     << setw(14) << pro[i2].merchant
                     << setw(9) << pro[i2].distance << "km"
                     << setw(12) << pro[i2].prod
                     << setw(6) << pro[i2].prize << "Ԫ" << endl;
            }
        }
        SetPos(0, 0);
        cout << "����4λ����(2201-"
             << 2200 + *nppro
             << ")���е��(��:2201)  ";
        color(23);
        cout << "ֹͣ���/���ز˵�0"
             << endl
             << endl;
        color(125);
        /// 2.0���������Լ����ѵ�͵�δ�������Ʒ���Ա��û��ڵ��ʱ�ɷ��ز˵����鿴��Ʒ���������ʹ�ѵ���Ʒ������ʧ
        if (*pr0 != 0)
        {
            cout << "��⵽���ϴε�ͺ���δ�������Ʒ������:" << endl;
            int i1, k1;
            for (i1 = 0; rod[i1] != 0; i1++)
                for (k1 = 0; k1 < *nppro; k1++)
                    if (rod[i1] == pro[k1].num)
                        cout << "      " << pro[k1].prod << "  " << pro[k1].prize << "Ԫ" << endl;
            cout << "      ���Ϲ���:" << *pr0 << "Ԫ" << endl;
            cout << "���ɼ�����ͣ��Ժ�һͬ����" << endl;
        }
        ///

        char num[4] = {'0'};
        for (i = 0;; i++)
        {
            flag = 1;
            for (j = 0; j < 4; j++)
            {
                num[j] = getche();
                if (num[0] == '0') // ����һλ ����0ֱ���˳�ѭ��
                {
                    color(116);
                    cout << "\n\t\t��ѡ����Ʒ����" << *pr0 << "Ԫ" << endl
                         << "\t�����ڶ���ҳ��鿴��ѡ����Ʒ��Ϣ������" << endl
                         << "\t\t��0���ز˵�,��1�鿴����" << endl;
                    HideCursor(1); // ���������
                    color(23);
                    cout << "\t\t\t�鿴����1";
                    ch = getch();

                    if (ch == '0' || ch != '1')
                    {
                        SetSize(63, 35);
                        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleScreenBufferSize(hOut, {63, (short int)(npro + 6)});
                        cas1(pro, user, Item, nppro, npuser);
                    }
                    if (ch == '1') /// 2.0���������ڵ�ͺ�ֱ�ӽ��붩��ҳ��
                    {
                        SetSize(63, 35);
                        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleScreenBufferSize(hOut, {63, (short int)(npro + 6)});
                        cas3(pro, user, Item, nppro, rod, npuser);
                    }
                }
            }
            od[i] = atoi(num); // atoi()�����������ַ���תΪ����

            for (k = 0; k < *nppro; k++)
                if (od[i] == pro[k].num)
                    break;
            if (k == *nppro)
                flag = 0;

            if (flag == 1)
            {
                rod[(*pco)++] = od[i];
                *pr0 += pro[k].prize;
                cout << "  " << pro[k].prod << "  " << pro[k].prize << "Ԫ\t���Ϲ���:"
                     << *pr0 << "Ԫ"
                     << endl;
            }
            else
                cout << "  "
                     << "�޴���Ʒ"
                     << endl;
        }
    }

    return rod; // �������Ʒ���루�����������ڵģ�
}

/// @brief �������
/// @param pro ��Ʒ�ṹ��
/// @param user ������Ϣ�ṹ��
/// @param Item ��Ʒ����
/// @param nppro ��Ʒ��ָ��
/// @param npuser ������Ϣ��
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
        cout << "����0"
             << "\t"
             << "�Ͼ�Է  1"
             << "\t"
             << "����Է  2"
             << "\t"
             << "�������3"
             << "\n"
             << "\tʳ��    4"
             << "\t"
             << "��Ʒ    5"
             << "\t"
             << "������Զ6"
             << endl
             << "\t�������7\t"
             << "�۸����8\t"
             << "�۸����9\n";
        color(121);
        cout << "\t(1-5)��һ����ʾ���ٵ�һ������" << endl;
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

/// @brief ��������
/// @param pro ��Ʒ��Ϣ�ṹ��
/// @param user ������Ϣ
/// @param Item ��Ʒ�����ַ���
/// @param nppro ��Ʒ��ָ��
/// @param rod ��ѡ��Ʒ��������
/// @param npuser ������Ϣ��
/// @return �۸�
float *cas3(struct Product *pro, struct User *user, char Item[][PRODUCT_NAME], int *nppro, int *rod, int *npuser)
{
    // *pr0 = 0;
    float r0;
    SYSTEMTIME t;
    char discounts[7][60] = {"���ż���5Ԫ", "8�۸���", "���ż���5Ԫ", "5�۸���", "���ֶ����8", "���ֶ����10", "6�۸���"};
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

                    cout << setw(4) << pro[i].num << setw(9) << pro[i].place << setw(14) << pro[i].merchant << setw(9) << pro[i].distance << "km" << setw(12) << pro[i].prod << setw(6) << pro[i].prize << "Ԫ" << endl;
                    //*pr0 += pro[i].prize;
                }
            }
        }

        if (*pr0 != 0)
        {

            cout << "\n\t\t\t���Ϲ���" << *pr0 << "Ԫ" << endl;
            color(189);
            GetLocalTime(&t);
            r0 = *pr0; /// 2.0��������ֹ��ν�������ҳ�浼��*pr0���Ż����߶���Żݣ�1.0�汾���迼�Ǵ�BUG����Ϊ1.0���ܶ�ν�������ҳ�棩
            if (t.wDayOfWeek == 0)
                r0 -= 5; /// 1.0�汾�˴�Ϊ*pr0-=5,�����Դ�����
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
            cout << "\n\n\t\t������ ����" << t.wDayOfWeek << " ��������" << discounts[t.wDayOfWeek] << endl
                 << "\t\t�Żݺ�����֧��" << r0 << "Ԫ"; // t.wDayOfWeekΪ������Ϣ
            SetPos(0, 0);
            color(23);
            cout << "����0"
                 << "\t"
                 << "����1" << endl;
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
            cout << "����0";
            color(116);
            cout << "\t\t����û���ڲ˵��ĵ��ҳ���е��";
        }

        ch = getch();

        if (ch == '1' && (*pr0 != 0))
        {
            *pr0 = r0; /// 2.0����
            cas31(pro, user, Item, nppro, npuser);
        }
        else
            Selectmenu(pro, user, Item, nppro, npuser);
    }
    return pr0;
}

/// @brief ����->�������     ������Ϊҳ��cas3����һҳ����ȡ��cas31
/// @param pro ��Ʒ�ṹ��
/// @param user ������Ϣ�ṹ��
/// @param Item ��Ʒ�����ַ���
/// @param nppro ��Ʒ��
/// @param npuser ������Ϣ��
/// @return ����
float *cas31(struct Product *pro, struct User *user, char Item[][60], int *nppro, int *npuser)
{
    /// void *memset (void *, int, size_t);�˺�����ֱ������������ݣ���ȥ��һ��ֵ
    memset(rod, 0, sizeof(rod)); // ���rod����(�洢�ϴ�ѡ������Ʒ���룩
    *pco = 0;                    // ���ѵ���Ʒ����������
    char ch;
    system("CLS");
    system("color 7F");
    color(125);
    SetPos(0, 12);
    line(2, 30, '=');
    cout << "\t\t����ǰ���Ϊ:" << user[*plog].balance << endl;
    user[*plog].balance -= *pr0;
    cout << "\t\t��������ʣ��:" << user[*plog].balance << endl;
    cout << "\t\t���λ���:" << *pr0 * 0.5 << endl;
    user[*plog].points += *pr0 * 0.5;
    cout << "\t\t�ܻ���:" << user[*plog].points << endl;
    Writeuser(user);//��������Ϣ��ʱ�����ļ�
    line(2, 30, '=');
    *pr0 = 0;
    rod[0] = 0;
    SetPos(0, 0);
    color(23);
    cout << "���ز˵�0";
    while (1)
    {
        ch = getch();
        if (ch == '0')
        {
            Selectmenu(pro, user, Item, nppro, npuser);
        }
    }
}
/// cas4������ҳ�����Ƴ����ļ�������Personal center.cpp�鿴

/// @brief ��ʼ����������ҳ��ʵ�������ã�
void cas0()
{
    int t = 4, p = 21, i;
    system("CLS");
    system("color 7F");
    color(23);

    SetPos(5, 19);
    cout << "��ʼ���У����Ե�";
    while (t--)
    {
        /*SetPos(21, 17);
        cout << "����" << t << "s�����" << endl
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
