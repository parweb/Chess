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

		private slots:
			void on_boutonMove_clicked();
			void on_boutonReload_clicked();
			void on_buttonNew_clicked();
	};
#endif // MAINWINDOW_H
