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
    E T3, Ti, Tc, Tn, T6, Tm, Tf, Tj;
    INT idx1 = 0;
    INT idx2 = rs[1];
    {
        E T1, T2, Ta, Tb;
        T1 = Rp[idx1];
        T2 = Rm[idx2];
        T3 = T1 + T2;
        Ti = T1 - T2;
        Ta = Ip[idx1];
        Tb = Im[idx2];
        Tc = Ta - Tb;
        Tn = Ta + Tb;
    }
    {
        E T4, T5, Td, Te;
        T4 = Rp[idx2];
        T5 = Rm[idx1];
        T6 = T4 + T5;
        Tm = T4 - T5;
        Td = Ip[idx2];
        Te = Im[idx1];
        Tf = Td - Te;
        Tj = Td + Te;
    }
    Rp[idx1] = T3 + T6;
    Rm[idx1] = Tc + Tf;
    {
        E T8, Tg, T7, T9;
        T8 = T3 - T6;
        Tg = Tc - Tf;
        T7 = W[2];
        T9 = W[3];
        Rp[idx2] = ((T7 * T8) - ((T9) * (Tg)));
        Rm[idx2] = (((T9) * (T8)) + (T7 * Tg));
    }
    {
        E Tk, To, Th, Tl;
        Tk = Ti - Tj;
        To = Tm + Tn;
        Th = W[0];
        Tl = W[1];
        Ip[idx1] = ((Th * Tk) - ((Tl) * (To)));
        Im[idx1] = (((Th) * (To)) + (Tl * Tk));
    }
    {
        E Tq, Ts, Tp, Tr;
        Tq = Ti + Tj;
        Ts = Tn - Tm;
        Tp = W[4];
        Tr = W[5];
        Ip[idx2] = ((Tp * Tq) - ((Tr) * (Ts)));
        Im[idx2] = (((Tp) * (Ts)) + (Tr * Tq));
    }
}
}
