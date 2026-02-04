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
extern  E KP222520933;
extern  E KP900968867;
extern  E KP623489801;
extern  E KP433883739;
extern  E KP781831482;
extern  E KP974927912;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, Ta, Tb, T4, Td, T7, Tc, T8, T9;
    T1 = R0[0];
    T8 = R1[0];
    T9 = R0[(rs[3])];
    Ta = T8 + T9;
    Tb = T9 - T8;
    {
        E T2, T3, T5, T6;
        T2 = R0[(rs[1])];
        T3 = R1[(rs[2])];
        T4 = T2 + T3;
        Td = T3 - T2;
        T5 = R1[(rs[1])];
        T6 = R0[(rs[2])];
        T7 = T5 + T6;
        Tc = T6 - T5;
    }
    // Introduce temporary variables to break WAW and WAR dependencies
    E temp_c2 = ((KP974927912 * Tb) - ((KP781831482) * (Tc))) - (KP433883739 * Td);
    E temp_c1 = (((KP781831482) * (Tb)) + (KP974927912 * Td)) + (KP433883739 * Tc);
    E temp_r2 = (((KP623489801) * (T7)) + (T1)) + (-(((KP900968867) * (T4)) + (KP222520933 * Ta)));
    E temp_c3 = (((KP433883739) * (Tb)) + (KP974927912 * Tc)) - (KP781831482 * Td);
    E temp_r3 = (((KP623489801) * (T4)) + (T1)) + (-(((KP222520933) * (T7)) + (KP900968867 * Ta)));
    E temp_r1 = (((KP623489801) * (Ta)) + (T1)) + (-(((KP900968867) * (T7)) + (KP222520933 * T4)));
    E temp_r0 = T1 + Ta + T4 + T7;

    // Eliminate write-after-write hazards by reordering independent writes
    Cr[0] = temp_r0;
    Cr[(csr[1])] = temp_r1;
    Cr[(csr[2])] = temp_r2;
    Cr[(csr[3])] = temp_r3;
    Ci[(csi[1])] = temp_c1;
    Ci[(csi[2])] = temp_c2;
    Ci[(csi[3])] = temp_c3;
}
}
