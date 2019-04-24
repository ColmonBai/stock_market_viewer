#pragma once
#include <QString>
#include <QMap>

class ViewerContent
{
public:
	ViewerContent(void);
	~ViewerContent(void);
	//通过新浪API生成content的数据
	void SetFromSinaAPI(QString urlStr);

	QString get_stockCode(){return m_stockCode;}
	QString get_stockName(){return m_stockName;}
	QString get_time(){return m_time;}
	QString get_date(){return m_date;}

	QString get_openingPrice(){return m_openingPrice;}
	QString get_current(){return m_current;}
	QString get_amount(){return m_amount;}
	QString get_turnover(){return m_turnover;}
	QString get_min(){return m_min;}
	QString get_max(){return m_max;}
	QString get_risingStopPrice(){return m_risingStopPrice;}
	QString get_droppingStopPrice(){return m_droppingStopPrice;}
	QString get_buyPrice(){return m_buyPrice;}
	QString get_sellPrice(){return m_sellPrice;}

	QMap<QString, QString> get_buyMap(){return m_buyMap;}
	QMap<QString, QString> get_sellMap(){return m_sellMap;}
private:
	QString m_stockCode;
	QString m_stockName;
	QString m_time;
	QString m_date;

	QString m_openingPrice;
	QString m_current;
	QString m_amount;
	QString m_turnover;
	QString m_min;
	QString m_max;
	QString m_risingStopPrice;
	QString m_droppingStopPrice;

	QString m_buyPrice;
	QString m_sellPrice;

	QMap<QString,QString> m_buyMap;
	QMap<QString,QString> m_sellMap;
	
};
