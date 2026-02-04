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
    INT rsi1 = rs[1], rsi2 = rs[2];
    E * restrict rp_base = Rp;
    E * restrict ip_base = Ip;
    E * restrict rm_base = Rm;
    E * restrict im_base = Im;
    E * restrict w_base = W;

    {
        E T1, TN, T6, TM;
        T1 = rp_base[0];
        TN = rm_base[0];
        {
            E T3 = ip_base[rsi1];
            E T5 = im_base[rsi1];
            E T2 = w_base[4];
            E T4 = w_base[5];
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
            E Tk = rp_base[rsi2];
            E Tm = rm_base[rsi2];
            E Tj = w_base[6];
            E Tl = w_base[7];
            Tn = Tj * Tk + Tl * Tm;
            TD = Tj * Tm - Tl * Tk;
        }
        {
            E Tp = ip_base[0];
            E Tr = im_base[0];
            E To = w_base[0];
            E Tq = w_base[1];
            Ts = To * Tp + Tq * Tr;
            TE = To * Tr - Tq * Tp;
        }
        Tt = Tn - Ts;
        TJ = TE - TD;
        Tx = Tn + Ts;
        TF = TD + TE;
    }
    {
        E Tc, TA, Th, TB;
        {
            E T9 = rp_base[rsi1];
            E Tb = rm_base[rsi1];
            E T8 = w_base[2];
            E Ta = w_base[3];
            Tc = T8 * T9 + Ta * Tb;
            TA = T8 * Tb - Ta * T9;
        }
        {
            E Te = ip_base[rsi2];
            E Tg = im_base[rsi2];
            E Td = w_base[8];
            E Tf = w_base[9];
            Th = Td * Te + Tf * Tg;
            TB = Td * Tg - Tf * Te;
        }
        Ti = Tc - Th;
        TI = TA - TB;
        Tw = Tc + Th;
        TC = TA + TB;
    }
    {
        E TK = KP866025403 * (TI + TJ);
        E Tu = Ti + Tt;
        E TH = T7 - KP500000000 * Tu;
        rm_base[rsi2] = T7 + Tu;
        rp_base[rsi1] = TH + TK;
        rm_base[0] = TH - TK;
        E TT = KP866025403 * (Tt - Ti);
        E TR = TJ - TI;
        E TU = KP500000000 * TR + TS;
        im_base[rsi2] = TR - TS;
        ip_base[rsi1] = TT + TU;
        im_base[0] = TT - TU;
    }
    {
        E TG = KP866025403 * (TC - TF);
        E Ty = Tw + Tx;
        E Tz = Tv - KP500000000 * Ty;
        rp_base[0] = Tv + Ty;
        rm_base[rsi1] = Tz + TG;
        rp_base[rsi2] = Tz - TG;
        E TP = KP866025403 * (Tw - Tx);
        E TL = TC + TF;
        E TQ = TO - KP500000000 * TL;
        ip_base[0] = TL + TO;
        ip_base[rsi2] = TP + TQ;
        im_base[rsi1] = TP - TQ;
    }
}
}
