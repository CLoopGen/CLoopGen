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
extern  E KP250000000;
extern  E KP559016994;
extern  E KP587785252;
extern  E KP951056516;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 38); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 38 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T7, T3T, T49, TE, T1v, T2T, T3g, T2d, T13, T3n, T3o, T1i, T26, T4e, T4d;
    E T23, T1n, T42, T3Z, T1m, T2h, T2I, T2i, T2P, T30, T37, T38, Tm, TB, TC;
    E T46, T47, T4a, T2a, T2b, T2e, T1w, T1x, T1y, T3O, T3R, T3U, T3h, T3i, T3j;
    E TH, TK, TL;

    // Introduce temporary arrays to break and restructure RAW/WAR dependencies
    E temp_cr[20], temp_ci[20];
    for (INT i = 0; i < 20; i++) {
        temp_cr[i] = cr[(rs[i])];
        temp_ci[i] = ci[(rs[i])];
    }

    {
        E T3, T2R, T1u, T2S, T6, T3f, T1r, T3e;
        {
            E T1, T2, T1s, T1t;
            T1 = temp_cr[0];
            T2 = temp_ci[9];
            T3 = T1 + T2;
            T2R = T1 - T2;
            T1s = temp_ci[14];
            T1t = temp_cr[15];
            T1u = T1s - T1t;
            T2S = T1s + T1t;
        }
        {
            E T4, T5, T1p, T1q;
            T4 = temp_cr[5];
            T5 = temp_ci[4];
            T6 = T4 + T5;
            T3f = T4 - T5;
            T1p = temp_ci[19];
            T1q = temp_cr[10];
            T1r = T1p - T1q;
            T3e = T1p + T1q;
        }
        T7 = T3 + T6;
        T3T = T2R - T2S;
        T49 = T3f + T3e;
        TE = T3 - T6;
        T1v = T1r - T1u;
        T2T = T2R + T2S;
        T3g = T3e - T3f;
        T2d = T1r + T1u;
    }
    {
        E Te, T3M, T3X, TF, TV, T2E, T2W, T21, TA, T3Q, T41, TJ, T1h, T2O, T36;
        E T25, Tl, T3N, T3Y, TG, T12, T2H, T2Z, T22, Tt, T3P, T40, TI, T1a, T2L;
        E T33, T24;
        {
            E Ta, T2U, TU, T2V, Td, T2D, TR, T2C;
            {
                E T8, T9, TS, TT;
                T8 = temp_cr[4];
                T9 = temp_ci[5];
                Ta = T8 + T9;
                T2U = T8 - T9;
                TS = temp_ci[10];
                TT = temp_cr[19];
                TU = TS - TT;
                T2V = TS + TT;
            }
            {
                E Tb, Tc, TP, TQ;
                Tb = temp_cr[9];
                Tc = temp_ci[0];
                Td = Tb + Tc;
                T2D = Tb - Tc;
                TP = temp_ci[15];
                TQ = temp_cr[14];
                TR = TP - TQ;
                T2C = TP + TQ;
            }
            Te = Ta + Td;
            T3M = T2U - T2V;
            T3X = T2D + T2C;
            TF = Ta - Td;
            TV = TR - TU;
            T2E = T2C - T2D;
            T2W = T2U + T2V;
            T21 = TR + TU;
        }
        {
            E Tw, T34, Tz, T2M, T1d, T2N, T1g, T35;
            {
                E Tu, Tv, Tx, Ty;
                Tu = temp_ci[7];
                Tv = temp_cr[2];
                Tw = Tu + Tv;
                T34 = Tu - Tv;
                Tx = temp_ci[2];
                Ty = temp_cr[7];
                Tz = Tx + Ty;
                T2M = Tx - Ty;
            }
            {
                E T1b, T1c, T1e, T1f;
                T1b = temp_ci[17];
                T1c = temp_cr[12];
                T1d = T1b - T1c;
                T2N = T1b + T1c;
                T1e = temp_ci[12];
                T1f = temp_cr[17];
                T1g = T1e - T1f;
                T35 = T1e + T1f;
            }
            TA = Tw + Tz;
            T3Q = T34 + T35;
            T41 = T2M - T2N;
            TJ = Tw - Tz;
            T1h = T1d - T1g;
            T2O = T2M + T2N;
            T36 = T34 - T35;
            T25 = T1d + T1g;
        }
        {
            E Th, T2X, T11, T2Y, Tk, T2F, TY, T2G;
            {
                E Tf, Tg, TZ, T10;
                Tf = temp_ci[3];
                Tg = temp_cr[6];
                Th = Tf + Tg;
                T2X = Tf - Tg;
                TZ = temp_ci[18];
                T10 = temp_cr[11];
                T11 = TZ - T10;
                T2Y = TZ + T10;
            }
            {
                E Ti, Tj, TW, TX;
                Ti = temp_cr[1];
                Tj = temp_ci[8];
                Tk = Ti + Tj;
                T2F = Ti - Tj;
                TW = temp_ci[13];
                TX = temp_cr[16];
                TY = TW - TX;
                T2G = TW + TX;
            }
            Tl = Th + Tk;
            T3N = T2X - T2Y;
            T3Y = T2F - T2G;
            TG = Th - Tk;
            T12 = TY - T11;
            T2H = T2F + T2G;
            T2Z = T2X + T2Y;
            T22 = TY + T11;
        }
        {
            E Tp, T31, T19, T32, Ts, T2K, T16, T2J;
            {
                E Tn, To, T17, T18;
                Tn = temp_cr[8];
                To = temp_ci[1];
                Tp = Tn + To;
                T31 = Tn - To;
                T17 = temp_ci[16];
                T18 = temp_cr[13];
                T19 = T17 - T18;
                T32 = T17 + T18;
            }
            {
                E Tq, Tr, T14, T15;
                Tq = temp_ci[6];
                Tr = temp_cr[3];
                Ts = Tq + Tr;
                T2K = Tq - Tr;
                T14 = temp_ci[11];
                T15 = temp_cr[18];
                T16 = T14 - T15;
                T2J = T14 + T15;
            }
            Tt = Tp + Ts;
            T3P = T31 + T32;
            T40 = T2K + T2J;
            TI = Tp - Ts;
            T1a = T16 - T19;
            T2L = T2J - T2K;
            T33 = T31 - T32;
            T24 = T16 + T19;
        }
        T13 = TV - T12;
        T3n = T2W - T2Z;
        T3o = T33 - T36;
        T1i = T1a - T1h;
        T26 = T24 - T25;
        T4e = T3P - T3Q;
        T4d = T3M - T3N;
        T23 = T21 - T22;
        T1n = TI - TJ;
        T42 = T40 - T41;
        T3Z = T3X - T3Y;
        T1m = TF - TG;
        T2h = Te - Tl;
        T2I = T2E + T2H;
        T2i = Tt - TA;
        T2P = T2L + T2O;
        T30 = T2W + T2Z;
        T37 = T33 + T36;
        T38 = T30 + T37;
        Tm = Te + Tl;
        TB = Tt + TA;
        TC = Tm + TB;
        T46 = T3X + T3Y;
        T47 = T40 + T41;
        T4a = T46 + T47;
        T2a = T21 + T22;
        T2b = T24 + T25;
        T2e = T2a + T2b;
        T1w = TV + T12;
        T1x = T1a + T1h;
        T1y = T1w + T1x;
        T3O = T3M + T3N;
        T3R = T3P + T3Q;
        T3U = T3O + T3R;
        T3h = T2E - T2H;
        T3i = T2L - T2O;
        T3j = T3h + T3i;
        TH = TF + TG;
        TK = TI + TJ;
        TL = TH + TK;
    }
    cr[0] = T7 + TC;
    ci[0] = T2d + T2e;

    {
        E T1U = TE + TL;
        E T1W = T1v + T1y;
        cr[(rs[10])] = (W[18] * T1U) - (W[19] * T1W);
        ci[(rs[10])] = (W[19] * T1U) + (W[18] * T1W);
    }
    {
        E T4y = T3T + T3U;
        E T4A = T49 + T4a;
        cr[(rs[5])] = (W[8] * T4y) - (W[9] * T4A);
        ci[(rs[5])] = (W[8] * T4A) + (W[9] * T4y);
    }
    {
        E T3I = T2T + T38;
        E T3K = T3g + T3j;
        cr[(rs[15])] = (W[28] * T3I) - (W[29] * T3K);
        ci[(rs[15])] = (W[28] * T3K) + (W[29] * T3I);
    }

    // Process remaining computations with reordered independent blocks to modify data flow
    {
        E T27 = (KP951056516 * T23) + (KP587785252 * T26);
        E T2j = (KP951056516 * T2h) + (KP587785252 * T2i);
        E T2v = (KP587785252 * T2h) - (KP951056516 * T2i);
        E T2r = (KP587785252 * T23) - (KP951056516 * T26);
        E T2c = KP559016994 * (T2a - T2b);
        E T2f = T2d - (KP250000000 * T2e);
        E T2g = T2c + T2f;
        E T2u = T2f - T2c;
        E T1Y = KP559016994 * (Tm - TB);
        E T1Z = T7 - (KP250000000 * TC);
        E T20 = T1Y + T1Z;
        E T2q = T1Z - T1Y;

        cr[(rs[4])] = (W[6] * (T20 + T27)) - (W[7] * (T2g - T2j));
        ci[(rs[4])] = (W[7] * (T20 + T27)) + (W[6] * (T2g - T2j));

        cr[(rs[12])] = (W[22] * (T2q - T2r)) - (W[23] * (T2v + T2u));
        ci[(rs[12])] = (W[23] * (T2q - T2r)) + (W[22] * (T2v + T2u));

        cr[(rs[16])] = (W[30] * (T20 - T27)) - (W[31] * (T2j + T2g));
        ci[(rs[16])] = (W[31] * (T20 - T27)) + (W[30] * (T2j + T2g));

        cr[(rs[8])] = (W[14] * (T2q + T2r)) - (W[15] * (T2u - T2v));
        ci[(rs[8])] = (W[15] * (T2q + T2r)) + (W[14] * (T2u - T2v));
    }

    {
        E T43 = (KP951056516 * T3Z) + (KP587785252 * T42);
        E T4f = (KP951056516 * T4d) + (KP587785252 * T4e);
        E T4r = (KP587785252 * T4d) - (KP951056516 * T4e);
        E T4m = (KP587785252 * T3Z) - (KP951056516 * T42);
        E T48 = KP559016994 * (T46 - T47);
        E T4b = T49 - (KP250000000 * T4a);
        E T4c = T48 + T4b;
        E T4q = T4b - T48;
        E T3S = KP559016994 * (T3O - T3R);
        E T3V = T3T - (KP250000000 * T3U);
        E T3W = T3S + T3V;
        E T4n = T3V - T3S;

        cr[(rs[1])] = (W[0] * (T3W - T43)) - (W[1] * (T4c + T4f));
        ci[(rs[1])] = (W[0] * (T4c + T4f)) + (W[1] * (T3W - T43));

        cr[(rs[17])] = (W[32] * (T4n - T4m)) - (W[33] * (T4q + T4r));
        ci[(rs[17])] = (W[32] * (T4q + T4r)) + (W[33] * (T4n - T4m));

        cr[(rs[9])] = (W[16] * (T43 + T3W)) - (W[17] * (T4c - T4f));
        ci[(rs[9])] = (W[16] * (T4c - T4f)) + (W[17] * (T43 + T3W));

        cr[(rs[13])] = (W[24] * (T4m + T4n)) - (W[25] * (T4q - T4r));
        ci[(rs[13])] = (W[24] * (T4q - T4r)) + (W[25] * (T4m + T4n));
    }

    {
        E T1j = (KP587785252 * T13) - (KP951056516 * T1i);
        E T1o = (KP587785252 * T1m) - (KP951056516 * T1n);
        E T1M = (KP951056516 * T1m) + (KP587785252 * T1n);
        E T1J = (KP951056516 * T13) + (KP587785252 * T1i);
        E T1z = T1v - (KP250000000 * T1y);
        E T1A = KP559016994 * (T1w - T1x);
        E T1B = T1z - T1A;
        E T1N = T1A + T1z;
        E TM = TE - (KP250000000 * TL);
        E TN = KP559016994 * (TH - TK);
        E TO = TM - TN;
        E T1I = TN + TM;

        cr[(rs[2])] = (W[2] * (TO - T1j)) - (W[3] * (T1o + T1B));
        ci[(rs[2])] = (W[3] * (TO - T1j)) + (W[2] * (T1o + T1B));

        cr[(rs[14])] = (W[26] * (T1I + T1J)) - (W[27] * (T1N - T1M));
        ci[(rs[14])] = (W[27] * (T1I + T1J)) + (W[26] * (T1N - T1M));

        cr[(rs[18])] = (W[34] * (TO + T1j)) - (W[35] * (T1B - T1o));
        ci[(rs[18])] = (W[35] * (TO + T1j)) + (W[34] * (T1B - T1o));

        cr[(rs[6])] = (W[10] * (T1I - T1J)) - (W[11] * (T1M + T1N));
        ci[(rs[6])] = (W[11] * (T1I - T1J)) + (W[10] * (T1M + T1N));
    }

    {
        E T2Q = (KP587785252 * T2I) - (KP951056516 * T2P);
        E T3p = (KP587785252 * T3n) - (KP951056516 * T3o);
        E T3B = (KP951056516 * T3n) + (KP587785252 * T3o);
        E T3x = (KP951056516 * T2I) + (KP587785252 * T2P);
        E T3k = T3g - (KP250000000 * T3j);
        E T3l = KP559016994 * (T3h - T3i);
        E T3m = T3k - T3l;
        E T3A = T3l + T3k;
        E T39 = T2T - (KP250000000 * T38);
        E T3a = KP559016994 * (T30 - T37);
        E T3b = T39 - T3a;
        E T3w = T3a + T39;

        cr[(rs[3])] = (W[4] * (T2Q + T3b)) - (W[5] * (T3m - T3p));
        ci[(rs[3])] = (W[4] * (T3m - T3p)) + (W[5] * (T2Q + T3b));

        cr[(rs[19])] = (W[36] * (T3x + T3w)) - (W[37] * (T3A - T3B));
        ci[(rs[19])] = (W[36] * (T3A - T3B)) + (W[37] * (T3x + T3w));

        cr[(rs[7])] = (W[12] * (T3b - T2Q)) - (W[13] * (T3m + T3p));
        ci[(rs[7])] = (W[12] * (T3m + T3p)) + (W[13] * (T3b - T2Q));

        cr[(rs[11])] = (W[20] * (T3w - T3x)) - (W[21] * (T3A + T3B));
        ci[(rs[11])] = (W[20] * (T3A + T3B)) + (W[21] * (T3w - T3x));
    }
}
}
