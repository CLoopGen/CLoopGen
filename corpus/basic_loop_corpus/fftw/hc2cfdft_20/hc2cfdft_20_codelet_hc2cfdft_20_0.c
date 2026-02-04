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
for (m = mb , W = W + ((mb - 1) * 38); m < me; m = m + 1 , Rp = Rp + ms , Ip = Ip + ms , Rm = Rm - ms , Im = Im - ms , W = W + 38 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T12, T2w, T4o, T4V, T2H, T3a, T4y, T4Y, T1z, T2v, T25, T2y, T2s, T2z, T4v;
    E T4X, T4r, T4U, T3A, T3Z, T2X, T37, T3k, T41, T2M, T39, T3v, T3Y, T2S, T36;
    E T3p, T42, Td, T4G, T33, T3N, Tw, T4H, T32, T3O;
    {
        E T3, T3L, T1x, T2V, Th, Tl, TC, T3g, Tq, Tu, TH, T3h, T7, Tb, T1q;
        E T2U, TR, T2P, T1F, T3r, T23, T2K, T2f, T3y, T1k, T3m, T2q, T2E, T10, T2Q;
        E T1K, T3s, T1U, T2J, T2a, T3x, T1b, T3l, T2l, T2D;
        {
            E T1, T2, T1s, T1u, T1v, T1w, T1r, T1t;
            T1 = Ip[0];
            T2 = Im[0];
            T1s = T1 + T2;
            T1u = Rp[0];
            T1v = Rm[0];
            T1w = T1u - T1v;
            T3 = T1 - T2;
            T3L = T1u + T1v;
            T1r = W[0];
            T1t = W[1];
            T1x = ((T1r * T1s) - ((T1t) * (T1w)));
            T2V = (((T1r) * (T1w)) + (T1t * T1s));
        }
        {
            E Tf, Tg, Tz, Tj, Tk, TB, Ty, TA;
            Tf = Ip[(rs[2])];
            Tg = Im[(rs[2])];
            Tz = Tf - Tg;
            Tj = Rp[(rs[2])];
            Tk = Rm[(rs[2])];
            TB = Tj + Tk;
            Th = Tf + Tg;
            Tl = Tj - Tk;
            Ty = W[6];
            TA = W[7];
            TC = ((Ty * Tz) - ((TA) * (TB)));
            T3g = (((TA) * (Tz)) + (Ty * TB));
        }
        {
            E To, Tp, TE, Ts, Tt, TG, TD, TF;
            To = Ip[(rs[7])];
            Tp = Im[(rs[7])];
            TE = To - Tp;
            Ts = Rp[(rs[7])];
            Tt = Rm[(rs[7])];
            TG = Ts + Tt;
            Tq = To + Tp;
            Tu = Ts - Tt;
            TD = W[26];
            TF = W[27];
            TH = ((TD * TE) - ((TF) * (TG)));
            T3h = (((TF) * (TE)) + (TD * TG));
        }
        {
            E T5, T6, T1n, T9, Ta, T1p, T1m, T1o;
            T5 = Ip[(rs[5])];
            T6 = Im[(rs[5])];
            T1n = T5 + T6;
            T9 = Rp[(rs[5])];
            Ta = Rm[(rs[5])];
            T1p = T9 - Ta;
            T7 = T5 - T6;
            Tb = T9 + Ta;
            T1m = W[20];
            T1o = W[21];
            T1q = ((T1m * T1n) - ((T1o) * (T1p)));
            T2U = (((T1m) * (T1p)) + (T1o * T1n));
        }
        {
            E TM, T1C, TQ, T1E;
            {
                E TK, TL, TO, TP;
                TK = Ip[(rs[4])];
                TL = Im[(rs[4])];
                TM = TK + TL;
                T1C = TK - TL;
                TO = Rp[(rs[4])];
                TP = Rm[(rs[4])];
                TQ = TO - TP;
                T1E = TO + TP;
            }
            {
                E TJ, TN, T1B, T1D;
                TJ = W[16];
                TN = W[17];
                TR = ((TJ * TM) - ((TN) * (TQ)));
                T2P = (((TN) * (TM)) + (TJ * TQ));
                T1B = W[14];
                T1D = W[15];
                T1F = ((T1B * T1C) - ((T1D) * (T1E)));
                T3r = (((T1D) * (T1C)) + (T1B * T1E));
            }
        }
        {
            E T1Y, T2c, T22, T2e;
            {
                E T1W, T1X, T20, T21;
                T1W = Ip[(rs[1])];
                T1X = Im[(rs[1])];
                T1Y = T1W + T1X;
                T2c = T1W - T1X;
                T20 = Rp[(rs[1])];
                T21 = Rm[(rs[1])];
                T22 = T20 - T21;
                T2e = T20 + T21;
            }
            {
                E T1V, T1Z, T2b, T2d;
                T1V = W[4];
                T1Z = W[5];
                T23 = ((T1V * T1Y) - ((T1Z) * (T22)));
                T2K = (((T1Z) * (T1Y)) + (T1V * T22));
                T2b = W[2];
                T2d = W[3];
                T2f = ((T2b * T2c) - ((T2d) * (T2e)));
                T3y = (((T2d) * (T2c)) + (T2b * T2e));
            }
        }
        {
            E T1f, T2n, T1j, T2p;
            {
                E T1d, T1e, T1h, T1i;
                T1d = Ip[(rs[3])];
                T1e = Im[(rs[3])];
                T1f = T1d - T1e;
                T2n = T1d + T1e;
                T1h = Rp[(rs[3])];
                T1i = Rm[(rs[3])];
                T1j = T1h + T1i;
                T2p = T1h - T1i;
            }
            {
                E T1c, T1g, T2m, T2o;
                T1c = W[10];
                T1g = W[11];
                T1k = ((T1c * T1f) - ((T1g) * (T1j)));
                T3m = (((T1c) * (T1j)) + (T1g * T1f));
                T2m = W[12];
                T2o = W[13];
                T2q = ((T2m * T2n) - ((T2o) * (T2p)));
                T2E = (((T2m) * (T2p)) + (T2o * T2n));
            }
        }
        {
            E TV, T1H, TZ, T1J;
            {
                E TT, TU, TX, TY;
                TT = Ip[(rs[9])];
                TU = Im[(rs[9])];
                TV = TT + TU;
                T1H = TT - TU;
                TX = Rp[(rs[9])];
                TY = Rm[(rs[9])];
                TZ = TX - TY;
                T1J = TX + TY;
            }
            {
                E TS, TW, T1G, T1I;
                TS = W[36];
                TW = W[37];
                T10 = ((TS * TV) - ((TW) * (TZ)));
                T2Q = (((TW) * (TV)) + (TS * TZ));
                T1G = W[34];
                T1I = W[35];
                T1K = ((T1G * T1H) - ((T1I) * (T1J)));
                T3s = (((T1I) * (T1H)) + (T1G * T1J));
            }
        }
        {
            E T1P, T27, T1T, T29;
            {
                E T1N, T1O, T1R, T1S;
                T1N = Ip[(rs[6])];
                T1O = Im[(rs[6])];
                T1P = T1N + T1O;
                T27 = T1N - T1O;
                T1R = Rp[(rs[6])];
                T1S = Rm[(rs[6])];
                T1T = T1R - T1S;
                T29 = T1R + T1S;
            }
            {
                E T1M, T1Q, T26, T28;
                T1M = W[24];
                T1Q = W[25];
                T1U = ((T1M * T1P) - ((T1Q) * (T1T)));
                T2J = (((T1Q) * (T1P)) + (T1M * T1T));
                T26 = W[22];
                T28 = W[23];
                T2a = ((T26 * T27) - ((T28) * (T29)));
                T3x = (((T28) * (T27)) + (T26 * T29));
            }
        }
        {
            E T16, T2k, T1a, T2i;
            {
                E T14, T15, T18, T19;
                T14 = Ip[(rs[8])];
                T15 = Im[(rs[8])];
                T16 = T14 - T15;
                T2k = T14 + T15;
                T18 = Rp[(rs[8])];
                T19 = Rm[(rs[8])];
                T1a = T18 + T19;
                T2i = T19 - T18;
            }
            {
                E T13, T17, T2h, T2j;
                T13 = W[30];
                T17 = W[31];
                T1b = ((T13 * T16) - ((T17) * (T1a)));
                T3l = (((T13) * (T1a)) + (T17 * T16));
                T2h = W[33];
                T2j = W[32];
                T2l = (((T2h) * (T2i)) + (T2j * T2k));
                T2D = ((T2j * T2i) - ((T2h) * (T2k)));
            }
        }
        {
            E T2g, T2r, T3n, T3o;
            {
                E TI, T11, T4m, T4n;
                TI = TC - TH;
                T11 = TR - T10;
                T12 = TI - T11;
                T2w = TI + T11;
                T4m = T3g + T3h;
                T4n = TR + T10;
                T4o = T4m + T4n;
                T4V = T4m - T4n;
            }
            {
                E T2F, T2G, T4w, T4x;
                T2F = T2D - T2E;
                T2G = T2a + T2f;
                T2H = T2F - T2G;
                T3a = T2F + T2G;
                T4w = T2l + T2q;
                T4x = T3x + T3y;
                T4y = T4w + T4x;
                T4Y = T4x - T4w;
            }
            {
                E T1l, T1y, T1L, T24;
                T1l = T1b - T1k;
                T1y = T1q - T1x;
                T1z = T1l + T1y;
                T2v = T1y - T1l;
                T1L = T1F - T1K;
                T24 = T1U - T23;
                T25 = T1L - T24;
                T2y = T1L + T24;
            }
            T2g = T2a - T2f;
            T2r = T2l - T2q;
            T2s = T2g - T2r;
            T2z = T2r + T2g;
            {
                E T4t, T4u, T4p, T4q;
                T4t = T3r + T3s;
                T4u = T1U + T23;
                T4v = T4t + T4u;
                T4X = T4t - T4u;
                T4p = T3l + T3m;
                T4q = T1q + T1x;
                T4r = T4p + T4q;
                T4U = T4p - T4q;
            }
            {
                E T3w, T3z, T2T, T2W;
                T3w = T2D + T2E;
                T3z = T3x - T3y;
                T3A = T3w + T3z;
                T3Z = T3z - T3w;
                T2T = T1b + T1k;
                T2W = T2U + T2V;
                T2X = T2T + T2W;
                T37 = T2T - T2W;
            }
            {
                E T3i, T3j, T2I, T2L;
                T3i = T3g - T3h;
                T3j = T2Q - T2P;
                T3k = T3i + T3j;
                T41 = T3i - T3j;
                T2I = T1F + T1K;
                T2L = T2J + T2K;
                T2M = T2I + T2L;
                T39 = T2I - T2L;
            }
            {
                E T3t, T3u, T2O, T2R;
                T3t = T3r - T3s;
                T3u = T2K - T2J;
                T3v = T3t + T3u;
                T3Y = T3t - T3u;
                T2O = TC + TH;
                T2R = T2P + T2Q;
                T2S = T2O + T2R;
                T36 = T2O - T2R;
            }
            T3n = T3l - T3m;
            T3o = T2U - T2V;
            T3p = T3n + T3o;
            T42 = T3n - T3o;
            {
                E Tc, T3M, T4, T8;
                T4 = W[18];
                T8 = W[19];
                Tc = ((T4 * T7) - ((T8) * (Tb)));
                T3M = (((T4) * (Tb)) + (T8 * T7));
                Td = T3 - Tc;
                T4G = T3L + T3M;
                T33 = Tc + T3;
                T3N = T3L - T3M;
            }
            {
                E Tm, T30, Tv, T31;
                {
                    E Te, Ti, Tn, Tr;
                    Te = W[8];
                    Ti = W[9];
                    Tm = ((Te * Th) - ((Ti) * (Tl)));
                    T30 = (((Ti) * (Th)) + (Te * Tl));
                    Tn = W[28];
                    Tr = W[29];
                    Tv = ((Tn * Tq) - ((Tr) * (Tu)));
                    T31 = (((Tr) * (Tq)) + (Tn * Tu));
                }
                Tw = Tm - Tv;
                T4H = Tm + Tv;
                T32 = T30 + T31;
                T3O = T31 - T30;
            }
        }
    }
    {
        E T3C, T3E, Tx, T2u, T3d, T3e, T3D, T3f;
        {
            E T3q, T3B, T1A, T2t;
            T3q = T3k - T3p;
            T3B = T3v - T3A;
            T3C = (((KP475528258) * (T3q)) + (KP293892626 * T3B));
            T3E = ((KP475528258 * T3B) - ((KP293892626) * (T3q)));
            Tx = Td - Tw;
            T1A = T12 + T1z;
            T2t = T25 + T2s;
            T2u = T1A + T2t;
            T3d = KP279508497 * (T1A - T2t);
            T3e = ((KP500000000 * Tx) - ((KP125000000) * (T2u)));
        }
        Ip[(rs[5])] = KP500000000 * (Tx + T2u);
        T3D = T3d - T3e;
        Im[(rs[2])] = T3D - T3E;
        Im[(rs[6])] = T3D + T3E;
        T3f = T3d + T3e;
        Ip[(rs[1])] = T3f - T3C;
        Ip[(rs[9])] = T3f + T3C;
    }
    {
        E T3H, T3T, T3P, T3Q, T3K, T3R, T3U, T3S;
        {
            E T3F, T3G, T3I, T3J;
            T3F = T12 - T1z;
            T3G = T25 - T2s;
            T3H = (((KP475528258) * (T3F)) + (KP293892626 * T3G));
            T3T = ((KP475528258 * T3G) - ((KP293892626) * (T3F)));
            T3P = T3N + T3O;
            T3I = T3k + T3p;
            T3J = T3v + T3A;
            T3Q = T3I + T3J;
            T3K = KP279508497 * (T3I - T3J);
            T3R = ((KP500000000 * T3P) - ((KP125000000) * (T3Q)));
        }
        Rp[(rs[5])] = KP500000000 * (T3P + T3Q);
        T3U = T3R - T3K;
        Rm[(rs[6])] = T3T + T3U;
        Rm[(rs[2])] = T3U - T3T;
        T3S = T3K + T3R;
        Rp[(rs[1])] = T3H + T3S;
        Rp[(rs[9])] = T3S - T3H;
    }
    {
        E T44, T46, T2C, T2B, T3V, T3W, T45, T3X;
        {
            E T40, T43, T2x, T2A;
            T40 = T3Y - T3Z;
            T43 = T41 - T42;
            T44 = ((KP475528258 * T40) - ((KP293892626) * (T43)));
            T46 = (((KP475528258) * (T43)) + (KP293892626 * T40));
            T2C = Tw + Td;
            T2x = T2v - T2w;
            T2A = T2y + T2z;
            T2B = T2x - T2A;
            T3V = (((KP500000000) * (T2C)) + (KP125000000 * T2B));
            T3W = KP279508497 * (T2x + T2A);
        }
        Im[(rs[4])] = KP500000000 * (T2B - T2C);
        T45 = T3W - T3V;
        Im[0] = T45 - T46;
        Im[(rs[8])] = T45 + T46;
        T3X = T3V + T3W;
        Ip[(rs[3])] = T3X - T44;
        Ip[(rs[7])] = T3X + T44;
    }
    {
        E T49, T4h, T4a, T4d, T4e, T4f, T4i, T4g;
        {
            E T47, T48, T4b, T4c;
            T47 = T2y - T2z;
            T48 = T2w + T2v;
            T49 = ((KP475528258 * T47) - ((KP293892626) * (T48)));
            T4h = (((KP475528258) * (T48)) + (KP293892626 * T47));
            T4a = T3N - T3O;
            T4b = T41 + T42;
            T4c = T3Y + T3Z;
            T4d = T4b + T4c;
            T4e = ((KP500000000 * T4a) - ((KP125000000) * (T4d)));
            T4f = KP279508497 * (T4b - T4c);
        }
        Rm[(rs[4])] = KP500000000 * (T4a + T4d);
        T4i = T4f + T4e;
        Rm[(rs[8])] = T4h + T4i;
        Rm[0] = T4i - T4h;
        T4g = T4e - T4f;
        Rp[(rs[3])] = T49 + T4g;
        Rp[(rs[7])] = T4g - T49;
    }
    {
        E T50, T52, T34, T2Z, T4R, T4S, T51, T4T;
        {
            E T4W, T4Z, T2N, T2Y;
            T4W = T4U - T4V;
            T4Z = T4X - T4Y;
            T50 = ((KP475528258 * T4W) - ((KP293892626) * (T4Z)));
            T52 = (((KP293892626) * (T4W)) + (KP475528258 * T4Z));
            T34 = T32 + T33;
            T2N = T2H - T2M;
            T2Y = T2S + T2X;
            T2Z = T2N - T2Y;
            T4R = (((KP500000000) * (T34)) + (KP125000000 * T2Z));
            T4S = KP279508497 * (T2Y + T2N);
        }
        Im[(rs[9])] = KP500000000 * (T2Z - T34);
        T51 = T4R - T4S;
        Ip[(rs[2])] = T51 + T52;
        Im[(rs[1])] = T52 - T51;
        T4T = T4R + T4S;
        Ip[(rs[6])] = T4T + T50;
        Im[(rs[5])] = T50 - T4T;
    }
    {
        E T5c, T5d, T53, T56, T57, T58, T5e, T59;
        {
            E T5a, T5b, T54, T55;
            T5a = T2M + T2H;
            T5b = T2S - T2X;
            T5c = ((KP475528258 * T5a) - ((KP293892626) * (T5b)));
            T5d = (((KP475528258) * (T5b)) + (KP293892626 * T5a));
            T53 = T4G - T4H;
            T54 = T4V + T4U;
            T55 = T4X + T4Y;
            T56 = T54 + T55;
            T57 = ((KP500000000 * T53) - ((KP125000000) * (T56)));
            T58 = KP279508497 * (T54 - T55);
        }
        Rm[(rs[9])] = KP500000000 * (T53 + T56);
        T5e = T58 + T57;
        Rp[(rs[6])] = T5d + T5e;
        Rm[(rs[5])] = T5e - T5d;
        T59 = T57 - T58;
        Rp[(rs[2])] = T59 - T5c;
        Rm[(rs[1])] = T5c + T59;
    }
    {
        E T4A, T4C, T35, T3c, T4j, T4k, T4B, T4l;
        {
            E T4s, T4z, T38, T3b;
            T4s = T4o - T4r;
            T4z = T4v - T4y;
            T4A = ((KP293892626 * T4s) - ((KP475528258) * (T4z)));
            T4C = (((KP475528258) * (T4s)) + (KP293892626 * T4z));
            T35 = T33 - T32;
            T38 = T36 + T37;
            T3b = T39 + T3a;
            T3c = T38 + T3b;
            T4j = ((KP500000000 * T35) - ((KP125000000) * (T3c)));
            T4k = KP279508497 * (T38 - T3b);
        }
        Ip[0] = KP500000000 * (T35 + T3c);
        T4B = T4k + T4j;
        Ip[(rs[4])] = T4B + T4C;
        Im[(rs[3])] = T4C - T4B;
        T4l = T4j - T4k;
        Ip[(rs[8])] = T4l + T4A;
        Im[(rs[7])] = T4A - T4l;
    }
    {
        E T4O, T4P, T4I, T4J, T4F, T4K, T4Q, T4L;
        {
            E T4M, T4N, T4D, T4E;
            T4M = T36 - T37;
            T4N = T39 - T3a;
            T4O = (((KP475528258) * (T4M)) + (KP293892626 * T4N));
            T4P = ((KP475528258 * T4N) - ((KP293892626) * (T4M)));
            T4I = T4G + T4H;
            T4D = T4o + T4r;
            T4E = T4v + T4y;
            T4J = T4D + T4E;
            T4F = KP279508497 * (T4D - T4E);
            T4K = ((KP500000000 * T4I) - ((KP125000000) * (T4J)));
        }
        Rp[0] = KP500000000 * (T4I + T4J);
        T4Q = T4K - T4F;
        Rp[(rs[8])] = T4P + T4Q;
        Rm[(rs[7])] = T4Q - T4P;
        T4L = T4F + T4K;
        Rp[(rs[4])] = T4L - T4O;
        Rm[(rs[3])] = T4O + T4L;
    }
}

}
