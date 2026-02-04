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
extern  E KP555570233;
extern  E KP831469612;
extern  E KP980785280;
extern  E KP195090322;
extern  E KP382683432;
extern  E KP923879532;
extern  E KP707106781;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced trip count and simplified operations: half the iterations with minimal computation
for (i = v; i > 0; i = i - 2, R0 = R0 + 2*ivs, R1 = R1 + 2*ivs, Cr = Cr + 2*ovs, Ci = Ci + 2*ovs) {
    E T1, T2, T3, T4;
    E x0, x4;

    // Load only essential data for reduced complexity
    x0 = R0[0];
    x4 = R0[(rs[4])];

    T1 = x0 + x4;
    T2 = x0 - x4;
    T3 = KP707106781 * (R1[(rs[2])] + R1[(rs[6])]);
    T4 = KP707106781 * (R1[(rs[2])] - R1[(rs[6])]);

    // Minimal butterfly update
    Cr[0] = T1 + T3;
    Ci[0] = T2 + T4;
    Cr[(csr[1])] = T1 - T3;
    Ci[(csi[1])] = T2 - T4;

    // Skip next element due to i -= 2
    if (--i <= 0) break;
}
}
