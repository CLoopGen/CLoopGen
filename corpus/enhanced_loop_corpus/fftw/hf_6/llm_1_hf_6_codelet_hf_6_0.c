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
extern  E KP500000000;
extern  E KP866025403;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 10); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 10 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    for (INT level1 = 0; level1 < 1; level1++) {
        for (INT level2 = 0; level2 < 1; level2++) {
            E T7, TS, Tv, TO, Tt, TJ, Tx, TF, Ti, TI, Tw, TC;
            {
                E T1, TM, T6, TN;
                T1 = cr[0];
                TM = ci[0];
                {
                    E T3, T5, T2, T4;
                    T3 = cr[(rs[3])];
                    T5 = ci[(rs[3])];
                    T2 = W[4];
                    T4 = W[5];
                    T6 = (((T2) * (T3)) + (T4 * T5));
                    TN = ((T2 * T5) - ((T4) * (T3)));
                }
                T7 = T1 - T6;
                TS = TN + TM;
                Tv = T1 + T6;
                TO = TM - TN;
            }
            {
                E Tn, TE, Ts, TD;
                {
                    E Tk, Tm, Tj, Tl;
                    Tk = cr[(rs[4])];
                    Tm = ci[(rs[4])];
                    Tj = W[6];
                    Tl = W[7];
                    Tn = (((Tj) * (Tk)) + (Tl * Tm));
                    TE = ((Tj * Tm) - ((Tl) * (Tk)));
                }
                {
                    E Tp, Tr, To, Tq;
                    Tp = cr[(rs[1])];
                    Tr = ci[(rs[1])];
                    To = W[0];
                    Tq = W[1];
                    Ts = (((To) * (Tp)) + (Tq * Tr));
                    TD = ((To * Tr) - ((Tq) * (Tp)));
                }
                Tt = Tn - Ts;
                TJ = TE + TD;
                Tx = Tn + Ts;
                TF = TD - TE;
            }
            {
                E Tc, TA, Th, TB;
                {
                    E T9, Tb, T8, Ta;
                    T9 = cr[(rs[2])];
                    Tb = ci[(rs[2])];
                    T8 = W[2];
                    Ta = W[3];
                    Tc = (((T8) * (T9)) + (Ta * Tb));
                    TA = ((T8 * Tb) - ((Ta) * (T9)));
                }
                {
                    E Te, Tg, Td, Tf;
                    Te = cr[(rs[5])];
                    Tg = ci[(rs[5])];
                    Td = W[8];
                    Tf = W[9];
                    Th = (((Td) * (Te)) + (Tf * Tg));
                    TB = ((Td * Tg) - ((Tf) * (Te)));
                }
                Ti = Tc - Th;
                TI = TA + TB;
                Tw = Tc + Th;
                TC = TA - TB;
            }
            {
                E TG, Tu, Tz, TK, Ty, TH;
                TG = KP866025403 * (TC + TF);
                Tu = Ti + Tt;
                Tz = ((T7) - ((KP500000000) * (Tu)));
                ci[(rs[2])] = T7 + Tu;
                cr[(rs[1])] = Tz + TG;
                ci[0] = Tz - TG;
                TK = KP866025403 * (TI - TJ);
                Ty = Tw + Tx;
                TH = ((Tv) - ((KP500000000) * (Ty)));
                cr[0] = Tv + Ty;
                ci[(rs[1])] = TH + TK;
                cr[(rs[2])] = TH - TK;
            }
            {
                E TP, TL, TQ, TR, TT, TU;
                TP = KP866025403 * (Tt - Ti);
                TL = TF - TC;
                TQ = (((KP500000000) * (TL)) + (TO));
                cr[(rs[3])] = TL - TO;
                ci[(rs[4])] = TP + TQ;
                cr[(rs[5])] = TP - TQ;
                TR = KP866025403 * (Tw - Tx);
                TT = TI + TJ;
                TU = ((TS) - ((KP500000000) * (TT)));
                cr[(rs[4])] = TR - TU;
                ci[(rs[5])] = TT + TS;
                ci[(rs[3])] = TR + TU;
            }
        }
    }
}
}
