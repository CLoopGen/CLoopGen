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
extern  E KP707106781;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, T7, Td, Tj, T6, Tg, Ta, Ti;
    {
        E T1, T2, Tb, Tc;
        T1 = R0[0];
        T2 = R0[(rs[2])];
        T3 = T1 + T2;
        T7 = T1 - T2;
        Tb = R1[(rs[3])];
        Tc = R1[(rs[1])];
        Td = Tb - Tc;
        Tj = Tb + Tc;
    }
    {
        E T4, T5, T8, T9;
        T4 = R0[(rs[1])];
        T5 = R0[(rs[3])];
        T6 = T4 + T5;
        Tg = T4 - T5;
        T8 = R1[0];
        T9 = R1[(rs[2])];
        Ta = T8 - T9;
        Ti = T8 + T9;
    }
    Cr[(csr[2])] = T3 - T6;
    Ci[(csi[2])] = Tj - Ti;
    {
        E Te, Tf, Th, Tk;
        Te = KP707106781 * (Ta + Td);
        Cr[(csr[3])] = T7 - Te;
        Cr[(csr[1])] = T7 + Te;
        Tf = KP707106781 * (Td - Ta);
        Ci[(csi[1])] = Tf - Tg;
        Ci[(csi[3])] = Tg + Tf;
        Th = T3 + T6;
        Tk = Ti + Tj;
        Cr[(csr[4])] = Th - Tk;
        Cr[0] = Th + Tk;
    }
}

}
