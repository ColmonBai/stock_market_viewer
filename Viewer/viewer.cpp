#include "viewer.h"
#include "ViewerContent.h"

#include <QDebug>
#include <QMessageBox>

Viewer::Viewer(QWidget *parent, Qt::WindowFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);


	this->setWindowIcon(QIcon(":Viewer/img/main_logo.ico"));  //设置窗口图标
	
	//可以在输入框回车 和 点击查询按钮 查询行情信息
	connect( ui.stockIineEdit, SIGNAL( returnPressed() ), 
		this, SLOT( slot_update() ) );
	connect( ui.checkPushButton, SIGNAL( clicked() ), 
		this, SLOT( slot_update()));
	//设置买卖窗口不可编辑
	ui.buyTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.sellTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

Viewer::~Viewer()
{

}
//更新信息的槽函数
void Viewer::slot_update()
{
	//使用正则表达式检测非法输入
	QString tailSTR=ui.stockIineEdit->text();
	QRegExp rx("[0-9]{6}");
	int pos = tailSTR.indexOf(rx);

	qDebug()<<pos;
	if(pos<0)
	{
	qDebug("invaild input.");
	//检查是否输入有效股票代码
    QString dlgTitle="输入无效";
    QString strInfo="请输入含有股票代码的字符串";
    QMessageBox::warning(this, dlgTitle, strInfo);

		return;
	}

	QString symbol = tailSTR.mid(pos,6);
    //qDebug(symbol);

	QString URLSTR = "http://hq.sinajs.cn/list=sh"+symbol;
	ViewerContent vct;
	vct.SetFromSinaAPI(URLSTR);
	this->updateViewer(vct);

}
//使用ViewerContent对象更新窗口内容
void Viewer::updateViewer(ViewerContent vct)
{
	qDebug("Update viewer.");
	//设置标题
	this->setWindowTitle(
        //vct.get_stockName()
		+" "+vct.get_stockCode()
		+" "+vct.get_time()
		+" "+vct.get_date());
	//设置标签
	ui.openingPriceValueLabel->setText(vct.get_openingPrice());
	ui.currentValueLabel->setText(vct.get_current());
	ui.amountValueLabel->setText(vct.get_amount());
	ui.turnoverValueLabel->setText(vct.get_turnover());
	ui.minValueLabel->setText(vct.get_min());
	ui.maxValueLabel->setText(vct.get_max());
	ui.risingStopPriceValueLabel->setText(vct.get_risingStopPrice());
	ui.droppingStopPriceValueLabel->setText(vct.get_droppingStopPrice());
	ui.maxBuyLabel->setText(vct.get_buyPrice());
	ui.minSellLabel->setText(vct.get_sellPrice());
	//ui.maxBuyLabel->setText();

	//买方表格
	ui.buyTableWidget->setColumnCount(2);
	ui.buyTableWidget->setRowCount(5);

	ui.buyTableWidget->horizontalHeader()->setStretchLastSection(true);

	QStringList header;
	header<<tr("价格")<<tr("数量");
	ui.buyTableWidget->setHorizontalHeaderLabels(header);

	int cnt = 0;
	QMapIterator<QString, QString> i(vct.get_buyMap());
	i.toBack();
	while(i.hasPrevious()) {
		i.previous();
		ui.buyTableWidget->setItem(cnt,0,new QTableWidgetItem(i.key()));
		ui.buyTableWidget->setItem(cnt,1,new QTableWidgetItem(i.value()));
		cnt++;
	}

	//卖方表格
	ui.sellTableWidget->setColumnCount(2);
	ui.sellTableWidget->setRowCount(5);
	ui.sellTableWidget->horizontalHeader()->setStretchLastSection(true);


	ui.sellTableWidget->setHorizontalHeaderLabels(header);
	
	cnt = 0;
	QMapIterator<QString, QString> j(vct.get_sellMap());
	while(j.hasNext()) {
		j.next();
		ui.sellTableWidget->setItem(cnt,0,new QTableWidgetItem(j.key()));
		ui.sellTableWidget->setItem(cnt,1,new QTableWidgetItem(j.value()));
		cnt++;
	}

    QPixmap pixmap;
    pixmap = vct.get_timeLinePixmap();
    pixmap.scaled(ui.timeLineLabel->size(), Qt::KeepAspectRatio);
    ui.timeLineLabel->setScaledContents(true);
    ui.timeLineLabel->setPixmap(pixmap);

    pixmap = vct.get_dayKLinePixmap();
    pixmap.scaled(ui.dayKLineLabel->size(), Qt::KeepAspectRatio);
    ui.dayKLineLabel->setScaledContents(true);
    ui.dayKLineLabel->setPixmap(pixmap);

}
