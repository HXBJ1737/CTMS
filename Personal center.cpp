
/**
 * @file Personal center.cpp
 * @author ���ǲ��� & Zhangjie
 * @brief
 * @version 0.1
 * @date 2023-05-15
 *
 * @copyright Copyright (c) 2023
 *
 */
/*
 *4.��������
 *210+70
 */
#include "Define.h"

/// @brief ��������
/// @param pro ��Ʒ�ṹ��
/// @param user ������Ϣ�ṹ��
/// @param Item ��Ʒ�����ַ���
/// @param nppro ��Ʒ��ָ��
/// @param npuser ������Ϣ��
/// @param plog ��¼�ĸ�����Ϣ�����±�
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
             << "�û���:" << user[*plog].username << endl
             << "\t\t    "
             << "UID:" << user[*plog].uid << endl
             << "\t\t    "
             << "��ַ:" << user[*plog].adr << endl
             << "\t\t    "
             << "���:" << user[*plog].balance << endl
             << "\t\t    "
             << "����:" << user[*plog].points << endl;
        // Writeuser(user);
        color(121);
        line(0, 60, '=');
        color(23);
        cout << "��ֵ1        " << endl
             << "������Ϣ�޸�2" << endl
             << "��Ʒ��Ϣ�޸�3" << endl
             << "�ʵ�4        ";

        SetPos(0, 0);
        color(23);
        cout << "����0";
        SetPos(0, 22);
        color(117);
        printf("            --------------------------------------\n");
        printf("            |�����˺ſ��û���Ϊ��%.2f          |\n", user[*plog].points);
        printf("            |����                  �һ���Ʒ      |\n");
        printf("            |100                   ������        |\n");
        printf("            |200                   ����һƿ      |\n");
        printf("            |400                   ������ֽ      |\n");
        printf("            |600                   ����һƿ      |\n");
        printf("            |800                   ѧУ����ʼǱ�|\n");
        printf("            |1000                  У���ĸ���    |\n");
        printf("            |10000                 2-112������ѡ |\n");
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

/// @brief �ҵ�->��ֵҳ��
/// @param pro ��Ʒ��Ϣ�ṹ��
/// @param user ������Ϣ
/// @param Item ��Ʒ�����ַ���
/// @param nppro ��Ʒ��
/// @param npuser ������Ϣ��
/// @param plog ��¼�ĸ�����Ϣ�����±�
void cas41(struct Product *pro, struct User *user, char Item[][PRODUCT_NAME], int *nppro, int *npuser, int *plog)
{
    char ch;
    while (1)
    {
        system("CLS");
        system("color 7F");
        color(23);
        SetPos(0, 0);
        cout << "����0\t\t\t";
        color(30);
        cout << "���:" << user[*plog].balance << endl;
        color(228); // 228
        cout << "*********************��ֵ20Ԫ �밴1*************************" << endl;
        cout << "                                                            " << endl;
        cout << "*********************��ֵ50Ԫ �밴2*************************" << endl;
        cout << "                                                            " << endl;
        cout << "*********************��ֵ100Ԫ �밴3************************" << endl;
        cout << "                                                            " << endl;
        cout << "*********************��ֵ200Ԫ �밴4************************" << endl;
        cout << "                                                            " << endl;
        cout << "*********************��ֵ500Ԫ �밴5************************" << endl;
        cout << "                                                            " << endl;
        cout << "****************��ػ�:��ֵ1000Ԫ��100Ԫ �밴6************" << endl;
        cout << "                                                            " << endl;
        cout << "****************��ػ�:��ֵ2000Ԫ��300Ԫ �밴7************" << endl;
        cout << "                                                            " << endl;
        cout << "****************��ػ�:��ֵ5000Ԫ��1000Ԫ �밴8***********" << endl;
        cout << "                                                            " << endl;
        cout << "****************��ػ�:��ֵ10000Ԫ��3000Ԫ �밴9**********" << endl;
        cout << "                                                            " << endl;
        cout << "**************�Գ���Ա�Ĺ���:����100Ԫ �밴 # **************" << endl;
        cout << "                                                            " << endl;
        cout << "**************�Գ���Ա�Ĺ���:����2000Ԫ �밴 $ *************" << endl;
        cout << "                                                            " << endl;
        cout << "**************�Գ���Ա�Ĺ���:����10000Ԫ �밴 % ************" << endl;
        color(71);
        cout << "                 �����ϵ���ƭ�����ʶ�����                   " << endl;
        color(191);
        cout << "                                                            " << endl;
        cout << "                                                            " << endl;
        cout << "                                                            " << endl;
        cout << "                                                            " << endl;
        cout << "                                                            " << endl;
        cout << "                                                            " << endl;
        cout << "                                                            " << endl;
        cout << "                   ���ڳ�ֵʱ���ִ���,���绰,19935589218  " << endl;
        color(206);
        cout << "              ��л���ϰ壬���ϰ壬��С�磬���ϵܣ����ϵ�����\n";

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
        else if (ch == '#' && user[*plog].balance >= 100) // ������Ϊ��
            user[*plog].balance -= 100;
        else if (ch == '$' && user[*plog].balance >= 2000) // ������Ϊ��
            user[*plog].balance -= 2000;
        else if (ch == '%' && user[*plog].balance >= 10000) // ������Ϊ��
            user[*plog].balance -= 10000;
        else if (ch == '0')
            cas4(pro, user, Item, nppro, npuser, plog);
        Writeuser(user); // ���Ѹ�����Ϣд���ļ�����ֹʧЧ
    }
}
/// @brief �ҵ�->������Ϣ�޸�
/// @param pro ��Ʒ��Ϣ�ṹ��
/// @param user ������Ϣ
/// @param Item ��Ʒ�����ַ���
/// @param nppro ��Ʒ��
/// @param npuser ������Ϣ��
/// @param plog ��¼�ĸ�����Ϣ�����±�
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
        cout << "����0\t�û���1\t����2\t��ַ3" << endl;
        ch = getch();
        if (ch == '1')
        {
            color(241);
            cout << "���������û�����";
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
            cout << "�����������룺";
            cin >> u;
            strcpy(user[*plog].password, u);
            memset(u, '\0', sizeof(u));
            cout << "\n\t\t�޸ĳɹ�";
            Sleep(300);
            Writeuser(user);
            cas4(pro, user, Item, nppro, npuser, plog);
        }
        else if (ch == '3')
        {
            color(241);
            cout << "�������µ�ַ��";
            cin >> u;
            strcpy(user[*plog].adr, u);
            memset(u, '\0', sizeof(u));
            cout << "\n\t\t�޸ĳɹ�";
            Sleep(300);
            Writeuser(user);
            cas4(pro, user, Item, nppro, npuser, plog);
        }
        if (ch == '0')
        {
            Writeuser(user); // ���Ѹ�����Ϣд���ļ�����ֹʧЧ
            cas4(pro, user, Item, nppro, npuser, plog);
        }
    }
}
/// @brief �ҵ�->��Ʒ��Ϣ�޸ģ������ԱȨ�ޣ�
/// @param pro ��Ʒ��Ϣ�ṹ��
/// @param user ������Ϣ
/// @param Item ��Ʒ�����ַ���
/// @param nppro ��Ʒ��
/// @param npuser ������Ϣ��
/// @param plog ��¼�ĸ�����Ϣ�����±�
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
        printf("����Esc\n");
        SetPos(21, 15);
        color(144);
        printf("�������ڹ���Աģʽ\n");
        color(113);
        printf("\t\t\tUID:20230322\n");
        printf("\t\t������8λ����Ա����:");
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
        if (strcmp(pass, realpass) == 0) // �ж�����������ע�������Ƿ�һ��
            goto there;                  // ������ʱ���˳��˺���
        else
        {
            memset(pass, '\0', sizeof(pass));
            printf("\n\t\t�������,����������:");
            goto here; // ���������봦��������
        }
    }
there:
    while (1)
    {
        system("CLS");
        system("color 7F");
        color(113);
        printf("�����޸���Ʒ�۸�\n");
        printf("��������Ʒ���벢�س���");
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
            printf("����Ʒԭ��Ϊ%.1f,\n�������޸ĺ�۸�:", pro[i].prize);
            scanf("%f", &pro[i].prize);
            printf("\n\t�޸ĳɹ�������1.5s�󷵻ظ�������");
            Sleep(1500);
            cas4(pro, user, Item, nppro, npuser, plog);
        }
    }
}

/// @brief �ҵ�->�ʵ�ҳ��
/// @param pro ��Ʒ��Ϣ
/// @param user ������Ϣ
/// @param Item ��Ʒ�����ַ���
/// @param nppro ��Ʒ��
/// @param npuser ������Ϣ��
/// @param plog ��¼�ĸ�����Ϣ�����±�
void cas45(struct Product *pro, struct User *user, char Item[][PRODUCT_NAME], int *nppro, int *npuser, int *plog)
{
    char ch;
    while (1)
    {
        system("CLS");
        system("color 7F");
        {
            SetSize(80, 35); /// ������̨�Ŀ�����Ϊԭ����2������ʾ�˵�
            HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleScreenBufferSize(hOut, {80, 35});
        }
        SetPos(0, 0);
        color(23);
        cout << "����0" << endl;
        color(127);
        float y, x, z;                            // ���帡���ͱ���
        printf("�¶�ʱ������\n");                   // ��ʾ���
        printf("����ʱ��§ס��\n");               // ��ʾ���
        printf("����ʱ��������\n");               // ��ʾ���
        printf("�˷�ʱ������\n");                 // ��ʾ���
        printf("һ�о�����������ǩ��û��ǩ��\n"); // ��ʾ���
        printf("\n");                             // ����
        for (double y = 2.5; y >= -1.6; y = y - 0.2)
        {
            for (double x = -3; x <= 4.8; x = x + 0.1)
            {
                // �����Ǹ���Ŀ���㣬��������ϸ����
                (pow((x * x + y * y - 1), 3) <= 3.6 * x * x * y * y * y || (x > -2.4 && x < -2.1 && y < 1.5 && y > -1) || (((x < 2.5 && x > 2.2) || (x > 3.4 && x < 3.7)) && y > -1 && y < 1.5) || (y > -1 && y < -0.6 && x < 3.7 && x > 2.2)) ? printf("*") : printf(" ");
            }
            printf("\n"); // ����
        }
        ch = getch();
        if (ch == '0')
        {
            SetSize(63, 35);                                                 // ��x=63�У���y=35��
            HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);                   // ��ȡ����̨��׼io�ľ��
            SetConsoleScreenBufferSize(hOut, {63, (short int)(*nppro + 6)}); // ���ÿ���̨��������С,npro+6��ʹ����̨���ݲ˵����ȶ�̬�仯,ȷ��������һ������������ʾ
            cas4(pro, user, Item, nppro, npuser, plog);
        }
    }
}