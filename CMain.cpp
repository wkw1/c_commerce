#include<iostream>
#include"CCommodity.h"
#include"CUserOp.h"
#include<thread>
using namespace std;
void getList(CUserOp &userOp);
void buyOne(CUserOp &userOp);
void signAndLogon(CUserOp &userOp);
void addCart(CUserOp &userOp);
void getCartList(CUserOp &userOp);
void delOneFromCart(CUserOp &userOp);

void oneUser();

void main(void){

	//һ���û�����������������
	thread th = thread(oneUser);

	th.join();

	getchar();
}


void oneUser() {
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

	CUserOp userOp = CUserOp(conn);

	signAndLogon(userOp);

	buyOne(userOp);
	addCart(userOp);
	//delOneFromCart(userOp);
	getCartList(userOp);

	userOp.signOut();

	driver->threadEnd();
}

//�ӹ��ﳵɾ��һ����Ʒ
void delOneFromCart(CUserOp &userOp) {
	int c_ID = 1000001;
	int type = 11;
	int bankcard = 111;
	int password = 111;
	CFood food;
	food.setCID(c_ID);
	food.setPrice(100);
	food.setCType({ type,0.3f });
	food.setCDiscountFactor(0.7f);
	food.setFType({ 11001,0.8f });

	CInfoForSCartList info = userOp.delShoppingCart(food);
	cout << "������Ϣ��" << info.op.info <<"  "<< endl;
}

//�õ����ﳵ�б�
void getCartList(CUserOp &userOp) {
	CInfoForSCartList info= userOp.viewShoppingCart();
	if (info.op.state != 1)
		cout << "����ʧ�ܣ�" << info.op.info << endl;
	else{
		list<CShoppingCartItem> cartItem = info.getCartItems();
		CShoppingCartItem item;
		for (int i = 0; i < cartItem.size(); i++) {
			cout << "����ʧ�ܣ�" << info.op.info << endl;
			item = cartItem.front();
			cout << "��ƷID��" << item.getCID() << endl;
			cout << "����ʱ�۸�" << item.getPrice() << endl;
			cout << "������" << item.getNum() << endl;
			cout << "ʱ��:" << item.getDate().tm_year << endl;
		}
	}
}

//������Ʒ�����ﳵ
void addCart(CUserOp &userOp) {
	int c_ID = 1000001;
	int type = 11;
	int bankcard = 111;
	int password = 111;
	CFood food;
	food.setCID(c_ID);
	food.setPrice(100);
	food.setCType({ type,0.3f });
	food.setCDiscountFactor(0.7f);
	food.setFType({ 11001,0.8f });

	CInfoForUserOp op = userOp.addShoppingCart(food);
	cout << "�������أ�" << op.state << "˵��" << op.info << endl;

}
//������Ʒ
void buyOne(CUserOp &userOp) {
	int c_ID = 1000001;
	int type = 11;
	int bankcard = 111;
	int password = 111;
	CFood food;
	food.setCID(c_ID);
	food.setPrice(100);
	food.setCType({ type,0.3f });
	food.setCDiscountFactor(0.7f);
	food.setFType({ 11001,0.8f });

	CInfoForUserOp op= userOp.buyCommodity(food,bankcard,password);
	cout << "���򷵻���Ϣ��" << op.state << "˵��" << op.info << endl;
}

//��¼ע��
void signAndLogon(CUserOp &userOp) {
	CUser user;
	user.setUserID("111");
	user.setUserName("wkw");
	user.setPassword("111");
	//dao.logon(user);

	CInfoForUserOp op = userOp.signIn("111", "111");
	cout << "��¼��Ϣ" << op.state << op.info << endl;

	cout << "�û���Ϣ" << endl;
	cout << "\tID:" << userOp.getUser().getUserID() << endl;
	cout << "\t����:" << userOp.getUser().getUserName() << endl;
	cout << "\t���Ѵ���:" << userOp.getUser().getConsumNumber() << endl;
	cout << "\t�����п�����:" << userOp.getUser().getBCNumber() << endl;
	for (int i = 0; i < userOp.getUser().getBCNumber(); i++) {
		cout << "\t����:" << userOp.getUser().getBankCard()[i].cardID << endl;
		cout << "\t����:" << userOp.getUser().getBankCard()[i].bankName << endl;
	}

}


void getList(CUserOp &userOp) {
	CInfoForCList lists = userOp.viewCommodity();

	list<CFood> foodList = lists.getFoodList();

	cout << foodList.size() << endl;

	CFood food;
	for (int i = 0; i<foodList.size(); i++) {
		food = foodList.front();
		cout << "��Ʒ���ͣ�" << endl
			<< "\t���ͱ��: "
			<< food.getCType().type << endl
			<< "\t������Ʒ�ۿ�: "
			<< food.getCType().typeDisFactor << endl
			<< "\t��������: "
			<< food.getCType().name << endl
			<< "\t������Ϣ: "
			<< food.getCType().addInfo << endl;
		cout << "��Ʒ���֣�" << food.getCName() << endl;
		cout << "��ƷID��" << food.getCID() << endl;
		cout << "ʳƷƷ�ƣ�" << food.getFBrand() << endl;
		cout << "ʳƷ���ͣ�" << endl
			<< "\t���ͱ��: "
			<< food.getFType().type << endl
			<< "\t������Ʒ�ۿ�: "
			<< food.getFType().typeDisFactor << endl
			<< "\t��������: "
			<< food.getFType().name << endl
			<< "\t������Ϣ: "
			<< food.getFType().addInfo << endl;
		cout << "ʳƷԭ�۸�" << food.getPrice() << endl;
		cout << "���ۺ�۸�" << food.getFinalPrice() << endl;
		cout << endl << endl;
	}



	list<CBook> bookList = lists.getBookList();
	cout << "ͼ���������" << bookList.size() << endl;
	CBook book;
	for (int i = 0; i<bookList.size(); i++) {
		book = bookList.front();
		cout << "��Ʒ���ͣ�" << endl
			<< "\t���ͱ��: "
			<< book.getCType().type << endl
			<< "\t������Ʒ�ۿ�: "
			<< book.getCType().typeDisFactor << endl
			<< "\t��������: "
			<< book.getCType().name << endl
			<< "\t������Ϣ: "
			<< book.getCType().addInfo << endl;
		cout << "��Ʒ���֣�" << book.getCName() << endl;
		cout << "��ƷID��" << book.getCID() << endl;
		cout << "���ISBN��" << book.getBISBN() << endl;
		cout << "������ߣ�" << book.getBPress() << endl;
		cout << "��ĳ����磺" << book.getBAuthor() << endl;
		cout << "������ࣺ" << endl
			<< "\t���ͱ��: "
			<< book.getBType().type << endl
			<< "\t������Ʒ�ۿ�: "
			<< book.getBType().typeDisFactor << endl
			<< "\t��������: "
			<< book.getBType().name << endl
			<< "\t������Ϣ: "
			<< book.getBType().addInfo << endl;
		cout << "ͼ��ԭ�۸�" << book.getPrice() << endl;
		cout << "���ۺ�۸�" << book.getFinalPrice() << endl;
		cout << endl << endl;
	}
}