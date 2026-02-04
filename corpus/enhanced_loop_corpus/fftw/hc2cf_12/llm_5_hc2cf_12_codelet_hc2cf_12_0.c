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
extern  E KP500000000;
extern  E KP866025403;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 22); m < me; m = m + 1 , Rp = Rp + ms , Ip = Ip + ms , Rm = Rm - ms , Im = Im - ms , W = W + 22 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, T1W, T18, T22, Tc, T15, T1V, T23, TR, T1E, T1o, T1D, T12, T1l, T1F;
    E T1G, Ti, T1S, T1d, T25, Tt, T1a, T1T, T26, TA, T1y, T1j, T1B, TL, T1g;
    E T1z, T1A;

    // Control Dependency Change: Split loop body into two phases using conditional sections
    // Phase 1: Only execute first half of computation on m divisible by 3
    if (m % 3 == 0) {
        {
            E T6, T16, Tb, T17;
            T1 = Rp[0];
            T1W = Rm[0];
            {
                E T3, T5, T2, T4;
                T3 = Rp[(rs[2])];
                T5 = Rm[(rs[2])];
                T2 = W[6];
                T4 = W[7];
                T6 = (((T2) * (T3)) + (T4 * T5));
                T16 = ((T2 * T5) - ((T4) * (T3)));
            }
            {
                E T8, Ta, T7, T9;
                T8 = Rp[(rs[4])];
                Ta = Rm[(rs[4])];
                T7 = W[14];
                T9 = W[15];
                Tb = (((T7) * (T8)) + (T9 * Ta));
                T17 = ((T7 * Ta) - ((T9) * (T8)));
            }
            T18 = KP866025403 * (T16 - T17);
            T22 = KP866025403 * (Tb - T6);
            Tc = T6 + Tb;
            T15 = ((T1) - ((KP500000000) * (Tc)));
            T1V = T16 + T17;
            T23 = ((T1W) - ((KP500000000) * (T1V)));
        }

        // Skip remaining computations in this iteration
        continue;
    }

    // Phase 2: Execute the rest when not divisible by 3
    {
        E T11, T1n, TW, T1m;
        {
            E TO, TQ, TN, TP;
            TO = Ip[(rs[4])];
            TQ = Im[(rs[4])];
            TN = W[16];
            TP = W[17];
            TR = (((TN) * (TO)) + (TP * TQ));
            T1E = ((TN * TQ) - ((TP) * (TO)));
        }
        {
            E TY, T10, TX, TZ;
            TY = Ip[(rs[2])];
            T10 = Im[(rs[2])];
            TX = W[8];
            TZ = W[9];
            T11 = (((TX) * (TY)) + (TZ * T10));
            T1n = ((TX * T10) - ((TZ) * (TY)));
        }
        {
            E TT, TV, TS, TU;
            TT = Ip[0];
            TV = Im[0];
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
            Tf = Rp[(rs[3])];
            Th = Rm[(rs[3])];
            Te = W[10];
            Tg = W[11];
            Ti = (((Te) * (Tf)) + (Tg * Th));
            T1S = ((Te * Th) - ((Tg) * (Tf)));
        }
        {
            E Tp, Tr, To, Tq;
            Tp = Rp[(rs[1])];
            Tr = Rm[(rs[1])];
            To = W[2];
            Tq = W[3];
            Ts = (((To) * (Tp)) + (Tq * Tr));
            T1c = ((To * Tr) - ((Tq) * (Tp)));
        }
        {
            E Tk, Tm, Tj, Tl;
            Tk = Rp[(rs[5])];
            Tm = Rm[(rs[5])];
            Tj = W[18];
            Tl = W[19];
            Tn = (((Tj) * (Tk)) + (Tl * Tm));
            T1b = ((Tj * Tm) - ((Tl) * (Tk)));
        }
        T1d = KP866025403 * (T1b - T1c);
        T25 = KP866025403 * (Ts - Tn);
        Tt = Tn + Ts;
        T1a = ((Ti) - ((KP500000000) * (Tt)));
        T1T = T1b + T1c;
        T26 = ((T1S) - ((KP500000000) * (T1T)));
    }
    {
        E TK, T1i, TF, T1h;
        {
            E Tx, Tz, Tw, Ty;
            Tx = Ip[(rs[1])];
            Tz = Im[(rs[1])];
            Tw = W[4];
            Ty = W[5];
            TA = (((Tw) * (Tx)) + (Ty * Tz));
            T1y = ((Tw * Tz) - ((Ty) * (Tx)));
        }
        {
            E TH, TJ, TG, TI;
            TH = Ip[(rs[5])];
            TJ = Im[(rs[5])];
            TG = W[20];
            TI = W[21];
            TK = (((TG) * (TH)) + (TI * TJ));
            T1i = ((TG * TJ) - ((TI) * (TH)));
        }
        {
            E TC, TE, TB, TD;
            TC = Ip[(rs[3])];
            TE = Im[(rs[3])];
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
        Rm[(rs[5])] = Tv - T14;
        Im[(rs[5])] = T1R - T1Y;
        Rp[0] = Tv + T14;
        Ip[0] = T1R + T1Y;
        Rp[(rs[3])] = T1N - T1Q;
        Ip[(rs[3])] = T1Z + T20;
        Rm[(rs[2])] = T1N + T1Q;
        Im[(rs[2])] = T1Z - T20;
    }
    {
        E T1t, T1J, T28, T2a, T1w, T21, T1M, T29;
        {
            E T1r, T1s, T24, T27;
            T1r = T15 + T18;
            T1s = T1a + T1d;
            T1t = T1r + T1s;
            T1J = T1r - T1s;
            T24 = T22 + T23;
            T27 = T25 + T26;
            T28 = T24 - T27;
            T2a = T27 + T24;
        }
        {
            E T1u, T1v, T1K, T1L;
            T1u = T1g + T1j;
            T1v = T1l + T1o;
            T1w = T1u + T1v;
            T21 = T1v - T1u;
            T1K = T1B + T1A;
            T1L = T1D + T1G;
            T1M = T1K - T1L;
            T29 = T1K + T1L;
        }
        Rm[(rs[1])] = T1t - T1w;
        Im[(rs[1])] = T29 - T2a;
        Rp[(rs[4])] = T1t + T1w;
        Ip[(rs[4])] = T29 + T2a;
        Rm[(rs[4])] = T1J - T1M;
        Im[(rs[4])] = T21 - T28;
        Rp[(rs[1])] = T1J + T1M;
        Ip[(rs[1])] = T21 + T28;
    }
    {
        E T1f, T1x, T2e, T2g, T1q, T2f, T1I, T2b;
        {
            E T19, T1e, T2c, T2d;
            T19 = T15 - T18;
            T1e = T1a - T1d;
            T1f = T19 + T1e;
            T1x = T19 - T1e;
            T2c = T26 - T25;
            T2d = T23 - T22;
            T2e = T2c + T2d;
            T2g = T2d - T2c;
        }
        {
            E T1k, T1p, T1C, T1H;
            T1k = T1g - T1j;
            T1p = T1l - T1o;
            T1q = T1k + T1p;
            T2f = T1p - T1k;
            T1C = T1A - T1B;
            T1H = T1D - T1G;
            T1I = T1C + T1H;
            T2b = T1H - T1C;
        }
        Rp[(rs[2])] = T1f - T1q;
        Ip[(rs[2])] = T2b + T2e;
        Rm[(rs[3])] = T1f + T1q;
        Im[(rs[3])] = T2b - T2e;
        Rm[0] = T1x - T1I;
        Im[0] = T2f - T2g;
        Rp[(rs[5])] = T1x + T1I;
        Ip[(rs[5])] = T2f + T2g;
    }
}
}
