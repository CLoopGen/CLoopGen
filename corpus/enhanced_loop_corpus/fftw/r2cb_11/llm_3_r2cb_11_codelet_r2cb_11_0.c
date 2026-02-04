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
extern  E KP2_000000000;
extern  E KP1_918985947;
extern  E KP1_309721467;
extern  E KP284629676;
extern  E KP830830026;
extern  E KP1_682507065;
extern  E KP563465113;
extern  E KP1_511499148;
extern  E KP1_979642883;
extern  E KP1_819263990;
extern  E KP1_081281634;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ovs , R1 = R1 + ovs , Cr = Cr + ivs , Ci = Ci + ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E Td, Tl, Tf, Th, Tj, T1, T2, T6, T5, T4, T3, T7, Tk, Te, Tg;
    E Ti;
    // Use strided access with fixed stride offsets instead of indexed arrays
    const INT s_csr = csr[1]; // Assume regular stride for Cr
    const INT s_csi = csi[1]; // Assume regular stride for Ci
    const INT s_rs = rs[1];   // Base output stride

    {
        E T8, Tc, T9, Ta, Tb;
        T8 = Ci[2 * s_csi];
        Tc = Ci[1 * s_csi];
        T9 = Ci[4 * s_csi];
        Ta = Ci[5 * s_csi];
        Tb = Ci[3 * s_csi];
        Td = (((KP1_081281634) * (T8)) + (KP1_819263990 * T9)) + (-(((KP1_979642883) * (Ta)) + (KP1_511499148 * Tb))) - (KP563465113 * Tc);
        Tl = (((KP1_979642883) * (T8)) + (KP1_819263990 * Ta)) + (-(((KP563465113) * (T9)) + (KP1_081281634 * Tb))) - (KP1_511499148 * Tc);
        Tf = (((KP563465113) * (T8)) + (KP1_819263990 * Tb)) + (-(((KP1_511499148) * (Ta)) + (KP1_081281634 * T9))) - (KP1_979642883 * Tc);
        Th = (((KP1_081281634) * (Tc)) + (KP1_819263990 * T8)) + (((KP1_979642883) * (Tb)) + (KP1_511499148 * T9)) + (KP563465113 * Ta);
        Tj = (((KP563465113) * (Tb)) + (KP1_979642883 * T9)) + ((KP1_081281634 * Ta) - ((KP1_511499148) * (T8))) - (KP1_819263990 * Tc);
    }
    T1 = Cr[0];
    T2 = Cr[s_csr];
    T6 = Cr[5 * s_csr];
    T5 = Cr[4 * s_csr];
    T4 = Cr[3 * s_csr];
    T3 = Cr[2 * s_csr];
    T7 = (((KP1_682507065) * (T3)) + (T1)) + ((KP830830026 * T5) - ((KP284629676) * (T6))) + (-(((KP1_309721467) * (T4)) + (KP1_918985947 * T2)));
    Tk = (((KP1_682507065) * (T4)) + (T1)) + ((KP830830026 * T6) - ((KP1_918985947) * (T5))) + (-(((KP284629676) * (T3)) + (KP1_309721467 * T2)));
    Te = (((KP830830026) * (T4)) + (T1)) + ((KP1_682507065 * T5) - ((KP1_309721467) * (T6))) + (-(((KP1_918985947) * (T3)) + (KP284629676 * T2)));
    Tg = (((KP1_682507065) * (T2)) + (T1)) + ((KP830830026 * T3) - ((KP1_918985947) * (T6))) + (-(((KP1_309721467) * (T5)) + (KP284629676 * T4)));
    Ti = (((KP830830026) * (T2)) + (T1)) + ((KP1_682507065 * T6) - ((KP284629676) * (T5))) + (-(((KP1_918985947) * (T4)) + (KP1_309721467 * T3)));
    R0[3 * s_rs] = T7 - Td;
    R0[4 * s_rs] = Te - Tf;
    R0[2 * s_rs] = Tk + Tl;
    R1[2 * s_rs] = T7 + Td;
    R1[3 * s_rs] = Tk - Tl;
    R0[1 * s_rs] = Ti + Tj;
    R1[1 * s_rs] = Te + Tf;
    R0[5 * s_rs] = Tg + Th;
    R1[0] = Tg - Th;
    R1[4 * s_rs] = Ti - Tj;
    R0[0] = (((KP2_000000000) * (T2 + T3 + T4 + T5 + T6)) + (T1));
}
}
