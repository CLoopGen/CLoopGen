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
    E T1, T1W, T18, T23, Tc, T15, T1V, T22, TR, T1E, T1o, T1D, T12, T1l, T1F;
    E T1G, Ti, T1S, T1d, T26, Tt, T1a, T1T, T25, TA, T1y, T1j, T1B, TL, T1g;
    E T1z, T1A;
    {
        E T6, T16, Tb, T17;
        T1 = cr[0];
        T1W = ci[0];
        {
            E T3, T5, T2, T4;
            T3 = cr[(rs[4])];
            T5 = ci[(rs[4])];
            T2 = W[6];
            T4 = W[7];
            T6 = (((T2) * (T3)) + (T4 * T5));
            T16 = ((T2 * T5) - ((T4) * (T3)));
        }
        {
            E T8, Ta, T7, T9;
            T8 = cr[(rs[8])];
            Ta = ci[(rs[8])];
            T7 = W[14];
            T9 = W[15];
            Tb = (((T7) * (T8)) + (T9 * Ta));
            T17 = ((T7 * Ta) - ((T9) * (T8)));
        }
        T18 = KP866025403 * (T16 - T17);
        T23 = KP866025403 * (Tb - T6);
        Tc = T6 + Tb;
        T15 = ((T1) - ((KP500000000) * (Tc)));
        T1V = T16 + T17;
        T22 = ((T1W) - ((KP500000000) * (T1V)));
    }
    {
        E T11, T1n, TW, T1m;
        {
            E TO, TQ, TN, TP;
            TO = cr[(rs[9])];
            TQ = ci[(rs[9])];
            TN = W[16];
            TP = W[17];
            TR = (((TN) * (TO)) + (TP * TQ));
            T1E = ((TN * TQ) - ((TP) * (TO)));
        }
        {
            E TY, T10, TX, TZ;
            TY = cr[(rs[5])];
            T10 = ci[(rs[5])];
            TX = W[8];
            TZ = W[9];
            T11 = (((TX) * (TY)) + (TZ * T10));
            T1n = ((TX * T10) - ((TZ) * (TY)));
        }
        {
            E TT, TV, TS, TU;
            TT = cr[(rs[1])];
            TV = ci[(rs[1])];
            TS = W[0];
            TU = W[1];
            TW = (((TS) * (TT)) + (TU * TV));
            T1m = ((TS * TV) - ((TU) * (TT)));
        }
        T1o = KP866025403 * (T1m - T1n);
        T1D = KP866025403 * (T11 - TW);
        T12 = TW + T11;
        T1l = ((TR) - ((KP500000000) * (T12)));
        T1F = T1m + T1n;
        T1G = ((T1E) - ((KP500000000) * (T1F)));
    }
    {
        E Ts, T1c, Tn, T1b;
        {
            E Tf, Th, Te, Tg;
            Tf = cr[(rs[6])];
            Th = ci[(rs[6])];
            Te = W[10];
            Tg = W[11];
            Ti = (((Te) * (Tf)) + (Tg * Th));
            T1S = ((Te * Th) - ((Tg) * (Tf)));
        }
        {
            E Tp, Tr, To, Tq;
            Tp = cr[(rs[2])];
            Tr = ci[(rs[2])];
            To = W[2];
            Tq = W[3];
            Ts = (((To) * (Tp)) + (Tq * Tr));
            T1c = ((To * Tr) - ((Tq) * (Tp)));
        }
        {
            E Tk, Tm, Tj, Tl;
            Tk = cr[(rs[10])];
            Tm = ci[(rs[10])];
            Tj = W[18];
            Tl = W[19];
            Tn = (((Tj) * (Tk)) + (Tl * Tm));
            T1b = ((Tj * Tm) - ((Tl) * (Tk)));
        }
        T1d = KP866025403 * (T1b - T1c);
        T26 = KP866025403 * (Ts - Tn);
        Tt = Tn + Ts;
        T1a = ((Ti) - ((KP500000000) * (Tt)));
        T1T = T1b + T1c;
        T25 = ((T1S) - ((KP500000000) * (T1T)));
    }
    {
        E TK, T1i, TF, T1h;
        {
            E Tx, Tz, Tw, Ty;
            Tx = cr[(rs[3])];
            Tz = ci[(rs[3])];
            Tw = W[4];
            Ty = W[5];
            TA = (((Tw) * (Tx)) + (Ty * Tz));
            T1y = ((Tw * Tz) - ((Ty) * (Tx)));
        }
        {
            E TH, TJ, TG, TI;
            TH = cr[(rs[11])];
            TJ = ci[(rs[11])];
            TG = W[20];
            TI = W[21];
            TK = (((TG) * (TH)) + (TI * TJ));
            T1i = ((TG * TJ) - ((TI) * (TH)));
        }
        {
            E TC, TE, TB, TD;
            TC = cr[(rs[7])];
            TE = ci[(rs[7])];
            TB = W[12];
            TD = W[13];
            TF = (((TB) * (TC)) + (TD * TE));
            T1h = ((TB * TE) - ((TD) * (TC)));
        }
        T1j = KP866025403 * (T1h - T1i);
        T1B = KP866025403 * (TK - TF);
        TL = TF + TK;
        T1g = ((TA) - ((KP500000000) * (TL)));
        T1z = T1h + T1i;
        T1A = ((T1y) - ((KP500000000) * (T1z)));
    }
    {
        E Tv, T1N, T1Y, T20, T14, T1Z, T1Q, T1R;
        {
            E Td, Tu, T1U, T1X;
            Td = T1 + Tc;
            Tu = Ti + Tt;
            Tv = Td + Tu;
            T1N = Td - Tu;
            T1U = T1S + T1T;
            T1X = T1V + T1W;
            T1Y = T1U + T1X;
            T20 = T1X - T1U;
        }
        {
            E TM, T13, T1O, T1P;
            TM = TA + TL;
            T13 = TR + T12;
            T14 = TM + T13;
            T1Z = TM - T13;
            T1O = T1y + T1z;
            T1P = T1E + T1F;
            T1Q = T1O - T1P;
            T1R = T1O + T1P;
        }
        ci[(rs[5])] = Tv - T14;
        cr[(rs[9])] = T1Z - T20;
        ci[(rs[8])] = T1Z + T20;
        cr[0] = Tv + T14;
        cr[(rs[3])] = T1N - T1Q;
        cr[(rs[6])] = T1R - T1Y;
        ci[(rs[11])] = T1R + T1Y;
        ci[(rs[2])] = T1N + T1Q;
    }
    {
        E T1f, T1x, T28, T2a, T1q, T21, T1I, T29;
        {
            E T19, T1e, T24, T27;
            T19 = T15 - T18;
            T1e = T1a - T1d;
            T1f = T19 + T1e;
            T1x = T19 - T1e;
            T24 = T22 - T23;
            T27 = T25 - T26;
            T28 = T24 - T27;
            T2a = T27 + T24;
        }
        {
            E T1k, T1p, T1C, T1H;
            T1k = T1g - T1j;
            T1p = T1l - T1o;
            T1q = T1k + T1p;
            T21 = T1p - T1k;
            T1C = T1A - T1B;
            T1H = T1D - T1G;
            T1I = T1C + T1H;
            T29 = T1H - T1C;
        }
        cr[(rs[2])] = T1f - T1q;
        cr[(rs[8])] = T29 - T2a;
        ci[(rs[9])] = T29 + T2a;
        ci[(rs[3])] = T1f + T1q;
        ci[0] = T1x - T1I;
        cr[(rs[11])] = T21 - T28;
        ci[(rs[6])] = T21 + T28;
        cr[(rs[5])] = T1x + T1I;
    }
    {
        E T1t, T1J, T2e, T2g, T1w, T2b, T1M, T2f;
        {
            E T1r, T1s, T2c, T2d;
            T1r = T15 + T18;
            T1s = T1a + T1d;
            T1t = T1r + T1s;
            T1J = T1r - T1s;
            T2c = T23 + T22;
            T2d = T26 + T25;
            T2e = T2c - T2d;
            T2g = T2d + T2c;
        }
        {
            E T1u, T1v, T1K, T1L;
            T1u = T1g + T1j;
            T1v = T1l + T1o;
            T1w = T1u + T1v;
            T2b = T1v - T1u;
            T1K = T1B + T1A;
            T1L = T1D + T1G;
            T1M = T1K - T1L;
            T2f = T1K + T1L;
        }
        ci[(rs[1])] = T1t - T1w;
        cr[(rs[1])] = T1J + T1M;
        cr[(rs[4])] = T1t + T1w;
        ci[(rs[4])] = T1J - T1M;
        cr[(rs[7])] = T2b - T2e;
        ci[(rs[7])] = T2f + T2g;
        ci[(rs[10])] = T2b + T2e;
        cr[(rs[10])] = T2f - T2g;
    }
}

}
