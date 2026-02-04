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
extern  E KP382683432;
extern  E KP923879532;
extern  E KP707106781;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (m = mb , W = W + (mb * 8); m < me; m = m + 1 , ri = ri + ms , ii = ii + ms , W = W + 8 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T2, T5, Tg, Ti, Tk, To, TE, TC, T6, T3, T8, TW, TJ, Tt, TU;
    E Tc, Tx, TH, TN, TO, TP, TR, T1f, T1k, T1b, T1i, T1y, T1H, T1u, T1F;
    {
        E T7, Tv, Ta, Ts, T4, Tw, Tb, Tr;
        {
            E Th, Tn, Tj, Tm;
            T2 = W[0];
            T5 = W[1];
            Tg = W[2];
            Ti = W[3];
            Th = T2 * Tg;
            Tn = T5 * Tg;
            Tj = T5 * Ti;
            Tm = T2 * Ti;
            Tk = Th - Tj;
            To = Tm + Tn;
            TE = Tm - Tn;
            TC = Th + Tj;
            T6 = W[5];
            T7 = T5 * T6;
            Tv = Tg * T6;
            Ta = T2 * T6;
            Ts = Ti * T6;
            T3 = W[4];
            T4 = T2 * T3;
            Tw = Ti * T3;
            Tb = T5 * T3;
            Tr = Tg * T3;
        }
        T8 = T4 + T7;
        TW = Tv - Tw;
        TJ = Ta + Tb;
        Tt = Tr - Ts;
        TU = Tr + Ts;
        Tc = Ta - Tb;
        Tx = Tv + Tw;
        TH = T4 - T7;
        TN = W[6];
        TO = W[7];
        TP = (((T2) * (TN)) + (T5 * TO));
        TR = ((T2 * TO) - ((T5) * (TN)));
        {
            E T1d, T1e, T19, T1a;
            T1d = Tk * T6;
            T1e = To * T3;
            T1f = T1d - T1e;
            T1k = T1d + T1e;
            T19 = Tk * T3;
            T1a = To * T6;
            T1b = T19 + T1a;
            T1i = T19 - T1a;
        }
        {
            E T1w, T1x, T1s, T1t;
            T1w = TC * T6;
            T1x = TE * T3;
            T1y = T1w - T1x;
            T1H = T1w + T1x;
            T1s = TC * T3;
            T1t = TE * T6;
            T1u = T1s + T1t;
            T1F = T1s - T1t;
        }
    }
    {
        E Tf, T3r, T1N, T3e, TA, T3s, T1Q, T3b, TM, T2M, T1W, T2w, TZ, T2N, T21;
        E T2x, T1B, T1K, T2V, T2W, T2X, T2Y, T2j, T2D, T2o, T2E, T18, T1n, T2Q, T2R;
        E T2S, T2T, T28, T2A, T2d, T2B;
        {
            E T1, T3d, Te, T3c, T9, Td;
            T1 = ri[0];
            T3d = ii[0];
            T9 = ri[(rs[8])];
            Td = ii[(rs[8])];
            Te = (((T8) * (T9)) + (Tc * Td));
            T3c = ((T8 * Td) - ((Tc) * (T9)));
            Tf = T1 + Te;
            T3r = T3d - T3c;
            T1N = T1 - Te;
            T3e = T3c + T3d;
        }
        {
            E Tq, T1O, Tz, T1P;
            {
                E Tl, Tp, Tu, Ty;
                Tl = ri[(rs[4])];
                Tp = ii[(rs[4])];
                Tq = (((Tk) * (Tl)) + (To * Tp));
                T1O = ((Tk * Tp) - ((To) * (Tl)));
                Tu = ri[(rs[12])];
                Ty = ii[(rs[12])];
                Tz = (((Tt) * (Tu)) + (Tx * Ty));
                T1P = ((Tt * Ty) - ((Tx) * (Tu)));
            }
            TA = Tq + Tz;
            T3s = Tq - Tz;
            T1Q = T1O - T1P;
            T3b = T1O + T1P;
        }
        {
            E TG, T1S, TL, T1T, T1U, T1V;
            {
                E TD, TF, TI, TK;
                TD = ri[(rs[2])];
                TF = ii[(rs[2])];
                TG = (((TC) * (TD)) + (TE * TF));
                T1S = ((TC * TF) - ((TE) * (TD)));
                TI = ri[(rs[10])];
                TK = ii[(rs[10])];
                TL = (((TH) * (TI)) + (TJ * TK));
                T1T = ((TH * TK) - ((TJ) * (TI)));
            }
            TM = TG + TL;
            T2M = T1S + T1T;
            T1U = T1S - T1T;
            T1V = TG - TL;
            T1W = T1U - T1V;
            T2w = T1V + T1U;
        }
        {
            E TT, T1Y, TY, T1Z, T1X, T20;
            {
                E TQ, TS, TV, TX;
                TQ = ri[(rs[14])];
                TS = ii[(rs[14])];
                TT = (((TP) * (TQ)) + (TR * TS));
                T1Y = ((TP * TS) - ((TR) * (TQ)));
                TV = ri[(rs[6])];
                TX = ii[(rs[6])];
                TY = (((TU) * (TV)) + (TW * TX));
                T1Z = ((TU * TX) - ((TW) * (TV)));
            }
            TZ = TT + TY;
            T2N = T1Y + T1Z;
            T1X = TT - TY;
            T20 = T1Y - T1Z;
            T21 = T1X + T20;
            T2x = T1X - T20;
        }
        {
            E T1r, T2k, T1J, T2h, T1A, T2l, T1E, T2g;
            {
                E T1p, T1q, T1G, T1I;
                T1p = ri[(rs[15])];
                T1q = ii[(rs[15])];
                T1r = (((TN) * (T1p)) + (TO * T1q));
                T2k = ((TN * T1q) - ((TO) * (T1p)));
                T1G = ri[(rs[11])];
                T1I = ii[(rs[11])];
                T1J = (((T1F) * (T1G)) + (T1H * T1I));
                T2h = ((T1F * T1I) - ((T1H) * (T1G)));
            }
            {
                E T1v, T1z, T1C, T1D;
                T1v = ri[(rs[7])];
                T1z = ii[(rs[7])];
                T1A = (((T1u) * (T1v)) + (T1y * T1z));
                T2l = ((T1u * T1z) - ((T1y) * (T1v)));
                T1C = ri[(rs[3])];
                T1D = ii[(rs[3])];
                T1E = (((Tg) * (T1C)) + (Ti * T1D));
                T2g = ((Tg * T1D) - ((Ti) * (T1C)));
            }
            T1B = T1r + T1A;
            T1K = T1E + T1J;
            T2V = T1B - T1K;
            T2W = T2k + T2l;
            T2X = T2g + T2h;
            T2Y = T2W - T2X;
            {
                E T2f, T2i, T2m, T2n;
                T2f = T1r - T1A;
                T2i = T2g - T2h;
                T2j = T2f - T2i;
                T2D = T2f + T2i;
                T2m = T2k - T2l;
                T2n = T1E - T1J;
                T2o = T2m + T2n;
                T2E = T2m - T2n;
            }
        }
        {
            E T14, T24, T1m, T2b, T17, T25, T1h, T2a;
            {
                E T12, T13, T1j, T1l;
                T12 = ri[(rs[1])];
                T13 = ii[(rs[1])];
                T14 = (((T2) * (T12)) + (T5 * T13));
                T24 = ((T2 * T13) - ((T5) * (T12)));
                T1j = ri[(rs[13])];
                T1l = ii[(rs[13])];
                T1m = (((T1i) * (T1j)) + (T1k * T1l));
                T2b = ((T1i * T1l) - ((T1k) * (T1j)));
            }
            {
                E T15, T16, T1c, T1g;
                T15 = ri[(rs[9])];
                T16 = ii[(rs[9])];
                T17 = (((T3) * (T15)) + (T6 * T16));
                T25 = ((T3 * T16) - ((T6) * (T15)));
                T1c = ri[(rs[5])];
                T1g = ii[(rs[5])];
                T1h = (((T1b) * (T1c)) + (T1f * T1g));
                T2a = ((T1b * T1g) - ((T1f) * (T1c)));
            }
            T18 = T14 + T17;
            T1n = T1h + T1m;
            T2Q = T18 - T1n;
            T2R = T24 + T25;
            T2S = T2a + T2b;
            T2T = T2R - T2S;
            {
                E T26, T27, T29, T2c;
                T26 = T24 - T25;
                T27 = T1h - T1m;
                T28 = T26 + T27;
                T2A = T26 - T27;
                T29 = T14 - T17;
                T2c = T2a - T2b;
                T2d = T29 - T2c;
                T2B = T29 + T2c;
            }
        }
        {
            E T23, T2r, T3A, T3C, T2q, T3B, T2u, T3x;
            {
                E T1R, T22, T3y, T3z;
                T1R = T1N - T1Q;
                T22 = KP707106781 * (T1W - T21);
                T23 = T1R + T22;
                T2r = T1R - T22;
                T3y = KP707106781 * (T2x - T2w);
                T3z = T3s + T3r;
                T3A = T3y + T3z;
                T3C = T3z - T3y;
            }
            {
                E T2e, T2p, T2s, T2t;
                T2e = (((KP923879532) * (T28)) + (KP382683432 * T2d));
                T2p = ((KP382683432 * T2j) - ((KP923879532) * (T2o)));
                T2q = T2e + T2p;
                T3B = T2p - T2e;
                T2s = ((KP382683432 * T28) - ((KP923879532) * (T2d)));
                T2t = (((KP382683432) * (T2o)) + (KP923879532 * T2j));
                T2u = T2s - T2t;
                T3x = T2s + T2t;
            }
            ri[(rs[11])] = T23 - T2q;
            ii[(rs[11])] = T3A - T3x;
            ri[(rs[3])] = T23 + T2q;
            ii[(rs[3])] = T3x + T3A;
            ri[(rs[15])] = T2r - T2u;
            ii[(rs[15])] = T3C - T3B;
            ri[(rs[7])] = T2r + T2u;
            ii[(rs[7])] = T3B + T3C;
        }
        {
            E T2P, T31, T3m, T3o, T30, T3n, T34, T3j;
            {
                E T2L, T2O, T3k, T3l;
                T2L = Tf - TA;
                T2O = T2M - T2N;
                T2P = T2L + T2O;
                T31 = T2L - T2O;
                T3k = TZ - TM;
                T3l = T3e - T3b;
                T3m = T3k + T3l;
                T3o = T3l - T3k;
            }
            {
                E T2U, T2Z, T32, T33;
                T2U = T2Q + T2T;
                T2Z = T2V - T2Y;
                T30 = KP707106781 * (T2U + T2Z);
                T3n = KP707106781 * (T2Z - T2U);
                T32 = T2T - T2Q;
                T33 = T2V + T2Y;
                T34 = KP707106781 * (T32 - T33);
                T3j = KP707106781 * (T32 + T33);
            }
            ri[(rs[10])] = T2P - T30;
            ii[(rs[10])] = T3m - T3j;
            ri[(rs[2])] = T2P + T30;
            ii[(rs[2])] = T3j + T3m;
            ri[(rs[14])] = T31 - T34;
            ii[(rs[14])] = T3o - T3n;
            ri[(rs[6])] = T31 + T34;
            ii[(rs[6])] = T3n + T3o;
        }
        {
            E T2z, T2H, T3u, T3w, T2G, T3v, T2K, T3p;
            {
                E T2v, T2y, T3q, T3t;
                T2v = T1N + T1Q;
                T2y = KP707106781 * (T2w + T2x);
                T2z = T2v + T2y;
                T2H = T2v - T2y;
                T3q = KP707106781 * (T1W + T21);
                T3t = T3r - T3s;
                T3u = T3q + T3t;
                T3w = T3t - T3q;
            }
            {
                E T2C, T2F, T2I, T2J;
                T2C = (((KP382683432) * (T2A)) + (KP923879532 * T2B));
                T2F = ((KP923879532 * T2D) - ((KP382683432) * (T2E)));
                T2G = T2C + T2F;
                T3v = T2F - T2C;
                T2I = ((KP923879532 * T2A) - ((KP382683432) * (T2B)));
                T2J = (((KP923879532) * (T2E)) + (KP382683432 * T2D));
                T2K = T2I - T2J;
                T3p = T2I + T2J;
            }
            ri[(rs[9])] = T2z - T2G;
            ii[(rs[9])] = T3u - T3p;
            ri[(rs[1])] = T2z + T2G;
            ii[(rs[1])] = T3p + T3u;
            ri[(rs[13])] = T2H - T2K;
            ii[(rs[13])] = T3w - T3v;
            ri[(rs[5])] = T2H + T2K;
            ii[(rs[5])] = T3v + T3w;
        }
        {
            E T11, T35, T3g, T3i, T1M, T3h, T38, T39;
            {
                E TB, T10, T3a, T3f;
                TB = Tf + TA;
                T10 = TM + TZ;
                T11 = TB + T10;
                T35 = TB - T10;
                T3a = T2M + T2N;
                T3f = T3b + T3e;
                T3g = T3a + T3f;
                T3i = T3f - T3a;
            }
            {
                E T1o, T1L, T36, T37;
                T1o = T18 + T1n;
                T1L = T1B + T1K;
                T1M = T1o + T1L;
                T3h = T1L - T1o;
                T36 = T2R + T2S;
                T37 = T2W + T2X;
                T38 = T36 - T37;
                T39 = T36 + T37;
            }
            ri[(rs[8])] = T11 - T1M;
            ii[(rs[8])] = T3g - T39;
            ri[0] = T11 + T1M;
            ii[0] = T39 + T3g;
            ri[(rs[12])] = T35 - T38;
            ii[(rs[12])] = T3i - T3h;
            ri[(rs[4])] = T35 + T38;
            ii[(rs[4])] = T3h + T3i;
        }
    }
}

}
