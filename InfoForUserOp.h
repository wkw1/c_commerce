#pragma once
#include<iostream>
#include<list>
#include"CCommodity.h"
#include"CShoppingCartItem.h"
using namespace std;
//�洢����������Ϣ������״̬����Ϣ˵��
typedef struct infoForUserOP {
	int state;
	string info;
}infoForUserOp;

// �û������������Ӧ��˵���ṹ���峣��
// ϵͳ�����ʾ
const infoForUserOp SYSTEM_DB_LINK_SUC = { 1,"���ݿ����ӳɹ�" };
const infoForUserOp SYSTEM_DOWN = { 0,"ϵͳ���ֹ���" };
const infoForUserOp SYSTEM_DB_LINK_FAIL = { -1,"���ݿ�����ʧ��" };

//��Ʒ���ݺͲ������
const infoForUserOp GET_COMM_SUCCESS = { 1,"�ɹ���ѯ����Ʒ" };
const infoForUserOp GET_COMM_NODATA = { 1,"�ɹ���ѯ����Ʒ" };

//ע���¼���
const infoForUserOp LOGON_SUCCESS = { 1,"�ɹ�ע��" };
const infoForUserOp SIGNIN_SUCCESS = { 1,"��¼�ɹ�" };
const infoForUserOp SIGNOUT_SUCCESS = { 1,"�ǳ��ɹ�" };
const infoForUserOp LOGON_ID_HAVE_USED = { -1,"��ID�ѱ�ע�ᣬ�����" };
const infoForUserOp SIGNIN_FAIL = { 0,"��¼ʧ��" };
const infoForUserOp SIGNIN_NO_USER = { -2,"�����û�������ȷ��" };
const infoForUserOp SIGNIN_PASS_ERROR = { -3,"�������" };
const infoForUserOp SIGNIN_HAVE_SIGN = { -4,"�ѵ�¼�������Լ����������ȡ��ȫ��ʩ" };

//������Ʒ���
const infoForUserOp BUY_SUCCESS = { 1,"����ɹ�����" };
const infoForUserOp BUY_FAIL_FOR_CDAO= { 0,"��Ʒ�����޿��������¼ܣ���ʱ���ܹ���" };
const infoForUserOp BUY_FAIL_FOR_USERDAO = { 0,"δ��¼���߳����������⣬���ܳɽ���Ʒ" };
const infoForUserOp BUY_FAIL_FOR_TRADEDAO = { 0,"����������ܳɽ���Ʒ" };

//���ﳵ���
const infoForUserOp ADD_CART_FAIL = { 0,"����ʧ��" };
const infoForUserOp ADD_CART_SUCCESS = { 1,"���빺�ﳵ�ɹ�" };

const infoForUserOp DEL_CART_FAIL = { 0,"ɾ��ʧ��" };
const infoForUserOp DEL_CART_SUCCESS = { 1,"ɾ���ɹ�" };

const infoForUserOp GET_CART_SUCCESS = { 1,"��ѯ��Ʒ�ɹ�" };
const infoForUserOp GET_CART_FAIL = { 0,"��ѯ��Ʒʧ��" };




//�û�����������Ϣ--�ɹ�����ʧ�ܣ���
class CInfoForUserOp {
public:
	int state;
	string info;//��stateһһ��Ӧ
	string addInfo;
public:
	CInfoForUserOp(infoForUserOP info, string addInfo);
	CInfoForUserOp(infoForUserOP info);
	CInfoForUserOp() {};
};


//��Ʒ���װ--�û��鿴��Ʒ����
class CInfoForCList {
public:
	CInfoForUserOp infoForOp;//�û��������
private:
	list<CFood> foodList;
	list<CBook> bookList;
	list<CClothing> clothingList;
public:
	CInfoForCList(CInfoForUserOp);
	CInfoForCList(CInfoForUserOp op,list<CFood> foodList);
public:
	list<CFood> getFoodList();
	void setFoodList(list<CFood> list);

	list<CBook> getBookList();
	void setBookList(list<CBook> list);

	list<CClothing> getClothingList();
	void setClothingList(list<CClothing> list);
};

//��ѯ���ﳵ��������Ϣ
class CInfoForSCartList {
public:
	CInfoForUserOp op;
private:
	list<CShoppingCartItem> cartItems;
public:
	CInfoForSCartList(CInfoForUserOp);
	CInfoForSCartList(CInfoForUserOp, list<CShoppingCartItem>);

public:
	list<CShoppingCartItem> getCartItems();
	void setCartItems(list<CShoppingCartItem> list);
};

