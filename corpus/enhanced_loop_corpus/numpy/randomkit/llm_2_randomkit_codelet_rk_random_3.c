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



void loop() {
    // Variant 1: Strided Memory Access (stride of 2, unrolled by factor 2)
    // This variant processes elements with a stride of 2 to increase cache line utilization
    // and reduce data dependencies. It handles boundary conditions explicitly.
    int limit = 624 - 397;
    for (i = 0; i < limit; i += 2) {
        unsigned long y1, y2;

        // First element in the pair
        y1 = (state->key[i] & 2147483648UL) | (state->key[i + 1] & 2147483647UL);
        state->key[i] = state->key[i + 397] ^ (y1 >> 1) ^ (-(y1 & 1) & 2567483615UL);

        // Second element, if within bounds
        if (i + 1 < limit) {
            y2 = (state->key[i + 1] & 2147483648UL) | (state->key[i + 2] & 2147483647UL);
            state->key[i + 1] = state->key[i + 398] ^ (y2 >> 1) ^ (-(y2 & 1) & 2567483615UL);
        }
    }
}
