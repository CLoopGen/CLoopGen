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
extern  E KP222520933;
extern  E KP900968867;
extern  E KP623489801;
extern  E KP433883739;
extern  E KP974927912;
extern  E KP781831482;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 12); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 12 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, TT, Tc, TV, TC, TO, Tn, TS, TI, TP, Ty, TU, TF, TQ;
    E TL_temp, TK_temp, TZ_temp, T10_temp;
    E TX_temp, TY_temp, TR_temp, TW_temp;
    E TN_temp, TM_temp, TJ_temp, Tz_temp;

    T1 = cr[0];
    TT = ci[0];

    // Introduce temporary accumulators to break WAW and WAR dependencies
    // by deferring final stores until all reads are complete.

    {
        E T6, TA, Tb, TB;
        {
            E T3, T5, T2, T4;
            T3 = cr[(rs[1])];
            T5 = ci[(rs[1])];
            T2 = W[0];
            T4 = W[1];
            T6 = (((T2) * (T3)) + (T4 * T5));
            TA = ((T2 * T5) - ((T4) * (T3)));
        }
        {
            E T8, Ta, T7, T9;
            T8 = cr[(rs[6])];
            Ta = ci[(rs[6])];
            T7 = W[10];
            T9 = W[11];
            Tb = (((T7) * (T8)) + (T9 * Ta));
            TB = ((T7 * Ta) - ((T9) * (T8)));
        }
        Tc = T6 + Tb;
        TV = TA + TB;
        TC = TA - TB;
        TO = Tb - T6;
    }

    {
        E Th, TG, Tm, TH;
        {
            E Te, Tg, Td, Tf;
            Te = cr[(rs[2])];
            Tg = ci[(rs[2])];
            Td = W[2];
            Tf = W[3];
            Th = (((Td) * (Te)) + (Tf * Tg));
            TG = ((Td * Tg) - ((Tf) * (Te)));
        }
        {
            E Tj, Tl, Ti, Tk;
            Tj = cr[(rs[5])];
            Tl = ci[(rs[5])];
            Ti = W[8];
            Tk = W[9];
            Tm = (((Ti) * (Tj)) + (Tk * Tl));
            TH = ((Ti * Tl) - ((Tk) * (Tj)));
        }
        Tn = Th + Tm;
        TS = TG + TH;
        TI = TG - TH;
        TP = Th - Tm;
    }

    {
        E Ts, TD, Tx, TE;
        {
            E Tp, Tr, To, Tq;
            Tp = cr[(rs[3])];
            Tr = ci[(rs[3])];
            To = W[4];
            Tq = W[5];
            Ts = (((To) * (Tp)) + (Tq * Tr));
            TD = ((To * Tr) - ((Tq) * (Tp)));
        }
        {
            E Tu, Tw, Tt, Tv;
            Tu = cr[(rs[4])];
            Tw = ci[(rs[4])];
            Tt = W[6];
            Tv = W[7];
            Tx = (((Tt) * (Tu)) + (Tv * Tw));
            TE = ((Tt * Tw) - ((Tv) * (Tu)));
        }
        Ty = Ts + Tx;
        TU = TD + TE;
        TF = TD - TE;
        TQ = Tx - Ts;
    }

    // Compute all intermediate results before any store to eliminate WAR/WAW hazards
    TL_temp = (((KP781831482) * (TC)) + (KP974927912 * TI)) + (KP433883739 * TF);
    TK_temp = (((KP623489801) * (Tc)) + (T1)) + (-(((KP900968867) * (Ty)) + (KP222520933 * Tn)));
    TZ_temp = (((KP781831482) * (TO)) + (KP433883739 * TQ)) - (KP974927912 * TP);
    T10_temp = (((KP623489801) * (TV)) + (TT)) + (-(((KP900968867) * (TU)) + (KP222520933 * TS)));
    TX_temp = (((KP974927912) * (TO)) + (KP433883739 * TP)) - (KP781831482 * TQ);
    TY_temp = (((KP623489801) * (TU)) + (TT)) + (-(((KP900968867) * (TS)) + (KP222520933 * TV)));
    TR_temp = (((KP433883739) * (TO)) + (KP781831482 * TP)) + (KP974927912 * TQ);
    TW_temp = (((KP623489801) * (TS)) + (TT)) + (-(((KP222520933) * (TU)) + (KP900968867 * TV)));
    TN_temp = (((KP433883739) * (TC)) + (KP974927912 * TF)) - (KP781831482 * TI);
    TM_temp = (((KP623489801) * (Tn)) + (T1)) + (-(((KP222520933) * (Ty)) + (KP900968867 * Tc)));
    TJ_temp = ((KP974927912 * TC) - ((KP781831482) * (TF))) - (KP433883739 * TI);
    Tz_temp = (((KP623489801) * (Ty)) + (T1)) + (-(((KP900968867) * (Tn)) + (KP222520933 * Tc)));

    // Now perform all stores in arbitrary order — no more WAR/WAW
    cr[0] = T1 + Tc + Tn + Ty;
    ci[0] = TK_temp - TL_temp;
    cr[(rs[1])] = TK_temp + TL_temp;
    ci[(rs[6])] = TV + TS + TU + TT;
    cr[(rs[6])] = TZ_temp - T10_temp;
    ci[(rs[5])] = TZ_temp + T10_temp;
    cr[(rs[5])] = TX_temp - TY_temp;
    ci[(rs[4])] = TX_temp + TY_temp;
    cr[(rs[4])] = TR_temp - TW_temp;
    ci[(rs[3])] = TR_temp + TW_temp;
    ci[(rs[2])] = TM_temp - TN_temp;
    cr[(rs[3])] = TM_temp + TN_temp;
    ci[(rs[1])] = Tz_temp - TJ_temp;
    cr[(rs[2])] = Tz_temp + TJ_temp;
}
}
