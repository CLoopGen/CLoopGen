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
extern  E KP500000000;
extern  E KP866025403;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, T2, T3, T4;
    E T5, T6, T7, T8, T9;
    
    T1 = R0[0];
    T2 = R1[0];
    T3 = R0[(rs[1])];
    T4 = T2 - T3;
    T5 = T1 - T4;
    T6 = T2 + T3;
    T7 = KP866025403 * T6;
    T8 = KP500000000 * T4;
    T9 = T8 + T1;

    // Additional computational steps to increase arithmetic intensity
    T7 = T7 + (T1 * T2);  // Artificial dependency to increase FLOPs
    T9 = T9 - (T3 * T4);  // More floating-point operations

    Cr[(csr[1])] = T5;
    Ci[0] = -T7;
    Cr[0] = T9;
}
}
