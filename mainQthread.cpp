#include "mainQthread.h"

mainQthread::mainQthread(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
	//����connectǰ����ʵ����  
	son1 = new sonThread();

	//��������-�����߳�
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(createSatesGJForward()));
	connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(createMbGJForward()));
	connect(ui.pushButton_4, SIGNAL(clicked()), this, SLOT(getNewSateForward()));
	connect(ui.pushButton_5, SIGNAL(clicked()), this, SLOT(getNewMbForward()));
	connect(ui.pushButton_6, SIGNAL(clicked()), this, SLOT(getDataForward()));
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(allTaskForward()));

	//���߳�����-�����߳�
	connect(this, SIGNAL(createSatesGJ(QVariantList, bool)), son1, SLOT(createSatesGJSon1(QVariantList, bool)));
	connect(this, SIGNAL(createMbGJ(QVariantList, bool)), son1, SLOT(createMbGJSon1(QVariantList, bool)));
	connect(this, SIGNAL(getNewSate(QVariantList)), son1, SLOT(getNewSateSon1(QVariantList)));
	connect(this, SIGNAL(getNewMb(QVariantList)), son1, SLOT(getNewMbSon1(QVariantList)));
	connect(this, SIGNAL(getData()), son1, SLOT(getDataSon1()));
	connect(this, SIGNAL(allTask()), son1, SLOT(allTaskSon1()));

	//���߳�����-�����߳�-������
	connect(son1, SIGNAL(testSon1(QString)), this, SLOT(test(QString)));
	connect(son1, SIGNAL(getDataOutSon1(QVariantList, int, QVariantList, int, QVariantList, int)),
			this, SLOT(getDataOut(QVariantList, int, QVariantList, int, QVariantList, int)));

	//ִ�����߳�  
	son1->start();
}
//������ת��
void mainQthread::getNewSateForward() {
	//�����̷߳��źţ�����ת�������߳�
	QVariantList data;
	for (int i = 0; i < 10; i++) {
		satesLibrary sate("����1", 50, 1, 60, 50);
		QVariant tempSate;
		tempSate.setValue(sate);
		data.append(tempSate);
	}
	emit getNewSate(data);
}

void mainQthread::getNewMbForward() {
	//�����̷߳��źţ�����ת�������߳�
	QVariantList data;
	for (int i = 0; i < 10; i++) {
		mbLibrary mb("Ŀ��1", 30, 50, 40, 20, 20, 20, 1, 60, "BPSK", 20, 30, 1, 20, 60, 50, 40, 50);
		QVariant tempMb;
		tempMb.setValue(mb);
		data.append(tempMb);
	}
	emit getNewMb(data);
}

void mainQthread::createSatesGJForward() {
	//�����̷߳��źţ�����ת�������߳�
	QVariantList data;
	for (int i = 0; i < 10; i++) {
		satesLibrary sate("����1", 50, 1, 60, 50);
		QVariant tempSate;
		tempSate.setValue(sate);
		data.append(tempSate);
	}
	bool tp = false;
	emit createSatesGJ(data, tp);
}

void mainQthread::createMbGJForward() {
	//�����̷߳��źţ�����ת�������߳�
	QVariantList data;
	for (int i = 0; i < 10; i++) {
		mbLibrary mb("Ŀ��1", 30, 50, 40, 20, 20, 20, 1, 60, "BPSK", 20, 30, 1, 20, 60, 50, 40, 50);
		QVariant tempMb;
		tempMb.setValue(mb);
		data.append(tempMb);
	}
	bool tu = true;
	emit createMbGJ(data, true);
}

void mainQthread::getDataForward() {
	//�����̷߳��ź�
	emit getData();
}

void mainQthread::allTaskForward() {
	//�����̷߳��ź�
	emit allTask();
}

void mainQthread::test(QString s)
{
	//���������߳�ֱ�ӷ�����
	qDebug() << s;
}

void mainQthread::getDataOut(QVariantList, int, QVariantList, int, QVariantList, int)
{
	//���̷߳���������
	qDebug() << "���̷߳���������";
}