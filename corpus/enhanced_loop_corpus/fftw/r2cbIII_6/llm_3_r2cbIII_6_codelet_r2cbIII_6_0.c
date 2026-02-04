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
extern  E KP1_732050807;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + 3*ovs , R1 = R1 + 3*ovs , Cr = Cr + 3*ivs , Ci = Ci + 3*ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1[3], T6[3], T4[3], T5[3], T9[3], Tb[3], Ta[3], Tc[3];
    for (INT j = 0; j < 3; ++j) {
        T1[j] = Cr[j * ivs + csr[(j+1)%3]];
        T6[j] = Ci[j * ivs + csi[(j+1)%3]];
        E T2 = Cr[j * ivs + csr[(j+2)%3]];
        E T3 = Cr[j * ivs];
        T4[j] = T2 + T3;
        T5[j] = KP1_732050807 * (T2 - T3);
        E T7 = Ci[j * ivs + csi[(j+2)%3]];
        E T8 = Ci[j * ivs];
        T9[j] = T7 + T8;
        Tb[j] = KP1_732050807 * (T7 - T8);
    }
    for (INT j = 0; j < 3; ++j) {
        R0[j * ovs] = KP2_000000000 * (T1[j] + T4[j]);
        R1[j * ovs + rs[1]] = KP2_000000000 * (T6[j] - T9[j]);
        Ta[j] = KP2_000000000 * T6[j] + T9[j];
        R1[j * ovs] = -(T5[j] + Ta[j]);
        R1[j * ovs + rs[2]] = T5[j] - Ta[j];
        Tc[j] = KP2_000000000 * T1[j] - T4[j];
        R0[j * ovs + rs[1]] = Tb[j] - Tc[j];
        R0[j * ovs + rs[2]] = Tc[j] + Tb[j];
    }
}
}
