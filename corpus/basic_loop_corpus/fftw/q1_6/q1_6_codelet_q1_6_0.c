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
extern  E KP500000000;
extern  E KP866025403;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (m = mb , W = W + (mb * 10); m < me; m = m + 1 , rio = rio + ms , iio = iio + ms , W = W + 10 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (vs) = (vs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, Tc, Tt, TM, TX, T16, T1n, T1G, T2h, T2A, T1R, T20, T2L, T2U, T3b;
    E T3u, T3F, T3O, T45, T4o, T4Z, T5i, T4z, T4I, Ta, TP, Tf, Tq, Tn, TN;
    E Tu, TJ, T14, T1J, T19, T1k, T1h, T1H, T1o, T1D, T2b, T2B, T2i, T2x, T1Y;
    E T2D, T23, T2e, T2S, T3x, T2X, T38, T35, T3v, T3c, T3r, T3M, T4r, T3R, T42;
    E T3Z, T4p, T46, T4l, T4T, T5j, T50, T5f, T4G, T5l, T4L, T4W;
    {
        E T1, T2, T1l, T1m;
        T1 = rio[0];
        T2 = rio[(rs[3])];
        T3 = T1 + T2;
        Tc = T1 - T2;
        {
            E Tr, Ts, TV, TW;
            Tr = iio[0];
            Ts = iio[(rs[3])];
            Tt = Tr - Ts;
            TM = Tr + Ts;
            TV = rio[(vs[1])];
            TW = rio[(vs[1]) + (rs[3])];
            TX = TV + TW;
            T16 = TV - TW;
        }
        T1l = iio[(vs[1])];
        T1m = iio[(vs[1]) + (rs[3])];
        T1n = T1l - T1m;
        T1G = T1l + T1m;
        {
            E T2f, T2g, T1P, T1Q;
            T2f = iio[(vs[2])];
            T2g = iio[(vs[2]) + (rs[3])];
            T2h = T2f - T2g;
            T2A = T2f + T2g;
            T1P = rio[(vs[2])];
            T1Q = rio[(vs[2]) + (rs[3])];
            T1R = T1P + T1Q;
            T20 = T1P - T1Q;
        }
    }
    {
        E T2J, T2K, T43, T44;
        T2J = rio[(vs[3])];
        T2K = rio[(vs[3]) + (rs[3])];
        T2L = T2J + T2K;
        T2U = T2J - T2K;
        {
            E T39, T3a, T3D, T3E;
            T39 = iio[(vs[3])];
            T3a = iio[(vs[3]) + (rs[3])];
            T3b = T39 - T3a;
            T3u = T39 + T3a;
            T3D = rio[(vs[4])];
            T3E = rio[(vs[4]) + (rs[3])];
            T3F = T3D + T3E;
            T3O = T3D - T3E;
        }
        T43 = iio[(vs[4])];
        T44 = iio[(vs[4]) + (rs[3])];
        T45 = T43 - T44;
        T4o = T43 + T44;
        {
            E T4X, T4Y, T4x, T4y;
            T4X = iio[(vs[5])];
            T4Y = iio[(vs[5]) + (rs[3])];
            T4Z = T4X - T4Y;
            T5i = T4X + T4Y;
            T4x = rio[(vs[5])];
            T4y = rio[(vs[5]) + (rs[3])];
            T4z = T4x + T4y;
            T4I = T4x - T4y;
        }
    }
    {
        E T6, Td, T9, Te;
        {
            E T4, T5, T7, T8;
            T4 = rio[(rs[2])];
            T5 = rio[(rs[5])];
            T6 = T4 + T5;
            Td = T4 - T5;
            T7 = rio[(rs[4])];
            T8 = rio[(rs[1])];
            T9 = T7 + T8;
            Te = T7 - T8;
        }
        Ta = T6 + T9;
        TP = KP866025403 * (T9 - T6);
        Tf = Td + Te;
        Tq = KP866025403 * (Te - Td);
    }
    {
        E Tj, TH, Tm, TI;
        {
            E Th, Ti, Tk, Tl;
            Th = iio[(rs[2])];
            Ti = iio[(rs[5])];
            Tj = Th - Ti;
            TH = Th + Ti;
            Tk = iio[(rs[4])];
            Tl = iio[(rs[1])];
            Tm = Tk - Tl;
            TI = Tk + Tl;
        }
        Tn = KP866025403 * (Tj - Tm);
        TN = TH + TI;
        Tu = Tj + Tm;
        TJ = KP866025403 * (TH - TI);
    }
    {
        E T10, T17, T13, T18;
        {
            E TY, TZ, T11, T12;
            TY = rio[(vs[1]) + (rs[2])];
            TZ = rio[(vs[1]) + (rs[5])];
            T10 = TY + TZ;
            T17 = TY - TZ;
            T11 = rio[(vs[1]) + (rs[4])];
            T12 = rio[(vs[1]) + (rs[1])];
            T13 = T11 + T12;
            T18 = T11 - T12;
        }
        T14 = T10 + T13;
        T1J = KP866025403 * (T13 - T10);
        T19 = T17 + T18;
        T1k = KP866025403 * (T18 - T17);
    }
    {
        E T1d, T1B, T1g, T1C;
        {
            E T1b, T1c, T1e, T1f;
            T1b = iio[(vs[1]) + (rs[2])];
            T1c = iio[(vs[1]) + (rs[5])];
            T1d = T1b - T1c;
            T1B = T1b + T1c;
            T1e = iio[(vs[1]) + (rs[4])];
            T1f = iio[(vs[1]) + (rs[1])];
            T1g = T1e - T1f;
            T1C = T1e + T1f;
        }
        T1h = KP866025403 * (T1d - T1g);
        T1H = T1B + T1C;
        T1o = T1d + T1g;
        T1D = KP866025403 * (T1B - T1C);
    }
    {
        E T27, T2v, T2a, T2w;
        {
            E T25, T26, T28, T29;
            T25 = iio[(vs[2]) + (rs[2])];
            T26 = iio[(vs[2]) + (rs[5])];
            T27 = T25 - T26;
            T2v = T25 + T26;
            T28 = iio[(vs[2]) + (rs[4])];
            T29 = iio[(vs[2]) + (rs[1])];
            T2a = T28 - T29;
            T2w = T28 + T29;
        }
        T2b = KP866025403 * (T27 - T2a);
        T2B = T2v + T2w;
        T2i = T27 + T2a;
        T2x = KP866025403 * (T2v - T2w);
    }
    {
        E T1U, T21, T1X, T22;
        {
            E T1S, T1T, T1V, T1W;
            T1S = rio[(vs[2]) + (rs[2])];
            T1T = rio[(vs[2]) + (rs[5])];
            T1U = T1S + T1T;
            T21 = T1S - T1T;
            T1V = rio[(vs[2]) + (rs[4])];
            T1W = rio[(vs[2]) + (rs[1])];
            T1X = T1V + T1W;
            T22 = T1V - T1W;
        }
        T1Y = T1U + T1X;
        T2D = KP866025403 * (T1X - T1U);
        T23 = T21 + T22;
        T2e = KP866025403 * (T22 - T21);
    }
    {
        E T2O, T2V, T2R, T2W;
        {
            E T2M, T2N, T2P, T2Q;
            T2M = rio[(vs[3]) + (rs[2])];
            T2N = rio[(vs[3]) + (rs[5])];
            T2O = T2M + T2N;
            T2V = T2M - T2N;
            T2P = rio[(vs[3]) + (rs[4])];
            T2Q = rio[(vs[3]) + (rs[1])];
            T2R = T2P + T2Q;
            T2W = T2P - T2Q;
        }
        T2S = T2O + T2R;
        T3x = KP866025403 * (T2R - T2O);
        T2X = T2V + T2W;
        T38 = KP866025403 * (T2W - T2V);
    }
    {
        E T31, T3p, T34, T3q;
        {
            E T2Z, T30, T32, T33;
            T2Z = iio[(vs[3]) + (rs[2])];
            T30 = iio[(vs[3]) + (rs[5])];
            T31 = T2Z - T30;
            T3p = T2Z + T30;
            T32 = iio[(vs[3]) + (rs[4])];
            T33 = iio[(vs[3]) + (rs[1])];
            T34 = T32 - T33;
            T3q = T32 + T33;
        }
        T35 = KP866025403 * (T31 - T34);
        T3v = T3p + T3q;
        T3c = T31 + T34;
        T3r = KP866025403 * (T3p - T3q);
    }
    {
        E T3I, T3P, T3L, T3Q;
        {
            E T3G, T3H, T3J, T3K;
            T3G = rio[(vs[4]) + (rs[2])];
            T3H = rio[(vs[4]) + (rs[5])];
            T3I = T3G + T3H;
            T3P = T3G - T3H;
            T3J = rio[(vs[4]) + (rs[4])];
            T3K = rio[(vs[4]) + (rs[1])];
            T3L = T3J + T3K;
            T3Q = T3J - T3K;
        }
        T3M = T3I + T3L;
        T4r = KP866025403 * (T3L - T3I);
        T3R = T3P + T3Q;
        T42 = KP866025403 * (T3Q - T3P);
    }
    {
        E T3V, T4j, T3Y, T4k;
        {
            E T3T, T3U, T3W, T3X;
            T3T = iio[(vs[4]) + (rs[2])];
            T3U = iio[(vs[4]) + (rs[5])];
            T3V = T3T - T3U;
            T4j = T3T + T3U;
            T3W = iio[(vs[4]) + (rs[4])];
            T3X = iio[(vs[4]) + (rs[1])];
            T3Y = T3W - T3X;
            T4k = T3W + T3X;
        }
        T3Z = KP866025403 * (T3V - T3Y);
        T4p = T4j + T4k;
        T46 = T3V + T3Y;
        T4l = KP866025403 * (T4j - T4k);
    }
    {
        E T4P, T5d, T4S, T5e;
        {
            E T4N, T4O, T4Q, T4R;
            T4N = iio[(vs[5]) + (rs[2])];
            T4O = iio[(vs[5]) + (rs[5])];
            T4P = T4N - T4O;
            T5d = T4N + T4O;
            T4Q = iio[(vs[5]) + (rs[4])];
            T4R = iio[(vs[5]) + (rs[1])];
            T4S = T4Q - T4R;
            T5e = T4Q + T4R;
        }
        T4T = KP866025403 * (T4P - T4S);
        T5j = T5d + T5e;
        T50 = T4P + T4S;
        T5f = KP866025403 * (T5d - T5e);
    }
    {
        E T4C, T4J, T4F, T4K;
        {
            E T4A, T4B, T4D, T4E;
            T4A = rio[(vs[5]) + (rs[2])];
            T4B = rio[(vs[5]) + (rs[5])];
            T4C = T4A + T4B;
            T4J = T4A - T4B;
            T4D = rio[(vs[5]) + (rs[4])];
            T4E = rio[(vs[5]) + (rs[1])];
            T4F = T4D + T4E;
            T4K = T4D - T4E;
        }
        T4G = T4C + T4F;
        T5l = KP866025403 * (T4F - T4C);
        T4L = T4J + T4K;
        T4W = KP866025403 * (T4K - T4J);
    }
    rio[0] = T3 + Ta;
    iio[0] = TM + TN;
    rio[(rs[1])] = TX + T14;
    iio[(rs[1])] = T1G + T1H;
    rio[(rs[3])] = T2L + T2S;
    rio[(rs[2])] = T1R + T1Y;
    iio[(rs[2])] = T2A + T2B;
    iio[(rs[3])] = T3u + T3v;
    iio[(rs[4])] = T4o + T4p;
    iio[(rs[5])] = T5i + T5j;
    rio[(rs[5])] = T4z + T4G;
    rio[(rs[4])] = T3F + T3M;
    {
        E T1w, T1y, T1v, T1x;
        T1w = T16 + T19;
        T1y = T1n + T1o;
        T1v = W[4];
        T1x = W[5];
        rio[(vs[3]) + (rs[1])] = (((T1v) * (T1w)) + (T1x * T1y));
        iio[(vs[3]) + (rs[1])] = ((T1v * T1y) - ((T1x) * (T1w)));
    }
    {
        E T58, T5a, T57, T59;
        T58 = T4I + T4L;
        T5a = T4Z + T50;
        T57 = W[4];
        T59 = W[5];
        rio[(vs[3]) + (rs[5])] = (((T57) * (T58)) + (T59 * T5a));
        iio[(vs[3]) + (rs[5])] = ((T57 * T5a) - ((T59) * (T58)));
    }
    {
        E TC, TE, TB, TD;
        TC = Tc + Tf;
        TE = Tt + Tu;
        TB = W[4];
        TD = W[5];
        rio[(vs[3])] = (((TB) * (TC)) + (TD * TE));
        iio[(vs[3])] = ((TB * TE) - ((TD) * (TC)));
    }
    {
        E T4e, T4g, T4d, T4f;
        T4e = T3O + T3R;
        T4g = T45 + T46;
        T4d = W[4];
        T4f = W[5];
        rio[(vs[3]) + (rs[4])] = (((T4d) * (T4e)) + (T4f * T4g));
        iio[(vs[3]) + (rs[4])] = ((T4d * T4g) - ((T4f) * (T4e)));
    }
    {
        E T3k, T3m, T3j, T3l;
        T3k = T2U + T2X;
        T3m = T3b + T3c;
        T3j = W[4];
        T3l = W[5];
        rio[(vs[3]) + (rs[3])] = (((T3j) * (T3k)) + (T3l * T3m));
        iio[(vs[3]) + (rs[3])] = ((T3j * T3m) - ((T3l) * (T3k)));
    }
    {
        E T2q, T2s, T2p, T2r;
        T2q = T20 + T23;
        T2s = T2h + T2i;
        T2p = W[4];
        T2r = W[5];
        rio[(vs[3]) + (rs[2])] = (((T2p) * (T2q)) + (T2r * T2s));
        iio[(vs[3]) + (rs[2])] = ((T2p * T2s) - ((T2r) * (T2q)));
    }
    {
        E T5g, T5o, T5m, T5q, T5c, T5k;
        T5c = ((T4z) - ((KP500000000) * (T4G)));
        T5g = T5c - T5f;
        T5o = T5c + T5f;
        T5k = ((T5i) - ((KP500000000) * (T5j)));
        T5m = T5k - T5l;
        T5q = T5l + T5k;
        {
            E T5b, T5h, T5n, T5p;
            T5b = W[2];
            T5h = W[3];
            rio[(vs[2]) + (rs[5])] = (((T5b) * (T5g)) + (T5h * T5m));
            iio[(vs[2]) + (rs[5])] = ((T5b * T5m) - ((T5h) * (T5g)));
            T5n = W[6];
            T5p = W[7];
            rio[(vs[4]) + (rs[5])] = (((T5n) * (T5o)) + (T5p * T5q));
            iio[(vs[4]) + (rs[5])] = ((T5n * T5q) - ((T5p) * (T5o)));
        }
    }
    {
        E To, Ty, Tw, TA, Tg, Tv;
        Tg = ((Tc) - ((KP500000000) * (Tf)));
        To = Tg + Tn;
        Ty = Tg - Tn;
        Tv = ((Tt) - ((KP500000000) * (Tu)));
        Tw = Tq + Tv;
        TA = Tv - Tq;
        {
            E Tb, Tp, Tx, Tz;
            Tb = W[0];
            Tp = W[1];
            rio[(vs[1])] = (((Tb) * (To)) + (Tp * Tw));
            iio[(vs[1])] = ((Tb * Tw) - ((Tp) * (To)));
            Tx = W[8];
            Tz = W[9];
            rio[(vs[5])] = (((Tx) * (Ty)) + (Tz * TA));
            iio[(vs[5])] = ((Tx * TA) - ((Tz) * (Ty)));
        }
    }
    {
        E T36, T3g, T3e, T3i, T2Y, T3d;
        T2Y = ((T2U) - ((KP500000000) * (T2X)));
        T36 = T2Y + T35;
        T3g = T2Y - T35;
        T3d = ((T3b) - ((KP500000000) * (T3c)));
        T3e = T38 + T3d;
        T3i = T3d - T38;
        {
            E T2T, T37, T3f, T3h;
            T2T = W[0];
            T37 = W[1];
            rio[(vs[1]) + (rs[3])] = (((T2T) * (T36)) + (T37 * T3e));
            iio[(vs[1]) + (rs[3])] = ((T2T * T3e) - ((T37) * (T36)));
            T3f = W[8];
            T3h = W[9];
            rio[(vs[5]) + (rs[3])] = (((T3f) * (T3g)) + (T3h * T3i));
            iio[(vs[5]) + (rs[3])] = ((T3f * T3i) - ((T3h) * (T3g)));
        }
    }
    {
        E T2y, T2G, T2E, T2I, T2u, T2C;
        T2u = ((T1R) - ((KP500000000) * (T1Y)));
        T2y = T2u - T2x;
        T2G = T2u + T2x;
        T2C = ((T2A) - ((KP500000000) * (T2B)));
        T2E = T2C - T2D;
        T2I = T2D + T2C;
        {
            E T2t, T2z, T2F, T2H;
            T2t = W[2];
            T2z = W[3];
            rio[(vs[2]) + (rs[2])] = (((T2t) * (T2y)) + (T2z * T2E));
            iio[(vs[2]) + (rs[2])] = ((T2t * T2E) - ((T2z) * (T2y)));
            T2F = W[6];
            T2H = W[7];
            rio[(vs[4]) + (rs[2])] = (((T2F) * (T2G)) + (T2H * T2I));
            iio[(vs[4]) + (rs[2])] = ((T2F * T2I) - ((T2H) * (T2G)));
        }
    }
    {
        E T3s, T3A, T3y, T3C, T3o, T3w;
        T3o = ((T2L) - ((KP500000000) * (T2S)));
        T3s = T3o - T3r;
        T3A = T3o + T3r;
        T3w = ((T3u) - ((KP500000000) * (T3v)));
        T3y = T3w - T3x;
        T3C = T3x + T3w;
        {
            E T3n, T3t, T3z, T3B;
            T3n = W[2];
            T3t = W[3];
            rio[(vs[2]) + (rs[3])] = (((T3n) * (T3s)) + (T3t * T3y));
            iio[(vs[2]) + (rs[3])] = ((T3n * T3y) - ((T3t) * (T3s)));
            T3z = W[6];
            T3B = W[7];
            rio[(vs[4]) + (rs[3])] = (((T3z) * (T3A)) + (T3B * T3C));
            iio[(vs[4]) + (rs[3])] = ((T3z * T3C) - ((T3B) * (T3A)));
        }
    }
    {
        E T1E, T1M, T1K, T1O, T1A, T1I;
        T1A = ((TX) - ((KP500000000) * (T14)));
        T1E = T1A - T1D;
        T1M = T1A + T1D;
        T1I = ((T1G) - ((KP500000000) * (T1H)));
        T1K = T1I - T1J;
        T1O = T1J + T1I;
        {
            E T1z, T1F, T1L, T1N;
            T1z = W[2];
            T1F = W[3];
            rio[(vs[2]) + (rs[1])] = (((T1z) * (T1E)) + (T1F * T1K));
            iio[(vs[2]) + (rs[1])] = ((T1z * T1K) - ((T1F) * (T1E)));
            T1L = W[6];
            T1N = W[7];
            rio[(vs[4]) + (rs[1])] = (((T1L) * (T1M)) + (T1N * T1O));
            iio[(vs[4]) + (rs[1])] = ((T1L * T1O) - ((T1N) * (T1M)));
        }
    }
    {
        E T4m, T4u, T4s, T4w, T4i, T4q;
        T4i = ((T3F) - ((KP500000000) * (T3M)));
        T4m = T4i - T4l;
        T4u = T4i + T4l;
        T4q = ((T4o) - ((KP500000000) * (T4p)));
        T4s = T4q - T4r;
        T4w = T4r + T4q;
        {
            E T4h, T4n, T4t, T4v;
            T4h = W[2];
            T4n = W[3];
            rio[(vs[2]) + (rs[4])] = (((T4h) * (T4m)) + (T4n * T4s));
            iio[(vs[2]) + (rs[4])] = ((T4h * T4s) - ((T4n) * (T4m)));
            T4t = W[6];
            T4v = W[7];
            rio[(vs[4]) + (rs[4])] = (((T4t) * (T4u)) + (T4v * T4w));
            iio[(vs[4]) + (rs[4])] = ((T4t * T4w) - ((T4v) * (T4u)));
        }
    }
    {
        E TK, TS, TQ, TU, TG, TO;
        TG = ((T3) - ((KP500000000) * (Ta)));
        TK = TG - TJ;
        TS = TG + TJ;
        TO = ((TM) - ((KP500000000) * (TN)));
        TQ = TO - TP;
        TU = TP + TO;
        {
            E TF, TL, TR, TT;
            TF = W[2];
            TL = W[3];
            rio[(vs[2])] = (((TF) * (TK)) + (TL * TQ));
            iio[(vs[2])] = ((TF * TQ) - ((TL) * (TK)));
            TR = W[6];
            TT = W[7];
            rio[(vs[4])] = (((TR) * (TS)) + (TT * TU));
            iio[(vs[4])] = ((TR * TU) - ((TT) * (TS)));
        }
    }
    {
        E T2c, T2m, T2k, T2o, T24, T2j;
        T24 = ((T20) - ((KP500000000) * (T23)));
        T2c = T24 + T2b;
        T2m = T24 - T2b;
        T2j = ((T2h) - ((KP500000000) * (T2i)));
        T2k = T2e + T2j;
        T2o = T2j - T2e;
        {
            E T1Z, T2d, T2l, T2n;
            T1Z = W[0];
            T2d = W[1];
            rio[(vs[1]) + (rs[2])] = (((T1Z) * (T2c)) + (T2d * T2k));
            iio[(vs[1]) + (rs[2])] = ((T1Z * T2k) - ((T2d) * (T2c)));
            T2l = W[8];
            T2n = W[9];
            rio[(vs[5]) + (rs[2])] = (((T2l) * (T2m)) + (T2n * T2o));
            iio[(vs[5]) + (rs[2])] = ((T2l * T2o) - ((T2n) * (T2m)));
        }
    }
    {
        E T40, T4a, T48, T4c, T3S, T47;
        T3S = ((T3O) - ((KP500000000) * (T3R)));
        T40 = T3S + T3Z;
        T4a = T3S - T3Z;
        T47 = ((T45) - ((KP500000000) * (T46)));
        T48 = T42 + T47;
        T4c = T47 - T42;
        {
            E T3N, T41, T49, T4b;
            T3N = W[0];
            T41 = W[1];
            rio[(vs[1]) + (rs[4])] = (((T3N) * (T40)) + (T41 * T48));
            iio[(vs[1]) + (rs[4])] = ((T3N * T48) - ((T41) * (T40)));
            T49 = W[8];
            T4b = W[9];
            rio[(vs[5]) + (rs[4])] = (((T49) * (T4a)) + (T4b * T4c));
            iio[(vs[5]) + (rs[4])] = ((T49 * T4c) - ((T4b) * (T4a)));
        }
    }
    {
        E T1i, T1s, T1q, T1u, T1a, T1p;
        T1a = ((T16) - ((KP500000000) * (T19)));
        T1i = T1a + T1h;
        T1s = T1a - T1h;
        T1p = ((T1n) - ((KP500000000) * (T1o)));
        T1q = T1k + T1p;
        T1u = T1p - T1k;
        {
            E T15, T1j, T1r, T1t;
            T15 = W[0];
            T1j = W[1];
            rio[(vs[1]) + (rs[1])] = (((T15) * (T1i)) + (T1j * T1q));
            iio[(vs[1]) + (rs[1])] = ((T15 * T1q) - ((T1j) * (T1i)));
            T1r = W[8];
            T1t = W[9];
            rio[(vs[5]) + (rs[1])] = (((T1r) * (T1s)) + (T1t * T1u));
            iio[(vs[5]) + (rs[1])] = ((T1r * T1u) - ((T1t) * (T1s)));
        }
    }
    {
        E T4U, T54, T52, T56, T4M, T51;
        T4M = ((T4I) - ((KP500000000) * (T4L)));
        T4U = T4M + T4T;
        T54 = T4M - T4T;
        T51 = ((T4Z) - ((KP500000000) * (T50)));
        T52 = T4W + T51;
        T56 = T51 - T4W;
        {
            E T4H, T4V, T53, T55;
            T4H = W[0];
            T4V = W[1];
            rio[(vs[1]) + (rs[5])] = (((T4H) * (T4U)) + (T4V * T52));
            iio[(vs[1]) + (rs[5])] = ((T4H * T52) - ((T4V) * (T4U)));
            T53 = W[8];
            T55 = W[9];
            rio[(vs[5]) + (rs[5])] = (((T53) * (T54)) + (T55 * T56));
            iio[(vs[5]) + (rs[5])] = ((T53 * T56) - ((T55) * (T54)));
        }
    }
}

}
