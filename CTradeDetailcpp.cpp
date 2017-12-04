#include "CTradeDetail.h"

string CTradeDetail::getUserID()
{
	return this->userID;
}

void CTradeDetail::setUserID(string userID)
{
	this->userID = userID;
}

int CTradeDetail::getCID()
{
	return this->cID;
}

void CTradeDetail::setCID(int cID)
{
	this->cID = cID;
}

float CTradeDetail::getTradeMoney()
{
	return this->tradeMoney;
}

void CTradeDetail::setTradeMoney(float money)
{
	this->tradeMoney = money;
}

tm CTradeDetail::getTradeDate()
{
	return this->tradeDate;
}

void CTradeDetail::setTradeDate(tm date)
{
	this->tradeDate = date;
}
