#include "Echiquier.h"

using namespace std;

Echiquier::Echiquier() {
	for ( int i = 0; i < 64; i++ ) {
		this->setPiece( i, NULL );
	}
}

Piece * Echiquier::getPiece( int x, int y ) {
	if (
		( x >= 1 ) && ( x <= 8 ) &&
		( y >= 1 ) && ( y <= 8 )
	) {
		return this->getPiece( getCase( x, y ) );
	}
	else {
		cout << "mauvais coord: x:" << x << " y:" << y << " !";
	}

	return NULL;
}

Piece * Echiquier::getPiece( int i ) {
	if ( ( i >= 0 ) && ( i <= 63 ) ) {
		return this->m_cases[ i ];
	}
	else {
		cout << "Nombre non compris entre 0 et 63 !";
	}

	return NULL;
}

void Echiquier::setPiece( int i, Piece * p ) {
	if ( ( i >= 0 ) && ( i <= 63 ) ) {
		this->m_cases[ i ] = p;
	}
	else {
		cout << "Nombre non compris entre 0 et 63 !";
	}
}

void Echiquier::setPiece( int x, int y, Piece * p ) {
	if (
		( x >= 1 ) && ( x <= 8 ) &&
		( y >= 1 ) && ( y <= 8 )
	) {
		this->setPiece( this->getCase( x, y ), p );
	}
	else {
		cout << "Coordonnée non valide";
	}
}

void Echiquier::create( Ui::MainWindow *& _ui ) {
	//JoueurBlanc JoueurBlanc;
	//JoueurNoir  JoueurNoir;

	//JoueurBlanc.placerPieces( * this );
	//JoueurNoir.placerPieces( * this );

	// -------------------------------- Roi

	Roi RoiBlanc(true);
	RoiBlanc.setQLabel( _ui->pionBlancRoi );
	this->enleverPiece(5,8);
	this->placerPiece(&RoiBlanc);
	//_ui->pionBlancRoi->move( 215, 455 );

	Roi RoiNoir(false);
	RoiNoir.setQLabel( _ui->pionNoirRoi );
	this->enleverPiece(5,1);
	this->placerPiece(&RoiNoir);
	//_ui->pionNoirRoi->move( 215, 105 );

	// -------------------------------- Reine

	Reine ReineBlanc(true);
	ReineBlanc.setQLabel( _ui->pionBlancReine );
	this->enleverPiece(4,8);
	this->placerPiece(&ReineBlanc);
	//_ui->pionBlancReine->move( 270, 455 );

	Reine ReineNoir(false);
	ReineNoir.setQLabel( _ui->pionNoirReine );
	this->enleverPiece(4,1);
	this->placerPiece(&ReineNoir);
	//_ui->pionNoirReine->move( 270, 105 );

	// -------------------------------- Tour

	Tour TourBlancUn(true, 1);
	TourBlancUn.setQLabel( _ui->pionBlancTour1 );
	this->enleverPiece(1,8);
	this->placerPiece(&TourBlancUn);
	//_ui->pionBlancTour1->move( 70, 455 );

	Tour TourBlancDeux(true, 8);
	TourBlancDeux.setQLabel( _ui->pionBlancTour2 );
	this->enleverPiece(8,8);
	this->placerPiece(&TourBlancDeux);
	//_ui->pionBlancTour2->move( 420, 455 );

	Tour TourNoirUn(false, 1);
	TourNoirUn.setQLabel( _ui->pionNoirTour1 );
	this->enleverPiece(1,1);
	this->placerPiece(&TourNoirUn);
	//_ui->pionNoirTour1->move( 70, 105 );

	Tour TourNoirDeux(false, 8);
	TourNoirDeux.setQLabel( _ui->pionNoirTour2 );
	this->enleverPiece(8,1);
	this->placerPiece(&TourNoirDeux);
	//_ui->pionNoirTour2->move( 420, 105 );

	// -------------------------------- Cavalier

	Cavalier CavalierBlancUn(true, 2);
	CavalierBlancUn.setQLabel( _ui->pionBlancCavalier1 );
	this->enleverPiece(2,8);
	this->placerPiece(&CavalierBlancUn);
	//_ui->pionBlancCavalier1->move( 120, 455 );

	Cavalier CavalierBlancDeux(true, 7);
	CavalierBlancDeux.setQLabel( _ui->pionBlancCavalier2 );
	this->enleverPiece(7,8);
	this->placerPiece(&CavalierBlancDeux);
	//_ui->pionBlancCavalier2->move( 370, 455 );

	Cavalier CavalierNoirUn(false, 2);
	CavalierNoirUn.setQLabel( _ui->pionNoirCavalier1 );
	this->enleverPiece(2,1);
	this->placerPiece(&CavalierNoirUn);
	//_ui->pionNoirCavalier1->move( 120, 105 );

	Cavalier CavalierNoirDeux(false, 7);
	CavalierNoirDeux.setQLabel( _ui->pionNoirCavalier2 );
	this->enleverPiece(7,1);
	this->placerPiece(&CavalierNoirDeux);
	//_ui->pionNoirCavalier2->move( 370, 105 );

	// -------------------------------- Fou

	Fou FouBlancUn(true, 3);
	FouBlancUn.setQLabel( _ui->pionBlancFou1 );
	this->enleverPiece(3,8);
	this->placerPiece(&FouBlancUn);
	//_ui->pionBlancFou1->move( 170, 455 );

	Fou FouBlancDeux(true, 6);
	FouBlancDeux.setQLabel( _ui->pionBlancFou2 );
	this->enleverPiece(6,8);
	this->placerPiece(&FouBlancDeux);
	//_ui->pionBlancFou2->move( 320, 455 );

	Fou FouNoirUn(false, 3);
	FouNoirUn.setQLabel( _ui->pionNoirFou1 );
	this->enleverPiece(3,1);
	this->placerPiece(&FouNoirUn);
	//_ui->pionNoirFou1->move( 170, 105 );

	Fou FouNoirDeux(false, 6);
	FouNoirDeux.setQLabel( _ui->pionNoirFou2 );
	this->enleverPiece(6,1);
	this->placerPiece(&FouNoirDeux);
	//_ui->pionNoirFou2->move( 320, 105 );

	// -------------------------------- Pion

	Pion PionBlancUn(true, 1);
	PionBlancUn.setQLabel( _ui->pionBlancPion1 );
	this->enleverPiece(1,7);
	this->placerPiece(&PionBlancUn);
	//_ui->pionBlancPion1->move( 70, 405 );

	Pion PionBlancDeux(true, 2);
	PionBlancDeux.setQLabel( _ui->pionBlancPion2 );
	this->enleverPiece(2,7);
	this->placerPiece(&PionBlancDeux);
	//_ui->pionBlancPion2->move( 120, 405 );

	Pion PionBlancTrois(true, 3);
	PionBlancTrois.setQLabel( _ui->pionBlancPion3 );
	this->enleverPiece(3,7);
	this->placerPiece(&PionBlancTrois);
	//_ui->pionBlancPion3->move( 170, 405 );

	Pion PionBlancQuatre(true, 4);
	PionBlancQuatre.setQLabel( _ui->pionBlancPion4 );
	this->enleverPiece(4,7);
	this->placerPiece(&PionBlancQuatre);
	//_ui->pionBlancPion4->move( 220, 405 );

	Pion PionBlancCinq(true, 5);
	PionBlancCinq.setQLabel( _ui->pionBlancPion5 );
	this->enleverPiece(5,7);
	this->placerPiece(&PionBlancCinq);
	//_ui->pionBlancPion5->move( 270, 405 );

	Pion PionBlancSix(true, 6);
	PionBlancSix.setQLabel( _ui->pionBlancPion6 );
	this->enleverPiece(6,7);
	this->placerPiece(&PionBlancSix);
	//_ui->pionBlancPion6->move( 320, 405 );

	Pion PionBlancSept(true, 7);
	PionBlancSept.setQLabel( _ui->pionBlancPion7 );
	this->enleverPiece(7,7);
	this->placerPiece(&PionBlancSept);
	//_ui->pionBlancPion7->move( 370, 405 );

	Pion PionBlancHuit(true, 8);
	PionBlancHuit.setQLabel( _ui->pionBlancPion8 );
	this->enleverPiece(8,7);
	this->placerPiece(&PionBlancHuit);
	//_ui->pionBlancPion8->move( 420, 405 );

	Pion PionNoirUn(false, 1);
	PionNoirUn.setQLabel( _ui->pionNoirPion1 );
	this->enleverPiece(1,2);
	this->placerPiece(&PionNoirUn);
	//_ui->pionNoirPion1->move( 70, 155 );

	Pion PionNoirDeux(false, 2);
	PionNoirDeux.setQLabel( _ui->pionNoirPion2 );
	this->enleverPiece(2,2);
	this->placerPiece(&PionNoirDeux);
	//_ui->pionNoirPion2->move( 120, 155 );

	Pion PionNoirTrois(false, 3);
	PionNoirTrois.setQLabel( _ui->pionNoirPion3 );
	this->enleverPiece(3,2);
	this->placerPiece(&PionNoirTrois);
	//_ui->pionNoirPion3->move( 170, 155 );

	Pion PionNoirQuatre(false, 4);
	PionNoirQuatre.setQLabel( _ui->pionNoirPion4 );
	this->enleverPiece(4,2);
	this->placerPiece(&PionNoirQuatre);
	//_ui->pionNoirPion4->move( 220, 155 );

	Pion PionNoirCinq(false, 5);
	PionNoirCinq.setQLabel( _ui->pionNoirPion5 );
	this->enleverPiece(5,2);
	this->placerPiece(&PionNoirCinq);
	//_ui->pionNoirPion5->move( 270, 155 );

	Pion PionNoirSix(false, 6);
	PionNoirSix.setQLabel( _ui->pionNoirPion6 );
	this->enleverPiece(6,2);
	this->placerPiece(&PionNoirSix);
	//_ui->pionNoirPion6->move( 320, 155 );

	Pion PionNoirSept(false, 7);
	PionNoirSept.setQLabel( _ui->pionNoirPion7 );
	this->enleverPiece(7,2);
	this->placerPiece(&PionNoirSept);
	//_ui->pionNoirPion7->move( 370, 155 );

	Pion PionNoirHuit(false, 8);
	PionNoirHuit.setQLabel( _ui->pionNoirPion8 );
	this->enleverPiece(8,2);
	this->placerPiece(&PionNoirHuit);
	//_ui->pionNoirPion8->move( 420, 155 );

	return this;
}

bool Echiquier::placerPiece( int x, int y ) {
	return this->placerPiece( this->getPiece( x, y ) );
}

bool Echiquier::placerPiece( Piece * p ) {
	if (
		( p->x() >= 1 ) && ( p->x() <= 8 )
		&& ( p->y() >= 1 ) && ( p->y() <= 8 )
		&& ( p != NULL )
	) {
		int i = getCase( p->x(), p->y() );
		this->setPiece( i, p );

		int xi = 60;
		int yi = 100;
		int exi = 50;
		int eyi = 50;

		int xf = xi + ( exi * ( p->x() - 1 ) );
		int yf = yi + ( eyi * ( p->y() - 1 ) );

		QLabel * plop = p->getQLabel();
		plop->move( xf, yf );

		return true;
	}

	return false;
}

bool Echiquier::deplacerPiece( Piece * p, int x, int y ) {
	if (
		( p != NULL ) &&
		( x >= 1 ) && ( x <= 8 ) &&
		( y >= 1 ) && ( y <= 8 )
	) {
		this->enleverPiece( p->x(), p->y() );
		return this->placerPiece( p );
	}

	return false;
}

bool Echiquier::deplacerPiece( int xd, int yd, int xf, int yf ) {
	return this->deplacerPiece( this->getPiece( xd, yd ), xf, yf );
}

bool Echiquier::enleverPiece( int x, int y ) {
	if (
		( x >= 1 ) && ( x <= 8 ) &&
		( y >= 1 ) && ( y <= 8 )
	) {
		this->setPiece( this->getCase( x, y ), NULL );

		return true;
	}

	return false;
}

bool Echiquier::enleverPiece( Piece * p ) {
	if (
		( p->x() >= 1 ) && ( p->x() <= 8 ) &&
		( p->y() >= 1 ) && ( p->y() <= 8 )
	) {
		return this->enleverPiece( p->x(), p->y() );
	}

	return false;
}

int Echiquier::getCase( int x, int y ) {
	return ( x - 1 + ( y - 1 ) * 8 );
}

int Echiquier::getCase( Piece * p ) {
	return getCase( p->x(), p->y() );
}
