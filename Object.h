#pragma once
#include<iostream>
#include<string>
using namespace std;

class Object
{
public:
    string object_name;                         //物品名称
    string people_name;                         //失主或捡到东西的人的名字
    string Phone_Number;                        //失主或捡到东西的人的联系方式
    string place;                               //丢失或捡到东西的地点
    int month, date, hour, minute;              //丢失或捡到物品的时间
    virtual void Show_Infomation() = 0;             //显示物品信息
    virtual string Get_Lost_or_Found() = 0;         //表示是失物还是拾物
    ~Object(){}
};
