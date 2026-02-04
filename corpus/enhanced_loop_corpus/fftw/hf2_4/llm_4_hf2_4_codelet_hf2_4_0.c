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
    E w_vals[4];
    for (INT i = 0; i < 4; ++i) w_vals[i] = W[i];
    E T2 = w_vals[0], T4 = w_vals[1], T3 = w_vals[2], T5 = w_vals[3];
    E T6 = (T2 * T3) + (T4 * T5);
    E T8 = (T2 * T5) - (T4 * T3);
    {
        E cr_vals[4], ci_vals[4];
        cr_vals[0] = cr[0];
        ci_vals[0] = ci[0];
        cr_vals[1] = cr[rs[1]];
        ci_vals[1] = ci[rs[1]];
        cr_vals[2] = cr[rs[2]];
        ci_vals[2] = ci[rs[2]];
        cr_vals[3] = cr[rs[3]];
        ci_vals[3] = ci[rs[3]];

        E T1 = cr_vals[0], Tp = ci_vals[0], T7 = cr_vals[2], T9 = ci_vals[2];
        E Ta = (T6 * T7) + (T8 * T9);
        E To = (T6 * T9) - (T8 * T7);

        E Tc = cr_vals[1], Td = ci_vals[1], Tf = cr_vals[3], Tg = ci_vals[3];
        E Te = (T2 * Tc) + (T4 * Td);
        E Tk = (T2 * Td) - (T4 * Tc);
        E Th = (T3 * Tf) + (T5 * Tg);
        E Tl = (T3 * Tg) - (T5 * Tf);

        E Tb = T1 + Ta, Ti = Te + Th;
        ci[rs[1]] = Tb - Ti;
        cr[0]     = Tb + Ti;

        E Tj = T1 - Ta, Tm = Tk - Tl;
        ci[0]      = Tj - Tm;
        cr[rs[1]]  = Tj + Tm;

        E Tn = Tk + Tl, Tq = To + Tp;
        cr[rs[2]] = Tn - Tq;
        ci[rs[3]] = Tn + Tq;

        E Tr = Th - Te, Ts = Tp - To;
        cr[rs[3]] = Tr - Ts;
        ci[rs[2]] = Tr + Ts;
    }
}
}
