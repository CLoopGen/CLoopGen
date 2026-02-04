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
    E T2, T4, T7, T9, Tb, Tl, Tf, Tj;
    {
        E T8, Te, Ta, Td;
        T2 = W[0];
        T4 = W[1];
        T7 = W[2];
        T9 = W[3];
        T8 = T2 * T7;
        Te = T4 * T7;
        Ta = T4 * T9;
        Td = T2 * T9;
        Tb = T8 - Ta;
        Tl = Td - Te;
        Tf = Td + Te;
        Tj = T8 + Ta;
    }

    E T1 = cr[0];
    E TI = ci[0];

    E T6, Tw, Tq, TA, Th, Tx, Tn, Tz;
    {
        E T3, T5, To, Tp;
        T3 = cr[(rs[1])];
        T5 = ci[(rs[1])];
        T6 = (((T2) * (T3)) + (T4 * T5));
        Tw = ((T2 * T5) - ((T4) * (T3)));
        To = cr[(rs[3])];
        Tp = ci[(rs[3])];
        Tq = (((T7) * (To)) + (T9 * Tp));
        TA = ((T7 * Tp) - ((T9) * (To)));
    }
    {
        E Tc, Tg, Tk, Tm;
        Tc = cr[(rs[4])];
        Tg = ci[(rs[4])];
        Th = (((Tb) * (Tc)) + (Tf * Tg));
        Tx = ((Tb * Tg) - ((Tf) * (Tc)));
        Tk = cr[(rs[2])];
        Tm = ci[(rs[2])];
        Tn = (((Tj) * (Tk)) + (Tl * Tm));
        Tz = ((Tj * Tm) - ((Tl) * (Tk)));
    }

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

    cr[0] = T1 + Ts;

    if (KP250000000 * Ts > T1) {
        E TC, TE, Tv, TD, Tt, Tu;
        TC = (((KP951056516) * (Ty)) + (KP587785252 * TB));
        TE = ((KP951056516 * TB) - ((KP587785252) * (Ty)));
        Tt = KP559016994 * (Ti - Tr);
        Tu = ((T1) - ((KP250000000) * (Ts)));
        Tv = Tt + Tu;
        TD = Tu - Tt;
        ci[0] = Tv - TC;
        ci[(rs[1])] = TD + TE;
        cr[(rs[1])] = Tv + TC;
        cr[(rs[2])] = TD - TE;
    } else {
        ci[0] = T1 - Ts;
        cr[(rs[1])] = T1 + Ts;
        ci[(rs[1])] = T1;
        cr[(rs[2])] = Ts;
    }

    ci[(rs[4])] = TL + TI;

    if (TL > 0.0) {
        E TH, TP, TO, TQ, TM, TN;
        TH = (((KP587785252) * (TF)) + (KP951056516 * TG));
        TP = ((KP951056516 * TF) - ((KP587785252) * (TG)));
        TM = ((TI) - ((KP250000000) * (TL)));
        TN = KP559016994 * (TJ - TK);
        TO = TM - TN;
        TQ = TN + TM;
        cr[(rs[3])] = TH - TO;
        ci[(rs[3])] = TP + TQ;
        ci[(rs[2])] = TH + TO;
        cr[(rs[4])] = TP - TQ;
    } else {
        cr[(rs[3])] = TF;
        ci[(rs[3])] = TG;
        ci[(rs[2])] = TL;
        cr[(rs[4])] = TI;
    }
}
}
