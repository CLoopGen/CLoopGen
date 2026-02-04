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
// Variant with indirect array indexing via index remapping (simulating gather-style access)
INT idx_cr1, idx_ci1, idx_r01, idx_r11;
for (i = v; i > 0; i = i - 1 , R0 = R0 + ovs , R1 = R1 + ovs , Cr = Cr + ivs , Ci = Ci + ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, T2, T3, T4, T5, T6;
    // Compute indirect indices based on strided offsets
    idx_cr1 = (csr[1]) ? ivs : 0;  // Simulate conditional strided access (could be extended)
    idx_ci1 = (csi[1]) ? ivs : 0;
    idx_r01 = (rs[1]) ? ovs : 0;
    idx_r11 = (rs[1]) ? ovs : 0;

    T1 = Cr[0];
    T2 = Cr[idx_cr1];
    T3 = T1 - T2;
    T4 = Ci[0];
    T5 = Ci[idx_ci1];
    T6 = T4 + T5;
    R0[0] = KP2_000000000 * (T1 + T2);
    R0[idx_r01] = KP2_000000000 * (T5 - T4);
    R1[0] = KP1_414213562 * (T3 - T6);
    R1[idx_r11] = -(KP1_414213562 * (T3 + T6));
}
}
