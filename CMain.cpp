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

	//一个用户启动操作；；；；
	thread th = thread(oneUser);

	th.join();

	getchar();
}


void oneUser() {
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

	CUserOp userOp = CUserOp(conn);

	signAndLogon(userOp);

	buyOne(userOp);
	addCart(userOp);
	//delOneFromCart(userOp);
	getCartList(userOp);

	userOp.signOut();

	driver->threadEnd();
}

//从购物车删除一件商品
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
	cout << "操作信息：" << info.op.info <<"  "<< endl;
}

//得到购物车列表
void getCartList(CUserOp &userOp) {
	CInfoForSCartList info= userOp.viewShoppingCart();
	if (info.op.state != 1)
		cout << "操作失败：" << info.op.info << endl;
	else{
		list<CShoppingCartItem> cartItem = info.getCartItems();
		CShoppingCartItem item;
		for (int i = 0; i < cartItem.size(); i++) {
			cout << "操作失败：" << info.op.info << endl;
			item = cartItem.front();
			cout << "商品ID：" << item.getCID() << endl;
			cout << "加入时价格：" << item.getPrice() << endl;
			cout << "数量：" << item.getNum() << endl;
			cout << "时间:" << item.getDate().tm_year << endl;
		}
	}
}

//加入商品到购物车
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
	cout << "操作返回：" << op.state << "说明" << op.info << endl;

}
//购买物品
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
	cout << "购买返回信息：" << op.state << "说明" << op.info << endl;
}

//登录注册
void signAndLogon(CUserOp &userOp) {
	CUser user;
	user.setUserID("111");
	user.setUserName("wkw");
	user.setPassword("111");
	//dao.logon(user);

	CInfoForUserOp op = userOp.signIn("111", "111");
	cout << "登录信息" << op.state << op.info << endl;

	cout << "用户信息" << endl;
	cout << "\tID:" << userOp.getUser().getUserID() << endl;
	cout << "\t姓名:" << userOp.getUser().getUserName() << endl;
	cout << "\t消费次数:" << userOp.getUser().getConsumNumber() << endl;
	cout << "\t绑定银行卡张数:" << userOp.getUser().getBCNumber() << endl;
	for (int i = 0; i < userOp.getUser().getBCNumber(); i++) {
		cout << "\t卡号:" << userOp.getUser().getBankCard()[i].cardID << endl;
		cout << "\t银行:" << userOp.getUser().getBankCard()[i].bankName << endl;
	}

}


void getList(CUserOp &userOp) {
	CInfoForCList lists = userOp.viewCommodity();

	list<CFood> foodList = lists.getFoodList();

	cout << foodList.size() << endl;

	CFood food;
	for (int i = 0; i<foodList.size(); i++) {
		food = foodList.front();
		cout << "商品类型：" << endl
			<< "\t类型标号: "
			<< food.getCType().type << endl
			<< "\t此类商品折扣: "
			<< food.getCType().typeDisFactor << endl
			<< "\t文字描述: "
			<< food.getCType().name << endl
			<< "\t附加信息: "
			<< food.getCType().addInfo << endl;
		cout << "商品名字：" << food.getCName() << endl;
		cout << "商品ID：" << food.getCID() << endl;
		cout << "食品品牌：" << food.getFBrand() << endl;
		cout << "食品类型：" << endl
			<< "\t类型标号: "
			<< food.getFType().type << endl
			<< "\t此类商品折扣: "
			<< food.getFType().typeDisFactor << endl
			<< "\t文字描述: "
			<< food.getFType().name << endl
			<< "\t附加信息: "
			<< food.getFType().addInfo << endl;
		cout << "食品原价格：" << food.getPrice() << endl;
		cout << "打折后价格：" << food.getFinalPrice() << endl;
		cout << endl << endl;
	}



	list<CBook> bookList = lists.getBookList();
	cout << "图书类个数：" << bookList.size() << endl;
	CBook book;
	for (int i = 0; i<bookList.size(); i++) {
		book = bookList.front();
		cout << "商品类型：" << endl
			<< "\t类型标号: "
			<< book.getCType().type << endl
			<< "\t此类商品折扣: "
			<< book.getCType().typeDisFactor << endl
			<< "\t文字描述: "
			<< book.getCType().name << endl
			<< "\t附加信息: "
			<< book.getCType().addInfo << endl;
		cout << "商品名字：" << book.getCName() << endl;
		cout << "商品ID：" << book.getCID() << endl;
		cout << "书的ISBN：" << book.getBISBN() << endl;
		cout << "书的作者：" << book.getBPress() << endl;
		cout << "书的出版社：" << book.getBAuthor() << endl;
		cout << "书的种类：" << endl
			<< "\t类型标号: "
			<< book.getBType().type << endl
			<< "\t此类商品折扣: "
			<< book.getBType().typeDisFactor << endl
			<< "\t文字描述: "
			<< book.getBType().name << endl
			<< "\t附加信息: "
			<< book.getBType().addInfo << endl;
		cout << "图书原价格：" << book.getPrice() << endl;
		cout << "打折后价格：" << book.getFinalPrice() << endl;
		cout << endl << endl;
	}
}