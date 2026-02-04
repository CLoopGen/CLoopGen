#include <stdint.h>

int rootlosers[300];
int j;
int k;
int num_moves;

void init_vars() {
    num_moves = 300;
    for (int i = 0; i < num_moves; i++) {
        rootlosers[i] = i % 7 == 0; // Approximately 1/7 of entries are non-zero
    }
    j = 0;
    k = 0;
}