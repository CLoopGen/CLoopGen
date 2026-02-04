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
INT base_offset = (mb - 1) * 6;
for (m = mb; m < me; m = m + 1 , base_offset += 6 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E Tc, Tr, Tk, Tx, T9, Ts, Tp, Tw;
    INT offset = m * ms;
    {
        E Ta, Tb, Tj, Tf, Tg, Th, Te, Ti;
        Ta = Ip[offset];
        Tb = Im[offset];
        Tj = Ta + Tb;
        Tf = Rm[offset];
        Tg = Rp[offset];
        Th = Tf - Tg;
        Tc = Ta - Tb;
        Tr = Tg + Tf;
        Te = W[base_offset + 0];
        Ti = W[base_offset + 1];
        Tk = ((Te * Th) - (Ti * Tj));
        Tx = (Ti * Th) + (Te * Tj);
    }
    {
        E T4, To, T8, Tm;
        {
            E T2, T3, T6, T7;
            T2 = Ip[offset + ms];
            T3 = Im[offset + ms];
            T4 = T2 - T3;
            To = T2 + T3;
            T6 = Rp[offset + ms];
            T7 = Rm[offset + ms];
            T8 = T6 + T7;
            Tm = T6 - T7;
        }
        {
            E T1 = W[base_offset + 2], T5 = W[base_offset + 3];
            T9 = (T1 * T4) - (T5 * T8);
            Ts = (T1 * T8) + (T5 * T4);
            E Tl = W[base_offset + 4], Tn = W[base_offset + 5];
            Tp = (Tl * Tm) + (Tn * To);
            Tw = (Tl * To) - (Tn * Tm);
        }
    }
    {
        E Td = T9 + Tc, Tq = Tk - Tp;
        Ip[offset] = KP500000000 * (Td + Tq);
        Im[offset + ms] = KP500000000 * (Tq - Td);
        E Tz = Tr + Ts, TA = Tw + Tx;
        Rm[offset + ms] = KP500000000 * (Tz - TA);
        Rp[offset] = KP500000000 * (Tz + TA);
    }
    {
        E Tt = Tr - Ts, Tu = Tp + Tk;
        Rm[offset] = KP500000000 * (Tt - Tu);
        Rp[offset + ms] = KP500000000 * (Tt + Tu);
        E Tv = Tc - T9, Ty = Tw - Tx;
        Ip[offset + ms] = KP500000000 * (Tv + Ty);
        Im[offset] = KP500000000 * (Ty - Tv);
    }
}
}
