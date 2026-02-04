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

    // Change memory access pattern: use array-of-struct style with local arrays
    // to promote consecutive memory layout and improve cache locality
    E cr_vals[12], ci_vals[12];  // Locally cached values accessed consecutively
    E W_vals[22];                // Cache W block for unit stride access

    // Prefetch all required data using stride and store in linear arrays
    for (INT i = 0; i < 12; ++i) {
        INT s = rs[i];
        cr_vals[i] = cr[s];
        ci_vals[i] = ci[s];
    }
    for (INT w = 0; w < 22; ++w) {
        W_vals[w] = W[w];
    }

    {
        E T6, T16, Tb, T17;
        T1 = cr_vals[0];
        T1W = ci_vals[0];
        {
            E T3 = cr_vals[4], T5 = ci_vals[4];
            E T2 = W_vals[6], T4 = W_vals[7];
            T6 = T2 * T3 + T4 * T5;
            T16 = T2 * T5 - T4 * T3;
        }
        {
            E T8 = cr_vals[8], Ta = ci_vals[8];
            E T7 = W_vals[14], T9 = W_vals[15];
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
            E TO = cr_vals[9], TQ = ci_vals[9];
            E TN = W_vals[16], TP = W_vals[17];
            TR = TN * TO + TP * TQ;
            T1E = TN * TQ - TP * TO;
        }
        {
            E TY = cr_vals[5], T10 = ci_vals[5];
            E TX = W_vals[8], TZ = W_vals[9];
            T11 = TX * TY + TZ * T10;
            T1n = TX * T10 - TZ * TY;
        }
        {
            E TT = cr_vals[1], TV = ci_vals[1];
            E TS = W_vals[0], TU = W_vals[1];
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
            E Tf = cr_vals[6], Th = ci_vals[6];
            E Te = W_vals[10], Tg = W_vals[11];
            Ti = Te * Tf + Tg * Th;
            T1S = Te * Th - Tg * Tf;
        }
        {
            E Tp = cr_vals[2], Tr = ci_vals[2];
            E To = W_vals[2], Tq = W_vals[3];
            Ts = To * Tp + Tq * Tr;
            T1c = To * Tr - Tq * Tp;
        }
        {
            E Tk = cr_vals[10], Tm = ci_vals[10];
            E Tj = W_vals[18], Tl = W_vals[19];
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
            E Tx = cr_vals[3], Tz = ci_vals[3];
            E Tw = W_vals[4], Ty = W_vals[5];
            TA = Tw * Tx + Ty * Tz;
            T1y = Tw * Tz - Ty * Tx;
        }
        {
            E TH = cr_vals[11], TJ = ci_vals[11];
            E TG = W_vals[20], TI = W_vals[21];
            TK = TG * TH + TI * TJ;
            T1i = TG * TJ - TI * TH;
        }
        {
            E TC = cr_vals[7], TE = ci_vals[7];
            E TB = W_vals[12], TD = W_vals[13];
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
        ci_vals[5] = Tv - T14;
        cr_vals[9] = T1Z - T20;
        ci_vals[8] = T1Z + T20;
        cr_vals[0] = Tv + T14;
        cr_vals[3] = T1N - T1Q;
        cr_vals[6] = T1R - T1Y;
        ci_vals[11] = T1R + T1Y;
        ci_vals[2] = T1N + T1Q;
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
        cr_vals[2] = T1f - T1q;
        cr_vals[8] = T29 - T2a;
        ci_vals[9] = T29 + T2a;
        ci_vals[3] = T1f + T1q;
        ci_vals[0] = T1x - T1I;
        cr_vals[11] = T21 - T28;
        ci_vals[6] = T21 + T28;
        cr_vals[5] = T1x + T1I;
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
        ci_vals[1] = T1t - T1w;
        cr_vals[1] = T1J + T1M;
        cr_vals[4] = T1t + T1w;
        ci_vals[4] = T1J - T1M;
        cr_vals[7] = T2b - T2e;
        ci_vals[7] = T2f + T2g;
        ci_vals[10] = T2b + T2e;
        cr_vals[10] = T2f - T2g;
    }

    // Write back results to original strided locations
    for (INT i = 0; i < 12; ++i) {
        INT s = rs[i];
        cr[s] = cr_vals[i];
        ci[s] = ci_vals[i];
    }
}
}
