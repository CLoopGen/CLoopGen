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
    {
        E T1, T2, Ta, Tb;
        T1 = Rp[0];
        T2 = Rm[(rs[1])];
        T3 = T1 + T2;
        Ti = T1 - T2;
        Ta = Ip[0];
        Tb = Im[(rs[1])];
        Tc = Ta - Tb;
        Tn = Ta + Tb;
    }
    {
        E T4, T5, Td, Te;
        T4 = Rp[(rs[1])];
        T5 = Rm[0];
        T6 = T4 + T5;
        Tm = T4 - T5;
        Td = Ip[(rs[1])];
        Te = Im[0];
        Tf = Td - Te;
        Tj = Td + Te;
    }
    Rp[0] = T3 + T6;
    Rm[0] = Tc + Tf;
    {
        E T8, Tg, T7, T9;
        T8 = T3 - T6;
        Tg = Tc - Tf;
        T7 = W[2];
        T9 = W[3];
        Rp[(rs[1])] = ((T7 * T8) - ((T9) * (Tg)));
        Rm[(rs[1])] = (((T9) * (T8)) + (T7 * Tg));
    }
    {
        E Tk, To, Th, Tl;
        Tk = Ti - Tj;
        To = Tm + Tn;
        Th = W[0];
        Tl = W[1];
        Ip[0] = ((Th * Tk) - ((Tl) * (To)));
        Im[0] = (((Th) * (To)) + (Tl * Tk));
    }
    {
        E Tq, Ts, Tp, Tr;
        Tq = Ti + Tj;
        Ts = Tn - Tm;
        Tp = W[4];
        Tr = W[5];
        Ip[(rs[1])] = ((Tp * Tq) - ((Tr) * (Ts)));
        Im[(rs[1])] = (((Tp) * (Ts)) + (Tr * Tq));
    }
}

}
