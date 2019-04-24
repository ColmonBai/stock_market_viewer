#ifndef VIEWER_H
#define VIEWER_H

#include <QtWidgets/QMainWindow>
#include <QPixmap>
#include "ui_viewer.h"
#include "ViewerContent.h"

class Viewer : public QMainWindow
{
	Q_OBJECT

public:
    Viewer(QWidget *parent = 0, Qt::WindowFlags flags = 0);
	~Viewer();
	//更新窗口
	void updateViewer(ViewerContent vct);

public slots:
	//接受更新窗口信号 并且判断非法输入
	void slot_update();

private:
	Ui::ViewerClass ui;
             
};

#endif // VIEWER_H
