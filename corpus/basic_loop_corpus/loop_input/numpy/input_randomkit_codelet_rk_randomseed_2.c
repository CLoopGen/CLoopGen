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

rk_state *state;
int i;

void init_vars() {
    state = (rk_state*)calloc(1, sizeof(rk_state));
    if (!state) {
        exit(1);
    }
    for (int j = 0; j < 624; j++) {
        state->key[j] = (unsigned long)(j * 1234567ULL);
    }
    state->pos = 0;
    state->has_gauss = 0;
    state->gauss = 0.0;
    state->has_binomial = 0;
    state->psave = 0.0;
    state->nsave = 0L;
    state->r = 0.0;
    state->q = 0.0;
    state->fm = 0.0;
    state->m = 0L;
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