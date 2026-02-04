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
for (m = mb , W = W + ((mb - 1) * 6); m < me; m = m + 1 , Rp = Rp + ms , Ip = Ip + ms , Rm = Rm - ms , Im = Im - ms , W = W + 6 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    for (INT inner = 0; inner < 1; inner++) {
        E T1, Tp, T6, To, Tc, Tk, Th, Tl;
        T1 = Rp[0];
        Tp = Rm[0];
        {
            E T3, T5, T2, T4;
            T3 = Rp[(rs[1])];
            T5 = Rm[(rs[1])];
            T2 = W[2];
            T4 = W[3];
            T6 = (((T2) * (T3)) + (T4 * T5));
            To = ((T2 * T5) - ((T4) * (T3)));
        }
        {
            E T9, Tb, T8, Ta;
            T9 = Ip[0];
            Tb = Im[0];
            T8 = W[0];
            Ta = W[1];
            Tc = (((T8) * (T9)) + (Ta * Tb));
            Tk = ((T8 * Tb) - ((Ta) * (T9)));
        }
        {
            E Te, Tg, Td, Tf;
            Te = Ip[(rs[1])];
            Tg = Im[(rs[1])];
            Td = W[4];
            Tf = W[5];
            Th = (((Td) * (Te)) + (Tf * Tg));
            Tl = ((Td * Tg) - ((Tf) * (Te)));
        }
        {
            E T7, Ti, Tn, Tq;
            T7 = T1 + T6;
            Ti = Tc + Th;
            Rm[(rs[1])] = T7 - Ti;
            Rp[0] = T7 + Ti;
            Tn = Tk + Tl;
            Tq = To + Tp;
            Im[(rs[1])] = Tn - Tq;
            Ip[0] = Tn + Tq;
        }
        {
            E Tj, Tm, Tr, Ts;
            Tj = T1 - T6;
            Tm = Tk - Tl;
            Rm[0] = Tj - Tm;
            Rp[(rs[1])] = Tj + Tm;
            Tr = Th - Tc;
            Ts = Tp - To;
            Im[0] = Tr - Ts;
            Ip[(rs[1])] = Tr + Ts;
        }
    }
}
}
