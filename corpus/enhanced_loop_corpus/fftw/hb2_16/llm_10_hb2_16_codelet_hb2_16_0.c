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
extern  E KP382683432;
extern  E KP923879532;
extern  E KP707106781;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb; m < me; m += 4) {
    INT idx = (m - mb) / 4;
    R *local_cr = cr + idx * 4 * ms;
    R *local_ci = ci - idx * 4 * ms;
    stride local_rs = rs + idx * fftw_an_INT_guaranteed_to_be_zero;
    const R *local_W = W + ((m - 1) * 8);

    for (INT inner = 0; inner < 4 && (m + inner) < me; inner++) {
        INT offset = inner * ms;
        const R *W_ptr = local_W + inner * 8;

        E Tv = W_ptr[0], Ty = W_ptr[1], T1l = W_ptr[2], T1n = W_ptr[3];
        E T1m = Tv * T1l, T1s = Ty * T1l, T1o = Ty * T1n, T1r = Tv * T1n;
        E T1p = T1m + T1o, T1t = T1r - T1s, T27 = T1r + T1s, T25 = T1m - T1o;
        E Tz = W_ptr[5], Tw = W_ptr[4];
        E TA = Ty * Tz, T1J = T1l * Tz, T15 = Tv * Tz, T1G = T1n * Tz;
        E Tx = Tv * Tw, T1K = T1n * Tw, T16 = Ty * Tw, T1F = T1l * Tw;
        E TB = Tx - TA, T21 = T1J + T1K, T1P = T15 - T16, T1H = T1F + T1G;
        E T1X = T1F - T1G, T17 = T15 + T16, T1L = T1J - T1K, T1N = Tx + TA;
        E T1v = W_ptr[6], T1w = W_ptr[7];
        E T1x = Tv * T1v + Ty * T1w, T1B = Tv * T1w - Ty * T1v;

        E T2D = T25 * Tz, T2E = T27 * Tw, T2F = T2D + T2E, T2T = T2D - T2E;
        E T29 = T25 * Tw, T2a = T27 * Tz, T2b = T29 - T2a, T2R = T29 + T2a;

        E T3h = T1p * Tz, T3i = T1t * Tw, T3j = T3h + T3i, T3x = T3h - T3i;
        E T33 = T1p * Tw, T34 = T1t * Tz, T35 = T33 - T34, T3t = T33 + T34;

        // Data access with offset
        E T1 = local_cr[inner*0], T2 = local_ci[local_rs[7] + offset];
        E T3 = T1 + T2, T2c = T1 - T2;
        E T1c = local_ci[local_rs[11] + offset], T1d = local_cr[local_rs[12] + offset];
        E T1e = T1c - T1d, T2d = T1c + T1d;

        E T4 = local_cr[local_rs[4] + offset], T5 = local_ci[local_rs[3] + offset];
        E T6 = T4 + T5, T2G = T4 - T5;
        E T19 = local_ci[local_rs[15] + offset], T1a = local_cr[local_rs[8] + offset];
        E T1b = T19 - T1a, T2H = T19 + T1a;

        E T7 = T3 + T6, T36 = T2c + T2d, T3k = T2H - T2G;
        E TC = T3 - T6, T1f = T1b - T1e, T2e = T2c - T2d;
        E T2I = T2G + T2H, T1Q = T1b + T1e;

        E T8 = local_cr[local_rs[2] + offset], T9 = local_ci[local_rs[5] + offset];
        E Ta = T8 + T9, T2f = T8 - T9;
        E TG = local_ci[local_rs[13] + offset], TH = local_cr[local_rs[10] + offset];
        E TI = TG - TH, T2g = TG + TH;

        E Tb = local_ci[local_rs[1] + offset], Tc = local_cr[local_rs[6] + offset];
        E Td = Tb + Tc, T2i = Tb - Tc;
        E TD = local_ci[local_rs[9] + offset], TE = local_cr[local_rs[14] + offset];
        E TF = TD - TE, T2j = TD + TE;

        E Te = Ta + Td, TJ = TF - TI, T1R = TI + TF, T18 = Ta - Td;

        E T2J = T2f + T2g, T2K = T2i + T2j;
        E T2L = KP707106781 * (T2J - T2K), T37 = KP707106781 * (T2J + T2K);
        E T2h = T2f - T2g, T2k = T2i - T2j;
        E T2l = KP707106781 * (T2h + T2k), T3l = KP707106781 * (T2h - T2k);

        E Tg = local_cr[local_rs[1] + offset], Th = local_ci[local_rs[6] + offset];
        E Ti = Tg + Th, T2x = Tg - Th;
        E TP = local_ci[local_rs[10] + offset], TQ = local_cr[local_rs[13] + offset];
        E TR = TP - TQ, T2y = TP + TQ;

        E Tj = local_cr[local_rs[5] + offset], Tk = local_ci[local_rs[2] + offset];
        E Tl = Tj + Tk, T2u = Tj - Tk;
        E TM = local_ci[local_rs[14] + offset], TN = local_cr[local_rs[9] + offset];
        E TO = TM - TN, T2v = TM + TN;

        E Tm = Ti + Tl, T1T = TO + TR, TL = Ti - Tl, TS = TO - TR;
        E TT = TL - TS, T1h = TL + TS;

        E T2w = T2u + T2v, T2z = T2x - T2y;
        E T2A = KP923879532 * T2w + KP382683432 * T2z;
        E T2N = KP923879532 * T2z - KP382683432 * T2w;
        E T39 = T2x + T2y, T3a = T2v - T2u;
        E T3b = KP382683432 * T39 - KP923879532 * T3a;
        E T3n = KP382683432 * T3a + KP923879532 * T39;

        E Tn = local_ci[offset], To = local_cr[local_rs[7] + offset];
        E Tp = Tn + To, T2q = Tn - To;
        E TY = local_ci[local_rs[12] + offset], TZ = local_cr[local_rs[11] + offset];
        E T10 = TY - TZ, T2r = TY + TZ;

        E Tq = local_cr[local_rs[3] + offset], Tr = local_ci[local_rs[4] + offset];
        E Ts = Tq + Tr, T2n = Tq - Tr;
        E TV = local_ci[local_rs[8] + offset], TW = local_cr[local_rs[15] + offset];
        E TX = TV - TW, T2o = TV + TW;

        E Tt = Tp + Ts, T1U = TX + T10, TU = Tp - Ts, T11 = TX - T10;
        E T12 = TU + T11, T1i = T11 - TU;

        E T2p = T2n - T2o, T2s = T2q - T2r;
        E T2t = KP923879532 * T2p - KP382683432 * T2s;
        E T2O = KP382683432 * T2p + KP923879532 * T2s;
        E T3c = T2q + T2r, T3d = T2n + T2o;
        E T3e = KP382683432 * T3c - KP923879532 * T3d;
        E T3o = KP382683432 * T3d + KP923879532 * T3c;

        E Tf = T7 + Te, Tu = Tm + Tt, T1O = Tf - Tu;
        E T1S = T1Q + T1R, T1V = T1T + T1U, T1W = T1S - T1V;

        local_cr[offset] = Tf + Tu;
        local_ci[offset] = T1S + T1V;
        local_cr[local_rs[8] + offset] = T1N * T1O - T1P * T1W;
        local_ci[local_rs[8] + offset] = T1P * T1O + T1N * T1W;

        E T38 = T36 - T37, T3f = T3b + T3e;
        E T3g = T38 - T3f, T3r = T38 + T3f;
        E T3m = T3k + T3l, T3p = T3n - T3o;
        E T3q = T3m - T3p, T3s = T3m + T3p;

        local_cr[local_rs[11] + offset] = T35 * T3g - T3j * T3q;
        local_ci[local_rs[11] + offset] = T3j * T3g + T35 * T3q;
        local_cr[local_rs[3] + offset] = T1l * T3r - T1n * T3s;
        local_ci[local_rs[3] + offset] = T1n * T3r + T1l * T3s;

        E T3u = T36 + T37, T3v = T3n + T3o;
        E T3w = T3u - T3v, T3B = T3u + T3v;
        E T3y = T3k - T3l, T3z = T3b - T3e;
        E T3A = T3y + T3z, T3C = T3y - T3z;

        local_cr[local_rs[7] + offset] = T3t * T3w - T3x * T3A;
        local_ci[local_rs[7] + offset] = T3t * T3A + T3x * T3w;
        local_cr[local_rs[15] + offset] = T1v * T3B - T1w * T3C;
        local_ci[local_rs[15] + offset] = T1v * T3C + T1w * T3B;

        E TK = TC + TJ, T13 = KP707106781 * (TT + T12);
        E T14 = TK - T13, T1q = TK + T13;
        E T1g = T18 + T1f, T1j = KP707106781 * (T1h + T1i);
        E T1k = T1g - T1j, T1u = T1g + T1j;

        local_cr[local_rs[10] + offset] = TB * T14 - T17 * T1k;
        local_ci[local_rs[10] + offset] = T17 * T14 + TB * T1k;
        local_cr[local_rs[2] + offset] = T1p * T1q - T1t * T1u;
        local_ci[local_rs[2] + offset] = T1t * T1q + T1p * T1u;

        E T1y = TC - TJ, T1z = KP707106781 * (T1i - T1h);
        E T1A = T1y - T1z, T1I = T1y + T1z;
        E T1C = T1f - T18, T1D = KP707106781 * (TT - T12);
        E T1E = T1C - T1D, T1M = T1C + T1D;

        local_cr[local_rs[14] + offset] = T1x * T1A - T1B * T1E;
        local_ci[local_rs[14] + offset] = T1x * T1E + T1B * T1A;
        local_cr[local_rs[6] + offset] = T1H * T1I - T1L * T1M;
        local_ci[local_rs[6] + offset] = T1H * T1M + T1L * T1I;

        E T2m = T2e - T2l, T2B = T2t - T2A;
        E T2C = T2m - T2B, T2S = T2m + T2B;
        E T2M = T2I - T2L, T2P = T2N - T2O;
        E T2Q = T2M - T2P, T2U = T2M + T2P;

        local_cr[local_rs[13] + offset] = T2b * T2C - T2F * T2Q;
        local_ci[local_rs[13] + offset] = T2F * T2C + T2b * T2Q;
        local_cr[local_rs[5] + offset] = T2R * T2S - T2T * T2U;
        local_ci[local_rs[5] + offset] = T2T * T2S + T2R * T2U;

        E T2V = T2e + T2l, T2W = T2N + T2O;
        E T2X = T2V - T2W, T31 = T2V + T2W;
        E T2Y = T2I + T2L, T2Z = T2A + T2t;
        E T30 = T2Y - T2Z, T32 = T2Y + T2Z;

        local_cr[local_rs[9] + offset] = Tw * T2X - Tz * T30;
        local_ci[local_rs[9] + offset] = Tw * T30 + Tz * T2X;
        local_cr[local_rs[1] + offset] = Tv * T31 - Ty * T32;
        local_ci[local_rs[1] + offset] = Tv * T32 + Ty * T31;

        E T1Y = T7 - Te, T1Z = T1U - T1T;
        E T20 = T1Y - T1Z, T26 = T1Y + T1Z;
        E T22 = T1Q - T1R, T23 = Tm - Tt;
        E T24 = T22 - T23, T28 = T23 + T22;

        local_cr[local_rs[12] + offset] = T1X * T20 - T21 * T24;
        local_ci[local_rs[12] + offset] = T1X * T24 + T21 * T20;
        local_cr[local_rs[4] + offset] = T25 * T26 - T27 * T28;
        local_ci[local_rs[4] + offset] = T25 * T28 + T27 * T26;
    }
}
}
