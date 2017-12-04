#pragma once
#ifndef CUSER_H
# define CUSER_H
#include<iostream>
using namespace std;

typedef struct userBankcard {
	int cardID;
	string bankName;
}userBankcard;


class CUser{
private:
	string userName;
	string userID;
	string password;
	userBankcard bankCard[10];
	int BCNumber;
	int consumNumber;
	tm registerDate;
	int userState;
public:
	string getUserName();
	void setUserName(string name);

	string getUserID();
	void setUserID(string ID);

	string getPassword();
	void setPassword(string password);

	userBankcard* getBankCard();
	void setBankCard(userBankcard bankCards[]);

	int getBCNumber();
	void setBCNumber(int number);

	int getConsumNumber();
	void setConsumNumber(int number);

	tm getRegisterDate();
	void setRegisterDate(tm date);

	int getUserState();
	void setUserState(int state);
};

#endif // !1

