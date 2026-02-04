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
for (i = v / 2; i > 0; i = i - 1 , R0 = R0 + 2*ovs , R1 = R1 + 2*ovs , Cr = Cr + 2*ivs , Ci = Ci + 2*ivs , (rs) = (rs) + 2*fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + 2*fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    E T5_lo, T8_lo, T3_lo, T6_lo;
    E T5_hi, T8_hi, T3_hi, T6_hi;
    E T9, Ta, Tb, Tc;

    {
        E T4_lo, T7_lo, T1_lo, T2_lo;
        E T4_hi, T7_hi, T1_hi, T2_hi;
        T4_lo = Cr[(csr[1])];
        T5_lo = KP2_000000000 * T4_lo;
        T7_lo = Ci[(csi[1])];
        T8_lo = KP2_000000000 * T7_lo;
        T1_lo = Cr[0];
        T2_lo = Cr[(csr[2])];
        T3_lo = T1_lo + T2_lo;
        T6_lo = T1_lo - T2_lo;

        T4_hi = (Cr + ivs)[(csr[1])];
        T5_hi = KP2_000000000 * T4_hi;
        T7_hi = (Ci + ivs)[(csi[1])];
        T8_hi = KP2_000000000 * T7_hi;
        T1_hi = Cr[ivs];
        T2_hi = Cr[(csr[2]) + ivs];
        T3_hi = T1_hi + T2_hi;
        T6_hi = T1_hi - T2_hi;
    }

    T9 = T3_lo - T5_lo;
    Ta = T6_lo + T8_lo;
    Tb = T3_lo + T5_lo;
    Tc = T6_lo - T8_lo;

    R0[(rs[1])] = T9;
    R1[(rs[1])] = Ta;
    R0[0] = Tb;
    R1[0] = Tc;

    T9 = T3_hi - T5_hi;
    Ta = T6_hi + T8_hi;
    Tb = T3_hi + T5_hi;
    Tc = T6_hi - T8_hi;

    (R0 + ovs)[(rs[1])] = T9;
    (R1 + ovs)[(rs[1])] = Ta;
    (R0 + ovs)[0] = Tb;
    (R1 + ovs)[0] = Tc;
}
}
