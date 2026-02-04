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
extern  E KP765366864;
extern  E KP1_847759065;
extern  E KP2_000000000;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
INT outer_i;
for (outer_i = v / 2; outer_i > 0; outer_i--) {
    for (i = 2; i > 0; i = i - 1 , R0 = R0 + ovs , R1 = R1 + ovs , Cr = Cr + ivs , Ci = Ci + ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
        E T3, T7, Tf, Tl, T6, Tc, Ta, Tk, Tb, Tg;
        {
            E T1, T2, Td, Te;
            T1 = Cr[0];
            T2 = Cr[(csr[3])];
            T3 = T1 + T2;
            T7 = T1 - T2;
            Td = Ci[0];
            Te = Ci[(csi[3])];
            Tf = Td + Te;
            Tl = Te - Td;
        }
        {
            E T4, T5, T8, T9;
            T4 = Cr[(csr[2])];
            T5 = Cr[(csr[1])];
            T6 = T4 + T5;
            Tc = T4 - T5;
            T8 = Ci[(csi[2])];
            T9 = Ci[(csi[1])];
            Ta = T8 + T9;
            Tk = T8 - T9;
        }
        R0[0] = KP2_000000000 * (T3 + T6);
        R0[(rs[2])] = KP2_000000000 * (Tl - Tk);
        Tb = T7 - Ta;
        Tg = Tc + Tf;
        R1[0] = ((KP1_847759065 * Tb) - ((KP765366864) * (Tg)));
        R1[(rs[2])] = -((((KP765366864) * (Tb)) + (KP1_847759065 * Tg)));
        {
            E Th, Ti, Tj, Tm;
            Th = T7 + Ta;
            Ti = Tc - Tf;
            R1[(rs[1])] = (((KP765366864) * (Th)) + (KP1_847759065 * Ti));
            R1[(rs[3])] = ((KP765366864 * Ti) - ((KP1_847759065) * (Th)));
            Tj = T3 - T6;
            Tm = Tk + Tl;
            R0[(rs[1])] = KP1_414213562 * (Tj + Tm);
            R0[(rs[3])] = KP1_414213562 * (Tm - Tj);
        }
    }
}
}
