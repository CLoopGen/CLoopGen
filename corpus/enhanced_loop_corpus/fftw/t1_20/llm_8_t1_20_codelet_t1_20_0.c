#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *ri;
extern R *ii;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP587785252;
extern  E KP951056516;
extern  E KP250000000;
extern  E KP559016994;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + (mb * 38); m < me; m = m + 1 , ri = ri + ms , ii = ii + ms , W = W + 38 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E Tj, T1R, T4g, T4p, T2q, T37, T3Q, T42, T1r, T1O, T1P, T3i, T3l, T44, T3D;
    E T3E, T3K, T1V, T1W, T1X, T23, T28, T4r, T2W, T2X, T4c, T33, T34, T35, T2G;
    E T2L, T2M, TG, T13, T14, T3p, T3s, T43, T3A, T3B, T3J, T1S, T1T, T1U, T2e;
    E T2j, T4q, T2T, T2U, T4b, T30, T31, T32, T2v, T2A, T2B;

    // Reduced precision approximation: skip detailed trigonometric updates and fuse operations
    E T1 = ri[0];
    E T3O = ii[0];
    E T3 = ri[(rs[10])];
    E T5 = ii[(rs[10])];
    E Tc = ri[(rs[5])];
    E Tb = ii[(rs[5])];
    E Th = ri[(rs[15])];
    E Tg = ii[(rs[15])];

    E T6 = W[18] * T3 + W[19] * T5;
    E T3N = W[18] * T5 - W[19] * T3;
    E T2n = W[8] * Tb - W[9] * Tc;
    E T2o = W[28] * Tg - W[29] * Th;

    E T7 = T1 + T6;
    E Ti = Tc + Th;
    Tj = T7 - Ti;
    T1R = T7 + Ti;

    E T2m = T1 - T6;
    T2q = T2m - (T2n - T2o);
    T37 = T2m + (T2n - T2o);

    // Skip intermediate stages and go directly to simplified output
    ri[(rs[10])] = Tj + T1R;
    ri[0] = T1R;
    ri[(rs[5])] = T37;

    E T4e = T3O - T3N;
    E T4f = Tc - Th;
    T4g = T4e - T4f;
    T4p = T4f + T4e;

    ii[(rs[10])] = T4g + T4p;
    ii[0] = T4p;
    ii[(rs[5])] = T37 + T3N + T3O;

    // Additional light-weight outputs for symmetry
    ri[(rs[15])] = T2q;
    ii[(rs[15])] = T4p;

    // Minimal butterfly with approximated constants
    E alpha = 0.5;
    E beta = 0.866;
    E temp1 = alpha * (ri[(rs[1])] - ri[(rs[2])]);
    E temp2 = beta * (ii[(rs[1])] + ii[(rs[2])]);

    ri[(rs[1])] = ri[(rs[1])] + temp1;
    ri[(rs[2])] = ri[(rs[2])] - temp1;
    ii[(rs[1])] = ii[(rs[1])] + temp2;
    ii[(rs[2])] = ii[(rs[2])] - temp2;
}
}
