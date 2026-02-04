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
extern  E KP1_118033988;
extern  E KP500000000;
extern  E KP1_175570504;
extern  E KP1_902113032;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ovs , R1 = R1 + ovs , Cr = Cr + ivs , Ci = Ci + ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E Ta, Tc, T1, T4, T5, T6, Tb, T7;
    {
        E T8, T9, T2, T3;
        // Changed access to use indirect indexing via precomputed index arrays (simulating gather-style access)
        INT idx_csi1 = csi[1], idx_csr1 = csr[1], idx_csr2 = csr[2];
        T8 = Ci[idx_csi1];
        T9 = Ci[0];
        Ta = (((KP1_902113032) * (T8)) + (KP1_175570504 * T9));
        Tc = ((KP1_175570504 * T8) - ((KP1_902113032) * (T9)));
        T1 = Cr[idx_csr2];
        T2 = Cr[idx_csr1];
        T3 = Cr[0];
        T4 = T2 + T3;
        T5 = (((KP500000000) * (T4)) - (T1));
        T6 = KP1_118033988 * (T3 - T2);
    }
    R0[0] = (((KP2_000000000) * (T4)) + (T1));
    Tb = T6 - T5;
    R0[rs[1]] = Tb + Tc;
    R1[rs[1]] = Tc - Tb;
    T7 = T5 + T6;
    R1[0] = T7 - Ta;
    R0[rs[2]] = -(T7 + Ta);
}
}
