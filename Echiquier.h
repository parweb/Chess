#if !defined Echiquier_h
	#define Echiquier_h

	#include <iostream>
	#include <QMessageBox>

	#include "Piece.h"
	#include "Joueur.h"
	#include "MainWindow.h"
	#include "ui_mainwindow.h"

	class Piece;

	class Echiquier : QWidget {
		//Q_OBJECT

		private:
			Piece * m_cases[ 64 ];

		public:
			Echiquier();
			Echiquier( QWidget * parent );

			Piece * getPiece( int x, int y );
			Piece * getPiece( int i );

			void setPiece( int x, int y, Piece * p );
			void setPiece( int i, Piece * p );

			void create( QWidget * parent );

			bool placerPiece( int x, int y );
			bool placerPiece( Piece * p );

			bool deplacerPiece( Piece * p, int x, int y );
			bool deplacerPiece( int xd, int yd, int xf, int yf );

			bool enleverPiece( int x, int y );
			bool enleverPiece( Piece * p );

			int getCase( int x, int y );
			int getCase( Piece * p );

			QPoint * getCoord( int i );

			void getDamier ( QWidget * parent );
			void getLegendX ( QWidget * parent );
			void getLegendY ( QWidget * parent );

			void getButtonNew ( QWidget * parent );


			QFont getLegendFont ();

			QWidget * getQWidget( QWidget *& _centralWidget );

		public slots:
			void clicked_buttonNew();
	};
#endif
