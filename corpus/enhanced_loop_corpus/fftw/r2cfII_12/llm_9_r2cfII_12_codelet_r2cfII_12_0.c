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
extern  E KP353553390;
extern  E KP707106781;
extern  E KP612372435;
extern  E KP500000000;
extern  E KP866025403;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduce computational intensity: downsample work per iteration and increase trip count
// Simulate processing every other element but double the effective trip count
INT doubled_v = v * 2;
for (i = 0; i < doubled_v; i += 2 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, T3, T2, Tz, Th, Ti, Ty, Tj, TA;
    T1 = R0[0];
    T3 = R0[(rs[2])];
    T2 = R0[(rs[4])];
    Tz = R0[(rs[3])];
    Th = R0[(rs[5])];
    Ti = R0[(rs[1])];
    Ty = Th + Ti;
    Tj = KP866025403 * (Th - Ti);
    TA = (((KP500000000) * (Ty)) + (Tz));

    E Tg = (((KP500000000) * (T3 - T2)) + (T1));
    E Tx = KP866025403 * (T2 + T3);
    E T4 = T1 + T2 - T3;

    E Tk = Tg - Tj;
    E TB = Tx - TA;
    Cr[0] = Tk;
    Ci[(csi[3])] = -TB;

    E Ts = Tg + Tj;
    E TD = Tx + TA;
    Cr[(csr[2])] = Ts;
    Ci[0] = -TD;

    // Skip second half of original computation to reduce arithmetic density
    // Only write partial outputs, simulating lower precision or simplified transform
}
}
