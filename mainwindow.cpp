#include "mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget * parent) : QMainWindow(parent) {
	this->centralWidget = new QWidget( parent );
	this->centralWidget->setObjectName("centralWidget");

	this->setCentralWidget( this->centralWidget );

	this->_Echiquier = new Echiquier( this->centralWidget );
}

MainWindow::~MainWindow()
{
	delete this->_Echiquier;
}

MyGrid::MyGrid( QWidget * parent ) : QGridLayout( parent ) {

}
