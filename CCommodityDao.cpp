#include"ConnData.h"
#include "CCommodityDao.h"
#include<time.h>
using namespace std;

tm StringToDatetime(string str)
{
	char *cha = (char*)str.data();// ��stringת����char*��
	tm tm_;         // ����tm�ṹ�塣
    // ����ʱ��ĸ���int��ʱ������
	int year, month, day, hour, minute, second;
	sscanf_s(cha, "%d-%d-%d %d:%d:%d",
		&year, &month, &day, &hour, &minute, &second);
	// ��string�洢������ʱ�䣬ת��Ϊint��ʱ������
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

//�õ�ʳ���б�
list<CFood> CCommodityDao::getFoodList()
{
	//ִ�в�ѯ SQL ���
	string sqlStr = "select * from";
	sqlStr += " (food  fd inner join type_descrip td on fd.c_type = td.type_ID) ";
	sqlStr += " inner join f_type_descrip ftd on fd.f_type = ftd.f_type_ID ";
	list<CFood> footList;//����洢�б�
	//select * from (food  fd inner join type_descrip tb on fd.c_type = tb.type)
	//inner join type_descrip tb1 on fd.f_type = tb1.type
	Statement* stat = 0;
	stat = conn->createStatement();
    
	stat->execute("SET character set gbk");//���ñ���
	ResultSet *res = 0;
	try {
		res = stat->executeQuery(sqlStr.c_str());
		conn->commit();
	}
	catch(exception e){
		//TODO�� ������
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
		//��Ʒ������Ҫ�ṹ��Ϣ 
		food.setCType({res->getInt("type_ID"),(float)res->getDouble("type_dis_factor"),
			res->getString("type_name").c_str(),res->getString("type_add_info").c_str() });
		//ʳƷ������Ҫ�ṹ��Ϣ 
		food.setFType({ res->getInt("f_type_ID"),(float)res->getDouble("f_type_dis_factor"),
			res->getString("f_type_name").c_str(),res->getString("f_type_add_info").c_str() });
		food.setCName( res->getString("c_name").c_str());
		food.setCInfo(res->getString("c_info").c_str());
		food.setFBrand(res->getString("f_brand").c_str());
		//��Ʒ�ļ۸�ͼ۸�����
		food.setPrice(res->getInt("c_price"));
		food.setCDiscountFactor(res->getDouble("c_dis_factor"));
		//��ȡ�������ڲ�ת��Ϊtm��ʽ
		tm f_pro_time= StringToDatetime(res->getString("f_pro_date").c_str());
		food.setFProductDate(f_pro_time);
		//��ȡ�������ڲ�ת��Ϊtm��ʽ
		tm f_exp_time = StringToDatetime(res->getString("f_exp_date").c_str());
		food.setFEXPDate(f_pro_time);
		

		//��ȡ��������ĺ���

		//���ַ����е����������������ַ�������--sb MySQL connector++	
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


//��ȡͼ���б�
list<CBook> CCommodityDao::getBookList()
{
	//ִ�в�ѯ SQL ���
	string sqlStr = "select * from";
	sqlStr += " (book bk inner join type_descrip td on bk.c_type = td.type_ID) ";
	sqlStr += " inner join b_type_descrip btd on bk.b_type = btd.b_type_ID ";

	list<CBook> bookList;//����洢�б�
						
	Statement* stat = 0;
	stat = conn->createStatement();

	stat->execute("SET character set gbk");//���ñ���
	ResultSet *res = 0;
	try {
		res = stat->executeQuery(sqlStr.c_str());
		conn->commit();
	}
	catch (exception e) {
		//TODO�� ������
	}

	CBook book;
	while (res->next()) {
		book.setCID(res->getInt("c_ID"));
		book.setCNumber(res->getInt("c_number"));
		//��Ʒ������Ҫ�ṹ��Ϣ 
		book.setCType({ res->getInt("type_ID"),(float)res->getDouble("type_dis_factor"),
			res->getString("type_name").c_str(),res->getString("type_add_info").c_str() });
		//ͼ��������Ҫ�ṹ��Ϣ 
		book.setBType({ res->getInt("b_type_ID"),(float)res->getDouble("b_type_dis_factor"),
			res->getString("b_type_name").c_str(),res->getString("b_type_add_info").c_str() });
		book.setCName(res->getString("c_name").c_str());
		book.setCInfo(res->getString("c_info").c_str());
		book.setBISBN(res->getString("b_ISBN").c_str());
		book.setBPress(res->getString("b_press").c_str());
		book.setBAuthor(res->getString("b_author").c_str());


		//��Ʒ�ļ۸�ͼ۸�����
		book.setPrice(res->getInt("c_price"));
		book.setCDiscountFactor(res->getDouble("c_dis_factor"));
		//��ȡ�������ڲ�ת��Ϊtm��ʽ
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
	//ִ�в�ѯ SQL ���
	string sqlStr = "select * from";
	sqlStr += " (clothing  clo inner join type_descrip td on clo.c_type = td.type_ID) ";
	sqlStr += " inner join clo_type_descrip ctd on clo.clo_type = ctd.clo_type_ID ";

	list<CClothing> cloList;//����洢�б�

	Statement* stat = 0;
	stat = conn->createStatement();

	stat->execute("SET character set gbk");//���ñ���
	ResultSet *res = 0;
	try {
		res = stat->executeQuery(sqlStr.c_str());
		conn->commit();
	}
	catch (exception e) {
		//TODO�� ������
	}

	CClothing clothing;
	while (res->next()) {
		clothing.setCID(res->getInt("c_ID"));
		clothing.setCNumber(res->getInt("c_number"));
		//��Ʒ������Ҫ�ṹ��Ϣ 
		clothing.setCType({ res->getInt("type_ID"),(float)res->getDouble("type_dis_factor"),
			res->getString("type_name").c_str(),res->getString("type_add_info").c_str() });
		//ͼ��������Ҫ�ṹ��Ϣ 
		clothing.setCloType({ res->getInt("clo_type_ID"),(float)res->getDouble("clo_type_dis_factor"),
			res->getString("clo_type_name").c_str(),res->getString("clo_type_add_info").c_str() });
		clothing.setCName(res->getString("c_name").c_str());
		clothing.setCInfo(res->getString("c_info").c_str());
		clothing.setCloSize(res->getString("clo_size").c_str());
		clothing.setCloSeasonal(res->getString("clo_seasonal").c_str());

		//��Ʒ�ļ۸�ͼ۸�����
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


//������Ʒ
int CCommodityDao::buyOne(int cID, int type)
{
	//��Ʒ������һ
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
