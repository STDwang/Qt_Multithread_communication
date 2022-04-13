#include "mainQthread.h"

mainQthread::mainQthread(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
	//You must instantiate before you connect
	//进行connect前必须实例化  
	workThread = new QThread;
	work = new Work();
	work->moveToThread(workThread);

	// Interface data -》 main thread
	//界面数据-》主线程
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(createSatesGJForward()));
	connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(createMbGJForward()));
	connect(ui.pushButton_4, SIGNAL(clicked()), this, SLOT(getNewSateForward()));
	connect(ui.pushButton_5, SIGNAL(clicked()), this, SLOT(getNewMbForward()));
	connect(ui.pushButton_6, SIGNAL(clicked()), this, SLOT(getDataForward()));
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(allTaskForward()));

	//Main thread data -》subthread
	//主线程数据-》子线程
	connect(this, SIGNAL(createSatesGJ(QVariantList, bool)), work, SLOT(createSatesGJSon1(QVariantList, bool)));
	connect(this, SIGNAL(createMbGJ(QVariantList, bool)), work, SLOT(createMbGJSon1(QVariantList, bool)));
	connect(this, SIGNAL(getNewSate(QVariantList)), work, SLOT(getNewSateSon1(QVariantList)));
	connect(this, SIGNAL(getNewMb(QVariantList)), work, SLOT(getNewMbSon1(QVariantList)));
	connect(this, SIGNAL(getData()), work, SLOT(getDataSon1()));
	connect(this, SIGNAL(allTask()), work, SLOT(allTaskSon1()));

	//Subthread data -》main thread -》interface
	//子线程数据-》主线程-》界面
	connect(work, SIGNAL(testSon1(QString)), this, SLOT(test(QString)));
	connect(work, SIGNAL(getDataOutSon1(QVariantList, int, QVariantList, int, QVariantList, int)),
			this, SLOT(getDataOut(QVariantList, int, QVariantList, int, QVariantList, int)));
 
	workThread->start();
}
//将数据转发
void mainQthread::getNewSateForward() {
	//向子线程发信号，数据转发给子线程
	QVariantList data;
	for (int i = 0; i < 10; i++) {
		satesLibrary sate("卫星1", 50, 1, 60, 50);
		QVariant tempSate;
		tempSate.setValue(sate);
		data.append(tempSate);
	}
	emit getNewSate(data);
}

void mainQthread::getNewMbForward() {
	//向子线程发信号，数据转发给子线程
	QVariantList data;
	for (int i = 0; i < 10; i++) {
		mbLibrary mb("目标1", 30, 50, 40, 20, 20, 20, 1, 60, "BPSK", 20, 30, 1, 20, 60, 50, 40, 50);
		QVariant tempMb;
		tempMb.setValue(mb);
		data.append(tempMb);
	}
	emit getNewMb(data);
}

void mainQthread::createSatesGJForward() {
	//向子线程发信号，数据转发给子线程
	QVariantList data;
	for (int i = 0; i < 10; i++) {
		satesLibrary sate("卫星1", 50, 1, 60, 50);
		QVariant tempSate;
		tempSate.setValue(sate);
		data.append(tempSate);
	}
	bool tp = false;
	emit createSatesGJ(data, tp);
}

void mainQthread::createMbGJForward() {
	//向子线程发信号，数据转发给子线程
	QVariantList data;
	for (int i = 0; i < 10; i++) {
		mbLibrary mb("目标1", 30, 50, 40, 20, 20, 20, 1, 60, "BPSK", 20, 30, 1, 20, 60, 50, 40, 50);
		QVariant tempMb;
		tempMb.setValue(mb);
		data.append(tempMb);
	}
	bool tu = true;
	emit createMbGJ(data, true);
}

void mainQthread::getDataForward() {
	//向子线程发信号
	emit getData();
}

void mainQthread::allTaskForward() {
	//向子线程发信号
	emit allTask();
}

void mainQthread::test(QString s)
{
	//连接上子线程直接发来的
	qDebug() << s;
}

void mainQthread::getDataOut(QVariantList, int, QVariantList, int, QVariantList, int)
{
	//子线程发来的数据
	qDebug() << "子线程发来了数据";
}