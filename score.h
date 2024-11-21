#ifndef SCORES_H
#define SCORES_H

#include <stdio.h>
#include <string.h>

// Structure pour représenter un joueur
typedef struct {
    char nom[50];
    int score;
} Joueur;

// Prototypes des fonctions
void chargerScores(FILE *fichier, Joueur joueurs[], int *nbJoueurs);
void sauvegarderScores(FILE *fichier, Joueur joueurs[], int nbJoueurs);
int trouverJoueur(Joueur joueurs[], int nbJoueurs, const char *nom);
void mettreAJourScore(Joueur joueurs[], int *nbJoueurs, const char *nom, int points);

#endif // SCORES_H

