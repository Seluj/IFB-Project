
#ifndef PROJET_IFB_TRAITEMENT_H
#define PROJET_IFB_TRAITEMENT_H

/**
 * @file traitement.h
 * @brief fichier header contenant les prototypes des fonctions relatives aux calculs
 * @author Ondine H., Loïs B. et Jules F.
 * @date juin 2021
 */


/**
 * initialise la grille et demande le nombre de jetons à aligner
 * @param grille grille à modifier
 */
void initialisation_grille(Grid* grille);

/**
 * initialise les joueurs en leur donnant leur numéro et leur type de jeton et en demandant leur pseudo
 * @param j1 joueur 1
 * @param j2 joueur 2
 * @return le nombre de joueur réel
 */
int initialisation_joueur(Joueur* j1, Joueur* j2);

/**
 * ajoute un jeton dans la grille
 * @param g grille de jeu
 * @param indice numéro de la colonne +1 où faire "tomber" le jeton
 * @param jeton type de jeton à ajouter X ou O
 * @return TRUE si l'action est réalisable et FALSE sinon
 */
Boolean add_token(Grid* g, int indice, char jeton);

/**
 * retirer un jeton de la grille
 * @param g grille de jeu
 * @param colonne numéro de la colonne +1 où retirer un jeton
 * @return TRUE si l'action est réalisable et FALSE sinon
 */
Boolean remove_token(Grid* g, int colonne);

/**
 * demande une colonne à l'utilisateur et compare au choix precedent
 * @param g grille de jeu
 * @param col colonne précédente
 * @param choix_mouvement choix de l'utilisateur
 * @param choix_mouvement_precedent choix précédent de l'utilisateur
 * @return retourne le numéro de la colonne choisie
 */
int colonne_utilisateur(Grid g, int col_precedente, int choix_mouvement, int choix_mouvement_precedent);

/**
 * sauvegarde la partie en cours
 * @param g grille à sauvegarder
 * @param nb_tour numéro du tour à sauvegarder
 * @param nb_jetons nombre de jeton dans la grille à sauvegarder
 * @param j1 joueur 1
 * @param j2 joueur 2
 * @param nb_joueur nombre de joueurs réels
 */
void save(Grid g, int nb_tour, int nb_jetons, Joueur j1, Joueur j2, int nb_joueur);

/**
 * initialise une partie sauvegardée
 * @param g grille à charger
 * @param nb_tour numéro du tour de la partie à charger
 * @param nb_jetons Nombre de jeton dans la grille chargé
 * @param j1 joueur 1
 * @param j2 joueur 2
 * @param nb_joueur nombre de joueur réel dans la partie chargée
 * @return TRUE si la grille a pu etre chargée et FALSE sinon
 */
Boolean load(Grid* g, int* nb_tour, int* nb_jetons, Joueur* j1, Joueur* j2, int* nb_joueur);

/**
 * vérifie si la grille est pleine et arrête le programme si c'est le cas
 * @param g grille à tester
 * @return TRUE si la grille est pleine et FALSE si elle ne l'est pas
 */
Boolean grille_pleine(Grid g);

/**
 * libere la mémoire de la grille
 * @param grille grille à liberer
 */
void free_memory(Grid* grille);

#endif //PROJET_IFB_TRAITEMENT_H
