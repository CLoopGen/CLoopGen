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
extern  E KP866025403;
extern  E KP500000000;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + (mb * 4); m < me; m = m + 2 , ri = ri + (2 * ms) , ii = ii + (2 * ms) , W = W + 8 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    if (m + 1 >= me) break;
    E T1, Ti, T6, Te, Tb, Tf, Tc, Th;
    E T1b, Tib, T6b, Teb, Tbb, Tfb, Tcb, Thb;

    T1 = ri[0];
    Ti = ii[0];
    {
        E T3, T5, T2, T4;
        T3 = ri[(rs[1])];
        T5 = ii[(rs[1])];
        T2 = W[0];
        T4 = W[1];
        T6 = (((T2) * (T3)) + (T4 * T5));
        Te = ((T2 * T5) - ((T4) * (T3)));
    }
    {
        E T8, Ta, T7, T9;
        T8 = ri[(rs[2])];
        Ta = ii[(rs[2])];
        T7 = W[2];
        T9 = W[3];
        Tb = (((T7) * (T8)) + (T9 * Ta));
        Tf = ((T7 * Ta) - ((T9) * (T8)));
    }
    Tc = T6 + Tb;
    Th = Te + Tf;
    ri[0] = T1 + Tc;
    ii[0] = Th + Ti;
    {
        E Td, Tg, Tj, Tk;
        Td = ((T1) - ((KP500000000) * (Tc)));
        Tg = KP866025403 * (Te - Tf);
        ri[(rs[2])] = Td - Tg;
        ri[(rs[1])] = Td + Tg;
        Tj = KP866025403 * (Tb - T6);
        Tk = ((Ti) - ((KP500000000) * (Th)));
        ii[(rs[1])] = Tj + Tk;
        ii[(rs[2])] = Tk - Tj;
    }

    T1b = ri[ms];
    Tib = ii[ms];
    {
        E T3b, T5b, T2b, T4b;
        T3b = ri[ms + (rs[1])];
        T5b = ii[ms + (rs[1])];
        T2b = W[4];
        T4b = W[5];
        T6b = (((T2b) * (T3b)) + (T4b * T5b));
        Teb = ((T2b * T5b) - ((T4b) * (T3b)));
    }
    {
        E T8b, Tab, T7b, T9b;
        T8b = ri[ms + (rs[2])];
        Tab = ii[ms + (rs[2])];
        T7b = W[6];
        T9b = W[7];
        Tbb = (((T7b) * (T8b)) + (T9b * Tab));
        Tfb = ((T7b * Tab) - ((T9b) * (T8b)));
    }
    Tcb = T6b + Tbb;
    Thb = Teb + Tfb;
    ri[ms] = T1b + Tcb;
    ii[ms] = Thb + Tib;
    {
        E Tdb, Tgb, Tjb, Tkb;
        Tdb = ((T1b) - ((KP500000000) * (Tcb)));
        Tgb = KP866025403 * (Teb - Tfb);
        ri[ms + (rs[2])] = Tdb - Tgb;
        ri[ms + (rs[1])] = Tdb + Tgb;
        Tjb = KP866025403 * (Tbb - T6b);
        Tkb = ((Tib) - ((KP500000000) * (Thb)));
        ii[ms + (rs[1])] = Tjb + Tkb;
        ii[ms + (rs[2])] = Tkb - Tjb;
    }
}
}
