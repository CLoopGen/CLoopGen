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
extern  E KP663413948;
extern  E KP642787609;
extern  E KP556670399;
extern  E KP766044443;
extern  E KP852868531;
extern  E KP173648177;
extern  E KP984807753;
extern  E KP150383733;
extern  E KP813797681;
extern  E KP342020143;
extern  E KP939692620;
extern  E KP296198132;
extern  E KP866025403;
extern  E KP500000000;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    for (INT j = 0; j < 1; ++j) {
        E T1, T4, To, Ta, Tl, Tk, Tf, Ti, Th, T2, T3, T5, Tg;
        T1 = R0[0];
        T2 = R1[(rs[1])];
        T3 = R0[(rs[3])];
        T4 = T2 - T3;
        To = T2 + T3;
        {
            E T6, T7, T8, T9;
            T6 = R0[(rs[1])];
            T7 = R1[(rs[2])];
            T8 = R0[(rs[4])];
            T9 = T7 - T8;
            Ta = T6 - T9;
            Tl = T7 + T8;
            Tk = (((KP500000000) * (T9)) + (T6));
        }
        {
            E Tb, Tc, Td, Te;
            Tb = R0[(rs[2])];
            Tc = R1[0];
            Td = R1[(rs[3])];
            Te = Tc + Td;
            Tf = Tb - Te;
            Ti = (((KP500000000) * (Te)) + (Tb));
            Th = Tc - Td;
        }
        Ci[(csi[1])] = KP866025403 * (Tf - Ta);
        T5 = T1 - T4;
        Tg = Ta + Tf;
        Cr[(csr[1])] = ((T5) - ((KP500000000) * (Tg)));
        Cr[(csr[4])] = T5 + Tg;
        {
            E Tr, Tt, Tw, Tv, Tu, Tp, Tq, Ts, Tj, Tm, Tn;
            Tr = (((KP500000000) * (T4)) + (T1));
            Tt = (((KP296198132) * (Th)) + (KP939692620 * Ti));
            Tw = ((KP342020143 * Ti) - ((KP813797681) * (Th)));
            Tv = ((KP150383733 * Tl) - ((KP984807753) * (Tk)));
            Tu = (((KP173648177) * (Tk)) + (KP852868531 * Tl));
            Tp = ((KP766044443 * Tk) - ((KP556670399) * (Tl)));
            Tq = (((KP852868531) * (Th)) + (KP173648177 * Ti));
            Ts = Tp + Tq;
            Tj = ((KP150383733 * Th) - ((KP984807753) * (Ti)));
            Tm = (((KP642787609) * (Tk)) + (KP663413948 * Tl));
            Tn = Tj - Tm;
            Ci[0] = ((Tn) - ((KP866025403) * (To)));
            Cr[0] = Tr + Ts;
            Ci[(csi[3])] = ((KP866025403 * ((Tp - Tq) - To)) - ((KP500000000) * (Tn)));
            Cr[(csr[3])] = (((KP866025403) * (Tm + Tj)) + (Tr)) - (KP500000000 * Ts);
            Ci[(csi[2])] = (((KP866025403) * (To - (Tu + Tt))) + (KP500000000 * (Tw - Tv)));
            Cr[(csr[2])] = (((KP500000000) * (Tt - Tu)) + (Tr)) + (KP866025403 * (Tv + Tw));
        }
    }
}
}
