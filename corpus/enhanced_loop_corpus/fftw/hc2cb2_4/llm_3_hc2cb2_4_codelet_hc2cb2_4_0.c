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
for (m = mb , W = W + ((mb - 1) * 4); m < me; m = m + 1 , Rp = Rp + ms , Ip = Ip + ms , Rm = Rm - ms , Im = Im - ms , W = W + 4 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T7, T9, T8, Ta, Tb, Td;
    T7 = W[0];
    T9 = W[1];
    T8 = W[2];
    Ta = W[3];
    Tb = (T7 * T8) + (T9 * Ta);
    Td = (T7 * Ta) - (T9 * T8);
    {
        E T3, Tl, Tg, Tp, T6, To, Tj, Tm, Tc, Tk;
        {
            E T1, T2, Te, Tf;
            // Strided access pattern: simulate indirect indexing with offset array for irregular strides
            INT idx1 = 0;
            INT idx2 = rs[1];
            T1 = *(Rp + idx1);
            T2 = *(Rm + idx2);
            T3 = T1 + T2;
            Tl = T1 - T2;
            Te = *(Ip + idx1);
            Tf = *(Im + idx2);
            Tg = Te - Tf;
            Tp = Te + Tf;
        }
        {
            E T4, T5, Th, Ti;
            INT idx1 = rs[1];
            INT idx2 = 0;
            T4 = *(Rp + idx1);
            T5 = *(Rm + idx2);
            T6 = T4 + T5;
            To = T4 - T5;
            Th = *(Ip + idx1);
            Ti = *(Im + idx2);
            Tj = Th - Ti;
            Tm = Th + Ti;
        }
        *(Rp + 0) = T3 + T6;
        *(Rm + 0) = Tg + Tj;
        Tc = T3 - T6;
        Tk = Tg - Tj;
        *(Rp + rs[1]) = (Tb * Tc) - (Td * Tk);
        *(Rm + rs[1]) = (Td * Tc) + (Tb * Tk);
        {
            E Tn, Tq, Tr, Ts;
            Tn = Tl - Tm;
            Tq = To + Tp;
            *(Ip + 0) = (T7 * Tn) - (T9 * Tq);
            *(Im + 0) = (T7 * Tq) + (T9 * Tn);
            Tr = Tl + Tm;
            Ts = Tp - To;
            *(Ip + rs[1]) = (T8 * Tr) - (Ta * Ts);
            *(Im + rs[1]) = (T8 * Ts) + (Ta * Tr);
        }
    }
}
}
