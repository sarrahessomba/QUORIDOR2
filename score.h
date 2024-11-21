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
void chargerScores(FILE *fichier, joueur joueurs[], int *nbJoueurs);
void Afficher_Scores(FILE *fichier, joueur joueurs[], int nbJoueurs);
int trouverJoueur(joueur joueurs[], int nbJoueurs, const char *nom);
void mettreAJourScore(joueur joueurs[], int *nbJoueurs, const char *nom, int points);

#endif //SCORE_H
