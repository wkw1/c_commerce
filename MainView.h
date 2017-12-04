#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Main.h"
#include"SignInView.h"
#include"CUserOp.h"
#include<thread>
//主页面 ，经过此页面可以生成多个用户
//每个用户一个线程
class MainView : public QMainWindow
{
	Q_OBJECT //使用信号槽必须包含的宏
public:
	MainView(QWidget *parent = Q_NULLPTR);

private slots:
	void slot_newOne();

private :
	CUserOp* oneUser();

private:
	Ui::MainWindow ui;
};