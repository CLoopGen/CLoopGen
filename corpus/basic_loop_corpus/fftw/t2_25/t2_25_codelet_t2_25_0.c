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
extern  E KP998026728;
extern  E KP062790519;
extern  E KP425779291;
extern  E KP904827052;
extern  E KP992114701;
extern  E KP125333233;
extern  E KP637423989;
extern  E KP770513242;
extern  E KP684547105;
extern  E KP728968627;
extern  E KP481753674;
extern  E KP876306680;
extern  E KP844327925;
extern  E KP535826794;
extern  E KP248689887;
extern  E KP968583161;
extern  E KP587785252;
extern  E KP951056516;
extern  E KP250000000;
extern  E KP559016994;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (m = mb , W = W + (mb * 8); m < me; m = m + 1 , ri = ri + ms , ii = ii + ms , W = W + 8 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T2, T5, T3, T6, T8, Td, T16, T14, Te, T9, T21, T23, Tx, TR, T1g;
    E TB, T1f, TV, T1Q, Tg, T1S, Tk, T18, T2s, T1c, T2q, Tn, To, Tp, Tr;
    E T28, T2x, TY, T2k, T2m, T2v, TG, TE, T10, T1h, T1E, T26, T1B, T1G, T1V;
    E T1X, T1z, T1j;
    {
        E Tw, TT, Tz, TQ, Tv, TU, TA, TP;
        {
            E T4, Tc, T7, Tb;
            T2 = W[0];
            T5 = W[1];
            T3 = W[2];
            T6 = W[3];
            T4 = T2 * T3;
            Tc = T5 * T3;
            T7 = T5 * T6;
            Tb = T2 * T6;
            T8 = T4 - T7;
            Td = Tb + Tc;
            T16 = Tb - Tc;
            T14 = T4 + T7;
            Te = W[5];
            Tw = T5 * Te;
            TT = T3 * Te;
            Tz = T2 * Te;
            TQ = T6 * Te;
            T9 = W[4];
            Tv = T2 * T9;
            TU = T6 * T9;
            TA = T5 * T9;
            TP = T3 * T9;
        }
        T21 = TP - TQ;
        T23 = TT + TU;
        {
            E T15, T17, Ta, Tf, T1a, T1b, Ti, Tj;
            Tx = Tv - Tw;
            TR = TP + TQ;
            T1g = Tz - TA;
            TB = Tz + TA;
            T1f = Tv + Tw;
            TV = TT - TU;
            T15 = T14 * T9;
            T17 = T16 * Te;
            T1Q = T15 + T17;
            Ta = T8 * T9;
            Tf = Td * Te;
            Tg = Ta + Tf;
            T1a = T14 * Te;
            T1b = T16 * T9;
            T1S = T1a - T1b;
            Ti = T8 * Te;
            Tj = Td * T9;
            Tk = Ti - Tj;
            T18 = T15 - T17;
            T2s = Ti + Tj;
            T1c = T1a + T1b;
            T2q = Ta - Tf;
            Tn = W[6];
            To = W[7];
            Tp = (((T8) * (Tn)) + (Td * To));
            Tr = ((T8 * To) - ((Td) * (Tn)));
            T28 = ((T1Q * To) - ((T1S) * (Tn)));
            T2x = ((TR * To) - ((TV) * (Tn)));
            TY = (((T3) * (Tn)) + (T6 * To));
            T2k = (((T2) * (Tn)) + (T5 * To));
            T2m = ((T2 * To) - ((T5) * (Tn)));
            T2v = (((TR) * (Tn)) + (TV * To));
            TG = ((T9 * To) - ((Te) * (Tn)));
            TE = (((T9) * (Tn)) + (Te * To));
            T10 = ((T3 * To) - ((T6) * (Tn)));
            T1h = (((T1f) * (Tn)) + (T1g * To));
            T1E = (((Tg) * (Tn)) + (Tk * To));
            T26 = (((T1Q) * (Tn)) + (T1S * To));
            T1B = ((Tx * To) - ((TB) * (Tn)));
            T1G = ((Tg * To) - ((Tk) * (Tn)));
            T1V = (((T14) * (Tn)) + (T16 * To));
            T1X = ((T14 * To) - ((T16) * (Tn)));
            T1z = (((Tx) * (Tn)) + (TB * To));
            T1j = ((T1f * To) - ((T1g) * (Tn)));
        }
    }
    {
        E T1, T6v, T2F, T6I, TK, T2G, T6u, T6J, T6N, T7c, T2O, T52, T2C, T6k, T48;
        E T5X, T4L, T5s, T4j, T5W, T4K, T5v, T1o, T6g, T30, T5M, T4A, T56, T3b, T5N;
        E T4B, T59, T1L, T6h, T3n, T5Q, T4D, T5g, T3y, T5P, T4E, T5d, T2d, T6j, T3L;
        E T5T, T4I, T5l, T3W, T5U, T4H, T5o;
        {
            E Tm, T2I, Tt, T2J, Tu, T6s, TD, T2L, TI, T2M, TJ, T6t;
            T1 = ri[0];
            T6v = ii[0];
            {
                E Th, Tl, Tq, Ts;
                Th = ri[(rs[5])];
                Tl = ii[(rs[5])];
                Tm = (((Tg) * (Th)) + (Tk * Tl));
                T2I = ((Tg * Tl) - ((Tk) * (Th)));
                Tq = ri[(rs[20])];
                Ts = ii[(rs[20])];
                Tt = (((Tp) * (Tq)) + (Tr * Ts));
                T2J = ((Tp * Ts) - ((Tr) * (Tq)));
            }
            Tu = Tm + Tt;
            T6s = T2I + T2J;
            {
                E Ty, TC, TF, TH;
                Ty = ri[(rs[10])];
                TC = ii[(rs[10])];
                TD = (((Tx) * (Ty)) + (TB * TC));
                T2L = ((Tx * TC) - ((TB) * (Ty)));
                TF = ri[(rs[15])];
                TH = ii[(rs[15])];
                TI = (((TE) * (TF)) + (TG * TH));
                T2M = ((TE * TH) - ((TG) * (TF)));
            }
            TJ = TD + TI;
            T6t = T2L + T2M;
            T2F = KP559016994 * (Tu - TJ);
            T6I = KP559016994 * (T6s - T6t);
            TK = Tu + TJ;
            T2G = ((T1) - ((KP250000000) * (TK)));
            T6u = T6s + T6t;
            T6J = ((T6v) - ((KP250000000) * (T6u)));
            {
                E T6L, T6M, T2K, T2N;
                T6L = Tm - Tt;
                T6M = TD - TI;
                T6N = (((KP951056516) * (T6L)) + (KP587785252 * T6M));
                T7c = ((KP951056516 * T6M) - ((KP587785252) * (T6L)));
                T2K = T2I - T2J;
                T2N = T2L - T2M;
                T2O = (((KP951056516) * (T2K)) + (KP587785252 * T2N));
                T52 = ((KP951056516 * T2N) - ((KP587785252) * (T2K)));
            }
        }
        {
            E T2g, T4c, T43, T46, T4h, T4g, T49, T4a, T4d, T2p, T2A, T2B, T2e, T2f;
            T2e = ri[(rs[3])];
            T2f = ii[(rs[3])];
            T2g = (((T3) * (T2e)) + (T6 * T2f));
            T4c = ((T3 * T2f) - ((T6) * (T2e)));
            {
                E T2j, T41, T2z, T45, T2o, T42, T2u, T44;
                {
                    E T2h, T2i, T2w, T2y;
                    T2h = ri[(rs[8])];
                    T2i = ii[(rs[8])];
                    T2j = (((T1f) * (T2h)) + (T1g * T2i));
                    T41 = ((T1f * T2i) - ((T1g) * (T2h)));
                    T2w = ri[(rs[18])];
                    T2y = ii[(rs[18])];
                    T2z = (((T2v) * (T2w)) + (T2x * T2y));
                    T45 = ((T2v * T2y) - ((T2x) * (T2w)));
                }
                {
                    E T2l, T2n, T2r, T2t;
                    T2l = ri[(rs[23])];
                    T2n = ii[(rs[23])];
                    T2o = (((T2k) * (T2l)) + (T2m * T2n));
                    T42 = ((T2k * T2n) - ((T2m) * (T2l)));
                    T2r = ri[(rs[13])];
                    T2t = ii[(rs[13])];
                    T2u = (((T2q) * (T2r)) + (T2s * T2t));
                    T44 = ((T2q * T2t) - ((T2s) * (T2r)));
                }
                T43 = T41 - T42;
                T46 = T44 - T45;
                T4h = T2u - T2z;
                T4g = T2j - T2o;
                T49 = T41 + T42;
                T4a = T44 + T45;
                T4d = T49 + T4a;
                T2p = T2j + T2o;
                T2A = T2u + T2z;
                T2B = T2p + T2A;
            }
            T2C = T2g + T2B;
            T6k = T4c + T4d;
            {
                E T47, T5r, T40, T5q, T3Y, T3Z;
                T47 = (((KP951056516) * (T43)) + (KP587785252 * T46));
                T5r = ((KP951056516 * T46) - ((KP587785252) * (T43)));
                T3Y = KP559016994 * (T2p - T2A);
                T3Z = ((T2g) - ((KP250000000) * (T2B)));
                T40 = T3Y + T3Z;
                T5q = T3Z - T3Y;
                T48 = T40 + T47;
                T5X = T5q + T5r;
                T4L = T40 - T47;
                T5s = T5q - T5r;
            }
            {
                E T4i, T5t, T4f, T5u, T4b, T4e;
                T4i = (((KP951056516) * (T4g)) + (KP587785252 * T4h));
                T5t = ((KP951056516 * T4h) - ((KP587785252) * (T4g)));
                T4b = KP559016994 * (T49 - T4a);
                T4e = ((T4c) - ((KP250000000) * (T4d)));
                T4f = T4b + T4e;
                T5u = T4e - T4b;
                T4j = T4f - T4i;
                T5W = T5u - T5t;
                T4K = T4i + T4f;
                T5v = T5t + T5u;
            }
        }
        {
            E TO, T34, T2V, T2Y, T39, T38, T31, T32, T35, T13, T1m, T1n, TM, TN;
            TM = ri[(rs[1])];
            TN = ii[(rs[1])];
            TO = (((T2) * (TM)) + (T5 * TN));
            T34 = ((T2 * TN) - ((T5) * (TM)));
            {
                E TX, T2T, T1l, T2X, T12, T2U, T1e, T2W;
                {
                    E TS, TW, T1i, T1k;
                    TS = ri[(rs[6])];
                    TW = ii[(rs[6])];
                    TX = (((TR) * (TS)) + (TV * TW));
                    T2T = ((TR * TW) - ((TV) * (TS)));
                    T1i = ri[(rs[16])];
                    T1k = ii[(rs[16])];
                    T1l = (((T1h) * (T1i)) + (T1j * T1k));
                    T2X = ((T1h * T1k) - ((T1j) * (T1i)));
                }
                {
                    E TZ, T11, T19, T1d;
                    TZ = ri[(rs[21])];
                    T11 = ii[(rs[21])];
                    T12 = (((TY) * (TZ)) + (T10 * T11));
                    T2U = ((TY * T11) - ((T10) * (TZ)));
                    T19 = ri[(rs[11])];
                    T1d = ii[(rs[11])];
                    T1e = (((T18) * (T19)) + (T1c * T1d));
                    T2W = ((T18 * T1d) - ((T1c) * (T19)));
                }
                T2V = T2T - T2U;
                T2Y = T2W - T2X;
                T39 = T1e - T1l;
                T38 = TX - T12;
                T31 = T2T + T2U;
                T32 = T2W + T2X;
                T35 = T31 + T32;
                T13 = TX + T12;
                T1m = T1e + T1l;
                T1n = T13 + T1m;
            }
            T1o = TO + T1n;
            T6g = T34 + T35;
            {
                E T2Z, T55, T2S, T54, T2Q, T2R;
                T2Z = (((KP951056516) * (T2V)) + (KP587785252 * T2Y));
                T55 = ((KP951056516 * T2Y) - ((KP587785252) * (T2V)));
                T2Q = KP559016994 * (T13 - T1m);
                T2R = ((TO) - ((KP250000000) * (T1n)));
                T2S = T2Q + T2R;
                T54 = T2R - T2Q;
                T30 = T2S + T2Z;
                T5M = T54 + T55;
                T4A = T2S - T2Z;
                T56 = T54 - T55;
            }
            {
                E T3a, T57, T37, T58, T33, T36;
                T3a = (((KP951056516) * (T38)) + (KP587785252 * T39));
                T57 = ((KP951056516 * T39) - ((KP587785252) * (T38)));
                T33 = KP559016994 * (T31 - T32);
                T36 = ((T34) - ((KP250000000) * (T35)));
                T37 = T33 + T36;
                T58 = T36 - T33;
                T3b = T37 - T3a;
                T5N = T58 - T57;
                T4B = T3a + T37;
                T59 = T57 + T58;
            }
        }
        {
            E T1r, T3r, T3i, T3l, T3w, T3v, T3o, T3p, T3s, T1y, T1J, T1K, T1p, T1q;
            T1p = ri[(rs[4])];
            T1q = ii[(rs[4])];
            T1r = (((T8) * (T1p)) + (Td * T1q));
            T3r = ((T8 * T1q) - ((Td) * (T1p)));
            {
                E T1u, T3g, T1I, T3k, T1x, T3h, T1D, T3j;
                {
                    E T1s, T1t, T1F, T1H;
                    T1s = ri[(rs[9])];
                    T1t = ii[(rs[9])];
                    T1u = (((T9) * (T1s)) + (Te * T1t));
                    T3g = ((T9 * T1t) - ((Te) * (T1s)));
                    T1F = ri[(rs[19])];
                    T1H = ii[(rs[19])];
                    T1I = (((T1E) * (T1F)) + (T1G * T1H));
                    T3k = ((T1E * T1H) - ((T1G) * (T1F)));
                }
                {
                    E T1v, T1w, T1A, T1C;
                    T1v = ri[(rs[24])];
                    T1w = ii[(rs[24])];
                    T1x = (((Tn) * (T1v)) + (To * T1w));
                    T3h = ((Tn * T1w) - ((To) * (T1v)));
                    T1A = ri[(rs[14])];
                    T1C = ii[(rs[14])];
                    T1D = (((T1z) * (T1A)) + (T1B * T1C));
                    T3j = ((T1z * T1C) - ((T1B) * (T1A)));
                }
                T3i = T3g - T3h;
                T3l = T3j - T3k;
                T3w = T1D - T1I;
                T3v = T1u - T1x;
                T3o = T3g + T3h;
                T3p = T3j + T3k;
                T3s = T3o + T3p;
                T1y = T1u + T1x;
                T1J = T1D + T1I;
                T1K = T1y + T1J;
            }
            T1L = T1r + T1K;
            T6h = T3r + T3s;
            {
                E T3m, T5f, T3f, T5e, T3d, T3e;
                T3m = (((KP951056516) * (T3i)) + (KP587785252 * T3l));
                T5f = ((KP951056516 * T3l) - ((KP587785252) * (T3i)));
                T3d = KP559016994 * (T1y - T1J);
                T3e = ((T1r) - ((KP250000000) * (T1K)));
                T3f = T3d + T3e;
                T5e = T3e - T3d;
                T3n = T3f + T3m;
                T5Q = T5e + T5f;
                T4D = T3f - T3m;
                T5g = T5e - T5f;
            }
            {
                E T3x, T5b, T3u, T5c, T3q, T3t;
                T3x = (((KP951056516) * (T3v)) + (KP587785252 * T3w));
                T5b = ((KP951056516 * T3w) - ((KP587785252) * (T3v)));
                T3q = KP559016994 * (T3o - T3p);
                T3t = ((T3r) - ((KP250000000) * (T3s)));
                T3u = T3q + T3t;
                T5c = T3t - T3q;
                T3y = T3u - T3x;
                T5P = T5c - T5b;
                T4E = T3x + T3u;
                T5d = T5b + T5c;
            }
        }
        {
            E T1P, T3P, T3G, T3J, T3U, T3T, T3M, T3N, T3Q, T20, T2b, T2c, T1N, T1O;
            T1N = ri[(rs[2])];
            T1O = ii[(rs[2])];
            T1P = (((T14) * (T1N)) + (T16 * T1O));
            T3P = ((T14 * T1O) - ((T16) * (T1N)));
            {
                E T1U, T3E, T2a, T3I, T1Z, T3F, T25, T3H;
                {
                    E T1R, T1T, T27, T29;
                    T1R = ri[(rs[7])];
                    T1T = ii[(rs[7])];
                    T1U = (((T1Q) * (T1R)) + (T1S * T1T));
                    T3E = ((T1Q * T1T) - ((T1S) * (T1R)));
                    T27 = ri[(rs[17])];
                    T29 = ii[(rs[17])];
                    T2a = (((T26) * (T27)) + (T28 * T29));
                    T3I = ((T26 * T29) - ((T28) * (T27)));
                }
                {
                    E T1W, T1Y, T22, T24;
                    T1W = ri[(rs[22])];
                    T1Y = ii[(rs[22])];
                    T1Z = (((T1V) * (T1W)) + (T1X * T1Y));
                    T3F = ((T1V * T1Y) - ((T1X) * (T1W)));
                    T22 = ri[(rs[12])];
                    T24 = ii[(rs[12])];
                    T25 = (((T21) * (T22)) + (T23 * T24));
                    T3H = ((T21 * T24) - ((T23) * (T22)));
                }
                T3G = T3E - T3F;
                T3J = T3H - T3I;
                T3U = T25 - T2a;
                T3T = T1U - T1Z;
                T3M = T3E + T3F;
                T3N = T3H + T3I;
                T3Q = T3M + T3N;
                T20 = T1U + T1Z;
                T2b = T25 + T2a;
                T2c = T20 + T2b;
            }
            T2d = T1P + T2c;
            T6j = T3P + T3Q;
            {
                E T3K, T5k, T3D, T5j, T3B, T3C;
                T3K = (((KP951056516) * (T3G)) + (KP587785252 * T3J));
                T5k = ((KP951056516 * T3J) - ((KP587785252) * (T3G)));
                T3B = KP559016994 * (T20 - T2b);
                T3C = ((T1P) - ((KP250000000) * (T2c)));
                T3D = T3B + T3C;
                T5j = T3C - T3B;
                T3L = T3D + T3K;
                T5T = T5j + T5k;
                T4I = T3D - T3K;
                T5l = T5j - T5k;
            }
            {
                E T3V, T5m, T3S, T5n, T3O, T3R;
                T3V = (((KP951056516) * (T3T)) + (KP587785252 * T3U));
                T5m = ((KP951056516 * T3U) - ((KP587785252) * (T3T)));
                T3O = KP559016994 * (T3M - T3N);
                T3R = ((T3P) - ((KP250000000) * (T3Q)));
                T3S = T3O + T3R;
                T5n = T3R - T3O;
                T3W = T3S - T3V;
                T5U = T5n - T5m;
                T4H = T3V + T3S;
                T5o = T5m + T5n;
            }
        }
        {
            E T6m, T6o, TL, T2E, T6d, T6e, T6n, T6f;
            {
                E T6i, T6l, T1M, T2D;
                T6i = T6g - T6h;
                T6l = T6j - T6k;
                T6m = (((KP951056516) * (T6i)) + (KP587785252 * T6l));
                T6o = ((KP951056516 * T6l) - ((KP587785252) * (T6i)));
                TL = T1 + TK;
                T1M = T1o + T1L;
                T2D = T2d + T2C;
                T2E = T1M + T2D;
                T6d = KP559016994 * (T1M - T2D);
                T6e = ((TL) - ((KP250000000) * (T2E)));
            }
            ri[0] = TL + T2E;
            T6n = T6e - T6d;
            ri[(rs[10])] = T6n - T6o;
            ri[(rs[15])] = T6n + T6o;
            T6f = T6d + T6e;
            ri[(rs[20])] = T6f - T6m;
            ri[(rs[5])] = T6f + T6m;
        }
        {
            E T6C, T6D, T6w, T6r, T6x, T6y, T6E, T6z;
            {
                E T6A, T6B, T6p, T6q;
                T6A = T1o - T1L;
                T6B = T2d - T2C;
                T6C = (((KP951056516) * (T6A)) + (KP587785252 * T6B));
                T6D = ((KP951056516 * T6B) - ((KP587785252) * (T6A)));
                T6w = T6u + T6v;
                T6p = T6g + T6h;
                T6q = T6j + T6k;
                T6r = T6p + T6q;
                T6x = KP559016994 * (T6p - T6q);
                T6y = ((T6w) - ((KP250000000) * (T6r)));
            }
            ii[0] = T6r + T6w;
            T6E = T6y - T6x;
            ii[(rs[10])] = T6D + T6E;
            ii[(rs[15])] = T6E - T6D;
            T6z = T6x + T6y;
            ii[(rs[5])] = T6z - T6C;
            ii[(rs[20])] = T6C + T6z;
        }
        {
            E T2P, T4z, T6O, T70, T4m, T6T, T4n, T6S, T4U, T71, T4X, T6Z, T4O, T75, T4P;
            E T74, T4s, T6P, T4v, T6H, T2H, T6K;
            T2H = T2F + T2G;
            T2P = T2H + T2O;
            T4z = T2H - T2O;
            T6K = T6I + T6J;
            T6O = T6K - T6N;
            T70 = T6N + T6K;
            {
                E T3c, T3z, T3A, T3X, T4k, T4l;
                T3c = (((KP968583161) * (T30)) + (KP248689887 * T3b));
                T3z = (((KP535826794) * (T3n)) + (KP844327925 * T3y));
                T3A = T3c + T3z;
                T3X = (((KP876306680) * (T3L)) + (KP481753674 * T3W));
                T4k = (((KP728968627) * (T48)) + (KP684547105 * T4j));
                T4l = T3X + T4k;
                T4m = T3A + T4l;
                T6T = T3X - T4k;
                T4n = KP559016994 * (T3A - T4l);
                T6S = T3c - T3z;
            }
            {
                E T4S, T4T, T6X, T4V, T4W, T6Y;
                T4S = ((KP535826794 * T4B) - ((KP844327925) * (T4A)));
                T4T = ((KP770513242 * T4D) - ((KP637423989) * (T4E)));
                T6X = T4S + T4T;
                T4V = (((KP125333233) * (T4L)) + (KP992114701 * T4K));
                T4W = (((KP904827052) * (T4I)) + (KP425779291 * T4H));
                T6Y = T4W + T4V;
                T4U = T4S - T4T;
                T71 = KP559016994 * (T6X + T6Y);
                T4X = T4V - T4W;
                T6Z = T6X - T6Y;
            }
            {
                E T4C, T4F, T4G, T4J, T4M, T4N;
                T4C = (((KP535826794) * (T4A)) + (KP844327925 * T4B));
                T4F = (((KP637423989) * (T4D)) + (KP770513242 * T4E));
                T4G = T4C - T4F;
                T4J = ((KP904827052 * T4H) - ((KP425779291) * (T4I)));
                T4M = ((KP125333233 * T4K) - ((KP992114701) * (T4L)));
                T4N = T4J + T4M;
                T4O = T4G + T4N;
                T75 = T4J - T4M;
                T4P = KP559016994 * (T4G - T4N);
                T74 = T4C + T4F;
            }
            {
                E T4q, T4r, T6F, T4t, T4u, T6G;
                T4q = ((KP968583161 * T3b) - ((KP248689887) * (T30)));
                T4r = ((KP535826794 * T3y) - ((KP844327925) * (T3n)));
                T6F = T4q + T4r;
                T4t = ((KP876306680 * T3W) - ((KP481753674) * (T3L)));
                T4u = ((KP728968627 * T4j) - ((KP684547105) * (T48)));
                T6G = T4t + T4u;
                T4s = T4q - T4r;
                T6P = KP559016994 * (T6F - T6G);
                T4v = T4t - T4u;
                T6H = T6F + T6G;
            }
            ri[(rs[1])] = T2P + T4m;
            ii[(rs[1])] = T6H + T6O;
            ri[(rs[4])] = T4z + T4O;
            ii[(rs[4])] = T6Z + T70;
            {
                E T4w, T4y, T4p, T4x, T4o;
                T4w = (((KP951056516) * (T4s)) + (KP587785252 * T4v));
                T4y = ((KP951056516 * T4v) - ((KP587785252) * (T4s)));
                T4o = ((T2P) - ((KP250000000) * (T4m)));
                T4p = T4n + T4o;
                T4x = T4o - T4n;
                ri[(rs[21])] = T4p - T4w;
                ri[(rs[16])] = T4x + T4y;
                ri[(rs[6])] = T4p + T4w;
                ri[(rs[11])] = T4x - T4y;
            }
            {
                E T6U, T6V, T6R, T6W, T6Q;
                T6U = (((KP951056516) * (T6S)) + (KP587785252 * T6T));
                T6V = ((KP951056516 * T6T) - ((KP587785252) * (T6S)));
                T6Q = ((T6O) - ((KP250000000) * (T6H)));
                T6R = T6P + T6Q;
                T6W = T6Q - T6P;
                ii[(rs[6])] = T6R - T6U;
                ii[(rs[16])] = T6W - T6V;
                ii[(rs[21])] = T6U + T6R;
                ii[(rs[11])] = T6V + T6W;
            }
            {
                E T4Y, T50, T4R, T4Z, T4Q;
                T4Y = (((KP951056516) * (T4U)) + (KP587785252 * T4X));
                T50 = ((KP951056516 * T4X) - ((KP587785252) * (T4U)));
                T4Q = ((T4z) - ((KP250000000) * (T4O)));
                T4R = T4P + T4Q;
                T4Z = T4Q - T4P;
                ri[(rs[24])] = T4R - T4Y;
                ri[(rs[19])] = T4Z + T50;
                ri[(rs[9])] = T4R + T4Y;
                ri[(rs[14])] = T4Z - T50;
            }
            {
                E T76, T77, T73, T78, T72;
                T76 = (((KP951056516) * (T74)) + (KP587785252 * T75));
                T77 = ((KP951056516 * T75) - ((KP587785252) * (T74)));
                T72 = ((T70) - ((KP250000000) * (T6Z)));
                T73 = T71 + T72;
                T78 = T72 - T71;
                ii[(rs[9])] = T73 - T76;
                ii[(rs[19])] = T78 - T77;
                ii[(rs[24])] = T76 + T73;
                ii[(rs[14])] = T77 + T78;
            }
        }
        {
            E T53, T5L, T7e, T7q, T5y, T7j, T5z, T7i, T66, T7r, T69, T7p, T60, T7v, T61;
            E T7u, T5E, T7f, T5H, T7b, T51, T7d;
            T51 = T2G - T2F;
            T53 = T51 - T52;
            T5L = T51 + T52;
            T7d = T6J - T6I;
            T7e = T7c + T7d;
            T7q = T7d - T7c;
            {
                E T5a, T5h, T5i, T5p, T5w, T5x;
                T5a = (((KP876306680) * (T56)) + (KP481753674 * T59));
                T5h = ((KP904827052 * T5d) - ((KP425779291) * (T5g)));
                T5i = T5a + T5h;
                T5p = (((KP535826794) * (T5l)) + (KP844327925 * T5o));
                T5w = (((KP062790519) * (T5s)) + (KP998026728 * T5v));
                T5x = T5p + T5w;
                T5y = T5i + T5x;
                T7j = T5p - T5w;
                T5z = KP559016994 * (T5i - T5x);
                T7i = T5a - T5h;
            }
            {
                E T64, T65, T7n, T67, T68, T7o;
                T64 = ((KP728968627 * T5N) - ((KP684547105) * (T5M)));
                T65 = (((KP125333233) * (T5Q)) + (KP992114701 * T5P));
                T7n = T64 - T65;
                T67 = ((KP062790519 * T5U) - ((KP998026728) * (T5T)));
                T68 = (((KP770513242) * (T5X)) + (KP637423989 * T5W));
                T7o = T67 - T68;
                T66 = T64 + T65;
                T7r = KP559016994 * (T7n - T7o);
                T69 = T67 + T68;
                T7p = T7n + T7o;
            }
            {
                E T5O, T5R, T5S, T5V, T5Y, T5Z;
                T5O = (((KP728968627) * (T5M)) + (KP684547105 * T5N));
                T5R = ((KP125333233 * T5P) - ((KP992114701) * (T5Q)));
                T5S = T5O + T5R;
                T5V = (((KP062790519) * (T5T)) + (KP998026728 * T5U));
                T5Y = ((KP770513242 * T5W) - ((KP637423989) * (T5X)));
                T5Z = T5V + T5Y;
                T60 = T5S + T5Z;
                T7v = T5V - T5Y;
                T61 = KP559016994 * (T5S - T5Z);
                T7u = T5O - T5R;
            }
            {
                E T5C, T5D, T79, T5F, T5G, T7a;
                T5C = ((KP876306680 * T59) - ((KP481753674) * (T56)));
                T5D = (((KP904827052) * (T5g)) + (KP425779291 * T5d));
                T79 = T5C - T5D;
                T5F = ((KP535826794 * T5o) - ((KP844327925) * (T5l)));
                T5G = ((KP062790519 * T5v) - ((KP998026728) * (T5s)));
                T7a = T5F + T5G;
                T5E = T5C + T5D;
                T7f = KP559016994 * (T79 - T7a);
                T5H = T5F - T5G;
                T7b = T79 + T7a;
            }
            ri[(rs[2])] = T53 + T5y;
            ii[(rs[2])] = T7b + T7e;
            ri[(rs[3])] = T5L + T60;
            ii[(rs[3])] = T7p + T7q;
            {
                E T5I, T5K, T5B, T5J, T5A;
                T5I = (((KP951056516) * (T5E)) + (KP587785252 * T5H));
                T5K = ((KP951056516 * T5H) - ((KP587785252) * (T5E)));
                T5A = ((T53) - ((KP250000000) * (T5y)));
                T5B = T5z + T5A;
                T5J = T5A - T5z;
                ri[(rs[22])] = T5B - T5I;
                ri[(rs[17])] = T5J + T5K;
                ri[(rs[7])] = T5B + T5I;
                ri[(rs[12])] = T5J - T5K;
            }
            {
                E T7k, T7l, T7h, T7m, T7g;
                T7k = (((KP951056516) * (T7i)) + (KP587785252 * T7j));
                T7l = ((KP951056516 * T7j) - ((KP587785252) * (T7i)));
                T7g = ((T7e) - ((KP250000000) * (T7b)));
                T7h = T7f + T7g;
                T7m = T7g - T7f;
                ii[(rs[7])] = T7h - T7k;
                ii[(rs[17])] = T7m - T7l;
                ii[(rs[22])] = T7k + T7h;
                ii[(rs[12])] = T7l + T7m;
            }
            {
                E T6a, T6c, T63, T6b, T62;
                T6a = (((KP951056516) * (T66)) + (KP587785252 * T69));
                T6c = ((KP951056516 * T69) - ((KP587785252) * (T66)));
                T62 = ((T5L) - ((KP250000000) * (T60)));
                T63 = T61 + T62;
                T6b = T62 - T61;
                ri[(rs[23])] = T63 - T6a;
                ri[(rs[18])] = T6b + T6c;
                ri[(rs[8])] = T63 + T6a;
                ri[(rs[13])] = T6b - T6c;
            }
            {
                E T7w, T7x, T7t, T7y, T7s;
                T7w = (((KP951056516) * (T7u)) + (KP587785252 * T7v));
                T7x = ((KP951056516 * T7v) - ((KP587785252) * (T7u)));
                T7s = ((T7q) - ((KP250000000) * (T7p)));
                T7t = T7r + T7s;
                T7y = T7s - T7r;
                ii[(rs[8])] = T7t - T7w;
                ii[(rs[18])] = T7y - T7x;
                ii[(rs[23])] = T7w + T7t;
                ii[(rs[13])] = T7x + T7y;
            }
        }
    }
}

}
