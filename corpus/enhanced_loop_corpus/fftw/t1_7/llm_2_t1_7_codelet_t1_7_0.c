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
extern  E KP222520933;
extern  E KP900968867;
extern  E KP623489801;
extern  E KP433883739;
extern  E KP781831482;
extern  E KP974927912;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + (mb * 12); m < me; m = m + 1 , ri = ri + ms , ii = ii + ms , W = W + 12 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, TR, Tc, TS, TC, TO, Tn, TT, TI, TP, Ty, TU, TF, TQ;
    INT rsi1 = rs[1], rsi2 = rs[2], rsi3 = rs[3], rsi4 = rs[4], rsi5 = rs[5], rsi6 = rs[6];
    E *ril = ri, *iil = ii, *Wl = W;

    T1 = ril[0];
    TR = iil[0];

    {
        E T6, TA, Tb, TB;
        {
            E T3 = ril[rsi1], T5 = iil[rsi1], T2 = Wl[0], T4 = Wl[1];
            T6 = T2 * T3 + T4 * T5;
            TA = T2 * T5 - T4 * T3;
        }
        {
            E T8 = ril[rsi6], Ta = iil[rsi6], T7 = Wl[10], T9 = Wl[11];
            Tb = T7 * T8 + T9 * Ta;
            TB = T7 * Ta - T9 * T8;
        }
        Tc = T6 + Tb;
        TS = Tb - T6;
        TC = TA - TB;
        TO = TA + TB;
    }

    {
        E Th, TG, Tm, TH;
        {
            E Te = ril[rsi2], Tg = iil[rsi2], Td = Wl[2], Tf = Wl[3];
            Th = Td * Te + Tf * Tg;
            TG = Td * Tg - Tf * Te;
        }
        {
            E Tj = ril[rsi5], Tl = iil[rsi5], Ti = Wl[8], Tk = Wl[9];
            Tm = Ti * Tj + Tk * Tl;
            TH = Ti * Tl - Tk * Tj;
        }
        Tn = Th + Tm;
        TT = Tm - Th;
        TI = TG - TH;
        TP = TG + TH;
    }

    {
        E Ts, TD, Tx, TE;
        {
            E Tp = ril[rsi3], Tr = iil[rsi3], To = Wl[4], Tq = Wl[5];
            Ts = To * Tp + Tq * Tr;
            TD = To * Tr - Tq * Tp;
        }
        {
            E Tu = ril[rsi4], Tw = iil[rsi4], Tt = Wl[6], Tv = Wl[7];
            Tx = Tt * Tu + Tv * Tw;
            TE = Tt * Tw - Tv * Tu;
        }
        Ty = Ts + Tx;
        TU = Tx - Ts;
        TF = TD - TE;
        TQ = TD + TE;
    }

    ril[0] = T1 + Tc + Tn + Ty;
    iil[0] = TO + TP + TQ + TR;

    {
        E TJ, Tz, TX, TY;
        TJ = KP974927912 * TC - KP781831482 * TF - KP433883739 * TI;
        Tz = KP623489801 * Ty + T1 - (KP900968867 * Tn + KP222520933 * Tc);
        ril[rsi5] = Tz - TJ;
        ril[rsi2] = Tz + TJ;
        TX = KP974927912 * TS - KP781831482 * TU - KP433883739 * TT;
        TY = KP623489801 * TQ + TR - (KP900968867 * TP + KP222520933 * TO);
        iil[rsi2] = TX + TY;
        iil[rsi5] = TY - TX;
    }

    {
        E TL, TK, TV, TW;
        TL = KP781831482 * TC + KP974927912 * TI + KP433883739 * TF;
        TK = KP623489801 * Tc + T1 - (KP900968867 * Ty + KP222520933 * Tn);
        ril[rsi6] = TK - TL;
        ril[rsi1] = TK + TL;
        TV = KP781831482 * TS + KP974927912 * TT + KP433883739 * TU;
        TW = KP623489801 * TO + TR - (KP900968867 * TQ + KP222520933 * TP);
        iil[rsi1] = TV + TW;
        iil[rsi6] = TW - TV;
    }

    {
        E TN, TM, TZ, T10;
        TN = KP433883739 * TC + KP974927912 * TF - KP781831482 * TI;
        TM = KP623489801 * Tn + T1 - (KP222520933 * Ty + KP900968867 * Tc);
        ril[rsi4] = TM - TN;
        ril[rsi3] = TM + TN;
        TZ = KP433883739 * TS + KP974927912 * TU - KP781831482 * TT;
        T10 = KP623489801 * TP + TR - (KP222520933 * TQ + KP900968867 * TO);
        iil[rsi3] = TZ + T10;
        iil[rsi4] = T10 - TZ;
    }
}
}
