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
for (m = mb; m < me; m += 1) {
    E Tv = W[0], Ty = W[1], T1l = W[2], T1n = W[3];
    E T1p = Tv*T1l + Ty*T1n;
    E T1t = Tv*T1n - Ty*T1l;
    E T25 = Tv*T1l - Ty*T1n;
    E T27 = Tv*T1n + Ty*T1l;
    E Tw = W[4], Tz = W[5];
    E TB = Tv*Tw - Ty*Tz;
    E T21 = T1l*Tz + T1n*Tw;
    E T1P = Tv*Tz - Ty*Tw;
    E T1H = T1l*Tw + T1n*Tz;
    E T1X = T1l*Tw - T1n*Tz;
    E T17 = Tv*Tz + Ty*Tw;
    E T1L = T1l*Tw - T1n*Tz;
    E T1N = Tv*Tw + Ty*Tz;
    E T1v = W[6], T1w = W[7];
    E T1x = Tv*T1v + Ty*T1w;
    E T1B = Tv*T1w - Ty*T1v;
    E T2F = T25*Tz + T27*Tw;
    E T2T = T25*Tz - T27*Tw;
    E T2b = T25*Tw - T27*Tz;
    E T2R = T25*Tw + T27*Tz;
    E T3j = T1p*Tz + T1t*Tw;
    E T3x = T1p*Tz - T1t*Tw;
    E T35 = T1p*Tw - T1t*Tz;
    E T3t = T1p*Tw + T1t*Tz;

    E T3, T2c, T1b, T2H, T6, T2G, T1e, T2d;
    T3 = Rp[0] + Rm[(rs[7])]; T2c = Rp[0] - Rm[(rs[7])];
    T1b = Ip[0] - Im[(rs[7])]; T2H = Ip[0] + Im[(rs[7])];
    T6 = Rp[(rs[4])] + Rm[(rs[3])]; T2G = Rp[(rs[4])] - Rm[(rs[3])];
    T1e = Ip[(rs[4])] - Im[(rs[3])]; T2d = Ip[(rs[4])] + Im[(rs[3])];

    E T7 = T3 + T6, T36 = T2c + T2d, T3k = T2H - T2G;
    E TC = T3 - T6, T1f = T1b - T1e, T2e = T2c - T2d;
    E T2I = T2G + T2H, T1Q = T1b + T1e;

    E Ta, T2f, TI, T2g, Td, T2i, TF, T2j;
    Ta = Rp[(rs[2])] + Rm[(rs[5])]; T2f = Rp[(rs[2])] - Rm[(rs[5])];
    TI = Ip[(rs[2])] - Im[(rs[5])]; T2g = Ip[(rs[2])] + Im[(rs[5])];
    Td = Rm[(rs[1])] + Rp[(rs[6])]; T2i = Rm[(rs[1])] - Rp[(rs[6])];
    TF = Ip[(rs[6])] - Im[(rs[1])]; T2j = Ip[(rs[6])] + Im[(rs[1])];

    E Te = Ta + Td, TJ = TF - TI, T1R = TI + TF;
    E T18 = Ta - Td;
    E T2J = T2f + T2g, T2K = T2i + T2j;
    E T2L = KP707106781 * (T2J - T2K), T37 = KP707106781 * (T2J + T2K);
    E T2h = T2f - T2g, T2k = T2i - T2j;
    E T2l = KP707106781 * (T2h + T2k), T3l = KP707106781 * (T2h - T2k);

    E Ti, T2x, TO, T2v, Tl, T2u, TR, T2y;
    Ti = Rp[(rs[1])] + Rm[(rs[6])]; T2x = Rp[(rs[1])] - Rm[(rs[6])];
    TO = Ip[(rs[1])] - Im[(rs[6])]; T2v = Ip[(rs[1])] + Im[(rs[6])];
    Tl = Rp[(rs[5])] + Rm[(rs[2])]; T2u = Rp[(rs[5])] - Rm[(rs[2])];
    TR = Ip[(rs[5])] - Im[(rs[2])]; T2y = Ip[(rs[5])] + Im[(rs[2])];

    E Tm = Ti + Tl, T1T = TO + TR;
    E TL = Ti - Tl, TS = TO - TR;
    E TT = TL - TS, T1h = TL + TS;
    E T2w = T2u + T2v, T2z = T2x - T2y;
    E T2A = KP923879532*T2w + KP382683432*T2z;
    E T2N = KP923879532*T2z - KP382683432*T2w;
    E T39 = T2x + T2y, T3a = T2v - T2u;
    E T3b = KP382683432*T39 - KP923879532*T3a;
    E T3n = KP382683432*T3a + KP923879532*T39;

    E Tp, T2q, TX, T2o, Ts, T2n, T10, T2r;
    Tp = Rm[0] + Rp[(rs[7])]; T2q = Rm[0] - Rp[(rs[7])];
    TX = Ip[(rs[7])] - Im[0]; T2o = Ip[(rs[7])] + Im[0];
    Ts = Rp[(rs[3])] + Rm[(rs[4])]; T2n = Rp[(rs[3])] - Rm[(rs[4])];
    T10 = Ip[(rs[3])] - Im[(rs[4])]; T2r = Ip[(rs[3])] + Im[(rs[4])];

    E Tt = Tp + Ts, T1U = TX + T10;
    E TU = Tp - Ts, T11 = TX - T10;
    E T12 = TU + T11, T1i = T11 - TU;
    E T2p = T2n - T2o, T2s = T2q - T2r;
    E T2t = KP923879532*T2p - KP382683432*T2s;
    E T2O = KP382683432*T2p + KP923879532*T2s;
    E T3c = T2q + T2r, T3d = T2n + T2o;
    E T3e = KP382683432*T3c - KP923879532*T3d;
    E T3o = KP382683432*T3d + KP923879532*T3c;

    E Tf = T7 + Te, Tu = Tm + Tt;
    E T1O = Tf - Tu, T1S = T1Q + T1R;
    E T1V = T1T + T1U, T1W = T1S - T1V;
    Rp[0] = Tf + Tu;
    Rm[0] = T1S + T1V;
    Rp[(rs[4])] = T1N*T1O - T1P*T1W;
    Rm[(rs[4])] = T1P*T1O + T1N*T1W;

    E T38 = T36 - T37, T3f = T3b + T3e;
    E T3g = T38 - T3f, T3r = T38 + T3f;
    E T3m = T3k + T3l, T3p = T3n - T3o;
    E T3q = T3m - T3p, T3s = T3m + T3p;
    Ip[(rs[5])] = T35*T3g - T3j*T3q;
    Im[(rs[5])] = T3j*T3g + T35*T3q;
    Ip[(rs[1])] = T1l*T3r - T1n*T3s;
    Im[(rs[1])] = T1n*T3r + T1l*T3s;

    E T3u = T36 + T37, T3v = T3n + T3o;
    E T3w = T3u - T3v, T3B = T3u + T3v;
    E T3y = T3k - T3l, T3z = T3b - T3e;
    E T3A = T3y + T3z, T3C = T3y - T3z;
    Ip[(rs[3])] = T3t*T3w - T3x*T3A;
    Im[(rs[3])] = T3t*T3A + T3x*T3w;
    Ip[(rs[7])] = T1v*T3B - T1w*T3C;
    Im[(rs[7])] = T1v*T3C + T1w*T3B;

    E TK = TC + TJ, T13 = KP707106781*(TT + T12);
    E T14 = TK - T13, T1q = TK + T13;
    E T1g = T18 + T1f, T1j = KP707106781*(T1h + T1i);
    E T1k = T1g - T1j, T1u = T1g + T1j;
    Rp[(rs[5])] = TB*T14 - T17*T1k;
    Rm[(rs[5])] = T17*T14 + TB*T1k;
    Rp[(rs[1])] = T1p*T1q - T1t*T1u;
    Rm[(rs[1])] = T1t*T1q + T1p*T1u;

    E T1y = TC - TJ, T1z = KP707106781*(T1i - T1h);
    E T1A = T1y - T1z, T1I = T1y + T1z;
    E T1C = T1f - T18, T1D = KP707106781*(TT - T12);
    E T1E = T1C - T1D, T1M = T1C + T1D;
    Rp[(rs[7])] = T1x*T1A - T1B*T1E;
    Rm[(rs[7])] = T1x*T1E + T1B*T1A;
    Rp[(rs[3])] = T1H*T1I - T1L*T1M;
    Rm[(rs[3])] = T1H*T1M + T1L*T1I;

    E T2m = T2e - T2l, T2B = T2t - T2A;
    E T2C = T2m - T2B, T2S = T2m + T2B;
    E T2M = T2I - T2L, T2P = T2N - T2O;
    E T2Q = T2M - T2P, T2U = T2M + T2P;
    Ip[(rs[6])] = T2b*T2C - T2F*T2Q;
    Im[(rs[6])] = T2F*T2C + T2b*T2Q;
    Ip[(rs[2])] = T2R*T2S - T2T*T2U;
    Im[(rs[2])] = T2T*T2S + T2R*T2U;

    E T2V = T2e + T2l, T2W = T2N + T2O;
    E T2X = T2V - T2W, T31 = T2V + T2W;
    E T2Y = T2I + T2L, T2Z = T2A + T2t;
    E T30 = T2Y - T2Z, T32 = T2Y + T2Z;
    Ip[(rs[4])] = Tw*T2X - Tz*T30;
    Im[(rs[4])] = Tw*T30 + Tz*T2X;
    Ip[0] = Tv*T31 - Ty*T32;
    Im[0] = Tv*T32 + Ty*T31;

    E T1Y = T7 - Te, T1Z = T1U - T1T;
    E T20 = T1Y - T1Z, T26 = T1Y + T1Z;
    E T22 = T1Q - T1R, T23 = Tm - Tt;
    E T24 = T22 - T23, T28 = T23 + T22;
    Rp[(rs[6])] = T1X*T20 - T21*T24;
    Rm[(rs[6])] = T1X*T24 + T21*T20;
    Rp[(rs[2])] = T25*T26 - T27*T28;
    Rm[(rs[2])] = T25*T28 + T27*T26;

    W += 8;
    Rp += ms; Ip += ms;
    Rm -= ms; Im -= ms;
    rs += fftw_an_INT_guaranteed_to_be_zero;
}
}
