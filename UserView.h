#pragma once

#include <QtWidgets>
#include<QCloseEvent>
#include "ui_UserView.h"
#include "CUserOp.h"
class UserView : public QMainWindow
{
	Q_OBJECT //��������ĺ�

private:
	Ui::UserView ui;
	CUserOp *userOp=NULL;

	CCommodity *cc = NULL;//�û���Ҫ�������Ʒ

private:
	QWidget *widgetScrollArea = NULL;
	QScrollArea *scrollArea = NULL;
	QTableWidget *foodWidget = NULL;
	QTableWidget *bookWidget = NULL;
	QTableWidget *clothingWidget = NULL;
	QListWidget *shopCartWidget = NULL;

	QWidget *myInfoWidget = NULL;

	QLabel *detailInfoWight = NULL;//ѡ����Ʒ֮����ʾ��ϸ����Ʒ��Ϣ
	QPushButton *buyWidget = NULL;//���������Ʒ�İ�ť
	QPushButton *addCartWidget = NULL;//���빺�ﳵ
	QLabel *opInfoWidget = NULL;//��ʾ�û�������Ϣ����Ŀ


	//QWidget *qqlockWidget = NULL;
	//QWidget *spaceWidget = NULL;

public:
	//���캯������Ҫ���� һ�����ݿ����Ӷ����һ���û���ID
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