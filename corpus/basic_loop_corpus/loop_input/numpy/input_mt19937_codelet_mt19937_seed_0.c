#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct s_mt19937_state {
    uint32_t key[624];
    int pos;
} mt19937_state;

mt19937_state *state;
uint32_t seed;
int pos;

void init_vars() {
    state = (mt19937_state*)malloc(sizeof(mt19937_state));
    if (!state) {
        exit(1);
    }
    seed = 5489U;
    pos = 0;
}