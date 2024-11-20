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
joueur deplacer(int direction,joueur joueur_actif,joueur adversaire,int tab[17][17],int N) {
   //
    if(N==2) {
        int x= joueur_actif.position.x,y= joueur_actif.position.y;
        int adv_x= adversaire.position.x, adv_y= adversaire.position.y;
        new_cord(direction,joueur_actif,&x,&y);
        if(x==adv_x && y==adv_y) {
            if(direction==1 || direction==2) {//Haut ou bas
                int direct;
                if(((tab[adv_x-1][adv_y]==7)&& direction==1)|| ((tab[adv_x+1][adv_y]==7) && direction==2)) {//barriere
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
                if(adv_x==0 || adv_x==16) {
                    if(adv_y==0) {
                        y= y+2;
                    }else if (adv_y==16) {
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
                if(adv_y==0 || adv_y==16) {
                    if(adv_x==0) {
                        x= x+2;
                    }else if(adv_x==16) {
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
    }
};
