#ifndef TIMER_H
#define TIMER_H

#include <time.h>

// Structure pour stocker les informations de chaque joueur
typedef struct {
    double tempsTotal; // Temps total accumulé pour chaque joueur par partie
    int points;        // Points du joueur pour calculer les malus à la fin de la partie
} Joueur;

// Prototypes des fonctions
void jouerTour(Joueur *joueur);
int JoueurLePlusLongTemps(Joueur joueurs[], int nombreJoueurs);

#endif // TIMER_H
