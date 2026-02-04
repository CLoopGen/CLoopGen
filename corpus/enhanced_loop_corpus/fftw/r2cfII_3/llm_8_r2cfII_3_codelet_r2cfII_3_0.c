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
extern  E KP500000000;
extern  E KP866025403;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 2 , R0 = R0 + 2*ivs , R1 = R1 + 2*ivs , Cr = Cr + 2*ovs , Ci = Ci + 2*ovs , (rs) = (rs) + 2*fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + 2*fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    E T1, T2, T3, T4, T5, T6, T7, T8;
    E U1, U2, U3, U4;

    // First iteration unrolled
    T1 = R0[0];
    T2 = R1[0];
    T3 = R0[(rs[1])];
    T4 = T2 - T3;
    Cr[(csr[1])] = T1 - T4;
    Ci[0] = -(KP866025403 * (T2 + T3));
    Cr[0] = (((KP500000000) * (T4)) + (T1));

    // Second iteration unrolled (simulating trip count reduction via unrolling)
    T5 = R0[ivs];
    T6 = R1[ivs];
    T7 = R0[ivs + (rs[1])];
    T8 = T6 - T7;
    Cr[ovs + (csr[1])] = T5 - T8;
    Ci[ovs] = -(KP866025403 * (T6 + T7));
    Cr[ovs] = (((KP500000000) * (T8)) + (T5));
}
}
