
#include "main.h"

/**
 * @file check_winner.c
 * @brief fichier source contenant les fonctions relatives au test du gagnant
 * @author Ondine H., Loïs B. et Jules F.
 * @date juin 2021
 */





int check_winner(Grid g, int colonne, Joueur j1, Joueur j2)
{
    int ligne = 0;
    int colonne_temp = colonne-1;
    //tant que la case de la grille contient _ on "descent" pour obtenir la ligne de la case ou il y a un jeton
    while(g.grille[colonne_temp][ligne] == '_'){
        ligne++;
    }
    if(nb_jetons_alignes(g, j1.jeton, ligne, colonne_temp) == g.largeur-1){
        //on compte le nombre de jetons du joueur 1
        return 0; //le joueur 1 a gagné
    }else if(nb_jetons_alignes(g, j2.jeton, ligne, colonne_temp) == g.largeur-1){
        //on compte le nombre de jetons du joueur 2
        return 1; //le joueur 2/l'ordinateur a gagné
    }
    return -1; //personne n'a gagné pour l'instant
}

int nb_jetons_dir(Grid g, char jeton, int ligne, int colonne, int dir_x, int dir_y)
{
    int l, c, resultat = 0;
    l = ligne;
    c = colonne;
    while(position_valide(g, l, c) == TRUE){ //on repete les instructions tant qu'on reste bien dans la grille
        if(g.grille[c][l] == jeton){ //si on rencontre un jeton,
            resultat++; //on incremente le resultat de 1
        }else{ //sinon on sort de la fonction
            dir_y = 100;
            dir_x = 100;
        }
        l += dir_y;
        c += dir_x;
    }
    return resultat;
}

int maximum(int a, int b)
{
    if(a > b){
        return a;
    }else{
        return b;
    }
}

int nb_jetons_alignes(Grid g, char jeton, int ligne, int colonne)
{
    int resultat;
    resultat = nb_jetons_dir(g, jeton, ligne, colonne, 0, 1) + nb_jetons_dir(g, jeton, ligne, colonne, 0, -1);
    /*
     * Nombre de jetons horizontaux
     *  |
     *  |
     *  |
     *  |
     */
    resultat =
            maximum(
                    nb_jetons_dir(g, jeton, ligne, colonne, 1, 0) + nb_jetons_dir(g, jeton, ligne, colonne, -1, 0),
                    resultat
            );
    /*
     * Max entre :
     *      - Nombre de jetons verticaux
     *      - Résultat précédent
     *  _____
     */
    resultat =
            maximum(
                    nb_jetons_dir(g, jeton, ligne, colonne, 1 ,1) + nb_jetons_dir(g, jeton, ligne, colonne, -1, -1),
                    resultat
            );
    /*
     * Max entre :
     *      - Nombre de jetons diagonal vers le bas à droite
     *      - Résultat précédent
     *   \
     *    \
     *     \
     *      \
     */
    resultat =
            maximum(
                    nb_jetons_dir(g, jeton, ligne, colonne, 1, -1) + nb_jetons_dir(g, jeton, ligne, colonne, -1, 1),
                    resultat
            );
    /*
     * Max entre :
     *      - Nombre de jetons en diagonale vers le bas à gauche
     *      - Résultat précédent
     *      /
     *     /
     *    /
     *   /
     */
    return resultat;
}

Boolean position_valide(Grid g, int ligne, int colonne)
{
    Boolean ret = TRUE;
    if( (colonne > g.largeur - 1 || colonne < 0) || (ligne > g.hauteur - 1 || ligne < 0) ){
        ret = FALSE;
    }
    return ret;
}