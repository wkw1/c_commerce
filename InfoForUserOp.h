#pragma once
#include<iostream>
#include<list>
#include"CCommodity.h"
#include"CShoppingCartItem.h"
using namespace std;
//存储操作返回信息，包括状态和消息说明
typedef struct infoForUserOP {
	int state;
	string info;
}infoForUserOp;

// 用户操作结果及相应的说明结构定义常量
// 系统相关提示
const infoForUserOp SYSTEM_DB_LINK_SUC = { 1,"数据库连接成功" };
const infoForUserOp SYSTEM_DOWN = { 0,"系统出现故障" };
const infoForUserOp SYSTEM_DB_LINK_FAIL = { -1,"数据库连接失败" };

//商品数据和操作相关
const infoForUserOp GET_COMM_SUCCESS = { 1,"成功查询到商品" };
const infoForUserOp GET_COMM_NODATA = { 1,"成功查询到商品" };

//注册登录相关
const infoForUserOp LOGON_SUCCESS = { 1,"成功注册" };
const infoForUserOp SIGNIN_SUCCESS = { 1,"登录成功" };
const infoForUserOp SIGNOUT_SUCCESS = { 1,"登出成功" };
const infoForUserOp LOGON_ID_HAVE_USED = { -1,"此ID已被注册，请更换" };
const infoForUserOp SIGNIN_FAIL = { 0,"登录失败" };
const infoForUserOp SIGNIN_NO_USER = { -2,"请检查用户名的正确性" };
const infoForUserOp SIGNIN_PASS_ERROR = { -3,"密码错误" };
const infoForUserOp SIGNIN_HAVE_SIGN = { -4,"已登录，若非自己操作，请采取安全措施" };

//购买商品相关
const infoForUserOp BUY_SUCCESS = { 1,"购买成功！！" };
const infoForUserOp BUY_FAIL_FOR_CDAO= { 0,"商品可能无库存或者已下架，暂时不能购买" };
const infoForUserOp BUY_FAIL_FOR_USERDAO = { 0,"未登录或者出现其他问题，不能成交商品" };
const infoForUserOp BUY_FAIL_FOR_TRADEDAO = { 0,"购买出错，不能成交商品" };

//购物车相关
const infoForUserOp ADD_CART_FAIL = { 0,"加入失败" };
const infoForUserOp ADD_CART_SUCCESS = { 1,"加入购物车成功" };

const infoForUserOp DEL_CART_FAIL = { 0,"删除失败" };
const infoForUserOp DEL_CART_SUCCESS = { 1,"删除成功" };

const infoForUserOp GET_CART_SUCCESS = { 1,"查询商品成功" };
const infoForUserOp GET_CART_FAIL = { 0,"查询商品失败" };




//用户操作返回信息--成功？？失败？？
class CInfoForUserOp {
public:
	int state;
	string info;//与state一一对应
	string addInfo;
public:
	CInfoForUserOp(infoForUserOP info, string addInfo);
	CInfoForUserOp(infoForUserOP info);
	CInfoForUserOp() {};
};


//商品类封装--用户查看商品返回
class CInfoForCList {
public:
	CInfoForUserOp infoForOp;//用户操作结果
private:
	list<CFood> foodList;
	list<CBook> bookList;
	list<CClothing> clothingList;
public:
	CInfoForCList(CInfoForUserOp);
	CInfoForCList(CInfoForUserOp op,list<CFood> foodList);
public:
	list<CFood> getFoodList();
	void setFoodList(list<CFood> list);

	list<CBook> getBookList();
	void setBookList(list<CBook> list);

	list<CClothing> getClothingList();
	void setClothingList(list<CClothing> list);
};

//查询购物车，返回信息
class CInfoForSCartList {
public:
	CInfoForUserOp op;
private:
	list<CShoppingCartItem> cartItems;
public:
	CInfoForSCartList(CInfoForUserOp);
	CInfoForSCartList(CInfoForUserOp, list<CShoppingCartItem>);

public:
	list<CShoppingCartItem> getCartItems();
	void setCartItems(list<CShoppingCartItem> list);
};

