#include "InfoForUserOp.h"

//¹¹Ôìº¯Êý
CInfoForUserOp::CInfoForUserOp(infoForUserOP info, string addInfo)
{
	this->state = info.state;
	this->info = info.info;
	this->addInfo = addInfo;
}

CInfoForUserOp::CInfoForUserOp(infoForUserOP info)
{
	this->state = info.state;
	this->info = info.info;
	this->addInfo = "";
}

CInfoForCList::CInfoForCList(CInfoForUserOp op)
{
	this->infoForOp = op;
}

CInfoForCList::CInfoForCList(CInfoForUserOp op, list<CFood> foodList)
{
	this->infoForOp = op;
	this->setFoodList(foodList);
}

list<CFood> CInfoForCList::getFoodList()
{
	return this->foodList;
}

void CInfoForCList::setFoodList(list<CFood> list)
{
	this->foodList = list;
}

list<CBook> CInfoForCList::getBookList()
{
	return this->bookList;
}

void CInfoForCList::setBookList(list<CBook> list)
{
	this->bookList = list;
}

list<CClothing> CInfoForCList::getClothingList()
{
	return this->clothingList;
}

void CInfoForCList::setClothingList(list<CClothing> list)
{
	this->clothingList = list;
}

CInfoForSCartList::CInfoForSCartList(CInfoForUserOp op)
{
	this->op = op;
}

CInfoForSCartList::CInfoForSCartList(CInfoForUserOp op, list<CShoppingCartItem> lists)
{
	this->op = op;
	this->cartItems = lists;
}

list<CShoppingCartItem> CInfoForSCartList::getCartItems()
{
	return this->cartItems;
}

void CInfoForSCartList::setCartItems(list<CShoppingCartItem> list)
{
	this-> cartItems = list;
}
