cmake_minimum_required(VERSION 3.29)
project(QUORIDOR2 C)

set(CMAKE_C_STANDARD 11)

add_executable(QUORIDOR2 main.c
        plateau.c
        plateau.h
        fonction.joueur.c
        fonction.joueur.h
        affichage.c
        affichage.h
        condition.c
        condition.h
        timer.h
        timer.c
        score.c
        score.h)
