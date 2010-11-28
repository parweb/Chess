#ifndef MAINWINDOW_H
	#define MAINWINDOW_H

	#include <QMainWindow>
	#include <QMessageBox>
	#include <QInputDialog>
	#include <QMap>
	#include <iostream>

	#include "Echiquier.h"

	namespace Ui {
		class MainWindow;
	}

	class Echiquier;

	class MainWindow : public QMainWindow {
		Q_OBJECT

		public:
			explicit MainWindow(QWidget * parent = 0);
			~MainWindow();

		private:
			Ui::MainWindow * ui;
			Echiquier * _Echiquier;
			QWidget * centralWidget;
	};
#endif // MAINWINDOW_H

#ifndef MYGRID_H
	#define MYGRID_H

	class MyGrid : public QGridLayout {
		//Q_OBJECT

		public:
			MyGrid(QWidget * parent = 0);
		private:

	};
#endif // MYGRID_H
