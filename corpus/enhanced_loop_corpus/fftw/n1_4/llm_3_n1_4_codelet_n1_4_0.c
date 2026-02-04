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
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , ri = ri + ivs , ii = ii + ivs , ro = ro + ovs , io = io + ovs , (is) = (is) + fftw_an_INT_guaranteed_to_be_zero , (os) = (os) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, Tb, T9, Tf, T6, Ta, Te, Tg;
    // Introduce indirect indexing through precomputed index arrays for irregular access pattern
    // Assume `idx_r` and `idx_i` are externally defined arrays containing runtime-computed indices
    // Here we simulate them as compile-time constants for self-containment
    const INT idx_r[4] = {0, is[1], is[2], is[3]};
    const INT idx_ro[4] = {0, os[1], os[2], os[3]};
    
    {
        E T1, T2, T7, T8;
        T1 = ri[idx_r[0]];
        T2 = ri[idx_r[2]];
        T3 = T1 + T2;
        Tb = T1 - T2;
        T7 = ii[idx_r[0]];
        T8 = ii[idx_r[2]];
        T9 = T7 - T8;
        Tf = T7 + T8;
    }
    {
        E T4, T5, Tc, Td;
        T4 = ri[idx_r[1]];
        T5 = ri[idx_r[3]];
        T6 = T4 + T5;
        Ta = T4 - T5;
        Tc = ii[idx_r[1]];
        Td = ii[idx_r[3]];
        Te = Tc - Td;
        Tg = Tc + Td;
    }
    // Use output index array for scattered write
    ro[idx_ro[2]] = T3 - T6;
    io[idx_ro[2]] = Tf - Tg;
    ro[idx_ro[0]] = T3 + T6;
    io[idx_ro[0]] = Tf + Tg;
    io[idx_ro[1]] = T9 - Ta;
    ro[idx_ro[1]] = Tb + Te;
    io[idx_ro[3]] = Ta + T9;
    ro[idx_ro[3]] = Tb - Te;
}
}
