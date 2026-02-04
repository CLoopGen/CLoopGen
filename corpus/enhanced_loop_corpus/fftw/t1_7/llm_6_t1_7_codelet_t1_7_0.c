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
            T2 = W[0];
            T4 = W[1];
            T3 = ri[(rs[1])];
            T5 = ii[(rs[1])];
            T6 = (((T2) * (T3)) + (T4 * T5));
            TA = ((T2 * T5) - ((T4) * (T3)));
        }
        {
            E T8, Ta, T7, T9;
            T7 = W[10];
            T9 = W[11];
            T8 = ri[(rs[6])];
            Ta = ii[(rs[6])];
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
            Td = W[2];
            Tf = W[3];
            Te = ri[(rs[2])];
            Tg = ii[(rs[2])];
            Th = (((Td) * (Te)) + (Tf * Tg));
            TG = ((Td * Tg) - ((Tf) * (Te)));
        }
        {
            E Tj, Tl, Ti, Tk;
            Ti = W[8];
            Tk = W[9];
            Tj = ri[(rs[5])];
            Tl = ii[(rs[5])];
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
            To = W[4];
            Tq = W[5];
            Tp = ri[(rs[3])];
            Tr = ii[(rs[3])];
            Ts = (((To) * (Tp)) + (Tq * Tr));
            TD = ((To * Tr) - ((Tq) * (Tp)));
        }
        {
            E Tu, Tw, Tt, Tv;
            Tt = W[6];
            Tv = W[7];
            Tu = ri[(rs[4])];
            Tw = ii[(rs[4])];
            Tx = (((Tt) * (Tu)) + (Tv * Tw));
            TE = ((Tt * Tw) - ((Tv) * (Tu)));
        }
        Ty = Ts + Tx;
        TU = Tx - Ts;
        TF = TD - TE;
        TQ = TD + TE;
    }
    // Introduce temporary variables to break direct WAW and WAR dependencies
    E temp_ri0 = T1 + Tc + Tn + Ty;
    E temp_ii0 = TO + TP + TQ + TR;
    ri[0] = temp_ri0;
    ii[0] = temp_ii0;

    {
        E TJ, Tz, TX, TY;
        TJ = ((KP974927912 * TC) - ((KP781831482) * (TF))) - (KP433883739 * TI);
        Tz = (((KP623489801) * (Ty)) + (T1)) + (-(((KP900968867) * (Tn)) + (KP222520933 * Tc)));
        E r5_val = Tz - TJ;
        E r2_val = Tz + TJ;
        ri[(rs[5])] = r5_val;
        ri[(rs[2])] = r2_val;
        TX = ((KP974927912 * TS) - ((KP781831482) * (TU))) - (KP433883739 * TT);
        TY = (((KP623489801) * (TQ)) + (TR)) + (-(((KP900968867) * (TP)) + (KP222520933 * TO)));
        E i2_val = TX + TY;
        E i5_val = TY - TX;
        ii[(rs[2])] = i2_val;
        ii[(rs[5])] = i5_val;
    }
    {
        E TL, TK, TV, TW;
        TL = (((KP781831482) * (TC)) + (KP974927912 * TI)) + (KP433883739 * TF);
        TK = (((KP623489801) * (Tc)) + (T1)) + (-(((KP900968867) * (Ty)) + (KP222520933 * Tn)));
        E r6_val = TK - TL;
        E r1_val = TK + TL;
        ri[(rs[6])] = r6_val;
        ri[(rs[1])] = r1_val;
        TV = (((KP781831482) * (TS)) + (KP974927912 * TT)) + (KP433883739 * TU);
        TW = (((KP623489801) * (TO)) + (TR)) + (-(((KP900968867) * (TQ)) + (KP222520933 * TP)));
        E i1_val = TV + TW;
        E i6_val = TW - TV;
        ii[(rs[1])] = i1_val;
        ii[(rs[6])] = i6_val;
    }
    {
        E TN, TM, TZ, T10;
        TN = (((KP433883739) * (TC)) + (KP974927912 * TF)) - (KP781831482 * TI);
        TM = (((KP623489801) * (Tn)) + (T1)) + (-(((KP222520933) * (Ty)) + (KP900968867 * Tc)));
        E r4_val = TM - TN;
        E r3_val = TM + TN;
        ri[(rs[4])] = r4_val;
        ri[(rs[3])] = r3_val;
        TZ = (((KP433883739) * (TS)) + (KP974927912 * TU)) - (KP781831482 * TT);
        T10 = (((KP623489801) * (TP)) + (TR)) + (-(((KP222520933) * (TQ)) + (KP900968867 * TO)));
        E i3_val = TZ + T10;
        E i4_val = T10 - TZ;
        ii[(rs[3])] = i3_val;
        ii[(rs[4])] = i4_val;
    }
}
}
