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
for (i = v; i > 0; i = i - 2 , R0 = R0 + 2*ivs , R1 = R1 + 2*ivs , Cr = Cr + 2*ovs , Ci = Ci + 2*ovs) {
    E T1, T6, T4, T5, T2, T3;
    E T1b, T6b, T4b, T5b, T2b, T3b;

    T1 = R0[0];
    T6 = R0[(rs[1])];
    T2 = R1[0];
    T3 = R1[(rs[1])];
    T4 = KP707106781 * (T2 - T3);
    T5 = KP707106781 * (T2 + T3);
    Cr[(csr[1])] = T1 - T4;
    Ci[(csi[1])] = T6 - T5;
    Cr[0] = T1 + T4;
    Ci[0] = -(T5 + T6);

    T1b = R0[ivs];
    T6b = R0[(rs[1]) + ivs];
    T2b = R1[ivs];
    T3b = R1[(rs[1]) + ivs];
    T4b = KP707106781 * (T2b - T3b);
    T5b = KP707106781 * (T2b + T3b);
    Cr[(csr[1]) + ovs] = T1b - T4b;
    Ci[(csi[1]) + ovs] = T6b - T5b;
    Cr[ovs] = T1b + T4b;
    Ci[ovs] = -(T5b + T6b);
}
}
