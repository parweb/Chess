#if !defined Echiquier_h
	#define Echiquier_h

	#include <iostream>

	#include "Piece.h"
	#include "Joueur.h"
	#include "MainWindow.h"
	#include "ui_mainwindow.h"

	class Piece;

	class Echiquier {
		private:
			Piece * m_cases[ 64 ];

		public:
			Echiquier();
			Piece * getPiece( int x, int y );
			bool create( Ui::MainWindow *& _ui );
			bool placerPiece( Piece * p );
			bool deplacerPiece( Piece * p, int x, int y );
			bool deplacerPiece( int xd, int yd, int xf, int yf );
			bool enleverPiece( int x, int y );
			int getCase( int x, int y );
			QWidget * getQWidget( QWidget *& _centralWidget );
	};
#endif
