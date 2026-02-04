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

extern rk_state *state;
extern unsigned long y;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < (624 - 1) / 2; i++) {
        y = (state->key[i] & 2147483648UL) | (state->key[i + 1] & 2147483647UL);
        state->key[i] = state->key[i + (397 - 624)] ^ (y >> 1) ^ (-(y & 1) & 2567483615UL);
    }
    for (; i < 624 - 1; i++) {
        y = (state->key[i] & 2147483648UL) | (state->key[i + 1] & 2147483647UL);
        state->key[i] = state->key[i + (397 - 624)] ^ (y >> 1) ^ (-(y & 1) & 2567483615UL);
    }
}
