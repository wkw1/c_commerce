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




//ʳƷ����Ӧ���췽��
float CFood::getFinalPrice()
{
	//���ռ۸�  ԭ��*��Ʒ�ۿ�һ�������ۿ�*���������ۿ�
	return this->getCDiscountFactor()*this->getCType().typeDisFactor
		*this->fType.typeDisFactor*this->getPrice();
}

//ʳ���get set����
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


//ͼ����Ĺ��췽��
float CBook::getFinalPrice()
{
	//���ռ۸�  ԭ��*��Ʒ�ۿ�*һ�������ۿ�*���������ۿ�
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


// �·������غ���
float CClothing::getFinalPrice()
{
	//���ռ۸�  ԭ��*��Ʒ�ۿ�һ�������ۿ�*���������ۿ�
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
