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
extern  E KP951056516;
extern  E KP587785252;
extern  E KP559016994;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
const INT step = ms;
const INT half_wlen = 9;

for (m = mb; m < me; ++m) {
    E * const base_Rp = Rp + (m - mb) * step;
    E * const base_Rm = Rm - (m - mb) * step;
    E * const base_Ip = Ip + (m - mb) * step;
    E * const base_Im = Im - (m - mb) * step;
    E * const w = W + ((m - mb) * 18);

    E T3, T18, TJ, T1i, TE, TF, T1B, T1A, T1f, T1t, Ti, Tl, Tt, TA, T1w;
    E T1v, T1p, T1E, TM, TO;

    T3 = base_Rp[0] + base_Rm[rs[4]];
    T18 = base_Rp[0] - base_Rm[rs[4]];
    TJ = base_Ip[0] - base_Im[rs[4]];
    T1i = base_Ip[0] + base_Im[rs[4]];

    E T6 = base_Rp[rs[2]] + base_Rm[rs[2]];
    E T19 = base_Rp[rs[2]] - base_Rm[rs[2]];
    E Tg = base_Rm[rs[3]] + base_Rp[rs[1]];
    E T1d = base_Rm[rs[3]] - base_Rp[rs[1]];
    E T9 = base_Rm[rs[1]] + base_Rp[rs[3]];
    E T1a = base_Rm[rs[1]] - base_Rp[rs[3]];
    E Td = base_Rp[rs[4]] + base_Rm[0];
    E T1c = base_Rp[rs[4]] - base_Rm[0];

    TE = T6 - T9;
    TF = Td - Tg;
    T1B = T1c - T1d;
    T1A = T19 - T1a;

    E T1b = T19 + T1a;
    E T1e = T1c + T1d;
    T1f = T1b + T1e;
    T1t = KP559016994 * (T1b - T1e);
    E Ta = T6 + T9;
    E Th = Td + Tg;
    Ti = Ta + Th;
    Tl = KP559016994 * (Ta - Th);

    E Tp = base_Ip[rs[2]] - base_Im[rs[2]];
    E T1j = base_Ip[rs[2]] + base_Im[rs[2]];
    E Tz = base_Ip[rs[1]] - base_Im[rs[3]];
    E T1n = base_Ip[rs[1]] + base_Im[rs[3]];
    E Ts = base_Ip[rs[3]] - base_Im[rs[1]];
    E T1k = base_Ip[rs[3]] + base_Im[rs[1]];
    E Tw = base_Ip[rs[4]] - base_Im[0];
    E T1m = base_Ip[rs[4]] + base_Im[0];

    Tt = Tp - Ts;
    TA = Tw - Tz;
    T1w = T1m + T1n;
    T1v = T1j + T1k;

    E T1l = T1j - T1k;
    E T1o = T1m - T1n;
    T1p = T1l + T1o;
    T1E = KP559016994 * (T1l - T1o);
    E TK = Tp + Ts;
    E TL = Tw + Tz;
    TM = TK + TL;
    TO = KP559016994 * (TK - TL);

    base_Rp[0] = T3 + Ti;
    base_Rm[0] = TJ + TM;

    E T1g = T18 + T1f;
    E T1q = T1i + T1p;
    E T17 = w[8], T1h = w[9];
    base_Ip[rs[2]] = T17 * T1g - T1h * T1q;
    base_Im[rs[2]] = T1h * T1g + T17 * T1q;

    E TB = KP587785252 * Tt - KP951056516 * TA;
    E TG = KP587785252 * TE - KP951056516 * TF;
    E T11 = KP951056516 * TE + KP587785252 * TF;
    E TX = KP951056516 * Tt + KP587785252 * TA;
    E TN = TJ - KP250000000 * TM;
    E TP = TN - TO;
    E T10 = TO + TN;
    E Tk = T3 - KP250000000 * Ti;
    E Tm = Tk - Tl;
    E TW = Tl + Tk;

    E TC = Tm - TB, TQ = TG + TP;
    base_Rp[rs[1]] = w[2] * TC - w[3] * TQ;
    base_Rm[rs[1]] = w[3] * TC + w[2] * TQ;

    E T14 = TW - TX, T16 = T11 + T10;
    base_Rp[rs[3]] = w[10] * T14 - w[11] * T16;
    base_Rm[rs[3]] = w[11] * T14 + w[10] * T16;

    E TS = Tm + TB, TU = TP - TG;
    base_Rp[rs[4]] = w[14] * TS - w[15] * TU;
    base_Rm[rs[4]] = w[15] * TS + w[14] * TU;

    E TY = TW + TX, T12 = T10 - T11;
    base_Rp[rs[2]] = w[6] * TY - w[7] * T12;
    base_Rm[rs[2]] = w[7] * TY + w[6] * T12;

    E T1x = KP587785252 * T1v - KP951056516 * T1w;
    E T1C = KP587785252 * T1A - KP951056516 * T1B;
    E T1Q = KP951056516 * T1A + KP587785252 * T1B;
    E T1N = KP951056516 * T1v + KP587785252 * T1w;
    E T1D = T1i - KP250000000 * T1p;
    E T1F = T1D - T1E;
    E T1R = T1E + T1D;
    E T1s = T18 - KP250000000 * T1f;
    E T1u = T1s - T1t;
    E T1M = T1t + T1s;

    E T1y = T1u - T1x, T1G = T1C + T1F;
    base_Ip[rs[3]] = w[12] * T1y - w[13] * T1G;
    base_Im[rs[3]] = w[12] * T1G + w[13] * T1y;

    E T1U = T1M + T1N, T1W = T1R - T1Q;
    base_Ip[rs[4]] = w[16] * T1U - w[17] * T1W;
    base_Im[rs[4]] = w[16] * T1W + w[17] * T1U;

    E T1I = T1u + T1x, T1K = T1F - T1C;
    base_Ip[rs[1]] = w[4] * T1I - w[5] * T1K;
    base_Im[rs[1]] = w[4] * T1K + w[5] * T1I;

    E T1O = T1M - T1N, T1S = T1Q + T1R;
    base_Ip[0] = w[0] * T1O - w[1] * T1S;
    base_Im[0] = w[0] * T1S + w[1] * T1O;
}
}
