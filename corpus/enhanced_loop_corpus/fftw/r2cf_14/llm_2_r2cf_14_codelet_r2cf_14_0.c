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
extern  E KP900968867;
extern  E KP222520933;
extern  E KP623489801;
extern  E KP433883739;
extern  E KP974927912;
extern  E KP781831482;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, TB, T6, Tv, Tn, Ts, Tk, Tt, Td, Ty, T9, Tw, Tg, Tz, T1;
    E T2;
    INT idx_r0_0 = rs[0], idx_r0_1 = rs[1], idx_r0_2 = rs[2], idx_r0_3 = rs[3], idx_r0_4 = rs[4], idx_r0_5 = rs[5], idx_r0_6 = rs[6];
    INT idx_r1_0 = 0, idx_r1_1 = rs[1], idx_r1_2 = rs[2], idx_r1_3 = rs[3], idx_r1_4 = rs[4], idx_r1_5 = rs[5], idx_r1_6 = rs[6];

    T1 = R0[idx_r0_0];
    T2 = R1[idx_r1_3];
    T3 = T1 - T2;
    TB = T1 + T2;

    T6 = R0[idx_r0_2] - R1[idx_r1_5];
    Tv = R0[idx_r0_2] + R1[idx_r1_5];
    Tn = R0[idx_r0_6] - R1[idx_r1_2];
    Ts = R0[idx_r0_6] + R1[idx_r1_2];

    Tk = R0[idx_r0_1] - R1[idx_r1_4];
    Tt = R0[idx_r0_1] + R1[idx_r1_4];
    Td = R0[idx_r0_3] - R1[idx_r1_6];
    Ty = R0[idx_r0_3] + R1[idx_r1_6];

    T9 = R0[idx_r0_5] - R1[idx_r1_1];
    Tw = R0[idx_r0_5] + R1[idx_r1_1];
    Tg = R0[idx_r0_4] - R1[idx_r1_0];
    Tz = R0[idx_r0_4] + R1[idx_r1_0];

    {
        E Tp, Tr, Tq, Ta, To, Th;
        Tp = Tn - Tk;
        Tr = Tg - Td;
        Tq = T9 - T6;
        Ci[csi[1]] = KP781831482 * Tp + KP974927912 * Tq + KP433883739 * Tr;
        Ci[csi[5]] = KP433883739 * Tq + KP781831482 * Tr - KP974927912 * Tp;
        Ci[csi[3]] = KP433883739 * Tp + KP974927912 * Tr - KP781831482 * Tq;
        Ta = T6 + T9;
        To = Tk + Tn;
        Th = Td + Tg;
        Cr[csr[3]] = KP623489801 * Ta + T3 - (KP222520933 * Th + KP900968867 * To);
        Cr[csr[7]] = T3 + To + Ta + Th;
        Cr[csr[1]] = KP623489801 * To + T3 - (KP900968867 * Th + KP222520933 * Ta);
        Cr[csr[5]] = KP623489801 * Th + T3 - (KP900968867 * Ta + KP222520933 * To);
    }
    {
        E Tu, TA, Tx, TC, TE, TD;
        Tu = Ts - Tt;
        TA = Ty - Tz;
        Tx = Tv - Tw;
        Ci[csi[2]] = KP974927912 * Tu + KP433883739 * Tx + KP781831482 * TA;
        Ci[csi[6]] = KP974927912 * Tx + KP433883739 * TA - KP781831482 * Tu;
        Ci[csi[4]] = KP974927912 * TA - KP781831482 * Tx - KP433883739 * Tu;
        TC = Tt + Ts;
        TE = Tv + Tw;
        TD = Ty + Tz;
        Cr[csr[6]] = KP623489801 * TC + TB - (KP900968867 * TD + KP222520933 * TE);
        Cr[csr[2]] = KP623489801 * TD + TB - (KP900968867 * TE + KP222520933 * TC);
        Cr[csr[4]] = KP623489801 * TE + TB - (KP222520933 * TD + KP900968867 * TC);
        Cr[0] = TB + TC + TE + TD;
    }
}
}
