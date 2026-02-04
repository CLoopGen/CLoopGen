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
extern  E KP1_732050807;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ovs , R1 = R1 + ovs , Cr = Cr + ivs , Ci = Ci + ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, T7, Tc, Te, T6, T8, T1, T2, T9, Td;
    INT idx_csr2 = csr[2], idx_csr1 = csr[1], idx_csr3 = csr[3];
    INT idx_csi2 = csi[2], idx_csi1 = csi[1];
    INT idx_rs1 = rs[1], idx_rs2 = rs[2];

    T1 = Cr[0];
    T2 = Cr[idx_csr3];
    T3 = T1 - T2;
    T7 = T1 + T2;

    {
        E Ta, Tb, T4, T5;
        Ta = Ci[idx_csi2];
        Tb = Ci[idx_csi1];
        Tc = KP1_732050807 * (Ta - Tb);
        Te = KP1_732050807 * (Ta + Tb);
        T4 = Cr[idx_csr2];
        T5 = Cr[idx_csr1];
        T6 = T4 - T5;
        T8 = T4 + T5;
    }

    R1[idx_rs1] = ((KP2_000000000 * T6)) + T3;
    R0[0] = ((KP2_000000000 * T8)) + T7;
    T9 = T7 - T8;
    R0[idx_rs2] = T9 - Tc;
    R0[idx_rs1] = T9 + Tc;
    Td = T3 - T6;
    R1[0] = Td - Te;
    R1[idx_rs2] = Td + Te;
}
}
