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
extern  E KP587785252;
extern  E KP951056516;
extern  E KP559016994;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced computational intensity: remove complex computations and lower trip count via step size increase
INT step = 2;
for (i = v; i >= step; i = i - step , R0 = R0 + ivs * step , R1 = R1 + ivs * step , Cr = Cr + ovs * step , Ci = Ci + ovs * step , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, To, T8, Tp;
    T1 = R0[0];
    To = R1[(rs[2])];

    // Simplified computation: keep only real-part contribution and skip full trigonometric evaluation
    T8 = R0[(rs[2])] + R0[(rs[3])] + R0[(rs[4])] + R0[(rs[1])]; // Sum of neighbors
    Tp = R1[0] + R1[(rs[4])] + R1[(rs[1])] + R1[(rs[3])];       // Sum of counterparts

    Cr[(csr[2])] = T1 + T8;
    Cr[0] = T1 - T8;
    Cr[(csr[1])] = Tp;
    Cr[(csr[3])] = Tp;

    Ci[(csi[2])] = Tp - To;
    Ci[0] = -(To + Tp);
    Ci[(csi[1])] = Tp - To;
    Ci[(csi[3])] = To - Tp;
}
// Handle remaining element if v is odd
if (v > 0 && (v % 2) == 1) {
    E T1 = R0[0], To = R1[(rs[2])];
    Cr[(csr[2])] = T1;
    Ci[(csi[2])] = -To;
    Cr[0] = T1;
    Ci[0] = -To;
}
}
