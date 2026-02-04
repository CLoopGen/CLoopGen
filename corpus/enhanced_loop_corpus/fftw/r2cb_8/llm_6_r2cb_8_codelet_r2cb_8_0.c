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
extern  E KP1_414213562;
extern  E KP2_000000000;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ovs , R1 = R1 + ovs , Cr = Cr + ivs , Ci = Ci + ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T5, Tg, T3, Te, T9, Ti, Td, Tj, T6, Ta;
    E temp_Cr[5], temp_Ci[4];
    
    // Introduce local caching to remove repeated memory accesses (eliminate RAW hazards)
    temp_Cr[0] = Cr[0];
    temp_Cr[1] = Cr[(csr[1])];
    temp_Cr[2] = Cr[(csr[2])];
    temp_Cr[3] = Cr[(csr[3])];
    temp_Cr[4] = Cr[(csr[4])];
    temp_Ci[0] = Ci[(csi[1])];
    temp_Ci[1] = Ci[(csi[2])];
    temp_Ci[2] = Ci[(csi[3])];

    {
        E T4, Tf, T1, T2;
        T4 = temp_Cr[2];
        T5 = KP2_000000000 * T4;
        Tf = temp_Ci[1];
        Tg = KP2_000000000 * Tf;
        T1 = temp_Cr[0];
        T2 = temp_Cr[4];
        T3 = T1 + T2;
        Te = T1 - T2;
        {
            E T7, T8, Tb, Tc;
            T7 = temp_Cr[1];
            T8 = temp_Cr[3];
            T9 = KP2_000000000 * (T7 + T8);
            Ti = T7 - T8;
            Tb = temp_Ci[0];
            Tc = temp_Ci[2];
            Td = KP2_000000000 * (Tb - Tc);
            Tj = Tb + Tc;
        }
    }
    T6 = T3 + T5;
    R0[(rs[2])] = T6 - T9;
    R0[0] = T6 + T9;
    Ta = T3 - T5;
    R0[(rs[1])] = Ta - Td;
    R0[(rs[3])] = Ta + Td;
    {
        E Th, Tk, Tl, Tm;
        Th = Te - Tg;
        Tk = KP1_414213562 * (Ti - Tj);
        R1[(rs[2])] = Th - Tk;
        R1[0] = Th + Tk;
        Tl = Te + Tg;
        Tm = KP1_414213562 * (Ti + Tj);
        R1[(rs[1])] = Tl - Tm;
        R1[(rs[3])] = Tl + Tm;
    }
}
}
