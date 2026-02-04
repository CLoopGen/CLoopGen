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
extern  E KP382683432;
extern  E KP923879532;
extern  E KP707106781;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Variant with reduced loop nesting — all code flattened into single scope
// Eliminates artificial blocks and reduces control flow depth for direct execution path

for (m = mb , W = W + (mb * 30); m < me; m = m + 1 , ri = ri + ms , ii = ii + ms , W = W + 30 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {

    E T7, T37, T1t, T2U, Ti, T38, T1w, T2R, Tu, T2s, T1C, T2c, TF, T2t, T1H;
    E T2d, T1f, T1q, T2B, T2C, T2D, T2E, T1Z, T2j, T24, T2k, TS, T13, T2w, T2x;
    E T2y, T2z, T1O, T2g, T1T, T2h;

    // Direct inline computation without intermediate scoping
    E T1 = ri[0];
    E T2T = ii[0];
    E T3 = ri[(rs[8])];
    E T5 = ii[(rs[8])];
    E T2 = W[14];
    E T4 = W[15];
    E T6 = T2*T3 + T4*T5;
    E T2S = T2*T5 - T4*T3;
    T7 = T1 + T6;
    T37 = T2T - T2S;
    T1t = T1 - T6;
    T2U = T2S + T2T;

    E T9 = ri[(rs[4])];
    E Tb = ii[(rs[4])];
    E T8 = W[6];
    E Ta = W[7];
    E Tc = T8*T9 + Ta*Tb;
    E T1u = T8*Tb - Ta*T9;
    E Te = ri[(rs[12])];
    E Tg = ii[(rs[12])];
    E Td = W[22];
    E Tf = W[23];
    E Th = Td*Te + Tf*Tg;
    E T1v = Td*Tg - Tf*Te;
    Ti = Tc + Th;
    T38 = Tc - Th;
    T1w = T1u - T1v;
    T2R = T1u + T1v;

    E Tl = ri[(rs[2])];
    E Tn = ii[(rs[2])];
    E Tk = W[2];
    E Tm = W[3];
    E To = Tk*Tl + Tm*Tn;
    E T1y = Tk*Tn - Tm*Tl;
    E Tq = ri[(rs[10])];
    E Ts = ii[(rs[10])];
    E Tp = W[18];
    E Tr = W[19];
    E Tt = Tp*Tq + Tr*Ts;
    E T1z = Tp*Ts - Tr*Tq;
    Tu = To + Tt;
    T2s = T1y + T1z;
    E T1A = T1y - T1z;
    E T1B = To - Tt;
    T1C = T1A - T1B;
    T2c = T1B + T1A;

    E Tw = ri[(rs[14])];
    E Ty = ii[(rs[14])];
    E Tv = W[26];
    E Tx = W[27];
    E Tz = Tv*Tw + Tx*Ty;
    E T1E = Tv*Ty - Tx*Tw;
    E TB = ri[(rs[6])];
    E TD = ii[(rs[6])];
    E TA = W[10];
    E TC = W[11];
    E TE = TA*TB + TC*TD;
    E T1F = TA*TD - TC*TB;
    TF = Tz + TE;
    T2t = T1E + T1F;
    E T1D = Tz - TE;
    E T1G = T1E - T1F;
    T1H = T1D + T1G;
    T2d = T1D - T1G;

    E T16 = ri[(rs[15])];
    E T18 = ii[(rs[15])];
    E T15 = W[28];
    E T17 = W[29];
    E T19 = T15*T16 + T17*T18;
    E T20 = T15*T18 - T17*T16;
    E T1m = ri[(rs[11])];
    E T1o = ii[(rs[11])];
    E T1l = W[20];
    E T1n = W[21];
    E T1p = T1l*T1m + T1n*T1o;
    E T1X = T1l*T1o - T1n*T1m;
    E T1b = ri[(rs[7])];
    E T1d = ii[(rs[7])];
    E T1a = W[12];
    E T1c = W[13];
    E T1e = T1a*T1b + T1c*T1d;
    E T21 = T1a*T1d - T1c*T1b;
    E T1h = ri[(rs[3])];
    E T1j = ii[(rs[3])];
    E T1g = W[4];
    E T1i = W[5];
    E T1k = T1g*T1h + T1i*T1j;
    E T1W = T1g*T1j - T1i*T1h;
    T1f = T19 + T1e;
    T1q = T1k + T1p;
    T2B = T1f - T1q;
    T2C = T20 + T21;
    T2D = T1W + T1X;
    T2E = T2C - T2D;
    E T1V = T19 - T1e;
    E T1Y = T1W - T1X;
    T1Z = T1V - T1Y;
    T2j = T1V + T1Y;
    E T22 = T20 - T21;
    E T23 = T1k - T1p;
    T24 = T22 + T23;
    T2k = T22 - T23;

    E TJ = ri[(rs[1])];
    E TL = ii[(rs[1])];
    E TI = W[0];
    E TK = W[1];
    E TM = TI*TJ + TK*TL;
    E T1K = TI*TL - TK*TJ;
    E TZ = ri[(rs[13])];
    E T11 = ii[(rs[13])];
    E TY = W[24];
    E T10 = W[25];
    E T12 = TY*TZ + T10*T11;
    E T1R = TY*T11 - T10*TZ;
    E TO = ri[(rs[9])];
    E TQ = ii[(rs[9])];
    E TN = W[16];
    E TP = W[17];
    E TR = TN*TO + TP*TQ;
    E T1L = TN*TQ - TP*TO;
    E TU = ri[(rs[5])];
    E TW = ii[(rs[5])];
    E TT = W[8];
    E TV = W[9];
    E TX = TT*TU + TV*TW;
    E T1Q = TT*TW - TV*TU;
    TS = TM + TR;
    T13 = TX + T12;
    T2w = TS - T13;
    T2x = T1K + T1L;
    T2y = T1Q + T1R;
    T2z = T2x - T2y;
    E T1M = T1K - T1L;
    E T1N = TX - T12;
    T1O = T1M + T1N;
    T2g = T1M - T1N;
    E T1P = TM - TR;
    E T1S = T1Q - T1R;
    T1T = T1P - T1S;
    T2h = T1P + T1S;

    // Final recombinations
    E T1x = T1t - T1w;
    E T1I = KP707106781 * (T1C - T1H);
    E T1J = T1x + T1I;
    E T27 = T1x - T1I;
    E T3e = KP707106781 * (T2d - T2c);
    E T3f = T38 + T37;
    E T3g = T3e + T3f;
    E T3i = T3f - T3e;
    E T1U = KP923879532*T1O + KP382683432*T1T;
    E T25 = KP382683432*T1Z - KP923879532*T24;
    E T26 = T1U + T25;
    E T3h = T25 - T1U;
    E T28 = KP382683432*T1O - KP923879532*T1T;
    E T29 = KP382683432*T24 + KP923879532*T1Z;
    E T2a = T28 - T29;
    E T3d = T28 + T29;

    ri[(rs[11])] = T1J - T26;
    ii[(rs[11])] = T3g - T3d;
    ri[(rs[3])] = T1J + T26;
    ii[(rs[3])] = T3d + T3g;
    ri[(rs[15])] = T27 - T2a;
    ii[(rs[15])] = T3i - T3h;
    ri[(rs[7])] = T27 + T2a;
    ii[(rs[7])] = T3h + T3i;

    E T2r = T7 - Ti;
    E T2u = T2s - T2t;
    E T2v = T2r + T2u;
    E T2H = T2r - T2u;
    E T30 = TF - Tu;
    E T31 = T2U - T2R;
    E T32 = T30 + T31;
    E T34 = T31 - T30;
    E T2A = T2w + T2z;
    E T2F = T2B - T2E;
    E T2G = KP707106781 * (T2A + T2F);
    E T33 = KP707106781 * (T2F - T2A);
    E T2I = T2z - T2w;
    E T2J = T2B + T2E;
    E T2K = KP707106781 * (T2I - T2J);
    E T2Z = KP707106781 * (T2I + T2J);

    ri[(rs[10])] = T2v - T2G;
    ii[(rs[10])] = T32 - T2Z;
    ri[(rs[2])] = T2v + T2G;
    ii[(rs[2])] = T2Z + T32;
    ri[(rs[14])] = T2H - T2K;
    ii[(rs[14])] = T34 - T33;
    ri[(rs[6])] = T2H + T2K;
    ii[(rs[6])] = T33 + T34;

    E T2b = T1t + T1w;
    E T2e = KP707106781 * (T2c + T2d);
    E T2f = T2b + T2e;
    E T2n = T2b - T2e;
    E T36 = KP707106781 * (T1C + T1H);
    E T39 = T37 - T38;
    E T3a = T36 + T39;
    E T3c = T39 - T36;
    E T2i = KP382683432*T2g + KP923879532*T2h;
    E T2l = KP923879532*T2j - KP382683432*T2k;
    E T2m = T2i + T2l;
    E T3b = T2l - T2i;
    E T2o = KP923879532*T2g - KP382683432*T2h;
    E T2p = KP923879532*T2k + KP382683432*T2j;
    E T2q = T2o - T2p;
    E T35 = T2o + T2p;

    ri[(rs[9])] = T2f - T2m;
    ii[(rs[9])] = T3a - T35;
    ri[(rs[1])] = T2f + T2m;
    ii[(rs[1])] = T35 + T3a;
    ri[(rs[13])] = T2n - T2q;
    ii[(rs[13])] = T3c - T3b;
    ri[(rs[5])] = T2n + T2q;
    ii[(rs[5])] = T3b + T3c;

    E Tj = T7 + Ti;
    E TG = Tu + TF;
    E TH = Tj + TG;
    E T2L = Tj - TG;
    E T2Q = T2s + T2t;
    E T2V = T2R + T2U;
    E T2W = T2Q + T2V;
    E T2Y = T2V - T2Q;
    E T14 = TS + T13;
    E T1r = T1f + T1q;
    E T1s = T14 + T1r;
    E T2X = T1r - T14;
    E T2M = T2x + T2y;
    E T2N = T2C + T2D;
    E T2O = T2M - T2N;
    E T2P = T2M + T2N;

    ri[(rs[8])] = TH - T1s;
    ii[(rs[8])] = T2W - T2P;
    ri[0] = TH + T1s;
    ii[0] = T2P + T2W;
    ri[(rs[12])] = T2L - T2O;
    ii[(rs[12])] = T2Y - T2X;
    ri[(rs[4])] = T2L + T2O;
    ii[(rs[4])] = T2X + T2Y;
}
}
