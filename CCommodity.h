#pragma once
#ifndef CCOMMODITY_H
#define CCOMMODITY_H
#include<iostream>
using namespace std;
//��Ʒ���ͽṹ
typedef struct commodity_type {
	int type;//Ψһ��ʶ
	float typeDisFactor;//�ۿ�����
	string name;//��������
	string addInfo;//������Ϣ
}commodityType;

//��Ʒ����
class CCommodity {
private:
	commodityType cType;//��Ʒ����
	string cInfo;//��Ʒ����
	string cName;//��Ʒ����
	int cID;//��ƷID
	float cPrice;//��Ʒԭ�۸�
	float cDiscountFactor=1.0f;//��Ʒ�ۿ�����
	int cNumber;//��Ʒ����
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

	//�麯��
	virtual float getFinalPrice() { return 0.0f; };
};

//ʳƷ��
class CFood :public CCommodity {
private:
	commodityType fType;//ʳƷ����
	string fBrand;//ʳƷƷ��
	tm fProductDate;//ʳƷ����ʱ��
	tm fEXPDate;//ʳƷ����ʱ��
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

//�·���
class CClothing:public CCommodity {
private:
	commodityType cloType;//�·�����--��������
	string cloSeasonal;//���ü���
	string cloSize;//�ߴ�
public:
	float getFinalPrice();

	commodityType getCloType();
	void setCloType(commodityType type);

	string getCloSeasonal();
	void setCloSeasonal(string isbn);

	string getCloSize();
	void setCloSize(string size);
};

//ͼ����
class CBook:public CCommodity {
private:
	commodityType bType;//��������
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