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
    unsigned long prev_key, current_y;
    if (i < 624 - 1) {
        prev_key = state->key[i];
        i++;
        for (; i < 624 - 1; i++) {
            current_y = (prev_key & 2147483648UL) | (state->key[i] & 2147483647UL);
            prev_key = state->key[i];
            state->key[i - 1] = state->key[i - 1 + (397 - 624)] ^ (current_y >> 1) ^ (-(current_y & 1) & 2567483615UL);
        }
    }
}
