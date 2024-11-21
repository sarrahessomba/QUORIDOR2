#ifndef TIMER_H
#define TIMER_H

#include <time.h>

// Définition de la structure pour le timer
typedef struct {
    time_t start_time;
    int time_limit; // Durée limite en secondes
} Timer;

// Prototypes des fonctions
void init_timer(Timer *timer, int time_limit);
int get_elapsed_time(Timer *timer);
int is_time_over(Timer *timer);

#endif

