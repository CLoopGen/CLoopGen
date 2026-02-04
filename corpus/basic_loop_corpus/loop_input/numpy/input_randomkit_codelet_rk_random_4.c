#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct rk_state_ {
    unsigned long key[624];
    int pos;
    int has_gauss;
    double gauss;
    int has_binomial;
    double psave;
    long nsave;
    double r;
    double q;
    double fm;
    long m;
    double p1;
    double xm;
    double xl;
    double xr;
    double c;
    double laml;
    double lamr;
    double p2;
    double p3;
    double p4;
} rk_state;

static rk_state state_instance;
rk_state *state = &state_instance;
unsigned long y;
int i;

void init_vars() {
    // Initialize all key values to non-zero predictable pattern
    for (int j = 0; j < 624; j++) {
        state->key[j] = 1812433253UL * (j + 1) + j;
    }
    // Ensure loop runs with valid bounds: i from current value to 624 - 2
    // We set i = 0 so loop runs from 0 to 622 inclusive
    i = 0;
    // Other fields are not accessed in the loop, but initialize for completeness
    state->pos = 0;
    state->has_gauss = 0;
    state->gauss = 0.0;
    state->has_binomial = 0;
    state->psave = 0.0;
    state->nsave = 0;
    state->r = 0.0;
    state->q = 0.0;
    state->fm = 0.0;
    state->m = 0;
    state->p1 = 0.0;
    state->xm = 0.0;
    state->xl = 0.0;
    state->xr = 0.0;
    state->c = 0.0;
    state->laml = 0.0;
    state->lamr = 0.0;
    state->p2 = 0.0;
    state->p3 = 0.0;
    state->p4 = 0.0;
}