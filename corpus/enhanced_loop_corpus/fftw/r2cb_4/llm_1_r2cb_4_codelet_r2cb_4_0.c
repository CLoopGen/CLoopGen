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
for (i = v; i > 0; i = i - 1) {
    E T5, T8, T3, T6;
    {
        E T4, T7, T1, T2;
        T4 = Cr[(csr[1])];
        T5 = KP2_000000000 * T4;
        T7 = Ci[(csi[1])];
        T8 = KP2_000000000 * T7;
        T1 = Cr[0];
        T2 = Cr[(csr[2])];
        T3 = T1 + T2;
        T6 = T1 - T2;
    }
    R0[(rs[1])] = T3 - T5;
    R1[(rs[1])] = T6 + T8;
    R0[0] = T3 + T5;
    R1[0] = T6 - T8;

    // Simulate partial unrolling by manually duplicating body once with pointer updates
    if (i > 1) {
        i = i - 1;
        R0 = R0 + ovs;
        R1 = R1 + ovs;
        Cr = Cr + ivs;
        Ci = Ci + ivs;
        (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero;
        (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero;
        (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero;

        E T5b, T8b, T3b, T6b;
        {
            E T4b, T7b, T1b, T2b;
            T4b = Cr[(csr[1])];
            T5b = KP2_000000000 * T4b;
            T7b = Ci[(csi[1])];
            T8b = KP2_000000000 * T7b;
            T1b = Cr[0];
            T2b = Cr[(csr[2])];
            T3b = T1b + T2b;
            T6b = T1b - T2b;
        }
        R0[(rs[1])] = T3b - T5b;
        R1[(rs[1])] = T6b + T8b;
        R0[0] = T3b + T5b;
        R1[0] = T6b - T8b;
    }

    // Update pointers after each logical iteration
    R0 = R0 + ovs;
    R1 = R1 + ovs;
    Cr = Cr + ivs;
    Ci = Ci + ivs;
    (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero;
    (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero;
    (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero;
}
}
