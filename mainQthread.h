#pragma once

#include <QtWidgets/QWidget>
#include "ui_mainQthread.h"

class mainQthread : public QWidget
{
    Q_OBJECT

public:
    mainQthread(QWidget *parent = Q_NULLPTR);

private:
    Ui::mainQthreadClass ui;
};
