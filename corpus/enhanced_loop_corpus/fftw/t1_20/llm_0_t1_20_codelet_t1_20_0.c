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
    for (m = mb, W = W + (mb * 38); m < me; m = m + 1, ri = ri + ms, ii = ii + ms, W = W + 38, (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
        E Tj, T1R, T4g, T4p, T2q, T37, T3Q, T42, T1r, T1O, T1P, T3i, T3l, T44, T3D;
        E T3E, T3K, T1V, T1W, T1X, T23, T28, T4r, T2W, T2X, T4c, T33, T34, T35, T2G;
        E T2L, T2M, TG, T13, T14, T3p, T3s, T43, T3A, T3B, T3J, T1S, T1T, T1U, T2e;
        E T2j, T4q, T2T, T2U, T4b, T30, T31, T32, T2v, T2A, T2B;

        // First unrolled iteration to simulate deeper nesting effect via code expansion
        {
            E T1, T3O, T6, T3N, Tc, T2n, Th, T2o;
            T1 = ri[0];
            T3O = ii[0];
            {
                E T3, T5, T2, T4;
                T3 = ri[(rs[10])];
                T5 = ii[(rs[10])];
                T2 = W[18];
                T4 = W[19];
                T6 = (((T2) * (T3)) + (T4 * T5));
                T3N = ((T2 * T5) - ((T4) * (T3)));
            }
            {
                E T9, Tb, T8, Ta;
                T9 = ri[(rs[5])];
                Tb = ii[(rs[5])];
                T8 = W[8];
                Ta = W[9];
                Tc = (((T8) * (T9)) + (Ta * Tb));
                T2n = ((T8 * Tb) - ((Ta) * (T9)));
            }
            {
                E Te, Tg, Td, Tf;
                Te = ri[(rs[15])];
                Tg = ii[(rs[15])];
                Td = W[28];
                Tf = W[29];
                Th = (((Td) * (Te)) + (Tf * Tg));
                T2o = ((Td * Tg) - ((Tf) * (Te)));
            }
            {
                E T7, Ti, T4e, T4f;
                T7 = T1 + T6;
                Ti = Tc + Th;
                Tj = T7 - Ti;
                T1R = T7 + Ti;
                T4e = T3O - T3N;
                T4f = Tc - Th;
                T4g = T4e - T4f;
                T4p = T4f + T4e;
            }
            {
                E T2m, T2p, T3M, T3P;
                T2m = T1 - T6;
                T2p = T2n - T2o;
                T2q = T2m - T2p;
                T37 = T2m + T2p;
                T3M = T2n + T2o;
                T3P = T3N + T3O;
                T3Q = T3M + T3P;
                T42 = T3P - T3M;
            }
        }

        // Simulated "nested" loop via repeated block with index-like progression (no actual nesting)
        for (INT inner = 0; inner < 1; ++inner) {
            {
                E T1f, T3g, T21, T2C, T1N, T3k, T27, T2K, T1q, T3h, T22, T2F, T1C, T3j, T26;
                E T2H;
                {
                    E T19, T1Z, T1e, T20;
                    {
                        E T16, T18, T15, T17;
                        T16 = ri[(rs[8])];
                        T18 = ii[(rs[8])];
                        T15 = W[14];
                        T17 = W[15];
                        T19 = (((T15) * (T16)) + (T17 * T18));
                        T1Z = ((T15 * T18) - ((T17) * (T16)));
                    }
                    {
                        E T1b, T1d, T1a, T1c;
                        T1b = ri[(rs[18])];
                        T1d = ii[(rs[18])];
                        T1a = W[34];
                        T1c = W[35];
                        T1e = (((T1a) * (T1b)) + (T1c * T1d));
                        T20 = ((T1a * T1d) - ((T1c) * (T1b)));
                    }
                    T1f = T19 + T1e;
                    T3g = T1Z + T20;
                    T21 = T1Z - T20;
                    T2C = T19 - T1e;
                }
                {
                    E T1H, T2I, T1M, T2J;
                    {
                        E T1E, T1G, T1D, T1F;
                        T1E = ri[(rs[17])];
                        T1G = ii[(rs[17])];
                        T1D = W[32];
                        T1F = W[33];
                        T1H = (((T1D) * (T1E)) + (T1F * T1G));
                        T2I = ((T1D * T1G) - ((T1F) * (T1E)));
                    }
                    {
                        E T1J, T1L, T1I, T1K;
                        T1J = ri[(rs[7])];
                        T1L = ii[(rs[7])];
                        T1I = W[12];
                        T1K = W[13];
                        T1M = (((T1I) * (T1J)) + (T1K * T1L));
                        T2J = ((T1I * T1L) - ((T1K) * (T1J)));
                    }
                    T1N = T1H + T1M;
                    T3k = T2I + T2J;
                    T27 = T1H - T1M;
                    T2K = T2I - T2J;
                }
                {
                    E T1k, T2D, T1p, T2E;
                    {
                        E T1h, T1j, T1g, T1i;
                        T1h = ri[(rs[13])];
                        T1j = ii[(rs[13])];
                        T1g = W[24];
                        T1i = W[25];
                        T1k = (((T1g) * (T1h)) + (T1i * T1j));
                        T2D = ((T1g * T1j) - ((T1i) * (T1h)));
                    }
                    {
                        E T1m, T1o, T1l, T1n;
                        T1m = ri[(rs[3])];
                        T1o = ii[(rs[3])];
                        T1l = W[4];
                        T1n = W[5];
                        T1p = (((T1l) * (T1m)) + (T1n * T1o));
                        T2E = ((T1l * T1o) - ((T1n) * (T1m)));
                    }
                    T1q = T1k + T1p;
                    T3h = T2D + T2E;
                    T22 = T1k - T1p;
                    T2F = T2D - T2E;
                }
                {
                    E T1w, T24, T1B, T25;
                    {
                        E T1t, T1v, T1s, T1u;
                        T1t = ri[(rs[12])];
                        T1v = ii[(rs[12])];
                        T1s = W[22];
                        T1u = W[23];
                        T1w = (((T1s) * (T1t)) + (T1u * T1v));
                        T24 = ((T1s * T1v) - ((T1u) * (T1t)));
                    }
                    {
                        E T1y, T1A, T1x, T1z;
                        T1y = ri[(rs[2])];
                        T1A = ii[(rs[2])];
                        T1x = W[2];
                        T1z = W[3];
                        T1B = (((T1x) * (T1y)) + (T1z * T1A));
                        T25 = ((T1x * T1A) - ((T1z) * (T1y)));
                    }
                    T1C = T1w + T1B;
                    T3j = T24 + T25;
                    T26 = T24 - T25;
                    T2H = T1w - T1B;
                }
                T1r = T1f - T1q;
                T1O = T1C - T1N;
                T1P = T1r + T1O;
                T3i = T3g - T3h;
                T3l = T3j - T3k;
                T44 = T3i + T3l;
                T3D = T3g + T3h;
                T3E = T3j + T3k;
                T3K = T3D + T3E;
                T1V = T1f + T1q;
                T1W = T1C + T1N;
                T1X = T1V + T1W;
                T23 = T21 + T22;
                T28 = T26 + T27;
                T4r = T23 + T28;
                T2W = T21 - T22;
                T2X = T26 - T27;
                T4c = T2W + T2X;
                T33 = T2C + T2F;
                T34 = T2H + T2K;
                T35 = T33 + T34;
                T2G = T2C - T2F;
                T2L = T2H - T2K;
                T2M = T2G + T2L;
            }
        }

        // Continue with rest of original logic
        {
            E Tu, T3n, T2c, T2r, T12, T3r, T2i, T2z, TF, T3o, T2d, T2u, TR, T3q, T2h;
            E T2w;
            {
                E To, T2a, Tt, T2b;
                {
                    E Tl, Tn, Tk, Tm;
                    Tl = ri[(rs[4])];
                    Tn = ii[(rs[4])];
                    Tk = W[6];
                    Tm = W[7];
                    To = (((Tk) * (Tl)) + (Tm * Tn));
                    T2a = ((Tk * Tn) - ((Tm) * (Tl)));
                }
                {
                    E Tq, Ts, Tp, Tr;
                    Tq = ri[(rs[14])];
                    Ts = ii[(rs[14])];
                    Tp = W[26];
                    Tr = W[27];
                    Tt = (((Tp) * (Tq)) + (Tr * Ts));
                    T2b = ((Tp * Ts) - ((Tr) * (Tq)));
                }
                Tu = To + Tt;
                T3n = T2a + T2b;
                T2c = T2a - T2b;
                T2r = To - Tt;
            }
            {
                E TW, T2x, T11, T2y;
                {
                    E TT, TV, TS, TU;
                    TT = ri[(rs[1])];
                    TV = ii[(rs[1])];
                    TS = W[0];
                    TU = W[1];
                    TW = (((TS) * (TT)) + (TU * TV));
                    T2x = ((TS * TV) - ((TU) * (TT)));
                }
                {
                    E TY, T10, TX, TZ;
                    TY = ri[(rs[11])];
                    T10 = ii[(rs[11])];
                    TX = W[20];
                    TZ = W[21];
                    T11 = (((TX) * (TY)) + (TZ * T10));
                    T2y = ((TX * T10) - ((TZ) * (TY)));
                }
                T12 = TW + T11;
                T3r = T2x + T2y;
                T2i = TW - T11;
                T2z = T2x - T2y;
            }
            {
                E Tz, T2s, TE, T2t;
                {
                    E Tw, Ty, Tv, Tx;
                    Tw = ri[(rs[9])];
                    Ty = ii[(rs[9])];
                    Tv = W[16];
                    Tx = W[17];
                    Tz = (((Tv) * (Tw)) + (Tx * Ty));
                    T2s = ((Tv * Ty) - ((Tx) * (Tw)));
                }
                {
                    E TB, TD, TA, TC;
                    TB = ri[(rs[19])];
                    TD = ii[(rs[19])];
                    TA = W[36];
                    TC = W[37];
                    TE = (((TA) * (TB)) + (TC * TD));
                    T2t = ((TA * TD) - ((TC) * (TB)));
                }
                TF = Tz + TE;
                T3o = T2s + T2t;
                T2d = Tz - TE;
                T2u = T2s - T2t;
            }
            {
                E TL, T2f, TQ, T2g;
                {
                    E TI, TK, TH, TJ;
                    TI = ri[(rs[16])];
                    TK = ii[(rs[16])];
                    TH = W[30];
                    TJ = W[31];
                    TL = (((TH) * (TI)) + (TJ * TK));
                    T2f = ((TH * TK) - ((TJ) * (TI)));
                }
                {
                    E TN, TP, TM, TO;
                    TN = ri[(rs[6])];
                    TP = ii[(rs[6])];
                    TM = W[10];
                    TO = W[11];
                    TQ = (((TM) * (TN)) + (TO * TP));
                    T2g = ((TM * TP) - ((TO) * (TN)));
                }
                TR = TL + TQ;
                T3q = T2f + T2g;
                T2h = T2f - T2g;
                T2w = TL - TQ;
            }
            TG = Tu - TF;
            T13 = TR - T12;
            T14 = TG + T13;
            T3p = T3n - T3o;
            T3s = T3q - T3r;
            T43 = T3p + T3s;
            T3A = T3n + T3o;
            T3B = T3q + T3r;
            T3J = T3A + T3B;
            T1S = Tu + TF;
            T1T = TR + T12;
            T1U = T1S + T1T;
            T2e = T2c + T2d;
            T2j = T2h + T2i;
            T4q = T2e + T2j;
            T2T = T2c - T2d;
            T2U = T2h - T2i;
            T4b = T2T + T2U;
            T30 = T2r + T2u;
            T31 = T2w + T2z;
            T32 = T30 + T31;
            T2v = T2r - T2u;
            T2A = T2w - T2z;
            T2B = T2v + T2A;
        }

        {
            E T3e, T1Q, T3d, T3u, T3w, T3m, T3t, T3v, T3f;
            T3e = KP559016994 * (T14 - T1P);
            T1Q = T14 + T1P;
            T3d = ((Tj) - ((KP250000000) * (T1Q)));
            T3m = T3i - T3l;
            T3t = T3p - T3s;
            T3u = ((KP951056516 * T3m) - ((KP587785252) * (T3t)));
            T3w = (((KP951056516) * (T3t)) + (KP587785252 * T3m));
            ri[(rs[10])] = Tj + T1Q;
            T3v = T3e + T3d;
            ri[(rs[14])] = T3v - T3w;
            ri[(rs[6])] = T3v + T3w;
            T3f = T3d - T3e;
            ri[(rs[2])] = T3f - T3u;
            ri[(rs[18])] = T3f + T3u;
        }
        {
            E T47, T45, T46, T41, T4a, T3Z, T40, T49, T48;
            T47 = KP559016994 * (T43 - T44);
            T45 = T43 + T44;
            T46 = ((T42) - ((KP250000000) * (T45)));
            T3Z = T1r - T1O;
            T40 = TG - T13;
            T41 = ((KP951056516 * T3Z) - ((KP587785252) * (T40)));
            T4a = (((KP951056516) * (T40)) + (KP587785252 * T3Z));
            ii[(rs[10])] = T45 + T42;
            T49 = T47 + T46;
            ii[(rs[6])] = T49 - T4a;
            ii[(rs[14])] = T4a + T49;
            T48 = T46 - T47;
            ii[(rs[2])] = T41 + T48;
            ii[(rs[18])] = T48 - T41;
        }
        {
            E T3x, T1Y, T3y, T3G, T3I, T3C, T3F, T3H, T3z;
            T3x = KP559016994 * (T1U - T1X);
            T1Y = T1U + T1X;
            T3y = ((T1R) - ((KP250000000) * (T1Y)));
            T3C = T3A - T3B;
            T3F = T3D - T3E;
            T3G = (((KP951056516) * (T3C)) + (KP587785252 * T3F));
            T3I = ((KP951056516 * T3F) - ((KP587785252) * (T3C)));
            ri[0] = T1R + T1Y;
            T3H = T3y - T3x;
            ri[(rs[12])] = T3H - T3I;
            ri[(rs[8])] = T3H + T3I;
            T3z = T3x + T3y;
            ri[(rs[4])] = T3z - T3G;
            ri[(rs[16])] = T3z + T3G;
        }
        {
            E T3U, T3L, T3V, T3T, T3Y, T3R, T3S, T3X, T3W;
            T3U = KP559016994 * (T3J - T3K);
            T3L = T3J + T3K;
            T3V = ((T3Q) - ((KP250000000) * (T3L)));
            T3R = T1S - T1T;
            T3S = T1V - T1W;
            T3T = (((KP951056516) * (T3R)) + (KP587785252 * T3S));
            T3Y = ((KP951056516 * T3S) - ((KP587785252) * (T3R)));
            ii[0] = T3L + T3Q;
            T3X = T3V - T3U;
            ii[(rs[8])] = T3X - T3Y;
            ii[(rs[12])] = T3Y + T3X;
            T3W = T3U + T3V;
            ii[(rs[4])] = T3T + T3W;
            ii[(rs[16])] = T3W - T3T;
        }
        {
            E T2P, T2N, T2O, T2l, T2R, T29, T2k, T2S, T2Q;
            T2P = KP559016994 * (T2B - T2M);
            T2N = T2B + T2M;
            T2O = ((T2q) - ((KP250000000) * (T2N)));
            T29 = T23 - T28;
            T2k = T2e - T2j;
            T2l = ((KP951056516 * T29) - ((KP587785252) * (T2k)));
            T2R = (((KP951056516) * (T2k)) + (KP587785252 * T29));
            ri[(rs[15])] = T2q + T2N;
            T2S = T2P + T2O;
            ri[(rs[11])] = T2R + T2S;
            ri[(rs[19])] = T2S - T2R;
            T2Q = T2O - T2P;
            ri[(rs[3])] = T2l + T2Q;
            ri[(rs[7])] = T2Q - T2l;
        }
        {
            E T4u, T4s, T4t, T4y, T4A, T4w, T4x, T4z, T4v;
            T4u = KP559016994 * (T4q - T4r);
            T4s = T4q + T4r;
            T4t = ((T4p) - ((KP250000000) * (T4s)));
            T4w = T2G - T2L;
            T4x = T2v - T2A;
            T4y = ((KP951056516 * T4w) - ((KP587785252) * (T4x)));
            T4A = (((KP951056516) * (T4x)) + (KP587785252 * T4w));
            ii[(rs[15])] = T4s + T4p;
            T4z = T4u + T4t;
            ii[(rs[11])] = T4z - T4A;
            ii[(rs[19])] = T4A + T4z;
            T4v = T4t - T4u;
            ii[(rs[3])] = T4v - T4y;
            ii[(rs[7])] = T4y + T4v;
        }
        {
            E T36, T38, T39, T2Z, T3b, T2V, T2Y, T3c, T3a;
            T36 = KP559016994 * (T32 - T35);
            T38 = T32 + T35;
            T39 = ((T37) - ((KP250000000) * (T38)));
            T2V = T2T - T2U;
            T2Y = T2W - T2X;
            T2Z = (((KP951056516) * (T2V)) + (KP587785252 * T2Y));
            T3b = ((KP951056516 * T2Y) - ((KP587785252) * (T2V)));
            ri[(rs[5])] = T37 + T38;
            T3c = T39 - T36;
            ri[(rs[13])] = T3b + T3c;
            ri[(rs[17])] = T3c - T3b;
            T3a = T36 + T39;
            ri[(rs[1])] = T2Z + T3a;
            ri[(rs[9])] = T3a - T2Z;
        }
        {
            E T4d, T4h, T4i, T4m, T4o, T4k, T4l, T4n, T4j;
            T4d = KP559016994 * (T4b - T4c);
            T4h = T4b + T4c;
            T4i = ((T4g) - ((KP250000000) * (T4h)));
            T4k = T30 - T31;
            T4l = T33 - T34;
            T4m = (((KP951056516) * (T4k)) + (KP587785252 * T4l));
            T4o = ((KP951056516 * T4l) - ((KP587785252) * (T4k)));
            ii[(rs[5])] = T4h + T4g;
            T4n = T4i - T4d;
            ii[(rs[13])] = T4n - T4o;
            ii[(rs[17])] = T4o + T4n;
            T4j = T4d + T4i;
            ii[(rs[1])] = T4j - T4m;
            ii[(rs[9])] = T4m + T4j;
        }
    }
}
