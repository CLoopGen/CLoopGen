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
    E T7, TS, Tv, TO, Tt, TJ, Tx, TF, Ti, TI, Tw, TC;
    stride base_r = rs; // Local copy to allow safe indirect indexing
    {
        E T1, TM, T6, TN;
        T1 = cr[0];
        TM = ci[0];
        {
            E T3, T5, T2, T4;
            INT idx3 = base_r[3];
            T3 = cr[idx3];
            T5 = ci[idx3];
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
            INT idx4 = base_r[4];
            Tk = cr[idx4];
            Tm = ci[idx4];
            Tj = W[6];
            Tl = W[7];
            Tn = (((Tj) * (Tk)) + (Tl * Tm));
            TE = ((Tj * Tm) - ((Tl) * (Tk)));
        }
        {
            E Tp, Tr, To, Tq;
            INT idx1 = base_r[1];
            Tp = cr[idx1];
            Tr = ci[idx1];
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
            INT idx2 = base_r[2];
            T9 = cr[idx2];
            Tb = ci[idx2];
            T8 = W[2];
            Ta = W[3];
            Tc = (((T8) * (T9)) + (Ta * Tb));
            TA = ((T8 * Tb) - ((Ta) * (T9)));
        }
        {
            E Te, Tg, Td, Tf;
            INT idx5 = base_r[5];
            Te = cr[idx5];
            Tg = ci[idx5];
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
        ci[base_r[2]] = T7 + Tu;
        cr[base_r[1]] = Tz + TG;
        ci[0] = Tz - TG;
        TK = KP866025403 * (TI - TJ);
        Ty = Tw + Tx;
        TH = ((Tv) - ((KP500000000) * (Ty)));
        cr[0] = Tv + Ty;
        ci[base_r[1]] = TH + TK;
        cr[base_r[2]] = TH - TK;
    }
    {
        E TP, TL, TQ, TR, TT, TU;
        TP = KP866025403 * (Tt - Ti);
        TL = TF - TC;
        TQ = (((KP500000000) * (TL)) + (TO));
        cr[base_r[3]] = TL - TO;
        ci[base_r[4]] = TP + TQ;
        cr[base_r[5]] = TP - TQ;
        TR = KP866025403 * (Tw - Tx);
        TT = TI + TJ;
        TU = ((TS) - ((KP500000000) * (TT)));
        cr[base_r[4]] = TR - TU;
        ci[base_r[5]] = TT + TS;
        ci[base_r[3]] = TR + TU;
    }
}
}
