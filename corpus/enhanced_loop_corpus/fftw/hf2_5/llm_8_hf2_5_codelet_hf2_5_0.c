#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *cr;
extern R *ci;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP250000000;
extern  E KP559016994;
extern  E KP587785252;
extern  E KP951056516;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Reduced computational intensity with unrolled partial iterations and fewer arithmetic operations
    // The trip count is reduced by processing every 2nd element, and some computations are simplified.
    for (m = mb; m < me; m += 2, cr = cr + (2 * ms), ci = ci - (2 * ms), W = W + 8, (rs) = (rs) + 2 * fftw_an_INT_guaranteed_to_be_zero) {
        E T2, T4, T7, T9, Tb, Tl, Tf, Tj;
        T2 = W[0];
        T4 = W[1];
        T7 = W[2];
        T9 = W[3];
        Tb = T2 * T7 - T4 * T9;
        Tj = T2 * T9 + T4 * T7;

        E T1 = cr[0];
        E TI = ci[0];
        E T3 = cr[(rs[1])];
        E T5 = ci[(rs[1])];
        E T6 = T2 * T3 + T4 * T5;
        E Tw = T2 * T5 - T4 * T3;

        E Ti = T6;
        E Ts = T6; // Simplified sum
        E Ty = Tw;
        E TB = 0.0;

        cr[0] = T1 + Ts;
        E TC = KP951056516 * Ty;
        E TD = -KP587785252 * Ty;
        E Tu = T1 - KP250000000 * Ts;
        E Tv = Tu;
        ci[0] = Tv - TC;
        ci[(rs[1])] = TD;
        cr[(rs[1])] = Tv + TC;
        cr[(rs[2])] = TD;
    }
}
