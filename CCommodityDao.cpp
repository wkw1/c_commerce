#include"ConnData.h"
#include "CCommodityDao.h"
#include<time.h>
using namespace std;

tm StringToDatetime(string str)
{
	char *cha = (char*)str.data();// 将string转换成char*。
	tm tm_;         // 定义tm结构体。
    // 定义时间的各个int临时变量。
	int year, month, day, hour, minute, second;
	sscanf_s(cha, "%d-%d-%d %d:%d:%d",
		&year, &month, &day, &hour, &minute, &second);
	// 将string存储的日期时间，转换为int临时变量。
	tm_.tm_year = year ;      
	tm_.tm_mon = month ;                
	tm_.tm_mday = day;                        
	tm_.tm_hour = hour;
	tm_.tm_min = minute;    
	tm_.tm_sec = second;         
	tm_.tm_isdst = 0;                             
	return tm_;                
}


CCommodityDao::CCommodityDao(Connection * conn)
{
	this->conn = conn;
}

//得到食物列表
list<CFood> CCommodityDao::getFoodList()
{
	//执行查询 SQL 语句
	string sqlStr = "select * from";
	sqlStr += " (food  fd inner join type_descrip td on fd.c_type = td.type_ID) ";
	sqlStr += " inner join f_type_descrip ftd on fd.f_type = ftd.f_type_ID ";
	list<CFood> footList;//定义存储列表
	//select * from (food  fd inner join type_descrip tb on fd.c_type = tb.type)
	//inner join type_descrip tb1 on fd.f_type = tb1.type
	Statement* stat = 0;
	stat = conn->createStatement();
    
	stat->execute("SET character set gbk");//设置编码
	ResultSet *res = 0;
	try {
		res = stat->executeQuery(sqlStr.c_str());
		conn->commit();
	}
	catch(exception e){
		//TODO： 出错处理
	}

	/*res->next();
	ResultSetMetaData *rr = res->getMetaData();

	for (int i = 1; i <= rr->getColumnCount(); i++) {
		cout << rr->getColumnName(i).c_str()<< endl;
	}*/
	
	CFood food;
	while (res->next()) {
		food.setCID(res->getInt("c_ID"));
		food.setCNumber(res->getInt("c_number"));
		//商品类型需要结构信息 
		food.setCType({res->getInt("type_ID"),(float)res->getDouble("type_dis_factor"),
			res->getString("type_name").c_str(),res->getString("type_add_info").c_str() });
		//食品类型需要结构信息 
		food.setFType({ res->getInt("f_type_ID"),(float)res->getDouble("f_type_dis_factor"),
			res->getString("f_type_name").c_str(),res->getString("f_type_add_info").c_str() });
		food.setCName( res->getString("c_name").c_str());
		food.setCInfo(res->getString("c_info").c_str());
		food.setFBrand(res->getString("f_brand").c_str());
		//商品的价格和价格因子
		food.setPrice(res->getInt("c_price"));
		food.setCDiscountFactor(res->getDouble("c_dis_factor"));
		//获取生产日期并转化为tm格式
		tm f_pro_time= StringToDatetime(res->getString("f_pro_date").c_str());
		food.setFProductDate(f_pro_time);
		//获取过期日期并转化为tm格式
		tm f_exp_time = StringToDatetime(res->getString("f_exp_date").c_str());
		food.setFEXPDate(f_pro_time);
		

		//获取关联对象的函数

		//将字符串中的数据流读出来用字符串保存--sb MySQL connector++	
		/*istream *str = res->getBlob("f_brand") ;
		string ret;
		char buffer[100];		
		str->read(buffer, sizeof(buffer));
		ret.append(buffer, str->gcount());
		cout << ret << endl;
		ret = "";*/
		footList.push_front(food);
	}

	if(res!=NULL)
	    delete res;
	if (stat != NULL)
		delete stat;
	return footList;
}


//获取图书列表
list<CBook> CCommodityDao::getBookList()
{
	//执行查询 SQL 语句
	string sqlStr = "select * from";
	sqlStr += " (book bk inner join type_descrip td on bk.c_type = td.type_ID) ";
	sqlStr += " inner join b_type_descrip btd on bk.b_type = btd.b_type_ID ";

	list<CBook> bookList;//定义存储列表
						
	Statement* stat = 0;
	stat = conn->createStatement();

	stat->execute("SET character set gbk");//设置编码
	ResultSet *res = 0;
	try {
		res = stat->executeQuery(sqlStr.c_str());
		conn->commit();
	}
	catch (exception e) {
		//TODO： 出错处理
	}

	CBook book;
	while (res->next()) {
		book.setCID(res->getInt("c_ID"));
		book.setCNumber(res->getInt("c_number"));
		//商品类型需要结构信息 
		book.setCType({ res->getInt("type_ID"),(float)res->getDouble("type_dis_factor"),
			res->getString("type_name").c_str(),res->getString("type_add_info").c_str() });
		//图书类型需要结构信息 
		book.setBType({ res->getInt("b_type_ID"),(float)res->getDouble("b_type_dis_factor"),
			res->getString("b_type_name").c_str(),res->getString("b_type_add_info").c_str() });
		book.setCName(res->getString("c_name").c_str());
		book.setCInfo(res->getString("c_info").c_str());
		book.setBISBN(res->getString("b_ISBN").c_str());
		book.setBPress(res->getString("b_press").c_str());
		book.setBAuthor(res->getString("b_author").c_str());


		//商品的价格和价格因子
		book.setPrice(res->getInt("c_price"));
		book.setCDiscountFactor(res->getDouble("c_dis_factor"));
		//获取生产日期并转化为tm格式
		tm f_pro_time = StringToDatetime(res->getString("b_pub_date").c_str());
		book.setBPubDate(f_pro_time);
		
		bookList.push_front(book);
	}

	if (res != NULL)
		delete res;
	if (stat != NULL)
		delete stat;
	return bookList;
}

list<CClothing> CCommodityDao::getClothingList()
{
	//执行查询 SQL 语句
	string sqlStr = "select * from";
	sqlStr += " (clothing  clo inner join type_descrip td on clo.c_type = td.type_ID) ";
	sqlStr += " inner join clo_type_descrip ctd on clo.clo_type = ctd.clo_type_ID ";

	list<CClothing> cloList;//定义存储列表

	Statement* stat = 0;
	stat = conn->createStatement();

	stat->execute("SET character set gbk");//设置编码
	ResultSet *res = 0;
	try {
		res = stat->executeQuery(sqlStr.c_str());
		conn->commit();
	}
	catch (exception e) {
		//TODO： 出错处理
	}

	CClothing clothing;
	while (res->next()) {
		clothing.setCID(res->getInt("c_ID"));
		clothing.setCNumber(res->getInt("c_number"));
		//商品类型需要结构信息 
		clothing.setCType({ res->getInt("type_ID"),(float)res->getDouble("type_dis_factor"),
			res->getString("type_name").c_str(),res->getString("type_add_info").c_str() });
		//图书类型需要结构信息 
		clothing.setCloType({ res->getInt("clo_type_ID"),(float)res->getDouble("clo_type_dis_factor"),
			res->getString("clo_type_name").c_str(),res->getString("clo_type_add_info").c_str() });
		clothing.setCName(res->getString("c_name").c_str());
		clothing.setCInfo(res->getString("c_info").c_str());
		clothing.setCloSize(res->getString("clo_size").c_str());
		clothing.setCloSeasonal(res->getString("clo_seasonal").c_str());

		//商品的价格和价格因子
		clothing.setPrice(res->getInt("c_price"));
		clothing.setCDiscountFactor(res->getDouble("c_dis_factor"));

		cloList.push_front(clothing);
	}

	if (res != NULL)
		delete res;
	if (stat != NULL)
		delete stat;
	return cloList;
}


//购买商品
int CCommodityDao::buyOne(int cID, int type)
{
	//商品数量减一
	string sqlStr = "update ";
	if (type == 11) {
		sqlStr += "food ";
	}
	else if (type==22) {
		sqlStr += "clothing ";
	}
	else if(type==33){
		sqlStr += "book ";
	}
	else {
		return 0;
	}
	sqlStr += "set c_number=c_number-1 where c_number>0 and c_ID = "+to_string(cID);
	Statement *stat = conn->createStatement();
	stat->execute("set character set gbk");
	try {
		int result = stat->executeUpdate(sqlStr.c_str());
		delete stat;
		if (result == 1) {
			return 1;
		}
		else
			return 0;
	}
	catch (exception e) {
		delete stat;
		return 0;
	}
}


CCommodityDao::~CCommodityDao()
{

}
