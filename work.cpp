#include "work.h"
#include <qthread.h>
Work::Work(QObject *parent) : QObject(parent)
{

}


//����Ŀ�����ݣ����ݿ������ݷ��ظ����߳�
void Work::getDataSon1() {
	QVariantList a, b, c;
	int a1, b1, c1;
	emit getDataOutSon1(a, a1, b, b1, c, c1);
}

//�����ǵ����ݣ��������ݿ�
void Work::getNewSateSon1(QVariantList data) {
	//д���ݿ�
	for (int i = 0; i < data.size(); i++) {
		satesLibrary tempSate = data[i].value<satesLibrary>();
		qDebug() << tempSate.name;
	}
	qDebug() << "���������������ݿ�";
}

//��Ŀ������ݣ��������ݿ�
void Work::getNewMbSon1(QVariantList data) {
	//д���ݿ�
	for (int i = 0; i < data.size(); i++) {
		mbLibrary tempSate = data[i].value<mbLibrary>();
		qDebug() << tempSate.name;
	}
	qDebug() << "��Ŀ�����������ݿ�";
}
//�������ǹ켣�����ļ�
void Work::createSatesGJSon1(QVariantList data, bool tp) {
	//���������ļ�
	QThread::sleep(10);
	//for (int i = 0; i < data.size(); i++) {
	//	satesLibrary tempSate = data[i].value<satesLibrary>();
	//	qDebug() << tempSate.name;
	//}
	qDebug() << "���ǹ켣������";
}

//����Ŀ��켣�����ļ�
void Work::createMbGJSon1(QVariantList data, bool tu) {
	//���������ļ�
	for (int i = 0; i < data.size(); i++) {
		mbLibrary tempSate = data[i].value<mbLibrary>();
		qDebug() << tempSate.name;
	}
	qDebug() << "Ŀ��켣������";
}

//���м���
void Work::allTaskSon1() {
	//��������
	qDebug() << "�������������";
}