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
extern  E KP500000000;
extern  E KP866025403;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 28); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 28 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1q, T2Q, Td, T1n, T2T, T3l, T13, T1k, T1l, T2E, T2F, T3j, T1H, T1T, T2k;
    E T2w, T2f, T2v, T1M, T1U, Tu, TL, TM, T2H, T2I, T3i, T1w, T1Q, T29, T2t;
    E T24, T2s, T1B, T1R;
    // Convert strided accesses into consecutive buffer loads via local arrays
    E cr_buf[15], ci_buf[15];
    const INT idx_list[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    for (INT i = 0; i < 15; ++i) {
        INT idx = idx_list[i];
        INT offset = rs[idx];
        cr_buf[idx] = cr[offset];
        ci_buf[idx] = ci[offset];
    }

    {
        E T1 = cr_buf[0], T2R = ci_buf[0];
        E T3 = cr_buf[5], T5 = ci_buf[5];
        E T6 = W[8]*T3 + W[9]*T5;
        E T1o = W[8]*T5 - W[9]*T3;
        E T8 = cr_buf[10], Ta = ci_buf[10];
        E Tb = W[18]*T8 + W[19]*Ta;
        E T1p = W[18]*Ta - W[19]*T8;
        T1q = KP866025403 * (T1o - T1p);
        T2Q = KP866025403 * (Tb - T6);
        E Tc = T6 + Tb;
        Td = T1 + Tc;
        T1n = T1 - KP500000000 * Tc;
        E T2S = T1o + T1p;
        T2T = T2R - KP500000000 * T2S;
        T3l = T2S + T2R;
    }
    {
        E TR = W[10]*cr_buf[6] + W[11]*ci_buf[6];
        E T2c = W[10]*ci_buf[6] - W[11]*cr_buf[6];
        E T18 = W[16]*cr_buf[9] + W[17]*ci_buf[9];
        E T2h = W[16]*ci_buf[9] - W[17]*cr_buf[9];
        E TW = W[20]*cr_buf[11] + W[21]*ci_buf[11];
        E T1E = W[20]*ci_buf[11] - W[21]*cr_buf[11];
        E T11 = W[0]*cr_buf[1] + W[1]*ci_buf[1];
        E T1F = W[0]*ci_buf[1] - W[1]*cr_buf[1];
        E T12 = TW + T11;
        E T2d = T1E + T1F;
        E T1d = W[26]*cr_buf[14] + W[27]*ci_buf[14];
        E T1J = W[26]*ci_buf[14] - W[27]*cr_buf[14];
        E T1i = W[6]*cr_buf[4] + W[7]*ci_buf[4];
        E T1K = W[6]*ci_buf[4] - W[7]*cr_buf[4];
        E T1j = T1d + T1i;
        E T2i = T1J + T1K;
        T13 = TR + T12;
        T1k = T18 + T1j;
        T1l = T13 + T1k;
        T2E = T2c + T2d;
        T2F = T2h + T2i;
        T3j = T2E + T2F;
        E T1D = TR - KP500000000*T12;
        E T1G = KP866025403*(T1E - T1F);
        T1H = T1D - T1G;
        T1T = T1D + T1G;
        E T2g = KP866025403*(T1d - T1i);
        E T2j = T2h - KP500000000*T2i;
        T2k = T2g - T2j;
        T2w = T2g + T2j;
        E T2b = KP866025403*(T11 - TW);
        E T2e = T2c - KP500000000*T2d;
        T2f = T2b + T2e;
        T2v = T2e - T2b;
        E T1I = T18 - KP500000000*T1j;
        E T1L = KP866025403*(T1J - T1K);
        T1M = T1I - T1L;
        T1U = T1I + T1L;
    }
    {
        E Ti = W[4]*cr_buf[3] + W[5]*ci_buf[3];
        E T21 = W[4]*ci_buf[3] - W[5]*cr_buf[3];
        E Tz = W[22]*cr_buf[12] + W[23]*ci_buf[12];
        E T26 = W[22]*ci_buf[12] - W[23]*cr_buf[12];
        E Tn = W[14]*cr_buf[8] + W[15]*ci_buf[8];
        E T1t = W[14]*ci_buf[8] - W[15]*cr_buf[8];
        E Ts = W[24]*cr_buf[13] + W[25]*ci_buf[13];
        E T1u = W[24]*ci_buf[13] - W[25]*cr_buf[13];
        E Tt = Tn + Ts;
        E T22 = T1t + T1u;
        E TE = W[2]*cr_buf[2] + W[3]*ci_buf[2];
        E T1y = W[2]*ci_buf[2] - W[3]*cr_buf[2];
        E TJ = W[12]*cr_buf[7] + W[13]*ci_buf[7];
        E T1z = W[12]*ci_buf[7] - W[13]*cr_buf[7];
        E TK = TE + TJ;
        E T27 = T1y + T1z;
        Tu = Ti + Tt;
        TL = Tz + TK;
        TM = Tu + TL;
        T2H = T21 + T22;
        T2I = T26 + T27;
        T3i = T2H + T2I;
        E T1s = Ti - KP500000000*Tt;
        E T1v = KP866025403*(T1t - T1u);
        T1w = T1s - T1v;
        T1Q = T1s + T1v;
        E T25 = KP866025403*(TJ - TE);
        E T28 = T26 - KP500000000*T27;
        T29 = T25 + T28;
        T2t = T28 - T25;
        E T20 = KP866025403*(Ts - Tn);
        E T23 = T21 - KP500000000*T22;
        T24 = T20 + T23;
        T2s = T23 - T20;
        E T1x = Tz - KP500000000*TK;
        E T1A = KP866025403*(T1y - T1z);
        T1B = T1x - T1A;
        T1R = T1x + T1A;
    }
    {
        E T2C = KP559016994*(TM - T1l);
        E T1m = TM + T1l;
        E T2B = Td - KP250000000*T1m;
        E T2G = T2E - T2F;
        E T2J = T2H - T2I;
        E T2K = KP951056516*T2G - KP587785252*T2J;
        E T2M = KP951056516*T2J + KP587785252*T2G;
        cr[0] = Td + T1m;
        E T2L = T2C + T2B;
        ci[rs[5]] = T2L - T2M;
        cr[rs[6]] = T2L + T2M;
        E T2D = T2B - T2C;
        ci[rs[2]] = T2D - T2K;
        cr[rs[3]] = T2D + T2K;
    }
    {
        E T3k = KP559016994*(T3i - T3j);
        E T3m = T3i + T3j;
        E T3n = T3l - KP250000000*T3m;
        E T3f = T1k - T13;
        E T3g = Tu - TL;
        E T3h = KP587785252*T3f - KP951056516*T3g;
        E T3p = KP587785252*T3g + KP951056516*T3f;
        ci[rs[14]] = T3m + T3l;
        E T3q = T3n - T3k;
        cr[rs[12]] = T3p - T3q;
        ci[rs[11]] = T3p + T3q;
        E T3o = T3k + T3n;
        cr[rs[9]] = T3h - T3o;
        ci[rs[8]] = T3h + T3o;
    }
    {
        E T2u = T2s - T2t;
        E T2x = T2v - T2w;
        E T2y = KP951056516*T2u + KP587785252*T2x;
        E T2A = KP951056516*T2x - KP587785252*T2u;
        E T1r = T1n - T1q;
        E T1C = T1w + T1B;
        E T1N = T1H + T1M;
        E T1O = T1C + T1N;
        E T2p = KP559016994*(T1C - T1N);
        E T2q = T1r - KP250000000*T1O;
        cr[rs[5]] = T1r + T1O;
        E T2z = T2q - T2p;
        cr[rs[2]] = T2z - T2A;
        ci[rs[6]] = T2z + T2A;
        E T2r = T2p + T2q;
        ci[0] = T2r - T2y;
        ci[rs[3]] = T2r + T2y;
    }
    {
        E T33 = T1w - T1B;
        E T34 = T1H - T1M;
        E T35 = KP951056516*T33 + KP587785252*T34;
        E T3d = KP951056516*T34 - KP587785252*T33;
        E T39 = T2T - T2Q;
        E T36 = T2v + T2w;
        E T37 = T2s + T2t;
        E T3a = T37 + T36;
        E T38 = KP559016994*(T36 - T37);
        E T3b = T39 - KP250000000*T3a;
        ci[rs[9]] = T3a + T39;
        E T3e = T38 + T3b;
        cr[rs[8]] = T3d - T3e;
        ci[rs[12]] = T3d + T3e;
        E T3c = T38 - T3b;
        cr[rs[11]] = T35 + T3c;
        cr[rs[14]] = T3c - T35;
    }
    {
        E T2V = T1T - T1U;
        E T2W = T1Q - T1R;
        E T2X = KP951056516*T2V - KP587785252*T2W;
        E T31 = KP951056516*T2W + KP587785252*T2V;
        E T2U = T2Q + T2T;
        E T2N = T2k - T2f;
        E T2O = T24 + T29;
        E T2P = T2N - T2O;
        E T2Y = KP250000000*T2P + T2U;
        E T2Z = KP559016994*(T2O + T2N);
        cr[rs[10]] = T2P - T2U;
        E T32 = T2Z + T2Y;
        ci[rs[10]] = T31 + T32;
        ci[rs[13]] = T32 - T31;
        E T30 = T2Y - T2Z;
        cr[rs[13]] = T2X - T30;
        ci[rs[7]] = T2X + T30;
    }
    {
        E T2a = T24 - T29;
        E T2l = T2f + T2k;
        E T2m = KP951056516*T2a + KP587785252*T2l;
        E T2o = KP951056516*T2l - KP587785252*T2a;
        E T1P = T1n + T1q;
        E T1S = T1Q + T1R;
        E T1V = T1T + T1U;
        E T1W = T1S + T1V;
        E T1X = KP559016994*(T1S - T1V);
        E T1Y = T1P - KP250000000*T1W;
        ci[rs[4]] = T1P + T1W;
        E T1Z = T1X + T1Y;
        cr[rs[4]] = T1Z - T2m;
        cr[rs[1]] = T1Z + T2m;
        E T2n = T1Y - T1X;
        cr[rs[7]] = T2n - T2o;
        ci[rs[1]] = T2n + T2o;
    }
}
}
