#include<QtWidgets/QApplication>

#include "viewer.h"
#include "ViewerContent.h"

//默认使用浦发银行sh600000打开界面
const QString testURL = "http://hq.sinajs.cn/list=sh600000";

int main(int argc, char *argv[])
{

	QApplication a(argc, argv);
	ViewerContent vct;
	vct.SetFromSinaAPI(testURL);

    Viewer w;
	w.updateViewer(vct);

	w.show();
	return a.exec();

}
