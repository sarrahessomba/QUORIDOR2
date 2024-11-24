//
// Created by sarra on 26/10/2024.
//

#ifndef PLATEAU_H
#include "fonction.joueur.h"
#define PLATEAU_H
void init_tab(int tab[17][17],int N,joueur joueur1,joueur joueur2,  joueur joueur3,joueur joueur4);
void affichage_plateau(int tab[17][17]);
sauvegarderPartie(int plateau[17][17],int player_turn,joueur joueurs[],int nbJoueurs, const char *nomFichier);
chargerPartie(int plateau[17][17],int * player_turn ,joueur joueurs[], int *nbJoueurs, const char *nomFichier);
#endif //PLATEAU_H
