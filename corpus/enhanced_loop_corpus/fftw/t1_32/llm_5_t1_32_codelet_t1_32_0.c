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
extern  E KP195090322;
extern  E KP980785280;
extern  E KP555570233;
extern  E KP831469612;
extern  E KP382683432;
extern  E KP923879532;
extern  E KP707106781;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Increase computational intensity by unrolling inner structure into a larger trip count
INT step = 2;
for (m = mb , W = W + (mb * 62); m < me; m = m + step , ri = ri + (ms * step), ii = ii + (ms * step), W = W + (62 * step), (rs) = (rs) + (fftw_an_INT_guaranteed_to_be_zero * step)) {

    // Process two iterations per loop: m and m+1
    for (INT iter = 0; iter < step && (m + iter) < me; iter++) {
        R *local_ri = ri + (iter * ms);
        R *local_ii = ii + (iter * ms);
        R *local_W = W + (iter * 62);

        E Tj, T5F, T7C, T7Q, T35, T4T, T78, T7m, T1Q, T61, T5Y, T6J, T3K, T59, T41;
        E T56, T2B, T67, T6e, T6O, T4b, T5d, T4s, T5g, TG, T7l, T5I, T73, T3a, T4U;
        E T3f, T4V, T14, T5N, T5M, T6E, T3m, T4Y, T3r, T4Z, T1r, T5P, T5S, T6F, T3x;
        E T51, T3C, T52, T2d, T5Z, T64, T6K, T3V, T57, T44, T5a, T2Y, T6f, T6a, T6P;
        E T4m, T5h, T4v, T5e;

        {
            E T1, T76, T6, T75, Tc, T32, Th, T33;
            T1 = local_ri[0];
            T76 = local_ii[0];
            {
                E T3, T5, T2, T4;
                T3 = local_ri[(rs[16])];
                T5 = local_ii[(rs[16])];
                T2 = local_W[30];
                T4 = local_W[31];
                T6 = (((T2) * (T3)) + (T4 * T5));
                T75 = ((T2 * T5) - ((T4) * (T3)));
            }
            {
                E T9, Tb, T8, Ta;
                T9 = local_ri[(rs[8])];
                Tb = local_ii[(rs[8])];
                T8 = local_W[14];
                Ta = local_W[15];
                Tc = (((T8) * (T9)) + (Ta * Tb));
                T32 = ((T8 * Tb) - ((Ta) * (T9)));
            }
            {
                E Te, Tg, Td, Tf;
                Te = local_ri[(rs[24])];
                Tg = local_ii[(rs[24])];
                Td = local_W[46];
                Tf = local_W[47];
                Th = (((Td) * (Te)) + (Tf * Tg));
                T33 = ((Td * Tg) - ((Tf) * (Te)));
            }
            {
                E T7, Ti, T7A, T7B;
                T7 = T1 + T6;
                Ti = Tc + Th;
                Tj = T7 + Ti;
                T5F = T7 - Ti;
                T7A = T76 - T75;
                T7B = Tc - Th;
                T7C = T7A - T7B;
                T7Q = T7B + T7A;
            }
            {
                E T31, T34, T74, T77;
                T31 = T1 - T6;
                T34 = T32 - T33;
                T35 = T31 - T34;
                T4T = T31 + T34;
                T74 = T32 + T33;
                T77 = T75 + T76;
                T78 = T74 + T77;
                T7m = T77 - T74;
            }
        }

        {
            E T1y, T3G, T1O, T3Z, T1D, T3H, T1J, T3Y;
            {
                E T1v, T1x, T1u, T1w;
                T1v = local_ri[(rs[1])];
                T1x = local_ii[(rs[1])];
                T1u = local_W[0];
                T1w = local_W[1];
                T1y = (((T1u) * (T1v)) + (T1w * T1x));
                T3G = ((T1u * T1x) - ((T1w) * (T1v)));
            }
            {
                E T1L, T1N, T1K, T1M;
                T1L = local_ri[(rs[25])];
                T1N = local_ii[(rs[25])];
                T1K = local_W[48];
                T1M = local_W[49];
                T1O = (((T1K) * (T1L)) + (T1M * T1N));
                T3Z = ((T1K * T1N) - ((T1M) * (T1L)));
            }
            {
                E T1A, T1C, T1z, T1B;
                T1A = local_ri[(rs[17])];
                T1C = local_ii[(rs[17])];
                T1z = local_W[32];
                T1B = local_W[33];
                T1D = (((T1z) * (T1A)) + (T1B * T1C));
                T3H = ((T1z * T1C) - ((T1B) * (T1A)));
            }
            {
                E T1G, T1I, T1F, T1H;
                T1G = local_ri[(rs[9])];
                T1I = local_ii[(rs[9])];
                T1F = local_W[16];
                T1H = local_W[17];
                T1J = (((T1F) * (T1G)) + (T1H * T1I));
                T3Y = ((T1F * T1I) - ((T1H) * (T1G)));
            }
            {
                E T1E, T1P, T5W, T5X;
                T1E = T1y + T1D;
                T1P = T1J + T1O;
                T1Q = T1E + T1P;
                T61 = T1E - T1P;
                T5W = T3G + T3H;
                T5X = T3Y + T3Z;
                T5Y = T5W - T5X;
                T6J = T5W + T5X;
            }
            {
                E T3I, T3J, T3X, T40;
                T3I = T3G - T3H;
                T3J = T1J - T1O;
                T3K = T3I + T3J;
                T59 = T3I - T3J;
                T3X = T1y - T1D;
                T40 = T3Y - T3Z;
                T41 = T3X - T40;
                T56 = T3X + T40;
            }
        }

        {
            E To, T36, TE, T3d, Tt, T37, Tz, T3c;
            {
                E Tl, Tn, Tk, Tm;
                Tl = local_ri[(rs[4])];
                Tn = local_ii[(rs[4])];
                Tk = local_W[6];
                Tm = local_W[7];
                To = (((Tk) * (Tl)) + (Tm * Tn));
                T36 = ((Tk * Tn) - ((Tm) * (Tl)));
            }
            {
                E TB, TD, TA, TC;
                TB = local_ri[(rs[12])];
                TD = local_ii[(rs[12])];
                TA = local_W[22];
                TC = local_W[23];
                TE = (((TA) * (TB)) + (TC * TD));
                T3d = ((TA * TD) - ((TC) * (TB)));
            }
            {
                E Tq, Ts, Tp, Tr;
                Tq = local_ri[(rs[20])];
                Ts = local_ii[(rs[20])];
                Tp = local_W[38];
                Tr = local_W[39];
                Tt = (((Tp) * (Tq)) + (Tr * Ts));
                T37 = ((Tp * Ts) - ((Tr) * (Tq)));
            }
            {
                E Tw, Ty, Tv, Tx;
                Tw = local_ri[(rs[28])];
                Ty = local_ii[(rs[28])];
                Tv = local_W[54];
                Tx = local_W[55];
                Tz = (((Tv) * (Tw)) + (Tx * Ty));
                T3c = ((Tv * Ty) - ((Tx) * (Tw)));
            }
            {
                E Tu, TF, T5G, T5H;
                Tu = To + Tt;
                TF = Tz + TE;
                TG = Tu + TF;
                T7l = TF - Tu;
                T5G = T36 + T37;
                T5H = T3c + T3d;
                T5I = T5G - T5H;
                T73 = T5G + T5H;
            }
            {
                E T38, T39, T3b, T3e;
                T38 = T36 - T37;
                T39 = To - Tt;
                T3a = T38 - T39;
                T4U = T39 + T38;
                T3b = Tz - TE;
                T3e = T3c - T3d;
                T3f = T3b + T3e;
                T4V = T3b - T3e;
            }
        }

        {
            E T19, T3t, T1p, T3A, T1e, T3u, T1k, T3z;
            {
                E T16, T18, T15, T17;
                T16 = local_ri[(rs[30])];
                T18 = local_ii[(rs[30])];
                T15 = local_W[58];
                T17 = local_W[59];
                T19 = (((T15) * (T16)) + (T17 * T18));
                T3t = ((T15 * T18) - ((T17) * (T16)));
            }
            {
                E T1m, T1o, T1l, T1n;
                T1m = local_ri[(rs[22])];
                T1o = local_ii[(rs[22])];
                T1l = local_W[42];
                T1n = local_W[43];
                T1p = (((T1l) * (T1m)) + (T1n * T1o));
                T3A = ((T1l * T1o) - ((T1n) * (T1m)));
            }
            {
                E T1b, T1d, T1a, T1c;
                T1b = local_ri[(rs[14])];
                T1d = local_ii[(rs[14])];
                T1a = local_W[26];
                T1c = local_W[27];
                T1e = (((T1a) * (T1b)) + (T1c * T1d));
                T3u = ((T1a * T1d) - ((T1c) * (T1b)));
            }
            {
                E T1h, T1j, T1g, T1i;
                T1h = local_ri[(rs[6])];
                T1j = local_ii[(rs[6])];
                T1g = local_W[10];
                T1i = local_W[11];
                T1k = (((T1g) * (T1h)) + (T1i * T1j));
                T3z = ((T1g * T1j) - ((T1i) * (T1h)));
            }
            {
                E T1f, T1q, T5Q, T5R;
                T1f = T19 + T1e;
                T1q = T1k + T1p;
                T1r = T1f + T1q;
                T5P = T1f - T1q;
                T5Q = T3t + T3u;
                T5R = T3z + T3A;
                T5S = T5Q - T5R;
                T6F = T5Q + T5R;
            }
            {
                E T3v, T3w, T3y, T3B;
                T3v = T3t - T3u;
                T3w = T1k - T1p;
                T3x = T3v + T3w;
                T51 = T3v - T3w;
                T3y = T19 - T1e;
                T3B = T3z - T3A;
                T3C = T3y - T3B;
                T52 = T3y + T3B;
            }
        }

        {
            E T1V, T3R, T20, T3S, T3Q, T3T, T26, T3M, T2b, T3N, T3L, T3O;
            {
                E T1S, T1U, T1R, T1T;
                T1S = local_ri[(rs[5])];
                T1U = local_ii[(rs[5])];
                T1R = local_W[8];
                T1T = local_W[9];
                T1V = (((T1R) * (T1S)) + (T1T * T1U));
                T3R = ((T1R * T1U) - ((T1T) * (T1S)));
            }
            {
                E T1X, T1Z, T1W, T1Y;
                T1X = local_ri[(rs[21])];
                T1Z = local_ii[(rs[21])];
                T1W = local_W[40];
                T1Y = local_W[41];
                T20 = (((T1W) * (T1X)) + (T1Y * T1Z));
                T3S = ((T1W * T1Z) - ((T1Y) * (T1X)));
            }
            T3Q = T1V - T20;
            T3T = T3R - T3S;
            {
                E T23, T25, T22, T24;
                T23 = local_ri[(rs[29])];
                T25 = local_ii[(rs[29])];
                T22 = local_W[56];
                T24 = local_W[57];
                T26 = (((T22) * (T23)) + (T24 * T25));
                T3M = ((T22 * T25) - ((T24) * (T23)));
            }
            {
                E T28, T2a, T27, T29;
                T28 = local_ri[(rs[13])];
                T2a = local_ii[(rs[13])];
                T27 = local_W[24];
                T29 = local_W[25];
                T2b = (((T27) * (T28)) + (T29 * T2a));
                T3N = ((T27 * T2a) - ((T29) * (T28)));
            }
            T3L = T26 - T2b;
            T3O = T3M - T3N;
            {
                E T21, T2c, T62, T63;
                T21 = T1V + T20;
                T2c = T26 + T2b;
                T2d = T21 + T2c;
                T5Z = T2c - T21;
                T62 = T3R + T3S;
                T63 = T3M + T3N;
                T64 = T62 - T63;
                T6K = T62 + T63;
            }
            {
                E T3P, T3U, T42, T43;
                T3P = T3L - T3O;
                T3U = T3Q + T3T;
                T3V = KP707106781 * (T3P - T3U);
                T57 = KP707106781 * (T3U + T3P);
                T42 = T3T - T3Q;
                T43 = T3L + T3O;
                T44 = KP707106781 * (T42 - T43);
                T5a = KP707106781 * (T42 + T43);
            }
        }

        {
            E T2G, T4c, T2L, T4d, T4e, T4f, T2R, T4i, T2W, T4j, T4h, T4k;
            {
                E T2D, T2F, T2C, T2E;
                T2D = local_ri[(rs[3])];
                T2F = local_ii[(rs[3])];
                T2C = local_W[4];
                T2E = local_W[5];
                T2G = (((T2C) * (T2D)) + (T2E * T2F));
                T4c = ((T2C * T2F) - ((T2E) * (T2D)));
            }
            {
                E T2I, T2K, T2H, T2J;
                T2I = local_ri[(rs[19])];
                T2K = local_ii[(rs[19])];
                T2H = local_W[36];
                T2J = local_W[37];
                T2L = (((T2H) * (T2I)) + (T2J * T2K));
                T4d = ((T2H * T2K) - ((T2J) * (T2I)));
            }
            T4e = T4c - T4d;
            T4f = T2G - T2L;
            {
                E T2O, T2Q, T2N, T2P;
                T2O = local_ri[(rs[27])];
                T2Q = local_ii[(rs[27])];
                T2N = local_W[52];
                T2P = local_W[53];
                T2R = (((T2N) * (T2O)) + (T2P * T2Q));
                T4i = ((T2N * T2Q) - ((T2P) * (T2O)));
            }
            {
                E T2T, T2V, T2S, T2U;
                T2T = local_ri[(rs[11])];
                T2V = local_ii[(rs[11])];
                T2S = local_W[20];
                T2U = local_W[21];
                T2W = (((T2S) * (T2T)) + (T2U * T2V));
                T4j = ((T2S * T2V) - ((T2U) * (T2T)));
            }
            T4h = T2R - T2W;
            T4k = T4i - T4j;
            {
                E T2M, T2X, T68, T69;
                T2M = T2G + T2L;
                T2X = T2R + T2W;
                T2Y = T2M + T2X;
                T6f = T2X - T2M;
                T68 = T4c + T4d;
                T69 = T4i + T4j;
                T6a = T68 - T69;
                T6P = T68 + T69;
            }
            {
                E T4g, T4l, T4t, T4u;
                T4g = T4e - T4f;
                T4l = T4h + T4k;
                T4m = KP707106781 * (T4g - T4l);
                T5h = KP707106781 * (T4g + T4l);
                T4t = T4h - T4k;
                T4u = T4f + T4e;
                T4v = KP707106781 * (T4t - T4u);
                T5e = KP707106781 * (T4u + T4t);
            }
        }

        {
            E T1t, T6X, T7a, T7c, T30, T7b, T70, T71;
            {
                E TH, T1s, T72, T79;
                TH = Tj + TG;
                T1s = T14 + T1r;
                T1t = TH + T1s;
                T6X = TH - T1s;
                T72 = T6E + T6F;
                T79 = T73 + T78;
                T7a = T72 + T79;
                T7c = T79 - T72;
            }
            {
                E T2e, T2Z, T6Y, T6Z;
                T2e = T1Q + T2d;
                T2Z = T2B + T2Y;
                T30 = T2e + T2Z;
                T7b = T2Z - T2e;
                T6Y = T6J + T6K;
                T6Z = T6O + T6P;
                T70 = T6Y - T6Z;
                T71 = T6Y + T6Z;
            }
            local_ri[(rs[16])] = T1t - T30;
            local_ii[(rs[16])] = T7a - T71;
            local_ri[0] = T1t + T30;
            local_ii[0] = T71 + T7a;
            local_ri[(rs[24])] = T6X - T70;
            local_ii[(rs[24])] = T7c - T7b;
            local_ri[(rs[8])] = T6X + T70;
            local_ii[(rs[8])] = T7b + T7c;
        }
    }
}
}
