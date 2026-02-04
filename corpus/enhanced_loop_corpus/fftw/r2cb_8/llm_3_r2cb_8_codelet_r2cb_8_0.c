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
    E T5, Tg, T3, Te, T9, Ti, Td, Tj, T6, Ta;
    // Use indirect addressing through index arrays for irregular access pattern
    INT idx_c2 = csr[2], idx_c4 = csr[4], idx_c1 = csr[1], idx_c3 = csr[3];
    INT idi_c2 = csi[2], idi_c1 = csi[1], idi_c3 = csi[3];
    INT idx_r0_0 = rs[0], idx_r0_1 = rs[1], idx_r0_2 = rs[2], idx_r0_3 = rs[3];
    INT idx_r1_0 = rs[0], idx_r1_1 = rs[1], idx_r1_2 = rs[2], idx_r1_3 = rs[3];

    {
        E T4, Tf, T1, T2;
        T4 = Cr[idx_c2];
        T5 = KP2_000000000 * T4;
        Tf = Ci[idi_c2];
        Tg = KP2_000000000 * Tf;
        T1 = Cr[0];
        T2 = Cr[idx_c4];
        T3 = T1 + T2;
        Te = T1 - T2;
        {
            E T7, T8, Tb, Tc;
            T7 = Cr[idx_c1];
            T8 = Cr[idx_c3];
            T9 = KP2_000000000 * (T7 + T8);
            Ti = T7 - T8;
            Tb = Ci[idi_c1];
            Tc = Ci[idi_c3];
            Td = KP2_000000000 * (Tb - Tc);
            Tj = Tb + Tc;
        }
    }
    T6 = T3 + T5;
    R0[idx_r0_2] = T6 - T9;
    R0[idx_r0_0] = T6 + T9;
    Ta = T3 - T5;
    R0[idx_r0_1] = Ta - Td;
    R0[idx_r0_3] = Ta + Td;
    {
        E Th, Tk, Tl, Tm;
        Th = Te - Tg;
        Tk = KP1_414213562 * (Ti - Tj);
        R1[idx_r1_2] = Th - Tk;
        R1[idx_r1_0] = Th + Tk;
        Tl = Te + Tg;
        Tm = KP1_414213562 * (Ti + Tj);
        R1[idx_r1_1] = Tl - Tm;
        R1[idx_r1_3] = Tl + Tm;
    }
}
}
