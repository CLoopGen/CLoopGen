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
for (m = mb , W = W + (mb * 6); m < me; m = m + 1 , rio += ms , iio += ms , W += 6) {
    E T3, Te, Tb, Tq, T6, T8, Th, Tr, Tv, TG, TD, TS, Ty, TA, TJ;
    E TT, TX, T18, T15, T1k, T10, T12, T1b, T1l, T1p, T1A, T1x, T1M, T1s, T1u;
    E T1D, T1N;

    const INT rs0 = 0, rs1 = rs[1], rs2 = rs[2], rs3 = rs[3];
    const INT vs1 = vs[1], vs2 = vs[2], vs3 = vs[3];

    E rbuf[16], ibuf[16];
    INT idx = 0;
    #define STORE_R(I) rbuf[idx++] = rio[I]
    #define STORE_I(I) ibuf[--idx] = iio[I]

    STORE_R(rs0); STORE_R(rs1); STORE_R(rs2); STORE_R(rs3);
    STORE_R(vs1); STORE_R(vs1 + rs1); STORE_R(vs1 + rs2); STORE_R(vs1 + rs3);
    STORE_R(vs2); STORE_R(vs2 + rs1); STORE_R(vs2 + rs2); STORE_R(vs2 + rs3);
    STORE_R(vs3); STORE_R(vs3 + rs1); STORE_R(vs3 + rs2); STORE_R(vs3 + rs3);

    idx = 15;
    STORE_I(rs0); STORE_I(rs1); STORE_I(rs2); STORE_I(rs3);
    STORE_I(vs1); STORE_I(vs1 + rs1); STORE_I(vs1 + rs2); STORE_I(vs1 + rs3);
    STORE_I(vs2); STORE_I(vs2 + rs1); STORE_I(vs2 + rs2); STORE_I(vs2 + rs3);
    STORE_I(vs3); STORE_I(vs3 + rs1); STORE_I(vs3 + rs2); STORE_I(vs3 + rs3);

    {
        E T1 = rbuf[0], T2 = rbuf[2];
        T3 = T1 + T2;
        Te = T1 - T2;
        E T9 = ibuf[0], Ta = ibuf[2];
        Tb = T9 - Ta;
        Tq = T9 + Ta;
    }
    {
        E T4 = rbuf[1], T5 = rbuf[3];
        T6 = T4 + T5;
        T8 = T4 - T5;
        E Tf = ibuf[1], Tg = ibuf[3];
        Th = Tf - Tg;
        Tr = Tf + Tg;
    }
    {
        E Tt = rbuf[4], Tu = rbuf[6];
        Tv = Tt + Tu;
        TG = Tt - Tu;
        E TB = ibuf[4], TC = ibuf[6];
        TD = TB - TC;
        TS = TB + TC;
    }
    {
        E Tw = rbuf[5], Tx = rbuf[7];
        Ty = Tw + Tx;
        TA = Tw - Tx;
        E TH = ibuf[5], TI = ibuf[7];
        TJ = TH - TI;
        TT = TH + TI;
    }
    {
        E TV = rbuf[8], TW = rbuf[10];
        TX = TV + TW;
        T18 = TV - TW;
        E T13 = ibuf[8], T14 = ibuf[10];
        T15 = T13 - T14;
        T1k = T13 + T14;
    }
    {
        E TY = rbuf[9], TZ = rbuf[11];
        T10 = TY + TZ;
        T12 = TY - TZ;
        E T19 = ibuf[9], T1a = ibuf[11];
        T1b = T19 - T1a;
        T1l = T19 + T1a;
    }
    {
        E T1n = rbuf[12], T1o = rbuf[14];
        T1p = T1n + T1o;
        T1A = T1n - T1o;
        E T1v = ibuf[12], T1w = ibuf[14];
        T1x = T1v - T1w;
        T1M = T1v + T1w;
    }
    {
        E T1q = rbuf[13], T1r = rbuf[15];
        T1s = T1q + T1r;
        T1u = T1q - T1r;
        E T1B = ibuf[13], T1C = ibuf[15];
        T1D = T1B - T1C;
        T1N = T1B + T1C;
    }

    rio[0] = T3 + T6;
    iio[0] = Tq + Tr;
    rio[rs1] = Tv + Ty;
    iio[rs1] = TS + TT;
    rio[rs2] = TX + T10;
    iio[rs2] = T1k + T1l;
    iio[rs3] = T1M + T1N;
    rio[rs3] = T1p + T1s;

    {
        E Tc = T8 + Tb, Ti = Te - Th;
        E T7 = W[4], Td = W[5];
        iio[vs3] = (T7 * Tc) - (Td * Ti);
        rio[vs3] = (Td * Tc) + (T7 * Ti);
    }
    {
        E T1K = T1p - T1s, T1O = T1M - T1N;
        E T1J = W[2], T1L = W[3];
        rio[vs2 + rs3] = (T1J * T1K) + (T1L * T1O);
        iio[vs2 + rs3] = (T1J * T1O) - (T1L * T1K);
    }
    {
        E Tk = Tb - T8, Tm = Te + Th;
        E Tj = W[0], Tl = W[1];
        iio[vs1] = (Tj * Tk) - (Tl * Tm);
        rio[vs1] = (Tl * Tk) + (Tj * Tm);
    }
    {
        E To = T3 - T6, Ts = Tq - Tr;
        E Tn = W[2], Tp = W[3];
        rio[vs2] = (Tn * To) + (Tp * Ts);
        iio[vs2] = (Tn * Ts) - (Tp * To);
    }
    {
        E T16 = T12 + T15, T1c = T18 - T1b;
        E T11 = W[4], T17 = W[5];
        iio[vs3 + rs2] = (T11 * T16) - (T17 * T1c);
        rio[vs3 + rs2] = (T17 * T16) + (T11 * T1c);
    }
    {
        E T1G = T1x - T1u, T1I = T1A + T1D;
        E T1F = W[0], T1H = W[1];
        iio[vs1 + rs3] = (T1F * T1G) - (T1H * T1I);
        rio[vs1 + rs3] = (T1H * T1G) + (T1F * T1I);
    }
    {
        E TQ = Tv - Ty, TU = TS - TT;
        E TP = W[2], TR = W[3];
        rio[vs2 + rs1] = (TP * TQ) + (TR * TU);
        iio[vs2 + rs1] = (TP * TU) - (TR * TQ);
    }
    {
        E T1e = T15 - T12, T1g = T18 + T1b;
        E T1d = W[0], T1f = W[1];
        iio[vs1 + rs2] = (T1d * T1e) - (T1f * T1g);
        rio[vs1 + rs2] = (T1f * T1e) + (T1d * T1g);
    }
    {
        E T1i = TX - T10, T1m = T1k - T1l;
        E T1h = W[2], T1j = W[3];
        rio[vs2 + rs2] = (T1h * T1i) + (T1j * T1m);
        iio[vs2 + rs2] = (T1h * T1m) - (T1j * T1i);
    }
    {
        E T1y = T1u + T1x, T1E = T1A - T1D;
        E T1t = W[4], T1z = W[5];
        iio[vs3 + rs3] = (T1t * T1y) - (T1z * T1E);
        rio[vs3 + rs3] = (T1z * T1y) + (T1t * T1E);
    }
    {
        E TM = TD - TA, TO = TG + TJ;
        E TL = W[0], TN = W[1];
        iio[vs1 + rs1] = (TL * TM) - (TN * TO);
        rio[vs1 + rs1] = (TN * TM) + (TL * TO);
    }
    {
        E TE = TA + TD, TK = TG - TJ;
        E Tz = W[4], TF = W[5];
        iio[vs3 + rs1] = (Tz * TE) - (TF * TK);
        rio[vs3 + rs1] = (TF * TE) + (Tz * TK);
    }
}
}
