#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SignIn.h"
#include"CUserOp.h"
#include"UserView.h"
#include<thread>


//µÇÂ¼Ò³Ãæ

class SignInView : public QMainWindow
{
	Q_OBJECT //Ê¹ÓÃÐÅºÅ²Û±ØÐë°üº¬µÄºê

private:
	Ui::SignInWindow ui;

private:
	CUserOp *userOp=NULL;

public:
	SignInView(CUserOp *op=NULL,QWidget *parent = Q_NULLPTR);
	~SignInView();


private slots:
	int slot_signIn();//µÇÂ¼
	int slot_reg();//×¢²á
};
