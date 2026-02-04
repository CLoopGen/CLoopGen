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
for (m = mb , W = W + ((mb - 1) * 4); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 4 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T2, T4, T3, T5, T6, T8;
    T2 = W[0];
    T4 = W[1];
    T3 = W[2];
    T5 = W[3];
    T6 = (((T2) * (T3)) + (T4 * T5));
    T8 = ((T2 * T5) - ((T4) * (T3)));
    {
        E T1, Tp, Ta, To, Te, Tk, Th, Tl, T7, T9;
        T1 = cr[0];
        Tp = ci[0];
        T7 = cr[(rs[2])];
        T9 = ci[(rs[2])];
        Ta = (((T6) * (T7)) + (T8 * T9));
        To = ((T6 * T9) - ((T8) * (T7)));
        {
            E Tc, Td, Tf, Tg;
            Tc = cr[(rs[1])];
            Td = ci[(rs[1])];
            Te = (((T2) * (Tc)) + (T4 * Td));
            Tk = ((T2 * Td) - ((T4) * (Tc)));
            Tf = cr[(rs[3])];
            Tg = ci[(rs[3])];
            Th = (((T3) * (Tf)) + (T5 * Tg));
            Tl = ((T3 * Tg) - ((T5) * (Tf)));
        }
        {
            E Tb, Ti, Tj, Tm;
            Tb = T1 + Ta;
            Ti = Te + Th;
            ci[(rs[1])] = Tb - Ti;
            cr[0] = Tb + Ti;
            Tj = T1 - Ta;
            Tm = Tk - Tl;
            ci[0] = Tj - Tm;
            cr[(rs[1])] = Tj + Tm;
        }
        {
            E Tn, Tq, Tr, Ts;
            Tn = Tk + Tl;
            Tq = To + Tp;
            cr[(rs[2])] = Tn - Tq;
            ci[(rs[3])] = Tn + Tq;
            Tr = Th - Te;
            Ts = Tp - To;
            cr[(rs[3])] = Tr - Ts;
            ci[(rs[2])] = Tr + Ts;
        }
    }
}

}
