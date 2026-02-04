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
extern  E KP781831482;
extern  E KP974927912;
extern  E KP433883739;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Variant: Use indirect indexing via precomputed index array to simulate irregular access
// This improves cache behavior in scenarios where rs[] has non-unit strides or irregular pattern

// Precompute effective indices once per iteration to reduce repeated base+offset calculations
INT idx[7];
for (m = mb, W = W + ((mb - 1) * 12); m < me; m = m + 1, cr = cr + ms, ci = ci - ms, W = W + 12, rs = rs + fftw_an_INT_guaranteed_to_be_zero) {
    for (INT i = 0; i < 7; i++) {
        idx[i] = rs[i];
    }

    E T1, T4, T7, Ta, Tx, TI, TV, TQ, TE, Tm, Tb, Te, Th, Tk, Tq;
    E TF, TR, TU, TJ, Tt;

    {
        E Tu, Tw, Tv, T2, T3;
        T1 = cr[0];
        T2 = cr[idx[1]];
        T3 = ci[0];
        T4 = T2 + T3;
        Tu = T2 - T3;
        {
            E T5, T6, T8, T9;
            T5 = cr[idx[2]];
            T6 = ci[idx[1]];
            T7 = T5 + T6;
            Tw = T5 - T6;
            T8 = cr[idx[3]];
            T9 = ci[idx[2]];
            Ta = T8 + T9;
            Tv = T8 - T9;
        }
        Tx = (((KP433883739) * (Tu)) + (KP974927912 * Tv)) - (KP781831482 * Tw);
        TI = (((KP781831482) * (Tu)) + (KP974927912 * Tw)) + (KP433883739 * Tv);
        TV = ((KP974927912 * Tu) - ((KP781831482) * (Tv))) - (KP433883739 * Tw);
        TQ = (((KP623489801) * (Ta)) + (T1)) + (-(((KP900968867) * (T7)) + (KP222520933 * T4)));
        TE = (((KP623489801) * (T4)) + (T1)) + (-(((KP900968867) * (Ta)) + (KP222520933 * T7)));
        Tm = (((KP623489801) * (T7)) + (T1)) + (-(((KP222520933) * (Ta)) + (KP900968867 * T4)));
    }
    {
        E Tp, Tn, To, Tc, Td;
        Tb = ci[idx[6]];
        Tc = ci[idx[5]];
        Td = cr[idx[6]];
        Te = Tc - Td;
        Tp = Tc + Td;
        {
            E Tf, Tg, Ti, Tj;
            Tf = ci[idx[4]];
            Tg = cr[idx[5]];
            Th = Tf - Tg;
            Tn = Tf + Tg;
            Ti = ci[idx[3]];
            Tj = cr[idx[4]];
            Tk = Ti - Tj;
            To = Ti + Tj;
        }
        Tq = ((KP781831482 * Tn) - ((KP974927912) * (To))) - (KP433883739 * Tp);
        TF = (((KP781831482) * (Tp)) + (KP974927912 * Tn)) + (KP433883739 * To);
        TR = (((KP433883739) * (Tn)) + (KP781831482 * To)) - (KP974927912 * Tp);
        TU = (((KP623489801) * (Tk)) + (Tb)) + (-(((KP900968867) * (Th)) + (KP222520933 * Te)));
        TJ = (((KP623489801) * (Te)) + (Tb)) + (-(((KP900968867) * (Tk)) + (KP222520933 * Th)));
        Tt = (((KP623489801) * (Th)) + (Tb)) + (-(((KP222520933) * (Tk)) + (KP900968867 * Te)));
    }
    cr[0] = T1 + T4 + T7 + Ta;
    ci[0] = Tb + Te + Th + Tk;
    {
        E Tr, Ty, Tl, Ts;
        Tr = Tm - Tq;
        Ty = Tt - Tx;
        Tl = W[6];
        Ts = W[7];
        cr[idx[4]] = ((Tl * Tr) - (Ts * Ty));
        ci[idx[4]] = ((Tl * Ty) + (Ts * Tr));
    }
    {
        E TY, T10, TX, TZ;
        TY = TQ + TR;
        T10 = TV + TU;
        TX = W[2];
        TZ = W[3];
        cr[idx[2]] = ((TX * TY) - (TZ * T10));
        ci[idx[2]] = ((TX * T10) + (TZ * TY));
    }
    {
        E TA, TC, Tz, TB;
        TA = Tm + Tq;
        TC = Tx + Tt;
        Tz = W[4];
        TB = W[5];
        cr[idx[3]] = ((Tz * TA) - (TB * TC));
        ci[idx[3]] = ((Tz * TC) + (TB * TA));
    }
    {
        E TM, TO, TL, TN;
        TM = TE + TF;
        TO = TJ - TI;
        TL = W[10];
        TN = W[11];
        cr[idx[6]] = ((TL * TM) - (TN * TO));
        ci[idx[6]] = ((TL * TO) + (TN * TM));
    }
    {
        E TS, TW, TP, TT;
        TS = TQ - TR;
        TW = TU - TV;
        TP = W[8];
        TT = W[9];
        cr[idx[5]] = ((TP * TS) - (TT * TW));
        ci[idx[5]] = ((TP * TW) + (TT * TS));
    }
    {
        E TG, TK, TD, TH;
        TG = TE - TF;
        TK = TI + TJ;
        TD = W[0];
        TH = W[1];
        cr[idx[1]] = ((TD * TG) - (TH * TK));
        ci[idx[1]] = ((TD * TK) + (TH * TG));
    }
}
}
