#include "MainView.h"
#include "UserView.h"

MainView::MainView(QWidget * parent) 
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.newOneBn, SIGNAL(clicked()),this,SLOT(slot_newOne()));
}

void MainView::slot_newOne()
{
	SignInView *signIn = new SignInView(oneUser());
	signIn->show();

	ui.newOneBn->setText("hehe");//�źŲ۲���
}

CUserOp* MainView::oneUser()
{
		//���ݿ�����
		Driver *driver = 0;
		Connection* conn = 0;
		try {
			driver = mysql::get_driver_instance();
			conn = driver->connect("tcp://localhost:3306/e_commerce",
				"root", "root");
			conn->setAutoCommit(false);//���ý�ֹ�Զ��ύ
		}
		catch (exception e) {
			cout << "���ݿ�����ʧ��" << endl;
		}

	return new CUserOp(conn);
}
