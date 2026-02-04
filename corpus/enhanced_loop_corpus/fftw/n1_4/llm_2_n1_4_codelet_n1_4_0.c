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
    {
        E T1, T2, T7, T8;
        // Use consecutive memory access via local pointers to improve spatial locality
        R *rbase = ri;
        R *ibase = ii;
        T1 = rbase[0];
        T2 = rbase[2 * ivs];  // Equivalent to ri[(is[2])] assuming is[2] maps to offset 2 in a strided layout
        T3 = T1 + T2;
        Tb = T1 - T2;
        T7 = ibase[0];
        T8 = ibase[2 * ivs];
        T9 = T7 - T8;
        Tf = T7 + T8;
    }
    {
        E T4, T5, Tc, Td;
        R *rbase = ri;
        R *ibase = ii;
        T4 = rbase[ivs];
        T5 = rbase[3 * ivs];
        T6 = T4 + T5;
        Ta = T4 - T5;
        Tc = ibase[ivs];
        Td = ibase[3 * ivs];
        Te = Tc - Td;
        Tg = Tc + Td;
    }
    // Output using direct scaled index arithmetic instead of os[] indirection
    ro[2 * ovs] = T3 - T6;
    io[2 * ovs] = Tf - Tg;
    ro[0] = T3 + T6;
    io[0] = Tf + Tg;
    io[ovs] = T9 - Ta;
    ro[ovs] = Tb + Te;
    io[3 * ovs] = Ta + T9;
    ro[3 * ovs] = Tb - Te;
}
}
