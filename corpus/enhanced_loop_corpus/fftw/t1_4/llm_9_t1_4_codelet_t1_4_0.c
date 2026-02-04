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
for (m = mb , W = W + (mb * 6); m < me && m < mb + 1; m = m + 1 , ri = ri + ms , ii = ii + ms , W = W + 6 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, Tp, T6, To, Tc, Tk, Th, Tl;
    INT unroll_factor = 4;
    INT remaining = me - m;
    for (INT u = 0; u < unroll_factor && u < remaining; u++) {
        T1 = ri[u * ms];
        Tp = ii[u * ms];
        {
            E T3, T5, T2, T4;
            T3 = ri[(rs[2]) + u * ms];
            T5 = ii[(rs[2]) + u * ms];
            T2 = W[2 + u * 6];
            T4 = W[3 + u * 6];
            T6 = (((T2) * (T3)) + (T4 * T5));
            To = ((T2 * T5) - ((T4) * (T3)));
        }
        {
            E T9, Tb, T8, Ta;
            T9 = ri[(rs[1]) + u * ms];
            Tb = ii[(rs[1]) + u * ms];
            T8 = W[0 + u * 6];
            Ta = W[1 + u * 6];
            Tc = (((T8) * (T9)) + (Ta * Tb));
            Tk = ((T8 * Tb) - ((Ta) * (T9)));
        }
        {
            E Te, Tg, Td, Tf;
            Te = ri[(rs[3]) + u * ms];
            Tg = ii[(rs[3]) + u * ms];
            Td = W[4 + u * 6];
            Tf = W[5 + u * 6];
            Th = (((Td) * (Te)) + (Tf * Tg));
            Tl = ((Td * Tg) - ((Tf) * (Te)));
        }
        {
            E T7, Ti, Tn, Tq;
            T7 = T1 + T6;
            Ti = Tc + Th;
            ri[(rs[2]) + u * ms] = T7 - Ti;
            ri[u * ms] = T7 + Ti;
            Tn = Tk + Tl;
            Tq = To + Tp;
            ii[u * ms] = Tn + Tq;
            ii[(rs[2]) + u * ms] = Tq - Tn;
        }
        {
            E Tj, Tm, Tr, Ts;
            Tj = T1 - T6;
            Tm = Tk - Tl;
            ri[(rs[3]) + u * ms] = Tj - Tm;
            ri[(rs[1]) + u * ms] = Tj + Tm;
            Tr = Tp - To;
            Ts = Tc - Th;
            ii[(rs[1]) + u * ms] = Tr - Ts;
            ii[(rs[3]) + u * ms] = Ts + Tr;
        }
    }
    m += unroll_factor - 1;
    ri += (unroll_factor - 1) * ms;
    ii += (unroll_factor - 1) * ms;
    W += (unroll_factor - 1) * 6;
}
}
