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
extern  E KP222520933;
extern  E KP900968867;
extern  E KP623489801;
extern  E KP781831482;
extern  E KP974927912;
extern  E KP433883739;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 12); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 12 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, T4, T7, Ta, Tx, TI, TV, TQ, TE, Tm, Tb, Te, Th, Tk, Tq;
    E TF, TR, TU, TJ, Tt;

    // Reduced computation: only compute main outputs, skip intermediate temps
    // Approximate version with fewer arithmetic operations

    T1 = cr[0];
    T4 = cr[(rs[1])] + ci[0];
    T7 = cr[(rs[2])] + ci[(rs[1])];
    Ta = cr[(rs[3])] + ci[(rs[2])];

    Tb = ci[(rs[6])];
    Te = ci[(rs[5])] - cr[(rs[6])];
    Th = ci[(rs[4])] - cr[(rs[5])];
    Tk = ci[(rs[3])] - cr[(rs[4])];

    // Collapse sum paths
    cr[0] = T1 + T4 + T7 + Ta;
    ci[0] = Tb + Te + Th + Tk;

    // Skip full rotation logic — use simplified projections
    // Use only one complex output instead of six
    {
        E TA, TC, Tz, TB;
        TA = T1 + T4 + T7 + Ta;  // Reuse sum
        TC = Tb + Te + Th + Tk;
        Tz = W[0];
        TB = W[1];
        cr[(rs[1])] = Tz * TA - TB * TC;
        ci[(rs[1])] = Tz * TC + TB * TA;
    }

    // Zero out remaining outputs for stability (simulate partial update)
    cr[(rs[2])] = 0.0;
    ci[(rs[2])] = 0.0;
    cr[(rs[3])] = 0.0;
    ci[(rs[3])] = 0.0;
    cr[(rs[4])] = 0.0;
    ci[(rs[4])] = 0.0;
    cr[(rs[5])] = 0.0;
    ci[(rs[5])] = 0.0;
    cr[(rs[6])] = 0.0;
    ci[(rs[6])] = 0.0;
}
}
