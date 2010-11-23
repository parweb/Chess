#include <iostream>
// A besoin de la declaration de la classe
#include "Joueur.h"

using namespace std;

Joueur::Joueur() {

}

Joueur::Joueur( bool isWhite ) {

}

void Joueur::placerPieces( Echiquier & e ) {
	for ( int i = 0; i < 16; i++ ) {
		e.placerPiece( this->m_pieces + i );
	}
}

JoueurBlanc::JoueurBlanc() : Joueur(true) {
	int n = 0;
	for ( int x = 1; x <= 8; ++x ) {
		this->m_pieces[ n++ ].init( x, 1, true );
		this->m_pieces[ n++ ].init( x, 2, true );
	}
}

JoueurNoir::JoueurNoir() {
	int n = 0;
	for ( int x = 1; x <= 8; ++x ) {
		this->m_pieces[ n++ ].init( x, 8, false );
		this->m_pieces[ n++ ].init( x, 7, false );
	}
}
