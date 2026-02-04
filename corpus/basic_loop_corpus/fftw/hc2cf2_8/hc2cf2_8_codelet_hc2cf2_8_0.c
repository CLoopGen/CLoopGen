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
    E T2, T5, T3, T6, T8, Tc, Tg, Ti, Tl, Tm, Tn, Tz, Tp, Tx;
    {
        E T4, Tb, T7, Ta;
        T2 = W[0];
        T5 = W[1];
        T3 = W[2];
        T6 = W[3];
        T4 = T2 * T3;
        Tb = T5 * T3;
        T7 = T5 * T6;
        Ta = T2 * T6;
        T8 = T4 - T7;
        Tc = Ta + Tb;
        Tg = T4 + T7;
        Ti = Ta - Tb;
        Tl = W[4];
        Tm = W[5];
        Tn = (((T2) * (Tl)) + (T5 * Tm));
        Tz = ((Tg * Tm) - ((Ti) * (Tl)));
        Tp = ((T2 * Tm) - ((T5) * (Tl)));
        Tx = (((Tg) * (Tl)) + (Ti * Tm));
    }
    {
        E Tf, T1i, TL, T1d, TJ, T17, TV, TY, Ts, T1j, TO, T1a, TC, T16, TQ;
        E TT;
        {
            E T1, T1c, Te, T1b, T9, Td;
            T1 = Rp[0];
            T1c = Rm[0];
            T9 = Rp[(rs[2])];
            Td = Rm[(rs[2])];
            Te = (((T8) * (T9)) + (Tc * Td));
            T1b = ((T8 * Td) - ((Tc) * (T9)));
            Tf = T1 + Te;
            T1i = T1c - T1b;
            TL = T1 - Te;
            T1d = T1b + T1c;
        }
        {
            E TF, TW, TI, TX;
            {
                E TD, TE, TG, TH;
                TD = Ip[(rs[3])];
                TE = Im[(rs[3])];
                TF = (((Tl) * (TD)) + (Tm * TE));
                TW = ((Tl * TE) - ((Tm) * (TD)));
                TG = Ip[(rs[1])];
                TH = Im[(rs[1])];
                TI = (((T3) * (TG)) + (T6 * TH));
                TX = ((T3 * TH) - ((T6) * (TG)));
            }
            TJ = TF + TI;
            T17 = TW + TX;
            TV = TF - TI;
            TY = TW - TX;
        }
        {
            E Tk, TM, Tr, TN;
            {
                E Th, Tj, To, Tq;
                Th = Rp[(rs[1])];
                Tj = Rm[(rs[1])];
                Tk = (((Tg) * (Th)) + (Ti * Tj));
                TM = ((Tg * Tj) - ((Ti) * (Th)));
                To = Rp[(rs[3])];
                Tq = Rm[(rs[3])];
                Tr = (((Tn) * (To)) + (Tp * Tq));
                TN = ((Tn * Tq) - ((Tp) * (To)));
            }
            Ts = Tk + Tr;
            T1j = Tk - Tr;
            TO = TM - TN;
            T1a = TM + TN;
        }
        {
            E Tw, TR, TB, TS;
            {
                E Tu, Tv, Ty, TA;
                Tu = Ip[0];
                Tv = Im[0];
                Tw = (((T2) * (Tu)) + (T5 * Tv));
                TR = ((T2 * Tv) - ((T5) * (Tu)));
                Ty = Ip[(rs[2])];
                TA = Im[(rs[2])];
                TB = (((Tx) * (Ty)) + (Tz * TA));
                TS = ((Tx * TA) - ((Tz) * (Ty)));
            }
            TC = Tw + TB;
            T16 = TR + TS;
            TQ = Tw - TB;
            TT = TR - TS;
        }
        {
            E Tt, TK, T1f, T1g;
            Tt = Tf + Ts;
            TK = TC + TJ;
            Rm[(rs[3])] = Tt - TK;
            Rp[0] = Tt + TK;
            {
                E T19, T1e, T15, T18;
                T19 = T16 + T17;
                T1e = T1a + T1d;
                Im[(rs[3])] = T19 - T1e;
                Ip[0] = T19 + T1e;
                T15 = Tf - Ts;
                T18 = T16 - T17;
                Rm[(rs[1])] = T15 - T18;
                Rp[(rs[2])] = T15 + T18;
            }
            T1f = TJ - TC;
            T1g = T1d - T1a;
            Im[(rs[1])] = T1f - T1g;
            Ip[(rs[2])] = T1f + T1g;
            {
                E T11, T1k, T14, T1h, T12, T13;
                T11 = TL - TO;
                T1k = T1i - T1j;
                T12 = TT - TQ;
                T13 = TV + TY;
                T14 = KP707106781 * (T12 - T13);
                T1h = KP707106781 * (T12 + T13);
                Rm[0] = T11 - T14;
                Ip[(rs[1])] = T1h + T1k;
                Rp[(rs[3])] = T11 + T14;
                Im[(rs[2])] = T1h - T1k;
            }
            {
                E TP, T1m, T10, T1l, TU, TZ;
                TP = TL + TO;
                T1m = T1j + T1i;
                TU = TQ + TT;
                TZ = TV - TY;
                T10 = KP707106781 * (TU + TZ);
                T1l = KP707106781 * (TZ - TU);
                Rm[(rs[2])] = TP - T10;
                Ip[(rs[3])] = T1l + T1m;
                Rp[(rs[1])] = TP + T10;
                Im[0] = T1l - T1m;
            }
        }
    }
}

}
