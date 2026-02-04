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
    for (INT unroll_factor = 0; unroll_factor < 2 && m + unroll_factor < me; unroll_factor++) {
        E T7, T9, T8, Ta, Tb, Td;
        T7 = W[unroll_factor * 4 + 0];
        T9 = W[unroll_factor * 4 + 1];
        T8 = W[unroll_factor * 4 + 2];
        Ta = W[unroll_factor * 4 + 3];
        Tb = (((T7) * (T8)) + (T9 * Ta));
        Td = ((T7 * Ta) - ((T9) * (T8)));
        {
            E T3, Tl, T6, To, Tg, Tp, Tj, Tm, Tc, Tk;
            {
                E T1, T2, T4, T5;
                T1 = cr[unroll_factor * ms + 0];
                T2 = ci[(rs[1]) - unroll_factor * ms];
                T3 = T1 + T2;
                Tl = T1 - T2;
                T4 = cr[(rs[1]) + unroll_factor * ms];
                T5 = ci[0 - unroll_factor * ms];
                T6 = T4 + T5;
                To = T4 - T5;
            }
            {
                E Te, Tf, Th, Ti;
                Te = ci[(rs[3]) - unroll_factor * ms];
                Tf = cr[(rs[2]) + unroll_factor * ms];
                Tg = Te - Tf;
                Tp = Te + Tf;
                Th = ci[(rs[2]) - unroll_factor * ms];
                Ti = cr[(rs[3]) + unroll_factor * ms];
                Tj = Th - Ti;
                Tm = Th + Ti;
            }
            cr[unroll_factor * ms + 0] = T3 + T6;
            ci[0 - unroll_factor * ms] = Tg + Tj;
            Tc = T3 - T6;
            Tk = Tg - Tj;
            cr[(rs[2]) + unroll_factor * ms] = ((Tb * Tc) - ((Td) * (Tk)));
            ci[(rs[2]) - unroll_factor * ms] = (((Td) * (Tc)) + (Tb * Tk));
            {
                E Tn, Tq, Tr, Ts;
                Tn = Tl - Tm;
                Tq = To + Tp;
                cr[(rs[1]) + unroll_factor * ms] = ((T7 * Tn) - ((T9) * (Tq)));
                ci[(rs[1]) - unroll_factor * ms] = (((T7) * (Tq)) + (T9 * Tn));
                Tr = Tl + Tm;
                Ts = Tp - To;
                cr[(rs[3]) + unroll_factor * ms] = ((T8 * Tr) - ((Ta) * (Ts)));
                ci[(rs[3]) - unroll_factor * ms] = (((T8) * (Ts)) + (Ta * Tr));
            }
        }
        if (unroll_factor == 1) {
            m = m + 1;
            cr = cr + ms;
            ci = ci - ms;
            W = W + 4;
            rs = (stride)((char*)rs + fftw_an_INT_guaranteed_to_be_zero);
        }
    }
}
}
