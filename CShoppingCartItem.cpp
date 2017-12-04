#include "CShoppingCartItem.h"

string CShoppingCartItem::getUserID()
{
	return this->userID;
}

void CShoppingCartItem::setUserID(string id)
{
	this->userID = userID;
}

int CShoppingCartItem::getCID()
{
	return this->cID;
}

void CShoppingCartItem::setCID(int id)
{
	this->cID = id;
}

CCommodity CShoppingCartItem::getCC()
{
	return this->cc;
}

void CShoppingCartItem::setCC(CCommodity cc)
{
	this->cc = cc;
}

int CShoppingCartItem::getNum()
{
	return this->num;
}

void CShoppingCartItem::setNum(int num)
{
	this->num = num;
}

float CShoppingCartItem::getPrice()
{
	return this->price;
}

void CShoppingCartItem::setPrice(float price)
{
	this->price = price;
}

tm CShoppingCartItem::getDate()
{
	return this->date;
}

void CShoppingCartItem::setDate(tm date)
{
	this->date = date;
}
