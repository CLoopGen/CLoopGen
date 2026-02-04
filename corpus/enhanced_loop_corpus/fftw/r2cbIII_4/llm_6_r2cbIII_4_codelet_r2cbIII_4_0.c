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
for (i = v; i > 0; i = i - 2 , R0 = R0 + 2*ovs , R1 = R1 + 2*ovs , Cr = Cr + 2*ivs , Ci = Ci + 2*ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12;
    // First iteration (original)
    T1 = Cr[0];
    T2 = Cr[(csr[1])];
    T3 = T1 - T2;
    T4 = Ci[0];
    T5 = Ci[(csi[1])];
    T6 = T4 + T5;
    R0[0] = KP2_000000000 * (T1 + T2);
    R0[(rs[1])] = KP2_000000000 * (T5 - T4);
    R1[0] = KP1_414213562 * (T3 - T6);
    R1[(rs[1])] = -(KP1_414213562 * (T3 + T6));

    // Second iteration (unrolled)
    T7 = Cr[ivs];
    T8 = Cr[ivs + (csr[1])];
    T9 = T7 - T8;
    T10 = Ci[ivs];
    T11 = Ci[ivs + (csi[1])];
    T12 = T10 + T11;
    R0[ovs] = KP2_000000000 * (T7 + T8);
    R0[ovs + (rs[1])] = KP2_000000000 * (T11 - T10);
    R1[ovs] = KP1_414213562 * (T9 - T12);
    R1[ovs + (rs[1])] = -(KP1_414213562 * (T9 + T12));
}
}
