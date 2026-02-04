#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int score[8];
int i;
int best_fcode;
int best_score;

void init_vars() {
    for (int idx = 0; idx < 8; idx++) {
        score[idx] = rand() % 1000;
    }
    i = 0;
    best_fcode = 0;
    best_score = score[0];
}