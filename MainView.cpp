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

	ui.newOneBn->setText("hehe");//信号槽测试
}

CUserOp* MainView::oneUser()
{
		//数据库连接
		Driver *driver = 0;
		Connection* conn = 0;
		try {
			driver = mysql::get_driver_instance();
			conn = driver->connect("tcp://localhost:3306/e_commerce",
				"root", "root");
			conn->setAutoCommit(false);//设置禁止自动提交
		}
		catch (exception e) {
			cout << "数据库连接失败" << endl;
		}

	return new CUserOp(conn);
}
