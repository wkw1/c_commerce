#include "CUserOp.h"
using namespace std;
using namespace sql;

CUserOp::CUserOp(Connection * conn)
{
	this->conn = conn;

	//初始化工具
	userDao = new CUserDao(conn);
	commodityDao = new CCommodityDao(conn);
	tradeDetailDao = new CTradeDetailDao(conn);
	shoppingCartDao = new CShoppinngCartDao(conn);
}

CUserOp::~CUserOp()
{
	if (userDao != NULL)
		delete userDao;
	if (commodityDao != NULL)
		delete commodityDao;
	if (tradeDetailDao !=NULL)
		delete tradeDetailDao;
	if (shoppingCartDao != NULL)
		delete shoppingCartDao;
	if (conn != NULL)
		delete conn;

}

CUser CUserOp::getUser()
{
	return this->user;
}

void CUserOp::setUser(CUser user)
{
	this->user = user;
}


//查看商品，返回商品列表
CInfoForCList CUserOp::viewCommodity()
{
	CInfoForCList cInfoForList = CInfoForCList(GET_COMM_SUCCESS);
	//获取食品类
	list<CFood> foodList = commodityDao->getFoodList();
	cInfoForList.setFoodList(foodList);
	list<CBook> bookList = commodityDao->getBookList();
	cInfoForList.setBookList(bookList);
	list<CClothing> cloList = commodityDao->getClothingList();
	cInfoForList.setClothingList(cloList);
	//未查询到数据
	if (foodList.size() == 0 && bookList.size() == 0 && cloList.size() == 0)
		return CInfoForCList(GET_COMM_NODATA);
	return cInfoForList;
}

// 注册函数
CInfoForUserOp CUserOp::logon(CUser user)
{
	return userDao->logon(user);
}

//登录函数
CInfoForUserOp CUserOp::signIn(string ID, string password)
{
	return userDao->signIn(ID, password, user);
}

//登出函数
CInfoForUserOp CUserOp::signOut()
{
	string id = user.getUserID();
	user= CUser();//清除保存的用户
	return userDao->signOut(id);
}


//将商品加入购物车
CInfoForUserOp CUserOp::addShoppingCart(CCommodity & cc)
{
	//数量

	if (shoppingCartDao->addOne(user.getUserID(), cc.getCID(), cc.getFinalPrice()) != 1)
		return CInfoForUserOp(ADD_CART_FAIL);

	return CInfoForUserOp(ADD_CART_SUCCESS);
}


//查看用户的购物车上商品
CInfoForSCartList CUserOp::viewShoppingCart()
{
	return  shoppingCartDao->getList(user.getUserID());
}

//从购物车中删除商品
CInfoForUserOp CUserOp::delShoppingCart(CCommodity & cc)
{
	if (shoppingCartDao->delOne(user.getUserID(), cc.getCID()) != 1)
		return CInfoForUserOp(DEL_CART_FAIL);
	
	return CInfoForUserOp(DEL_CART_SUCCESS);
}



//购买商品函数
CInfoForUserOp CUserOp::buyCommodity(CCommodity &cc,int bankcard, int password)
{
	//1 商品数量减一
	if (commodityDao->buyOne(cc.getCID(), cc.getCType().type) != 1) {//失败
		conn->rollback();
		return CInfoForUserOp(BUY_FAIL_FOR_CDAO);
	}
		
	//2 用户购买商品数量加1
	if (userDao->buyOne(user.getUserID()) != 1){
		conn->rollback();
		return CInfoForUserOp(BUY_FAIL_FOR_USERDAO);
	}	
	//3 增加一条消费记录 TODO
	CTradeDetail detail;
	detail.setCID(cc.getCID());
	detail.setUserID(user.getUserID());
	detail.setTradeMoney(cc.getFinalPrice());
	if (tradeDetailDao->addOne(detail) != 1) {
		conn->rollback();
		return CInfoForUserOp(BUY_FAIL_FOR_TRADEDAO);
	}

	//4 支付 TODO 
	conn->commit();
	return CInfoForUserOp(BUY_SUCCESS);
}



//绑定银行卡
CInfoForUserOp CUserOp::bindingBankcard(int bankcard, int password)
{
	return CInfoForUserOp();
}


CInfoForUserOp CUserOp::searchCommodity(string key)
{

	return CInfoForUserOp();
}
