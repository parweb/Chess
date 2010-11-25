/**
 * Mise en oeuvre de Piece.h
 *
 * @file Piece.cxx
 */

// A besoin de la declaration de la classe
#include "Piece.h"


using namespace std;

Piece::Piece () {
	this->setGeometry(QRect(-100, -100, 50, 50));
	this->setScaledContents(true);
	this->setAlignment(Qt::AlignCenter);

	QString piece = ":/Pion/"+ this->getType() +".png";

	this->setPixmap(QPixmap(":/Pion/"+ piece +".png"));
	this->show();
}

Piece::Piece ( int x, int y, bool isWhite ) {
	this->m_x = x;
	this->m_y = y;
	this->m_white = isWhite;
}

Piece::Piece ( const Piece & autre ) {
	this->m_x = autre.x();
	this->m_y = autre.m_y;
	this->m_white = autre.m_white;
}

Piece & Piece::operator=( const Piece &autre ) {
	this->m_x = autre.x();
	this->m_y = autre.m_y;
	this->m_white = autre.m_white;

	return * this;
}

void Piece::init ( int x, int y, bool isWhite ) {
	this->m_x = x;
	this->m_y = y;
	this->m_white = isWhite;
}

void Piece::moveTo ( int x, int y ) {
	this->m_x = x;
	this->m_y = y;

	int xi = 60;
	int yi = 100;
	int exi = 50;
	int eyi = 50;

	int xf = xi + ( exi * ( this->m_x - 1 ) );
	int yf = yi + ( eyi * ( this->m_y - 1 ) );

	this->move( xf, yf );
}

bool Piece::mouvementValide ( Echiquier & e, int x, int y ) {
	cout << "mouvementValide de Piece" << endl;
	return ( e.getPiece( x, y ) != NULL );
}

QString Piece::getType () {
	return ( ( m_white ) ? "Blanc" : "Noir" );
}

int Piece::x () const {
	return this->m_x;
}

int Piece::y () const {
	return this->m_y;
}

bool Piece::isWhite () {
	return this->m_white;
}

bool Piece::isBlack () {
	return !this->m_white;
}

void Piece::setQLabel( QLabel *& _QL ) {
	this->_QLabel = _QL;
}

QLabel * Piece::getQLabel() {
	return this->_QLabel;
}

Roi::Roi ( bool isWhite ) {
	this->m_x = 5;
	this->m_y = ( isWhite ? 8 : 1 );
	this->m_white = isWhite;
}

bool Roi::mouvementValide ( Echiquier &e, int x, int y ) {
	cout << "Mouvement Valide Roi" << endl;
	e.getPiece( x, y );

	return true;
}

QString Roi::getType () {
	return ( ( this->m_white ) ? "roi_blanc" : "roi_noir" );
}

Reine::Reine ( bool isWhite ) {
	this->m_x = 4;
	this->m_y = ( isWhite ? 8:1 );
	this->m_white = isWhite;
}

bool Reine::mouvementValide ( Echiquier &e, int x, int y ) {
	cout << "Mouvement Valide Reine" << endl;
	e.getPiece( x, y );

	return true;
}

QString Reine::getType () {
	return ( ( this->m_white ) ? "reine_blanc" : "reine_noir" );
}

Fou::Fou ( bool isWhite, int x ) {
	this->m_x = x;
	this->m_y = ( isWhite ? 8:1 );
	this->m_white = isWhite;
}

bool Fou::mouvementValide ( Echiquier &e, int x, int y ) {
	cout << "Mouvement Valide Fou" << endl;
	e.getPiece( x, y );

	return true;
}

QString Fou::getType () {
	return ( ( this->m_white ) ? "fou_blanc" : "fou_noir" );
}

Tour::Tour ( bool isWhite, int x ) {
	this->m_x = x;
	this->m_y = ( isWhite ? 8:1 );
	this->m_white = isWhite;
}

bool Tour::mouvementValide ( Echiquier &e, int x, int y ) {
	cout << "Mouvement Valide Tour" << endl;
	e.getPiece( x, y );

	return true;
}

QString Tour::getType () {
	return ( ( this->m_white ) ? "tour_blanc" : "tour_noir" );
}

Cavalier::Cavalier ( bool isWhite, int x ) {
	m_x = x;
	this->m_y = ( isWhite ? 8:1 );
	this->m_white = isWhite;
}

bool Cavalier::mouvementValide ( Echiquier &e, int x, int y ) {
	cout << "Mouvement Valide Cavalier" << endl;
	e.getPiece( x, y );

	return true;
}

QString Cavalier::getType () {
	return ( ( this->m_white ) ? "cavalier_blanc" : "cavalier_noir" );
}

Pion::Pion ( bool isWhite, int x ) {
	this->m_x = x;
	this->m_y = ( isWhite ? 7:2 );
	this->m_white = isWhite;
}

bool Pion::mouvementValide ( Echiquier &e, int x, int y ) {
	cout << "Mouvement Valide Pion" << endl;
	e.getPiece( x, y );

	return true;
}

QString Pion::getType () {
	return ( ( this->m_white ) ? "pion_blanc" : "pion_noir" );
}
