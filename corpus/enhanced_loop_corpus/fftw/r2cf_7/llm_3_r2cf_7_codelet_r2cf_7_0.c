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
    E *r0_base = R0, *r1_base = R1;
    E *cr_base = Cr, *ci_base = Ci;

    T1 = r0_base[0];
    T8 = r1_base[0];
    T9 = r0_base[rs[3]];
    Ta = T8 + T9;
    Tb = T9 - T8;

    {
        E T2, T3, T5, T6;
        T2 = r0_base[rs[1]];
        T3 = r1_base[rs[2]];
        T4 = T2 + T3;
        Td = T3 - T2;
        T5 = r1_base[rs[1]];
        T6 = r0_base[rs[2]];
        T7 = T5 + T6;
        Tc = T6 - T5;
    }

    ci_base[csi[2]] = ((KP974927912 * Tb) - ((KP781831482) * (Tc))) - (KP433883739 * Td);
    ci_base[csi[1]] = (((KP781831482) * (Tb)) + (KP974927912 * Td)) + (KP433883739 * Tc);
    cr_base[csr[2]] = (((KP623489801) * (T7)) + (T1)) + (-(((KP900968867) * (T4)) + (KP222520933 * Ta)));
    ci_base[csi[3]] = (((KP433883739) * (Tb)) + (KP974927912 * Tc)) - (KP781831482 * Td);
    cr_base[csr[3]] = (((KP623489801) * (T4)) + (T1)) + (-(((KP222520933) * (T7)) + (KP900968867 * Ta)));
    cr_base[csr[1]] = (((KP623489801) * (Ta)) + (T1)) + (-(((KP900968867) * (T7)) + (KP222520933 * T4)));
    cr_base[0] = T1 + Ta + T4 + T7;
}
}
