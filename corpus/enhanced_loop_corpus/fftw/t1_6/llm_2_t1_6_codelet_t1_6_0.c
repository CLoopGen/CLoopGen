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
    E T7, TS, Tv, TO, Tt, TJ, Tx, TF, Ti, TI, Tw, TC;
    INT rsi3 = rs[3], rsi4 = rs[4], rsi1 = rs[1], rsi2 = rs[2], rsi5 = rs[5];
    R *ri_base = ri, *ii_base = ii;

    {
        E T1, TN, T6, TM;
        T1 = ri_base[0];
        TN = ii_base[0];
        {
            E T3 = ri_base[rsi3], T5 = ii_base[rsi3];
            E T2 = W[4], T4 = W[5];
            T6 = T2 * T3 + T4 * T5;
            TM = T2 * T5 - T4 * T3;
        }
        T7 = T1 - T6;
        TS = TN - TM;
        Tv = T1 + T6;
        TO = TN + TM;
    }
    {
        E Tn, TD, Ts, TE;
        {
            E Tk = ri_base[rsi4], Tm = ii_base[rsi4];
            E Tj = W[6], Tl = W[7];
            Tn = Tj * Tk + Tl * Tm;
            TD = Tj * Tm - Tl * Tk;
        }
        {
            E Tp = ri_base[rsi1], Tr = ii_base[rsi1];
            E To = W[0], Tq = W[1];
            Ts = To * Tp + Tq * Tr;
            TE = To * Tr - Tq * Tp;
        }
        Tt = Tn - Ts;
        TJ = TD + TE;
        Tx = Tn + Ts;
        TF = TD - TE;
    }
    {
        E Tc, TA, Th, TB;
        {
            E T9 = ri_base[rsi2], Tb = ii_base[rsi2];
            E T8 = W[2], Ta = W[3];
            Tc = T8 * T9 + Ta * Tb;
            TA = T8 * Tb - Ta * T9;
        }
        {
            E Te = ri_base[rsi5], Tg = ii_base[rsi5];
            E Td = W[8], Tf = W[9];
            Th = Td * Te + Tf * Tg;
            TB = Td * Tg - Tf * Te;
        }
        Ti = Tc - Th;
        TI = TA + TB;
        Tw = Tc + Th;
        TC = TA - TB;
    }
    {
        E TG = KP866025403 * (TC - TF);
        E Tu = Ti + Tt;
        E Tz = T7 - KP500000000 * Tu;
        ri_base[rsi3] = T7 + Tu;
        ri_base[rsi1] = Tz + TG;
        ri_base[rsi5] = Tz - TG;
        E TR = KP866025403 * (Tt - Ti);
        E TT = TC + TF;
        E TU = TS - KP500000000 * TT;
        ii_base[rsi1] = TR + TU;
        ii_base[rsi3] = TT + TS;
        ii_base[rsi5] = TU - TR;
    }
    {
        E TK = KP866025403 * (TI - TJ);
        E Ty = Tw + Tx;
        E TH = Tv - KP500000000 * Ty;
        ri_base[0] = Tv + Ty;
        ri_base[rsi4] = TH + TK;
        ri_base[rsi2] = TH - TK;
        E TQ = KP866025403 * (Tx - Tw);
        E TL = TI + TJ;
        E TP = TO - KP500000000 * TL;
        ii_base[0] = TL + TO;
        ii_base[rsi4] = TQ + TP;
        ii_base[rsi2] = TP - TQ;
    }
}
}
