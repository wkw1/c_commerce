#pragma once
#include<iostream>
#include"ConnData.h"
#include"CShoppingCartItem.h"
#include"InfoForUserOp.h"
#include"unit.h"
using namespace std;
class CShoppinngCartDao {
private:
	Connection* conn = 0;
public:
	CShoppinngCartDao(Connection* conn);
public:
	CInfoForSCartList getList(string userID);//获取列表

	int addOne(string userID,int cID,float price);//加入商品到购物车

	int delOne(string userID,int cID);//删除商品-- 手动删除和购买商品后删除
};

