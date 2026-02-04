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
for (i = v / 3; i > 0; i = i - 1 , ri = ri + 3*ivs , ii = ii + 3*ivs , ro = ro + 3*ovs , io = io + 3*ovs , (is) = (is) + fftw_an_INT_guaranteed_to_be_zero , (os) = (os) + fftw_an_INT_guaranteed_to_be_zero) {
    for (INT j = 0; j < 3; ++j) {
        E T1, Ta, T4, T9, T8, Tb, T5, Tc;
        E *rri = &ri[j*ivs];
        E *iii = &ii[j*ivs];
        E *rro = &ro[j*ovs];
        E *iio = &io[j*ovs];

        T1 = rri[0];
        Ta = iii[0];
        {
            E T2, T3, T6, T7;
            T2 = rri[(is[1])];
            T3 = rri[(is[2])];
            T4 = T2 + T3;
            T9 = KP866025403 * (T3 - T2);
            T6 = iii[(is[1])];
            T7 = iii[(is[2])];
            T8 = KP866025403 * (T6 - T7);
            Tb = T6 + T7;
        }
        rro[0] = T1 + T4;
        iio[0] = Ta + Tb;
        T5 = T1 - KP500000000 * T4;
        rro[(os[2])] = T5 - T8;
        rro[(os[1])] = T5 + T8;
        Tc = Ta - KP500000000 * Tb;
        iio[(os[1])] = T9 + Tc;
        iio[(os[2])] = Tc - T9;
    }
}
}
