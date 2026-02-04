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
extern  E KP250000000;
extern  E KP500000000;
extern  E KP433012701;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 10); m < me; m = m + 1 , Rp = Rp + ms , Ip = Ip + ms , Rm = Rm - ms , Im = Im - ms , W = W + 10 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, TM, Tc, TN, Ts, T10, TI, TR, TF, T11, TH, TU;
    const INT s = rs[0]; // Assume base stride is constant per iteration for clarity
    {
        E T1, T2, TD, Tz, TA, TB, T7, Tf, Tb, Th, Tq, Tw, Tm, Tu, T4;
        E T8;
        {
            E T5, T6, T9, Ta;
            // Convert strided access into consecutive local array using direct offsets
            E temp_Ip[3], temp_Im[3], temp_Rp[3], temp_Rm[3];
            temp_Ip[0] = Ip[0];           temp_Im[0] = Im[0];
            temp_Ip[1] = Ip[s];           temp_Im[1] = Im[s];
            temp_Ip[2] = Ip[2*s];         temp_Im[2] = Im[2*s];
            temp_Rp[0] = Rp[0];           temp_Rm[0] = Rm[0];
            temp_Rp[1] = Rp[s];           temp_Rm[1] = Rm[s];
            temp_Rp[2] = Rp[2*s];         temp_Rm[2] = Rm[2*s];

            T1 = temp_Ip[0];
            T2 = temp_Im[0];
            TD = T1 + T2;
            Tz = temp_Rm[0];
            TA = temp_Rp[0];
            TB = Tz - TA;
            T5 = temp_Ip[1];
            T6 = temp_Im[1];
            T7 = T5 + T6;
            Tf = T5 - T6;
            T9 = temp_Rp[1];
            Ta = temp_Rm[1];
            Tb = T9 - Ta;
            Th = T9 + Ta;

            Tq = temp_Rp[2] - temp_Rm[2];
            Tw = temp_Rp[2] + temp_Rm[2];
            Tm = temp_Ip[2] + temp_Im[2];
            Tu = temp_Ip[2] - temp_Im[2];
        }
        T3 = T1 - T2;
        TM = TA + Tz;
        T4 = W[5];
        T8 = W[4];
        Tc = (((T4) * (T7)) + (T8 * Tb));
        TN = ((T8 * T7) - ((T4) * (Tb)));
        {
            E Ti, TP, Tr, TQ;
            {
                E Te, Tg, Tj, Tn;
                Te = W[2];
                Tg = W[3];
                Ti = ((Te * Tf) - ((Tg) * (Th)));
                TP = (((Tg) * (Tf)) + (Te * Th));
                Tj = W[9];
                Tn = W[8];
                Tr = (((Tj) * (Tm)) + (Tn * Tq));
                TQ = ((Tn * Tm) - ((Tj) * (Tq)));
            }
            Ts = Ti - Tr;
            T10 = TP + TQ;
            TI = Ti + Tr;
            TR = TP - TQ;
        }
        {
            E Tx, TS, TE, TT;
            {
                E Tt, Tv, Ty, TC;
                Tt = W[6];
                Tv = W[7];
                Tx = ((Tt * Tu) - ((Tv) * (Tw)));
                TS = (((Tv) * (Tu)) + (Tt * Tw));
                Ty = W[0];
                TC = W[1];
                TE = ((Ty * TB) - ((TC) * (TD)));
                TT = (((TC) * (TB)) + (Ty * TD));
            }
            TF = Tx + TE;
            T11 = TS + TT;
            TH = TE - Tx;
            TU = TS - TT;
        }
    }
    {
        E T12, Td, TG, TZ;
        T12 = KP433012701 * (T10 - T11);
        Td = T3 - Tc;
        TG = Ts + TF;
        TZ = ((KP500000000 * Td) - ((KP250000000) * (TG)));
        Ip[0] = KP500000000 * (Td + TG);
        Im[s] = T12 - TZ;
        Ip[2*s] = TZ + T12;
    }
    {
        E T16, T13, T14, T15;
        T16 = KP433012701 * (Ts - TF);
        T13 = TM + TN;
        T14 = T10 + T11;
        T15 = ((KP500000000 * T13) - ((KP250000000) * (T14)));
        Rp[2*s] = T15 - T16;
        Rp[0] = KP500000000 * (T13 + T14);
        Rm[s] = T16 + T15;
    }
    {
        E TY, TJ, TK, TX;
        TY = KP433012701 * (TU - TR);
        TJ = TH - TI;
        TK = Tc + T3;
        TX = (((KP500000000) * (TK)) + (KP250000000 * TJ));
        Im[2*s] = KP500000000 * (TJ - TK);
        Im[0] = TY - TX;
        Ip[s] = TX + TY;
    }
    {
        E TL, TO, TV, TW;
        TL = KP433012701 * (TI + TH);
        TO = TM - TN;
        TV = TR + TU;
        TW = ((KP500000000 * TO) - ((KP250000000) * (TV)));
        Rp[s] = TL + TW;
        Rm[2*s] = KP500000000 * (TO + TV);
        Rm[0] = TW - TL;
    }
}
}
