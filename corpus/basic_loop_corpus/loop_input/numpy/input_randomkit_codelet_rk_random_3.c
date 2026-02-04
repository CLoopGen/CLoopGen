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

rk_state global_state;
rk_state *state = &global_state;
unsigned long y;
int i;

void init_vars() {
    for (int j = 0; j < 624; j++) {
        state->key[j] = rand() | ((unsigned long)rand() << 32);
    }
    state->pos = 0;
    state->has_gauss = 0;
    state->gauss = 0.0;
    state->has_binomial = 0;
    state->psave = 0.5;
    state->nsave = 100;
    state->r = 0.1;
    state->q = 0.9;
    state->fm = 50.0;
    state->m = 50;
    state->p1 = 0.2;
    state->xm = 60.0;
    state->xl = 40.0;
    state->xr = 70.0;
    state->c = 0.5;
    state->laml = 2.0;
    state->lamr = 3.0;
    state->p2 = 0.3;
    state->p3 = 0.4;
    state->p4 = 0.5;
    y = 0;
    i = 0;
}