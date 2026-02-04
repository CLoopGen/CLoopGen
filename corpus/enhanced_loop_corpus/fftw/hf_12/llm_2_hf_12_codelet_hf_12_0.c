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
    E T1, T1W, T18, T23, Tc, T15, T1V, T22, TR, T1E, T1o, T1D, T12, T1l, T1F;
    E T1G, Ti, T1S, T1d, T26, Tt, T1a, T1T, T25, TA, T1y, T1j, T1B, TL, T1g;
    E T1z, T1A;
    const INT * restrict rsi = rs; // Use restricted pointer for stride indices
    const R * restrict Wr = W;     // Local const pointer to W for clarity
    R * restrict cri = cr;         // Restricted pointer for consecutive access simulation
    R * restrict cii = ci;

    // Convert strided accesses into indirect indexed accesses via precomputed offsets
    INT idx4 = rsi[4], idx8 = rsi[8], idx9 = rsi[9], idx5 = rsi[5], idx1 = rsi[1];
    INT idx6 = rsi[6], idx2 = rsi[2], idx10 = rsi[10], idx3 = rsi[3], idx11 = rsi[11], idx7 = rsi[7];

    {
        E T6, T16, Tb, T17;
        T1 = cri[0];
        T1W = cii[0];
        {
            E T3 = cri[idx4], T5 = cii[idx4];
            E T2 = Wr[6], T4 = Wr[7];
            T6 = T2 * T3 + T4 * T5;
            T16 = T2 * T5 - T4 * T3;
        }
        {
            E T8 = cri[idx8], Ta = cii[idx8];
            E T7 = Wr[14], T9 = Wr[15];
            Tb = T7 * T8 + T9 * Ta;
            T17 = T7 * Ta - T9 * T8;
        }
        T18 = KP866025403 * (T16 - T17);
        T23 = KP866025403 * (Tb - T6);
        Tc = T6 + Tb;
        T15 = T1 - KP500000000 * Tc;
        T1V = T16 + T17;
        T22 = T1W - KP500000000 * T1V;
    }
    {
        E T11, T1n, TW, T1m;
        {
            E TO = cri[idx9], TQ = cii[idx9];
            E TN = Wr[16], TP = Wr[17];
            TR = TN * TO + TP * TQ;
            T1E = TN * TQ - TP * TO;
        }
        {
            E TY = cri[idx5], T10 = cii[idx5];
            E TX = Wr[8], TZ = Wr[9];
            T11 = TX * TY + TZ * T10;
            T1n = TX * T10 - TZ * TY;
        }
        {
            E TT = cri[idx1], TV = cii[idx1];
            E TS = Wr[0], TU = Wr[1];
            TW = TS * TT + TU * TV;
            T1m = TS * TV - TU * TT;
        }
        T1o = KP866025403 * (T1m - T1n);
        T1D = KP866025403 * (T11 - TW);
        T12 = TW + T11;
        T1l = TR - KP500000000 * T12;
        T1F = T1m + T1n;
        T1G = T1E - KP500000000 * T1F;
    }
    {
        E Ts, T1c, Tn, T1b;
        {
            E Tf = cri[idx6], Th = cii[idx6];
            E Te = Wr[10], Tg = Wr[11];
            Ti = Te * Tf + Tg * Th;
            T1S = Te * Th - Tg * Tf;
        }
        {
            E Tp = cri[idx2], Tr = cii[idx2];
            E To = Wr[2], Tq = Wr[3];
            Ts = To * Tp + Tq * Tr;
            T1c = To * Tr - Tq * Tp;
        }
        {
            E Tk = cri[idx10], Tm = cii[idx10];
            E Tj = Wr[18], Tl = Wr[19];
            Tn = Tj * Tk + Tl * Tm;
            T1b = Tj * Tm - Tl * Tk;
        }
        T1d = KP866025403 * (T1b - T1c);
        T26 = KP866025403 * (Ts - Tn);
        Tt = Tn + Ts;
        T1a = Ti - KP500000000 * Tt;
        T1T = T1b + T1c;
        T25 = T1S - KP500000000 * T1T;
    }
    {
        E TK, T1i, TF, T1h;
        {
            E Tx = cri[idx3], Tz = cii[idx3];
            E Tw = Wr[4], Ty = Wr[5];
            TA = Tw * Tx + Ty * Tz;
            T1y = Tw * Tz - Ty * Tx;
        }
        {
            E TH = cri[idx11], TJ = cii[idx11];
            E TG = Wr[20], TI = Wr[21];
            TK = TG * TH + TI * TJ;
            T1i = TG * TJ - TI * TH;
        }
        {
            E TC = cri[idx7], TE = cii[idx7];
            E TB = Wr[12], TD = Wr[13];
            TF = TB * TC + TD * TE;
            T1h = TB * TE - TD * TC;
        }
        T1j = KP866025403 * (T1h - T1i);
        T1B = KP866025403 * (TK - TF);
        TL = TF + TK;
        T1g = TA - KP500000000 * TL;
        T1z = T1h + T1i;
        T1A = T1y - KP500000000 * T1z;
    }
    {
        E Tv, T1N, T1Y, T20, T14, T1Z, T1Q, T1R;
        {
            E Td = T1 + Tc;
            E Tu = Ti + Tt;
            Tv = Td + Tu;
            T1N = Td - Tu;
            E T1U = T1S + T1T;
            E T1X = T1V + T1W;
            T1Y = T1U + T1X;
            T20 = T1X - T1U;
        }
        {
            E TM = TA + TL;
            E T13 = TR + T12;
            T14 = TM + T13;
            T1Z = TM - T13;
            E T1O = T1y + T1z;
            E T1P = T1E + T1F;
            T1Q = T1O - T1P;
            T1R = T1O + T1P;
        }
        cii[idx5] = Tv - T14;
        cri[idx9] = T1Z - T20;
        cii[idx8] = T1Z + T20;
        cri[0] = Tv + T14;
        cri[idx3] = T1N - T1Q;
        cri[idx6] = T1R - T1Y;
        cii[idx11] = T1R + T1Y;
        cii[idx2] = T1N + T1Q;
    }
    {
        E T1f, T1x, T28, T2a, T1q, T21, T1I, T29;
        {
            E T19 = T15 - T18;
            E T1e = T1a - T1d;
            T1f = T19 + T1e;
            T1x = T19 - T1e;
            E T24 = T22 - T23;
            E T27 = T25 - T26;
            T28 = T24 - T27;
            T2a = T27 + T24;
        }
        {
            E T1k = T1g - T1j;
            E T1p = T1l - T1o;
            T1q = T1k + T1p;
            T21 = T1p - T1k;
            E T1C = T1A - T1B;
            E T1H = T1D - T1G;
            T1I = T1C + T1H;
            T29 = T1H - T1C;
        }
        cri[idx2] = T1f - T1q;
        cri[idx8] = T29 - T2a;
        cii[idx9] = T29 + T2a;
        cii[idx3] = T1f + T1q;
        cii[0] = T1x - T1I;
        cri[idx11] = T21 - T28;
        cii[idx6] = T21 + T28;
        cri[idx5] = T1x + T1I;
    }
    {
        E T1t, T1J, T2e, T2g, T1w, T2b, T1M, T2f;
        {
            E T1r = T15 + T18;
            E T1s = T1a + T1d;
            T1t = T1r + T1s;
            T1J = T1r - T1s;
            E T2c = T23 + T22;
            E T2d = T26 + T25;
            T2e = T2c - T2d;
            T2g = T2d + T2c;
        }
        {
            E T1u = T1g + T1j;
            E T1v = T1l + T1o;
            T1w = T1u + T1v;
            T2b = T1v - T1u;
            E T1K = T1B + T1A;
            E T1L = T1D + T1G;
            T1M = T1K - T1L;
            T2f = T1K + T1L;
        }
        cii[idx1] = T1t - T1w;
        cri[idx1] = T1J + T1M;
        cri[idx4] = T1t + T1w;
        cii[idx4] = T1J - T1M;
        cri[idx7] = T2b - T2e;
        cii[idx7] = T2f + T2g;
        cii[idx10] = T2b + T2e;
        cri[idx10] = T2f - T2g;
    }
}
}
