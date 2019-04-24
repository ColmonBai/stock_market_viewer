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

	m_stockInfo = codeContent;
}
void SinaFinanceAPI::downloadFromUrl(QString urlStr)
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
    QByteArray bytes = reply->readAll();
    m_pixmap.loadFromData(bytes);

    //QFile file("test.png");
    //if (file.open(QIODevice::Append))
    //{
    //    file.write(bytes);
    //}
    //file.close();

}
//写入文件
void SinaFinanceAPI::writeFile(QString filename)
{
}
