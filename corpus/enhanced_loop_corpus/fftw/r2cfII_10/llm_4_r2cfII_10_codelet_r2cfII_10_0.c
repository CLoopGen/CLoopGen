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
extern  E KP587785252;
extern  E KP951056516;
extern  E KP559016994;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, To, T8, Tq, T9, Tp, Te, Ts, Th, Tn;
    T1 = R0[0];
    To = R1[(rs[2])];
    {
        E T2, T3, T4, T5, T6, T7;
        T2 = R0[(rs[2])];
        T3 = R0[(rs[3])];
        T4 = T2 - T3;
        T5 = R0[(rs[4])];
        T6 = R0[(rs[1])];
        T7 = T5 - T6;
        T8 = T4 + T7;
        Tq = T5 + T6;
        T9 = KP559016994 * (T4 - T7);
        Tp = T2 + T3;
    }
    {
        E Tc, Td, Tm, Tf, Tg, Tl;
        Tc = R1[0];
        Td = R1[(rs[4])];
        Tm = Tc + Td;
        Tf = R1[(rs[1])];
        Tg = R1[(rs[3])];
        Tl = Tf + Tg;
        Te = Tc - Td;
        Ts = KP559016994 * (Tm + Tl);
        Th = Tf - Tg;
        Tn = Tl - Tm;
    }
    // Introduce WAW dependency by reordering and delaying Cr/Ci updates
    E temp_Cr2 = T1 + T8;
    E temp_Ci2 = Tn - To;

    {
        E Ti, Tk, Tb, Tj, Ta;
        Ti = (((KP951056516) * (Te)) + (KP587785252 * Th));
        Tk = ((KP951056516 * Th) - ((KP587785252) * (Te)));
        Ta = ((T1) - ((KP250000000) * (T8)));
        Tb = T9 + Ta;
        Tj = Ta - T9;
        // Reorder writes to eliminate early write of Cr[0], introduce dependency via temp
        Cr[(csr[4])] = Tb - Ti;
        Cr[(csr[3])] = Tj + Tk;
        Cr[(csr[1])] = Tj - Tk;
        Cr[0] = Tb + Ti;
    }
    {
        E Tr, Tw, Tu, Tv, Tt;
        Tr = (((KP951056516) * (Tp)) + (KP587785252 * Tq));
        Tw = ((KP951056516 * Tq) - ((KP587785252) * (Tp)));
        Tt = (((KP250000000) * (Tn)) + (To));
        Tu = Ts + Tt;
        Tv = Tt - Ts;
        Ci[(csi[3])] = Tw + Tv;
        Ci[(csi[4])] = Tr - Tu;
        Ci[(csi[1])] = Tv - Tw;
        Ci[0] = -(Tr + Tu);
    }
    // Finalize delayed stores with RAW/WAW dependencies now resolved
    Cr[(csr[2])] = temp_Cr2;
    Ci[(csi[2])] = temp_Ci2;
}
}
