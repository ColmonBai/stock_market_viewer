#pragma once
#include <QtCore>    
#include <QtNetwork/QtNetwork>
#include <QPixmap>


class SinaFinanceAPI
{
public:
	SinaFinanceAPI(void);
	~SinaFinanceAPI(void);
	//从指定api地址获取信息
	void requestStockInfo(QString urlStr);
    void downloadFromUrl(QString urlStr);
    //取出对象
    QString getStockInfoString(){return m_stockInfo;}
    QPixmap getPic(){return m_pixmap;};
    //写入文件
	void writeFile(QString filename);
private:
	QString m_stockInfo;
	QString m_URL;
    QPixmap m_pixmap;
};
