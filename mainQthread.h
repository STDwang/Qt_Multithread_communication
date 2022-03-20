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
	//�����߳������ǵ����ݣ��������ݿ�
	void getNewSate(QVariantList);
	//Fill the database with the new target data for the child thread
	//�����߳���Ŀ������ݣ��������ݿ�
	void getNewMb(QVariantList);
	//Let the child thread generate the satellite track to save the file
	//�����߳��������ǹ켣�����ļ�
	void createSatesGJ(QVariantList, bool);
	//Let the child thread generate the target trace to save the file
	//�����߳�����Ŀ��켣�����ļ�
	void createMbGJ(QVariantList, bool);
	//Satellite target data is requested from the subthread, which takes the data from the database and returns it
	//�����߳�Ҫ����Ŀ�����ݣ����̴߳����ݿ������ݷ���
	void getData();
	//Let the child thread do the calculation
	//�����߳̽��м���
	void allTask();

private slots:
	//Data is forwarded to the child thread -- only for forwarding purposes, not for calculation
	//����ת�������߳�--������ת�����ã������м���
	void getNewSateForward();
	void getNewMbForward();
	void createSatesGJForward();
	void createMbGJForward();
	void getDataForward();
	void allTaskForward();

	//The satellite target data returned by the child thread
	//���̷߳��ص�����Ŀ������
	void getDataOut(QVariantList satesList, int satesLen,
					QVariantList mbList, int mbLen,
					QVariantList moduList, int moduLen);

	//Test Connection
	//��������
	void test(QString);

private:
    Ui::mainQthreadClass ui;
	sonThread *son1;
};
