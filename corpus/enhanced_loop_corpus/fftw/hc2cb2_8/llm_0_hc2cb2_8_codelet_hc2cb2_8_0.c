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
for (m = mb , W = W + ((mb - 1) * 6); m < me; m = m + 1 , Rp = Rp + ms , Ip = Ip + ms , Rm = Rm - ms , Im = Im - ms , W = W + 6 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E Tf, Ti, Tg, Tj, Tl, Tp, TP, TR, TF, TG, TH, T15, TL, TT;
    {
        E Th, To, Tk, Tn;
        Tf = W[0];
        Ti = W[1];
        Tg = W[2];
        Tj = W[3];
        Th = Tf * Tg;
        To = Ti * Tg;
        Tk = Ti * Tj;
        Tn = Tf * Tj;
        Tl = Th - Tk;
        Tp = Tn + To;
        TP = Th + Tk;
        TR = Tn - To;
        TF = W[4];
        TG = W[5];
        TH = (((Tf) * (TF)) + (Ti * TG));
        T15 = ((TP * TG) - ((TR) * (TF)));
        TL = ((Tf * TG) - ((Ti) * (TF)));
        TT = (((TP) * (TF)) + (TR * TG));
    }
    for (INT inner = 0; inner < 1; ++inner) {
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
        Rp[(rs[2])] = ((Tl * Tm) - ((Tp) * (TE)));
        Rm[(rs[2])] = (((Tp) * (Tm)) + (Tl * TE));
        {
            E TQ, TS, TK, TO;
            TQ = TI + TJ;
            TS = TN + TM;
            Rp[(rs[1])] = ((TP * TQ) - ((TR) * (TS)));
            Rm[(rs[1])] = (((TP) * (TS)) + (TR * TQ));
            TK = TI - TJ;
            TO = TM - TN;
            Rp[(rs[3])] = ((TH * TK) - ((TL) * (TO)));
            Rm[(rs[3])] = (((TH) * (TO)) + (TL * TK));
        }
        {
            E T1h, T1l, T1k, T1m, T1g, T1j;
            T1g = KP707106781 * (T19 + T1a);
            T1h = T1f - T1g;
            T1l = T1f + T1g;
            T1j = KP707106781 * (TZ - T12);
            T1k = T1i + T1j;
            T1m = T1i - T1j;
            Ip[(rs[1])] = ((Tg * T1h) - ((Tj) * (T1k)));
            Im[(rs[1])] = (((Tg) * (T1k)) + (Tj * T1h));
            Ip[(rs[3])] = ((TF * T1l) - ((TG) * (T1m)));
            Im[(rs[3])] = (((TF) * (T1m)) + (TG * T1l));
        }
        {
            E T14, T1d, T1c, T1e, T13, T1b;
            T13 = KP707106781 * (TZ + T12);
            T14 = TW - T13;
            T1d = TW + T13;
            T1b = KP707106781 * (T19 - T1a);
            T1c = T18 - T1b;
            T1e = T18 + T1b;
            Ip[(rs[2])] = ((TT * T14) - ((T15) * (T1c)));
            Im[(rs[2])] = (((T15) * (T14)) + (TT * T1c));
            Ip[0] = ((Tf * T1d) - ((Ti) * (T1e)));
            Im[0] = (((Ti) * (T1d)) + (Tf * T1e));
        }
    }
}
}
