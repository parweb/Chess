/**
 * Mise en oeuvre de Piece.h
 *
 * @file Piece.cxx
 */

// A besoin de la declaration de la classe
#include "Piece.h"


using namespace std;

Piece::Piece () {
	//
}

Piece::Piece ( Echiquier * lEchiquier ) : QLabel( lEchiquier->getCentralWidget() ) {
	this->_echiquier = lEchiquier;

	this->setGeometry( QRect( 0, 0, 50, 50 ) );
	this->setScaledContents( true );
	this->setAlignment( Qt::AlignCenter );

	this->setFixedSize( 50, 50 );
	this->setAcceptDrops( true );
}

Piece::Piece ( int x, int y, bool isWhite ) {
	m_x = x;
	m_y = y;
	m_white = isWhite;
}
/*
Piece::Piece ( const Piece &autre ) {
	m_x = autre.x();
	m_y = autre.m_y;
	m_white = autre.m_white;
}
*/
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

bool Piece::moveTo ( int x, int y, Echiquier * e ) {
	if ( this->mouvementValide( e, x, y ) ) {
		this->m_x = x;
		this->m_y = y;
	}
}

QString Piece::getType () {
	return ( ( this->m_white ) ? "Blanc" : "Noir" ) ;
}

int Piece::x () const {
	return this->m_x;
}

int Piece::y () const {
	return this->m_y;
}

bool Piece::getColor () {
	return this->m_white;
}

Roi::Roi () {}
Reine::Reine () {}
Tour::Tour () {}
Fou::Fou () {}
Cavalier::Cavalier () {}

Roi::Roi ( bool isWhite, Echiquier * lEchiquier ) : Piece( lEchiquier ) {
	this->m_x = 5;
	this->m_y = ( isWhite ? 8 : 1 );
	this->m_white = isWhite;

	this->setPixmap(QPixmap( ":/Pions/"+this->getType()+".png" ));

	lEchiquier->placerPiece( this );
}

Reine::Reine ( bool isWhite, Echiquier * lEchiquier ) : Piece( lEchiquier ) {
	this->m_x = 4;
	this->m_y = ( isWhite ? 8:1 );
	this->m_white = isWhite;

	this->setPixmap(QPixmap( ":/Pions/"+this->getType()+".png" ));

	lEchiquier->placerPiece( this );
}

Fou::Fou ( bool isWhite, int x, Echiquier * lEchiquier ) : Piece( lEchiquier ) {
	this->m_x = x;
	this->m_y = ( isWhite ? 8:1 );
	this->m_white = isWhite;

	this->setPixmap(QPixmap( ":/Pions/"+this->getType()+".png" ));

	lEchiquier->placerPiece( this );
}

Tour::Tour ( bool isWhite, int x, Echiquier * lEchiquier ) : Piece( lEchiquier ) {
	this->m_x = x;
	this->m_y = ( isWhite ? 8:1 );
	this->m_white = isWhite;

	this->setPixmap(QPixmap( ":/Pions/"+this->getType()+".png" ));

	lEchiquier->placerPiece( this );
}

Cavalier::Cavalier ( bool isWhite, int x, Echiquier * lEchiquier ) : Piece( lEchiquier ) {
	m_x = x;
	this->m_y = ( isWhite ? 8:1 );
	this->m_white = isWhite;

	this->setPixmap(QPixmap( ":/Pions/"+this->getType()+".png" ));

	lEchiquier->placerPiece( this );
}

Pion::Pion ( bool isWhite, int x, Echiquier * lEchiquier ) : Piece( lEchiquier ) {
	this->m_x = x;
	this->m_y = ( isWhite ? 7:2 );
	this->m_white = isWhite;

	this->setPixmap(QPixmap( ":/Pions/"+this->getType()+".png" ));

	lEchiquier->placerPiece( this );
}

QString Roi::getType () {
	return ( ( this->m_white ) ? "roi_blanc" : "roi_noir" );
}

QString Reine::getType () {
	return ( ( this->m_white ) ? "reine_blanc" : "reine_noir" );
}

QString Fou::getType () {
	return ( ( this->m_white ) ? "fou_blanc" : "fou_noir" );
}

QString Tour::getType () {
	return ( ( this->m_white ) ? "tour_blanc" : "tour_noir" );
}

QString Cavalier::getType () {
	return ( ( this->m_white ) ? "cavalier_blanc" : "cavalier_noir" );
}

QString Pion::getType () {
	return ( ( this->m_white ) ? "pion_blanc" : "pion_noir" );
}

bool Piece::miseEchec( int x, int y, bool & color, Echiquier * echiquier ) {
	int gp = 0;

	for ( int i = 1; i < 9; i++ ) {
		for ( int j = 1; j < 9; j++ ) {
			if ( color == this->m_white ) {
				if ( ( echiquier->getPiece( i, j ) != NULL ) && ( echiquier->getPiece( i, j )->getColor() != this->m_white ) && ( echiquier->getPiece( i, j )->getType() != "roi_blanc" ) && ( echiquier->getPiece( i, j )->getType() != "roi_noir" ) ) {
					if ( echiquier->getPiece( i, j )->mouvementValide( echiquier, x, y ) ) {
						gp += 1;
					}
					else {
						continue;
					}
				}
				else {
					continue;
				}
			}
			else {
				if ( ( echiquier->getPiece( i, j ) != NULL ) && ( echiquier->getPiece( i, j )->getColor() == this->m_white ) && ( echiquier->getPiece( i, j )->getType() != "roi_blanc" ) && ( echiquier->getPiece( i, j )->getType() != "roi_noir" ) ) {
					if ( echiquier->getPiece( i, j )->mouvementValide( echiquier, x, y ) ) {
						gp += 1;
					}
					else {
						continue;
					}
				}

				else {
					continue;
				}
			}
		}
	}

	if ( gp > 0 ) {
		return true;
	}
	else {
		return false;
	}
}

bool Piece::mouvementValide( Echiquier * echiquier, int x, int y ) {
	return true;
}

bool Roi::mouvementValide( Echiquier * echiquier, int x, int y ) {
	int ecart_x = x - this->x();
	int ecart_y = y - this->y();

	ecart_x = ( ecart_x > 0 ) ? ecart_x : ( ecart_x * -1 );
	ecart_y = ( ecart_y > 0 ) ? ecart_y : ( ecart_y * -1 );

	if ( ( ( x == this->x() ) && ( ecart_y == 1 ) ) || ( ( ecart_x == 1 ) && ( this->y() == y ) ) || ( ( ecart_x == 1 ) && ( ecart_y == 1 ) ) ) {
		this->miseEchec( this->x(), this->y(), this->m_white, echiquier );

		return true;
	}
	else {
		return false;
	}
}

bool Reine::mouvementValide( Echiquier * echiquier, int x, int y ) {
	int ecart_x = x - this->x();
	int ecart_y = y - this->y();

	int ecart_n1, ecart_n2;

	ecart_x = ( ecart_x > 0 ) ? ecart_x : ( ecart_x * -1 );
	ecart_y = ( ecart_y > 0 ) ? ecart_y : ( ecart_y * -1 );

	if ( ( ( ecart_x == 2 ) && ( ecart_y == 1 ) ) || ( ( ecart_x == 1 ) && ( ecart_y == 2 ) ) ){
		return false;
	}
	else {
		if ( ecart_x == ecart_y ) {
			int i = 0;

			ecart_n2 = ( y > this->y() ) ? this->y() + 1 : this->y() - 1;

			if ( this->x() < x ) {
				ecart_n1 = this->x() + 1;

				while ( ecart_n1 < x ) {
					if ( echiquier->getPiece( ecart_n1, ecart_n2 ) != NULL ) i += 1;

					ecart_n1 += 1;
					ecart_n2 = ( y > this->y() ) ? ecart_n2 += 1 : ecart_n2 -= 1;
				}
			}
			else {
				ecart_n1 = this->x() - 1;

				while ( x < ecart_n1 ) {
					if ( echiquier->getPiece( ecart_n1, ecart_n2 ) != NULL ) i += 1;

					ecart_n1 -= 1;
					ecart_n2 = ( y > this->y() ) ? ecart_n2 += 1 : ecart_n2 -= 1;
				}
			}

			if ( i > 0 ) {
				return false;
			}
			else {
				return true;
			}
		}

		else if ( ( x == this->x() ) || ( y == this->y() ) ) {
			if ( x == this->x() ) {
				ecart_n1 = ( y > this->y() ) ? this->y() + 1 : y + 1;
				ecart_n2 = ( y > this->y() ) ? y : this->y();

				int i = 0;
				while ( ecart_n1 < ecart_n2 ) {
					if ( echiquier->getPiece( this->x(), ecart_n1 ) != NULL ) {
						i += 1;
					}

					ecart_n1 += 1;
				}

				if ( i > 0 ) {
					return false;
				}
				else {
					return true;
				}
			}

			else if ( y == this->y() ) {
				ecart_n1 = ( x > this->x() ) ? this->x() + 1 : x + 1;
				ecart_n2 = ( x > this->x() ) ? x : this->x();

				int i = 0;
				while ( ecart_n1 < ecart_n2 ) {
					if ( echiquier->getPiece( ecart_n1, this->y() ) != NULL ) i += 1;
					ecart_n1 += 1;
				}

				if ( i > 0 ) {
					return false;
				}
				else {
					return true;
				}
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
}

bool Fou::mouvementValide( Echiquier * echiquier, int x, int y ) {
	int ecart_x = x - this->x();
	int ecart_y = y - this->y();

	ecart_x = ( ecart_x > 0 ) ? ecart_x : ( ecart_x * -1 );
	ecart_y = ( ecart_y > 0 ) ? ecart_y : ( ecart_y * -1) ;

	int ecart_n1, ecart_n2;

	if ( ecart_x == ecart_y ) {
		int i = 0;

		ecart_n2 = ( y > this->y() ) ? this->y() + 1 : this->y() - 1;

		if ( this->x() < x ) {
			ecart_n1 = this->x() + 1;

			while ( ecart_n1 < x ) {
				if ( echiquier->getPiece( ecart_n1, ecart_n2 ) != NULL) {
					i += 1;
				}

				ecart_n1 += 1;
				ecart_n2 = ( y > this->y() ) ? ecart_n2 += 1 : ecart_n2 -= 1;
			}
		}
		else {
			ecart_n1 = this->x() - 1;

			while ( x < ecart_n1 ) {
				if ( echiquier->getPiece( ecart_n1, ecart_n2 )!= NULL ) i += 1;

				ecart_n1 -= 1;
				ecart_n2 = ( y > this->y() ) ? ecart_n2 += 1 : ecart_n2 -= 1;
			}
		}

		if ( i > 0 ) {
			return false;
		}
		else {
			return true;
		}
	}
	else {
		return false;
	}
}

bool Tour::mouvementValide( Echiquier * echiquier, int x, int y ) {
	int ecart_n1, ecart_n2;

	if ( ( x == this->x() ) || ( y == this->y() ) ) {
		if ( x == this->x() ) {
			ecart_n1 = ( y > this->y() ) ? this->y() + 1 : y + 1;
			ecart_n2 = ( y > this->y() ) ? y : this->y();

			int i = 0;
			while ( ecart_n1 < ecart_n2 ) {
				if ( echiquier->getPiece( this->x(), ecart_n1 ) != NULL ) {
					i += 1;
				}

				ecart_n1 += 1;
			}

			if ( i > 0 ) {
				return false;
			}
			else {
				return true;
			}
		}
		else if ( y == this->y() ) {
			ecart_n1 = ( x > this->x() ) ? this->x() + 1 : x + 1;
			ecart_n2 = ( x > this->x() ) ? x : this->x();

			int i = 0;
			while ( ecart_n1 < ecart_n2 ) {
				if ( echiquier->getPiece( ecart_n1, this->y() ) != NULL ) {
					i += 1;
				}

				ecart_n1 += 1;
			}

			if ( i > 0 ) {
				return false;
			}
			else {
				return true;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool Cavalier::mouvementValide( Echiquier * echiquier, int x, int y ) {
	int ecart_x = x - this->x();
	int ecart_y = y - this->y();

	ecart_x = ( ecart_x > 0 ) ? ecart_x : ( ecart_x * -1 );
	ecart_y = ( ecart_y > 0 ) ? ecart_y : ( ecart_y * -1 );

	if ( ( ecart_x == 1 || ecart_x == 2 ) && ( ecart_y == 1 || ecart_y == 2 ) ) {
		return true;
	}
	else {
		return false;
	}
}

bool Pion::mouvementValide( Echiquier * echiquier, int x, int y ) {
	Piece * afterPiece = echiquier->getPiece( x, y );

	if ( afterPiece == NULL ) {
		if ( x == this->x() ) {
			int sens = this->m_white ? -1 : 1;

			if ( this->y() + ( 1 * sens ) == y ) {
				return true;
			}
			else {
				if (
					(
						( this->m_white && this->y() == 7 ) ||
						( !this->m_white && this->y() == 2 )
					) &&
					( this->y() + ( 2 * sens ) == y )
				) {
					return true;
				}
				else {
					return false;
				}
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

void Piece::mousePressEvent( QMouseEvent * event ) {
	QMap<int, QString> abscisse;

	abscisse.insert(1, "A");
	abscisse.insert(2, "B");
	abscisse.insert(3, "C");
	abscisse.insert(4, "D");
	abscisse.insert(5, "E");
	abscisse.insert(6, "F");
	abscisse.insert(7, "G");
	abscisse.insert(8, "H");

	this->selection();

	//pieceOrigine

	QLineEdit * pieceOrigine = this->_echiquier->getCentralWidget()->findChild<QLineEdit *>("pieceOrigine");
	QLineEdit * pieceDestination = this->_echiquier->getCentralWidget()->findChild<QLineEdit *>("pieceDestination");

	if (
		( this->_echiquier->xd() >= 1 && this->_echiquier->xd() <= 8 ) &&
		( this->_echiquier->yd() >= 1 && this->_echiquier->yd() <= 8 ) &&
		this->_echiquier->player == this->getColor()
	) {
		this->_echiquier->xf( this->x() );
		this->_echiquier->yf( this->y() );

		pieceDestination->setText( abscisse.value( this->x() ) + QString::number( this->y() ) );

		this->_echiquier->makeMove();
	}
	else {
		this->_echiquier->xd( this->x() );
		this->_echiquier->yd( this->y() );

		pieceOrigine->setText( abscisse.value( this->x() ) + QString::number( this->y() ) );
		pieceDestination->setText( "" );
	}
}

void Piece::selection() {
	for ( int i = 0; i < 64; i++ ) {
		if ( i < 16 || i > 47 ) {
			//this->_echiquier->getPiece( i )->setEnabled( true );
		}
	}

	//this->setEnabled( false );
}
