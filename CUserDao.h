#pragma once
#ifndef CUSERDAO_H
#define CUSERDAO_H
#include"CCommodity.h"
#include"ConnData.h"
#include"CUser.h"
#include"InfoForUserOp.h"
#include"unit.h"
using namespace std;
class CUserDao {
private:
	Connection* conn = 0;
public:
	CUserDao(Connection* conn);
public:
	CInfoForUserOp logon(CUser user);//ע��
	CInfoForUserOp signIn(string ID,string password, CUser &user);//��¼
	CInfoForUserOp signOut(string ID);//�ǳ�

	int buyOne(string ID);
};

#endif // !CUSERDAO_H