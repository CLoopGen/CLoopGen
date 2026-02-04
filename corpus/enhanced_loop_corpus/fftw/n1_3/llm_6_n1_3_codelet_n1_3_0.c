#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern  R *ri;
extern  R *ii;
extern R *ro;
extern R *io;
extern stride is;
extern stride os;
extern INT v;
extern INT ivs;
extern INT ovs;
extern  E KP500000000;
extern  E KP866025403;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 2 , ri = ri + 2*ivs , ii = ii + 2*ivs , ro = ro + 2*ovs , io = io + 2*ovs , (is) = (is) + fftw_an_INT_guaranteed_to_be_zero , (os) = (os) + fftw_an_INT_guaranteed_to_be_zero) {
    if (i < 2) break;
    E T1, Ta, T4, T9, T8, Tb, T5, Tc;
    E T1b, Tab, T4b, T9b, T8b, Tbb, T5b, Tcb;

    T1 = ri[0];
    Ta = ii[0];
    {
        E T2, T3, T6, T7;
        T2 = ri[(is[1])];
        T3 = ri[(is[2])];
        T4 = T2 + T3;
        T9 = KP866025403 * (T3 - T2);
        T6 = ii[(is[1])];
        T7 = ii[(is[2])];
        T8 = KP866025403 * (T6 - T7);
        Tb = T6 + T7;
    }
    ro[0] = T1 + T4;
    io[0] = Ta + Tb;
    T5 = T1 - KP500000000 * T4;
    ro[(os[2])] = T5 - T8;
    ro[(os[1])] = T5 + T8;
    Tc = Ta - KP500000000 * Tb;
    io[(os[1])] = T9 + Tc;
    io[(os[2])] = Tc - T9;

    T1b = ri[ivs];
    Tab = ii[ivs];
    {
        E T2b, T3b, T6b, T7b;
        T2b = ri[ivs + (is[1])];
        T3b = ri[ivs + (is[2])];
        T4b = T2b + T3b;
        T9b = KP866025403 * (T3b - T2b);
        T6b = ii[ivs + (is[1])];
        T7b = ii[ivs + (is[2])];
        T8b = KP866025403 * (T6b - T7b);
        Tbb = T6b + T7b;
    }
    ro[ovs] = T1b + T4b;
    io[ovs] = Tab + Tbb;
    T5b = T1b - KP500000000 * T4b;
    ro[ovs + (os[2])] = T5b - T8b;
    ro[ovs + (os[1])] = T5b + T8b;
    Tcb = Tab - KP500000000 * Tbb;
    io[ovs + (os[1])] = T9b + Tcb;
    io[ovs + (os[2])] = Tcb - T9b;
}
}
