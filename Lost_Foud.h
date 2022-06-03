#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"Object.h"
#include"Found.h"
#include"Lost.h"
using namespace std;

class Lost_Found
{
public:
    int object_num;         //记录物品数量
    Object** object_arr;    //物品数组指针（第一个*指new，第二个*指向数组）
    bool File_is_Empty;
    Lost_Found()
    {
        fstream file;                                   //创建流对象
        file.open("Object_Information.txt", ios::in);   //文件的打开方式（ios::in，为读文件而打开文件）
        //若文件不存在
        if (!file.is_open())                            //如果文件不存在就将数值初始化
        {
            //cout << "文件不存在" <<endl;                //测试代码
            this->object_num = 0;                       //初始化物品数量
            this->object_arr = NULL;                    //初始化数组指针
            this->File_is_Empty = true;
            file.close();                               //关闭文件
            return;                                     //强行终止函数运行
        }
        //如果文件存在，但里面一点内容也没有
        char temp;
        file >> temp;                                   //让文件往里读一个字符，若文件为空，那么读到的第一个字符将是一个结尾标eof
        if (file.eof())                                 //若eof()函数为真，就说明文件是空的
        {
            //cout << "文件为空！" << endl;               //测试代码
            this->object_num = 0;                       //初始化物品数量
            this->object_arr = NULL;                    //初始化数组指针
            this->File_is_Empty = true;
            file.close();
            return;
        }
        //若文件存在，且内容不为空，就记录数据
        int num = this->Check_Object_Num();
        //cout << "当前物品数量为：" << num << "个" << endl;    //测试代码
        this->object_num = num;                             //初始化物品数量
        this->object_arr = new Object*[this->object_num];   //让物品数组追加新的内存
        this->init_Object();                                //初始化
        // for (int  i = 0; i < this->object_num; i++)         //测试代码
        // {
        //     cout << object_arr[i]->object_name << endl;
        // }
        
    }

    void Add_Object()       //添加物品函数
    {
        int add = 0;    //所要添加的数量
        cout << "要添加几个物品：";
        cin >> add;
        if (add > 0)
        {
            int newNum = this->object_num + add;        //计算新空间大小
            Object** newSpace = new Object*[newNum];    //开辟新空间
            if (object_arr != NULL)                     //当原数组不为空时，先将原来数组里的数据拷进newSpace里面
            {
                for (int i = 0; i < this->object_num; i++)
                {
                    newSpace[i] = this->object_arr[i];
                }
                
            }
            for (int i = 0; i < add; i++)           //添加新数据
            {
                int month = 0, date = 0, choice = 0, hour = 0, minute = 0;
                string ob_name, people_name, place, phone_num;
                cout << "请输入第" << i + 1 << "个物品的名字：";
                cin >> ob_name;
                cout << "什么时候捡到或丢失的呢？" << endl << "月：";
                cin >> month;
                cout << "日：";
                cin >> date;
                cout << "时：";
                cin >> hour;
                cout << "分：";
                cin >> minute;
                cout << "是捡到东西了还是东西丢了？" << endl;
                cout << "1.我捡到东西了" << endl << "2.我东西丢了" << endl;
                cout << "请输入您的选择：";
                cin >> choice;
                cout << "在哪捡到或丢的呢？" << endl;
                cin >> place;
                cout << "请输入您的姓名：";
                cin >> people_name;
                cout << "您的联系方式(手机号码、QQ、微信都行)：";
                cin >> phone_num;
                Object * object = NULL;     //创建父类指针
                switch (choice)
                {
                case 1:         //捡到东西，父类指针指向子类指针
                    object = new Found(ob_name, people_name, month, date, hour, minute, place, phone_num);
                    break;
                case 2:         //东西丢了
                    object = new Lost(ob_name, people_name, month, date, hour, minute, place, phone_num);
                    break;
                default:
                    break;
                }
                newSpace[this->object_num + i] = object;    //将创建的object指针保存到数组中
            }
            delete[] this->object_arr;      //释放原有内存
            this->object_arr = newSpace;    //原来的空间就不要了，指向新空间，更新空间
            this->object_num = newNum;      //更新物品数量
            this->SaveObject();
            this->File_is_Empty = false;    //更新物品不为空
            cout << "成功添加" << add << "件物品！" << endl;
        }
        else
        {
            cout << "无效输入，请重新输入！" << endl;   //若用户输入了别的，就重新输入，类似递归
            Add_Object();
        }
        
    }

    void TuiChu()           //退出系统函数
    {
        cout << "已退出系统，欢迎下次使用！" << endl;
        system("pause");
        exit(0);
    }

    void Show_Menu()        //显示菜单
    {
        cout << "*************************************" << endl;
        cout << "********欢迎使用失物招领系统!********" << endl;
        cout << "***********0.退出管理程序    ********" << endl;
        cout << "***********1.发布物品信息    ********" << endl;
        cout << "***********2.显示全部物品信息********" << endl;
        cout << "***********3.认领物品        ********" << endl;
        cout << "***********4.查看物品信息    ********" << endl;
        cout << "*************************************" << endl;
        cout << endl;
    }

    void Show_again()       //当用户输入错误时重新显示的菜单
{
    cout << "*************************************" << endl;
    cout << "***********0.退出管理程序    ********" << endl;
    cout << "***********1.发布物品信息    ********" << endl;
    cout << "***********2.显示全部物品信息********" << endl;
    cout << "***********3.认领物品        ********" << endl;
    cout << "***********4.查看物品信息    ********" << endl;
    cout << "*************************************" << endl;
    cout << endl;
}

    void Choice()           //用户选择功能菜单的函数
    {
        cout << "请输入您的选择：";
        int choice = 0;
        cin >> choice;
        if (choice == 0)
        {
            TuiChu();
        }
        switch (choice)
        {
            case 1:     //发布物品信息
                this->Add_Object();
                system("pause");
                system("cls");
                break;
            case 2:     //显示物品信息
                this->Show_Object_Info();
                system("pause");
                system("cls");
                break;
            case 3:     //认领物品
                this->Take_Object();
                system("pause");
                system("cls");
                break;
            case 4:     //查看物品信息
                this->Find_Object();
                system("pause");
                system("cls");
                break;
            default:
                system("cls");
                Show_again();
                cout << "请重新输入！" << endl;
                Choice();
                break;                              //若输入了其他的东西就重新输入
        }
        
    }

    void SaveObject()       //保存物品信息函数
    {
        ofstream file;                                      //创建流对象
        file.open("Object_Information.txt", ios::out);      //文件的打开方式(out:为写文件而打开文件),创建名为“Object_Information.txt”的文件
        if (file.is_open())
        {
            cout << "读取文件成功！" << endl;
        }
        
        for (int i = 0; i < this->object_num; i++)          //将信息录入Object_Information.txt文件里
        {
            file << this->object_arr[i]->object_name << " " << this->object_arr[i]->month << " " 
            << this->object_arr[i]->date << " " << this->object_arr[i]->hour << " " << 
            this->object_arr[i]->minute << " " << this->object_arr[i]->Get_Lost_or_Found() << " "
            << this->object_arr[i]->place << " " << this->object_arr[i]->people_name << " " << this->object_arr[i]->Phone_Number
            << '\n';
        }
        file.close();   //关闭文件
    }

    int Check_Object_Num()      //通过记录行数的方法记录物品数量，初始化物品数量用
    {
        File_is_Empty = false;
        fstream file;
        char c; 
        int line_num = 0;
        file.open("Object_Information.txt", ios::in);
        while (file.get(c)) 
        {
            if (c == '\n')      //如果读到的字符为换行符，行数就加一
            {
                line_num++;
            }
            
        }
        file.close();
        return line_num;
    } 

    void init_Object()          //初始化物品的函数
    {
        fstream file;
        file.open("Object_Information.txt", ios::in);
        string o_name, state, o_place, p_name, phone;
        int m = 0, d = 0, h = 0, mi = 0;
        int temp = 0;   //临时下标
        //读数据
        while (file >> o_name && file >> m && file >> d && file >> h && file >> mi && file >> state && file >> o_place && file >> p_name && file >> phone)
        {
            Object *object = NULL;
            if (state == "失物")
            {
                object = new Lost(o_name, p_name, m, d, h, mi, o_place, phone);
            }
            else if (state == "拾物")
            {
                object = new Found(o_name, p_name, m, d, h, mi, o_place, phone);
            }
            this->object_arr[temp] = object;    //将文件里数据加载到数组中
            temp++;
        }
        file.close();
    }

    void Show_Object_Info()     //显示物品信息的函数
    {
        if (this->File_is_Empty)        //判断文件是否为空
        {
            cout << "文件还未创建或其中无数据！" << endl;
        }
        else
        {
            for (int i = 0; i < this->object_num; i++)
            {
                this->object_arr[i]->Show_Infomation();     //利用多态调用函数
                //为什么可以访问Show_Infomation()？？
                //Object到Lost/Found(重写),子类继承父类的函数，访问object_arr中的成员（成员是Lost/Found）就可访问Show_Infomation()
            }
            
        }
        
    }

    int If_Object_is_Exist(string name)   //判断物品是否存在，当用户认领物品时就用到此函数，若存在就返回数组的下标
    {
        int Xia_Biao = -1;  //若物品不存在就返回下标-1，让函数强行停止
        for (int  i = 0; i < this->object_num; i++)
        {
            if (this->object_arr[i]->object_name == name)
            {
                Xia_Biao = i;
                break;
            }
            
        }
        return Xia_Biao;
    }

    void Take_Object()      //认领物品函数
    {
        if (this->File_is_Empty)
        {
            cout << "文件还未被创建或文件无数据！" << endl;
        }
        else
        {
            cout << "请输入要认领的物品名称：";
            string name, p_name;        //物品名称，认领人姓名
            cin >> name;
            int Xia_Biao = this->If_Object_is_Exist(name);  //获取该物品在数组中的下标
            if (Xia_Biao != -1)                             //找到物品
            {
                cout << "已找到此物品！"  << endl;
                cout << "请输入你的姓名吧：" << endl;
                cin >> p_name;  //记录认领人的名字
                this->object_arr[Xia_Biao]->object_name += "(已认领,认领人姓名为：" + p_name + ")";     //将物品名称修改为此格式
                this->SaveObject();             
                cout << "认领成功！" << endl;
            }
            else
            {
                cout << "查不到此物品......" << endl;
            }
            
        }
    }

    void Find_Object()      //查找物品
    {
        if (this->File_is_Empty)
        {
            cout << "文件还未创建或文件为空！" << endl;
        }
        else
        {
            cout << "请选择查找方式：" << endl;
            cout << "1.按照物品名称查找" << endl;
            cout << "2.按日期查找" << endl;
            cout << "3.按失主或捡到东西的人的名字查找" << endl;
            int xuanze = 0;
            cout << "您的选择：";
            cin >> xuanze;
            if (xuanze == 1)
            {
                string o_name;
                cout << "请输入想查找物品的名称：";
                cin >> o_name;
                bool temp = false;
                for (int i = 0; i < object_num; i++)
                {
                    if (o_name == this->object_arr[i]->object_name)
                    {
                        this->object_arr[i]->Show_Infomation();
                        temp = true;
                    }
                }
                if (temp == false)
                {
                    cout << "找不到此物品或该物品已被认领！" << endl;
                }
                else
                {
                    cout << "已找到该物品！" << endl;
                }
                
            }
            else if (xuanze == 2)
            {
                cout << "1.查看一个月的所有物品" << endl;
                cout << "2.查具体时间(月、日)的物品" << endl;
                int xuanze2 = 0;
                cout << "您的选择：";
                cin >> xuanze2;
                if (xuanze2 == 1)
                {
                    int m = 0;
                    cout << "请输入你想查找的月份：";
                    cin >> m;
                    bool temp = false;
                    for (int i = 0; i < object_num; i++)
                    {
                        if (this->object_arr[i]->month == m)
                        {
                            this->object_arr[i]->Show_Infomation();
                            temp = true;
                        }
                    }
                    if (temp == false)
                    {
                        cout << "该月无物品挂失......" << endl;
                    }
                    else
                    {
                        cout << "已显示" << m << "月份所有的挂失物品"  << endl;
                    }
                    
                }
                else if (xuanze2 == 2)
                {
                    int m = 0, d= 0;
                    cout << "请输入月份：";
                    cin >> m;
                    cout << "请输入日：";
                    cin >> d;
                    bool temp = false;
                    for (int i = 0; i < object_num; i++)
                    {
                        if (this->object_arr[i]->month == m && this->object_arr[i]->date == d)
                        {
                            this->object_arr[i]->Show_Infomation();
                            temp = true;
                        }
                        
                    }
                    if (temp == false)
                    {
                        cout << "当天无物品挂失......" << endl;
                    }
                    else
                    {
                        cout << "已显示" << m << "月" << d << "日所有的挂失物品"  << endl;
                    }
                }
                
            }
            else if (xuanze == 3)
            {
                string p_name;
                cout << "请输入人名：" << endl;
                cin >> p_name;
                bool temp = false;
                for (int i = 0; i < object_num; i++)
                {
                    if (this->object_arr[i]->people_name == p_name)
                    {
                        this->object_arr[i]->Show_Infomation();
                        temp = true;
                    }
                }
                if (temp == false)
                {
                    cout << "查无此人！" << endl;
                }
                else
                {
                    cout << "已显示该人所挂失的所有物品信息！" << endl;
                }
                
            }
        }
        
    }

    ~Lost_Found(){}
};
/***
 *_______________#########_______________________
 *______________############_____________________
 *______________#############____________________
 *_____________##__###########___________________
 *____________###__######_#####__________________
 *____________###_#######___####_________________
 *___________###__##########_####________________
 *__________####__###########_####_______________
 *________#####___###########__#####_____________
 *_______######___###_########___#####___________
 *_______#####___###___########___######_________
 *______######___###__###########___######_______
 *_____######___####_##############__######______
 *____#######__#####################_#######_____
 *____#######__##############################____
 *___#######__######_#################_#######___
 *___#######__######_######_#########___######___
 *___#######____##__######___######_____######___
 *___#######________######____#####_____#####____
 *____######________#####_____#####_____####_____
 *_____#####________####______#####_____###______
 *______#####______;###________###______#________
 *________##_______####________####______________
 */