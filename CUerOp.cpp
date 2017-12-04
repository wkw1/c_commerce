#include "CUserOp.h"
using namespace std;
using namespace sql;

CUserOp::CUserOp(Connection * conn)
{
	this->conn = conn;

	//��ʼ������
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


//�鿴��Ʒ��������Ʒ�б�
CInfoForCList CUserOp::viewCommodity()
{
	CInfoForCList cInfoForList = CInfoForCList(GET_COMM_SUCCESS);
	//��ȡʳƷ��
	list<CFood> foodList = commodityDao->getFoodList();
	cInfoForList.setFoodList(foodList);
	list<CBook> bookList = commodityDao->getBookList();
	cInfoForList.setBookList(bookList);
	list<CClothing> cloList = commodityDao->getClothingList();
	cInfoForList.setClothingList(cloList);
	//δ��ѯ������
	if (foodList.size() == 0 && bookList.size() == 0 && cloList.size() == 0)
		return CInfoForCList(GET_COMM_NODATA);
	return cInfoForList;
}

// ע�ắ��
CInfoForUserOp CUserOp::logon(CUser user)
{
	return userDao->logon(user);
}

//��¼����
CInfoForUserOp CUserOp::signIn(string ID, string password)
{
	return userDao->signIn(ID, password, user);
}

//�ǳ�����
CInfoForUserOp CUserOp::signOut()
{
	string id = user.getUserID();
	user= CUser();//���������û�
	return userDao->signOut(id);
}


//����Ʒ���빺�ﳵ
CInfoForUserOp CUserOp::addShoppingCart(CCommodity & cc)
{
	//����

	if (shoppingCartDao->addOne(user.getUserID(), cc.getCID(), cc.getFinalPrice()) != 1)
		return CInfoForUserOp(ADD_CART_FAIL);

	return CInfoForUserOp(ADD_CART_SUCCESS);
}


//�鿴�û��Ĺ��ﳵ����Ʒ
CInfoForSCartList CUserOp::viewShoppingCart()
{
	return  shoppingCartDao->getList(user.getUserID());
}

//�ӹ��ﳵ��ɾ����Ʒ
CInfoForUserOp CUserOp::delShoppingCart(CCommodity & cc)
{
	if (shoppingCartDao->delOne(user.getUserID(), cc.getCID()) != 1)
		return CInfoForUserOp(DEL_CART_FAIL);
	
	return CInfoForUserOp(DEL_CART_SUCCESS);
}



//������Ʒ����
CInfoForUserOp CUserOp::buyCommodity(CCommodity &cc,int bankcard, int password)
{
	//1 ��Ʒ������һ
	if (commodityDao->buyOne(cc.getCID(), cc.getCType().type) != 1) {//ʧ��
		conn->rollback();
		return CInfoForUserOp(BUY_FAIL_FOR_CDAO);
	}
		
	//2 �û�������Ʒ������1
	if (userDao->buyOne(user.getUserID()) != 1){
		conn->rollback();
		return CInfoForUserOp(BUY_FAIL_FOR_USERDAO);
	}	
	//3 ����һ�����Ѽ�¼ TODO
	CTradeDetail detail;
	detail.setCID(cc.getCID());
	detail.setUserID(user.getUserID());
	detail.setTradeMoney(cc.getFinalPrice());
	if (tradeDetailDao->addOne(detail) != 1) {
		conn->rollback();
		return CInfoForUserOp(BUY_FAIL_FOR_TRADEDAO);
	}

	//4 ֧�� TODO 
	conn->commit();
	return CInfoForUserOp(BUY_SUCCESS);
}



//�����п�
CInfoForUserOp CUserOp::bindingBankcard(int bankcard, int password)
{
	return CInfoForUserOp();
}


CInfoForUserOp CUserOp::searchCommodity(string key)
{

	return CInfoForUserOp();
}
