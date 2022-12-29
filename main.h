
#ifndef PROJET_IFB_MAIN_H
#define PROJET_IFB_MAIN_H

/**
 * @file main.h
 * @brief fichier header contenant les inculsions des bibliotheque et des headers du projet, les définitions des structures
 * @author Ondine H., Loïs B. et Jules F.
 * @date juin 2021
 */

/**
 * Structure pour la grille : Grille tableau de caractères, sa largeur et sa hauteur
 */
typedef struct {
    char** grille;
    int largeur;
    int hauteur;
} Grid;

/**
 * Structure pour les joueurs : le Jeton, l'inititive (numéro_joueur), pseudo
 */
typedef struct {
    char jeton;
    int numero_joueur;
    char pseudo[101];
} Joueur;


/**
 * Structure Boolean : TRUE = 1 et FALSE = 0
 */
typedef enum {
    FALSE = 0,
    TRUE = 1,
} Boolean;

#include "traitement.h"
#include "affichage.h"
#include "jeu.h"
#include "check_winner.h"
#include "ordinateur.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

#endif //PROJET_IFB_MAIN_H
