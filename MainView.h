#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Main.h"
#include"SignInView.h"
#include"CUserOp.h"
#include<thread>
//��ҳ�� ��������ҳ��������ɶ���û�
//ÿ���û�һ���߳�
class MainView : public QMainWindow
{
	Q_OBJECT //ʹ���źŲ۱�������ĺ�
public:
	MainView(QWidget *parent = Q_NULLPTR);

private slots:
	void slot_newOne();

private :
	CUserOp* oneUser();

private:
	Ui::MainWindow ui;
};