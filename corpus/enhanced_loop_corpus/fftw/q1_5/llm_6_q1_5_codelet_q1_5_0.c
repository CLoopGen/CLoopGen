#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *rio;
extern R *iio;
extern  R *W;
extern stride rs;
extern stride vs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP250000000;
extern  E KP587785252;
extern  E KP951056516;
extern  E KP559016994;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + (mb * 8); m < me; m = m + 1 , rio = rio + ms , iio = iio + ms , W = W + 8 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (vs) = (vs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, Ta, TG, Tv, T8, Tb, Tp, Tj, TD, To, Tq, Tr, TN, TW, T1s;
    E T1h, TU, TX, T1b, T15, T1p, T1a, T1c, T1d, T1z, T1I, T2e, T23, T1G, T1J;
    E T1X, T1R, T2b, T1W, T1Y, T1Z, T3v, T3p, T3J, T3u, T3w, T3x, T37, T3g, T3M;
    E T3B, T3e, T3h, T2l, T2u, T30, T2P, T2s, T2v, T2J, T2D, T2X, T2I, T2K, T2L;
    {
        E T7, Tu, T4, Tt;
        T1 = rio[0];
        {
            E T5, T6, T2, T3;
            T5 = rio[(rs[2])];
            T6 = rio[(rs[3])];
            T7 = T5 + T6;
            Tu = T5 - T6;
            T2 = rio[(rs[1])];
            T3 = rio[(rs[4])];
            T4 = T2 + T3;
            Tt = T2 - T3;
        }
        Ta = KP559016994 * (T4 - T7);
        TG = ((KP951056516 * Tu) - ((KP587785252) * (Tt)));
        Tv = (((KP951056516) * (Tt)) + (KP587785252 * Tu));
        T8 = T4 + T7;
        Tb = ((T1) - ((KP250000000) * (T8)));
    }
    {
        E Ti, Tn, Tf, Tm;
        Tp = iio[0];
        {
            E Tg, Th, Td, Te;
            Tg = iio[(rs[2])];
            Th = iio[(rs[3])];
            Ti = Tg - Th;
            Tn = Tg + Th;
            Td = iio[(rs[1])];
            Te = iio[(rs[4])];
            Tf = Td - Te;
            Tm = Td + Te;
        }
        Tj = (((KP951056516) * (Tf)) + (KP587785252 * Ti));
        TD = ((KP951056516 * Ti) - ((KP587785252) * (Tf)));
        To = KP559016994 * (Tm - Tn);
        Tq = Tm + Tn;
        Tr = ((Tp) - ((KP250000000) * (Tq)));
    }
    {
        E TT, T1g, TQ, T1f;
        TN = rio[(vs[1])];
        {
            E TR, TS, TO, TP;
            TR = rio[(vs[1]) + (rs[2])];
            TS = rio[(vs[1]) + (rs[3])];
            TT = TR + TS;
            T1g = TR - TS;
            TO = rio[(vs[1]) + (rs[1])];
            TP = rio[(vs[1]) + (rs[4])];
            TQ = TO + TP;
            T1f = TO - TP;
        }
        TW = KP559016994 * (TQ - TT);
        T1s = ((KP951056516 * T1g) - ((KP587785252) * (T1f)));
        T1h = (((KP951056516) * (T1f)) + (KP587785252 * T1g));
        TU = TQ + TT;
        TX = ((TN) - ((KP250000000) * (TU)));
    }
    {
        E T14, T19, T11, T18;
        T1b = iio[(vs[1])];
        {
            E T12, T13, TZ, T10;
            T12 = iio[(vs[1]) + (rs[2])];
            T13 = iio[(vs[1]) + (rs[3])];
            T14 = T12 - T13;
            T19 = T12 + T13;
            TZ = iio[(vs[1]) + (rs[1])];
            T10 = iio[(vs[1]) + (rs[4])];
            T11 = TZ - T10;
            T18 = TZ + T10;
        }
        T15 = (((KP951056516) * (T11)) + (KP587785252 * T14));
        T1p = ((KP951056516 * T14) - ((KP587785252) * (T11)));
        T1a = KP559016994 * (T18 - T19);
        T1c = T18 + T19;
        T1d = ((T1b) - ((KP250000000) * (T1c)));
    }
    {
        E T1F, T22, T1C, T21;
        T1z = rio[(vs[2])];
        {
            E T1D, T1E, T1A, T1B;
            T1D = rio[(vs[2]) + (rs[2])];
            T1E = rio[(vs[2]) + (rs[3])];
            T1F = T1D + T1E;
            T22 = T1D - T1E;
            T1A = rio[(vs[2]) + (rs[1])];
            T1B = rio[(vs[2]) + (rs[4])];
            T1C = T1A + T1B;
            T21 = T1A - T1B;
        }
        T1I = KP559016994 * (T1C - T1F);
        T2e = ((KP951056516 * T22) - ((KP587785252) * (T21)));
        T23 = (((KP951056516) * (T21)) + (KP587785252 * T22));
        T1G = T1C + T1F;
        T1J = ((T1z) - ((KP250000000) * (T1G)));
    }
    {
        E T1Q, T1V, T1N, T1U;
        T1X = iio[(vs[2])];
        {
            E T1O, T1P, T1L, T1M;
            T1O = iio[(vs[2]) + (rs[2])];
            T1P = iio[(vs[2]) + (rs[3])];
            T1Q = T1O - T1P;
            T1V = T1O + T1P;
            T1L = iio[(vs[2]) + (rs[1])];
            T1M = iio[(vs[2]) + (rs[4])];
            T1N = T1L - T1M;
            T1U = T1L + T1M;
        }
        T1R = (((KP951056516) * (T1N)) + (KP587785252 * T1Q));
        T2b = ((KP951056516 * T1Q) - ((KP587785252) * (T1N)));
        T1W = KP559016994 * (T1U - T1V);
        T1Y = T1U + T1V;
        T1Z = ((T1X) - ((KP250000000) * (T1Y)));
    }
    {
        E T3o, T3t, T3l, T3s;
        T3v = iio[(vs[4])];
        {
            E T3m, T3n, T3j, T3k;
            T3m = iio[(vs[4]) + (rs[2])];
            T3n = iio[(vs[4]) + (rs[3])];
            T3o = T3m - T3n;
            T3t = T3m + T3n;
            T3j = iio[(vs[4]) + (rs[1])];
            T3k = iio[(vs[4]) + (rs[4])];
            T3l = T3j - T3k;
            T3s = T3j + T3k;
        }
        T3p = (((KP951056516) * (T3l)) + (KP587785252 * T3o));
        T3J = ((KP951056516 * T3o) - ((KP587785252) * (T3l)));
        T3u = KP559016994 * (T3s - T3t);
        T3w = T3s + T3t;
        T3x = ((T3v) - ((KP250000000) * (T3w)));
    }
    {
        E T3d, T3A, T3a, T3z;
        T37 = rio[(vs[4])];
        {
            E T3b, T3c, T38, T39;
            T3b = rio[(vs[4]) + (rs[2])];
            T3c = rio[(vs[4]) + (rs[3])];
            T3d = T3b + T3c;
            T3A = T3b - T3c;
            T38 = rio[(vs[4]) + (rs[1])];
            T39 = rio[(vs[4]) + (rs[4])];
            T3a = T38 + T39;
            T3z = T38 - T39;
        }
        T3g = KP559016994 * (T3a - T3d);
        T3M = ((KP951056516 * T3A) - ((KP587785252) * (T3z)));
        T3B = (((KP951056516) * (T3z)) + (KP587785252 * T3A));
        T3e = T3a + T3d;
        T3h = ((T37) - ((KP250000000) * (T3e)));
    }
    {
        E T2r, T2O, T2o, T2N;
        T2l = rio[(vs[3])];
        {
            E T2p, T2q, T2m, T2n;
            T2p = rio[(vs[3]) + (rs[2])];
            T2q = rio[(vs[3]) + (rs[3])];
            T2r = T2p + T2q;
            T2O = T2p - T2q;
            T2m = rio[(vs[3]) + (rs[1])];
            T2n = rio[(vs[3]) + (rs[4])];
            T2o = T2m + T2n;
            T2N = T2m - T2n;
        }
        T2u = KP559016994 * (T2o - T2r);
        T30 = ((KP951056516 * T2O) - ((KP587785252) * (T2N)));
        T2P = (((KP951056516) * (T2N)) + (KP587785252 * T2O));
        T2s = T2o + T2r;
        T2v = ((T2l) - ((KP250000000) * (T2s)));
    }
    {
        E T2C, T2H, T2z, T2G;
        T2J = iio[(vs[3])];
        {
            E T2A, T2B, T2x, T2y;
            T2A = iio[(vs[3]) + (rs[2])];
            T2B = iio[(vs[3]) + (rs[3])];
            T2C = T2A - T2B;
            T2H = T2A + T2B;
            T2x = iio[(vs[3]) + (rs[1])];
            T2y = iio[(vs[3]) + (rs[4])];
            T2z = T2x - T2y;
            T2G = T2x + T2y;
        }
        T2D = (((KP951056516) * (T2z)) + (KP587785252 * T2C));
        T2X = ((KP951056516 * T2C) - ((KP587785252) * (T2z)));
        T2I = KP559016994 * (T2G - T2H);
        T2K = T2G + T2H;
        T2L = ((T2J) - ((KP250000000) * (T2K)));
    }
    rio[0] = T1 + T8;
    iio[0] = Tp + Tq;
    rio[(rs[1])] = TN + TU;
    iio[(rs[1])] = T1b + T1c;
    rio[(rs[2])] = T1z + T1G;
    iio[(rs[2])] = T1X + T1Y;
    iio[(rs[4])] = T3v + T3w;
    rio[(rs[4])] = T37 + T3e;
    rio[(rs[3])] = T2l + T2s;
    iio[(rs[3])] = T2J + T2K;
    {
        E Tk, Ty, Tw, TA, Tc, Ts;
        Tc = Ta + Tb;
        Tk = Tc + Tj;
        Ty = Tc - Tj;
        Ts = To + Tr;
        Tw = Ts - Tv;
        TA = Tv + Ts;
        {
            E T9, Tl, Tx, Tz;
            T9 = W[0];
            Tl = W[1];
            rio[(vs[1])] = (((T9) * (Tk)) + (Tl * Tw));
            iio[(vs[1])] = ((T9 * Tw) - ((Tl) * (Tk)));
            Tx = W[6];
            Tz = W[7];
            rio[(vs[4])] = (((Tx) * (Ty)) + (Tz * TA));
            iio[(vs[4])] = ((Tx * TA) - ((Tz) * (Ty)));
        }
    }
    {
        E TE, TK, TI, TM, TC, TH;
        TC = Tb - Ta;
        TE = TC - TD;
        TK = TC + TD;
        TH = Tr - To;
        TI = TG + TH;
        TM = TH - TG;
        {
            E TB, TF, TJ, TL;
            TB = W[2];
            TF = W[3];
            rio[(vs[2])] = (((TB) * (TE)) + (TF * TI));
            iio[(vs[2])] = ((TB * TI) - ((TF) * (TE)));
            TJ = W[4];
            TL = W[5];
            rio[(vs[3])] = (((TJ) * (TK)) + (TL * TM));
            iio[(vs[3])] = ((TJ * TM) - ((TL) * (TK)));
        }
    }
    {
        E T2c, T2i, T2g, T2k, T2a, T2f;
        T2a = T1J - T1I;
        T2c = T2a - T2b;
        T2i = T2a + T2b;
        T2f = T1Z - T1W;
        T2g = T2e + T2f;
        T2k = T2f - T2e;
        {
            E T29, T2d, T2h, T2j;
            T29 = W[2];
            T2d = W[3];
            rio[(vs[2]) + (rs[2])] = (((T29) * (T2c)) + (T2d * T2g));
            iio[(vs[2]) + (rs[2])] = ((T29 * T2g) - ((T2d) * (T2c)));
            T2h = W[4];
            T2j = W[5];
            rio[(vs[3]) + (rs[2])] = (((T2h) * (T2i)) + (T2j * T2k));
            iio[(vs[3]) + (rs[2])] = ((T2h * T2k) - ((T2j) * (T2i)));
        }
    }
    {
        E T3K, T3Q, T3O, T3S, T3I, T3N;
        T3I = T3h - T3g;
        T3K = T3I - T3J;
        T3Q = T3I + T3J;
        T3N = T3x - T3u;
        T3O = T3M + T3N;
        T3S = T3N - T3M;
        {
            E T3H, T3L, T3P, T3R;
            T3H = W[2];
            T3L = W[3];
            rio[(vs[2]) + (rs[4])] = (((T3H) * (T3K)) + (T3L * T3O));
            iio[(vs[2]) + (rs[4])] = ((T3H * T3O) - ((T3L) * (T3K)));
            T3P = W[4];
            T3R = W[5];
            rio[(vs[3]) + (rs[4])] = (((T3P) * (T3Q)) + (T3R * T3S));
            iio[(vs[3]) + (rs[4])] = ((T3P * T3S) - ((T3R) * (T3Q)));
        }
    }
    {
        E T1S, T26, T24, T28, T1K, T20;
        T1K = T1I + T1J;
        T1S = T1K + T1R;
        T26 = T1K - T1R;
        T20 = T1W + T1Z;
        T24 = T20 - T23;
        T28 = T23 + T20;
        {
            E T1H, T1T, T25, T27;
            T1H = W[0];
            T1T = W[1];
            rio[(vs[1]) + (rs[2])] = (((T1H) * (T1S)) + (T1T * T24));
            iio[(vs[1]) + (rs[2])] = ((T1H * T24) - ((T1T) * (T1S)));
            T25 = W[6];
            T27 = W[7];
            rio[(vs[4]) + (rs[2])] = (((T25) * (T26)) + (T27 * T28));
            iio[(vs[4]) + (rs[2])] = ((T25 * T28) - ((T27) * (T26)));
        }
    }
    {
        E T2E, T2S, T2Q, T2U, T2w, T2M;
        T2w = T2u + T2v;
        T2E = T2w + T2D;
        T2S = T2w - T2D;
        T2M = T2I + T2L;
        T2Q = T2M - T2P;
        T2U = T2P + T2M;
        {
            E T2t, T2F, T2R, T2T;
            T2t = W[0];
            T2F = W[1];
            rio[(vs[1]) + (rs[3])] = (((T2t) * (T2E)) + (T2F * T2Q));
            iio[(vs[1]) + (rs[3])] = ((T2t * T2Q) - ((T2F) * (T2E)));
            T2R = W[6];
            T2T = W[7];
            rio[(vs[4]) + (rs[3])] = (((T2R) * (T2S)) + (T2T * T2U));
            iio[(vs[4]) + (rs[3])] = ((T2R * T2U) - ((T2T) * (T2S)));
        }
    }
    {
        E T2Y, T34, T32, T36, T2W, T31;
        T2W = T2v - T2u;
        T2Y = T2W - T2X;
        T34 = T2W + T2X;
        T31 = T2L - T2I;
        T32 = T30 + T31;
        T36 = T31 - T30;
        {
            E T2V, T2Z, T33, T35;
            T2V = W[2];
            T2Z = W[3];
            rio[(vs[2]) + (rs[3])] = (((T2V) * (T2Y)) + (T2Z * T32));
            iio[(vs[2]) + (rs[3])] = ((T2V * T32) - ((T2Z) * (T2Y)));
            T33 = W[4];
            T35 = W[5];
            rio[(vs[3]) + (rs[3])] = (((T33) * (T34)) + (T35 * T36));
            iio[(vs[3]) + (rs[3])] = ((T33 * T36) - ((T35) * (T34)));
        }
    }
    {
        E T3q, T3E, T3C, T3G, T3i, T3y;
        T3i = T3g + T3h;
        T3q = T3i + T3p;
        T3E = T3i - T3p;
        T3y = T3u + T3x;
        T3C = T3y - T3B;
        T3G = T3B + T3y;
        {
            E T3f, T3r, T3D, T3F;
            T3f = W[0];
            T3r = W[1];
            rio[(vs[1]) + (rs[4])] = (((T3f) * (T3q)) + (T3r * T3C));
            iio[(vs[1]) + (rs[4])] = ((T3f * T3C) - ((T3r) * (T3q)));
            T3D = W[6];
            T3F = W[7];
            rio[(vs[4]) + (rs[4])] = (((T3D) * (T3E)) + (T3F * T3G));
            iio[(vs[4]) + (rs[4])] = ((T3D * T3G) - ((T3F) * (T3E)));
        }
    }
    {
        E T1q, T1w, T1u, T1y, T1o, T1t;
        T1o = TX - TW;
        T1q = T1o - T1p;
        T1w = T1o + T1p;
        T1t = T1d - T1a;
        T1u = T1s + T1t;
        T1y = T1t - T1s;
        {
            E T1n, T1r, T1v, T1x;
            T1n = W[2];
            T1r = W[3];
            rio[(vs[2]) + (rs[1])] = (((T1n) * (T1q)) + (T1r * T1u));
            iio[(vs[2]) + (rs[1])] = ((T1n * T1u) - ((T1r) * (T1q)));
            T1v = W[4];
            T1x = W[5];
            rio[(vs[3]) + (rs[1])] = (((T1v) * (T1w)) + (T1x * T1y));
            iio[(vs[3]) + (rs[1])] = ((T1v * T1y) - ((T1x) * (T1w)));
        }
    }
    {
        E T16, T1k, T1i, T1m, TY, T1e;
        TY = TW + TX;
        T16 = TY + T15;
        T1k = TY - T15;
        T1e = T1a + T1d;
        T1i = T1e - T1h;
        T1m = T1h + T1e;
        {
            E TV, T17, T1j, T1l;
            TV = W[0];
            T17 = W[1];
            rio[(vs[1]) + (rs[1])] = (((TV) * (T16)) + (T17 * T1i));
            iio[(vs[1]) + (rs[1])] = ((TV * T1i) - ((T17) * (T16)));
            T1j = W[6];
            T1l = W[7];
            rio[(vs[4]) + (rs[1])] = (((T1j) * (T1k)) + (T1l * T1m));
            iio[(vs[4]) + (rs[1])] = ((T1j * T1m) - ((T1l) * (T1k)));
        }
    }
}

}
