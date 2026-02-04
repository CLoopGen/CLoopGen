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
extern  E KP500000000;
extern  E KP1_902113032;
extern  E KP1_175570504;
extern  E KP2_000000000;
extern  E KP1_118033988;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ovs , R1 = R1 + ovs , Cr = Cr + ivs , Ci = Ci + ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, To, T8, Tq, Ta, Tp, Te, Ts, Th, Tn;
    T1 = Cr[(csr[2])];
    To = Ci[(csi[2])];
    {
        E T2, T3, T4, T5, T6, T7;
        T2 = Cr[(csr[4])];
        T3 = Cr[0];
        T4 = T2 + T3;
        T5 = Cr[(csr[3])];
        T6 = Cr[(csr[1])];
        T7 = T5 + T6;
        T8 = T4 + T7;
        Tq = T5 - T6;
        Ta = KP1_118033988 * (T7 - T4);
        Tp = T2 - T3;
    }
    {
        E Tc, Td, Tm, Tf, Tg, Tl;
        Tc = Ci[(csi[4])];
        Td = Ci[0];
        Tm = Tc + Td;
        Tf = Ci[(csi[1])];
        Tg = Ci[(csi[3])];
        Tl = Tg + Tf;
        Te = Tc - Td;
        Ts = KP1_118033988 * (Tl + Tm);
        Th = Tf - Tg;
        Tn = Tl - Tm;
    }
    // Introduce temporary variables to break WAW and WAR dependencies by reordering independent computations
    E temp_R0_0, temp_R1_2, temp_R0_1, temp_R0_3, temp_R0_4, temp_R0_2_val, temp_R1_0, temp_R1_3, temp_R1_4, temp_R1_1;

    temp_R0_0 = KP2_000000000 * (T1 + T8);
    temp_R1_2 = KP2_000000000 * (Tn - To);

    {
        E Ti, Tj, Tb, Tk, T9;
        Ti = ((KP1_175570504 * Te) - ((KP1_902113032) * (Th)));
        Tj = (((KP1_175570504) * (Th)) + (KP1_902113032 * Te));
        T9 = ((KP500000000 * T8) - ((KP2_000000000) * (T1)));
        Tb = T9 - Ta;
        Tk = T9 + Ta;
        temp_R0_1 = Tb + Ti;
        temp_R0_3 = Tk + Tj;
        temp_R0_4 = Ti - Tb;
        temp_R0_2_val = Tj - Tk;
    }

    {
        E Tr, Tv, Tu, Tw, Tt;
        Tr = (((KP1_902113032) * (Tp)) + (KP1_175570504 * Tq));
        Tv = ((KP1_902113032 * Tq) - ((KP1_175570504) * (Tp)));
        Tt = (((KP500000000) * (Tn)) + (KP2_000000000 * To));
        Tu = Ts + Tt;
        Tw = Tt - Ts;
        temp_R1_0 = -(Tr + Tu);
        temp_R1_3 = Tw - Tv;
        temp_R1_4 = Tr - Tu;
        temp_R1_1 = Tv + Tw;
    }

    // Final write-back phase: eliminate write-after-write hazards via single assignment per memory location
    R0[0] = temp_R0_0;
    R1[(rs[2])] = temp_R1_2;
    R0[(rs[1])] = temp_R0_1;
    R0[(rs[3])] = temp_R0_3;
    R0[(rs[4])] = temp_R0_4;
    R0[(rs[2])] = temp_R0_2_val;
    R1[0] = temp_R1_0;
    R1[(rs[3])] = temp_R1_3;
    R1[(rs[4])] = temp_R1_4;
    R1[(rs[1])] = temp_R1_1;
}
}
