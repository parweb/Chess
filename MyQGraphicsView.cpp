#include "MyQGraphicsView.h"

using namespace std;

MyQGraphicsView::MyQGraphicsView ( QWidget * parent ) : QGraphicsView( parent ) {
	//this->_echiquier = lechiquier;
}

void MyQGraphicsView::setEchiquier ( Echiquier * lEchiquier ) {
	this->_echiquier = lEchiquier;
}

void MyQGraphicsView::mousePressEvent( QMouseEvent * event ) {
	QMap<int, QString> abscisse;

	abscisse.insert(1, "A");
	abscisse.insert(2, "B");
	abscisse.insert(3, "C");
	abscisse.insert(4, "D");
	abscisse.insert(5, "E");
	abscisse.insert(6, "F");
	abscisse.insert(7, "G");
	abscisse.insert(8, "H");

	QLineEdit * pieceDestination = this->_echiquier->getCentralWidget()->findChild<QLineEdit *>("pieceDestination");

	if (
		( this->_echiquier->xf() == NULL && this->_echiquier->yf() == NULL ) &&
		( this->x() != NULL && this->y() != NULL ) &&
		this->_echiquier->xd() != NULL && this->_echiquier->yd() != NULL
	) {
		this->_echiquier->xf( this->x() );
		this->_echiquier->yf( this->y() );

		pieceDestination->setText( abscisse.value( this->x() ) + QString::number( this->y() ) );

		this->_echiquier->makeMove();
	}
	else {
		pieceDestination->setText( "" );
	}
}

void MyQGraphicsView::x( int _x ) {
	this->__x = _x;
}

void MyQGraphicsView::y( int _y ) {
	this->__y = _y;
}

int MyQGraphicsView::x() {
	return this->__x;
}

int MyQGraphicsView::y() {
	return this->__y;
}
