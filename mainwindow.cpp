#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
	Echiquier *lEchiquier;
	this->_Echiquier = lEchiquier;

	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_boutonNew_clicked()
{
	QString pseudo1 = QInputDialog::getText( this, "Joueur 1", "Nom du joueur 1 :" );
	QString pseudo2 = QInputDialog::getText( this, "Joueur 2", "Nom du joueur 2 :" );

	if ( pseudo1 != "" && pseudo2 != "" ) {
		// si les pseudos on bien été rempli alors on active le bouton save
		ui->boutonSave->setEnabled(true);

		// on initialise toutes les pieces sur léchiquier
		this->_Echiquier->create( ui );
	}
	else {
		// si les pseudos sont pas rempli on désactive le bouton save
		ui->boutonSave->setEnabled(false);
	}

	//QMessageBox::information(this, "sdg", "dsjgse");
}


void MainWindow::on_boutonReload_clicked()
{
	QString pseudo1 = QInputDialog::getText( this, "Joueur 1", "Nom du joueur 1 :" );
	QString pseudo2 = QInputDialog::getText( this, "Joueur 2", "Nom du joueur 2 :" );

	//QMessageBox::information(this, "sdg", "dsjgse");
}

void MainWindow::on_boutonMove_clicked()
{
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

	QString origine = ui->pieceOrigine->text();
	QString origine1 = origine.left(1);
	QString origine2 = origine.right(1);

	QString destination = ui->pieceDestination->text();
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
		QMessageBox::information(this, "debug", "Les coordonnées de départ ne sont pas valide");
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
		QMessageBox::information(this, "debug", "Les coordonnées d'arrivé ne sont pas valide");
	}

	// on déplace la piece
	this->_Echiquier->deplacerPiece( xd, yd, xf, yf );
}
