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
extern  E KP1_902113032;
extern  E KP1_175570504;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Use indirect array indexing via precomputed index arrays to modify access pattern
// Assume auxiliary index arrays are logically embedded via stride adjustments
INT idx_ci1, idx_ci2, idx_cr0, idx_cr1, idx_cr2;
for (i = v; i > 0; i = i - 1 , R0 = R0 + ovs , R1 = R1 + ovs , Cr = Cr + ivs , Ci = Ci + ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E Ta, Tc, T1, T4, T5, T6, Tb, T7;
    {
        E T8, T9, T2, T3;
        // Indirect access using dynamic index computation based on strided positions
        idx_ci1 = csi[1]; idx_ci2 = csi[2];
        idx_cr0 = 0; idx_cr1 = csr[1]; idx_cr2 = csr[2];

        T8 = Ci[idx_ci1];
        T9 = Ci[idx_ci2];
        Ta = ((KP1_175570504 * T8) - ((KP1_902113032) * (T9)));
        Tc = (((KP1_902113032) * (T8)) + (KP1_175570504 * T9));
        T1 = Cr[idx_cr0];
        T2 = Cr[idx_cr1];
        T3 = Cr[idx_cr2];
        T4 = T2 + T3;
        T5 = T1 - (KP500000000 * T4);
        T6 = KP1_118033988 * (T2 - T3);
    }
    R0[0] = (KP2_000000000 * T4) + T1;
    Tb = T6 + T5;
    R1[0] = Tb - Tc;
    R0[rs[2]] = Tb + Tc;
    T7 = T5 - T6;
    R0[rs[1]] = T7 - Ta;
    R1[rs[1]] = T7 + Ta;
}
}
