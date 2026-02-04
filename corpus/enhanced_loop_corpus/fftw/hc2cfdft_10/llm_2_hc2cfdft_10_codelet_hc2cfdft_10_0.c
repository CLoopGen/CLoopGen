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
extern  E KP293892626;
extern  E KP475528258;
extern  E KP125000000;
extern  E KP500000000;
extern  E KP279508497;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 18); m < me; m = m + 1 , Rp = Rp + ms , Ip = Ip + ms , Rm = Rm - ms , Im = Im - ms , W = W + 18 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E Tw, TL, TM, T1W, T1X, T27, T1Z, T20, T26, TX, T1a, T1b, T1d, T1e, T1f;
    E T1q, T1t, T1u, T1x, T1A, T1B, T1g, T1h, T1i, Td, T25, T1k, T1F;
    INT idx[5];
    idx[0] = 0;
    idx[1] = rs[1];
    idx[2] = rs[2];
    idx[3] = rs[3];
    idx[4] = rs[4];

    {
        E T3, T1D, T19, T1z, T7, Tb, TR, T1v, Tm, T1o, TK, T1s, Tv, T1p, T12;
        E T1y, TF, T1r, TW, T1w;
        {
            E T1, T2, T18, T14, T15, T16, T13, T17;
            T1 = Ip[idx[0]];
            T2 = Im[idx[0]];
            T18 = T1 + T2;
            T14 = Rm[idx[0]];
            T15 = Rp[idx[0]];
            T16 = T14 - T15;
            T3 = T1 - T2;
            T1D = T15 + T14;
            T13 = W[0];
            T17 = W[1];
            T19 = ((T13 * T16) - ((T17) * (T18)));
            T1z = (((T17) * (T16)) + (T13 * T18));
        }
        {
            E T5, T6, TO, T9, Ta, TQ, TN, TP;
            T5 = Ip[idx[2]];
            T6 = Im[idx[2]];
            TO = T5 - T6;
            T9 = Rp[idx[2]];
            Ta = Rm[idx[2]];
            TQ = T9 + Ta;
            T7 = T5 + T6;
            Tb = T9 - Ta;
            TN = W[6];
            TP = W[7];
            TR = ((TN * TO) - ((TP) * (TQ)));
            T1v = (((TP) * (TO)) + (TN * TQ));
        }
        {
            E Th, TJ, Tl, TH;
            {
                E Tf, Tg, Tj, Tk;
                Tf = Ip[idx[1]];
                Tg = Im[idx[1]];
                Th = Tf - Tg;
                TJ = Tf + Tg;
                Tj = Rp[idx[1]];
                Tk = Rm[idx[1]];
                Tl = Tj + Tk;
                TH = Tj - Tk;
            }
            {
                E Te, Ti, TG, TI;
                Te = W[2];
                Ti = W[3];
                Tm = ((Te * Th) - ((Ti) * (Tl)));
                T1o = (((Te) * (Tl)) + (Ti * Th));
                TG = W[4];
                TI = W[5];
                TK = (((TG) * (TH)) + (TI * TJ));
                T1s = ((TG * TJ) - ((TI) * (TH)));
            }
        }
        {
            E Tq, TZ, Tu, T11;
            {
                E To, Tp, Ts, Tt;
                To = Ip[idx[3]];
                Tp = Im[idx[3]];
                Tq = To + Tp;
                TZ = To - Tp;
                Ts = Rp[idx[3]];
                Tt = Rm[idx[3]];
                Tu = Ts - Tt;
                T11 = Ts + Tt;
            }
            {
                E Tn, Tr, TY, T10;
                Tn = W[13];
                Tr = W[12];
                Tv = (((Tn) * (Tq)) + (Tr * Tu));
                T1p = ((Tr * Tq) - ((Tn) * (Tu)));
                TY = W[10];
                T10 = W[11];
                T12 = ((TY * TZ) - ((T10) * (T11)));
                T1y = (((T10) * (TZ)) + (TY * T11));
            }
        }
        {
            E TA, TV, TE, TT;
            {
                E Ty, Tz, TC, TD;
                Ty = Ip[idx[4]];
                Tz = Im[idx[4]];
                TA = Ty - Tz;
                TV = Ty + Tz;
                TC = Rp[idx[4]];
                TD = Rm[idx[4]];
                TE = TC + TD;
                TT = TC - TD;
            }
            {
                E Tx, TB, TS, TU;
                Tx = W[14];
                TB = W[15];
                TF = ((Tx * TA) - ((TB) * (TE)));
                T1r = (((Tx) * (TE)) + (TB * TA));
                TS = W[16];
                TU = W[17];
                TW = (((TS) * (TT)) + (TU * TV));
                T1w = ((TS * TV) - ((TU) * (TT)));
            }
        }
        Tw = Tm - Tv;
        TL = TF - TK;
        TM = Tw + TL;
        T1W = T1v + T1w;
        T1X = T1y + T1z;
        T27 = T1W + T1X;
        T1Z = T1o + T1p;
        T20 = T1s + T1r;
        T26 = T1Z + T20;
        TX = TR - TW;
        T1a = T12 + T19;
        T1b = TX + T1a;
        T1d = T19 - T12;
        T1e = TR + TW;
        T1f = T1d - T1e;
        T1q = T1o - T1p;
        T1t = T1r - T1s;
        T1u = T1q + T1t;
        T1x = T1v - T1w;
        T1A = T1y - T1z;
        T1B = T1x + T1A;
        T1g = Tm + Tv;
        T1h = TK + TF;
        T1i = T1g + T1h;
        {
            E Tc, T1E, T4, T8;
            T4 = W[9];
            T8 = W[8];
            Tc = (((T4) * (T7)) + (T8 * Tb));
            T1E = ((T8 * T7) - ((T4) * (Tb)));
            Td = T3 - Tc;
            T25 = T1D + T1E;
            T1k = Tc + T3;
            T1F = T1D - T1E;
        }
    }
    {
        E T1U, T1c, T1T, T22, T24, T1Y, T21, T23, T1V;
        T1U = KP279508497 * (TM - T1b);
        T1c = TM + T1b;
        T1T = ((KP500000000 * Td) - ((KP125000000) * (T1c)));
        T1Y = T1W - T1X;
        T21 = T1Z - T20;
        T22 = ((KP475528258 * T1Y) - ((KP293892626) * (T21)));
        T24 = (((KP475528258) * (T21)) + (KP293892626 * T1Y));
        Ip[idx[0]] = KP500000000 * (Td + T1c);
        T23 = T1U + T1T;
        Ip[idx[4]] = T23 + T24;
        Im[idx[3]] = T24 - T23;
        T1V = T1T - T1U;
        Ip[idx[2]] = T1V + T22;
        Im[idx[1]] = T22 - T1V;
    }
    {
        E T2a, T28, T29, T2e, T2g, T2c, T2d, T2f, T2b;
        T2a = KP279508497 * (T26 - T27);
        T28 = T26 + T27;
        T29 = ((KP500000000 * T25) - ((KP125000000) * (T28)));
        T2c = TX - T1a;
        T2d = Tw - TL;
        T2e = ((KP475528258 * T2c) - ((KP293892626) * (T2d)));
        T2g = (((KP475528258) * (T2d)) + (KP293892626 * T2c));
        Rp[idx[0]] = KP500000000 * (T25 + T28);
        T2f = T2a + T29;
        Rp[idx[4]] = T2f - T2g;
        Rm[idx[3]] = T2g + T2f;
        T2b = T29 - T2a;
        Rp[idx[2]] = T2b - T2e;
        Rm[idx[1]] = T2e + T2b;
    }
    {
        E T1M, T1j, T1L, T1Q, T1S, T1O, T1P, T1R, T1N;
        T1M = KP279508497 * (T1i + T1f);
        T1j = T1f - T1i;
        T1L = (((KP500000000) * (T1k)) + (KP125000000 * T1j));
        T1O = T1A - T1x;
        T1P = T1q - T1t;
        T1Q = ((KP293892626 * T1O) - ((KP475528258) * (T1P)));
        T1S = (((KP293892626) * (T1P)) + (KP475528258 * T1O));
        Im[idx[4]] = KP500000000 * (T1j - T1k);
        T1R = T1L - T1M;
        Ip[idx[3]] = T1R + T1S;
        Im[idx[2]] = T1S - T1R;
        T1N = T1L + T1M;
        Ip[idx[1]] = T1N + T1Q;
        Im[idx[0]] = T1Q - T1N;
    }
    {
        E T1C, T1G, T1H, T1n, T1J, T1l, T1m, T1K, T1I;
        T1C = KP279508497 * (T1u - T1B);
        T1G = T1u + T1B;
        T1H = ((KP500000000 * T1F) - ((KP125000000) * (T1G)));
        T1l = T1g - T1h;
        T1m = T1e + T1d;
        T1n = (((KP475528258) * (T1l)) + (KP293892626 * T1m));
        T1J = ((KP475528258 * T1m) - ((KP293892626) * (T1l)));
        Rm[idx[4]] = KP500000000 * (T1F + T1G);
        T1K = T1H - T1C;
        Rp[idx[3]] = T1J + T1K;
        Rm[idx[2]] = T1K - T1J;
        T1I = T1C + T1H;
        Rp[idx[1]] = T1n + T1I;
        Rm[idx[0]] = T1I - T1n;
    }
}
}
