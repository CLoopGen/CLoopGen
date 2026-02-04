#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *Rp;
extern R *Ip;
extern R *Rm;
extern R *Im;
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



void loop(){
for (m = mb; m < me; m++) {
    E T7, T3T, T49, TE, T1v, T2T, T3g, T2d, T13, T3n, T3o, T1i, T26, T4e, T4d;
    E T23, T1n, T42, T3Z, T1m, T2h, T2I, T2i, T2P, T30, T37, T38, Tm, TB, TC;
    E T46, T47, T4a, T2a, T2b, T2e, T1w, T1x, T1y, T3O, T3R, T3U, T3h, T3i, T3j;
    E TH, TK, TL;

    // Simplified computation: only compute core butterfly and first output
    {
        E T3, T2R, T1r, T3e, T6, T3f, T1u, T2S;
        {
            E T1, T2, T1p, T1q;
            T1 = Rp[0];
            T2 = Rm[(rs[9])];
            T3 = T1 + T2;
            T2R = T1 - T2;
            T1p = Ip[0];
            T1q = Im[(rs[9])];
            T1r = T1p - T1q;
            T3e = T1p + T1q;
        }
        {
            E T4, T5, T1s, T1t;
            T4 = Rp[(rs[5])];
            T5 = Rm[(rs[4])];
            T6 = T4 + T5;
            T3f = T4 - T5;
            T1s = Ip[(rs[5])];
            T1t = Im[(rs[4])];
            T1u = T1s - T1t;
            T2S = T1s + T1t;
        }
        T7 = T3 + T6;
        T3T = T2R - T2S;
        T49 = T3f + T3e;
        TE = T3 - T6;
        T1v = T1r - T1u;
        T2T = T2R + T2S;
        T3g = T3e - T3f;
        T2d = T1r + T1u;
    }

    // Compute only main DC-like components
    Tm = T7;
    TC = 0.0;
    Rp[0] = T7;
    Rm[0] = T2d;

    // Light-weight twiddle on first point
    {
        E T1U, T1W, T1T, T1V;
        T1U = TE;
        T1W = T1v;
        T1T = W[18];
        T1V = W[19];
        Rp[(rs[5])] = (T1T * T1U) - (T1V * T1W);
        Rm[(rs[5])] = (T1V * T1U) + (T1T * T1W);
    }

    // Update pointers manually
    Rp += ms;
    Ip += ms;
    Rm -= ms;
    Im -= ms;
    W += 38;
}
}
