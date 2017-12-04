#include "SignInView.h"

SignInView::SignInView(CUserOp *op,QWidget * parent)
{
	ui.setupUi(this);
	userOp = op;
	//��¼����
	connect(ui.signIn, SIGNAL(clicked()), this, SLOT(slot_signIn()));
	
}

//
int SignInView::slot_signIn()
{
	string userID = ui.userID->text().toStdString();
	string password = ui.password->text().toStdString();

	CInfoForUserOp info = userOp->signIn(userID,password);
	if (info.state == 1) {
		ui.info->setText(QString::fromLocal8Bit(info.info.data()));
	    ui:close();
		//TODO ��תҳ��
		UserView *userView = new UserView(userOp);
		userView->show();   
	}
	else {//��¼ʧ��
		ui.info->setText(QString::fromLocal8Bit(info.info.data()));
	}
	return info.state;
}

SignInView::~SignInView()
{
}

int SignInView::slot_reg()
{
	return 0;
}
