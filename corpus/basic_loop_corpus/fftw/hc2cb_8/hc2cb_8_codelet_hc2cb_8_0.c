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
extern  E KP707106781;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (m = mb , W = W + ((mb - 1) * 14); m < me; m = m + 1 , Rp = Rp + ms , Ip = Ip + ms , Rm = Rm - ms , Im = Im - ms , W = W + 14 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T7, T18, T1c, To, Ty, TM, TY, TC, Te, TZ, T10, Tv, Tz, TP, TS;
    E TD;
    {
        E T3, TK, Tk, TX, T6, TW, Tn, TL;
        {
            E T1, T2, Ti, Tj;
            T1 = Rp[0];
            T2 = Rm[(rs[3])];
            T3 = T1 + T2;
            TK = T1 - T2;
            Ti = Ip[0];
            Tj = Im[(rs[3])];
            Tk = Ti - Tj;
            TX = Ti + Tj;
        }
        {
            E T4, T5, Tl, Tm;
            T4 = Rp[(rs[2])];
            T5 = Rm[(rs[1])];
            T6 = T4 + T5;
            TW = T4 - T5;
            Tl = Ip[(rs[2])];
            Tm = Im[(rs[1])];
            Tn = Tl - Tm;
            TL = Tl + Tm;
        }
        T7 = T3 + T6;
        T18 = TK + TL;
        T1c = TX - TW;
        To = Tk + Tn;
        Ty = T3 - T6;
        TM = TK - TL;
        TY = TW + TX;
        TC = Tk - Tn;
    }
    {
        E Ta, TN, Tr, TO, Td, TQ, Tu, TR;
        {
            E T8, T9, Tp, Tq;
            T8 = Rp[(rs[1])];
            T9 = Rm[(rs[2])];
            Ta = T8 + T9;
            TN = T8 - T9;
            Tp = Ip[(rs[1])];
            Tq = Im[(rs[2])];
            Tr = Tp - Tq;
            TO = Tp + Tq;
        }
        {
            E Tb, Tc, Ts, Tt;
            Tb = Rm[0];
            Tc = Rp[(rs[3])];
            Td = Tb + Tc;
            TQ = Tb - Tc;
            Ts = Ip[(rs[3])];
            Tt = Im[0];
            Tu = Ts - Tt;
            TR = Ts + Tt;
        }
        Te = Ta + Td;
        TZ = TN + TO;
        T10 = TQ + TR;
        Tv = Tr + Tu;
        Tz = Tu - Tr;
        TP = TN - TO;
        TS = TQ - TR;
        TD = Ta - Td;
    }
    Rp[0] = T7 + Te;
    Rm[0] = To + Tv;
    {
        E Tg, Tw, Tf, Th;
        Tg = T7 - Te;
        Tw = To - Tv;
        Tf = W[6];
        Th = W[7];
        Rp[(rs[2])] = ((Tf * Tg) - ((Th) * (Tw)));
        Rm[(rs[2])] = (((Th) * (Tg)) + (Tf * Tw));
    }
    {
        E TG, TI, TF, TH;
        TG = Ty + Tz;
        TI = TD + TC;
        TF = W[2];
        TH = W[3];
        Rp[(rs[1])] = ((TF * TG) - ((TH) * (TI)));
        Rm[(rs[1])] = (((TF) * (TI)) + (TH * TG));
    }
    {
        E TA, TE, Tx, TB;
        TA = Ty - Tz;
        TE = TC - TD;
        Tx = W[10];
        TB = W[11];
        Rp[(rs[3])] = ((Tx * TA) - ((TB) * (TE)));
        Rm[(rs[3])] = (((Tx) * (TE)) + (TB * TA));
    }
    {
        E T1a, T1g, T1e, T1i, T19, T1d;
        T19 = KP707106781 * (TZ + T10);
        T1a = T18 - T19;
        T1g = T18 + T19;
        T1d = KP707106781 * (TP - TS);
        T1e = T1c + T1d;
        T1i = T1c - T1d;
        {
            E T17, T1b, T1f, T1h;
            T17 = W[4];
            T1b = W[5];
            Ip[(rs[1])] = ((T17 * T1a) - ((T1b) * (T1e)));
            Im[(rs[1])] = (((T17) * (T1e)) + (T1b * T1a));
            T1f = W[12];
            T1h = W[13];
            Ip[(rs[3])] = ((T1f * T1g) - ((T1h) * (T1i)));
            Im[(rs[3])] = (((T1f) * (T1i)) + (T1h * T1g));
        }
    }
    {
        E TU, T14, T12, T16, TT, T11;
        TT = KP707106781 * (TP + TS);
        TU = TM - TT;
        T14 = TM + TT;
        T11 = KP707106781 * (TZ - T10);
        T12 = TY - T11;
        T16 = TY + T11;
        {
            E TJ, TV, T13, T15;
            TJ = W[8];
            TV = W[9];
            Ip[(rs[2])] = ((TJ * TU) - ((TV) * (T12)));
            Im[(rs[2])] = (((TV) * (TU)) + (TJ * T12));
            T13 = W[0];
            T15 = W[1];
            Ip[0] = ((T13 * T14) - ((T15) * (T16)));
            Im[0] = (((T15) * (T14)) + (T13 * T16));
        }
    }
}

}
