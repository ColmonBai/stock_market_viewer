#include <QtCore>    
#include <QtNetwork/QtNetwork>

#include "SinaFinanceAPI.h"
#include <iostream>

SinaFinanceAPI::SinaFinanceAPI(void)
{
}

SinaFinanceAPI::~SinaFinanceAPI(void)
{
}
//从指定api地址获取信息csv格式的字符串
void SinaFinanceAPI::requestStockInfo(QString urlStr)
{
	QUrl url(urlStr);    
    QNetworkAccessManager manager;    
    QEventLoop loop;    
    QNetworkReply *reply;  
   
    qDebug() << "Reading html code form " << urlStr;    
    reply = manager.get(QNetworkRequest(url));    
    //请求结束并下载完成后，退出子事件循环    
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));    
    //开启子事件循环    
    loop.exec();  
	QString codeContent = reply->readAll();  

   // QTextCodec *codec;
   // codec = QTextCodec::codecForHtml(codeContent.toLocal8Bit());
   // codeContent = codec->toUnicode(codeContent.toLocal8Bit());

    //qDebug()<<codeContent;
    //std::cout<<m_stockInfo.data();
	m_stockInfo = codeContent;
}
//输出字符串
QString SinaFinanceAPI::getStockInfoString()
{
	return m_stockInfo;
}
//写入文件
void SinaFinanceAPI::writeFile(QString filename)
{
}
