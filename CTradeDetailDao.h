#pragma once

#ifndef CTRADEDETAILDAO_H
#define CTRADEDETAILDAO_H
#include<iostream>
#include<string>
#include"ConnData.h"
#include"CTradeDetail.h"
using namespace std;
//д��������Ϣ
class CTradeDetailDao {
private:
	Connection* conn = 0;
public:
	CTradeDetailDao(Connection* conn);
public:
	int addOne(CTradeDetail detail);
};
#endif // !CTRADEDETAILDAO_H
