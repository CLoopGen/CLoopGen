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
    for (pos = 0; pos < 624; pos += 4) {
        state->key[pos] = seed;
        seed = (1812433253UL * (seed ^ (seed >> 30)) + pos + 1) & 4294967295UL;

        if (pos + 1 < 624) {
            state->key[pos + 1] = seed;
            seed = (1812433253UL * (seed ^ (seed >> 30)) + pos + 2) & 4294967295UL;
        }

        if (pos + 2 < 624) {
            state->key[pos + 2] = seed;
            seed = (1812433253UL * (seed ^ (seed >> 30)) + pos + 3) & 4294967295UL;
        }

        if (pos + 3 < 624) {
            state->key[pos + 3] = seed;
            seed = (1812433253UL * (seed ^ (seed >> 30)) + pos + 4) & 4294967295UL;
        }
    }
}
