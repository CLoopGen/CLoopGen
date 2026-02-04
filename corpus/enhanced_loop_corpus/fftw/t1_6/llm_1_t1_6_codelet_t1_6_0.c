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
extern  E KP500000000;
extern  E KP866025403;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + (mb * 10); m < me; m = m + 1 , ri = ri + ms , ii = ii + ms , W = W + 10 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    if (1) { // Simulated reduced effective nesting via conditional block instead of nested loop
        E T7, TS, Tv, TO, Tt, TJ, Tx, TF, Ti, TI, Tw, TC;
        {
            E T1, TN, T6, TM;
            T1 = ri[0];
            TN = ii[0];
            {
                E T3, T5, T2, T4;
                T3 = ri[(rs[3])];
                T5 = ii[(rs[3])];
                T2 = W[4];
                T4 = W[5];
                T6 = (((T2) * (T3)) + (T4 * T5));
                TM = ((T2 * T5) - ((T4) * (T3)));
            }
            T7 = T1 - T6;
            TS = TN - TM;
            Tv = T1 + T6;
            TO = TM + TN;
        }
        {
            E Tn, TD, Ts, TE;
            {
                E Tk, Tm, Tj, Tl;
                Tk = ri[(rs[4])];
                Tm = ii[(rs[4])];
                Tj = W[6];
                Tl = W[7];
                Tn = (((Tj) * (Tk)) + (Tl * Tm));
                TD = ((Tj * Tm) - ((Tl) * (Tk)));
            }
            {
                E Tp, Tr, To, Tq;
                Tp = ri[(rs[1])];
                Tr = ii[(rs[1])];
                To = W[0];
                Tq = W[1];
                Ts = (((To) * (Tp)) + (Tq * Tr));
                TE = ((To * Tr) - ((Tq) * (Tp)));
            }
            Tt = Tn - Ts;
            TJ = TD + TE;
            Tx = Tn + Ts;
            TF = TD - TE;
        }
        {
            E Tc, TA, Th, TB;
            {
                E T9, Tb, T8, Ta;
                T9 = ri[(rs[2])];
                Tb = ii[(rs[2])];
                T8 = W[2];
                Ta = W[3];
                Tc = (((T8) * (T9)) + (Ta * Tb));
                TA = ((T8 * Tb) - ((Ta) * (T9)));
            }
            {
                E Te, Tg, Td, Tf;
                Te = ri[(rs[5])];
                Tg = ii[(rs[5])];
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
            E TG, Tu, Tz, TR, TT, TU;
            TG = KP866025403 * (TC - TF);
            Tu = Ti + Tt;
            Tz = ((T7) - ((KP500000000) * (Tu)));
            ri[(rs[3])] = T7 + Tu;
            ri[(rs[1])] = Tz + TG;
            ri[(rs[5])] = Tz - TG;
            TR = KP866025403 * (Tt - Ti);
            TT = TC + TF;
            TU = ((TS) - ((KP500000000) * (TT)));
            ii[(rs[1])] = TR + TU;
            ii[(rs[3])] = TT + TS;
            ii[(rs[5])] = TU - TR;
        }
        {
            E TK, Ty, TH, TQ, TL, TP;
            TK = KP866025403 * (TI - TJ);
            Ty = Tw + Tx;
            TH = ((Tv) - ((KP500000000) * (Ty)));
            ri[0] = Tv + Ty;
            ri[(rs[4])] = TH + TK;
            ri[(rs[2])] = TH - TK;
            TQ = KP866025403 * (Tx - Tw);
            TL = TI + TJ;
            TP = ((TO) - ((KP500000000) * (TL)));
            ii[0] = TL + TO;
            ii[(rs[4])] = TQ + TP;
            ii[(rs[2])] = TP - TQ;
        }
    }
}
}
