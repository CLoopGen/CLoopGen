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
for (m = mb , W = W + ((mb - 1) * 18); m < me; m = m + 1 , Rp = Rp + ms , Ip = Ip + ms , Rm = Rm - ms , Im = Im - ms , W = W + 18 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T7, T1O, TT, T1C, TF, TQ, TR, T1r, T1s, T1L, TX, TY, TZ, T16, T19;
    E T1y, Ti, Tt, Tu, T1o, T1p, T1M, TU, TV, TW, T1d, T1g, T1x;
    const INT * restrict rstride = rs;
    E * restrict local_Rp = Rp;
    E * restrict local_Ip = Ip;
    E * restrict local_Rm = Rm;
    E * restrict local_Im = Im;
    E * restrict local_W = W;
    {
        E T1, T1B, T6, T1A;
        T1 = local_Rp[0];
        T1B = local_Rm[0];
        {
            E T3 = local_Ip[rstride[2]], T5 = local_Im[rstride[2]];
            E T2 = local_W[8], T4 = local_W[9];
            T6 = T2 * T3 + T4 * T5;
            T1A = T2 * T5 - T4 * T3;
        }
        T7 = T1 - T6;
        T1O = T1B - T1A;
        TT = T1 + T6;
        T1C = T1A + T1B;
    }
    {
        E Tz, T14, TP, T18, TE, T15, TK, T17;
        {
            E Tw = local_Rp[rstride[2]], Ty = local_Rm[rstride[2]];
            E Tv = local_W[6], Tx = local_W[7];
            Tz = Tv * Tw + Tx * Ty;
            T14 = Tv * Ty - Tx * Tw;
        }
        {
            E TM = local_Ip[0], TO = local_Im[0];
            E TL = local_W[0], TN = local_W[1];
            TP = TL * TM + TN * TO;
            T18 = TL * TO - TN * TM;
        }
        {
            E TB = local_Ip[rstride[4]], TD = local_Im[rstride[4]];
            E TA = local_W[16], TC = local_W[17];
            TE = TA * TB + TC * TD;
            T15 = TA * TD - TC * TB;
        }
        {
            E TH = local_Rp[rstride[3]], TJ = local_Rm[rstride[3]];
            E TG = local_W[10], TI = local_W[11];
            TK = TG * TH + TI * TJ;
            T17 = TG * TJ - TI * TH;
        }
        TF = Tz - TE;
        TQ = TK - TP;
        TR = TF + TQ;
        T1r = T14 - T15;
        T1s = T18 - T17;
        T1L = T1s - T1r;
        TX = Tz + TE;
        TY = TK + TP;
        TZ = TX + TY;
        T16 = T14 + T15;
        T19 = T17 + T18;
        T1y = T16 + T19;
    }
    {
        E Tc, T1b, Ts, T1f, Th, T1c, Tn, T1e;
        {
            E T9 = local_Rp[rstride[1]], Tb = local_Rm[rstride[1]];
            E T8 = local_W[2], Ta = local_W[3];
            Tc = T8 * T9 + Ta * Tb;
            T1b = T8 * Tb - Ta * T9;
        }
        {
            E Tp = local_Ip[rstride[1]], Tr = local_Im[rstride[1]];
            E To = local_W[4], Tq = local_W[5];
            Ts = To * Tp + Tq * Tr;
            T1f = To * Tr - Tq * Tp;
        }
        {
            E Te = local_Ip[rstride[3]], Tg = local_Im[rstride[3]];
            E Td = local_W[12], Tf = local_W[13];
            Th = Td * Te + Tf * Tg;
            T1c = Td * Tg - Tf * Te;
        }
        {
            E Tk = local_Rp[rstride[4]], Tm = local_Rm[rstride[4]];
            E Tj = local_W[14], Tl = local_W[15];
            Tn = Tj * Tk + Tl * Tm;
            T1e = Tj * Tm - Tl * Tk;
        }
        Ti = Tc - Th;
        Tt = Tn - Ts;
        Tu = Ti + Tt;
        T1o = T1b - T1c;
        T1p = T1e - T1f;
        T1M = T1o + T1p;
        TU = Tc + Th;
        TV = Tn + Ts;
        TW = TU + TV;
        T1d = T1b + T1c;
        T1g = T1e + T1f;
        T1x = T1d + T1g;
    }
    {
        E T1l, TS, T1m, T1u, T1w, T1q, T1t, T1v, T1n;
        T1l = KP559016994 * (Tu - TR);
        TS = Tu + TR;
        T1m = T7 - KP250000000 * TS;
        T1q = T1o - T1p;
        T1t = T1r + T1s;
        T1u = KP951056516 * T1q + KP587785252 * T1t;
        T1w = KP951056516 * T1t - KP587785252 * T1q;
        local_Rm[rstride[4]] = T7 + TS;
        T1v = T1m - T1l;
        local_Rm[rstride[2]] = T1v - T1w;
        local_Rp[rstride[3]] = T1v + T1w;
        T1n = T1l + T1m;
        local_Rm[0] = T1n - T1u;
        local_Rp[rstride[1]] = T1n + T1u;
    }
    {
        E T1S, T1N, T1T, T1R, T1V, T1P, T1Q, T1W, T1U;
        T1S = KP559016994 * (T1M + T1L);
        T1N = T1L - T1M;
        T1T = KP250000000 * T1N + T1O;
        T1P = TQ - TF;
        T1Q = Ti - Tt;
        T1R = KP587785252 * T1P - KP951056516 * T1Q;
        T1V = KP587785252 * T1Q + KP951056516 * T1P;
        local_Im[rstride[4]] = T1N - T1O;
        T1W = T1T - T1S;
        local_Im[rstride[2]] = T1V - T1W;
        local_Ip[rstride[3]] = T1V + T1W;
        T1U = T1S + T1T;
        local_Im[0] = T1R - T1U;
        local_Ip[rstride[1]] = T1R + T1U;
    }
    {
        E T12, T10, T11, T1i, T1k, T1a, T1h, T1j, T13;
        T12 = KP559016994 * (TW - TZ);
        T10 = TW + TZ;
        T11 = TT - KP250000000 * T10;
        T1a = T16 - T19;
        T1h = T1d - T1g;
        T1i = KP951056516 * T1a - KP587785252 * T1h;
        T1k = KP951056516 * T1h + KP587785252 * T1a;
        local_Rp[0] = TT + T10;
        T1j = T12 + T11;
        local_Rp[rstride[4]] = T1j - T1k;
        local_Rm[rstride[3]] = T1j + T1k;
        T13 = T11 - T12;
        local_Rp[rstride[2]] = T13 - T1i;
        local_Rm[rstride[1]] = T13 + T1i;
    }
    {
        E T1H, T1z, T1G, T1F, T1J, T1D, T1E, T1K, T1I;
        T1H = KP559016994 * (T1x - T1y);
        T1z = T1x + T1y;
        T1G = T1C - KP250000000 * T1z;
        T1D = TX - TY;
        T1E = TU - TV;
        T1F = KP951056516 * T1D - KP587785252 * T1E;
        T1J = KP951056516 * T1E + KP587785252 * T1D;
        local_Ip[0] = T1z + T1C;
        T1K = T1H + T1G;
        local_Im[rstride[3]] = T1J - T1K;
        local_Ip[rstride[4]] = T1J + T1K;
        T1I = T1G - T1H;
        local_Im[rstride[1]] = T1F - T1I;
        local_Ip[rstride[2]] = T1F + T1I;
    }
}
}
