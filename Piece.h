#if !defined Piece_h
	#define Piece_h

	#include <QString>

	class Echiquier;

	class Piece {
		/*static const int _X = 70;
		static const int _Y = 105;
		static const int _EX = 50;
		static const int _EY = 50;*/

		protected:
			int m_x;
			int m_y;
			bool m_white;

		public:
			Piece();
			Piece( int x, int y, bool white );
			Piece( const Piece & autre);
			Piece & operator=(const Piece & autre);
			void init( int x, int y, bool white );
			void move( int x, int y );
			virtual bool mouvementValide(Echiquier & e, int x, int y);
			int x() const;
			int y() const;
			bool isWhite();
			bool isBlack();
			virtual QString myType();
	};

	class Roi : public Piece {
		public:
			Roi(bool white);
			bool mouvementValide(Echiquier &e, int x, int y);
			QString myType();
	};

	class Reine : public Piece {
		public:
			Reine(bool white);
			bool mouvementValide(Echiquier &e, int x, int y);
			QString myType();
	};

	class Pion : public Piece {
		public:
			Pion(bool white, int nb);
			bool mouvementValide(Echiquier &e, int x, int y);
			QString myType();
	};

	class Fou : public Piece {
		public:
			Fou(bool white, int nb);
			bool mouvementValide(Echiquier &e, int x, int y);
			QString myType();
	};

	class Cavalier : public Piece {
		public:
			Cavalier(bool white, int nb);
			bool mouvementValide(Echiquier &e, int x, int y);
			QString myType();
	};

	class Tour : public Piece {
		public:
			Tour(bool white, int nb);
			bool mouvementValide(Echiquier &e, int x, int y);
			QString myType();
	};
#endif
