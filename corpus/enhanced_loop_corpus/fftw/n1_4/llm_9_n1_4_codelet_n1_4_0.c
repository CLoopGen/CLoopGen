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
for (i = v / 2; i > 0; i = i - 1 , ri = ri + 2*ivs , ii = ii + 2*ivs , ro = ro + 2*ovs , io = io + 2*ovs , (is) = (is) + fftw_an_INT_guaranteed_to_be_zero , (os) = (os) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, Tb, T9, Tf, T6, Ta, Te, Tg;
    E S3, Sb, S9, Sf, S6, Sa, Se, Sg;

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

        E S1, S2, S7, S8;
        S1 = ri[ivs];
        S2 = ri[ivs + (is[2])];
        S3 = S1 + S2;
        Sb = S1 - S2;
        S7 = ii[ivs];
        S8 = ii[ivs + (is[2])];
        S9 = S7 - S8;
        Sf = S7 + S8;
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

        E S4, S5, Sc, Sd;
        S4 = ri[ivs + (is[1])];
        S5 = ri[ivs + (is[3])];
        S6 = S4 + S5;
        Sa = S4 - S5;
        Sc = ii[ivs + (is[1])];
        Sd = ii[ivs + (is[3])];
        Se = Sc - Sd;
        Sg = Sc + Sd;
    }

    ro[(os[2])] = T3 - T6;
    io[(os[2])] = Tf - Tg;
    ro[0] = T3 + T6;
    io[0] = Tf + Tg;
    io[(os[1])] = T9 - Ta;
    ro[(os[1])] = Tb + Te;
    io[(os[3])] = Ta + T9;
    ro[(os[3])] = Tb - Te;

    ro[ovs + (os[2])] = S3 - S6;
    io[ovs + (os[2])] = Sf - Sg;
    ro[ovs] = S3 + S6;
    io[ovs] = Sf + Sg;
    io[ovs + (os[1])] = S9 - Sa;
    ro[ovs + (os[1])] = Sb + Se;
    io[ovs + (os[3])] = Sa + S9;
    ro[ovs + (os[3])] = Sb - Se;
}
}
