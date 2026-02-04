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
for (m = mb; m < me; m += 2, Rp = Rp + (ms << 1), Ip = Ip + (ms << 1), Rm = Rm - (ms << 1), Im = Im - (ms << 1), W = W + 16, (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    if (m + 1 >= me) break;

    for (int unroll_idx = 0; unroll_idx < 2; ++unroll_idx) {
        INT offset = unroll_idx * ms;
        R *rp = Rp + offset;
        R *ip = Ip + offset;
        R *rm = Rm - offset;
        R *im = Im - offset;
        R *w = W + (unroll_idx << 3);

        E T2 = w[0], T5 = w[1], Tg = w[2], Ti = w[3];
        E Th = T2 * Tg, Tn = T5 * Tg, Tj = T5 * Ti, Tm = T2 * Ti;
        E Tk = Th - Tj, To = Tm + Tn, T1h = Tm - Tn, T1f = Th + Tj;
        E T6 = w[5], T3 = w[4], Tx = w[6], Ty = w[7];

        E T7 = T5 * T6, T16 = Tg * T6, Ta = T2 * T6, T13 = Ti * T6;
        E T4 = T2 * T3, T17 = Ti * T3, Tb = T5 * T3, T12 = Tg * T3;
        E T8 = T4 - T7, T14 = T12 + T13, T1Q = T16 + T17, Tc = Ta + Tb;
        E T1O = T12 - T13, T1v = Ta - Tb, T18 = T16 - T17, T1t = T4 + T7;

        E T1l = T1f * T6, T1m = T1h * T3, T1n = T1l + T1m, T24 = T1l - T1m;
        E T1g = T1f * T3, T1i = T1h * T6, T1j = T1g - T1i, T22 = T1g + T1i;

        E Tl = Tk * T3, Tp = To * T6, Tq = Tl + Tp, Ts = Tk * T6, Tt = To * T3, Tu = Ts - Tt;
        E T1E = Tl - Tp, T1G = Ts + Tt;
        E Tz = Tk * Tx + To * Ty, TJ = Tq * Tx + Tu * Ty;
        E T1Z = T1f * Ty - T1h * Tx, TB = Tk * Ty - To * Tx;
        E T1X = T1f * Tx + T1h * Ty, T1A = T2 * Ty - T5 * Tx;
        E TZ = Tg * Ty - Ti * Tx, TL = Tq * Ty - Tu * Tx;
        E T1y = T2 * Tx + T5 * Ty, TX = Tg * Tx + Ti * Ty;

        E T1 = rp[0], T48 = rm[0];
        E T9 = rp[rs[5]], Td = rm[rs[5]];
        E Te = T8 * T9 + Tc * Td, T47 = T8 * Td - Tc * T9;

        E Tr = ip[rs[2]], Tv = im[rs[2]];
        E Tw = Tq * Tr + Tu * Tv, T2H = Tq * Tv - Tu * Tr;
        E TA = ip[rs[7]], TC = im[rs[7]];
        E TD = Tz * TA + TB * TC, T2I = Tz * TC - TB * TA;

        E Tf = T1 + Te, TE = Tw + TD;
        E TF = Tf - TE, T2b = Tf + TE;
        E T4B = T48 - T47, T4C = Tw - TD;
        E T4D = T4B - T4C, T4M = T4C + T4B;

        E T2G = T1 - Te, T2J = T2H - T2I;
        E T2K = T2G - T2J, T3r = T2G + T2J;
        E T46 = T2H + T2I, T49 = T47 + T48;
        E T4a = T46 + T49, T4m = T49 - T46;

        E T1x = T1t * rp[rs[4]] + T1v * rm[rs[4]];
        E T2j = T1t * rm[rs[4]] - T1v * rp[rs[4]];
        E T1C = T1y * rp[rs[9]] + T1A * rm[rs[9]];
        E T2k = T1y * rm[rs[9]] - T1A * rp[rs[9]];
        E T1D = T1x + T1C, T3H = T2j + T2k;
        E T2l = T2j - T2k, T2W = T1x - T1C;

        E T21 = T1X * ip[rs[8]] + T1Z * im[rs[8]];
        E T32 = T1X * im[rs[8]] - T1Z * ip[rs[8]];
        E T26 = T22 * ip[rs[3]] + T24 * im[rs[3]];
        E T33 = T22 * im[rs[3]] - T24 * ip[rs[3]];
        E T27 = T21 + T26, T3L = T32 + T33;
        E T2r = T21 - T26, T34 = T32 - T33;

        E T1I = T1E * ip[rs[6]] + T1G * im[rs[6]];
        E T2X = T1E * im[rs[6]] - T1G * ip[rs[6]];
        E T1L = Tg * ip[rs[1]] + Ti * im[rs[1]];
        E T2Y = Tg * im[rs[1]] - Ti * ip[rs[1]];
        E T1M = T1I + T1L, T3I = T2X + T2Y;
        E T2m = T1I - T1L, T2Z = T2X - T2Y;

        E T1S = T1O * rp[rs[6]] + T1Q * rm[rs[6]];
        E T2o = T1O * rm[rs[6]] - T1Q * rp[rs[6]];
        E T1V = T1f * rp[rs[1]] + T1h * rm[rs[1]];
        E T2p = T1f * rm[rs[1]] - T1h * rp[rs[1]];
        E T1W = T1S + T1V, T3K = T2o + T2p;
        E T2q = T2o - T2p, T31 = T1S - T1V;

        E T1N = T1D - T1M, T28 = T1W - T27;
        E T29 = T1N + T28, T3J = T3H + T3I;
        E T3M = T3K + T3L, T44 = T3J + T3M;
        E T3U = T3H - T3I, T3V = T3L - T3K;
        E T4j = T3V - T3U, T2f = T1D + T1M;
        E T2g = T1W + T27, T2h = T2f + T2g;

        E TO = Tk * rp[rs[2]] + To * rm[rs[2]];
        E T2u = Tk * rm[rs[2]] - To * rp[rs[2]];
        E TN = TJ * rp[rs[7]] + TL * rm[rs[7]];
        E T2v = TJ * rm[rs[7]] - TL * rp[rs[7]];
        E T3A = T2u + T2v, T2w = T2u - T2v, T2L = TO - TN;

        E T1e = T2 * ip[0] + T5 * im[0];
        E T2R = T2 * im[0] - T5 * ip[0];
        E T1p = T1j * ip[rs[5]] + T1n * im[rs[5]];
        E T2S = T1j * im[rs[5]] - T1n * ip[rs[5]];
        E T1q = T1e + T1p, T3E = T2R + T2S;
        E T2z = T1p - T1e, T2T = T2R - T2S;

        E TR = T3 * ip[rs[4]] + T6 * im[rs[4]];
        E T2M = T3 * im[rs[4]] - T6 * ip[rs[4]];
        E TU = Tx * ip[rs[9]] + Ty * im[rs[9]];
        E T2N = Tx * im[rs[9]] - Ty * ip[rs[9]];
        E TV = TR + TU, T3B = T2M + T2N;
        E T2x = TR - TU, T2O = T2M - T2N;

        E T11 = TX * rp[rs[8]] + TZ * rm[rs[8]];
        E T2A = TX * rm[rs[8]] - TZ * rp[rs[8]];
        E T1a = T14 * rp[rs[3]] + T18 * rm[rs[3]];
        E T2B = T14 * rm[rs[3]] - T18 * rp[rs[3]];
        E T1b = T11 + T1a, T3D = T2A + T2B;
        E T2C = T2A - T2B, T2Q = T11 - T1a;

        E TW = TO - TV, T1r = T1b - T1q;
        E T1s = TW + T1r, T3C = T3A + T3B;
        E T3F = T3D + T3E, T43 = T3C + T3F;
        E T3X = T3A - T3B, T3Y = T3D - T3E;
        E T4k = T3X + T3Y, T2c = TO + TV;
        E T2d = T1b + T1q, T2e = T2c + T2d;

        E T3S = KP559016994 * (T1s - T29);
        E T2a = T1s + T29;
        E T3R = TF - KP250000000 * T2a;
        E T3W = T3U + T3V, T3Z = T3X - T3Y;
        E T40 = KP951056516 * T3W - KP587785252 * T3Z;
        E T42 = KP951056516 * T3Z + KP587785252 * T3W;
        rm[rs[9]] = TF + T2a;
        E T41 = T3S + T3R;
        rm[rs[5]] = T41 - T42;
        rp[rs[6]] = T41 + T42;
        E T3T = T3R - T3S;
        rp[rs[2]] = T3T - T40;
        rm[rs[1]] = T3T + T40;

        E T4r = KP559016994 * (T4k + T4j);
        E T4l = T4j - T4k;
        E T4q = KP250000000 * T4l + T4m;
        E T4n = T1r - TW, T4o = T1N - T28;
        E T4p = KP587785252 * T4n + KP951056516 * T4o;
        E T4t = KP951056516 * T4n - KP587785252 * T4o;
        im[rs[9]] = T4l - T4m;
        E T4u = T4r + T4q;
        im[rs[5]] = T4t - T4u;
        ip[rs[6]] = T4t + T4u;
        E T4s = T4q - T4r;
        im[rs[1]] = T4p - T4s;
        ip[rs[2]] = T4p + T4s;
    }
}
}
