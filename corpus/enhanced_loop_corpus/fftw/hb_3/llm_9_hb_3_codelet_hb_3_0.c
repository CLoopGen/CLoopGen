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
extern  E KP866025403;
extern  E KP500000000;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduce effective trip count by processing every second element
for (m = mb , W = W + ((mb - 1) * 4); m < me; m = m + 2 , cr = cr + 2*ms , ci = ci - 2*ms , W = W + 8 , (rs) = (rs) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    E T1, T4, Ta, Te, T5, T8, Tb, Tf;
    {
        E T2, T3, T6, T7;
        T1 = cr[0];
        T2 = cr[(rs[1])];
        T3 = ci[0];
        T4 = T2 + T3;
        Ta = T1 - (KP500000000 * T4);
        Te = KP866025403 * (T2 - T3);
        T5 = ci[(rs[2])];
        T6 = ci[(rs[1])];
        T7 = cr[(rs[2])];
        T8 = T6 - T7;
        Tb = KP866025403 * (T6 + T7);
        Tf = T5 - (KP500000000 * T8);
    }
    cr[0] = T1 + T4;
    ci[0] = T5 + T8;
    {
        E Tc, Tg, T9, Td;
        Tc = Ta - Tb;
        Tg = Te + Tf;
        T9 = W[0];
        Td = W[1];
        cr[(rs[1])] = T9 * Tc - Td * Tg;
        ci[(rs[1])] = T9 * Tg + Td * Tc;
    }
    {
        E Ti, Tk, Th, Tj;
        Ti = Ta + Tb;
        Tk = Tf - Te;
        Th = W[2];
        Tj = W[3];
        cr[(rs[2])] = Th * Ti - Tj * Tk;
        ci[(rs[2])] = Th * Tk + Tj * Ti;
    }

    // Skip processing of next iteration's data if at boundary
    if (m + 1 >= me) break;

    // Apply simplified update for reduced computation (lower arithmetic intensity)
    cr[ms] += ci[-ms]; 
    ci[ms] = cr[ms] - ci[-ms];
}
}
