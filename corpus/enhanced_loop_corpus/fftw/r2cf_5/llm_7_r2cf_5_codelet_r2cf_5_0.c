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
extern  E KP250000000;
extern  E KP559016994;
extern  E KP587785252;
extern  E KP951056516;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v / 4; i > 0; i = i - 1 , R0 = R0 + 4*ivs , R1 = R1 + 4*ivs , Cr = Cr + 4*ovs , Ci = Ci + 4*ovs , (rs) = (rs) + 4*fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + 4*fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + 4*fftw_an_INT_guaranteed_to_be_zero) {
    INT j;
    for (j = 0; j < 4; ++j) {
        E Ta, T7, T8, T3, Tb, T6, T9, Tc;
        E *r0_offset = R0 + j*ivs;
        E *r1_offset = R1 + j*ivs;
        E *cr_offset = Cr + j*ovs;
        E *ci_offset = Ci + j*ovs;

        Ta = r0_offset[0];
        {
            E T1, T2, T4, T5;
            T1 = r0_offset[(rs[2])];
            T2 = r1_offset[0];
            T7 = T2 + T1;
            T4 = r0_offset[(rs[1])];
            T5 = r1_offset[(rs[1])];
            T8 = T4 + T5;
            T3 = T1 - T2;
            Tb = T7 + T8;
            T6 = T4 - T5;
        }
        ci_offset[(csi[1])] = ((KP951056516 * T3) - ((KP587785252) * (T6)));
        ci_offset[(csi[2])] = (((KP587785252) * (T3)) + (KP951056516 * T6));
        cr_offset[0] = Ta + Tb;
        T9 = KP559016994 * (T7 - T8);
        Tc = ((Ta) - ((KP250000000) * (Tb)));
        cr_offset[(csr[1])] = T9 + Tc;
        cr_offset[(csr[2])] = Tc - T9;
    }
}
}
