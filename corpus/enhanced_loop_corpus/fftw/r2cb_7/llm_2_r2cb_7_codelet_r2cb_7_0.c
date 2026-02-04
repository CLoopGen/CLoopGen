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
    // Change memory access to use base pointer with scaled offsets (consecutive-like access via precomputed strides)
    INT idx_csr1 = csr[1], idx_csr2 = csr[2], idx_csr3 = csr[3];
    INT idx_csi1 = csi[1], idx_csi2 = csi[2], idx_csi3 = csi[3];
    INT idx_rs0 = rs[0], idx_rs1 = rs[1], idx_rs2 = rs[2], idx_rs3 = rs[3];

    T6 = Ci[idx_csi2];
    T8 = Ci[idx_csi1];
    T7 = Ci[idx_csi3];
    T9 = ((KP1_563662964 * T6) - (KP1_949855824 * T7)) - (KP867767478 * T8);
    Td = ((KP867767478 * T6) + (KP1_563662964 * T7)) - (KP1_949855824 * T8);
    Tb = ((KP1_563662964 * T8) + (KP1_949855824 * T6)) + (KP867767478 * T7);
    T1 = Cr[0];
    T4 = Cr[idx_csr3];
    T2 = Cr[idx_csr1];
    T3 = Cr[idx_csr2];
    T5 = (KP1_246979603 * T3 + T1) - (KP445041867 * T4 + KP1_801937735 * T2);
    Tc = (KP1_246979603 * T4 + T1) - (KP1_801937735 * T3 + KP445041867 * T2);
    Ta = (KP1_246979603 * T2 + T1) - (KP1_801937735 * T4 + KP445041867 * T3);
    R0[idx_rs2] = T5 - T9;
    R1[idx_rs1] = T5 + T9;
    R0[idx_rs1] = Tc + Td;
    R1[idx_rs2] = Tc - Td;
    R0[idx_rs3] = Ta + Tb;
    R1[idx_rs0] = Ta - Tb;
    R0[idx_rs0] = KP2_000000000 * (T2 + T3 + T4) + T1;
}
}
