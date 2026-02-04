#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *Rp;
extern R *Ip;
extern R *Rm;
extern R *Im;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
E prev_T6 = 0.0, prev_T8 = 0.0;
for (m = mb , W = W + ((mb - 1) * 4); m < me; m = m + 1 , Rp = Rp + ms , Ip = Ip + ms , Rm = Rm - ms , Im = Im - ms , W = W + 4 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T2, T4, T3, T5, T6, T8;
    T2 = W[0];
    T4 = W[1];
    T3 = W[2];
    T5 = W[3];
    T6 = (((T2) * (T3)) + (T4 * T5)) + prev_T6;
    T8 = ((T2 * T5) - ((T4) * (T3))) + prev_T8;
    prev_T6 = T6;
    prev_T8 = T8;

    {
        E T1, Tp, Ta, To, Te, Tk, Th, Tl, T7, T9;
        T1 = Rp[0];
        Tp = Rm[0];
        T7 = Rp[(rs[1])];
        T9 = Rm[(rs[1])];
        Ta = (((T6) * (T7)) + (T8 * T9));
        To = ((T6 * T9) - ((T8) * (T7)));
        {
            E Tc, Td, Tf, Tg;
            Tc = Ip[0];
            Td = Im[0];
            Te = (((T2) * (Tc)) + (T4 * Td));
            Tk = ((T2 * Td) - ((T4) * (Tc)));
            Tf = Ip[(rs[1])];
            Tg = Im[(rs[1])];
            Th = (((T3) * (Tf)) + (T5 * Tg));
            Tl = ((T3 * Tg) - ((T5) * (Tf)));
        }
        {
            E Tb, Ti, Tn, Tq;
            Tb = T1 + Ta;
            Ti = Te + Th;
            Rm[(rs[1])] = Tb - Ti;
            Rp[0] = Tb + Ti;
            Tn = Tk + Tl;
            Tq = To + Tp;
            Im[(rs[1])] = Tn - Tq;
            Ip[0] = Tn + Tq;
        }
        {
            E Tj, Tm, Tr, Ts;
            Tj = T1 - Ta;
            Tm = Tk - Tl;
            Rm[0] = Tj - Tm;
            Rp[(rs[1])] = Tj + Tm;
            Tr = Th - Te;
            Ts = Tp - To;
            Im[0] = Tr - Ts;
            Ip[(rs[1])] = Tr + Ts;
        }
    }
}
}
