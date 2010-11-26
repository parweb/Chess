#if !defined Joueur_h
	#define Joueur_h

#include "Piece.h"
	#include <iostream>


	class Piece;
	class Tour;
	class Cavalier;
	class Fou;
	class Roi;
	class Reine;
	class Pion;

	class Joueur {
		protected:
			Piece * m_pieces[ 16 ];

		public:
			Joueur();
			Joueur( bool isWhite );
			void placerPieces( Echiquier * e );

			Tour _Tour1;
			Tour _Tour2;

			Cavalier _Cavalier1;
			Cavalier _Cavalier2;

			Fou _Fou1;
			Fou _Fou2;

			Roi _Roi;
			Reine _Reine;

			Pion _Pion1;
			Pion _Pion2;
			Pion _Pion3;
			Pion _Pion4;
			Pion _Pion5;
			Pion _Pion6;
			Pion _Pion7;
			Pion _Pion8;
	};

	class JoueurBlanc : public Joueur {
		public:
			JoueurBlanc();
	};

	class JoueurNoir : public Joueur {
		public:
			JoueurNoir();
	};
#endif
