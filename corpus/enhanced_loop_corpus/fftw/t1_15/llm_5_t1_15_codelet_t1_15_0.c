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
extern  E KP500000000;
extern  E KP866025403;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + (mb * 28); m < me; m = m + 1 , ri = ri + ms , ii = ii + ms , W = W + 28 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1q, T34, Td, T1n, T2S, T35, T13, T1k, T1l, T2E, T2F, T2O, T1H, T1T, T2k;
    E T2t, T2f, T2s, T1M, T1U, Tu, TL, TM, T2H, T2I, T2N, T1w, T1Q, T29, T2w;
    E T24, T2v, T1B, T1R;

    // Control dependency: Early exit on specific index condition
    if (m == (mb + 2)) {
        ri[0] = 0.0;
        ii[0] = 0.0;
        continue;
    }

    {
        E T1, T2R, T6, T1o, Tb, T1p, Tc, T2Q;
        T1 = ri[0];
        T2R = ii[0];
        {
            E T3, T5, T2, T4;
            T3 = ri[(rs[5])];
            T5 = ii[(rs[5])];
            T2 = W[8];
            T4 = W[9];
            T6 = (((T2) * (T3)) + (T4 * T5));
            T1o = ((T2 * T5) - ((T4) * (T3)));
        }
        {
            E T8, Ta, T7, T9;
            T8 = ri[(rs[10])];
            Ta = ii[(rs[10])];
            T7 = W[18];
            T9 = W[19];
            Tb = (((T7) * (T8)) + (T9 * Ta));
            T1p = ((T7 * Ta) - ((T9) * (T8)));
        }
        T1q = KP866025403 * (T1o - T1p);
        T34 = KP866025403 * (Tb - T6);
        Tc = T6 + Tb;
        Td = T1 + Tc;
        T1n = ((T1) - ((KP500000000) * (Tc)));
        T2Q = T1o + T1p;
        T2S = T2Q + T2R;
        T35 = ((T2R) - ((KP500000000) * (T2Q)));
    }

    // Conditional block execution based on stride value
    if (rs[0] > 0) {
        E TR, T2c, T18, T2h, TW, T1E, T11, T1F, T12, T2d, T1d, T1J, T1i, T1K, T1j;
        E T2i;
        {
            E TO, TQ, TN, TP;
            TO = ri[(rs[6])];
            TQ = ii[(rs[6])];
            TN = W[10];
            TP = W[11];
            TR = (((TN) * (TO)) + (TP * TQ));
            T2c = ((TN * TQ) - ((TP) * (TO)));
        }
        {
            E T15, T17, T14, T16;
            T15 = ri[(rs[9])];
            T17 = ii[(rs[9])];
            T14 = W[16];
            T16 = W[17];
            T18 = (((T14) * (T15)) + (T16 * T17));
            T2h = ((T14 * T17) - ((T16) * (T15)));
        }
        {
            E TT, TV, TS, TU;
            TT = ri[(rs[11])];
            TV = ii[(rs[11])];
            TS = W[20];
            TU = W[21];
            TW = (((TS) * (TT)) + (TU * TV));
            T1E = ((TS * TV) - ((TU) * (TT)));
        }
        {
            E TY, T10, TX, TZ;
            TY = ri[(rs[1])];
            T10 = ii[(rs[1])];
            TX = W[0];
            TZ = W[1];
            T11 = (((TX) * (TY)) + (TZ * T10));
            T1F = ((TX * T10) - ((TZ) * (TY)));
        }
        T12 = TW + T11;
        T2d = T1E + T1F;
        {
            E T1a, T1c, T19, T1b;
            T1a = ri[(rs[14])];
            T1c = ii[(rs[14])];
            T19 = W[26];
            T1b = W[27];
            T1d = (((T19) * (T1a)) + (T1b * T1c));
            T1J = ((T19 * T1c) - ((T1b) * (T1a)));
        }
        {
            E T1f, T1h, T1e, T1g;
            T1f = ri[(rs[4])];
            T1h = ii[(rs[4])];
            T1e = W[6];
            T1g = W[7];
            T1i = (((T1e) * (T1f)) + (T1g * T1h));
            T1K = ((T1e * T1h) - ((T1g) * (T1f)));
        }
        T1j = T1d + T1i;
        T2i = T1J + T1K;
        {
            E T1D, T1G, T2g, T2j;
            T13 = TR + T12;
            T1k = T18 + T1j;
            T1l = T13 + T1k;
            T2E = T2c + T2d;
            T2F = T2h + T2i;
            T2O = T2E + T2F;
            T1D = ((TR) - ((KP500000000) * (T12)));
            T1G = KP866025403 * (T1E - T1F);
            T1H = T1D - T1G;
            T1T = T1D + T1G;
            T2g = KP866025403 * (T1i - T1d);
            T2j = ((T2h) - ((KP500000000) * (T2i)));
            T2k = T2g + T2j;
            T2t = T2j - T2g;
            {
                E T2b, T2e, T1I, T1L;
                T2b = KP866025403 * (T11 - TW);
                T2e = ((T2c) - ((KP500000000) * (T2d)));
                T2f = T2b + T2e;
                T2s = T2e - T2b;
                T1I = ((T18) - ((KP500000000) * (T1j)));
                T1L = KP866025403 * (T1J - T1K);
                T1M = T1I - T1L;
                T1U = T1I + T1L;
            }
        }
    } else {
        // Fallback initialization to prevent undefined behavior
        T13 = T1k = T1l = T2E = T2F = T2O = T1H = T1T = T2k = T2t = T2f = T2s = T1M = T1U = 0.0;
    }

    {
        E Ti, T21, Tz, T26, Tn, T1t, Ts, T1u, Tt, T22, TE, T1y, TJ, T1z, TK;
        E T27;
        {
            E Tf, Th, Te, Tg;
            Tf = ri[(rs[3])];
            Th = ii[(rs[3])];
            Te = W[4];
            Tg = W[5];
            Ti = (((Te) * (Tf)) + (Tg * Th));
            T21 = ((Te * Th) - ((Tg) * (Tf)));
        }
        {
            E Tw, Ty, Tv, Tx;
            Tw = ri[(rs[12])];
            Ty = ii[(rs[12])];
            Tv = W[22];
            Tx = W[23];
            Tz = (((Tv) * (Tw)) + (Tx * Ty));
            T26 = ((Tv * Ty) - ((Tx) * (Tw)));
        }
        {
            E Tk, Tm, Tj, Tl;
            Tk = ri[(rs[8])];
            Tm = ii[(rs[8])];
            Tj = W[14];
            Tl = W[15];
            Tn = (((Tj) * (Tk)) + (Tl * Tm));
            T1t = ((Tj * Tm) - ((Tl) * (Tk)));
        }
        {
            E Tp, Tr, To, Tq;
            Tp = ri[(rs[13])];
            Tr = ii[(rs[13])];
            To = W[24];
            Tq = W[25];
            Ts = (((To) * (Tp)) + (Tq * Tr));
            T1u = ((To * Tr) - ((Tq) * (Tp)));
        }
        Tt = Tn + Ts;
        T22 = T1t + T1u;
        {
            E TB, TD, TA, TC;
            TB = ri[(rs[2])];
            TD = ii[(rs[2])];
            TA = W[2];
            TC = W[3];
            TE = (((TA) * (TB)) + (TC * TD));
            T1y = ((TA * TD) - ((TC) * (TB)));
        }
        {
            E TG, TI, TF, TH;
            TG = ri[(rs[7])];
            TI = ii[(rs[7])];
            TF = W[12];
            TH = W[13];
            TJ = (((TF) * (TG)) + (TH * TI));
            T1z = ((TF * TI) - ((TH) * (TG)));
        }
        TK = TE + TJ;
        T27 = T1y + T1z;
        {
            E T1s, T1v, T25, T28;
            Tu = Ti + Tt;
            TL = Tz + TK;
            TM = Tu + TL;
            T2H = T21 + T22;
            T2I = T26 + T27;
            T2N = T2H + T2I;
            T1s = ((Ti) - ((KP500000000) * (Tt)));
            T1v = KP866025403 * (T1t - T1u);
            T1w = T1s - T1v;
            T1Q = T1s + T1v;
            T25 = KP866025403 * (TJ - TE);
            T28 = ((T26) - ((KP500000000) * (T27)));
            T29 = T25 + T28;
            T2w = T28 - T25;
            {
                E T20, T23, T1x, T1A;
                T20 = KP866025403 * (Ts - Tn);
                T23 = ((T21) - ((KP500000000) * (T22)));
                T24 = T20 + T23;
                T2v = T23 - T20;
                T1x = ((Tz) - ((KP500000000) * (TK)));
                T1A = KP866025403 * (T1y - T1z);
                T1B = T1x - T1A;
                T1R = T1x + T1A;
            }
        }
    }

    // Conditional computation of final stages based on accumulated values
    if (TM > T1l) {
        E T2C, T1m, T2B, T2K, T2M, T2G, T2J, T2L, T2D;
        T2C = KP559016994 * (TM - T1l);
        T1m = TM + T1l;
        T2B = ((Td) - ((KP250000000) * (T1m)));
        T2G = T2E - T2F;
        T2J = T2H - T2I;
        T2K = ((KP951056516 * T2G) - ((KP587785252) * (T2J)));
        T2M = (((KP951056516) * (T2J)) + (KP587785252 * T2G));
        ri[0] = Td + T1m;
        T2L = T2C + T2B;
        ri[(rs[9])] = T2L - T2M;
        ri[(rs[6])] = T2L + T2M;
        T2D = T2B - T2C;
        ri[(rs[12])] = T2D - T2K;
        ri[(rs[3])] = T2D + T2K;
    } else {
        ri[0] = Td;
        ri[(rs[3])] = ri[(rs[6])] = ri[(rs[9])] = ri[(rs[12])] = 0.0;
    }

    {
        E T2U, T2P, T2T, T2Y, T30, T2W, T2X, T2Z, T2V;
        T2U = KP559016994 * (T2N - T2O);
        T2P = T2N + T2O;
        T2T = ((T2S) - ((KP250000000) * (T2P)));
        T2W = T13 - T1k;
        T2X = Tu - TL;
        T2Y = ((KP951056516 * T2W) - ((KP587785252) * (T2X)));
        T30 = (((KP951056516) * (T2X)) + (KP587785252 * T2W));
        ii[0] = T2P + T2S;
        T2Z = T2U + T2T;
        ii[(rs[6])] = T2Z - T30;
        ii[(rs[9])] = T30 + T2Z;
        T2V = T2T - T2U;
        ii[(rs[3])] = T2V - T2Y;
        ii[(rs[12])] = T2Y + T2V;
    }

    // Final blocks remain unconditional for correctness
    {
        E T2y, T2A, T1r, T1O, T2p, T2q, T2z, T2r;
        {
            E T2u, T2x, T1C, T1N;
            T2u = T2s - T2t;
            T2x = T2v - T2w;
            T2y = ((KP951056516 * T2u) - ((KP587785252) * (T2x)));
            T2A = (((KP951056516) * (T2x)) + (KP587785252 * T2u));
            T1r = T1n - T1q;
            T1C = T1w + T1B;
            T1N = T1H + T1M;
            T1O = T1C + T1N;
            T2p = ((T1r) - ((KP250000000) * (T1O)));
            T2q = KP559016994 * (T1C - T1N);
        }
        ri[(rs[5])] = T1r + T1O;
        T2z = T2q + T2p;
        ri[(rs[14])] = T2z - T2A;
        ri[(rs[11])] = T2z + T2A;
        T2r = T2p - T2q;
        ri[(rs[2])] = T2r - T2y;
        ri[(rs[8])] = T2r + T2y;
    }
    {
        E T3h, T3q, T3i, T3l, T3m, T3n, T3p, T3o;
        {
            E T3f, T3g, T3j, T3k;
            T3f = T1H - T1M;
            T3g = T1w - T1B;
            T3h = ((KP951056516 * T3f) - ((KP587785252) * (T3g)));
            T3q = (((KP951056516) * (T3g)) + (KP587785252 * T3f));
            T3i = T35 - T34;
            T3j = T2v + T2w;
            T3k = T2s + T2t;
            T3l = T3j + T3k;
            T3m = ((T3i) - ((KP250000000) * (T3l)));
            T3n = KP559016994 * (T3j - T3k);
        }
        ii[(rs[5])] = T3l + T3i;
        T3p = T3n + T3m;
        ii[(rs[11])] = T3p - T3q;
        ii[(rs[14])] = T3q + T3p;
        T3o = T3m - T3n;
        ii[(rs[2])] = T3h + T3o;
        ii[(rs[8])] = T3o - T3h;
    }
    {
        E T3c, T3d, T36, T37, T33, T38, T3e, T39;
        {
            E T3a, T3b, T31, T32;
            T3a = T1Q - T1R;
            T3b = T1T - T1U;
            T3c = (((KP951056516) * (T3a)) + (KP587785252 * T3b));
            T3d = ((KP951056516 * T3b) - ((KP587785252) * (T3a)));
            T36 = T34 + T35;
            T31 = T24 + T29;
            T32 = T2f + T2k;
            T37 = T31 + T32;
            T33 = KP559016994 * (T31 - T32);
            T38 = ((T36) - ((KP250000000) * (T37)));
        }
        ii[(rs[10])] = T37 + T36;
        T3e = T38 - T33;
        ii[(rs[7])] = T3d + T3e;
        ii[(rs[13])] = T3e - T3d;
        T39 = T33 + T38;
        ii[(rs[1])] = T39 - T3c;
        ii[(rs[4])] = T3c + T39;
    }
    {
        E T2m, T2o, T1P, T1W, T1X, T1Y, T2n, T1Z;
        {
            E T2a, T2l, T1S, T1V;
            T2a = T24 - T29;
            T2l = T2f - T2k;
            T2m = (((KP951056516) * (T2a)) + (KP587785252 * T2l));
            T2o = ((KP951056516 * T2l) - ((KP587785252) * (T2a)));
            T1P = T1n + T1q;
            T1S = T1Q + T1R;
            T1V = T1T + T1U;
            T1W = T1S + T1V;
            T1X = KP559016994 * (T1S - T1V);
            T1Y = ((T1P) - ((KP250000000) * (T1W)));
        }
        ri[(rs[10])] = T1P + T1W;
        T2n = T1Y - T1X;
        ri[(rs[7])] = T2n - T2o;
        ri[(rs[13])] = T2n + T2o;
        T1Z = T1X + T1Y;
        ri[(rs[4])] = T1Z - T2m;
        ri[(rs[1])] = T1Z + T2m;
    }
}
}
