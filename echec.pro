#-------------------------------------------------
#
# Project created by QtCreator 2010-10-27T17:39:01
#
#-------------------------------------------------

QT       += core gui

TARGET = echec
TEMPLATE = app


SOURCES += main.cpp\
		mainwindow.cpp \
	Piece.cxx \
	Joueur.cxx \
	Echiquier.cxx

HEADERS  += mainwindow.h \
	Piece.h \
	Joueur.h \
	Echiquier.h

OTHER_FILES += \
	README.txt

RESOURCES += \
	pions.qrc
