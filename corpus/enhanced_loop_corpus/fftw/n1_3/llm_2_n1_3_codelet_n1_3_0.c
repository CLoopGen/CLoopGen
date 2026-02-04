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
for (i = v; i > 0; i = i - 1 , ri = ri + ivs , ii = ii + ivs , ro = ro + ovs , io = io + ovs , (is) = (is) + fftw_an_INT_guaranteed_to_be_zero , (os) = (os) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, Ta, T4, T9, T8, Tb, T5, Tc;
    INT idx1 = is[1], idx2 = is[2];
    INT oidx1 = os[1], oidx2 = os[2];

    T1 = ri[0];
    Ta = ii[0];

    E T2 = ri[idx1];
    E T3 = ri[idx2];
    T4 = T2 + T3;
    T9 = KP866025403 * (T3 - T2);

    E T6 = ii[idx1];
    E T7 = ii[idx2];
    T8 = KP866025403 * (T6 - T7);
    Tb = T6 + T7;

    ro[0] = T1 + T4;
    io[0] = Ta + Tb;

    T5 = T1 - KP500000000 * T4;
    ro[oidx2] = T5 - T8;
    ro[oidx1] = T5 + T8;

    Tc = Ta - KP500000000 * Tb;
    io[oidx1] = T9 + Tc;
    io[oidx2] = Tc - T9;
}
}
