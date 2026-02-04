#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    unsigned int i;
    unsigned int j;
    unsigned int n;
    unsigned int skip;
    unsigned int carry;
    unsigned long u[24];
} ranlux_state_t;

unsigned long two24 = 16777216UL; // 2^24

ranlux_state_t *state;
int i;
long seed;

void init_vars() {
    // Allocate state structure on heap and assign to pointer
    state = (ranlux_state_t*)malloc(sizeof(ranlux_state_t));
    if (!state) {
        fprintf(stderr, "Failed to allocate state\n");
        exit(1);
    }

    // Initialize state fields to valid starting values
    state->i = 0;
    state->j = 0;
    state->n = 24;
    state->skip = 0;
    state->carry = 0;

    // Initialize u array to zero
    for (int idx = 0; idx < 24; idx++) {
        state->u[idx] = 0;
    }

    // Set seed to a non-zero value for PRNG sequence
    seed = 123456789L;
}