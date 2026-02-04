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
extern  E KP707106781;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
INT idx_r0[4], idx_r1[4], idx_cr[5], idx_ci[4];
for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, T7, Td, Tj, T6, Tg, Ta, Ti;
    
    idx_r0[0] = 0;
    idx_r0[1] = rs[1];
    idx_r0[2] = rs[2];
    idx_r0[3] = rs[3];
    idx_r1[0] = 0;
    idx_r1[1] = rs[1];
    idx_r1[2] = rs[2];
    idx_r1[3] = rs[3];
    idx_cr[0] = 0;
    idx_cr[1] = csr[1];
    idx_cr[2] = csr[2];
    idx_cr[3] = csr[3];
    idx_cr[4] = csr[4];
    idx_ci[0] = 0;
    idx_ci[1] = csi[1];
    idx_ci[2] = csi[2];
    idx_ci[3] = csi[3];

    {
        E T1, T2, Tb, Tc;
        T1 = R0[idx_r0[0]];
        T2 = R0[idx_r0[2]];
        T3 = T1 + T2;
        T7 = T1 - T2;
        Tb = R1[idx_r1[3]];
        Tc = R1[idx_r1[1]];
        Td = Tb - Tc;
        Tj = Tb + Tc;
    }
    {
        E T4, T5, T8, T9;
        T4 = R0[idx_r0[1]];
        T5 = R0[idx_r0[3]];
        T6 = T4 + T5;
        Tg = T4 - T5;
        T8 = R1[idx_r1[0]];
        T9 = R1[idx_r1[2]];
        Ta = T8 - T9;
        Ti = T8 + T9;
    }
    Cr[idx_cr[2]] = T3 - T6;
    Ci[idx_ci[2]] = Tj - Ti;
    {
        E Te, Tf, Th, Tk;
        Te = KP707106781 * (Ta + Td);
        Cr[idx_cr[3]] = T7 - Te;
        Cr[idx_cr[1]] = T7 + Te;
        Tf = KP707106781 * (Td - Ta);
        Ci[idx_ci[1]] = Tf - Tg;
        Ci[idx_ci[3]] = Tg + Tf;
        Th = T3 + T6;
        Tk = Ti + Tj;
        Cr[idx_cr[4]] = Th - Tk;
        Cr[idx_cr[0]] = Th + Tk;
    }
}
}
