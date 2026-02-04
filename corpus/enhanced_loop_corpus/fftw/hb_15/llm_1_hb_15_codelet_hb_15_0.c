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
extern  E KP559016994;
extern  E KP250000000;
extern  E KP951056516;
extern  E KP587785252;
extern  E KP500000000;
extern  E KP866025403;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced loop nesting: the entire computation is now inlined without any additional control structure.
// The original single loop remains but all nested blocks are preserved as-is.
for (m = mb , W = W + ((mb - 1) * 28); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 28 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T5, T10, T1J, T2C, T2c, T2M, TH, T18, T17, TS, T2Q, T2R, T2S, Tg, Tr;
    E Ts, T11, T12, T13, T2N, T2O, T2P, T1u, T1x, T1y, T1W, T1Z, T28, T1P, T1S;
    E T27, T1B, T1E, T1F, T2G, T2H, T2I, T2D, T2E, T2F;
    {
        E T1, TW, T4, T2a, TZ, T1I, T1H, T2b;
        T1 = cr[0];
        TW = ci[(rs[14])];
        {
            E T2, T3, TX, TY;
            T2 = cr[(rs[5])];
            T3 = ci[(rs[4])];
            T4 = T2 + T3;
            T2a = KP866025403 * (T2 - T3);
            TX = ci[(rs[9])];
            TY = cr[(rs[10])];
            TZ = TX - TY;
            T1I = KP866025403 * (TX + TY);
        }
        T5 = T1 + T4;
        T10 = TW + TZ;
        T1H = ((T1) - ((KP500000000) * (T4)));
        T1J = T1H - T1I;
        T2C = T1H + T1I;
        T2b = ((TW) - ((KP500000000) * (TZ)));
        T2c = T2a + T2b;
        T2M = T2b - T2a;
    }
    {
        E Ta, T1N, T1s, Tl, T1U, T1z, Tf, T1Q, T1v, TG, T1R, T1w, Tq, T1X, T1C;
        E TM, T1V, T1A, TB, T1O, T1t, TR, T1Y, T1D;
        {
            E T6, T7, T8, T9;
            T6 = cr[(rs[3])];
            T7 = ci[(rs[6])];
            T8 = ci[(rs[1])];
            T9 = T7 + T8;
            Ta = T6 + T9;
            T1N = KP866025403 * (T7 - T8);
            T1s = ((T6) - ((KP500000000) * (T9)));
        }
        {
            E Th, Ti, Tj, Tk;
            Th = cr[(rs[6])];
            Ti = ci[(rs[3])];
            Tj = cr[(rs[1])];
            Tk = Ti + Tj;
            Tl = Th + Tk;
            T1U = KP866025403 * (Ti - Tj);
            T1z = ((Th) - ((KP500000000) * (Tk)));
        }
        {
            E Tb, Tc, Td, Te;
            Tb = ci[(rs[2])];
            Tc = cr[(rs[2])];
            Td = cr[(rs[7])];
            Te = Tc + Td;
            Tf = Tb + Te;
            T1Q = KP866025403 * (Tc - Td);
            T1v = ((Tb) - ((KP500000000) * (Te)));
        }
        {
            E TF, TC, TD, TE;
            TF = cr[(rs[12])];
            TC = ci[(rs[12])];
            TD = ci[(rs[7])];
            TE = TC + TD;
            TG = TE - TF;
            T1R = (((KP500000000) * (TE)) + (TF));
            T1w = KP866025403 * (TD - TC);
        }
        {
            E Tm, Tn, To, Tp;
            Tm = ci[(rs[5])];
            Tn = ci[0];
            To = cr[(rs[4])];
            Tp = Tn + To;
            Tq = Tm + Tp;
            T1X = KP866025403 * (Tn - To);
            T1C = ((Tm) - ((KP500000000) * (Tp)));
        }
        {
            E TI, TJ, TK, TL;
            TI = ci[(rs[8])];
            TJ = ci[(rs[13])];
            TK = cr[(rs[11])];
            TL = TJ - TK;
            TM = TI + TL;
            T1V = ((TI) - ((KP500000000) * (TL)));
            T1A = KP866025403 * (TJ + TK);
        }
        {
            E Tx, Ty, Tz, TA;
            Tx = ci[(rs[11])];
            Ty = cr[(rs[8])];
            Tz = cr[(rs[13])];
            TA = Ty + Tz;
            TB = Tx - TA;
            T1O = (((KP500000000) * (TA)) + (Tx));
            T1t = KP866025403 * (Ty - Tz);
        }
        {
            E TQ, TN, TO, TP;
            TQ = cr[(rs[9])];
            TN = ci[(rs[10])];
            TO = cr[(rs[14])];
            TP = TN - TO;
            TR = TP - TQ;
            T1Y = (((KP500000000) * (TP)) + (TQ));
            T1D = KP866025403 * (TN + TO);
        }
        TH = TB - TG;
        T18 = Tl - Tq;
        T17 = Ta - Tf;
        TS = TM - TR;
        T2Q = T1V - T1U;
        T2R = T1X + T1Y;
        T2S = T2Q - T2R;
        Tg = Ta + Tf;
        Tr = Tl + Tq;
        Ts = Tg + Tr;
        T11 = TB + TG;
        T12 = TM + TR;
        T13 = T11 + T12;
        T2N = T1O - T1N;
        T2O = T1Q + T1R;
        T2P = T2N - T2O;
        T1u = T1s + T1t;
        T1x = T1v + T1w;
        T1y = T1u + T1x;
        T1W = T1U + T1V;
        T1Z = T1X - T1Y;
        T28 = T1W + T1Z;
        T1P = T1N + T1O;
        T1S = T1Q - T1R;
        T27 = T1P + T1S;
        T1B = T1z + T1A;
        T1E = T1C + T1D;
        T1F = T1B + T1E;
        T2G = T1z - T1A;
        T2H = T1C - T1D;
        T2I = T2G + T2H;
        T2D = T1s - T1t;
        T2E = T1v - T1w;
        T2F = T2D + T2E;
    }
    cr[0] = T5 + Ts;
    ci[0] = T10 + T13;
    {
        E TT, T19, T1k, T1h, T16, T1l, Tw, T1g;
        TT = ((KP587785252 * TH) - ((KP951056516) * (TS)));
        T19 = ((KP587785252 * T17) - ((KP951056516) * (T18)));
        T1k = (((KP951056516) * (T17)) + (KP587785252 * T18));
        T1h = (((KP951056516) * (TH)) + (KP587785252 * TS));
        {
            E T14, T15, Tu, Tv;
            T14 = ((T10) - ((KP250000000) * (T13)));
            T15 = KP559016994 * (T11 - T12);
            T16 = T14 - T15;
            T1l = T15 + T14;
            Tu = ((T5) - ((KP250000000) * (Ts)));
            Tv = KP559016994 * (Tg - Tr);
            Tw = Tu - Tv;
            T1g = Tv + Tu;
        }
        {
            E TU, T1a, Tt, TV;
            TU = Tw + TT;
            T1a = T16 - T19;
            Tt = W[4];
            TV = W[5];
            cr[(rs[3])] = ((Tt * TU) - ((TV) * (T1a)));
            ci[(rs[3])] = (((TV) * (TU)) + (Tt * T1a));
        }
        {
            E T1o, T1q, T1n, T1p;
            T1o = T1g + T1h;
            T1q = T1l - T1k;
            T1n = W[16];
            T1p = W[17];
            cr[(rs[9])] = ((T1n * T1o) - ((T1p) * (T1q)));
            ci[(rs[9])] = (((T1p) * (T1o)) + (T1n * T1q));
        }
        {
            E T1c, T1e, T1b, T1d;
            T1c = Tw - TT;
            T1e = T19 + T16;
            T1b = W[22];
            T1d = W[23];
            cr[(rs[12])] = ((T1b * T1c) - ((T1d) * (T1e)));
            ci[(rs[12])] = (((T1d) * (T1c)) + (T1b * T1e));
        }
        {
            E T1i, T1m, T1f, T1j;
            T1i = T1g - T1h;
            T1m = T1k + T1l;
            T1f = W[10];
            T1j = W[11];
            cr[(rs[6])] = ((T1f * T1i) - ((T1j) * (T1m)));
            ci[(rs[6])] = (((T1j) * (T1i)) + (T1f * T1m));
        }
    }
    {
        E T21, T2n, T26, T2q, T1M, T2y, T2m, T2f, T2A, T2r, T2x, T2z;
        {
            E T1T, T20, T24, T25;
            T1T = T1P - T1S;
            T20 = T1W - T1Z;
            T21 = (((KP951056516) * (T1T)) + (KP587785252 * T20));
            T2n = ((KP587785252 * T1T) - ((KP951056516) * (T20)));
            T24 = T1u - T1x;
            T25 = T1B - T1E;
            T26 = (((KP951056516) * (T24)) + (KP587785252 * T25));
            T2q = ((KP587785252 * T24) - ((KP951056516) * (T25)));
        }
        {
            E T1G, T1K, T1L, T29, T2d, T2e;
            T1G = KP559016994 * (T1y - T1F);
            T1K = T1y + T1F;
            T1L = ((T1J) - ((KP250000000) * (T1K)));
            T1M = T1G + T1L;
            T2y = T1J + T1K;
            T2m = T1L - T1G;
            T29 = KP559016994 * (T27 - T28);
            T2d = T27 + T28;
            T2e = ((T2c) - ((KP250000000) * (T2d)));
            T2f = T29 + T2e;
            T2A = T2c + T2d;
            T2r = T2e - T29;
        }
        T2x = W[18];
        T2z = W[19];
        cr[(rs[10])] = ((T2x * T2y) - ((T2z) * (T2A)));
        ci[(rs[10])] = (((T2z) * (T2y)) + (T2x * T2A));
        {
            E T2u, T2w, T2t, T2v;
            T2u = T2m + T2n;
            T2w = T2r - T2q;
            T2t = W[24];
            T2v = W[25];
            cr[(rs[13])] = ((T2t * T2u) - ((T2v) * (T2w)));
            ci[(rs[13])] = (((T2v) * (T2u)) + (T2t * T2w));
        }
        {
            E T22, T2g, T1r, T23;
            T22 = T1M - T21;
            T2g = T26 + T2f;
            T1r = W[0];
            T23 = W[1];
            cr[(rs[1])] = ((T1r * T22) - ((T23) * (T2g)));
            ci[(rs[1])] = (((T23) * (T22)) + (T1r * T2g));
        }
        {
            E T2i, T2k, T2h, T2j;
            T2i = T1M + T21;
            T2k = T2f - T26;
            T2h = W[6];
            T2j = W[7];
            cr[(rs[4])] = ((T2h * T2i) - ((T2j) * (T2k)));
            ci[(rs[4])] = (((T2j) * (T2i)) + (T2h * T2k));
        }
        {
            E T2o, T2s, T2l, T2p;
            T2o = T2m - T2n;
            T2s = T2q + T2r;
            T2l = W[12];
            T2p = W[13];
            cr[(rs[7])] = ((T2l * T2o) - ((T2p) * (T2s)));
            ci[(rs[7])] = (((T2p) * (T2o)) + (T2l * T2s));
        }
    }
    {
        E T31, T3h, T36, T3k, T2K, T3g, T2Y, T2U, T3l, T39, T2B, T2L;
        {
            E T2Z, T30, T34, T35;
            T2Z = T2N + T2O;
            T30 = T2Q + T2R;
            T31 = ((KP587785252 * T2Z) - ((KP951056516) * (T30)));
            T3h = (((KP951056516) * (T2Z)) + (KP587785252 * T30));
            T34 = T2D - T2E;
            T35 = T2G - T2H;
            T36 = ((KP587785252 * T34) - ((KP951056516) * (T35)));
            T3k = (((KP951056516) * (T34)) + (KP587785252 * T35));
        }
        {
            E T2X, T2J, T2W, T38, T2T, T37;
            T2X = KP559016994 * (T2F - T2I);
            T2J = T2F + T2I;
            T2W = ((T2C) - ((KP250000000) * (T2J)));
            T2K = T2C + T2J;
            T3g = T2X + T2W;
            T2Y = T2W - T2X;
            T38 = KP559016994 * (T2P - T2S);
            T2T = T2P + T2S;
            T37 = ((T2M) - ((KP250000000) * (T2T)));
            T2U = T2M + T2T;
            T3l = T38 + T37;
            T39 = T37 - T38;
        }
        T2B = W[8];
        T2L = W[9];
        cr[(rs[5])] = ((T2B * T2K) - ((T2L) * (T2U)));
        ci[(rs[5])] = (((T2L) * (T2K)) + (T2B * T2U));
        {
            E T3o, T3q, T3n, T3p;
            T3o = T3g + T3h;
            T3q = T3l - T3k;
            T3n = W[26];
            T3p = W[27];
            cr[(rs[14])] = ((T3n * T3o) - ((T3p) * (T3q)));
            ci[(rs[14])] = (((T3n) * (T3q)) + (T3p * T3o));
        }
        {
            E T32, T3a, T2V, T33;
            T32 = T2Y - T31;
            T3a = T36 + T39;
            T2V = W[2];
            T33 = W[3];
            cr[(rs[2])] = ((T2V * T32) - ((T33) * (T3a)));
            ci[(rs[2])] = (((T2V) * (T3a)) + (T33 * T32));
        }
        {
            E T3c, T3e, T3b, T3d;
            T3c = T2Y + T31;
            T3e = T39 - T36;
            T3b = W[14];
            T3d = W[15];
            cr[(rs[8])] = ((T3b * T3c) - ((T3d) * (T3e)));
            ci[(rs[8])] = (((T3b) * (T3e)) + (T3d * T3c));
        }
        {
            E T3i, T3m, T3f, T3j;
            T3i = T3g - T3h;
            T3m = T3k + T3l;
            T3f = W[20];
            T3j = W[21];
            cr[(rs[11])] = ((T3f * T3i) - ((T3j) * (T3m)));
            ci[(rs[11])] = (((T3f) * (T3m)) + (T3j * T3i));
        }
    }
}
}
