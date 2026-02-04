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
// Reduce trip count by half and unroll two iterations per loop cycle
for (m = mb , W = W + ((mb - 1) * 10); m < me; m = m + 2 , Rp = Rp + 2*ms , Ip = Ip + 2*ms , Rm = Rm - 2*ms , Im = Im - 2*ms , W = W + 20 , (rs) = (rs) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    if (m + 1 >= me) break; // Ensure safe unrolling

    E T7_0, TS_0, Tv_0, TO_0, Tt_0, TJ_0, Tx_0, TF_0, Ti_0, TI_0, Tw_0, TC_0;
    E T7_1, TS_1, Tv_1, TO_1, Tt_1, TJ_1, Tx_1, TF_1, Ti_1, TI_1, Tw_1, TC_1;

    // First iteration (m)
    {
        E T1, TN, T6, TM;
        T1 = Rp[0];
        TN = Rm[0];
        {
            E T3, T5, T2, T4;
            T3 = Ip[(rs[1])];
            T5 = Im[(rs[1])];
            T2 = W[4];
            T4 = W[5];
            T6 = (((T2) * (T3)) + (T4 * T5));
            TM = ((T2 * T5) - ((T4) * (T3)));
        }
        T7_0 = T1 - T6;
        TS_0 = TN - TM;
        Tv_0 = T1 + T6;
        TO_0 = TM + TN;
    }
    {
        E Tn, TD, Ts, TE;
        {
            E Tk, Tm, Tj, Tl;
            Tk = Rp[(rs[2])];
            Tm = Rm[(rs[2])];
            Tj = W[6];
            Tl = W[7];
            Tn = (((Tj) * (Tk)) + (Tl * Tm));
            TD = ((Tj * Tm) - ((Tl) * (Tk)));
        }
        {
            E Tp, Tr, To, Tq;
            Tp = Ip[0];
            Tr = Im[0];
            To = W[0];
            Tq = W[1];
            Ts = (((To) * (Tp)) + (Tq * Tr));
            TE = ((To * Tr) - ((Tq) * (Tp)));
        }
        Tt_0 = Tn - Ts;
        TJ_0 = TE - TD;
        Tx_0 = Tn + Ts;
        TF_0 = TD + TE;
    }
    {
        E Tc, TA, Th, TB;
        {
            E T9, Tb, T8, Ta;
            T9 = Rp[(rs[1])];
            Tb = Rm[(rs[1])];
            T8 = W[2];
            Ta = W[3];
            Tc = (((T8) * (T9)) + (Ta * Tb));
            TA = ((T8 * Tb) - ((Ta) * (T9)));
        }
        {
            E Te, Tg, Td, Tf;
            Te = Ip[(rs[2])];
            Tg = Im[(rs[2])];
            Td = W[8];
            Tf = W[9];
            Th = (((Td) * (Te)) + (Tf * Tg));
            TB = ((Td * Tg) - ((Tf) * (Te)));
        }
        Ti_0 = Tc - Th;
        TI_0 = TA - TB;
        Tw_0 = Tc + Th;
        TC_0 = TA + TB;
    }

    // Second iteration (m+1), offset pointers accordingly
    {
        E T1, TN, T6, TM;
        T1 = Rp[ms];
        TN = Rm[-ms];
        {
            E T3, T5, T2, T4;
            T3 = Ip[ms + (rs[1])];
            T5 = Im[ms + (rs[1])];
            T2 = W[14];
            T4 = W[15];
            T6 = (((T2) * (T3)) + (T4 * T5));
            TM = ((T2 * T5) - ((T4) * (T3)));
        }
        T7_1 = T1 - T6;
        TS_1 = TN - TM;
        Tv_1 = T1 + T6;
        TO_1 = TM + TN;
    }
    {
        E Tn, TD, Ts, TE;
        {
            E Tk, Tm, Tj, Tl;
            Tk = Rp[ms + (rs[2])];
            Tm = Rm[-ms + (rs[2])];
            Tj = W[16];
            Tl = W[17];
            Tn = (((Tj) * (Tk)) + (Tl * Tm));
            TD = ((Tj * Tm) - ((Tl) * (Tk)));
        }
        {
            E Tp, Tr, To, Tq;
            Tp = Ip[ms];
            Tr = Im[ms];
            To = W[10];
            Tq = W[11];
            Ts = (((To) * (Tp)) + (Tq * Tr));
            TE = ((To * Tr) - ((Tq) * (Tp)));
        }
        Tt_1 = Tn - Ts;
        TJ_1 = TE - TD;
        Tx_1 = Tn + Ts;
        TF_1 = TD + TE;
    }
    {
        E Tc, TA, Th, TB;
        {
            E T9, Tb, T8, Ta;
            T9 = Rp[ms + (rs[1])];
            Tb = Rm[-ms + (rs[1])];
            T8 = W[12];
            Ta = W[13];
            Tc = (((T8) * (T9)) + (Ta * Tb));
            TA = ((T8 * Tb) - ((Ta) * (T9)));
        }
        {
            E Te, Tg, Td, Tf;
            Te = Ip[ms + (rs[2])];
            Tg = Im[ms + (rs[2])];
            Td = W[18];
            Tf = W[19];
            Th = (((Td) * (Te)) + (Tf * Tg));
            TB = ((Td * Tg) - ((Tf) * (Te)));
        }
        Ti_1 = Tc - Th;
        TI_1 = TA - TB;
        Tw_1 = Tc + Th;
        TC_1 = TA + TB;
    }

    // Update outputs for first iteration
    {
        E TK, Tu, TH, TT, TR, TU;
        TK = KP866025403 * (TI_0 + TJ_0);
        Tu = Ti_0 + Tt_0;
        TH = ((T7_0) - ((KP500000000) * (Tu)));
        Rm[(rs[2])] = T7_0 + Tu;
        Rp[(rs[1])] = TH + TK;
        Rm[0] = TH - TK;
        TT = KP866025403 * (Tt_0 - Ti_0);
        TR = TJ_0 - TI_0;
        TU = (((KP500000000) * (TR)) + (TS_0));
        Im[(rs[2])] = TR - TS_0;
        Ip[(rs[1])] = TT + TU;
        Im[0] = TT - TU;
    }
    {
        E TG, Ty, Tz, TP, TL, TQ;
        TG = KP866025403 * (TC_0 - TF_0);
        Ty = Tw_0 + Tx_0;
        Tz = ((Tv_0) - ((KP500000000) * (Ty)));
        Rp[0] = Tv_0 + Ty;
        Rm[(rs[1])] = Tz + TG;
        Rp[(rs[2])] = Tz - TG;
        TP = KP866025403 * (Tw_0 - Tx_0);
        TL = TC_0 + TF_0;
        TQ = ((TO_0) - ((KP500000000) * (TL)));
        Ip[0] = TL + TO_0;
        Ip[(rs[2])] = TP + TQ;
        Im[(rs[1])] = TP - TQ;
    }

    // Update outputs for second iteration
    {
        E TK, Tu, TH, TT, TR, TU;
        TK = KP866025403 * (TI_1 + TJ_1);
        Tu = Ti_1 + Tt_1;
        TH = ((T7_1) - ((KP500000000) * (Tu)));
        Rm[-ms + (rs[2])] = T7_1 + Tu;
        Rp[ms + (rs[1])] = TH + TK;
        Rm[ms] = TH - TK;
        TT = KP866025403 * (Tt_1 - Ti_1);
        TR = TJ_1 - TI_1;
        TU = (((KP500000000) * (TR)) + (TS_1));
        Im[ms + (rs[2])] = TR - TS_1;
        Ip[ms + (rs[1])] = TT + TU;
        Im[ms] = TT - TU;
    }
    {
        E TG, Ty, Tz, TP, TL, TQ;
        TG = KP866025403 * (TC_1 - TF_1);
        Ty = Tw_1 + Tx_1;
        Tz = ((Tv_1) - ((KP500000000) * (Ty)));
        Rp[ms] = Tv_1 + Ty;
        Rm[ms + (rs[1])] = Tz + TG;
        Rp[ms + (rs[2])] = Tz - TG;
        TP = KP866025403 * (Tw_1 - Tx_1);
        TL = TC_1 + TF_1;
        TQ = ((TO_1) - ((KP500000000) * (TL)));
        Ip[ms] = TL + TO_1;
        Ip[ms + (rs[2])] = TP + TQ;
        Im[ms + (rs[1])] = TP - TQ;
    }
}
}
