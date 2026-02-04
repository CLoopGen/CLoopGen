#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *cr;
extern R *ci;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 4); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 4 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T7, T9, T8, Ta, Tb, Td;
    T7 = W[0];
    T9 = W[1];
    T8 = W[2];
    Ta = W[3];
    Tb = (((T7) * (T8)) + (T9 * Ta));
    Td = ((T7 * Ta) - ((T9) * (T8)));
    {
        E T3, Tl, T6, To, Tg, Tp, Tj, Tm, Tc, Tk;
        const INT s1 = rs[1], s2 = rs[2], s3 = rs[3];
        {
            E T1, T2, T4, T5;
            T1 = cr[0];
            T2 = ci[s1];
            T3 = T1 + T2;
            Tl = T1 - T2;
            T4 = cr[s1];
            T5 = ci[0];
            T6 = T4 + T5;
            To = T4 - T5;
        }
        {
            E Te, Tf, Th, Ti;
            Te = ci[s3];
            Tf = cr[s2];
            Tg = Te - Tf;
            Tp = Te + Tf;
            Th = ci[s2];
            Ti = cr[s3];
            Tj = Th - Ti;
            Tm = Th + Ti;
        }
        cr[0] = T3 + T6;
        ci[0] = Tg + Tj;
        Tc = T3 - T6;
        Tk = Tg - Tj;
        cr[s2] = ((Tb * Tc) - (Td * Tk));
        ci[s2] = ((Td * Tc) + (Tb * Tk));
        {
            E Tn, Tq, Tr, Ts;
            Tn = Tl - Tm;
            Tq = To + Tp;
            cr[s1] = (T7 * Tn) - (T9 * Tq);
            ci[s1] = (T7 * Tq) + (T9 * Tn);
            Tr = Tl + Tm;
            Ts = Tp - To;
            cr[s3] = (T8 * Tr) - (Ta * Ts);
            ci[s3] = (T8 * Ts) + (Ta * Tr);
        }
    }
}
}
