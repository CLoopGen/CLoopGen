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
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 1248; i++) {
        int idx = i % 624;
        state->key[idx] = (state->key[idx] & 4294967295UL) ^ (state->key[idx] >> 32);
    }
}
