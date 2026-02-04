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
for (m = mb , W = W + ((mb - 1) * 8); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 8 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, TE, Tu, Tx, TC, TB, TF, TG, TH, Tc, Tn, To;
    ptrdiff_t r1 = rs[1], r2 = rs[2], r3 = rs[3], r4 = rs[4];
    E *cr_ptr = cr;
    E *ci_ptr = ci;
    E *W_ptr = W;

    T1 = cr_ptr[0];
    TE = ci_ptr[0];

    E T6 = (W_ptr[0] * cr_ptr[r1]) + (W_ptr[1] * ci_ptr[r1]);
    E Ts = (W_ptr[0] * ci_ptr[r1]) - (W_ptr[1] * cr_ptr[r1]);

    E Tm = (W_ptr[4] * cr_ptr[r3]) + (W_ptr[5] * ci_ptr[r3]);
    E Tw = (W_ptr[4] * ci_ptr[r3]) - (W_ptr[5] * cr_ptr[r3]);

    E Tb = (W_ptr[6] * cr_ptr[r4]) + (W_ptr[7] * ci_ptr[r4]);
    E Tt = (W_ptr[6] * ci_ptr[r4]) - (W_ptr[7] * cr_ptr[r4]);

    E Th = (W_ptr[2] * cr_ptr[r2]) + (W_ptr[3] * ci_ptr[r2]);
    E Tv = (W_ptr[2] * ci_ptr[r2]) - (W_ptr[3] * cr_ptr[r2]);

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

    cr_ptr[0] = T1 + To;

    E Ty = (KP951056516 * Tu) + (KP587785252 * Tx);
    E TA = (KP951056516 * Tx) - (KP587785252 * Tu);
    E Tp = KP559016994 * (Tc - Tn);
    E Tq = T1 - (KP250000000 * To);
    E Tr = Tp + Tq;
    E Tz = Tq - Tp;

    ci_ptr[0] = Tr - Ty;
    ci_ptr[r1] = Tz + TA;
    cr_ptr[r1] = Tr + Ty;
    cr_ptr[r2] = Tz - TA;

    ci_ptr[r4] = TH + TE;

    E TD = (KP587785252 * TB) + (KP951056516 * TC);
    E TL = (KP951056516 * TB) - (KP587785252 * TC);
    E TI = TE - (KP250000000 * TH);
    E TJ = KP559016994 * (TF - TG);
    E TK = TI - TJ;
    E TM = TJ + TI;

    cr_ptr[r3] = TD - TK;
    ci_ptr[r3] = TL + TM;
    ci_ptr[r2] = TD + TK;
    cr_ptr[r4] = TL - TM;
}
}
