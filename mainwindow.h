#ifndef MAINWINDOW_H
	#define MAINWINDOW_H

	#include <QMainWindow>
	#include <QMessageBox>
	#include <QInputDialog>
	#include <QMap>
	#include <iostream>

	#include "Echiquier.h"
	#include "ui_mainwindow.h"

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

		private slots:
			void on_boutonMove_clicked();
			void on_boutonReload_clicked();
			void on_boutonNew_clicked();
	};
#endif // MAINWINDOW_H
