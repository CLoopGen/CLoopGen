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
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ovs , R1 = R1 + ovs , Cr = Cr + ivs , Ci = Ci + ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T5, T8, T3, T6;
    {
        E T4, T7, T1, T2;
        // Change memory access to consecutive indexing with offset scaling
        INT idx_csr1 = csr[0] + csr[1]; // indirect precomputed index
        INT idx_csi1 = csi[0] + csi[1];
        INT idx_csr2 = csr[0] + 2*csr[1];
        
        T4 = Cr[idx_csr1];
        T5 = KP2_000000000 * T4;
        T7 = Ci[idx_csi1];
        T8 = KP2_000000000 * T7;
        T1 = Cr[0];
        T2 = Cr[idx_csr2];
        T3 = T1 + T2;
        T6 = T1 - T2;
    }
    // Use scaled strided output indexing
    R0[rs[0] + rs[1]] = T3 - T5;
    R1[rs[0] + rs[1]] = T6 + T8;
    R0[0] = T3 + T5;
    R1[0] = T6 - T8;
}
}
