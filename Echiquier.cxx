#include "Echiquier.h"

using namespace std;

Echiquier::Echiquier() {
	for ( int i = 0; i < 64; ++i ) {
		m_cases[ i ] = NULL;
	}
}

Echiquier::Echiquier( QWidget * parent ) : QWidget( parent ) {
	this->centralWidget = parent;
	this->setObjectName( "echiquier" );

	this->getButtonNew();
	this->getButtonMove();
	this->getLegendX();
	this->getLegendY();

	this->_damier = this->getDamier();


	//this->_pions->move( 60, 100 );
}

Piece * Echiquier::getPiece( int x, int y ) {
	if (
		( x >= 1 ) && ( x <= 8 ) &&
		( y >= 1 ) && ( y <= 8 )
	) {
		return this->getPiece( getCase( x, y ) );
	}
	else {
		cout << "mauvais coord: x:" << x << " y:" << y << " !";
	}

	return NULL;
}

Piece * Echiquier::getPiece( int i ) {
	if ( ( i >= 0 ) && ( i <= 63 ) ) {
		return this->m_cases[ i ];
	}
	else {
		cout << "Nombre non compris entre 0 et 63 !";
	}

	return NULL;
}

QWidget * Echiquier::getCentralWidget() {
	return this->centralWidget;
}

void Echiquier::setPiece( int i, Piece * p ) {
	if ( ( i >= 0 ) && ( i <= 63 ) ) {
		this->m_cases[ i ] = p;
	}
	else {
		cout << "Nombre non compris entre 0 et 63 !";
	}
}

void Echiquier::setPiece( int x, int y, Piece * p ) {
	if (
		( x >= 1 ) && ( x <= 8 ) &&
		( y >= 1 ) && ( y <= 8 )
	) {
		this->setPiece( this->getCase( x, y ), p );
	}
	else {
		cout << "Coordonnée non valide";
	}
}

bool Echiquier::placerPiece( int x, int y ) {
	return this->placerPiece( this->getPiece( x, y ) );
}


bool Echiquier::placerPiece( Piece & p ) {
	return this->placerPiece( this->getPiece( p.x(), p.y() ) );
}

bool Echiquier::placerPiece( Piece * p ) {
	if (
		( p->x() >= 1 ) && ( p->x() <= 8 )
		&& ( p->y() >= 1 ) && ( p->y() <= 8 )
		&& ( p != NULL )
	) {
		int i = this->getCase( p->x(), p->y() );
		this->setPiece( i, p );

		//p->moveTo( p->x(), p->y() );

		this->_pions->addWidget( p, p->y(), p->x() );

		return true;
	}

	return false;
}

bool Echiquier::deplacerPiece( Piece * p, int x, int y ) {
	if (
		( p != NULL ) &&
		( x >= 1 ) && ( x <= 8 ) &&
		( y >= 1 ) && ( y <= 8 )
	) {
		this->enleverPiece( p->x(), p->y() );
		p->moveTo( x, y );
		return this->placerPiece( p );
	}

	return false;
}

bool Echiquier::deplacerPiece( int xd, int yd, int xf, int yf ) {
	return this->deplacerPiece( this->getPiece( xd, yd ), xf, yf );
}

bool Echiquier::enleverPiece( int x, int y ) {
	if (
		( x >= 1 ) && ( x <= 8 ) &&
		( y >= 1 ) && ( y <= 8 )
	) {
		this->setPiece( this->getCase( x, y ), NULL );

		return true;
	}

	return false;
}

bool Echiquier::enleverPiece( Piece * p ) {
	if (
		( p->x() >= 1 ) && ( p->x() <= 8 ) &&
		( p->y() >= 1 ) && ( p->y() <= 8 )
	) {
		return this->enleverPiece( p->x(), p->y() );
	}

	return false;
}

int Echiquier::getCase( int x, int y ) {
	return ( x - 1 + ( y - 1 ) * 8 );
}

int Echiquier::getCase( Piece * p ) {
	return getCase( p->x(), p->y() );
}

QPoint * Echiquier::getCoord( int i ) {
	int x, y;

	x = ( i % 8 ) + 1;
	y = ( i / 8 ) + 1;

	return new QPoint( x, y );
}

QWidget * Echiquier::getDamier () {
	QWidget * conteneur = new QWidget( this->getCentralWidget() );
	conteneur->resize( 400, 400 );
	conteneur->move( 60, 100 );

	for ( int i = 0; i < 64; i++ ) {
		this->setPiece( i, NULL );

		QPoint * coord = this->getCoord( i );

		int xi = 0;
		int yi = 0;
		int exi = 50;
		int eyi = 50;

		int xf, yf;

		xf = xi + ( exi * ( coord->x() - 1 ) );
		yf = yi + ( eyi * ( coord->y() - 1 ) );

		QGraphicsView * place = new QGraphicsView( conteneur );

		place->setObjectName( "CASE_"+QString::number( i+1 ) );
		place->setGeometry( QRect( xf, yf, exi, eyi ) );
		place->setAutoFillBackground( false );

		if ( ( coord->x() + coord->y() ) % 2 ) {
			place->setStyleSheet( QString::fromUtf8( "background:rgb( 100, 100, 100 );") );
		}
	}

	this->_pions = new QGridLayout( conteneur );

	this->_pions->setSpacing( 0 );
	this->_pions->setContentsMargins( 0, 0, 0, 0 );

	this->_pions->setColumnMinimumWidth(1, 50 );
	this->_pions->setColumnMinimumWidth(2, 50 );
	this->_pions->setColumnMinimumWidth(3, 50 );
	this->_pions->setColumnMinimumWidth(4, 50 );
	this->_pions->setColumnMinimumWidth(5, 50 );
	this->_pions->setColumnMinimumWidth(6, 50 );
	this->_pions->setColumnMinimumWidth(7, 50 );
	this->_pions->setColumnMinimumWidth(8, 50 );

	this->_pions->setRowMinimumHeight(1, 50 );
	this->_pions->setRowMinimumHeight(2, 50 );
	this->_pions->setRowMinimumHeight(3, 50 );
	this->_pions->setRowMinimumHeight(4, 50 );
	this->_pions->setRowMinimumHeight(5, 50 );
	this->_pions->setRowMinimumHeight(6, 50 );
	this->_pions->setRowMinimumHeight(7, 50 );
	this->_pions->setRowMinimumHeight(8, 50 );

	return conteneur;
}

void Echiquier::getLegendX () {
	QMap<int, QString> abscisse;

	abscisse.insert( 0, "A" );
	abscisse.insert( 1, "B" );
	abscisse.insert( 2, "C" );
	abscisse.insert( 3, "D" );
	abscisse.insert( 4, "E" );
	abscisse.insert( 5, "F" );
	abscisse.insert( 6, "G" );
	abscisse.insert( 7, "H" );

	int Depart = 0;
	int Ecart = 50;
	int Arrive = 0;

	QWidget * conteneur = new QWidget( this->getCentralWidget() );
	conteneur->resize( 400, 50 );
	conteneur->move( 60, 50 );

	for ( int i = 0; i < 8; i++ ) {
		QLabel * label = new QLabel( conteneur );

		Arrive = Depart + ( Ecart * i );

		label->setObjectName( "_"+abscisse.value( i ) );
		label->setText( abscisse.value( i ) );
		label->setGeometry( QRect( Arrive, 0, 50, 50 ) );
		label->setFont( this->getLegendFont() );
		label->setAlignment( Qt::AlignCenter );
	}
}

void Echiquier::getLegendY () {
	int Depart = 0;
	int Ecart = 50;
	int Arrive = 0;

	QWidget * conteneur = new QWidget( this->getCentralWidget() );
	conteneur->resize( 50, 400 );
	conteneur->move( 10, 100 );

	for ( int i = 0; i < 8; i++ ) {
		QLabel * label = new QLabel( conteneur );

		Arrive = Depart + ( Ecart * i );

		label->setObjectName( "_"+QString::number( i+1 ) );
		label->setText( QString::number( i+1 ) );
		label->setGeometry( QRect( 0, Arrive, 50, 50 ) );
		label->setFont( this->getLegendFont() );
		label->setAlignment( Qt::AlignCenter );
	}
}

void Echiquier::getPions () {
	Roi * RoiBlanc = new Roi( true, this );
	Roi * RoiNoir = new Roi( false, this );
	Reine * ReineBlanc = new Reine( true, this );
	Reine * ReineNoir = new Reine( false, this );
	Cavalier * CavalierBlanc1 = new Cavalier( true, 2, this );
	Cavalier * CavalierBlanc2 = new Cavalier( true, 7, this );
	Cavalier * CavalierNoir1 = new Cavalier( false, 2, this );
	Cavalier * CavalierNoir2 = new Cavalier( false, 7, this );
	Tour * TourBlanc1 = new Tour( true, 1, this );
	Tour * TourBlanc2 = new Tour( true, 8, this );
	Tour * TourNoir1 = new Tour( false, 1, this );
	Tour * TourNoir2 = new Tour( false, 8, this );
	Fou * FouBlanc1 = new Fou( true, 3, this );
	Fou * FouBlanc2 = new Fou( true, 6, this );
	Fou * FouNoir1 = new Fou( false, 3, this );
	Fou * FouNoir2 = new Fou( false, 6, this );
	Pion * PionBlanc1 = new Pion( true, 1, this );
	Pion * PionBlanc2 = new Pion( true, 2, this );
	Pion * PionBlanc3 = new Pion( true, 3, this );
	Pion * PionBlanc4 = new Pion( true, 4, this );
	Pion * PionBlanc5 = new Pion( true, 5, this );
	Pion * PionBlanc6 = new Pion( true, 6, this );
	Pion * PionBlanc7 = new Pion( true, 7, this );
	Pion * PionBlanc8 = new Pion( true, 8, this );
	Pion * PionNoir1 = new Pion( false, 1, this );
	Pion * PionNoir2 = new Pion( false, 2, this );
	Pion * PionNoir3 = new Pion( false, 3, this );
	Pion * PionNoir4 = new Pion( false, 4, this );
	Pion * PionNoir5 = new Pion( false, 5, this );
	Pion * PionNoir6 = new Pion( false, 6, this );
	Pion * PionNoir7 = new Pion( false, 7, this );
	Pion * PionNoir8 = new Pion( false, 8, this );
}

QFont Echiquier::getLegendFont () {
	QFont font;
	font.setPointSize( 30 );

	return font;
}

void Echiquier::getButtonNew () {
	QPushButton * buttonNew = new QPushButton( this->getCentralWidget() );
	buttonNew->setObjectName( "boutonNew" );
	buttonNew->setGeometry( QRect( 80, 20, 110, 32) );
	buttonNew->setText( "Nouveau" );

	QObject::connect( buttonNew, SIGNAL( clicked() ), this, SLOT( clicked_buttonNew() ) );
}

void Echiquier::getButtonMove () {
	QLineEdit * pieceOrigine = new QLineEdit( this->getCentralWidget() );
	pieceOrigine->setObjectName( "pieceOrigine" );
	pieceOrigine->setGeometry( QRect( 150, 525, 41, 22 ) );
	this->_pieceOrigine = pieceOrigine;

	QLineEdit * pieceDestination = new QLineEdit( this->getCentralWidget() );
	pieceDestination->setObjectName( "pieceDestination" );
	pieceDestination->setGeometry( QRect( 250, 525, 41, 22 ) );
	this->_pieceDestination = pieceDestination;


	QLabel * labelStart = new QLabel( this->getCentralWidget() );
	labelStart->setObjectName( "labelStart" );
	labelStart->setGeometry( QRect( 100, 525, 41, 16 ) );
	labelStart->setText( QString::fromUtf8( "Départ" ) );

	QLabel * labelEnd = new QLabel( this->getCentralWidget() );
	labelEnd->setObjectName( "labelEnd" );
	labelEnd->setGeometry( QRect( 200, 525, 51, 16 ) );
	labelEnd->setText( QString::fromUtf8( "Arrivée" ) );

	QPushButton * buttonMove = new QPushButton( this->getCentralWidget() );
	buttonMove->setObjectName( "boutonMove" );
	buttonMove->setGeometry( QRect( 300, 520, 114, 32 ) );
	buttonMove->setText( QString::fromUtf8( "Déplacer" ) );

	QObject::connect( buttonMove, SIGNAL( clicked() ), this, SLOT( clicked_buttonMove() ) );
}

void Echiquier::clicked_buttonNew() {
	this->getPions();

//	cout << "clicked_buttonNew";
	//this->create();

	/*
	QString pseudo1 = QInputDialog::getText( this, "Joueur 1", "Nom du joueur 1 :" );
	QString pseudo2 = QInputDialog::getText( this, "Joueur 2", "Nom du joueur 2 :" );

	if ( pseudo1 != "" && pseudo2 != "" ) {
		// si les pseudos on bien été rempli alors on active le bouton save
//		ui->boutonSave->setEnabled( true );

		// on initialise toutes les pieces sur léchiquier
		//this->_Echiquier->create( ui );
		this->create();
	}
	else {
		// si les pseudos sont pas rempli on désactive le bouton save
//		ui->boutonSave->setEnabled( false );
	}

	//QMessageBox::information( this, "sdg", "dsjgse" );

	*/
}

void Echiquier::clicked_buttonMove() {
	QMap<QString, int> abscisse;

	abscisse.insert("A", 1);
	abscisse.insert("B", 2);
	abscisse.insert("C", 3);
	abscisse.insert("D", 4);
	abscisse.insert("E", 5);
	abscisse.insert("F", 6);
	abscisse.insert("G", 7);
	abscisse.insert("H", 8);
	abscisse.insert("a", 1);
	abscisse.insert("b", 2);
	abscisse.insert("c", 3);
	abscisse.insert("d", 4);
	abscisse.insert("e", 5);
	abscisse.insert("f", 6);
	abscisse.insert("g", 7);
	abscisse.insert("h", 8);

	QString origine = this->_pieceOrigine->text();
	QString origine1 = origine.left(1);
	QString origine2 = origine.right(1);

	QString destination = this->_pieceDestination->text();
	QString destination1 = destination.left(1);
	QString destination2 = destination.right(1);

	//QMessageBox::information(this, "sdg", "origine: "+origine1+"-"+origine2+" destination: "+destination1+"-"+destination2);

	QRegExp isLetter("(A|B|C|D|E|F|G|H|a|b|c|d|e|f|g|h)");
	QRegExp isNumber("(1|2|3|4|5|6|7|8)");

	int xd, yd, xf, yf;

	if ( origine.count() == 2 && origine.contains( isLetter ) && origine.contains( isNumber ) ) {
		if ( origine1.contains( isLetter ) ) {
			xd = abscisse.value( origine1 );
			yd = origine2.toInt();
		}
		else if ( origine1.contains( isNumber ) ) {
			xd = abscisse.value( origine2 );
			yd = origine1.toInt();
		}
	}
	else {
		QMessageBox::information(this, "debug", "Les coordonnÈes de dÈpart ne sont pas valide");
	}

	if ( destination.count() == 2 && destination.contains( isLetter ) && destination.contains( isNumber ) ) {
		if ( destination1.contains( isLetter ) ) {
			xf = abscisse.value( destination1 );
			yf = destination2.toInt();
		}
		else if ( destination1.contains( isNumber ) ) {
			xf = abscisse.value( destination2 );
			yf = destination1.toInt();
		}
	}
	else {
		QMessageBox::information(this, "debug", "Les coordonnÈes d'arrivÈ ne sont pas valide");
	}

	// on déplace la piece
	this->deplacerPiece( xd, yd, xf, yf );
}
