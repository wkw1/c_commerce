#include"CShoppingCartDao.h"




//加入意见商品到购物车
int CShoppinngCartDao::addOne(string userID,int cID, float price)
{
	string sqlStr = "insert into shopping_cart(user_ID,c_ID,add_price) values(";
	sqlStr += "\"" + userID + "\",";
	sqlStr +=  to_string(cID) + ",";
	sqlStr += to_string(price) + ")";
		
	Statement *stat = conn->createStatement();
	stat->execute("set character set gbk");//设置编码

	try {
		int result = stat->executeUpdate(sqlStr.c_str()); 
			delete stat;
		if (result == 1){
			conn->commit();
			return 1;
		}	
		else
			return 0;
	}
	catch (SQLException e) {
		if (e.getErrorCode() == 1062) {//已存在此商品的记录
			                           //直接增加数量
			string upStr = "update shopping_cart set num=num+1 where ";
			upStr += " user_ID= \"" + userID+"\" and ";
			upStr += " c_ID=" + to_string(cID);
			try {
				if (stat->executeUpdate(upStr.c_str()) == 1) {
					delete stat;
					return 1;
				}
				delete stat;
				return 0;		
			}
			catch (exception e) {
				return 0;
			}
		}
		return 0;
	}
	catch(exception e){
		delete stat;
		return 0;
	}
}

int CShoppinngCartDao::delOne(string userID,int cID)
{
	string sqlStr = "delete from shopping_cart where user_ID = ";
	sqlStr += "\"" + userID + " \" and c_ID =";
	sqlStr += to_string(cID);
	Statement *stat = conn->createStatement();
	stat->execute("set character set gbk");
	try {
		int result = stat->executeUpdate(sqlStr.c_str());
		delete stat;
		conn->commit();
		if (result == 1)
			return 1;
		else
			return 0;
	}
	catch (exception e) {
		conn->rollback();
		delete stat;
		return 0;
	}
}

CShoppinngCartDao::CShoppinngCartDao(Connection * conn)
{
	this->conn = conn;
}

//得到购物车列表
CInfoForSCartList CShoppinngCartDao::getList(string userID)
{
	string sqlStr = "select * from shopping_cart where user_ID = ";
	sqlStr += "\"" + userID + "\"";
	Statement *stat = conn->createStatement();
	stat->execute("set character set gbk");
	ResultSet *res=0;
	try {
		res = stat->executeQuery(sqlStr.c_str());
		list<CShoppingCartItem> lists;
		CShoppingCartItem item;
		while (res->next()) {
			item.setCID(res->getInt("c_ID"));
			item.setUserID(res->getString("user_ID").c_str());
			item.setPrice(res->getDouble("add_price"));
			item.setNum(res->getInt("num"));
			item.setDate(StringToDatetime( res->getString("add_date").c_str()));
			lists.push_back(item);
		}
		delete res;
		delete stat;
		return CInfoForSCartList(GET_CART_SUCCESS,lists);
	}
	catch (exception e) {
		if(res!=NULL)
		    delete res;
		delete stat;
		return CInfoForSCartList(GET_CART_FAIL);
	}
}
