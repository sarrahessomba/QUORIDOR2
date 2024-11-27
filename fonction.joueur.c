//
// Created by sarra on 29/10/2024.
//
#include <stdio.h>
#include "fonction.joueur.h"
//Proposition des fonctionnalités de chaque joueur
void new_cord(int direction,joueur joueur_actif,int * new_x,int * new_y) {
    switch (direction) {
        case 1:
            *new_x = joueur_actif.position.x-2;
            *new_y = joueur_actif.position.y;
        break;
        case 2:
            *new_x = joueur_actif.position.x+2;
            *new_y = joueur_actif.position.y;
        break;
        case 3:
            *new_x = joueur_actif.position.x;
            *new_y = joueur_actif.position.y-2;
        break;
        case 4:
            *new_x = joueur_actif.position.x;
            *new_y = joueur_actif.position.y+2;
    }
};
int valid_deplacer(int direction,joueur joueur_actif,int tab[17][17]) {
    int new_x,new_y;
    new_cord(direction,joueur_actif,&new_x,&new_y);
    if((new_x<0 || new_x>16  || new_y<0 || new_y>16)||(direction==2 && tab[new_x-1][new_y]==7) ||(direction==1 && tab[new_x+1][new_y]==7) ||(direction==4 && tab[new_x][new_y-1]==7) || (direction==3 && tab[new_x][new_y+1]==7)) {//depasse le plateau
        return 0;
    }
    return 1;
};
joueur deplacer(int direction,joueur joueur_actif,joueur adversaire,joueur adversaire2,joueur adversaire3,joueur adversaire4,int tab[17][17],int N) {
   //
    if(N==2) {
        int x= joueur_actif.position.x,y= joueur_actif.position.y;
        int adv_x= adversaire.position.x, adv_y= adversaire.position.y;
        new_cord(direction,joueur_actif,&x,&y);//calcule les nouvelles cord
        if(x==adv_x && y==adv_y) {
            if(direction==1 || direction==2) {//Haut ou bas
                int direct;
                if(((tab[adv_x-1][adv_y]==7)&& direction==1)|| ((tab[adv_x+1][adv_y]==7) && direction==2)) {//barriere derriere le joueur adverse
                    printf("3.Gauche ou 4.Droite\n");
                    scanf("%d",&direct);
                    while(direct!=3 && direct!=4) {//blindage
                        printf("Entrer 3 ou 4\n");
                        scanf("%d",&direct);
                    }
                    if(direct==3) {//
                        y=y-2;
                    }else {
                        y=y+2;
                    }
                }else
                if(adv_x==0 || adv_x==16) {//bordures x
                    if(adv_y==0) {//coin 0 0
                        y= y+2;
                    }else if (adv_y==16) {//coin 0 16
                        y= y-2;
                    }else {
                        int choix;
                        printf("3.Gauche ou 4.Droite\n");
                        scanf("%d",&choix);
                        while(choix!=4 && choix!=3) {
                            printf("Choix invalide\n");
                            scanf("%d",&choix);
                        }
                        if(choix==3) {
                            y= y-2;
                        }else {
                            y= y+2;
                        }
                    }
                }else if(tab[adv_x-1][adv_y]!=7 || tab[adv_x+1][adv_y]!=7) {//pas de barriere
                    if(direction==1) {// deplace de  2 cases en  haut
                        x= x-2;
                    }else { // deplace de 2 cases en bas
                        x= x+2;
                    }
                }
            }else if(direction==3 || direction==4) {//gauche ou droite
                if((tab[adv_x][adv_y-1]==7 && direction==3) || ((tab[adv_x][adv_y+1]==7) && direction==4)) {//barrière derriere la case
                    int direct;
                        printf("1.Haut ou 2.Bas\n");
                        scanf("%d",&direct);
                        while(direct!=1 && direct!=2) {
                            printf("Entrer 1 ou 2\n");
                            scanf("%d",&direct);
                        }
                        if(direct==1) {
                            x= x-2;
                        }else {
                            x= x+2;
                        }
                }else
                if(adv_y==0 || adv_y==16) {//bordures y
                    if(adv_x==0) { //coin 0 0
                        x= x+2;
                    }else if(adv_x==16) {//coin 16 0
                        x= x-2;
                    }else {
                        int choix;
                        printf("1.Haut ou 2.Bas\n");
                        scanf("%d",&choix);
                        while(choix!=1 && choix!=2) {
                            printf("Choix invalide\n");
                            scanf("%d",&choix);
                        }
                        if(choix==1) {
                            x= x-2;
                        }else {
                            x= x+2;
                        }
                    }
                }else if((tab[adv_x][adv_y+1]!=7) || tab[adv_x][adv_y-1]!=7) {
                    if(direction==3) {
                        y= y-2;
                    }else {
                        y= y+2;
                    }
                }
            }
        }
        tab[joueur_actif.position.x][joueur_actif.position.y]=0;
        joueur_actif.position.x=x;
        joueur_actif.position.y=y;
        tab[joueur_actif.position.x][joueur_actif.position.y]=joueur_actif.pion;
        return joueur_actif;
    }else {
        int adv_x1=adversaire.position.x ,adv_y1=adversaire.position.y,adv_x2=adversaire2.position.x,adv_y2=adversaire2.position.y,adv_x3=adversaire3.position.x,adv_y3=adversaire3.position.y,adv_x4=adversaire4.position.x,adv_y4=adversaire4.position.y;
        int x=joueur_actif.position.x,y=joueur_actif.position.y;
        new_cord(direction,joueur_actif,&x,&y);
        if((x==adv_x1 && y==adv_y1)||(x==adv_x2 && y==adv_y2)||(x==adv_x3 && y==adv_y3) ||(x==adv_x4 && y==adv_y4)) {
            if(direction==1 || direction==2) {
                int direct;
                if(((tab[x-1][y]==7&& direction==1)||(tab[x+1][y]==7 && direction==2))){//barriere derriere un joueur
                    printf("3.Gauche ou 4.Droite\n");
                    scanf("%d",&direct);
                    while(direct!=3 && direct!=4) {
                        printf("Entrer 3 ou 4\n");
                        scanf("%d",&direct);
                    }
                    if(direct==3) {
                        y=y-2;
                    }else {
                        y=y+2;
                    }
                }else if((x==0 || x==16)) {//bordures x
                    if(y==0) {//coin
                        y= y+2;
                    }else if (y==16) { //coin
                        y= y-2;
                    }else {
                        int choix;
                        printf("3.Gauche ou 4.Droite\n");
                        scanf("%d",&choix);
                        while(choix!=4 && choix!=3) {
                            printf("Choix invalide\n");
                            scanf("%d",&choix);
                        }
                        if(choix==3) {
                            y= y-2;
                        }else {
                            y= y+2;
                        }
                    }
                }else if(tab[x-1][y]!=7 || tab[x+1][y]!=7) {//pas de barriere en haut ou en bas du pion de l adv
                    if(direction==1) {
                        x= x-2;
                    }else {
                        x= x+2;
                    }
                }
            }else if(direction==3 || direction==4) {
                int direct;
                if(((tab[x][y-1]==7 && direction==3)||(tab[x][y+1]==7 && direction==4))) {
                    printf("1.Haut ou 2.Bas\n");
                    scanf("%d",&direct);
                    while(direct!=1 && direct!=2) {
                        printf("Entrer 1 ou 2\n");
                        scanf("%d",&direct);
                    }
                    if(direct==1) {
                        x=x-2;
                    }else {
                        x=x+2;
                    }
                }else if(y==0 || y==16) {
                    if(x==0) {
                        x= x+2;
                    }else if(x==16) {
                        x= x-2;
                    }else {
                        int choix;
                        printf("1.Haut ou 2.Bas\n");
                        scanf("%d",&choix);
                        while(choix!=1 && choix!=2) {
                            printf("Choix invalide\n");
                            scanf("%d",&choix);
                        }
                        if(choix==1) {
                            x= x-2;
                        }else {
                            x= x+2;
                        }
                    }
                }else if((tab[x][y+1]!=7) || tab[x][y-1]!=7) {
                    if(direction==3) {
                        y= y-2;
                    }else {
                        y= y+2;
                    }
                }
            }
        }
        tab[joueur_actif.position.x][joueur_actif.position.y]=0;
        joueur_actif.position.x=x;
        joueur_actif.position.y=y;
        tab[joueur_actif.position.x][joueur_actif.position.y]=joueur_actif.pion;
        return joueur_actif;
    }
};
int a_gagner(joueur joueur1,joueur joueur2,joueur joueur3,joueur joueur4,int N) {
    if(N==2) {
        if(joueur1.position.x==16) {
            return 1;
        }
        if(joueur2.position.x==0) {
            return 2;
        }if(joueur1.nb_barr==0 && joueur2.nb_barr==0) {
            return -1;
        }
        return 0;
    }else {
        if(joueur1.position.x==16) {
            return 1;
        }
        if(joueur2.position.y==16) {
            return 2;
        }
        if(joueur3.position.x==0) {
            return 3;
        }
        if(joueur4.position.y==0) {
            return 4;
        }
        if(joueur1.nb_barr==0 && joueur2.nb_barr==0 && joueur3.nb_barr==0 && joueur4.nb_barr==0) {
            return -1;
        }
        return 0;
    }
};
int valid_barriere(int x,int y,int direction_bar,joueur joueur_actif,int tab[17][17]) {
    if(x<0 || x>16 || y<0 || y>16 || tab[x][y]!=6 || (direction_bar==1 && tab[x-1][y]!=6) || (direction_bar==2 && tab[x+1][y]!=6) || (direction_bar==3 && tab[x][y-1]!=6) || (direction_bar==4 && tab[x][y+1]!=6)) {
        return 0;
    }
    if(joueur_actif.nb_barr==0) {
        printf("Vous n'avez plus de barrieres\n");
        return 0;
    }
    return 1;
}
int placer_barriere(int x,int y,int direction_bar,int tab[17][17],joueur joueur_actif) {
    tab[x][y]=7;
    if(direction_bar==1) {
        tab[x-1][y]=7;
    }else if(direction_bar==2) {
        tab[x+1][y]=7;
    }else if(direction_bar==3) {
        tab[x][y-1]=7;
    }else {
        tab[x][y+1]=7;
    }
    joueur_actif.nb_barr=joueur_actif.nb_barr-1;
    return joueur_actif.nb_barr;
};
void reprendre_partie(int plateau[17][17], int *N) {
    FILE *file = fopen("sauvegarde_partie.txt", "r");
    if (file == NULL) {
        printf("Aucune partie sauvegardee trouvee.\n");
        return;
    }


    // nombre de joueurs
    fscanf(file, "%d", N);

    // Chargement du plateau
    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 17; j++) {
            fscanf(file, "%d", &plateau[i][j]);
        }
    }

    fclose(file);
    printf("Partie chargee! Vous pouvez continuer celle-ci.\n");
}
int Annuler_coup(int player_turn,int choix_menu,int x,int y,int direction,joueur * joueur_actif,joueur joueur1,joueur joueur2,joueur joueur3,joueur joueur4,int plateau[17][17],int N) {
    int choix;
    printf("Souhaitez vous annuler votre coup\n");
    printf("1. OUI 2. NON\n");
    scanf("%d",&choix);
    while(choix!=1 && choix!=2) {
        printf("Erreur\n");
        scanf("%d",&choix);
    }
    if(N==2) {
        if(choix==1) {
            printf("joueur %d est d'accord?\n",(player_turn)%2 +1);
            printf("1. OUI 2. NON\n");
            scanf("%d",&choix);
            while(choix!=1 && choix!=2) {
                printf("Erreur\n");
                scanf("%d",&choix);
            }
            if(choix==1) {
                if(choix_menu==1){
                    plateau[(joueur_actif->position.x)][joueur_actif->position.y]=0;
                    if(player_turn==1) {
                        plateau[joueur1.position.x][joueur1.position.y]=joueur1.pion;
                        joueur_actif->position.x=joueur1.position.x;
                        joueur_actif->position.y=joueur1.position.y;
                    }else {
                        plateau[joueur2.position.x][joueur2.position.y]=joueur2.pion;
                        joueur_actif->position.x=joueur2.position.x;
                        joueur_actif->position.y=joueur2.position.y;
                    }
                }
            }else if(choix_menu==2) {
                plateau[x][y]=0;
                if(direction==1) {
                    plateau[x-1][y]=0;
                }else if(direction==2) {
                    plateau[x+1][y]=0;
                }else if(direction==3) {
                    plateau[x][y-1]=0;
                }else if(direction==4) {
                    plateau[x][y+1]=0;
                }
            }else {
                printf("rejouer\n");
            }
        }else {
            return 0;
        }
    }else {
        if(choix==1) {
            printf("joueur %d est d'accord?\n",(player_turn)%4 +1);
            printf("1. OUI 2. NON\n");
            scanf("%d",&choix);
            while(choix!=1 && choix!=2) {
                printf("Erreur\n");
                scanf("%d",&choix);
            }
            if(choix==1) {
                if(choix_menu==1) {
                    plateau[joueur_actif->position.x][joueur_actif->position.y]=0;
                    if(player_turn==1) {
                        plateau[joueur1.position.x][joueur1.position.y]=joueur1.pion;
                        joueur_actif->position.x=joueur1.position.x;
                        joueur_actif->position.y=joueur1.position.y;
                    }else if (player_turn==2) {
                        plateau[joueur2.position.x][joueur2.position.y]=joueur2.pion;
                        joueur_actif->position.x=joueur2.position.x;
                        joueur_actif->position.y=joueur2.position.y;
                    }else if(player_turn==3) {
                        plateau[joueur3.position.x][joueur3.position.y]=joueur3.pion;
                        joueur_actif->position.x=joueur3.position.x;
                        joueur_actif->position.y=joueur3.position.y;
                    }else {
                        plateau[joueur4.position.x][joueur4.position.y]=joueur4.pion;
                        joueur_actif->position.x=joueur4.position.x;
                        joueur_actif->position.y=joueur4.position.y;
                    }
                }else if (choix_menu==2) {
                    plateau[x][y]=0;
                    if(direction==1) {
                        plateau[x-1][y]=0;
                    }else if(direction==2) {
                        plateau[x+1][y]=0;
                    }else if(direction==3) {
                        plateau[x][y-1]=0;
                    }else {
                        plateau[x][y+1]=0;
                    }
                }else {
                    printf("rejouer\n");
                }
            }else {
                return 0;
            }
        }
    }
}