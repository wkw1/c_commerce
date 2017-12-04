#include "CUserDao.h"

CUserDao::CUserDao(Connection * conn)
{
	this->conn = conn;
}

//ע�ắ����ʵ�����û����в����û�������
CInfoForUserOp CUserDao::logon(CUser user)
{
	Statement *stat;
	stat = conn->createStatement();
	stat->execute("SET character set gbk");//���ñ���

	string sqlStr = "insert into user(user_ID,user_name,password)";
	sqlStr += " values(";
	sqlStr += "\"" + user.getUserID()+ "\",";
	sqlStr += "\"" +user.getUserName()+"\",";
	sqlStr += "\"" + user.getPassword() + "\")";
	cout << sqlStr << endl;
	try {
		//�����ݿ��в�������
		int result = stat->executeUpdate(sqlStr.c_str());
		if (result == 1) {
			delete stat;
			conn->commit();
			return CInfoForUserOp(LOGON_SUCCESS);
		}	
		//cout << "reuslt:" << result << endl;
	}
	catch (SQLException ep) {
		delete stat;
		if (ep.getErrorCode() == 1062)//��ע��
			return CInfoForUserOp(LOGON_ID_HAVE_USED);
	}
	catch(exception e){
		delete stat;
		return CInfoForUserOp(SYSTEM_DOWN);
	}
}

//��¼����
CInfoForUserOp CUserDao::signIn(string ID, string password,CUser &user)
{
	//1 ���ݿ��ѯ�Ƿ��д��û�
	Statement *stat = conn->createStatement();
	stat->execute("set character set gbk");
	//���û���ϢSQL
	string sqlStr = "select * from user where user_ID =";
	sqlStr += ID;
	//��ѯ�û����п�SQL
	string sqlStr1 = "select * from user_bankcard where user_ID =";
	sqlStr1 += ID;

	ResultSet *res =0;//�����û���Ϣ
	ResultSet *resCard = 0;//�����û����п���Ϣ
	try {
		res = stat->executeQuery(sqlStr.c_str());//��ѯ�û���Ϣ
		resCard = stat->executeQuery(sqlStr1.c_str());//��ѯ�û��󶨵����п�
	}
	catch(exception e){
		conn->rollback();
		delete stat;
		delete res;
		return CInfoForUserOp(SYSTEM_DOWN);
	}
	//��ѯ���û�
	if (!res->next()) {
			delete stat;
			delete res;
		return CInfoForUserOp(SIGNIN_NO_USER);
	}

	//2 ��������
	if(res->getString("password").c_str()!=password) {
			delete stat;
			delete res;
		return CInfoForUserOp(SIGNIN_PASS_ERROR);
	}

	//3 �ѵ�¼
	if (res->getInt("user_state") == 1) {
		delete stat;
		delete res;
		return CInfoForUserOp(SIGNIN_HAVE_SIGN);
	}

	//��־�û���¼--�������ݿ��û���¼״̬Ϊ1;
	string upSql = "update user set user_state = 1 where user_ID = ";
	upSql += ID;

	try {
		int result = stat->executeUpdate(upSql.c_str());
		
		if (result == 1) {//�ɹ���¼��user��ֵ
			//user.setUserID(res->getString("user_ID").c_str());
			user.setUserName(res->getString("user_name").c_str());
			user.setBCNumber(res->getInt("bc_num"));
			user.setConsumNumber(res->getInt("cons_num"));
			user.setUserID(res->getString("user_ID").c_str());
			user.setRegisterDate(StringToDatetime(res->getString("res_time").c_str()));
			user.setUserState(1);

			//�û����п�
			userBankcard bankcards[10];
			for (int i = 0; resCard->next()&&i < 10; i++) {
				bankcards[i].cardID = resCard->getInt("card_ID");
				bankcards[i].bankName = resCard->getString("bank_name").c_str();
			}
			user.setBankCard(bankcards);

			conn->commit();
			delete stat;
			delete res;
			return CInfoForUserOp(SIGNIN_SUCCESS);
		}
		else {
			conn->rollback();
			return CInfoForUserOp(SIGNIN_FAIL);
		}	
	}
	catch (exception e) {
		conn->rollback();
		return CInfoForUserOp(SYSTEM_DOWN);
	}
}


//�ǳ�����
CInfoForUserOp CUserDao::signOut(string ID)
{

	//1 ���ݿ��ѯ�Ƿ��д��û�
	Statement *stat = conn->createStatement();
	stat->execute("set character set gbk");

	//��־�û���¼--�������ݿ��û���¼״̬Ϊ0;
	string upSql = "update user set user_state = 0 where user_ID = ";
	upSql += ID;
	try {
		int result = stat->executeUpdate(upSql.c_str()); 
			delete stat;
		if (result == 1) {
			conn->commit();
			return CInfoForUserOp(SIGNOUT_SUCCESS);
		}
	}
	catch (SQLException e) {
		delete stat;
		if(e.getErrorCode()== 1062)
			return CInfoForUserOp(SIGNOUT_SUCCESS);
	}
	catch(exception e){
		delete stat;
		return CInfoForUserOp(SYSTEM_DOWN);
	}
	
}

// ������Ʒ �û�������Ʒ������һ
int CUserDao::buyOne(string ID)
{
	//��Ʒ������һ
	string sqlStr = "update user ";
	sqlStr += " set cons_num=cons_num+1 where user_state = 1 and user_ID= "+ID;
	Statement *stat = conn->createStatement();
	stat->execute("set character set gbk");
	try {
		int result = stat->executeUpdate(sqlStr.c_str());
		delete stat;
		if (result == 1) {//��һ�ɹ�
			return 1;
		}
		else {
			return 0;
		}
			
	}
	catch (exception e) {
		delete stat;
		return 0;
	}
}
