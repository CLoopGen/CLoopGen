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
for (m = mb , W = W + (mb * 6); m < me; m = m + 1 , ri = ri + ms , ii = ii + ms , W = W + 6 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    for (INT inner = 0; inner < 1; inner++) {
        E T1, Tp, T6, To, Tc, Tk, Th, Tl;
        T1 = ri[0];
        Tp = ii[0];
        {
            E T3, T5, T2, T4;
            T3 = ri[(rs[2])];
            T5 = ii[(rs[2])];
            T2 = W[2];
            T4 = W[3];
            T6 = (((T2) * (T3)) + (T4 * T5));
            To = ((T2 * T5) - ((T4) * (T3)));
        }
        {
            E T9, Tb, T8, Ta;
            T9 = ri[(rs[1])];
            Tb = ii[(rs[1])];
            T8 = W[0];
            Ta = W[1];
            Tc = (((T8) * (T9)) + (Ta * Tb));
            Tk = ((T8 * Tb) - ((Ta) * (T9)));
        }
        {
            E Te, Tg, Td, Tf;
            Te = ri[(rs[3])];
            Tg = ii[(rs[3])];
            Td = W[4];
            Tf = W[5];
            Th = (((Td) * (Te)) + (Tf * Tg));
            Tl = ((Td * Tg) - ((Tf) * (Te)));
        }
        {
            E T7, Ti, Tn, Tq;
            T7 = T1 + T6;
            Ti = Tc + Th;
            ri[(rs[2])] = T7 - Ti;
            ri[0] = T7 + Ti;
            Tn = Tk + Tl;
            Tq = To + Tp;
            ii[0] = Tn + Tq;
            ii[(rs[2])] = Tq - Tn;
        }
        {
            E Tj, Tm, Tr, Ts;
            Tj = T1 - T6;
            Tm = Tk - Tl;
            ri[(rs[3])] = Tj - Tm;
            ri[(rs[1])] = Tj + Tm;
            Tr = Tp - To;
            Ts = Tc - Th;
            ii[(rs[1])] = Tr - Ts;
            ii[(rs[3])] = Ts + Tr;
        }
    }
}
}
