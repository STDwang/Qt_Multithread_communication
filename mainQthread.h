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
	//�����߳������ǵ����ݣ��������ݿ�
	void getNewSate(QVariantList);
	//�����߳���Ŀ������ݣ��������ݿ�
	void getNewMb(QVariantList);
	//�����߳��������ǹ켣�����ļ�
	void createSatesGJ(QVariantList, bool);
	//�����߳�����Ŀ��켣�����ļ�
	void createMbGJ(QVariantList, bool);
	//�����߳�Ҫ����Ŀ�����ݣ����̴߳����ݿ������ݷ���
	void getData();
	//�����߳̽��м���
	void allTask();

private slots:
	//����ת�������߳�--������ת�����ã������м���
	void getNewSateForward();
	void getNewMbForward();
	void createSatesGJForward();
	void createMbGJForward();
	void getDataForward();
	void allTaskForward();

	//���̷߳��ص�����Ŀ������
	void getDataOut(QVariantList satesList, int satesLen,
					QVariantList mbList, int mbLen,
					QVariantList moduList, int moduLen);
	//��������
	void test(QString);

private:
    Ui::mainQthreadClass ui;
	sonThread *son1;
};
