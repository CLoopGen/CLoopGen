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
for (i = v; i > 0; i = i - 2 , R0 = R0 + 2*ovs , R1 = R1 + 2*ovs , Cr = Cr + 2*ivs , Ci = Ci + 2*ivs , (rs) = (rs) + 2*fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + 2*fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    E Td, Tl, Tf, Th, Tj, T1, T2, T6, T5, T4, T3, T7, Tk, Te, Tg;
    E Ti;
    E Td2, Tl2, Tf2, Th2, Tj2, T12, T22, T62, T52, T42, T32, T72, Tk2, Te2, Tg2;
    E Ti2;

    // First iteration (original body)
    {
        E T8, Tc, T9, Ta, Tb;
        T8 = Ci[(csi[2])];
        Tc = Ci[(csi[1])];
        T9 = Ci[(csi[4])];
        Ta = Ci[(csi[5])];
        Tb = Ci[(csi[3])];
        Td = (((KP1_081281634) * (T8)) + (KP1_819263990 * T9)) + (-(((KP1_979642883) * (Ta)) + (KP1_511499148 * Tb))) - (KP563465113 * Tc);
        Tl = (((KP1_979642883) * (T8)) + (KP1_819263990 * Ta)) + (-(((KP563465113) * (T9)) + (KP1_081281634 * Tb))) - (KP1_511499148 * Tc);
        Tf = (((KP563465113) * (T8)) + (KP1_819263990 * Tb)) + (-(((KP1_511499148) * (Ta)) + (KP1_081281634 * T9))) - (KP1_979642883 * Tc);
        Th = (((KP1_081281634) * (Tc)) + (KP1_819263990 * T8)) + (((KP1_979642883) * (Tb)) + (KP1_511499148 * T9)) + (KP563465113 * Ta);
        Tj = (((KP563465113) * (Tb)) + (KP1_979642883 * T9)) + ((KP1_081281634 * Ta) - ((KP1_511499148) * (T8))) - (KP1_819263990 * Tc);
    }
    T1 = Cr[0];
    T2 = Cr[(csr[1])];
    T6 = Cr[(csr[5])];
    T5 = Cr[(csr[4])];
    T4 = Cr[(csr[3])];
    T3 = Cr[(csr[2])];
    T7 = (((KP1_682507065) * (T3)) + (T1)) + ((KP830830026 * T5) - ((KP284629676) * (T6))) + (-(((KP1_309721467) * (T4)) + (KP1_918985947 * T2)));
    Tk = (((KP1_682507065) * (T4)) + (T1)) + ((KP830830026 * T6) - ((KP1_918985947) * (T5))) + (-(((KP284629676) * (T3)) + (KP1_309721467 * T2)));
    Te = (((KP830830026) * (T4)) + (T1)) + ((KP1_682507065 * T5) - ((KP1_309721467) * (T6))) + (-(((KP1_918985947) * (T3)) + (KP284629676 * T2)));
    Tg = (((KP1_682507065) * (T2)) + (T1)) + ((KP830830026 * T3) - ((KP1_918985947) * (T6))) + (-(((KP1_309721467) * (T5)) + (KP284629676 * T4)));
    Ti = (((KP830830026) * (T2)) + (T1)) + ((KP1_682507065 * T6) - ((KP284629676) * (T5))) + (-(((KP1_918985947) * (T4)) + (KP1_309721467 * T3)));
    R0[(rs[3])] = T7 - Td;
    R0[(rs[4])] = Te - Tf;
    R0[(rs[2])] = Tk + Tl;
    R1[(rs[2])] = T7 + Td;
    R1[(rs[3])] = Tk - Tl;
    R0[(rs[1])] = Ti + Tj;
    R1[(rs[1])] = Te + Tf;
    R0[(rs[5])] = Tg + Th;
    R1[0] = Tg - Th;
    R1[(rs[4])] = Ti - Tj;
    R0[0] = (((KP2_000000000) * (T2 + T3 + T4 + T5 + T6)) + (T1));

    if (i == 1) continue; // Skip second iteration if odd trip count

    // Second iteration (unrolled)
    {
        E T8, Tc, T9, Ta, Tb;
        T8 = Ci[(csi[2])+ivs];
        Tc = Ci[(csi[1])+ivs];
        T9 = Ci[(csi[4])+ivs];
        Ta = Ci[(csi[5])+ivs];
        Tb = Ci[(csi[3])+ivs];
        Td2 = (((KP1_081281634) * (T8)) + (KP1_819263990 * T9)) + (-(((KP1_979642883) * (Ta)) + (KP1_511499148 * Tb))) - (KP563465113 * Tc);
        Tl2 = (((KP1_979642883) * (T8)) + (KP1_819263990 * Ta)) + (-(((KP563465113) * (T9)) + (KP1_081281634 * Tb))) - (KP1_511499148 * Tc);
        Tf2 = (((KP563465113) * (T8)) + (KP1_819263990 * Tb)) + (-(((KP1_511499148) * (Ta)) + (KP1_081281634 * T9))) - (KP1_979642883 * Tc);
        Th2 = (((KP1_081281634) * (Tc)) + (KP1_819263990 * T8)) + (((KP1_979642883) * (Tb)) + (KP1_511499148 * T9)) + (KP563465113 * Ta);
        Tj2 = (((KP563465113) * (Tb)) + (KP1_979642883 * T9)) + ((KP1_081281634 * Ta) - ((KP1_511499148) * (T8))) - (KP1_819263990 * Tc);
    }
    T12 = Cr[ivs];
    T22 = Cr[(csr[1])+ivs];
    T62 = Cr[(csr[5])+ivs];
    T52 = Cr[(csr[4])+ivs];
    T42 = Cr[(csr[3])+ivs];
    T32 = Cr[(csr[2])+ivs];
    T72 = (((KP1_682507065) * (T32)) + (T12)) + ((KP830830026 * T52) - ((KP284629676) * (T62))) + (-(((KP1_309721467) * (T42)) + (KP1_918985947 * T22)));
    Tk2 = (((KP1_682507065) * (T42)) + (T12)) + ((KP830830026 * T62) - ((KP1_918985947) * (T52))) + (-(((KP284629676) * (T32)) + (KP1_309721467 * T22)));
    Te2 = (((KP830830026) * (T42)) + (T12)) + ((KP1_682507065 * T52) - ((KP1_309721467) * (T62))) + (-(((KP1_918985947) * (T32)) + (KP284629676 * T22)));
    Tg2 = (((KP1_682507065) * (T22)) + (T12)) + ((KP830830026 * T32) - ((KP1_918985947) * (T62))) + (-(((KP1_309721467) * (T52)) + (KP284629676 * T42)));
    Ti2 = (((KP830830026) * (T22)) + (T12)) + ((KP1_682507065 * T62) - ((KP284629676) * (T52))) + (-(((KP1_918985947) * (T42)) + (KP1_309721467 * T32)));
    R0[(rs[3])+ovs] = T72 - Td2;
    R0[(rs[4])+ovs] = Te2 - Tf2;
    R0[(rs[2])+ovs] = Tk2 + Tl2;
    R1[(rs[2])+ovs] = T72 + Td2;
    R1[(rs[3])+ovs] = Tk2 - Tl2;
    R0[(rs[1])+ovs] = Ti2 + Tj2;
    R1[(rs[1])+ovs] = Te2 + Tf2;
    R0[(rs[5])+ovs] = Tg2 + Th2;
    R1[ovs] = Tg2 - Th2;
    R1[(rs[4])+ovs] = Ti2 - Tj2;
    R0[ovs] = (((KP2_000000000) * (T22 + T32 + T42 + T52 + T62)) + (T12));
}
}
