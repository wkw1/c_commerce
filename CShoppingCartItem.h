#pragma once
#include<iostream>
#include<string>
#include"CCommodity.h"
using namespace std;
//���ﳵ����Ʒʵ��
class CShoppingCartItem {
private:
	string userID;
	int cID;
	CCommodity cc;//��Ʒʵ��
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