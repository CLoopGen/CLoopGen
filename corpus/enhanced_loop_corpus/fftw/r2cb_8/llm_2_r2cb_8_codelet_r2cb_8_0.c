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
    {
        E T4, Tf, T1, T2;
        // Change memory access to consecutive indexing via pointer arithmetic
        T4 = *(Cr + 2*ivs);
        T5 = KP2_000000000 * T4;
        Tf = *(Ci + 2*ivs);
        Tg = KP2_000000000 * Tf;
        T1 = *Cr;
        T2 = *(Cr + 4*ivs);
        T3 = T1 + T2;
        Te = T1 - T2;
        {
            E T7, T8, Tb, Tc;
            T7 = *(Cr + ivs);
            T8 = *(Cr + 3*ivs);
            T9 = KP2_000000000 * (T7 + T8);
            Ti = T7 - T8;
            Tb = *(Ci + ivs);
            Tc = *(Ci + 3*ivs);
            Td = KP2_000000000 * (Tb - Tc);
            Tj = Tb + Tc;
        }
    }
    T6 = T3 + T5;
    *(R0 + 2*ovs) = T6 - T9;
    *R0 = T6 + T9;
    Ta = T3 - T5;
    *(R0 + ovs) = Ta - Td;
    *(R0 + 3*ovs) = Ta + Td;
    {
        E Th, Tk, Tl, Tm;
        Th = Te - Tg;
        Tk = KP1_414213562 * (Ti - Tj);
        *(R1 + 2*ovs) = Th - Tk;
        *R1 = Th + Tk;
        Tl = Te + Tg;
        Tm = KP1_414213562 * (Ti + Tj);
        *(R1 + ovs) = Tl - Tm;
        *(R1 + 3*ovs) = Tl + Tm;
    }
}
}
