#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *Rp;
extern R *Ip;
extern R *Rm;
extern R *Im;
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
for (m = mb , W = W + ((mb - 1) * 10); m < me; m = m + 1 , Rp = Rp + ms , Ip = Ip + ms , Rm = Rm - ms , Im = Im - ms , W = W + 10 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T7, TS, Tv, TO, Tt, TJ, Tx, TF, Ti, TI, Tw, TC;

    // First block: skip computation on every third iteration
    if ((m - mb) % 3 != 0) {
        E T1, TN, T6, TM;
        T1 = Rp[0];
        TN = Rm[0];
        {
            E T3, T5, T2, T4;
            T3 = Ip[(rs[1])];
            T5 = Im[(rs[1])];
            T2 = W[4];
            T4 = W[5];
            T6 = (((T2) * (T3)) + (T4 * T5));
            TM = ((T2 * T5) - ((T4) * (T3)));
        }
        T7 = T1 - T6;
        TS = TN - TM;
        Tv = T1 + T6;
        TO = TM + TN;
    } else {
        // Use averaged values from neighbors when skipped
        T7 = (Rp[0] + Rm[0]) * 0.5;
        TS = (Ip[(rs[1])] - Im[(rs[1])]) * 0.5;
        Tv = T7;
        TO = TS;
    }

    // Second block: conditionally compute based on stride sign
    if (ms > 0) {
        E Tn, TD, Ts, TE;
        {
            E Tk, Tm, Tj, Tl;
            Tk = Rp[(rs[2])];
            Tm = Rm[(rs[2])];
            Tj = W[6];
            Tl = W[7];
            Tn = (((Tj) * (Tk)) + (Tl * Tm));
            TD = ((Tj * Tm) - ((Tl) * (Tk)));
        }
        {
            E Tp, Tr, To, Tq;
            Tp = Ip[0];
            Tr = Im[0];
            To = W[0];
            Tq = W[1];
            Ts = (((To) * (Tp)) + (Tq * Tr));
            TE = ((To * Tr) - ((Tq) * (Tp)));
        }
        Tt = Tn - Ts;
        TJ = TE - TD;
        Tx = Tn + Ts;
        TF = TD + TE;
    } else {
        // Fallback: symmetric initialization when ms <= 0
        Tt = Tx = TJ = TF = 0.0;
    }

    // Third block: always execute but with conditional scaling
    {
        E Tc, TA, Th, TB;
        {
            E T9, Tb, T8, Ta;
            T9 = Rp[(rs[1])];
            Tb = Rm[(rs[1])];
            T8 = W[2];
            Ta = W[3];
            Tc = (((T8) * (T9)) + (Ta * Tb));
            TA = ((T8 * Tb) - ((Ta) * (T9)));
        }
        {
            E Te, Tg, Td, Tf;
            Te = Ip[(rs[2])];
            Tg = Im[(rs[2])];
            Td = W[8];
            Tf = W[9];
            Th = (((Td) * (Te)) + (Tf * Tg));
            TB = ((Td * Tg) - ((Tf) * (Te)));
        }
        Ti = Tc - Th;
        TI = TA - TB;
        Tw = Tc + Th;
        TC = TA + TB;
    }

    // Final blocks remain largely unchanged but respect prior conditions
    {
        E TK, Tu, TH, TT, TR, TU;
        TK = KP866025403 * (TI + TJ);
        Tu = Ti + Tt;
        TH = ((T7) - ((KP500000000) * (Tu)));
        Rm[(rs[2])] = T7 + Tu;
        Rp[(rs[1])] = TH + TK;
        Rm[0] = TH - TK;
        TT = KP866025403 * (Tt - Ti);
        TR = TJ - TI;
        TU = (((KP500000000) * (TR)) + (TS));
        Im[(rs[2])] = TR - TS;
        Ip[(rs[1])] = TT + TU;
        Im[0] = TT - TU;
    }
    {
        E TG, Ty, Tz, TP, TL, TQ;
        TG = KP866025403 * (TC - TF);
        Ty = Tw + Tx;
        Tz = ((Tv) - ((KP500000000) * (Ty)));
        Rp[0] = Tv + Ty;
        Rm[(rs[1])] = Tz + TG;
        Rp[(rs[2])] = Tz - TG;
        TP = KP866025403 * (Tw - Tx);
        TL = TC + TF;
        TQ = ((TO) - ((KP500000000) * (TL)));
        Ip[0] = TL + TO;
        Ip[(rs[2])] = TP + TQ;
        Im[(rs[1])] = TP - TQ;
    }
}

}
