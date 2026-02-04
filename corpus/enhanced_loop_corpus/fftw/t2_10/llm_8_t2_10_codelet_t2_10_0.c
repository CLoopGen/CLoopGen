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
extern  E KP587785252;
extern  E KP951056516;
extern  E KP250000000;
extern  E KP559016994;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + (mb * 6); m < me; m = m + 1 , ri = ri + ms , ii = ii + ms , W = W + 6 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T2, T5, T3, T6, T8, Tm, Tc, Tk, T9, Td, Te, TM, TO, Tg, Tp;
    E Tv, Tx, Tr;
    {
        E T4, Tb, T7, Ta;
        T2 = W[0];
        T5 = W[1];
        T3 = W[2];
        T6 = W[3];
        T4 = T2 * T3;
        Tb = T5 * T3;
        T7 = T5 * T6;
        Ta = T2 * T6;
        T8 = T4 - T7;
        Tm = Ta - Tb;
        Tc = Ta + Tb;
        Tk = T4 + T7;
        T9 = W[4];
        Td = W[5];
        Te = (((T8) * (T9)) + (Tc * Td));
        TM = (((T3) * (T9)) + (T6 * Td));
        TO = ((T3 * Td) - ((T6) * (T9)));
        Tg = ((T8 * Td) - ((Tc) * (T9)));
        Tp = (((Tk) * (T9)) + (Tm * Td));
        Tv = (((T2) * (T9)) + (T5 * Td));
        Tx = ((T2 * Td) - ((T5) * (T9)));
        Tr = ((Tk * Td) - ((Tm) * (T9)));
    }
    {
        E Tj, T1S, TX, T1G, TL, TU, TV, T1s, T1t, T1C, T11, T12, T13, T1h, T1k;
        E T1Q, Tu, TD, TE, T1v, T1w, T1B, TY, TZ, T10, T1a, T1d, T1P;
        {
            E T1, T1F, Ti, T1E, Tf, Th;
            T1 = ri[0];
            T1F = ii[0];
            Tf = ri[(rs[5])];
            Th = ii[(rs[5])];
            Ti = (((Te) * (Tf)) + (Tg * Th));
            T1E = ((Te * Th) - ((Tg) * (Tf)));
            Tj = T1 - Ti;
            T1S = T1F - T1E;
            TX = T1 + Ti;
            T1G = T1E + T1F;
        }
        {
            E TH, T1f, TT, T1j, TK, T1g, TQ, T1i;
            {
                E TF, TG, TR, TS;
                TF = ri[(rs[4])];
                TG = ii[(rs[4])];
                TH = (((T8) * (TF)) + (Tc * TG));
                T1f = ((T8 * TG) - ((Tc) * (TF)));
                TR = ri[(rs[1])];
                TS = ii[(rs[1])];
                TT = (((T2) * (TR)) + (T5 * TS));
                T1j = ((T2 * TS) - ((T5) * (TR)));
            }
            {
                E TI, TJ, TN, TP;
                TI = ri[(rs[9])];
                TJ = ii[(rs[9])];
                TK = (((T9) * (TI)) + (Td * TJ));
                T1g = ((T9 * TJ) - ((Td) * (TI)));
                TN = ri[(rs[6])];
                TP = ii[(rs[6])];
                TQ = (((TM) * (TN)) + (TO * TP));
                T1i = ((TM * TP) - ((TO) * (TN)));
            }
            TL = TH - TK;
            TU = TQ - TT;
            TV = TL + TU;
            T1s = T1f + T1g;
            T1t = T1i + T1j;
            T1C = T1s + T1t;
            T11 = TH + TK;
            T12 = TQ + TT;
            T13 = T11 + T12;
            T1h = T1f - T1g;
            T1k = T1i - T1j;
            T1Q = T1h + T1k;
        }
        {
            E To, T18, TC, T1c, Tt, T19, Tz, T1b;
            {
                E Tl, Tn, TA, TB;
                Tl = ri[(rs[2])];
                Tn = ii[(rs[2])];
                To = (((Tk) * (Tl)) + (Tm * Tn));
                T18 = ((Tk * Tn) - ((Tm) * (Tl)));
                TA = ri[(rs[3])];
                TB = ii[(rs[3])];
                TC = (((T3) * (TA)) + (T6 * TB));
                T1c = ((T3 * TB) - ((T6) * (TA)));
            }
            {
                E Tq, Ts, Tw, Ty;
                Tq = ri[(rs[7])];
                Ts = ii[(rs[7])];
                Tt = (((Tp) * (Tq)) + (Tr * Ts));
                T19 = ((Tp * Ts) - ((Tr) * (Tq)));
                Tw = ri[(rs[8])];
                Ty = ii[(rs[8])];
                Tz = (((Tv) * (Tw)) + (Tx * Ty));
                T1b = ((Tv * Ty) - ((Tx) * (Tw)));
            }
            Tu = To - Tt;
            TD = Tz - TC;
            TE = Tu + TD;
            T1v = T18 + T19;
            T1w = T1b + T1c;
            T1B = T1v + T1w;
            TY = To + Tt;
            TZ = Tz + TC;
            T10 = TY + TZ;
            T1a = T18 - T19;
            T1d = T1b - T1c;
            T1P = T1a + T1d;
        }
        {
            E T15, TW, T16, T1m, T1o, T1e, T1l, T1n, T17;
            T15 = KP559016994 * (TE - TV);
            TW = TE + TV;
            T16 = ((Tj) - ((KP250000000) * (TW)));
            T1e = T1a - T1d;
            T1l = T1h - T1k;
            T1m = (((KP951056516) * (T1e)) + (KP587785252 * T1l));
            T1o = ((KP951056516 * T1l) - ((KP587785252) * (T1e)));
            ri[(rs[5])] = Tj + TW;
            T1n = T16 - T15;
            ri[(rs[7])] = T1n - T1o;
            ri[(rs[3])] = T1n + T1o;
            T17 = T15 + T16;
            ri[(rs[9])] = T17 - T1m;
            ri[(rs[1])] = T17 + T1m;
        }
        {
            E T1R, T1T, T1U, T1Y, T20, T1W, T1X, T1Z, T1V;
            T1R = KP559016994 * (T1P - T1Q);
            T1T = T1P + T1Q;
            T1U = ((T1S) - ((KP250000000) * (T1T)));
            T1W = Tu - TD;
            T1X = TL - TU;
            T1Y = (((KP951056516) * (T1W)) + (KP587785252 * T1X));
            T20 = ((KP951056516 * T1X) - ((KP587785252) * (T1W)));
            ii[(rs[5])] = T1T + T1S;
            T1Z = T1U - T1R;
            ii[(rs[3])] = T1Z - T20;
            ii[(rs[7])] = T20 + T1Z;
            T1V = T1R + T1U;
            ii[(rs[1])] = T1V - T1Y;
            ii[(rs[9])] = T1Y + T1V;
        }
        {
            E T1q, T14, T1p, T1y, T1A, T1u, T1x, T1z, T1r;
            T1q = KP559016994 * (T10 - T13);
            T14 = T10 + T13;
            T1p = ((TX) - ((KP250000000) * (T14)));
            T1u = T1s - T1t;
            T1x = T1v - T1w;
            T1y = ((KP951056516 * T1u) - ((KP587785252) * (T1x)));
            T1A = (((KP951056516) * (T1x)) + (KP587785252 * T1u));
            ri[0] = TX + T14;
            T1z = T1q + T1p;
            ri[(rs[4])] = T1z - T1A;
            ri[(rs[6])] = T1z + T1A;
            T1r = T1p - T1q;
            ri[(rs[2])] = T1r - T1y;
            ri[(rs[8])] = T1r + T1y;
        }
        {
            E T1L, T1D, T1K, T1J, T1N, T1H, T1I, T1O, T1M;
            T1L = KP559016994 * (T1B - T1C);
            T1D = T1B + T1C;
            T1K = ((T1G) - ((KP250000000) * (T1D)));
            T1H = T11 - T12;
            T1I = TY - TZ;
            T1J = ((KP951056516 * T1H) - ((KP587785252) * (T1I)));
            T1N = (((KP951056516) * (T1I)) + (KP587785252 * T1H));
            ii[0] = T1D + T1G;
            T1O = T1L + T1K;
            ii[(rs[4])] = T1N + T1O;
            ii[(rs[6])] = T1O - T1N;
            T1M = T1K - T1L;
            ii[(rs[2])] = T1J + T1M;
            ii[(rs[8])] = T1M - T1J;
        }
    }
}
}
