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
	list<CFood> getFoodList();//��ȡʳƷ���б�
	list<CBook> getBookList();//��ȡͼ�����б�
	list<CClothing> getClothingList();//��ȡ�·����б�

	int buyOne(int cID,int type);//����һ����Ʒ
public:
	~CCommodityDao();
};
#endif // !CCOMMODITYDAO_H
