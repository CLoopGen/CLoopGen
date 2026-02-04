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
for (m = mb , W = W + ((mb - 1) * 30); m < me; m = m + 1 , Rp = Rp + ms , Ip = Ip + ms , Rm = Rm - ms , Im = Im - ms , W = W + 30 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T19, T3h, T21, T2Y, T1o, T3d, T2s, T39, TW, T3i, T24, T2Z, T1z, T3c, T2p;
    E T3a, Tj, T2S, T28, T2R, T1L, T36, T2i, T32, TC, T2V, T2b, T2U, T1W, T35;
    E T2l, T33;
    {
        E T10, T1m, T14, T1k, T18, T1h, T1f, T1Z;
        {
            E TY, TZ, T12, T13;
            TY = Ip[(rs[4])];
            TZ = Im[(rs[4])];
            T10 = TY - TZ;
            T1m = TY + TZ;
            T12 = Rp[(rs[4])];
            T13 = Rm[(rs[4])];
            T14 = T12 + T13;
            T1k = T12 - T13;
        }
        {
            E T16, T17, T1d, T1e;
            T16 = Ip[0];
            T17 = Im[0];
            T18 = T16 - T17;
            T1h = T16 + T17;
            T1d = Rm[0];
            T1e = Rp[0];
            T1f = T1d - T1e;
            T1Z = T1e + T1d;
        }
        {
            E T15, T20, TX, T11;
            TX = W[14];
            T11 = W[15];
            T15 = ((TX * T10) - ((T11) * (T14)));
            T20 = (((TX) * (T14)) + (T11 * T10));
            T19 = T15 + T18;
            T3h = T1Z - T20;
            T21 = T1Z + T20;
            T2Y = T18 - T15;
        }
        {
            E T1i, T2r, T1n, T2q;
            {
                E T1c, T1g, T1j, T1l;
                T1c = W[0];
                T1g = W[1];
                T1i = ((T1c * T1f) - ((T1g) * (T1h)));
                T2r = (((T1g) * (T1f)) + (T1c * T1h));
                T1j = W[16];
                T1l = W[17];
                T1n = (((T1j) * (T1k)) + (T1l * T1m));
                T2q = ((T1j * T1m) - ((T1l) * (T1k)));
            }
            T1o = T1i - T1n;
            T3d = T2r - T2q;
            T2s = T2q + T2r;
            T39 = T1n + T1i;
        }
    }
    {
        E TH, T1s, TL, T1q, TQ, T1x, TU, T1v;
        {
            E TF, TG, TJ, TK;
            TF = Ip[(rs[2])];
            TG = Im[(rs[2])];
            TH = TF - TG;
            T1s = TF + TG;
            TJ = Rp[(rs[2])];
            TK = Rm[(rs[2])];
            TL = TJ + TK;
            T1q = TJ - TK;
        }
        {
            E TO, TP, TS, TT;
            TO = Ip[(rs[6])];
            TP = Im[(rs[6])];
            TQ = TO - TP;
            T1x = TO + TP;
            TS = Rp[(rs[6])];
            TT = Rm[(rs[6])];
            TU = TS + TT;
            T1v = TS - TT;
        }
        {
            E TM, T22, TV, T23;
            {
                E TE, TI, TN, TR;
                TE = W[6];
                TI = W[7];
                TM = ((TE * TH) - ((TI) * (TL)));
                T22 = (((TE) * (TL)) + (TI * TH));
                TN = W[22];
                TR = W[23];
                TV = ((TN * TQ) - ((TR) * (TU)));
                T23 = (((TN) * (TU)) + (TR * TQ));
            }
            TW = TM + TV;
            T3i = TM - TV;
            T24 = T22 + T23;
            T2Z = T22 - T23;
        }
        {
            E T1t, T2n, T1y, T2o;
            {
                E T1p, T1r, T1u, T1w;
                T1p = W[8];
                T1r = W[9];
                T1t = (((T1p) * (T1q)) + (T1r * T1s));
                T2n = ((T1p * T1s) - ((T1r) * (T1q)));
                T1u = W[24];
                T1w = W[25];
                T1y = (((T1u) * (T1v)) + (T1w * T1x));
                T2o = ((T1u * T1x) - ((T1w) * (T1v)));
            }
            T1z = T1t + T1y;
            T3c = T1y - T1t;
            T2p = T2n + T2o;
            T3a = T2n - T2o;
        }
    }
    {
        E T4, T1E, T8, T1C, Td, T1J, Th, T1H;
        {
            E T2, T3, T6, T7;
            T2 = Ip[(rs[1])];
            T3 = Im[(rs[1])];
            T4 = T2 - T3;
            T1E = T2 + T3;
            T6 = Rp[(rs[1])];
            T7 = Rm[(rs[1])];
            T8 = T6 + T7;
            T1C = T6 - T7;
        }
        {
            E Tb, Tc, Tf, Tg;
            Tb = Ip[(rs[5])];
            Tc = Im[(rs[5])];
            Td = Tb - Tc;
            T1J = Tb + Tc;
            Tf = Rp[(rs[5])];
            Tg = Rm[(rs[5])];
            Th = Tf + Tg;
            T1H = Tf - Tg;
        }
        {
            E T9, T26, Ti, T27;
            {
                E T1, T5, Ta, Te;
                T1 = W[2];
                T5 = W[3];
                T9 = ((T1 * T4) - ((T5) * (T8)));
                T26 = (((T1) * (T8)) + (T5 * T4));
                Ta = W[18];
                Te = W[19];
                Ti = ((Ta * Td) - ((Te) * (Th)));
                T27 = (((Ta) * (Th)) + (Te * Td));
            }
            Tj = T9 + Ti;
            T2S = T26 - T27;
            T28 = T26 + T27;
            T2R = T9 - Ti;
        }
        {
            E T1F, T2g, T1K, T2h;
            {
                E T1B, T1D, T1G, T1I;
                T1B = W[4];
                T1D = W[5];
                T1F = (((T1B) * (T1C)) + (T1D * T1E));
                T2g = ((T1B * T1E) - ((T1D) * (T1C)));
                T1G = W[20];
                T1I = W[21];
                T1K = (((T1G) * (T1H)) + (T1I * T1J));
                T2h = ((T1G * T1J) - ((T1I) * (T1H)));
            }
            T1L = T1F + T1K;
            T36 = T2g - T2h;
            T2i = T2g + T2h;
            T32 = T1K - T1F;
        }
    }
    {
        E Tn, T1P, Tr, T1N, Tw, T1U, TA, T1S;
        {
            E Tl, Tm, Tp, Tq;
            Tl = Ip[(rs[7])];
            Tm = Im[(rs[7])];
            Tn = Tl - Tm;
            T1P = Tl + Tm;
            Tp = Rp[(rs[7])];
            Tq = Rm[(rs[7])];
            Tr = Tp + Tq;
            T1N = Tp - Tq;
        }
        {
            E Tu, Tv, Ty, Tz;
            Tu = Ip[(rs[3])];
            Tv = Im[(rs[3])];
            Tw = Tu - Tv;
            T1U = Tu + Tv;
            Ty = Rp[(rs[3])];
            Tz = Rm[(rs[3])];
            TA = Ty + Tz;
            T1S = Ty - Tz;
        }
        {
            E Ts, T29, TB, T2a;
            {
                E Tk, To, Tt, Tx;
                Tk = W[26];
                To = W[27];
                Ts = ((Tk * Tn) - ((To) * (Tr)));
                T29 = (((Tk) * (Tr)) + (To * Tn));
                Tt = W[10];
                Tx = W[11];
                TB = ((Tt * Tw) - ((Tx) * (TA)));
                T2a = (((Tt) * (TA)) + (Tx * Tw));
            }
            TC = Ts + TB;
            T2V = Ts - TB;
            T2b = T29 + T2a;
            T2U = T29 - T2a;
        }
        {
            E T1Q, T2j, T1V, T2k;
            {
                E T1M, T1O, T1R, T1T;
                T1M = W[28];
                T1O = W[29];
                T1Q = (((T1M) * (T1N)) + (T1O * T1P));
                T2j = ((T1M * T1P) - ((T1O) * (T1N)));
                T1R = W[12];
                T1T = W[13];
                T1V = (((T1R) * (T1S)) + (T1T * T1U));
                T2k = ((T1R * T1U) - ((T1T) * (T1S)));
            }
            T1W = T1Q + T1V;
            T35 = T1V - T1Q;
            T2l = T2j + T2k;
            T33 = T2j - T2k;
        }
    }
    {
        E T1b, T2f, T2u, T2w, T1Y, T2e, T2d, T2v;
        {
            E TD, T1a, T2m, T2t;
            TD = Tj + TC;
            T1a = TW + T19;
            T1b = TD + T1a;
            T2f = T1a - TD;
            T2m = T2i + T2l;
            T2t = T2p + T2s;
            T2u = T2m - T2t;
            T2w = T2m + T2t;
        }
        {
            E T1A, T1X, T25, T2c;
            T1A = T1o - T1z;
            T1X = T1L + T1W;
            T1Y = T1A - T1X;
            T2e = T1X + T1A;
            T25 = T21 + T24;
            T2c = T28 + T2b;
            T2d = T25 - T2c;
            T2v = T25 + T2c;
        }
        Ip[0] = KP500000000 * (T1b + T1Y);
        Rp[0] = KP500000000 * (T2v + T2w);
        Im[(rs[7])] = KP500000000 * (T1Y - T1b);
        Rm[(rs[7])] = KP500000000 * (T2v - T2w);
        Rm[(rs[3])] = KP500000000 * (T2d - T2e);
        Im[(rs[3])] = KP500000000 * (T2u - T2f);
        Rp[(rs[4])] = KP500000000 * (T2d + T2e);
        Ip[(rs[4])] = KP500000000 * (T2f + T2u);
    }
    {
        E T2z, T2L, T2J, T2P, T2C, T2M, T2F, T2N;
        {
            E T2x, T2y, T2H, T2I;
            T2x = T2b - T28;
            T2y = T19 - TW;
            T2z = KP500000000 * (T2x + T2y);
            T2L = KP500000000 * (T2y - T2x);
            T2H = T21 - T24;
            T2I = Tj - TC;
            T2J = KP500000000 * (T2H - T2I);
            T2P = KP500000000 * (T2H + T2I);
        }
        {
            E T2A, T2B, T2D, T2E;
            T2A = T2l - T2i;
            T2B = T1L - T1W;
            T2C = T2A + T2B;
            T2M = T2A - T2B;
            T2D = T1z + T1o;
            T2E = T2s - T2p;
            T2F = T2D - T2E;
            T2N = T2D + T2E;
        }
        {
            E T2G, T2Q, T2K, T2O;
            T2G = KP353553390 * (T2C + T2F);
            Ip[(rs[2])] = T2z + T2G;
            Im[(rs[5])] = T2G - T2z;
            T2Q = KP353553390 * (T2M + T2N);
            Rm[(rs[5])] = T2P - T2Q;
            Rp[(rs[2])] = T2P + T2Q;
            T2K = KP353553390 * (T2F - T2C);
            Rm[(rs[1])] = T2J - T2K;
            Rp[(rs[6])] = T2J + T2K;
            T2O = KP353553390 * (T2M - T2N);
            Ip[(rs[6])] = T2L + T2O;
            Im[(rs[1])] = T2O - T2L;
        }
    }
    {
        E T30, T3w, T3F, T3j, T2X, T3G, T3D, T3L, T3m, T3v, T38, T3q, T3A, T3K, T3f;
        E T3r;
        {
            E T2T, T2W, T34, T37;
            T30 = KP500000000 * (T2Y - T2Z);
            T3w = KP500000000 * (T2Z + T2Y);
            T3F = KP500000000 * (T3h - T3i);
            T3j = KP500000000 * (T3h + T3i);
            T2T = T2R - T2S;
            T2W = T2U + T2V;
            T2X = KP353553390 * (T2T + T2W);
            T3G = KP353553390 * (T2T - T2W);
            {
                E T3B, T3C, T3k, T3l;
                T3B = T3a + T39;
                T3C = T3d - T3c;
                T3D = ((KP191341716 * T3B) - ((KP461939766) * (T3C)));
                T3L = (((KP461939766) * (T3B)) + (KP191341716 * T3C));
                T3k = T3d + T3c;
                T3l = T3a - T39;
                T3m = KP353553390 * (T3k + T3l);
                T3v = KP353553390 * (T3l - T3k);
            }
            T34 = T32 + T33;
            T37 = T35 - T36;
            T38 = (((KP191341716) * (T34)) + (KP461939766 * T37));
            T3q = ((KP461939766 * T34) - ((KP191341716) * (T37)));
            {
                E T3y, T3z, T3b, T3e;
                T3y = T33 - T32;
                T3z = T36 + T35;
                T3A = (((KP461939766) * (T3y)) + (KP191341716 * T3z));
                T3K = ((KP191341716 * T3y) - ((KP461939766) * (T3z)));
                T3b = T39 - T3a;
                T3e = T3c + T3d;
                T3f = ((KP461939766 * T3b) - ((KP191341716) * (T3e)));
                T3r = (((KP191341716) * (T3b)) + (KP461939766 * T3e));
            }
        }
        {
            E T31, T3g, T3t, T3u;
            T31 = T2X + T30;
            T3g = T38 + T3f;
            Ip[(rs[1])] = T31 + T3g;
            Im[(rs[6])] = T3g - T31;
            T3t = T3j + T3m;
            T3u = T3q + T3r;
            Rm[(rs[6])] = T3t - T3u;
            Rp[(rs[1])] = T3t + T3u;
        }
        {
            E T3n, T3o, T3p, T3s;
            T3n = T3j - T3m;
            T3o = T3f - T38;
            Rm[(rs[2])] = T3n - T3o;
            Rp[(rs[5])] = T3n + T3o;
            T3p = T30 - T2X;
            T3s = T3q - T3r;
            Ip[(rs[5])] = T3p + T3s;
            Im[(rs[2])] = T3s - T3p;
        }
        {
            E T3x, T3E, T3N, T3O;
            T3x = T3v + T3w;
            T3E = T3A + T3D;
            Ip[(rs[3])] = T3x + T3E;
            Im[(rs[4])] = T3E - T3x;
            T3N = T3F + T3G;
            T3O = T3K + T3L;
            Rm[(rs[4])] = T3N - T3O;
            Rp[(rs[3])] = T3N + T3O;
        }
        {
            E T3H, T3I, T3J, T3M;
            T3H = T3F - T3G;
            T3I = T3D - T3A;
            Rm[0] = T3H - T3I;
            Rp[(rs[7])] = T3H + T3I;
            T3J = T3w - T3v;
            T3M = T3K - T3L;
            Ip[(rs[7])] = T3J + T3M;
            Im[0] = T3M - T3J;
        }
    }
}
}
