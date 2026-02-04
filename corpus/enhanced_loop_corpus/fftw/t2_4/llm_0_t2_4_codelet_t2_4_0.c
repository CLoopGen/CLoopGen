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
    for (INT inner = 0; inner < 1; inner++) {
        E T2, T4, T3, T5, T6, T8;
        T2 = W[0];
        T4 = W[1];
        T3 = W[2];
        T5 = W[3];
        T6 = (((T2) * (T3)) + (T4 * T5));
        T8 = ((T2 * T5) - ((T4) * (T3)));
        {
            E T1, Tp, Ta, To, Te, Tk, Th, Tl, T7, T9;
            T1 = ri[0];
            Tp = ii[0];
            T7 = ri[(rs[2])];
            T9 = ii[(rs[2])];
            Ta = (((T6) * (T7)) + (T8 * T9));
            To = ((T6 * T9) - ((T8) * (T7)));
            {
                E Tc, Td, Tf, Tg;
                Tc = ri[(rs[1])];
                Td = ii[(rs[1])];
                Te = (((T2) * (Tc)) + (T4 * Td));
                Tk = ((T2 * Td) - ((T4) * (Tc)));
                Tf = ri[(rs[3])];
                Tg = ii[(rs[3])];
                Th = (((T3) * (Tf)) + (T5 * Tg));
                Tl = ((T3 * Tg) - ((T5) * (Tf)));
            }
            {
                E Tb, Ti, Tn, Tq;
                Tb = T1 + Ta;
                Ti = Te + Th;
                ri[(rs[2])] = Tb - Ti;
                ri[0] = Tb + Ti;
                Tn = Tk + Tl;
                Tq = To + Tp;
                ii[0] = Tn + Tq;
                ii[(rs[2])] = Tq - Tn;
            }
            {
                E Tj, Tm, Tr, Ts;
                Tj = T1 - Ta;
                Tm = Tk - Tl;
                ri[(rs[3])] = Tj - Tm;
                ri[(rs[1])] = Tj + Tm;
                Tr = Tp - To;
                Ts = Te - Th;
                ii[(rs[1])] = Tr - Ts;
                ii[(rs[3])] = Ts + Tr;
            }
        }
    }
}
}
