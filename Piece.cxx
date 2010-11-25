/**
 * Mise en oeuvre de Piece.h
 *
 * @file Piece.cxx
 */

// A besoin de la declaration de la classe
#include "Piece.h"


using namespace std;

Piece::Piece () {
	// ne fait rien => objet instancie mais non valide.
}

Piece::Piece ( int x, int y, bool isWhite ) {
	m_x = x;
	m_y = y;
	m_white = isWhite;
}

Piece::Piece ( const Piece &autre ) {
	m_x = autre.x();
	m_y = autre.m_y;
	m_white = autre.m_white;
}

Piece & Piece::operator=( const Piece &autre ) {
	m_x = autre.x();
	m_y = autre.m_y;
	m_white = autre.m_white;

	return * this;
}

void Piece::init ( int x, int y, bool isWhite ) {
	m_x = x;
	m_y = y;
	m_white = isWhite;
}

void Piece::move ( int x, int y ) {
	this->m_x = x;
	this->m_y = y;
}

bool Piece::mouvementValide ( Echiquier & e, int x, int y ) {
	cout << "mouvementValide de Piece" << endl;
	return ( e.getPiece( x, y ) != NULL ) ;
}

QString Piece::getType () {
	return ( ( m_white ) ? "Blanc" : "Noir" ) ;
}

int Piece::x () const {
	return m_x;
}

int Piece::y () const {
	return m_y;
}

bool Piece::isWhite () {
	return m_white;
}

bool Piece::isBlack () {
	return !m_white;
}

void Piece::setQLabel( QLabel *& _QL ) {
	this->_QLabel = _QL;
}

QLabel * Piece::getQLabel() {
	return this->_QLabel;
}

Roi::Roi ( bool isWhite ) {
	m_x = 5;
	m_y = ( isWhite ? 8 : 1 ) ;
	m_white = isWhite;
}

bool Roi::mouvementValide ( Echiquier &e, int x, int y ) {
	cout << "Mouvement Valide Roi" << endl;
	e.getPiece( x, y ) ;

	return true;
}

QString Roi::getType () {
	return ( ( m_white ) ? "RoiBlanc" : "RoiNoir" ) ;
}

Reine::Reine ( bool isWhite ) {
	m_x = 4;
	m_y = ( isWhite ? 8:1 ) ;
	m_white = isWhite;
}

bool Reine::mouvementValide ( Echiquier &e, int x, int y ) {
	cout << "Mouvement Valide Reine" << endl;
	e.getPiece( x, y ) ;

	return true;
}

QString Reine::getType () {
	return ( ( m_white ) ? "DameBlanche" : "DameNoire" ) ;
}

Fou::Fou ( bool isWhite, int x ) {
	m_x = x;
	m_y = ( isWhite ? 8:1 ) ;
	m_white = isWhite;
}

bool Fou::mouvementValide ( Echiquier &e, int x, int y ) {
	cout << "Mouvement Valide Fou" << endl;
	e.getPiece( x, y ) ;

	return true;
}

QString Fou::getType () {
	return ( ( m_white ) ? "FouBlanc" : "FouNoir" ) ;
}

Tour::Tour ( bool isWhite, int x ) {
	m_x = x;
	m_y = ( isWhite ? 8:1 ) ;
	m_white = isWhite;
}

bool Tour::mouvementValide ( Echiquier &e, int x, int y ) {
	cout << "Mouvement Valide Tour" << endl;
	e.getPiece( x, y ) ;

	return true;
}

QString Tour::getType () {
	return ( ( m_white ) ? "TourBlanche" : "TourNoire" ) ;
}

Cavalier::Cavalier ( bool isWhite, int x ) {
	m_x = x;
	m_y = ( isWhite ? 8:1 ) ;
	m_white = isWhite;
}

bool Cavalier::mouvementValide ( Echiquier &e, int x, int y ) {
	cout << "Mouvement Valide Cavalier" << endl;
	e.getPiece( x, y ) ;

	return true;
}

QString Cavalier::getType () {
	return ( ( m_white ) ? "CavalierBlanc" : "CavalierNoir" ) ;
}

Pion::Pion ( bool isWhite, int x ) {
	m_x = x;
	m_y = ( isWhite ? 7:2 ) ;
	m_white = isWhite;
}

bool Pion::mouvementValide ( Echiquier &e, int x, int y ) {
	cout << "Mouvement Valide Pion" << endl;
	e.getPiece( x, y ) ;

	return true;
}

QString Pion::getType () {
	return ( ( m_white ) ? "PionBlanc" : "PionNoir" ) ;
}
