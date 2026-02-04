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
    E T1, T4, Ta, Te, T5, T8, Tb, Tf;
    E Tc, Tg, Ti, Tk;
    E result_cr1_real, result_cr1_imag, result_cr2_real, result_cr2_imag;

    {
        E T2, T3, T6, T7;
        T1 = cr[0];
        T2 = cr[(rs[1])];
        T3 = ci[0];
        T4 = T2 + T3;
        Ta = ((T1) - ((KP500000000) * (T4)));
        Te = KP866025403 * (T2 - T3);
        T5 = ci[(rs[2])];
        T6 = ci[(rs[1])];
        T7 = cr[(rs[2])];
        T8 = T6 - T7;
        Tb = KP866025403 * (T6 + T7);
        Tf = ((T5) - ((KP500000000) * (T8)));
    }

    cr[0] = T1 + T4;
    ci[0] = T5 + T8;

    Tc = Ta - Tb;
    Tg = Te + Tf;
    Ti = Ta + Tb;
    Tk = Tf - Te;

    result_cr1_real = (W[0] * Tc) - (W[1] * Tg);
    result_cr1_imag = (W[0] * Tg) + (W[1] * Tc);
    result_cr2_real = (W[2] * Ti) - (W[3] * Tk);
    result_cr2_imag = (W[2] * Tk) + (W[3] * Ti);

    cr[(rs[1])] = result_cr1_real;
    ci[(rs[1])] = result_cr1_imag;
    cr[(rs[2])] = result_cr2_real;
    ci[(rs[2])] = result_cr2_imag;
}
}
