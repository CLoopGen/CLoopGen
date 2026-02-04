#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *rio;
extern R *iio;
extern  R *W;
extern stride rs;
extern stride vs;
extern INT mb;
extern INT me;
extern INT ms;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + (mb * 2); m < me; m = m + 2 , rio = rio + (2 * ms) , iio = iio + (2 * ms) , W = W + 4 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (vs) = (vs) + fftw_an_INT_guaranteed_to_be_zero) {
    if (m + 1 >= me) break;
    E T1, T2, T4, T6, T7, T8, T9, Ta, Tc, Te, Tf, Tg;
    E T1b, T2b, T4b, T6b, T7b, T8b, T9b, Tab, Tcb, Teb, Tfb, Tgb;

    T1 = rio[0];
    T2 = rio[(rs[1])];
    T4 = T1 - T2;
    T6 = iio[0];
    T7 = iio[(rs[1])];
    T8 = T6 - T7;
    T9 = rio[(vs[1])];
    Ta = rio[(vs[1]) + (rs[1])];
    Tc = T9 - Ta;
    Te = iio[(vs[1])];
    Tf = iio[(vs[1]) + (rs[1])];
    Tg = Te - Tf;

    T1b = rio[ms];
    T2b = rio[ms + (rs[1])];
    T4b = T1b - T2b;
    T6b = iio[ms];
    T7b = iio[ms + (rs[1])];
    T8b = T6b - T7b;
    T9b = rio[ms + (vs[1])];
    Tab = rio[ms + (vs[1]) + (rs[1])];
    Tcb = T9b - Tab;
    Teb = iio[ms + (vs[1])];
    Tfb = iio[ms + (vs[1]) + (rs[1])];
    Tgb = Teb - Tfb;

    rio[0] = T1 + T2;
    iio[0] = T6 + T7;
    rio[(rs[1])] = T9 + Ta;
    iio[(rs[1])] = Te + Tf;
    {
        E Tb, Td, T3, T5;
        Tb = W[0];
        Td = W[1];
        rio[(vs[1]) + (rs[1])] = (((Tb) * (Tc)) + (Td * Tg));
        iio[(vs[1]) + (rs[1])] = ((Tb * Tg) - ((Td) * (Tc)));
        T3 = W[0];
        T5 = W[1];
        rio[(vs[1])] = (((T3) * (T4)) + (T5 * T8));
        iio[(vs[1])] = ((T3 * T8) - ((T5) * (T4)));
    }

    rio[ms] = T1b + T2b;
    iio[ms] = T6b + T7b;
    rio[ms + (rs[1])] = T9b + Tab;
    iio[ms + (rs[1])] = Teb + Tfb;
    {
        E Tbb, Tdb, T3b, T5b;
        Tbb = W[2];
        Tdb = W[3];
        rio[ms + (vs[1]) + (rs[1])] = (((Tbb) * (Tcb)) + (Tdb * Tgb));
        iio[ms + (vs[1]) + (rs[1])] = ((Tbb * Tgb) - ((Tdb) * (Tcb)));
        T3b = W[2];
        T5b = W[3];
        rio[ms + (vs[1])] = (((T3b) * (T4b)) + (T5b * T8b));
        iio[ms + (vs[1])] = ((T3b * T8b) - ((T5b) * (T4b)));
    }
}
}
