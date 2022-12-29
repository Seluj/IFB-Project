

#ifndef PROJET_IFB_AFFICHAGE_H
#define PROJET_IFB_AFFICHAGE_H

/**
 * @file affichage.h
 * @brief fichier header contenant les prototypes des fonctions relatives à l'affichage
 * @author Ondine H., Loïs B. et Jules F.
 * @date juin 2021
 */



/**
 * Menu principal du jeu, il ne se lance qu'une fois au tout début du programme
 * @return retourne le choix de l'utilisateur,
 *                  1-> nouvelle partie
 *                  2-> charger une partie sauvegarder
 *                  3-> quitter
 */
int menu_principal();

/**
 * Menu du jeu, il se lance au début de chaque tour
 * @param nombre_de_jetons nombre de jetons dans la grille
 * @return retourne le choix de l'utilisateur,
 *                  1-> ajouter un jeton
 *                  2-> enlever un jeton
 *                  3-> sauvegarder et quitter
 */
int menu_mvt(int nombre_de_jetons);

/**
 * menu lorsque l'utilisateur choisi une nouvelle partie
 * @return retourne le nombre de joueur, 1 ou 2
 */
int menu_nb_de_joueur();

/**
 * affichage de la grille avec couleur
 * @param Grille grille à afficher
 */
void affichage_grille(Grid Grille);

/**
 * colore le texte
 * @param couleur_du_texte couleur du texte
 * @param couleur_de_fond couleur du fond/du surlignage
 */
void couleur(int couleur_du_texte, int couleur_de_fond);

/**
 * affiche un trophée lorsque un joueur gagne
 */
void affichage_trophe();

/**
 * Affiche un petit message au lancement du programme
 */
void affichage_debut();

#endif //PROJET_IFB_AFFICHAGE_H
