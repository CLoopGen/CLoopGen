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
for (m = mb , W = W + ((mb - 1) * 4); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 4 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, Ti, T6, Te, Tb, Tf, Tc, Tj;
    T1 = cr[0];
    Ti = ci[0];
    {
        E T3, T5, T2, T4;
        T3 = cr[(rs[1])];
        T5 = ci[(rs[1])];
        T2 = W[0];
        T4 = W[1];
        T6 = (((T2) * (T3)) + (T4 * T5));
        Te = ((T2 * T5) - ((T4) * (T3)));
    }
    {
        E T8, Ta, T7, T9;
        T8 = cr[(rs[2])];
        Ta = ci[(rs[2])];
        T7 = W[2];
        T9 = W[3];
        Tb = (((T7) * (T8)) + (T9 * Ta));
        Tf = ((T7 * Ta) - ((T9) * (T8)));
    }
    Tc = T6 + Tb;
    Tj = Te + Tf;
    {
        E Td, Tg, Th, Tk;
        cr[0] = T1 + Tc;
        Td = ((T1) - ((KP500000000) * (Tc)));
        Tg = KP866025403 * (Te - Tf);
        ci[0] = Td - Tg;
        cr[(rs[1])] = Td + Tg;
        ci[(rs[2])] = Tj + Ti;
        Th = KP866025403 * (Tb - T6);
        Tk = ((Ti) - ((KP500000000) * (Tj)));
        cr[(rs[2])] = Th - Tk;
        ci[(rs[1])] = Th + Tk;
    }
}

}
