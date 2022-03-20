#pragma once
#pragma execution_character_set("utf-8")
#include <QtWidgets/QWidget>
#include "ui_mainQthread.h"
#include "qdebug.h"
#include "sonThread.h"

class mainQthread : public QWidget
{
    Q_OBJECT

public:
    mainQthread(QWidget *parent = Q_NULLPTR);

signals:
	//给子线程新卫星的数据，填入数据库
	void getNewSate(QVariantList);
	//给子线程新目标的数据，填入数据库
	void getNewMb(QVariantList);
	//让子线程生成卫星轨迹保存文件
	void createSatesGJ(QVariantList, bool);
	//让子线程生成目标轨迹保存文件
	void createMbGJ(QVariantList, bool);
	//向子线程要卫星目标数据，子线程从数据库拿数据返回
	void getData();
	//让子线程进行计算
	void allTask();

private slots:
	//数据转发给子线程--仅仅起转发作用，不进行计算
	void getNewSateForward();
	void getNewMbForward();
	void createSatesGJForward();
	void createMbGJForward();
	void getDataForward();
	void allTaskForward();

	//子线程返回的卫星目标数据
	void getDataOut(QVariantList satesList, int satesLen,
					QVariantList mbList, int mbLen,
					QVariantList moduList, int moduLen);
	//测试连接
	void test(QString);

private:
    Ui::mainQthreadClass ui;
	sonThread *son1;
};
