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
extern  E KP951056516;
extern  E KP587785252;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 2 , R0 = R0 + 2*ivs , R1 = R1 + 2*ivs , Cr = Cr + 2*ovs , Ci = Ci + 2*ovs , (rs) = (rs) + 2*fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + 2*fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    E T8, T3, T6, T9, Tc, Tb, T7, Ta;
    E T8a, T3a, T6a, T9a, Tca, Tba, T7a, Taa;

    T8 = R0[0];
    T8a = R0[ivs];

    {
        E T1, T2, T4, T5;
        E T1a, T2a, T4a, T5a;
        T1 = R0[(rs[1])];
        T2 = R1[(rs[1])];
        T3 = T1 - T2;
        T4 = R0[(rs[2])];
        T5 = R1[0];
        T6 = T4 - T5;
        T9 = T3 + T6;
        Tc = T4 + T5;
        Tb = T1 + T2;

        T1a = R0[(rs[1]) + ivs];
        T2a = R1[(rs[1]) + ivs];
        T3a = T1a - T2a;
        T4a = R0[(rs[2]) + ivs];
        T5a = R1[ivs];
        T6a = T4a - T5a;
        T9a = T3a + T6a;
        Tca = T4a + T5a;
        Tba = T1a + T2a;
    }
    Cr[(csr[2])] = T8 + T9;
    Ci[(csi[1])] = ((KP587785252 * Tb) - ((KP951056516) * (Tc)));
    Ci[0] = -((((KP951056516) * (Tb)) + (KP587785252 * Tc)));
    T7 = KP559016994 * (T3 - T6);
    Ta = ((T8) - ((KP250000000) * (T9)));
    Cr[0] = T7 + Ta;
    Cr[(csr[1])] = Ta - T7;

    Cr[(csr[2]) + ovs] = T8a + T9a;
    Ci[(csi[1]) + ovs] = ((KP587785252 * Tba) - ((KP951056516) * (Tca)));
    Ci[ovs] = -((((KP951056516) * (Tba)) + (KP587785252 * Tca)));
    T7a = KP559016994 * (T3a - T6a);
    Taa = ((T8a) - ((KP250000000) * (T9a)));
    Cr[ovs] = T7a + Taa;
    Cr[(csr[1]) + ovs] = Taa - T7a;
}
}
