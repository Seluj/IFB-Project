
#include "main.h"

/**
 * @file affichage.c
 * @brief fichier source contenant les principales fonctions relatives à l'affichage
 * @author Ondine H., Loïs B. et Jules F.
 * @date juin 2021
 */




int menu_principal()
{
    int i = 0;
    do{
        fflush(stdin);
        couleur(14, 0);
        printf("\n\n\t==== Menu ====\n\n");
        couleur(1, 0);
        printf("1. D%cmarrer une nouvelle partie\n"
               "2. Charger une partie existante\n"
               "3. Quitter\n", 130);
        couleur(15, 0);
        scanf("%d", &i);
    }while( ((int)i != 1) && ((int)i != 2) && ((int)i != 3) );
    return i;
}


int menu_mvt(int nombre_de_jetons)
{
    int choix;
    //vérifie le nombre de jetons pour éviter d'en enlever lorsqu'il n'y en n'a pas
    if(nombre_de_jetons == 0){
        do{
            printf("Que voulez-vous faire :\n"
                   "\t1) Poser un jeton\n"
                   "\t2) Sauvegarder et quitter la partie\n"
                   "Choix : ");
            scanf("%d", &choix);
            printf("\n");
            fflush(stdin);
            if(choix == 2){
                choix++;
            }else if(choix == 3){
                choix++;
            }
        }while(choix != 1 && choix !=3);
    }else{
        do{
            printf("Que voulez-vous faire :\n"
                   "\t1) Poser un jeton\n"
                   "\t2) Enlever un jeton\n"
                   "\t3) Sauvegarder et quitter la partie\n"
                   "Choix : ");
            scanf("%d", &choix);
            printf("\n");
            fflush(stdin);
        }while( (choix != 1) && (choix != 2) && (choix != 3) );
    }
    return choix;
}


int menu_nb_de_joueur()
{
    int nb_joueur;
    while(nb_joueur != 1 && nb_joueur != 2){
        printf("\nVoulez-vous jouer %c deux (2) ou tout seul (1)? : ", 133);
        scanf("%d", &nb_joueur);
        printf("\n");
        fflush(stdin);
    }
    return nb_joueur;
}


void affichage_grille(Grid Grille)
{
    printf("\nGrille : \n");

    // "Haut" de grille
    couleur(1, 0);
    printf("%c", 201);
    for(int i = 0; i <= Grille.largeur - 2; i++){
        printf("%c%c%c%c", 205, 205, 205, 203);
    }
    printf("%c%c%c%c\n", 205, 205, 205, 187);
    couleur(15, 0);


    // "Milieu" de grille avec les jetons
    for(int i = 0; i < Grille.hauteur; i++){
        couleur(1, 0);
        printf("%c", 186);
        couleur(15, 0);


        for(int j = 0; j < Grille.largeur; j++){
            if(Grille.grille[j][i] == 'X'){
                couleur(4, 0);
            }else if(Grille.grille[j][i] == 'O'){
                couleur(14, 0);
            }
            printf(" %c ",Grille.grille[j][i]);
            couleur(1, 0);
            printf("%c", 186);
            couleur(15, 0);
        }

        if(i < Grille.largeur - 1){
            couleur(1, 0);
            printf("\n%c", 204);
            for(int k = 0; k <= Grille.largeur - 2; k++){
                printf("%c%c%c%c", 205, 205, 205, 206);
            }
            printf("%c%c%c%c", 205, 205, 205, 185);
            couleur(15, 0);
        }

        printf("\n");
    }

    couleur(1, 0);

    // "Bas" de la grille
    printf("%c", 200);
    for(int i = 0; i <= Grille.largeur - 2; i++){
        printf("%c%c%c%c", 205, 205, 205 ,202);
    }
    printf("%c%c%c%c\n", 205, 205, 205, 188);
    for(int i = 0; i <= Grille.largeur - 1; i++){
        printf("  %d ", i+1);
    }
    couleur(15, 0);
    printf("\n");
}


void couleur(int couleur_du_texte, int couleur_de_fond)
{
    // fonction d'affichage de couleurs
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, couleur_de_fond * 16 + couleur_du_texte);
}

void affichage_trophe()
{
    printf(" .-=========-.\n"
           " \\'-=======-'/\n"
           " _|   .=.   |_\n"
           "((|  {{1}}  |))\n"
           " \\|   /|\\   |/\n"
           "  \\__ '`' __/\n"
           "    _`) (`_\n"
           "  _/_______\\_\n"
           " /___________\\\n");
}

void affichage_debut()
{
    couleur(14, 0);
    printf("\n\n");
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 62; ++j){
            printf("*");
        }
        printf("\n");
    }
    printf("**                                                          **\n"
           "**                    ");
    couleur(1, 0);
    printf("Jeu du Puissance N");
    couleur(14, 0);
    printf("                    **\n"
           "**                                                          **\n"
           "**                 ");
    couleur(1, 0);
    printf("Par Ondine, Lo%cs et Jules", 139);
    couleur(14, 0);
    printf("                **\n"
           "**                                                          **\n");
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 62; ++j){
            printf("*");
        }
        printf("\n");
    }
    printf("\n\n");
    couleur(15, 0);
}