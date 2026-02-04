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
extern  E KP587785252;
extern  E KP951056516;
extern  E KP250000000;
extern  E KP559016994;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (m = mb, W = W + ((mb - 1) * 18); m < me; m = m + 1, cr = cr + ms, ci = ci - ms, W = W + 18, (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
        E T7, T1R, TT, T1C, TF, TQ, TR, T1o, T1p, T1P, TX, TY, TZ, T1d, T1g;
        E T1x, Ti, Tt, Tu, T1r, T1s, T1O, TU, TV, TW, T16, T19, T1y;
        {
            E T1, T1A, T6, T1B;
            T1 = cr[0];
            T1A = ci[0];
            {
                E T3, T5, T2, T4;
                T3 = cr[(rs[5])];
                T5 = ci[(rs[5])];
                T2 = W[8];
                T4 = W[9];
                T6 = (((T2) * (T3)) + (T4 * T5));
                T1B = ((T2 * T5) - ((T4) * (T3)));
            }
            T7 = T1 - T6;
            T1R = T1B + T1A;
            TT = T1 + T6;
            T1C = T1A - T1B;
        }
        {
            E Tz, T1b, TP, T1e, TE, T1c, TK, T1f;
            {
                E Tw, Ty, Tv, Tx;
                Tw = cr[(rs[4])];
                Ty = ci[(rs[4])];
                Tv = W[6];
                Tx = W[7];
                Tz = (((Tv) * (Tw)) + (Tx * Ty));
                T1b = ((Tv * Ty) - ((Tx) * (Tw)));
            }
            {
                E TM, TO, TL, TN;
                TM = cr[(rs[1])];
                TO = ci[(rs[1])];
                TL = W[0];
                TN = W[1];
                TP = (((TL) * (TM)) + (TN * TO));
                T1e = ((TL * TO) - ((TN) * (TM)));
            }
            {
                E TB, TD, TA, TC;
                TB = cr[(rs[9])];
                TD = ci[(rs[9])];
                TA = W[16];
                TC = W[17];
                TE = (((TA) * (TB)) + (TC * TD));
                T1c = ((TA * TD) - ((TC) * (TB)));
            }
            {
                E TH, TJ, TG, TI;
                TH = cr[(rs[6])];
                TJ = ci[(rs[6])];
                TG = W[10];
                TI = W[11];
                TK = (((TG) * (TH)) + (TI * TJ));
                T1f = ((TG * TJ) - ((TI) * (TH)));
            }
            TF = Tz - TE;
            TQ = TK - TP;
            TR = TF + TQ;
            T1o = T1b + T1c;
            T1p = T1f + T1e;
            T1P = T1o + T1p;
            TX = Tz + TE;
            TY = TK + TP;
            TZ = TX + TY;
            T1d = T1b - T1c;
            T1g = T1e - T1f;
            T1x = T1g - T1d;
        }
        {
            E Tc, T14, Ts, T18, Th, T15, Tn, T17;
            {
                E T9, Tb, T8, Ta;
                T9 = cr[(rs[2])];
                Tb = ci[(rs[2])];
                T8 = W[2];
                Ta = W[3];
                Tc = (((T8) * (T9)) + (Ta * Tb));
                T14 = ((T8 * Tb) - ((Ta) * (T9)));
            }
            {
                E Tp, Tr, To, Tq;
                Tp = cr[(rs[3])];
                Tr = ci[(rs[3])];
                To = W[4];
                Tq = W[5];
                Ts = (((To) * (Tp)) + (Tq * Tr));
                T18 = ((To * Tr) - ((Tq) * (Tp)));
            }
            {
                E Te, Tg, Td, Tf;
                Te = cr[(rs[7])];
                Tg = ci[(rs[7])];
                Td = W[12];
                Tf = W[13];
                Th = (((Td) * (Te)) + (Tf * Tg));
                T15 = ((Td * Tg) - ((Tf) * (Te)));
            }
            {
                E Tk, Tm, Tj, Tl;
                Tk = cr[(rs[8])];
                Tm = ci[(rs[8])];
                Tj = W[14];
                Tl = W[15];
                Tn = (((Tj) * (Tk)) + (Tl * Tm));
                T17 = ((Tj * Tm) - ((Tl) * (Tk)));
            }
            Ti = Tc - Th;
            Tt = Tn - Ts;
            Tu = Ti + Tt;
            T1r = T14 + T15;
            T1s = T17 + T18;
            T1O = T1r + T1s;
            TU = Tc + Th;
            TV = Tn + Ts;
            TW = TU + TV;
            T16 = T14 - T15;
            T19 = T17 - T18;
            T1y = T16 + T19;
        }
        {
            E T11, TS, T12, T1i, T1k, T1a, T1h, T1j, T13;
            T11 = KP559016994 * (Tu - TR);
            TS = Tu + TR;
            T12 = ((T7) - ((KP250000000) * (TS)));
            T1a = T16 - T19;
            T1h = T1d + T1g;
            T1i = (((KP951056516) * (T1a)) + (KP587785252 * T1h));
            T1k = ((KP951056516 * T1h) - ((KP587785252) * (T1a)));
            ci[(rs[4])] = T7 + TS;
            T1j = T12 - T11;
            ci[(rs[2])] = T1j - T1k;
            cr[(rs[3])] = T1j + T1k;
            T13 = T11 + T12;
            ci[0] = T13 - T1i;
            cr[(rs[1])] = T13 + T1i;
        }
        {
            E T1m, T10, T1l, T1u, T1w, T1q, T1t, T1v, T1n;
            T1m = KP559016994 * (TW - TZ);
            T10 = TW + TZ;
            T1l = ((TT) - ((KP250000000) * (T10)));
            T1q = T1o - T1p;
            T1t = T1r - T1s;
            T1u = ((KP951056516 * T1q) - ((KP587785252) * (T1t)));
            T1w = (((KP951056516) * (T1t)) + (KP587785252 * T1q));
            cr[0] = TT + T10;
            T1v = T1m + T1l;
            cr[(rs[4])] = T1v - T1w;
            ci[(rs[3])] = T1v + T1w;
            T1n = T1l - T1m;
            cr[(rs[2])] = T1n - T1u;
            ci[(rs[1])] = T1n + T1u;
        }
        {
            E T1H, T1z, T1G, T1F, T1J, T1D, T1E, T1K, T1I;
            T1H = KP559016994 * (T1y + T1x);
            T1z = T1x - T1y;
            T1G = (((KP250000000) * (T1z)) + (T1C));
            T1D = Ti - Tt;
            T1E = TQ - TF;
            T1F = (((KP587785252) * (T1D)) + (KP951056516 * T1E));
            T1J = ((KP587785252 * T1E) - ((KP951056516) * (T1D)));
            cr[(rs[5])] = T1z - T1C;
            T1K = T1H + T1G;
            cr[(rs[9])] = T1J - T1K;
            ci[(rs[8])] = T1J + T1K;
            T1I = T1G - T1H;
            cr[(rs[7])] = T1F - T1I;
            ci[(rs[6])] = T1F + T1I;
        }
        {
            E T1Q, T1S, T1T, T1N, T1V, T1L, T1M, T1W, T1U;
            T1Q = KP559016994 * (T1O - T1P);
            T1S = T1O + T1P;
            T1T = ((T1R) - ((KP250000000) * (T1S)));
            T1L = TU - TV;
            T1M = TX - TY;
            T1N = (((KP951056516) * (T1L)) + (KP587785252 * T1M));
            T1V = ((KP951056516 * T1M) - ((KP587785252) * (T1L)));
            ci[(rs[9])] = T1S + T1R;
            T1W = T1T - T1Q;
            cr[(rs[8])] = T1V - T1W;
            ci[(rs[7])] = T1V + T1W;
            T1U = T1Q + T1T;
            cr[(rs[6])] = T1N - T1U;
            ci[(rs[5])] = T1N + T1U;
        }
    }
}
