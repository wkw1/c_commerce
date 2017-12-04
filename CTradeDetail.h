#pragma once
#ifndef CTRADEDETAIL_H
#define CTRADEDETAIL_H
#include<iostream>
using namespace std;
//写入消费信息
class CTradeDetail {
private:
	string userID;
	int cID;
	float tradeMoney;
	tm tradeDate;
public:
	string getUserID();
	void setUserID(string userID);
	int getCID();
	void setCID(int cID);
	float getTradeMoney();
	void setTradeMoney(float money);
	tm getTradeDate();
	void setTradeDate(tm date);
};
#endif // !CTRADEDETAIL_H
