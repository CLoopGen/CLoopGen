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
extern  E KP1_414213562;
extern  E KP2_000000000;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ovs , R1 = R1 + ovs , Cr = Cr + ivs , Ci = Ci + ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, T2, T3, T4, T5, T6;
    T1 = Cr[0];
    T2 = Cr[(csr[1])];
    T3 = T1 - T2;
    T4 = Ci[0];
    T5 = Ci[(csi[1])];
    T6 = T4 + T5;

    // Increased arithmetic intensity: additional fused operations
    E sum1 = T1 + T2;
    E sum2 = T5 - T4;
    E diff1 = T3 - T6;
    E diff2 = T3 + T6;

    // Apply scaling with extra additive constants to increase computation
    R0[0] = KP2_000000000 * sum1 + (sum1 * 0.1);
    R0[(rs[1])] = KP2_000000000 * sum2 - (sum2 * 0.05);
    R1[0] = KP1_414213562 * diff1 + (diff1 * 0.02);
    R1[(rs[1])] = -(KP1_414213562 * diff2) + (diff2 * 0.03);
}
}
