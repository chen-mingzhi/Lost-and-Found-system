#pragma once
#include<iostream>
#include<string>
using namespace std;

class Object
{
public:
    string object_name;                         //��Ʒ����
    string people_name;                         //ʧ����񵽶������˵�����
    string Phone_Number;                        //ʧ����񵽶������˵���ϵ��ʽ
    string place;                               //��ʧ��񵽶����ĵص�
    int month, date, hour, minute;              //��ʧ�����Ʒ��ʱ��
    virtual void Show_Infomation() = 0;             //��ʾ��Ʒ��Ϣ
    virtual string Get_Lost_or_Found() = 0;         //��ʾ��ʧ�ﻹ��ʰ��
    ~Object(){}
};
