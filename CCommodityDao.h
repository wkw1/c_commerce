#pragma once
#ifndef CCOMMODITYDAO_H
#define CCOMMODITYDAO_H
#include<iostream>
#include<string>
#include<list>
#include"unit.h"

#include"CCommodity.h"
using namespace std;
class CCommodityDao {
private:
	Connection* conn = 0;
public:
	CCommodityDao(Connection* conn);
public:
	list<CFood> getFoodList();//获取食品类列表
	list<CBook> getBookList();//获取图书类列表
	list<CClothing> getClothingList();//获取衣服类列表

	int buyOne(int cID,int type);//购买一个商品
public:
	~CCommodityDao();
};
#endif // !CCOMMODITYDAO_H
