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
extern  E KP866025403;
extern  E KP500000000;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T5, Tp, Tb, Tn, Ty, Tt, Ta, Tq, Tc, Ti, Tz, Tu, Td, To;
    INT idx_r[6], idx_csr[7], idx_csi[7];

    // Precompute indirect indices using base pointer offsets
    for (INT j = 0; j < 6; ++j) idx_r[j] = rs[j];
    for (INT j = 0; j < 7; ++j) {
        idx_csr[j] = csr[j];
        idx_csi[j] = csi[j];
    }

    {
        E T1, T2, T3, T4;
        T1 = R0[0];
        T2 = R0[idx_r[2]];
        T3 = R0[idx_r[4]];
        T4 = T2 + T3;
        T5 = T1 + T4;
        Tp = T1 - KP500000000 * T4;
        Tb = T3 - T2;
    }
    {
        E Tj, Tk, Tl, Tm;
        Tj = R1[idx_r[1]];
        Tk = R1[idx_r[3]];
        Tl = R1[idx_r[5]];
        Tm = Tk + Tl;
        Tn = Tj - KP500000000 * Tm;
        Ty = Tl - Tk;
        Tt = Tj + Tm;
    }
    {
        E T6, T7, T8, T9;
        T6 = R0[idx_r[3]];
        T7 = R0[idx_r[5]];
        T8 = R0[idx_r[1]];
        T9 = T7 + T8;
        Ta = T6 + T9;
        Tq = T6 - KP500000000 * T9;
        Tc = T8 - T7;
    }
    {
        E Te, Tf, Tg, Th;
        Te = R1[idx_r[4]];
        Tf = R1[0];
        Tg = R1[idx_r[2]];
        Th = Tf + Tg;
        Ti = Te - KP500000000 * Th;
        Tz = Tg - Tf;
        Tu = Te + Th;
    }

    Cr[idx_csr[3]] = T5 - Ta;
    Ci[idx_csi[3]] = Tt - Tu;
    Td = KP866025403 * (Tb - Tc);
    To = Ti - Tn;
    Ci[idx_csi[1]] = Td + To;
    Ci[idx_csi[5]] = To - Td;

    {
        E Tx, TA, Tv, Tw;
        Tx = Tp - Tq;
        TA = KP866025403 * (Ty - Tz);
        Cr[idx_csr[5]] = Tx - TA;
        Cr[idx_csr[1]] = Tx + TA;
        Tv = T5 + Ta;
        Tw = Tt + Tu;
        Cr[idx_csr[6]] = Tv - Tw;
        Cr[0] = Tv + Tw;
    }
    {
        E Tr, Ts, TB, TC;
        Tr = Tp + Tq;
        Ts = Tn + Ti;
        Cr[idx_csr[2]] = Tr - Ts;
        Cr[idx_csr[4]] = Tr + Ts;
        TB = Ty + Tz;
        TC = Tb + Tc;
        Ci[idx_csi[2]] = KP866025403 * (TB - TC);
        Ci[idx_csi[4]] = KP866025403 * (TC + TB);
    }
}
}
