#include "CUser.h"

string CUser::getUserName()
{
	return this->userName;
}

void CUser::setUserName(string name)
{
	this->userName = name;
}

string CUser::getUserID()
{
	return this->userID;
}

void CUser::setUserID(string ID)
{
	this->userID = ID;
}

string CUser::getPassword()
{
	return this->password;
}

void CUser::setPassword(string password)
{
	this->password = password;
}

userBankcard * CUser::getBankCard()
{
	return this->bankCard;
}

void CUser::setBankCard(userBankcard bankCards[])
{
	for(int i=0;i<10;i++)
	   this->bankCard[i] = bankCards[i];
}

int CUser::getBCNumber()
{
	return this->BCNumber;
}

void CUser::setBCNumber(int number)
{
	this->BCNumber = number;
}

int CUser::getConsumNumber()
{
	return this->consumNumber;
}

void CUser::setConsumNumber(int number)
{
	this->consumNumber = number;
}

tm CUser::getRegisterDate()
{
	return this->registerDate;
}

void CUser::setRegisterDate(tm date)
{
	this->registerDate = date;
}

int CUser::getUserState()
{
	return this->userState;
}

void CUser::setUserState(int state)
{
	this->userState = state;
}
