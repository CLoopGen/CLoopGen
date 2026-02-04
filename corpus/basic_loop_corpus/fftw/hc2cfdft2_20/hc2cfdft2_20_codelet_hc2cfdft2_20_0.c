#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *Rp;
extern R *Ip;
extern R *Rm;
extern R *Im;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP125000000;
extern  E KP500000000;
extern  E KP279508497;
extern  E KP293892626;
extern  E KP475528258;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (m = mb , W = W + ((mb - 1) * 8); m < me; m = m + 1 , Rp = Rp + ms , Ip = Ip + ms , Rm = Rm - ms , Im = Im - ms , W = W + 8 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T4, T7, Tm, To, Tq, Tu, T1I, T1G, T8, T5, Ta, T1u, T2u, Tg, T2s;
    E T21, T1A, T1Z, T1O, T2I, T1K, T2G, Tw, TC, T2a, T2e, TH, TI, TJ, TX;
    E T2D, TN, T2B, T26, T1n, TZ, T24, T1j;
    {
        E T9, T1y, Te, T1t, T6, T1z, Tf, T1s;
        {
            E Tn, Tt, Tp, Ts;
            T4 = W[0];
            T7 = W[1];
            Tm = W[2];
            To = W[3];
            Tn = T4 * Tm;
            Tt = T7 * Tm;
            Tp = T7 * To;
            Ts = T4 * To;
            Tq = Tn - Tp;
            Tu = Ts + Tt;
            T1I = Ts - Tt;
            T1G = Tn + Tp;
            T8 = W[5];
            T9 = T7 * T8;
            T1y = Tm * T8;
            Te = T4 * T8;
            T1t = To * T8;
            T5 = W[4];
            T6 = T4 * T5;
            T1z = To * T5;
            Tf = T7 * T5;
            T1s = Tm * T5;
        }
        Ta = T6 - T9;
        T1u = T1s + T1t;
        T2u = T1y + T1z;
        Tg = Te + Tf;
        T2s = T1s - T1t;
        T21 = Te - Tf;
        T1A = T1y - T1z;
        T1Z = T6 + T9;
        {
            E T1M, T1N, T1H, T1J;
            T1M = T1G * T8;
            T1N = T1I * T5;
            T1O = T1M + T1N;
            T2I = T1M - T1N;
            T1H = T1G * T5;
            T1J = T1I * T8;
            T1K = T1H - T1J;
            T2G = T1H + T1J;
            {
                E Tr, Tv, TA, TB;
                Tr = Tq * T5;
                Tv = Tu * T8;
                Tw = Tr + Tv;
                TA = Tq * T8;
                TB = Tu * T5;
                TC = TA - TB;
                T2a = Tr - Tv;
                T2e = TA + TB;
                TH = W[6];
                TI = W[7];
                TJ = (((Tq) * (TH)) + (Tu * TI));
                TX = (((Tw) * (TH)) + (TC * TI));
                T2D = (((T1G) * (TH)) + (T1I * TI));
                TN = ((Tq * TI) - ((Tu) * (TH)));
                T2B = ((T1G * TI) - ((T1I) * (TH)));
                T26 = ((T4 * TI) - ((T7) * (TH)));
                T1n = ((Tm * TI) - ((To) * (TH)));
                TZ = ((Tw * TI) - ((TC) * (TH)));
                T24 = (((T4) * (TH)) + (T7 * TI));
                T1j = (((Tm) * (TH)) + (To * TI));
            }
        }
    }
    {
        E Tl, T3n, T1i, T2Q, T47, T50, T4S, T5i, T2M, T2T, T4I, T5f, T4L, T5e, T4P;
        E T5h, T2r, T2S, T1X, T2P, T31, T3u, T36, T3t, T3E, T4l, T3U, T4j, T3h, T3r;
        E T3J, T4m, T3c, T3q, T3P, T4i, TS, T51, T3m, T48;
        {
            E T3, T45, T1V, T3f, Tz, TF, TW, T3A, TM, TQ, T11, T3B, Td, Tj, T1Q;
            E T3e, T19, T3L, T23, T39, T2p, T3S, T2z, T34, T1E, T3G, T2K, T2Y, T1g, T3M;
            E T28, T3a, T2i, T3R, T2w, T33, T1r, T3F, T2F, T2X, T4N, T4O;
            {
                E T1, T2, T1R, T1S, T1T, T1U;
                T1 = Ip[0];
                T2 = Im[0];
                T1R = T1 + T2;
                T1S = Rp[0];
                T1T = Rm[0];
                T1U = T1S - T1T;
                T3 = T1 - T2;
                T45 = T1S + T1T;
                T1V = ((T4 * T1R) - ((T7) * (T1U)));
                T3f = (((T4) * (T1U)) + (T7 * T1R));
            }
            {
                E Tx, Ty, TU, TD, TE, TV;
                Tx = Ip[(rs[2])];
                Ty = Im[(rs[2])];
                TU = Tx - Ty;
                TD = Rp[(rs[2])];
                TE = Rm[(rs[2])];
                TV = TD + TE;
                Tz = Tx + Ty;
                TF = TD - TE;
                TW = ((Tq * TU) - ((Tu) * (TV)));
                T3A = (((Tu) * (TU)) + (Tq * TV));
            }
            {
                E TK, TL, TY, TO, TP, T10;
                TK = Ip[(rs[7])];
                TL = Im[(rs[7])];
                TY = TK - TL;
                TO = Rp[(rs[7])];
                TP = Rm[(rs[7])];
                T10 = TO + TP;
                TM = TK + TL;
                TQ = TO - TP;
                T11 = ((TX * TY) - ((TZ) * (T10)));
                T3B = (((TZ) * (TY)) + (TX * T10));
            }
            {
                E Tb, Tc, T1L, Th, Ti, T1P;
                Tb = Ip[(rs[5])];
                Tc = Im[(rs[5])];
                T1L = Tb + Tc;
                Th = Rp[(rs[5])];
                Ti = Rm[(rs[5])];
                T1P = Th - Ti;
                Td = Tb - Tc;
                Tj = Th + Ti;
                T1Q = ((T1K * T1L) - ((T1O) * (T1P)));
                T3e = (((T1K) * (T1P)) + (T1O * T1L));
            }
            {
                E T15, T20, T18, T22;
                {
                    E T13, T14, T16, T17;
                    T13 = Ip[(rs[4])];
                    T14 = Im[(rs[4])];
                    T15 = T13 + T14;
                    T20 = T13 - T14;
                    T16 = Rp[(rs[4])];
                    T17 = Rm[(rs[4])];
                    T18 = T16 - T17;
                    T22 = T16 + T17;
                }
                T19 = ((T5 * T15) - ((T8) * (T18)));
                T3L = (((T21) * (T20)) + (T1Z * T22));
                T23 = ((T1Z * T20) - ((T21) * (T22)));
                T39 = (((T8) * (T15)) + (T5 * T18));
            }
            {
                E T2l, T2x, T2o, T2y;
                {
                    E T2j, T2k, T2m, T2n;
                    T2j = Ip[(rs[1])];
                    T2k = Im[(rs[1])];
                    T2l = T2j + T2k;
                    T2x = T2j - T2k;
                    T2m = Rp[(rs[1])];
                    T2n = Rm[(rs[1])];
                    T2o = T2m - T2n;
                    T2y = T2m + T2n;
                }
                T2p = ((Tm * T2l) - ((To) * (T2o)));
                T3S = (((T1I) * (T2x)) + (T1G * T2y));
                T2z = ((T1G * T2x) - ((T1I) * (T2y)));
                T34 = (((To) * (T2l)) + (Tm * T2o));
            }
            {
                E T1x, T2H, T1D, T2J;
                {
                    E T1v, T1w, T1B, T1C;
                    T1v = Ip[(rs[3])];
                    T1w = Im[(rs[3])];
                    T1x = T1v - T1w;
                    T2H = T1v + T1w;
                    T1B = Rp[(rs[3])];
                    T1C = Rm[(rs[3])];
                    T1D = T1B + T1C;
                    T2J = T1B - T1C;
                }
                T1E = ((T1u * T1x) - ((T1A) * (T1D)));
                T3G = (((T1u) * (T1D)) + (T1A * T1x));
                T2K = ((T2G * T2H) - ((T2I) * (T2J)));
                T2Y = (((T2G) * (T2J)) + (T2I * T2H));
            }
            {
                E T1c, T25, T1f, T27;
                {
                    E T1a, T1b, T1d, T1e;
                    T1a = Ip[(rs[9])];
                    T1b = Im[(rs[9])];
                    T1c = T1a + T1b;
                    T25 = T1a - T1b;
                    T1d = Rp[(rs[9])];
                    T1e = Rm[(rs[9])];
                    T1f = T1d - T1e;
                    T27 = T1d + T1e;
                }
                T1g = ((TH * T1c) - ((TI) * (T1f)));
                T3M = (((T26) * (T25)) + (T24 * T27));
                T28 = ((T24 * T25) - ((T26) * (T27)));
                T3a = (((TI) * (T1c)) + (TH * T1f));
            }
            {
                E T2d, T2t, T2h, T2v;
                {
                    E T2b, T2c, T2f, T2g;
                    T2b = Ip[(rs[6])];
                    T2c = Im[(rs[6])];
                    T2d = T2b + T2c;
                    T2t = T2b - T2c;
                    T2f = Rp[(rs[6])];
                    T2g = Rm[(rs[6])];
                    T2h = T2f - T2g;
                    T2v = T2f + T2g;
                }
                T2i = ((T2a * T2d) - ((T2e) * (T2h)));
                T3R = (((T2u) * (T2t)) + (T2s * T2v));
                T2w = ((T2s * T2t) - ((T2u) * (T2v)));
                T33 = (((T2e) * (T2d)) + (T2a * T2h));
            }
            {
                E T1m, T2E, T1q, T2C;
                {
                    E T1k, T1l, T1o, T1p;
                    T1k = Ip[(rs[8])];
                    T1l = Im[(rs[8])];
                    T1m = T1k - T1l;
                    T2E = T1k + T1l;
                    T1o = Rp[(rs[8])];
                    T1p = Rm[(rs[8])];
                    T1q = T1o + T1p;
                    T2C = T1p - T1o;
                }
                T1r = ((T1j * T1m) - ((T1n) * (T1q)));
                T3F = (((T1j) * (T1q)) + (T1n * T1m));
                T2F = (((T2B) * (T2C)) + (T2D * T2E));
                T2X = ((T2D * T2C) - ((T2B) * (T2E)));
            }
            {
                E Tk, T12, T1h, T46;
                Tk = ((Ta * Td) - ((Tg) * (Tj)));
                Tl = T3 - Tk;
                T3n = Tk + T3;
                T12 = TW - T11;
                T1h = T19 - T1g;
                T1i = T12 - T1h;
                T2Q = T12 + T1h;
                T46 = (((Ta) * (Tj)) + (Tg * Td));
                T47 = T45 - T46;
                T50 = T45 + T46;
                {
                    E T4Q, T4R, T2A, T2L;
                    T4Q = T2F + T2K;
                    T4R = T3R + T3S;
                    T4S = T4Q + T4R;
                    T5i = T4R - T4Q;
                    T2A = T2w - T2z;
                    T2L = T2F - T2K;
                    T2M = T2A - T2L;
                    T2T = T2L + T2A;
                }
            }
            {
                E T4G, T4H, T4J, T4K;
                T4G = T3A + T3B;
                T4H = T19 + T1g;
                T4I = T4G + T4H;
                T5f = T4G - T4H;
                T4J = T3F + T3G;
                T4K = T1Q + T1V;
                T4L = T4J + T4K;
                T5e = T4J - T4K;
            }
            T4N = T3L + T3M;
            T4O = T2i + T2p;
            T4P = T4N + T4O;
            T5h = T4N - T4O;
            {
                E T29, T2q, T1F, T1W;
                T29 = T23 - T28;
                T2q = T2i - T2p;
                T2r = T29 - T2q;
                T2S = T29 + T2q;
                T1F = T1r - T1E;
                T1W = T1Q - T1V;
                T1X = T1F + T1W;
                T2P = T1W - T1F;
            }
            {
                E T3C, T3D, T3N, T3O;
                {
                    E T2Z, T30, T32, T35;
                    T2Z = T2X - T2Y;
                    T30 = T2w + T2z;
                    T31 = T2Z - T30;
                    T3u = T2Z + T30;
                    T32 = T23 + T28;
                    T35 = T33 + T34;
                    T36 = T32 + T35;
                    T3t = T32 - T35;
                }
                T3C = T3A - T3B;
                T3D = T3a - T39;
                T3E = T3C + T3D;
                T4l = T3C - T3D;
                {
                    E T3Q, T3T, T3d, T3g;
                    T3Q = T2X + T2Y;
                    T3T = T3R - T3S;
                    T3U = T3Q + T3T;
                    T4j = T3T - T3Q;
                    T3d = T1r + T1E;
                    T3g = T3e + T3f;
                    T3h = T3d + T3g;
                    T3r = T3d - T3g;
                }
                {
                    E T3H, T3I, T38, T3b;
                    T3H = T3F - T3G;
                    T3I = T3e - T3f;
                    T3J = T3H + T3I;
                    T4m = T3H - T3I;
                    T38 = TW + T11;
                    T3b = T39 + T3a;
                    T3c = T38 + T3b;
                    T3q = T38 - T3b;
                }
                T3N = T3L - T3M;
                T3O = T34 - T33;
                T3P = T3N + T3O;
                T4i = T3N - T3O;
                {
                    E TG, TR, T3k, T3l;
                    TG = ((Tw * Tz) - ((TC) * (TF)));
                    TR = ((TJ * TM) - ((TN) * (TQ)));
                    TS = TG - TR;
                    T51 = TG + TR;
                    T3k = (((TC) * (Tz)) + (Tw * TF));
                    T3l = (((TN) * (TM)) + (TJ * TQ));
                    T3m = T3k + T3l;
                    T48 = T3l - T3k;
                }
            }
        }
        {
            E T3W, T3Y, TT, T2O, T3x, T3y, T3X, T3z;
            {
                E T3K, T3V, T1Y, T2N;
                T3K = T3E - T3J;
                T3V = T3P - T3U;
                T3W = (((KP475528258) * (T3K)) + (KP293892626 * T3V));
                T3Y = ((KP475528258 * T3V) - ((KP293892626) * (T3K)));
                TT = Tl - TS;
                T1Y = T1i + T1X;
                T2N = T2r + T2M;
                T2O = T1Y + T2N;
                T3x = KP279508497 * (T1Y - T2N);
                T3y = ((KP500000000 * TT) - ((KP125000000) * (T2O)));
            }
            Ip[(rs[5])] = KP500000000 * (TT + T2O);
            T3X = T3x - T3y;
            Im[(rs[2])] = T3X - T3Y;
            Im[(rs[6])] = T3X + T3Y;
            T3z = T3x + T3y;
            Ip[(rs[1])] = T3z - T3W;
            Ip[(rs[9])] = T3z + T3W;
        }
        {
            E T41, T4d, T49, T4a, T44, T4b, T4e, T4c;
            {
                E T3Z, T40, T42, T43;
                T3Z = T1i - T1X;
                T40 = T2r - T2M;
                T41 = (((KP475528258) * (T3Z)) + (KP293892626 * T40));
                T4d = ((KP475528258 * T40) - ((KP293892626) * (T3Z)));
                T49 = T47 + T48;
                T42 = T3E + T3J;
                T43 = T3P + T3U;
                T4a = T42 + T43;
                T44 = KP279508497 * (T42 - T43);
                T4b = ((KP500000000 * T49) - ((KP125000000) * (T4a)));
            }
            Rp[(rs[5])] = KP500000000 * (T49 + T4a);
            T4e = T4b - T44;
            Rm[(rs[6])] = T4d + T4e;
            Rm[(rs[2])] = T4e - T4d;
            T4c = T44 + T4b;
            Rp[(rs[1])] = T41 + T4c;
            Rp[(rs[9])] = T4c - T41;
        }
        {
            E T4o, T4q, T2W, T2V, T4f, T4g, T4p, T4h;
            {
                E T4k, T4n, T2R, T2U;
                T4k = T4i - T4j;
                T4n = T4l - T4m;
                T4o = ((KP475528258 * T4k) - ((KP293892626) * (T4n)));
                T4q = (((KP475528258) * (T4n)) + (KP293892626 * T4k));
                T2W = TS + Tl;
                T2R = T2P - T2Q;
                T2U = T2S + T2T;
                T2V = T2R - T2U;
                T4f = (((KP500000000) * (T2W)) + (KP125000000 * T2V));
                T4g = KP279508497 * (T2R + T2U);
            }
            Im[(rs[4])] = KP500000000 * (T2V - T2W);
            T4p = T4g - T4f;
            Im[0] = T4p - T4q;
            Im[(rs[8])] = T4p + T4q;
            T4h = T4f + T4g;
            Ip[(rs[3])] = T4h - T4o;
            Ip[(rs[7])] = T4h + T4o;
        }
        {
            E T4t, T4B, T4u, T4x, T4y, T4z, T4C, T4A;
            {
                E T4r, T4s, T4v, T4w;
                T4r = T2S - T2T;
                T4s = T2Q + T2P;
                T4t = ((KP475528258 * T4r) - ((KP293892626) * (T4s)));
                T4B = (((KP475528258) * (T4s)) + (KP293892626 * T4r));
                T4u = T47 - T48;
                T4v = T4l + T4m;
                T4w = T4i + T4j;
                T4x = T4v + T4w;
                T4y = ((KP500000000 * T4u) - ((KP125000000) * (T4x)));
                T4z = KP279508497 * (T4v - T4w);
            }
            Rm[(rs[4])] = KP500000000 * (T4u + T4x);
            T4C = T4z + T4y;
            Rm[(rs[8])] = T4B + T4C;
            Rm[0] = T4C - T4B;
            T4A = T4y - T4z;
            Rp[(rs[3])] = T4t + T4A;
            Rp[(rs[7])] = T4A - T4t;
        }
        {
            E T5k, T5m, T3o, T3j, T5b, T5c, T5l, T5d;
            {
                E T5g, T5j, T37, T3i;
                T5g = T5e - T5f;
                T5j = T5h - T5i;
                T5k = ((KP475528258 * T5g) - ((KP293892626) * (T5j)));
                T5m = (((KP293892626) * (T5g)) + (KP475528258 * T5j));
                T3o = T3m + T3n;
                T37 = T31 - T36;
                T3i = T3c + T3h;
                T3j = T37 - T3i;
                T5b = (((KP500000000) * (T3o)) + (KP125000000 * T3j));
                T5c = KP279508497 * (T3i + T37);
            }
            Im[(rs[9])] = KP500000000 * (T3j - T3o);
            T5l = T5b - T5c;
            Ip[(rs[2])] = T5l + T5m;
            Im[(rs[1])] = T5m - T5l;
            T5d = T5b + T5c;
            Ip[(rs[6])] = T5d + T5k;
            Im[(rs[5])] = T5k - T5d;
        }
        {
            E T5w, T5x, T5n, T5q, T5r, T5s, T5y, T5t;
            {
                E T5u, T5v, T5o, T5p;
                T5u = T36 + T31;
                T5v = T3c - T3h;
                T5w = ((KP475528258 * T5u) - ((KP293892626) * (T5v)));
                T5x = (((KP475528258) * (T5v)) + (KP293892626 * T5u));
                T5n = T50 - T51;
                T5o = T5f + T5e;
                T5p = T5h + T5i;
                T5q = T5o + T5p;
                T5r = ((KP500000000 * T5n) - ((KP125000000) * (T5q)));
                T5s = KP279508497 * (T5o - T5p);
            }
            Rm[(rs[9])] = KP500000000 * (T5n + T5q);
            T5y = T5s + T5r;
            Rp[(rs[6])] = T5x + T5y;
            Rm[(rs[5])] = T5y - T5x;
            T5t = T5r - T5s;
            Rp[(rs[2])] = T5t - T5w;
            Rm[(rs[1])] = T5w + T5t;
        }
        {
            E T4U, T4W, T3p, T3w, T4D, T4E, T4V, T4F;
            {
                E T4M, T4T, T3s, T3v;
                T4M = T4I - T4L;
                T4T = T4P - T4S;
                T4U = ((KP293892626 * T4M) - ((KP475528258) * (T4T)));
                T4W = (((KP475528258) * (T4M)) + (KP293892626 * T4T));
                T3p = T3n - T3m;
                T3s = T3q + T3r;
                T3v = T3t + T3u;
                T3w = T3s + T3v;
                T4D = ((KP500000000 * T3p) - ((KP125000000) * (T3w)));
                T4E = KP279508497 * (T3s - T3v);
            }
            Ip[0] = KP500000000 * (T3p + T3w);
            T4V = T4E + T4D;
            Ip[(rs[4])] = T4V + T4W;
            Im[(rs[3])] = T4W - T4V;
            T4F = T4D - T4E;
            Ip[(rs[8])] = T4F + T4U;
            Im[(rs[7])] = T4U - T4F;
        }
        {
            E T58, T59, T52, T53, T4Z, T54, T5a, T55;
            {
                E T56, T57, T4X, T4Y;
                T56 = T3q - T3r;
                T57 = T3t - T3u;
                T58 = (((KP475528258) * (T56)) + (KP293892626 * T57));
                T59 = ((KP475528258 * T57) - ((KP293892626) * (T56)));
                T52 = T50 + T51;
                T4X = T4I + T4L;
                T4Y = T4P + T4S;
                T53 = T4X + T4Y;
                T4Z = KP279508497 * (T4X - T4Y);
                T54 = ((KP500000000 * T52) - ((KP125000000) * (T53)));
            }
            Rp[0] = KP500000000 * (T52 + T53);
            T5a = T54 - T4Z;
            Rp[(rs[8])] = T59 + T5a;
            Rm[(rs[7])] = T5a - T59;
            T55 = T4Z + T54;
            Rp[(rs[4])] = T55 - T58;
            Rm[(rs[3])] = T58 + T55;
        }
    }
}

}
