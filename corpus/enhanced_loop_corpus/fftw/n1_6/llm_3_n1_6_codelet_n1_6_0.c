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
extern  E KP866025403;
extern  E KP500000000;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , ri = ri + ivs , ii = ii + ivs , ro = ro + ovs , io = io + ovs , (is) = (is) + fftw_an_INT_guaranteed_to_be_zero , (os) = (os) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, Tb, Tq, Tx, T6, Tc, T9, Td, Ta, Te, Ti, Tu, Tl, Tv, Tr;
    E Ty;
    // Change memory access pattern to use consecutive array layout with precomputed indices
    // Assume input/output are now stored in interleaved format: [re0, im0, re1, im1, ...]
    // Use local arrays to gather data first for better locality

    E rin[6], iin[6];
    for (INT j = 0; j < 6; ++j) {
        INT idx_r = is[j];
        rin[j] = ri[idx_r];
        iin[j] = ii[idx_r];
    }

    {
        E T1, T2, To, Tp;
        T1 = rin[0];
        T2 = rin[3];
        T3 = T1 - T2;
        Tb = T1 + T2;
        To = iin[0];
        Tp = iin[3];
        Tq = To - Tp;
        Tx = To + Tp;
    }
    {
        E T4, T5, T7, T8;
        T4 = rin[2];
        T5 = rin[5];
        T6 = T4 - T5;
        Tc = T4 + T5;
        T7 = rin[4];
        T8 = rin[1];
        T9 = T7 - T8;
        Td = T7 + T8;
    }
    Ta = T6 + T9;
    Te = Tc + Td;
    {
        E Tg, Th, Tj, Tk;
        Tg = iin[2];
        Th = iin[5];
        Ti = Tg - Th;
        Tu = Tg + Th;
        Tj = iin[4];
        Tk = iin[1];
        Tl = Tj - Tk;
        Tv = Tj + Tk;
    }
    Tr = Ti + Tl;
    Ty = Tu + Tv;

    // Scatter results using precomputed os indices
    ro[is[3]] = T3 + Ta;
    io[is[3]] = Tq + Tr;
    ro[0] = Tb + Te;
    io[0] = Tx + Ty;

    {
        E Tf, Tm, Tn, Ts;
        Tf = T3 - KP500000000 * Ta;
        Tm = KP866025403 * (Ti - Tl);
        ro[is[5]] = Tf - Tm;
        ro[is[1]] = Tf + Tm;
        Tn = KP866025403 * (T9 - T6);
        Ts = Tq - KP500000000 * Tr;
        io[is[1]] = Tn + Ts;
        io[is[5]] = Ts - Tn;
    }
    {
        E Tt, Tw, Tz, TA;
        Tt = Tb - KP500000000 * Te;
        Tw = KP866025403 * (Tu - Tv);
        ro[is[2]] = Tt - Tw;
        ro[is[4]] = Tt + Tw;
        Tz = Tx - KP500000000 * Ty;
        TA = KP866025403 * (Td - Tc);
        io[is[2]] = Tz - TA;
        io[is[4]] = TA + Tz;
    }
}
}
