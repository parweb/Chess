#include "Echiquier.h"

using namespace std;

Echiquier::Echiquier( ) {
	for ( int i = 0; i < 64; ++i ) {
		m_cases[ i ] = NULL;
	}
}

Echiquier::Echiquier( QWidget * parent ) : QWidget( parent ) {
	this->centralWidget = parent;
	this->setObjectName( "echiquier" );

	this->getButtonNew();
	this->getLegendX();
	this->getLegendY();

	this->_damier = this->getDamier();

	this->getPions();
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
		( p->x( ) >= 1 ) && ( p->x( ) <= 8 )
		&& ( p->y( ) >= 1 ) && ( p->y( ) <= 8 )
		&& ( p != NULL )
	) {
		int i = getCase( p->x( ), p->y( ) );
		this->setPiece( i, p );

		p->moveTo( p->x( ), p->y( ) );

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
		this->enleverPiece( p->x( ), p->y( ) );
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
		( p->x( ) >= 1 ) && ( p->x( ) <= 8 ) &&
		( p->y( ) >= 1 ) && ( p->y( ) <= 8 )
	) {
		return this->enleverPiece( p->x( ), p->y( ) );
	}

	return false;
}

int Echiquier::getCase( int x, int y ) {
	return ( x - 1 + ( y - 1 ) * 8 );
}

int Echiquier::getCase( Piece * p ) {
	return getCase( p->x( ), p->y( ) );
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

		xf = xi + ( exi * ( coord->x( ) - 1 ) );
		yf = yi + ( eyi * ( coord->y( ) - 1 ) );

		QGraphicsView * place = new QGraphicsView( conteneur );

		place->setObjectName( "CASE_"+QString::number( i+1 ) );
		place->setGeometry( QRect( xf, yf, exi, eyi ) );
		place->setAutoFillBackground( false );

		if ( ( coord->x( ) + coord->y( ) ) % 2 ) {
			place->setStyleSheet( QString::fromUtf8( "background:rgb( 100, 100, 100 );") );
		}
	}

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
		label->setFont( this->getLegendFont( ) );
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
		label->setFont( this->getLegendFont( ) );
		label->setAlignment( Qt::AlignCenter );
	}
}

void Echiquier::getPions () {
	QGridLayout * pions = new QGridLayout( this->getCentralWidget() );

	for ( int i = 0; i < 8; i++ ) {
		pions->setRowMinimumHeight( i, 50 );
		pions->setColumnMinimumWidth( i, 50 );
	}

	pions->setMargin( 0 );
	pions->setContentsMargins(0, 0, 0, 0);

	pions->layout()->setMargin(0);
	pions->layout()->setContentsMargins(0, 0, 0, 0);

	pions->setHorizontalSpacing(0);
	pions->setVerticalSpacing(0);
	pions->layout()->setSizeConstraint( pions->layout()->SetFixedSize );

	this->_pions = pions;
}

QFont Echiquier::getLegendFont ( ) {
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

void Echiquier::clicked_buttonNew( ) {
	cout << "clicked_buttonNew";
	//this->create();

	/*
	QString pseudo1 = QInputDialog::getText( this, "Joueur 1", "Nom du joueur 1 :" );
	QString pseudo2 = QInputDialog::getText( this, "Joueur 2", "Nom du joueur 2 :" );

	if ( pseudo1 != "" && pseudo2 != "" ) {
		// si les pseudos on bien été rempli alors on active le bouton save
//		ui->boutonSave->setEnabled( true );

		// on initialise toutes les pieces sur léchiquier
		//this->_Echiquier->create( ui );
		this->create( );
	}
	else {
		// si les pseudos sont pas rempli on désactive le bouton save
//		ui->boutonSave->setEnabled( false );
	}

	//QMessageBox::information( this, "sdg", "dsjgse" );

	*/
}
