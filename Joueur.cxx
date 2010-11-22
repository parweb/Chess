#include <iostream>
// A besoin de la declaration de la classe
#include "Joueur.h"

using namespace std;

Joueur::Joueur() {

}

Joueur::Joueur( bool white ) {
	int n = 0;
	int y = white ? 1 : 8;

	for ( int x = 1; x <= 8; ++x ) {
		m_pieces[ n++ ].init( x, y, white );
	}

	y = white ? 2 : 7;

	for ( int x = 1; x <= 8; ++x ){
		m_pieces[ n++ ].init( x, y, white );
	}
}

void Joueur::placerPieces( Echiquier & e ) {
	for ( int i = 0; i < 16; i++ ) {
		e.placer( m_pieces + i );
	}
}

JoueurBlanc::JoueurBlanc() : Joueur(true) {
	int n = 0;
	for ( int x = 1; x <= 8; ++x ) {
		m_pieces[ n++ ].init( x, 1, true );
		m_pieces[ n++ ].init( x, 2, true );
	}
}

JoueurNoir::JoueurNoir() {
	int n = 0;
	for ( int x = 1; x <= 8; ++x ) {
		m_pieces[ n++ ].init( x, 8, false );
		m_pieces[ n++ ].init( x, 7, false );
	}
}
