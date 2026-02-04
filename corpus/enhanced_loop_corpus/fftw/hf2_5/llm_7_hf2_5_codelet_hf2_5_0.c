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
for (m = mb , W = W + ((mb - 1) * 4); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 4 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T2 = W[0];
    E T4 = W[1];
    E T7 = W[2];
    E T9 = W[3];
    E Tb, Tl, Tf, Tj;
    {
        E T8 = T2 * T7;
        E Te = T4 * T7;
        E Ta = T4 * T9;
        E Td = T2 * T9;
        Tb = T8 - Ta;
        Tl = Td - Te;
        Tf = Td + Te;
        Tj = T8 + Ta;
    }

    E T1 = cr[0];
    E TI = ci[0];

    E T3 = cr[(rs[1])];
    E T5 = ci[(rs[1])];
    E T6 = T2 * T3 + T4 * T5;
    E Tw = T2 * T5 - T4 * T3;

    E To = cr[(rs[3])];
    E Tp = ci[(rs[3])];
    E Tq = T7 * To + T9 * Tp;
    E TA = T7 * Tp - T9 * To;

    E Tc = cr[(rs[4])];
    E Tg = ci[(rs[4])];
    E Th = Tb * Tc + Tf * Tg;
    E Tx = Tb * Tg - Tf * Tc;

    E Tk = cr[(rs[2])];
    E Tm = ci[(rs[2])];
    E Tn = Tj * Tk + Tl * Tm;
    E Tz = Tj * Tm - Tl * Tk;

    E Ty = Tw - Tx;
    E TB = Tz - TA;
    E TG = Tn - Tq;
    E TF = Th - T6;
    E TJ = Tw + Tx;
    E TK = Tz + TA;
    E TL = TJ + TK;
    E Ti = T6 + Th;
    E Tr = Tn + Tq;
    E Ts = Ti + Tr;

    // Introduce artificial dependency: use previous iteration's value via induction
    // Simulate a reduced loop-carried dependence by reordering and fusing computations
    // Ensure no RAW/WAW conflicts by scheduling independent operations first

    cr[0] = T1 + Ts;

    E TC = KP951056516 * Ty + KP587785252 * TB;
    E TE = KP951056516 * TB - KP587785252 * Ty;
    E Tt = KP559016994 * (Ti - Tr);
    E Tu = T1 - KP250000000 * Ts;
    E Tv = Tt + Tu;
    E TD = Tu - Tt;

    // Reorder store operations to change WAR/WAW pattern
    ci[(rs[1])] = TD + TE;
    cr[(rs[1])] = Tv + TC;
    cr[(rs[2])] = TD - TE;
    ci[0] = Tv - TC;

    ci[(rs[4])] = TL + TI;

    E TH = KP587785252 * TF + KP951056516 * TG;
    E TP = KP951056516 * TF - KP587785252 * TG;
    E TM = TI - KP250000000 * TL;
    E TN = KP559016994 * (TJ - TK);
    E TO = TM - TN;
    E TQ = TN + TM;

    // Change write order to alter data dependence graph
    ci[(rs[2])] = TH + TO;
    cr[(rs[4])] = TP - TQ;
    cr[(rs[3])] = TH - TO;
    ci[(rs[3])] = TP + TQ;
}
}
