
#ifndef FONCTION_JOUEUR_H
#define FONCTION_JOUEUR_H
typedef struct position {
    int x;
    int y;
}position;
typedef struct joueur {
    char nom[50];
    int nb_barr;
    position position;
    int pion;
}joueur;
joueur deplacer(int direction,joueur joueur_actif,joueur adversaire,joueur adversaire2,joueur adversaire3,joueur adversaire4,int tab[17][17],int N);
int valid_deplacer(int direction,joueur joueur_actif,int tab[17][17]);
int a_gagner(joueur joueur1,joueur joueur2,joueur joueur3,joueur joueur4,int N);
int placer_barriere(int x,int y,int direction_bar,int tab[17][17],joueur joueur_actif);
int valid_barriere(int x,int y,int direction_bar,joueur joueur_actif,int tab[17][17]);
#endif //FONCTION_JOUEUR_H
