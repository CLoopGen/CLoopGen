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
for (i = v; i > 0; i = i - 1 , R0 += ovs , R1 += ovs , Cr += ivs , Ci += ivs) {
    E T9, Td, Tb, T1, T4, T2, T3, T5, Tc, Ta, T6, T8, T7;
    // Use indirect array indexing with precomputed offset arrays for strided access
    INT idx_ci[3], idx_cr[4];
    idx_ci[0] = 0;
    idx_ci[1] = csi[1];
    idx_ci[2] = csi[2];
    idx_cr[0] = 0;
    idx_cr[1] = csr[1];
    idx_cr[2] = csr[2];
    idx_cr[3] = csr[3];

    T6 = Ci[idx_ci[2]];
    T8 = Ci[idx_ci[0]];
    T7 = Ci[idx_ci[1]];
    T9 = (KP1_563662964 * T6 + KP1_949855824 * T7) + KP867767478 * T8;
    Td = (KP1_563662964 * T7 - KP1_949855824 * T8) - KP867767478 * T6;
    Tb = (KP1_949855824 * T6 - KP1_563662964 * T8) - KP867767478 * T7;
    T1 = Cr[idx_cr[3]];
    T4 = Cr[idx_cr[0]];
    T2 = Cr[idx_cr[2]];
    T3 = Cr[idx_cr[1]];
    T5 = (KP445041867 * T3 + KP1_801937735 * T4) - (KP1_246979603 * T2 + T1);
    Tc = (KP1_801937735 * T2 + KP445041867 * T4) - (KP1_246979603 * T3 + T1);
    Ta = (KP1_246979603 * T4 + T1) - (KP1_801937735 * T3 + KP445041867 * T2);
    R1[0] = T5 - T9;
    R0[rs[3]] = -(T5 + T9);
    R0[rs[2]] = Td - Tc;
    R1[rs[1]] = Tc + Td;
    R1[rs[2]] = Tb - Ta;
    R0[rs[1]] = Ta + Tb;
    R0[0] = KP2_000000000 * (T2 + T3 + T4) + T1;
}
}
