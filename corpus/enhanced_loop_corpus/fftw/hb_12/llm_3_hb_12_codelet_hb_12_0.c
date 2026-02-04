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
extern  E KP500000000;
extern  E KP866025403;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 22); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 22 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T5, TH, T12, T1M, T1i, T1U, Tg, Tt, T19, T1X, T1p, T1P, Ta, TM, T15;
    E T1N, T1l, T1V, Tl, Ty, T1c, T1Y, T1s, T1Q;
    // Change memory access to use indirect indexing via precomputed offset arrays
    // Simulate gather/scatter behavior using indexed lookups

    INT idx_cr[12], idx_ci[12], idx_W[22];
    for (INT i = 0; i < 12; ++i) {
        idx_cr[i] = (rs[i]);
        idx_ci[i] = (rs[i]);
    }
    for (INT i = 0; i < 22; ++i) {
        idx_W[i] = i;
    }

    // Use indirect access through index tables
    #define CR(i) cr[idx_cr[(i)]]
    #define CI(i) ci[idx_ci[(i)]]
    #define WR(i) W[idx_W[(i)]]

    {
        E T1, TD, T4, T1g, TG, T11, T10, T1h;
        T1 = CR(0);
        TD = CI(11);
        {
            E T2, T3, TE, TF;
            T2 = CR(4);
            T3 = CI(3);
            T4 = T2 + T3;
            T1g = KP866025403 * (T2 - T3);
            TE = CI(7);
            TF = CR(8);
            TG = TE - TF;
            T11 = KP866025403 * (TE + TF);
        }
        T5 = T1 + T4;
        TH = TD + TG;
        T10 = T1 - KP500000000 * T4;
        T12 = T10 - T11;
        T1M = T10 + T11;
        T1h = TD - KP500000000 * TG;
        T1i = T1g + T1h;
        T1U = T1h - T1g;
    }
    {
        E Tc, Tp, Tf, T17, Ts, T1o, T18, T1n;
        Tc = CR(3);
        Tp = CI(8);
        {
            E Td, Te, Tq, Tr;
            Td = CI(4);
            Te = CI(0);
            Tf = Td + Te;
            T17 = KP866025403 * (Td - Te);
            Tq = CR(7);
            Tr = CR(11);
            Ts = Tq + Tr;
            T1o = KP866025403 * (Tq - Tr);
        }
        Tg = Tc + Tf;
        Tt = Tp - Ts;
        T18 = KP500000000 * Ts + Tp;
        T19 = T17 + T18;
        T1X = T18 - T17;
        T1n = Tc - KP500000000 * Tf;
        T1p = T1n + T1o;
        T1P = T1n - T1o;
    }
    {
        E T6, TL, T9, T1j, TK, T14, T13, T1k;
        T6 = CI(5);
        TL = CR(6);
        {
            E T7, T8, TI, TJ;
            T7 = CI(1);
            T8 = CR(2);
            T9 = T7 + T8;
            T1j = KP866025403 * (T7 - T8);
            TI = CI(9);
            TJ = CR(10);
            TK = TI - TJ;
            T14 = KP866025403 * (TI + TJ);
        }
        Ta = T6 + T9;
        TM = TK - TL;
        T13 = T6 - KP500000000 * T9;
        T15 = T13 + T14;
        T1N = T13 - T14;
        T1k = KP500000000 * TK + TL;
        T1l = T1j - T1k;
        T1V = T1j + T1k;
    }
    {
        E Th, Tx, Tk, T1a, Tw, T1r, T1b, T1q;
        Th = CI(2);
        Tx = CR(9);
        {
            E Ti, Tj, Tu, Tv;
            Ti = CR(1);
            Tj = CR(5);
            Tk = Ti + Tj;
            T1a = KP866025403 * (Ti - Tj);
            Tu = CI(10);
            Tv = CI(6);
            Tw = Tu + Tv;
            T1r = KP866025403 * (Tv - Tu);
        }
        Tl = Th + Tk;
        Ty = Tw - Tx;
        T1b = KP500000000 * Tw + Tx;
        T1c = T1a - T1b;
        T1Y = T1a + T1b;
        T1q = Th - KP500000000 * Tk;
        T1s = T1q + T1r;
        T1Q = T1q - T1r;
    }
    {
        E Tb, Tm, TU, TW, TX, TY, TT, TV;
        Tb = T5 + Ta;
        Tm = Tg + Tl;
        TU = Tb - Tm;
        TW = TH + TM;
        TX = Tt + Ty;
        TY = TW - TX;
        CR(0) = Tb + Tm;
        CI(0) = TW + TX;
        TT = WR(10);
        TV = WR(11);
        CR(6) = TT * TU - TV * TY;
        CI(6) = TV * TU + TT * TY;
    }
    {
        E TA, TQ, TO, TS;
        {
            E To, Tz, TC, TN;
            To = T5 - Ta;
            Tz = Tt - Ty;
            TA = To - Tz;
            TQ = To + Tz;
            TC = Tg - Tl;
            TN = TH - TM;
            TO = TC + TN;
            TS = TN - TC;
        }
        {
            E Tn, TB, TP, TR;
            Tn = WR(16);
            TB = WR(17);
            CR(9) = Tn * TA - TB * TO;
            CI(9) = Tn * TO + TB * TA;
            TP = WR(4);
            TR = WR(5);
            CR(3) = TP * TQ - TR * TS;
            CI(3) = TP * TS + TR * TQ;
        }
    }
    {
        E T28, T2e, T2c, T2g;
        {
            E T26, T27, T2a, T2b;
            T26 = T1M - T1N;
            T27 = T1X + T1Y;
            T28 = T26 - T27;
            T2e = T26 + T27;
            T2a = T1U + T1V;
            T2b = T1P - T1Q;
            T2c = T2a + T2b;
            T2g = T2a - T2b;
        }
        {
            E T25, T29, T2d, T2f;
            T25 = WR(8);
            T29 = WR(9);
            CR(5) = T25 * T28 - T29 * T2c;
            CI(5) = T25 * T2c + T29 * T28;
            T2d = WR(20);
            T2f = WR(21);
            CR(11) = T2d * T2e - T2f * T2g;
            CI(11) = T2d * T2g + T2f * T2e;
        }
    }
    {
        E T1S, T22, T20, T24;
        {
            E T1O, T1R, T1W, T1Z;
            T1O = T1M + T1N;
            T1R = T1P + T1Q;
            T1S = T1O - T1R;
            T22 = T1O + T1R;
            T1W = T1U - T1V;
            T1Z = T1X - T1Y;
            T20 = T1W - T1Z;
            T24 = T1W + T1Z;
        }
        {
            E T1L, T1T, T21, T23;
            T1L = WR(2);
            T1T = WR(3);
            CR(2) = T1L * T1S - T1T * T20;
            CI(2) = T1T * T1S + T1L * T20;
            T21 = WR(14);
            T23 = WR(15);
            CR(8) = T21 * T22 - T23 * T24;
            CI(8) = T23 * T22 + T21 * T24;
        }
    }
    {
        E T1C, T1I, T1G, T1K;
        {
            E T1A, T1B, T1E, T1F;
            T1A = T12 + T15;
            T1B = T1p + T1s;
            T1C = T1A - T1B;
            T1I = T1A + T1B;
            T1E = T1i + T1l;
            T1F = T19 + T1c;
            T1G = T1E - T1F;
            T1K = T1E + T1F;
        }
        {
            E T1z, T1D, T1H, T1J;
            T1z = WR(18);
            T1D = WR(19);
            CR(10) = T1z * T1C - T1D * T1G;
            CI(10) = T1D * T1C + T1z * T1G;
            T1H = WR(6);
            T1J = WR(7);
            CR(4) = T1H * T1I - T1J * T1K;
            CI(4) = T1J * T1I + T1H * T1K;
        }
    }
    {
        E T1e, T1w, T1u, T1y;
        {
            E T16, T1d, T1m, T1t;
            T16 = T12 - T15;
            T1d = T19 - T1c;
            T1e = T16 - T1d;
            T1w = T16 + T1d;
            T1m = T1i - T1l;
            T1t = T1p - T1s;
            T1u = T1m + T1t;
            T1y = T1m - T1t;
        }
        {
            E TZ, T1f, T1v, T1x;
            TZ = WR(0);
            T1f = WR(1);
            CR(1) = TZ * T1e - T1f * T1u;
            CI(1) = TZ * T1u + T1f * T1e;
            T1v = WR(12);
            T1x = WR(13);
            CR(7) = T1v * T1w - T1x * T1y;
            CI(7) = T1v * T1y + T1x * T1w;
        }
    }

    #undef CR
    #undef CI
    #undef WR
}
}
