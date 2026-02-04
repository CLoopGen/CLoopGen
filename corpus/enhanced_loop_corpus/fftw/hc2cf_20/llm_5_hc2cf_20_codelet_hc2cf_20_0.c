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
extern  E KP587785252;
extern  E KP951056516;
extern  E KP250000000;
extern  E KP559016994;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 38); m < me; m = m + 1 , Rp = Rp + ms , Ip = Ip + ms , Rm = Rm - ms , Im = Im - ms , W = W + 38 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E Tj, T1R, T4j, T4s, T2q, T37, T3Q, T42, T1r, T1O, T1P, T3p, T3s, T3K, T3A;
    E T3B, T3Z, T1V, T1W, T1X, T23, T28, T4q, T2W, T2X, T4f, T33, T34, T35, T2G;
    E T2L, T2M, TG, T13, T14, T3i, T3l, T3J, T3D, T3E, T40, T1S, T1T, T1U, T2e;
    E T2j, T4p, T2T, T2U, T4e, T30, T31, T32, T2v, T2A, T2B;

    // Skip early iterations using conditional guard
    if (m < mb + 2) {
        // Initialize core values directly for first two iterations
        Tj = Rp[0] + Rm[0];
        T1R = Rp[0] - Rm[0];
        T2q = Rp[(rs[5])] + Rm[(rs[5])];
        T37 = Ip[(rs[2])] - Im[(rs[2])];

        Rp[0] = Tj;
        Ip[0] = T1R;
        Rm[0] = T2q;
        Im[0] = T37;
        continue;
    }

    // For m >= mb+2, perform full butterfly computation
    {
        E T1, T3O, T6, T3N, Tc, T2n, Th, T2o;
        T1 = Rp[0];
        T3O = Rm[0];
        {
            E T3, T5, T2, T4;
            T3 = Rp[(rs[5])];
            T5 = Rm[(rs[5])];
            T2 = W[18];
            T4 = W[19];
            T6 = (((T2) * (T3)) + (T4 * T5));
            T3N = ((T2 * T5) - ((T4) * (T3)));
        }
        {
            E T9, Tb, T8, Ta;
            T9 = Ip[(rs[2])];
            Tb = Im[(rs[2])];
            T8 = W[8];
            Ta = W[9];
            Tc = (((T8) * (T9)) + (Ta * Tb));
            T2n = ((T8 * Tb) - ((Ta) * (T9)));
        }
        {
            E Te, Tg, Td, Tf;
            Te = Ip[(rs[7])];
            Tg = Im[(rs[7])];
            Td = W[28];
            Tf = W[29];
            Th = (((Td) * (Te)) + (Tf * Tg));
            T2o = ((Td * Tg) - ((Tf) * (Te)));
        }
        {
            E T7, Ti, T4h, T4i;
            T7 = T1 + T6;
            Ti = Tc + Th;
            Tj = T7 - Ti;
            T1R = T7 + Ti;
            T4h = T3O - T3N;
            T4i = Tc - Th;
            T4j = T4h - T4i;
            T4s = T4i + T4h;
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

    // Always compute middle blocks unconditionally
    {
        E T1f, T3n, T21, T2C, T1N, T3r, T27, T2K, T1q, T3o, T22, T2F, T1C, T3q, T26;
        E T2H;
        {
            E T19, T1Z, T1e, T20;
            {
                E T16, T18, T15, T17;
                T16 = Rp[(rs[4])];
                T18 = Rm[(rs[4])];
                T15 = W[14];
                T17 = W[15];
                T19 = (((T15) * (T16)) + (T17 * T18));
                T1Z = ((T15 * T18) - ((T17) * (T16)));
            }
            {
                E T1b, T1d, T1a, T1c;
                T1b = Rp[(rs[9])];
                T1d = Rm[(rs[9])];
                T1a = W[34];
                T1c = W[35];
                T1e = (((T1a) * (T1b)) + (T1c * T1d));
                T20 = ((T1a * T1d) - ((T1c) * (T1b)));
            }
            T1f = T19 + T1e;
            T3n = T1Z + T20;
            T21 = T1Z - T20;
            T2C = T19 - T1e;
        }
        {
            E T1H, T2I, T1M, T2J;
            {
                E T1E, T1G, T1D, T1F;
                T1E = Ip[(rs[8])];
                T1G = Im[(rs[8])];
                T1D = W[32];
                T1F = W[33];
                T1H = (((T1D) * (T1E)) + (T1F * T1G));
                T2I = ((T1D * T1G) - ((T1F) * (T1E)));
            }
            {
                E T1J, T1L, T1I, T1K;
                T1J = Ip[(rs[3])];
                T1L = Im[(rs[3])];
                T1I = W[12];
                T1K = W[13];
                T1M = (((T1I) * (T1J)) + (T1K * T1L));
                T2J = ((T1I * T1L) - ((T1K) * (T1J)));
            }
            T1N = T1H + T1M;
            T3r = T2I + T2J;
            T27 = T1H - T1M;
            T2K = T2I - T2J;
        }
        {
            E T1k, T2D, T1p, T2E;
            {
                E T1h, T1j, T1g, T1i;
                T1h = Ip[(rs[6])];
                T1j = Im[(rs[6])];
                T1g = W[24];
                T1i = W[25];
                T1k = (((T1g) * (T1h)) + (T1i * T1j));
                T2D = ((T1g * T1j) - ((T1i) * (T1h)));
            }
            {
                E T1m, T1o, T1l, T1n;
                T1m = Ip[(rs[1])];
                T1o = Im[(rs[1])];
                T1l = W[4];
                T1n = W[5];
                T1p = (((T1l) * (T1m)) + (T1n * T1o));
                T2E = ((T1l * T1o) - ((T1n) * (T1m)));
            }
            T1q = T1k + T1p;
            T3o = T2D + T2E;
            T22 = T1k - T1p;
            T2F = T2D - T2E;
        }
        {
            E T1w, T24, T1B, T25;
            {
                E T1t, T1v, T1s, T1u;
                T1t = Rp[(rs[6])];
                T1v = Rm[(rs[6])];
                T1s = W[22];
                T1u = W[23];
                T1w = (((T1s) * (T1t)) + (T1u * T1v));
                T24 = ((T1s * T1v) - ((T1u) * (T1t)));
            }
            {
                E T1y, T1A, T1x, T1z;
                T1y = Rp[(rs[1])];
                T1A = Rm[(rs[1])];
                T1x = W[2];
                T1z = W[3];
                T1B = (((T1x) * (T1y)) + (T1z * T1A));
                T25 = ((T1x * T1A) - ((T1z) * (T1y)));
            }
            T1C = T1w + T1B;
            T3q = T24 + T25;
            T26 = T24 - T25;
            T2H = T1w - T1B;
        }
        T1r = T1f - T1q;
        T1O = T1C - T1N;
        T1P = T1r + T1O;
        T3p = T3n + T3o;
        T3s = T3q + T3r;
        T3K = T3p + T3s;
        T3A = T3n - T3o;
        T3B = T3r - T3q;
        T3Z = T3B - T3A;
        T1V = T1f + T1q;
        T1W = T1C + T1N;
        T1X = T1V + T1W;
        T23 = T21 + T22;
        T28 = T26 + T27;
        T4q = T23 + T28;
        T2W = T21 - T22;
        T2X = T26 - T27;
        T4f = T2W + T2X;
        T33 = T2C + T2F;
        T34 = T2H + T2K;
        T35 = T33 + T34;
        T2G = T2C - T2F;
        T2L = T2H - T2K;
        T2M = T2G + T2L;
    }
    {
        E Tu, T3g, T2c, T2r, T12, T3k, T2f, T2z, TF, T3h, T2d, T2u, TR, T3j, T2i;
        E T2w;
        {
            E To, T2a, Tt, T2b;
            {
                E Tl, Tn, Tk, Tm;
                Tl = Rp[(rs[2])];
                Tn = Rm[(rs[2])];
                Tk = W[6];
                Tm = W[7];
                To = (((Tk) * (Tl)) + (Tm * Tn));
                T2a = ((Tk * Tn) - ((Tm) * (Tl)));
            }
            {
                E Tq, Ts, Tp, Tr;
                Tq = Rp[(rs[7])];
                Ts = Rm[(rs[7])];
                Tp = W[26];
                Tr = W[27];
                Tt = (((Tp) * (Tq)) + (Tr * Ts));
                T2b = ((Tp * Ts) - ((Tr) * (Tq)));
            }
            Tu = To + Tt;
            T3g = T2a + T2b;
            T2c = T2a - T2b;
            T2r = To - Tt;
        }
        {
            E TW, T2x, T11, T2y;
            {
                E TT, TV, TS, TU;
                TT = Ip[0];
                TV = Im[0];
                TS = W[0];
                TU = W[1];
                TW = (((TS) * (TT)) + (TU * TV));
                T2x = ((TS * TV) - ((TU) * (TT)));
            }
            {
                E TY, T10, TX, TZ;
                TY = Ip[(rs[5])];
                T10 = Im[(rs[5])];
                TX = W[20];
                TZ = W[21];
                T11 = (((TX) * (TY)) + (TZ * T10));
                T2y = ((TX * T10) - ((TZ) * (TY)));
            }
            T12 = TW + T11;
            T3k = T2x + T2y;
            T2f = T11 - TW;
            T2z = T2x - T2y;
        }
        {
            E Tz, T2s, TE, T2t;
            {
                E Tw, Ty, Tv, Tx;
                Tw = Ip[(rs[4])];
                Ty = Im[(rs[4])];
                Tv = W[16];
                Tx = W[17];
                Tz = (((Tv) * (Tw)) + (Tx * Ty));
                T2s = ((Tv * Ty) - ((Tx) * (Tw)));
            }
            {
                E TB, TD, TA, TC;
                TB = Ip[(rs[9])];
                TD = Im[(rs[9])];
                TA = W[36];
                TC = W[37];
                TE = (((TA) * (TB)) + (TC * TD));
                T2t = ((TA * TD) - ((TC) * (TB)));
            }
            TF = Tz + TE;
            T3h = T2s + T2t;
            T2d = Tz - TE;
            T2u = T2s - T2t;
        }
        {
            E TL, T2g, TQ, T2h;
            {
                E TI, TK, TH, TJ;
                TI = Rp[(rs[8])];
                TK = Rm[(rs[8])];
                TH = W[30];
                TJ = W[31];
                TL = (((TH) * (TI)) + (TJ * TK));
                T2g = ((TH * TK) - ((TJ) * (TI)));
            }
            {
                E TN, TP, TM, TO;
                TN = Rp[(rs[3])];
                TP = Rm[(rs[3])];
                TM = W[10];
                TO = W[11];
                TQ = (((TM) * (TN)) + (TO * TP));
                T2h = ((TM * TP) - ((TO) * (TN)));
            }
            TR = TL + TQ;
            T3j = T2g + T2h;
            T2i = T2g - T2h;
            T2w = TL - TQ;
        }
        TG = Tu - TF;
        T13 = TR - T12;
        T14 = TG + T13;
        T3i = T3g + T3h;
        T3l = T3j + T3k;
        T3J = T3i + T3l;
        T3D = T3g - T3h;
        T3E = T3j - T3k;
        T40 = T3D + T3E;
        T1S = Tu + TF;
        T1T = TR + T12;
        T1U = T1S + T1T;
        T2e = T2c + T2d;
        T2j = T2f - T2i;
        T4p = T2j - T2e;
        T2T = T2c - T2d;
        T2U = T2i + T2f;
        T4e = T2T + T2U;
        T30 = T2r + T2u;
        T31 = T2w + T2z;
        T32 = T30 + T31;
        T2v = T2r - T2u;
        T2A = T2w - T2z;
        T2B = T2v + T2A;
    }

    // Final transforms and writes
    {
        E T3y, T1Q, T3x, T3G, T3I, T3C, T3F, T3H, T3z;
        T3y = KP559016994 * (T14 - T1P);
        T1Q = T14 + T1P;
        T3x = ((Tj) - ((KP250000000) * (T1Q)));
        T3C = T3A + T3B;
        T3F = T3D - T3E;
        T3G = ((KP951056516 * T3C) - ((KP587785252) * (T3F)));
        T3I = (((KP951056516) * (T3F)) + (KP587785252 * T3C));
        Rm[(rs[9])] = Tj + T1Q;
        T3H = T3y + T3x;
        Rm[(rs[5])] = T3H - T3I;
        Rp[(rs[6])] = T3H + T3I;
        T3z = T3x - T3y;
        Rp[(rs[2])] = T3z - T3G;
        Rm[(rs[1])] = T3z + T3G;
    }
    {
        E T47, T41, T46, T45, T49, T43, T44, T4a, T48;
        T47 = KP559016994 * (T40 + T3Z);
        T41 = T3Z - T40;
        T46 = (((KP250000000) * (T41)) + (T42));
        T43 = T13 - TG;
        T44 = T1r - T1O;
        T45 = (((KP587785252) * (T43)) + (KP951056516 * T44));
        T49 = ((KP951056516 * T43) - ((KP587785252) * (T44)));
        Im[(rs[9])] = T41 - T42;
        T4a = T47 + T46;
        Im[(rs[5])] = T49 - T4a;
        Ip[(rs[6])] = T49 + T4a;
        T48 = T46 - T47;
        Im[(rs[1])] = T45 - T48;
        Ip[(rs[2])] = T45 + T48;
    }
    {
        E T3d, T1Y, T3e, T3u, T3w, T3m, T3t, T3v, T3f;
        T3d = KP559016994 * (T1U - T1X);
        T1Y = T1U + T1X;
        T3e = ((T1R) - ((KP250000000) * (T1Y)));
        T3m = T3i - T3l;
        T3t = T3p - T3s;
        T3u = (((KP951056516) * (T3m)) + (KP587785252 * T3t));
        T3w = ((KP951056516 * T3t) - ((KP587785252) * (T3m)));
        Rp[0] = T1R + T1Y;
        T3v = T3e - T3d;
        Rm[(rs[7])] = T3v - T3w;
        Rp[(rs[8])] = T3v + T3w;
        T3f = T3d + T3e;
        Rp[(rs[4])] = T3f - T3u;
        Rm[(rs[3])] = T3f + T3u;
    }
    {
        E T3U, T3L, T3V, T3T, T3X, T3R, T3S, T3Y, T3W;
        T3U = KP559016994 * (T3J - T3K);
        T3L = T3J + T3K;
        T3V = ((T3Q) - ((KP250000000) * (T3L)));
        T3R = T1S - T1T;
        T3S = T1V - T1W;
        T3T = (((KP951056516) * (T3R)) + (KP587785252 * T3S));
        T3X = ((KP587785252 * T3R) - ((KP951056516) * (T3S)));
        Ip[0] = T3L + T3Q;
        T3Y = T3V - T3U;
        Im[(rs[7])] = T3X - T3Y;
        Ip[(rs[8])] = T3X + T3Y;
        T3W = T3U + T3V;
        Im[(rs[3])] = T3T - T3W;
        Ip[(rs[4])] = T3T + T3W;
    }
    {
        E T2P, T2N, T2O, T2l, T2R, T29, T2k, T2S, T2Q;
        T2P = KP559016994 * (T2B - T2M);
        T2N = T2B + T2M;
        T2O = ((T2q) - ((KP250000000) * (T2N)));
        T29 = T23 - T28;
        T2k = T2e + T2j;
        T2l = ((KP951056516 * T29) - ((KP587785252) * (T2k)));
        T2R = (((KP951056516) * (T2k)) + (KP587785252 * T29));
        Rm[(rs[4])] = T2q + T2N;
        T2S = T2P + T2O;
        Rm[(rs[8])] = T2R + T2S;
        Rm[0] = T2S - T2R;
        T2Q = T2O - T2P;
        Rp[(rs[3])] = T2l + T2Q;
        Rp[(rs[7])] = T2Q - T2l;
    }
    {
        E T4w, T4r, T4x, T4v, T4A, T4t, T4u, T4z, T4y;
        T4w = KP559016994 * (T4p + T4q);
        T4r = T4p - T4q;
        T4x = (((KP250000000) * (T4r)) + (T4s));
        T4t = T2v - T2A;
        T4u = T2G - T2L;
        T4v = (((KP951056516) * (T4t)) + (KP587785252 * T4u));
        T4A = ((KP951056516 * T4u) - ((KP587785252) * (T4t)));
        Im[(rs[4])] = T4r - T4s;
        T4z = T4w + T4x;
        Ip[(rs[3])] = T4z - T4A;
        Ip[(rs[7])] = T4A + T4z;
        T4y = T4w - T4x;
        Im[(rs[8])] = T4v + T4y;
        Im[0] = T4y - T4v;
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
        Rp[(rs[5])] = T37 + T38;
        T3c = T39 - T36;
        Rm[(rs[6])] = T3b + T3c;
        Rm[(rs[2])] = T3c - T3b;
        T3a = T36 + T39;
        Rp[(rs[1])] = T2Z + T3a;
        Rp[(rs[9])] = T3a - T2Z;
    }
    {
        E T4g, T4k, T4l, T4d, T4o, T4b, T4c, T4n, T4m;
        T4g = KP559016994 * (T4e - T4f);
        T4k = T4e + T4f;
        T4l = ((T4j) - ((KP250000000) * (T4k)));
        T4b = T33 - T34;
        T4c = T30 - T31;
        T4d = ((KP951056516 * T4b) - ((KP587785252) * (T4c)));
        T4o = (((KP951056516) * (T4c)) + (KP587785252 * T4b));
        Ip[(rs[5])] = T4k + T4j;
        T4n = T4g + T4l;
        Ip[(rs[1])] = T4n - T4o;
        Ip[(rs[9])] = T4o + T4n;
        T4m = T4g - T4l;
        Im[(rs[6])] = T4d + T4m;
        Im[(rs[2])] = T4m - T4d;
    }
}
}
