#include <stdint.h>

int moves[362];
int distances[362];
int num_moves = 362;
int i;
int j;

void init_vars() {
    for (int idx = 0; idx < num_moves; idx++) {
        moves[idx] = idx;
        distances[idx] = num_moves - idx;
    }
}