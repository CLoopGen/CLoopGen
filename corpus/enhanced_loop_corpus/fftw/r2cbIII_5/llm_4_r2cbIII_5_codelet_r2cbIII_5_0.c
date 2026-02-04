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
extern  E KP1_118033988;
extern  E KP500000000;
extern  E KP1_175570504;
extern  E KP1_902113032;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ovs , R1 = R1 + ovs , Cr = Cr + ivs , Ci = Ci + ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E Ta, Tc, T1, T4, T5, T6, Tb, T7;
    E temp_Ci1 = Ci[(csi[1])];
    E temp_Ci0 = Ci[0];
    E temp_Cr2 = Cr[(csr[2])];
    E temp_Cr1 = Cr[(csr[1])];
    E temp_Cr0 = Cr[0];

    Ta = (((KP1_902113032) * temp_Ci1) + (KP1_175570504 * temp_Ci0));
    Tc = ((KP1_175570504 * temp_Ci1) - ((KP1_902113032) * temp_Ci0));
    T4 = temp_Cr1 + temp_Cr0;
    T5 = (((KP500000000) * (T4)) - (temp_Cr2));
    T6 = KP1_118033988 * (temp_Cr0 - temp_Cr1);

    R0[0] = (((KP2_000000000) * (T4)) + (temp_Cr2));
    Tb = T6 - T5;
    R0[(rs[1])] = Tb + Tc;
    R1[(rs[1])] = Tc - Tb;
    T7 = T5 + T6;
    R1[0] = T7 - Ta;
    R0[(rs[2])] = -(T7 + Ta);
}
}
