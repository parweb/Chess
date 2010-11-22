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

	class MainWindow : public QMainWindow {
		Q_OBJECT

		public:
			explicit MainWindow(QWidget *parent = 0);
			~MainWindow();

		private:
			Ui::MainWindow *ui;

		protected:
			Echiquier* _Echiquier;

		private slots:
			void on_boutonMove_clicked();
			void on_boutonReload_clicked();
			void on_boutonNew_clicked();
	};
#endif // MAINWINDOW_H
