//
// Created by sarra on 30/10/2024.
//
#include <stdio.h>
void esthetique() {
    printf("X/Y ");
    for(int k=0; k<=9; k++) {
        printf("%d ", k);
    }
    for(int k=65; k<=71; k++) {
        printf("%c ", k);
    }
    printf("\n");
    printf("  ");
    for(int k=0; k<17; k++) {
        printf("--");
    }
    printf("\n");
}
void esthetique2(int i) {
    if(i>=0 && i<=9) {
        printf("%d | ", i);
    }else if(i>=9 && i<=17) {
        printf("%c | ", (55+i));
    }
}
#include <stdio.h>
void afficherAide() {
    // affiche les règles du jeu
    printf("Regles du jeu :\n");
    printf("- Chaque joueur doit atteindre le bord oppose du plateau pour gagner.\n");
    printf("- A chaque tour, un joueur peut deplacer son pion ou placer une barriere ou meme passer son tour.\n");
    printf("- Les barrieres peuvent etre placees pour bloquer l'adversaire, mais elles ne doivent pas definitivement bloquer l'acces au cote oppose.\n");
    printf("- Un pion peut sauter au-dessus un autre pion (adjacent) si aucune barriere ne le bloque.\n");
    printf("- Le jeu se termine lorsqu'un joueur atteint le bord oppose de sa ligne de départ.\n");
    printf("- A=10,B=11,C=12,D=13,E=14,F=15,G=16\n");
    printf("-Entrer les X avant les Y\n");
    printf("6=case sans demi-barriere, 7=case avec demi-barriere, 0-case de pion vide\n");

}
