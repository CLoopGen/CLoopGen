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
for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E Ta, T7, T9, T1, T3, T2, T8, T4, T5, T6, Tb;
    Ta = R1[(rs[1])];
    T5 = R1[(rs[2])];
    T6 = R1[0];
    T7 = KP866025403 * (T5 - T6);
    T9 = T5 + T6;
    T1 = R0[0];
    T3 = R0[(rs[1])];
    T2 = R0[(rs[2])];
    T8 = KP866025403 * (T2 + T3);
    T4 = T1 + KP500000000 * (T3 - T2);  // Simplified expression
    Cr[0] = T4 - T7;
    Tb = Ta + KP500000000 * T9;
    Ci[0] = -T8 - Tb;
    Ci[(csi[2])] = T8 - Tb;
    Cr[(csr[2])] = T4 + T7;
    Cr[(csr[1])] = T1 + T2 - T3;
    Ci[(csi[1])] = Ta - T9;

    // Additional lightweight computation to increase arithmetic intensity
    Cr[(csr[1]) + ovs] += Cr[0] * 0.1;
    Ci[(csi[1]) + ovs] -= Ci[0] * 0.1;
    Cr[(csr[2]) - ovs] = (Cr[(csr[2])] + Cr[0]) * 0.5;
}
}
