#include <QtGui/QApplication>
#include "mainwindow.h"
#include "Echiquier.h"

int main( int argc, char * argv[] ) {
	QApplication a( argc, argv );

	MainWindow w;

	w.setEnabled(true);
	w.resize( 500, 620);

	w.show();

	return a.exec();
}
