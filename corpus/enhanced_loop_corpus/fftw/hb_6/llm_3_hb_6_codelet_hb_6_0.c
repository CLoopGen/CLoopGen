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
extern  E KP500000000;
extern  E KP866025403;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 10); m < me; m = m + 1 , cr += ms, ci -= ms , W += 10 , (rs) += fftw_an_INT_guaranteed_to_be_zero) {
    E T3, Ty, Ta, TO, Tr, TB, Td, TE, Tk, TL, Tn, TH;
    const INT s = rs[0];  // Assume unit stride base; convert strided to consecutive via precomputed array views
    R *cr_consec = cr;   // Conceptual consecutive view
    R *ci_consec = ci;
    R wbuf[10];
    for (INT i = 0; i < 10; ++i) wbuf[i] = W[i];  // Local copy to enable dense access

    {
        E T1, T2, Tb, Tc;
        T1 = cr_consec[0*s];
        T2 = ci_consec[2*s];
        T3 = T1 + T2;
        Ty = T1 - T2;
        {
            E T6, Tz, T9, TA;
            {
                E T4, T5, T7, T8;
                T4 = cr_consec[2*s];
                T5 = ci_consec[0*s];
                T6 = T4 + T5;
                Tz = T4 - T5;
                T7 = ci_consec[1*s];
                T8 = cr_consec[1*s];
                T9 = T7 + T8;
                TA = T7 - T8;
            }
            Ta = T6 + T9;
            TO = KP866025403 * (Tz - TA);
            Tr = KP866025403 * (T6 - T9);
            TB = Tz + TA;
        }
        Tb = ci_consec[5*s];
        Tc = cr_consec[3*s];
        Td = Tb - Tc;
        TE = Tb + Tc;
        {
            E Tg, TG, Tj, TF;
            {
                E Te, Tf, Th, Ti;
                Te = ci_consec[3*s];
                Tf = cr_consec[5*s];
                Tg = Te - Tf;
                TG = Te + Tf;
                Th = ci_consec[4*s];
                Ti = cr_consec[4*s];
                Tj = Th - Ti;
                TF = Th + Ti;
            }
            Tk = Tg + Tj;
            TL = KP866025403 * (TG + TF);
            Tn = KP866025403 * (Tj - Tg);
            TH = TF - TG;
        }
    }
    cr_consec[0*s] = T3 + Ta;
    ci_consec[0*s] = Td + Tk;
    {
        E TC, TI, Tx, TD;
        TC = Ty + TB;
        TI = TE - TH;
        Tx = wbuf[4];
        TD = wbuf[5];
        cr_consec[3*s] = ((Tx * TC) - (TD * TI));
        ci_consec[3*s] = (TD * TC) + (Tx * TI);
    }
    {
        E To, Tu, Ts, Tw, Tm, Tq;
        Tm = T3 - (KP500000000 * Ta);
        To = Tm - Tn;
        Tu = Tm + Tn;
        Tq = Td - (KP500000000 * Tk);
        Ts = Tq - Tr;
        Tw = Tr + Tq;
        {
            E Tl, Tp, Tt, Tv;
            Tl = wbuf[2];
            Tp = wbuf[3];
            cr_consec[2*s] = (Tl * To) - (Tp * Ts);
            ci_consec[2*s] = (Tl * Ts) + (Tp * To);
            Tt = wbuf[6];
            Tv = wbuf[7];
            cr_consec[4*s] = (Tt * Tu) - (Tv * Tw);
            ci_consec[4*s] = (Tt * Tw) + (Tv * Tu);
        }
    }
    {
        E TM, TS, TQ, TU, TK, TP;
        TK = Ty - (KP500000000 * TB);
        TM = TK - TL;
        TS = TK + TL;
        TP = (KP500000000 * TH) + TE;
        TQ = TO + TP;
        TU = TP - TO;
        {
            E TJ, TN, TR, TT;
            TJ = wbuf[0];
            TN = wbuf[1];
            cr_consec[1*s] = (TJ * TM) - (TN * TQ);
            ci_consec[1*s] = (TN * TM) + (TJ * TQ);
            TR = wbuf[8];
            TT = wbuf[9];
            cr_consec[5*s] = (TR * TS) - (TT * TU);
            ci_consec[5*s] = (TT * TS) + (TR * TU);
        }
    }
}
}
