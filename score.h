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
void mettreAJourScore(joueur joueurs[], int nbJoueurs,const char *nomdufichier);
void afficherScores(const char * nomdufichier,joueur * joueur);
#endif //SCORE_H
