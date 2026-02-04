#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *ri;
extern R *ii;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + (mb * 4); m < me; m = m + 1 , ri = ri + ms , ii = ii + ms , W = W + 4 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T2 = W[0], T4 = W[1], T3 = W[2], T5 = W[3];
    E T6 = T2 * T3 + T4 * T5;
    E T8 = T2 * T5 - T4 * T3;

    E T1 = ri[0], Tp = ii[0];
    E T7 = ri[rs[2]], T9 = ii[rs[2]];
    E Ta = T6 * T7 + T8 * T9;
    E To = T6 * T9 - T8 * T7;

    E Tc = ri[rs[1]], Td = ii[rs[1]];
    E Te = T2 * Tc + T4 * Td;
    E Tk = T2 * Td - T4 * Tc;

    E Tf = ri[rs[3]], Tg = ii[rs[3]];
    E Th = T3 * Tf + T5 * Tg;
    E Tl = T3 * Tg - T5 * Tf;

    E Tb = T1 + Ta, Ti = Te + Th;
    ri[rs[2]] = Tb - Ti;
    ri[0] = Tb + Ti;

    E Tn = Tk + Tl, Tq = To + Tp;
    ii[0] = Tn + Tq;
    ii[rs[2]] = Tq - Tn;

    E Tj = T1 - Ta, Tm = Tk - Tl;
    ri[rs[3]] = Tj - Tm;
    ri[rs[1]] = Tj + Tm;

    E Tr = Tp - To, Ts = Te - Th;
    ii[rs[1]] = Tr - Ts;
    ii[rs[3]] = Ts + Tr;

    if (m + 1 < me) {
        E T2b = W[4], T4b = W[5], T3b = W[6], T5b = W[7];
        E T6b = T2b * T3b + T4b * T5b;
        E T8b = T2b * T5b - T4b * T3b;

        E T1b = ri[ms], Tpb = ii[ms];
        E T7b = ri[ms + rs[2]], T9b = ii[ms + rs[2]];
        E Tab = T6b * T7b + T8b * T9b;
        E Tob = T6b * T9b - T8b * T7b;

        E Tcb = ri[ms + rs[1]], Tdb = ii[ms + rs[1]];
        E Teb = T2b * Tcb + T4b * Tdb;
        E Tkb = T2b * Tdb - T4b * Tcb;

        E Tfb = ri[ms + rs[3]], Tgb = ii[ms + rs[3]];
        E Thb = T3b * Tfb + T5b * Tgb;
        E Tlb = T3b * Tgb - T5b * Tfb;

        E Tbb = T1b + Tab, Tib = Teb + Thb;
        ri[ms + rs[2]] = Tbb - Tib;
        ri[ms] = Tbb + Tib;

        E Tnb = Tkb + Tlb, Tqb = Tob + Tpb;
        ii[ms] = Tnb + Tqb;
        ii[ms + rs[2]] = Tqb - Tnb;

        E Tjb = T1b - Tab, Tmb = Tkb - Tlb;
        ri[ms + rs[3]] = Tjb - Tmb;
        ri[ms + rs[1]] = Tjb + Tmb;

        E Trb = Tpb - Tob, Tsb = Teb - Thb;
        ii[ms + rs[1]] = Trb - Tsb;
        ii[ms + rs[3]] = Tsb + Trb;

        m += 1;
        ri += ms;
        ii += ms;
        W += 4;
    }
}
}
