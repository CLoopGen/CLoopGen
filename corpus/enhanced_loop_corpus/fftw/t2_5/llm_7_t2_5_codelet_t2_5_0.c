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
for (m = mb; m < me; m += 2, ri = ri + (ms * 2), ii = ii + (ms * 2), W = W + 8, (rs) = (rs) + (2 * fftw_an_INT_guaranteed_to_be_zero)) {
    for (INT inner = 0; inner < 2 && (m + inner) < me; ++inner) {
        E T2 = W[inner * 4 + 0];
        E T4 = W[inner * 4 + 1];
        E T7 = W[inner * 4 + 2];
        E T9 = W[inner * 4 + 3];
        E T8 = T2 * T7;
        E Te = T4 * T7;
        E Ta = T4 * T9;
        E Td = T2 * T9;
        E Tb = T8 - Ta;
        E Tl = Td - Te;
        E Tf = Td + Te;
        E Tj = T8 + Ta;

        E T1 = ri[inner * ms];
        E TI = ii[inner * ms];

        E T3 = ri[inner * ms + rs[1]];
        E T5 = ii[inner * ms + rs[1]];
        E T6 = T2 * T3 + T4 * T5;
        E Tw = T2 * T5 - T4 * T3;

        E To = ri[inner * ms + rs[3]];
        E Tp = ii[inner * ms + rs[3]];
        E Tq = T7 * To + T9 * Tp;
        E TA = T7 * Tp - T9 * To;

        E Tc = ri[inner * ms + rs[4]];
        E Tg = ii[inner * ms + rs[4]];
        E Th = Tb * Tc + Tf * Tg;
        E Tx = Tb * Tg - Tf * Tc;

        E Tk = ri[inner * ms + rs[2]];
        E Tm = ii[inner * ms + rs[2]];
        E Tn = Tj * Tk + Tl * Tm;
        E Tz = Tj * Tm - Tl * Tk;

        E Ty = Tw - Tx;
        E TB = Tz - TA;
        E TN = Tn - Tq;
        E TM = T6 - Th;
        E TF = Tw + Tx;
        E TG = Tz + TA;
        E TH = TF + TG;
        E Ti = T6 + Th;
        E Tr = Tn + Tq;
        E Ts = Ti + Tr;

        ri[inner * ms] = T1 + Ts;
        ii[inner * ms] = TH + TI;

        E TC = KP951056516 * Ty + KP587785252 * TB;
        E TE = KP951056516 * TB - KP587785252 * Ty;
        E Tu = T1 - KP250000000 * Ts;
        E Tt = KP559016994 * (Ti - Tr);
        E Tv = Tt + Tu;
        E TD = Tu - Tt;

        ri[inner * ms + rs[4]] = Tv - TC;
        ri[inner * ms + rs[3]] = TD + TE;
        ri[inner * ms + rs[1]] = Tv + TC;
        ri[inner * ms + rs[2]] = TD - TE;

        E TO = KP951056516 * TM + KP587785252 * TN;
        E TP = KP951056516 * TN - KP587785252 * TM;
        E TK = TI - KP250000000 * TH;
        E TJ = KP559016994 * (TF - TG);
        E TL = TJ + TK;
        E TQ = TK - TJ;

        ii[inner * ms + rs[1]] = TL - TO;
        ii[inner * ms + rs[3]] = TQ - TP;
        ii[inner * ms + rs[4]] = TO + TL;
        ii[inner * ms + rs[2]] = TP + TQ;
    }
}
}
