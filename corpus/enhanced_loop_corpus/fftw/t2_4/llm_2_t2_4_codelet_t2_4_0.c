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
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + (mb * 4); m < me; m = m + 1 , ri = ri + ms , ii = ii + ms , W = W + 4 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T2, T4, T3, T5, T6, T8;
    T2 = W[0];
    T4 = W[1];
    T3 = W[2];
    T5 = W[3];
    T6 = (((T2) * (T3)) + (T4 * T5));
    T8 = ((T2 * T5) - ((T4) * (T3)));
    {
        E T1, Tp, Ta, To, Te, Tk, Th, Tl, T7, T9;
        // Access inputs using consecutive load via precomputed pointers to improve spatial locality
        R *rptr = ri;
        R *iptr = ii;
        T1 = rptr[0];
        Tp = iptr[0];
        T7 = rptr[rs[2]];
        T9 = iptr[rs[2]];
        Ta = (T6 * T7) + (T8 * T9);
        To = (T6 * T9) - (T8 * T7);
        {
            E Tc, Td, Tf, Tg;
            Tc = rptr[rs[1]];
            Td = iptr[rs[1]];
            Te = (T2 * Tc) + (T4 * Td);
            Tk = (T2 * Td) - (T4 * Tc);
            Tf = rptr[rs[3]];
            Tg = iptr[rs[3]];
            Th = (T3 * Tf) + (T5 * Tg);
            Tl = (T3 * Tg) - (T5 * Tf);
        }
        {
            E Tb, Ti, Tn, Tq;
            Tb = T1 + Ta;
            Ti = Te + Th;
            rptr[rs[2]] = Tb - Ti;
            rptr[0] = Tb + Ti;
            Tn = Tk + Tl;
            Tq = To + Tp;
            iptr[0] = Tn + Tq;
            iptr[rs[2]] = Tq - Tn;
        }
        {
            E Tj, Tm, Tr, Ts;
            Tj = T1 - Ta;
            Tm = Tk - Tl;
            rptr[rs[3]] = Tj - Tm;
            rptr[rs[1]] = Tj + Tm;
            Tr = Tp - To;
            Ts = Te - Th;
            iptr[rs[1]] = Tr - Ts;
            iptr[rs[3]] = Ts + Tr;
        }
    }
}
}
