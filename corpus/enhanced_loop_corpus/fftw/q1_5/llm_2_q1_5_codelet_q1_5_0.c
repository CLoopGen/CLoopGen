#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *rio;
extern R *iio;
extern  R *W;
extern stride rs;
extern stride vs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP250000000;
extern  E KP587785252;
extern  E KP951056516;
extern  E KP559016994;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + (mb * 8); m < me; m = m + 1 , rio = rio + ms , iio = iio + ms , W = W + 8 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (vs) = (vs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, Ta, TG, Tv, T8, Tb, Tp, Tj, TD, To, Tq, Tr, TN, TW, T1s;
    E T1h, TU, TX, T1b, T15, T1p, T1a, T1c, T1d, T1z, T1I, T2e, T23, T1G, T1J;
    E T1X, T1R, T2b, T1W, T1Y, T1Z, T3v, T3p, T3J, T3u, T3w, T3x, T37, T3g, T3M;
    E T3B, T3e, T3h, T2l, T2u, T30, T2P, T2s, T2v, T2J, T2D, T2X, T2I, T2K, T2L;
    const INT r1 = rs[1], r2 = rs[2], r3 = rs[3], r4 = rs[4];
    const INT v1 = vs[1], v2 = vs[2], v4 = vs[4], v3 = vs[3];
    E * restrict rbase = rio;
    E * restrict ibase = iio;
    E * restrict wptr = W;

    {
        E T7, Tu, T4, Tt;
        T1 = rbase[0];
        {
            E T5 = rbase[r2], T6 = rbase[r3];
            T7 = T5 + T6;
            Tu = T5 - T6;
            E T2 = rbase[r1], T3 = rbase[r4];
            T4 = T2 + T3;
            Tt = T2 - T3;
        }
        Ta = KP559016994 * (T4 - T7);
        TG = ((KP951056516 * Tu) - ((KP587785252) * (Tt)));
        Tv = (((KP951056516) * (Tt)) + (KP587785252 * Tu));
        T8 = T4 + T7;
        Tb = ((T1) - ((KP250000000) * (T8)));
    }
    {
        E Ti, Tn, Tf, Tm;
        Tp = ibase[0];
        {
            E Tg = ibase[r2], Th = ibase[r3];
            Ti = Tg - Th;
            Tn = Tg + Th;
            E Td = ibase[r1], Te = ibase[r4];
            Tf = Td - Te;
            Tm = Td + Te;
        }
        Tj = (((KP951056516) * (Tf)) + (KP587785252 * Ti));
        TD = ((KP951056516 * Ti) - ((KP587785252) * (Tf)));
        To = KP559016994 * (Tm - Tn);
        Tq = Tm + Tn;
        Tr = ((Tp) - ((KP250000000) * (Tq)));
    }
    {
        E TT, T1g, TQ, T1f;
        TN = rbase[v1];
        {
            E TR = rbase[v1 + r2], TS = rbase[v1 + r3];
            TT = TR + TS;
            T1g = TR - TS;
            E TO = rbase[v1 + r1], TP = rbase[v1 + r4];
            TQ = TO + TP;
            T1f = TO - TP;
        }
        TW = KP559016994 * (TQ - TT);
        T1s = ((KP951056516 * T1g) - ((KP587785252) * (T1f)));
        T1h = (((KP951056516) * (T1f)) + (KP587785252 * T1g));
        TU = TQ + TT;
        TX = ((TN) - ((KP250000000) * (TU)));
    }
    {
        E T14, T19, T11, T18;
        T1b = ibase[v1];
        {
            E T12 = ibase[v1 + r2], T13 = ibase[v1 + r3];
            T14 = T12 - T13;
            T19 = T12 + T13;
            E TZ = ibase[v1 + r1], T10 = ibase[v1 + r4];
            T11 = TZ - T10;
            T18 = TZ + T10;
        }
        T15 = (((KP951056516) * (T11)) + (KP587785252 * T14));
        T1p = ((KP951056516 * T14) - ((KP587785252) * (T11)));
        T1a = KP559016994 * (T18 - T19);
        T1c = T18 + T19;
        T1d = ((T1b) - ((KP250000000) * (T1c)));
    }
    {
        E T1F, T22, T1C, T21;
        T1z = rbase[v2];
        {
            E T1D = rbase[v2 + r2], T1E = rbase[v2 + r3];
            T1F = T1D + T1E;
            T22 = T1D - T1E;
            E T1A = rbase[v2 + r1], T1B = rbase[v2 + r4];
            T1C = T1A + T1B;
            T21 = T1A - T1B;
        }
        T1I = KP559016994 * (T1C - T1F);
        T2e = ((KP951056516 * T22) - ((KP587785252) * (T21)));
        T23 = (((KP951056516) * (T21)) + (KP587785252 * T22));
        T1G = T1C + T1F;
        T1J = ((T1z) - ((KP250000000) * (T1G)));
    }
    {
        E T1Q, T1V, T1N, T1U;
        T1X = ibase[v2];
        {
            E T1O = ibase[v2 + r2], T1P = ibase[v2 + r3];
            T1Q = T1O - T1P;
            T1V = T1O + T1P;
            E T1L = ibase[v2 + r1], T1M = ibase[v2 + r4];
            T1N = T1L - T1M;
            T1U = T1L + T1M;
        }
        T1R = (((KP951056516) * (T1N)) + (KP587785252 * T1Q));
        T2b = ((KP951056516 * T1Q) - ((KP587785252) * (T1N)));
        T1W = KP559016994 * (T1U - T1V);
        T1Y = T1U + T1V;
        T1Z = ((T1X) - ((KP250000000) * (T1Y)));
    }
    {
        E T3o, T3t, T3l, T3s;
        T3v = ibase[v4];
        {
            E T3m = ibase[v4 + r2], T3n = ibase[v4 + r3];
            T3o = T3m - T3n;
            T3t = T3m + T3n;
            E T3j = ibase[v4 + r1], T3k = ibase[v4 + r4];
            T3l = T3j - T3k;
            T3s = T3j + T3k;
        }
        T3p = (((KP951056516) * (T3l)) + (KP587785252 * T3o));
        T3J = ((KP951056516 * T3o) - ((KP587785252) * (T3l)));
        T3u = KP559016994 * (T3s - T3t);
        T3w = T3s + T3t;
        T3x = ((T3v) - ((KP250000000) * (T3w)));
    }
    {
        E T3d, T3A, T3a, T3z;
        T37 = rbase[v4];
        {
            E T3b = rbase[v4 + r2], T3c = rbase[v4 + r3];
            T3d = T3b + T3c;
            T3A = T3b - T3c;
            E T38 = rbase[v4 + r1], T39 = rbase[v4 + r4];
            T3a = T38 + T39;
            T3z = T38 - T39;
        }
        T3g = KP559016994 * (T3a - T3d);
        T3M = ((KP951056516 * T3A) - ((KP587785252) * (T3z)));
        T3B = (((KP951056516) * (T3z)) + (KP587785252 * T3A));
        T3e = T3a + T3d;
        T3h = ((T37) - ((KP250000000) * (T3e)));
    }
    {
        E T2r, T2O, T2o, T2N;
        T2l = rbase[v3];
        {
            E T2p = rbase[v3 + r2], T2q = rbase[v3 + r3];
            T2r = T2p + T2q;
            T2O = T2p - T2q;
            E T2m = rbase[v3 + r1], T2n = rbase[v3 + r4];
            T2o = T2m + T2n;
            T2N = T2m - T2n;
        }
        T2u = KP559016994 * (T2o - T2r);
        T30 = ((KP951056516 * T2O) - ((KP587785252) * (T2N)));
        T2P = (((KP951056516) * (T2N)) + (KP587785252 * T2O));
        T2s = T2o + T2r;
        T2v = ((T2l) - ((KP250000000) * (T2s)));
    }
    {
        E T2C, T2H, T2z, T2G;
        T2J = ibase[v3];
        {
            E T2A = ibase[v3 + r2], T2B = ibase[v3 + r3];
            T2C = T2A - T2B;
            T2H = T2A + T2B;
            E T2x = ibase[v3 + r1], T2y = ibase[v3 + r4];
            T2z = T2x - T2y;
            T2G = T2x + T2y;
        }
        T2D = (((KP951056516) * (T2z)) + (KP587785252 * T2C));
        T2X = ((KP951056516 * T2C) - ((KP587785252) * (T2z)));
        T2I = KP559016994 * (T2G - T2H);
        T2K = T2G + T2H;
        T2L = ((T2J) - ((KP250000000) * (T2K)));
    }

    rbase[0] = T1 + T8;
    ibase[0] = Tp + Tq;
    rbase[r1] = TN + TU;
    ibase[r1] = T1b + T1c;
    rbase[r2] = T1z + T1G;
    ibase[r2] = T1X + T1Y;
    ibase[r4] = T3v + T3w;
    rbase[r4] = T37 + T3e;
    rbase[r3] = T2l + T2s;
    ibase[r3] = T2J + T2K;

    {
        E Tk, Ty, Tw, TA, Tc, Ts;
        Tc = Ta + Tb;
        Tk = Tc + Tj;
        Ty = Tc - Tj;
        Ts = To + Tr;
        Tw = Ts - Tv;
        TA = Tv + Ts;
        {
            E T9 = wptr[0], Tl = wptr[1];
            rbase[v1] = T9 * Tk + Tl * Tw;
            ibase[v1] = T9 * Tw - Tl * Tk;
            E Tx = wptr[6], Tz = wptr[7];
            rbase[v4] = Tx * Ty + Tz * TA;
            ibase[v4] = Tx * TA - Tz * Ty;
        }
    }
    {
        E TE, TK, TI, TM, TC, TH;
        TC = Tb - Ta;
        TE = TC - TD;
        TK = TC + TD;
        TH = Tr - To;
        TI = TG + TH;
        TM = TH - TG;
        {
            E TB = wptr[2], TF = wptr[3];
            rbase[v2] = TB * TE + TF * TI;
            ibase[v2] = TB * TI - TF * TE;
            E TJ = wptr[4], TL = wptr[5];
            rbase[v3] = TJ * TK + TL * TM;
            ibase[v3] = TJ * TM - TL * TK;
        }
    }
    {
        E T2c, T2i, T2g, T2k, T2a, T2f;
        T2a = T1J - T1I;
        T2c = T2a - T2b;
        T2i = T2a + T2b;
        T2f = T1Z - T1W;
        T2g = T2e + T2f;
        T2k = T2f - T2e;
        {
            E T29 = wptr[2], T2d = wptr[3];
            rbase[v2 + r2] = T29 * T2c + T2d * T2g;
            ibase[v2 + r2] = T29 * T2g - T2d * T2c;
            E T2h = wptr[4], T2j = wptr[5];
            rbase[v3 + r2] = T2h * T2i + T2j * T2k;
            ibase[v3 + r2] = T2h * T2k - T2j * T2i;
        }
    }
    {
        E T3K, T3Q, T3O, T3S, T3I, T3N;
        T3I = T3h - T3g;
        T3K = T3I - T3J;
        T3Q = T3I + T3J;
        T3N = T3x - T3u;
        T3O = T3M + T3N;
        T3S = T3N - T3M;
        {
            E T3H = wptr[2], T3L = wptr[3];
            rbase[v2 + r4] = T3H * T3K + T3L * T3O;
            ibase[v2 + r4] = T3H * T3O - T3L * T3K;
            E T3P = wptr[4], T3R = wptr[5];
            rbase[v3 + r4] = T3P * T3Q + T3R * T3S;
            ibase[v3 + r4] = T3P * T3S - T3R * T3Q;
        }
    }
    {
        E T1S, T26, T24, T28, T1K, T20;
        T1K = T1I + T1J;
        T1S = T1K + T1R;
        T26 = T1K - T1R;
        T20 = T1W + T1Z;
        T24 = T20 - T23;
        T28 = T23 + T20;
        {
            E T1H = wptr[0], T1T = wptr[1];
            rbase[v1 + r2] = T1H * T1S + T1T * T24;
            ibase[v1 + r2] = T1H * T24 - T1T * T1S;
            E T25 = wptr[6], T27 = wptr[7];
            rbase[v4 + r2] = T25 * T26 + T27 * T28;
            ibase[v4 + r2] = T25 * T28 - T27 * T26;
        }
    }
    {
        E T2E, T2S, T2Q, T2U, T2w, T2M;
        T2w = T2u + T2v;
        T2E = T2w + T2D;
        T2S = T2w - T2D;
        T2M = T2I + T2L;
        T2Q = T2M - T2P;
        T2U = T2P + T2M;
        {
            E T2t = wptr[0], T2F = wptr[1];
            rbase[v1 + r3] = T2t * T2E + T2F * T2Q;
            ibase[v1 + r3] = T2t * T2Q - T2F * T2E;
            E T2R = wptr[6], T2T = wptr[7];
            rbase[v4 + r3] = T2R * T2S + T2T * T2U;
            ibase[v4 + r3] = T2R * T2U - T2T * T2S;
        }
    }
    {
        E T2Y, T34, T32, T36, T2W, T31;
        T2W = T2v - T2u;
        T2Y = T2W - T2X;
        T34 = T2W + T2X;
        T31 = T2L - T2I;
        T32 = T30 + T31;
        T36 = T31 - T30;
        {
            E T2V = wptr[2], T2Z = wptr[3];
            rbase[v2 + r3] = T2V * T2Y + T2Z * T32;
            ibase[v2 + r3] = T2V * T32 - T2Z * T2Y;
            E T33 = wptr[4], T35 = wptr[5];
            rbase[v3 + r3] = T33 * T34 + T35 * T36;
            ibase[v3 + r3] = T33 * T36 - T35 * T34;
        }
    }
    {
        E T3q, T3E, T3C, T3G, T3i, T3y;
        T3i = T3g + T3h;
        T3q = T3i + T3p;
        T3E = T3i - T3p;
        T3y = T3u + T3x;
        T3C = T3y - T3B;
        T3G = T3B + T3y;
        {
            E T3f = wptr[0], T3r = wptr[1];
            rbase[v1 + r4] = T3f * T3q + T3r * T3C;
            ibase[v1 + r4] = T3f * T3C - T3r * T3q;
            E T3D = wptr[6], T3F = wptr[7];
            rbase[v4 + r4] = T3D * T3E + T3F * T3G;
            ibase[v4 + r4] = T3D * T3G - T3F * T3E;
        }
    }
    {
        E T1q, T1w, T1u, T1y, T1o, T1t;
        T1o = TX - TW;
        T1q = T1o - T1p;
        T1w = T1o + T1p;
        T1t = T1d - T1a;
        T1u = T1s + T1t;
        T1y = T1t - T1s;
        {
            E T1n = wptr[2], T1r = wptr[3];
            rbase[v2 + r1] = T1n * T1q + T1r * T1u;
            ibase[v2 + r1] = T1n * T1u - T1r * T1q;
            E T1v = wptr[4], T1x = wptr[5];
            rbase[v3 + r1] = T1v * T1w + T1x * T1y;
            ibase[v3 + r1] = T1v * T1y - T1x * T1w;
        }
    }
    {
        E T16, T1k, T1i, T1m, TY, T1e;
        TY = TW + TX;
        T16 = TY + T15;
        T1k = TY - T15;
        T1e = T1a + T1d;
        T1i = T1e - T1h;
        T1m = T1h + T1e;
        {
            E TV = wptr[0], T17 = wptr[1];
            rbase[v1 + r1] = TV * T16 + T17 * T1i;
            ibase[v1 + r1] = TV * T1i - T17 * T16;
            E T1j = wptr[6], T1l = wptr[7];
            rbase[v4 + r1] = T1j * T1k + T1l * T1m;
            ibase[v4 + r1] = T1j * T1m - T1l * T1k;
        }
    }
}
}
