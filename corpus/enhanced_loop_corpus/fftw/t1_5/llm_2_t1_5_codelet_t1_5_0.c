#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *ri;
extern R *ii;
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
for (m = mb , W = W + (mb * 8); m < me; m = m + 1 , ri = ri + ms , ii = ii + ms , W = W + 8 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, TE, Tu, Tx, TJ, TI, TB, TC, TD, Tc, Tn, To;
    ptrdiff_t s1 = rs[1], s2 = rs[2], s3 = rs[3], s4 = rs[4];
    INT idx_r[5] = {0, s1, s2, s3, s4};
    INT idx_i[5] = {0, s1, s2, s3, s4};

    T1 = ri[idx_r[0]];
    TE = ii[idx_i[0]];

    E T6, Ts, Tm, Tw, Tb, Tt, Th, Tv;
    E T3 = ri[idx_r[1]], T5 = ii[idx_i[1]];
    E T2 = W[0], T4 = W[1];
    T6 = T2 * T3 + T4 * T5;
    Ts = T2 * T5 - T4 * T3;

    E Tj = ri[idx_r[3]], Tl = ii[idx_i[3]];
    E Ti = W[4], Tk = W[5];
    Tm = Ti * Tj + Tk * Tl;
    Tw = Ti * Tl - Tk * Tj;

    E T8 = ri[idx_r[4]], Ta = ii[idx_i[4]];
    E T7 = W[6], T9 = W[7];
    Tb = T7 * T8 + T9 * Ta;
    Tt = T7 * Ta - T9 * T8;

    E Te = ri[idx_r[2]], Tg = ii[idx_i[2]];
    E Td = W[2], Tf = W[3];
    Th = Td * Te + Tf * Tg;
    Tv = Td * Tg - Tf * Te;

    Tu = Ts - Tt;
    Tx = Tv - Tw;
    TJ = Th - Tm;
    TI = T6 - Tb;
    TB = Ts + Tt;
    TC = Tv + Tw;
    TD = TB + TC;
    Tc = T6 + Tb;
    Tn = Th + Tm;
    To = Tc + Tn;

    ri[0] = T1 + To;
    ii[0] = TD + TE;

    E Ty = KP951056516 * Tu + KP587785252 * Tx;
    E TA = KP951056516 * Tx - KP587785252 * Tu;
    E Tp = KP559016994 * (Tc - Tn);
    E Tq = T1 - KP250000000 * To;
    E Tr = Tp + Tq;
    E Tz = Tq - Tp;

    ri[idx_r[4]] = Tr - Ty;
    ri[idx_r[3]] = Tz + TA;
    ri[idx_r[1]] = Tr + Ty;
    ri[idx_r[2]] = Tz - TA;

    E TK = KP951056516 * TI + KP587785252 * TJ;
    E TL = KP951056516 * TJ - KP587785252 * TI;
    E TF = KP559016994 * (TB - TC);
    E TG = TE - KP250000000 * TD;
    E TH = TF + TG;
    E TM = TG - TF;

    ii[idx_i[1]] = TH - TK;
    ii[idx_i[3]] = TM - TL;
    ii[idx_i[4]] = TK + TH;
    ii[idx_i[2]] = TL + TM;
}
}
