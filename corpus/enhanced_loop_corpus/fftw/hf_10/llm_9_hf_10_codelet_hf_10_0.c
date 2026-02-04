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
extern  E KP587785252;
extern  E KP951056516;
extern  E KP250000000;
extern  E KP559016994;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 18); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 18 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T7, T1R, TT, T1C, TF, TQ, TR, T1o, T1p, T1P, TX, TY, TZ, T1d, T1g;
    E T1x, Ti, Tt, Tu, T1r, T1s, T1O, TU, TV, TW, T16, T19, T1y;

    {
        E T1, T1A, T6, T1B;
        T1 = cr[0];
        T1A = ci[0];
        {
            E T3, T5, T2, T4;
            T3 = cr[(rs[5])];
            T5 = ci[(rs[5])];
            T2 = W[8];
            T4 = W[9];
            T6 = T2 * T3 + T4 * T5;
            T1B = T2 * T5 - T4 * T3;
        }
        T7 = T1 - T6;
        T1R = T1B + T1A;
        TT = T1 + T6;
        T1C = T1A - T1B;
    }

    {
        E Tz, T1b, TP, T1e, TE, T1c, TK, T1f;
        Tz = cr[(rs[4])] * W[6] + ci[(rs[4])] * W[7];
        T1b = W[6] * ci[(rs[4])] - W[7] * cr[(rs[4])];

        TP = cr[(rs[1])] * W[0] + ci[(rs[1])] * W[1];
        T1e = W[0] * ci[(rs[1])] - W[1] * cr[(rs[1])];

        TE = cr[(rs[9])] * W[16] + ci[(rs[9])] * W[17];
        T1c = W[16] * ci[(rs[9])] - W[17] * cr[(rs[9])];

        TK = cr[(rs[6])] * W[10] + ci[(rs[6])] * W[11];
        T1f = W[10] * ci[(rs[6])] - W[11] * cr[(rs[6])];

        TF = Tz - TE;
        TQ = TK - TP;
        TR = TF + TQ;
        T1o = T1b + T1c;
        T1p = T1f + T1e;
        T1P = T1o + T1p;
        TX = Tz + TE;
        TY = TK + TP;
        TZ = TX + TY;
        T1d = T1b - T1c;
        T1g = T1e - T1f;
        T1x = T1g - T1d;
    }

    {
        E Tc, T14, Ts, T18, Th, T15, Tn, T17;
        Tc = cr[(rs[2])] * W[2] + ci[(rs[2])] * W[3];
        T14 = W[2] * ci[(rs[2])] - W[3] * cr[(rs[2])];

        Ts = cr[(rs[3])] * W[4] + ci[(rs[3])] * W[5];
        T18 = W[4] * ci[(rs[3])] - W[5] * cr[(rs[3])];

        Th = cr[(rs[7])] * W[12] + ci[(rs[7])] * W[13];
        T15 = W[12] * ci[(rs[7])] - W[13] * cr[(rs[7])];

        Tn = cr[(rs[8])] * W[14] + ci[(rs[8])] * W[15];
        T17 = W[14] * ci[(rs[8])] - W[15] * cr[(rs[8])];

        Ti = Tc - Th;
        Tt = Tn - Ts;
        Tu = Ti + Tt;
        T1r = T14 + T15;
        T1s = T17 + T18;
        T1O = T1r + T1s;
        TU = Tc + Th;
        TV = Tn + Ts;
        TW = TU + TV;
        T16 = T14 - T15;
        T19 = T17 - T18;
        T1y = T16 + T19;
    }

    {
        E T11 = KP559016994 * (Tu - TR);
        E TS = Tu + TR;
        E T12 = T7 - KP250000000 * TS;
        E T1a = T16 - T19;
        E T1h = T1d + T1g;
        E T1i = KP951056516 * T1a + KP587785252 * T1h;
        E T1k = KP951056516 * T1h - KP587785252 * T1a;
        ci[(rs[4])] = T7 + TS;
        E T1j = T12 - T11;
        ci[(rs[2])] = T1j - T1k;
        cr[(rs[3])] = T1j + T1k;
        E T13 = T11 + T12;
        ci[0] = T13 - T1i;
        cr[(rs[1])] = T13 + T1i;
    }

    {
        E T1m = KP559016994 * (TW - TZ);
        E T10 = TW + TZ;
        E T1l = TT - KP250000000 * T10;
        E T1q = T1o - T1p;
        E T1t = T1r - T1s;
        E T1u = KP951056516 * T1q - KP587785252 * T1t;
        E T1w = KP951056516 * T1t + KP587785252 * T1q;
        cr[0] = TT + T10;
        E T1v = T1m + T1l;
        cr[(rs[4])] = T1v - T1w;
        ci[(rs[3])] = T1v + T1w;
        E T1n = T1l - T1m;
        cr[(rs[2])] = T1n - T1u;
        ci[(rs[1])] = T1n + T1u;
    }

    {
        E T1H = KP559016994 * (T1y + T1x);
        E T1z = T1x - T1y;
        E T1G = KP250000000 * T1z + T1C;
        E T1D = Ti - Tt;
        E T1E = TQ - TF;
        E T1F = KP587785252 * T1D + KP951056516 * T1E;
        E T1J = KP587785252 * T1E - KP951056516 * T1D;
        cr[(rs[5])] = T1z - T1C;
        E T1K = T1H + T1G;
        cr[(rs[9])] = T1J - T1K;
        ci[(rs[8])] = T1J + T1K;
        E T1I = T1G - T1H;
        cr[(rs[7])] = T1F - T1I;
        ci[(rs[6])] = T1F + T1I;
    }

    {
        E T1Q = KP559016994 * (T1O - T1P);
        E T1S = T1O + T1P;
        E T1T = T1R - KP250000000 * T1S;
        E T1L = TU - TV;
        E T1M = TX - TY;
        E T1N = KP951056516 * T1L + KP587785252 * T1M;
        E T1V = KP951056516 * T1M - KP587785252 * T1L;
        ci[(rs[9])] = T1S + T1R;
        E T1W = T1T - T1Q;
        cr[(rs[8])] = T1V - T1W;
        ci[(rs[7])] = T1V + T1W;
        E T1U = T1Q + T1T;
        cr[(rs[6])] = T1N - T1U;
        ci[(rs[5])] = T1N + T1U;
    }
}
}
