#pragma once
#ifndef CUSEROP_H
#define CUSEROP_H
#include<iostream>
#include"CUser.h"
#include"CUserDao.h"
#include"CCommodityDao.h"
#include"ConnData.h"
#include"CTradeDetailDao.h"
#include"InfoForUserOp.h"
#include"CShoppingCartItem.h"
#include"CShoppingCartDao.h"
using namespace std;

/*
  用户操作类 controller
  用户在平台所有操作都要经过此类
 */

class CUserOp {
private:
	CUser user;//存储用户
	bool isSignIn = false;//标记用户是否登录

	CUserDao * userDao=0;//用户数据库操作实例
	CCommodityDao * commodityDao=0;//商品数据库操作实例
	CTradeDetailDao * tradeDetailDao=0;//交易明细
	CShoppinngCartDao * shoppingCartDao = 0;//购物车

	Connection *conn = 0;//数据库连接对象，每个用户一个

public:
	CUserOp(Connection *conn);//需要调度者传入conn对象
	~CUserOp();

public:
	CUser getUser();
	void setUser(CUser user);
public:
	CInfoForUserOp logon(CUser user);//注册 
	CInfoForUserOp signIn(string ID, string password);//登录
	CInfoForUserOp signOut();//登出操作
	CInfoForCList  viewCommodity();//浏览商品
	CInfoForUserOp searchCommodity(string key);//搜索商品 --TODO
	CInfoForUserOp addShoppingCart(CCommodity &cc);//加入购物车
	CInfoForSCartList viewShoppingCart();//查看自己的购物车
	CInfoForUserOp delShoppingCart(CCommodity &cc);//从购物车删除商品
	CInfoForUserOp buyCommodity(CCommodity &cc,int bankcard,int password);//购买商品
	CInfoForUserOp bindingBankcard(int bankcard,int password);//绑定银行卡 --TODO
};
#endif // !CUSEROP_H
