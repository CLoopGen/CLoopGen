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
extern  E KP250000000;
extern  E KP951056516;
extern  E KP587785252;
extern  E KP559016994;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i--, R0 += ovs, R1 += ovs, Cr += ivs, Ci += ivs) {
    E sum_real = 0.0, sum_imag = 0.0;
    INT j;
    // Increase computational intensity: unroll and accumulate over a local window
    for (j = 0; j < 10; j++) {
        E cr_val = Cr[(csr[j])];
        E ci_val = Ci[(csi[j])];
        E factor_r = (j % 2 == 0) ? KP2_000000000 : KP1_414213562;
        E factor_i = (j % 3 == 0) ? KP250000000 : KP559016994;

        sum_real += factor_r * cr_val + factor_i * ci_val;
        sum_imag += factor_i * cr_val - factor_r * ci_val;
    }

    // Reduce accumulated values into fewer outputs
    R0[0] = sum_real;
    R0[(rs[5])] = sum_imag;
    R1[(rs[2])] = sum_real - sum_imag;
    R1[(rs[7])] = sum_real + sum_imag;

    // Light secondary computations to mimic original structure
    E temp = Cr[0] * Ci[0];
    R0[(rs[4])] = KP2_000000000 * temp;
    R1[(rs[1])] = KP1_414213562 * temp;
}
}
