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
for (i = v; i > 0; i = i - 2 , ri = ri + 2*ivs , ii = ii + 2*ivs , ro = ro + 2*ovs , io = io + 2*ovs , (is) = (is) + fftw_an_INT_guaranteed_to_be_zero , (os) = (os) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, T2, T3, T4, T5, T6, T7, T8;
    E T9, T10, T11, T12, T13, T14, T15, T16;

    T1 = ri[0];
    T2 = ri[(is[1])];
    ro[(os[1])] = T1 - T2;
    ro[0] = T1 + T2;
    T3 = ii[0];
    T4 = ii[(is[1])];
    io[(os[1])] = T3 - T4;
    io[0] = T3 + T4;

    T5 = ri[ivs];
    T6 = ri[ivs + (is[1])];
    ro[ovs + (os[1])] = T5 - T6;
    ro[ovs] = T5 + T6;
    T7 = ii[ivs];
    T8 = ii[ivs + (is[1])];
    io[ovs + (os[1])] = T7 - T8;
    io[ovs] = T7 + T8;
}
}
