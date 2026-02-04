#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *cr;
extern R *ci;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP250000000;
extern  E KP559016994;
extern  E KP587785252;
extern  E KP951056516;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
E *cr_base = cr;
E *ci_base = ci;
stride rs_base = rs;
ptrdiff_t r1, r2, r3, r4;

for (m = mb , W = W + ((mb - 1) * 8); m < me; m = m + 1 , W = W + 8 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    r1 = rs_base[1]; r2 = rs_base[2]; r3 = rs_base[3]; r4 = rs_base[4];
    E T1, TE, Tu, Tx, TC, TB, TF, TG, TH, Tc, Tn, To;

    INT idx0 = (m - mb) * ms;
    E *cr_offset = &cr_base[idx0];
    E *ci_offset = &ci_base[idx0];

    T1 = cr_offset[0];
    TE = ci_offset[0];

    E T6 = W[0] * cr_offset[r1] + W[1] * ci_offset[r1];
    E Ts = W[0] * ci_offset[r1] - W[1] * cr_offset[r1];

    E Tm = W[4] * cr_offset[r3] + W[5] * ci_offset[r3];
    E Tw = W[4] * ci_offset[r3] - W[5] * cr_offset[r3];

    E Tb = W[6] * cr_offset[r4] + W[7] * ci_offset[r4];
    E Tt = W[6] * ci_offset[r4] - W[7] * cr_offset[r4];

    E Th = W[2] * cr_offset[r2] + W[3] * ci_offset[r2];
    E Tv = W[2] * ci_offset[r2] - W[3] * cr_offset[r2];

    Tu = Ts - Tt;
    Tx = Tv - Tw;
    TC = Th - Tm;
    TB = Tb - T6;
    TF = Ts + Tt;
    TG = Tv + Tw;
    TH = TF + TG;
    Tc = T6 + Tb;
    Tn = Th + Tm;
    To = Tc + Tn;

    cr_offset[0] = T1 + To;

    E Ty = KP951056516 * Tu + KP587785252 * Tx;
    E TA = KP951056516 * Tx - KP587785252 * Tu;
    E Tp = KP559016994 * (Tc - Tn);
    E Tq = T1 - KP250000000 * To;
    E Tr = Tp + Tq;
    E Tz = Tq - Tp;

    ci_offset[0] = Tr - Ty;
    ci_offset[r1] = Tz + TA;
    cr_offset[r1] = Tr + Ty;
    cr_offset[r2] = Tz - TA;

    ci_offset[r4] = TH + TE;

    E TD = KP587785252 * TB + KP951056516 * TC;
    E TL = KP951056516 * TB - KP587785252 * TC;
    E TI = TE - KP250000000 * TH;
    E TJ = KP559016994 * (TF - TG);
    E TK = TI - TJ;
    E TM = TJ + TI;

    cr_offset[r3] = TD - TK;
    ci_offset[r3] = TL + TM;
    ci_offset[r2] = TD + TK;
    cr_offset[r4] = TL - TM;
}
}
