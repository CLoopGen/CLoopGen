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
extern  E KP500000000;
extern  E KP866025403;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 22); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 22 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T5, TH, T12, T1M, T1i, T1U, Tg, Tt, T19, T1X, T1p, T1P, Ta, TM, T15;
    E T1N, T1l, T1V, Tl, Ty, T1c, T1Y, T1s, T1Q;
    const INT *rsoff = rs; // Base pointer for stride offsets
    R *cr_base = cr;       // Make local base pointers for consecutive-style access
    R *ci_base = ci;
    R *W_base = W;

    {
        E T1, TD, T4, T1g, TG, T11, T10, T1h;
        T1 = cr_base[0];
        TD = ci_base[rsoff[11]];
        {
            E T2, T3, TE, TF;
            T2 = cr_base[rsoff[4]];
            T3 = ci_base[rsoff[3]];
            T4 = T2 + T3;
            T1g = KP866025403 * (T2 - T3);
            TE = ci_base[rsoff[7]];
            TF = cr_base[rsoff[8]];
            TG = TE - TF;
            T11 = KP866025403 * (TE + TF);
        }
        T5 = T1 + T4;
        TH = TD + TG;
        T10 = T1 - KP500000000 * T4;
        T12 = T10 - T11;
        T1M = T10 + T11;
        T1h = TD - KP500000000 * TG;
        T1i = T1g + T1h;
        T1U = T1h - T1g;
    }
    {
        E Tc, Tp, Tf, T17, Ts, T1o, T18, T1n;
        Tc = cr_base[rsoff[3]];
        Tp = ci_base[rsoff[8]];
        {
            E Td, Te, Tq, Tr;
            Td = ci_base[rsoff[4]];
            Te = ci_base[0];
            Tf = Td + Te;
            T17 = KP866025403 * (Td - Te);
            Tq = cr_base[rsoff[7]];
            Tr = cr_base[rsoff[11]];
            Ts = Tq + Tr;
            T1o = KP866025403 * (Tq - Tr);
        }
        Tg = Tc + Tf;
        Tt = Tp - Ts;
        T18 = KP500000000 * Ts + Tp;
        T19 = T17 + T18;
        T1X = T18 - T17;
        T1n = Tc - KP500000000 * Tf;
        T1p = T1n + T1o;
        T1P = T1n - T1o;
    }
    {
        E T6, TL, T9, T1j, TK, T14, T13, T1k;
        T6 = ci_base[rsoff[5]];
        TL = cr_base[rsoff[6]];
        {
            E T7, T8, TI, TJ;
            T7 = ci_base[rsoff[1]];
            T8 = cr_base[rsoff[2]];
            T9 = T7 + T8;
            T1j = KP866025403 * (T7 - T8);
            TI = ci_base[rsoff[9]];
            TJ = cr_base[rsoff[10]];
            TK = TI - TJ;
            T14 = KP866025403 * (TI + TJ);
        }
        Ta = T6 + T9;
        TM = TK - TL;
        T13 = T6 - KP500000000 * T9;
        T15 = T13 + T14;
        T1N = T13 - T14;
        T1k = KP500000000 * TK + TL;
        T1l = T1j - T1k;
        T1V = T1j + T1k;
    }
    {
        E Th, Tx, Tk, T1a, Tw, T1r, T1b, T1q;
        Th = ci_base[rsoff[2]];
        Tx = cr_base[rsoff[9]];
        {
            E Ti, Tj, Tu, Tv;
            Ti = cr_base[rsoff[1]];
            Tj = cr_base[rsoff[5]];
            Tk = Ti + Tj;
            T1a = KP866025403 * (Ti - Tj);
            Tu = ci_base[rsoff[10]];
            Tv = ci_base[rsoff[6]];
            Tw = Tu + Tv;
            T1r = KP866025403 * (Tv - Tu);
        }
        Tl = Th + Tk;
        Ty = Tw - Tx;
        T1b = KP500000000 * Tw + Tx;
        T1c = T1a - T1b;
        T1Y = T1a + T1b;
        T1q = Th - KP500000000 * Tk;
        T1s = T1q + T1r;
        T1Q = T1q - T1r;
    }
    {
        E Tb, Tm, TU, TW, TX, TY, TT, TV;
        Tb = T5 + Ta;
        Tm = Tg + Tl;
        TU = Tb - Tm;
        TW = TH + TM;
        TX = Tt + Ty;
        TY = TW - TX;
        cr_base[0] = Tb + Tm;
        ci_base[0] = TW + TX;
        TT = W_base[10];
        TV = W_base[11];
        cr_base[rsoff[6]] = TT * TU - TV * TY;
        ci_base[rsoff[6]] = TV * TU + TT * TY;
    }
    {
        E TA, TQ, TO, TS;
        {
            E To, Tz, TC, TN;
            To = T5 - Ta;
            Tz = Tt - Ty;
            TA = To - Tz;
            TQ = To + Tz;
            TC = Tg - Tl;
            TN = TH - TM;
            TO = TC + TN;
            TS = TN - TC;
        }
        {
            E Tn, TB, TP, TR;
            Tn = W_base[16];
            TB = W_base[17];
            cr_base[rsoff[9]] = Tn * TA - TB * TO;
            ci_base[rsoff[9]] = Tn * TO + TB * TA;
            TP = W_base[4];
            TR = W_base[5];
            cr_base[rsoff[3]] = TP * TQ - TR * TS;
            ci_base[rsoff[3]] = TP * TS + TR * TQ;
        }
    }
    {
        E T28, T2e, T2c, T2g;
        {
            E T26, T27, T2a, T2b;
            T26 = T1M - T1N;
            T27 = T1X + T1Y;
            T28 = T26 - T27;
            T2e = T26 + T27;
            T2a = T1U + T1V;
            T2b = T1P - T1Q;
            T2c = T2a + T2b;
            T2g = T2a - T2b;
        }
        {
            E T25, T29, T2d, T2f;
            T25 = W_base[8];
            T29 = W_base[9];
            cr_base[rsoff[5]] = T25 * T28 - T29 * T2c;
            ci_base[rsoff[5]] = T25 * T2c + T29 * T28;
            T2d = W_base[20];
            T2f = W_base[21];
            cr_base[rsoff[11]] = T2d * T2e - T2f * T2g;
            ci_base[rsoff[11]] = T2d * T2g + T2f * T2e;
        }
    }
    {
        E T1S, T22, T20, T24;
        {
            E T1O, T1R, T1W, T1Z;
            T1O = T1M + T1N;
            T1R = T1P + T1Q;
            T1S = T1O - T1R;
            T22 = T1O + T1R;
            T1W = T1U - T1V;
            T1Z = T1X - T1Y;
            T20 = T1W - T1Z;
            T24 = T1W + T1Z;
        }
        {
            E T1L, T1T, T21, T23;
            T1L = W_base[2];
            T1T = W_base[3];
            cr_base[rsoff[2]] = T1L * T1S - T1T * T20;
            ci_base[rsoff[2]] = T1T * T1S + T1L * T20;
            T21 = W_base[14];
            T23 = W_base[15];
            cr_base[rsoff[8]] = T21 * T22 - T23 * T24;
            ci_base[rsoff[8]] = T23 * T22 + T21 * T24;
        }
    }
    {
        E T1C, T1I, T1G, T1K;
        {
            E T1A, T1B, T1E, T1F;
            T1A = T12 + T15;
            T1B = T1p + T1s;
            T1C = T1A - T1B;
            T1I = T1A + T1B;
            T1E = T1i + T1l;
            T1F = T19 + T1c;
            T1G = T1E - T1F;
            T1K = T1E + T1F;
        }
        {
            E T1z, T1D, T1H, T1J;
            T1z = W_base[18];
            T1D = W_base[19];
            cr_base[rsoff[10]] = T1z * T1C - T1D * T1G;
            ci_base[rsoff[10]] = T1D * T1C + T1z * T1G;
            T1H = W_base[6];
            T1J = W_base[7];
            cr_base[rsoff[4]] = T1H * T1I - T1J * T1K;
            ci_base[rsoff[4]] = T1J * T1I + T1H * T1K;
        }
    }
    {
        E T1e, T1w, T1u, T1y;
        {
            E T16, T1d, T1m, T1t;
            T16 = T12 - T15;
            T1d = T19 - T1c;
            T1e = T16 - T1d;
            T1w = T16 + T1d;
            T1m = T1i - T1l;
            T1t = T1p - T1s;
            T1u = T1m + T1t;
            T1y = T1m - T1t;
        }
        {
            E TZ, T1f, T1v, T1x;
            TZ = W_base[0];
            T1f = W_base[1];
            cr_base[rsoff[1]] = TZ * T1e - T1f * T1u;
            ci_base[rsoff[1]] = TZ * T1u + T1f * T1e;
            T1v = W_base[12];
            T1x = W_base[13];
            cr_base[rsoff[7]] = T1v * T1w - T1x * T1y;
            ci_base[rsoff[7]] = T1v * T1y + T1x * T1w;
        }
    }
}
}
