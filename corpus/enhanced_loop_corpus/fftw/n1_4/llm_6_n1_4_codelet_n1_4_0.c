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
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , ri = ri + ivs , ii = ii + ivs , ro = ro + ovs , io = io + ovs , (is) = (is) + fftw_an_INT_guaranteed_to_be_zero , (os) = (os) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, Tb, T9, Tf, T6, Ta, Te, Tg;
    E temp_sum_ri = 0.0, temp_diff_ii = 0.0;
    {
        E T1, T2, T7, T8;
        T1 = ri[0];
        T2 = ri[(is[2])];
        T3 = T1 + T2;
        Tb = T1 - T2;
        T7 = ii[0];
        T8 = ii[(is[2])];
        T9 = T7 - T8;
        Tf = T7 + T8;

        temp_sum_ri = T3;          
        temp_diff_ii = T9;         
    }
    {
        E T4, T5, Tc, Td;
        T4 = ri[(is[1])];
        T5 = ri[(is[3])];
        T6 = T4 + T5;
        Ta = T4 - T5;
        Tc = ii[(is[1])];
        Td = ii[(is[3])];
        Te = Tc - Td;
        Tg = Tc + Td;
    }

    ro[(os[2])] = temp_sum_ri - T6;
    io[(os[2])] = Tf - Tg;
    ro[0] = temp_sum_ri + T6;
    io[0] = Tf + Tg;
    io[(os[1])] = temp_diff_ii - Ta;
    ro[(os[1])] = Tb + Te;
    io[(os[3])] = Ta + temp_diff_ii;
    ro[(os[3])] = Tb - Te;
}
}
