//
// Created by sarra on 21/11/2024.
//


#ifndef SCORES_H
#define SCORE_H

#include <stdio.h>
#include <string.h>
#include "fonction.joueur.h"
// Structure pour représenter un joueur

// Prototypes des fonctions
void mettreAJourScore(joueur joueurs[], int nbJoueurs,const char* nomfichier);
void afficherScores(joueur * joueur);
int Sauvegarder_Scores(joueur joueur[],int N,const char* nomfichier);
#endif //SCORE_H
