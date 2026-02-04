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
for (m = mb , W = W + ((mb - 1) * 6); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 6 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
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
    {
        E T7, T1f, T1i, Tw, TI, TW, T18, TM, Te, T19, T1a, TD, TJ, TZ, T12;
        E TN, Tm, TE;
        {
            E T3, TU, Tv, TV, T6, T16, Ts, T17;
            {
                E T1, T2, Tt, Tu;
                T1 = cr[0];
                T2 = ci[(rs[3])];
                T3 = T1 + T2;
                TU = T1 - T2;
                Tt = ci[(rs[5])];
                Tu = cr[(rs[6])];
                Tv = Tt - Tu;
                TV = Tt + Tu;
            }
            {
                E T4, T5, Tq, Tr;
                T4 = cr[(rs[2])];
                T5 = ci[(rs[1])];
                T6 = T4 + T5;
                T16 = T4 - T5;
                Tq = ci[(rs[7])];
                Tr = cr[(rs[4])];
                Ts = Tq - Tr;
                T17 = Tq + Tr;
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
            E Ta, TX, TC, T11, Td, T10, Tz, TY;
            {
                E T8, T9, TA, TB;
                T8 = cr[(rs[1])];
                T9 = ci[(rs[2])];
                Ta = T8 + T9;
                TX = T8 - T9;
                TA = ci[(rs[4])];
                TB = cr[(rs[7])];
                TC = TA - TB;
                T11 = TA + TB;
            }
            {
                E Tb, Tc, Tx, Ty;
                Tb = ci[0];
                Tc = cr[(rs[3])];
                Td = Tb + Tc;
                T10 = Tb - Tc;
                Tx = ci[(rs[6])];
                Ty = cr[(rs[5])];
                Tz = Tx - Ty;
                TY = Tx + Ty;
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
        cr[0] = T7 + Te;
        ci[0] = Tw + TD;
        Tm = T7 - Te;
        TE = Tw - TD;
        cr[(rs[4])] = ((Tl * Tm) - ((Tp) * (TE)));
        ci[(rs[4])] = (((Tp) * (Tm)) + (Tl * TE));
        {
            E TQ, TS, TK, TO;
            TQ = TI + TJ;
            TS = TN + TM;
            cr[(rs[2])] = ((TP * TQ) - ((TR) * (TS)));
            ci[(rs[2])] = (((TP) * (TS)) + (TR * TQ));
            TK = TI - TJ;
            TO = TM - TN;
            cr[(rs[6])] = ((TH * TK) - ((TL) * (TO)));
            ci[(rs[6])] = (((TH) * (TO)) + (TL * TK));
        }
        {
            E T1h, T1l, T1k, T1m, T1g, T1j;
            T1g = KP707106781 * (T19 + T1a);
            T1h = T1f - T1g;
            T1l = T1f + T1g;
            T1j = KP707106781 * (TZ - T12);
            T1k = T1i + T1j;
            T1m = T1i - T1j;
            cr[(rs[3])] = ((Tg * T1h) - ((Tj) * (T1k)));
            ci[(rs[3])] = (((Tg) * (T1k)) + (Tj * T1h));
            cr[(rs[7])] = ((TF * T1l) - ((TG) * (T1m)));
            ci[(rs[7])] = (((TF) * (T1m)) + (TG * T1l));
        }
        {
            E T14, T1d, T1c, T1e, T13, T1b;
            T13 = KP707106781 * (TZ + T12);
            T14 = TW - T13;
            T1d = TW + T13;
            T1b = KP707106781 * (T19 - T1a);
            T1c = T18 - T1b;
            T1e = T18 + T1b;
            cr[(rs[5])] = ((TT * T14) - ((T15) * (T1c)));
            ci[(rs[5])] = (((T15) * (T14)) + (TT * T1c));
            cr[(rs[1])] = ((Tf * T1d) - ((Ti) * (T1e)));
            ci[(rs[1])] = (((Ti) * (T1d)) + (Tf * T1e));
        }
    }
}

}
