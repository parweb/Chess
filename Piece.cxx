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

Piece::Piece ( QWidget * parent ) : QLabel( parent ) {
	this->setGeometry(QRect(0, 0, 50, 50));
	this->setScaledContents(true);
	this->setAlignment(Qt::AlignCenter);

	this->setFixedSize( 50, 50 );
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

Roi::Roi () {}
Reine::Reine () {}
Tour::Tour () {}
Fou::Fou () {}
Cavalier::Cavalier () {}

Roi::Roi ( bool isWhite, Echiquier * lEchiquier ) : Piece( lEchiquier->getCentralWidget() ) {
	this->m_x = 5;
	this->m_y = ( isWhite ? 8 : 1 );
	this->m_white = isWhite;

	this->setPixmap(QPixmap( ":/Pions/"+this->getType()+".png" ));

	lEchiquier->placerPiece( this );
}

Reine::Reine ( bool isWhite, Echiquier * lEchiquier ) : Piece( lEchiquier->getCentralWidget() ) {
	this->m_x = 4;
	this->m_y = ( isWhite ? 8:1 );
	this->m_white = isWhite;

	this->setPixmap(QPixmap( ":/Pions/"+this->getType()+".png" ));
}

Fou::Fou ( bool isWhite, int x, Echiquier * lEchiquier ) : Piece( lEchiquier->getCentralWidget() ) {
	this->m_x = x;
	this->m_y = ( isWhite ? 8:1 );
	this->m_white = isWhite;

	this->setPixmap(QPixmap( ":/Pions/"+this->getType()+".png" ));
}

Tour::Tour ( bool isWhite, int x, Echiquier * lEchiquier ) : Piece( lEchiquier->getCentralWidget() ) {
	this->m_x = x;
	this->m_y = ( isWhite ? 8:1 );
	this->m_white = isWhite;

	this->setPixmap(QPixmap( ":/Pions/"+this->getType()+".png" ));
}

Cavalier::Cavalier ( bool isWhite, int x, Echiquier * lEchiquier ) : Piece( lEchiquier->getCentralWidget() ) {
	m_x = x;
	this->m_y = ( isWhite ? 8:1 );
	this->m_white = isWhite;

	this->setPixmap(QPixmap( ":/Pions/"+this->getType()+".png" ));
}

Pion::Pion ( bool isWhite, int x, Echiquier * lEchiquier ) : Piece( lEchiquier->getCentralWidget() ) {
	this->m_x = x;
	this->m_y = ( isWhite ? 7:2 );
	this->m_white = isWhite;

	this->setPixmap(QPixmap( ":/Pions/"+this->getType()+".png" ));
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

bool Piece::miseEchec( int x, int y, bool & color, Echiquier & echiquier ) {
	int gp = 0;

	for ( int i = 1; i < 9; i++ ) {
		for ( int j = 1; j < 9; j++ ) {
			if ( color == this->m_white ) {
				if ( ( echiquier.getPiece( i, j ) != NULL ) && ( echiquier.getPiece( i, j )->isWhite() != this->m_white ) && ( echiquier.getPiece( i, j )->getType() != "roi_blanc" ) && ( echiquier.getPiece( i, j )->getType() != "roi_noir" ) ) {
					if ( echiquier.getPiece( i, j )->mouvementValide( x, y, echiquier ) ) {
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
				if ( ( echiquier.getPiece( i, j ) != NULL ) && ( echiquier.getPiece( i, j )->isWhite() == this->m_white ) && ( echiquier.getPiece( i, j )->getType() != "roi_blanc" ) && ( echiquier.getPiece( i, j )->getType() != "roi_noir" ) ) {
					if ( echiquier.getPiece( i, j )->mouvementValide( x, y, echiquier ) ) {
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

bool Piece::mouvementValide( int x, int y, Echiquier & echiquier ) {
	return true;
}

bool Roi::mouvementValide ( Echiquier & echiquier, int x, int y ) {
	int tmp_x = x - this->x();
	int tmp_y = y - this->y();

	tmp_x = ( tmp_x > 0 ) ? tmp_x : ( tmp_x * -1 );
	tmp_y = ( tmp_y > 0 ) ? tmp_y : ( tmp_y * -1 );

	if ( ( ( x == this->x() ) && ( tmp_y == 1 ) ) || ( ( tmp_x == 1 ) && ( this->y() == y ) ) || ( ( tmp_x == 1 ) && ( tmp_y == 1 ) ) ) {
		this->miseEchec( this->x(), this->y(), this->m_white, echiquier );

		return true;
	}
	else {
		return false;
	}
}

bool Reine::mouvementValide ( Echiquier & echiquier, int x, int y ) {
	int tmp_x = x - this->x();
	int tmp_y = y - this->y();

	int tmp_n1, tmp_n2;

	tmp_x = ( tmp_x > 0 ) ? tmp_x : ( tmp_x * -1 );
	tmp_y = ( tmp_y > 0 ) ? tmp_y : ( tmp_y * -1 );

	if ( ( ( tmp_x == 2 ) && ( tmp_y == 1 ) ) || ( ( tmp_x == 1 ) && ( tmp_y == 2 ) ) ){
		return false;
	}
	else {
		if ( tmp_x == tmp_y ) {
			int i = 0;

			tmp_n2 = ( y > this->y() ) ? this->y() + 1 : this->y() - 1;

			if ( this->x() < x ) {
				tmp_n1 = this->x() + 1;

				while ( tmp_n1 < x ) {
					if ( echiquier.getPiece( tmp_n1, tmp_n2 ) != NULL ) i += 1;

					tmp_n1 += 1;
					tmp_n2 = ( y > this->y() ) ? tmp_n2 += 1 : tmp_n2 -= 1;
				}
			}
			else {
				tmp_n1 = this->x() - 1;

				while ( x < tmp_n1 ) {
					if ( echiquier.getPiece( tmp_n1, tmp_n2 ) != NULL ) i += 1;

					tmp_n1 -= 1;
					tmp_n2 = ( y > this->y() ) ? tmp_n2 += 1 : tmp_n2 -= 1;
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
				tmp_n1 = ( y > this->y() ) ? this->y() + 1 : y + 1;
				tmp_n2 = ( y > this->y() ) ? y : this->y();

				int i = 0;
				while ( tmp_n1 < tmp_n2 ) {
					if ( echiquier.getPiece( this->x(), tmp_n1 ) != NULL ) {
						i += 1;
					}

					tmp_n1 += 1;
				}

				if ( i > 0 ) {
					return false;
				}
				else {
					return true;
				}
			}

			else if ( y == this->y() ) {
				tmp_n1 = ( x > this->x() ) ? this->x() + 1 : x + 1;
				tmp_n2 = ( x > this->x() ) ? x : this->x();

				int i = 0;
				while ( tmp_n1 < tmp_n2 ) {
					if ( echiquier.getPiece( tmp_n1, this->y() ) != NULL ) i += 1;
					tmp_n1 += 1;
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

bool Fou::mouvementValide ( Echiquier & echiquier, int x, int y ) {
	int tmp_x = x - this->x();
	int tmp_y = y - this->y();

	tmp_x = ( tmp_x > 0 ) ? tmp_x : ( tmp_x * -1 );
	tmp_y = ( tmp_y > 0 ) ? tmp_y : ( tmp_y * -1) ;

	int tmp_n1, tmp_n2;

	if ( tmp_x == tmp_y ) {
		int i = 0;

		tmp_n2 = ( y > this->y() ) ? this->y() + 1 : this->y() - 1;

		if ( this->x() < x ) {
			tmp_n1 = this->x() + 1;

			while ( tmp_n1 < x ) {
				if ( echiquier.getPiece( tmp_n1, tmp_n2 ) != NULL) {
					i += 1;
				}

				tmp_n1 += 1;
				tmp_n2 = ( y > this->y() ) ? tmp_n2 += 1 : tmp_n2 -= 1;
			}
		}
		else {
			tmp_n1 = this->x() - 1;

			while ( x < tmp_n1 ) {
				if ( echiquier.getPiece( tmp_n1, tmp_n2 )!= NULL ) i += 1;

				tmp_n1 -= 1;
				tmp_n2 = ( y > this->y() ) ? tmp_n2 += 1 : tmp_n2 -= 1;
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

bool Tour::mouvementValide ( Echiquier & echiquier, int x, int y ) {
	int tmp_n1, tmp_n2;

	if ( ( x == this->x() ) || ( y == this->y() ) ) {
		if ( x == this->x() ) {
			tmp_n1 = ( y > this->y() ) ? this->y() + 1 : y + 1;
			tmp_n2 = ( y > this->y() ) ? y : this->y();

			int i = 0;
			while ( tmp_n1 < tmp_n2 ) {
				if ( echiquier.getPiece( this->x(), tmp_n1 ) != NULL ) {
					i += 1;
				}

				tmp_n1 += 1;
			}

			if ( i > 0 ) {
				return false;
			}
			else {
				return true;
			}
		}
		else if ( y == this->y() ) {
			tmp_n1 = ( x > this->x() ) ? this->x() + 1 : x + 1;
			tmp_n2 = ( x > this->x() ) ? x : this->x();

			int i = 0;
			while ( tmp_n1 < tmp_n2 ) {
				if ( echiquier.getPiece( tmp_n1, this->y() ) != NULL ) {
					i += 1;
				}

				tmp_n1 += 1;
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

bool Cavalier::mouvementValide ( Echiquier & echiquier, int x, int y ) {
	int tmp_x = x - this->x();
	int tmp_y = y - this->y();

	tmp_x = ( tmp_x > 0 ) ? tmp_x : ( tmp_x * -1 );
	tmp_y = ( tmp_y > 0 ) ? tmp_y : ( tmp_y * -1 );

	if ( ( tmp_x == 1 || tmp_x == 2 ) && ( tmp_y == 1 || tmp_y == 2 ) ) {
		return true;
	}
	else {
		return false;
	}
}

bool Pion::mouvementValide ( Echiquier & echiquier, int x, int y ) {
	if ( echiquier.getPiece( x, y ) == NULL ) {
		if ( this->m_white ) {
			if ( this->y() == 2 ) {
				if ( ( x == this->x() ) && ( ( y - this->y() == 2 ) || ( y - this->y() == 1 ) ) ) {
					return true;
				}
				else {
					return false;
				}
			}
			else {
				if ( ( x == this->x() ) && ( y - this->y() == 1 ) ) {
					return true;
				}
				else {
					return false;
				}
			}
		}
		else {
			if ( this->y() == 7 ) {
				if ( ( x == this->x() ) && ( ( this->y() - y == 1 ) || ( this->y() - y == 2 ) ) ) {
					return true;
				}
				else {
					return false;
				}
			}
			else {
				if ( ( x == this->x() ) && ( this->y() - y == 1 ) ) {
					return true;
				}
				else {
					return false;
				}
			}
		}
	}
	else {
		if ( this->m_white ) {
			if ( (this->x() != x ) && ( y - this->y() == 1 ) ) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			if ( ( this->x() != x ) && ( this->y() - y == 1 ) ) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}
