#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    int n;
    unsigned long x[25];
} tt_state_t;

tt_state_t *state;
int i;

void init_vars() {
    state = (tt_state_t *)malloc(sizeof(tt_state_t));
    if (!state) {
        exit(1);
    }
    state->n = 25;
    for (int j = 0; j < 25; j++) {
        state->x[j] = 12345UL + j;
    }
    i = 0;
}