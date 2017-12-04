#include "UserView.h"

UserView::UserView(CUserOp *userOp, QWidget * parent) 
	: QMainWindow(parent){
	/*
	  �����ʼ��	
	*/
	ui.setupUi(this);
	ui.userLable->setText(QString::fromLocal8Bit(userOp->getUser().getUserName().data()));
	scrollArea = new QScrollArea(this);
	scrollArea->setStyleSheet("QScrollArea{background:transparent;}"
		"QScrollBar::vertical{background:#35A739;border:-5px solid grey;margin:-2px 0px 0px 0px;width:8px;}"
		"QScrollBar::horizontal{background:#35A739;border:0px solid #126691;height:10px;}"
		"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {background:#D3D3D3;}"
	);

	scrollArea->setFrameShape(QFrame::NoFrame);
	scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	scrollArea->setFocusPolicy(Qt::NoFocus);

	//��ʼ���û�����
	this->userOp = userOp;

	//�����źŲۺ���
	connect(ui.tabWidget, SIGNAL(currentChanged(int)), this, SLOT(slot_CurrentChanged(int)));
	slot_CurrentChanged(0);
}

//�رմ���
void UserView::closeEvent(QCloseEvent *event)
{
	userOp->signOut();
}


UserView::~UserView()
{
	if (widgetScrollArea != NULL)
		widgetScrollArea->close();
	if (scrollArea != NULL)
		scrollArea->close();
	if (foodWidget != NULL)
		foodWidget->close();
	if (bookWidget != NULL)
		bookWidget->close();
	if (clothingWidget != NULL)
		clothingWidget->close();
	if (shopCartWidget != NULL)
		shopCartWidget->close();
	if (myInfoWidget != NULL)
		myInfoWidget->close();

	if (userOp != NULL)
		delete userOp;
	if (cc != NULL)
		delete userOp;
}



//���֮�󶥲� tabWidget ��Ķ��� 
void UserView::slot_CurrentChanged(int index)
{
	scrollArea->takeWidget();
	widgetScrollArea = new QWidget(this);
	widgetScrollArea->setStyleSheet("background:transparent;");
	scrollArea->setWidget(widgetScrollArea);
	if (index == 0) {
		/*contentsWidget->addItem(tr("login"));
		contentsWidget->addItem(tr("mainpanel"));
		contentsWidget->addItem(tr("status"));
		contentsWidget->addItem(tr("session"));*/
		initCommListWidget();
	}
	else if (index == 1) {
		/*contentsWidget->addItem(tr("password"));
		contentsWidget->addItem(tr("qqlock"));*/
		initSCartWidget();
	}
	else if (index == 2) {
		/*contentsWidget->addItem(tr("spacepermission"));*/
		initMyInfoWidget();
	}
	else if (index == 3) {
		initBindCartWidget();
	}
	/*if (contentsWidget->count() > 0) {
		/*contentsWidget->setCurrentRow(0);}*/
}


void UserView::resizeEvent(QResizeEvent * event)
{
	ui.tabWidget->setGeometry(0, 35, this->width(), this->height() - 35);
	//contentsWidget->setGeometry(0, 71, 130, this->height() - 71);
	scrollArea->setGeometry(131, 72, this->width() - 132, this->height() - 73);
	//minButton->move(width() - 27 - closeButton->width(), 6);
	//closeButton->move(width() - 27, 6);
	move((QApplication::desktop()->width() - width()) / 2, (QApplication::desktop()->height() - height()) / 2);
	QWidget::resizeEvent(event);
}


//ѡ����Ŀ���Ķ���
void UserView::slot_ItemClicked(QTableWidgetItem * item)
{
	//detailInfoWight->setText(item->text());
}


void UserView::slot_ValueChanged(int value)
{
}


//������Ʒ
void UserView::slot_BuyOne()
{
	if (cc == NULL) {
		opInfoWidget->setText(QString::fromLocal8Bit("��ѡ����Ʒ����"));
		return;
	}
	if (userOp==NULL) {
		opInfoWidget->setText(QString::fromLocal8Bit("δ��¼����"));
		return;
	}
	string str = userOp->buyCommodity(*cc, 1, 1).info;
	opInfoWidget->setText(QString::fromLocal8Bit(str.data()));
}

void UserView::slot_bookTableChoose(int row, int col)
{
	cc->setCID(bookWidget->item(row, 0)->text().toInt());
	cc->setCType({33});
	cc->setCName(bookWidget->item(row, 1)->text().toStdString());
	cc->setPrice(bookWidget->item(row, 5)->text().toFloat());
	updateDetail();
}

void UserView::slot_foodTableChoose(int row, int col)
{
	cc->setCID(foodWidget->item(row, 0)->text().toInt());
	cc->setCType({ 11 });
	cc->setCName(foodWidget->item(row, 1)->text().toStdString());
	cc->setPrice(foodWidget->item(row, 5)->text().toFloat());
	updateDetail();
}

void UserView::slot_clothTableChoose(int row, int col)
{
	cc->setCID(clothingWidget->item(row, 0)->text().toInt());
	cc->setCType({ 22 });
	cc->setCName(clothingWidget->item(row, 1)->text().toStdString());
	cc->setPrice(clothingWidget->item(row, 5)->text().toFloat());
	updateDetail();
}

//��ʾѡ����Ϣ
void UserView::updateDetail() {
	detailInfoWight->setText(
		QString::fromStdString("ID:" + to_string(cc->getCID()))
		+ QString::fromLocal8Bit("\n���ƣ�")
		+ QString::fromStdString(cc->getCName())
		+ QString::fromLocal8Bit("\n�۸�")
		+ QString::fromStdString( to_string(cc->getPrice())
	    ));
}


//��Ʒ�б�ĳ�ʼ������
void UserView::initCommListWidget()
{
	/************ ��ȡ��Ʒ **************/
	CInfoForCList cList = userOp->viewCommodity();
	cc = new CCommodity();//��ʼ����Ʒ


	/*
	   ʳ���б���ʾ
	*/
	QLabel *foodLable = new QLabel(widgetScrollArea);
	foodLable->setText("shiwu !!!!");
	foodLable->setGeometry(50, 10, 150, 30);
	foodLable->show();
	
	list<CFood>foodList = cList.getFoodList();
	list<CFood>::iterator food = foodList.begin();
	int foodListSize = foodList.size() * 50 + 50;

	foodWidget = new QTableWidget(widgetScrollArea);
	foodWidget->setColumnCount(6);
	foodWidget->setRowCount(foodList.size());

	foodWidget->setHorizontalHeaderLabels(QStringList() <<
		QString::fromLocal8Bit("ID") 
		<< QString::fromLocal8Bit("��Ʒ����")
		<< QString::fromLocal8Bit("˵������") 
		<< QString::fromLocal8Bit("ʣ������")
		<< QString::fromLocal8Bit("ԭ��")
		<< QString::fromLocal8Bit("�ּ�") );
	foodWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  //����ѡ�еķ�ʽ
	foodWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //��ֹ�޸�	
	//bookWidget->setSelectionMode(QAbstractItemView::SingleSelection);  //����Ϊ����ѡ�е���

	for (int i = 0; food != foodList.end(); i++) {
		foodWidget->setRowHeight(i, 50);
		QTableWidgetItem *item0 = new QTableWidgetItem(QString::number((*food).getCID()));
		foodWidget->setItem(i, 0, item0);

		QTableWidgetItem *item1 = new QTableWidgetItem(QString::fromLocal8Bit((*food).getCName().data()));
		foodWidget->setItem(i, 1, item1);

		QTableWidgetItem *item2 = new QTableWidgetItem(QString::fromLocal8Bit((*food).getCInfo().data()));
		foodWidget->setItem(i, 2, item2);

		QTableWidgetItem *item5 = new QTableWidgetItem(QString::number((*food).getCNumber()));
		foodWidget->setItem(i, 3, item5);

		QTableWidgetItem *item3 = new QTableWidgetItem(QString::number((*food).getPrice()));
		foodWidget->setItem(i, 4, item3);

		QTableWidgetItem *item4 = new QTableWidgetItem(QString::number((*food).getFinalPrice()));
		foodWidget->setItem(i, 5, item4);

		*food++;
	}
	foodWidget->setGeometry(50, 50, 900, foodListSize);
	foodWidget->show();

	//�����źŲ�
	connect(foodWidget, SIGNAL(cellClicked(int, int)),
		this, SLOT(slot_foodTableChoose(int, int)));
	
	/*
	  ͼ�����ʾ
	*/
	QLabel *boodLable = new QLabel(widgetScrollArea);
	boodLable->setText("booList");
	boodLable->setGeometry(50, foodListSize+60, 150, 30);
	boodLable->show();
	list<CBook>bookList = cList.getBookList();
	list<CBook>::iterator book = bookList.begin();
	int bookListSize = bookList.size() * 50+50;

	bookWidget = new QTableWidget(widgetScrollArea);
	bookWidget->setColumnCount(6);
	bookWidget->setRowCount(bookList.size());

	bookWidget->setHorizontalHeaderLabels(QStringList() << 
		QString::fromLocal8Bit("ID")
		<< QString::fromLocal8Bit("��Ʒ����")
		<< QString::fromLocal8Bit("˵������")
		<< QString::fromLocal8Bit("ʣ������")
		<< QString::fromLocal8Bit("ԭ��")
		<< QString::fromLocal8Bit("�ּ�"));
	bookWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  //����ѡ�еķ�ʽ
	bookWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //��ֹ�޸�
	bookWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
	//bookWidget->setSelectionMode(QAbstractItemView::SingleSelection);  //����Ϊ����ѡ�е���

	for (int i = 0; book != bookList.end(); i++) {
		bookWidget->setRowHeight(i,50);
		QTableWidgetItem *item0 = new QTableWidgetItem(QString::number((*book).getCID()));
		bookWidget->setItem(i, 0, item0);

		QTableWidgetItem *item1 = new QTableWidgetItem(QString::fromLocal8Bit((*book).getCName().data()));
		bookWidget->setItem(i, 1, item1);

		QTableWidgetItem *item2 = new QTableWidgetItem(QString::fromLocal8Bit((*book).getCInfo().data()));
		bookWidget->setItem(i, 2, item2);

		QTableWidgetItem *item3 = new QTableWidgetItem(QString::number((*book).getCNumber()));
		bookWidget->setItem(i, 3, item3);

		QTableWidgetItem *item4 = new QTableWidgetItem(QString::number((*book).getPrice()));
		bookWidget->setItem(i, 4, item4);
		
		QTableWidgetItem *item5 = new QTableWidgetItem(QString::number((*book).getFinalPrice()));
		bookWidget->setItem(i, 5, item5);
		*book++;
	}

	bookWidget->setGeometry(50, 100 + foodListSize, 900, bookListSize);
	bookWidget->show();
	//�����źŲ�
	/*connect(bookWidget, SIGNAL(itemClicked(QTableWidgetItem*)),
	this, SLOT(slot_ItemClicked(QTableWidgetItem*)));*/
	connect(bookWidget, SIGNAL(cellClicked(int, int)),
		this, SLOT(slot_bookTableChoose(int, int)));


	/*
	�·�����ʾ
	*/
	QLabel *clothLable = new QLabel(widgetScrollArea);
	clothLable->setText("clothing");
	clothLable->setGeometry(50, foodListSize + bookListSize + 150, 150, 30);
	clothLable->show();
	list<CClothing>clothList = cList.getClothingList();
	list<CClothing>::iterator cloth = clothList.begin();
	int clothListSize = clothList.size() * 50 + 50;

	clothingWidget = new QTableWidget(widgetScrollArea);
	clothingWidget->setColumnCount(6);
	clothingWidget->setRowCount(clothList.size());

	clothingWidget->setHorizontalHeaderLabels(QStringList() <<
		QString::fromLocal8Bit("ID")
		<< QString::fromLocal8Bit("��Ʒ����")
		<< QString::fromLocal8Bit("˵������")
		<< QString::fromLocal8Bit("ʣ������")
		<< QString::fromLocal8Bit("ԭ��")
		<< QString::fromLocal8Bit("�ּ�"));
	clothingWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  //����ѡ�еķ�ʽ
	clothingWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //��ֹ�޸�
	clothingWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
	//bookWidget->setSelectionMode(QAbstractItemView::SingleSelection);  //����Ϊ����ѡ�е���

	for (int i = 0; cloth != clothList.end(); i++) {
		clothingWidget->setRowHeight(i, 50);
		QTableWidgetItem *item0 = new QTableWidgetItem(QString::number((*cloth).getCID()));
		clothingWidget->setItem(i, 0, item0);

		QTableWidgetItem *item1 = new QTableWidgetItem(QString::fromLocal8Bit((*cloth).getCName().data()));
		clothingWidget->setItem(i, 1, item1);

		QTableWidgetItem *item2 = new QTableWidgetItem(QString::fromLocal8Bit((*cloth).getCInfo().data()));
		clothingWidget->setItem(i, 2, item2);

		QTableWidgetItem *item3 = new QTableWidgetItem(QString::number((*cloth).getCNumber()));
		clothingWidget->setItem(i, 3, item3);

		QTableWidgetItem *item4 = new QTableWidgetItem(QString::number((*cloth).getPrice()));
		clothingWidget->setItem(i, 4, item4);

		QTableWidgetItem *item5 = new QTableWidgetItem(QString::number((*cloth).getFinalPrice()));
		clothingWidget->setItem(i, 5, item5);
		*cloth++;
	}

	clothingWidget->setGeometry(50, 200 + foodListSize+bookListSize, 900, clothListSize);
	clothingWidget->show();

	//�����źŲ�
	/*connect(bookWidget, SIGNAL(itemClicked(QTableWidgetItem*)),
	this, SLOT(slot_ItemClicked(QTableWidgetItem*)));*/
	connect(clothingWidget, SIGNAL(cellClicked(int, int)),
		this, SLOT(slot_clothTableChoose(int, int)));


	
	/************�û������ؼ�**************/
	detailInfoWight = new QLabel(widgetScrollArea);
	detailInfoWight->setText("the commotity you choose");
	detailInfoWight->setGeometry(1000, 50, 150,200);
	detailInfoWight->show();

	buyWidget = new QPushButton(widgetScrollArea);
	buyWidget->setText("buy");
	buyWidget->setGeometry(1000, 200, 100, 50);
	buyWidget->show();
	QPalette pal = buyWidget->palette();
	pal.setColor(QPalette::Button, Qt::blue);
	buyWidget->setPalette(pal);
	buyWidget->setAutoFillBackground(true);
	buyWidget->setFlat(true);

	opInfoWidget = new QLabel(widgetScrollArea);
	opInfoWidget->setText("buy info!!");
	opInfoWidget->setGeometry(1000, 300, 150, 100);
	opInfoWidget->show();

	connect(buyWidget, SIGNAL(clicked()), this, SLOT(slot_BuyOne()));
	//�ܽ���ߴ�
	widgetScrollArea->resize(1200, 1000);
}
//���ﳵ�ĳ�ʼ������
void UserView::initSCartWidget()
{


}

//�ҵ���Ϣ��ʼ������
void UserView::initMyInfoWidget()
{
	//widgetScrollArea = new QWidget(this);
	widgetScrollArea->setStyleSheet("background:transparent;");
	scrollArea->setWidget(widgetScrollArea);

	QLabel *mInfo = new QLabel(widgetScrollArea);
	
	mInfo->setText(
		QString::fromStdString("ID:" + userOp->getUser().getUserID())
		+ QString::fromLocal8Bit("\n������")
		+ QString::fromStdString(userOp->getUser().getUserName())
		+ QString::fromLocal8Bit("\n����������")
		+ QString::fromStdString(to_string(userOp->getUser().getConsumNumber()))
		+ QString::fromLocal8Bit("\n���п���Ŀ��")
		+ QString::fromStdString(to_string(userOp->getUser().getBCNumber()))
		+ QString::fromLocal8Bit("\nע��ʱ�䣺")
		+ QString::fromStdString(to_string(userOp->getUser().getRegisterDate().tm_year))
	);
	mInfo->setGeometry(50, 50, 300, 500);
	mInfo->show();

	widgetScrollArea->resize(1200, 1000);
}
//�����п�
void UserView::initBindCartWidget()
{

}
