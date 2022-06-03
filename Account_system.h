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
    cout << "1.登录" << endl;
    cout << "2.注册" << endl;
    cout << "0.退出" << endl;
}

void OFF()
{
    cout << "感谢使用！" << endl;
    system("pause");
    exit(0);
}

void Login_or_Register()
{
    Show_Login_or_Register();
    cout << "请输入您的选择：";
    int choice = 0;
    cin >> choice;
    if (choice == 1)
    {
        ifstream file;
        file.open("User_Information.txt", ios::in);
        if (!file.is_open())
        {
            cout << "文件不存在" << endl;
            file.close();
        }
        string name, mima;
        cout << "请输入用户名：";
        cin >> name;
        cout << "请输入密码：";
        cin >> mima;
        string Username, Password;
        bool temp = false;
        while (file >> Username && file >> Password)
        {
            if (name == Username && mima == Password)
            {
                cout << "登录成功！" << endl;
                temp = true;
                file.close();
                system("pause");
                system("cls");
                Lost_Found lf;                  //登入之后进入系统，在此实现功能
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
            cout << "登录失败！" << endl << "用户名或者密码错误......" << endl;
            cout << "按任意键继续或按0退出:";
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
    cout << "请输入用户名：";
    cin >> name;
    cout << "请输入密码：";
    cin >> mima;
    ofstream file;
    file.open("User_Information.txt", ios::out | ios::app);   //ios::app 追加
    file << name << " " << mima << endl;
    cout << "注册成功！" << endl;
    system("pause");
    system("cls");
    file.close();
    Login_or_Register();
}

void Lost_and_Found()
{
    Login_or_Register();        //单纯的进行重命名一下，很酷
}