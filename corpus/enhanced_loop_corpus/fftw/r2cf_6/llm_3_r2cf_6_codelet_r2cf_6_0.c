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
extern  E KP500000000;
extern  E KP866025403;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, Td, T9, Tc, T6, Tb, T1, T2, Ta, Te;
    INT base_r0 = 0;
    INT base_r1 = 0;
    INT stride_rs1 = rs[1];
    INT stride_rs2 = rs[2];
    INT offset_csr1 = csr[1];
    INT offset_csr2 = csr[2];
    INT offset_csr3 = csr[3];
    INT offset_csi1 = csi[1];
    INT offset_csi2 = csi[2];

    T1 = R0[base_r0];
    T2 = R1[stride_rs1];
    T3 = T1 - T2;
    Td = T1 + T2;

    {
        E T7, T8, T4, T5;
        T7 = R0[stride_rs2];
        T8 = R1[base_r1];
        T9 = T7 - T8;
        Tc = T7 + T8;
        T4 = R0[stride_rs1];
        T5 = R1[stride_rs2];
        T6 = T4 - T5;
        Tb = T4 + T5;
    }

    Ci[offset_csi1] = KP866025403 * (T9 - T6);
    Ta = T6 + T9;
    Cr[offset_csr1] = T3 - (KP500000000 * Ta);
    Cr[offset_csr3] = T3 + Ta;
    Ci[offset_csi2] = KP866025403 * (Tb - Tc);
    Te = Tb + Tc;
    Cr[offset_csr2] = Td - (KP500000000 * Te);
    Cr[0] = Td + Te;
}
}
