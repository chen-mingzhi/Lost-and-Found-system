#pragma once
#include<iostream>
#include"Object.h"
using namespace std;

class Lost:public Object
{
public:
    Lost(string object_name, string people_name, int month, int date, int hour, int minute, string place, string Phone_Number)
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
        return "失物";
    }

    void Show_Infomation()
    {
        cout << "物品名称：" << this->object_name << endl;
        cout << "失物还是拾物：" << this->Get_Lost_or_Found() << endl;
        cout << "丢失的地点：" << this->place << endl;
        cout << "丢失的时间：" << this->month << "月" << this->date << "日" ;
        cout << this->hour << "时" << this->minute << "分" << endl;
        cout << "物主名字：" << this->people_name << endl;
        cout << "物主者联系电话：" << this->Phone_Number << endl << endl;
    }
    ~Lost(){}
};
/***                                                                          
 *          .,:,,,                                        .::,,,::.          
 *        .::::,,;;,                                  .,;;:,,....:i:         
 *        :i,.::::,;i:.      ....,,:::::::::,....   .;i:,.  ......;i.        
 *        :;..:::;::::i;,,:::;:,,,,,,,,,,..,.,,:::iri:. .,:irsr:,.;i.        
 *        ;;..,::::;;;;ri,,,.                    ..,,:;s1s1ssrr;,.;r,        
 *        :;. ,::;ii;:,     . ...................     .;iirri;;;,,;i,        
 *        ,i. .;ri:.   ... ............................  .,,:;:,,,;i:        
 *        :s,.;r:... ....................................... .::;::s;        
 *        ,1r::. .............,,,.,,:,,........................,;iir;        
 *        ,s;...........     ..::.,;:,,.          ...............,;1s        
 *       :i,..,.              .,:,,::,.          .......... .......;1,       
 *      ir,....:rrssr;:,       ,,.,::.     .r5S9989398G95hr;. ....,.:s,      
 *     ;r,..,s9855513XHAG3i   .,,,,,,,.  ,S931,.,,.;s;s&BHHA8s.,..,..:r:     
 *    :r;..rGGh,  :SAG;;G@BS:.,,,,,,,,,.r83:      hHH1sXMBHHHM3..,,,,.ir.    
 *   ,si,.1GS,   sBMAAX&MBMB5,,,,,,:,,.:&8       3@HXHBMBHBBH#X,.,,,,,,rr    
 *   ;1:,,SH:   .A@&&B#&8H#BS,,,,,,,,,.,5XS,     3@MHABM&59M#As..,,,,:,is,   
 *  .rr,,,;9&1   hBHHBB&8AMGr,,,,,,,,,,,:h&&9s;   r9&BMHBHMB9:  . .,,,,;ri.  
 *  :1:....:5&XSi;r8BMBHHA9r:,......,,,,:ii19GG88899XHHH&GSr.      ...,:rs.  
 *  ;s.     .:sS8G8GG889hi.        ....,,:;:,.:irssrriii:,.        ...,,i1,  
 *  ;1,         ..,....,,isssi;,        .,,.                      ....,.i1,  
 *  ;h:               i9HHBMBBHAX9:         .                     ...,,,rs,  
 *  ,1i..            :A#MBBBBMHB##s                             ....,,,;si.  
 *  .r1,..        ,..;3BMBBBHBB#Bh.     ..                    ....,,,,,i1;   
 *   :h;..       .,..;,1XBMMMMBXs,.,, .. :: ,.               ....,,,,,,ss.   
 *    ih: ..    .;;;, ;;:s58A3i,..    ,. ,.:,,.             ...,,,,,:,s1,    
 *    .s1,....   .,;sh,  ,iSAXs;.    ,.  ,,.i85            ...,,,,,,:i1;     
 *     .rh: ...     rXG9XBBM#M#MHAX3hss13&&HHXr         .....,,,,,,,ih;      
 *      .s5: .....    i598X&&A&AAAAAA&XG851r:       ........,,,,:,,sh;       
 *      . ihr, ...  .         ..                    ........,,,,,;11:.       
 *         ,s1i. ...  ..,,,..,,,.,,.,,.,..       ........,,.,,.;s5i.         
 *          .:s1r,......................       ..............;shs,           
 *          . .:shr:.  ....                 ..............,ishs.             
 *              .,issr;,... ...........................,is1s;.               
 *                 .,is1si;:,....................,:;ir1sr;,                  
 *                    ..:isssssrrii;::::::;;iirsssssr;:..                    
 *                         .,::iiirsssssssssrri;;:.                      
 */
