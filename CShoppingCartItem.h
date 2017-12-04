#pragma once
#include<iostream>
#include<string>
#include"CCommodity.h"
using namespace std;
//购物车中商品实体
class CShoppingCartItem {
private:
	string userID;
	int cID;
	CCommodity cc;//商品实体
	int num;
	float price;
	tm date;
public:
	string getUserID();
	void setUserID(string id);

	int getCID();
	void setCID(int id);

	CCommodity getCC();
	void setCC(CCommodity cc);

	int getNum();
	void setNum(int num);

	float getPrice();
	void setPrice(float price);

	tm getDate();
	void setDate(tm date);
};