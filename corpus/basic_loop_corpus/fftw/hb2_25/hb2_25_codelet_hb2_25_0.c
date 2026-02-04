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
extern  E KP998026728;
extern  E KP062790519;
extern  E KP992114701;
extern  E KP125333233;
extern  E KP425779291;
extern  E KP904827052;
extern  E KP248689887;
extern  E KP968583161;
extern  E KP770513242;
extern  E KP637423989;
extern  E KP844327925;
extern  E KP535826794;
extern  E KP684547105;
extern  E KP728968627;
extern  E KP481753674;
extern  E KP876306680;
extern  E KP559016994;
extern  E KP250000000;
extern  E KP587785252;
extern  E KP951056516;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (m = mb , W = W + ((mb - 1) * 8); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 8 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E TN, TQ, TO, TR, TT, TY, T2t, T2r, TZ, TU, T4f, T4l, T2d, T4v, T5m;
    E T2j, T5l, T4X, T2v, T11, T3R, T1L, T5d, T6x, T5h, T6t, T25, T26, T27, T29;
    E T6D, T7v, T49, T7l, T7p, T7t, T2p, T2n, T4b, T4p, T5n, T6B, T5b, T5p, T6p;
    E T6r, T59, T4r;
    {
        E T2c, T4j, T2h, T4e, T2b, T4k, T2i, T4d;
        {
            E TP, TX, TS, TW;
            TN = W[0];
            TQ = W[1];
            TO = W[2];
            TR = W[3];
            TP = TN * TO;
            TX = TQ * TO;
            TS = TQ * TR;
            TW = TN * TR;
            TT = TP - TS;
            TY = TW + TX;
            T2t = TW - TX;
            T2r = TP + TS;
            TZ = W[5];
            T2c = TQ * TZ;
            T4j = TO * TZ;
            T2h = TN * TZ;
            T4e = TR * TZ;
            TU = W[4];
            T2b = TN * TU;
            T4k = TR * TU;
            T2i = TQ * TU;
            T4d = TO * TU;
        }
        T4f = T4d - T4e;
        T4l = T4j + T4k;
        {
            E T2s, T2u, TV, T10, T3P, T3Q, T1J, T1K;
            T2d = T2b - T2c;
            T4v = T2b + T2c;
            T5m = T4j - T4k;
            T2j = T2h + T2i;
            T5l = T4d + T4e;
            T4X = T2h - T2i;
            T2s = T2r * TU;
            T2u = T2t * TZ;
            T2v = T2s + T2u;
            TV = TT * TU;
            T10 = TY * TZ;
            T11 = TV + T10;
            T3P = T2r * TZ;
            T3Q = T2t * TU;
            T3R = T3P - T3Q;
            T1J = TT * TZ;
            T1K = TY * TU;
            T1L = T1J - T1K;
            T5d = TV - T10;
            T6x = T3P + T3Q;
            T5h = T1J + T1K;
            T6t = T2s - T2u;
            T25 = W[6];
            T26 = W[7];
            T27 = (((TT) * (T25)) + (TY * T26));
            T29 = ((TT * T26) - ((TY) * (T25)));
            T6D = ((T4v * T26) - ((T4X) * (T25)));
            T7v = ((T11 * T26) - ((T1L) * (T25)));
            T49 = (((T2r) * (T25)) + (T2t * T26));
            T7l = (((T2d) * (T25)) + (T2j * T26));
            T7p = ((T2d * T26) - ((T2j) * (T25)));
            T7t = (((T11) * (T25)) + (T1L * T26));
            T2p = ((TU * T26) - ((TZ) * (T25)));
            T2n = (((TU) * (T25)) + (TZ * T26));
            T4b = ((T2r * T26) - ((T2t) * (T25)));
            T4p = (((T2v) * (T25)) + (T3R * T26));
            T5n = (((T5l) * (T25)) + (T5m * T26));
            T6B = (((T4v) * (T25)) + (T4X * T26));
            T5b = ((TN * T26) - ((TQ) * (T25)));
            T5p = ((T5l * T26) - ((T5m) * (T25)));
            T6p = (((TO) * (T25)) + (TR * T26));
            T6r = ((TO * T26) - ((TR) * (T25)));
            T59 = (((TN) * (T25)) + (TQ * T26));
            T4r = ((T2v * T26) - ((T3R) * (T25)));
        }
    }
    {
        E T9, T6i, T40, T3z, T5Y, Ti, Tr, Ts, T1d, T1m, T1P, T2K, T4P, T3H, T4y;
        E T5G, T71, T65, T6N, T5z, T70, T64, T6K, T2Z, T4Q, T3I, T4B, T20, T5Z, T3C;
        E T43, T6j, TB, TK, TL, T1w, T1F, T1Q, T3f, T4S, T3K, T4F, T5V, T74, T68;
        E T6U, T5O, T73, T67, T6R, T3u, T4T, T3L, T4I;
        {
            E T1, T4, T7, T8, T3Z, T3Y, T3x, T3y;
            T1 = cr[0];
            {
                E T2, T3, T5, T6;
                T2 = cr[(rs[5])];
                T3 = ci[(rs[4])];
                T4 = T2 + T3;
                T5 = cr[(rs[10])];
                T6 = ci[(rs[9])];
                T7 = T5 + T6;
                T8 = T4 + T7;
                T3Z = T5 - T6;
                T3Y = T2 - T3;
            }
            T9 = T1 + T8;
            T6i = (((KP951056516) * (T3Y)) + (KP587785252 * T3Z));
            T40 = ((KP587785252 * T3Y) - ((KP951056516) * (T3Z)));
            T3x = ((T1) - ((KP250000000) * (T8)));
            T3y = KP559016994 * (T4 - T7);
            T3z = T3x - T3y;
            T5Y = T3y + T3x;
        }
        {
            E Ta, T2x, T5w, T2F, Th, T2w, T1e, T2P, T5B, T2X, T1l, T2O, Tj, T2N, T5D;
            E T2T, Tq, T2S, T15, T2B, T5u, T2H, T1c, T2G;
            {
                E Tg, T2E, Td, T2D;
                Ta = cr[(rs[1])];
                {
                    E Te, Tf, Tb, Tc;
                    Te = cr[(rs[11])];
                    Tf = ci[(rs[8])];
                    Tg = Te + Tf;
                    T2E = Te - Tf;
                    Tb = cr[(rs[6])];
                    Tc = ci[(rs[3])];
                    Td = Tb + Tc;
                    T2D = Tb - Tc;
                }
                T2x = KP559016994 * (Td - Tg);
                T5w = (((KP951056516) * (T2D)) + (KP587785252 * T2E));
                T2F = ((KP587785252 * T2D) - ((KP951056516) * (T2E)));
                Th = Td + Tg;
                T2w = ((Ta) - ((KP250000000) * (Th)));
            }
            {
                E T1k, T2W, T1h, T2V;
                T1e = ci[(rs[20])];
                {
                    E T1i, T1j, T1f, T1g;
                    T1i = cr[(rs[14])];
                    T1j = cr[(rs[19])];
                    T1k = T1i + T1j;
                    T2W = T1j - T1i;
                    T1f = ci[(rs[15])];
                    T1g = cr[(rs[24])];
                    T1h = T1f - T1g;
                    T2V = T1f + T1g;
                }
                T2P = KP559016994 * (T1h + T1k);
                T5B = (((KP951056516) * (T2V)) + (KP587785252 * T2W));
                T2X = ((KP587785252 * T2V) - ((KP951056516) * (T2W)));
                T1l = T1h - T1k;
                T2O = ((T1e) - ((KP250000000) * (T1l)));
            }
            {
                E Tp, T2M, Tm, T2L;
                Tj = cr[(rs[4])];
                {
                    E Tn, To, Tk, Tl;
                    Tn = ci[(rs[10])];
                    To = ci[(rs[5])];
                    Tp = Tn + To;
                    T2M = Tn - To;
                    Tk = cr[(rs[9])];
                    Tl = ci[0];
                    Tm = Tk + Tl;
                    T2L = Tk - Tl;
                }
                T2N = ((KP587785252 * T2L) - ((KP951056516) * (T2M)));
                T5D = (((KP951056516) * (T2L)) + (KP587785252 * T2M));
                T2T = KP559016994 * (Tm - Tp);
                Tq = Tm + Tp;
                T2S = ((Tj) - ((KP250000000) * (Tq)));
            }
            {
                E T1b, T2A, T18, T2z;
                T15 = ci[(rs[23])];
                {
                    E T19, T1a, T16, T17;
                    T19 = ci[(rs[13])];
                    T1a = cr[(rs[16])];
                    T1b = T19 - T1a;
                    T2A = T19 + T1a;
                    T16 = ci[(rs[18])];
                    T17 = cr[(rs[21])];
                    T18 = T16 - T17;
                    T2z = T16 + T17;
                }
                T2B = ((KP587785252 * T2z) - ((KP951056516) * (T2A)));
                T5u = (((KP951056516) * (T2z)) + (KP587785252 * T2A));
                T2H = KP559016994 * (T18 - T1b);
                T1c = T18 + T1b;
                T2G = ((T15) - ((KP250000000) * (T1c)));
            }
            Ti = Ta + Th;
            Tr = Tj + Tq;
            Ts = Ti + Tr;
            T1d = T15 + T1c;
            T1m = T1e + T1l;
            T1P = T1d + T1m;
            {
                E T2C, T4w, T2J, T4x, T2y, T2I;
                T2y = T2w - T2x;
                T2C = T2y - T2B;
                T4w = T2y + T2B;
                T2I = T2G - T2H;
                T2J = T2F + T2I;
                T4x = T2I - T2F;
                T2K = ((KP876306680 * T2C) - ((KP481753674) * (T2J)));
                T4P = (((KP728968627) * (T4x)) + (KP684547105 * T4w));
                T3H = (((KP876306680) * (T2J)) + (KP481753674 * T2C));
                T4y = ((KP728968627 * T4w) - ((KP684547105) * (T4x)));
            }
            {
                E T5C, T6M, T5F, T6L, T5A, T5E;
                T5A = T2T + T2S;
                T5C = T5A - T5B;
                T6M = T5A + T5B;
                T5E = T2O + T2P;
                T5F = T5D + T5E;
                T6L = T5E - T5D;
                T5G = ((KP535826794 * T5C) - ((KP844327925) * (T5F)));
                T71 = (((KP637423989) * (T6L)) + (KP770513242 * T6M));
                T65 = (((KP535826794) * (T5F)) + (KP844327925 * T5C));
                T6N = ((KP770513242 * T6L) - ((KP637423989) * (T6M)));
            }
            {
                E T5v, T6I, T5y, T6J, T5t, T5x;
                T5t = T2x + T2w;
                T5v = T5t - T5u;
                T6I = T5t + T5u;
                T5x = T2H + T2G;
                T5y = T5w + T5x;
                T6J = T5x - T5w;
                T5z = ((KP968583161 * T5v) - ((KP248689887) * (T5y)));
                T70 = (((KP535826794) * (T6J)) + (KP844327925 * T6I));
                T64 = (((KP968583161) * (T5y)) + (KP248689887 * T5v));
                T6K = ((KP535826794 * T6I) - ((KP844327925) * (T6J)));
            }
            {
                E T2R, T4z, T2Y, T4A, T2Q, T2U;
                T2Q = T2O - T2P;
                T2R = T2N + T2Q;
                T4z = T2Q - T2N;
                T2U = T2S - T2T;
                T2Y = T2U - T2X;
                T4A = T2U + T2X;
                T2Z = (((KP904827052) * (T2R)) + (KP425779291 * T2Y));
                T4Q = ((KP125333233 * T4A) - ((KP992114701) * (T4z)));
                T3I = ((KP904827052 * T2Y) - ((KP425779291) * (T2R)));
                T4B = (((KP125333233) * (T4z)) + (KP992114701 * T4A));
            }
        }
        {
            E T1S, T1V, T1Y, T1Z, T3B, T3A, T41, T42;
            T1S = ci[(rs[24])];
            {
                E T1T, T1U, T1W, T1X;
                T1T = ci[(rs[19])];
                T1U = cr[(rs[20])];
                T1V = T1T - T1U;
                T1W = ci[(rs[14])];
                T1X = cr[(rs[15])];
                T1Y = T1W - T1X;
                T1Z = T1V + T1Y;
                T3B = T1W + T1X;
                T3A = T1T + T1U;
            }
            T20 = T1S + T1Z;
            T5Z = (((KP951056516) * (T3A)) + (KP587785252 * T3B));
            T3C = ((KP587785252 * T3A) - ((KP951056516) * (T3B)));
            T41 = ((T1S) - ((KP250000000) * (T1Z)));
            T42 = KP559016994 * (T1V - T1Y);
            T43 = T41 - T42;
            T6j = T42 + T41;
        }
        {
            E Tt, T32, T5L, T3a, TA, T31, T1o, T36, T5J, T3c, T1v, T3b, TC, T3h, T5S;
            E T3p, TJ, T3g, T1x, T3l, T5Q, T3r, T1E, T3q;
            {
                E Tw, T38, Tz, T39;
                Tt = cr[(rs[2])];
                {
                    E Tu, Tv, Tx, Ty;
                    Tu = cr[(rs[7])];
                    Tv = ci[(rs[2])];
                    Tw = Tu + Tv;
                    T38 = Tu - Tv;
                    Tx = cr[(rs[12])];
                    Ty = ci[(rs[7])];
                    Tz = Tx + Ty;
                    T39 = Tx - Ty;
                }
                T32 = KP559016994 * (Tw - Tz);
                T5L = (((KP951056516) * (T38)) + (KP587785252 * T39));
                T3a = ((KP587785252 * T38) - ((KP951056516) * (T39)));
                TA = Tw + Tz;
                T31 = ((Tt) - ((KP250000000) * (TA)));
            }
            {
                E T1r, T34, T1u, T35;
                T1o = ci[(rs[22])];
                {
                    E T1p, T1q, T1s, T1t;
                    T1p = ci[(rs[17])];
                    T1q = cr[(rs[22])];
                    T1r = T1p - T1q;
                    T34 = T1p + T1q;
                    T1s = ci[(rs[12])];
                    T1t = cr[(rs[17])];
                    T1u = T1s - T1t;
                    T35 = T1s + T1t;
                }
                T36 = ((KP587785252 * T34) - ((KP951056516) * (T35)));
                T5J = (((KP951056516) * (T34)) + (KP587785252 * T35));
                T3c = KP559016994 * (T1r - T1u);
                T1v = T1r + T1u;
                T3b = ((T1o) - ((KP250000000) * (T1v)));
            }
            {
                E TI, T3o, TF, T3n;
                TC = cr[(rs[3])];
                {
                    E TG, TH, TD, TE;
                    TG = ci[(rs[11])];
                    TH = ci[(rs[6])];
                    TI = TG + TH;
                    T3o = TG - TH;
                    TD = cr[(rs[8])];
                    TE = ci[(rs[1])];
                    TF = TD + TE;
                    T3n = TD - TE;
                }
                T3h = KP559016994 * (TF - TI);
                T5S = (((KP951056516) * (T3n)) + (KP587785252 * T3o));
                T3p = ((KP587785252 * T3n) - ((KP951056516) * (T3o)));
                TJ = TF + TI;
                T3g = ((TC) - ((KP250000000) * (TJ)));
            }
            {
                E T1D, T3k, T1A, T3j;
                T1x = ci[(rs[21])];
                {
                    E T1B, T1C, T1y, T1z;
                    T1B = cr[(rs[13])];
                    T1C = cr[(rs[18])];
                    T1D = T1B + T1C;
                    T3k = T1C - T1B;
                    T1y = ci[(rs[16])];
                    T1z = cr[(rs[23])];
                    T1A = T1y - T1z;
                    T3j = T1y + T1z;
                }
                T3l = ((KP587785252 * T3j) - ((KP951056516) * (T3k)));
                T5Q = (((KP951056516) * (T3j)) + (KP587785252 * T3k));
                T3r = KP559016994 * (T1A + T1D);
                T1E = T1A - T1D;
                T3q = ((T1x) - ((KP250000000) * (T1E)));
            }
            TB = Tt + TA;
            TK = TC + TJ;
            TL = TB + TK;
            T1w = T1o + T1v;
            T1F = T1x + T1E;
            T1Q = T1w + T1F;
            {
                E T37, T4D, T3e, T4E, T33, T3d;
                T33 = T31 - T32;
                T37 = T33 - T36;
                T4D = T33 + T36;
                T3d = T3b - T3c;
                T3e = T3a + T3d;
                T4E = T3d - T3a;
                T3f = ((KP535826794 * T37) - ((KP844327925) * (T3e)));
                T4S = (((KP062790519) * (T4E)) + (KP998026728 * T4D));
                T3K = (((KP535826794) * (T3e)) + (KP844327925 * T37));
                T4F = ((KP062790519 * T4D) - ((KP998026728) * (T4E)));
            }
            {
                E T5R, T6T, T5U, T6S, T5P, T5T;
                T5P = T3h + T3g;
                T5R = T5P - T5Q;
                T6T = T5P + T5Q;
                T5T = T3q + T3r;
                T5U = T5S + T5T;
                T6S = T5T - T5S;
                T5V = ((KP728968627 * T5R) - ((KP684547105) * (T5U)));
                T74 = ((KP125333233 * T6T) - ((KP992114701) * (T6S)));
                T68 = (((KP728968627) * (T5U)) + (KP684547105 * T5R));
                T6U = (((KP125333233) * (T6S)) + (KP992114701 * T6T));
            }
            {
                E T5K, T6Q, T5N, T6P, T5I, T5M;
                T5I = T32 + T31;
                T5K = T5I - T5J;
                T6Q = T5I + T5J;
                T5M = T3c + T3b;
                T5N = T5L + T5M;
                T6P = T5M - T5L;
                T5O = ((KP876306680 * T5K) - ((KP481753674) * (T5N)));
                T73 = ((KP904827052 * T6Q) - ((KP425779291) * (T6P)));
                T67 = (((KP876306680) * (T5N)) + (KP481753674 * T5K));
                T6R = (((KP904827052) * (T6P)) + (KP425779291 * T6Q));
            }
            {
                E T3m, T4H, T3t, T4G, T3i, T3s;
                T3i = T3g - T3h;
                T3m = T3i - T3l;
                T4H = T3i + T3l;
                T3s = T3q - T3r;
                T3t = T3p + T3s;
                T4G = T3s - T3p;
                T3u = ((KP062790519 * T3m) - ((KP998026728) * (T3t)));
                T4T = ((KP770513242 * T4H) - ((KP637423989) * (T4G)));
                T3L = (((KP062790519) * (T3t)) + (KP998026728 * T3m));
                T4I = (((KP770513242) * (T4G)) + (KP637423989 * T4H));
            }
        }
        {
            E TM, T14, T2e, T21, T23, T2l, T1H, T2f, T1O, T2k;
            {
                E T12, T13, T1R, T22;
                T12 = KP559016994 * (Ts - TL);
                TM = Ts + TL;
                T13 = ((T9) - ((KP250000000) * (TM)));
                T14 = T12 + T13;
                T2e = T13 - T12;
                T1R = KP559016994 * (T1P - T1Q);
                T21 = T1P + T1Q;
                T22 = ((T20) - ((KP250000000) * (T21)));
                T23 = T1R + T22;
                T2l = T22 - T1R;
            }
            {
                E T1n, T1G, T1M, T1N;
                T1n = T1d - T1m;
                T1G = T1w - T1F;
                T1H = (((KP951056516) * (T1n)) + (KP587785252 * T1G));
                T2f = ((KP587785252 * T1n) - ((KP951056516) * (T1G)));
                T1M = Ti - Tr;
                T1N = TB - TK;
                T1O = (((KP951056516) * (T1M)) + (KP587785252 * T1N));
                T2k = ((KP587785252 * T1M) - ((KP951056516) * (T1N)));
            }
            {
                E T1I, T24, T2o, T2q;
                cr[0] = T9 + TM;
                ci[0] = T20 + T21;
                T1I = T14 - T1H;
                T24 = T1O + T23;
                cr[(rs[5])] = ((T11 * T1I) - ((T1L) * (T24)));
                ci[(rs[5])] = (((T1L) * (T1I)) + (T11 * T24));
                T2o = T2e + T2f;
                T2q = T2l - T2k;
                cr[(rs[15])] = ((T2n * T2o) - ((T2p) * (T2q)));
                ci[(rs[15])] = (((T2p) * (T2o)) + (T2n * T2q));
                {
                    E T2g, T2m, T28, T2a;
                    T2g = T2e - T2f;
                    T2m = T2k + T2l;
                    cr[(rs[10])] = ((T2d * T2g) - ((T2j) * (T2m)));
                    ci[(rs[10])] = (((T2j) * (T2g)) + (T2d * T2m));
                    T28 = T14 + T1H;
                    T2a = T23 - T1O;
                    cr[(rs[20])] = ((T27 * T28) - ((T29) * (T2a)));
                    ci[(rs[20])] = (((T29) * (T28)) + (T27 * T2a));
                }
            }
        }
        {
            E T76, T7n, T7a, T7q, T6H, T6W, T6X, T6Y, T7e, T7f, T7d, T7g, T7x, T7y;
            {
                E T72, T75, T78, T79;
                T72 = T70 + T71;
                T75 = T73 - T74;
                T76 = (((KP951056516) * (T72)) + (KP587785252 * T75));
                T7n = ((KP587785252 * T72) - ((KP951056516) * (T75)));
                T78 = T6K - T6N;
                T79 = T6U - T6R;
                T7a = (((KP951056516) * (T78)) + (KP587785252 * T79));
                T7q = ((KP587785252 * T78) - ((KP951056516) * (T79)));
            }
            {
                E T6O, T6V, T7b, T7c;
                T6H = T5Y + T5Z;
                T6O = T6K + T6N;
                T6V = T6R + T6U;
                T6W = T6O - T6V;
                T6X = ((T6H) - ((KP250000000) * (T6W)));
                T6Y = KP559016994 * (T6O + T6V);
                T7e = T6j - T6i;
                T7b = T70 - T71;
                T7c = T73 + T74;
                T7f = T7b + T7c;
                T7d = KP559016994 * (T7b - T7c);
                T7g = ((T7e) - ((KP250000000) * (T7f)));
            }
            T7x = T6H + T6W;
            T7y = T7e + T7f;
            cr[(rs[4])] = ((TT * T7x) - ((TY) * (T7y)));
            ci[(rs[4])] = (((TY) * (T7x)) + (TT * T7y));
            {
                E T7o, T7u, T7s, T7w, T7m, T7r;
                T7m = T6X - T6Y;
                T7o = T7m - T7n;
                T7u = T7m + T7n;
                T7r = T7g - T7d;
                T7s = T7q + T7r;
                T7w = T7r - T7q;
                cr[(rs[14])] = ((T7l * T7o) - ((T7p) * (T7s)));
                ci[(rs[14])] = (((T7p) * (T7o)) + (T7l * T7s));
                cr[(rs[19])] = ((T7t * T7u) - ((T7v) * (T7w)));
                ci[(rs[19])] = (((T7v) * (T7u)) + (T7t * T7w));
            }
            {
                E T77, T7j, T7i, T7k, T6Z, T7h;
                T6Z = T6X + T6Y;
                T77 = T6Z - T76;
                T7j = T6Z + T76;
                T7h = T7d + T7g;
                T7i = T7a + T7h;
                T7k = T7h - T7a;
                cr[(rs[9])] = ((TU * T77) - ((TZ) * (T7i)));
                ci[(rs[9])] = (((TZ) * (T77)) + (TU * T7i));
                cr[(rs[24])] = ((T25 * T7j) - ((T26) * (T7k)));
                ci[(rs[24])] = (((T26) * (T7j)) + (T25 * T7k));
            }
        }
        {
            E T3N, T4h, T3U, T4m, T3D, T3E, T3w, T3F, T44, T45, T3X, T46, T4t, T4u;
            {
                E T3J, T3M, T3S, T3T;
                T3J = T3H - T3I;
                T3M = T3K - T3L;
                T3N = (((KP951056516) * (T3J)) + (KP587785252 * T3M));
                T4h = ((KP587785252 * T3J) - ((KP951056516) * (T3M)));
                T3S = T2K + T2Z;
                T3T = T3f - T3u;
                T3U = (((KP951056516) * (T3S)) + (KP587785252 * T3T));
                T4m = ((KP587785252 * T3S) - ((KP951056516) * (T3T)));
            }
            {
                E T30, T3v, T3V, T3W;
                T3D = T3z - T3C;
                T30 = T2K - T2Z;
                T3v = T3f + T3u;
                T3E = T30 + T3v;
                T3w = KP559016994 * (T30 - T3v);
                T3F = ((T3D) - ((KP250000000) * (T3E)));
                T44 = T40 + T43;
                T3V = T3H + T3I;
                T3W = T3K + T3L;
                T45 = T3V + T3W;
                T3X = KP559016994 * (T3V - T3W);
                T46 = ((T44) - ((KP250000000) * (T45)));
            }
            T4t = T3D + T3E;
            T4u = T44 + T45;
            cr[(rs[2])] = ((T2r * T4t) - ((T2t) * (T4u)));
            ci[(rs[2])] = (((T2t) * (T4t)) + (T2r * T4u));
            {
                E T4i, T4q, T4o, T4s, T4g, T4n;
                T4g = T3F - T3w;
                T4i = T4g - T4h;
                T4q = T4g + T4h;
                T4n = T46 - T3X;
                T4o = T4m + T4n;
                T4s = T4n - T4m;
                cr[(rs[12])] = ((T4f * T4i) - ((T4l) * (T4o)));
                ci[(rs[12])] = (((T4l) * (T4i)) + (T4f * T4o));
                cr[(rs[17])] = ((T4p * T4q) - ((T4r) * (T4s)));
                ci[(rs[17])] = (((T4r) * (T4q)) + (T4p * T4s));
            }
            {
                E T3O, T4a, T48, T4c, T3G, T47;
                T3G = T3w + T3F;
                T3O = T3G - T3N;
                T4a = T3G + T3N;
                T47 = T3X + T46;
                T48 = T3U + T47;
                T4c = T47 - T3U;
                cr[(rs[7])] = ((T2v * T3O) - ((T3R) * (T48)));
                ci[(rs[7])] = (((T3R) * (T3O)) + (T2v * T48));
                cr[(rs[22])] = ((T49 * T4a) - ((T4b) * (T4c)));
                ci[(rs[22])] = (((T4b) * (T4a)) + (T49 * T4c));
            }
        }
        {
            E T4V, T5f, T50, T5i, T4L, T4M, T4K, T4N, T54, T55, T53, T56, T5r, T5s;
            {
                E T4R, T4U, T4Y, T4Z;
                T4R = T4P - T4Q;
                T4U = T4S - T4T;
                T4V = (((KP951056516) * (T4R)) + (KP587785252 * T4U));
                T5f = ((KP587785252 * T4R) - ((KP951056516) * (T4U)));
                T4Y = T4y + T4B;
                T4Z = T4F + T4I;
                T50 = (((KP951056516) * (T4Y)) + (KP587785252 * T4Z));
                T5i = ((KP587785252 * T4Y) - ((KP951056516) * (T4Z)));
            }
            {
                E T4C, T4J, T51, T52;
                T4L = T3z + T3C;
                T4C = T4y - T4B;
                T4J = T4F - T4I;
                T4M = T4C + T4J;
                T4K = KP559016994 * (T4C - T4J);
                T4N = ((T4L) - ((KP250000000) * (T4M)));
                T54 = T43 - T40;
                T51 = T4P + T4Q;
                T52 = T4S + T4T;
                T55 = T51 + T52;
                T53 = KP559016994 * (T51 - T52);
                T56 = ((T54) - ((KP250000000) * (T55)));
            }
            T5r = T4L + T4M;
            T5s = T54 + T55;
            cr[(rs[3])] = ((TO * T5r) - ((TR) * (T5s)));
            ci[(rs[3])] = (((TR) * (T5r)) + (TO * T5s));
            {
                E T5g, T5o, T5k, T5q, T5e, T5j;
                T5e = T4N - T4K;
                T5g = T5e - T5f;
                T5o = T5e + T5f;
                T5j = T56 - T53;
                T5k = T5i + T5j;
                T5q = T5j - T5i;
                cr[(rs[13])] = ((T5d * T5g) - ((T5h) * (T5k)));
                ci[(rs[13])] = (((T5h) * (T5g)) + (T5d * T5k));
                cr[(rs[18])] = ((T5n * T5o) - ((T5p) * (T5q)));
                ci[(rs[18])] = (((T5p) * (T5o)) + (T5n * T5q));
            }
            {
                E T4W, T5a, T58, T5c, T4O, T57;
                T4O = T4K + T4N;
                T4W = T4O - T4V;
                T5a = T4O + T4V;
                T57 = T53 + T56;
                T58 = T50 + T57;
                T5c = T57 - T50;
                cr[(rs[8])] = ((T4v * T4W) - ((T4X) * (T58)));
                ci[(rs[8])] = (((T4X) * (T4W)) + (T4v * T58));
                cr[(rs[23])] = ((T59 * T5a) - ((T5b) * (T5c)));
                ci[(rs[23])] = (((T5b) * (T5a)) + (T59 * T5c));
            }
        }
        {
            E T6a, T6v, T6e, T6y, T60, T61, T5X, T62, T6k, T6l, T6h, T6m, T6F, T6G;
            {
                E T66, T69, T6c, T6d;
                T66 = T64 - T65;
                T69 = T67 - T68;
                T6a = (((KP951056516) * (T66)) + (KP587785252 * T69));
                T6v = ((KP587785252 * T66) - ((KP951056516) * (T69)));
                T6c = T5z - T5G;
                T6d = T5O - T5V;
                T6e = (((KP951056516) * (T6c)) + (KP587785252 * T6d));
                T6y = ((KP587785252 * T6c) - ((KP951056516) * (T6d)));
            }
            {
                E T5H, T5W, T6f, T6g;
                T60 = T5Y - T5Z;
                T5H = T5z + T5G;
                T5W = T5O + T5V;
                T61 = T5H + T5W;
                T5X = KP559016994 * (T5H - T5W);
                T62 = ((T60) - ((KP250000000) * (T61)));
                T6k = T6i + T6j;
                T6f = T64 + T65;
                T6g = T67 + T68;
                T6l = T6f + T6g;
                T6h = KP559016994 * (T6f - T6g);
                T6m = ((T6k) - ((KP250000000) * (T6l)));
            }
            T6F = T60 + T61;
            T6G = T6k + T6l;
            cr[(rs[1])] = ((TN * T6F) - ((TQ) * (T6G)));
            ci[(rs[1])] = (((TQ) * (T6F)) + (TN * T6G));
            {
                E T6w, T6C, T6A, T6E, T6u, T6z;
                T6u = T62 - T5X;
                T6w = T6u - T6v;
                T6C = T6u + T6v;
                T6z = T6m - T6h;
                T6A = T6y + T6z;
                T6E = T6z - T6y;
                cr[(rs[11])] = ((T6t * T6w) - ((T6x) * (T6A)));
                ci[(rs[11])] = (((T6x) * (T6w)) + (T6t * T6A));
                cr[(rs[16])] = ((T6B * T6C) - ((T6D) * (T6E)));
                ci[(rs[16])] = (((T6D) * (T6C)) + (T6B * T6E));
            }
            {
                E T6b, T6q, T6o, T6s, T63, T6n;
                T63 = T5X + T62;
                T6b = T63 - T6a;
                T6q = T63 + T6a;
                T6n = T6h + T6m;
                T6o = T6e + T6n;
                T6s = T6n - T6e;
                cr[(rs[6])] = ((T5l * T6b) - ((T5m) * (T6o)));
                ci[(rs[6])] = (((T5m) * (T6b)) + (T5l * T6o));
                cr[(rs[21])] = ((T6p * T6q) - ((T6r) * (T6s)));
                ci[(rs[21])] = (((T6r) * (T6q)) + (T6p * T6s));
            }
        }
    }
}

}
