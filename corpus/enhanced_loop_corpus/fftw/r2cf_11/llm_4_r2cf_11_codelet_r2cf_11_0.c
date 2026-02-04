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
extern  E KP654860733;
extern  E KP142314838;
extern  E KP959492973;
extern  E KP415415013;
extern  E KP841253532;
extern  E KP989821441;
extern  E KP909631995;
extern  E KP281732556;
extern  E KP540640817;
extern  E KP755749574;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, T4, Tl, Tg, Th, Td, Ti, Ta, Tk, T7, Tj, Tb, Tc;
    E *base_R0 = R0;
    E *base_R1 = R1;
    E *base_Cr = Cr;
    E *base_Ci = Ci;

    T1 = base_R0[0];
    {
        E T2, T3, Te, Tf;
        T2 = base_R0[rs[1]];
        T3 = base_R1[rs[4]];
        T4 = T2 + T3;
        Tl = T3 - T2;
        Te = base_R1[0];
        Tf = base_R0[rs[5]];
        Tg = Te + Tf;
        Th = Tf - Te;
    }
    Tb = base_R1[rs[1]];
    Tc = base_R0[rs[4]];
    Td = Tb + Tc;
    Ti = Tc - Tb;
    {
        E T8, T9, T5, T6;
        T8 = base_R1[rs[2]];
        T9 = base_R0[rs[3]];
        Ta = T8 + T9;
        Tk = T9 - T8;
        T5 = base_R0[rs[2]];
        T6 = base_R1[rs[3]];
        T7 = T5 + T6;
        Tj = T6 - T5;
    }

    base_Ci[4*ovs] = (((KP755749574) * (Th)) + (KP540640817 * Ti)) + ((KP281732556 * Tj) - ((KP909631995) * (Tk))) - (KP989821441 * Tl);
    base_Cr[4*ovs] = (((KP841253532) * (Td)) + (T1)) + ((KP415415013 * Ta) - ((KP959492973) * (T7))) + (-(((KP142314838) * (T4)) + (KP654860733 * Tg)));
    base_Ci[2*ovs] = (((KP909631995) * (Th)) + (KP755749574 * Tl)) + (-(((KP540640817) * (Tk)) + (KP989821441 * Tj))) - (KP281732556 * Ti);
    base_Ci[5*ovs] = (((KP281732556) * (Th)) + (KP755749574 * Ti)) + ((KP989821441 * Tk) - ((KP909631995) * (Tj))) - (KP540640817 * Tl);
    base_Ci[1*ovs] = (((KP540640817) * (Th)) + (KP909631995 * Tl)) + (((KP989821441) * (Ti)) + (KP755749574 * Tj)) + (KP281732556 * Tk);
    base_Ci[3*ovs] = (((KP989821441) * (Th)) + (KP540640817 * Tj)) + ((KP755749574 * Tk) - ((KP909631995) * (Ti))) - (KP281732556 * Tl);
    base_Cr[3*ovs] = (((KP415415013) * (Td)) + (T1)) + ((KP841253532 * T7) - ((KP654860733) * (Ta))) + (-(((KP959492973) * (T4)) + (KP142314838 * Tg)));
    base_Cr[1*ovs] = (((KP841253532) * (Tg)) + (T1)) + ((KP415415013 * T4) - ((KP959492973) * (Ta))) + (-(((KP654860733) * (T7)) + (KP142314838 * Td)));
    base_Cr[0] = T1 + Tg + T4 + Td + T7 + Ta;
    base_Cr[2*ovs] = (((KP415415013) * (Tg)) + (T1)) + ((KP841253532 * Ta) - ((KP142314838) * (T7))) + (-(((KP959492973) * (Td)) + (KP654860733 * T4)));
    base_Cr[5*ovs] = (((KP841253532) * (T4)) + (T1)) + ((KP415415013 * T7) - ((KP142314838) * (Ta))) + (-(((KP654860733) * (Td)) + (KP959492973 * Tg)));
}
}
