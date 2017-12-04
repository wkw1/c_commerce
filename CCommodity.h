#pragma once
#ifndef CCOMMODITY_H
#define CCOMMODITY_H
#include<iostream>
using namespace std;
//商品类型结构
typedef struct commodity_type {
	int type;//唯一标识
	float typeDisFactor;//折扣因子
	string name;//描述名称
	string addInfo;//附加信息
}commodityType;

//商品基类
class CCommodity {
private:
	commodityType cType;//商品类型
	string cInfo;//产品描述
	string cName;//商品名称
	int cID;//商品ID
	float cPrice;//商品原价格
	float cDiscountFactor=1.0f;//商品折扣因子
	int cNumber;//商品数量
public:
	commodityType getCType();
	void setCType(commodityType type);

	string getCName();
	void setCName(string name);

	string getCInfo();
	void setCInfo(string info);

	int getCID();
	void setCID(int ID);

	float getPrice();
	void setPrice(float price);

	float getCDiscountFactor();
	void setCDiscountFactor(float factor);
	
	int getCNumber();
	void setCNumber(int number);

	//虚函数
	virtual float getFinalPrice() { return 0.0f; };
};

//食品类
class CFood :public CCommodity {
private:
	commodityType fType;//食品类型
	string fBrand;//食品品牌
	tm fProductDate;//食品生产时期
	tm fEXPDate;//食品过期时间
public:
	float getFinalPrice();

	commodityType getFType();
	void setFType(commodityType type);

	string getFBrand();
	void setFBrand(string brand);

	tm getFProductDate();
	void setFProductDate(tm date);

	tm getFEXPDate();
	void setFEXPDate(tm date);
};

//衣服类
class CClothing:public CCommodity {
private:
	commodityType cloType;//衣服类型--二级类型
	string cloSeasonal;//适用季节
	string cloSize;//尺寸
public:
	float getFinalPrice();

	commodityType getCloType();
	void setCloType(commodityType type);

	string getCloSeasonal();
	void setCloSeasonal(string isbn);

	string getCloSize();
	void setCloSize(string size);
};

//图书类
class CBook:public CCommodity {
private:
	commodityType bType;//二级类型
	string bISBN;
	string bPress;
	string bAuthor;
	tm bPubDate;
public:
	float getFinalPrice();

	commodityType getBType();
	void setBType(commodityType type);

	string getBISBN();
	void setBISBN(string ISBN);

	string getBPress();
	void setBPress(string press);

	string getBAuthor();
	void setBAuthor(string author);

	tm getBPubDate();
	void setBPubDate(tm date);
};

#endif