cmake_minimum_required(VERSION 3.19)
project(Projet_IFB C)

set(CMAKE_C_STANDARD 99)

add_executable(Projet_IFB main.c affichage.c affichage.h traitement.c traitement.h check_winner.c check_winner.h jeu.c jeu.h ordinateur.c ordinateur.h main.h)