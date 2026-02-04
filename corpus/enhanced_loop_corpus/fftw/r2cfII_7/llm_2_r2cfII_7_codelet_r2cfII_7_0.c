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
extern  E KP900968867;
extern  E KP222520933;
extern  E KP623489801;
extern  E KP433883739;
extern  E KP974927912;
extern  E KP781831482;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, Ta, Td, T4, Tb, T7, Tc, T8, T9;
    INT idx_r1 = rs[1], idx_r2 = rs[2], idx_r3 = rs[3];
    INT idx_csr1 = csr[1], idx_csr2 = csr[2], idx_csr3 = csr[3];
    INT idx_csi1 = csi[1], idx_csi2 = csi[2];

    T1 = R0[0];
    T8 = R1[0];
    T9 = R0[idx_r3];
    Ta = T8 - T9;
    Td = T8 + T9;

    {
        E T2, T3, T5, T6;
        T2 = R0[idx_r1];
        T3 = R1[idx_r2];
        T4 = T2 - T3;
        Tb = T2 + T3;
        T5 = R1[idx_r1];
        T6 = R0[idx_r2];
        T7 = T5 - T6;
        Tc = T5 + T6;
    }

    Ci[0] = -((((KP781831482) * (Tb)) + (KP974927912 * Tc)) + (KP433883739 * Td));
    Ci[idx_csi1] = ((KP781831482 * Tc) - ((KP974927912) * (Td))) - (KP433883739 * Tb);
    Cr[0] = (((KP623489801) * (T4)) + (T1)) + (((KP222520933) * (T7)) + (KP900968867 * Ta));
    Ci[idx_csi2] = ((KP974927912 * Tb) - ((KP781831482) * (Td))) - (KP433883739 * Tc);
    Cr[idx_csr2] = (((KP900968867) * (T7)) + (T1)) + (-(((KP623489801) * (Ta)) + (KP222520933 * T4)));
    Cr[idx_csr1] = (((KP222520933) * (Ta)) + (T1)) + (-(((KP623489801) * (T7)) + (KP900968867 * T4)));
    Cr[idx_csr3] = T1 + T4 - (T7 + Ta);
}
}
