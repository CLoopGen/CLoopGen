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
for (i = v; i > 0; i = i - 2 , R0 = R0 + 2*ovs , R1 = R1 + 2*ovs , Cr = Cr + 2*ivs , Ci = Ci + 2*ivs , (rs) = (rs) + 2*fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + 2*fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    E T3, T7, Tc, Te, T6, T8, T1, T2, T9, Td;
    E T1a, T2a, T3a, T7a, Tca, Tea, T6a, T8a, T9a, Tda;

    // First element
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
    R1[(rs[1])] = (((KP2_000000000) * (T6)) + (T3));
    R0[0] = (((KP2_000000000) * (T8)) + (T7));
    T9 = T7 - T8;
    R0[(rs[2])] = T9 - Tc;
    R0[(rs[1])] = T9 + Tc;
    Td = T3 - T6;
    R1[0] = Td - Te;
    R1[(rs[2])] = Td + Te;

    // Second element (unrolled)
    if (i > 1) {
        T1a = Cr[ivs];
        T2a = Cr[ivs + (csr[3])];
        T3a = T1a - T2a;
        T7a = T1a + T2a;
        {
            E Taa, Tba, T4a, T5a;
            Taa = Ci[ivs + (csi[2])];
            Tba = Ci[ivs + (csi[1])];
            Tca = KP1_732050807 * (Taa - Tba);
            Tea = KP1_732050807 * (Taa + Tba);
            T4a = Cr[ivs + (csr[2])];
            T5a = Cr[ivs + (csr[1])];
            T6a = T4a - T5a;
            T8a = T4a + T5a;
        }
        R1[ovs + (rs[1])] = (((KP2_000000000) * (T6a)) + (T3a));
        R0[ovs] = (((KP2_000000000) * (T8a)) + (T7a));
        T9a = T7a - T8a;
        R0[ovs + (rs[2])] = T9a - Tca;
        R0[ovs + (rs[1])] = T9a + Tca;
        Tda = T3a - T6a;
        R1[ovs] = Tda - Tea;
        R1[ovs + (rs[2])] = Tda + Tea;
    }
}
}
