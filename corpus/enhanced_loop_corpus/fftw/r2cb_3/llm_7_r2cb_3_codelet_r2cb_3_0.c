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
for (i = v / 2; i > 0; i = i - 1 , R0 = R0 + 2*ovs , R1 = R1 + 2*ovs , Cr = Cr + 2*ivs , Ci = Ci + 2*ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T5, T1, T2, T3, T4;
    E sum_real, sum_imag;

    // Reduced arithmetic intensity: combine operations and reduce writes
    T1 = Cr[0];
    T2 = Cr[(csr[1])];
    T3 = T1 - T2;
    T4 = Ci[(csi[1])];
    T5 = KP1_732050807 * T4;

    sum_real = ((KP2_000000000) * T2) + T1 + T3;
    sum_imag = T5;

    R0[0] = sum_real;
    R1[0] = sum_imag;

    // Only one write to R0 and R1 per two input elements conceptually, reduced trip count
    // Simulating lower computational intensity with fewer effective operations
}
}
