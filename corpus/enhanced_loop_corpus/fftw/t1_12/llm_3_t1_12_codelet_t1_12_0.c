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
extern  E KP500000000;
extern  E KP866025403;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Change memory access pattern to use fully consecutive array layout
// Assume input arrays have been pre-reorganized into linear buffers with fixed stride simulation
for (m = mb , W = W + (mb * 22); m < me; m = m + 1 , ri = ri + ms , ii = ii + ms , W = W + 22 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, T1W, T18, T21, Tc, T15, T1V, T22, TR, T1E, T1o, T1D, T12, T1l, T1F;
    E T1G, Ti, T1S, T1d, T24, Tt, T1a, T1T, T25, TA, T1z, T1j, T1y, TL, T1g;
    E T1A, T1B;

    // Precompute effective addresses using rs offsets to create a strided-to-consecutive mapping
    // This simulates gathering data from scattered locations into local variables via known index map
    const INT idx4 = rs[4], idx8 = rs[8], idx9 = rs[9], idx5 = rs[5], idx1 = rs[1];
    const INT idx6 = rs[6], idx2 = rs[2], idx10 = rs[10], idx3 = rs[3], idx11 = rs[11], idx7 = rs[7];

    // Load all required values upfront using computed indices to expose more ILP and reduce address recalc
    E r4 = ri[idx4], i4 = ii[idx4];
    E r8 = ri[idx8], i8 = ii[idx8];
    E r9 = ri[idx9], i9 = ii[idx9];
    E r5 = ri[idx5], i5 = ii[idx5];
    E r1 = ri[idx1], i1 = ii[idx1];
    E r6 = ri[idx6], i6 = ii[idx6];
    E r2 = ri[idx2], i2 = ii[idx2];
    E r10 = ri[idx10], i10 = ii[idx10];
    E r3 = ri[idx3], i3 = ii[idx3];
    E r11 = ri[idx11], i11 = ii[idx11];
    E r7 = ri[idx7], i7 = ii[idx7];

    // Also preload W values used multiple times
    E W0 = W[0], W1 = W[1], W2 = W[2], W3 = W[3], W4 = W[4], W5 = W[5];
    E W6 = W[6], W7 = W[7], W8 = W[8], W9 = W[9], W10 = W[10], W11 = W[11];
    E W12 = W[12], W13 = W[13], W14 = W[14], W15 = W[15], W16 = W[16], W17 = W[17];
    E W18 = W[18], W19 = W[19], W20 = W[20], W21 = W[21];

    {
        E T6, T16, Tb, T17;
        T1 = ri[0];
        T1W = ii[0];
        T6 = W6 * r4 + W7 * i4;
        T16 = W6 * i4 - W7 * r4;
        Tb = W14 * r8 + W15 * i8;
        T17 = W14 * i8 - W15 * r8;
        T18 = KP866025403 * (T16 - T17);
        T21 = KP866025403 * (Tb - T6);
        Tc = T6 + Tb;
        T15 = T1 - KP500000000 * Tc;
        T1V = T16 + T17;
        T22 = T1W - KP500000000 * T1V;
    }
    {
        E T11, T1n, TW, T1m;
        TR = W16 * r9 + W17 * i9;
        T1E = W16 * i9 - W17 * r9;
        T11 = W8 * r5 + W9 * i5;
        T1n = W8 * i5 - W9 * r5;
        TW = W0 * r1 + W1 * i1;
        T1m = W0 * i1 - W1 * r1;
        T1o = KP866025403 * (T1m - T1n);
        T1D = KP866025403 * (T11 - TW);
        T12 = TW + T11;
        T1l = TR - KP500000000 * T12;
        T1F = T1m + T1n;
        T1G = T1E - KP500000000 * T1F;
    }
    {
        E Ts, T1c, Tn, T1b;
        Ti = W10 * r6 + W11 * i6;
        T1S = W10 * i6 - W11 * r6;
        Ts = W2 * r2 + W3 * i2;
        T1c = W2 * i2 - W3 * r2;
        Tn = W18 * r10 + W19 * i10;
        T1b = W18 * i10 - W19 * r10;
        T1d = KP866025403 * (T1b - T1c);
        T24 = KP866025403 * (Ts - Tn);
        Tt = Tn + Ts;
        T1a = Ti - KP500000000 * Tt;
        T1T = T1b + T1c;
        T25 = T1S - KP500000000 * T1T;
    }
    {
        E TK, T1i, TF, T1h;
        TA = W4 * r3 + W5 * i3;
        T1z = W4 * i3 - W5 * r3;
        TK = W20 * r11 + W21 * i11;
        T1i = W20 * i11 - W21 * r11;
        TF = W12 * r7 + W13 * i7;
        T1h = W12 * i7 - W13 * r7;
        T1j = KP866025403 * (T1h - T1i);
        T1y = KP866025403 * (TK - TF);
        TL = TF + TK;
        T1g = TA - KP500000000 * TL;
        T1A = T1h + T1i;
        T1B = T1z - KP500000000 * T1A;
    }
    {
        E Tv, T1N, T1Y, T20, T14, T1Z, T1Q, T1R;
        {
            E Td, Tu, T1U, T1X;
            Td = T1 + Tc;
            Tu = Ti + Tt;
            Tv = Td + Tu;
            T1N = Td - Tu;
            T1U = T1S + T1T;
            T1X = T1V + T1W;
            T1Y = T1U + T1X;
            T20 = T1X - T1U;
        }
        {
            E TM, T13, T1O, T1P;
            TM = TA + TL;
            T13 = TR + T12;
            T14 = TM + T13;
            T1Z = TM - T13;
            T1O = T1z + T1A;
            T1P = T1E + T1F;
            T1Q = T1O - T1P;
            T1R = T1O + T1P;
        }
        ri[idx6] = Tv - T14;
        ii[idx6] = T1Y - T1R;
        ri[0] = Tv + T14;
        ii[0] = T1R + T1Y;
        ri[idx3] = T1N - T1Q;
        ii[idx3] = T1Z + T20;
        ri[idx9] = T1N + T1Q;
        ii[idx9] = T20 - T1Z;
    }
    {
        E T1t, T1x, T27, T2a, T1w, T28, T1I, T29;
        {
            E T1r, T1s, T23, T26;
            T1r = T15 + T18;
            T1s = T1a + T1d;
            T1t = T1r + T1s;
            T1x = T1r - T1s;
            T23 = T21 + T22;
            T26 = T24 + T25;
            T27 = T23 - T26;
            T2a = T26 + T23;
        }
        {
            E T1u, T1v, T1C, T1H;
            T1u = T1g + T1j;
            T1v = T1l + T1o;
            T1w = T1u + T1v;
            T28 = T1u - T1v;
            T1C = T1y + T1B;
            T1H = T1D + T1G;
            T1I = T1C - T1H;
            T29 = T1C + T1H;
        }
        ri[idx10] = T1t - T1w;
        ii[idx10] = T2a - T29;
        ri[idx4] = T1t + T1w;
        ii[idx4] = T29 + T2a;
        ri[idx7] = T1x - T1I;
        ii[idx7] = T28 + T27;
        ri[idx1] = T1x + T1I;
        ii[idx1] = T27 - T28;
    }
    {
        E T1f, T1J, T2d, T2f, T1q, T2g, T1M, T2e;
        {
            E T19, T1e, T2b, T2c;
            T19 = T15 - T18;
            T1e = T1a - T1d;
            T1f = T19 + T1e;
            T1J = T19 - T1e;
            T2b = T25 - T24;
            T2c = T22 - T21;
            T2d = T2b + T2c;
            T2f = T2c - T2b;
        }
        {
            E T1k, T1p, T1K, T1L;
            T1k = T1g - T1j;
            T1p = T1l - T1o;
            T1q = T1k + T1p;
            T2g = T1k - T1p;
            T1K = T1B - T1y;
            T1L = T1G - T1D;
            T1M = T1K - T1L;
            T2e = T1K + T1L;
        }
        ri[idx2] = T1f - T1q;
        ii[idx2] = T2d - T2e;
        ri[idx8] = T1f + T1q;
        ii[idx8] = T2e + T2d;
        ri[idx11] = T1J - T1M;
        ii[idx11] = T2g + T2f;
        ri[idx5] = T1J + T1M;
        ii[idx5] = T2f - T2g;
    }
}
}
