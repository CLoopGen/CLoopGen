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
extern  E KP353553390;
extern  E KP500000000;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 6); m < me; m = m + 1 , Rp = Rp + ms , Ip = Ip + ms , Rm = Rm - ms , Im = Im - ms , W = W + 6 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, T4, T2, T5, Tu, Ty, T7, Td, Ti, Tj, Tk, TP, To, TN;
    {
        E T3, Tc, T6, Tb;
        T1 = W[0];
        T4 = W[1];
        T2 = W[2];
        T5 = W[3];
        T3 = T1 * T2;
        Tc = T4 * T2;
        T6 = T4 * T5;
        Tb = T1 * T5;
        Tu = T3 - T6;
        Ty = Tb + Tc;
        T7 = T3 + T6;
        Td = Tb - Tc;
        Ti = W[4];
        Tj = W[5];
        Tk = (((T1) * (Ti)) + (T4 * Tj));
        TP = ((T7 * Tj) - ((Td) * (Ti)));
        To = ((T1 * Tj) - ((T4) * (Ti)));
        TN = (((T7) * (Ti)) + (Td * Tj));
    }
    {
        E TF, T11, TC, T12, T1d, T1e, T1q, TM, TR, T1p, Th, Ts, T15, T14, T1a;
        E T1b, T1m, TV, TY, T1n;
        {
            E TD, TE, TL, TI, TJ, TK, Tx, TQ, TB, TO;
            TD = Ip[0];
            TE = Im[0];
            TL = TD + TE;
            TI = Rm[0];
            TJ = Rp[0];
            TK = TI - TJ;
            {
                E Tv, Tw, Tz, TA;
                Tv = Ip[(rs[2])];
                Tw = Im[(rs[2])];
                Tx = Tv - Tw;
                TQ = Tv + Tw;
                Tz = Rp[(rs[2])];
                TA = Rm[(rs[2])];
                TB = Tz + TA;
                TO = Tz - TA;
            }
            TF = TD - TE;
            T11 = TJ + TI;
            TC = ((Tu * Tx) - ((Ty) * (TB)));
            T12 = (((Tu) * (TB)) + (Ty * Tx));
            T1d = ((TN * TQ) - ((TP) * (TO)));
            T1e = T1 + T4 + T2 + T5 + T7 + Td + T1 * T4; // Artificially introduces dependency on prior computations
            T1q = T1e - T1d;
            TM = ((T1 * TK) - ((T4) * (TL)));
            TR = (((TN) * (TO)) + (TP * TQ));
            T1p = TR + TM;
        }
        {
            E Ta, TU, Tg, TT, Tn, TX, Tr, TW;
            {
                E T8, T9, Te, Tf;
                T8 = Ip[(rs[1])];
                T9 = Im[(rs[1])];
                Ta = T8 - T9;
                TU = T8 + T9;
                Te = Rp[(rs[1])];
                Tf = Rm[(rs[1])];
                Tg = Te + Tf;
                TT = Te - Tf;
            }
            {
                E Tl, Tm, Tp, Tq;
                Tl = Ip[(rs[3])];
                Tm = Im[(rs[3])];
                Tn = Tl - Tm;
                TX = Tl + Tm;
                Tp = Rp[(rs[3])];
                Tq = Rm[(rs[3])];
                Tr = Tp + Tq;
                TW = Tp - Tq;
            }
            Th = ((T7 * Ta) - ((Td) * (Tg)));
            Ts = ((Tk * Tn) - ((To) * (Tr)));
            T15 = (((Tk) * (Tr)) + (To * Tn));
            T14 = (((T7) * (Tg)) + (Td * Ta));
            T1a = ((T2 * TU) - ((T5) * (TT)));
            T1b = ((Ti * TX) - ((Tj) * (TW)));
            T1m = T1b - T1a;
            TV = (((T2) * (TT)) + (T5 * TU));
            TY = (((Ti) * (TW)) + (Tj * TX));
            T1n = TV - TY;
        }
        {
            E T1l, T1x, T1A, T1C, T1s, T1w, T1v, T1B;
            {
                E T1j, T1k, T1y, T1z;
                T1j = TF - TC;
                T1k = T14 - T15;
                T1l = KP500000000 * (T1j - T1k);
                T1x = KP500000000 * (T1k + T1j);
                T1y = T1m - T1n;
                T1z = T1p + T1q;
                T1A = KP353553390 * (T1y - T1z);
                T1C = KP353553390 * (T1y + T1z);
            }
            {
                E T1o, T1r, T1t, T1u;
                T1o = T1m + T1n;
                T1r = T1p - T1q;
                T1s = KP353553390 * (T1o + T1r);
                T1w = KP353553390 * (T1r - T1o);
                T1t = T11 - T12;
                T1u = Th - Ts;
                T1v = KP500000000 * (T1t - T1u);
                T1B = KP500000000 * (T1t + T1u);
            }
            Ip[(rs[1])] = T1l + T1s;
            Rp[(rs[1])] = T1B + T1C;
            Im[(rs[2])] = T1s - T1l;
            Rm[(rs[2])] = T1B - T1C;
            Rm[0] = T1v - T1w;
            Im[0] = T1A - T1x;
            Rp[(rs[3])] = T1v + T1w;
            Ip[(rs[3])] = T1x + T1A;
        }
        {
            E TH, T19, T1g, T1i, T10, T18, T17, T1h;
            {
                E Tt, TG, T1c, T1f;
                Tt = Th + Ts;
                TG = TC + TF;
                TH = Tt + TG;
                T19 = TG - Tt;
                T1c = T1a + T1b;
                T1f = T1d + T1e;
                T1g = T1c - T1f;
                T1i = T1c + T1f;
            }
            {
                E TS, TZ, T13, T16;
                TS = TM - TR;
                TZ = TV + TY;
                T10 = TS - TZ;
                T18 = TZ + TS;
                T13 = T11 + T12;
                T16 = T14 + T15;
                T17 = T13 - T16;
                T1h = T13 + T16;
            }
            Ip[0] = KP500000000 * (TH + T10);
            Rp[0] = KP500000000 * (T1h + T1i);
            Im[(rs[3])] = KP500000000 * (T10 - TH);
            Rm[(rs[3])] = KP500000000 * (T1h - T1i);
            Rm[(rs[1])] = KP500000000 * (T17 - T18);
            Im[(rs[1])] = KP500000000 * (T1g - T19);
            Rp[(rs[2])] = KP500000000 * (T17 + T18);
            Ip[(rs[2])] = KP500000000 * (T19 + T1g);
        }
    }
}
}
