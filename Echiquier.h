#if !defined Echiquier_h
	#define Echiquier_h

	#include <iostream>
	#include <QGraphicsView>
	#include <QMessageBox>
	#include <QPushButton>
	#include <QMap>
	#include <QInputDialog>
	#include <QGridLayout>

	#include "Piece.h"
	#include "Joueur.h"

	class Piece;

	class Echiquier : QWidget {
		Q_OBJECT

		private:
			Piece * m_cases[ 64 ];
			QWidget * centralWidget;
			QWidget * _damier;
			QGridLayout * _pions;

		public:
			Echiquier();
			Echiquier( QWidget * parent );

			Piece * getPiece( int x, int y );
			Piece * getPiece( int i );

			void setPiece( int x, int y, Piece * p );
			void setPiece( int i, Piece * p );

			void create();

			bool placerPiece( int x, int y );
			bool placerPiece( Piece * p );

			bool deplacerPiece( Piece * p, int x, int y );
			bool deplacerPiece( int xd, int yd, int xf, int yf );

			bool enleverPiece( int x, int y );
			bool enleverPiece( Piece * p );

			int getCase( int x, int y );
			int getCase( Piece * p );

			QPoint * getCoord( int i );

			QWidget * getDamier ( QWidget * parent );
			void getLegendX ( QWidget * parent );
			void getLegendY ( QWidget * parent );
			void getPions ( QWidget * parent );

			void getButtonNew ( QWidget * parent );


			QFont getLegendFont ();

			QWidget * getQWidget( QWidget *& _centralWidget );

		public slots:
			void clicked_buttonNew();
	};
#endif
