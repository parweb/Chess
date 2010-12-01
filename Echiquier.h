#if !defined Echiquier_h
	#define Echiquier_h
	#include <QGraphicsView>
	#include <QMessageBox>
	#include <QPushButton>
	#include <QMap>
	#include <QInputDialog>
	#include <QGridLayout>
	#include <QAction>

	#include "Piece.h"
	#include "Joueur.h"
	#include "mainwindow.h"
	#include "MyQGraphicsView.h"

	#include <iostream>

	class Piece;

	class Echiquier : QWidget {
		Q_OBJECT

		private:
			Piece * m_cases[ 64 ];
			QWidget * centralWidget;
			QWidget * _damier;

			QLineEdit * _pieceDestination;
			QLineEdit * _pieceOrigine;
			QLabel * legendBlanc;
			QLabel * legendNoir;

			QString _joueur1;
			QString _joueur2;

			int _xd, _yd, _xf, _yf;

//			JoueurBlanc _JoueurBlanc;
//			JoueurNoir _JoueurNoir;

		public:
			int xd();
			int yd();
			int xf();
			int yf();
			void xd( int i );
			void yd( int i );
			void xf( int i );
			void yf( int i );

			QGridLayout * _pions;
			bool player; // true:blanc ou false:noir

			Echiquier();
			Echiquier( QWidget * parent );

			Piece * getPiece( int x, int y );
			Piece * getPiece( int i );

			QWidget * getCentralWidget();

			void setPiece( int x, int y, Piece * p );
			void setPiece( int i, Piece * p );

			void create();

			void makeMove();

			void togglePlayer();

			QLabel * getInfo();
			void setInfo( QString text );

			bool placerPiece( int x, int y );
			bool placerPiece( Piece * p );
			bool placerPiece( Piece & p );

			bool deplacerPiece( Piece * p, int x, int y );
			bool deplacerPiece( int xd, int yd, int xf, int yf );

			bool enleverPiece( int x, int y );
			bool enleverPiece( Piece * p );

			int getCase( int x, int y );
			int getCase( Piece * p );

			QPoint * getCoord( int i );

			QWidget * getDamier ();

			void getLegendX ();
			void getLegendY ();
			void getPions ();

			void getButtonNew ();
			void getButtonMove ();
			void getLegendJoueur ();

			QFont getLegendFont ();

		public slots:
			void clicked_buttonNew();
			void clicked_buttonMove();
	};
#endif
