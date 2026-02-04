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
extern  E KP250000000;
extern  E KP559016994;
extern  E KP951056516;
extern  E KP587785252;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T8, T3, T6, T9, Tc, Tb, T7, Ta;
    T8 = R0[0];

    E T1 = R0[(rs[1])];
    E T2 = R1[(rs[1])];
    E T4 = R0[(rs[2])];
    E T5 = R1[0];

    T3 = T1 - T2;
    T6 = T4 - T5;
    T9 = T3 + T6;
    Tc = T4 + T5;
    Tb = T1 + T2;

    E temp_Cr2 = T8 + T9;
    E temp_Ci1 = (KP587785252 * Tb) - (KP951056516 * Tc);
    E temp_Ci0 = -((KP951056516 * Tb) + (KP587785252 * Tc));
    T7 = KP559016994 * (T3 - T6);
    Ta = T8 - (KP250000000 * T9);

    Cr[(csr[2])] = temp_Cr2;
    Ci[(csi[1])] = temp_Ci1;
    Ci[0] = temp_Ci0;
    Cr[0] = T7 + Ta;
    Cr[(csr[1])] = Ta - T7;
}
}
