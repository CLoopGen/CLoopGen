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
for (m = mb , W = W + ((mb - 1) * 8); m < me; m = m + 1 , cr += ms , ci -= ms , W += 8 , rs += fftw_an_INT_guaranteed_to_be_zero) {
    E Tv = W[0], Ty = W[1], T1l = W[2], T1n = W[3];
    E T1m = Tv * T1l, T1s = Ty * T1l, T1o = Ty * T1n, T1r = Tv * T1n;
    E T1p = T1m + T1o, T1t = T1r - T1s, T27 = T1r + T1s, T25 = T1m - T1o;
    E Tz = W[5], Tw = W[4];
    E TA = Ty * Tz, T1J = T1l * Tz, T15 = Tv * Tz, T1G = T1n * Tz;
    E Tx = Tv * Tw, T1K = T1n * Tw, T16 = Ty * Tw, T1F = T1l * Tw;
    E TB = Tx - TA, T21 = T1J + T1K, T1P = T15 - T16, T1H = T1F + T1G;
    E T1X = T1F - T1G, T17 = T15 + T16, T1L = T1J - T1K, T1N = Tx + TA;
    E T1v = W[6], T1w = W[7];
    E T1x = Tv*T1v + Ty*T1w, T1B = Tv*T1w - Ty*T1v;
    E T2D = T25*Tz, T2E = T27*Tw, T2F = T2D + T2E, T2T = T2D - T2E;
    E T29 = T25*Tw, T2a = T27*Tz, T2b = T29 - T2a, T2R = T29 + T2a;
    E T3h = T1p*Tz, T3i = T1t*Tw, T3j = T3h + T3i, T3x = T3h - T3i;
    E T33 = T1p*Tw, T34 = T1t*Tz, T35 = T33 - T34, T3t = T33 + T34;

    const INT * restrict rrs = rs;
    R * restrict pcr = cr;
    R * restrict pci = ci;

    E T1 = pcr[0], T2 = pci[rrs[7]], T3 = T1 + T2, T2c = T1 - T2;
    E T1c = pci[rrs[11]], T1d = pcr[rrs[12]], T1e = T1c - T1d, T2d = T1c + T1d;
    E T4 = pcr[rrs[4]], T5 = pci[rrs[3]], T6 = T4 + T5, T2G = T4 - T5;
    E T19 = pci[rrs[15]], T1a = pcr[rrs[8]], T1b = T19 - T1a, T2H = T19 + T1a;

    E T7 = T3 + T6, T36 = T2c + T2d, T3k = T2H - T2G, TC = T3 - T6;
    E T1f = T1b - T1e, T2e = T2c - T2d, T2I = T2G + T2H, T1Q = T1b + T1e;

    E T8 = pcr[rrs[2]], T9 = pci[rrs[5]], Ta = T8 + T9, T2f = T8 - T9;
    E TG = pci[rrs[13]], TH = pcr[rrs[10]], TI = TG - TH, T2g = TG + TH;
    E Tb = pci[rrs[1]], Tc = pcr[rrs[6]], Td = Tb + Tc, T2i = Tb - Tc;
    E TD = pci[rrs[9]], TE = pcr[rrs[14]], TF = TD - TE, T2j = TD + TE;

    E Te = Ta + Td, TJ = TF - TI, T1R = TI + TF, T18 = Ta - Td;
    E T2J = T2f + T2g, T2K = T2i + T2j;
    E T2L = KP707106781 * (T2J - T2K), T37 = KP707106781 * (T2J + T2K);
    E T2h = T2f - T2g, T2k = T2i - T2j;
    E T2l = KP707106781 * (T2h + T2k), T3l = KP707106781 * (T2h - T2k);

    E Tg = pcr[rrs[1]], Th = pci[rrs[6]], Ti = Tg + Th, T2x = Tg - Th;
    E TP = pci[rrs[10]], TQ = pcr[rrs[13]], TR = TP - TQ, T2y = TP + TQ;
    E Tj = pcr[rrs[5]], Tk = pci[rrs[2]], Tl = Tj + Tk, T2u = Tj - Tk;
    E TM = pci[rrs[14]], TN = pcr[rrs[9]], TO = TM - TN, T2v = TM + TN;

    E Tm = Ti + Tl, T1T = TO + TR, TL = Ti - Tl, TS = TO - TR;
    E TT = TL - TS, T1h = TL + TS;
    E T2w = T2u + T2v, T2z = T2x - T2y;
    E T2A = KP923879532*T2w + KP382683432*T2z;
    E T2N = KP923879532*T2z - KP382683432*T2w;
    E T39 = T2x + T2y, T3a = T2v - T2u;
    E T3b = KP382683432*T39 - KP923879532*T3a;
    E T3n = KP382683432*T3a + KP923879532*T39;

    E Tn = pci[0], To = pcr[rrs[7]], Tp = Tn + To, T2q = Tn - To;
    E TY = pci[rrs[12]], TZ = pcr[rrs[11]], T10 = TY - TZ, T2r = TY + TZ;
    E Tq = pcr[rrs[3]], Tr = pci[rrs[4]], Ts = Tq + Tr, T2n = Tq - Tr;
    E TV = pci[rrs[8]], TW = pcr[rrs[15]], TX = TV - TW, T2o = TV + TW;

    E Tt = Tp + Ts, T1U = TX + T10, TU = Tp - Ts, T11 = TX - T10;
    E T12 = TU + T11, T1i = T11 - TU;
    E T2p = T2n - T2o, T2s = T2q - T2r;
    E T2t = KP923879532*T2p - KP382683432*T2s;
    E T2O = KP382683432*T2p + KP923879532*T2s;
    E T3c = T2q + T2r, T3d = T2n + T2o;
    E T3e = KP382683432*T3c - KP923879532*T3d;
    E T3o = KP382683432*T3d + KP923879532*T3c;

    E Tf = T7 + Te, Tu = Tm + Tt, T1O = Tf - Tu, T1S = T1Q + T1R;
    E T1V = T1T + T1U, T1W = T1S - T1V;
    pcr[0] = Tf + Tu;
    pci[0] = T1S + T1V;
    pcr[rrs[8]] = T1N*T1O - T1P*T1W;
    pci[rrs[8]] = T1P*T1O + T1N*T1W;

    E T38 = T36 - T37, T3f = T3b + T3e, T3g = T38 - T3f, T3r = T38 + T3f;
    E T3m = T3k + T3l, T3p = T3n - T3o, T3q = T3m - T3p, T3s = T3m + T3p;
    pcr[rrs[11]] = T35*T3g - T3j*T3q;
    pci[rrs[11]] = T3j*T3g + T35*T3q;
    pcr[rrs[3]] = T1l*T3r - T1n*T3s;
    pci[rrs[3]] = T1n*T3r + T1l*T3s;

    E T3u = T36 + T37, T3v = T3n + T3o, T3w = T3u - T3v, T3B = T3u + T3v;
    E T3y = T3k - T3l, T3z = T3b - T3e, T3A = T3y + T3z, T3C = T3y - T3z;
    pcr[rrs[7]] = T3t*T3w - T3x*T3A;
    pci[rrs[7]] = T3t*T3A + T3x*T3w;
    pcr[rrs[15]] = T1v*T3B - T1w*T3C;
    pci[rrs[15]] = T1v*T3C + T1w*T3B;

    E TK = TC + TJ, T13 = KP707106781*(TT + T12), T14 = TK - T13, T1q = TK + T13;
    E T1g = T18 + T1f, T1j = KP707106781*(T1h + T1i), T1k = T1g - T1j, T1u = T1g + T1j;
    pcr[rrs[10]] = TB*T14 - T17*T1k;
    pci[rrs[10]] = T17*T14 + TB*T1k;
    pcr[rrs[2]] = T1p*T1q - T1t*T1u;
    pci[rrs[2]] = T1t*T1q + T1p*T1u;

    E T1y = TC - TJ, T1z = KP707106781*(T1i - T1h), T1A = T1y - T1z, T1I = T1y + T1z;
    E T1C = T1f - T18, T1D = KP707106781*(TT - T12), T1E = T1C - T1D, T1M = T1C + T1D;
    pcr[rrs[14]] = T1x*T1A - T1B*T1E;
    pci[rrs[14]] = T1x*T1E + T1B*T1A;
    pcr[rrs[6]] = T1H*T1I - T1L*T1M;
    pci[rrs[6]] = T1H*T1M + T1L*T1I;

    E T2m = T2e - T2l, T2B = T2t - T2A, T2C = T2m - T2B, T2S = T2m + T2B;
    E T2M = T2I - T2L, T2P = T2N - T2O, T2Q = T2M - T2P, T2U = T2M + T2P;
    pcr[rrs[13]] = T2b*T2C - T2F*T2Q;
    pci[rrs[13]] = T2F*T2C + T2b*T2Q;
    pcr[rrs[5]] = T2R*T2S - T2T*T2U;
    pci[rrs[5]] = T2T*T2S + T2R*T2U;

    E T2V = T2e + T2l, T2W = T2N + T2O, T2X = T2V - T2W, T31 = T2V + T2W;
    E T2Y = T2I + T2L, T2Z = T2A + T2t, T30 = T2Y - T2Z, T32 = T2Y + T2Z;
    pcr[rrs[9]] = Tw*T2X - Tz*T30;
    pci[rrs[9]] = Tw*T30 + Tz*T2X;
    pcr[rrs[1]] = Tv*T31 - Ty*T32;
    pci[rrs[1]] = Tv*T32 + Ty*T31;

    E T1Y = T7 - Te, T1Z = T1U - T1T, T20 = T1Y - T1Z, T26 = T1Y + T1Z;
    E T22 = T1Q - T1R, T23 = Tm - Tt, T24 = T22 - T23, T28 = T23 + T22;
    pcr[rrs[12]] = T1X*T20 - T21*T24;
    pci[rrs[12]] = T1X*T24 + T21*T20;
    pcr[rrs[4]] = T25*T26 - T27*T28;
    pci[rrs[4]] = T25*T28 + T27*T26;
}
}
