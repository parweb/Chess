#include "Joueur.h"
#include "Piece.h"

using namespace std;

Joueur::Joueur() {

}

Joueur::Joueur( bool isWhite ) {

}

void Joueur::placerPieces( Echiquier * e ) {
	e->placerPiece( this->_Tour1 );
	e->placerPiece( this->_Tour2 );
	e->placerPiece( this->_Cavalier1 );
	e->placerPiece( this->_Cavalier2 );
	e->placerPiece( this->_Fou1 );
	e->placerPiece( this->_Fou2 );
	e->placerPiece( this->_Roi );
	e->placerPiece( this->_Reine );
	e->placerPiece( this->_Pion1 );
	e->placerPiece( this->_Pion2 );
	e->placerPiece( this->_Pion3 );
	e->placerPiece( this->_Pion4 );
	e->placerPiece( this->_Pion5 );
	e->placerPiece( this->_Pion6 );
	e->placerPiece( this->_Pion7 );
	e->placerPiece( this->_Pion8 );
}

JoueurBlanc::JoueurBlanc() : Joueur( true ) {
	this->_Tour1->init		( 1, 1, true );
	this->_Tour2->init		( 8, 1, true );
	this->_Cavalier1->init	( 2, 1, true );
	this->_Cavalier2->init	( 7, 1, true );
	this->_Fou1->init		( 3, 1, true );
	this->_Fou2->init		( 6, 1, true );
	this->_Roi->init		( 4, 1, true );
	this->_Reine->init		( 5, 1, true );
	this->_Pion1->init		( 1, 2, true );
	this->_Pion2->init		( 2, 2, true );
	this->_Pion3->init		( 3, 2, true );
	this->_Pion4->init		( 4, 2, true );
	this->_Pion5->init		( 5, 2, true );
	this->_Pion6->init		( 6, 2, true );
	this->_Pion7->init		( 7, 2, true );
	this->_Pion8->init		( 8, 2, true );
}

JoueurNoir::JoueurNoir() : Joueur( false ) {
	this->_Tour1->init		( 1, 8, false );
	this->_Tour2->init		( 8, 8, false );
	this->_Cavalier1->init	( 2, 8, false );
	this->_Cavalier2->init	( 7, 8, false );
	this->_Fou1->init		( 3, 8, false );
	this->_Fou2->init		( 6, 8, false );
	this->_Roi->init		( 4, 8, false );
	this->_Reine->init		( 5, 7, false );
	this->_Pion1->init		( 1, 7, false );
	this->_Pion2->init		( 2, 7, false );
	this->_Pion3->init		( 3, 7, false );
	this->_Pion4->init		( 4, 7, false );
	this->_Pion5->init		( 5, 7, false );
	this->_Pion6->init		( 6, 7, false );
	this->_Pion7->init		( 7, 7, false );
	this->_Pion8->init		( 8, 7, false );
}
