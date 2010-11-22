#include <iostream>

#include "Echiquier.h"

using namespace std;

Echiquier::Echiquier() {
	for ( int i = 0; i < 64; i++ ) {
		m_cases[i] = NULL;
	}
}

Piece* Echiquier::getPiece( int x, int y ) {
	return m_cases[ getCase( x, y ) ];
}

bool Echiquier::create( Ui::MainWindow* & _ui ) {
	JoueurBlanc JoueurBlanc;
	JoueurNoir  JoueurNoir;

	JoueurBlanc.placerPieces( *this );
	JoueurNoir.placerPieces( *this );

	// -------------------------------- Roi

	Roi RoiBlanc(true);
	this->enleverPiece(5,8);
	this->placer(&RoiBlanc);

	Roi RoiNoir(false);
	this->enleverPiece(5,1);
	this->placer(&RoiNoir);

	// -------------------------------- Reine

	Reine ReineBlanc(true);
	this->enleverPiece(4,8);
	this->placer(&ReineBlanc);

	Reine ReineNoir(false);
	this->enleverPiece(4,1);
	this->placer(&ReineNoir);

	// -------------------------------- Tour

	Tour TourBlancUn(true, 1);
	this->enleverPiece(1,8);
	this->placer(&TourBlancUn);

	Tour TourBlancDeux(true, 8);
	this->enleverPiece(8,8);
	this->placer(&TourBlancDeux);

	Tour TourNoirUn(false, 1);
	this->enleverPiece(1,1);
	this->placer(&TourNoirUn);

	Tour TourNoirDeux(false, 8);
	this->enleverPiece(8,1);
	this->placer(&TourNoirDeux);

	// -------------------------------- Cavalier

	Cavalier CavalierBlancUn(true, 2);
	this->enleverPiece(2,8);
	this->placer(&CavalierBlancUn);

	Cavalier CavalierBlancDeux(true, 7);
	this->enleverPiece(7,8);
	this->placer(&CavalierBlancDeux);

	Cavalier CavalierNoirUn(false, 2);
	this->enleverPiece(2,1);
	this->placer(&CavalierNoirUn);

	Cavalier CavalierNoirDeux(false, 7);
	this->enleverPiece(7,1);
	this->placer(&CavalierNoirDeux);

	// -------------------------------- Fou

	Fou FouBlancUn(true, 3);
	this->enleverPiece(3,8);
	this->placer(&FouBlancUn);

	Fou FouBlancDeux(true, 6);
	this->enleverPiece(6,8);
	this->placer(&FouBlancDeux);

	Fou FouNoirUn(false, 3);
	this->enleverPiece(3,1);
	this->placer(&FouNoirUn);

	Fou FouNoirDeux(false, 6);
	this->enleverPiece(6,1);
	this->placer(&FouNoirDeux);

	// -------------------------------- Pion

	Pion PionBlancUn(true, 1);
	this->enleverPiece(1,7);
	this->placer(&PionBlancUn);

	Pion PionBlancDeux(true, 2);
	this->enleverPiece(2,7);
	this->placer(&PionBlancDeux);

	Pion PionBlancTrois(true, 3);
	this->enleverPiece(3,7);
	this->placer(&PionBlancTrois);

	Pion PionBlancQuatre(true, 4);
	this->enleverPiece(4,7);
	this->placer(&PionBlancQuatre);

	Pion PionBlancCinq(true, 5);
	this->enleverPiece(5,7);
	this->placer(&PionBlancCinq);

	Pion PionBlancSix(true, 6);
	this->enleverPiece(6,7);
	this->placer(&PionBlancSix);

	Pion PionBlancSept(true, 7);
	this->enleverPiece(7,7);
	this->placer(&PionBlancSept);

	Pion PionBlancHuit(true, 8);
	this->enleverPiece(8,7);
	this->placer(&PionBlancHuit);

	Pion PionNoirUn(false, 1);
	this->enleverPiece(1,2);
	this->placer(&PionNoirUn);

	Pion PionNoirDeux(false, 2);
	this->enleverPiece(2,2);
	this->placer(&PionNoirDeux);

	Pion PionNoirTrois(false, 3);
	this->enleverPiece(3,2);
	this->placer(&PionNoirTrois);

	Pion PionNoirQuatre(false, 4);
	this->enleverPiece(4,2);
	this->placer(&PionNoirQuatre);

	Pion PionNoirCinq(false, 5);
	this->enleverPiece(5,2);
	this->placer(&PionNoirCinq);

	Pion PionNoirSix(false, 6);
	this->enleverPiece(6,2);
	this->placer(&PionNoirSix);

	Pion PionNoirSept(false, 7);
	this->enleverPiece(7,2);
	this->placer(&PionNoirSept);

	Pion PionNoirHuit(false, 8);
	this->enleverPiece(8,2);
	this->placer(&PionNoirHuit);

	return true;
}

bool Echiquier::placer( Piece* p ) {
	if (
		( p->x() >= 1 ) && ( p->x() <= 8 )
		&& ( p->y() >= 1 ) && ( p->y() <= 8 )
		&& ( p != NULL )
	) {
		m_cases[ getCase( p->x(), p->y() ) ] = p;

		int xi = 70;
		int yi = 105;
		int exi = 50;
		int eyi = 50;

		int xf = xi + ( exi * ( p->x() - 1 ) );
		int yf = yi + ( eyi * ( p->y() - 1 ) );

		p->move( xf, yf );

		//QString plop666 = p->myType();

		return true;
	}

	return false;
}

bool Echiquier::deplacer( Piece* p, int x, int y ) {
	p->move( x, y );

	enleverPiece( p->x(), p->y() );
	return placer( p );
}

bool Echiquier::deplacer( int xd, int yd, int xf, int yf ) {
	return deplacer( getPiece( xd, yd ), xf, yf );
}

Piece* Echiquier::enleverPiece( int x, int y ) {
	if (
		( getPiece( x, y ) != NULL )
		&& ( x >= 1 ) && ( x <= 8 )
		&& ( y >= 1 ) && ( y <= 8 )
	) {
		int place = getCase( x, y );

		Piece *tmp = m_cases[ place ];
		m_cases[ place ] = tmp;

		return tmp;
	}

	return NULL;
}


int Echiquier::getCase( int x, int y ) {
	return ( x - 1 + ( y - 1 ) * 8 );
}

QWidget* Echiquier::getQWidget( QWidget* & _centralWidget ) {
	QGraphicsView *caseA1;
	QGraphicsView *caseB1;
	QGraphicsView *caseD1;
	QGraphicsView *caseC1;
	QGraphicsView *caseG1;
	QGraphicsView *caseF1;
	QGraphicsView *caseE1;
	QGraphicsView *caseH1;
	QGraphicsView *caseA2;
	QGraphicsView *caseC2;
	QGraphicsView *caseD2;
	QGraphicsView *caseB2;
	QGraphicsView *caseH2;
	QGraphicsView *caseG2;
	QGraphicsView *caseE2;
	QGraphicsView *caseF2;
	QGraphicsView *caseF4;
	QGraphicsView *caseB3;
	QGraphicsView *caseC3;
	QGraphicsView *caseA3;
	QGraphicsView *caseG3;
	QGraphicsView *caseC4;
	QGraphicsView *caseD4;
	QGraphicsView *caseH3;
	QGraphicsView *caseG4;
	QGraphicsView *caseF3;
	QGraphicsView *caseB4;
	QGraphicsView *caseD3;
	QGraphicsView *caseE4;
	QGraphicsView *caseE3;
	QGraphicsView *caseA4;
	QGraphicsView *caseH4;
	QGraphicsView *caseH8;
	QGraphicsView *caseG7;
	QGraphicsView *caseE7;
	QGraphicsView *caseH7;
	QGraphicsView *caseB6;
	QGraphicsView *caseC5;
	QGraphicsView *caseC6;
	QGraphicsView *caseF8;
	QGraphicsView *caseA8;
	QGraphicsView *caseD8;
	QGraphicsView *caseB8;
	QGraphicsView *caseD6;
	QGraphicsView *caseF5;
	QGraphicsView *caseG6;
	QGraphicsView *caseE5;
	QGraphicsView *caseD7;
	QGraphicsView *caseC7;
	QGraphicsView *caseG5;
	QGraphicsView *caseE6;
	QGraphicsView *caseD5;
	QGraphicsView *caseH6;
	QGraphicsView *caseF6;
	QGraphicsView *caseE8;
	QGraphicsView *caseB7;
	QGraphicsView *caseG8;
	QGraphicsView *caseF7;
	QGraphicsView *caseB5;
	QGraphicsView *caseC8;
	QGraphicsView *caseA5;
	QGraphicsView *caseH5;
	QGraphicsView *caseA6;
	QGraphicsView *caseA7;

	caseA1 = new QGraphicsView(_centralWidget);
	caseA1->setObjectName(QString::fromUtf8("caseA1"));
	caseA1->setGeometry(QRect(60, 100, 50, 50));
	caseA1->setAutoFillBackground(false);

	caseB1 = new QGraphicsView(_centralWidget);
	caseB1->setObjectName(QString::fromUtf8("caseB1"));
	caseB1->setGeometry(QRect(110, 100, 50, 50));
	caseB1->setAutoFillBackground(false);
	caseB1->setStyleSheet(QString::fromUtf8("background:rgb(100, 100, 100);"));

	QBrush colorGris(QColor(27, 28, 0, 255));
	colorGris.setStyle(Qt::SolidPattern);
	caseB1->setBackgroundBrush(colorGris);

	QBrush colorNoir(QColor(0, 0, 0, 255));
	colorNoir.setStyle(Qt::SolidPattern);
	caseB1->setForegroundBrush(colorNoir);

	caseD1 = new QGraphicsView(_centralWidget);
	caseD1->setObjectName(QString::fromUtf8("caseD1"));
	caseD1->setGeometry(QRect(210, 100, 50, 50));
	caseD1->setAutoFillBackground(false);
	caseD1->setStyleSheet(QString::fromUtf8("background:rgb(100, 100, 100);"));
	caseD1->setBackgroundBrush(colorGris);
	caseD1->setForegroundBrush(colorNoir);

	caseC1 = new QGraphicsView(_centralWidget);
	caseC1->setObjectName(QString::fromUtf8("caseC1"));
	caseC1->setGeometry(QRect(160, 100, 50, 50));
	caseC1->setAutoFillBackground(false);

	caseG1 = new QGraphicsView(_centralWidget);
	caseG1->setObjectName(QString::fromUtf8("caseG1"));
	caseG1->setGeometry(QRect(360, 100, 50, 50));
	caseG1->setAutoFillBackground(false);

	caseF1 = new QGraphicsView(_centralWidget);
	caseF1->setObjectName(QString::fromUtf8("caseF1"));
	caseF1->setGeometry(QRect(310, 100, 50, 50));
	caseF1->setAutoFillBackground(false);
	caseF1->setStyleSheet(QString::fromUtf8("background:rgb(100, 100, 100);"));
	caseF1->setBackgroundBrush(colorGris);
	caseF1->setForegroundBrush(colorNoir);

	caseE1 = new QGraphicsView(_centralWidget);
	caseE1->setObjectName(QString::fromUtf8("caseE1"));
	caseE1->setGeometry(QRect(260, 100, 50, 50));
	caseE1->setAutoFillBackground(false);

	caseH1 = new QGraphicsView(_centralWidget);
	caseH1->setObjectName(QString::fromUtf8("caseH1"));
	caseH1->setGeometry(QRect(410, 100, 50, 50));
	caseH1->setAutoFillBackground(false);
	caseH1->setStyleSheet(QString::fromUtf8("background:rgb(100, 100, 100);"));
	caseH1->setBackgroundBrush(colorGris);
	caseH1->setForegroundBrush(colorNoir);

	caseA2 = new QGraphicsView(_centralWidget);
	caseA2->setObjectName(QString::fromUtf8("caseA2"));
	caseA2->setGeometry(QRect(60, 150, 50, 50));
	caseA2->setAutoFillBackground(false);
	caseA2->setStyleSheet(QString::fromUtf8("background:rgb(100, 100, 100);"));
	caseA2->setBackgroundBrush(colorGris);
	caseA2->setForegroundBrush(colorNoir);

	caseC2 = new QGraphicsView(_centralWidget);
	caseC2->setObjectName(QString::fromUtf8("caseC2"));
	caseC2->setGeometry(QRect(160, 150, 50, 50));
	caseC2->setAutoFillBackground(false);
	caseC2->setStyleSheet(QString::fromUtf8("background:rgb(100, 100, 100);"));
	caseC2->setBackgroundBrush(colorGris);
	caseC2->setForegroundBrush(colorNoir);

	caseD2 = new QGraphicsView(_centralWidget);
	caseD2->setObjectName(QString::fromUtf8("caseD2"));
	caseD2->setGeometry(QRect(210, 150, 50, 50));
	caseD2->setAutoFillBackground(false);

	caseB2 = new QGraphicsView(_centralWidget);
	caseB2->setObjectName(QString::fromUtf8("caseB2"));
	caseB2->setGeometry(QRect(110, 150, 50, 50));
	caseB2->setAutoFillBackground(false);

	caseH2 = new QGraphicsView(_centralWidget);
	caseH2->setObjectName(QString::fromUtf8("caseH2"));
	caseH2->setGeometry(QRect(410, 150, 50, 50));
	caseH2->setAutoFillBackground(false);

	caseG2 = new QGraphicsView(_centralWidget);
	caseG2->setObjectName(QString::fromUtf8("caseG2"));
	caseG2->setGeometry(QRect(360, 150, 50, 50));
	caseG2->setAutoFillBackground(false);
	caseG2->setStyleSheet(QString::fromUtf8("background:rgb(100, 100, 100);"));
	caseG2->setBackgroundBrush(colorGris);
	caseG2->setForegroundBrush(colorNoir);

	caseE2 = new QGraphicsView(_centralWidget);
	caseE2->setObjectName(QString::fromUtf8("caseE2"));
	caseE2->setGeometry(QRect(260, 150, 50, 50));
	caseE2->setAutoFillBackground(false);
	caseE2->setStyleSheet(QString::fromUtf8("background:rgb(100, 100, 100);"));
	caseE2->setBackgroundBrush(colorGris);
	caseE2->setForegroundBrush(colorNoir);

	caseF2 = new QGraphicsView(_centralWidget);
	caseF2->setObjectName(QString::fromUtf8("caseF2"));
	caseF2->setGeometry(QRect(310, 150, 50, 50));
	caseF2->setAutoFillBackground(false);

	caseF4 = new QGraphicsView(_centralWidget);
	caseF4->setObjectName(QString::fromUtf8("caseF4"));
	caseF4->setGeometry(QRect(310, 250, 50, 50));
	caseF4->setAutoFillBackground(false);

	caseB3 = new QGraphicsView(_centralWidget);
	caseB3->setObjectName(QString::fromUtf8("caseB3"));
	caseB3->setGeometry(QRect(110, 200, 50, 50));
	caseB3->setAutoFillBackground(false);
	caseB3->setStyleSheet(QString::fromUtf8("background:rgb(100, 100, 100);"));
	caseB3->setBackgroundBrush(colorGris);
	caseB3->setForegroundBrush(colorNoir);

	caseC3 = new QGraphicsView(_centralWidget);
	caseC3->setObjectName(QString::fromUtf8("caseC3"));
	caseC3->setGeometry(QRect(160, 200, 50, 50));
	caseC3->setAutoFillBackground(false);

	caseA3 = new QGraphicsView(_centralWidget);
	caseA3->setObjectName(QString::fromUtf8("caseA3"));
	caseA3->setGeometry(QRect(60, 200, 50, 50));
	caseA3->setAutoFillBackground(false);

	caseG3 = new QGraphicsView(_centralWidget);
	caseG3->setObjectName(QString::fromUtf8("caseG3"));
	caseG3->setGeometry(QRect(360, 200, 50, 50));
	caseG3->setAutoFillBackground(false);

	caseC4 = new QGraphicsView(_centralWidget);
	caseC4->setObjectName(QString::fromUtf8("caseC4"));
	caseC4->setGeometry(QRect(160, 250, 50, 50));
	caseC4->setAutoFillBackground(false);
	caseC4->setStyleSheet(QString::fromUtf8("background:rgb(100, 100, 100);"));
	caseC4->setBackgroundBrush(colorGris);
	caseC4->setForegroundBrush(colorNoir);

	caseD4 = new QGraphicsView(_centralWidget);
	caseD4->setObjectName(QString::fromUtf8("caseD4"));
	caseD4->setGeometry(QRect(210, 250, 50, 50));
	caseD4->setAutoFillBackground(false);

	caseH3 = new QGraphicsView(_centralWidget);
	caseH3->setObjectName(QString::fromUtf8("caseH3"));
	caseH3->setGeometry(QRect(410, 200, 50, 50));
	caseH3->setAutoFillBackground(false);
	caseH3->setStyleSheet(QString::fromUtf8("background:rgb(100, 100, 100);"));
	caseH3->setBackgroundBrush(colorGris);
	caseH3->setForegroundBrush(colorNoir);

	caseG4 = new QGraphicsView(_centralWidget);
	caseG4->setObjectName(QString::fromUtf8("caseG4"));
	caseG4->setGeometry(QRect(360, 250, 50, 50));
	caseG4->setAutoFillBackground(false);
	caseG4->setStyleSheet(QString::fromUtf8("background:rgb(100, 100, 100);"));
	caseG4->setBackgroundBrush(colorGris);
	caseG4->setForegroundBrush(colorNoir);

	caseF3 = new QGraphicsView(_centralWidget);
	caseF3->setObjectName(QString::fromUtf8("caseF3"));
	caseF3->setGeometry(QRect(310, 200, 50, 50));
	caseF3->setAutoFillBackground(false);
	caseF3->setStyleSheet(QString::fromUtf8("background:rgb(100, 100, 100);"));
	caseF3->setBackgroundBrush(colorGris);
	caseF3->setForegroundBrush(colorNoir);

	caseB4 = new QGraphicsView(_centralWidget);
	caseB4->setObjectName(QString::fromUtf8("caseB4"));
	caseB4->setGeometry(QRect(110, 250, 50, 50));
	caseB4->setAutoFillBackground(false);

	caseD3 = new QGraphicsView(_centralWidget);
	caseD3->setObjectName(QString::fromUtf8("caseD3"));
	caseD3->setGeometry(QRect(210, 200, 50, 50));
	caseD3->setAutoFillBackground(false);
	caseD3->setStyleSheet(QString::fromUtf8("background:rgb(100, 100, 100);"));
	caseD3->setBackgroundBrush(colorGris);
	caseD3->setForegroundBrush(colorNoir);

	caseE4 = new QGraphicsView(_centralWidget);
	caseE4->setObjectName(QString::fromUtf8("caseE4"));
	caseE4->setGeometry(QRect(260, 250, 50, 50));
	caseE4->setAutoFillBackground(false);
	caseE4->setStyleSheet(QString::fromUtf8("background:rgb(100, 100, 100);"));
	caseE4->setBackgroundBrush(colorGris);
	caseE4->setForegroundBrush(colorNoir);

	caseE3 = new QGraphicsView(_centralWidget);
	caseE3->setObjectName(QString::fromUtf8("caseE3"));
	caseE3->setGeometry(QRect(260, 200, 50, 50));
	caseE3->setAutoFillBackground(false);

	caseA4 = new QGraphicsView(_centralWidget);
	caseA4->setObjectName(QString::fromUtf8("caseA4"));
	caseA4->setGeometry(QRect(60, 250, 50, 50));
	caseA4->setAutoFillBackground(false);
	caseA4->setStyleSheet(QString::fromUtf8("background:rgb(100, 100, 100);"));
	caseA4->setBackgroundBrush(colorGris);
	caseA4->setForegroundBrush(colorNoir);

	caseH4 = new QGraphicsView(_centralWidget);
	caseH4->setObjectName(QString::fromUtf8("caseH4"));
	caseH4->setGeometry(QRect(410, 250, 50, 50));
	caseH4->setAutoFillBackground(false);

	caseH8 = new QGraphicsView(_centralWidget);
	caseH8->setObjectName(QString::fromUtf8("caseH8"));
	caseH8->setGeometry(QRect(410, 450, 50, 50));
	caseH8->setAutoFillBackground(false);

	caseG7 = new QGraphicsView(_centralWidget);
	caseG7->setObjectName(QString::fromUtf8("caseG7"));
	caseG7->setGeometry(QRect(360, 400, 50, 50));
	caseG7->setAutoFillBackground(false);

	caseE7 = new QGraphicsView(_centralWidget);
	caseE7->setObjectName(QString::fromUtf8("caseE7"));
	caseE7->setGeometry(QRect(260, 400, 50, 50));
	caseE7->setAutoFillBackground(false);

	caseH7 = new QGraphicsView(_centralWidget);
	caseH7->setObjectName(QString::fromUtf8("caseH7"));
	caseH7->setGeometry(QRect(410, 400, 50, 50));
	caseH7->setAutoFillBackground(false);
	caseH7->setStyleSheet(QString::fromUtf8("background:rgb(100, 100, 100);"));
	caseH7->setBackgroundBrush(colorGris);
	caseH7->setForegroundBrush(colorNoir);

	caseB6 = new QGraphicsView(_centralWidget);
	caseB6->setObjectName(QString::fromUtf8("caseB6"));
	caseB6->setGeometry(QRect(110, 350, 50, 50));
	caseB6->setAutoFillBackground(false);

	caseC5 = new QGraphicsView(_centralWidget);
	caseC5->setObjectName(QString::fromUtf8("caseC5"));
	caseC5->setGeometry(QRect(160, 300, 50, 50));
	caseC5->setAutoFillBackground(false);

	caseC6 = new QGraphicsView(_centralWidget);
	caseC6->setObjectName(QString::fromUtf8("caseC6"));
	caseC6->setGeometry(QRect(160, 350, 50, 50));
	caseC6->setAutoFillBackground(false);
	caseC6->setStyleSheet(QString::fromUtf8("background:rgb(100, 100, 100);"));
	caseC6->setBackgroundBrush(colorGris);
	caseC6->setForegroundBrush(colorNoir);

	caseF8 = new QGraphicsView(_centralWidget);
	caseF8->setObjectName(QString::fromUtf8("caseF8"));
	caseF8->setGeometry(QRect(310, 450, 50, 50));
	caseF8->setAutoFillBackground(false);

	caseA8 = new QGraphicsView(_centralWidget);
	caseA8->setObjectName(QString::fromUtf8("caseA8"));
	caseA8->setGeometry(QRect(60, 450, 50, 50));
	caseA8->setAutoFillBackground(false);
	caseA8->setStyleSheet(QString::fromUtf8("background:rgb(100, 100, 100);"));
	caseA8->setBackgroundBrush(colorGris);
	caseA8->setForegroundBrush(colorNoir);

	caseD8 = new QGraphicsView(_centralWidget);
	caseD8->setObjectName(QString::fromUtf8("caseD8"));
	caseD8->setGeometry(QRect(210, 450, 50, 50));
	caseD8->setAutoFillBackground(false);

	caseB8 = new QGraphicsView(_centralWidget);
	caseB8->setObjectName(QString::fromUtf8("caseB8"));
	caseB8->setGeometry(QRect(110, 450, 50, 50));
	caseB8->setAutoFillBackground(false);

	caseD6 = new QGraphicsView(_centralWidget);
	caseD6->setObjectName(QString::fromUtf8("caseD6"));
	caseD6->setGeometry(QRect(210, 350, 50, 50));
	caseD6->setAutoFillBackground(false);

	caseF5 = new QGraphicsView(_centralWidget);
	caseF5->setObjectName(QString::fromUtf8("caseF5"));
	caseF5->setGeometry(QRect(310, 300, 50, 50));
	caseF5->setAutoFillBackground(false);
	caseF5->setStyleSheet(QString::fromUtf8("background:rgb(100, 100, 100);"));
	caseF5->setBackgroundBrush(colorGris);
	caseF5->setForegroundBrush(colorNoir);

	caseG6 = new QGraphicsView(_centralWidget);
	caseG6->setObjectName(QString::fromUtf8("caseG6"));
	caseG6->setGeometry(QRect(360, 350, 50, 50));
	caseG6->setAutoFillBackground(false);
	caseG6->setStyleSheet(QString::fromUtf8("background:rgb(100, 100, 100);"));
	caseG6->setBackgroundBrush(colorGris);
	caseG6->setForegroundBrush(colorNoir);

	caseE5 = new QGraphicsView(_centralWidget);
	caseE5->setObjectName(QString::fromUtf8("caseE5"));
	caseE5->setGeometry(QRect(260, 300, 50, 50));
	caseE5->setAutoFillBackground(false);

	caseD7 = new QGraphicsView(_centralWidget);
	caseD7->setObjectName(QString::fromUtf8("caseD7"));
	caseD7->setGeometry(QRect(210, 400, 50, 50));
	caseD7->setAutoFillBackground(false);
	caseD7->setStyleSheet(QString::fromUtf8("background:rgb(100, 100, 100);"));
	caseD7->setBackgroundBrush(colorGris);
	caseD7->setForegroundBrush(colorNoir);

	caseC7 = new QGraphicsView(_centralWidget);
	caseC7->setObjectName(QString::fromUtf8("caseC7"));
	caseC7->setGeometry(QRect(160, 400, 50, 50));
	caseC7->setAutoFillBackground(false);

	caseG5 = new QGraphicsView(_centralWidget);
	caseG5->setObjectName(QString::fromUtf8("caseG5"));
	caseG5->setGeometry(QRect(360, 300, 50, 50));
	caseG5->setAutoFillBackground(false);

	caseE6 = new QGraphicsView(_centralWidget);
	caseE6->setObjectName(QString::fromUtf8("caseE6"));
	caseE6->setGeometry(QRect(260, 350, 50, 50));
	caseE6->setAutoFillBackground(false);
	caseE6->setStyleSheet(QString::fromUtf8("background:rgb(100, 100, 100);"));
	caseE6->setBackgroundBrush(colorGris);
	caseE6->setForegroundBrush(colorNoir);

	caseD5 = new QGraphicsView(_centralWidget);
	caseD5->setObjectName(QString::fromUtf8("caseD5"));
	caseD5->setGeometry(QRect(210, 300, 50, 50));
	caseD5->setAutoFillBackground(false);
	caseD5->setStyleSheet(QString::fromUtf8("background:rgb(100, 100, 100);"));
	caseD5->setBackgroundBrush(colorGris);
	caseD5->setForegroundBrush(colorNoir);

	caseH6 = new QGraphicsView(_centralWidget);
	caseH6->setObjectName(QString::fromUtf8("caseH6"));
	caseH6->setGeometry(QRect(410, 350, 50, 50));
	caseH6->setAutoFillBackground(false);

	caseF6 = new QGraphicsView(_centralWidget);
	caseF6->setObjectName(QString::fromUtf8("caseF6"));
	caseF6->setGeometry(QRect(310, 350, 50, 50));
	caseF6->setAutoFillBackground(false);

	caseE8 = new QGraphicsView(_centralWidget);
	caseE8->setObjectName(QString::fromUtf8("caseE8"));
	caseE8->setGeometry(QRect(260, 450, 50, 50));
	caseE8->setAutoFillBackground(false);
	caseE8->setStyleSheet(QString::fromUtf8("background:rgb(100, 100, 100);"));
	caseE8->setBackgroundBrush(colorGris);
	caseE8->setForegroundBrush(colorNoir);

	caseB7 = new QGraphicsView(_centralWidget);
	caseB7->setObjectName(QString::fromUtf8("caseB7"));
	caseB7->setGeometry(QRect(110, 400, 50, 50));
	caseB7->setAutoFillBackground(false);
	caseB7->setStyleSheet(QString::fromUtf8("background:rgb(100, 100, 100);"));
	caseB7->setBackgroundBrush(colorGris);
	caseB7->setForegroundBrush(colorNoir);

	caseG8 = new QGraphicsView(_centralWidget);
	caseG8->setObjectName(QString::fromUtf8("caseG8"));
	caseG8->setGeometry(QRect(360, 450, 50, 50));
	caseG8->setAutoFillBackground(false);
	caseG8->setStyleSheet(QString::fromUtf8("background:rgb(100, 100, 100);"));
	caseG8->setBackgroundBrush(colorGris);
	caseG8->setForegroundBrush(colorNoir);

	caseF7 = new QGraphicsView(_centralWidget);
	caseF7->setObjectName(QString::fromUtf8("caseF7"));
	caseF7->setGeometry(QRect(310, 400, 50, 50));
	caseF7->setAutoFillBackground(false);
	caseF7->setStyleSheet(QString::fromUtf8("background:rgb(100, 100, 100);"));
	caseF7->setBackgroundBrush(colorGris);
	caseF7->setForegroundBrush(colorNoir);

	caseB5 = new QGraphicsView(_centralWidget);
	caseB5->setObjectName(QString::fromUtf8("caseB5"));
	caseB5->setGeometry(QRect(110, 300, 50, 50));
	caseB5->setAutoFillBackground(false);
	caseB5->setStyleSheet(QString::fromUtf8("background:rgb(100, 100, 100);"));
	caseB5->setBackgroundBrush(colorGris);
	caseB5->setForegroundBrush(colorNoir);

	caseC8 = new QGraphicsView(_centralWidget);
	caseC8->setObjectName(QString::fromUtf8("caseC8"));
	caseC8->setGeometry(QRect(160, 450, 50, 50));
	caseC8->setAutoFillBackground(false);
	caseC8->setStyleSheet(QString::fromUtf8("background:rgb(100, 100, 100);"));
	caseC8->setBackgroundBrush(colorGris);
	caseC8->setForegroundBrush(colorNoir);

	caseA5 = new QGraphicsView(_centralWidget);
	caseA5->setObjectName(QString::fromUtf8("caseA5"));
	caseA5->setGeometry(QRect(60, 300, 50, 50));
	caseA5->setAutoFillBackground(false);

	caseH5 = new QGraphicsView(_centralWidget);
	caseH5->setObjectName(QString::fromUtf8("caseH5"));
	caseH5->setGeometry(QRect(410, 300, 50, 50));
	caseH5->setAutoFillBackground(false);
	caseH5->setStyleSheet(QString::fromUtf8("background:rgb(100, 100, 100);"));
	caseH5->setBackgroundBrush(colorGris);
	caseH5->setForegroundBrush(colorNoir);

	caseA6 = new QGraphicsView(_centralWidget);
	caseA6->setObjectName(QString::fromUtf8("caseA6"));
	caseA6->setGeometry(QRect(60, 350, 50, 50));
	caseA6->setAutoFillBackground(false);
	caseA6->setStyleSheet(QString::fromUtf8("background:rgb(100, 100, 100);"));
	caseA6->setBackgroundBrush(colorGris);
	caseA6->setForegroundBrush(colorNoir);

	caseA7 = new QGraphicsView(_centralWidget);
	caseA7->setObjectName(QString::fromUtf8("caseA7"));
	caseA7->setGeometry(QRect(60, 400, 50, 50));
	caseA7->setAutoFillBackground(false);

	return _centralWidget;
}
