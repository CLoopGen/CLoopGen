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
for (i = v; i > 0; i--) {
    E T3, TB, T6, Tv, Tn, Ts, Tk, Tt, Td, Ty, T9, Tw, Tg, Tz, T1;
    E T2;

    INT base_r0 = 0;
    INT base_r1 = 0;
    INT stride_offset;

    E r0_vals[7], r1_vals[7];

    for (stride_offset = 0; stride_offset < 7; stride_offset++) {
        r0_vals[stride_offset] = R0[base_r0 + rs[stride_offset]];
        r1_vals[stride_offset] = R1[base_r1 + rs[stride_offset]];
    }

    T1 = r0_vals[0];
    T2 = r1_vals[3];
    T3 = T1 - T2;
    TB = T1 + T2;

    T6 = r0_vals[2] - r1_vals[5];
    Tv = r0_vals[2] + r1_vals[5];
    Tn = r0_vals[6] - r1_vals[2];
    Ts = r0_vals[6] + r1_vals[2];

    Tk = r0_vals[1] - r1_vals[4];
    Tt = r0_vals[1] + r1_vals[4];
    Td = r0_vals[3] - r1_vals[6];
    Ty = r0_vals[3] + r1_vals[6];

    T9 = r0_vals[5] - r1_vals[1];
    Tw = r0_vals[5] + r1_vals[1];
    Tg = r0_vals[4] - r1_vals[0];
    Tz = r0_vals[4] + r1_vals[0];

    {
        E Tp = Tn - Tk;
        E Tr = Tg - Td;
        E Tq = T9 - T6;
        E Ta = T6 + T9;
        E To = Tk + Tn;
        E Th = Td + Tg;

        Ci[csi[1]] = KP781831482 * Tp + KP974927912 * Tq + KP433883739 * Tr;
        Ci[csi[5]] = KP433883739 * Tq + KP781831482 * Tr - KP974927912 * Tp;
        Ci[csi[3]] = KP433883739 * Tp + KP974927912 * Tr - KP781831482 * Tq;

        Cr[csr[3]] = KP623489801 * Ta + T3 - (KP222520933 * Th + KP900968867 * To);
        Cr[csr[7]] = T3 + To + Ta + Th;
        Cr[csr[1]] = KP623489801 * To + T3 - (KP900968867 * Th + KP222520933 * Ta);
        Cr[csr[5]] = KP623489801 * Th + T3 - (KP900968867 * Ta + KP222520933 * To);
    }
    {
        E Tu = Ts - Tt;
        E TA = Ty - Tz;
        E Tx = Tv - Tw;
        E TC = Tt + Ts;
        E TE = Tv + Tw;
        E TD = Ty + Tz;

        Ci[csi[2]] = KP974927912 * Tu + KP433883739 * Tx + KP781831482 * TA;
        Ci[csi[6]] = KP974927912 * Tx + KP433883739 * TA - KP781831482 * Tu;
        Ci[csi[4]] = KP974927912 * TA - KP781831482 * Tx - KP433883739 * Tu;

        Cr[csr[6]] = KP623489801 * TC + TB - (KP900968867 * TD + KP222520933 * TE);
        Cr[csr[2]] = KP623489801 * TD + TB - (KP900968867 * TE + KP222520933 * TC);
        Cr[csr[4]] = KP623489801 * TE + TB - (KP222520933 * TD + KP900968867 * TC);
        Cr[0] = TB + TC + TE + TD;
    }

    R0 += ivs;
    R1 += ivs;
    Cr += ovs;
    Ci += ovs;
}
}
