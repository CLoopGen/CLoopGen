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
extern  E KP461939766;
extern  E KP191341716;
extern  E KP353553390;
extern  E KP500000000;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (m = mb , W = W + ((mb - 1) * 8); m < me; m = m + 1 , Rp = Rp + ms , Ip = Ip + ms , Rm = Rm - ms , Im = Im - ms , W = W + 8 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, T4, T2, T5, T7, Td, T12, TY, Tk, Ti, Tm, T1l, T1b, TL, T1h;
    E Ts, TR, T17, Ty, Tz, TA, TE, T1L, T1Q, T1H, T1O, T24, T2d, T20, T2b;
    {
        E Tl, TP, Tq, TK, Tj, TQ, Tr, TJ;
        {
            E T3, Tc, T6, Tb;
            T1 = W[0];
            T4 = W[1];
            T2 = W[2];
            T5 = W[3];
            T3 = T1 * T2;
            Tc = T4 * T2;
            T6 = T4 * T5;
            Tb = T1 * T5;
            T7 = T3 + T6;
            Td = Tb - Tc;
            T12 = Tb + Tc;
            TY = T3 - T6;
            Tk = W[5];
            Tl = T4 * Tk;
            TP = T2 * Tk;
            Tq = T1 * Tk;
            TK = T5 * Tk;
            Ti = W[4];
            Tj = T1 * Ti;
            TQ = T5 * Ti;
            Tr = T4 * Ti;
            TJ = T2 * Ti;
        }
        Tm = Tj - Tl;
        T1l = Tq - Tr;
        T1b = TP + TQ;
        TL = TJ + TK;
        T1h = Tj + Tl;
        Ts = Tq + Tr;
        TR = TP - TQ;
        T17 = TJ - TK;
        Ty = W[6];
        Tz = W[7];
        TA = (((T1) * (Ty)) + (T4 * Tz));
        TE = ((T1 * Tz) - ((T4) * (Ty)));
        {
            E T1J, T1K, T1F, T1G;
            T1J = TY * Tk;
            T1K = T12 * Ti;
            T1L = T1J - T1K;
            T1Q = T1J + T1K;
            T1F = TY * Ti;
            T1G = T12 * Tk;
            T1H = T1F + T1G;
            T1O = T1F - T1G;
        }
        {
            E T22, T23, T1Y, T1Z;
            T22 = T7 * Tk;
            T23 = Td * Ti;
            T24 = T22 + T23;
            T2d = T22 - T23;
            T1Y = T7 * Ti;
            T1Z = Td * Tk;
            T20 = T1Y - T1Z;
            T2b = T1Y + T1Z;
        }
    }
    {
        E T1t, T3i, T2l, T3B, T1E, T3t, T2M, T3x, T1g, T3C, T2J, T3u, T1T, T3w, T2o;
        E T3j, Tx, T3b, T2C, T3q, T27, T3m, T2s, T3c, TW, T3f, T2F, T3n, T2g, T3p;
        E T2v, T3e;
        {
            E T1k, T1C, T1o, T1B, T1s, T1z, T1y, T2j, T1p, T2k;
            {
                E T1i, T1j, T1m, T1n;
                T1i = Ip[(rs[4])];
                T1j = Im[(rs[4])];
                T1k = T1i - T1j;
                T1C = T1i + T1j;
                T1m = Rp[(rs[4])];
                T1n = Rm[(rs[4])];
                T1o = T1m + T1n;
                T1B = T1m - T1n;
            }
            {
                E T1q, T1r, T1w, T1x;
                T1q = Ip[0];
                T1r = Im[0];
                T1s = T1q - T1r;
                T1z = T1q + T1r;
                T1w = Rm[0];
                T1x = Rp[0];
                T1y = T1w - T1x;
                T2j = T1x + T1w;
            }
            T1p = ((T1h * T1k) - ((T1l) * (T1o)));
            T1t = T1p + T1s;
            T3i = T1s - T1p;
            T2k = (((T1h) * (T1o)) + (T1l * T1k));
            T2l = T2j + T2k;
            T3B = T2j - T2k;
            {
                E T1A, T1D, T2K, T2L;
                T1A = ((T1 * T1y) - ((T4) * (T1z)));
                T1D = (((Ti) * (T1B)) + (Tk * T1C));
                T1E = T1A - T1D;
                T3t = T1D + T1A;
                T2K = ((Ti * T1C) - ((Tk) * (T1B)));
                T2L = (((T4) * (T1y)) + (T1 * T1z));
                T2M = T2K + T2L;
                T3x = T2L - T2K;
            }
        }
        {
            E T11, T1M, T15, T1I, T1a, T1R, T1e, T1P;
            {
                E TZ, T10, T13, T14;
                TZ = Ip[(rs[2])];
                T10 = Im[(rs[2])];
                T11 = TZ - T10;
                T1M = TZ + T10;
                T13 = Rp[(rs[2])];
                T14 = Rm[(rs[2])];
                T15 = T13 + T14;
                T1I = T13 - T14;
            }
            {
                E T18, T19, T1c, T1d;
                T18 = Ip[(rs[6])];
                T19 = Im[(rs[6])];
                T1a = T18 - T19;
                T1R = T18 + T19;
                T1c = Rp[(rs[6])];
                T1d = Rm[(rs[6])];
                T1e = T1c + T1d;
                T1P = T1c - T1d;
            }
            {
                E T16, T1f, T2H, T2I;
                T16 = ((TY * T11) - ((T12) * (T15)));
                T1f = ((T17 * T1a) - ((T1b) * (T1e)));
                T1g = T16 + T1f;
                T3C = T16 - T1f;
                T2H = ((T1H * T1M) - ((T1L) * (T1I)));
                T2I = ((T1O * T1R) - ((T1Q) * (T1P)));
                T2J = T2H + T2I;
                T3u = T2H - T2I;
            }
            {
                E T1N, T1S, T2m, T2n;
                T1N = (((T1H) * (T1I)) + (T1L * T1M));
                T1S = (((T1O) * (T1P)) + (T1Q * T1R));
                T1T = T1N + T1S;
                T3w = T1S - T1N;
                T2m = (((TY) * (T15)) + (T12 * T11));
                T2n = (((T17) * (T1e)) + (T1b * T1a));
                T2o = T2m + T2n;
                T3j = T2m - T2n;
            }
        }
        {
            E Ta, T1W, Tg, T1V, Tp, T25, Tv, T21;
            {
                E T8, T9, Te, Tf;
                T8 = Ip[(rs[1])];
                T9 = Im[(rs[1])];
                Ta = T8 - T9;
                T1W = T8 + T9;
                Te = Rp[(rs[1])];
                Tf = Rm[(rs[1])];
                Tg = Te + Tf;
                T1V = Te - Tf;
            }
            {
                E Tn, To, Tt, Tu;
                Tn = Ip[(rs[5])];
                To = Im[(rs[5])];
                Tp = Tn - To;
                T25 = Tn + To;
                Tt = Rp[(rs[5])];
                Tu = Rm[(rs[5])];
                Tv = Tt + Tu;
                T21 = Tt - Tu;
            }
            {
                E Th, Tw, T2A, T2B;
                Th = ((T7 * Ta) - ((Td) * (Tg)));
                Tw = ((Tm * Tp) - ((Ts) * (Tv)));
                Tx = Th + Tw;
                T3b = Th - Tw;
                T2A = ((T2 * T1W) - ((T5) * (T1V)));
                T2B = ((T20 * T25) - ((T24) * (T21)));
                T2C = T2A + T2B;
                T3q = T2A - T2B;
            }
            {
                E T1X, T26, T2q, T2r;
                T1X = (((T2) * (T1V)) + (T5 * T1W));
                T26 = (((T20) * (T21)) + (T24 * T25));
                T27 = T1X + T26;
                T3m = T26 - T1X;
                T2q = (((T7) * (Tg)) + (Td * Ta));
                T2r = (((Tm) * (Tv)) + (Ts * Tp));
                T2s = T2q + T2r;
                T3c = T2q - T2r;
            }
        }
        {
            E TD, T29, TH, T28, TO, T2e, TU, T2c;
            {
                E TB, TC, TF, TG;
                TB = Ip[(rs[7])];
                TC = Im[(rs[7])];
                TD = TB - TC;
                T29 = TB + TC;
                TF = Rp[(rs[7])];
                TG = Rm[(rs[7])];
                TH = TF + TG;
                T28 = TF - TG;
            }
            {
                E TM, TN, TS, TT;
                TM = Ip[(rs[3])];
                TN = Im[(rs[3])];
                TO = TM - TN;
                T2e = TM + TN;
                TS = Rp[(rs[3])];
                TT = Rm[(rs[3])];
                TU = TS + TT;
                T2c = TS - TT;
            }
            {
                E TI, TV, T2D, T2E;
                TI = ((TA * TD) - ((TE) * (TH)));
                TV = ((TL * TO) - ((TR) * (TU)));
                TW = TI + TV;
                T3f = TI - TV;
                T2D = ((Ty * T29) - ((Tz) * (T28)));
                T2E = ((T2b * T2e) - ((T2d) * (T2c)));
                T2F = T2D + T2E;
                T3n = T2D - T2E;
            }
            {
                E T2a, T2f, T2t, T2u;
                T2a = (((Ty) * (T28)) + (Tz * T29));
                T2f = (((T2b) * (T2c)) + (T2d * T2e));
                T2g = T2a + T2f;
                T3p = T2f - T2a;
                T2t = (((TA) * (TH)) + (TE * TD));
                T2u = (((TL) * (TU)) + (TR * TO));
                T2v = T2t + T2u;
                T3e = T2t - T2u;
            }
        }
        {
            E T1v, T2z, T2O, T2Q, T2i, T2y, T2x, T2P;
            {
                E TX, T1u, T2G, T2N;
                TX = Tx + TW;
                T1u = T1g + T1t;
                T1v = TX + T1u;
                T2z = T1u - TX;
                T2G = T2C + T2F;
                T2N = T2J + T2M;
                T2O = T2G - T2N;
                T2Q = T2G + T2N;
            }
            {
                E T1U, T2h, T2p, T2w;
                T1U = T1E - T1T;
                T2h = T27 + T2g;
                T2i = T1U - T2h;
                T2y = T2h + T1U;
                T2p = T2l + T2o;
                T2w = T2s + T2v;
                T2x = T2p - T2w;
                T2P = T2p + T2w;
            }
            Ip[0] = KP500000000 * (T1v + T2i);
            Rp[0] = KP500000000 * (T2P + T2Q);
            Im[(rs[7])] = KP500000000 * (T2i - T1v);
            Rm[(rs[7])] = KP500000000 * (T2P - T2Q);
            Rm[(rs[3])] = KP500000000 * (T2x - T2y);
            Im[(rs[3])] = KP500000000 * (T2O - T2z);
            Rp[(rs[4])] = KP500000000 * (T2x + T2y);
            Ip[(rs[4])] = KP500000000 * (T2z + T2O);
        }
        {
            E T2T, T35, T33, T39, T2W, T36, T2Z, T37;
            {
                E T2R, T2S, T31, T32;
                T2R = T2v - T2s;
                T2S = T1t - T1g;
                T2T = KP500000000 * (T2R + T2S);
                T35 = KP500000000 * (T2S - T2R);
                T31 = T2l - T2o;
                T32 = Tx - TW;
                T33 = KP500000000 * (T31 - T32);
                T39 = KP500000000 * (T31 + T32);
            }
            {
                E T2U, T2V, T2X, T2Y;
                T2U = T2F - T2C;
                T2V = T27 - T2g;
                T2W = T2U + T2V;
                T36 = T2U - T2V;
                T2X = T1T + T1E;
                T2Y = T2M - T2J;
                T2Z = T2X - T2Y;
                T37 = T2X + T2Y;
            }
            {
                E T30, T3a, T34, T38;
                T30 = KP353553390 * (T2W + T2Z);
                Ip[(rs[2])] = T2T + T30;
                Im[(rs[5])] = T30 - T2T;
                T3a = KP353553390 * (T36 + T37);
                Rm[(rs[5])] = T39 - T3a;
                Rp[(rs[2])] = T39 + T3a;
                T34 = KP353553390 * (T2Z - T2W);
                Rm[(rs[1])] = T33 - T34;
                Rp[(rs[6])] = T33 + T34;
                T38 = KP353553390 * (T36 - T37);
                Ip[(rs[6])] = T35 + T38;
                Im[(rs[1])] = T38 - T35;
            }
        }
        {
            E T3k, T3Q, T3Z, T3D, T3h, T40, T3X, T45, T3G, T3P, T3s, T3K, T3U, T44, T3z;
            E T3L;
            {
                E T3d, T3g, T3o, T3r;
                T3k = KP500000000 * (T3i - T3j);
                T3Q = KP500000000 * (T3j + T3i);
                T3Z = KP500000000 * (T3B - T3C);
                T3D = KP500000000 * (T3B + T3C);
                T3d = T3b - T3c;
                T3g = T3e + T3f;
                T3h = KP353553390 * (T3d + T3g);
                T40 = KP353553390 * (T3d - T3g);
                {
                    E T3V, T3W, T3E, T3F;
                    T3V = T3u + T3t;
                    T3W = T3x - T3w;
                    T3X = ((KP191341716 * T3V) - ((KP461939766) * (T3W)));
                    T45 = (((KP461939766) * (T3V)) + (KP191341716 * T3W));
                    T3E = T3c + T3b;
                    T3F = T3e - T3f;
                    T3G = KP353553390 * (T3E + T3F);
                    T3P = KP353553390 * (T3F - T3E);
                }
                T3o = T3m + T3n;
                T3r = T3p - T3q;
                T3s = (((KP191341716) * (T3o)) + (KP461939766 * T3r));
                T3K = ((KP461939766 * T3o) - ((KP191341716) * (T3r)));
                {
                    E T3S, T3T, T3v, T3y;
                    T3S = T3n - T3m;
                    T3T = T3q + T3p;
                    T3U = (((KP461939766) * (T3S)) + (KP191341716 * T3T));
                    T44 = ((KP191341716 * T3S) - ((KP461939766) * (T3T)));
                    T3v = T3t - T3u;
                    T3y = T3w + T3x;
                    T3z = ((KP461939766 * T3v) - ((KP191341716) * (T3y)));
                    T3L = (((KP191341716) * (T3v)) + (KP461939766 * T3y));
                }
            }
            {
                E T3l, T3A, T3N, T3O;
                T3l = T3h + T3k;
                T3A = T3s + T3z;
                Ip[(rs[1])] = T3l + T3A;
                Im[(rs[6])] = T3A - T3l;
                T3N = T3D + T3G;
                T3O = T3K + T3L;
                Rm[(rs[6])] = T3N - T3O;
                Rp[(rs[1])] = T3N + T3O;
            }
            {
                E T3H, T3I, T3J, T3M;
                T3H = T3D - T3G;
                T3I = T3z - T3s;
                Rm[(rs[2])] = T3H - T3I;
                Rp[(rs[5])] = T3H + T3I;
                T3J = T3k - T3h;
                T3M = T3K - T3L;
                Ip[(rs[5])] = T3J + T3M;
                Im[(rs[2])] = T3M - T3J;
            }
            {
                E T3R, T3Y, T47, T48;
                T3R = T3P + T3Q;
                T3Y = T3U + T3X;
                Ip[(rs[3])] = T3R + T3Y;
                Im[(rs[4])] = T3Y - T3R;
                T47 = T3Z + T40;
                T48 = T44 + T45;
                Rm[(rs[4])] = T47 - T48;
                Rp[(rs[3])] = T47 + T48;
            }
            {
                E T41, T42, T43, T46;
                T41 = T3Z - T40;
                T42 = T3X - T3U;
                Rm[0] = T41 - T42;
                Rp[(rs[7])] = T41 + T42;
                T43 = T3Q - T3P;
                T46 = T44 - T45;
                Ip[(rs[7])] = T43 + T46;
                Im[0] = T46 - T43;
            }
        }
    }
}

}
