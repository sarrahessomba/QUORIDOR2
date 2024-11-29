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
int afficherScores(const char * nomdufichier);
int mettre_a_jour_score(joueur tab_joueur[],int N,const char* nomFichier);
int sauvegardescore(joueur tab_joueur[],int N,const char * nomFichier);
#endif //SCORE_H
