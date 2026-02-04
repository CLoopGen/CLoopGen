#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern  R *ri;
extern  R *ii;
extern R *ro;
extern R *io;
extern stride is;
extern stride os;
extern INT v;
extern INT ivs;
extern INT ovs;
extern  E KP831469612;
extern  E KP555570233;
extern  E KP195090322;
extern  E KP980785280;
extern  E KP923879532;
extern  E KP382683432;
extern  E KP707106781;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , ri = ri + ivs , ii = ii + ivs , ro = ro + ovs , io = io + ovs , (is) = (is) + fftw_an_INT_guaranteed_to_be_zero , (os) = (os) + fftw_an_INT_guaranteed_to_be_zero) {
    E T7, T4r, T4Z, T18, T1z, T3t, T3T, T2T, Te, T1f, T50, T4s, T2W, T3u, T1G;
    E T3U, Tm, T1n, T1O, T2Z, T3y, T3X, T4w, T53, Tt, T1u, T1V, T2Y, T3B, T3W;
    E T4z, T52, T2t, T3L, T3O, T2K, TR, TY, T5F, T5G, T5H, T5I, T4R, T5j, T2E;
    E T3P, T4W, T5k, T2N, T3M, T22, T3E, T3H, T2j, TC, TJ, T5A, T5B, T5C, T5D;
    E T4G, T5g, T2d, T3F, T4L, T5h, T2m, T3I;
    {
        E T3, T1x, T14, T2S, T6, T2R, T17, T1y;
        {
            E T1, T2, T12, T13;
            T1 = ri[0];
            T2 = ri[(is[16])];
            T3 = T1 + T2;
            T1x = T1 - T2;
            T12 = ii[0];
            T13 = ii[(is[16])];
            T14 = T12 + T13;
            T2S = T12 - T13;
        }
        {
            E T4, T5, T15, T16;
            T4 = ri[(is[8])];
            T5 = ri[(is[24])];
            T6 = T4 + T5;
            T2R = T4 - T5;
            T15 = ii[(is[8])];
            T16 = ii[(is[24])];
            T17 = T15 + T16;
            T1y = T15 - T16;
        }
        T7 = T3 + T6;
        T4r = T3 - T6;
        T4Z = T14 - T17;
        T18 = T14 + T17;
        T1z = T1x - T1y;
        T3t = T1x + T1y;
        T3T = T2S - T2R;
        T2T = T2R + T2S;
    }
    {
        E Ta, T1B, T1b, T1A, Td, T1D, T1e, T1E;
        {
            E T8, T9, T19, T1a;
            T8 = ri[(is[4])];
            T9 = ri[(is[20])];
            Ta = T8 + T9;
            T1B = T8 - T9;
            T19 = ii[(is[4])];
            T1a = ii[(is[20])];
            T1b = T19 + T1a;
            T1A = T19 - T1a;
        }
        {
            E Tb, Tc, T1c, T1d;
            Tb = ri[(is[28])];
            Tc = ri[(is[12])];
            Td = Tb + Tc;
            T1D = Tb - Tc;
            T1c = ii[(is[28])];
            T1d = ii[(is[12])];
            T1e = T1c + T1d;
            T1E = T1c - T1d;
        }
        Te = Ta + Td;
        T1f = T1b + T1e;
        T50 = Td - Ta;
        T4s = T1b - T1e;
        {
            E T2U, T2V, T1C, T1F;
            T2U = T1D - T1E;
            T2V = T1B + T1A;
            T2W = KP707106781 * (T2U - T2V);
            T3u = KP707106781 * (T2V + T2U);
            T1C = T1A - T1B;
            T1F = T1D + T1E;
            T1G = KP707106781 * (T1C - T1F);
            T3U = KP707106781 * (T1C + T1F);
        }
    }
    {
        E Ti, T1L, T1j, T1J, Tl, T1I, T1m, T1M, T1K, T1N;
        {
            E Tg, Th, T1h, T1i;
            Tg = ri[(is[2])];
            Th = ri[(is[18])];
            Ti = Tg + Th;
            T1L = Tg - Th;
            T1h = ii[(is[2])];
            T1i = ii[(is[18])];
            T1j = T1h + T1i;
            T1J = T1h - T1i;
        }
        {
            E Tj, Tk, T1k, T1l;
            Tj = ri[(is[10])];
            Tk = ri[(is[26])];
            Tl = Tj + Tk;
            T1I = Tj - Tk;
            T1k = ii[(is[10])];
            T1l = ii[(is[26])];
            T1m = T1k + T1l;
            T1M = T1k - T1l;
        }
        Tm = Ti + Tl;
        T1n = T1j + T1m;
        T1K = T1I + T1J;
        T1N = T1L - T1M;
        T1O = ((KP382683432 * T1K) - ((KP923879532) * (T1N)));
        T2Z = (((KP923879532) * (T1K)) + (KP382683432 * T1N));
        {
            E T3w, T3x, T4u, T4v;
            T3w = T1J - T1I;
            T3x = T1L + T1M;
            T3y = ((KP923879532 * T3w) - ((KP382683432) * (T3x)));
            T3X = (((KP382683432) * (T3w)) + (KP923879532 * T3x));
            T4u = T1j - T1m;
            T4v = Ti - Tl;
            T4w = T4u - T4v;
            T53 = T4v + T4u;
        }
    }
    {
        E Tp, T1S, T1q, T1Q, Ts, T1P, T1t, T1T, T1R, T1U;
        {
            E Tn, To, T1o, T1p;
            Tn = ri[(is[30])];
            To = ri[(is[14])];
            Tp = Tn + To;
            T1S = Tn - To;
            T1o = ii[(is[30])];
            T1p = ii[(is[14])];
            T1q = T1o + T1p;
            T1Q = T1o - T1p;
        }
        {
            E Tq, Tr, T1r, T1s;
            Tq = ri[(is[6])];
            Tr = ri[(is[22])];
            Ts = Tq + Tr;
            T1P = Tq - Tr;
            T1r = ii[(is[6])];
            T1s = ii[(is[22])];
            T1t = T1r + T1s;
            T1T = T1r - T1s;
        }
        Tt = Tp + Ts;
        T1u = T1q + T1t;
        T1R = T1P + T1Q;
        T1U = T1S - T1T;
        T1V = (((KP382683432) * (T1R)) + (KP923879532 * T1U));
        T2Y = ((KP382683432 * T1U) - ((KP923879532) * (T1R)));
        {
            E T3z, T3A, T4x, T4y;
            T3z = T1Q - T1P;
            T3A = T1S + T1T;
            T3B = (((KP923879532) * (T3z)) + (KP382683432 * T3A));
            T3W = ((KP923879532 * T3A) - ((KP382683432) * (T3z)));
            T4x = Tp - Ts;
            T4y = T1q - T1t;
            T4z = T4x + T4y;
            T52 = T4x - T4y;
        }
    }
    {
        E TN, T2p, T2J, T4S, TQ, T2G, T2s, T4T, TU, T2x, T2w, T4O, TX, T2z, T2C;
        E T4P;
        {
            E TL, TM, T2H, T2I;
            TL = ri[(is[31])];
            TM = ri[(is[15])];
            TN = TL + TM;
            T2p = TL - TM;
            T2H = ii[(is[31])];
            T2I = ii[(is[15])];
            T2J = T2H - T2I;
            T4S = T2H + T2I;
        }
        {
            E TO, TP, T2q, T2r;
            TO = ri[(is[7])];
            TP = ri[(is[23])];
            TQ = TO + TP;
            T2G = TO - TP;
            T2q = ii[(is[7])];
            T2r = ii[(is[23])];
            T2s = T2q - T2r;
            T4T = T2q + T2r;
        }
        {
            E TS, TT, T2u, T2v;
            TS = ri[(is[3])];
            TT = ri[(is[19])];
            TU = TS + TT;
            T2x = TS - TT;
            T2u = ii[(is[3])];
            T2v = ii[(is[19])];
            T2w = T2u - T2v;
            T4O = T2u + T2v;
        }
        {
            E TV, TW, T2A, T2B;
            TV = ri[(is[27])];
            TW = ri[(is[11])];
            TX = TV + TW;
            T2z = TV - TW;
            T2A = ii[(is[27])];
            T2B = ii[(is[11])];
            T2C = T2A - T2B;
            T4P = T2A + T2B;
        }
        T2t = T2p - T2s;
        T3L = T2p + T2s;
        T3O = T2J - T2G;
        T2K = T2G + T2J;
        TR = TN + TQ;
        TY = TU + TX;
        T5F = TR - TY;
        {
            E T4N, T4Q, T2y, T2D;
            T5G = T4S + T4T;
            T5H = T4O + T4P;
            T5I = T5G - T5H;
            T4N = TN - TQ;
            T4Q = T4O - T4P;
            T4R = T4N - T4Q;
            T5j = T4N + T4Q;
            T2y = T2w - T2x;
            T2D = T2z + T2C;
            T2E = KP707106781 * (T2y - T2D);
            T3P = KP707106781 * (T2y + T2D);
            {
                E T4U, T4V, T2L, T2M;
                T4U = T4S - T4T;
                T4V = TX - TU;
                T4W = T4U - T4V;
                T5k = T4V + T4U;
                T2L = T2z - T2C;
                T2M = T2x + T2w;
                T2N = KP707106781 * (T2L - T2M);
                T3M = KP707106781 * (T2M + T2L);
            }
        }
    }
    {
        E Ty, T2f, T21, T4C, TB, T1Y, T2i, T4D, TF, T28, T2b, T4I, TI, T23, T26;
        E T4J;
        {
            E Tw, Tx, T1Z, T20;
            Tw = ri[(is[1])];
            Tx = ri[(is[17])];
            Ty = Tw + Tx;
            T2f = Tw - Tx;
            T1Z = ii[(is[1])];
            T20 = ii[(is[17])];
            T21 = T1Z - T20;
            T4C = T1Z + T20;
        }
        {
            E Tz, TA, T2g, T2h;
            Tz = ri[(is[9])];
            TA = ri[(is[25])];
            TB = Tz + TA;
            T1Y = Tz - TA;
            T2g = ii[(is[9])];
            T2h = ii[(is[25])];
            T2i = T2g - T2h;
            T4D = T2g + T2h;
        }
        {
            E TD, TE, T29, T2a;
            TD = ri[(is[5])];
            TE = ri[(is[21])];
            TF = TD + TE;
            T28 = TD - TE;
            T29 = ii[(is[5])];
            T2a = ii[(is[21])];
            T2b = T29 - T2a;
            T4I = T29 + T2a;
        }
        {
            E TG, TH, T24, T25;
            TG = ri[(is[29])];
            TH = ri[(is[13])];
            TI = TG + TH;
            T23 = TG - TH;
            T24 = ii[(is[29])];
            T25 = ii[(is[13])];
            T26 = T24 - T25;
            T4J = T24 + T25;
        }
        T22 = T1Y + T21;
        T3E = T2f + T2i;
        T3H = T21 - T1Y;
        T2j = T2f - T2i;
        TC = Ty + TB;
        TJ = TF + TI;
        T5A = TC - TJ;
        {
            E T4E, T4F, T27, T2c;
            T5B = T4C + T4D;
            T5C = T4I + T4J;
            T5D = T5B - T5C;
            T4E = T4C - T4D;
            T4F = TI - TF;
            T4G = T4E - T4F;
            T5g = T4F + T4E;
            T27 = T23 - T26;
            T2c = T28 + T2b;
            T2d = KP707106781 * (T27 - T2c);
            T3F = KP707106781 * (T2c + T27);
            {
                E T4H, T4K, T2k, T2l;
                T4H = Ty - TB;
                T4K = T4I - T4J;
                T4L = T4H - T4K;
                T5h = T4H + T4K;
                T2k = T2b - T28;
                T2l = T23 + T26;
                T2m = KP707106781 * (T2k - T2l);
                T3I = KP707106781 * (T2k + T2l);
            }
        }
    }
    {
        E T4B, T57, T5a, T5c, T4Y, T56, T55, T5b;
        {
            E T4t, T4A, T58, T59;
            T4t = T4r - T4s;
            T4A = KP707106781 * (T4w - T4z);
            T4B = T4t + T4A;
            T57 = T4t - T4A;
            T58 = ((KP382683432 * T4G) - ((KP923879532) * (T4L)));
            T59 = (((KP382683432) * (T4W)) + (KP923879532 * T4R));
            T5a = T58 - T59;
            T5c = T58 + T59;
        }
        {
            E T4M, T4X, T51, T54;
            T4M = (((KP923879532) * (T4G)) + (KP382683432 * T4L));
            T4X = ((KP382683432 * T4R) - ((KP923879532) * (T4W)));
            T4Y = T4M + T4X;
            T56 = T4X - T4M;
            T51 = T4Z - T50;
            T54 = KP707106781 * (T52 - T53);
            T55 = T51 - T54;
            T5b = T51 + T54;
        }
        ro[(os[22])] = T4B - T4Y;
        io[(os[22])] = T5b - T5c;
        ro[(os[6])] = T4B + T4Y;
        io[(os[6])] = T5b + T5c;
        io[(os[30])] = T55 - T56;
        ro[(os[30])] = T57 - T5a;
        io[(os[14])] = T55 + T56;
        ro[(os[14])] = T57 + T5a;
    }
    {
        E T5f, T5r, T5u, T5w, T5m, T5q, T5p, T5v;
        {
            E T5d, T5e, T5s, T5t;
            T5d = T4r + T4s;
            T5e = KP707106781 * (T53 + T52);
            T5f = T5d + T5e;
            T5r = T5d - T5e;
            T5s = ((KP923879532 * T5g) - ((KP382683432) * (T5h)));
            T5t = (((KP923879532) * (T5k)) + (KP382683432 * T5j));
            T5u = T5s - T5t;
            T5w = T5s + T5t;
        }
        {
            E T5i, T5l, T5n, T5o;
            T5i = (((KP382683432) * (T5g)) + (KP923879532 * T5h));
            T5l = ((KP923879532 * T5j) - ((KP382683432) * (T5k)));
            T5m = T5i + T5l;
            T5q = T5l - T5i;
            T5n = T50 + T4Z;
            T5o = KP707106781 * (T4w + T4z);
            T5p = T5n - T5o;
            T5v = T5n + T5o;
        }
        ro[(os[18])] = T5f - T5m;
        io[(os[18])] = T5v - T5w;
        ro[(os[2])] = T5f + T5m;
        io[(os[2])] = T5v + T5w;
        io[(os[26])] = T5p - T5q;
        ro[(os[26])] = T5r - T5u;
        io[(os[10])] = T5p + T5q;
        ro[(os[10])] = T5r + T5u;
    }
    {
        E T5z, T5P, T5S, T5U, T5K, T5O, T5N, T5T;
        {
            E T5x, T5y, T5Q, T5R;
            T5x = T7 - Te;
            T5y = T1n - T1u;
            T5z = T5x + T5y;
            T5P = T5x - T5y;
            T5Q = T5D - T5A;
            T5R = T5F + T5I;
            T5S = KP707106781 * (T5Q - T5R);
            T5U = KP707106781 * (T5Q + T5R);
        }
        {
            E T5E, T5J, T5L, T5M;
            T5E = T5A + T5D;
            T5J = T5F - T5I;
            T5K = KP707106781 * (T5E + T5J);
            T5O = KP707106781 * (T5J - T5E);
            T5L = T18 - T1f;
            T5M = Tt - Tm;
            T5N = T5L - T5M;
            T5T = T5M + T5L;
        }
        ro[(os[20])] = T5z - T5K;
        io[(os[20])] = T5T - T5U;
        ro[(os[4])] = T5z + T5K;
        io[(os[4])] = T5T + T5U;
        io[(os[28])] = T5N - T5O;
        ro[(os[28])] = T5P - T5S;
        io[(os[12])] = T5N + T5O;
        ro[(os[12])] = T5P + T5S;
    }
    {
        E Tv, T5V, T5Y, T60, T10, T11, T1w, T5Z;
        {
            E Tf, Tu, T5W, T5X;
            Tf = T7 + Te;
            Tu = Tm + Tt;
            Tv = Tf + Tu;
            T5V = Tf - Tu;
            T5W = T5B + T5C;
            T5X = T5G + T5H;
            T5Y = T5W - T5X;
            T60 = T5W + T5X;
        }
        {
            E TK, TZ, T1g, T1v;
            TK = TC + TJ;
            TZ = TR + TY;
            T10 = TK + TZ;
            T11 = TZ - TK;
            T1g = T18 + T1f;
            T1v = T1n + T1u;
            T1w = T1g - T1v;
            T5Z = T1g + T1v;
        }
        ro[(os[16])] = Tv - T10;
        io[(os[16])] = T5Z - T60;
        ro[0] = Tv + T10;
        io[0] = T5Z + T60;
        io[(os[8])] = T11 + T1w;
        ro[(os[8])] = T5V + T5Y;
        io[(os[24])] = T1w - T11;
        ro[(os[24])] = T5V - T5Y;
    }
    {
        E T1X, T33, T31, T37, T2o, T34, T2P, T35;
        {
            E T1H, T1W, T2X, T30;
            T1H = T1z - T1G;
            T1W = T1O - T1V;
            T1X = T1H + T1W;
            T33 = T1H - T1W;
            T2X = T2T - T2W;
            T30 = T2Y - T2Z;
            T31 = T2X - T30;
            T37 = T2X + T30;
        }
        {
            E T2e, T2n, T2F, T2O;
            T2e = T22 - T2d;
            T2n = T2j - T2m;
            T2o = (((KP980785280) * (T2e)) + (KP195090322 * T2n));
            T34 = ((KP195090322 * T2e) - ((KP980785280) * (T2n)));
            T2F = T2t - T2E;
            T2O = T2K - T2N;
            T2P = ((KP195090322 * T2F) - ((KP980785280) * (T2O)));
            T35 = (((KP195090322) * (T2O)) + (KP980785280 * T2F));
        }
        {
            E T2Q, T38, T32, T36;
            T2Q = T2o + T2P;
            ro[(os[23])] = T1X - T2Q;
            ro[(os[7])] = T1X + T2Q;
            T38 = T34 + T35;
            io[(os[23])] = T37 - T38;
            io[(os[7])] = T37 + T38;
            T32 = T2P - T2o;
            io[(os[31])] = T31 - T32;
            io[(os[15])] = T31 + T32;
            T36 = T34 - T35;
            ro[(os[31])] = T33 - T36;
            ro[(os[15])] = T33 + T36;
        }
    }
    {
        E T3D, T41, T3Z, T45, T3K, T42, T3R, T43;
        {
            E T3v, T3C, T3V, T3Y;
            T3v = T3t - T3u;
            T3C = T3y - T3B;
            T3D = T3v + T3C;
            T41 = T3v - T3C;
            T3V = T3T - T3U;
            T3Y = T3W - T3X;
            T3Z = T3V - T3Y;
            T45 = T3V + T3Y;
        }
        {
            E T3G, T3J, T3N, T3Q;
            T3G = T3E - T3F;
            T3J = T3H - T3I;
            T3K = (((KP555570233) * (T3G)) + (KP831469612 * T3J));
            T42 = ((KP555570233 * T3J) - ((KP831469612) * (T3G)));
            T3N = T3L - T3M;
            T3Q = T3O - T3P;
            T3R = ((KP555570233 * T3N) - ((KP831469612) * (T3Q)));
            T43 = (((KP831469612) * (T3N)) + (KP555570233 * T3Q));
        }
        {
            E T3S, T46, T40, T44;
            T3S = T3K + T3R;
            ro[(os[21])] = T3D - T3S;
            ro[(os[5])] = T3D + T3S;
            T46 = T42 + T43;
            io[(os[21])] = T45 - T46;
            io[(os[5])] = T45 + T46;
            T40 = T3R - T3K;
            io[(os[29])] = T3Z - T40;
            io[(os[13])] = T3Z + T40;
            T44 = T42 - T43;
            ro[(os[29])] = T41 - T44;
            ro[(os[13])] = T41 + T44;
        }
    }
    {
        E T49, T4l, T4j, T4p, T4c, T4m, T4f, T4n;
        {
            E T47, T48, T4h, T4i;
            T47 = T3t + T3u;
            T48 = T3X + T3W;
            T49 = T47 + T48;
            T4l = T47 - T48;
            T4h = T3T + T3U;
            T4i = T3y + T3B;
            T4j = T4h - T4i;
            T4p = T4h + T4i;
        }
        {
            E T4a, T4b, T4d, T4e;
            T4a = T3E + T3F;
            T4b = T3H + T3I;
            T4c = (((KP980785280) * (T4a)) + (KP195090322 * T4b));
            T4m = ((KP980785280 * T4b) - ((KP195090322) * (T4a)));
            T4d = T3L + T3M;
            T4e = T3O + T3P;
            T4f = ((KP980785280 * T4d) - ((KP195090322) * (T4e)));
            T4n = (((KP195090322) * (T4d)) + (KP980785280 * T4e));
        }
        {
            E T4g, T4q, T4k, T4o;
            T4g = T4c + T4f;
            ro[(os[17])] = T49 - T4g;
            ro[(os[1])] = T49 + T4g;
            T4q = T4m + T4n;
            io[(os[17])] = T4p - T4q;
            io[(os[1])] = T4p + T4q;
            T4k = T4f - T4c;
            io[(os[25])] = T4j - T4k;
            io[(os[9])] = T4j + T4k;
            T4o = T4m - T4n;
            ro[(os[25])] = T4l - T4o;
            ro[(os[9])] = T4l + T4o;
        }
    }
    {
        E T3b, T3n, T3l, T3r, T3e, T3o, T3h, T3p;
        {
            E T39, T3a, T3j, T3k;
            T39 = T1z + T1G;
            T3a = T2Z + T2Y;
            T3b = T39 + T3a;
            T3n = T39 - T3a;
            T3j = T2T + T2W;
            T3k = T1O + T1V;
            T3l = T3j - T3k;
            T3r = T3j + T3k;
        }
        {
            E T3c, T3d, T3f, T3g;
            T3c = T22 + T2d;
            T3d = T2j + T2m;
            T3e = (((KP555570233) * (T3c)) + (KP831469612 * T3d));
            T3o = ((KP831469612 * T3c) - ((KP555570233) * (T3d)));
            T3f = T2t + T2E;
            T3g = T2K + T2N;
            T3h = ((KP831469612 * T3f) - ((KP555570233) * (T3g)));
            T3p = (((KP831469612) * (T3g)) + (KP555570233 * T3f));
        }
        {
            E T3i, T3s, T3m, T3q;
            T3i = T3e + T3h;
            ro[(os[19])] = T3b - T3i;
            ro[(os[3])] = T3b + T3i;
            T3s = T3o + T3p;
            io[(os[19])] = T3r - T3s;
            io[(os[3])] = T3r + T3s;
            T3m = T3h - T3e;
            io[(os[27])] = T3l - T3m;
            io[(os[11])] = T3l + T3m;
            T3q = T3o - T3p;
            ro[(os[27])] = T3n - T3q;
            ro[(os[11])] = T3n + T3q;
        }
    }
}
}
