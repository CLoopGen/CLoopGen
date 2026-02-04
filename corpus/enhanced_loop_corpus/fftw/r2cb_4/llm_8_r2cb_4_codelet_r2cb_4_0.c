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
for (i = v; i > 0; i = i - 2 , R0 = R0 + 2*ovs , R1 = R1 + 2*ovs , Cr = Cr + 2*ivs , Ci = Ci + 2*ivs , (rs) = (rs) + 2*fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + 2*fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    E T5a, T8a, T3a, T6a;
    E T5b, T8b, T3b, T6b;
    {
        E T4a, T7a, T1a, T2a;
        E T4b, T7b, T1b, T2b;
        T4a = Cr[(csr[1])];
        T5a = KP2_000000000 * T4a;
        T7a = Ci[(csi[1])];
        T8a = KP2_000000000 * T7a;
        T1a = Cr[0];
        T2a = Cr[(csr[2])];
        T3a = T1a + T2a;
        T6a = T1a - T2a;

        T4b = (Cr + ivs)[(csr[1])];
        T5b = KP2_000000000 * T4b;
        T7b = (Ci + ivs)[(csi[1])];
        T8b = KP2_000000000 * T7b;
        T1b = Cr[ivs];
        T2b = Cr[(csr[2]) + ivs];
        T3b = T1b + T2b;
        T6b = T1b - T2b;
    }
    R0[(rs[1])] = T3a - T5a;
    R1[(rs[1])] = T6a + T8a;
    R0[0] = T3a + T5a;
    R1[0] = T6a - T8a;

    (R0 + ovs)[(rs[1])] = T3b - T5b;
    (R1 + ovs)[(rs[1])] = T6b + T8b;
    (R0 + ovs)[0] = T3b + T5b;
    (R1 + ovs)[0] = T6b - T8b;
}
}
