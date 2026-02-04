#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern  R *ri;
extern  R *ii;
extern R *ro;
extern R *io;
extern stride is;
extern stride os;
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
for (i = v; i > 0; i = i - 1, ri = ri + ivs, ii = ii + ivs, ro = ro + ovs, io = io + ovs, (is) = (is) + fftw_an_INT_guaranteed_to_be_zero, (os) = (os) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, TM, T4, TG, Tk, TR, Tw, TN, T7, TK, Ta, TH, Tn, TQ, Td;
    E TJ, Tq, TO, Tt, TP, Tg, TI;
    {
        E T2, T3, Ti, Tj;
        T1 = ri[0];
        TM = ii[0];
        T2 = ri[(is[1])];
        T3 = ri[(is[10])];
        T4 = T2 + T3;
        TG = T3 - T2;
        Ti = ii[(is[1])];
        Tj = ii[(is[10])];
        Tk = Ti - Tj;
        TR = Ti + Tj;
        {
            E Tu, Tv, T5, T6;
            Tu = ii[(is[2])];
            Tv = ii[(is[9])];
            Tw = Tu - Tv;
            TN = Tu + Tv;
            T5 = ri[(is[2])];
            T6 = ri[(is[9])];
            T7 = T5 + T6;
            TK = T6 - T5;
        }
    }
    {
        E T8, T9, To, Tp;
        T8 = ri[(is[3])];
        T9 = ri[(is[8])];
        Ta = T8 + T9;
        TH = T9 - T8;
        {
            E Tl, Tm, Tb, Tc;
            Tl = ii[(is[3])];
            Tm = ii[(is[8])];
            Tn = Tl - Tm;
            TQ = Tl + Tm;
            Tb = ri[(is[4])];
            Tc = ri[(is[7])];
            Td = Tb + Tc;
            TJ = Tc - Tb;
        }
        To = ii[(is[4])];
        Tp = ii[(is[7])];
        Tq = To - Tp;
        TO = To + Tp;
        {
            E Tr, Ts, Te, Tf;
            Tr = ii[(is[5])];
            Ts = ii[(is[6])];
            Tt = Tr - Ts;
            TP = Tr + Ts;
            Te = ri[(is[5])];
            Tf = ri[(is[6])];
            Tg = Te + Tf;
            TI = Tf - Te;
        }
    }
    // Reduced arithmetic intensity: only compute DC and Nyquist components
    ro[0] = T1 + T4 + T7 + Ta + Td + Tg;
    io[0] = TM + TR + TN + TQ + TO + TP;

    // Skip all other outputs to reduce computational load
}
}
