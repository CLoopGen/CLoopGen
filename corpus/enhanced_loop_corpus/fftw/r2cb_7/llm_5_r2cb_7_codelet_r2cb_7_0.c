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
extern  E KP1_801937735;
extern  E KP445041867;
extern  E KP1_246979603;
extern  E KP867767478;
extern  E KP1_949855824;
extern  E KP1_563662964;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ovs , R1 = R1 + ovs , Cr = Cr + ivs , Ci = Ci + ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T9, Td, Tb, T1, T4, T2, T3, T5, Tc, Ta, T6, T8, T7;
    // Eliminate some loop-carried dependencies by fusing computations
    // and introducing local accumulators to reduce memory-based dependencies

    // Load all Cr and Ci values first to minimize interleaving
    T1 = Cr[0];
    T2 = Cr[(csr[1])];
    T3 = Cr[(csr[2])];
    T4 = Cr[(csr[3])];
    T6 = Ci[(csi[2])];
    T8 = Ci[(csi[1])];
    T7 = Ci[(csi[3])];

    // Group symmetric operations to expose parallelism and remove artificial dependencies
    E sum_T2_T3_T4 = T2 + T3 + T4;
    E KP_T2 = KP1_801937735 * T2;
    E KP_T3 = KP1_801937735 * T3;
    E KP_T4 = KP1_801937735 * T4;
    E KP44_T4 = KP445041867 * T4;
    E KP44_T3 = KP445041867 * T3;
    E KP44_T2 = KP445041867 * T2;

    T5 = (KP1_246979603 * T3 + T1) - (KP44_T4 + KP_T2);
    Tc = (KP1_246979603 * T4 + T1) - (KP_T3 + KP44_T2);
    Ta = (KP1_246979603 * T2 + T1) - (KP_T4 + KP44_T3);

    E KP156_T6 = KP1_563662964 * T6;
    E KP156_T7 = KP1_563662964 * T7;
    E KP156_T8 = KP1_563662964 * T8;
    E KP194_T8 = KP1_949855824 * T8;
    E KP194_T6 = KP1_949855824 * T6;
    E KP194_T7 = KP1_949855824 * T7;
    E KP867_T8 = KP867767478 * T8;
    E KP867_T7 = KP867767478 * T7;
    E KP867_T6 = KP867767478 * T6;

    T9 = KP156_T6 - KP194_T7 - KP867_T8;
    Td = KP867_T6 + KP156_T7 - KP194_T8;
    Tb = KP156_T8 + KP194_T6 + KP867_T7;

    // Enforce a strict store order to introduce new WAW-like semantics artificially
    R0[0] = KP2_000000000 * sum_T2_T3_T4 + T1;
    R0[(rs[1])] = Tc + Td;
    R0[(rs[2])] = T5 - T9;
    R0[(rs[3])] = Ta + Tb;
    R1[0] = Ta - Tb;
    R1[(rs[1])] = T5 + T9;
    R1[(rs[2])] = Tc - Td;
}
}
