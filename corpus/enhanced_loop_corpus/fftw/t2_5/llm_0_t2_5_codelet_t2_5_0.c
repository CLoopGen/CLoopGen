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
for (m = mb , W = W + (mb * 4); m < me; m = m + 1 , ri = ri + ms , ii = ii + ms , W = W + 4 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
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
    for (INT unroll_factor = 0; unroll_factor < 1; unroll_factor++) {
        E T1, TI, Ty, TB, TN, TM, TF, TG, TH, Ti, Tr, Ts;
        T1 = ri[0];
        TI = ii[0];
        {
            E T6, Tw, Tq, TA, Th, Tx, Tn, Tz;
            {
                E T3, T5, To, Tp;
                T3 = ri[(rs[1])];
                T5 = ii[(rs[1])];
                T6 = (((T2) * (T3)) + (T4 * T5));
                Tw = ((T2 * T5) - ((T4) * (T3)));
                To = ri[(rs[3])];
                Tp = ii[(rs[3])];
                Tq = (((T7) * (To)) + (T9 * Tp));
                TA = ((T7 * Tp) - ((T9) * (To)));
            }
            {
                E Tc, Tg, Tk, Tm;
                Tc = ri[(rs[4])];
                Tg = ii[(rs[4])];
                Th = (((Tb) * (Tc)) + (Tf * Tg));
                Tx = ((Tb * Tg) - ((Tf) * (Tc)));
                Tk = ri[(rs[2])];
                Tm = ii[(rs[2])];
                Tn = (((Tj) * (Tk)) + (Tl * Tm));
                Tz = ((Tj * Tm) - ((Tl) * (Tk)));
            }
            Ty = Tw - Tx;
            TB = Tz - TA;
            TN = Tn - Tq;
            TM = T6 - Th;
            TF = Tw + Tx;
            TG = Tz + TA;
            TH = TF + TG;
            Ti = T6 + Th;
            Tr = Tn + Tq;
            Ts = Ti + Tr;
        }
        ri[0] = T1 + Ts;
        ii[0] = TH + TI;
        {
            E TC, TE, Tv, TD, Tt, Tu;
            TC = (((KP951056516) * (Ty)) + (KP587785252 * TB));
            TE = ((KP951056516 * TB) - ((KP587785252) * (Ty)));
            Tt = KP559016994 * (Ti - Tr);
            Tu = ((T1) - ((KP250000000) * (Ts)));
            Tv = Tt + Tu;
            TD = Tu - Tt;
            ri[(rs[4])] = Tv - TC;
            ri[(rs[3])] = TD + TE;
            ri[(rs[1])] = Tv + TC;
            ri[(rs[2])] = TD - TE;
        }
        {
            E TO, TP, TL, TQ, TJ, TK;
            TO = (((KP951056516) * (TM)) + (KP587785252 * TN));
            TP = ((KP951056516 * TN) - ((KP587785252) * (TM)));
            TJ = KP559016994 * (TF - TG);
            TK = ((TI) - ((KP250000000) * (TH)));
            TL = TJ + TK;
            TQ = TK - TJ;
            ii[(rs[1])] = TL - TO;
            ii[(rs[3])] = TQ - TP;
            ii[(rs[4])] = TO + TL;
            ii[(rs[2])] = TP + TQ;
        }
    }
}
}
