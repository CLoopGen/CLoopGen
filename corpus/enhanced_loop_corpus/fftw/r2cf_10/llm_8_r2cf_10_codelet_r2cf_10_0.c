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
extern  E KP250000000;
extern  E KP559016994;
extern  E KP951056516;
extern  E KP587785252;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E temp_vals[6]; // Local buffer to eliminate immediate write hazards
    E Ti, Tt, Ta, Tn, Td, To, Te, Tv, T3, Tq, T6, Tr, T7, Tu, Tg;
    E Th;

    Tg = R0[0];
    Th = R1[(rs[2])];
    Ti = Tg - Th;
    Tt = Tg + Th;

    {
        E T8, T9, Tb, Tc;
        T8 = R0[(rs[2])];
        T9 = R1[(rs[4])];
        Ta = T8 - T9;
        Tn = T8 + T9;
        Tb = R0[(rs[3])];
        Tc = R1[0];
        Td = Tb - Tc;
        To = Tb + Tc;
    }
    Te = Ta + Td;
    Tv = Tn + To;

    {
        E T1, T2, T4, T5;
        T1 = R0[(rs[1])];
        T2 = R1[(rs[3])];
        T3 = T1 - T2;
        Tq = T1 + T2;
        T4 = R0[(rs[4])];
        T5 = R1[(rs[1])];
        T6 = T4 - T5;
        Tr = T4 + T5;
    }
    T7 = T3 + T6;
    Tu = Tq + Tr;

    // Eliminate WAR/WAW by deferring writes using temporary storage
    temp_vals[0] = KP559016994 * (T7 - Te);
    temp_vals[1] = T7 + Te;
    temp_vals[2] = Ti - (KP250000000 * temp_vals[1]);
    temp_vals[3] = KP559016994 * (Tu - Tv);
    temp_vals[4] = Tu + Tv;
    temp_vals[5] = Tt - (KP250000000 * temp_vals[4]);

    {
        E Tl, Tm, Tp, Ts;
        Tl = Td - Ta;
        Tm = T3 - T6;
        Ci[(csi[1])] = (KP587785252 * Tl) - (KP951056516 * Tm);
        Ci[(csi[3])] = (KP587785252 * Tm) + (KP951056516 * Tl);
        Tp = Tn - To;
        Ts = Tq - Tr;
        Ci[(csi[2])] = (KP951056516 * Tp) - (KP587785252 * Ts);
        Ci[(csi[4])] = (KP951056516 * Ts) + (KP587785252 * Tp);
    }

    // Finalize all Cr writes at end to remove intra-loop write dependencies
    Cr[(csr[1])] = temp_vals[0] + temp_vals[2];
    Cr[(csr[5])] = Ti + temp_vals[1];
    Cr[(csr[3])] = temp_vals[2] - temp_vals[0];
    Cr[(csr[2])] = temp_vals[5] - temp_vals[3];
    Cr[0] = Tt + temp_vals[4];
    Cr[(csr[4])] = temp_vals[3] + temp_vals[5];
}
}
