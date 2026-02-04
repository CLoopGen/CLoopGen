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
for (m = mb , W = W + (mb * 8); m < me; m = m + 1 , rio += ms , iio += ms , W += 8) {
    E T1, Ta, TG, Tv, T8, Tb, Tp, Tj, TD, To, Tq, Tr, TN, TW, T1s;
    E T1h, TU, TX, T1b, T15, T1p, T1a, T1c, T1d, T1z, T1I, T2e, T23, T1G, T1J;
    E T1X, T1R, T2b, T1W, T1Y, T1Z, T3v, T3p, T3J, T3u, T3w, T3x, T37, T3g, T3M;
    E T3B, T3e, T3h, T2l, T2u, T30, T2P, T2s, T2v, T2J, T2D, T2X, T2I, T2K, T2L;

    const INT s1 = rs[1], s2 = rs[2], s3 = rs[3], s4 = rs[4];
    const INT t1 = vs[1], t2 = vs[2], t3 = vs[3], t4 = vs[4];

    E ri_vals[5], ii_vals[5];
    E * restrict rw = W;

    ri_vals[0] = rio[0];
    ri_vals[1] = rio[s1];
    ri_vals[2] = rio[s2];
    ri_vals[3] = rio[s3];
    ri_vals[4] = rio[s4];

    ii_vals[0] = iio[0];
    ii_vals[1] = iio[s1];
    ii_vals[2] = iio[s2];
    ii_vals[3] = iio[s3];
    ii_vals[4] = iio[s4];

    E T7 = ri_vals[2] + ri_vals[3];
    E Tu = ri_vals[2] - ri_vals[3];
    E T4 = ri_vals[1] + ri_vals[4];
    E Tt = ri_vals[1] - ri_vals[4];
    T1 = ri_vals[0];
    Ta = KP559016994 * (T4 - T7);
    TG = KP951056516 * Tu - KP587785252 * Tt;
    Tv = KP951056516 * Tt + KP587785252 * Tu;
    T8 = T4 + T7;
    Tb = T1 - KP250000000 * T8;

    E Ti = ii_vals[2] - ii_vals[3];
    E Tn = ii_vals[2] + ii_vals[3];
    E Tf = ii_vals[1] - ii_vals[4];
    E Tm = ii_vals[1] + ii_vals[4];
    Tp = ii_vals[0];
    Tj = KP951056516 * Tf + KP587785252 * Ti;
    TD = KP951056516 * Ti - KP587785252 * Tf;
    To = KP559016994 * (Tm - Tn);
    Tq = Tm + Tn;
    Tr = Tp - KP250000000 * Tq;

    E TT = rio[t1 + s2] + rio[t1 + s3];
    E T1g = rio[t1 + s2] - rio[t1 + s3];
    E TQ = rio[t1 + s1] + rio[t1 + s4];
    E T1f = rio[t1 + s1] - rio[t1 + s4];
    TN = rio[t1];
    TW = KP559016994 * (TQ - TT);
    T1s = KP951056516 * T1g - KP587785252 * T1f;
    T1h = KP951056516 * T1f + KP587785252 * T1g;
    TU = TQ + TT;
    TX = TN - KP250000000 * TU;

    E T14 = iio[t1 + s2] - iio[t1 + s3];
    E T19 = iio[t1 + s2] + iio[t1 + s3];
    E T11 = iio[t1 + s1] - iio[t1 + s4];
    E T18 = iio[t1 + s1] + iio[t1 + s4];
    T1b = iio[t1];
    T15 = KP951056516 * T11 + KP587785252 * T14;
    T1p = KP951056516 * T14 - KP587785252 * T11;
    T1a = KP559016994 * (T18 - T19);
    T1c = T18 + T19;
    T1d = T1b - KP250000000 * T1c;

    E T1F = rio[t2 + s2] + rio[t2 + s3];
    E T22 = rio[t2 + s2] - rio[t2 + s3];
    E T1C = rio[t2 + s1] + rio[t2 + s4];
    E T21 = rio[t2 + s1] - rio[t2 + s4];
    T1z = rio[t2];
    T1I = KP559016994 * (T1C - T1F);
    T2e = KP951056516 * T22 - KP587785252 * T21;
    T23 = KP951056516 * T21 + KP587785252 * T22;
    T1G = T1C + T1F;
    T1J = T1z - KP250000000 * T1G;

    E T1Q = iio[t2 + s2] - iio[t2 + s3];
    E T1V = iio[t2 + s2] + iio[t2 + s3];
    E T1N = iio[t2 + s1] - iio[t2 + s4];
    E T1U = iio[t2 + s1] + iio[t2 + s4];
    T1X = iio[t2];
    T1R = KP951056516 * T1N + KP587785252 * T1Q;
    T2b = KP951056516 * T1Q - KP587785252 * T1N;
    T1W = KP559016994 * (T1U - T1V);
    T1Y = T1U + T1V;
    T1Z = T1X - KP250000000 * T1Y;

    E T3o = iio[t4 + s2] - iio[t4 + s3];
    E T3t = iio[t4 + s2] + iio[t4 + s3];
    E T3l = iio[t4 + s1] - iio[t4 + s4];
    E T3s = iio[t4 + s1] + iio[t4 + s4];
    T3v = iio[t4];
    T3p = KP951056516 * T3l + KP587785252 * T3o;
    T3J = KP951056516 * T3o - KP587785252 * T3l;
    T3u = KP559016994 * (T3s - T3t);
    T3w = T3s + T3t;
    T3x = T3v - KP250000000 * T3w;

    E T3d = rio[t4 + s2] + rio[t4 + s3];
    E T3A = rio[t4 + s2] - rio[t4 + s3];
    E T3a = rio[t4 + s1] + rio[t4 + s4];
    E T3z = rio[t4 + s1] - rio[t4 + s4];
    T37 = rio[t4];
    T3g = KP559016994 * (T3a - T3d);
    T3M = KP951056516 * T3A - KP587785252 * T3z;
    T3B = KP951056516 * T3z + KP587785252 * T3A;
    T3e = T3a + T3d;
    T3h = T37 - KP250000000 * T3e;

    E T2r = rio[t3 + s2] + rio[t3 + s3];
    E T2O = rio[t3 + s2] - rio[t3 + s3];
    E T2o = rio[t3 + s1] + rio[t3 + s4];
    E T2N = rio[t3 + s1] - rio[t3 + s4];
    T2l = rio[t3];
    T2u = KP559016994 * (T2o - T2r);
    T30 = KP951056516 * T2O - KP587785252 * T2N;
    T2P = KP951056516 * T2N + KP587785252 * T2O;
    T2s = T2o + T2r;
    T2v = T2l - KP250000000 * T2s;

    E T2C = iio[t3 + s2] - iio[t3 + s3];
    E T2H = iio[t3 + s2] + iio[t3 + s3];
    E T2z = iio[t3 + s1] - iio[t3 + s4];
    E T2G = iio[t3 + s1] + iio[t3 + s4];
    T2J = iio[t3];
    T2D = KP951056516 * T2z + KP587785252 * T2C;
    T2X = KP951056516 * T2C - KP587785252 * T2z;
    T2I = KP559016994 * (T2G - T2H);
    T2K = T2G + T2H;
    T2L = T2J - KP250000000 * T2K;

    rio[0] = T1 + T8;
    iio[0] = Tp + Tq;
    rio[s1] = TN + TU;
    iio[s1] = T1b + T1c;
    rio[s2] = T1z + T1G;
    iio[s2] = T1X + T1Y;
    iio[s4] = T3v + T3w;
    rio[s4] = T37 + T3e;
    rio[s3] = T2l + T2s;
    iio[s3] = T2J + T2K;

    E Tc = Ta + Tb;
    E Tk = Tc + Tj, Ty = Tc - Tj;
    E Ts = To + Tr;
    E Tw = Ts - Tv, TA = Tv + Ts;
    rio[t1] = rw[0]*Tk + rw[1]*Tw;
    iio[t1] = rw[0]*Tw - rw[1]*Tk;
    rio[t4] = rw[6]*Ty + rw[7]*TA;
    iio[t4] = rw[6]*TA - rw[7]*Ty;

    E TC = Tb - Ta;
    E TE = TC - TD, TK = TC + TD;
    E TH = Tr - To;
    E TI = TG + TH, TM = TH - TG;
    rio[t2] = rw[2]*TE + rw[3]*TI;
    iio[t2] = rw[2]*TI - rw[3]*TE;
    rio[t3] = rw[4]*TK + rw[5]*TM;
    iio[t3] = rw[4]*TM - rw[5]*TK;

    E T2a = T1J - T1I;
    E T2c = T2a - T2b, T2i = T2a + T2b;
    E T2f = T1Z - T1W;
    E T2g = T2e + T2f, T2k = T2f - T2e;
    rio[t2 + s2] = rw[2]*T2c + rw[3]*T2g;
    iio[t2 + s2] = rw[2]*T2g - rw[3]*T2c;
    rio[t3 + s2] = rw[4]*T2i + rw[5]*T2k;
    iio[t3 + s2] = rw[4]*T2k - rw[5]*T2i;

    E T3I = T3h - T3g;
    E T3K = T3I - T3J, T3Q = T3I + T3J;
    E T3N = T3x - T3u;
    E T3O = T3M + T3N, T3S = T3N - T3M;
    rio[t2 + s4] = rw[2]*T3K + rw[3]*T3O;
    iio[t2 + s4] = rw[2]*T3O - rw[3]*T3K;
    rio[t3 + s4] = rw[4]*T3Q + rw[5]*T3S;
    iio[t3 + s4] = rw[4]*T3S - rw[5]*T3Q;

    E T1K = T1I + T1J;
    E T1S = T1K + T1R, T26 = T1K - T1R;
    E T20 = T1W + T1Z;
    E T24 = T20 - T23, T28 = T23 + T20;
    rio[t1 + s2] = rw[0]*T1S + rw[1]*T24;
    iio[t1 + s2] = rw[0]*T24 - rw[1]*T1S;
    rio[t4 + s2] = rw[6]*T26 + rw[7]*T28;
    iio[t4 + s2] = rw[6]*T28 - rw[7]*T26;

    E T2w = T2u + T2v;
    E T2E = T2w + T2D, T2S = T2w - T2D;
    E T2M = T2I + T2L;
    E T2Q = T2M - T2P, T2U = T2P + T2M;
    rio[t1 + s3] = rw[0]*T2E + rw[1]*T2Q;
    iio[t1 + s3] = rw[0]*T2Q - rw[1]*T2E;
    rio[t4 + s3] = rw[6]*T2S + rw[7]*T2U;
    iio[t4 + s3] = rw[6]*T2U - rw[7]*T2S;

    E T2W = T2v - T2u;
    E T2Y = T2W - T2X, T34 = T2W + T2X;
    E T31 = T2L - T2I;
    E T32 = T30 + T31, T36 = T31 - T30;
    rio[t2 + s3] = rw[2]*T2Y + rw[3]*T32;
    iio[t2 + s3] = rw[2]*T32 - rw[3]*T2Y;
    rio[t3 + s3] = rw[4]*T34 + rw[5]*T36;
    iio[t3 + s3] = rw[4]*T36 - rw[5]*T34;

    E T3i = T3g + T3h;
    E T3q = T3i + T3p, T3E = T3i - T3p;
    E T3y = T3u + T3x;
    E T3C = T3y - T3B, T3G = T3B + T3y;
    rio[t1 + s4] = rw[0]*T3q + rw[1]*T3C;
    iio[t1 + s4] = rw[0]*T3C - rw[1]*T3q;
    rio[t4 + s4] = rw[6]*T3E + rw[7]*T3G;
    iio[t4 + s4] = rw[6]*T3G - rw[7]*T3E;

    E T1o = TX - TW;
    E T1q = T1o - T1p, T1w = T1o + T1p;
    E T1t = T1d - T1a;
    E T1u = T1s + T1t, T1y = T1t - T1s;
    rio[t2 + s1] = rw[2]*T1q + rw[3]*T1u;
    iio[t2 + s1] = rw[2]*T1u - rw[3]*T1q;
    rio[t3 + s1] = rw[4]*T1w + rw[5]*T1y;
    iio[t3 + s1] = rw[4]*T1y - rw[5]*T1w;

    E TY = TW + TX;
    E T16 = TY + T15, T1k = TY - T15;
    E T1e = T1a + T1d;
    E T1i = T1e - T1h, T1m = T1h + T1e;
    rio[t1 + s1] = rw[0]*T16 + rw[1]*T1i;
    iio[t1 + s1] = rw[0]*T1i - rw[1]*T16;
    rio[t4 + s1] = rw[6]*T1k + rw[7]*T1m;
    iio[t4 + s1] = rw[6]*T1m - rw[7]*T1k;
}
}
