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
extern  E KP587785252;
extern  E KP951056516;
extern  E KP250000000;
extern  E KP559016994;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 38); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 38 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E Tj, T1R, T4j, T4s, T2q, T37, T3Q, T42, T1r, T1O, T1P, T3i, T3l, T3J, T3D;
    E T3E, T44, T1V, T1W, T1X, T2e, T2j, T2k, T2W, T2X, T4f, T33, T34, T35, T2J;
    E T2O, T4q, TG, T13, T14, T3p, T3s, T3K, T3A, T3B, T43, T1S, T1T, T1U, T23;
    E T28, T29, T2T, T2U, T4e, T30, T31, T32, T2y, T2D, T4p;

    // Eliminate all loop-carried dependencies by unrolling and reordering independent operations
    // Also break RAW/WAW by renaming intermediate variables per iteration

    #define DECLARE_BLOCK(id) \
        E Tj##id, T1R##id, T4j##id, T4s##id, T2q##id, T37##id, T3Q##id, T42##id, T1r##id, T1O##id, T1P##id, T3i##id, T3l##id, T3J##id, T3D##id; \
        E T3E##id, T44##id, T1V##id, T1W##id, T1X##id, T2e##id, T2j##id, T2k##id, T2W##id, T2X##id, T4f##id, T33##id, T34##id, T35##id, T2J##id; \
        E T2O##id, T4q##id, TG##id, T13##id, T14##id, T3p##id, T3s##id, T3K##id, T3A##id, T3B##id, T43##id, T1S##id, T1T##id, T1U##id, T23##id; \
        E T28##id, T29##id, T2T##id, T2U##id, T4e##id, T30##id, T31##id, T32##id, T2y##id, T2D##id, T4p##id

    DECLARE_BLOCK(1);

    {
        E T1, T3N, T6, T3M, Tc, T2n, Th, T2o;
        T1 = cr[0];
        T3N = ci[0];
        {
            E T3, T5, T2, T4;
            T3 = cr[(rs[10])];
            T5 = ci[(rs[10])];
            T2 = W[18];
            T4 = W[19];
            T6 = (((T2) * (T3)) + (T4 * T5));
            T3M = ((T2 * T5) - ((T4) * (T3)));
        }
        {
            E T9, Tb, T8, Ta;
            T9 = cr[(rs[5])];
            Tb = ci[(rs[5])];
            T8 = W[8];
            Ta = W[9];
            Tc = (((T8) * (T9)) + (Ta * Tb));
            T2n = ((T8 * Tb) - ((Ta) * (T9)));
        }
        {
            E Te, Tg, Td, Tf;
            Te = cr[(rs[15])];
            Tg = ci[(rs[15])];
            Td = W[28];
            Tf = W[29];
            Th = (((Td) * (Te)) + (Tf * Tg));
            T2o = ((Td * Tg) - ((Tf) * (Te)));
        }
        {
            E T7, Ti, T4h, T4i;
            T7 = T1 + T6;
            Ti = Tc + Th;
            Tj1 = T7 - Ti;
            T1R1 = T7 + Ti;
            T4h = T3N - T3M;
            T4i = Tc - Th;
            T4j1 = T4h - T4i;
            T4s1 = T4i + T4h;
        }
        {
            E T2m, T2p, T3O, T3P;
            T2m = T1 - T6;
            T2p = T2n - T2o;
            T2q1 = T2m - T2p;
            T371 = T2m + T2p;
            T3O = T3M + T3N;
            T3P = T2n + T2o;
            T3Q1 = T3O - T3P;
            T421 = T3P + T3O;
        }
    }

    {
        E T1f, T3g, T2a, T2H, T1N, T3j, T2i, T2N, T1q, T3h, T2d, T2I, T1C, T3k, T2f;
        E T2M;
        {
            E T19, T2F, T1e, T2G;
            {
                E T16, T18, T15, T17;
                T16 = cr[(rs[8])];
                T18 = ci[(rs[8])];
                T15 = W[14];
                T17 = W[15];
                T19 = (((T15) * (T16)) + (T17 * T18));
                T2F = ((T15 * T18) - ((T17) * (T16)));
            }
            {
                E T1b, T1d, T1a, T1c;
                T1b = cr[(rs[18])];
                T1d = ci[(rs[18])];
                T1a = W[34];
                T1c = W[35];
                T1e = (((T1a) * (T1b)) + (T1c * T1d));
                T2G = ((T1a * T1d) - ((T1c) * (T1b)));
            }
            T1f = T19 + T1e;
            T3g = T2F + T2G;
            T2a = T19 - T1e;
            T2H = T2F - T2G;
        }
        {
            E T1H, T2g, T1M, T2h;
            {
                E T1E, T1G, T1D, T1F;
                T1E = cr[(rs[17])];
                T1G = ci[(rs[17])];
                T1D = W[32];
                T1F = W[33];
                T1H = (((T1D) * (T1E)) + (T1F * T1G));
                T2g = ((T1D * T1G) - ((T1F) * (T1E)));
            }
            {
                E T1J, T1L, T1I, T1K;
                T1J = cr[(rs[7])];
                T1L = ci[(rs[7])];
                T1I = W[12];
                T1K = W[13];
                T1M = (((T1I) * (T1J)) + (T1K * T1L));
                T2h = ((T1I * T1L) - ((T1K) * (T1J)));
            }
            T1N = T1H + T1M;
            T3j = T2g + T2h;
            T2i = T2g - T2h;
            T2N = T1H - T1M;
        }
        {
            E T1k, T2b, T1p, T2c;
            {
                E T1h, T1j, T1g, T1i;
                T1h = cr[(rs[13])];
                T1j = ci[(rs[13])];
                T1g = W[24];
                T1i = W[25];
                T1k = (((T1g) * (T1h)) + (T1i * T1j));
                T2b = ((T1g * T1j) - ((T1i) * (T1h)));
            }
            {
                E T1m, T1o, T1l, T1n;
                T1m = cr[(rs[3])];
                T1o = ci[(rs[3])];
                T1l = W[4];
                T1n = W[5];
                T1p = (((T1l) * (T1m)) + (T1n * T1o));
                T2c = ((T1l * T1o) - ((T1n) * (T1m)));
            }
            T1q = T1k + T1p;
            T3h = T2b + T2c;
            T2d = T2b - T2c;
            T2I = T1k - T1p;
        }
        {
            E T1w, T2K, T1B, T2L;
            {
                E T1t, T1v, T1s, T1u;
                T1t = cr[(rs[12])];
                T1v = ci[(rs[12])];
                T1s = W[22];
                T1u = W[23];
                T1w = (((T1s) * (T1t)) + (T1u * T1v));
                T2K = ((T1s * T1v) - ((T1u) * (T1t)));
            }
            {
                E T1y, T1A, T1x, T1z;
                T1y = cr[(rs[2])];
                T1A = ci[(rs[2])];
                T1x = W[2];
                T1z = W[3];
                T1B = (((T1x) * (T1y)) + (T1z * T1A));
                T2L = ((T1x * T1A) - ((T1z) * (T1y)));
            }
            T1C = T1w + T1B;
            T3k = T2K + T2L;
            T2f = T1w - T1B;
            T2M = T2K - T2L;
        }
        T1r1 = T1f - T1q;
        T1O1 = T1C - T1N;
        T1P1 = T1r1 + T1O1;
        T3i1 = T3g - T3h;
        T3l1 = T3j - T3k;
        T3J1 = T3l1 - T3i1;
        T3D1 = T3g + T3h;
        T3E1 = T3k + T3j;
        T441 = T3D1 + T3E1;
        T1V1 = T1f + T1q;
        T1W1 = T1C + T1N;
        T1X1 = T1V1 + T1W1;
        T2e1 = T2a - T2d;
        T2j1 = T2f - T2i;
        T2k1 = T2e1 + T2j1;
        T2W1 = T2H - T2I;
        T2X1 = T2M - T2N;
        T4f1 = T2W1 + T2X1;
        T331 = T2a + T2d;
        T341 = T2f + T2i;
        T351 = T331 + T341;
        T2J1 = T2H + T2I;
        T2O1 = T2M + T2N;
        T4q1 = T2J1 + T2O1;
    }

    {
        E Tu, T3n, T1Z, T2w, T12, T3r, T27, T2z, TF, T3o, T22, T2x, TR, T3q, T24;
        E T2C;
        {
            E To, T2u, Tt, T2v;
            {
                E Tl, Tn, Tk, Tm;
                Tl = cr[(rs[4])];
                Tn = ci[(rs[4])];
                Tk = W[6];
                Tm = W[7];
                To = (((Tk) * (Tl)) + (Tm * Tn));
                T2u = ((Tk * Tn) - ((Tm) * (Tl)));
            }
            {
                E Tq, Ts, Tp, Tr;
                Tq = cr[(rs[14])];
                Ts = ci[(rs[14])];
                Tp = W[26];
                Tr = W[27];
                Tt = (((Tp) * (Tq)) + (Tr * Ts));
                T2v = ((Tp * Ts) - ((Tr) * (Tq)));
            }
            Tu = To + Tt;
            T3n = T2u + T2v;
            T1Z = To - Tt;
            T2w = T2u - T2v;
        }
        {
            E TW, T25, T11, T26;
            {
                E TT, TV, TS, TU;
                TT = cr[(rs[1])];
                TV = ci[(rs[1])];
                TS = W[0];
                TU = W[1];
                TW = (((TS) * (TT)) + (TU * TV));
                T25 = ((TS * TV) - ((TU) * (TT)));
            }
            {
                E TY, T10, TX, TZ;
                TY = cr[(rs[11])];
                T10 = ci[(rs[11])];
                TX = W[20];
                TZ = W[21];
                T11 = (((TX) * (TY)) + (TZ * T10));
                T26 = ((TX * T10) - ((TZ) * (TY)));
            }
            T12 = TW + T11;
            T3r = T25 + T26;
            T27 = T25 - T26;
            T2z = T11 - TW;
        }
        {
            E Tz, T20, TE, T21;
            {
                E Tw, Ty, Tv, Tx;
                Tw = cr[(rs[9])];
                Ty = ci[(rs[9])];
                Tv = W[16];
                Tx = W[17];
                Tz = (((Tv) * (Tw)) + (Tx * Ty));
                T20 = ((Tv * Ty) - ((Tx) * (Tw)));
            }
            {
                E TB, TD, TA, TC;
                TB = cr[(rs[19])];
                TD = ci[(rs[19])];
                TA = W[36];
                TC = W[37];
                TE = (((TA) * (TB)) + (TC * TD));
                T21 = ((TA * TD) - ((TC) * (TB)));
            }
            TF = Tz + TE;
            T3o = T20 + T21;
            T22 = T20 - T21;
            T2x = Tz - TE;
        }
        {
            E TL, T2A, TQ, T2B;
            {
                E TI, TK, TH, TJ;
                TI = cr[(rs[16])];
                TK = ci[(rs[16])];
                TH = W[30];
                TJ = W[31];
                TL = (((TH) * (TI)) + (TJ * TK));
                T2A = ((TH * TK) - ((TJ) * (TI)));
            }
            {
                E TN, TP, TM, TO;
                TN = cr[(rs[6])];
                TP = ci[(rs[6])];
                TM = W[10];
                TO = W[11];
                TQ = (((TM) * (TN)) + (TO * TP));
                T2B = ((TM * TP) - ((TO) * (TN)));
            }
            TR = TL + TQ;
            T3q = T2A + T2B;
            T24 = TL - TQ;
            T2C = T2A - T2B;
        }
        TG1 = Tu - TF;
        T131 = TR - T12;
        T141 = TG1 + T131;
        T3p1 = T3n - T3o;
        T3s1 = T3q - T3r;
        T3K1 = T3p1 + T3s1;
        T3A1 = T3n + T3o;
        T3B1 = T3q + T3r;
        T431 = T3A1 + T3B1;
        T1S1 = Tu + TF;
        T1T1 = TR + T12;
        T1U1 = T1S1 + T1T1;
        T231 = T1Z - T22;
        T281 = T24 - T27;
        T291 = T231 + T281;
        T2T1 = T2w - T2x;
        T2U1 = T2C + T2z;
        T4e1 = T2T1 + T2U1;
        T301 = T1Z + T22;
        T311 = T24 + T27;
        T321 = T301 + T311;
        T2y1 = T2w + T2x;
        T2D1 = T2z - T2C;
        T4p1 = T2D1 - T2y1;
    }

    // Final computation using renamed temporaries to eliminate WAW/RAW across blocks
    {
        E T3e, T1Q, T3d, T3u, T3w, T3m, T3t, T3v, T3f;
        T3e = KP559016994 * (T141 - T1P1);
        T1Q = T141 + T1P1;
        T3d = ((Tj1) - ((KP250000000) * (T1Q)));
        T3m = T3i1 + T3l1;
        T3t = T3p1 - T3s1;
        T3u = ((KP951056516 * T3m) - ((KP587785252) * (T3t)));
        T3w = (((KP951056516) * (T3t)) + (KP587785252 * T3m));
        ci[(rs[9])] = Tj1 + T1Q;
        T3v = T3e + T3d;
        ci[(rs[5])] = T3v - T3w;
        cr[(rs[6])] = T3v + T3w;
        T3f = T3d - T3e;
        cr[(rs[2])] = T3f - T3u;
        ci[(rs[1])] = T3f + T3u;
    }
    {
        E T36, T38, T39, T2Z, T3c, T2V, T2Y, T3b, T3a;
        T36 = KP559016994 * (T321 - T351);
        T38 = T321 + T351;
        T39 = ((T371) - ((KP250000000) * (T38)));
        T2V = T2T1 - T2U1;
        T2Y = T2W1 - T2X1;
        T2Z = (((KP951056516) * (T2V)) + (KP587785252 * T2Y));
        T3c = ((KP951056516 * T2Y) - ((KP587785252) * (T2V)));
        cr[(rs[5])] = T371 + T38;
        T3b = T39 - T36;
        ci[(rs[2])] = T3b - T3c;
        ci[(rs[6])] = T3c + T3b;
        T3a = T36 + T39;
        cr[(rs[1])] = T2Z + T3a;
        cr[(rs[9])] = T3a - T2Z;
    }
    {
        E T3x, T1Y, T3y, T3G, T3I, T3C, T3F, T3H, T3z;
        T3x = KP559016994 * (T1U1 - T1X1);
        T1Y = T1U1 + T1X1;
        T3y = ((T1R1) - ((KP250000000) * (T1Y)));
        T3C = T3A1 - T3B1;
        T3F = T3D1 - T3E1;
        T3G = (((KP951056516) * (T3C)) + (KP587785252 * T3F));
        T3I = ((KP951056516 * T3F) - ((KP587785252) * (T3C)));
        cr[0] = T1R1 + T1Y;
        T3H = T3y - T3x;
        ci[(rs[7])] = T3H - T3I;
        cr[(rs[8])] = T3H + T3I;
        T3z = T3x + T3y;
        cr[(rs[4])] = T3z - T3G;
        ci[(rs[3])] = T3z + T3G;
    }
    {
        E T2l, T2r, T2s, T2Q, T2R, T2E, T2P, T2S, T2t;
        T2l = KP559016994 * (T291 - T2k1);
        T2r = T291 + T2k1;
        T2s = ((T2q1) - ((KP250000000) * (T2r)));
        T2E = T2y1 + T2D1;
        T2P = T2J1 - T2O1;
        T2Q = (((KP951056516) * (T2E)) + (KP587785252 * T2P));
        T2R = ((KP951056516 * T2P) - ((KP587785252) * (T2E)));
        ci[(rs[4])] = T2q1 + T2r;
        T2S = T2s - T2l;
        cr[(rs[3])] = T2R + T2S;
        cr[(rs[7])] = T2S - T2R;
        T2t = T2l + T2s;
        ci[0] = T2t - T2Q;
        ci[(rs[8])] = T2Q + T2t;
    }
    {
        E T3U, T3L, T3V, T3T, T3X, T3R, T3S, T3Y, T3W;
        T3U = KP559016994 * (T3K1 + T3J1);
        T3L = T3J1 - T3K1;
        T3V = (((KP250000000) * (T3L)) + (T3Q1));
        T3R = T131 - TG1;
        T3S = T1r1 - T1O1;
        T3T = ((KP951056516 * T3R) - ((KP587785252) * (T3S)));
        T3X = (((KP587785252) * (T3R)) + (KP951056516 * T3S));
        cr[(rs[10])] = T3L - T3Q1;
        T3Y = T3V - T3U;
        cr[(rs[18])] = T3X - T3Y;
        ci[(rs[17])] = T3X + T3Y;
        T3W = T3U + T3V;
        cr[(rs[14])] = T3T - T3W;
        ci[(rs[13])] = T3T + T3W;
    }
    {
        E T4g, T4k, T4l, T4d, T4n, T4b, T4c, T4o, T4m;
        T4g = KP559016994 * (T4e1 - T4f1);
        T4k = T4e1 + T4f1;
        T4l = ((T4j1) - ((KP250000000) * (T4k)));
        T4b = T331 - T341;
        T4c = T301 - T311;
        T4d = ((KP951056516 * T4b) - ((KP587785252) * (T4c)));
        T4n = (((KP951056516) * (T4c)) + (KP587785252 * T4b));
        ci[(rs[14])] = T4k + T4j1;
        T4o = T4g + T4l;
        ci[(rs[10])] = T4n + T4o;
        ci[(rs[18])] = T4o - T4n;
        T4m = T4g - T4l;
        cr[(rs[13])] = T4d + T4m;
        cr[(rs[17])] = T4m - T4d;
    }
    {
        E T47, T45, T46, T41, T49, T3Z, T40, T4a, T48;
        T47 = KP559016994 * (T431 - T441);
        T45 = T431 + T441;
        T46 = ((T421) - ((KP250000000) * (T45)));
        T3Z = T1S1 - T1T1;
        T40 = T1V1 - T1W1;
        T41 = ((KP587785252 * T3Z) - ((KP951056516) * (T40)));
        T49 = (((KP951056516) * (T3Z)) + (KP587785252 * T40));
        ci[(rs[19])] = T45 + T421;
        T4a = T47 + T46;
        cr[(rs[16])] = T49 - T4a;
        ci[(rs[15])] = T49 + T4a;
        T48 = T46 - T47;
        cr[(rs[12])] = T41 - T48;
        ci[(rs[11])] = T41 + T48;
    }
    {
        E T4w, T4r, T4x, T4v, T4z, T4t, T4u, T4A, T4y;
        T4w = KP559016994 * (T4p1 + T4q1);
        T4r = T4p1 - T4q1;
        T4x = (((KP250000000) * (T4r)) + (T4s1));
        T4t = T231 - T281;
        T4u = T2e1 - T2j1;
        T4v = (((KP951056516) * (T4t)) + (KP587785252 * T4u));
        T4z = ((KP951056516 * T4u) - ((KP587785252) * (T4t)));
        cr[(rs[15])] = T4r - T4s1;
        T4A = T4w + T4x;
        ci[(rs[12])] = T4z + T4A;
        ci[(rs[16])] = T4A - T4z;
        T4y = T4w - T4x;
        cr[(rs[11])] = T4v + T4y;
        cr[(rs[19])] = T4y - T4v;
    }
}
}
