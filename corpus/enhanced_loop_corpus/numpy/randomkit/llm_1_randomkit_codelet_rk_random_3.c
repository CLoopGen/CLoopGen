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
    for (i = 0; i < (624 - 397) * 2; i += 2) {
        int idx1 = i;
        int idx2 = i + 1;
        if (idx1 < 624 - 397) {
            y = (state->key[idx1] & 2147483648UL) | (state->key[idx1 + 1] & 2147483647UL);
            state->key[idx1] = state->key[idx1 + 397] ^ (y >> 1) ^ (-(y & 1) & 2567483615UL);
        }
        if (idx2 < 624 - 397) {
            y = (state->key[idx2] & 2147483648UL) | (state->key[idx2 + 1] & 2147483647UL);
            state->key[idx2] = state->key[idx2 + 397] ^ (y >> 1) ^ (-(y & 1) & 2567483615UL);
        }
    }
}
