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
extern  E KP250000000;
extern  E KP559016994;
extern  E KP587785252;
extern  E KP951056516;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 2 , R0 = R0 + 2*ivs , R1 = R1 + 2*ivs , Cr = Cr + 2*ovs , Ci = Ci + 2*ovs , (rs) = (rs) + 2*fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + 2*fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    E Ta, T7, T8, T3, Tb, T6, T9, Tc;
    E Ta2, T72, T82, T32, Tb2, T62, T92, Tc2;

    // First iteration (original)
    Ta = R0[0];
    {
        E T1, T2, T4, T5;
        T1 = R0[(rs[2])];
        T2 = R1[0];
        T7 = T2 + T1;
        T4 = R0[(rs[1])];
        T5 = R1[(rs[1])];
        T8 = T4 + T5;
        T3 = T1 - T2;
        Tb = T7 + T8;
        T6 = T4 - T5;
    }
    Ci[(csi[1])] = ((KP951056516 * T3) - ((KP587785252) * (T6)));
    Ci[(csi[2])] = (((KP587785252) * (T3)) + (KP951056516 * T6));
    Cr[0] = Ta + Tb;
    T9 = KP559016994 * (T7 - T8);
    Tc = ((Ta) - ((KP250000000) * (Tb)));
    Cr[(csr[1])] = T9 + Tc;
    Cr[(csr[2])] = Tc - T9;

    // Second iteration (unrolled)
    if (i > 1) {
        Ta2 = R0[ivs];
        {
            E T1, T2, T4, T5;
            T1 = R0[ivs + (rs[2])];
            T2 = R1[ivs];
            T72 = T2 + T1;
            T4 = R0[ivs + (rs[1])];
            T5 = R1[ivs + (rs[1])];
            T82 = T4 + T5;
            T32 = T1 - T2;
            Tb2 = T72 + T82;
            T62 = T4 - T5;
        }
        Ci[(csi[1]) + ovs] = ((KP951056516 * T32) - ((KP587785252) * (T62)));
        Ci[(csi[2]) + ovs] = (((KP587785252) * (T32)) + (KP951056516 * T62));
        Cr[ovs] = Ta2 + Tb2;
        T92 = KP559016994 * (T72 - T82);
        Tc2 = ((Ta2) - ((KP250000000) * (Tb2)));
        Cr[(csr[1]) + ovs] = T92 + Tc2;
        Cr[(csr[2]) + ovs] = Tc2 - T92;
    }
}
}
