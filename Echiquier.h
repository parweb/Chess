#if !defined Echiquier_h
	#define Echiquier_h

	#include "Piece.h"
	#include "Joueur.h"
	#include "MainWindow.h"
	#include "ui_mainwindow.h"

	class Echiquier {
		private:
			Piece* m_cases[ 64 ];

		public:
			//QMainWindow* _ui;
			Echiquier();
			Piece* getPiece( int x, int y );
			bool create( Ui::MainWindow* & _ui );
			//bool create();
			bool placer( Piece* p );
			bool deplacer( Piece* p, int x, int y );
			bool deplacer( int xd, int yd, int xf, int yf );
			Piece* enleverPiece( int x, int y );
			int getCase( int x, int y );
			QWidget* getQWidget( QWidget* & _centralWidget );
	};
#endif
