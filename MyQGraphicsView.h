#if !defined MYQGRAPHICSVIEW_H
	#define MYQGRAPHICSVIEW_H

	#include <QMouseEvent>
	#include <QMessageBox>
	#include <QGraphicsView>

	#include "Echiquier.h"

	class MyQGraphicsView : public QGraphicsView {
		private:
			Echiquier * _echiquier;
			int __x;
			int __y;

		public:
			MyQGraphicsView( QWidget * parent = 0 );
			void mousePressEvent( QMouseEvent * event );
			void setEchiquier( Echiquier * lEchiquier );

			void x( int _x );
			void y( int _y );

			int x();
			int y();
	};

#endif // MYQGRAPHICSVIEW_H
