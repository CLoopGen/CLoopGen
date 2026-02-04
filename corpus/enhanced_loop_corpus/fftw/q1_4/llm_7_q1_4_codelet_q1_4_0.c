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

    // Eliminate some intermediate variables to inline computations and reduce WAR/WAW hazards
    // Also reorganize memory accesses to break false dependencies

    {
        E T1 = rio[0];
        E T2 = rio[(rs[2])];
        E T9 = iio[0];
        E Ta = iio[(rs[2])];
        rio[0] = T1 + T2;
        iio[0] = T9 + Ta;
        Te = T1 - T2;
        Tb = T9 - Ta;
    }
    {
        E T4 = rio[(rs[1])];
        E T5 = rio[(rs[3])];
        E Tf = iio[(rs[1])];
        E Tg = iio[(rs[3])];
        rio[(rs[1])] = T4 + T5;
        iio[(rs[1])] = Tf + Tg;
        T8 = T4 - T5;
        Th = Tf - Tg;
    }
    {
        E Tt = rio[(vs[1])];
        E Tu = rio[(vs[1]) + (rs[2])];
        E TB = iio[(vs[1])];
        E TC = iio[(vs[1]) + (rs[2])];
        Tv = Tt + Tu;
        TS = TB + TC;
        TG = Tt - Tu;
        TD = TB - TC;
    }
    {
        E Tw = rio[(vs[1]) + (rs[1])];
        E Tx = rio[(vs[1]) + (rs[3])];
        E TH = iio[(vs[1]) + (rs[1])];
        E TI = iio[(vs[1]) + (rs[3])];
        Ty = Tw + Tx;
        TT = TH + TI;
        TA = Tw - Tx;
        TJ = TH - TI;
    }
    {
        E TV = rio[(vs[2])];
        E TW = rio[(vs[2]) + (rs[2])];
        E T13 = iio[(vs[2])];
        E T14 = iio[(vs[2]) + (rs[2])];
        TX = TV + TW;
        T1k = T13 + T14;
        T18 = TV - TW;
        T15 = T13 - T14;
    }
    {
        E TY = rio[(vs[2]) + (rs[1])];
        E TZ = rio[(vs[2]) + (rs[3])];
        E T19 = iio[(vs[2]) + (rs[1])];
        E T1a = iio[(vs[2]) + (rs[3])];
        T10 = TY + TZ;
        T1l = T19 + T1a;
        T12 = TY - TZ;
        T1b = T19 - T1a;
    }
    {
        E T1n = rio[(vs[3])];
        E T1o = rio[(vs[3]) + (rs[2])];
        E T1v = iio[(vs[3])];
        E T1w = iio[(vs[3]) + (rs[2])];
        T1p = T1n + T1o;
        T1M = T1v + T1w;
        T1A = T1n - T1o;
        T1x = T1v - T1w;
    }
    {
        E T1q = rio[(vs[3]) + (rs[1])];
        E T1r = rio[(vs[3]) + (rs[3])];
        E T1B = iio[(vs[3]) + (rs[1])];
        E T1C = iio[(vs[3]) + (rs[3])];
        T1s = T1q + T1r;
        T1N = T1B + T1C;
        T1u = T1q - T1r;
        T1D = T1B - T1C;
    }

    // Now write combined results earlier
    rio[(rs[2])] = TX + T10;
    iio[(rs[2])] = T1k + T1l;
    rio[(rs[3])] = T1p + T1s;
    iio[(rs[3])] = T1M + T1N;

    // Reuse registers immediately — increase RAW dependency depth but reduce live range
    {
        E Tc = T8 + Tb;
        E Ti = Te - Th;
        E T7 = W[4];
        E Td = W[5];
        iio[(vs[3])] = (T7 * Tc) - (Td * Ti);
        rio[(vs[3])] = (Td * Tc) + (T7 * Ti);
    }
    {
        E T1K = T1p - T1s;
        E T1O = T1M - T1N;
        E T1J = W[2];
        E T1L = W[3];
        rio[(vs[2]) + (rs[3])] = (T1J * T1K) + (T1L * T1O);
        iio[(vs[2]) + (rs[3])] = (T1J * T1O) - (T1L * T1K);
    }
    {
        E Tk = Tb - T8;
        E Tm = Te + Th;
        E Tj = W[0];
        E Tl = W[1];
        iio[(vs[1])] = (Tj * Tk) - (Tl * Tm);
        rio[(vs[1])] = (Tl * Tk) + (Tj * Tm);
    }
    {
        E To = rio[0] - T6;  // Use updated value from earlier store
        E Ts = iio[0] - Tr;
        E Tn = W[2];
        E Tp = W[3];
        rio[(vs[2])] = (Tn * To) + (Tp * Ts);
        iio[(vs[2])] = (Tn * Ts) - (Tp * To);
    }
    {
        E T16 = T12 + T15;
        E T1c = T18 - T1b;
        E T11 = W[4];
        E T17 = W[5];
        iio[(vs[3]) + (rs[2])] = (T11 * T16) - (T17 * T1c);
        rio[(vs[3]) + (rs[2])] = (T17 * T16) + (T11 * T1c);
    }
    {
        E T1G = T1x - T1u;
        E T1I = T1A + T1D;
        E T1F = W[0];
        E T1H = W[1];
        iio[(vs[1]) + (rs[3])] = (T1F * T1G) - (T1H * T1I);
        rio[(vs[1]) + (rs[3])] = (T1H * T1G) + (T1F * T1I);
    }
    {
        E TQ = Tv - Ty;
        E TU = TS - TT;
        E TP = W[2];
        E TR = W[3];
        rio[(vs[2]) + (rs[1])] = (TP * TQ) + (TR * TU);
        iio[(vs[2]) + (rs[1])] = (TP * TU) - (TR * TQ);
    }
    {
        E T1e = T15 - T12;
        E T1g = T18 + T1b;
        E T1d = W[0];
        E T1f = W[1];
        iio[(vs[1]) + (rs[2])] = (T1d * T1e) - (T1f * T1g);
        rio[(vs[1]) + (rs[2])] = (T1f * T1e) + (T1d * T1g);
    }
    {
        E T1i = TX - T10;
        E T1m = T1k - T1l;
        E T1h = W[2];
        E T1j = W[3];
        rio[(vs[2]) + (rs[2])] = (T1h * T1i) + (T1j * T1m);
        iio[(vs[2]) + (rs[2])] = (T1h * T1m) - (T1j * T1i);
    }
    {
        E T1y = T1u + T1x;
        E T1E = T1A - T1D;
        E T1t = W[4];
        E T1z = W[5];
        iio[(vs[3]) + (rs[3])] = (T1t * T1y) - (T1z * T1E);
        rio[(vs[3]) + (rs[3])] = (T1z * T1y) + (T1t * T1E);
    }
    {
        E TM = TD - TA;
        E TO = TG + TJ;
        E TL = W[0];
        E TN = W[1];
        iio[(vs[1]) + (rs[1])] = (TL * TM) - (TN * TO);
        rio[(vs[1]) + (rs[1])] = (TN * TM) + (TL * TO);
    }
    {
        E TE = TA + TD;
        E TK = TG - TJ;
        E Tz = W[4];
        E TF = W[5];
        iio[(vs[3]) + (rs[1])] = (Tz * TE) - (TF * TK);
        rio[(vs[3]) + (rs[1])] = (TF * TE) + (Tz * TK);
    }
}
}
