#include <stdint.h>
#include <stdlib.h>

typedef struct s_mt19937_state {
    uint32_t key[624];
    int pos;
} mt19937_state;

mt19937_state *target_state;
mt19937_state *state;
int i;

void init_vars() {
    state = (mt19937_state*)malloc(sizeof(mt19937_state));
    target_state = (mt19937_state*)malloc(sizeof(mt19937_state));

    if (!state || !target_state) {
        exit(1);
    }

    for (int j = 0; j < 624; j++) {
        state->key[j] = (uint32_t)(j * j + 1);
    }
    state->pos = 0;
    target_state->pos = 0;
}