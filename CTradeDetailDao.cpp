#include "CTradeDetailDao.h"
using namespace std;
CTradeDetailDao::CTradeDetailDao(Connection * conn)
{
	this->conn = conn;
}
int CTradeDetailDao::addOne(CTradeDetail detail)
{
	//增加一条消费记录
	string sqlStr = "insert into trade_detail(user_ID,c_ID,trade_money) values( ";
	sqlStr += "\""+detail.getUserID()+"\",";
	sqlStr += to_string(detail.getCID()) + ",";
	sqlStr += to_string(detail.getTradeMoney()) + ")";

	Statement *stat = conn->createStatement();
	stat->execute("set character set gbk");

	try {
		int result = stat->executeUpdate(sqlStr.c_str());
		delete stat;
		if (result == 1)
			return 1;
		else
			return 0;
	}
	catch (exception e) {
		delete stat;
		return 0;
	}
}
