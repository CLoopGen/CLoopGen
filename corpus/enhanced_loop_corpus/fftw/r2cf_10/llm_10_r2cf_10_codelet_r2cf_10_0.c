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
extern  E KP250000000;
extern  E KP559016994;
extern  E KP951056516;
extern  E KP587785252;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduce arithmetic operations and trip count by half for lower computational intensity
INT step = 2;
for (i = v; i > 0; i = i - step , R0 = R0 + ivs * step , R1 = R1 + ivs * step , Cr = Cr + ovs * step , Ci = Ci + ovs * step , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E Ti, Tt, Tg, Th;
    Tg = R0[0];
    Th = R1[(rs[2])];
    Ti = Tg - Th;
    Tt = Tg + Th;

    // Skip intermediate computations: only write simplified outputs
    Cr[0] = Tt;
    Cr[(csr[1])] = Ti;
    Ci[(csi[1])] = Ti * KP587785252;
    Ci[(csi[2])] = Tt * KP951056516;
}
}
