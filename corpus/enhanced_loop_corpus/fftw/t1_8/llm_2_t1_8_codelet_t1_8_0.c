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
extern  E KP707106781;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + (mb * 14); m < me; m = m + 1 , ri = ri + ms , ii = ii + ms , W = W + 14 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T7, T1e, TH, T19, TF, T13, TR, TU, Ti, T1f, TK, T16, Tu, T12, TM;
    E TP;
    R * restrict rri = ri;
    R * restrict rii = ii;
    stride * restrict rrs = &rs;
    const R * restrict rW = W;
    {
        E T1, T18, T6, T17;
        T1 = rri[0];
        T18 = rii[0];
        {
            E T3, T5, T2, T4;
            T3 = rri[(rrs[0][4])];
            T5 = rii[(rrs[0][4])];
            T2 = rW[6];
            T4 = rW[7];
            T6 = (((T2) * (T3)) + (T4 * T5));
            T17 = ((T2 * T5) - ((T4) * (T3)));
        }
        T7 = T1 + T6;
        T1e = T18 - T17;
        TH = T1 - T6;
        T19 = T17 + T18;
    }
    {
        E Tz, TS, TE, TT;
        {
            E Tw, Ty, Tv, Tx;
            Tw = rri[(rrs[0][7])];
            Ty = rii[(rrs[0][7])];
            Tv = rW[12];
            Tx = rW[13];
            Tz = (((Tv) * (Tw)) + (Tx * Ty));
            TS = ((Tv * Ty) - ((Tx) * (Tw)));
        }
        {
            E TB, TD, TA, TC;
            TB = rri[(rrs[0][3])];
            TD = rii[(rrs[0][3])];
            TA = rW[4];
            TC = rW[5];
            TE = (((TA) * (TB)) + (TC * TD));
            TT = ((TA * TD) - ((TC) * (TB)));
        }
        TF = Tz + TE;
        T13 = TS + TT;
        TR = Tz - TE;
        TU = TS - TT;
    }
    {
        E Tc, TI, Th, TJ;
        {
            E T9, Tb, T8, Ta;
            T9 = rri[(rrs[0][2])];
            Tb = rii[(rrs[0][2])];
            T8 = rW[2];
            Ta = rW[3];
            Tc = (((T8) * (T9)) + (Ta * Tb));
            TI = ((T8 * Tb) - ((Ta) * (T9)));
        }
        {
            E Te, Tg, Td, Tf;
            Te = rri[(rrs[0][6])];
            Tg = rii[(rrs[0][6])];
            Td = rW[10];
            Tf = rW[11];
            Th = (((Td) * (Te)) + (Tf * Tg));
            TJ = ((Td * Tg) - ((Tf) * (Te)));
        }
        Ti = Tc + Th;
        T1f = Tc - Th;
        TK = TI - TJ;
        T16 = TI + TJ;
    }
    {
        E To, TN, Tt, TO;
        {
            E Tl, Tn, Tk, Tm;
            Tl = rri[(rrs[0][1])];
            Tn = rii[(rrs[0][1])];
            Tk = rW[0];
            Tm = rW[1];
            To = (((Tk) * (Tl)) + (Tm * Tn));
            TN = ((Tk * Tn) - ((Tm) * (Tl)));
        }
        {
            E Tq, Ts, Tp, Tr;
            Tq = rri[(rrs[0][5])];
            Ts = rii[(rrs[0][5])];
            Tp = rW[8];
            Tr = rW[9];
            Tt = (((Tp) * (Tq)) + (Tr * Ts));
            TO = ((Tp * Ts) - ((Tr) * (Tq)));
        }
        Tu = To + Tt;
        T12 = TN + TO;
        TM = To - Tt;
        TP = TN - TO;
    }
    {
        E Tj, TG, T1b, T1c;
        Tj = T7 + Ti;
        TG = Tu + TF;
        rri[(rrs[0][4])] = Tj - TG;
        rri[0] = Tj + TG;
        {
            E T15, T1a, T11, T14;
            T15 = T12 + T13;
            T1a = T16 + T19;
            rii[0] = T15 + T1a;
            rii[(rrs[0][4])] = T1a - T15;
            T11 = T7 - Ti;
            T14 = T12 - T13;
            rri[(rrs[0][6])] = T11 - T14;
            rri[(rrs[0][2])] = T11 + T14;
        }
        T1b = TF - Tu;
        T1c = T19 - T16;
        rii[(rrs[0][2])] = T1b + T1c;
        rii[(rrs[0][6])] = T1c - T1b;
        {
            E TX, T1g, T10, T1d, TY, TZ;
            TX = TH - TK;
            T1g = T1e - T1f;
            TY = TP - TM;
            TZ = TR + TU;
            T10 = KP707106781 * (TY - TZ);
            T1d = KP707106781 * (TY + TZ);
            rri[(rrs[0][7])] = TX - T10;
            rii[(rrs[0][5])] = T1g - T1d;
            rri[(rrs[0][3])] = TX + T10;
            rii[(rrs[0][1])] = T1d + T1g;
        }
        {
            E TL, T1i, TW, T1h, TQ, TV;
            TL = TH + TK;
            T1i = T1f + T1e;
            TQ = TM + TP;
            TV = TR - TU;
            TW = KP707106781 * (TQ + TV);
            T1h = KP707106781 * (TV - TQ);
            rri[(rrs[0][5])] = TL - TW;
            rii[(rrs[0][7])] = T1i - T1h;
            rri[(rrs[0][1])] = TL + TW;
            rii[(rrs[0][3])] = T1h + T1i;
        }
    }
}
}
