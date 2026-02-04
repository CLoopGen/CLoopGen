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
extern  E KP707106781;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 14); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 14 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T7, T1f, TH, T19, TF, T12, TR, TU, Ti, T1e, TK, T16, Tu, T13, TM;
    E TP;
    // Use consecutive array access via local arrays to improve spatial locality
    E cr_local[8], ci_local[8];
    for (INT i = 0; i < 8; i++) {
        cr_local[i] = cr[rs[i]];
        ci_local[i] = ci[rs[i]];
    }
    {
        E T1, T18, T6, T17;
        T1 = cr_local[0];
        T18 = ci_local[0];
        {
            E T3, T5, T2, T4;
            T3 = cr_local[4];
            T5 = ci_local[4];
            T2 = W[6];
            T4 = W[7];
            T6 = (((T2) * (T3)) + (T4 * T5));
            T17 = ((T2 * T5) - ((T4) * (T3)));
        }
        T7 = T1 + T6;
        T1f = T18 - T17;
        TH = T1 - T6;
        T19 = T17 + T18;
    }
    {
        E Tz, TS, TE, TT;
        {
            E Tw, Ty, Tv, Tx;
            Tw = cr_local[7];
            Ty = ci_local[7];
            Tv = W[12];
            Tx = W[13];
            Tz = (((Tv) * (Tw)) + (Tx * Ty));
            TS = ((Tv * Ty) - ((Tx) * (Tw)));
        }
        {
            E TB, TD, TA, TC;
            TB = cr_local[3];
            TD = ci_local[3];
            TA = W[4];
            TC = W[5];
            TE = (((TA) * (TB)) + (TC * TD));
            TT = ((TA * TD) - ((TC) * (TB)));
        }
        TF = Tz + TE;
        T12 = TS + TT;
        TR = Tz - TE;
        TU = TS - TT;
    }
    {
        E Tc, TI, Th, TJ;
        {
            E T9, Tb, T8, Ta;
            T9 = cr_local[2];
            Tb = ci_local[2];
            T8 = W[2];
            Ta = W[3];
            Tc = (((T8) * (T9)) + (Ta * Tb));
            TI = ((T8 * Tb) - ((Ta) * (T9)));
        }
        {
            E Te, Tg, Td, Tf;
            Te = cr_local[6];
            Tg = ci_local[6];
            Td = W[10];
            Tf = W[11];
            Th = (((Td) * (Te)) + (Tf * Tg));
            TJ = ((Td * Tg) - ((Tf) * (Te)));
        }
        Ti = Tc + Th;
        T1e = Tc - Th;
        TK = TI - TJ;
        T16 = TI + TJ;
    }
    {
        E To, TN, Tt, TO;
        {
            E Tl, Tn, Tk, Tm;
            Tl = cr_local[1];
            Tn = ci_local[1];
            Tk = W[0];
            Tm = W[1];
            To = (((Tk) * (Tl)) + (Tm * Tn));
            TN = ((Tk * Tn) - ((Tm) * (Tl)));
        }
        {
            E Tq, Ts, Tp, Tr;
            Tq = cr_local[5];
            Ts = ci_local[5];
            Tp = W[8];
            Tr = W[9];
            Tt = (((Tp) * (Tq)) + (Tr * Ts));
            TO = ((Tp * Ts) - ((Tr) * (Tq)));
        }
        Tu = To + Tt;
        T13 = TN + TO;
        TM = To - Tt;
        TP = TN - TO;
    }
    {
        E Tj, TG, T1b, T1c;
        Tj = T7 + Ti;
        TG = Tu + TF;
        ci[rs[3]] = Tj - TG;
        cr[0] = Tj + TG;
        T1b = TF - Tu;
        T1c = T19 - T16;
        cr[rs[6]] = T1b - T1c;
        ci[rs[5]] = T1b + T1c;
        {
            E TX, T1i, T10, T1h, TY, TZ;
            TX = TH - TK;
            T1i = T1f - T1e;
            TY = TM - TP;
            TZ = TR + TU;
            T10 = KP707106781 * (TY + TZ);
            T1h = KP707106781 * (TZ - TY);
            cr[rs[3]] = TX - T10;
            ci[rs[6]] = T1h + T1i;
            ci[0] = TX + T10;
            cr[rs[5]] = T1h - T1i;
        }
    }
    {
        E T15, T1a, T11, T14;
        T15 = T13 + T12;
        T1a = T16 + T19;
        cr[rs[4]] = T15 - T1a;
        ci[rs[7]] = T15 + T1a;
        T11 = T7 - Ti;
        T14 = T12 - T13;
        cr[rs[2]] = T11 - T14;
        ci[rs[1]] = T11 + T14;
        {
            E TL, T1g, TW, T1d, TQ, TV;
            TL = TH + TK;
            T1g = T1e + T1f;
            TQ = TM + TP;
            TV = TR - TU;
            TW = KP707106781 * (TQ + TV);
            T1d = KP707106781 * (TV - TQ);
            ci[rs[2]] = TL - TW;
            ci[rs[4]] = T1d + T1g;
            cr[rs[1]] = TL + TW;
            cr[rs[7]] = T1d - T1g;
        }
    }
}
}
