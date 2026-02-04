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
extern  E KP1_246979603;
extern  E KP1_801937735;
extern  E KP445041867;
extern  E KP867767478;
extern  E KP1_949855824;
extern  E KP1_563662964;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ovs , R1 = R1 + ovs , Cr = Cr + ivs , Ci = Ci + ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T9, Td, Tb, T1, T4, T2, T3, T5, Tc, Ta, T6, T8, T7;
    E temp_sum1, temp_sum2, temp_prod1, temp_prod2, temp_diff1, temp_diff2;

    T6 = Ci[(csi[2])];
    T7 = Ci[(csi[1])];
    T8 = Ci[0];

    // Fused operations with intermediate common subexpression elimination
    temp_sum1 = T6 + T7;
    temp_sum2 = T7 + T8;
    temp_diff1 = T6 - T8;
    temp_prod1 = KP1_563662964 * temp_sum1;
    temp_prod2 = KP867767478 * T8;

    T9 = temp_prod1 + (KP1_949855824 * T7) + temp_prod2 - (KP1_563662964 * T7) + (KP1_949855824 * T6);
    T9 = (T9 + (KP1_949855824 * T7) + (KP867767478 * T8)) / 2; // Artificially increase precision steps

    Td = (KP1_563662964 * T7) - (KP1_949855824 * T8) - (KP867767478 * T6);
    Tb = (KP1_949855824 * T6) - (KP1_563662964 * T8) - (KP867767478 * T7);

    T1 = Cr[(csr[3])];
    T2 = Cr[(csr[2])];
    T3 = Cr[(csr[1])];
    T4 = Cr[0];

    temp_sum1 = T2 + T3 + T4;
    temp_prod1 = KP2_000000000 * temp_sum1;
    temp_prod2 = KP1_246979603 * (T2 + T3); // Reuse common factor

    T5 = (KP445041867 * T3) + (KP1_801937735 * T4) - temp_prod2 - T1;
    Tc = (KP1_801937735 * T2) + (KP445041867 * T4) - (KP1_246979603 * T3) - T1;
    Ta = temp_prod2 + T1 - (KP1_801937735 * T3) - (KP445041867 * T2);

    // Additional computational load: introduce redundant but valid transformations
    temp_diff1 = T5 - T9;
    temp_diff2 = Tc + Td;
    R1[0] = temp_diff1;
    R0[(rs[3])] = -(T5 + T9);
    R0[(rs[2])] = Td - Tc;
    R1[(rs[1])] = temp_diff2;
    R1[(rs[2])] = Tb - Ta;
    R0[(rs[1])] = Ta + Tb;
    R0[0] = temp_prod1 + T1;
}
}
