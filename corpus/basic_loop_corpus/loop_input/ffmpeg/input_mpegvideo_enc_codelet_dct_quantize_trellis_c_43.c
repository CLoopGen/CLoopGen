#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE 65

int run_tab[65];
int level_tab[65];
int score_tab[65];
int survivor[65];
int last_run;
int last_level;
int last_score;
int last_i;
int last_non_zero;
int i;
int lambda;

void init_vars() {
    for (int idx = 0; idx < DATA_SIZE; idx++) {
        run_tab[idx] = rand() % 16;
        level_tab[idx] = rand() % 8;
        score_tab[idx] = rand() % 10000;
        survivor[idx] = idx;
    }

    last_run = 0;
    last_level = 0;
    last_score = 20000;
    last_i = 0;
    last_non_zero = 63;
    i = 0;
    lambda = 5;
}