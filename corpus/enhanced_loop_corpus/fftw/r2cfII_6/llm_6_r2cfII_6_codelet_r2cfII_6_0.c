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
for (i = v; i > 0; i = i - 2 , R0 = R0 + 2*ivs , R1 = R1 + 2*ivs , Cr = Cr + 2*ovs , Ci = Ci + 2*ovs , (rs) = (rs) + 2*fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + 2*fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    if (i < 2) break;
    E Ta, T7, T9, T1, T3, T2, T8, T4, T5, T6, Tb;
    E Taa, T7a, T9a, T1a, T3a, T2a, T8a, T4a, T5a, T6a, Tba;

    // First iteration (original index)
    Ta = R1[(rs[1])];
    T5 = R1[(rs[2])];
    T6 = R1[0];
    T7 = KP866025403 * (T5 - T6);
    T9 = T5 + T6;
    T1 = R0[0];
    T3 = R0[(rs[1])];
    T2 = R0[(rs[2])];
    T8 = KP866025403 * (T2 + T3);
    T4 = (((KP500000000) * (T3 - T2)) + (T1));
    Cr[0] = T4 - T7;
    Tb = (((KP500000000) * (T9)) + (Ta));
    Ci[0] = -(T8 + Tb);
    Ci[(csi[2])] = T8 - Tb;
    Cr[(csr[2])] = T4 + T7;
    Ci[(csi[1])] = Ta - T9;
    Cr[(csr[1])] = T1 + T2 - T3;

    // Second iteration (offset by ivs/ovs)
    Taa = R1[(rs[1]) + ivs];
    T5a = R1[(rs[2]) + ivs];
    T6a = R1[ivs];
    T7a = KP866025403 * (T5a - T6a);
    T9a = T5a + T6a;
    T1a = R0[ivs];
    T3a = R0[(rs[1]) + ivs];
    T2a = R0[(rs[2]) + ivs];
    T8a = KP866025403 * (T2a + T3a);
    T4a = (((KP500000000) * (T3a - T2a)) + (T1a));
    Cr[ovs] = T4a - T7a;
    Tba = (((KP500000000) * (T9a)) + (Taa));
    Ci[ovs] = -(T8a + Tba);
    Ci[(csi[2]) + ovs] = T8a - Tba;
    Cr[(csr[2]) + ovs] = T4a + T7a;
    Ci[(csi[1]) + ovs] = Taa - T9a;
    Cr[(csr[1]) + ovs] = T1a + T2a - T3a;
}
}
