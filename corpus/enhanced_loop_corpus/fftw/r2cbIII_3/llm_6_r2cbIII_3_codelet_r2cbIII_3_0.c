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
for (i = v; i > 0; i = i - 2 , R0 = R0 + 2*ovs , R1 = R1 + 2*ovs , Cr = Cr + 2*ivs , Ci = Ci + 2*ivs , (rs) = (rs) + 2*fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + 2*fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    E T5, T1, T2, T3, T4;
    E T10, T6, T7, T8, T9;

    // First iteration (i-th)
    T4 = Ci[0];
    T5 = KP1_732050807 * T4;
    T1 = Cr[(csr[1])];
    T2 = Cr[0];
    T3 = T2 - T1;
    R0[0] = ((KP2_000000000) * T2) + T1;
    R0[(rs[1])] = -(T3 + T5);
    R1[0] = T3 - T5;

    // Second iteration (i-1-th), offset by ivs/ovs
    T9 = Ci[ivs];
    T10 = KP1_732050807 * T9;
    T6 = Cr[ivs + (csr[1])];
    T7 = Cr[ivs];
    T8 = T7 - T6;
    R0[ovs] = ((KP2_000000000) * T7) + T6;
    R0[ovs + (rs[1])] = -(T8 + T10);
    R1[ovs] = T8 - T10;

    if (i == 1) break; // Handle odd v: avoid overrunning
}
}
