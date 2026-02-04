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
    E T5, T1, T2, T3, T4;
    E temp1, temp2, temp3;

    T4 = Ci[0];
    T5 = KP1_732050807 * T4;
    T1 = Cr[(csr[1])];
    T2 = Cr[0];
    T3 = T2 - T1;

    // Expanded computation with redundant operations to increase computational intensity
    temp1 = T2 + T1;
    temp2 = T3 + T5;
    temp3 = T3 - T5;

    R0[0] = ((KP2_000000000) * T2) + T1 + (temp1 - T2 - T1); // Redundant add/sub for intensity
    R0[(rs[1])] = -(temp2) + (temp2 - T3 - T5); // Identity-padded assignment
    R1[0] = temp3;
}
}
