#include "CUserDao.h"

CUserDao::CUserDao(Connection * conn)
{
	this->conn = conn;
}

//注册函数，实现向用户表中插入用户的数据
CInfoForUserOp CUserDao::logon(CUser user)
{
	Statement *stat;
	stat = conn->createStatement();
	stat->execute("SET character set gbk");//设置编码

	string sqlStr = "insert into user(user_ID,user_name,password)";
	sqlStr += " values(";
	sqlStr += "\"" + user.getUserID()+ "\",";
	sqlStr += "\"" +user.getUserName()+"\",";
	sqlStr += "\"" + user.getPassword() + "\")";
	cout << sqlStr << endl;
	try {
		//向数据库中插入数据
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
		if (ep.getErrorCode() == 1062)//已注册
			return CInfoForUserOp(LOGON_ID_HAVE_USED);
	}
	catch(exception e){
		delete stat;
		return CInfoForUserOp(SYSTEM_DOWN);
	}
}

//登录函数
CInfoForUserOp CUserDao::signIn(string ID, string password,CUser &user)
{
	//1 数据库查询是否有此用户
	Statement *stat = conn->createStatement();
	stat->execute("set character set gbk");
	//传用户信息SQL
	string sqlStr = "select * from user where user_ID =";
	sqlStr += ID;
	//查询用户银行卡SQL
	string sqlStr1 = "select * from user_bankcard where user_ID =";
	sqlStr1 += ID;

	ResultSet *res =0;//保存用户信息
	ResultSet *resCard = 0;//保存用户银行卡信息
	try {
		res = stat->executeQuery(sqlStr.c_str());//查询用户信息
		resCard = stat->executeQuery(sqlStr1.c_str());//查询用户绑定的银行卡
	}
	catch(exception e){
		conn->rollback();
		delete stat;
		delete res;
		return CInfoForUserOp(SYSTEM_DOWN);
	}
	//查询无用户
	if (!res->next()) {
			delete stat;
			delete res;
		return CInfoForUserOp(SIGNIN_NO_USER);
	}

	//2 检验密码
	if(res->getString("password").c_str()!=password) {
			delete stat;
			delete res;
		return CInfoForUserOp(SIGNIN_PASS_ERROR);
	}

	//3 已登录
	if (res->getInt("user_state") == 1) {
		delete stat;
		delete res;
		return CInfoForUserOp(SIGNIN_HAVE_SIGN);
	}

	//标志用户登录--更改数据库用户登录状态为1;
	string upSql = "update user set user_state = 1 where user_ID = ";
	upSql += ID;

	try {
		int result = stat->executeUpdate(upSql.c_str());
		
		if (result == 1) {//成功登录给user赋值
			//user.setUserID(res->getString("user_ID").c_str());
			user.setUserName(res->getString("user_name").c_str());
			user.setBCNumber(res->getInt("bc_num"));
			user.setConsumNumber(res->getInt("cons_num"));
			user.setUserID(res->getString("user_ID").c_str());
			user.setRegisterDate(StringToDatetime(res->getString("res_time").c_str()));
			user.setUserState(1);

			//用户银行卡
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


//登出函数
CInfoForUserOp CUserDao::signOut(string ID)
{

	//1 数据库查询是否有此用户
	Statement *stat = conn->createStatement();
	stat->execute("set character set gbk");

	//标志用户登录--更改数据库用户登录状态为0;
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

// 购买商品 用户购买商品数量加一
int CUserDao::buyOne(string ID)
{
	//商品数量加一
	string sqlStr = "update user ";
	sqlStr += " set cons_num=cons_num+1 where user_state = 1 and user_ID= "+ID;
	Statement *stat = conn->createStatement();
	stat->execute("set character set gbk");
	try {
		int result = stat->executeUpdate(sqlStr.c_str());
		delete stat;
		if (result == 1) {//加一成功
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
