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
extern  E KP707106781;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs) {
    E T1, T6, T2, T3;
    E Tr, Ti;

    T1 = R0[0];
    T6 = R0[(rs[1])];
    T2 = R1[0];
    T3 = R1[(rs[1])];

    Tr = T2 - T3;
    Ti = T2 + T3;

    Cr[(csr[1])] = T1 - KP707106781 * Tr;
    Ci[(csi[1])] = T6 - KP707106781 * Ti;
    Cr[0] = T1 + KP707106781 * Tr;
    Ci[0] = -KP707106781 * Ti - T6;
}
}
