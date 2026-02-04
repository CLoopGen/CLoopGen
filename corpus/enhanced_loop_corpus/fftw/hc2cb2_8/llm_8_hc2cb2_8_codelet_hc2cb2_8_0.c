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
for (m = mb , W = W + ((mb - 1) * 6); m < me; m = m + 2 , Rp = Rp + (2 * ms) , Ip = Ip + (2 * ms) , Rm = Rm - (2 * ms) , Im = Im - (2 * ms) , W = W + 12 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    if (m + 1 >= me) break;
    E Tf0, Ti0, Tg0, Tj0, Tl0, Tp0, TP0, TR0, TF0, TG0, TH0, T150, TL0, TT0;
    E Tf1, Ti1, Tg1, Tj1, Tl1, Tp1, TP1, TR1, TF1, TG1, TH1, T151, TL1, TT1;
    {
        E Th0, To0, Tk0, Tn0;
        Tf0 = W[0];
        Ti0 = W[1];
        Tg0 = W[2];
        Tj0 = W[3];
        Th0 = Tf0 * Tg0;
        To0 = Ti0 * Tg0;
        Tk0 = Ti0 * Tj0;
        Tn0 = Tf0 * Tj0;
        Tl0 = Th0 - Tk0;
        Tp0 = Tn0 + To0;
        TP0 = Th0 + Tk0;
        TR0 = Tn0 - To0;
        TF0 = W[4];
        TG0 = W[5];
        TH0 = (((Tf0) * (TF0)) + (Ti0 * TG0));
        T150 = ((TP0 * TG0) - ((TR0) * (TF0)));
        TL0 = ((Tf0 * TG0) - ((Ti0) * (TF0)));
        TT0 = (((TP0) * (TF0)) + (TR0 * TG0));
    }
    {
        E Th1, To1, Tk1, Tn1;
        Tf1 = W[6];
        Ti1 = W[7];
        Tg1 = W[8];
        Tj1 = W[9];
        Th1 = Tf1 * Tg1;
        To1 = Ti1 * Tg1;
        Tk1 = Ti1 * Tj1;
        Tn1 = Tf1 * Tj1;
        Tl1 = Th1 - Tk1;
        Tp1 = Tn1 + To1;
        TP1 = Th1 + Tk1;
        TR1 = Tn1 - To1;
        TF1 = W[10];
        TG1 = W[11];
        TH1 = (((Tf1) * (TF1)) + (Ti1 * TG1));
        T151 = ((TP1 * TG1) - ((TR1) * (TF1)));
        TL1 = ((Tf1 * TG1) - ((Ti1) * (TF1)));
        TT1 = (((TP1) * (TF1)) + (TR1 * TG1));
    }
    {
        E T7, T1f, T1i, Tw, TI, TW, T18, TM, Te, T19, T1a, TD, TJ, TZ, T12;
        E TN, Tm, TE;
        {
            E T3, TU, Ts, T17, T6, T16, Tv, TV;
            {
                E T1, T2, Tq, Tr;
                T1 = Rp[0];
                T2 = Rm[(rs[3])];
                T3 = T1 + T2;
                TU = T1 - T2;
                Tq = Ip[0];
                Tr = Im[(rs[3])];
                Ts = Tq - Tr;
                T17 = Tq + Tr;
            }
            {
                E T4, T5, Tt, Tu;
                T4 = Rp[(rs[2])];
                T5 = Rm[(rs[1])];
                T6 = T4 + T5;
                T16 = T4 - T5;
                Tt = Ip[(rs[2])];
                Tu = Im[(rs[1])];
                Tv = Tt - Tu;
                TV = Tt + Tu;
            }
            T7 = T3 + T6;
            T1f = TU + TV;
            T1i = T17 - T16;
            Tw = Ts + Tv;
            TI = T3 - T6;
            TW = TU - TV;
            T18 = T16 + T17;
            TM = Ts - Tv;
        }
        {
            E Ta, TX, Tz, TY, Td, T10, TC, T11;
            {
                E T8, T9, Tx, Ty;
                T8 = Rp[(rs[1])];
                T9 = Rm[(rs[2])];
                Ta = T8 + T9;
                TX = T8 - T9;
                Tx = Ip[(rs[1])];
                Ty = Im[(rs[2])];
                Tz = Tx - Ty;
                TY = Tx + Ty;
            }
            {
                E Tb, Tc, TA, TB;
                Tb = Rm[0];
                Tc = Rp[(rs[3])];
                Td = Tb + Tc;
                T10 = Tb - Tc;
                TA = Ip[(rs[3])];
                TB = Im[0];
                TC = TA - TB;
                T11 = TA + TB;
            }
            Te = Ta + Td;
            T19 = TX + TY;
            T1a = T10 + T11;
            TD = Tz + TC;
            TJ = TC - Tz;
            TZ = TX - TY;
            T12 = T10 - T11;
            TN = Ta - Td;
        }
        Rp[0] = T7 + Te;
        Rm[0] = Tw + TD;
        Tm = T7 - Te;
        TE = Tw - TD;
        Rp[(rs[2])] = ((Tl0 * Tm) - ((Tp0) * (TE)));
        Rm[(rs[2])] = (((Tp0) * (Tm)) + (Tl0 * TE));
        {
            E TQ, TS, TK, TO;
            TQ = TI + TJ;
            TS = TN + TM;
            Rp[(rs[1])] = ((TP0 * TQ) - ((TR0) * (TS)));
            Rm[(rs[1])] = (((TP0) * (TS)) + (TR0 * TQ));
            TK = TI - TJ;
            TO = TM - TN;
            Rp[(rs[3])] = ((TH0 * TK) - ((TL0) * (TO)));
            Rm[(rs[3])] = (((TH0) * (TO)) + (TL0 * TK));
        }
        {
            E T1h, T1l, T1k, T1m, T1g, T1j;
            T1g = KP707106781 * (T19 + T1a);
            T1h = T1f - T1g;
            T1l = T1f + T1g;
            T1j = KP707106781 * (TZ - T12);
            T1k = T1i + T1j;
            T1m = T1i - T1j;
            Ip[(rs[1])] = ((Tg0 * T1h) - ((Tj0) * (T1k)));
            Im[(rs[1])] = (((Tg0) * (T1k)) + (Tj0 * T1h));
            Ip[(rs[3])] = ((TF0 * T1l) - ((TG0) * (T1m)));
            Im[(rs[3])] = (((TF0) * (T1m)) + (TG0 * T1l));
        }
        {
            E T14, T1d, T1c, T1e, T13, T1b;
            T13 = KP707106781 * (TZ + T12);
            T14 = TW - T13;
            T1d = TW + T13;
            T1b = KP707106781 * (T19 - T1a);
            T1c = T18 - T1b;
            T1e = T18 + T1b;
            Ip[(rs[2])] = ((TT0 * T14) - ((T150) * (T1c)));
            Im[(rs[2])] = (((T150) * (T14)) + (TT0 * T1c));
            Ip[0] = ((Tf0 * T1d) - ((Ti0) * (T1e)));
            Im[0] = (((Ti0) * (T1d)) + (Tf0 * T1e));
        }
    }
    {
        E T7, T1f, T1i, Tw, TI, TW, T18, TM, Te, T19, T1a, TD, TJ, TZ, T12;
        E TN, Tm, TE;
        {
            E T3, TU, Ts, T17, T6, T16, Tv, TV;
            {
                E T1, T2, Tq, Tr;
                T1 = Rp[ms];
                T2 = Rm[(rs[3]) - ms];
                T3 = T1 + T2;
                TU = T1 - T2;
                Tq = Ip[ms];
                Tr = Im[(rs[3]) - ms];
                Ts = Tq - Tr;
                T17 = Tq + Tr;
            }
            {
                E T4, T5, Tt, Tu;
                T4 = Rp[(rs[2]) + ms];
                T5 = Rm[(rs[1]) - ms];
                T6 = T4 + T5;
                T16 = T4 - T5;
                Tt = Ip[(rs[2]) + ms];
                Tu = Im[(rs[1]) - ms];
                Tv = Tt - Tu;
                TV = Tt + Tu;
            }
            T7 = T3 + T6;
            T1f = TU + TV;
            T1i = T17 - T16;
            Tw = Ts + Tv;
            TI = T3 - T6;
            TW = TU - TV;
            T18 = T16 + T17;
            TM = Ts - Tv;
        }
        {
            E Ta, TX, Tz, TY, Td, T10, TC, T11;
            {
                E T8, T9, Tx, Ty;
                T8 = Rp[(rs[1]) + ms];
                T9 = Rm[(rs[2]) - ms];
                Ta = T8 + T9;
                TX = T8 - T9;
                Tx = Ip[(rs[1]) + ms];
                Ty = Im[(rs[2]) - ms];
                Tz = Tx - Ty;
                TY = Tx + Ty;
            }
            {
                E Tb, Tc, TA, TB;
                Tb = Rm[-ms];
                Tc = Rp[(rs[3]) + ms];
                Td = Tb + Tc;
                T10 = Tb - Tc;
                TA = Ip[(rs[3]) + ms];
                TB = Im[-ms];
                TC = TA - TB;
                T11 = TA + TB;
            }
            Te = Ta + Td;
            T19 = TX + TY;
            T1a = T10 + T11;
            TD = Tz + TC;
            TJ = TC - Tz;
            TZ = TX - TY;
            T12 = T10 - T11;
            TN = Ta - Td;
        }
        Rp[ms] = T7 + Te;
        Rm[-ms] = Tw + TD;
        Tm = T7 - Te;
        TE = Tw - TD;
        Rp[(rs[2]) + ms] = ((Tl1 * Tm) - ((Tp1) * (TE)));
        Rm[(rs[2]) - ms] = (((Tp1) * (Tm)) + (Tl1 * TE));
        {
            E TQ, TS, TK, TO;
            TQ = TI + TJ;
            TS = TN + TM;
            Rp[(rs[1]) + ms] = ((TP1 * TQ) - ((TR1) * (TS)));
            Rm[(rs[1]) - ms] = (((TP1) * (TS)) + (TR1 * TQ));
            TK = TI - TJ;
            TO = TM - TN;
            Rp[(rs[3]) + ms] = ((TH1 * TK) - ((TL1) * (TO)));
            Rm[(rs[3]) - ms] = (((TH1) * (TO)) + (TL1 * TK));
        }
        {
            E T1h, T1l, T1k, T1m, T1g, T1j;
            T1g = KP707106781 * (T19 + T1a);
            T1h = T1f - T1g;
            T1l = T1f + T1g;
            T1j = KP707106781 * (TZ - T12);
            T1k = T1i + T1j;
            T1m = T1i - T1j;
            Ip[(rs[1]) + ms] = ((Tg1 * T1h) - ((Tj1) * (T1k)));
            Im[(rs[1]) - ms] = (((Tg1) * (T1k)) + (Tj1 * T1h));
            Ip[(rs[3]) + ms] = ((TF1 * T1l) - ((TG1) * (T1m)));
            Im[(rs[3]) - ms] = (((TF1) * (T1m)) + (TG1 * T1l));
        }
        {
            E T14, T1d, T1c, T1e, T13, T1b;
            T13 = KP707106781 * (TZ + T12);
            T14 = TW - T13;
            T1d = TW + T13;
            T1b = KP707106781 * (T19 - T1a);
            T1c = T18 - T1b;
            T1e = T18 + T1b;
            Ip[(rs[2]) + ms] = ((TT1 * T14) - ((T151) * (T1c)));
            Im[(rs[2]) - ms] = (((T151) * (T14)) + (TT1 * T1c));
            Ip[ms] = ((Tf1 * T1d) - ((Ti1) * (T1e)));
            Im[ms] = (((Ti1) * (T1d)) + (Tf1 * T1e));
        }
    }
}
}
