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
extern  E KP500000000;
extern  E KP866025403;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + (mb * 22); m < me; m = m + 1 , ri = ri + ms , ii = ii + ms , W = W + 22 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    for (INT inner = 0; inner < 1; ++inner) {
        E T1, T1W, T18, T21, Tc, T15, T1V, T22, TR, T1E, T1o, T1D, T12, T1l, T1F;
        E T1G, Ti, T1S, T1d, T24, Tt, T1a, T1T, T25, TA, T1z, T1j, T1y, TL, T1g;
        E T1A, T1B;
        {
            E T6, T16, Tb, T17;
            T1 = ri[0];
            T1W = ii[0];
            {
                E T3, T5, T2, T4;
                T3 = ri[(rs[4])];
                T5 = ii[(rs[4])];
                T2 = W[6];
                T4 = W[7];
                T6 = (((T2) * (T3)) + (T4 * T5));
                T16 = ((T2 * T5) - ((T4) * (T3)));
            }
            {
                E T8, Ta, T7, T9;
                T8 = ri[(rs[8])];
                Ta = ii[(rs[8])];
                T7 = W[14];
                T9 = W[15];
                Tb = (((T7) * (T8)) + (T9 * Ta));
                T17 = ((T7 * Ta) - ((T9) * (T8)));
            }
            T18 = KP866025403 * (T16 - T17);
            T21 = KP866025403 * (Tb - T6);
            Tc = T6 + Tb;
            T15 = ((T1) - ((KP500000000) * (Tc)));
            T1V = T16 + T17;
            T22 = ((T1W) - ((KP500000000) * (T1V)));
        }
        {
            E T11, T1n, TW, T1m;
            {
                E TO, TQ, TN, TP;
                TO = ri[(rs[9])];
                TQ = ii[(rs[9])];
                TN = W[16];
                TP = W[17];
                TR = (((TN) * (TO)) + (TP * TQ));
                T1E = ((TN * TQ) - ((TP) * (TO)));
            }
            {
                E TY, T10, TX, TZ;
                TY = ri[(rs[5])];
                T10 = ii[(rs[5])];
                TX = W[8];
                TZ = W[9];
                T11 = (((TX) * (TY)) + (TZ * T10));
                T1n = ((TX * T10) - ((TZ) * (TY)));
            }
            {
                E TT, TV, TS, TU;
                TT = ri[(rs[1])];
                TV = ii[(rs[1])];
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
                Tf = ri[(rs[6])];
                Th = ii[(rs[6])];
                Te = W[10];
                Tg = W[11];
                Ti = (((Te) * (Tf)) + (Tg * Th));
                T1S = ((Te * Th) - ((Tg) * (Tf)));
            }
            {
                E Tp, Tr, To, Tq;
                Tp = ri[(rs[2])];
                Tr = ii[(rs[2])];
                To = W[2];
                Tq = W[3];
                Ts = (((To) * (Tp)) + (Tq * Tr));
                T1c = ((To * Tr) - ((Tq) * (Tp)));
            }
            {
                E Tk, Tm, Tj, Tl;
                Tk = ri[(rs[10])];
                Tm = ii[(rs[10])];
                Tj = W[18];
                Tl = W[19];
                Tn = (((Tj) * (Tk)) + (Tl * Tm));
                T1b = ((Tj * Tm) - ((Tl) * (Tk)));
            }
            T1d = KP866025403 * (T1b - T1c);
            T24 = KP866025403 * (Ts - Tn);
            Tt = Tn + Ts;
            T1a = ((Ti) - ((KP500000000) * (Tt)));
            T1T = T1b + T1c;
            T25 = ((T1S) - ((KP500000000) * (T1T)));
        }
        {
            E TK, T1i, TF, T1h;
            {
                E Tx, Tz, Tw, Ty;
                Tx = ri[(rs[3])];
                Tz = ii[(rs[3])];
                Tw = W[4];
                Ty = W[5];
                TA = (((Tw) * (Tx)) + (Ty * Tz));
                T1z = ((Tw * Tz) - ((Ty) * (Tx)));
            }
            {
                E TH, TJ, TG, TI;
                TH = ri[(rs[11])];
                TJ = ii[(rs[11])];
                TG = W[20];
                TI = W[21];
                TK = (((TG) * (TH)) + (TI * TJ));
                T1i = ((TG * TJ) - ((TI) * (TH)));
            }
            {
                E TC, TE, TB, TD;
                TC = ri[(rs[7])];
                TE = ii[(rs[7])];
                TB = W[12];
                TD = W[13];
                TF = (((TB) * (TC)) + (TD * TE));
                T1h = ((TB * TE) - ((TD) * (TC)));
            }
            T1j = KP866025403 * (T1h - T1i);
            T1y = KP866025403 * (TK - TF);
            TL = TF + TK;
            T1g = ((TA) - ((KP500000000) * (TL)));
            T1A = T1h + T1i;
            T1B = ((T1z) - ((KP500000000) * (T1A)));
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
                T1O = T1z + T1A;
                T1P = T1E + T1F;
                T1Q = T1O - T1P;
                T1R = T1O + T1P;
            }
            ri[(rs[6])] = Tv - T14;
            ii[(rs[6])] = T1Y - T1R;
            ri[0] = Tv + T14;
            ii[0] = T1R + T1Y;
            ri[(rs[3])] = T1N - T1Q;
            ii[(rs[3])] = T1Z + T20;
            ri[(rs[9])] = T1N + T1Q;
            ii[(rs[9])] = T20 - T1Z;
        }
        {
            E T1t, T1x, T27, T2a, T1w, T28, T1I, T29;
            {
                E T1r, T1s, T23, T26;
                T1r = T15 + T18;
                T1s = T1a + T1d;
                T1t = T1r + T1s;
                T1x = T1r - T1s;
                T23 = T21 + T22;
                T26 = T24 + T25;
                T27 = T23 - T26;
                T2a = T26 + T23;
            }
            {
                E T1u, T1v, T1C, T1H;
                T1u = T1g + T1j;
                T1v = T1l + T1o;
                T1w = T1u + T1v;
                T28 = T1u - T1v;
                T1C = T1y + T1B;
                T1H = T1D + T1G;
                T1I = T1C - T1H;
                T29 = T1C + T1H;
            }
            ri[(rs[10])] = T1t - T1w;
            ii[(rs[10])] = T2a - T29;
            ri[(rs[4])] = T1t + T1w;
            ii[(rs[4])] = T29 + T2a;
            ri[(rs[7])] = T1x - T1I;
            ii[(rs[7])] = T28 + T27;
            ri[(rs[1])] = T1x + T1I;
            ii[(rs[1])] = T27 - T28;
        }
        {
            E T1f, T1J, T2d, T2f, T1q, T2g, T1M, T2e;
            {
                E T19, T1e, T2b, T2c;
                T19 = T15 - T18;
                T1e = T1a - T1d;
                T1f = T19 + T1e;
                T1J = T19 - T1e;
                T2b = T25 - T24;
                T2c = T22 - T21;
                T2d = T2b + T2c;
                T2f = T2c - T2b;
            }
            {
                E T1k, T1p, T1K, T1L;
                T1k = T1g - T1j;
                T1p = T1l - T1o;
                T1q = T1k + T1p;
                T2g = T1k - T1p;
                T1K = T1B - T1y;
                T1L = T1G - T1D;
                T1M = T1K - T1L;
                T2e = T1K + T1L;
            }
            ri[(rs[2])] = T1f - T1q;
            ii[(rs[2])] = T2d - T2e;
            ri[(rs[8])] = T1f + T1q;
            ii[(rs[8])] = T2e + T2d;
            ri[(rs[11])] = T1J - T1M;
            ii[(rs[11])] = T2g + T2f;
            ri[(rs[5])] = T1J + T1M;
            ii[(rs[5])] = T2f - T2g;
        }
    }
}
}
