#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SignIn.h"
#include"CUserOp.h"
#include"UserView.h"
#include<thread>


//��¼ҳ��

class SignInView : public QMainWindow
{
	Q_OBJECT //ʹ���źŲ۱�������ĺ�

private:
	Ui::SignInWindow ui;

private:
	CUserOp *userOp=NULL;

public:
	SignInView(CUserOp *op=NULL,QWidget *parent = Q_NULLPTR);
	~SignInView();


private slots:
	int slot_signIn();//��¼
	int slot_reg();//ע��
};
