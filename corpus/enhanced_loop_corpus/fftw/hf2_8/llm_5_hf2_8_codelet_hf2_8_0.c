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

    if (!(m & 1)) {
        E Tf, T1j, TL, T1d, TJ, T16, TV, TY, Ts, T1i, TO, T1a, TC, T17, TQ;
        E TT;
        {
            E T1, T1c, Te, T1b, T9, Td;
            T1 = cr[0];
            T1c = ci[0];
            T9 = cr[(rs[4])];
            Td = ci[(rs[4])];
            Te = (((T8) * (T9)) + (Tc * Td));
            T1b = ((T8 * Td) - ((Tc) * (T9)));
            Tf = T1 + Te;
            T1j = T1c - T1b;
            TL = T1 - Te;
            T1d = T1b + T1c;
        }
        {
            E TF, TW, TI, TX;
            {
                E TD, TE, TG, TH;
                TD = cr[(rs[7])];
                TE = ci[(rs[7])];
                TF = (((Tl) * (TD)) + (Tm * TE));
                TW = ((Tl * TE) - ((Tm) * (TD)));
                TG = cr[(rs[3])];
                TH = ci[(rs[3])];
                TI = (((T3) * (TG)) + (T6 * TH));
                TX = ((T3 * TH) - ((T6) * (TG)));
            }
            TJ = TF + TI;
            T16 = TW + TX;
            TV = TF - TI;
            TY = TW - TX;
        }
        {
            E Tk, TM, Tr, TN;
            {
                E Th, Tj, To, Tq;
                Th = cr[(rs[2])];
                Tj = ci[(rs[2])];
                Tk = (((Tg) * (Th)) + (Ti * Tj));
                TM = ((Tg * Tj) - ((Ti) * (Th)));
                To = cr[(rs[6])];
                Tq = ci[(rs[6])];
                Tr = (((Tn) * (To)) + (Tp * Tq));
                TN = ((Tn * Tq) - ((Tp) * (To)));
            }
            Ts = Tk + Tr;
            T1i = Tk - Tr;
            TO = TM - TN;
            T1a = TM + TN;
        }
        {
            E Tw, TR, TB, TS;
            {
                E Tu, Tv, Ty, TA;
                Tu = cr[(rs[1])];
                Tv = ci[(rs[1])];
                Tw = (((T2) * (Tu)) + (T5 * Tv));
                TR = ((T2 * Tv) - ((T5) * (Tu)));
                Ty = cr[(rs[5])];
                TA = ci[(rs[5])];
                TB = (((Tx) * (Ty)) + (Tz * TA));
                TS = ((Tx * TA) - ((Tz) * (Ty)));
            }
            TC = Tw + TB;
            T17 = TR + TS;
            TQ = Tw - TB;
            TT = TR - TS;
        }
        {
            E Tt, TK, T1f, T1g;
            Tt = Tf + Ts;
            TK = TC + TJ;
            ci[(rs[3])] = Tt - TK;
            cr[0] = Tt + TK;
            T1f = TJ - TC;
            T1g = T1d - T1a;
            cr[(rs[6])] = T1f - T1g;
            ci[(rs[5])] = T1f + T1g;
            {
                E T11, T1m, T14, T1l, T12, T13;
                T11 = TL - TO;
                T1m = T1j - T1i;
                T12 = TQ - TT;
                T13 = TV + TY;
                T14 = KP707106781 * (T12 + T13);
                T1l = KP707106781 * (T13 - T12);
                cr[(rs[3])] = T11 - T14;
                ci[(rs[6])] = T1l + T1m;
                ci[0] = T11 + T14;
                cr[(rs[5])] = T1l - T1m;
            }
        }
        {
            E T19, T1e, T15, T18;
            T19 = T17 + T16;
            T1e = T1a + T1d;
            cr[(rs[4])] = T19 - T1e;
            ci[(rs[7])] = T19 + T1e;
            T15 = Tf - Ts;
            T18 = T16 - T17;
            cr[(rs[2])] = T15 - T18;
            ci[(rs[1])] = T15 + T18;
            {
                E TP, T1k, T10, T1h, TU, TZ;
                TP = TL + TO;
                T1k = T1i + T1j;
                TU = TQ + TT;
                TZ = TV - TY;
                T10 = KP707106781 * (TU + TZ);
                T1h = KP707106781 * (TZ - TU);
                ci[(rs[2])] = TP - T10;
                ci[(rs[4])] = T1h + T1k;
                cr[(rs[1])] = TP + T10;
                cr[(rs[7])] = T1h - T1k;
            }
        }
    } else {
        cr[0] = T2 * KP707106781;
        ci[0] = T5 * KP707106781;
        cr[(rs[1])] = T3 * KP707106781;
        ci[(rs[1])] = T6 * KP707106781;
        cr[(rs[2])] = Tg * KP707106781;
        ci[(rs[2])] = Ti * KP707106781;
        cr[(rs[3])] = Tl * KP707106781;
        ci[(rs[3])] = Tm * KP707106781;
    }
}
}
