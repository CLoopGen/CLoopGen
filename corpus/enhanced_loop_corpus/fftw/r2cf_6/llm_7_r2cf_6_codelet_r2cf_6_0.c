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
extern  E KP500000000;
extern  E KP866025403;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v / 3; i > 0; i = i - 1 , R0 = R0 + 3*ivs , R1 = R1 + 3*ivs , Cr = Cr + 3*ovs , Ci = Ci + 3*ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    // Triply unrolled version: process three iterations per loop trip
    INT j;
    for (j = 0; j < 3; j++) {
        E T1 = R0[j*ivs];
        E T2 = R1[j*ivs + (rs[1])];
        E T3 = T1 - T2;
        E Td = T1 + T2;

        E T7 = R0[j*ivs + (rs[2])];
        E T8 = R1[j*ivs];
        E T9 = T7 - T8;
        E Tc = T7 + T8;

        E T4 = R0[j*ivs + (rs[1])];
        E T5 = R1[j*ivs + (rs[2])];
        E T6 = T4 - T5;
        E Tb = T4 + T5;

        E Ta = T6 + T9;
        E Te = Tb + Tc;

        Ci[(csi[1]) + j*ovs] = KP866025403 * (T9 - T6);
        Cr[(csr[1]) + j*ovs] = T3 - (KP500000000 * Ta);
        Cr[(csr[3]) + j*ovs] = T3 + Ta;
        Ci[(csi[2]) + j*ovs] = KP866025403 * (Tb - Tc);
        Cr[(csr[2]) + j*ovs] = Td - (KP500000000 * Te);
        Cr[j*ovs] = Td + Te;
    }
}
}
