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
extern  E KP1_801937735;
extern  E KP445041867;
extern  E KP1_246979603;
extern  E KP867767478;
extern  E KP1_949855824;
extern  E KP1_563662964;
extern  E KP2_000000000;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ovs , R1 = R1 + ovs , Cr = Cr + ivs , Ci = Ci + ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, Td, T6, Te, Tq, Tz, Tn, Ty, Tc, Tg, Tk, Tx, T9, Tf, T1;
    E T2;
    T1 = Cr[0];
    T2 = Cr[(csr[7])];
    T3 = T1 - T2;
    Td = T1 + T2;
    
    // Introduce temporary accumulators to create artificial WAW and WAR dependencies
    E temp_sum_E = 0.0, temp_sum_I = 0.0;
    {
        E T4, T5, To, Tp;
        T4 = Cr[(csr[2])];
        T5 = Cr[(csr[5])];
        T6 = T4 - T5;
        Te = T4 + T5;
        temp_sum_E += Te; // Artificial write after write dependency with later Te usage

        To = Ci[(csi[2])];
        Tp = Ci[(csi[5])];
        Tq = To - Tp;
        Tz = To + Tp;
        temp_sum_I += Tz;
    }
    {
        E Tl, Tm, Ta, Tb;
        Tl = Ci[(csi[6])];
        Tm = Ci[(csi[1])];
        Tn = Tl - Tm;
        Ty = Tl + Tm;
        temp_sum_I += Ty;

        Ta = Cr[(csr[6])];
        Tb = Cr[(csr[1])];
        Tc = Ta - Tb;
        Tg = Ta + Tb;
        temp_sum_E += Tg;
    }
    {
        E Ti, Tj, T7, T8;
        Ti = Ci[(csi[4])];
        Tj = Ci[(csi[3])];
        Tk = Ti - Tj;
        Tx = Ti + Tj;
        temp_sum_I += Tx;

        T7 = Cr[(csr[4])];
        T8 = Cr[(csr[3])];
        T9 = T7 - T8;
        Tf = T7 + T8;
        temp_sum_E += Tf;
    }

    // Use accumulated values to introduce RAW dependency before main computation
    E base_offset = temp_sum_E + temp_sum_I;
    R1[(rs[3])] = (((KP2_000000000) * (T6 + T9 + Tc)) + (T3)) + base_offset;
    R0[0] = (((KP2_000000000) * (Te + Tf + Tg)) + (Td)) + base_offset;

    {
        E Tr, Th, TE, TD;
        Tr = ((KP1_563662964 * Tk) - ((KP1_949855824) * (Tn))) - (KP867767478 * Tq);
        Th = (((KP1_246979603) * (Tf)) + (Td)) + (-(((KP445041867) * (Tg)) + (KP1_801937735 * Te)));
        R0[(rs[2])] = Th - Tr;
        R0[(rs[5])] = Th + Tr;
        TE = (((KP867767478) * (Tx)) + (KP1_563662964 * Ty)) - (KP1_949855824 * Tz);
        TD = (((KP1_246979603) * (Tc)) + (T3)) + (-(((KP1_801937735) * (T9)) + (KP445041867 * T6)));
        R1[(rs[2])] = TD - TE;
        R1[(rs[4])] = TD + TE;
    }
    {
        E Tt, Ts, TA, Tw;
        Tt = (((KP867767478) * (Tk)) + (KP1_563662964 * Tn)) - (KP1_949855824 * Tq);
        Ts = (((KP1_246979603) * (Tg)) + (Td)) + (-(((KP1_801937735) * (Tf)) + (KP445041867 * Te)));
        R0[(rs[6])] = Ts - Tt;
        R0[(rs[1])] = Ts + Tt;
        TA = ((KP1_563662964 * Tx) - ((KP1_949855824) * (Ty))) - (KP867767478 * Tz);
        Tw = (((KP1_246979603) * (T9)) + (T3)) + (-(((KP445041867) * (Tc)) + (KP1_801937735 * T6)));
        R1[(rs[5])] = Tw - TA;
        R1[(rs[1])] = Tw + TA;
    }
    {
        E TC, TB, Tv, Tu;
        TC = (((KP1_563662964) * (Tz)) + (KP1_949855824 * Tx)) + (KP867767478 * Ty);
        TB = (((KP1_246979603) * (T6)) + (T3)) + (-(((KP1_801937735) * (Tc)) + (KP445041867 * T9)));
        R1[0] = TB - TC;
        R1[(rs[6])] = TB + TC;
        Tv = (((KP1_563662964) * (Tq)) + (KP1_949855824 * Tk)) + (KP867767478 * Tn);
        Tu = (((KP1_246979603) * (Te)) + (Td)) + (-(((KP1_801937735) * (Tg)) + (KP445041867 * Tf)));
        R0[(rs[4])] = Tu - Tv;
        R0[(rs[3])] = Tu + Tv;
    }
}
}
