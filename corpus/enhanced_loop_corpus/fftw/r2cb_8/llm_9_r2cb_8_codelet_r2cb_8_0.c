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
// Reduced trip count by unrolling the loop and processing two iterations per loop cycle
// Assumes v is even for correctness; no functional change but doubles computational stride
for (i = v; i > 1; i = i - 2 , R0 = R0 + 2*ovs , R1 = R1 + 2*ovs , Cr = Cr + 2*ivs , Ci = Ci + 2*ivs , (rs) = (rs) + 2*fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + 2*fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    // First iteration (original i)
    {
        E T5, Tg, T3, Te, T9, Ti, Td, Tj, T6, Ta;
        {
            E T4, Tf, T1, T2;
            T4 = Cr[(csr[2])];
            T5 = KP2_000000000 * T4;
            Tf = Ci[(csi[2])];
            Tg = KP2_000000000 * Tf;
            T1 = Cr[0];
            T2 = Cr[(csr[4])];
            T3 = T1 + T2;
            Te = T1 - T2;
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

    // Second iteration (i-1), offset by ivs in Cr/Ci and ovs in R0/R1, rs adjusted accordingly
    {
        E T5, Tg, T3, Te, T9, Ti, Td, Tj, T6, Ta;
        {
            E T4, Tf, T1, T2;
            T4 = (Cr+ivs)[(csr[2])];
            T5 = KP2_000000000 * T4;
            Tf = (Ci+ivs)[(csi[2])];
            Tg = KP2_000000000 * Tf;
            T1 = (Cr+ivs)[0];
            T2 = (Cr+ivs)[(csr[4])];
            T3 = T1 + T2;
            Te = T1 - T2;
            {
                E T7, T8, Tb, Tc;
                T7 = (Cr+ivs)[(csr[1])];
                T8 = (Cr+ivs)[(csr[3])];
                T9 = KP2_000000000 * (T7 + T8);
                Ti = T7 - T8;
                Tb = (Ci+ivs)[(csi[1])];
                Tc = (Ci+ivs)[(csi[3])];
                Td = KP2_000000000 * (Tb - Tc);
                Tj = Tb + Tc;
            }
        }
        T6 = T3 + T5;
        (R0+ovs)[(rs[2])] = T6 - T9;
        (R0+ovs)[0] = T6 + T9;
        Ta = T3 - T5;
        (R0+ovs)[(rs[1])] = Ta - Td;
        (R0+ovs)[(rs[3])] = Ta + Td;
        {
            E Th, Tk, Tl, Tm;
            Th = Te - Tg;
            Tk = KP1_414213562 * (Ti - Tj);
            (R1+ovs)[(rs[2])] = Th - Tk;
            (R1+ovs)[0] = Th + Tk;
            Tl = Te + Tg;
            Tm = KP1_414213562 * (Ti + Tj);
            (R1+ovs)[(rs[1])] = Tl - Tm;
            (R1+ovs)[(rs[3])] = Tl + Tm;
        }
    }
}

// Handle remaining single iteration if v was odd
if (v % 2 == 1) {
    E T5, Tg, T3, Te, T9, Ti, Td, Tj, T6, Ta;
    {
        E T4, Tf, T1, T2;
        T4 = Cr[(csr[2])];
        T5 = KP2_000000000 * T4;
        Tf = Ci[(csi[2])];
        Tg = KP2_000000000 * Tf;
        T1 = Cr[0];
        T2 = Cr[(csr[4])];
        T3 = T1 + T2;
        Te = T1 - T2;
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
