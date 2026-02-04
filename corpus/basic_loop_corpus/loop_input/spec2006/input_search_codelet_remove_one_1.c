#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int *marker;
int move_ordering[65536];
int num_moves;
int i;
int best;

void init_vars() {
    num_moves = 65536;
    best = 0;
    marker = (int*)malloc(sizeof(int));
    *marker = -1;

    for (int idx = 0; idx < num_moves; idx++) {
        move_ordering[idx] = rand() % 1000;
    }
}