#include <stdint.h>

int lunch_dragon[240];
int lunch_worm[240];
int next_lunch;
int k;
int dragon1;
int worm1;

void init_vars() {
    next_lunch = 240;
    dragon1 = -1;
    worm1 = -1;

    for (int i = 0; i < 240; i++) {
        lunch_dragon[i] = (i % 2) ? 1 : 2;
        lunch_worm[i] = (i % 2) ? 2 : 1;
    }

    lunch_dragon[239] = dragon1;
    lunch_worm[239] = worm1;
}