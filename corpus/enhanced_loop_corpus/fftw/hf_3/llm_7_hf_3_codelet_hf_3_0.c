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
for (m = mb , W = W + ((mb - 1) * 4); m < me; m = m + 2 , cr = cr + 2*ms , ci = ci - 2*ms , W = W + 8 , (rs) = (rs) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    if (m + 1 >= me) break;
    for (INT inner = 0; inner < 2; inner++) {
        E T1, Ti, T6, Te, Tb, Tf, Tc, Tj;
        T1 = cr[inner * ms];
        Ti = ci[-inner * ms];
        {
            E T3, T5, T2, T4;
            T3 = cr[inner * ms + rs[1]];
            T5 = ci[-inner * ms + rs[1]];
            T2 = W[inner * 4];
            T4 = W[inner * 4 + 1];
            T6 = T2 * T3 + T4 * T5;
            Te = T2 * T5 - T4 * T3;
        }
        {
            E T8, Ta, T7, T9;
            T8 = cr[inner * ms + rs[2]];
            Ta = ci[-inner * ms + rs[2]];
            T7 = W[inner * 4 + 2];
            T9 = W[inner * 4 + 3];
            Tb = T7 * T8 + T9 * Ta;
            Tf = T7 * Ta - T9 * T8;
        }
        Tc = T6 + Tb;
        Tj = Te + Tf;
        E Td = T1 - KP500000000 * Tc;
        E Tg = KP866025403 * (Te - Tf);
        E Th = KP866025403 * (Tb - T6);
        E Tk = Ti - KP500000000 * Tj;
        cr[inner * ms] = T1 + Tc;
        ci[-inner * ms] = Td - Tg;
        cr[inner * ms + rs[1]] = Td + Tg;
        ci[-inner * ms + rs[2]] = Tj + Ti;
        cr[inner * ms + rs[2]] = Th - Tk;
        ci[-inner * ms + rs[1]] = Th + Tk;
    }
}
}
