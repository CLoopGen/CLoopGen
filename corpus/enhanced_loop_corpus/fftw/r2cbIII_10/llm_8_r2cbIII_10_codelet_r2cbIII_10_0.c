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
for (i = v; i > 0; i = i - 2 , R0 = R0 + 2*ovs , R1 = R1 + 2*ovs , Cr = Cr + 2*ivs , Ci = Ci + 2*ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    if (i < 2) break;
    E T1, To, T8, Tq, Ta, Tp, Te, Ts, Th, Tn;
    E T1b, Tob, T8b, Tqb, Tab, Tpb, Teb, Tsb, Thb, Tnb;

    // First iteration (original)
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
    R0[0] = KP2_000000000 * (T1 + T8);
    R1[(rs[2])] = KP2_000000000 * (Tn - To);
    {
        E Ti, Tj, Tb, Tk, T9;
        Ti = ((KP1_175570504 * Te) - ((KP1_902113032) * (Th)));
        Tj = (((KP1_175570504) * (Th)) + (KP1_902113032 * Te));
        T9 = ((KP500000000 * T8) - ((KP2_000000000) * (T1)));
        Tb = T9 - Ta;
        Tk = T9 + Ta;
        R0[(rs[1])] = Tb + Ti;
        R0[(rs[3])] = Tk + Tj;
        R0[(rs[4])] = Ti - Tb;
        R0[(rs[2])] = Tj - Tk;
    }
    {
        E Tr, Tv, Tu, Tw, Tt;
        Tr = (((KP1_902113032) * (Tp)) + (KP1_175570504 * Tq));
        Tv = ((KP1_902113032 * Tq) - ((KP1_175570504) * (Tp)));
        Tt = (((KP500000000) * (Tn)) + (KP2_000000000 * To));
        Tu = Ts + Tt;
        Tw = Tt - Ts;
        R1[0] = -(Tr + Tu);
        R1[(rs[3])] = Tw - Tv;
        R1[(rs[4])] = Tr - Tu;
        R1[(rs[1])] = Tv + Tw;
    }

    // Second iteration (unrolled)
    T1b = Cr[(csr[2]) + ivs];
    Tob = Ci[(csi[2]) + ivs];
    {
        E T2b, T3b, T4b, T5b, T6b, T7b;
        T2b = Cr[(csr[4]) + ivs];
        T3b = Cr[ivs];
        T4b = T2b + T3b;
        T5b = Cr[(csr[3]) + ivs];
        T6b = Cr[(csr[1]) + ivs];
        T7b = T5b + T6b;
        T8b = T4b + T7b;
        Tqb = T5b - T6b;
        Tab = KP1_118033988 * (T7b - T4b);
        Tpb = T2b - T3b;
    }
    {
        E Tcb, Tdb, Tmb, Tfb, Tgb, Tlb;
        Tcb = Ci[(csi[4]) + ivs];
        Tdb = Ci[ivs];
        Tmb = Tcb + Tdb;
        Tfb = Ci[(csi[1]) + ivs];
        Tgb = Ci[(csi[3]) + ivs];
        Tlb = Tgb + Tfb;
        Teb = Tcb - Tdb;
        Tsb = KP1_118033988 * (Tlb + Tmb);
        Thb = Tfb - Tgb;
        Tnb = Tlb - Tmb;
    }
    R0[ovs] = KP2_000000000 * (T1b + T8b);
    R1[(rs[2]) + ovs] = KP2_000000000 * (Tnb - Tob);
    {
        E Tib, Tjb, Tbb, Tkb, T9b;
        Tib = ((KP1_175570504 * Teb) - ((KP1_902113032) * (Thb)));
        Tjb = (((KP1_175570504) * (Thb)) + (KP1_902113032 * Teb));
        T9b = ((KP500000000 * T8b) - ((KP2_000000000) * (T1b)));
        Tbb = T9b - Tab;
        Tkb = T9b + Tab;
        R0[(rs[1]) + ovs] = Tbb + Tib;
        R0[(rs[3]) + ovs] = Tkb + Tjb;
        R0[(rs[4]) + ovs] = Tib - Tbb;
        R0[(rs[2]) + ovs] = Tjb - Tkb;
    }
    {
        E Trb, Tvb, Tub, Twb, Ttb;
        Trb = (((KP1_902113032) * (Tpb)) + (KP1_175570504 * Tqb));
        Tvb = ((KP1_902113032 * Tqb) - ((KP1_175570504) * (Tpb)));
        Ttb = (((KP500000000) * (Tnb)) + (KP2_000000000 * Tob));
        Tub = Tsb + Ttb;
        Twb = Ttb - Tsb;
        R1[ovs] = -(Trb + Tub);
        R1[(rs[3]) + ovs] = Twb - Tvb;
        R1[(rs[4]) + ovs] = Trb - Tub;
        R1[(rs[1]) + ovs] = Tvb + Twb;
    }
}
}
