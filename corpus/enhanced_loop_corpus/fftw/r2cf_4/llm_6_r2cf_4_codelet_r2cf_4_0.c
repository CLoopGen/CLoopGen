#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *R0;
extern R *R1;
extern R *Cr;
extern R *Ci;
extern stride rs;
extern stride csr;
extern stride csi;
extern INT v;
extern INT ivs;
extern INT ovs;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 2 , R0 = R0 + 2*ivs , R1 = R1 + 2*ivs , Cr = Cr + 2*ovs , Ci = Ci + 2*ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, T2, T3, T4, T5, T6, T7, T8, T9, Ta, Tb, Tc;
    E Td, Te, Tf, Tg, Th, Ti;

    if (i == 1) break;

    T1 = R0[0];
    T2 = R0[(rs[1])];
    T3 = T1 + T2;
    T4 = R1[0];
    T5 = R1[(rs[1])];
    T6 = T4 + T5;
    Cr[(csr[1])] = T1 - T2;
    Ci[(csi[1])] = T5 - T4;
    Cr[(csr[2])] = T3 - T6;
    Cr[0] = T3 + T6;

    T7 = R0[ivs];
    T8 = R0[ivs + (rs[1])];
    T9 = T7 + T8;
    Ta = R1[ivs];
    Tb = R1[ivs + (rs[1])];
    Tc = Ta + Tb;
    Cr[(csr[1]) + ovs] = T7 - T8;
    Ci[(csi[1]) + ovs] = Tb - Ta;
    Cr[(csr[2]) + ovs] = T9 - Tc;
    Cr[ovs] = T9 + Tc;
}
}
