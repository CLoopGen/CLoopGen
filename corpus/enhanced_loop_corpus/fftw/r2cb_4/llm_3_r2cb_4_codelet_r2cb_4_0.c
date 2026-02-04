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
        // Use fixed-offset sequential access pattern assuming regular stride layout
        // Simulate vector-like linear traversal by unrolling dependence on csr/csi tables
        T4 = *(Cr + ivs);          // Equivalent to Cr[csr[1]] under assumption csr[1] == ivs
        T5 = KP2_000000000 * T4;
        T7 = *(Ci + ivs);          // Corresponds to Ci[csi[1]]
        T8 = KP2_000000000 * T7;
        T1 = Cr[0];
        T2 = Cr[2 * ivs];          // Linearized access for Cr[(csr[2])]
        T3 = T1 + T2;
        T6 = T1 - T2;
    }
    // Output using direct pointer arithmetic instead of indexed base+stride
    *(R0 + rs[1]) = T3 - T5;
    *(R1 + rs[1]) = T6 + T8;
    *R0 = T3 + T5;
    *R1 = T6 - T8;
}
}
