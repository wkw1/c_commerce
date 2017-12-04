#pragma once

#include <QtWidgets>
#include<QCloseEvent>
#include "ui_UserView.h"
#include "CUserOp.h"
class UserView : public QMainWindow
{
	Q_OBJECT //必须包含的宏

private:
	Ui::UserView ui;
	CUserOp *userOp=NULL;

	CCommodity *cc = NULL;//用户想要购买的商品

private:
	QWidget *widgetScrollArea = NULL;
	QScrollArea *scrollArea = NULL;
	QTableWidget *foodWidget = NULL;
	QTableWidget *bookWidget = NULL;
	QTableWidget *clothingWidget = NULL;
	QListWidget *shopCartWidget = NULL;

	QWidget *myInfoWidget = NULL;

	QLabel *detailInfoWight = NULL;//选择商品之后显示详细的商品信息
	QPushButton *buyWidget = NULL;//点击购买商品的按钮
	QPushButton *addCartWidget = NULL;//加入购物车
	QLabel *opInfoWidget = NULL;//显示用户操作信息的栏目


	//QWidget *qqlockWidget = NULL;
	//QWidget *spaceWidget = NULL;

public:
	//构造函数，需要传入 一个数据库连接对象和一个用户的ID
	UserView( CUserOp *op=NULL,QWidget *parent=NULL );
	~UserView();
protected:
	void closeEvent(QCloseEvent *event);

private:
	void initCommListWidget();
	void initSCartWidget();
	void initMyInfoWidget();
	void initBindCartWidget();
	void updateDetail();

protected:
	//void paintEvent(QPaintEvent *event);
	//void mousePressEvent(QMouseEvent *event);
	//void mouseReleaseEvent(QMouseEvent *event);
	//void mouseMoveEvent(QMouseEvent *event);
	void resizeEvent(QResizeEvent *event);


private slots:
	void slot_CurrentChanged(int index);
	void slot_ItemClicked(QTableWidgetItem *item);
	void slot_ValueChanged(int value);
	void slot_BuyOne();
	void slot_bookTableChoose(int row,int col);
	void slot_foodTableChoose(int row, int col);
	void slot_clothTableChoose(int row, int col);
};