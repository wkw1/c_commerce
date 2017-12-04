#include "CCommodity.h"
using namespace std;
commodityType CCommodity::getCType()
{
	return this->cType;
}
void CCommodity::setCType(commodityType type)
{
	this->cType = type;
}

string CCommodity::getCName()
{
	return this->cName;
}

void CCommodity::setCName(string name)
{
	this->cName = name;
}

string CCommodity::getCInfo()
{
	return this->cInfo;
}

void CCommodity::setCInfo(string info)
{
	this->cInfo = info;
}

int CCommodity::getCID()
{
	return this->cID;
}
void CCommodity::setCID(int ID)
{
	this->cID = ID;
}

float CCommodity::getPrice()
{
	return this->cPrice;
}

void CCommodity::setPrice(float price)
{
	this->cPrice = price;
}

float CCommodity::getCDiscountFactor()
{
	return this->cDiscountFactor;
}

void CCommodity::setCDiscountFactor(float factor)
{
	this->cDiscountFactor = factor;
}

int CCommodity::getCNumber()
{
	return this->cNumber;
}

void CCommodity::setCNumber(int number)
{
	this->cNumber = number;
}




//食品类相应构造方法
float CFood::getFinalPrice()
{
	//最终价格  原价*商品折扣一级类型折扣*二级类型折扣
	return this->getCDiscountFactor()*this->getCType().typeDisFactor
		*this->fType.typeDisFactor*this->getPrice();
}

//食物的get set方法
commodityType CFood::getFType()
{
	return this->fType;
}

void CFood::setFType(commodityType type)
{
	this->fType = type;
}

string CFood::getFBrand()
{
	return this->fBrand;
}

void CFood::setFBrand(string brand)
{
	this->fBrand = brand;
}

tm CFood::getFProductDate()
{
	return this->fProductDate;
}

void CFood::setFProductDate(tm date)
{
	this->fProductDate = date;
}

tm CFood::getFEXPDate()
{
	return this->fEXPDate;
}

void CFood::setFEXPDate(tm date)
{
	this->fEXPDate = date;
}


//图书类的构造方法
float CBook::getFinalPrice()
{
	//最终价格  原价*商品折扣*一级类型折扣*二级类型折扣
	return this->getCDiscountFactor()*this->getCType().typeDisFactor
		*this->bType.typeDisFactor*this->getPrice();
}

commodityType CBook::getBType()
{
	return this->bType;
}

void CBook::setBType(commodityType type)
{
	this->bType = type;
}

string CBook::getBISBN()
{
	return this->bISBN;
}

void CBook::setBISBN(string ISBN)
{
	this->bISBN = ISBN;
}

string CBook::getBPress()
{
	return this->bPress;
}

void CBook::setBPress(string press)
{
	this->bPress = press;
}

string CBook::getBAuthor()
{
	return this->bAuthor;
}

void CBook::setBAuthor(string author)
{
	this->bAuthor = author;
}

tm CBook::getBPubDate()
{
	return this->bPubDate;
}

void CBook::setBPubDate(tm date)
{
	this->bPubDate = date;
}


// 衣服类的相关函数
float CClothing::getFinalPrice()
{
	//最终价格  原价*商品折扣一级类型折扣*二级类型折扣
	return this->getCDiscountFactor()*this->getCType().typeDisFactor
		*this->cloType.typeDisFactor*this->getPrice();
}

commodityType CClothing::getCloType()
{
	return this->cloType;
}

void CClothing::setCloType(commodityType type)
{
	this->cloType = type;
}

string CClothing::getCloSeasonal()
{
	return this->cloSeasonal;
}

void CClothing::setCloSeasonal(string seasonal)
{
	this->cloSeasonal = seasonal;
}

string CClothing::getCloSize()
{
	return this->cloSize;
}

void CClothing::setCloSize(string size)
{
	this->cloSize = size;
}
