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
	CInfoForSCartList getList(string userID);//��ȡ�б�

	int addOne(string userID,int cID,float price);//������Ʒ�����ﳵ

	int delOne(string userID,int cID);//ɾ����Ʒ-- �ֶ�ɾ���͹�����Ʒ��ɾ��
};

