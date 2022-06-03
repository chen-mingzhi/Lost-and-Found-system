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
    int object_num;         //��¼��Ʒ����
    Object** object_arr;    //��Ʒ����ָ�루��һ��*ָnew���ڶ���*ָ�����飩
    bool File_is_Empty;
    Lost_Found()
    {
        fstream file;                                   //����������
        file.open("Object_Information.txt", ios::in);   //�ļ��Ĵ򿪷�ʽ��ios::in��Ϊ���ļ������ļ���
        //���ļ�������
        if (!file.is_open())                            //����ļ������ھͽ���ֵ��ʼ��
        {
            //cout << "�ļ�������" <<endl;                //���Դ���
            this->object_num = 0;                       //��ʼ����Ʒ����
            this->object_arr = NULL;                    //��ʼ������ָ��
            this->File_is_Empty = true;
            file.close();                               //�ر��ļ�
            return;                                     //ǿ����ֹ��������
        }
        //����ļ����ڣ�������һ������Ҳû��
        char temp;
        file >> temp;                                   //���ļ������һ���ַ������ļ�Ϊ�գ���ô�����ĵ�һ���ַ�����һ����β��eof
        if (file.eof())                                 //��eof()����Ϊ�棬��˵���ļ��ǿյ�
        {
            //cout << "�ļ�Ϊ�գ�" << endl;               //���Դ���
            this->object_num = 0;                       //��ʼ����Ʒ����
            this->object_arr = NULL;                    //��ʼ������ָ��
            this->File_is_Empty = true;
            file.close();
            return;
        }
        //���ļ����ڣ������ݲ�Ϊ�գ��ͼ�¼����
        int num = this->Check_Object_Num();
        //cout << "��ǰ��Ʒ����Ϊ��" << num << "��" << endl;    //���Դ���
        this->object_num = num;                             //��ʼ����Ʒ����
        this->object_arr = new Object*[this->object_num];   //����Ʒ����׷���µ��ڴ�
        this->init_Object();                                //��ʼ��
        // for (int  i = 0; i < this->object_num; i++)         //���Դ���
        // {
        //     cout << object_arr[i]->object_name << endl;
        // }
        
    }

    void Add_Object()       //�����Ʒ����
    {
        int add = 0;    //��Ҫ��ӵ�����
        cout << "Ҫ��Ӽ�����Ʒ��";
        cin >> add;
        if (add > 0)
        {
            int newNum = this->object_num + add;        //�����¿ռ��С
            Object** newSpace = new Object*[newNum];    //�����¿ռ�
            if (object_arr != NULL)                     //��ԭ���鲻Ϊ��ʱ���Ƚ�ԭ������������ݿ���newSpace����
            {
                for (int i = 0; i < this->object_num; i++)
                {
                    newSpace[i] = this->object_arr[i];
                }
                
            }
            for (int i = 0; i < add; i++)           //���������
            {
                int month = 0, date = 0, choice = 0, hour = 0, minute = 0;
                string ob_name, people_name, place, phone_num;
                cout << "�������" << i + 1 << "����Ʒ�����֣�";
                cin >> ob_name;
                cout << "ʲôʱ��񵽻�ʧ���أ�" << endl << "�£�";
                cin >> month;
                cout << "�գ�";
                cin >> date;
                cout << "ʱ��";
                cin >> hour;
                cout << "�֣�";
                cin >> minute;
                cout << "�Ǽ񵽶����˻��Ƕ������ˣ�" << endl;
                cout << "1.�Ҽ񵽶�����" << endl << "2.�Ҷ�������" << endl;
                cout << "����������ѡ��";
                cin >> choice;
                cout << "���ļ񵽻򶪵��أ�" << endl;
                cin >> place;
                cout << "����������������";
                cin >> people_name;
                cout << "������ϵ��ʽ(�ֻ����롢QQ��΢�Ŷ���)��";
                cin >> phone_num;
                Object * object = NULL;     //��������ָ��
                switch (choice)
                {
                case 1:         //�񵽶���������ָ��ָ������ָ��
                    object = new Found(ob_name, people_name, month, date, hour, minute, place, phone_num);
                    break;
                case 2:         //��������
                    object = new Lost(ob_name, people_name, month, date, hour, minute, place, phone_num);
                    break;
                default:
                    break;
                }
                newSpace[this->object_num + i] = object;    //��������objectָ�뱣�浽������
            }
            delete[] this->object_arr;      //�ͷ�ԭ���ڴ�
            this->object_arr = newSpace;    //ԭ���Ŀռ�Ͳ�Ҫ�ˣ�ָ���¿ռ䣬���¿ռ�
            this->object_num = newNum;      //������Ʒ����
            this->SaveObject();
            this->File_is_Empty = false;    //������Ʒ��Ϊ��
            cout << "�ɹ����" << add << "����Ʒ��" << endl;
        }
        else
        {
            cout << "��Ч���룬���������룡" << endl;   //���û������˱�ģ����������룬���Ƶݹ�
            Add_Object();
        }
        
    }

    void TuiChu()           //�˳�ϵͳ����
    {
        cout << "���˳�ϵͳ����ӭ�´�ʹ�ã�" << endl;
        system("pause");
        exit(0);
    }

    void Show_Menu()        //��ʾ�˵�
    {
        cout << "*************************************" << endl;
        cout << "********��ӭʹ��ʧ������ϵͳ!********" << endl;
        cout << "***********0.�˳��������    ********" << endl;
        cout << "***********1.������Ʒ��Ϣ    ********" << endl;
        cout << "***********2.��ʾȫ����Ʒ��Ϣ********" << endl;
        cout << "***********3.������Ʒ        ********" << endl;
        cout << "***********4.�鿴��Ʒ��Ϣ    ********" << endl;
        cout << "*************************************" << endl;
        cout << endl;
    }

    void Show_again()       //���û��������ʱ������ʾ�Ĳ˵�
{
    cout << "*************************************" << endl;
    cout << "***********0.�˳��������    ********" << endl;
    cout << "***********1.������Ʒ��Ϣ    ********" << endl;
    cout << "***********2.��ʾȫ����Ʒ��Ϣ********" << endl;
    cout << "***********3.������Ʒ        ********" << endl;
    cout << "***********4.�鿴��Ʒ��Ϣ    ********" << endl;
    cout << "*************************************" << endl;
    cout << endl;
}

    void Choice()           //�û�ѡ���ܲ˵��ĺ���
    {
        cout << "����������ѡ��";
        int choice = 0;
        cin >> choice;
        if (choice == 0)
        {
            TuiChu();
        }
        switch (choice)
        {
            case 1:     //������Ʒ��Ϣ
                this->Add_Object();
                system("pause");
                system("cls");
                break;
            case 2:     //��ʾ��Ʒ��Ϣ
                this->Show_Object_Info();
                system("pause");
                system("cls");
                break;
            case 3:     //������Ʒ
                this->Take_Object();
                system("pause");
                system("cls");
                break;
            case 4:     //�鿴��Ʒ��Ϣ
                this->Find_Object();
                system("pause");
                system("cls");
                break;
            default:
                system("cls");
                Show_again();
                cout << "���������룡" << endl;
                Choice();
                break;                              //�������������Ķ�������������
        }
        
    }

    void SaveObject()       //������Ʒ��Ϣ����
    {
        ofstream file;                                      //����������
        file.open("Object_Information.txt", ios::out);      //�ļ��Ĵ򿪷�ʽ(out:Ϊд�ļ������ļ�),������Ϊ��Object_Information.txt�����ļ�
        if (file.is_open())
        {
            cout << "��ȡ�ļ��ɹ���" << endl;
        }
        
        for (int i = 0; i < this->object_num; i++)          //����Ϣ¼��Object_Information.txt�ļ���
        {
            file << this->object_arr[i]->object_name << " " << this->object_arr[i]->month << " " 
            << this->object_arr[i]->date << " " << this->object_arr[i]->hour << " " << 
            this->object_arr[i]->minute << " " << this->object_arr[i]->Get_Lost_or_Found() << " "
            << this->object_arr[i]->place << " " << this->object_arr[i]->people_name << " " << this->object_arr[i]->Phone_Number
            << '\n';
        }
        file.close();   //�ر��ļ�
    }

    int Check_Object_Num()      //ͨ����¼�����ķ�����¼��Ʒ��������ʼ����Ʒ������
    {
        File_is_Empty = false;
        fstream file;
        char c; 
        int line_num = 0;
        file.open("Object_Information.txt", ios::in);
        while (file.get(c)) 
        {
            if (c == '\n')      //����������ַ�Ϊ���з��������ͼ�һ
            {
                line_num++;
            }
            
        }
        file.close();
        return line_num;
    } 

    void init_Object()          //��ʼ����Ʒ�ĺ���
    {
        fstream file;
        file.open("Object_Information.txt", ios::in);
        string o_name, state, o_place, p_name, phone;
        int m = 0, d = 0, h = 0, mi = 0;
        int temp = 0;   //��ʱ�±�
        //������
        while (file >> o_name && file >> m && file >> d && file >> h && file >> mi && file >> state && file >> o_place && file >> p_name && file >> phone)
        {
            Object *object = NULL;
            if (state == "ʧ��")
            {
                object = new Lost(o_name, p_name, m, d, h, mi, o_place, phone);
            }
            else if (state == "ʰ��")
            {
                object = new Found(o_name, p_name, m, d, h, mi, o_place, phone);
            }
            this->object_arr[temp] = object;    //���ļ������ݼ��ص�������
            temp++;
        }
        file.close();
    }

    void Show_Object_Info()     //��ʾ��Ʒ��Ϣ�ĺ���
    {
        if (this->File_is_Empty)        //�ж��ļ��Ƿ�Ϊ��
        {
            cout << "�ļ���δ���������������ݣ�" << endl;
        }
        else
        {
            for (int i = 0; i < this->object_num; i++)
            {
                this->object_arr[i]->Show_Infomation();     //���ö�̬���ú���
                //Ϊʲô���Է���Show_Infomation()����
                //Object��Lost/Found(��д),����̳и���ĺ���������object_arr�еĳ�Ա����Ա��Lost/Found���Ϳɷ���Show_Infomation()
            }
            
        }
        
    }

    int If_Object_is_Exist(string name)   //�ж���Ʒ�Ƿ���ڣ����û�������Ʒʱ���õ��˺����������ھͷ���������±�
    {
        int Xia_Biao = -1;  //����Ʒ�����ھͷ����±�-1���ú���ǿ��ֹͣ
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

    void Take_Object()      //������Ʒ����
    {
        if (this->File_is_Empty)
        {
            cout << "�ļ���δ���������ļ������ݣ�" << endl;
        }
        else
        {
            cout << "������Ҫ�������Ʒ���ƣ�";
            string name, p_name;        //��Ʒ���ƣ�����������
            cin >> name;
            int Xia_Biao = this->If_Object_is_Exist(name);  //��ȡ����Ʒ�������е��±�
            if (Xia_Biao != -1)                             //�ҵ���Ʒ
            {
                cout << "���ҵ�����Ʒ��"  << endl;
                cout << "��������������ɣ�" << endl;
                cin >> p_name;  //��¼�����˵�����
                this->object_arr[Xia_Biao]->object_name += "(������,����������Ϊ��" + p_name + ")";     //����Ʒ�����޸�Ϊ�˸�ʽ
                this->SaveObject();             
                cout << "����ɹ���" << endl;
            }
            else
            {
                cout << "�鲻������Ʒ......" << endl;
            }
            
        }
    }

    void Find_Object()      //������Ʒ
    {
        if (this->File_is_Empty)
        {
            cout << "�ļ���δ�������ļ�Ϊ�գ�" << endl;
        }
        else
        {
            cout << "��ѡ����ҷ�ʽ��" << endl;
            cout << "1.������Ʒ���Ʋ���" << endl;
            cout << "2.�����ڲ���" << endl;
            cout << "3.��ʧ����񵽶������˵����ֲ���" << endl;
            int xuanze = 0;
            cout << "����ѡ��";
            cin >> xuanze;
            if (xuanze == 1)
            {
                string o_name;
                cout << "�������������Ʒ�����ƣ�";
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
                    cout << "�Ҳ�������Ʒ�����Ʒ�ѱ����죡" << endl;
                }
                else
                {
                    cout << "���ҵ�����Ʒ��" << endl;
                }
                
            }
            else if (xuanze == 2)
            {
                cout << "1.�鿴һ���µ�������Ʒ" << endl;
                cout << "2.�����ʱ��(�¡���)����Ʒ" << endl;
                int xuanze2 = 0;
                cout << "����ѡ��";
                cin >> xuanze2;
                if (xuanze2 == 1)
                {
                    int m = 0;
                    cout << "������������ҵ��·ݣ�";
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
                        cout << "��������Ʒ��ʧ......" << endl;
                    }
                    else
                    {
                        cout << "����ʾ" << m << "�·����еĹ�ʧ��Ʒ"  << endl;
                    }
                    
                }
                else if (xuanze2 == 2)
                {
                    int m = 0, d= 0;
                    cout << "�������·ݣ�";
                    cin >> m;
                    cout << "�������գ�";
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
                        cout << "��������Ʒ��ʧ......" << endl;
                    }
                    else
                    {
                        cout << "����ʾ" << m << "��" << d << "�����еĹ�ʧ��Ʒ"  << endl;
                    }
                }
                
            }
            else if (xuanze == 3)
            {
                string p_name;
                cout << "������������" << endl;
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
                    cout << "���޴��ˣ�" << endl;
                }
                else
                {
                    cout << "����ʾ��������ʧ��������Ʒ��Ϣ��" << endl;
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