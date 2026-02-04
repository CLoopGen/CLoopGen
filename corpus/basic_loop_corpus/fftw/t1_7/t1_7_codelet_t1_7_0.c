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
    T1 = ri[0];
    TR = ii[0];
    {
        E T6, TA, Tb, TB;
        {
            E T3, T5, T2, T4;
            T3 = ri[(rs[1])];
            T5 = ii[(rs[1])];
            T2 = W[0];
            T4 = W[1];
            T6 = (((T2) * (T3)) + (T4 * T5));
            TA = ((T2 * T5) - ((T4) * (T3)));
        }
        {
            E T8, Ta, T7, T9;
            T8 = ri[(rs[6])];
            Ta = ii[(rs[6])];
            T7 = W[10];
            T9 = W[11];
            Tb = (((T7) * (T8)) + (T9 * Ta));
            TB = ((T7 * Ta) - ((T9) * (T8)));
        }
        Tc = T6 + Tb;
        TS = Tb - T6;
        TC = TA - TB;
        TO = TA + TB;
    }
    {
        E Th, TG, Tm, TH;
        {
            E Te, Tg, Td, Tf;
            Te = ri[(rs[2])];
            Tg = ii[(rs[2])];
            Td = W[2];
            Tf = W[3];
            Th = (((Td) * (Te)) + (Tf * Tg));
            TG = ((Td * Tg) - ((Tf) * (Te)));
        }
        {
            E Tj, Tl, Ti, Tk;
            Tj = ri[(rs[5])];
            Tl = ii[(rs[5])];
            Ti = W[8];
            Tk = W[9];
            Tm = (((Ti) * (Tj)) + (Tk * Tl));
            TH = ((Ti * Tl) - ((Tk) * (Tj)));
        }
        Tn = Th + Tm;
        TT = Tm - Th;
        TI = TG - TH;
        TP = TG + TH;
    }
    {
        E Ts, TD, Tx, TE;
        {
            E Tp, Tr, To, Tq;
            Tp = ri[(rs[3])];
            Tr = ii[(rs[3])];
            To = W[4];
            Tq = W[5];
            Ts = (((To) * (Tp)) + (Tq * Tr));
            TD = ((To * Tr) - ((Tq) * (Tp)));
        }
        {
            E Tu, Tw, Tt, Tv;
            Tu = ri[(rs[4])];
            Tw = ii[(rs[4])];
            Tt = W[6];
            Tv = W[7];
            Tx = (((Tt) * (Tu)) + (Tv * Tw));
            TE = ((Tt * Tw) - ((Tv) * (Tu)));
        }
        Ty = Ts + Tx;
        TU = Tx - Ts;
        TF = TD - TE;
        TQ = TD + TE;
    }
    ri[0] = T1 + Tc + Tn + Ty;
    ii[0] = TO + TP + TQ + TR;
    {
        E TJ, Tz, TX, TY;
        TJ = ((KP974927912 * TC) - ((KP781831482) * (TF))) - (KP433883739 * TI);
        Tz = (((KP623489801) * (Ty)) + (T1)) + (-(((KP900968867) * (Tn)) + (KP222520933 * Tc)));
        ri[(rs[5])] = Tz - TJ;
        ri[(rs[2])] = Tz + TJ;
        TX = ((KP974927912 * TS) - ((KP781831482) * (TU))) - (KP433883739 * TT);
        TY = (((KP623489801) * (TQ)) + (TR)) + (-(((KP900968867) * (TP)) + (KP222520933 * TO)));
        ii[(rs[2])] = TX + TY;
        ii[(rs[5])] = TY - TX;
    }
    {
        E TL, TK, TV, TW;
        TL = (((KP781831482) * (TC)) + (KP974927912 * TI)) + (KP433883739 * TF);
        TK = (((KP623489801) * (Tc)) + (T1)) + (-(((KP900968867) * (Ty)) + (KP222520933 * Tn)));
        ri[(rs[6])] = TK - TL;
        ri[(rs[1])] = TK + TL;
        TV = (((KP781831482) * (TS)) + (KP974927912 * TT)) + (KP433883739 * TU);
        TW = (((KP623489801) * (TO)) + (TR)) + (-(((KP900968867) * (TQ)) + (KP222520933 * TP)));
        ii[(rs[1])] = TV + TW;
        ii[(rs[6])] = TW - TV;
    }
    {
        E TN, TM, TZ, T10;
        TN = (((KP433883739) * (TC)) + (KP974927912 * TF)) - (KP781831482 * TI);
        TM = (((KP623489801) * (Tn)) + (T1)) + (-(((KP222520933) * (Ty)) + (KP900968867 * Tc)));
        ri[(rs[4])] = TM - TN;
        ri[(rs[3])] = TM + TN;
        TZ = (((KP433883739) * (TS)) + (KP974927912 * TU)) - (KP781831482 * TT);
        T10 = (((KP623489801) * (TP)) + (TR)) + (-(((KP222520933) * (TQ)) + (KP900968867 * TO)));
        ii[(rs[3])] = TZ + T10;
        ii[(rs[4])] = T10 - TZ;
    }
}

}
