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
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 2 , R0 = R0 + 2*ovs , R1 = R1 + 2*ovs , Cr = Cr + 2*ivs , Ci = Ci + 2*ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, T2, T3, T4;
    T1 = Cr[0];
    T2 = Cr[(csr[1])];
    T3 = Cr[ivs];
    T4 = Cr[ivs + (csr[1])];
    R1[0] = T1 - T2;
    R0[0] = T1 + T2;
    R1[ovs] = T3 - T4;
    R0[ovs] = T3 + T4;
}
}
