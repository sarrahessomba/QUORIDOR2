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
                    while(direct!=3 && direct!=4) {
                        printf("Entrer 3 ou 4\n");
                        scanf("%d",&direct);
                    }
                    if(direct==3) {
                        y=y-2;
                    }else {
                        y=y+2;
                    }
                }else
                if(adv_x==0 || adv_x==16) {//bordures x
                    if(adv_y==0) {//coin
                        y= y+2;
                    }else if (adv_y==16) {//coin
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
                }else if(tab[adv_x-1][adv_y]!=7 || tab[adv_x+1][adv_y]!=7) {
                    if(direction==1) {
                        x= x-2;
                    }else {
                        x= x-2;
                    }
                }
            }else if(direction==3 || direction==4) {
                if((tab[adv_x][adv_y-1]==7 && direction==3) || ((tab[adv_x][adv_y+1]==7) && direction==4)) {
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
                    if(adv_x==0) { //coin
                        x= x+2;
                    }else if(adv_x==16) {//coin
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
                }else if((tab[adv_x][adv_y+1]!=7) && tab[adv_x][adv_y-1]!=7) {
                    if(direction==3) {
                        y= y-2;
                    }else {
                        y= y+2;
                    }
                }else if(tab[adv_x-1][adv_y]!=7 || tab[adv_x+1][adv_y]!=7) {
                    if(direction==1) {
                        x= x-2;
                    }else {
                        x= x-2;
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
                        x= x-2;
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
                }else if((tab[x][y+1]!=7) && tab[x][y-1]!=7) {
                    if(direction==3) {
                        y= y-2;
                    }else {
                        y= y+2;
                    }
                }else if(tab[x-1][y]!=7 || tab[x+1][y]!=7) {
                    if(direction==1) {
                        x= x-2;
                    }else {
                        x= x-2;
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
    joueur_actif.nb_barr-=1;
    return joueur_actif.nb_barr;
};
/*int menu () {
    int choixx;
    do {
        printf("1. Deplacer son pion\n");
        printf("2. Placer une barriere\n");
        printf("3. Passer son tour\n");
        scanf("%d", &choixx);
    }while(choixx != 1 && choixx != 2 && choixx != 3);
    return choixx;
}
/*void deplacer (int i,int x, int y,int tableau[17][17],int N) {
    tableau[x][y] = i;
    if(N==4) {
        int av_x[4] = {0,8,16,8};
        int av_y[4] = {8,0,8,16};
        tableau[av_x[i-1]][av_y[i-1]] =0;
        av_x[i-1] =x;
        av_y[i-1]=y;
        esthetique();
        for(int j=0;j<17;j++) {
            esthetique2(j);
            for(int k=0;k<17;k++) {
                printf("%d ", tableau[j][k]);
            }
            printf("\n");
        }
    }else {
        int av_x[2] = {0,16};
        int av_y[2] = {8,8};
        tableau[av_x[i-1]][av_y[i-1]] =0;
        av_x[i-1] =x;
        av_y[i-1]=y;
        esthetique();
        for(int j=0;j<17;j++) {
            esthetique2(j);
            for(int k=0;k<17;k++) {
                printf("%d ", tableau[j][k]);
            }
            printf("\n");
        }
    }
}
void menu_deplacer(int direction,int tab[17][17]) {

}
/*
 int choix;
printf("1. Haut\n");
printf("2. Bas\n");
printf("3. Gauche\n");
printf("4. Droite\n");
scanf("%d", &choix);*/