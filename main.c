#include <stdio.h>
#include "plateau.h"
#include "fonction.joueur.h"
#include "timer.h"
#include "score.h"
int main() {
    int choix,x,y,condition;
    int N,player_turn=1; int choixmenu,direction;
    int plateaujeu[17][17]={{0}};
    joueur joueur1;
    joueur joueur2;
    joueur joueur3;
    joueur joueur4;
    joueur joueur_actif;
    joueur adversaire;
    joueur adversaire1;
    joueur adversaire2;
    joueur adversaire3;
    FILE fichier;
    joueur tab_joueur[4]={joueur1,joueur2,joueur3,joueur4};
    do {
        printf("1. JOUER\n");
        printf("2. AFFICHER LES SCORES\n");
        printf("3. AIDE\n");
        printf("4.SORTIE\n");
        scanf("%d",&choix);
        switch(choix) {
            case 1: //Nombres de joueurs
                printf("Entrer le nombre de joueurs (2 ou 4) joueurs\n");
                scanf("%d",&N);
            while(N!=2 && N!=4) {
                printf("Entrer 2 ou 4!\n");
                scanf("%d",&N);
            }
            //initialisation du plateau
            //O= case vide 6=pas de moitié d un barriere i=pion du joueur i 7= presence de moitié d'une barriere
            if(N==2) {
                printf("Joueur 1 entre son nom\n");
                scanf("%s",&joueur1.nom);
                printf("Joueur 2 entre son nom\n");
                scanf("%s",&joueur2.nom);
                joueur1.pion=1;
                joueur1.position.x=0;
                joueur1.position.y=8;
                joueur2.pion=2;
                joueur2.position.x=16;
                joueur2.position.y=8;
                init_tab(plateaujeu,N,joueur1,joueur2,joueur3,joueur4);
                affichage_plateau(plateaujeu);
                do {
                    if(player_turn==1) {
                        joueur_actif=joueur1;
                        adversaire=joueur2;
                    }else {
                        joueur_actif=joueur2;
                        adversaire=joueur1;
                    }
                    printf("Tour du joueur %d\n",player_turn);
                    //jouerTour(&joueur_actif);
                    printf("1. Deplacer son pion\n");
                    printf("2. Placer une barriere\n");
                    printf("3. Annuler son coup\n");
                    printf("4. Passer son tour\n");
                    scanf("%d",&choixmenu);
                    while(choixmenu<1 || choixmenu>4) {
                        printf("Choix invalide\n");
                        scanf("%d",&choixmenu);
                    }
                    switch(choixmenu) {//Menu des fonctions du joueur
                        case 1:
                            printf("1. Haut\n");
                        printf("2. Bas\n");
                        printf("3. Gauche\n");
                        printf("4. Droite\n");
                        scanf("%d",&direction);
                        while(direction!=1 && direction!=2 && direction!=3 && direction!=4) {
                            printf("Choix invalide\n");
                            scanf("%d",&direction);
                        }
                        int d=valid_deplacer(direction,joueur_actif,plateaujeu);//verifie si le deplacement est valide
                        if(d==1) {
                            joueur_actif=deplacer(direction,joueur_actif,adversaire,adversaire1,adversaire2,adversaire3,plateaujeu,N);
                            affichage_plateau(plateaujeu);
                        }
                        while(d==0) {//cas où c est invalide
                            printf("Deplacement impossible\n");
                            printf("1. Haut\n");
                            printf("2. Bas\n");
                            printf("3. Gauche\n");
                            printf("4. Droite\n");
                            scanf("%d",&direction);
                            while(direction!=1 && direction!=2 && direction!=3 && direction!=4) {
                                printf("Choix invalide\n");
                                scanf("%d",&direction);
                            }
                            d=valid_deplacer(direction,joueur_actif,plateaujeu);
                            if(d==1) {//cas valide
                                joueur_actif=deplacer(direction,joueur_actif,adversaire,adversaire1,adversaire2,adversaire3,plateaujeu,N);
                                affichage_plateau(plateaujeu);
                                break;
                            }
                        }
                        break;
                        case 2://barrieres
                            int direction_bar;
                        printf("Entrer les coordonnees de la demi-barriere\n");
                        scanf("%d %d",&x,&y);
                        printf("Entrer la direction\n");
                        printf("1. Haut\n");
                        printf("2. Bas\n");
                        printf("3. Gauche\n");
                        printf("4. Droite\n");
                        scanf("%d",&direction_bar);
                        while(direction_bar!=1 && direction_bar!=2 && direction_bar!=3 && direction_bar!=4) {
                            printf("Choix invalide\n");
                            scanf("%d",&direction_bar);
                        }
                        int b=valid_barriere(x,y,direction_bar,joueur_actif,plateaujeu);
                        if(b==1) {
                            joueur_actif.nb_barr=placer_barriere(x,y,direction_bar,plateaujeu,joueur_actif);//actualise le nombre de barrière du joueur
                            affichage_plateau(plateaujeu);
                        }
                        while(b==0) {//cas invalide
                            printf("Placement impossible\n");
                            printf("Entrer les coordonnees de la demi-barriere\n");
                            scanf("%d %d",&x,&y);
                            printf("Entrer la direction\n");
                            printf("1. Haut\n");
                            printf("2. Bas\n");
                            printf("3. Gauche\n");
                            printf("4. Droite\n");
                            scanf("%d",&direction_bar);
                            while(direction_bar!=1 && direction_bar!=2 && direction_bar!=3 && direction_bar!=4) {
                                printf("Choix invalide\n");
                                scanf("%d",&direction_bar);
                            }
                            b=valid_barriere(x,y,direction_bar,joueur_actif,plateaujeu);
                            if(b==1) {//cas valide
                                joueur_actif.nb_barr=placer_barriere(x,y,direction_bar,plateaujeu,joueur_actif);
                                affichage_plateau(plateaujeu);
                                break;
                            }
                        }
                        break;
                    }
                    if(player_turn==1) {
                        joueur1=joueur_actif;
                    }else {
                        joueur2=joueur_actif;
                    }
                    if(a_gagner(joueur1,joueur2,joueur3,joueur4,N)==1) {
                        printf("%s a gagne\n",joueur1.nom);
                        break;
                    }else if(a_gagner(joueur1,joueur2,joueur3,joueur4,N)==2) {
                        printf("%s a gagne\n",joueur2.nom);
                        break;
                    };
                    player_turn=(player_turn)%2+1;
                }while(a_gagner(joueur1,joueur2,joueur3,joueur4,N)==0);
                    break;
            }else {
                printf("Joueur 1 entre son nom\n");
                scanf("%s",&joueur1.nom);
                printf("Joueur 2 entre son nom\n");
                scanf("%s",&joueur2.nom);
                printf("Joueur 3 entre son nom\n");
                scanf("%s",&joueur3.nom);
                printf("Joueur 4 entre son nom\n");
                scanf("%s",&joueur4.nom);
                joueur1.pion=1;
                joueur1.position.x=0;
                joueur1.position.y=8;
                joueur2.pion=2;
                joueur2.position.x=8;
                joueur2.position.y=0;
                joueur3.pion=3;
                joueur3.position.x=16;
                joueur3.position.y=8;
                joueur4.pion=4;
                joueur4.position.x=8;
                joueur4.position.y=16;
                init_tab(plateaujeu,N,joueur1,joueur2,joueur3,joueur4);
                affichage_plateau(plateaujeu);
                do {
                    if(player_turn==1) {
                        joueur_actif=joueur1;
                        adversaire1=joueur2;
                        adversaire2=joueur3;
                        adversaire3=joueur4;
                    }else if(player_turn==2) {
                        joueur_actif=joueur2;
                        adversaire1=joueur1;
                        adversaire2=joueur3;
                        adversaire3=joueur4;
                    }else if(player_turn==3) {
                        joueur_actif=joueur3;
                        adversaire1=joueur1;
                        adversaire2=joueur2;
                        adversaire3=joueur4;
                    }else if(player_turn==4) {
                        joueur_actif=joueur4;
                        adversaire1=joueur1;
                        adversaire2=joueur2;
                        adversaire3=joueur3;
                    }
                    printf("Tour du joueur %d\n",player_turn);
                    printf("1. Deplacer son pion\n");
                    printf("2. Placer une barriere\n");
                    printf("4. Passer son tour\n");
                    scanf("%d",&choixmenu);
                    while(choixmenu<1 || choixmenu>3) {
                        printf("Choix invalide\n");
                        scanf("%d",&choixmenu);
                    }
                    switch(choixmenu) {
                        //Menu des fonctions du joueur
                        case 1://deplacement du pion
                            printf("1. Haut\n");
                        printf("2. Bas\n");
                        printf("3. Gauche\n");
                        printf("4. Droite\n");
                        scanf("%d",&direction);
                        while(direction!=1 && direction!=2 && direction!=3 && direction!=4) {
                            printf("Choix invalide\n");
                            scanf("%d",&direction);
                        }
                        int d=valid_deplacer(direction,joueur_actif,plateaujeu);//verifie si le deplacement est valide
                        if(d==1) {
                            joueur_actif=deplacer(direction,joueur_actif,adversaire,adversaire1,adversaire2,adversaire3,plateaujeu,N);
                            affichage_plateau(plateaujeu);
                        }
                        while(d==0) {//cas où c est invalide
                            printf("Deplacement impossible\n");
                            printf("1. Haut\n");
                            printf("2. Bas\n");
                            printf("3. Gauche\n");
                            printf("4. Droite\n");
                            scanf("%d",&direction);
                            while(direction!=1 && direction!=2 && direction!=3 && direction!=4) {
                                printf("Choix invalide\n");
                                scanf("%d",&direction);
                            }
                            d=valid_deplacer(direction,joueur_actif,plateaujeu);
                            if(d==1) {
                                //cas valide
                                joueur_actif=deplacer(direction,joueur_actif,adversaire,adversaire1,adversaire2,adversaire3,plateaujeu,N);
                                affichage_plateau(plateaujeu);
                                break;
                            }
                        }
                        break;
                        case 2://barrieres
                              int direction_bar;
                        printf("Entrer les coordonnees de la demi-barriere\n");
                        scanf("%d %d",&x,&y);
                        printf("Entrer la direction\n");
                        printf("1. Haut\n");
                        printf("2. Bas\n");
                        printf("3. Gauche\n");
                        printf("4. Droite\n");
                        scanf("%d",&direction_bar);
                        while(direction_bar!=1 && direction_bar!=2 && direction_bar!=3 && direction_bar!=4) {
                            printf("Choix invalide\n");
                            scanf("%d",&direction_bar);
                        }
                        int b=valid_barriere(x,y,direction_bar,joueur_actif,plateaujeu);
                        if(b==1) {
                            joueur_actif.nb_barr=placer_barriere(x,y,direction_bar,plateaujeu,joueur_actif);//actualise le nombre de barrière du joueur
                            affichage_plateau(plateaujeu);
                        }
                        while(b==0) {//cas invalide
                            printf("Placement impossible\n");
                            printf("Entrer les coordonnees de la demi-barriere\n");
                            scanf("%d %d",&x,&y);
                            printf("Entrer la direction\n");
                            printf("1. Haut\n");
                            printf("2. Bas\n");
                            printf("3. Gauche\n");
                            printf("4. Droite\n");
                            scanf("%d",&direction_bar);
                            while(direction_bar!=1 && direction_bar!=2 && direction_bar!=3 && direction_bar!=4) {
                                printf("Choix invalide\n");
                                scanf("%d",&direction_bar);
                            }
                            b=valid_barriere(x,y,direction_bar,joueur_actif,plateaujeu);
                            if(b==1) {//cas valide
                                joueur_actif.nb_barr=placer_barriere(x,y,direction_bar,plateaujeu,joueur_actif);
                                affichage_plateau(plateaujeu);
                                break;
                            }
                        }
                        break;
                    }
                    if(player_turn==1) {
                        joueur1=joueur_actif;
                    }else if(player_turn==2) {
                        joueur2=joueur_actif;
                    }if(player_turn==3) {
                        joueur3=joueur_actif;
                    }else if(player_turn==4) {
                        joueur4=joueur_actif;
                    }
                    if(a_gagner(joueur1,joueur2,joueur3,joueur4,N)==1) {
                        printf("%s a gagne\n",joueur1.nom);
                        break;
                    }else if(a_gagner(joueur1,joueur2,joueur3,joueur4,N)==2) {
                        printf("%s a gagne\n",joueur2.nom);
                        break;
                    }else if(a_gagner(joueur1,joueur2,joueur3,joueur4,N)==3){
                        printf("%s a gagne\n",joueur3.nom);
                        break;
                    }else if(a_gagner(joueur1,joueur2,joueur3,joueur4,N)==4) {
                        printf("%s a gagne\n",joueur4.nom);
                        break;
                    };
                    player_turn=(player_turn)%4+1;
                }while(a_gagner(joueur1,joueur2,joueur3,joueur4,N)==0);

            }
            break;

        }

    }while(choixmenu!=2);
}
