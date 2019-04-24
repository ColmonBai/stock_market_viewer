#pragma once
#include <QtCore>    
#include <QtNetwork/QtNetwork>

class SinaFinanceAPI
{
public:
	SinaFinanceAPI(void);
	~SinaFinanceAPI(void);
	//从指定api地址获取信息
	void requestStockInfo(QString urlStr);
	//输出字符串
	QString getStockInfoString();
	//写入文件
	void writeFile(QString filename);
private:
	QString m_stockInfo;
	QString m_URL;
};
