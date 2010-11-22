#if !defined Joueur_h
	#define Joueur_h

	#include "Piece.h"
	#include "Echiquier.h"

	class Joueur {
		protected:
			Piece m_pieces[ 16 ];

		public:
			Joueur();
			Joueur( bool white );
			void placerPieces( Echiquier & e );
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
