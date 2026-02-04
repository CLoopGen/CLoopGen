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
for (i = v; i > 0; i = i - 1 , R0 = R0 + 2*ivs , R1 = R1 + 2*ivs , Cr = Cr + 2*ovs , Ci = Ci + 2*ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1_even, T2_even, T1_odd, T2_odd;
    T1_even = R0[0];
    T2_even = R1[0];
    T1_odd = R0[ivs];
    T2_odd = R1[ivs];
    Cr[0] = T1_even + T2_even;
    Cr[ovs] = T1_odd + T2_odd;
    Cr[csr[1]] = T1_even - T2_even;
    Cr[ovs + csr[1]] = T1_odd - T2_odd;
}
}
