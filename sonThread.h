#pragma once
#ifndef TESTTHREAD_H  
#define TESTTHREAD_H  
#pragma execution_character_set("utf-8")
#include <QThread> 
#include <QMetaType>
#include <QVariant>
#include "qdebug.h"

struct mbLibrary {
	QString name;
	double longitude;
	double latitude;
	double height;
	double Vx;
	double Vy;
	double Vz;
	double timeStep;
	double numberTimes;

	QString modulation;
	double modulationFrequency;
	double symbolRate;
	double jxT;
	double outputSamplingRate;
	double allTime;
	double tuningFrequency;
	double signalFrequency;
	double snr;

	mbLibrary() {};
	mbLibrary(QString name, double longitude, double latitude, double height, double Vx, double Vy, double Vz, double timeStep, double numberTimes,
		QString modulation, double modulationFrequency, double symbolRate, double jxT, double outputSamplingRate, double allTime, double tuningFrequency, double signalFrequency, double snr) {
		this->name = name;
		this->longitude = longitude;
		this->latitude = latitude;
		this->height = height;
		this->Vx = Vx;
		this->Vy = Vy;
		this->Vz = Vz;
		this->timeStep = timeStep;
		this->numberTimes = numberTimes;
		this->modulation = modulation;
		this->modulationFrequency = modulationFrequency;
		this->symbolRate = symbolRate;
		this->jxT = jxT;
		this->outputSamplingRate = outputSamplingRate;
		this->allTime = allTime;
		this->tuningFrequency = tuningFrequency;
		this->signalFrequency = signalFrequency;
		this->snr = snr;
	}
};

struct satesLibrary {
	QString name;
	double height;
	double timeStep;
	double numberTimes;
	double distance;

	satesLibrary() {};
	satesLibrary(QString name, double height, double timeStep, double numberTimes, double distance) {
		this->name = name;
		this->height = height;
		this->timeStep = timeStep;
		this->numberTimes = numberTimes;
		this->distance = distance;
	}
};

Q_DECLARE_METATYPE(mbLibrary);
Q_DECLARE_METATYPE(satesLibrary);

//工作线程 work thread
class sonThread : public QThread
{
	Q_OBJECT
public:
	explicit sonThread(QObject *parent = 0);

protected:
	void run();

signals:
	//测试连接
	void testSon1(QString);
	//发送数据给主进程界面
	void getDataOutSon1(QVariantList satesList, int satesLen,
					QVariantList mbList, int mbLen,
					QVariantList moduList, int moduLen);

private slots:
	//新卫星的数据，填入数据库
	void getNewSateSon1(QVariantList);
	//新目标的数据，填入数据库
	void getNewMbSon1(QVariantList);
	//生成卫星轨迹保存文件
	void createSatesGJSon1(QVariantList, bool);
	//生成目标轨迹保存文件
	void createMbGJSon1(QVariantList, bool);
	//卫星目标数据，数据库拿数据返回给主线程
	void getDataSon1();
	//进行计算
	void allTaskSon1();
};

#endif // TESTTHREAD_H 