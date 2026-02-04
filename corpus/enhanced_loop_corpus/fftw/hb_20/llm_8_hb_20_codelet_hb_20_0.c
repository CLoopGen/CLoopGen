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
extern  E KP250000000;
extern  E KP559016994;
extern  E KP587785252;
extern  E KP951056516;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 38); m < me; m = m + 2 , cr = cr + (2 * ms) , ci = ci - (2 * ms) , W = W + 76 , (rs) = (rs) + 2 * fftw_an_INT_guaranteed_to_be_zero) {
    if (m + 1 >= me) break;
    E T7, T3T, T49, TE, T1v, T2T, T3g, T2d, T13, T3n, T3o, T1i, T26, T4e, T4d;
    E T23, T1n, T42, T3Z, T1m, T2h, T2I, T2i, T2P, T30, T37, T38, Tm, TB, TC;
    E T46, T47, T4a, T2a, T2b, T2e, T1w, T1x, T1y, T3O, T3R, T3U, T3h, T3i, T3j;
    E TH, TK, TL;
    // First iteration (m)
    {
        E T3, T2R, T1u, T2S, T6, T3f, T1r, T3e;
        {
            E T1, T2, T1s, T1t;
            T1 = cr[0];
            T2 = ci[(rs[9])];
            T3 = T1 + T2;
            T2R = T1 - T2;
            T1s = ci[(rs[14])];
            T1t = cr[(rs[15])];
            T1u = T1s - T1t;
            T2S = T1s + T1t;
        }
        {
            E T4, T5, T1p, T1q;
            T4 = cr[(rs[5])];
            T5 = ci[(rs[4])];
            T6 = T4 + T5;
            T3f = T4 - T5;
            T1p = ci[(rs[19])];
            T1q = cr[(rs[10])];
            T1r = T1p - T1q;
            T3e = T1p + T1q;
        }
        T7 = T3 + T6;
        T3T = T2R - T2S;
        T49 = T3f + T3e;
        TE = T3 - T6;
        T1v = T1r - T1u;
        T2T = T2R + T2S;
        T3g = T3e - T3f;
        T2d = T1r + T1u;
    }
    {
        E Te, T3M, T3X, TF, TV, T2E, T2W, T21, TA, T3Q, T41, TJ, T1h, T2O, T36;
        E T25, Tl, T3N, T3Y, TG, T12, T2H, T2Z, T22, Tt, T3P, T40, TI, T1a, T2L;
        E T33, T24;
        {
            E Ta, T2U, TU, T2V, Td, T2D, TR, T2C;
            {
                E T8, T9, TS, TT;
                T8 = cr[(rs[4])];
                T9 = ci[(rs[5])];
                Ta = T8 + T9;
                T2U = T8 - T9;
                TS = ci[(rs[10])];
                TT = cr[(rs[19])];
                TU = TS - TT;
                T2V = TS + TT;
            }
            {
                E Tb, Tc, TP, TQ;
                Tb = cr[(rs[9])];
                Tc = ci[0];
                Td = Tb + Tc;
                T2D = Tb - Tc;
                TP = ci[(rs[15])];
                TQ = cr[(rs[14])];
                TR = TP - TQ;
                T2C = TP + TQ;
            }
            Te = Ta + Td;
            T3M = T2U - T2V;
            T3X = T2D + T2C;
            TF = Ta - Td;
            TV = TR - TU;
            T2E = T2C - T2D;
            T2W = T2U + T2V;
            T21 = TR + TU;
        }
        {
            E Tw, T34, Tz, T2M, T1d, T2N, T1g, T35;
            {
                E Tu, Tv, Tx, Ty;
                Tu = ci[(rs[7])];
                Tv = cr[(rs[2])];
                Tw = Tu + Tv;
                T34 = Tu - Tv;
                Tx = ci[(rs[2])];
                Ty = cr[(rs[7])];
                Tz = Tx + Ty;
                T2M = Tx - Ty;
            }
            {
                E T1b, T1c, T1e, T1f;
                T1b = ci[(rs[17])];
                T1c = cr[(rs[12])];
                T1d = T1b - T1c;
                T2N = T1b + T1c;
                T1e = ci[(rs[12])];
                T1f = cr[(rs[17])];
                T1g = T1e - T1f;
                T35 = T1e + T1f;
            }
            TA = Tw + Tz;
            T3Q = T34 + T35;
            T41 = T2M - T2N;
            TJ = Tw - Tz;
            T1h = T1d - T1g;
            T2O = T2M + T2N;
            T36 = T34 - T35;
            T25 = T1d + T1g;
        }
        {
            E Th, T2X, T11, T2Y, Tk, T2F, TY, T2G;
            {
                E Tf, Tg, TZ, T10;
                Tf = ci[(rs[3])];
                Tg = cr[(rs[6])];
                Th = Tf + Tg;
                T2X = Tf - Tg;
                TZ = ci[(rs[18])];
                T10 = cr[(rs[11])];
                T11 = TZ - T10;
                T2Y = TZ + T10;
            }
            {
                E Ti, Tj, TW, TX;
                Ti = cr[(rs[1])];
                Tj = ci[(rs[8])];
                Tk = Ti + Tj;
                T2F = Ti - Tj;
                TW = ci[(rs[13])];
                TX = cr[(rs[16])];
                TY = TW - TX;
                T2G = TW + TX;
            }
            Tl = Th + Tk;
            T3N = T2X - T2Y;
            T3Y = T2F - T2G;
            TG = Th - Tk;
            T12 = TY - T11;
            T2H = T2F + T2G;
            T2Z = T2X + T2Y;
            T22 = TY + T11;
        }
        {
            E Tp, T31, T19, T32, Ts, T2K, T16, T2J;
            {
                E Tn, To, T17, T18;
                Tn = cr[(rs[8])];
                To = ci[(rs[1])];
                Tp = Tn + To;
                T31 = Tn - To;
                T17 = ci[(rs[16])];
                T18 = cr[(rs[13])];
                T19 = T17 - T18;
                T32 = T17 + T18;
            }
            {
                E Tq, Tr, T14, T15;
                Tq = ci[(rs[6])];
                Tr = cr[(rs[3])];
                Ts = Tq + Tr;
                T2K = Tq - Tr;
                T14 = ci[(rs[11])];
                T15 = cr[(rs[18])];
                T16 = T14 - T15;
                T2J = T14 + T15;
            }
            Tt = Tp + Ts;
            T3P = T31 + T32;
            T40 = T2K + T2J;
            TI = Tp - Ts;
            T1a = T16 - T19;
            T2L = T2J - T2K;
            T33 = T31 - T32;
            T24 = T16 + T19;
        }
        T13 = TV - T12;
        T3n = T2W - T2Z;
        T3o = T33 - T36;
        T1i = T1a - T1h;
        T26 = T24 - T25;
        T4e = T3P - T3Q;
        T4d = T3M - T3N;
        T23 = T21 - T22;
        T1n = TI - TJ;
        T42 = T40 - T41;
        T3Z = T3X - T3Y;
        T1m = TF - TG;
        T2h = Te - Tl;
        T2I = T2E + T2H;
        T2i = Tt - TA;
        T2P = T2L + T2O;
        T30 = T2W + T2Z;
        T37 = T33 + T36;
        T38 = T30 + T37;
        Tm = Te + Tl;
        TB = Tt + TA;
        TC = Tm + TB;
        T46 = T3X + T3Y;
        T47 = T40 + T41;
        T4a = T46 + T47;
        T2a = T21 + T22;
        T2b = T24 + T25;
        T2e = T2a + T2b;
        T1w = TV + T12;
        T1x = T1a + T1h;
        T1y = T1w + T1x;
        T3O = T3M + T3N;
        T3R = T3P + T3Q;
        T3U = T3O + T3R;
        T3h = T2E - T2H;
        T3i = T2L - T2O;
        T3j = T3h + T3i;
        TH = TF + TG;
        TK = TI + TJ;
        TL = TH + TK;
    }
    cr[0] = T7 + TC;
    ci[0] = T2d + T2e;
    {
        E T1U, T1W, T1T, T1V;
        T1U = TE + TL;
        T1W = T1v + T1y;
        T1T = W[18];
        T1V = W[19];
        cr[(rs[10])] = ((T1T * T1U) - ((T1V) * (T1W)));
        ci[(rs[10])] = (((T1V) * (T1U)) + (T1T * T1W));
    }
    {
        E T4y, T4A, T4x, T4z;
        T4y = T3T + T3U;
        T4A = T49 + T4a;
        T4x = W[8];
        T4z = W[9];
        cr[(rs[5])] = ((T4x * T4y) - ((T4z) * (T4A)));
        ci[(rs[5])] = (((T4x) * (T4A)) + (T4z * T4y));
    }
    {
        E T3I, T3K, T3H, T3J;
        T3I = T2T + T38;
        T3K = T3g + T3j;
        T3H = W[28];
        T3J = W[29];
        cr[(rs[15])] = ((T3H * T3I) - ((T3J) * (T3K)));
        ci[(rs[15])] = (((T3H) * (T3K)) + (T3J * T3I));
    }
    {
        E T27, T2j, T2v, T2r, T2g, T2u, T20, T2q;
        T27 = (((KP951056516) * (T23)) + (KP587785252 * T26));
        T2j = (((KP951056516) * (T2h)) + (KP587785252 * T2i));
        T2v = ((KP587785252 * T2h) - ((KP951056516) * (T2i)));
        T2r = ((KP587785252 * T23) - ((KP951056516) * (T26)));
        {
            E T2c, T2f, T1Y, T1Z;
            T2c = KP559016994 * (T2a - T2b);
            T2f = ((T2d) - ((KP250000000) * (T2e)));
            T2g = T2c + T2f;
            T2u = T2f - T2c;
            T1Y = KP559016994 * (Tm - TB);
            T1Z = ((T7) - ((KP250000000) * (TC)));
            T20 = T1Y + T1Z;
            T2q = T1Z - T1Y;
        }
        {
            E T28, T2k, T1X, T29;
            T28 = T20 + T27;
            T2k = T2g - T2j;
            T1X = W[6];
            T29 = W[7];
            cr[(rs[4])] = ((T1X * T28) - ((T29) * (T2k)));
            ci[(rs[4])] = (((T29) * (T28)) + (T1X * T2k));
        }
        {
            E T2y, T2A, T2x, T2z;
            T2y = T2q - T2r;
            T2A = T2v + T2u;
            T2x = W[22];
            T2z = W[23];
            cr[(rs[12])] = ((T2x * T2y) - ((T2z) * (T2A)));
            ci[(rs[12])] = (((T2z) * (T2y)) + (T2x * T2A));
        }
        {
            E T2m, T2o, T2l, T2n;
            T2m = T20 - T27;
            T2o = T2j + T2g;
            T2l = W[30];
            T2n = W[31];
            cr[(rs[16])] = ((T2l * T2m) - ((T2n) * (T2o)));
            ci[(rs[16])] = (((T2n) * (T2m)) + (T2l * T2o));
        }
        {
            E T2s, T2w, T2p, T2t;
            T2s = T2q + T2r;
            T2w = T2u - T2v;
            T2p = W[14];
            T2t = W[15];
            cr[(rs[8])] = ((T2p * T2s) - ((T2t) * (T2w)));
            ci[(rs[8])] = (((T2t) * (T2s)) + (T2p * T2w));
        }
    }
    {
        E T43, T4f, T4r, T4m, T4c, T4q, T3W, T4n;
        T43 = (((KP951056516) * (T3Z)) + (KP587785252 * T42));
        T4f = (((KP951056516) * (T4d)) + (KP587785252 * T4e));
        T4r = ((KP587785252 * T4d) - ((KP951056516) * (T4e)));
        T4m = ((KP587785252 * T3Z) - ((KP951056516) * (T42)));
        {
            E T48, T4b, T3S, T3V;
            T48 = KP559016994 * (T46 - T47);
            T4b = ((T49) - ((KP250000000) * (T4a)));
            T4c = T48 + T4b;
            T4q = T4b - T48;
            T3S = KP559016994 * (T3O - T3R);
            T3V = ((T3T) - ((KP250000000) * (T3U)));
            T3W = T3S + T3V;
            T4n = T3V - T3S;
        }
        {
            E T44, T4g, T3L, T45;
            T44 = T3W - T43;
            T4g = T4c + T4f;
            T3L = W[0];
            T45 = W[1];
            cr[(rs[1])] = ((T3L * T44) - ((T45) * (T4g)));
            ci[(rs[1])] = (((T3L) * (T4g)) + (T45 * T44));
        }
        {
            E T4u, T4w, T4t, T4v;
            T4u = T4n - T4m;
            T4w = T4q + T4r;
            T4t = W[32];
            T4v = W[33];
            cr[(rs[17])] = ((T4t * T4u) - ((T4v) * (T4w)));
            ci[(rs[17])] = (((T4t) * (T4w)) + (T4v * T4u));
        }
        {
            E T4i, T4k, T4h, T4j;
            T4i = T43 + T3W;
            T4k = T4c - T4f;
            T4h = W[16];
            T4j = W[17];
            cr[(rs[9])] = ((T4h * T4i) - ((T4j) * (T4k)));
            ci[(rs[9])] = (((T4h) * (T4k)) + (T4j * T4i));
        }
        {
            E T4o, T4s, T4l, T4p;
            T4o = T4m + T4n;
            T4s = T4q - T4r;
            T4l = W[24];
            T4p = W[25];
            cr[(rs[13])] = ((T4l * T4o) - ((T4p) * (T4s)));
            ci[(rs[13])] = (((T4l) * (T4s)) + (T4p * T4o));
        }
    }
    {
        E T1j, T1o, T1M, T1J, T1B, T1N, TO, T1I;
        T1j = ((KP587785252 * T13) - ((KP951056516) * (T1i)));
        T1o = ((KP587785252 * T1m) - ((KP951056516) * (T1n)));
        T1M = (((KP951056516) * (T1m)) + (KP587785252 * T1n));
        T1J = (((KP951056516) * (T13)) + (KP587785252 * T1i));
        {
            E T1z, T1A, TM, TN;
            T1z = ((T1v) - ((KP250000000) * (T1y)));
            T1A = KP559016994 * (T1w - T1x);
            T1B = T1z - T1A;
            T1N = T1A + T1z;
            TM = ((TE) - ((KP250000000) * (TL)));
            TN = KP559016994 * (TH - TK);
            TO = TM - TN;
            T1I = TN + TM;
        }
        {
            E T1k, T1C, TD, T1l;
            T1k = TO - T1j;
            T1C = T1o + T1B;
            TD = W[2];
            T1l = W[3];
            cr[(rs[2])] = ((TD * T1k) - ((T1l) * (T1C)));
            ci[(rs[2])] = (((T1l) * (T1k)) + (TD * T1C));
        }
        {
            E T1Q, T1S, T1P, T1R;
            T1Q = T1I + T1J;
            T1S = T1N - T1M;
            T1P = W[26];
            T1R = W[27];
            cr[(rs[14])] = ((T1P * T1Q) - ((T1R) * (T1S)));
            ci[(rs[14])] = (((T1R) * (T1Q)) + (T1P * T1S));
        }
        {
            E T1E, T1G, T1D, T1F;
            T1E = TO + T1j;
            T1G = T1B - T1o;
            T1D = W[34];
            T1F = W[35];
            cr[(rs[18])] = ((T1D * T1E) - ((T1F) * (T1G)));
            ci[(rs[18])] = (((T1F) * (T1E)) + (T1D * T1G));
        }
        {
            E T1K, T1O, T1H, T1L;
            T1K = T1I - T1J;
            T1O = T1M + T1N;
            T1H = W[10];
            T1L = W[11];
            cr[(rs[6])] = ((T1H * T1K) - ((T1L) * (T1O)));
            ci[(rs[6])] = (((T1L) * (T1K)) + (T1H * T1O));
        }
    }
    {
        E T2Q, T3p, T3B, T3x, T3m, T3A, T3b, T3w;
        T2Q = ((KP587785252 * T2I) - ((KP951056516) * (T2P)));
        T3p = ((KP587785252 * T3n) - ((KP951056516) * (T3o)));
        T3B = (((KP951056516) * (T3n)) + (KP587785252 * T3o));
        T3x = (((KP951056516) * (T2I)) + (KP587785252 * T2P));
        {
            E T3k, T3l, T39, T3a;
            T3k = ((T3g) - ((KP250000000) * (T3j)));
            T3l = KP559016994 * (T3h - T3i);
            T3m = T3k - T3l;
            T3A = T3l + T3k;
            T39 = ((T2T) - ((KP250000000) * (T38)));
            T3a = KP559016994 * (T30 - T37);
            T3b = T39 - T3a;
            T3w = T3a + T39;
        }
        {
            E T3c, T3q, T2B, T3d;
            T3c = T2Q + T3b;
            T3q = T3m - T3p;
            T2B = W[4];
            T3d = W[5];
            cr[(rs[3])] = ((T2B * T3c) - ((T3d) * (T3q)));
            ci[(rs[3])] = (((T2B) * (T3q)) + (T3d * T3c));
        }
        {
            E T3E, T3G, T3D, T3F;
            T3E = T3x + T3w;
            T3G = T3A - T3B;
            T3D = W[36];
            T3F = W[37];
            cr[(rs[19])] = ((T3D * T3E) - ((T3F) * (T3G)));
            ci[(rs[19])] = (((T3D) * (T3G)) + (T3F * T3E));
        }
        {
            E T3s, T3u, T3r, T3t;
            T3s = T3b - T2Q;
            T3u = T3m + T3p;
            T3r = W[12];
            T3t = W[13];
            cr[(rs[7])] = ((T3r * T3s) - ((T3t) * (T3u)));
            ci[(rs[7])] = (((T3r) * (T3u)) + (T3t * T3s));
        }
        {
            E T3y, T3C, T3v, T3z;
            T3y = T3w - T3x;
            T3C = T3A + T3B;
            T3v = W[20];
            T3z = W[21];
            cr[(rs[11])] = ((T3v * T3y) - ((T3z) * (T3C)));
            ci[(rs[11])] = (((T3v) * (T3C)) + (T3z * T3y));
        }
    }

    // Second iteration (m+1), offset by ms
    {
        E T3, T2R, T1u, T2S, T6, T3f, T1r, T3e;
        {
            E T1, T2, T1s, T1t;
            T1 = cr[ms];
            T2 = ci[(rs[9]) + ms];
            T3 = T1 + T2;
            T2R = T1 - T2;
            T1s = ci[(rs[14]) + ms];
            T1t = cr[(rs[15]) + ms];
            T1u = T1s - T1t;
            T2S = T1s + T1t;
        }
        {
            E T4, T5, T1p, T1q;
            T4 = cr[(rs[5]) + ms];
            T5 = ci[(rs[4]) + ms];
            T6 = T4 + T5;
            T3f = T4 - T5;
            T1p = ci[(rs[19]) + ms];
            T1q = cr[(rs[10]) + ms];
            T1r = T1p - T1q;
            T3e = T1p + T1q;
        }
        T7 = T3 + T6;
        T3T = T2R - T2S;
        T49 = T3f + T3e;
        TE = T3 - T6;
        T1v = T1r - T1u;
        T2T = T2R + T2S;
        T3g = T3e - T3f;
        T2d = T1r + T1u;
    }
    {
        E Te, T3M, T3X, TF, TV, T2E, T2W, T21, TA, T3Q, T41, TJ, T1h, T2O, T36;
        E T25, Tl, T3N, T3Y, TG, T12, T2H, T2Z, T22, Tt, T3P, T40, TI, T1a, T2L;
        E T33, T24;
        {
            E Ta, T2U, TU, T2V, Td, T2D, TR, T2C;
            {
                E T8, T9, TS, TT;
                T8 = cr[(rs[4]) + ms];
                T9 = ci[(rs[5]) + ms];
                Ta = T8 + T9;
                T2U = T8 - T9;
                TS = ci[(rs[10]) + ms];
                TT = cr[(rs[19]) + ms];
                TU = TS - TT;
                T2V = TS + TT;
            }
            {
                E Tb, Tc, TP, TQ;
                Tb = cr[(rs[9]) + ms];
                Tc = ci[ms];
                Td = Tb + Tc;
                T2D = Tb - Tc;
                TP = ci[(rs[15]) + ms];
                TQ = cr[(rs[14]) + ms];
                TR = TP - TQ;
                T2C = TP + TQ;
            }
            Te = Ta + Td;
            T3M = T2U - T2V;
            T3X = T2D + T2C;
            TF = Ta - Td;
            TV = TR - TU;
            T2E = T2C - T2D;
            T2W = T2U + T2V;
            T21 = TR + TU;
        }
        {
            E Tw, T34, Tz, T2M, T1d, T2N, T1g, T35;
            {
                E Tu, Tv, Tx, Ty;
                Tu = ci[(rs[7]) + ms];
                Tv = cr[(rs[2]) + ms];
                Tw = Tu + Tv;
                T34 = Tu - Tv;
                Tx = ci[(rs[2]) + ms];
                Ty = cr[(rs[7]) + ms];
                Tz = Tx + Ty;
                T2M = Tx - Ty;
            }
            {
                E T1b, T1c, T1e, T1f;
                T1b = ci[(rs[17]) + ms];
                T1c = cr[(rs[12]) + ms];
                T1d = T1b - T1c;
                T2N = T1b + T1c;
                T1e = ci[(rs[12]) + ms];
                T1f = cr[(rs[17]) + ms];
                T1g = T1e - T1f;
                T35 = T1e + T1f;
            }
            TA = Tw + Tz;
            T3Q = T34 + T35;
            T41 = T2M - T2N;
            TJ = Tw - Tz;
            T1h = T1d - T1g;
            T2O = T2M + T2N;
            T36 = T34 - T35;
            T25 = T1d + T1g;
        }
        {
            E Th, T2X, T11, T2Y, Tk, T2F, TY, T2G;
            {
                E Tf, Tg, TZ, T10;
                Tf = ci[(rs[3]) + ms];
                Tg = cr[(rs[6]) + ms];
                Th = Tf + Tg;
                T2X = Tf - Tg;
                TZ = ci[(rs[18]) + ms];
                T10 = cr[(rs[11]) + ms];
                T11 = TZ - T10;
                T2Y = TZ + T10;
            }
            {
                E Ti, Tj, TW, TX;
                Ti = cr[(rs[1]) + ms];
                Tj = ci[(rs[8]) + ms];
                Tk = Ti + Tj;
                T2F = Ti - Tj;
                TW = ci[(rs[13]) + ms];
                TX = cr[(rs[16]) + ms];
                TY = TW - TX;
                T2G = TW + TX;
            }
            Tl = Th + Tk;
            T3N = T2X - T2Y;
            T3Y = T2F - T2G;
            TG = Th - Tk;
            T12 = TY - T11;
            T2H = T2F + T2G;
            T2Z = T2X + T2Y;
            T22 = TY + T11;
        }
        {
            E Tp, T31, T19, T32, Ts, T2K, T16, T2J;
            {
                E Tn, To, T17, T18;
                Tn = cr[(rs[8]) + ms];
                To = ci[(rs[1]) + ms];
                Tp = Tn + To;
                T31 = Tn - To;
                T17 = ci[(rs[16]) + ms];
                T18 = cr[(rs[13]) + ms];
                T19 = T17 - T18;
                T32 = T17 + T18;
            }
            {
                E Tq, Tr, T14, T15;
                Tq = ci[(rs[6]) + ms];
                Tr = cr[(rs[3]) + ms];
                Ts = Tq + Tr;
                T2K = Tq - Tr;
                T14 = ci[(rs[11]) + ms];
                T15 = cr[(rs[18]) + ms];
                T16 = T14 - T15;
                T2J = T14 + T15;
            }
            Tt = Tp + Ts;
            T3P = T31 + T32;
            T40 = T2K + T2J;
            TI = Tp - Ts;
            T1a = T16 - T19;
            T2L = T2J - T2K;
            T33 = T31 - T32;
            T24 = T16 + T19;
        }
        T13 = TV - T12;
        T3n = T2W - T2Z;
        T3o = T33 - T36;
        T1i = T1a - T1h;
        T26 = T24 - T25;
        T4e = T3P - T3Q;
        T4d = T3M - T3N;
        T23 = T21 - T22;
        T1n = TI - TJ;
        T42 = T40 - T41;
        T3Z = T3X - T3Y;
        T1m = TF - TG;
        T2h = Te - Tl;
        T2I = T2E + T2H;
        T2i = Tt - TA;
        T2P = T2L + T2O;
        T30 = T2W + T2Z;
        T37 = T33 + T36;
        T38 = T30 + T37;
        Tm = Te + Tl;
        TB = Tt + TA;
        TC = Tm + TB;
        T46 = T3X + T3Y;
        T47 = T40 + T41;
        T4a = T46 + T47;
        T2a = T21 + T22;
        T2b = T24 + T25;
        T2e = T2a + T2b;
        T1w = TV + T12;
        T1x = T1a + T1h;
        T1y = T1w + T1x;
        T3O = T3M + T3N;
        T3R = T3P + T3Q;
        T3U = T3O + T3R;
        T3h = T2E - T2H;
        T3i = T2L - T2O;
        T3j = T3h + T3i;
        TH = TF + TG;
        TK = TI + TJ;
        TL = TH + TK;
    }
    cr[ms] = T7 + TC;
    ci[ms] = T2d + T2e;
    {
        E T1U, T1W, T1T, T1V;
        T1U = TE + TL;
        T1W = T1v + T1y;
        T1T = W[18];
        T1V = W[19];
        cr[(rs[10]) + ms] = ((T1T * T1U) - ((T1V) * (T1W)));
        ci[(rs[10]) + ms] = (((T1V) * (T1U)) + (T1T * T1W));
    }
    {
        E T4y, T4A, T4x, T4z;
        T4y = T3T + T3U;
        T4A = T49 + T4a;
        T4x = W[8];
        T4z = W[9];
        cr[(rs[5]) + ms] = ((T4x * T4y) - ((T4z) * (T4A)));
        ci[(rs[5]) + ms] = (((T4x) * (T4A)) + (T4z * T4y));
    }
    {
        E T3I, T3K, T3H, T3J;
        T3I = T2T + T38;
        T3K = T3g + T3j;
        T3H = W[28];
        T3J = W[29];
        cr[(rs[15]) + ms] = ((T3H * T3I) - ((T3J) * (T3K)));
        ci[(rs[15]) + ms] = (((T3H) * (T3K)) + (T3J * T3I));
    }
    {
        E T27, T2j, T2v, T2r, T2g, T2u, T20, T2q;
        T27 = (((KP951056516) * (T23)) + (KP587785252 * T26));
        T2j = (((KP951056516) * (T2h)) + (KP587785252 * T2i));
        T2v = ((KP587785252 * T2h) - ((KP951056516) * (T2i)));
        T2r = ((KP587785252 * T23) - ((KP951056516) * (T26)));
        {
            E T2c, T2f, T1Y, T1Z;
            T2c = KP559016994 * (T2a - T2b);
            T2f = ((T2d) - ((KP250000000) * (T2e)));
            T2g = T2c + T2f;
            T2u = T2f - T2c;
            T1Y = KP559016994 * (Tm - TB);
            T1Z = ((T7) - ((KP250000000) * (TC)));
            T20 = T1Y + T1Z;
            T2q = T1Z - T1Y;
        }
        {
            E T28, T2k, T1X, T29;
            T28 = T20 + T27;
            T2k = T2g - T2j;
            T1X = W[6];
            T29 = W[7];
            cr[(rs[4]) + ms] = ((T1X * T28) - ((T29) * (T2k)));
            ci[(rs[4]) + ms] = (((T29) * (T28)) + (T1X * T2k));
        }
        {
            E T2y, T2A, T2x, T2z;
            T2y = T2q - T2r;
            T2A = T2v + T2u;
            T2x = W[22];
            T2z = W[23];
            cr[(rs[12]) + ms] = ((T2x * T2y) - ((T2z) * (T2A)));
            ci[(rs[12]) + ms] = (((T2z) * (T2y)) + (T2x * T2A));
        }
        {
            E T2m, T2o, T2l, T2n;
            T2m = T20 - T27;
            T2o = T2j + T2g;
            T2l = W[30];
            T2n = W[31];
            cr[(rs[16]) + ms] = ((T2l * T2m) - ((T2n) * (T2o)));
            ci[(rs[16]) + ms] = (((T2n) * (T2m)) + (T2l * T2o));
        }
        {
            E T2s, T2w, T2p, T2t;
            T2s = T2q + T2r;
            T2w = T2u - T2v;
            T2p = W[14];
            T2t = W[15];
            cr[(rs[8]) + ms] = ((T2p * T2s) - ((T2t) * (T2w)));
            ci[(rs[8]) + ms] = (((T2t) * (T2s)) + (T2p * T2w));
        }
    }
    {
        E T43, T4f, T4r, T4m, T4c, T4q, T3W, T4n;
        T43 = (((KP951056516) * (T3Z)) + (KP587785252 * T42));
        T4f = (((KP951056516) * (T4d)) + (KP587785252 * T4e));
        T4r = ((KP587785252 * T4d) - ((KP951056516) * (T4e)));
        T4m = ((KP587785252 * T3Z) - ((KP951056516) * (T42)));
        {
            E T48, T4b, T3S, T3V;
            T48 = KP559016994 * (T46 - T47);
            T4b = ((T49) - ((KP250000000) * (T4a)));
            T4c = T48 + T4b;
            T4q = T4b - T48;
            T3S = KP559016994 * (T3O - T3R);
            T3V = ((T3T) - ((KP250000000) * (T3U)));
            T3W = T3S + T3V;
            T4n = T3V - T3S;
        }
        {
            E T44, T4g, T3L, T45;
            T44 = T3W - T43;
            T4g = T4c + T4f;
            T3L = W[0];
            T45 = W[1];
            cr[(rs[1]) + ms] = ((T3L * T44) - ((T45) * (T4g)));
            ci[(rs[1]) + ms] = (((T3L) * (T4g)) + (T45 * T44));
        }
        {
            E T4u, T4w, T4t, T4v;
            T4u = T4n - T4m;
            T4w = T4q + T4r;
            T4t = W[32];
            T4v = W[33];
            cr[(rs[17]) + ms] = ((T4t * T4u) - ((T4v) * (T4w)));
            ci[(rs[17]) + ms] = (((T4t) * (T4w)) + (T4v * T4u));
        }
        {
            E T4i, T4k, T4h, T4j;
            T4i = T43 + T3W;
            T4k = T4c - T4f;
            T4h = W[16];
            T4j = W[17];
            cr[(rs[9]) + ms] = ((T4h * T4i) - ((T4j) * (T4k)));
            ci[(rs[9]) + ms] = (((T4h) * (T4k)) + (T4j * T4i));
        }
        {
            E T4o, T4s, T4l, T4p;
            T4o = T4m + T4n;
            T4s = T4q - T4r;
            T4l = W[24];
            T4p = W[25];
            cr[(rs[13]) + ms] = ((T4l * T4o) - ((T4p) * (T4s)));
            ci[(rs[13]) + ms] = (((T4l) * (T4s)) + (T4p * T4o));
        }
    }
    {
        E T1j, T1o, T1M, T1J, T1B, T1N, TO, T1I;
        T1j = ((KP587785252 * T13) - ((KP951056516) * (T1i)));
        T1o = ((KP587785252 * T1m) - ((KP951056516) * (T1n)));
        T1M = (((KP951056516) * (T1m)) + (KP587785252 * T1n));
        T1J = (((KP951056516) * (T13)) + (KP587785252 * T1i));
        {
            E T1z, T1A, TM, TN;
            T1z = ((T1v) - ((KP250000000) * (T1y)));
            T1A = KP559016994 * (T1w - T1x);
            T1B = T1z - T1A;
            T1N = T1A + T1z;
            TM = ((TE) - ((KP250000000) * (TL)));
            TN = KP559016994 * (TH - TK);
            TO = TM - TN;
            T1I = TN + TM;
        }
        {
            E T1k, T1C, TD, T1l;
            T1k = TO - T1j;
            T1C = T1o + T1B;
            TD = W[2];
            T1l = W[3];
            cr[(rs[2]) + ms] = ((TD * T1k) - ((T1l) * (T1C)));
            ci[(rs[2]) + ms] = (((T1l) * (T1k)) + (TD * T1C));
        }
        {
            E T1Q, T1S, T1P, T1R;
            T1Q = T1I + T1J;
            T1S = T1N - T1M;
            T1P = W[26];
            T1R = W[27];
            cr[(rs[14]) + ms] = ((T1P * T1Q) - ((T1R) * (T1S)));
            ci[(rs[14]) + ms] = (((T1R) * (T1Q)) + (T1P * T1S));
        }
        {
            E T1E, T1G, T1D, T1F;
            T1E = TO + T1j;
            T1G = T1B - T1o;
            T1D = W[34];
            T1F = W[35];
            cr[(rs[18]) + ms] = ((T1D * T1E) - ((T1F) * (T1G)));
            ci[(rs[18]) + ms] = (((T1F) * (T1E)) + (T1D * T1G));
        }
        {
            E T1K, T1O, T1H, T1L;
            T1K = T1I - T1J;
            T1O = T1M + T1N;
            T1H = W[10];
            T1L = W[11];
            cr[(rs[6]) + ms] = ((T1H * T1K) - ((T1L) * (T1O)));
            ci[(rs[6]) + ms] = (((T1L) * (T1K)) + (T1H * T1O));
        }
    }
    {
        E T2Q, T3p, T3B, T3x, T3m, T3A, T3b, T3w;
        T2Q = ((KP587785252 * T2I) - ((KP951056516) * (T2P)));
        T3p = ((KP587785252 * T3n) - ((KP951056516) * (T3o)));
        T3B = (((KP951056516) * (T3n)) + (KP587785252 * T3o));
        T3x = (((KP951056516) * (T2I)) + (KP587785252 * T2P));
        {
            E T3k, T3l, T39, T3a;
            T3k = ((T3g) - ((KP250000000) * (T3j)));
            T3l = KP559016994 * (T3h - T3i);
            T3m = T3k - T3l;
            T3A = T3l + T3k;
            T39 = ((T2T) - ((KP250000000) * (T38)));
            T3a = KP559016994 * (T30 - T37);
            T3b = T39 - T3a;
            T3w = T3a + T39;
        }
        {
            E T3c, T3q, T2B, T3d;
            T3c = T2Q + T3b;
            T3q = T3m - T3p;
            T2B = W[4];
            T3d = W[5];
            cr[(rs[3]) + ms] = ((T2B * T3c) - ((T3d) * (T3q)));
            ci[(rs[3]) + ms] = (((T2B) * (T3q)) + (T3d * T3c));
        }
        {
            E T3E, T3G, T3D, T3F;
            T3E = T3x + T3w;
            T3G = T3A - T3B;
            T3D = W[36];
            T3F = W[37];
            cr[(rs[19]) + ms] = ((T3D * T3E) - ((T3F) * (T3G)));
            ci[(rs[19]) + ms] = (((T3D) * (T3G)) + (T3F * T3E));
        }
        {
            E T3s, T3u, T3r, T3t;
            T3s = T3b - T2Q;
            T3u = T3m + T3p;
            T3r = W[12];
            T3t = W[13];
            cr[(rs[7]) + ms] = ((T3r * T3s) - ((T3t) * (T3u)));
            ci[(rs[7]) + ms] = (((T3r) * (T3u)) + (T3t * T3s));
        }
        {
            E T3y, T3C, T3v, T3z;
            T3y = T3w - T3x;
            T3C = T3A + T3B;
            T3v = W[20];
            T3z = W[21];
            cr[(rs[11]) + ms] = ((T3v * T3y) - ((T3z) * (T3C)));
            ci[(rs[11]) + ms] = (((T3v) * (T3C)) + (T3z * T3y));
        }
    }
}
}
