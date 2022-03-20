#include "sonThread.h"  

sonThread::sonThread(QObject *parent) :
	QThread(parent)
{

}

void sonThread::run()
{
	//�����ź�  
	emit testSon1("���ӽ������ӳɹ�");
}

//����Ŀ�����ݣ����ݿ������ݷ��ظ����߳�
void sonThread::getDataSon1() {
	QVariantList a, b, c;
	int a1, b1, c1;
	emit getDataOutSon1(a, a1, b, b1, c, c1);
}

//�����ǵ����ݣ��������ݿ�
void sonThread::getNewSateSon1(QVariantList data) {
	//д���ݿ�
	for (int i = 0; i < data.size(); i++) {
		satesLibrary tempSate = data[i].value<satesLibrary>();
		qDebug() << tempSate.name;
	}
	qDebug() << "���������������ݿ�";
}

//��Ŀ������ݣ��������ݿ�
void sonThread::getNewMbSon1(QVariantList data) {
	//д���ݿ�
	for (int i = 0; i < data.size(); i++) {
		mbLibrary tempSate = data[i].value<mbLibrary>();
		qDebug() << tempSate.name;
	}
	qDebug() << "��Ŀ�����������ݿ�";
}
//�������ǹ켣�����ļ�
void sonThread::createSatesGJSon1(QVariantList data, bool tp) {
	//���������ļ�
	for (int i = 0; i < data.size(); i++) {
		satesLibrary tempSate = data[i].value<satesLibrary>();
		qDebug() << tempSate.name;
	}
	qDebug() << "���ǹ켣������";
}

//����Ŀ��켣�����ļ�
void sonThread::createMbGJSon1(QVariantList data, bool tu) {
	//���������ļ�
	for (int i = 0; i < data.size(); i++) {
		mbLibrary tempSate = data[i].value<mbLibrary>();
		qDebug() << tempSate.name;
	}
	qDebug() << "Ŀ��켣������";
}

//���м���
void sonThread::allTaskSon1() {
	//��������
	qDebug() << "�������������";
}