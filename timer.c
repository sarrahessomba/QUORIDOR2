#include "timer.h"

// Initialiser le timer avec une durée limite
void init_timer(Timer *timer, int time_limit) {
    timer->start_time = time(NULL);
    timer->time_limit = time_limit;
}

// Obtenir le temps écoulé depuis le début du timer
int get_elapsed_time(Timer *timer) {
    return (int)(time(NULL) - timer->start_time);
}

// Vérifier si le temps est écoulé
int is_time_over(Timer *timer) {
    return get_elapsed_time(timer) >= timer->time_limit;
}
