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
    // Use indirect indexing through an index array (simulating gather/scatter pattern)
    const INT * restrict idx_csr = (const INT*)csr;
    const INT * restrict idx_csi = (const INT*)csi;
    const INT * restrict idx_rs  = (const INT*)rs;

    // Gather inputs using indirect addressing
    E ci_vals[4];
    E cr_vals[4];
    ci_vals[0] = Ci[0];               // Not used directly, but for completeness
    ci_vals[1] = Ci[idx_csi[1]];
    ci_vals[2] = Ci[idx_csi[2]];
    ci_vals[3] = Ci[idx_csi[3]];

    cr_vals[0] = Cr[0];
    cr_vals[1] = Cr[idx_csr[1]];
    cr_vals[2] = Cr[idx_csr[2]];
    cr_vals[3] = Cr[idx_csr[3]];

    T6 = ci_vals[2];
    T8 = ci_vals[1];
    T7 = ci_vals[3];
    T9 = (KP1_563662964 * T6 - KP1_949855824 * T7) - KP867767478 * T8;
    Td = (KP867767478 * T6 + KP1_563662964 * T7) - KP1_949855824 * T8;
    Tb = (KP1_563662964 * T8 + KP1_949855824 * T6) + KP867767478 * T7;
    T1 = cr_vals[0];
    T4 = cr_vals[3];
    T2 = cr_vals[1];
    T3 = cr_vals[2];
    T5 = KP1_246979603 * T3 + T1 - (KP445041867 * T4 + KP1_801937735 * T2);
    Tc = KP1_246979603 * T4 + T1 - (KP1_801937735 * T3 + KP445041867 * T2);
    Ta = KP1_246979603 * T2 + T1 - (KP1_801937735 * T4 + KP445041867 * T3);

    // Scatter outputs using indirect indices
    R0[idx_rs[2]] = T5 - T9;
    R1[idx_rs[1]] = T5 + T9;
    R0[idx_rs[1]] = Tc + Td;
    R1[idx_rs[2]] = Tc - Td;
    R0[idx_rs[3]] = Ta + Tb;
    R1[idx_rs[0]] = Ta - Tb;
    R0[idx_rs[0]] = KP2_000000000 * (T2 + T3 + T4) + T1;
}
}
