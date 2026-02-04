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
extern  E KP382683432;
extern  E KP923879532;
extern  E KP707106781;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 2 , R0 = R0 + 2*ivs , R1 = R1 + 2*ivs , Cr = Cr + 2*ovs , Ci = Ci + 2*ovs , (rs) = (rs) + 2*fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + 2*fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    if (i < 2) break;
    E T1, Tj, T4, Ti, T8, Te, Tb, Tf, T2, T3;
    E T1b, Tjb, T4b, Tib, T8b, Teb, Tbb, Tfb, T2b, T3b;

    T1 = R0[0];
    Tj = R0[(rs[2])];
    T2 = R0[(rs[1])];
    T3 = R0[(rs[3])];
    T4 = KP707106781 * (T2 - T3);
    Ti = KP707106781 * (T2 + T3);

    T1b = R0[ivs];
    Tjb = R0[ivs + (rs[2])];
    T2b = R0[ivs + (rs[1])];
    T3b = R0[ivs + (rs[3])];
    T4b = KP707106781 * (T2b - T3b);
    Tib = KP707106781 * (T2b + T3b);

    {
        E T6, T7, T9, Ta;
        E T6b, T7b, T9b, Tab;
        T6 = R1[0];
        T7 = R1[(rs[2])];
        T8 = ((KP923879532 * T6) - ((KP382683432) * (T7)));
        Te = (((KP382683432) * (T6)) + (KP923879532 * T7));
        T9 = R1[(rs[1])];
        Ta = R1[(rs[3])];
        Tb = ((KP382683432 * T9) - ((KP923879532) * (Ta)));
        Tf = (((KP923879532) * (T9)) + (KP382683432 * Ta));

        T6b = R1[ivs];
        T7b = R1[ivs + (rs[2])];
        T8b = ((KP923879532 * T6b) - ((KP382683432) * (T7b)));
        Teb = (((KP382683432) * (T6b)) + (KP923879532 * T7b));
        T9b = R1[ivs + (rs[1])];
        Tab = R1[ivs + (rs[3])];
        Tbb = ((KP382683432 * T9b) - ((KP923879532) * (Tab)));
        Tfb = (((KP923879532) * (T9b)) + (KP382683432 * Tab));
    }
    {
        E T5, Tc, Th, Tk;
        E T5b, Tcb, Thb, Tkb;
        T5 = T1 + T4;
        Tc = T8 + Tb;
        Cr[(csr[3])] = T5 - Tc;
        Cr[0] = T5 + Tc;
        Th = Te + Tf;
        Tk = Ti + Tj;
        Ci[0] = -(Th + Tk);
        Ci[(csi[3])] = Tk - Th;

        T5b = T1b + T4b;
        Tcb = T8b + Tbb;
        Cr[(csr[3]) + ovs] = T5b - Tcb;
        Cr[ovs] = T5b + Tcb;
        Thb = Teb + Tfb;
        Tkb = Tib + Tjb;
        Ci[ovs] = -(Thb + Tkb);
        Ci[(csi[3]) + ovs] = Tkb - Thb;
    }
    {
        E Td, Tg, Tl, Tm;
        E Tdb, Tgb, Tlb, Tmb;
        Td = T1 - T4;
        Tg = Te - Tf;
        Cr[(csr[2])] = Td - Tg;
        Cr[(csr[1])] = Td + Tg;
        Tl = Tb - T8;
        Tm = Tj - Ti;
        Ci[(csi[2])] = Tl - Tm;
        Ci[(csi[1])] = Tl + Tm;

        Tdb = T1b - T4b;
        Tgb = Teb - Tfb;
        Cr[(csr[2]) + ovs] = Tdb - Tgb;
        Cr[(csr[1]) + ovs] = Tdb + Tgb;
        Tlb = Tbb - T8b;
        Tmb = Tjb - Tib;
        Ci[(csi[2]) + ovs] = Tlb - Tmb;
        Ci[(csi[1]) + ovs] = Tlb + Tmb;
    }
}
}
