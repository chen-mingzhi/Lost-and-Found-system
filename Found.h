#pragma once
#include<iostream>
#include"Object.h"
using namespace std;

class Found:public Object
{
public:
    Found(string object_name, string people_name, int month, int date, int hour, int minute, string place, string Phone_Number)
    {
        this->object_name = object_name;
        this->people_name = people_name;
        this->month = month;
        this->date = date;
        this->hour = hour;
        this->minute = minute;
        this->place = place;
        this->Phone_Number = Phone_Number;
    }

    string Get_Lost_or_Found()
    {
        return "拾物";
    }

    void Show_Infomation()
    {
        cout << "物品名称：" << this->object_name << endl;
        cout << "失物还是拾物：" << this->Get_Lost_or_Found() << endl;
        cout << "捡到的地点：" << this->place << endl;
        cout << "捡到的时间：" << "年" << this->month << "月" << this->date << "日" ;
        cout << this->hour << "时" << this->minute << "分" << endl;
        cout << "拾物者名字：" << this->people_name << endl;
        cout << "拾物者联系电话：" << this->Phone_Number << endl << endl;
    }
    
    ~Found(){}
};

/***
 *               ii.                                         ;9ABH,          
 *              SA391,                                    .r9GG35&G          
 *              &#ii13Gh;                               i3X31i;:,rB1         
 *              iMs,:,i5895,                         .5G91:,:;:s1:8A         
 *               33::::,,;5G5,                     ,58Si,,:::,sHX;iH1        
 *                Sr.,:;rs13BBX35hh11511h5Shhh5S3GAXS:.,,::,,1AG3i,GG        
 *                .G51S511sr;;iiiishS8G89Shsrrsh59S;.,,,,,..5A85Si,h8        
 *               :SB9s:,............................,,,.,,,SASh53h,1G.       
 *            .r18S;..,,,,,,,,,,,,,,,,,,,,,,,,,,,,,....,,.1H315199,rX,       
 *          ;S89s,..,,,,,,,,,,,,,,,,,,,,,,,....,,.......,,,;r1ShS8,;Xi       
 *        i55s:.........,,,,,,,,,,,,,,,,.,,,......,.....,,....r9&5.:X1       
 *       59;.....,.     .,,,,,,,,,,,...        .............,..:1;.:&s       
 *      s8,..;53S5S3s.   .,,,,,,,.,..      i15S5h1:.........,,,..,,:99       
 *      93.:39s:rSGB@A;  ..,,,,.....    .SG3hhh9G&BGi..,,,,,,,,,,,,.,83      
 *      G5.G8  9#@@@@@X. .,,,,,,.....  iA9,.S&B###@@Mr...,,,,,,,,..,.;Xh     
 *      Gs.X8 S@@@@@@@B:..,,,,,,,,,,. rA1 ,A@@@@@@@@@H:........,,,,,,.iX:    
 *     ;9. ,8A#@@@@@@#5,.,,,,,,,,,... 9A. 8@@@@@@@@@@M;    ....,,,,,,,,S8    
 *     X3    iS8XAHH8s.,,,,,,,,,,...,..58hH@@@@@@@@@Hs       ...,,,,,,,:Gs   
 *    r8,        ,,,...,,,,,,,,,,.....  ,h8XABMMHX3r.          .,,,,,,,.rX:  
 *   :9, .    .:,..,:;;;::,.,,,,,..          .,,.               ..,,,,,,.59  
 *  .Si      ,:.i8HBMMMMMB&5,....                    .            .,,,,,.sMr
 *  SS       :: h@@@@@@@@@@#; .                     ...  .         ..,,,,iM5
 *  91  .    ;:.,1&@@@@@@MXs.                            .          .,,:,:&S
 *  hS ....  .:;,,,i3MMS1;..,..... .  .     ...                     ..,:,.99
 *  ,8; ..... .,:,..,8Ms:;,,,...                                     .,::.83
 *   s&: ....  .sS553B@@HX3s;,.    .,;13h.                            .:::&1
 *    SXr  .  ...;s3G99XA&X88Shss11155hi.                             ,;:h&,
 *     iH8:  . ..   ,;iiii;,::,,,,,.                                 .;irHA  
 *      ,8X5;   .     .......                                       ,;iihS8Gi
 *         1831,                                                 .,;irrrrrs&@
 *           ;5A8r.                                            .:;iiiiirrss1H
 *             :X@H3s.......                                .,:;iii;iiiiirsrh
 *              r#h:;,...,,.. .,,:;;;;;:::,...              .:;;;;;;iiiirrss1
 *             ,M8 ..,....,.....,,::::::,,...         .     .,;;;iiiiiirss11h
 *             8B;.,,,,,,,.,.....          .           ..   .:;;;;iirrsss111h
 *            i@5,:::,,,,,,,,.... .                   . .:::;;;;;irrrss111111
 *            9Bi,:,,,,......                        ..r91;;;;;iirrsss1ss1111
 */