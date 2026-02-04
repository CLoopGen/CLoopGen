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
for (m = mb , W = W + ((mb - 1) * 30); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 30 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T7, T2K, T2W, Tw, T17, T1S, T2k, T1w, Te, TD, T1x, T10, T2n, T2L, T1Z;
    E T2X, Tm, T1z, TN, T19, T2e, T2p, T2P, T2Z, Tt, T1A, TW, T1a, T27, T2q;
    E T2S, T30;

    // Variant 2: Eliminate some loop-carried dependencies by precomputing W values
    // and reordering computations to expose independent chains

    E W14 = W[14], W15 = W[15];
    E W20 = W[20], W21 = W[21];
    E W4 = W[4], W5 = W[5];
    E W12 = W[12], W13 = W[13];
    E W28 = W[28], W29 = W[29];
    E W18 = W[18], W19 = W[19];
    E W2 = W[2], W3 = W[3];
    E W26 = W[26], W27 = W[27];
    E W10 = W[10], W11 = W[11];
    E W24 = W[24], W25 = W[25];
    E W8 = W[8], W9 = W[9];
    E W16 = W[16], W17 = W[17];
    E W0 = W[0], W1 = W[1];
    E W22 = W[22], W23 = W[23];
    E W6 = W[6], W7 = W[7];

    // Reorder computation to remove artificial WAW dependencies on intermediate variables
    // by using distinct names per block (no reuse)

    {
        E T3, T1Q, T16, T1R, T6, T2i, T13, T2j;
        {
            E T1, T2, T14, T15;
            T1 = cr[0];
            T2 = ci[(rs[7])];
            T3 = T1 + T2;
            T1Q = T1 - T2;
            T14 = ci[(rs[11])];
            T15 = cr[(rs[12])];
            T16 = T14 - T15;
            T1R = T14 + T15;
        }
        {
            E T4, T5, T11, T12;
            T4 = cr[(rs[4])];
            T5 = ci[(rs[3])];
            T6 = T4 + T5;
            T2i = T4 - T5;
            T11 = ci[(rs[15])];
            T12 = cr[(rs[8])];
            T13 = T11 - T12;
            T2j = T11 + T12;
        }
        T7 = T3 + T6;
        T2K = T1Q + T1R;
        T2W = T2j - T2i;
        Tw = T3 - T6;
        T17 = T13 - T16;
        T1S = T1Q - T1R;
        T2k = T2i + T2j;
        T1w = T13 + T16;
    }

    {
        E Ta, T1T, TC, T1U, Td, T1W, Tz, T1X;
        {
            E T8, T9, TA, TB;
            T8 = cr[(rs[2])];
            T9 = ci[(rs[5])];
            Ta = T8 + T9;
            T1T = T8 - T9;
            TA = ci[(rs[13])];
            TB = cr[(rs[10])];
            TC = TA - TB;
            T1U = TA + TB;
        }
        {
            E Tb, Tc, Tx, Ty;
            Tb = ci[(rs[1])];
            Tc = cr[(rs[6])];
            Td = Tb + Tc;
            T1W = Tb - Tc;
            Tx = ci[(rs[9])];
            Ty = cr[(rs[14])];
            Tz = Tx - Ty;
            T1X = Tx + Ty;
        }
        Te = Ta + Td;
        TD = Tz - TC;
        T1x = TC + Tz;
        T10 = Ta - Td;

        {
            E T2l, T2m;
            T2l = T1T + T1U;
            T2m = T1W + T1X;
            T2n = KP707106781 * (T2l - T2m);
            T2L = KP707106781 * (T2l + T2m);
            T1Z = KP707106781 * ((T1T - T1U) + (T1W - T1X));
            T2X = KP707106781 * ((T1T - T1U) - (T1W - T1X));
        }
    }

    {
        E Ti, T2b, TL, T2c, Tl, T28, TI, T29, TF, TM;
        {
            E Tg, Th, TJ, TK;
            Tg = cr[(rs[1])];
            Th = ci[(rs[6])];
            Ti = Tg + Th;
            T2b = Tg - Th;
            TJ = ci[(rs[10])];
            TK = cr[(rs[13])];
            TL = TJ - TK;
            T2c = TJ + TK;
        }
        {
            E Tj, Tk, TG, TH;
            Tj = cr[(rs[5])];
            Tk = ci[(rs[2])];
            Tl = Tj + Tk;
            T28 = Tj - Tk;
            TG = ci[(rs[14])];
            TH = cr[(rs[9])];
            TI = TG - TH;
            T29 = TG + TH;
        }
        Tm = Ti + Tl;
        T1z = TI + TL;
        TF = Ti - Tl;
        TM = TI - TL;
        TN = TF - TM;
        T19 = TF + TM;

        {
            E T2a, T2d, T2N, T2O;
            T2a = T28 + T29;
            T2d = T2b - T2c;
            T2e = (((KP923879532) * (T2a)) + (KP382683432 * T2d));
            T2p = ((KP923879532 * T2d) - ((KP382683432) * (T2a)));
            T2N = T2b + T2c;
            T2O = T29 - T28;
            T2P = ((KP382683432 * T2N) - ((KP923879532) * (T2O)));
            T2Z = (((KP382683432) * (T2O)) + (KP923879532 * T2N));
        }
    }

    {
        E Tp, T24, TU, T25, Ts, T21, TR, T22, TO, TV;
        {
            E Tn, To, TS, TT;
            Tn = ci[0];
            To = cr[(rs[7])];
            Tp = Tn + To;
            T24 = Tn - To;
            TS = ci[(rs[12])];
            TT = cr[(rs[11])];
            TU = TS - TT;
            T25 = TS + TT;
        }
        {
            E Tq, Tr, TP, TQ;
            Tq = cr[(rs[3])];
            Tr = ci[(rs[4])];
            Ts = Tq + Tr;
            T21 = Tq - Tr;
            TP = ci[(rs[8])];
            TQ = cr[(rs[15])];
            TR = TP - TQ;
            T22 = TP + TQ;
        }
        Tt = Tp + Ts;
        T1A = TR + TU;
        TO = Tp - Ts;
        TV = TR - TU;
        TW = TO + TV;
        T1a = TV - TO;

        {
            E T23, T26, T2Q, T2R;
            T23 = T21 - T22;
            T26 = T24 - T25;
            T27 = ((KP923879532 * T23) - ((KP382683432) * (T26)));
            T2q = (((KP382683432) * (T23)) + (KP923879532 * T26));
            T2Q = T24 + T25;
            T2R = T21 + T22;
            T2S = ((KP382683432 * T2Q) - ((KP923879532) * (T2R)));
            T30 = (((KP382683432) * (T2R)) + (KP923879532 * T2Q));
        }
    }

    {
        E Tf, Tu, T1u, T1y, T1B, T1C;
        Tf = T7 + Te;
        Tu = Tm + Tt;
        T1u = Tf - Tu;
        T1y = T1w + T1x;
        T1B = T1z + T1A;
        T1C = T1y - T1B;
        cr[0] = Tf + Tu;
        ci[0] = T1y + T1B;
        cr[(rs[8])] = ((W14 * T1u) - (W15 * T1C));
        ci[(rs[8])] = ((W15 * T1u) + (W14 * T1C));
    }

    {
        E T2U, T34, T32, T36;
        {
            E T2M, T2T, T2Y, T31;
            T2M = T2K - T2L;
            T2T = T2P + T2S;
            T2U = T2M - T2T;
            T34 = T2M + T2T;
            T2Y = T2W + T2X;
            T31 = T2Z - T30;
            T32 = T2Y - T31;
            T36 = T2Y + T31;
        }
        cr[(rs[11])] = ((W20 * T2U) - (W21 * T32));
        ci[(rs[11])] = ((W21 * T2U) + (W20 * T32));
        cr[(rs[3])] = ((W4 * T34) - (W5 * T36));
        ci[(rs[3])] = ((W5 * T34) + (W4 * T36));
    }

    {
        E T3a, T3g, T3e, T3i;
        {
            E T38, T39, T3c, T3d;
            T38 = T2K + T2L;
            T39 = T2Z + T30;
            T3a = T38 - T39;
            T3g = T38 + T39;
            T3c = T2W - T2X;
            T3d = T2P - T2S;
            T3e = T3c + T3d;
            T3i = T3c - T3d;
        }
        cr[(rs[7])] = ((W12 * T3a) - (W13 * T3e));
        ci[(rs[7])] = ((W12 * T3e) + (W13 * T3a));
        cr[(rs[15])] = ((W28 * T3g) - (W29 * T3i));
        ci[(rs[15])] = ((W28 * T3i) + (W29 * T3g));
    }

    {
        E TY, T1e, T1c, T1g;
        {
            E TE, TX, T18, T1b;
            TE = Tw + TD;
            TX = KP707106781 * (TN + TW);
            TY = TE - TX;
            T1e = TE + TX;
            T18 = T10 + T17;
            T1b = KP707106781 * (T19 + T1a);
            T1c = T18 - T1b;
            T1g = T18 + T1b;
        }
        cr[(rs[10])] = ((W18 * TY) - (W19 * T1c));
        ci[(rs[10])] = ((W19 * TY) + (W18 * T1c));
        cr[(rs[2])] = ((W2 * T1e) - (W3 * T1g));
        ci[(rs[2])] = ((W3 * T1e) + (W2 * T1g));
    }

    {
        E T1k, T1q, T1o, T1s;
        {
            E T1i, T1j, T1m, T1n;
            T1i = Tw - TD;
            T1j = KP707106781 * (T1a - T19);
            T1k = T1i - T1j;
            T1q = T1i + T1j;
            T1m = T17 - T10;
            T1n = KP707106781 * (TN - TW);
            T1o = T1m - T1n;
            T1s = T1m + T1n;
        }
        cr[(rs[14])] = ((W26 * T1k) - (W27 * T1o));
        ci[(rs[14])] = ((W26 * T1o) + (W27 * T1k));
        cr[(rs[6])] = ((W10 * T1q) - (W11 * T1s));
        ci[(rs[6])] = ((W10 * T1s) + (W11 * T1q));
    }

    {
        E T2g, T2u, T2s, T2w;
        {
            E T20_val, T2f, T2o, T2r;
            T20_val = T1S - T1Z;
            T2f = T27 - T2e;
            T2g = T20_val - T2f;
            T2u = T20_val + T2f;
            T2o = T2k - T2n;
            T2r = T2p - T2q;
            T2s = T2o - T2r;
            T2w = T2o + T2r;
        }
        cr[(rs[13])] = ((W24 * T2g) - (W25 * T2s));
        ci[(rs[13])] = ((W25 * T2g) + (W24 * T2s));
        cr[(rs[5])] = ((W8 * T2u) - (W9 * T2w));
        ci[(rs[5])] = ((W9 * T2u) + (W8 * T2w));
    }

    {
        E T2A, T2G, T2E, T2I;
        {
            E T2y, T2z, T2C, T2D;
            T2y = T1S + T1Z;
            T2z = T2p + T2q;
            T2A = T2y - T2z;
            T2G = T2y + T2z;
            T2C = T2k + T2n;
            T2D = T2e + T27;
            T2E = T2C - T2D;
            T2I = T2C + T2D;
        }
        cr[(rs[9])] = ((W16 * T2A) - (W17 * T2E));
        ci[(rs[9])] = ((W16 * T2E) + (W17 * T2A));
        cr[(rs[1])] = ((W0 * T2G) - (W1 * T2I));
        ci[(rs[1])] = ((W0 * T2I) + (W1 * T2G));
    }

    {
        E T1G, T1M, T1K, T1O;
        {
            E T1E, T1F, T1I, T1J;
            T1E = T7 - Te;
            T1F = T1A - T1z;
            T1G = T1E - T1F;
            T1M = T1E + T1F;
            T1I = T1w - T1x;
            T1J = Tm - Tt;
            T1K = T1I - T1J;
            T1O = T1J + T1I;
        }
        cr[(rs[12])] = ((W22 * T1G) - (W23 * T1K));
        ci[(rs[12])] = ((W22 * T1K) + (W23 * T1G));
        cr[(rs[4])] = ((W6 * T1M) - (W7 * T1O));
        ci[(rs[4])] = ((W7 * T1M) + (W6 * T1O));
    }
}
}
