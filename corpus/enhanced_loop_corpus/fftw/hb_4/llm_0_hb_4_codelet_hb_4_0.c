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
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 6); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 6 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, Ti, T6, Tm, Tc, Tn, Tf, Tj;
    for (INT inner = 0; inner < 1; inner++) {
        {
            E T1, T2, T4, T5;
            T1 = cr[0];
            T2 = ci[(rs[1])];
            T3 = T1 + T2;
            Ti = T1 - T2;
            T4 = cr[(rs[1])];
            T5 = ci[0];
            T6 = T4 + T5;
            Tm = T4 - T5;
        }
        {
            E Ta, Tb, Td, Te;
            Ta = ci[(rs[3])];
            Tb = cr[(rs[2])];
            Tc = Ta - Tb;
            Tn = Ta + Tb;
            Td = ci[(rs[2])];
            Te = cr[(rs[3])];
            Tf = Td - Te;
            Tj = Td + Te;
        }
    }
    cr[0] = T3 + T6;
    ci[0] = Tc + Tf;
    {
        E T8, Tg, T7, T9;
        T8 = T3 - T6;
        Tg = Tc - Tf;
        T7 = W[2];
        T9 = W[3];
        cr[(rs[2])] = ((T7 * T8) - ((T9) * (Tg)));
        ci[(rs[2])] = (((T9) * (T8)) + (T7 * Tg));
    }
    {
        E Tk, To, Th, Tl;
        Tk = Ti - Tj;
        To = Tm + Tn;
        Th = W[0];
        Tl = W[1];
        cr[(rs[1])] = ((Th * Tk) - ((Tl) * (To)));
        ci[(rs[1])] = (((Th) * (To)) + (Tl * Tk));
    }
    {
        E Tq, Ts, Tp, Tr;
        Tq = Ti + Tj;
        Ts = Tn - Tm;
        Tp = W[4];
        Tr = W[5];
        cr[(rs[3])] = ((Tp * Tq) - ((Tr) * (Ts)));
        ci[(rs[3])] = (((Tp) * (Ts)) + (Tr * Tq));
    }
}
}
