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
extern  E KP382683432;
extern  E KP923879532;
extern  E KP707106781;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 8); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 8 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E Tv, Ty, T1l, T1n, T1p, T1t, T27, T25, Tz, Tw, TB, T21, T1P, T1H, T1X;
    E T17, T1L, T1N, T1v, T1w, T1x, T1B, T2F, T2T, T2b, T2R, T3j, T3x, T35, T3t;

    // Flattened structure: removed one level of block scoping to reduce nesting depth
    E TA, T1J, T15, T1G, Tx, T1K, T16, T1F;
    E T1m, T1s, T1o, T1r;
    Tv = W[0];
    Ty = W[1];
    T1l = W[2];
    T1n = W[3];
    T1m = Tv * T1l;
    T1s = Ty * T1l;
    T1o = Ty * T1n;
    T1r = Tv * T1n;
    T1p = T1m + T1o;
    T1t = T1r - T1s;
    T27 = T1r + T1s;
    T25 = T1m - T1o;
    Tz = W[5];
    TA = Ty * Tz;
    T1J = T1l * Tz;
    T15 = Tv * Tz;
    T1G = T1n * Tz;
    Tw = W[4];
    Tx = Tv * Tw;
    T1K = T1n * Tw;
    T16 = Ty * Tw;
    T1F = T1l * Tw;

    TB = Tx - TA;
    T21 = T1J + T1K;
    T1P = T15 - T16;
    T1H = T1F + T1G;
    T1X = T1F - T1G;
    T17 = T15 + T16;
    T1L = T1J - T1K;
    T1N = Tx + TA;
    T1v = W[6];
    T1w = W[7];
    T1x = (((Tv) * (T1v)) + (Ty * T1w));
    T1B = ((Tv * T1w) - ((Ty) * (T1v)));

    E T2D, T2E, T29, T2a;
    T2D = T25 * Tz;
    T2E = T27 * Tw;
    T2F = T2D + T2E;
    T2T = T2D - T2E;
    T29 = T25 * Tw;
    T2a = T27 * Tz;
    T2b = T29 - T2a;
    T2R = T29 + T2a;

    E T3h, T3i, T33, T34;
    T3h = T1p * Tz;
    T3i = T1t * Tw;
    T3j = T3h + T3i;
    T3x = T3h - T3i;
    T33 = T1p * Tw;
    T34 = T1t * Tz;
    T35 = T33 - T34;
    T3t = T33 + T34;

    E T7, T36, T3k, TC, T1f, T2e, T2I, T1Q, Te, TJ, T1R, T18, T2L, T37, T2l;
    E T3l, Tm, T1T, TT, T1h, T2A, T2N, T3b, T3n, Tt, T1U, T12, T1i, T2t, T2O;
    E T3e, T3o;

    E T3, T2c, T1e, T2d, T6, T2G, T1b, T2H;
    E T1, T2, T1c, T1d;
    T1 = cr[0];
    T2 = ci[(rs[7])];
    T3 = T1 + T2;
    T2c = T1 - T2;
    T1c = ci[(rs[11])];
    T1d = cr[(rs[12])];
    T1e = T1c - T1d;
    T2d = T1c + T1d;

    E T4, T5, T19, T1a;
    T4 = cr[(rs[4])];
    T5 = ci[(rs[3])];
    T6 = T4 + T5;
    T2G = T4 - T5;
    T19 = ci[(rs[15])];
    T1a = cr[(rs[8])];
    T1b = T19 - T1a;
    T2H = T19 + T1a;

    T7 = T3 + T6;
    T36 = T2c + T2d;
    T3k = T2H - T2G;
    TC = T3 - T6;
    T1f = T1b - T1e;
    T2e = T2c - T2d;
    T2I = T2G + T2H;
    T1Q = T1b + T1e;

    E Ta, T2f, TI, T2g, Td, T2i, TF, T2j;
    E T8, T9, TG, TH;
    T8 = cr[(rs[2])];
    T9 = ci[(rs[5])];
    Ta = T8 + T9;
    T2f = T8 - T9;
    TG = ci[(rs[13])];
    TH = cr[(rs[10])];
    TI = TG - TH;
    T2g = TG + TH;

    E Tb, Tc, TD, TE;
    Tb = ci[(rs[1])];
    Tc = cr[(rs[6])];
    Td = Tb + Tc;
    T2i = Tb - Tc;
    TD = ci[(rs[9])];
    TE = cr[(rs[14])];
    TF = TD - TE;
    T2j = TD + TE;

    Te = Ta + Td;
    TJ = TF - TI;
    T1R = TI + TF;
    T18 = Ta - Td;

    E T2J, T2K, T2h, T2k;
    T2J = T2f + T2g;
    T2K = T2i + T2j;
    T2L = KP707106781 * (T2J - T2K);
    T37 = KP707106781 * (T2J + T2K);
    T2h = T2f - T2g;
    T2k = T2i - T2j;
    T2l = KP707106781 * (T2h + T2k);
    T3l = KP707106781 * (T2h - T2k);

    E Ti, T2x, TR, T2y, Tl, T2u, TO, T2v, TL, TS;
    E Tg, Th, TP, TQ;
    Tg = cr[(rs[1])];
    Th = ci[(rs[6])];
    Ti = Tg + Th;
    T2x = Tg - Th;
    TP = ci[(rs[10])];
    TQ = cr[(rs[13])];
    TR = TP - TQ;
    T2y = TP + TQ;

    E Tj, Tk, TM, TN;
    Tj = cr[(rs[5])];
    Tk = ci[(rs[2])];
    Tl = Tj + Tk;
    T2u = Tj - Tk;
    TM = ci[(rs[14])];
    TN = cr[(rs[9])];
    TO = TM - TN;
    T2v = TM + TN;

    Tm = Ti + Tl;
    T1T = TO + TR;
    TL = Ti - Tl;
    TS = TO - TR;
    TT = TL - TS;
    T1h = TL + TS;

    E T2w, T2z, T39, T3a;
    T2w = T2u + T2v;
    T2z = T2x - T2y;
    T2A = (((KP923879532) * (T2w)) + (KP382683432 * T2z));
    T2N = ((KP923879532 * T2z) - ((KP382683432) * (T2w)));
    T39 = T2x + T2y;
    T3a = T2v - T2u;
    T3b = ((KP382683432 * T39) - ((KP923879532) * (T3a)));
    T3n = (((KP382683432) * (T3a)) + (KP923879532 * T39));

    E Tp, T2q, T10, T2r, Ts, T2n, TX, T2o, TU, T11;
    E Tn, To, TY, TZ;
    Tn = ci[0];
    To = cr[(rs[7])];
    Tp = Tn + To;
    T2q = Tn - To;
    TY = ci[(rs[12])];
    TZ = cr[(rs[11])];
    T10 = TY - TZ;
    T2r = TY + TZ;

    E Tq, Tr, TV, TW;
    Tq = cr[(rs[3])];
    Tr = ci[(rs[4])];
    Ts = Tq + Tr;
    T2n = Tq - Tr;
    TV = ci[(rs[8])];
    TW = cr[(rs[15])];
    TX = TV - TW;
    T2o = TV + TW;

    Tt = Tp + Ts;
    T1U = TX + T10;
    TU = Tp - Ts;
    T11 = TX - T10;
    T12 = TU + T11;
    T1i = T11 - TU;

    E T2p, T2s, T3c, T3d;
    T2p = T2n - T2o;
    T2s = T2q - T2r;
    T2t = ((KP923879532 * T2p) - ((KP382683432) * (T2s)));
    T2O = (((KP382683432) * (T2p)) + (KP923879532 * T2s));
    T3c = T2q + T2r;
    T3d = T2n + T2o;
    T3e = ((KP382683432 * T3c) - ((KP923879532) * (T3d)));
    T3o = (((KP382683432) * (T3d)) + (KP923879532 * T3c));

    E Tf, Tu, T1O, T1S, T1V, T1W;
    Tf = T7 + Te;
    Tu = Tm + Tt;
    T1O = Tf - Tu;
    T1S = T1Q + T1R;
    T1V = T1T + T1U;
    T1W = T1S - T1V;
    cr[0] = Tf + Tu;
    ci[0] = T1S + T1V;
    cr[(rs[8])] = ((T1N * T1O) - ((T1P) * (T1W)));
    ci[(rs[8])] = (((T1P) * (T1O)) + (T1N * T1W));

    E T3g, T3r, T3q, T3s;
    E T38, T3f, T3m, T3p;
    T38 = T36 - T37;
    T3f = T3b + T3e;
    T3g = T38 - T3f;
    T3r = T38 + T3f;
    T3m = T3k + T3l;
    T3p = T3n - T3o;
    T3q = T3m - T3p;
    T3s = T3m + T3p;

    cr[(rs[11])] = ((T35 * T3g) - ((T3j) * (T3q)));
    ci[(rs[11])] = (((T3j) * (T3g)) + (T35 * T3q));
    cr[(rs[3])] = ((T1l * T3r) - ((T1n) * (T3s)));
    ci[(rs[3])] = (((T1n) * (T3r)) + (T1l * T3s));

    E T3w, T3B, T3A, T3C;
    E T3u, T3v, T3y, T3z;
    T3u = T36 + T37;
    T3v = T3n + T3o;
    T3w = T3u - T3v;
    T3B = T3u + T3v;
    T3y = T3k - T3l;
    T3z = T3b - T3e;
    T3A = T3y + T3z;
    T3C = T3y - T3z;

    cr[(rs[7])] = ((T3t * T3w) - ((T3x) * (T3A)));
    ci[(rs[7])] = (((T3t) * (T3A)) + (T3x * T3w));
    cr[(rs[15])] = ((T1v * T3B) - ((T1w) * (T3C)));
    ci[(rs[15])] = (((T1v) * (T3C)) + (T1w * T3B));

    E T14, T1q, T1k, T1u;
    E TK, T13, T1g, T1j;
    TK = TC + TJ;
    T13 = KP707106781 * (TT + T12);
    T14 = TK - T13;
    T1q = TK + T13;
    T1g = T18 + T1f;
    T1j = KP707106781 * (T1h + T1i);
    T1k = T1g - T1j;
    T1u = T1g + T1j;

    cr[(rs[10])] = ((TB * T14) - ((T17) * (T1k)));
    ci[(rs[10])] = (((T17) * (T14)) + (TB * T1k));
    cr[(rs[2])] = ((T1p * T1q) - ((T1t) * (T1u)));
    ci[(rs[2])] = (((T1t) * (T1q)) + (T1p * T1u));

    E T1A, T1I, T1E, T1M;
    E T1y, T1z, T1C, T1D;
    T1y = TC - TJ;
    T1z = KP707106781 * (T1i - T1h);
    T1A = T1y - T1z;
    T1I = T1y + T1z;
    T1C = T1f - T18;
    T1D = KP707106781 * (TT - T12);
    T1E = T1C - T1D;
    T1M = T1C + T1D;

    cr[(rs[14])] = ((T1x * T1A) - ((T1B) * (T1E)));
    ci[(rs[14])] = (((T1x) * (T1E)) + (T1B * T1A));
    cr[(rs[6])] = ((T1H * T1I) - ((T1L) * (T1M)));
    ci[(rs[6])] = (((T1H) * (T1M)) + (T1L * T1I));

    E T2C, T2S, T2Q, T2U;
    E T2m, T2B, T2M, T2P;
    T2m = T2e - T2l;
    T2B = T2t - T2A;
    T2C = T2m - T2B;
    T2S = T2m + T2B;
    T2M = T2I - T2L;
    T2P = T2N - T2O;
    T2Q = T2M - T2P;
    T2U = T2M + T2P;

    cr[(rs[13])] = ((T2b * T2C) - ((T2F) * (T2Q)));
    ci[(rs[13])] = (((T2F) * (T2C)) + (T2b * T2Q));
    cr[(rs[5])] = ((T2R * T2S) - ((T2T) * (T2U)));
    ci[(rs[5])] = (((T2T) * (T2S)) + (T2R * T2U));

    E T2X, T31, T30, T32;
    E T2V, T2W, T2Y, T2Z;
    T2V = T2e + T2l;
    T2W = T2N + T2O;
    T2X = T2V - T2W;
    T31 = T2V + T2W;
    T2Y = T2I + T2L;
    T2Z = T2A + T2t;
    T30 = T2Y - T2Z;
    T32 = T2Y + T2Z;

    cr[(rs[9])] = ((Tw * T2X) - ((Tz) * (T30)));
    ci[(rs[9])] = (((Tw) * (T30)) + (Tz * T2X));
    cr[(rs[1])] = ((Tv * T31) - ((Ty) * (T32)));
    ci[(rs[1])] = (((Tv) * (T32)) + (Ty * T31));

    E T20, T26, T24, T28;
    E T1Y, T1Z, T22, T23;
    T1Y = T7 - Te;
    T1Z = T1U - T1T;
    T20 = T1Y - T1Z;
    T26 = T1Y + T1Z;
    T22 = T1Q - T1R;
    T23 = Tm - Tt;
    T24 = T22 - T23;
    T28 = T23 + T22;

    cr[(rs[12])] = ((T1X * T20) - ((T21) * (T24)));
    ci[(rs[12])] = (((T1X) * (T24)) + (T21 * T20));
    cr[(rs[4])] = ((T25 * T26) - ((T27) * (T28)));
    ci[(rs[4])] = (((T25) * (T28)) + (T27 * T26));
}
}
