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
    E T4, Tf, T1, T2;
    T1 = Cr[0];
    T2 = Cr[(csr[4])];
    T3 = T1 + T2;
    Te = T1 - T2;

    if (i > v / 2) {
        T4 = Cr[(csr[2])];
        T5 = KP2_000000000 * T4;
        Tf = Ci[(csi[2])];
        Tg = KP2_000000000 * Tf;
        {
            E T7, T8, Tb, Tc;
            T7 = Cr[(csr[1])];
            T8 = Cr[(csr[3])];
            T9 = KP2_000000000 * (T7 + T8);
            Ti = T7 - T8;
            Tb = Ci[(csi[1])];
            Tc = Ci[(csi[3])];
            Td = KP2_000000000 * (Tb - Tc);
            Tj = Tb + Tc;
        }
    } else {
        T5 = KP2_000000000 * Cr[(csr[3])];
        Tg = KP2_000000000 * Ci[(csi[3])];
        T9 = KP2_000000000 * (Cr[(csr[1])] + Cr[(csr[2])]);
        Ti = Cr[(csr[1])] - Cr[(csr[2])];
        Td = KP2_000000000 * (Ci[(csi[1])] - Ci[(csi[2])]);
        Tj = Ci[(csi[1])] + Ci[(csi[2])];
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
