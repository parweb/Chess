#if !defined Piece_h
	#define Piece_h

	#include <iostream>
	#include <QString>
	#include <QLabel>
	#include <QMouseEvent>

	#include "Echiquier.h"

	class Echiquier;

	class Piece : public QLabel {
		protected:
			int m_x;
			int m_y;
			bool m_white;
			Echiquier * _echiquier;

		public:
			Piece();
			Piece( Echiquier * lEchiquier );
			Piece( int x, int y, bool isWhite );
			Piece( const Piece & autre);
			Piece & operator=(const Piece & autre);
			void init( int x, int y, bool isWhite );
			bool moveTo( int x, int y, Echiquier * e );
			//virtual void moveTo( int x, int y );
			virtual bool mouvementValide( Echiquier * e, int x, int y );
			int x() const;
			int y() const;
			bool getColor();
			virtual QString getType() = 0;
			bool miseEchec( int x, int y, bool & color, Echiquier * echiquier );
			void mousePressEvent( QMouseEvent * event );
			void selection();
	};

	class Roi : public Piece {
		public:
			Roi();
			Roi(bool isWhite, Echiquier * lEchiquier );
			bool mouvementValide( Echiquier * e, int x, int y);
			QString getType();
	};

	class Reine : public Piece {
		public:
			Reine();
			Reine(bool isWhite, Echiquier * lEchiquier );
			bool mouvementValide( Echiquier * e, int x, int y);
			QString getType();
	};

	class Pion : public Piece {
		public:
			Pion();
			Pion(bool isWhite, int nb, Echiquier * lEchiquier );
			bool mouvementValide( Echiquier * e, int x, int y);
			QString getType();
	};

	class Fou : public Piece {
		public:
			Fou();
			Fou(bool isWhite, int nb, Echiquier * lEchiquier );
			bool mouvementValide( Echiquier * e, int x, int y);
			QString getType();
	};

	class Cavalier : public Piece {
		public:
			Cavalier();
			Cavalier(bool isWhite, int nb, Echiquier * lEchiquier );
			bool mouvementValide( Echiquier * e, int x, int y);
			QString getType();
	};

	class Tour : public Piece {
		public:
			Tour();
			Tour(bool isWhite, int nb, Echiquier * lEchiquier );
			bool mouvementValide( Echiquier * e, int x, int y);
			QString getType();
	};
#endif
