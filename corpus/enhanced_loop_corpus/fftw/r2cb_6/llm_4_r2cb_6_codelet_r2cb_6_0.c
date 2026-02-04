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
extern  E KP2_000000000;
extern  E KP1_732050807;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ovs , R1 = R1 + ovs , Cr = Cr + ivs , Ci = Ci + ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, T7, Tc, Te, T6, T8, T1, T2, T9, Td;
    T1 = Cr[0];
    T2 = Cr[(csr[3])];
    T3 = T1 - T2;
    T7 = T1 + T2;
    {
        E Ta, Tb, T4, T5;
        Ta = Ci[(csi[2])];
        Tb = Ci[(csi[1])];
        Tc = KP1_732050807 * (Ta - Tb);
        Te = KP1_732050807 * (Ta + Tb);
        T4 = Cr[(csr[2])];
        T5 = Cr[(csr[1])];
        T6 = T4 - T5;
        T8 = T4 + T5;
    }
    if (T6 != 0 || T3 != 0) {
        R1[(rs[1])] = (((KP2_000000000) * (T6)) + (T3));
        R0[0] = (((KP2_000000000) * (T8)) + (T7));
        T9 = T7 - T8;
        R0[(rs[2])] = T9 - Tc;
        R0[(rs[1])] = T9 + Tc;
        Td = T3 - T6;
        R1[0] = Td - Te;
        R1[(rs[2])] = Td + Te;
    }
}
}
