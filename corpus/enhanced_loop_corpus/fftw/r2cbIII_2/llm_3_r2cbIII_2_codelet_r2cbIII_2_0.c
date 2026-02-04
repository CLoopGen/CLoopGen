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
// Change to consecutive, forward traversal with unit stride regardless of original strides
// Assume Cr and Ci are accessed consecutively in reverse order, R0 and R1 filled forward
R *base_R0 = R0;
R *base_R1 = R1;
const R *base_Cr = Cr;
const R *base_Ci = Ci;
for (i = 0; i < v; i++) {
    E T1, T2;
    // Consecutive access: use linear index from start
    T1 = base_Cr[i];
    T2 = base_Ci[i];
    base_R0[i] = KP2_000000000 * T1;
    base_R1[i] = -(KP2_000000000 * T2);
}
}
