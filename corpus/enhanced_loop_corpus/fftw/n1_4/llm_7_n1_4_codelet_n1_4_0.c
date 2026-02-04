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
    E T1 = ri[0];
    E T2 = ri[(is[2])];
    E T4 = ri[(is[1])];
    E T5 = ri[(is[3])];
    E T7 = ii[0];
    E T8 = ii[(is[2])];
    E Tc = ii[(is[1])];
    E Td = ii[(is[3])];

    T3 = T1 + T2;
    Tb = T1 - T2;
    T6 = T4 + T5;
    Ta = T4 - T5;
    T9 = T7 - T8;
    Tf = T7 + T8;
    Te = Tc - Td;
    Tg = Tc + Td;

    E sum_T3_T6 = T3 + T6;
    E diff_T3_T6 = T3 - T6;
    E sum_Tf_Tg = Tf + Tg;
    E diff_Tf_Tg = Tf - Tg;
    E sum_Tb_Te = Tb + Te;
    E diff_Tb_Te = Tb - Te;
    E sum_Ta_T9 = Ta + T9;
    E diff_T9_Ta = T9 - Ta;

    ro[(os[2])] = diff_T3_T6;
    io[(os[2])] = diff_Tf_Tg;
    ro[0] = sum_T3_T6;
    io[0] = sum_Tf_Tg;
    io[(os[1])] = diff_T9_Ta;
    ro[(os[1])] = sum_Tb_Te;
    io[(os[3])] = sum_Ta_T9;
    ro[(os[3])] = diff_Tb_Te;
}
}
