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
extern  E KP250000000;
extern  E KP559016994;
extern  E KP587785252;
extern  E KP951056516;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 38); m < me; m = m + 1 , Rp = Rp + ms , Ip = Ip + ms , Rm = Rm - ms , Im = Im - ms , W = W + 38 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T7, T3T, T49, TE, T1v, T2T, T3g, T2d, T13, T3n, T3o, T1i, T26, T4e, T4d;
    E T23, T1n, T42, T3Z, T1m, T2h, T2I, T2i, T2P, T30, T37, T38, Tm, TB, TC;
    E T46, T47, T4a, T2a, T2b, T2e, T1w, T1x, T1y, T3O, T3R, T3U, T3h, T3i, T3j;
    E TH, TK, TL;

    // Initialize early to allow conditional skipping
    T7 = T2d = 0.0;

    // Control dependency: split execution path based on modulo pattern
    if (m % 3 == 0) {
        // Minimal path: only compute first stage and exit early
        E T3, T2R, T1r, T3e, T6, T3f, T1u, T2S;
        E T1 = Rp[0], T2 = Rm[(rs[9])];
        T3 = T1 + T2;
        T2R = T1 - T2;
        E T1p = Ip[0], T1q = Im[(rs[9])];
        T1r = T1p - T1q;
        T3e = T1p + T1q;

        E T4 = Rp[(rs[5])], T5 = Rm[(rs[4])];
        T6 = T4 + T5;
        T3f = T4 - T5;
        E T1s = Ip[(rs[5])], T1t = Im[(rs[4])];
        T1u = T1s - T1t;
        T2S = T1s + T1t;

        T7 = T3 + T6;
        T2d = T1r + T1u;

        Rp[0] = T7;
        Rm[0] = T2d;
        continue;
    }

    // Full computation for other iterations
    {
        E T3, T2R, T1r, T3e, T6, T3f, T1u, T2S;
        {
            E T1, T2, T1p, T1q;
            T1 = Rp[0];
            T2 = Rm[(rs[9])];
            T3 = T1 + T2;
            T2R = T1 - T2;
            T1p = Ip[0];
            T1q = Im[(rs[9])];
            T1r = T1p - T1q;
            T3e = T1p + T1q;
        }
        {
            E T4, T5, T1s, T1t;
            T4 = Rp[(rs[5])];
            T5 = Rm[(rs[4])];
            T6 = T4 + T5;
            T3f = T4 - T5;
            T1s = Ip[(rs[5])];
            T1t = Im[(rs[4])];
            T1u = T1s - T1t;
            T2S = T1s + T1t;
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
            E Ta, T2U, TR, T2C, Td, T2D, TU, T2V;
            {
                E T8, T9, TP, TQ;
                T8 = Rp[(rs[4])];
                T9 = Rm[(rs[5])];
                Ta = T8 + T9;
                T2U = T8 - T9;
                TP = Ip[(rs[4])];
                TQ = Im[(rs[5])];
                TR = TP - TQ;
                T2C = TP + TQ;
            }
            {
                E Tb, Tc, TS, TT;
                Tb = Rp[(rs[9])];
                Tc = Rm[0];
                Td = Tb + Tc;
                T2D = Tb - Tc;
                TS = Ip[(rs[9])];
                TT = Im[0];
                TU = TS - TT;
                T2V = TS + TT;
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
            E Tw, T34, T1d, T2N, Tz, T2M, T1g, T35;
            {
                E Tu, Tv, T1b, T1c;
                Tu = Rm[(rs[7])];
                Tv = Rp[(rs[2])];
                Tw = Tu + Tv;
                T34 = Tu - Tv;
                T1b = Ip[(rs[2])];
                T1c = Im[(rs[7])];
                T1d = T1b - T1c;
                T2N = T1b + T1c;
            }
            {
                E Tx, Ty, T1e, T1f;
                Tx = Rm[(rs[2])];
                Ty = Rp[(rs[7])];
                Tz = Tx + Ty;
                T2M = Tx - Ty;
                T1e = Ip[(rs[7])];
                T1f = Im[(rs[2])];
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
            E Th, T2X, TY, T2G, Tk, T2F, T11, T2Y;
            {
                E Tf, Tg, TW, TX;
                Tf = Rm[(rs[3])];
                Tg = Rp[(rs[6])];
                Th = Tf + Tg;
                T2X = Tf - Tg;
                TW = Ip[(rs[6])];
                TX = Im[(rs[3])];
                TY = TW - TX;
                T2G = TW + TX;
            }
            {
                E Ti, Tj, TZ, T10;
                Ti = Rp[(rs[1])];
                Tj = Rm[(rs[8])];
                Tk = Ti + Tj;
                T2F = Ti - Tj;
                TZ = Ip[(rs[1])];
                T10 = Im[(rs[8])];
                T11 = TZ - T10;
                T2Y = TZ + T10;
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
            E Tp, T31, T16, T2J, Ts, T2K, T19, T32;
            {
                E Tn, To, T14, T15;
                Tn = Rp[(rs[8])];
                To = Rm[(rs[1])];
                Tp = Tn + To;
                T31 = Tn - To;
                T14 = Ip[(rs[8])];
                T15 = Im[(rs[1])];
                T16 = T14 - T15;
                T2J = T14 + T15;
            }
            {
                E Tq, Tr, T17, T18;
                Tq = Rm[(rs[6])];
                Tr = Rp[(rs[3])];
                Ts = Tq + Tr;
                T2K = Tq - Tr;
                T17 = Ip[(rs[3])];
                T18 = Im[(rs[6])];
                T19 = T17 - T18;
                T32 = T17 + T18;
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

    Rp[0] = T7 + TC;
    Rm[0] = T2d + T2e;

    // Additional control: apply rotation only on specific indices
    if (m % 4 != 0) {
        E T1U = TE + TL;
        E T1W = T1v + T1y;
        E T1T = W[18], T1V = W[19];
        Rp[(rs[5])] = ((T1T * T1U) - (T1V * T1W));
        Rm[(rs[5])] = ((T1V * T1U) + (T1T * T1W));
    }

    // Always perform at least one complex update
    {
        E T4y = T3T + T3U;
        E T4A = T49 + T4a;
        E T4x = W[8], T4z = W[9];
        Ip[(rs[2])] = (T4x * T4y) - (T4z * T4A);
        Im[(rs[2])] = (T4x * T4A) + (T4z * T4y);
    }

    // Remaining blocks unchanged
    {
        E T3I, T3K, T3H, T3J;
        T3I = T2T + T38;
        T3K = T3g + T3j;
        T3H = W[28];
        T3J = W[29];
        Ip[(rs[7])] = ((T3H * T3I) - ((T3J) * (T3K)));
        Im[(rs[7])] = (((T3H) * (T3K)) + (T3J * T3I));
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
            Rp[(rs[2])] = ((T1X * T28) - ((T29) * (T2k)));
            Rm[(rs[2])] = (((T29) * (T28)) + (T1X * T2k));
        }
        {
            E T2y, T2A, T2x, T2z;
            T2y = T2q - T2r;
            T2A = T2v + T2u;
            T2x = W[22];
            T2z = W[23];
            Rp[(rs[6])] = ((T2x * T2y) - ((T2z) * (T2A)));
            Rm[(rs[6])] = (((T2z) * (T2y)) + (T2x * T2A));
        }
        {
            E T2m, T2o, T2l, T2n;
            T2m = T20 - T27;
            T2o = T2j + T2g;
            T2l = W[30];
            T2n = W[31];
            Rp[(rs[8])] = ((T2l * T2m) - ((T2n) * (T2o)));
            Rm[(rs[8])] = (((T2n) * (T2m)) + (T2l * T2o));
        }
        {
            E T2s, T2w, T2p, T2t;
            T2s = T2q + T2r;
            T2w = T2u - T2v;
            T2p = W[14];
            T2t = W[15];
            Rp[(rs[4])] = ((T2p * T2s) - ((T2t) * (T2w)));
            Rm[(rs[4])] = (((T2t) * (T2s)) + (T2p * T2w));
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
            Ip[0] = ((T3L * T44) - ((T45) * (T4g)));
            Im[0] = (((T3L) * (T4g)) + (T45 * T44));
        }
        {
            E T4u, T4w, T4t, T4v;
            T4u = T4n - T4m;
            T4w = T4q + T4r;
            T4t = W[32];
            T4v = W[33];
            Ip[(rs[8])] = ((T4t * T4u) - ((T4v) * (T4w)));
            Im[(rs[8])] = (((T4t) * (T4w)) + (T4v * T4u));
        }
        {
            E T4i, T4k, T4h, T4j;
            T4i = T43 + T3W;
            T4k = T4c - T4f;
            T4h = W[16];
            T4j = W[17];
            Ip[(rs[4])] = ((T4h * T4i) - ((T4j) * (T4k)));
            Im[(rs[4])] = (((T4h) * (T4k)) + (T4j * T4i));
        }
        {
            E T4o, T4s, T4l, T4p;
            T4o = T4m + T4n;
            T4s = T4q - T4r;
            T4l = W[24];
            T4p = W[25];
            Ip[(rs[6])] = ((T4l * T4o) - ((T4p) * (T4s)));
            Im[(rs[6])] = (((T4l) * (T4s)) + (T4p * T4o));
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
            Rp[(rs[1])] = ((TD * T1k) - ((T1l) * (T1C)));
            Rm[(rs[1])] = (((T1l) * (T1k)) + (TD * T1C));
        }
        {
            E T1Q, T1S, T1P, T1R;
            T1Q = T1I + T1J;
            T1S = T1N - T1M;
            T1P = W[26];
            T1R = W[27];
            Rp[(rs[7])] = ((T1P * T1Q) - ((T1R) * (T1S)));
            Rm[(rs[7])] = (((T1R) * (T1Q)) + (T1P * T1S));
        }
        {
            E T1E, T1G, T1D, T1F;
            T1E = TO + T1j;
            T1G = T1B - T1o;
            T1D = W[34];
            T1F = W[35];
            Rp[(rs[9])] = ((T1D * T1E) - ((T1F) * (T1G)));
            Rm[(rs[9])] = (((T1F) * (T1E)) + (T1D * T1G));
        }
        {
            E T1K, T1O, T1H, T1L;
            T1K = T1I - T1J;
            T1O = T1M + T1N;
            T1H = W[10];
            T1L = W[11];
            Rp[(rs[3])] = ((T1H * T1K) - ((T1L) * (T1O)));
            Rm[(rs[3])] = (((T1L) * (T1K)) + (T1H * T1O));
        }
    }

    {
        E T2Q, T3p, T3B, T3x, T3b, T3A, T39, T3w;
        T2Q = ((KP587785252 * T2I) - ((KP951056516) * (T2P)));
        T3p = ((KP587785252 * T3n) - ((KP951056516) * (T3o)));
        T3B = (((KP951056516) * (T3n)) + (KP587785252 * T3o));
        T3x = (((KP951056516) * (T2I)) + (KP587785252 * T2P));
        {
            E T3k, T3l, T39_val, T3a;
            T3k = ((T3g) - ((KP250000000) * (T3j)));
            T3l = KP559016994 * (T3h - T3i);
            T3b = T3k - T3l;
            T3A = T3l + T3k;
            T39_val = ((T2T) - ((KP250000000) * (T38)));
            T3a = KP559016994 * (T30 - T37);
            T39 = T39_val - T3a;
            T3w = T3a + T39_val;
        }
        {
            E T3c, T3q, T2B, T3d;
            T3c = T2Q + T3b;
            T3q = T3b - T3p;
            T2B = W[4];
            T3d = W[5];
            Ip[(rs[1])] = ((T2B * T3c) - ((T3d) * (T3q)));
            Im[(rs[1])] = (((T2B) * (T3q)) + (T3d * T3c));
        }
        {
            E T3E, T3G, T3D, T3F;
            T3E = T3x + T3w;
            T3G = T3A - T3B;
            T3D = W[36];
            T3F = W[37];
            Ip[(rs[9])] = ((T3D * T3E) - ((T3F) * (T3G)));
            Im[(rs[9])] = (((T3D) * (T3G)) + (T3F * T3E));
        }
        {
            E T3s, T3u, T3r, T3t;
            T3s = T3b - T2Q;
            T3u = T3p + T3A;
            T3r = W[12];
            T3t = W[13];
            Ip[(rs[3])] = ((T3r * T3s) - ((T3t) * (T3u)));
            Im[(rs[3])] = (((T3r) * (T3u)) + (T3t * T3s));
        }
        {
            E T3y, T3C, T3v, T3z;
            T3y = T3w - T3x;
            T3C = T3A + T3B;
            T3v = W[20];
            T3z = W[21];
            Ip[(rs[5])] = ((T3v * T3y) - ((T3z) * (T3C)));
            Im[(rs[5])] = (((T3v) * (T3C)) + (T3z * T3y));
        }
    }
}
}
