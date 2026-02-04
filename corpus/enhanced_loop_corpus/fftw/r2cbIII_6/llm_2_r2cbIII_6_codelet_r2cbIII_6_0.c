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
    E T1, T6, T4, T5, T9, Tb, Ta, Tc;
    INT idx1_csr = csr[1], idx2_csr = csr[2];
    INT idx1_csi = csi[1], idx2_csi = csi[2];
    T1 = Cr[idx1_csr];
    T6 = Ci[idx1_csi];
    {
        E T2, T3, T7, T8;
        T2 = Cr[idx2_csr];
        T3 = Cr[0];
        T4 = T2 + T3;
        T5 = KP1_732050807 * (T2 - T3);
        T7 = Ci[idx2_csi];
        T8 = Ci[0];
        T9 = T7 + T8;
        Tb = KP1_732050807 * (T7 - T8);
    }
    R0[0] = KP2_000000000 * (T1 + T4);
    R1[rs[1]] = KP2_000000000 * (T6 - T9);
    Ta = KP2_000000000 * T6 + T9;
    R1[0] = -(T5 + Ta);
    R1[rs[2]] = T5 - Ta;
    Tc = KP2_000000000 * T1 - T4;
    R0[rs[1]] = Tb - Tc;
    R0[rs[2]] = Tc + Tb;
}
}
