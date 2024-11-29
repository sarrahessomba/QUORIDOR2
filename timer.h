//
// Created by sarra on 21/11/2024.
//
#ifndef TIMER_H
#define TIMER_H

#include <time.h>

// Structure pour le chronomètre d'un joueur
typedef struct Chronometre {
    time_t debut_tour; // Temps de début du tour
    int temps_restant; // Temps restant en secondes
} Chronometre;

// Prototypes des fonctions
void initialiser_chronometre(Chronometre* chrono, int temps_total);
void demarrer_chronometre(Chronometre* chrono);
int obtenir_temps_restant(Chronometre* chrono);
int temps_ecoule(Chronometre* chrono);

#endif
