#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct s_mt19937_state {
    uint32_t key[624];
    int pos;
} mt19937_state;

mt19937_state *state;
uint32_t y;
int i;

void init_vars() {
    state = (mt19937_state*)malloc(sizeof(mt19937_state));
    if (!state) {
        exit(1);
    }
    state->pos = 0;
    for (int j = 0; j < 624; j++) {
        state->key[j] = (uint32_t)(j * j + 1); 
    }
}