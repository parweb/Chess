/** 
 * Programme test de Piece
 *
 * @file testPiece.cxx
 */

/*
// Utile pour l'affichage
#include <iostream>
#include "Piece.h"
#include "Joueur.h"
#include "Echiquier.h"

// Pour utiliser les flux de iostream sans mettre "std::" tout le temps.
using namespace std;

int main( int argc, char** argv )
{
	Echiquier Echiquier;

	JoueurBlanc JoueurBlanc;
	JoueurNoir  JoueurNoir;

	JoueurBlanc.placerPieces(Echiquier);
	JoueurNoir.placerPieces(Echiquier);

	// -------------------------------- Roi

	Roi RoiBlanc(true);
	Echiquier.enleverPiece(5,1);
	Echiquier.placer(&RoiBlanc);

	Roi RoiNoir(false);
	Echiquier.enleverPiece(5,8);
	Echiquier.placer(&RoiNoir);

	// -------------------------------- Reine

	Reine ReineBlanc(true);
	Echiquier.enleverPiece(4,1);
	Echiquier.placer(&ReineBlanc);

	Reine ReineNoir(false);
	Echiquier.enleverPiece(4,8);
	Echiquier.placer(&ReineNoir);

	// -------------------------------- Tour

	Tour TourBlancUn(true, 1);
	Echiquier.enleverPiece(1,1);
	Echiquier.placer(&TourBlancUn);

	Tour TourBlancDeux(true, 8);
	Echiquier.enleverPiece(8,1);
	Echiquier.placer(&TourBlancDeux);

	Tour TourNoirUn(false, 1);
	Echiquier.enleverPiece(1,8);
	Echiquier.placer(&TourNoirUn);

	Tour TourNoirDeux(false, 8);
	Echiquier.enleverPiece(8,8);
	Echiquier.placer(&TourNoirDeux);

	// -------------------------------- Cavalier

	Cavalier CavalierBlancUn(true, 2);
	Echiquier.enleverPiece(2,1);
	Echiquier.placer(&TourBlancUn);

	Cavalier CavalierBlancDeux(true, 7);
	Echiquier.enleverPiece(7,1);
	Echiquier.placer(&CavalierBlancDeux);

	Cavalier CavalierNoirUn(false, 2);
	Echiquier.enleverPiece(2,8);
	Echiquier.placer(&CavalierNoirUn);

	Cavalier CavalierNoirDeux(false, 7);
	Echiquier.enleverPiece(7,8);
	Echiquier.placer(&CavalierNoirDeux);

	// -------------------------------- Fou

	Fou FouBlancUn(true, 3);
	Echiquier.enleverPiece(3,1);
	Echiquier.placer(&FouBlancUn);

	Fou FouBlancDeux(true, 6);
	Echiquier.enleverPiece(6,1);
	Echiquier.placer(&FouBlancDeux);

	Fou FouNoirUn(false, 3);
	Echiquier.enleverPiece(3,8);
	Echiquier.placer(&FouNoirUn);

	Fou FouNoirDeux(false, 6);
	Echiquier.enleverPiece(6,8);
	Echiquier.placer(&FouNoirDeux);

	// -------------------------------- Pion

	Pion PionBlancUn(true, 1);
	Echiquier.enleverPiece(1,2);
	Echiquier.placer(&PionBlancUn);

	Pion PionBlancDeux(true, 2);
	Echiquier.enleverPiece(2,2);
	Echiquier.placer(&PionBlancDeux);

	Pion PionBlancTrois(true, 3);
	Echiquier.enleverPiece(3,2);
	Echiquier.placer(&PionBlancTrois);

	Pion PionBlancQuatre(true, 4);
	Echiquier.enleverPiece(4,2);
	Echiquier.placer(&PionBlancQuatre);

	Pion PionBlancCinq(true, 5);
	Echiquier.enleverPiece(5,2);
	Echiquier.placer(&PionBlancCinq);

	Pion PionBlancSix(true, 6);
	Echiquier.enleverPiece(6,2);
	Echiquier.placer(&PionBlancSix);

	Pion PionBlancSept(true, 7);
	Echiquier.enleverPiece(7,2);
	Echiquier.placer(&PionBlancSept);

	Pion PionBlancHuit(true, 8);
	Echiquier.enleverPiece(8,2);
	Echiquier.placer(&PionBlancHuit);

	Pion PionNoirUn(false, 1);
	Echiquier.enleverPiece(1,7);
	Echiquier.placer(&PionNoirUn);

	Pion PionNoirDeux(false, 2);
	Echiquier.enleverPiece(2,7);
	Echiquier.placer(&PionNoirDeux);

	Pion PionNoirTrois(false, 3);
	Echiquier.enleverPiece(3,7);
	Echiquier.placer(&PionNoirTrois);

	Pion PionNoirQuatre(false, 4);
	Echiquier.enleverPiece(4,7);
	Echiquier.placer(&PionNoirQuatre);

	Pion PionNoirCinq(false, 5);
	Echiquier.enleverPiece(5,7);
	Echiquier.placer(&PionNoirCinq);

	Pion PionNoirSix(false, 6);
	Echiquier.enleverPiece(6,7);
	Echiquier.placer(&PionNoirSix);

	Pion PionNoirSept(false, 7);
	Echiquier.enleverPiece(7,7);
	Echiquier.placer(&PionNoirSept);

	Pion PionNoirHuit(false, 8);
	Echiquier.enleverPiece(8,7);
	Echiquier.placer(&PionNoirHuit);

	Echiquier.affiche();
}
*/
