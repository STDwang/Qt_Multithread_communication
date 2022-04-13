#include "work.h"
#include <qthread.h>
Work::Work(QObject *parent) : QObject(parent)
{

}


//卫星目标数据，数据库拿数据返回给主线程
void Work::getDataSon1() {
	QVariantList a, b, c;
	int a1, b1, c1;
	emit getDataOutSon1(a, a1, b, b1, c, c1);
}

//新卫星的数据，填入数据库
void Work::getNewSateSon1(QVariantList data) {
	//写数据库
	for (int i = 0; i < data.size(); i++) {
		satesLibrary tempSate = data[i].value<satesLibrary>();
		qDebug() << tempSate.name;
	}
	qDebug() << "新卫星已填入数据库";
}

//新目标的数据，填入数据库
void Work::getNewMbSon1(QVariantList data) {
	//写数据库
	for (int i = 0; i < data.size(); i++) {
		mbLibrary tempSate = data[i].value<mbLibrary>();
		qDebug() << tempSate.name;
	}
	qDebug() << "新目标已填入数据库";
}
//生成卫星轨迹保存文件
void Work::createSatesGJSon1(QVariantList data, bool tp) {
	//计算生成文件
	QThread::sleep(10);
	//for (int i = 0; i < data.size(); i++) {
	//	satesLibrary tempSate = data[i].value<satesLibrary>();
	//	qDebug() << tempSate.name;
	//}
	qDebug() << "卫星轨迹已生成";
}

//生成目标轨迹保存文件
void Work::createMbGJSon1(QVariantList data, bool tu) {
	//计算生成文件
	for (int i = 0; i < data.size(); i++) {
		mbLibrary tempSate = data[i].value<mbLibrary>();
		qDebug() << tempSate.name;
	}
	qDebug() << "目标轨迹已生成";
}

//进行计算
void Work::allTaskSon1() {
	//计算任务
	qDebug() << "计算任务已完成";
}