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
  �û������� controller
  �û���ƽ̨���в�����Ҫ��������
 */

class CUserOp {
private:
	CUser user;//�洢�û�
	bool isSignIn = false;//����û��Ƿ��¼

	CUserDao * userDao=0;//�û����ݿ����ʵ��
	CCommodityDao * commodityDao=0;//��Ʒ���ݿ����ʵ��
	CTradeDetailDao * tradeDetailDao=0;//������ϸ
	CShoppinngCartDao * shoppingCartDao = 0;//���ﳵ

	Connection *conn = 0;//���ݿ����Ӷ���ÿ���û�һ��

public:
	CUserOp(Connection *conn);//��Ҫ�����ߴ���conn����
	~CUserOp();

public:
	CUser getUser();
	void setUser(CUser user);
public:
	CInfoForUserOp logon(CUser user);//ע�� 
	CInfoForUserOp signIn(string ID, string password);//��¼
	CInfoForUserOp signOut();//�ǳ�����
	CInfoForCList  viewCommodity();//�����Ʒ
	CInfoForUserOp searchCommodity(string key);//������Ʒ --TODO
	CInfoForUserOp addShoppingCart(CCommodity &cc);//���빺�ﳵ
	CInfoForSCartList viewShoppingCart();//�鿴�Լ��Ĺ��ﳵ
	CInfoForUserOp delShoppingCart(CCommodity &cc);//�ӹ��ﳵɾ����Ʒ
	CInfoForUserOp buyCommodity(CCommodity &cc,int bankcard,int password);//������Ʒ
	CInfoForUserOp bindingBankcard(int bankcard,int password);//�����п� --TODO
};
#endif // !CUSEROP_H
