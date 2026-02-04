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

extern unsigned long seed;
extern rk_state *state;
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 2; outer++) {
        for (pos = 0; pos < 312; pos++) {
            state->key[pos + outer * 312] = seed;
            seed = (1812433253UL * (seed ^ (seed >> 30)) + pos + 1) & 4294967295UL;
        }
    }
}
