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

FORMS    += mainwindow.ui

OTHER_FILES += \
	Pion/TourN.png \
	Pion/TourB.png \
	Pion/RoiN.png \
	Pion/RoiB.png \
	Pion/ReineN.png \
	Pion/ReineB.png \
	Pion/PionN.png \
	Pion/PionB.png \
	Pion/FouN.png \
	Pion/FouB.png \
	Pion/Chess_symbols.PNG \
	Pion/CavalierN.png \
	Pion/CavalierB.png \
    README.txt

RESOURCES +=
