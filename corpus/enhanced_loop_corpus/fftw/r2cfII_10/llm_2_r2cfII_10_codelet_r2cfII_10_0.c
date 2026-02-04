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
    INT idx_r2 = rs[2], idx_r3 = rs[3], idx_r4 = rs[4], idx_r1 = rs[1];
    INT idx_cs2 = csr[2], idx_cs4 = csr[4], idx_cs3 = csr[3], idx_cs1 = csr[1];
    INT idx_ci2 = csi[2], idx_ci3 = csi[3], idx_ci4 = csi[4], idx_ci1 = csi[1];

    T1 = R0[0];
    To = R1[idx_r2];

    {
        E T2, T3, T4, T5, T6, T7;
        T2 = R0[idx_r2];
        T3 = R0[idx_r3];
        T4 = T2 - T3;
        T5 = R0[idx_r4];
        T6 = R0[idx_r1];
        T7 = T5 - T6;
        T8 = T4 + T7;
        Tq = T5 + T6;
        T9 = KP559016994 * (T4 - T7);
        Tp = T2 + T3;
    }

    {
        E Tc, Td, Tm, Tf, Tg, Tl;
        Tc = R1[0];
        Td = R1[idx_r4];
        Tm = Tc + Td;
        Tf = R1[idx_r1];
        Tg = R1[idx_r3];
        Tl = Tf + Tg;
        Te = Tc - Td;
        Ts = KP559016994 * (Tm + Tl);
        Th = Tf - Tg;
        Tn = Tl - Tm;
    }

    Cr[idx_cs2] = T1 + T8;
    Ci[idx_ci2] = Tn - To;

    {
        E Ti, Tk, Tb, Tj, Ta;
        Ti = (((KP951056516) * (Te)) + (KP587785252 * Th));
        Tk = ((KP951056516 * Th) - ((KP587785252) * (Te)));
        Ta = ((T1) - ((KP250000000) * (T8)));
        Tb = T9 + Ta;
        Tj = Ta - T9;
        Cr[idx_cs4] = Tb - Ti;
        Cr[idx_cs3] = Tj + Tk;
        Cr[0] = Tb + Ti;
        Cr[idx_cs1] = Tj - Tk;
    }

    {
        E Tr, Tw, Tu, Tv, Tt;
        Tr = (((KP951056516) * (Tp)) + (KP587785252 * Tq));
        Tw = ((KP951056516 * Tq) - ((KP587785252) * (Tp)));
        Tt = (((KP250000000) * (Tn)) + (To));
        Tu = Ts + Tt;
        Tv = Tt - Ts;
        Ci[0] = -(Tr + Tu);
        Ci[idx_ci3] = Tw + Tv;
        Ci[idx_ci4] = Tr - Tu;
        Ci[idx_ci1] = Tv - Tw;
    }
}
}
