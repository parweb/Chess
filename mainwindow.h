#ifndef MAINWINDOW_H
	#define MAINWINDOW_H

	#include <QMainWindow>
	#include <QMessageBox>
	#include <QInputDialog>
	#include <QMap>
	#include <iostream>

	#include "Echiquier.h"

	class Echiquier;

	class MainWindow : public QMainWindow {
		Q_OBJECT

		public:
			explicit MainWindow(QWidget * parent = 0);
			~MainWindow();

		private:
			Echiquier * _Echiquier;
			QWidget * centralWidget;
	};
#endif // MAINWINDOW_H
