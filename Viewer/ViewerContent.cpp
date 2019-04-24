#include "ViewerContent.h"
#include "SinaFinanceAPI.h"

#include <QtCore>   
#include <QTextCodec>

#include <iostream>  
#include <string>  
#include <vector>  
#include <fstream>  
#include <sstream> 
using namespace std;

ViewerContent::ViewerContent(void)
{
}

ViewerContent::~ViewerContent(void)
{
}
//使用新浪API提供的csv格式的字符串更新生成ViewerContent对象
void ViewerContent::SetFromSinaAPI(QString urlStr)
{
	qDebug("Set viewer content from SinaAPI.");
	SinaFinanceAPI sfAPI;
	sfAPI.requestStockInfo(urlStr);
	QString stockInfo = sfAPI.getStockInfoString();


	m_stockCode=stockInfo.mid(11, 8);
	m_stockName=stockInfo.mid(21, 4);
    qDebug()<<m_stockName;

    char*  ch;
    QByteArray ba = m_stockName.toLatin1(); // must
    ch=ba.data();
    std::cout<<"Name str: "<< ch<<endl;
    std::printf("%d\n",ch);

	m_openingPrice=stockInfo.section(',',1,1);
	m_current=stockInfo.section(',',3,3);
	m_amount=stockInfo.section(',',8,8);
	//交易量 精度为整数
	m_turnover=stockInfo.section(',',9,9).section('.',0,0);
	m_max=stockInfo.section(',',4,4);
	m_min=stockInfo.section(',',5,5);
	//涨停价 和 跌停价
	double yesterday=stockInfo.section(',',2,2).toDouble();
	double risingStopPrice = yesterday*1.1;
	double droppingStopPrice = yesterday*0.9;
	m_risingStopPrice=QString::number(risingStopPrice, 10, 2);
	m_droppingStopPrice=QString::number(droppingStopPrice, 10, 2);


	m_buyPrice=stockInfo.section(',',6,6);
	m_sellPrice=stockInfo.section(',',7,7);

	m_date=stockInfo.section(',',30,30);
	m_time=stockInfo.section(',',31,31);

	m_buyMap.insert(stockInfo.section(',',11,11),stockInfo.section(',',10,10));
	m_buyMap.insert(stockInfo.section(',',13,13),stockInfo.section(',',12,12));
	m_buyMap.insert(stockInfo.section(',',15,15),stockInfo.section(',',14,14));
	m_buyMap.insert(stockInfo.section(',',17,17),stockInfo.section(',',16,16));
	m_buyMap.insert(stockInfo.section(',',19,19),stockInfo.section(',',18,18));

	m_sellMap.insert(stockInfo.section(',',21,21),stockInfo.section(',',20,20));
	m_sellMap.insert(stockInfo.section(',',23,23),stockInfo.section(',',22,22));
	m_sellMap.insert(stockInfo.section(',',25,25),stockInfo.section(',',24,24));
	m_sellMap.insert(stockInfo.section(',',27,27),stockInfo.section(',',26,26));
	m_sellMap.insert(stockInfo.section(',',29,29),stockInfo.section(',',28,28));
}
