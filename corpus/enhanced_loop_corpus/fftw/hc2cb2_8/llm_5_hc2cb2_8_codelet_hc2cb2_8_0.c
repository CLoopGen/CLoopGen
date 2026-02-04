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

    E T7 = 0.0, T1f = 0.0, T1i = 0.0, Tw = 0.0, TI = 0.0, TW = 0.0, T18 = 0.0, TM = 0.0;
    E Te = 0.0, T19 = 0.0, T1a = 0.0, TD = 0.0, TJ = 0.0, TZ = 0.0, T12 = 0.0;
    E TN = 0.0, Tm, TE;

    if (m >= mb + 2) {
        {
            E T3, TU, Ts, T17, T6, T16, Tv, TV;
            T3 = Rp[0] + Rm[(rs[3])];
            TU = Rp[0] - Rm[(rs[3])];
            Ts = Ip[0] - Im[(rs[3])];
            T17 = Ip[0] + Im[(rs[3])];
            T6 = Rp[(rs[2])] + Rm[(rs[1])];
            T16 = Rp[(rs[2])] - Rm[(rs[1])];
            Tv = Ip[(rs[2])] - Im[(rs[1])];
            TV = Ip[(rs[2])] + Im[(rs[1])];

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
            Ta = Rp[(rs[1])] + Rm[(rs[2])];
            TX = Rp[(rs[1])] - Rm[(rs[2])];
            Tz = Ip[(rs[1])] - Im[(rs[2])];
            TY = Ip[(rs[1])] + Im[(rs[2])];
            Td = Rm[0] + Rp[(rs[3])];
            T10 = Rm[0] - Rp[(rs[3])];
            TC = Ip[(rs[3])] - Im[0];
            T11 = Ip[(rs[3])] + Im[0];

            Te = Ta + Td;
            T19 = TX + TY;
            T1a = T10 + T11;
            TD = Tz + TC;
            TJ = TC - Tz;
            TZ = TX - TY;
            T12 = T10 - T11;
            TN = Ta - Td;
        }
    } else {
        T7 = Rp[0] + Rp[(rs[2])] + Rm[(rs[3])] + Rm[(rs[1])];
        Te = Rp[(rs[1])] + Rp[(rs[3])] + Rm[(rs[2])] + Rm[0];
        Tw = Ip[0] + Ip[(rs[2])] - Im[(rs[3])] - Im[(rs[1])];
        TD = Ip[(rs[1])] + Ip[(rs[3])] - Im[(rs[2])] - Im[0];

        TI = Rp[0] - Rp[(rs[2])] + Rm[(rs[3])] - Rm[(rs[1])];
        TM = Ip[0] - Ip[(rs[2])] - Im[(rs[3])] + Im[(rs[1])];
        TN = Rp[(rs[1])] - Rp[(rs[3])] + Rm[(rs[2])] - Rm[0];
        TJ = Ip[(rs[3])] - Ip[(rs[1])] - Im[0] + Im[(rs[2])];
        TZ = Ip[(rs[1])] - Im[(rs[2])] - Ip[(rs[2])] + Im[(rs[1])];
        T12 = Rp[(rs[1])] - Rp[(rs[3])] - Rm[(rs[2])] + Rm[0];
        T1f = Ip[(rs[1])] + Ip[(rs[2])] + Im[(rs[1])] + Im[(rs[2])];
        T1i = Ip[0] + Ip[(rs[3])] + Im[0] + Im[(rs[3])] - (Rp[(rs[2])] - Rm[(rs[1])]);
        T19 = Rp[(rs[1])] + Rm[(rs[2])] + Ip[(rs[1])] + Ip[(rs[2])];
        T1a = Rp[(rs[3])] + Rm[0] + Ip[(rs[3])] + Im[0];
        T18 = Rp[(rs[2])] + Rm[(rs[1])] + Ip[0] + Ip[(rs[3])];
        TW = Rp[0] - Rp[(rs[2])] - Rm[(rs[3])] + Rm[(rs[1])];
    }

    Rp[0] = T7 + Te;
    Rm[0] = Tw + TD;
    Tm = T7 - Te;
    TE = Tw - TD;
    Rp[(rs[2])] = ((Tl * Tm) - ((Tp) * (TE)));
    Rm[(rs[2])] = (((Tp) * (Tm)) + (Tl * TE));

    {
        E TQ = TI + TJ;
        E TS = TN + TM;
        Rp[(rs[1])] = ((TP * TQ) - ((TR) * (TS)));
        Rm[(rs[1])] = (((TP) * (TS)) + (TR * TQ));
    }
    {
        E TK = TI - TJ;
        E TO = TM - TN;
        Rp[(rs[3])] = ((TH * TK) - ((TL) * (TO)));
        Rm[(rs[3])] = (((TH) * (TO)) + (TL * TK));
    }
    {
        E T1g = KP707106781 * (T19 + T1a);
        E T1h = T1f - T1g;
        E T1l = T1f + T1g;
        E T1j = KP707106781 * (TZ - T12);
        E T1k = T1i + T1j;
        E T1m = T1i - T1j;
        Ip[(rs[1])] = ((Tg * T1h) - ((Tj) * (T1k)));
        Im[(rs[1])] = (((Tg) * (T1k)) + (Tj * T1h));
        Ip[(rs[3])] = ((TF * T1l) - ((TG) * (T1m)));
        Im[(rs[3])] = (((TF) * (T1m)) + (TG * T1l));
    }
    {
        E T13 = KP707106781 * (TZ + T12);
        E T14 = TW - T13;
        E T1d = TW + T13;
        E T1b = KP707106781 * (T19 - T1a);
        E T1c = T18 - T1b;
        E T1e = T18 + T1b;
        Ip[(rs[2])] = ((TT * T14) - ((T15) * (T1c)));
        Im[(rs[2])] = (((T15) * (T14)) + (TT * T1c));
        Ip[0] = ((Tf * T1d) - ((Ti) * (T1e)));
        Im[0] = (((Ti) * (T1d)) + (Tf * T1e));
    }
}
}
