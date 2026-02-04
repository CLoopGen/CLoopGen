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
extern  E KP382683432;
extern  E KP923879532;
extern  E KP707106781;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
INT idx_r = mb * ms;
INT idx_i = mb * ms;
INT idx_w = (mb - 1) * 8;
for (m = mb; m < me; m++) {
    E Tv, Ty, T1l, T1n, T1p, T1t, T27, T25, Tz, Tw, TB, T21, T1P, T1H, T1X;
    E T17, T1L, T1N, T1v, T1w, T1x, T1B, T2F, T2T, T2b, T2R, T3j, T3x, T35, T3t;
    {
        E TA, T1J, T15, T1G, Tx, T1K, T16, T1F;
        {
            E T1m, T1s, T1o, T1r;
            Tv = W[idx_w + 0];
            Ty = W[idx_w + 1];
            T1l = W[idx_w + 2];
            T1n = W[idx_w + 3];
            T1m = Tv * T1l;
            T1s = Ty * T1l;
            T1o = Ty * T1n;
            T1r = Tv * T1n;
            T1p = T1m + T1o;
            T1t = T1r - T1s;
            T27 = T1r + T1s;
            T25 = T1m - T1o;
            Tz = W[idx_w + 5];
            TA = Ty * Tz;
            T1J = T1l * Tz;
            T15 = Tv * Tz;
            T1G = T1n * Tz;
            Tw = W[idx_w + 4];
            Tx = Tv * Tw;
            T1K = T1n * Tw;
            T16 = Ty * Tw;
            T1F = T1l * Tw;
        }
        TB = Tx - TA;
        T21 = T1J + T1K;
        T1P = T15 - T16;
        T1H = T1F + T1G;
        T1X = T1F - T1G;
        T17 = T15 + T16;
        T1L = T1J - T1K;
        T1N = Tx + TA;
        T1v = W[idx_w + 6];
        T1w = W[idx_w + 7];
        T1x = Tv * T1v + Ty * T1w;
        T1B = Tv * T1w - Ty * T1v;
        {
            E T2D, T2E, T29, T2a;
            T2D = T25 * Tz;
            T2E = T27 * Tw;
            T2F = T2D + T2E;
            T2T = T2D - T2E;
            T29 = T25 * Tw;
            T2a = T27 * Tz;
            T2b = T29 - T2a;
            T2R = T29 + T2a;
        }
        {
            E T3h, T3i, T33, T34;
            T3h = T1p * Tz;
            T3i = T1t * Tw;
            T3j = T3h + T3i;
            T3x = T3h - T3i;
            T33 = T1p * Tw;
            T34 = T1t * Tz;
            T35 = T33 - T34;
            T3t = T33 + T34;
        }
    }

    INT r_offsets[8] = {0, rs[1], rs[2], rs[3], rs[4], rs[5], rs[6], rs[7]};
    INT i_offsets[8] = {0, rs[7], rs[6], rs[5], rs[4], rs[3], rs[2], rs[1]};

    E temp_Rp[8], temp_Rm[8], temp_Ip[8], temp_Im[8];
    for (INT k = 0; k < 8; k++) {
        temp_Rp[k] = Rp[idx_r + r_offsets[k]];
        temp_Rm[k] = Rm[idx_r - r_offsets[k]];
        temp_Ip[k] = Ip[idx_i + r_offsets[k]];
        temp_Im[k] = Im[idx_i - r_offsets[k]];
    }

    {
        E T7, T36, T3k, TC, T1f, T2e, T2I, T1Q, Te, TJ, T1R, T18, T2L, T37, T2l;
        E T3l, Tm, T1T, TT, T1h, T2A, T2N, T3b, T3n, Tt, T1U, T12, T1i, T2t, T2O;
        E T3e, T3o;

        T7 = temp_Rp[0] + temp_Rp[4];
        T36 = (temp_Rp[0] - temp_Rp[4]) + (temp_Ip[0] + temp_Ip[4]);
        T3k = (temp_Ip[0] - temp_Ip[4]) - (temp_Rp[0] - temp_Rp[4]);
        TC = temp_Rp[0] - temp_Rp[4];
        T1f = (temp_Ip[0] - temp_Ip[4]) - (temp_Im[4] - temp_Im[0]);
        T2e = (temp_Rp[0] - temp_Rp[4]) - (temp_Ip[0] + temp_Ip[4]);
        T2I = (temp_Rp[4] - temp_Rp[0]) + (temp_Ip[0] + temp_Ip[4]);
        T1Q = (temp_Ip[0] - temp_Ip[4]) + (temp_Im[4] - temp_Im[0]);

        Te = temp_Rp[2] + temp_Rp[6];
        TJ = (temp_Ip[6] - temp_Ip[2]) - (temp_Im[2] - temp_Im[6]);
        T1R = (temp_Ip[6] - temp_Ip[2]) + (temp_Im[2] - temp_Im[6]);
        T18 = temp_Rp[2] - temp_Rp[6];

        Tm = temp_Rp[1] + temp_Rp[5];
        T1T = (temp_Ip[1] - temp_Ip[5]) + (temp_Im[5] - temp_Im[1]);
        TT = (temp_Rp[1] - temp_Rp[5]) - (temp_Ip[5] - temp_Ip[1]);
        T1h = (temp_Rp[1] - temp_Rp[5]) + (temp_Ip[5] - temp_Ip[1]);

        Tt = temp_Rp[7] + temp_Rp[3];
        T1U = (temp_Ip[7] - temp_Ip[3]) + (temp_Im[3] - temp_Im[7]);
        T12 = (temp_Rp[7] - temp_Rp[3]) + (temp_Ip[3] - temp_Ip[7]);
        T1i = (temp_Ip[3] - temp_Ip[7]) - (temp_Rp[7] - temp_Rp[3]);

        {
            E T2J = (temp_Rp[2] - temp_Rp[6]) + (temp_Ip[2] + temp_Ip[6]);
            E T2K = (temp_Rp[6] - temp_Rp[2]) + (temp_Ip[6] + temp_Ip[2]);
            T2L = KP707106781 * (T2J - T2K);
            T37 = KP707106781 * (T2J + T2K);

            E T2h = (temp_Rp[2] - temp_Rp[6]) - (temp_Ip[2] + temp_Ip[6]);
            E T2k = (temp_Rp[6] - temp_Rp[2]) - (temp_Ip[6] + temp_Ip[2]);
            T2l = KP707106781 * (T2h + T2k);
            T3l = KP707106781 * (T2h - T2k);
        }

        {
            E T2w = (temp_Rp[5] - temp_Rp[1]) + (temp_Ip[1] + temp_Ip[5]);
            E T2z = (temp_Rp[1] - temp_Rp[5]) - (temp_Ip[5] + temp_Ip[1]);
            T2A = KP923879532 * T2w + KP382683432 * T2z;
            T2N = KP923879532 * T2z - KP382683432 * T2w;

            E T39 = (temp_Rp[1] - temp_Rp[5]) + (temp_Ip[5] + temp_Ip[1]);
            E T3a = (temp_Ip[1] - temp_Ip[5]) - (temp_Rp[5] - temp_Rp[1]);
            T3b = KP382683432 * T39 - KP923879532 * T3a;
            T3n = KP382683432 * T3a + KP923879532 * T39;
        }

        {
            E T2p = (temp_Rp[3] - temp_Rp[7]) - (temp_Ip[7] + temp_Ip[3]);
            E T2s = (temp_Rp[7] - temp_Rp[3]) - (temp_Ip[3] + temp_Ip[7]);
            T2t = KP923879532 * T2p - KP382683432 * T2s;
            T2O = KP382683432 * T2p + KP923879532 * T2s;

            E T3c = (temp_Rp[7] - temp_Rp[3]) + (temp_Ip[3] + temp_Ip[7]);
            E T3d = (temp_Rp[3] - temp_Rp[7]) + (temp_Ip[7] + temp_Ip[3]);
            T3e = KP382683432 * T3c - KP923879532 * T3d;
            T3o = KP382683432 * T3d + KP923879532 * T3c;
        }

        E Tf = T7 + Te;
        E Tu = Tm + Tt;
        E T1O = Tf - Tu;
        E T1S = T1Q + T1R;
        E T1V = T1T + T1U;
        E T1W = T1S - T1V;

        Rp[idx_r] = Tf + Tu;
        Rm[idx_r] = T1S + T1V;
        Rp[idx_r + rs[4]] = T1N * T1O - T1P * T1W;
        Rm[idx_r + rs[4]] = T1P * T1O + T1N * T1W;

        E T38 = T36 - T37;
        E T3f = T3b + T3e;
        E T3g = T38 - T3f;
        E T3r = T38 + T3f;
        E T3m = T3k + T3l;
        E T3p = T3n - T3o;
        E T3q = T3m - T3p;
        E T3s = T3m + T3p;

        Ip[idx_i + rs[5]] = T35 * T3g - T3j * T3q;
        Im[idx_i + rs[5]] = T3j * T3g + T35 * T3q;
        Ip[idx_i + rs[1]] = T1l * T3r - T1n * T3s;
        Im[idx_i + rs[1]] = T1n * T3r + T1l * T3s;

        E T3u = T36 + T37;
        E T3v = T3n + T3o;
        E T3w = T3u - T3v;
        E T3B = T3u + T3v;
        E T3y = T3k - T3l;
        E T3z = T3b - T3e;
        E T3A = T3y + T3z;
        E T3C = T3y - T3z;

        Ip[idx_i + rs[3]] = T3t * T3w - T3x * T3A;
        Im[idx_i + rs[3]] = T3t * T3A + T3x * T3w;
        Ip[idx_i + rs[7]] = T1v * T3B - T1w * T3C;
        Im[idx_i + rs[7]] = T1v * T3C + T1w * T3B;

        E TK = TC + TJ;
        E T13 = KP707106781 * (TT + T12);
        E T14 = TK - T13;
        E T1q = TK + T13;
        E T1g = T18 + T1f;
        E T1j = KP707106781 * (T1h + T1i);
        E T1k = T1g - T1j;
        E T1u = T1g + T1j;

        Rp[idx_r + rs[5]] = TB * T14 - T17 * T1k;
        Rm[idx_r + rs[5]] = T17 * T14 + TB * T1k;
        Rp[idx_r + rs[1]] = T1p * T1q - T1t * T1u;
        Rm[idx_r + rs[1]] = T1t * T1q + T1p * T1u;

        E T1y = TC - TJ;
        E T1z = KP707106781 * (T1i - T1h);
        E T1A = T1y - T1z;
        E T1I = T1y + T1z;
        E T1C = T1f - T18;
        E T1D = KP707106781 * (TT - T12);
        E T1E = T1C - T1D;
        E T1M = T1C + T1D;

        Rp[idx_r + rs[7]] = T1x * T1A - T1B * T1E;
        Rm[idx_r + rs[7]] = T1x * T1E + T1B * T1A;
        Rp[idx_r + rs[3]] = T1H * T1I - T1L * T1M;
        Rm[idx_r + rs[3]] = T1H * T1M + T1L * T1I;

        E T2m = T2e - T2l;
        E T2B = T2t - T2A;
        E T2C = T2m - T2B;
        E T2S = T2m + T2B;
        E T2M = T2I - T2L;
        E T2P = T2N - T2O;
        E T2Q = T2M - T2P;
        E T2U = T2M + T2P;

        Ip[idx_i + rs[6]] = T2b * T2C - T2F * T2Q;
        Im[idx_i + rs[6]] = T2F * T2C + T2b * T2Q;
        Ip[idx_i + rs[2]] = T2R * T2S - T2T * T2U;
        Im[idx_i + rs[2]] = T2T * T2S + T2R * T2U;

        E T2V = T2e + T2l;
        E T2W = T2N + T2O;
        E T2X = T2V - T2W;
        E T31 = T2V + T2W;
        E T2Y = T2I + T2L;
        E T2Z = T2A + T2t;
        E T30 = T2Y - T2Z;
        E T32 = T2Y + T2Z;

        Ip[idx_i + rs[4]] = Tw * T2X - Tz * T30;
        Im[idx_i + rs[4]] = Tw * T30 + Tz * T2X;
        Ip[idx_i] = Tv * T31 - Ty * T32;
        Im[idx_i] = Tv * T32 + Ty * T31;

        E T1Y = T7 - Te;
        E T1Z = T1U - T1T;
        E T20 = T1Y - T1Z;
        E T26 = T1Y + T1Z;
        E T22 = T1Q - T1R;
        E T23 = Tm - Tt;
        E T24 = T22 - T23;
        E T28 = T23 + T22;

        Rp[idx_r + rs[6]] = T1X * T20 - T21 * T24;
        Rm[idx_r + rs[6]] = T1X * T24 + T21 * T20;
        Rp[idx_r + rs[2]] = T25 * T26 - T27 * T28;
        Rm[idx_r + rs[2]] = T25 * T28 + T27 * T26;
    }

    idx_r += ms;
    idx_i += ms;
    idx_w += 8;
}
}
