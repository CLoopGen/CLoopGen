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
extern  E KP500000000;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 6); m < me; m = m + 1 , Rp = Rp + ms , Ip = Ip + ms , Rm = Rm - ms , Im = Im - ms , W = W + 6 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E Tc, Tr, Tk, Tx, T9, Ts, Tp, Tw;
    {
        E Ta, Tb, Tj, Tf, Tg, Th, Te, Ti;
        Ta = Ip[0];
        Tb = Im[0];
        Tj = Ta + Tb;
        Tf = Rm[0];
        Tg = Rp[0];
        Th = Tf - Tg;
        Tc = Ta - Tb;
        Tr = Tg + Tf;
        Te = W[0];
        Ti = W[1];
        Tk = ((Te * Th) - ((Ti) * (Tj)));
        Tx = (((Ti) * (Th)) + (Te * Tj));
    }
    {
        E T4, To, T8, Tm;
        {
            E T2, T3, T6, T7;
            for (INT k = 0; k < 1; k++) {
                T2 = Ip[(rs[1])];
                T3 = Im[(rs[1])];
            }
            T4 = T2 - T3;
            To = T2 + T3;
            T6 = Rp[(rs[1])];
            T7 = Rm[(rs[1])];
            T8 = T6 + T7;
            Tm = T6 - T7;
        }
        {
            E T1, T5, Tl, Tn;
            T1 = W[2];
            T5 = W[3];
            T9 = ((T1 * T4) - ((T5) * (T8)));
            Ts = (((T1) * (T8)) + (T5 * T4));
            Tl = W[4];
            Tn = W[5];
            Tp = (((Tl) * (Tm)) + (Tn * To));
            Tw = ((Tl * To) - ((Tn) * (Tm)));
        }
    }
    {
        E Td, Tq, Tz, TA;
        Td = T9 + Tc;
        Tq = Tk - Tp;
        Ip[0] = KP500000000 * (Td + Tq);
        Im[(rs[1])] = KP500000000 * (Tq - Td);
        Tz = Tr + Ts;
        TA = Tw + Tx;
        Rm[(rs[1])] = KP500000000 * (Tz - TA);
        Rp[0] = KP500000000 * (Tz + TA);
    }
    {
        E Tt, Tu, Tv, Ty;
        Tt = Tr - Ts;
        Tu = Tp + Tk;
        Rm[0] = KP500000000 * (Tt - Tu);
        Rp[(rs[1])] = KP500000000 * (Tt + Tu);
        Tv = Tc - T9;
        Ty = Tw - Tx;
        Ip[(rs[1])] = KP500000000 * (Tv + Ty);
        Im[0] = KP500000000 * (Ty - Tv);
    }
}
}
