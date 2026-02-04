#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *ri;
extern R *ii;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP587785252;
extern  E KP951056516;
extern  E KP250000000;
extern  E KP559016994;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (m = mb , W = W + (mb * 18); m < me; m = m + 1 , ri = ri + ms , ii = ii + ms , W = W + 18 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T7, T1O, TT, T1C, TF, TQ, TR, T1o, T1p, T1y, TX, TY, TZ, T1d, T1g;
    E T1M, Ti, Tt, Tu, T1r, T1s, T1x, TU, TV, TW, T16, T19, T1L;
    {
        E T1, T1B, T6, T1A;
        T1 = ri[0];
        T1B = ii[0];
        {
            E T3, T5, T2, T4;
            T3 = ri[(rs[5])];
            T5 = ii[(rs[5])];
            T2 = W[8];
            T4 = W[9];
            T6 = (((T2) * (T3)) + (T4 * T5));
            T1A = ((T2 * T5) - ((T4) * (T3)));
        }
        T7 = T1 - T6;
        T1O = T1B - T1A;
        TT = T1 + T6;
        T1C = T1A + T1B;
    }
    {
        E Tz, T1b, TP, T1f, TE, T1c, TK, T1e;
        {
            E Tw, Ty, Tv, Tx;
            Tw = ri[(rs[4])];
            Ty = ii[(rs[4])];
            Tv = W[6];
            Tx = W[7];
            Tz = (((Tv) * (Tw)) + (Tx * Ty));
            T1b = ((Tv * Ty) - ((Tx) * (Tw)));
        }
        {
            E TM, TO, TL, TN;
            TM = ri[(rs[1])];
            TO = ii[(rs[1])];
            TL = W[0];
            TN = W[1];
            TP = (((TL) * (TM)) + (TN * TO));
            T1f = ((TL * TO) - ((TN) * (TM)));
        }
        {
            E TB, TD, TA, TC;
            TB = ri[(rs[9])];
            TD = ii[(rs[9])];
            TA = W[16];
            TC = W[17];
            TE = (((TA) * (TB)) + (TC * TD));
            T1c = ((TA * TD) - ((TC) * (TB)));
        }
        {
            E TH, TJ, TG, TI;
            TH = ri[(rs[6])];
            TJ = ii[(rs[6])];
            TG = W[10];
            TI = W[11];
            TK = (((TG) * (TH)) + (TI * TJ));
            T1e = ((TG * TJ) - ((TI) * (TH)));
        }
        TF = Tz - TE;
        TQ = TK - TP;
        TR = TF + TQ;
        T1o = T1b + T1c;
        T1p = T1e + T1f;
        T1y = T1o + T1p;
        TX = Tz + TE;
        TY = TK + TP;
        TZ = TX + TY;
        T1d = T1b - T1c;
        T1g = T1e - T1f;
        T1M = T1d + T1g;
    }
    {
        E Tc, T14, Ts, T18, Th, T15, Tn, T17;
        {
            E T9, Tb, T8, Ta;
            T9 = ri[(rs[2])];
            Tb = ii[(rs[2])];
            T8 = W[2];
            Ta = W[3];
            Tc = (((T8) * (T9)) + (Ta * Tb));
            T14 = ((T8 * Tb) - ((Ta) * (T9)));
        }
        {
            E Tp, Tr, To, Tq;
            Tp = ri[(rs[3])];
            Tr = ii[(rs[3])];
            To = W[4];
            Tq = W[5];
            Ts = (((To) * (Tp)) + (Tq * Tr));
            T18 = ((To * Tr) - ((Tq) * (Tp)));
        }
        {
            E Te, Tg, Td, Tf;
            Te = ri[(rs[7])];
            Tg = ii[(rs[7])];
            Td = W[12];
            Tf = W[13];
            Th = (((Td) * (Te)) + (Tf * Tg));
            T15 = ((Td * Tg) - ((Tf) * (Te)));
        }
        {
            E Tk, Tm, Tj, Tl;
            Tk = ri[(rs[8])];
            Tm = ii[(rs[8])];
            Tj = W[14];
            Tl = W[15];
            Tn = (((Tj) * (Tk)) + (Tl * Tm));
            T17 = ((Tj * Tm) - ((Tl) * (Tk)));
        }
        Ti = Tc - Th;
        Tt = Tn - Ts;
        Tu = Ti + Tt;
        T1r = T14 + T15;
        T1s = T17 + T18;
        T1x = T1r + T1s;
        TU = Tc + Th;
        TV = Tn + Ts;
        TW = TU + TV;
        T16 = T14 - T15;
        T19 = T17 - T18;
        T1L = T16 + T19;
    }
    {
        E T11, TS, T12, T1i, T1k, T1a, T1h, T1j, T13;
        T11 = KP559016994 * (Tu - TR);
        TS = Tu + TR;
        T12 = ((T7) - ((KP250000000) * (TS)));
        T1a = T16 - T19;
        T1h = T1d - T1g;
        T1i = (((KP951056516) * (T1a)) + (KP587785252 * T1h));
        T1k = ((KP951056516 * T1h) - ((KP587785252) * (T1a)));
        ri[(rs[5])] = T7 + TS;
        T1j = T12 - T11;
        ri[(rs[7])] = T1j - T1k;
        ri[(rs[3])] = T1j + T1k;
        T13 = T11 + T12;
        ri[(rs[9])] = T13 - T1i;
        ri[(rs[1])] = T13 + T1i;
    }
    {
        E T1N, T1P, T1Q, T1U, T1W, T1S, T1T, T1V, T1R;
        T1N = KP559016994 * (T1L - T1M);
        T1P = T1L + T1M;
        T1Q = ((T1O) - ((KP250000000) * (T1P)));
        T1S = Ti - Tt;
        T1T = TF - TQ;
        T1U = (((KP951056516) * (T1S)) + (KP587785252 * T1T));
        T1W = ((KP951056516 * T1T) - ((KP587785252) * (T1S)));
        ii[(rs[5])] = T1P + T1O;
        T1V = T1Q - T1N;
        ii[(rs[3])] = T1V - T1W;
        ii[(rs[7])] = T1W + T1V;
        T1R = T1N + T1Q;
        ii[(rs[1])] = T1R - T1U;
        ii[(rs[9])] = T1U + T1R;
    }
    {
        E T1m, T10, T1l, T1u, T1w, T1q, T1t, T1v, T1n;
        T1m = KP559016994 * (TW - TZ);
        T10 = TW + TZ;
        T1l = ((TT) - ((KP250000000) * (T10)));
        T1q = T1o - T1p;
        T1t = T1r - T1s;
        T1u = ((KP951056516 * T1q) - ((KP587785252) * (T1t)));
        T1w = (((KP951056516) * (T1t)) + (KP587785252 * T1q));
        ri[0] = TT + T10;
        T1v = T1m + T1l;
        ri[(rs[4])] = T1v - T1w;
        ri[(rs[6])] = T1v + T1w;
        T1n = T1l - T1m;
        ri[(rs[2])] = T1n - T1u;
        ri[(rs[8])] = T1n + T1u;
    }
    {
        E T1H, T1z, T1G, T1F, T1J, T1D, T1E, T1K, T1I;
        T1H = KP559016994 * (T1x - T1y);
        T1z = T1x + T1y;
        T1G = ((T1C) - ((KP250000000) * (T1z)));
        T1D = TX - TY;
        T1E = TU - TV;
        T1F = ((KP951056516 * T1D) - ((KP587785252) * (T1E)));
        T1J = (((KP951056516) * (T1E)) + (KP587785252 * T1D));
        ii[0] = T1z + T1C;
        T1K = T1H + T1G;
        ii[(rs[4])] = T1J + T1K;
        ii[(rs[6])] = T1K - T1J;
        T1I = T1G - T1H;
        ii[(rs[2])] = T1F + T1I;
        ii[(rs[8])] = T1I - T1F;
    }
}

}
