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
INT local_v = v / 4;
for (i = local_v; i > 0; i = i - 1 , R0 = R0 + 4*ovs , R1 = R1 + 4*ovs , Cr = Cr + 4*ivs , Ci = Ci + 4*ivs , (rs) = (rs) + 4*fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + 4*fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + 4*fftw_an_INT_guaranteed_to_be_zero) {
    for (INT j = 0; j < 4; ++j) {
        E T3, T7, Tc, Te, T6, T8, T1, T2, T9, Td;
        INT idx = j * ivs;
        INT oidx = j * ovs;

        T1 = Cr[idx];
        T2 = Cr[idx + (csr[3])];
        T3 = T1 - T2;
        T7 = T1 + T2;
        {
            E Ta, Tb, T4, T5;
            Ta = Ci[idx + (csi[2])];
            Tb = Ci[idx + (csi[1])];
            Tc = KP1_732050807 * (Ta - Tb);
            Te = KP1_732050807 * (Ta + Tb);
            T4 = Cr[idx + (csr[2])];
            T5 = Cr[idx + (csr[1])];
            T6 = T4 - T5;
            T8 = T4 + T5;
        }
        R1[oidx + (rs[1])] = (((KP2_000000000) * (T6)) + (T3));
        R0[oidx] = (((KP2_000000000) * (T8)) + (T7));
        T9 = T7 - T8;
        R0[oidx + (rs[2])] = T9 - Tc;
        R0[oidx + (rs[1])] = T9 + Tc;
        Td = T3 - T6;
        R1[oidx] = Td - Te;
        R1[oidx + (rs[2])] = Td + Te;
    }
}
}
