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
extern  E KP1_847759065;
extern  E KP765366864;
extern  E KP1_414213562;
extern  E KP2_000000000;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced computational variant: decrease trip count and simplify arithmetic
INT reduced_i = (v + 1) / 2;  // Effectively reduce iterations by half (approximate)
for (i = reduced_i; i > 0; i = i - 1 , R0 = R0 + (ovs * 2) , R1 = R1 + (ovs * 2) , Cr = Cr + (ivs * 2) , Ci = Ci + (ivs * 2) , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T6, T9, TR, TS, Ti, Tl, TD, TG;
    E T3, T5, TA, TC;

    // Simplified butterfly-like operation: only compute first and last outputs
    T3 = Cr[0] + Cr[(csr[8])];
    T5 = KP2_000000000 * Cr[(csr[4])];
    T6 = T3 + T5;
    T9 = KP2_000000000 * (Cr[(csr[2])] + Cr[(csr[6])]);

    TA = Cr[0] - Cr[(csr[8])];
    TC = KP2_000000000 * Ci[(csi[4])];
    TR = TA + TC;
    TS = KP1_414213562 * ((Cr[(csr[2])] - Cr[(csr[6])] + Ci[(csi[2])] + Ci[(csi[6])])); // Merged

    // Only write partial results to reduce memory traffic and computation
    R0[0] = T6 + T9;
    R0[(rs[4])] = T6 - T9;
    R1[(rs[1])] = TR + TS;
    R1[(rs[5])] = TR - TS;

    // Skip complex cross terms; minimal state usage
}
}
