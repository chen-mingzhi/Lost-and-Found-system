#include<iostream>
#include<fstream>
#include<string>
#include"Lost_Foud.h"
#include"Lost.h"
#include"Found.h"
using namespace std;
void Login_or_Register();
void Register();
void OFF();

void Show_Login_or_Register()
{
    cout << "1.��¼" << endl;
    cout << "2.ע��" << endl;
    cout << "0.�˳�" << endl;
}

void OFF()
{
    cout << "��лʹ�ã�" << endl;
    system("pause");
    exit(0);
}

void Login_or_Register()
{
    Show_Login_or_Register();
    cout << "����������ѡ��";
    int choice = 0;
    cin >> choice;
    if (choice == 1)
    {
        ifstream file;
        file.open("User_Information.txt", ios::in);
        if (!file.is_open())
        {
            cout << "�ļ�������" << endl;
            file.close();
        }
        string name, mima;
        cout << "�������û�����";
        cin >> name;
        cout << "���������룺";
        cin >> mima;
        string Username, Password;
        bool temp = false;
        while (file >> Username && file >> Password)
        {
            if (name == Username && mima == Password)
            {
                cout << "��¼�ɹ���" << endl;
                temp = true;
                file.close();
                system("pause");
                system("cls");
                Lost_Found lf;                  //����֮�����ϵͳ���ڴ�ʵ�ֹ���
                lf.Show_Menu();
                while (true)
                {
                    lf.Choice();
                    lf.Show_again();
                }
            }
            
        }
        if (temp == false)
        {
            cout << "��¼ʧ�ܣ�" << endl << "�û��������������......" << endl;
            cout << "�������������0�˳�:";
            int choice2 = 0;
            cin >> choice2;
            if (choice2 == 0)
            {
                OFF();
            }
            else
            {
                Login_or_Register();
            }
        }
    }
    else if (choice == 2)
    {
        Register();
    }
    else if (choice == 0)
    {
        OFF();
    }
    
}

void Register()
{
    string name, mima;
    cout << "�������û�����";
    cin >> name;
    cout << "���������룺";
    cin >> mima;
    ofstream file;
    file.open("User_Information.txt", ios::out | ios::app);   //ios::app ׷��
    file << name << " " << mima << endl;
    cout << "ע��ɹ���" << endl;
    system("pause");
    system("cls");
    file.close();
    Login_or_Register();
}

void Lost_and_Found()
{
    Login_or_Register();        //�����Ľ���������һ�£��ܿ�
}