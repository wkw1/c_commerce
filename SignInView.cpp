#include "SignInView.h"

SignInView::SignInView(CUserOp *op,QWidget * parent)
{
	ui.setupUi(this);
	userOp = op;
	//µÇÂ¼¶¯×÷
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
		//TODO Ìø×ªÒ³Ãæ
		UserView *userView = new UserView(userOp);
		userView->show();   
	}
	else {//µÇÂ¼Ê§°Ü
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
