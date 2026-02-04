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
for (m = mb , W = W + (mb * 30); m < me; m = m + 1 , ri = ri + ms , ii = ii + ms , W = W + 30 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T7, T37, T1t, T2U, Ti, T38, T1w, T2R, Tu, T2s, T1C, T2c, TF, T2t, T1H;
    E T2d, T1f, T1q, T2B, T2C, T2D, T2E, T1Z, T2j, T24, T2k, TS, T13, T2w, T2x;
    E T2y, T2z, T1O, T2g, T1T, T2h;
    {
        E T1, T2T, T6, T2S;
        T1 = ri[0];
        T2T = ii[0];
        {
            E T3, T5, T2, T4;
            T3 = ri[(rs[8])];
            T5 = ii[(rs[8])];
            T2 = W[14];
            T4 = W[15];
            T6 = (((T2) * (T3)) + (T4 * T5));
            T2S = ((T2 * T5) - ((T4) * (T3)));
        }
        T7 = T1 + T6;
        T37 = T2T - T2S;
        T1t = T1 - T6;
        T2U = T2S + T2T;
    }
    {
        E Tc, T1u, Th, T1v;
        {
            E T9, Tb, T8, Ta;
            T9 = ri[(rs[4])];
            Tb = ii[(rs[4])];
            T8 = W[6];
            Ta = W[7];
            Tc = (((T8) * (T9)) + (Ta * Tb));
            T1u = ((T8 * Tb) - ((Ta) * (T9)));
        }
        {
            E Te, Tg, Td, Tf;
            Te = ri[(rs[12])];
            Tg = ii[(rs[12])];
            Td = W[22];
            Tf = W[23];
            Th = (((Td) * (Te)) + (Tf * Tg));
            T1v = ((Td * Tg) - ((Tf) * (Te)));
        }
        Ti = Tc + Th;
        T38 = Tc - Th;
        T1w = T1u - T1v;
        T2R = T1u + T1v;
    }
    {
        E To, T1y, Tt, T1z, T1A, T1B;
        {
            E Tl, Tn, Tk, Tm;
            Tl = ri[(rs[2])];
            Tn = ii[(rs[2])];
            Tk = W[2];
            Tm = W[3];
            To = (((Tk) * (Tl)) + (Tm * Tn));
            T1y = ((Tk * Tn) - ((Tm) * (Tl)));
        }
        {
            E Tq, Ts, Tp, Tr;
            Tq = ri[(rs[10])];
            Ts = ii[(rs[10])];
            Tp = W[18];
            Tr = W[19];
            Tt = (((Tp) * (Tq)) + (Tr * Ts));
            T1z = ((Tp * Ts) - ((Tr) * (Tq)));
        }
        Tu = To + Tt;
        T2s = T1y + T1z;
        T1A = T1y - T1z;
        T1B = To - Tt;
        T1C = T1A - T1B;
        T2c = T1B + T1A;
    }
    {
        E Tz, T1E, TE, T1F, T1D, T1G;
        {
            E Tw, Ty, Tv, Tx;
            Tw = ri[(rs[14])];
            Ty = ii[(rs[14])];
            Tv = W[26];
            Tx = W[27];
            Tz = (((Tv) * (Tw)) + (Tx * Ty));
            T1E = ((Tv * Ty) - ((Tx) * (Tw)));
        }
        {
            E TB, TD, TA, TC;
            TB = ri[(rs[6])];
            TD = ii[(rs[6])];
            TA = W[10];
            TC = W[11];
            TE = (((TA) * (TB)) + (TC * TD));
            T1F = ((TA * TD) - ((TC) * (TB)));
        }
        TF = Tz + TE;
        T2t = T1E + T1F;
        T1D = Tz - TE;
        T1G = T1E - T1F;
        T1H = T1D + T1G;
        T2d = T1D - T1G;
    }
    {
        E T19, T20, T1p, T1X, T1e, T21, T1k, T1W;
        {
            E T16, T18, T15, T17;
            T16 = ri[(rs[15])];
            T18 = ii[(rs[15])];
            T15 = W[28];
            T17 = W[29];
            T19 = (((T15) * (T16)) + (T17 * T18));
            T20 = ((T15 * T18) - ((T17) * (T16)));
        }
        {
            E T1m, T1o, T1l, T1n;
            T1m = ri[(rs[11])];
            T1o = ii[(rs[11])];
            T1l = W[20];
            T1n = W[21];
            T1p = (((T1l) * (T1m)) + (T1n * T1o));
            T1X = ((T1l * T1o) - ((T1n) * (T1m)));
        }
        {
            E T1b, T1d, T1a, T1c;
            T1b = ri[(rs[7])];
            T1d = ii[(rs[7])];
            T1a = W[12];
            T1c = W[13];
            T1e = (((T1a) * (T1b)) + (T1c * T1d));
            T21 = ((T1a * T1d) - ((T1c) * (T1b)));
        }
        {
            E T1h, T1j, T1g, T1i;
            T1h = ri[(rs[3])];
            T1j = ii[(rs[3])];
            T1g = W[4];
            T1i = W[5];
            T1k = (((T1g) * (T1h)) + (T1i * T1j));
            T1W = ((T1g * T1j) - ((T1i) * (T1h)));
        }
        T1f = T19 + T1e;
        T1q = T1k + T1p;
        T2B = T1f - T1q;
        T2C = T20 + T21;
        T2D = T1W + T1X;
        T2E = T2C - T2D;
        {
            E T1V, T1Y, T22, T23;
            T1V = T19 - T1e;
            T1Y = T1W - T1X;
            T1Z = T1V - T1Y;
            T2j = T1V + T1Y;
            T22 = T20 - T21;
            T23 = T1k - T1p;
            T24 = T22 + T23;
            T2k = T22 - T23;
        }
    }
    {
        E TM, T1K, T12, T1R, TR, T1L, TX, T1Q;
        {
            E TJ, TL, TI, TK;
            TJ = ri[(rs[1])];
            TL = ii[(rs[1])];
            TI = W[0];
            TK = W[1];
            TM = (((TI) * (TJ)) + (TK * TL));
            T1K = ((TI * TL) - ((TK) * (TJ)));
        }
        {
            E TZ, T11, TY, T10;
            TZ = ri[(rs[13])];
            T11 = ii[(rs[13])];
            TY = W[24];
            T10 = W[25];
            T12 = (((TY) * (TZ)) + (T10 * T11));
            T1R = ((TY * T11) - ((T10) * (TZ)));
        }
        {
            E TO, TQ, TN, TP;
            TO = ri[(rs[9])];
            TQ = ii[(rs[9])];
            TN = W[16];
            TP = W[17];
            TR = (((TN) * (TO)) + (TP * TQ));
            T1L = ((TN * TQ) - ((TP) * (TO)));
        }
        {
            E TU, TW, TT, TV;
            TU = ri[(rs[5])];
            TW = ii[(rs[5])];
            TT = W[8];
            TV = W[9];
            TX = (((TT) * (TU)) + (TV * TW));
            T1Q = ((TT * TW) - ((TV) * (TU)));
        }
        TS = TM + TR;
        T13 = TX + T12;
        T2w = TS - T13;
        T2x = T1K + T1L;
        T2y = T1Q + T1R;
        T2z = T2x - T2y;
        {
            E T1M, T1N, T1P, T1S;
            T1M = T1K - T1L;
            T1N = TX - T12;
            T1O = T1M + T1N;
            T2g = T1M - T1N;
            T1P = TM - TR;
            T1S = T1Q - T1R;
            T1T = T1P - T1S;
            T2h = T1P + T1S;
        }
    }
    {
        E T1J, T27, T3g, T3i, T26, T3h, T2a, T3d;
        {
            E T1x, T1I, T3e, T3f;
            T1x = T1t - T1w;
            T1I = KP707106781 * (T1C - T1H);
            T1J = T1x + T1I;
            T27 = T1x - T1I;
            T3e = KP707106781 * (T2d - T2c);
            T3f = T38 + T37;
            T3g = T3e + T3f;
            T3i = T3f - T3e;
        }
        {
            E T1U, T25, T28, T29;
            T1U = (((KP923879532) * (T1O)) + (KP382683432 * T1T));
            T25 = ((KP382683432 * T1Z) - ((KP923879532) * (T24)));
            T26 = T1U + T25;
            T3h = T25 - T1U;
            T28 = ((KP382683432 * T1O) - ((KP923879532) * (T1T)));
            T29 = (((KP382683432) * (T24)) + (KP923879532 * T1Z));
            T2a = T28 - T29;
            T3d = T28 + T29;
        }
        ri[(rs[11])] = T1J - T26;
        ii[(rs[11])] = T3g - T3d;
        ri[(rs[3])] = T1J + T26;
        ii[(rs[3])] = T3d + T3g;
        ri[(rs[15])] = T27 - T2a;
        ii[(rs[15])] = T3i - T3h;
        ri[(rs[7])] = T27 + T2a;
        ii[(rs[7])] = T3h + T3i;
    }
    {
        E T2v, T2H, T32, T34, T2G, T33, T2K, T2Z;
        {
            E T2r, T2u, T30, T31;
            T2r = T7 - Ti;
            T2u = T2s - T2t;
            T2v = T2r + T2u;
            T2H = T2r - T2u;
            T30 = TF - Tu;
            T31 = T2U - T2R;
            T32 = T30 + T31;
            T34 = T31 - T30;
        }
        {
            E T2A, T2F, T2I, T2J;
            T2A = T2w + T2z;
            T2F = T2B - T2E;
            T2G = KP707106781 * (T2A + T2F);
            T33 = KP707106781 * (T2F - T2A);
            T2I = T2z - T2w;
            T2J = T2B + T2E;
            T2K = KP707106781 * (T2I - T2J);
            T2Z = KP707106781 * (T2I + T2J);
        }
        ri[(rs[10])] = T2v - T2G;
        ii[(rs[10])] = T32 - T2Z;
        ri[(rs[2])] = T2v + T2G;
        ii[(rs[2])] = T2Z + T32;
        ri[(rs[14])] = T2H - T2K;
        ii[(rs[14])] = T34 - T33;
        ri[(rs[6])] = T2H + T2K;
        ii[(rs[6])] = T33 + T34;
    }
    {
        E T2f, T2n, T3a, T3c, T2m, T3b, T2q, T35;
        {
            E T2b, T2e, T36, T39;
            T2b = T1t + T1w;
            T2e = KP707106781 * (T2c + T2d);
            T2f = T2b + T2e;
            T2n = T2b - T2e;
            T36 = KP707106781 * (T1C + T1H);
            T39 = T37 - T38;
            T3a = T36 + T39;
            T3c = T39 - T36;
        }
        {
            E T2i, T2l, T2o, T2p;
            T2i = (((KP382683432) * (T2g)) + (KP923879532 * T2h));
            T2l = ((KP923879532 * T2j) - ((KP382683432) * (T2k)));
            T2m = T2i + T2l;
            T3b = T2l - T2i;
            T2o = ((KP923879532 * T2g) - ((KP382683432) * (T2h)));
            T2p = (((KP923879532) * (T2k)) + (KP382683432 * T2j));
            T2q = T2o - T2p;
            T35 = T2o + T2p;
        }
        ri[(rs[9])] = T2f - T2m;
        ii[(rs[9])] = T3a - T35;
        ri[(rs[1])] = T2f + T2m;
        ii[(rs[1])] = T35 + T3a;
        ri[(rs[13])] = T2n - T2q;
        ii[(rs[13])] = T3c - T3b;
        ri[(rs[5])] = T2n + T2q;
        ii[(rs[5])] = T3b + T3c;
    }
    {
        E TH, T2L, T2W, T2Y, T1s, T2X, T2O, T2P;
        {
            E Tj, TG, T2Q, T2V;
            Tj = T7 + Ti;
            TG = Tu + TF;
            TH = Tj + TG;
            T2L = Tj - TG;
            T2Q = T2s + T2t;
            T2V = T2R + T2U;
            T2W = T2Q + T2V;
            T2Y = T2V - T2Q;
        }
        {
            E T14, T1r, T2M, T2N;
            T14 = TS + T13;
            T1r = T1f + T1q;
            T1s = T14 + T1r;
            T2X = T1r - T14;
            T2M = T2x + T2y;
            T2N = T2C + T2D;
            T2O = T2M - T2N;
            T2P = T2M + T2N;
        }
        ri[(rs[8])] = TH - T1s;
        ii[(rs[8])] = T2W - T2P;
        ri[0] = TH + T1s;
        ii[0] = T2P + T2W;
        ri[(rs[12])] = T2L - T2O;
        ii[(rs[12])] = T2Y - T2X;
        ri[(rs[4])] = T2L + T2O;
        ii[(rs[4])] = T2X + T2Y;
    }
}

}
