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
extern  E KP587785252;
extern  E KP951056516;
extern  E KP559016994;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb; m < me; m += 1, cr += ms, ci -= ms, W += 4, rs += fftw_an_INT_guaranteed_to_be_zero) {
    E Th, Tk, Ti, Tl, Tn, TP, Tx, TN;
    Th = W[0];
    Tk = W[1];
    Ti = W[2];
    Tl = W[3];
    Tn = Th * Ti + Tk * Tl;
    TP = Th * Tl + Tk * Ti;
    Tx = Th * Tl - Tk * Ti;
    TN = Th * Ti - Tk * Tl;

    E T1 = cr[0];
    E T2 = cr[rs[1]];
    E T3 = ci[0];
    E T5 = cr[rs[2]];
    E T6 = ci[rs[1]];
    E T4 = T2 + T3;
    E Ty = T2 - T3;
    E T7 = T5 + T6;
    E Tz = T5 - T6;
    E T8 = T4 + T7;
    E Tp = KP559016994 * (T4 - T7);
    E TK = KP951056516 * Ty + KP587785252 * Tz;
    E TA = KP587785252 * Ty - KP951056516 * Tz;
    E To = T1 - KP250000000 * T8;

    E T9 = ci[rs[4]];
    E Ta = ci[rs[3]];
    E Tb = cr[rs[4]];
    E Td = ci[rs[2]];
    E Te = cr[rs[3]];
    E Tc = Ta - Tb;
    E Tr = Ta + Tb;
    E Tf = Td - Te;
    E Ts = Td + Te;
    E Tg = Tc + Tf;
    E Tt = KP587785252 * Tr - KP951056516 * Ts;
    E TI = KP951056516 * Tr + KP587785252 * Ts;
    E TC = KP559016994 * (Tc - Tf);
    E TB = T9 - KP250000000 * Tg;

    cr[0] = T1 + T8;
    ci[0] = T9 + Tg;

    E Tq = To - Tp;
    E Tu = Tq - Tt;
    E TF = Tq + Tt;
    E TD = TB - TC;
    E TE = TA + TD;
    E TG = TD - TA;
    cr[rs[2]] = Tn * Tu - Tx * TE;
    ci[rs[2]] = Tn * TE + Tx * Tu;
    cr[rs[3]] = Ti * TF - Tl * TG;
    ci[rs[3]] = Ti * TG + Tl * TF;

    E TH = Tp + To;
    E TJ = TH - TI;
    E TO = TH + TI;
    E TL = TC + TB;
    E TM = TK + TL;
    E TQ = TL - TK;
    cr[rs[1]] = Th * TJ - Tk * TM;
    ci[rs[1]] = Th * TM + Tk * TJ;
    cr[rs[4]] = TN * TO - TP * TQ;
    ci[rs[4]] = TN * TQ + TP * TO;
}
}
