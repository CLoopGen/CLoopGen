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
for (m = mb , W = W + ((mb - 1) * 6); m < me; m = m + 2 , cr = cr + (2 * ms) , ci = ci - (2 * ms) , W = W + 12 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    if (m + 1 >= me) break;
    E T3, Ti, T6, Tm, Tc, Tn, Tf, Tj;
    E T3b, Tib, T6b, Tmb, Tcb, Tnb, Tfb, Tjb;

    {
        E T1, T2, T4, T5;
        T1 = cr[0];
        T2 = ci[(rs[1])];
        T3 = T1 + T2;
        Ti = T1 - T2;
        T4 = cr[(rs[1])];
        T5 = ci[0];
        T6 = T4 + T5;
        Tm = T4 - T5;
    }
    {
        E Ta, Tb, Td, Te;
        Ta = ci[(rs[3])];
        Tb = cr[(rs[2])];
        Tc = Ta - Tb;
        Tn = Ta + Tb;
        Td = ci[(rs[2])];
        Te = cr[(rs[3])];
        Tf = Td - Te;
        Tj = Td + Te;
    }
    cr[0] = T3 + T6;
    ci[0] = Tc + Tf;

    {
        E T8, Tg, T7, T9;
        T8 = T3 - T6;
        Tg = Tc - Tf;
        T7 = W[2];
        T9 = W[3];
        cr[(rs[2])] = ((T7 * T8) - ((T9) * (Tg)));
        ci[(rs[2])] = (((T9) * (T8)) + (T7 * Tg));
    }
    {
        E Tk, To, Th, Tl;
        Tk = Ti - Tj;
        To = Tm + Tn;
        Th = W[0];
        Tl = W[1];
        cr[(rs[1])] = ((Th * Tk) - ((Tl) * (To)));
        ci[(rs[1])] = (((Th) * (To)) + (Tl * Tk));
    }
    {
        E Tq, Ts, Tp, Tr;
        Tq = Ti + Tj;
        Ts = Tn - Tm;
        Tp = W[4];
        Tr = W[5];
        cr[(rs[3])] = ((Tp * Tq) - ((Tr) * (Ts)));
        ci[(rs[3])] = (((Tp) * (Ts)) + (Tr * Tq));
    }

    {
        E T1b, T2b, T4b, T5b;
        T1b = cr[ms];
        T2b = ci[(rs[1]) + ms];
        T3b = T1b + T2b;
        Tib = T1b - T2b;
        T4b = cr[(rs[1]) + ms];
        T5b = ci[ms];
        T6b = T4b + T5b;
        Tmb = T4b - T5b;
    }
    {
        E Tab, Tbb, Tdb, Teb;
        Tab = ci[(rs[3]) + ms];
        Tbb = cr[(rs[2]) + ms];
        Tcb = Tab - Tbb;
        Tnb = Tab + Tbb;
        Tdb = ci[(rs[2]) + ms];
        Teb = cr[(rs[3]) + ms];
        Tfb = Tdb - Teb;
        Tjb = Tdb + Teb;
    }
    cr[ms] = T3b + T6b;
    ci[ms] = Tcb + Tfb;

    {
        E T8b, Tgb, T7b, T9b;
        T8b = T3b - T6b;
        Tgb = Tcb - Tfb;
        T7b = W[8];
        T9b = W[9];
        cr[(rs[2]) + ms] = ((T7b * T8b) - ((T9b) * (Tgb)));
        ci[(rs[2]) + ms] = (((T9b) * (T8b)) + (T7b * Tgb));
    }
    {
        E Tkb, Tob, Thb, Tlb;
        Tkb = Tib - Tjb;
        Tob = Tmb + Tnb;
        Thb = W[6];
        Tlb = W[7];
        cr[(rs[1]) + ms] = ((Thb * Tkb) - ((Tlb) * (Tob)));
        ci[(rs[1]) + ms] = (((Thb) * (Tob)) + (Tlb * Tkb));
    }
    {
        E Tqb, Tsb, Tpb, Trb;
        Tqb = Tib + Tjb;
        Tsb = Tnb - Tmb;
        Tpb = W[10];
        Trb = W[11];
        cr[(rs[3]) + ms] = ((Tpb * Tqb) - ((Trb) * (Tsb)));
        ci[(rs[3]) + ms] = (((Tpb) * (Tsb)) + (Trb * Tqb));
    }
}
}
