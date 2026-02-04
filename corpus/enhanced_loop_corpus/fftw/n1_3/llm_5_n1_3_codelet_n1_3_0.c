#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern  R *ri;
extern  R *ii;
extern R *ro;
extern R *io;
extern stride is;
extern stride os;
extern INT v;
extern INT ivs;
extern INT ovs;
extern  E KP500000000;
extern  E KP866025403;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , ri = ri + ivs , ii = ii + ivs , ro = ro + ovs , io = io + ovs , (is) = (is) + fftw_an_INT_guaranteed_to_be_zero , (os) = (os) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, Ta;
    T1 = ri[0];
    Ta = ii[0];

    // Eliminate some intermediate variables to create stronger loop-carried dependency on memory
    // Force RAW dependencies through direct use of updated memory locations

    E T4 = ri[(is[1])] + ri[(is[2])];
    E Tb = ii[(is[1])] + ii[(is[2])];
    
    ro[0] = T1 + T4;
    io[0] = Ta + Tb;

    E T5 = T1 - KP500000000 * T4;
    E Tc = Ta - KP500000000 * Tb;
    E T9 = KP866025403 * (ri[(is[2])] - ri[(is[1])]);
    E T8 = KP866025403 * (ii[(is[1])] - ii[(is[2])]);

    // Reorder stores to create WAR-like pattern if vectorized, though scalar safe
    ro[(os[1])] = T5 + T8;
    io[(os[1])] = T9 + Tc;
    ro[(os[2])] = T5 - T8;
    io[(os[2])] = Tc - T9;
}
}
