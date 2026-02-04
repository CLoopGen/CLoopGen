#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    unsigned long mt[624];
    int mti;
} mt_state_t;

mt_state_t *state;
int i;

void init_vars() {
    state = (mt_state_t*)malloc(sizeof(mt_state_t));
    if (!state) {
        exit(1);
    }
    state->mt[0] = 5489UL;
    for (int j = 1; j < 624; j++) {
        state->mt[j] = 0;
    }
    state->mti = 1;
    i = 1;
}