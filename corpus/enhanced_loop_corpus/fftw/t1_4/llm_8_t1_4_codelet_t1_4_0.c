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
for (m = mb , W = W + (mb * 6); m < me; m = m + 2 , ri = ri + (2 * ms) , ii = ii + (2 * ms) , W = W + 12 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    if (m + 1 >= me) break;
    E T1, Tp, T6, To, Tc, Tk, Th, Tl;
    E T1b, Tpb, T6b, Tob, Tcb, Tkb, Thb, Tlb;

    T1 = ri[0];
    Tp = ii[0];
    T1b = ri[ms];
    Tpb = ii[ms];

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

    {
        E T3, T5, T2, T4;
        T3 = ri[(rs[2]) + ms];
        T5 = ii[(rs[2]) + ms];
        T2 = W[8];
        T4 = W[9];
        T6b = (((T2) * (T3)) + (T4 * T5));
        Tob = ((T2 * T5) - ((T4) * (T3)));
    }
    {
        E T9, Tb, T8, Ta;
        T9 = ri[(rs[1]) + ms];
        Tb = ii[(rs[1]) + ms];
        T8 = W[6];
        Ta = W[7];
        Tcb = (((T8) * (T9)) + (Ta * Tb));
        Tkb = ((T8 * Tb) - ((Ta) * (T9)));
    }
    {
        E Te, Tg, Td, Tf;
        Te = ri[(rs[3]) + ms];
        Tg = ii[(rs[3]) + ms];
        Td = W[10];
        Tf = W[11];
        Thb = (((Td) * (Te)) + (Tf * Tg));
        Tlb = ((Td * Tg) - ((Tf) * (Te)));
    }
    {
        E T7, Ti, Tn, Tq;
        T7 = T1b + T6b;
        Ti = Tcb + Thb;
        ri[(rs[2]) + ms] = T7 - Ti;
        ri[ms] = T7 + Ti;
        Tn = Tkb + Tlb;
        Tq = Tob + Tpb;
        ii[ms] = Tn + Tq;
        ii[(rs[2]) + ms] = Tq - Tn;
    }
    {
        E Tj, Tm, Tr, Ts;
        Tj = T1b - T6b;
        Tm = Tkb - Tlb;
        ri[(rs[3]) + ms] = Tj - Tm;
        ri[(rs[1]) + ms] = Tj + Tm;
        Tr = Tpb - Tob;
        Ts = Tcb - Thb;
        ii[(rs[1]) + ms] = Tr - Ts;
        ii[(rs[3]) + ms] = Ts + Tr;
    }
}
}
