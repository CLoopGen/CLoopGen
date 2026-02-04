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
    for (INT inner = 0; inner < 1; ++inner) {
        {
            E T1, T2, T9, Ta;
            T1 = rio[0];
            T2 = rio[(rs[2])];
            T3 = T1 + T2;
            Te = T1 - T2;
            T9 = iio[0];
            Ta = iio[(rs[2])];
            Tb = T9 - Ta;
            Tq = T9 + Ta;
        }
        {
            E T4, T5, Tf, Tg;
            T4 = rio[(rs[1])];
            T5 = rio[(rs[3])];
            T6 = T4 + T5;
            T8 = T4 - T5;
            Tf = iio[(rs[1])];
            Tg = iio[(rs[3])];
            Th = Tf - Tg;
            Tr = Tf + Tg;
        }
        {
            E Tt, Tu, TB, TC;
            Tt = rio[(vs[1])];
            Tu = rio[(vs[1]) + (rs[2])];
            Tv = Tt + Tu;
            TG = Tt - Tu;
            TB = iio[(vs[1])];
            TC = iio[(vs[1]) + (rs[2])];
            TD = TB - TC;
            TS = TB + TC;
        }
        {
            E Tw, Tx, TH, TI;
            Tw = rio[(vs[1]) + (rs[1])];
            Tx = rio[(vs[1]) + (rs[3])];
            Ty = Tw + Tx;
            TA = Tw - Tx;
            TH = iio[(vs[1]) + (rs[1])];
            TI = iio[(vs[1]) + (rs[3])];
            TJ = TH - TI;
            TT = TH + TI;
        }
        {
            E TV, TW, T13, T14;
            TV = rio[(vs[2])];
            TW = rio[(vs[2]) + (rs[2])];
            TX = TV + TW;
            T18 = TV - TW;
            T13 = iio[(vs[2])];
            T14 = iio[(vs[2]) + (rs[2])];
            T15 = T13 - T14;
            T1k = T13 + T14;
        }
        {
            E TY, TZ, T19, T1a;
            TY = rio[(vs[2]) + (rs[1])];
            TZ = rio[(vs[2]) + (rs[3])];
            T10 = TY + TZ;
            T12 = TY - TZ;
            T19 = iio[(vs[2]) + (rs[1])];
            T1a = iio[(vs[2]) + (rs[3])];
            T1b = T19 - T1a;
            T1l = T19 + T1a;
        }
        {
            E T1n, T1o, T1v, T1w;
            T1n = rio[(vs[3])];
            T1o = rio[(vs[3]) + (rs[2])];
            T1p = T1n + T1o;
            T1A = T1n - T1o;
            T1v = iio[(vs[3])];
            T1w = iio[(vs[3]) + (rs[2])];
            T1x = T1v - T1w;
            T1M = T1v + T1w;
        }
        {
            E T1q, T1r, T1B, T1C;
            T1q = rio[(vs[3]) + (rs[1])];
            T1r = rio[(vs[3]) + (rs[3])];
            T1s = T1q + T1r;
            T1u = T1q - T1r;
            T1B = iio[(vs[3]) + (rs[1])];
            T1C = iio[(vs[3]) + (rs[3])];
            T1D = T1B - T1C;
            T1N = T1B + T1C;
        }
        rio[0] = T3 + T6;
        iio[0] = Tq + Tr;
        rio[(rs[1])] = Tv + Ty;
        iio[(rs[1])] = TS + TT;
        rio[(rs[2])] = TX + T10;
        iio[(rs[2])] = T1k + T1l;
        iio[(rs[3])] = T1M + T1N;
        rio[(rs[3])] = T1p + T1s;
        {
            E Tc, Ti, T7, Td;
            Tc = T8 + Tb;
            Ti = Te - Th;
            T7 = W[4];
            Td = W[5];
            iio[(vs[3])] = ((T7 * Tc) - ((Td) * (Ti)));
            rio[(vs[3])] = (((Td) * (Tc)) + (T7 * Ti));
        }
        {
            E T1K, T1O, T1J, T1L;
            T1K = T1p - T1s;
            T1O = T1M - T1N;
            T1J = W[2];
            T1L = W[3];
            rio[(vs[2]) + (rs[3])] = (((T1J) * (T1K)) + (T1L * T1O));
            iio[(vs[2]) + (rs[3])] = ((T1J * T1O) - ((T1L) * (T1K)));
        }
        {
            E Tk, Tm, Tj, Tl;
            Tk = Tb - T8;
            Tm = Te + Th;
            Tj = W[0];
            Tl = W[1];
            iio[(vs[1])] = ((Tj * Tk) - ((Tl) * (Tm)));
            rio[(vs[1])] = (((Tl) * (Tk)) + (Tj * Tm));
        }
        {
            E To, Ts, Tn, Tp;
            To = T3 - T6;
            Ts = Tq - Tr;
            Tn = W[2];
            Tp = W[3];
            rio[(vs[2])] = (((Tn) * (To)) + (Tp * Ts));
            iio[(vs[2])] = ((Tn * Ts) - ((Tp) * (To)));
        }
        {
            E T16, T1c, T11, T17;
            T16 = T12 + T15;
            T1c = T18 - T1b;
            T11 = W[4];
            T17 = W[5];
            iio[(vs[3]) + (rs[2])] = ((T11 * T16) - ((T17) * (T1c)));
            rio[(vs[3]) + (rs[2])] = (((T17) * (T16)) + (T11 * T1c));
        }
        {
            E T1G, T1I, T1F, T1H;
            T1G = T1x - T1u;
            T1I = T1A + T1D;
            T1F = W[0];
            T1H = W[1];
            iio[(vs[1]) + (rs[3])] = ((T1F * T1G) - ((T1H) * (T1I)));
            rio[(vs[1]) + (rs[3])] = (((T1H) * (T1G)) + (T1F * T1I));
        }
        {
            E TQ, TU, TP, TR;
            TQ = Tv - Ty;
            TU = TS - TT;
            TP = W[2];
            TR = W[3];
            rio[(vs[2]) + (rs[1])] = (((TP) * (TQ)) + (TR * TU));
            iio[(vs[2]) + (rs[1])] = ((TP * TU) - ((TR) * (TQ)));
        }
        {
            E T1e, T1g, T1d, T1f;
            T1e = T15 - T12;
            T1g = T18 + T1b;
            T1d = W[0];
            T1f = W[1];
            iio[(vs[1]) + (rs[2])] = ((T1d * T1e) - ((T1f) * (T1g)));
            rio[(vs[1]) + (rs[2])] = (((T1f) * (T1e)) + (T1d * T1g));
        }
        {
            E T1i, T1m, T1h, T1j;
            T1i = TX - T10;
            T1m = T1k - T1l;
            T1h = W[2];
            T1j = W[3];
            rio[(vs[2]) + (rs[2])] = (((T1h) * (T1i)) + (T1j * T1m));
            iio[(vs[2]) + (rs[2])] = ((T1h * T1m) - ((T1j) * (T1i)));
        }
        {
            E T1y, T1E, T1t, T1z;
            T1y = T1u + T1x;
            T1E = T1A - T1D;
            T1t = W[4];
            T1z = W[5];
            iio[(vs[3]) + (rs[3])] = ((T1t * T1y) - ((T1z) * (T1E)));
            rio[(vs[3]) + (rs[3])] = (((T1z) * (T1y)) + (T1t * T1E));
        }
        {
            E TM, TO, TL, TN;
            TM = TD - TA;
            TO = TG + TJ;
            TL = W[0];
            TN = W[1];
            iio[(vs[1]) + (rs[1])] = ((TL * TM) - ((TN) * (TO)));
            rio[(vs[1]) + (rs[1])] = (((TN) * (TM)) + (TL * TO));
        }
        {
            E TE, TK, Tz, TF;
            TE = TA + TD;
            TK = TG - TJ;
            Tz = W[4];
            TF = W[5];
            iio[(vs[3]) + (rs[1])] = ((Tz * TE) - ((TF) * (TK)));
            rio[(vs[3]) + (rs[1])] = (((TF) * (TE)) + (Tz * TK));
        }
    }
}
}
