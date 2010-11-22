/**
 * Mise en oeuvre de Piece.h
 *
 * @file Piece.cxx
 */

// A besoin de la declaration de la classe
#include "Piece.h"
#include "Echiquier.h"
#include <iostream>

using namespace std;

Piece::Piece () {
	// ne fait rien => objet instancie mais non valide.
}

Piece::Piece ( int x, int y, bool white ) {
	m_x = x;
	m_y = y;
	m_white = white;
}

Piece::Piece ( const Piece &autre ) {
	m_x = autre.x ();
	m_y = autre.m_y;
	m_white = autre.m_white;
}

Piece & Piece::operator=( const Piece &autre ) {
	m_x = autre.x();
	m_y = autre.m_y;
	m_white = autre.m_white;

	return *this;
}

void Piece::init ( int x, int y, bool white ) {
	m_x = x;
	m_y = y;
	m_white = white;
}

void Piece::move ( int x, int y ) {
	m_x = x;
	m_y = y;
}

bool Piece::mouvementValide ( Echiquier & e, int x, int y ) {
	cout << "mouvementValide de Piece" << endl;
	return ( e.getPiece( x, y ) != NULL ) ;
}

QString Piece::myType () {
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

Roi::Roi ( bool white ) {
	m_x = 5;
	m_y = ( white ? 8:1 ) ;
	m_white = white;
}

bool Roi::mouvementValide ( Echiquier &e, int x, int y ) {
	cout << "Mouvement Valide Roi" << endl;
	e.getPiece( x, y ) ;

	return true;
}

QString Roi::myType () {
	return ( ( m_white ) ? "RoiBlanc" : "RoiNoir" ) ;
}

Reine::Reine ( bool white ) {
	m_x = 4;
	m_y = ( white ? 8:1 ) ;
	m_white = white;
}

bool Reine::mouvementValide ( Echiquier &e, int x, int y ) {
	cout << "Mouvement Valide Reine" << endl;
	e.getPiece( x, y ) ;

	return true;
}

QString Reine::myType () {
	return ( ( m_white ) ? "DameBlanche" : "DameNoire" ) ;
}

Fou::Fou ( bool white, int x ) {
	m_x = x;
	m_y = ( white ? 8:1 ) ;
	m_white = white;
}

bool Fou::mouvementValide ( Echiquier &e, int x, int y ) {
	cout << "Mouvement Valide Fou" << endl;
	e.getPiece( x, y ) ;

	return true;
}

QString Fou::myType () {
	return ( ( m_white ) ? "FouBlanc" : "FouNoir" ) ;
}

Tour::Tour ( bool white, int x ) {
	m_x = x;
	m_y = ( white ? 8:1 ) ;
	m_white = white;
}

bool Tour::mouvementValide ( Echiquier &e, int x, int y ) {
	cout << "Mouvement Valide Tour" << endl;
	e.getPiece( x, y ) ;

	return true;
}

QString Tour::myType () {
	return ( ( m_white ) ? "TourBlanche" : "TourNoire" ) ;
}

Cavalier::Cavalier ( bool white, int x ) {
	m_x = x;
	m_y = ( white ? 8:1 ) ;
	m_white = white;
}

bool Cavalier::mouvementValide ( Echiquier &e, int x, int y ) {
	cout << "Mouvement Valide Cavalier" << endl;
	e.getPiece( x, y ) ;

	return true;
}

QString Cavalier::myType () {
	return ( ( m_white ) ? "CavalierBlanc" : "CavalierNoir" ) ;
}

Pion::Pion ( bool white, int x ) {
	m_x = x;
	m_y = ( white ? 7:2 ) ;
	m_white = white;
}

bool Pion::mouvementValide ( Echiquier &e, int x, int y ) {
	cout << "Mouvement Valide Pion" << endl;
	e.getPiece( x, y ) ;

	return true;
}

QString Pion::myType () {
	return ( ( m_white ) ? "PionBlanc" : "PionNoir" ) ;
}
