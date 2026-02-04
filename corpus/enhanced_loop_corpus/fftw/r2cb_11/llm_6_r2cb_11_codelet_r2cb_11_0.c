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
    E temp_ci[6], temp_cr[6];
    
    // Introduce local caching to remove immediate RAW dependencies on memory
    temp_ci[2] = Ci[(csi[2])];
    temp_ci[1] = Ci[(csi[1])];
    temp_ci[4] = Ci[(csi[4])];
    temp_ci[5] = Ci[(csi[5])];
    temp_ci[3] = Ci[(csi[3])];
    
    temp_cr[0] = Cr[0];
    temp_cr[1] = Cr[(csr[1])];
    temp_cr[5] = Cr[(csr[5])];
    temp_cr[4] = Cr[(csr[4])];
    temp_cr[3] = Cr[(csr[3])];
    temp_cr[2] = Cr[(csr[2])];

    {
        E T8, Tc, T9, Ta, Tb;
        T8 = temp_ci[2];
        Tc = temp_ci[1];
        T9 = temp_ci[4];
        Ta = temp_ci[5];
        Tb = temp_ci[3];
        Td = (((KP1_081281634) * (T8)) + (KP1_819263990 * T9)) + (-(((KP1_979642883) * (Ta)) + (KP1_511499148 * Tb))) - (KP563465113 * Tc);
        Tl = (((KP1_979642883) * (T8)) + (KP1_819263990 * Ta)) + (-(((KP563465113) * (T9)) + (KP1_081281634 * Tb))) - (KP1_511499148 * Tc);
        Tf = (((KP563465113) * (T8)) + (KP1_819263990 * Tb)) + (-(((KP1_511499148) * (Ta)) + (KP1_081281634 * T9))) - (KP1_979642883 * Tc);
        Th = (((KP1_081281634) * (Tc)) + (KP1_819263990 * T8)) + (((KP1_979642883) * (Tb)) + (KP1_511499148 * T9)) + (KP563465113 * Ta);
        Tj = (((KP563465113) * (Tb)) + (KP1_979642883 * T9)) + ((KP1_081281634 * Ta) - ((KP1_511499148) * (T8))) - (KP1_819263990 * Tc);
    }
    
    T1 = temp_cr[0];
    T2 = temp_cr[1];
    T6 = temp_cr[5];
    T5 = temp_cr[4];
    T4 = temp_cr[3];
    T3 = temp_cr[2];
    
    T7 = (((KP1_682507065) * (T3)) + (T1)) + ((KP830830026 * T5) - ((KP284629676) * (T6))) + (-(((KP1_309721467) * (T4)) + (KP1_918985947 * T2)));
    Tk = (((KP1_682507065) * (T4)) + (T1)) + ((KP830830026 * T6) - ((KP1_918985947) * (T5))) + (-(((KP284629676) * (T3)) + (KP1_309721467 * T2)));
    Te = (((KP830830026) * (T4)) + (T1)) + ((KP1_682507065 * T5) - ((KP1_309721467) * (T6))) + (-(((KP1_918985947) * (T3)) + (KP284629676 * T2)));
    Tg = (((KP1_682507065) * (T2)) + (T1)) + ((KP830830026 * T3) - ((KP1_918985947) * (T6))) + (-(((KP1_309721467) * (T5)) + (KP284629676 * T4)));
    Ti = (((KP830830026) * (T2)) + (T1)) + ((KP1_682507065 * T6) - ((KP284629676) * (T5))) + (-(((KP1_918985947) * (T4)) + (KP1_309721467 * T3)));
    
    // Reorder stores to change WAW and WAR dependencies
    R1[0] = Tg - Th;
    R0[0] = (((KP2_000000000) * (T2 + T3 + T4 + T5 + T6)) + (T1));
    R0[(rs[3])] = T7 - Td;
    R0[(rs[4])] = Te - Tf;
    R0[(rs[2])] = Tk + Tl;
    R1[(rs[2])] = T7 + Td;
    R1[(rs[3])] = Tk - Tl;
    R0[(rs[1])] = Ti + Tj;
    R1[(rs[1])] = Te + Tf;
    R0[(rs[5])] = Tg + Th;
    R1[(rs[4])] = Ti - Tj;
}
}
