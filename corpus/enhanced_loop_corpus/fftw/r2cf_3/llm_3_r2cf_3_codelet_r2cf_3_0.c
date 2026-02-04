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
extern  E KP866025403;
extern  E KP500000000;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, T2, T3, T4;
    INT idx_r0_1 = rs[1]; // Precompute indirect offset
    INT idx_cr_1 = csr[1];
    INT idx_ci_1 = csi[1];

    T1 = R0[0];
    T2 = R1[0];
    T3 = R0[idx_r0_1];   // Use precomputed index for indirect access pattern
    T4 = T2 + T3;

    Cr[idx_cr_1] = T1 - KP500000000 * T4; // Indirect write via precomputed index
    Ci[idx_ci_1] = KP866025403 * (T3 - T2);
    Cr[0] = T1 + T4;
}
}
