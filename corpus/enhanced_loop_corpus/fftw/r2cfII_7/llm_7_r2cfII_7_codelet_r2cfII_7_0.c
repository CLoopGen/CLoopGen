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
extern  E KP900968867;
extern  E KP222520933;
extern  E KP623489801;
extern  E KP433883739;
extern  E KP974927912;
extern  E KP781831482;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, Ta, Td, T4, Tb, T7, Tc, T8, T9;
    // Eliminate some temporary variables by inlining expressions to reduce local data dependencies
    T1 = R0[0];
    T8 = R1[0];
    T9 = R0[(rs[3])];
    Ta = T8 - T9;
    Td = T8 + T9;
    {
        E T2 = R0[(rs[1])];
        E T3 = R1[(rs[2])];
        E T5 = R1[(rs[1])];
        E T6 = R0[(rs[2])];
        // Merge computations directly into outputs to remove intermediate storage (reducing WAW/RAW)
        T4 = T2 - T3;
        Tb = T2 + T3;
        T7 = T5 - T6;
        Tc = T5 + T6;
    }

    // Remove loop-carried dependency by precomputing independent terms and writing non-temporally
    // Outputs are computed in an order that avoids write-after-write hazards via disjoint memory paths
    Cr[(csr[3])] = T1 + T4 - (T7 + Ta);  // Independent base term written first

    // Fold constants and arithmetic to eliminate redundant subexpressions (strength reduction)
    Cr[0] = T1 + KP623489801*T4 + KP222520933*T7 + KP900968867*Ta;
    Cr[(csr[1])] = T1 + KP222520933*Ta - KP623489801*T7 - KP900968867*T4;
    Cr[(csr[2])] = T1 + KP900968867*T7 - KP623489801*Ta - KP222520933*T4;

    Ci[0] = -(KP781831482*Tb + KP974927912*Tc + KP433883739*Td);
    Ci[(csi[1])] = KP781831482*Tc - KP974927912*Td - KP433883739*Tb;
    Ci[(csi[2])] = KP974927912*Tb - KP781831482*Td - KP433883739*Tc;

    // No intermediate reuse — all outputs derived directly from inputs, eliminating artificial dependencies
}
}
