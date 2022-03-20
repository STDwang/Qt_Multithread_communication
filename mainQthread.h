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
	//Give the child thread the data of the new satellite, fill in the database
	//给子线程新卫星的数据，填入数据库
	void getNewSate(QVariantList);
	//Fill the database with the new target data for the child thread
	//给子线程新目标的数据，填入数据库
	void getNewMb(QVariantList);
	//Let the child thread generate the satellite track to save the file
	//让子线程生成卫星轨迹保存文件
	void createSatesGJ(QVariantList, bool);
	//Let the child thread generate the target trace to save the file
	//让子线程生成目标轨迹保存文件
	void createMbGJ(QVariantList, bool);
	//Satellite target data is requested from the subthread, which takes the data from the database and returns it
	//向子线程要卫星目标数据，子线程从数据库拿数据返回
	void getData();
	//Let the child thread do the calculation
	//让子线程进行计算
	void allTask();

private slots:
	//Data is forwarded to the child thread -- only for forwarding purposes, not for calculation
	//数据转发给子线程--仅仅起转发作用，不进行计算
	void getNewSateForward();
	void getNewMbForward();
	void createSatesGJForward();
	void createMbGJForward();
	void getDataForward();
	void allTaskForward();

	//The satellite target data returned by the child thread
	//子线程返回的卫星目标数据
	void getDataOut(QVariantList satesList, int satesLen,
					QVariantList mbList, int mbLen,
					QVariantList moduList, int moduLen);

	//Test Connection
	//测试连接
	void test(QString);

private:
    Ui::mainQthreadClass ui;
	sonThread *son1;
};
