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
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + (mb * 8); m < me; m = m + 1 , ri = ri + ms , ii = ii + ms , W = W + 8 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T2, T5, Tg, Ti, Tk, To, T1h, T1f, T6, T3, T8, T14, T1Q, Tc, T1O;
    E T1v, T18, T1t, T1n, T24, T1j, T22, Tq, Tu, T1E, T1G, Tx, Ty, Tz, TJ;
    E T1Z, TB, T1X, T1A, TZ, TL, T1y, TX;
    {
        E T7, T16, Ta, T13, T4, T17, Tb, T12;
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
            T1h = Tm - Tn;
            T1f = Th + Tj;
            T6 = W[5];
            T7 = T5 * T6;
            T16 = Tg * T6;
            Ta = T2 * T6;
            T13 = Ti * T6;
            T3 = W[4];
            T4 = T2 * T3;
            T17 = Ti * T3;
            Tb = T5 * T3;
            T12 = Tg * T3;
        }
        T8 = T4 - T7;
        T14 = T12 + T13;
        T1Q = T16 + T17;
        Tc = Ta + Tb;
        T1O = T12 - T13;
        T1v = Ta - Tb;
        T18 = T16 - T17;
        T1t = T4 + T7;
        {
            E T1l, T1m, T1g, T1i;
            T1l = T1f * T6;
            T1m = T1h * T3;
            T1n = T1l + T1m;
            T24 = T1l - T1m;
            T1g = T1f * T3;
            T1i = T1h * T6;
            T1j = T1g - T1i;
            T22 = T1g + T1i;
            {
                E Tl, Tp, Ts, Tt;
                Tl = Tk * T3;
                Tp = To * T6;
                Tq = Tl + Tp;
                Ts = Tk * T6;
                Tt = To * T3;
                Tu = Ts - Tt;
                T1E = Tl - Tp;
                T1G = Ts + Tt;
                Tx = W[6];
                Ty = W[7];
                Tz = Tk * Tx + To * Ty;
                TJ = Tq * Tx + Tu * Ty;
                T1Z = T1f * Ty - T1h * Tx;
                TB = Tk * Ty - To * Tx;
                T1X = T1f * Tx + T1h * Ty;
                T1A = T2 * Ty - T5 * Tx;
                TZ = Tg * Ty - Ti * Tx;
                TL = Tq * Ty - Tu * Tx;
                T1y = T2 * Tx + T5 * Ty;
                TX = Tg * Tx + Ti * Ty;
            }
        }
    }
    {
        E TF, T2b, T4A, T4J, T2K, T3r, T4a, T4m, T1N, T28, T29, T3C, T3F, T4o, T3X;
        E T3Y, T44, T2f, T2g, T2h, T2n, T2s, T4L, T3g, T3h, T4w, T3n, T3o, T3p, T30;
        E T35, T36, TW, T1r, T1s, T3J, T3M, T4n, T3U, T3V, T43, T2c, T2d, T2e, T2y;
        E T2D, T4K, T3d, T3e, T4v, T3k, T3l, T3m, T2P, T2U, T2V;
        {
            E T1, T48, Te, T47, Tw, T2H, TD, T2I, T9, Td;
            T1 = ri[0];
            T48 = ii[0];
            T9 = ri[(rs[10])];
            Td = ii[(rs[10])];
            Te = T8 * T9 + Tc * Td;
            T47 = T8 * Td - Tc * T9;
            {
                E Tr, Tv, TA, TC;
                Tr = ri[(rs[5])];
                Tv = ii[(rs[5])];
                Tw = Tq * Tr + Tu * Tv;
                T2H = Tq * Tv - Tu * Tr;
                TA = ri[(rs[15])];
                TC = ii[(rs[15])];
                TD = Tz * TA + TB * TC;
                T2I = Tz * TC - TB * TA;
            }
            {
                E Tf, TE, T4y, T4z;
                Tf = T1 + Te;
                TE = Tw + TD;
                TF = Tf - TE;
                T2b = Tf + TE;
                T4y = T48 - T47;
                T4z = Tw - TD;
                T4A = T4y - T4z;
                T4J = T4z + T4y;
            }
            {
                E T2G, T2J, T46, T49;
                T2G = T1 - Te;
                T2J = T2H - T2I;
                T2K = T2G - T2J;
                T3r = T2G + T2J;
                T46 = T2H + T2I;
                T49 = T47 + T48;
                T4a = T46 + T49;
                T4m = T49 - T46;
            }
        }
        {
            E T1D, T3A, T2l, T2W, T27, T3E, T2r, T34, T1M, T3B, T2m, T2Z, T1W, T3D, T2q;
            E T31;
            {
                E T1x, T2j, T1C, T2k;
                {
                    E T1u, T1w, T1z, T1B;
                    T1u = ri[(rs[8])];
                    T1w = ii[(rs[8])];
                    T1x = T1t * T1u + T1v * T1w;
                    T2j = T1t * T1w - T1v * T1u;
                    T1z = ri[(rs[18])];
                    T1B = ii[(rs[18])];
                    T1C = T1y * T1z + T1A * T1B;
                    T2k = T1y * T1B - T1A * T1z;
                }
                T1D = T1x + T1C;
                T3A = T2j + T2k;
                T2l = T2j - T2k;
                T2W = T1x - T1C;
            }
            {
                E T21, T32, T26, T33;
                {
                    E T1Y, T20, T23, T25;
                    T1Y = ri[(rs[17])];
                    T20 = ii[(rs[17])];
                    T21 = T1X * T1Y + T1Z * T20;
                    T32 = T1X * T20 - T1Z * T1Y;
                    T23 = ri[(rs[7])];
                    T25 = ii[(rs[7])];
                    T26 = T22 * T23 + T24 * T25;
                    T33 = T22 * T25 - T24 * T23;
                }
                T27 = T21 + T26;
                T3E = T32 + T33;
                T2r = T21 - T26;
                T34 = T32 - T33;
            }
            {
                E T1I, T2X, T1L, T2Y;
                {
                    E T1F, T1H, T1J, T1K;
                    T1F = ri[(rs[13])];
                    T1H = ii[(rs[13])];
                    T1I = T1E * T1F + T1G * T1H;
                    T2X = T1E * T1H - T1G * T1F;
                    T1J = ri[(rs[3])];
                    T1K = ii[(rs[3])];
                    T1L = Tg * T1J + Ti * T1K;
                    T2Y = Tg * T1K - Ti * T1J;
                }
                T1M = T1I + T1L;
                T3B = T2X + T2Y;
                T2m = T1I - T1L;
                T2Z = T2X - T2Y;
            }
            {
                E T1S, T2o, T1V, T2p;
                {
                    E T1P, T1R, T1T, T1U;
                    T1P = ri[(rs[12])];
                    T1R = ii[(rs[12])];
                    T1S = T1O * T1P + T1Q * T1R;
                    T2o = T1O * T1R - T1Q * T1P;
                    T1T = ri[(rs[2])];
                    T1U = ii[(rs[2])];
                    T1V = T1f * T1T + T1h * T1U;
                    T2p = T1f * T1U - T1h * T1T;
                }
                T1W = T1S + T1V;
                T3D = T2o + T2p;
                T2q = T2o - T2p;
                T31 = T1S - T1V;
            }
            T1N = T1D - T1M;
            T28 = T1W - T27;
            T29 = T1N + T28;
            T3C = T3A - T3B;
            T3F = T3D - T3E;
            T4o = T3C + T3F;
            T3X = T3A + T3B;
            T3Y = T3D + T3E;
            T44 = T3X + T3Y;
            T2f = T1D + T1M;
            T2g = T1W + T27;
            T2h = T2f + T2g;
            T2n = T2l + T2m;
            T2s = T2q + T2r;
            T4L = T2n + T2s;
            T3g = T2l - T2m;
            T3h = T2q - T2r;
            T4w = T3g + T3h;
            T3n = T2W + T2Z;
            T3o = T31 + T34;
            T3p = T3n + T3o;
            T30 = T2W - T2Z;
            T35 = T31 - T34;
            T36 = T30 + T35;
        }
        {
            E TO, T3H, T2w, T2L, T1q, T3L, T2C, T2T, TV, T3I, T2x, T2O, T1b, T3K, T2B;
            E T2Q;
            {
                E TI, T2u, TN, T2v;
                {
                    E TG, TH, TK, TM;
                    TG = ri[(rs[4])];
                    TH = ii[(rs[4])];
                    TI = Tk * TG + To * TH;
                    T2u = Tk * TH - To * TG;
                    TK = ri[(rs[14])];
                    TM = ii[(rs[14])];
                    TN = TJ * TK + TL * TM;
                    T2v = TJ * TM - TL * TK;
                }
                TO = TI + TN;
                T3H = T2u + T2v;
                T2w = T2u - T2v;
                T2L = TI - TN;
            }
            {
                E T1e, T2R, T1p, T2S;
                {
                    E T1c, T1d, T1k, T1o;
                    T1c = ri[(rs[1])];
                    T1d = ii[(rs[1])];
                    T1e = T2 * T1c + T5 * T1d;
                    T2R = T2 * T1d - T5 * T1c;
                    T1k = ri[(rs[11])];
                    T1o = ii[(rs[11])];
                    T1p = T1j * T1k + T1n * T1o;
                    T2S = T1j * T1o - T1n * T1k;
                }
                T1q = T1e + T1p;
                T3L = T2R + T2S;
                T2C = T1e - T1p;
                T2T = T2R - T2S;
            }
            {
                E TR, T2M, TU, T2N;
                {
                    E TP, TQ, TS, TT;
                    TP = ri[(rs[9])];
                    TQ = ii[(rs[9])];
                    TR = T3 * TP + T6 * TQ;
                    T2M = T3 * TQ - T6 * TP;
                    TS = ri[(rs[19])];
                    TT = ii[(rs[19])];
                    TU = Tx * TS + Ty * TT;
                    T2N = Tx * TT - Ty * TS;
                }
                TV = TR + TU;
                T3I = T2M + T2N;
                T2x = TR - TU;
                T2O = T2M - T2N;
            }
            {
                E T11, T2z, T1a, T2A;
                {
                    E TY, T10, T15, T19;
                    TY = ri[(rs[16])];
                    T10 = ii[(rs[16])];
                    T11 = TX * TY + TZ * T10;
                    T2z = TX * T10 - TZ * TY;
                    T15 = ri[(rs[6])];
                    T19 = ii[(rs[6])];
                    T1a = T14 * T15 + T18 * T19;
                    T2A = T14 * T19 - T18 * T15;
                }
                T1b = T11 + T1a;
                T3K = T2z + T2A;
                T2B = T2z - T2A;
                T2Q = T11 - T1a;
            }
            TW = TO - TV;
            T1r = T1b - T1q;
            T1s = TW + T1r;
            T3J = T3H - T3I;
            T3M = T3K - T3L;
            T4n = T3J + T3M;
            T3U = T3H + T3I;
            T3V = T3K + T3L;
            T43 = T3U + T3V;
            T2c = TO + TV;
            T2d = T1b + T1q;
            T2e = T2c + T2d;
            T2y = T2w + T2x;
            T2D = T2B + T2C;
            T4K = T2y + T2D;
            T3d = T2w - T2x;
            T3e = T2B - T2C;
            T4v = T3d + T3e;
            T3k = T2L + T2O;
            T3l = T2Q + T2T;
            T3m = T3k + T3l;
            T2P = T2L - T2O;
            T2U = T2Q - T2T;
            T2V = T2P + T2U;
        }
        {
            E T3y, T2a, T3x, T3O, T3Q, T3G, T3N, T3P, T3z;
            T3y = KP559016994 * (T1s - T29);
            T2a = T1s + T29;
            T3x = TF - KP250000000 * T2a;
            T3G = T3C - T3F;
            T3N = T3J - T3M;
            T3O = KP951056516 * T3G - KP587785252 * T3N;
            T3Q = KP951056516 * T3N + KP587785252 * T3G;
            ri[(rs[10])] = TF + T2a;
            T3P = T3y + T3x;
            ri[(rs[14])] = T3P - T3Q;
            ri[(rs[6])] = T3P + T3Q;
            T3z = T3x - T3y;
            ri[(rs[2])] = T3z - T3O;
            ri[(rs[18])] = T3z + T3O;
        }
        {
            E T4r, T4p, T4q, T4l, T4u, T4j, T4k, T4t, T4s;
            T4r = KP559016994 * (T4n - T4o);
            T4p = T4n + T4o;
            T4q = T4m - KP250000000 * T4p;
            T4j = T1N - T28;
            T4k = TW - T1r;
            T4l = KP951056516 * T4j - KP587785252 * T4k;
            T4u = KP951056516 * T4k + KP587785252 * T4j;
            ii[(rs[10])] = T4p + T4m;
            T4t = T4r + T4q;
            ii[(rs[6])] = T4t - T4u;
            ii[(rs[14])] = T4u + T4t;
            T4s = T4q - T4r;
            ii[(rs[2])] = T4l + T4s;
            ii[(rs[18])] = T4s - T4l;
        }
        {
            E T3R, T2i, T3S, T40, T42, T3W, T3Z, T41, T3T;
            T3R = KP559016994 * (T2e - T2h);
            T2i = T2e + T2h;
            T3S = T2b - KP250000000 * T2i;
            T3W = T3U - T3V;
            T3Z = T3X - T3Y;
            T40 = KP951056516 * T3W + KP587785252 * T3Z;
            T42 = KP951056516 * T3Z - KP587785252 * T3W;
            ri[0] = T2b + T2i;
            T41 = T3S - T3R;
            ri[(rs[12])] = T41 - T42;
            ri[(rs[8])] = T41 + T42;
            T3T = T3R + T3S;
            ri[(rs[4])] = T3T - T40;
            ri[(rs[16])] = T3T + T40;
        }
        {
            E T4e, T45, T4f, T4d, T4i, T4b, T4c, T4h, T4g;
            T4e = KP559016994 * (T43 - T44);
            T45 = T43 + T44;
            T4f = T4a - KP250000000 * T45;
            T4b = T2c - T2d;
            T4c = T2f - T2g;
            T4d = KP951056516 * T4b + KP587785252 * T4c;
            T4i = KP951056516 * T4c - KP587785252 * T4b;
            ii[0] = T45 + T4a;
            T4h = T4f - T4e;
            ii[(rs[8])] = T4h - T4i;
            ii[(rs[12])] = T4i + T4h;
            T4g = T4e + T4f;
            ii[(rs[4])] = T4d + T4g;
            ii[(rs[16])] = T4g - T4d;
        }
        {
            E T39, T37, T38, T2F, T3b, T2t, T2E, T3c, T3a;
            T39 = KP559016994 * (T2V - T36);
            T37 = T2V + T36;
            T38 = T2K - KP250000000 * T37;
            T2t = T2n - T2s;
            T2E = T2y - T2D;
            T2F = KP951056516 * T2t - KP587785252 * T2E;
            T3b = KP951056516 * T2E + KP587785252 * T2t;
            ri[(rs[15])] = T2K + T37;
            T3c = T39 + T38;
            ri[(rs[11])] = T3b + T3c;
            ri[(rs[19])] = T3c - T3b;
            T3a = T38 - T39;
            ri[(rs[3])] = T2F + T3a;
            ri[(rs[7])] = T3a - T2F;
        }
        {
            E T4O, T4M, T4N, T4S, T4U, T4Q, T4R, T4T, T4P;
            T4O = KP559016994 * (T4K - T4L);
            T4M = T4K + T4L;
            T4N = T4J - KP250000000 * T4M;
            T4Q = T30 - T35;
            T4R = T2P - T2U;
            T4S = KP951056516 * T4Q - KP587785252 * T4R;
            T4U = KP951056516 * T4R + KP587785252 * T4Q;
            ii[(rs[15])] = T4M + T4J;
            T4T = T4O + T4N;
            ii[(rs[11])] = T4T - T4U;
            ii[(rs[19])] = T4U + T4T;
            T4P = T4N - T4O;
            ii[(rs[3])] = T4P - T4S;
            ii[(rs[7])] = T4S + T4P;
        }
        {
            E T3q, T3s, T3t, T3j, T3v, T3f, T3i, T3w, T3u;
            T3q = KP559016994 * (T3m - T3p);
            T3s = T3m + T3p;
            T3t = T3r - KP250000000 * T3s;
            T3f = T3d - T3e;
            T3i = T3g - T3h;
            T3j = KP951056516 * T3f + KP587785252 * T3i;
            T3v = KP951056516 * T3i - KP587785252 * T3f;
            ri[(rs[5])] = T3r + T3s;
            T3w = T3t - T3q;
            ri[(rs[13])] = T3v + T3w;
            ri[(rs[17])] = T3w - T3v;
            T3u = T3q + T3t;
            ri[(rs[1])] = T3j + T3u;
            ri[(rs[9])] = T3u - T3j;
        }
        {
            E T4x, T4B, T4C, T4G, T4I, T4E, T4F, T4H, T4D;
            T4x = KP559016994 * (T4v - T4w);
            T4B = T4v + T4w;
            T4C = T4A - KP250000000 * T4B;
            T4E = T3k - T3l;
            T4F = T3n - T3o;
            T4G = KP951056516 * T4E + KP587785252 * T4F;
            T4I = KP951056516 * T4F - KP587785252 * T4E;
            ii[(rs[5])] = T4B + T4A;
            T4H = T4C - T4x;
            ii[(rs[13])] = T4H - T4I;
            ii[(rs[17])] = T4I + T4H;
            T4D = T4x + T4C;
            ii[(rs[1])] = T4D - T4G;
            ii[(rs[9])] = T4G + T4D;
        }
    }
}
}
