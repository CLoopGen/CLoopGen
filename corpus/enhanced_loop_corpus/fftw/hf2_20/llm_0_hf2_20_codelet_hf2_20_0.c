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
extern  E KP587785252;
extern  E KP951056516;
extern  E KP250000000;
extern  E KP559016994;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 8); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 8 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T2, T5, Tg, Ti, Tk, To, T1h, T1f, T6, T3, T8, T14, T1Q, Tc, T1O;
    E T1v, T18, T1t, T1n, T24, T1j, T22, Tq, Tu, T1E, T1G, Tx, Ty, Tz, TJ;
    E T1Z, TB, T1X, T1A, TZ, TL, T1y, TX;
    for (INT inner = 0; inner < 1; ++inner) { // Artificial nesting depth increase
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
                    Tz = (((Tk) * (Tx)) + (To * Ty));
                    TJ = (((Tq) * (Tx)) + (Tu * Ty));
                    T1Z = ((T1f * Ty) - ((T1h) * (Tx)));
                    TB = ((Tk * Ty) - ((To) * (Tx)));
                    T1X = (((T1f) * (Tx)) + (T1h * Ty));
                    T1A = ((T2 * Ty) - ((T5) * (Tx)));
                    TZ = ((Tg * Ty) - ((Ti) * (Tx)));
                    TL = ((Tq * Ty) - ((Tu) * (Tx)));
                    T1y = (((T2) * (Tx)) + (T5 * Ty));
                    TX = (((Tg) * (Tx)) + (Ti * Ty));
                }
            }
        }
        {
            E TF, T2b, T4D, T4M, T2K, T3r, T4a, T4m, T1N, T28, T29, T3C, T3F, T43, T3X;
            E T3Y, T4o, T2f, T2g, T2h, T2y, T2D, T2E, T3g, T3h, T4z, T3n, T3o, T3p, T33;
            E T38, T4K, TW, T1r, T1s, T3J, T3M, T44, T3U, T3V, T4n, T2c, T2d, T2e, T2n;
            E T2s, T2t, T3d, T3e, T4y, T3k, T3l, T3m, T2S, T2X, T4J;
            {
                E T1, T47, Te, T46, Tw, T2H, TD, T2I, T9, Td;
                T1 = cr[0];
                T47 = ci[0];
                T9 = cr[(rs[10])];
                Td = ci[(rs[10])];
                Te = (((T8) * (T9)) + (Tc * Td));
                T46 = ((T8 * Td) - ((Tc) * (T9)));
                {
                    E Tr, Tv, TA, TC;
                    Tr = cr[(rs[5])];
                    Tv = ci[(rs[5])];
                    Tw = (((Tq) * (Tr)) + (Tu * Tv));
                    T2H = ((Tq * Tv) - ((Tu) * (Tr)));
                    TA = cr[(rs[15])];
                    TC = ci[(rs[15])];
                    TD = (((Tz) * (TA)) + (TB * TC));
                    T2I = ((Tz * TC) - ((TB) * (TA)));
                }
                {
                    E Tf, TE, T4B, T4C;
                    Tf = T1 + Te;
                    TE = Tw + TD;
                    TF = Tf - TE;
                    T2b = Tf + TE;
                    T4B = T47 - T46;
                    T4C = Tw - TD;
                    T4D = T4B - T4C;
                    T4M = T4C + T4B;
                }
                {
                    E T2G, T2J, T48, T49;
                    T2G = T1 - Te;
                    T2J = T2H - T2I;
                    T2K = T2G - T2J;
                    T3r = T2G + T2J;
                    T48 = T46 + T47;
                    T49 = T2H + T2I;
                    T4a = T48 - T49;
                    T4m = T49 + T48;
                }
            }
            {
                E T1D, T3A, T2u, T31, T27, T3D, T2C, T37, T1M, T3B, T2x, T32, T1W, T3E, T2z;
                E T36;
                {
                    E T1x, T2Z, T1C, T30;
                    {
                        E T1u, T1w, T1z, T1B;
                        T1u = cr[(rs[8])];
                        T1w = ci[(rs[8])];
                        T1x = (((T1t) * (T1u)) + (T1v * T1w));
                        T2Z = ((T1t * T1w) - ((T1v) * (T1u)));
                        T1z = cr[(rs[18])];
                        T1B = ci[(rs[18])];
                        T1C = (((T1y) * (T1z)) + (T1A * T1B));
                        T30 = ((T1y * T1B) - ((T1A) * (T1z)));
                    }
                    T1D = T1x + T1C;
                    T3A = T2Z + T30;
                    T2u = T1x - T1C;
                    T31 = T2Z - T30;
                }
                {
                    E T21, T2A, T26, T2B;
                    {
                        E T1Y, T20, T23, T25;
                        T1Y = cr[(rs[17])];
                        T20 = ci[(rs[17])];
                        T21 = (((T1X) * (T1Y)) + (T1Z * T20));
                        T2A = ((T1X * T20) - ((T1Z) * (T1Y)));
                        T23 = cr[(rs[7])];
                        T25 = ci[(rs[7])];
                        T26 = (((T22) * (T23)) + (T24 * T25));
                        T2B = ((T22 * T25) - ((T24) * (T23)));
                    }
                    T27 = T21 + T26;
                    T3D = T2A + T2B;
                    T2C = T2A - T2B;
                    T37 = T21 - T26;
                }
                {
                    E T1I, T2v, T1L, T2w;
                    {
                        E T1F, T1H, T1J, T1K;
                        T1F = cr[(rs[13])];
                        T1H = ci[(rs[13])];
                        T1I = (((T1E) * (T1F)) + (T1G * T1H));
                        T2v = ((T1E * T1H) - ((T1G) * (T1F)));
                        T1J = cr[(rs[3])];
                        T1K = ci[(rs[3])];
                        T1L = (((Tg) * (T1J)) + (Ti * T1K));
                        T2w = ((Tg * T1K) - ((Ti) * (T1J)));
                    }
                    T1M = T1I + T1L;
                    T3B = T2v + T2w;
                    T2x = T2v - T2w;
                    T32 = T1I - T1L;
                }
                {
                    E T1S, T34, T1V, T35;
                    {
                        E T1P, T1R, T1T, T1U;
                        T1P = cr[(rs[12])];
                        T1R = ci[(rs[12])];
                        T1S = (((T1O) * (T1P)) + (T1Q * T1R));
                        T34 = ((T1O * T1R) - ((T1Q) * (T1P)));
                        T1T = cr[(rs[2])];
                        T1U = ci[(rs[2])];
                        T1V = (((T1f) * (T1T)) + (T1h * T1U));
                        T35 = ((T1f * T1U) - ((T1h) * (T1T)));
                    }
                    T1W = T1S + T1V;
                    T3E = T34 + T35;
                    T2z = T1S - T1V;
                    T36 = T34 - T35;
                }
                T1N = T1D - T1M;
                T28 = T1W - T27;
                T29 = T1N + T28;
                T3C = T3A - T3B;
                T3F = T3D - T3E;
                T43 = T3F - T3C;
                T3X = T3A + T3B;
                T3Y = T3E + T3D;
                T4o = T3X + T3Y;
                T2f = T1D + T1M;
                T2g = T1W + T27;
                T2h = T2f + T2g;
                T2y = T2u - T2x;
                T2D = T2z - T2C;
                T2E = T2y + T2D;
                T3g = T31 - T32;
                T3h = T36 - T37;
                T4z = T3g + T3h;
                T3n = T2u + T2x;
                T3o = T2z + T2C;
                T3p = T3n + T3o;
                T33 = T31 + T32;
                T38 = T36 + T37;
                T4K = T33 + T38;
            }
            {
                E TO, T3H, T2j, T2Q, T1q, T3L, T2r, T2T, TV, T3I, T2m, T2R, T1b, T3K, T2o;
                E T2W;
                {
                    E TI, T2O, TN, T2P;
                    {
                        E TG, TH, TK, TM;
                        TG = cr[(rs[4])];
                        TH = ci[(rs[4])];
                        TI = (((Tk) * (TG)) + (To * TH));
                        T2O = ((Tk * TH) - ((To) * (TG)));
                        TK = cr[(rs[14])];
                        TM = ci[(rs[14])];
                        TN = (((TJ) * (TK)) + (TL * TM));
                        T2P = ((TJ * TM) - ((TL) * (TK)));
                    }
                    TO = TI + TN;
                    T3H = T2O + T2P;
                    T2j = TI - TN;
                    T2Q = T2O - T2P;
                }
                {
                    E T1e, T2p, T1p, T2q;
                    {
                        E T1c, T1d, T1k, T1o;
                        T1c = cr[(rs[1])];
                        T1d = ci[(rs[1])];
                        T1e = (((T2) * (T1c)) + (T5 * T1d));
                        T2p = ((T2 * T1d) - ((T5) * (T1c)));
                        T1k = cr[(rs[11])];
                        T1o = ci[(rs[11])];
                        T1p = (((T1j) * (T1k)) + (T1n * T1o));
                        T2q = ((T1j * T1o) - ((T1n) * (T1k)));
                    }
                    T1q = T1e + T1p;
                    T3L = T2p + T2q;
                    T2r = T2p - T2q;
                    T2T = T1p - T1e;
                }
                {
                    E TR, T2k, TU, T2l;
                    {
                        E TP, TQ, TS, TT;
                        TP = cr[(rs[9])];
                        TQ = ci[(rs[9])];
                        TR = (((T3) * (TP)) + (T6 * TQ));
                        T2k = ((T3 * TQ) - ((T6) * (TP)));
                        TS = cr[(rs[19])];
                        TT = ci[(rs[19])];
                        TU = (((Tx) * (TS)) + (Ty * TT));
                        T2l = ((Tx * TT) - ((Ty) * (TS)));
                    }
                    TV = TR + TU;
                    T3I = T2k + T2l;
                    T2m = T2k - T2l;
                    T2R = TR - TU;
                }
                {
                    E T11, T2U, T1a, T2V;
                    {
                        E TY, T10, T15, T19;
                        TY = cr[(rs[16])];
                        T10 = ci[(rs[16])];
                        T11 = (((TX) * (TY)) + (TZ * T10));
                        T2U = ((TX * T10) - ((TZ) * (TY)));
                        T15 = cr[(rs[6])];
                        T19 = ci[(rs[6])];
                        T1a = (((T14) * (T15)) + (T18 * T19));
                        T2V = ((T14 * T19) - ((T18) * (T15)));
                    }
                    T1b = T11 + T1a;
                    T3K = T2U + T2V;
                    T2o = T11 - T1a;
                    T2W = T2U - T2V;
                }
                TW = TO - TV;
                T1r = T1b - T1q;
                T1s = TW + T1r;
                T3J = T3H - T3I;
                T3M = T3K - T3L;
                T44 = T3J + T3M;
                T3U = T3H + T3I;
                T3V = T3K + T3L;
                T4n = T3U + T3V;
                T2c = TO + TV;
                T2d = T1b + T1q;
                T2e = T2c + T2d;
                T2n = T2j - T2m;
                T2s = T2o - T2r;
                T2t = T2n + T2s;
                T3d = T2Q - T2R;
                T3e = T2W + T2T;
                T4y = T3d + T3e;
                T3k = T2j + T2m;
                T3l = T2o + T2r;
                T3m = T3k + T3l;
                T2S = T2Q + T2R;
                T2X = T2T - T2W;
                T4J = T2X - T2S;
            }
            {
                E T3y, T2a, T3x, T3O, T3Q, T3G, T3N, T3P, T3z;
                T3y = KP559016994 * (T1s - T29);
                T2a = T1s + T29;
                T3x = ((TF) - ((KP250000000) * (T2a)));
                T3G = T3C + T3F;
                T3N = T3J - T3M;
                T3O = ((KP951056516 * T3G) - ((KP587785252) * (T3N)));
                T3Q = (((KP951056516) * (T3N)) + (KP587785252 * T3G));
                ci[(rs[9])] = TF + T2a;
                T3P = T3y + T3x;
                ci[(rs[5])] = T3P - T3Q;
                cr[(rs[6])] = T3P + T3Q;
                T3z = T3x - T3y;
                cr[(rs[2])] = T3z - T3O;
                ci[(rs[1])] = T3z + T3O;
            }
            {
                E T3q, T3s, T3t, T3j, T3w, T3f, T3i, T3v, T3u;
                T3q = KP559016994 * (T3m - T3p);
                T3s = T3m + T3p;
                T3t = ((T3r) - ((KP250000000) * (T3s)));
                T3f = T3d - T3e;
                T3i = T3g - T3h;
                T3j = (((KP951056516) * (T3f)) + (KP587785252 * T3i));
                T3w = ((KP951056516 * T3i) - ((KP587785252) * (T3f)));
                cr[(rs[5])] = T3r + T3s;
                T3v = T3t - T3q;
                ci[(rs[2])] = T3v - T3w;
                ci[(rs[6])] = T3w + T3v;
                T3u = T3q + T3t;
                cr[(rs[1])] = T3j + T3u;
                cr[(rs[9])] = T3u - T3j;
            }
            {
                E T3R, T2i, T3S, T40, T42, T3W, T3Z, T41, T3T;
                T3R = KP559016994 * (T2e - T2h);
                T2i = T2e + T2h;
                T3S = ((T2b) - ((KP250000000) * (T2i)));
                T3W = T3U - T3V;
                T3Z = T3X - T3Y;
                T40 = (((KP951056516) * (T3W)) + (KP587785252 * T3Z));
                T42 = ((KP951056516 * T3Z) - ((KP587785252) * (T3W)));
                cr[0] = T2b + T2i;
                T41 = T3S - T3R;
                ci[(rs[7])] = T41 - T42;
                cr[(rs[8])] = T41 + T42;
                T3T = T3R + T3S;
                cr[(rs[4])] = T3T - T40;
                ci[(rs[3])] = T3T + T40;
            }
            {
                E T2F, T2L, T2M, T3a, T3b, T2Y, T39, T3c, T2N;
                T2F = KP559016994 * (T2t - T2E);
                T2L = T2t + T2E;
                T2M = ((T2K) - ((KP250000000) * (T2L)));
                T2Y = T2S + T2X;
                T39 = T33 - T38;
                T3a = (((KP951056516) * (T2Y)) + (KP587785252 * T39));
                T3b = ((KP951056516 * T39) - ((KP587785252) * (T2Y)));
                ci[(rs[4])] = T2K + T2L;
                T3c = T2M - T2F;
                cr[(rs[3])] = T3b + T3c;
                cr[(rs[7])] = T3c - T3b;
                T2N = T2F + T2M;
                ci[0] = T2N - T3a;
                ci[(rs[8])] = T3a + T2N;
            }
            {
                E T4e, T45, T4f, T4d, T4h, T4b, T4c, T4i, T4g;
                T4e = KP559016994 * (T44 + T43);
                T45 = T43 - T44;
                T4f = (((KP250000000) * (T45)) + (T4a));
                T4b = T1r - TW;
                T4c = T1N - T28;
                T4d = ((KP951056516 * T4b) - ((KP587785252) * (T4c)));
                T4h = (((KP587785252) * (T4b)) + (KP951056516 * T4c));
                cr[(rs[10])] = T45 - T4a;
                T4i = T4f - T4e;
                cr[(rs[18])] = T4h - T4i;
                ci[(rs[17])] = T4h + T4i;
                T4g = T4e + T4f;
                cr[(rs[14])] = T4d - T4g;
                ci[(rs[13])] = T4d + T4g;
            }
            {
                E T4A, T4E, T4F, T4x, T4H, T4v, T4w, T4I, T4G;
                T4A = KP559016994 * (T4y - T4z);
                T4E = T4y + T4z;
                T4F = ((T4D) - ((KP250000000) * (T4E)));
                T4v = T3n - T3o;
                T4w = T3k - T3l;
                T4x = ((KP951056516 * T4v) - ((KP587785252) * (T4w)));
                T4H = (((KP951056516) * (T4w)) + (KP587785252 * T4v));
                ci[(rs[14])] = T4E + T4D;
                T4I = T4A + T4F;
                ci[(rs[10])] = T4H + T4I;
                ci[(rs[18])] = T4I - T4H;
                T4G = T4A - T4F;
                cr[(rs[13])] = T4x + T4G;
                cr[(rs[17])] = T4G - T4x;
            }
            {
                E T4r, T4p, T4q, T4l, T4t, T4j, T4k, T4u, T4s;
                T4r = KP559016994 * (T4n - T4o);
                T4p = T4n + T4o;
                T4q = ((T4m) - ((KP250000000) * (T4p)));
                T4j = T2c - T2d;
                T4k = T2f - T2g;
                T4l = ((KP587785252 * T4j) - ((KP951056516) * (T4k)));
                T4t = (((KP951056516) * (T4j)) + (KP587785252 * T4k));
                ci[(rs[19])] = T4p + T4m;
                T4u = T4r + T4q;
                cr[(rs[16])] = T4t - T4u;
                ci[(rs[15])] = T4t + T4u;
                T4s = T4q - T4r;
                cr[(rs[12])] = T4l - T4s;
                ci[(rs[11])] = T4l + T4s;
            }
            {
                E T4Q, T4L, T4R, T4P, T4T, T4N, T4O, T4U, T4S;
                T4Q = KP559016994 * (T4J + T4K);
                T4L = T4J - T4K;
                T4R = (((KP250000000) * (T4L)) + (T4M));
                T4N = T2n - T2s;
                T4O = T2y - T2D;
                T4P = (((KP951056516) * (T4N)) + (KP587785252 * T4O));
                T4T = ((KP951056516 * T4O) - ((KP587785252) * (T4N)));
                cr[(rs[15])] = T4L - T4M;
                T4U = T4Q + T4R;
                ci[(rs[12])] = T4T + T4U;
                ci[(rs[16])] = T4U - T4T;
                T4S = T4Q - T4R;
                cr[(rs[11])] = T4P + T4S;
                cr[(rs[19])] = T4S - T4P;
            }
        }
    }
}
}
