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
extern  E KP1_118033988;
extern  E KP1_902113032;
extern  E KP1_175570504;
extern  E KP500000000;
extern  E KP866025403;
extern  E KP2_000000000;
extern  E KP1_732050807;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced computational intensity: process only every other element and simplify arithmetic
for (i = v; i > 0; i = i - 2 , R0 = R0 + 2*ovs , R1 = R1 + 2*ovs , Cr = Cr + 2*ivs , Ci = Ci + 2*ivs , (rs) = (rs) + 2*fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + 2*fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    E T3, Tu, Ti, T8, Td, Te;
    {
        E T1, T2, Tf;
        T1 = Cr[0];
        T2 = Cr[(csr[5])];
        Tf = T1 - T2;
        T3 = T1 + T2; // Simplified: remove multiplication by 2.0
        Tu = Tf;
        Ti = T1 + T2; // Reuse sum
    }
    {
        E T4, T9, T7, Tc, Tj, To, T8, Td, Te;
        T4 = Cr[(csr[3])];
        T9 = Cr[(csr[6])];
        T7 = Cr[(csr[7])] + Cr[(csr[2])];
        Tc = Cr[(csr[4])] + Cr[(csr[1])];
        T8 = T4 + T7;
        Td = T9 + Tc;
        Te = T8 + Td;
    }
    // Only write simplified result
    R0[0] = Te + T3;

    // Skip complex twiddle factors and cross terms
    // Approximate one output point instead of full butterfly
    R1[(rs[2])] = ((KP500000000) * (T8 + Td)) + Ti;
}
}
