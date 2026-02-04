#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *rio;
extern R *iio;
extern  R *W;
extern stride rs;
extern stride vs;
extern INT mb;
extern INT me;
extern INT ms;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + (mb * 6); m < me; m = m + 1 , rio = rio + ms , iio = iio + ms , W = W + 6 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (vs) = (vs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, Te, Tb, Tq, T6, T8, Th, Tr, Tv, TG, TD, TS, Ty, TA, TJ;
    E TT, TX, T18, T15, T1k, T10, T12, T1b, T1l, T1p, T1A, T1x, T1M, T1s, T1u;
    E T1D, T1N;
    const INT rs0 = rs[0], rs1 = rs[1], rs2 = rs[2], rs3 = rs[3];
    const INT vs1 = vs[1], vs2 = vs[2], vs3 = vs[3];
    R * restrict rbase = rio;
    R * restrict ibase = iio;

    {
        E T1, T2, T9, Ta;
        T1 = rbase[0];
        T2 = rbase[rs2];
        T3 = T1 + T2;
        Te = T1 - T2;
        T9 = ibase[0];
        Ta = ibase[rs2];
        Tb = T9 - Ta;
        Tq = T9 + Ta;
    }
    {
        E T4, T5, Tf, Tg;
        T4 = rbase[rs1];
        T5 = rbase[rs1 + rs3];
        T6 = T4 + T5;
        T8 = T4 - T5;
        Tf = ibase[rs1];
        Tg = ibase[rs1 + rs3];
        Th = Tf - Tg;
        Tr = Tf + Tg;
    }
    {
        E Tt, Tu, TB, TC;
        Tt = rbase[vs1];
        Tu = rbase[vs1 + rs2];
        Tv = Tt + Tu;
        TG = Tt - Tu;
        TB = ibase[vs1];
        TC = ibase[vs1 + rs2];
        TD = TB - TC;
        TS = TB + TC;
    }
    {
        E Tw, Tx, TH, TI;
        Tw = rbase[vs1 + rs1];
        Tx = rbase[vs1 + rs1 + rs3];
        Ty = Tw + Tx;
        TA = Tw - Tx;
        TH = ibase[vs1 + rs1];
        TI = ibase[vs1 + rs1 + rs3];
        TJ = TH - TI;
        TT = TH + TI;
    }
    {
        E TV, TW, T13, T14;
        TV = rbase[vs2];
        TW = rbase[vs2 + rs2];
        TX = TV + TW;
        T18 = TV - TW;
        T13 = ibase[vs2];
        T14 = ibase[vs2 + rs2];
        T15 = T13 - T14;
        T1k = T13 + T14;
    }
    {
        E TY, TZ, T19, T1a;
        TY = rbase[vs2 + rs1];
        TZ = rbase[vs2 + rs1 + rs3];
        T10 = TY + TZ;
        T12 = TY - TZ;
        T19 = ibase[vs2 + rs1];
        T1a = ibase[vs2 + rs1 + rs3];
        T1b = T19 - T1a;
        T1l = T19 + T1a;
    }
    {
        E T1n, T1o, T1v, T1w;
        T1n = rbase[vs3];
        T1o = rbase[vs3 + rs2];
        T1p = T1n + T1o;
        T1A = T1n - T1o;
        T1v = ibase[vs3];
        T1w = ibase[vs3 + rs2];
        T1x = T1v - T1w;
        T1M = T1v + T1w;
    }
    {
        E T1q, T1r, T1B, T1C;
        T1q = rbase[vs3 + rs1];
        T1r = rbase[vs3 + rs1 + rs3];
        T1s = T1q + T1r;
        T1u = T1q - T1r;
        T1B = ibase[vs3 + rs1];
        T1C = ibase[vs3 + rs1 + rs3];
        T1D = T1B - T1C;
        T1N = T1B + T1C;
    }

    rbase[0] = T3 + T6;
    ibase[0] = Tq + Tr;
    rbase[rs1] = Tv + Ty;
    ibase[rs1] = TS + TT;
    rbase[rs2] = TX + T10;
    ibase[rs2] = T1k + T1l;
    ibase[rs3] = T1M + T1N;
    rbase[rs3] = T1p + T1s;

    {
        E Tc, Ti, T7, Td;
        Tc = T8 + Tb;
        Ti = Te - Th;
        T7 = W[4];
        Td = W[5];
        ibase[vs3] = (T7 * Tc) - (Td * Ti);
        rbase[vs3] = (Td * Tc) + (T7 * Ti);
    }
    {
        E T1K, T1O, T1J, T1L;
        T1K = T1p - T1s;
        T1O = T1M - T1N;
        T1J = W[2];
        T1L = W[3];
        rbase[vs2 + rs3] = (T1J * T1K) + (T1L * T1O);
        ibase[vs2 + rs3] = (T1J * T1O) - (T1L * T1K);
    }
    {
        E Tk, Tm, Tj, Tl;
        Tk = Tb - T8;
        Tm = Te + Th;
        Tj = W[0];
        Tl = W[1];
        ibase[vs1] = (Tj * Tk) - (Tl * Tm);
        rbase[vs1] = (Tl * Tk) + (Tj * Tm);
    }
    {
        E To, Ts, Tn, Tp;
        To = T3 - T6;
        Ts = Tq - Tr;
        Tn = W[2];
        Tp = W[3];
        rbase[vs2] = (Tn * To) + (Tp * Ts);
        ibase[vs2] = (Tn * Ts) - (Tp * To);
    }
    {
        E T16, T1c, T11, T17;
        T16 = T12 + T15;
        T1c = T18 - T1b;
        T11 = W[4];
        T17 = W[5];
        ibase[vs3 + rs2] = (T11 * T16) - (T17 * T1c);
        rbase[vs3 + rs2] = (T17 * T16) + (T11 * T1c);
    }
    {
        E T1G, T1I, T1F, T1H;
        T1G = T1x - T1u;
        T1I = T1A + T1D;
        T1F = W[0];
        T1H = W[1];
        ibase[vs1 + rs3] = (T1F * T1G) - (T1H * T1I);
        rbase[vs1 + rs3] = (T1H * T1G) + (T1F * T1I);
    }
    {
        E TQ, TU, TP, TR;
        TQ = Tv - Ty;
        TU = TS - TT;
        TP = W[2];
        TR = W[3];
        rbase[vs2 + rs1] = (TP * TQ) + (TR * TU);
        ibase[vs2 + rs1] = (TP * TU) - (TR * TQ);
    }
    {
        E T1e, T1g, T1d, T1f;
        T1e = T15 - T12;
        T1g = T18 + T1b;
        T1d = W[0];
        T1f = W[1];
        ibase[vs1 + rs2] = (T1d * T1e) - (T1f * T1g);
        rbase[vs1 + rs2] = (T1f * T1e) + (T1d * T1g);
    }
    {
        E T1i, T1m, T1h, T1j;
        T1i = TX - T10;
        T1m = T1k - T1l;
        T1h = W[2];
        T1j = W[3];
        rbase[vs2 + rs2] = (T1h * T1i) + (T1j * T1m);
        ibase[vs2 + rs2] = (T1h * T1m) - (T1j * T1i);
    }
    {
        E T1y, T1E, T1t, T1z;
        T1y = T1u + T1x;
        T1E = T1A - T1D;
        T1t = W[4];
        T1z = W[5];
        ibase[vs3 + rs3] = (T1t * T1y) - (T1z * T1E);
        rbase[vs3 + rs3] = (T1z * T1y) + (T1t * T1E);
    }
    {
        E TM, TO, TL, TN;
        TM = TD - TA;
        TO = TG + TJ;
        TL = W[0];
        TN = W[1];
        ibase[vs1 + rs1] = (TL * TM) - (TN * TO);
        rbase[vs1 + rs1] = (TN * TM) + (TL * TO);
    }
    {
        E TE, TK, Tz, TF;
        TE = TA + TD;
        TK = TG - TJ;
        Tz = W[4];
        TF = W[5];
        ibase[vs3 + rs1] = (Tz * TE) - (TF * TK);
        rbase[vs3 + rs1] = (TF * TE) + (Tz * TK);
    }
}
}
