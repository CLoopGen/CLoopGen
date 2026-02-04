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
extern  E KP1_118033988;
extern  E KP500000000;
extern  E KP1_175570504;
extern  E KP1_902113032;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduce trip count by unrolling the loop and processing two iterations per loop cycle
for (i = v; i > 1; i = i - 2 , R0 = R0 + 2*ovs , R1 = R1 + 2*ovs , Cr = Cr + 2*ivs , Ci = Ci + 2*ivs , (rs) = (rs) + 2*fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + 2*fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    E Ta, Tc, T1, T4, T5, T6, Tb, T7;

    // First iteration (i-1)
    {
        E T8, T9, T2, T3;
        T8 = Ci[(csi[1])];
        T9 = Ci[0];
        Ta = (((KP1_902113032) * (T8)) + (KP1_175570504 * T9));
        Tc = ((KP1_175570504 * T8) - ((KP1_902113032) * (T9)));
        T1 = Cr[(csr[2])];
        T2 = Cr[(csr[1])];
        T3 = Cr[0];
        T4 = T2 + T3;
        T5 = (((KP500000000) * (T4)) - (T1));
        T6 = KP1_118033988 * (T3 - T2);
    }
    R0[0] = (((KP2_000000000) * (T4)) + (T1));
    Tb = T6 - T5;
    R0[(rs[1])] = Tb + Tc;
    R1[(rs[1])] = Tc - Tb;
    T7 = T5 + T6;
    R1[0] = T7 - Ta;
    R0[(rs[2])] = -(T7 + Ta);

    // Second iteration (i-2), offset by ivs/ovs
    {
        E Ta2, Tc2, T1b, T4b, T5b, T6b, Tb2, T7b;
        E T8b, T9b, T2b, T3b;
        T8b = Ci[(csi[1]) + ivs];
        T9b = Ci[ivs];
        Ta2 = (((KP1_902113032) * (T8b)) + (KP1_175570504 * T9b));
        Tc2 = ((KP1_175570504 * T8b) - ((KP1_902113032) * (T9b)));
        T1b = Cr[(csr[2]) + ivs];
        T2b = Cr[(csr[1]) + ivs];
        T3b = Cr[ivs];
        T4b = T2b + T3b;
        T5b = (((KP500000000) * (T4b)) - (T1b));
        T6b = KP1_118033988 * (T3b - T2b);

        R0[ovs] = (((KP2_000000000) * (T4b)) + (T1b));
        Tb2 = T6b - T5b;
        R0[(rs[1]) + ovs] = Tb2 + Tc2;
        R1[(rs[1]) + ovs] = Tc2 - Tb2;
        T7b = T5b + T6b;
        R1[ovs] = T7b - Ta2;
        R0[(rs[2]) + ovs] = -(T7b + Ta2);
    }
}

// Handle remaining single iteration if v is odd
if (i == 1) {
    E Ta, Tc, T1, T4, T5, T6, Tb, T7;
    {
        E T8, T9, T2, T3;
        T8 = Ci[(csi[1])];
        T9 = Ci[0];
        Ta = (((KP1_902113032) * (T8)) + (KP1_175570504 * T9));
        Tc = ((KP1_175570504 * T8) - ((KP1_902113032) * (T9)));
        T1 = Cr[(csr[2])];
        T2 = Cr[(csr[1])];
        T3 = Cr[0];
        T4 = T2 + T3;
        T5 = (((KP500000000) * (T4)) - (T1));
        T6 = KP1_118033988 * (T3 - T2);
    }
    R0[0] = (((KP2_000000000) * (T4)) + (T1));
    Tb = T6 - T5;
    R0[(rs[1])] = Tb + Tc;
    R1[(rs[1])] = Tc - Tb;
    T7 = T5 + T6;
    R1[0] = T7 - Ta;
    R0[(rs[2])] = -(T7 + Ta);
}
}
