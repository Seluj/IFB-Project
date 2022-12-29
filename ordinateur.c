
#include "main.h"

/**
 * @file ordinateur.c
 * @brief fichier source contenant les fonctions relatives au jeu de l'ordinateur
 * @author Ondine H., Loïs B. et Jules F.
 * @date juin 2021
 */



int mvt_ordi(int nb_jetons)
{
    int choix;
    srand(time(0));
    int temp;

    //on teste le nombre de jeton dans la grille
    if(nb_jetons != 0){
        //il y a déjà un jeton ou plus
        temp = rand()%5;
        //si le rand est inférieur ou égale à 3 on ajoute un jeton, sinon on en enlève un
        if(temp == 0 || temp == 1 || temp == 2 || temp == 3){
            choix = 1;
        }else{
            choix = 2;
        }
    }else{
        //il n'y a pas de jeton donc il en mets un
        choix = 1;
    }
    return choix;
}

int colonne_ordi(Grid g, int col_precedent, int choix_mvt, int choix_mvt_precedent)
{
    int resultat;
    srand(time(0));

    //on teste le choix du mouvement
    switch(choix_mvt){
        case 1:
            if(choix_mvt_precedent == 2){
                do{
                    resultat = (rand() % (g.largeur-1)) + 1;
                }while(resultat > g.largeur || resultat == col_precedent);
            }else{
                do{
                    resultat = (rand() % (g.largeur-1)) + 1;
                }while(resultat > g.largeur);
            }
            break;
        case 2:
            do{
                resultat = (rand()% (g.largeur-1)) + 1;
            }while(resultat > g.largeur);
            break;
    }
    return resultat;
}