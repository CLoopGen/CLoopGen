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
extern  E KP951056516;
extern  E KP587785252;
extern  E KP250000000;
extern  E KP559016994;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (m = mb , W = W + ((mb - 1) * 18); m < me; m = m + 1 , Rp = Rp + ms , Ip = Ip + ms , Rm = Rm - ms , Im = Im - ms , W = W + 18 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, TS, TR, T13, Ti, T12, TT, TU, T1g, T1T, Tr, T1s, TJ, T1h, TG;
    E T1m, TK, TL, T1k, T1l, T1b, T1P, TY, T1w;
    {
        E Td, To, Tg, Tp, Th, TQ, T6, Tl, T9, Tm, Ta, TP, T1, T2;
        T1 = Rp[0];
        T2 = Rm[(rs[4])];
        T3 = T1 + T2;
        TS = T1 - T2;
        {
            E Tb, Tc, Te, Tf;
            Tb = Rp[(rs[4])];
            Tc = Rm[0];
            Td = Tb + Tc;
            To = Tb - Tc;
            Te = Rm[(rs[3])];
            Tf = Rp[(rs[1])];
            Tg = Te + Tf;
            Tp = Te - Tf;
        }
        Th = Td + Tg;
        TQ = To + Tp;
        {
            E T4, T5, T7, T8;
            T4 = Rp[(rs[2])];
            T5 = Rm[(rs[2])];
            T6 = T4 + T5;
            Tl = T4 - T5;
            T7 = Rm[(rs[1])];
            T8 = Rp[(rs[3])];
            T9 = T7 + T8;
            Tm = T7 - T8;
        }
        Ta = T6 + T9;
        TP = Tl + Tm;
        TR = KP559016994 * (TP - TQ);
        T13 = KP559016994 * (Ta - Th);
        Ti = Ta + Th;
        T12 = ((T3) - ((KP250000000) * (Ti)));
        TT = TP + TQ;
        TU = ((TS) - ((KP250000000) * (TT)));
        {
            E T1e, T1f, Tn, Tq;
            T1e = T6 - T9;
            T1f = Td - Tg;
            T1g = ((KP587785252 * T1e) - ((KP951056516) * (T1f)));
            T1T = (((KP951056516) * (T1e)) + (KP587785252 * T1f));
            Tn = Tl - Tm;
            Tq = To - Tp;
            Tr = (((KP951056516) * (Tn)) + (KP587785252 * Tq));
            T1s = ((KP587785252 * Tn) - ((KP951056516) * (Tq)));
        }
    }
    {
        E TB, T18, TE, T19, TF, T1j, Tu, T15, Tx, T16, Ty, T1i, TH, TI;
        TH = Ip[0];
        TI = Im[(rs[4])];
        TJ = TH + TI;
        T1h = TH - TI;
        {
            E Tz, TA, TC, TD;
            Tz = Ip[(rs[4])];
            TA = Im[0];
            TB = Tz + TA;
            T18 = Tz - TA;
            TC = Im[(rs[3])];
            TD = Ip[(rs[1])];
            TE = TC + TD;
            T19 = TD - TC;
        }
        TF = TB - TE;
        T1j = T18 + T19;
        {
            E Ts, Tt, Tv, Tw;
            Ts = Ip[(rs[2])];
            Tt = Im[(rs[2])];
            Tu = Ts + Tt;
            T15 = Ts - Tt;
            Tv = Im[(rs[1])];
            Tw = Ip[(rs[3])];
            Tx = Tv + Tw;
            T16 = Tw - Tv;
        }
        Ty = Tu - Tx;
        T1i = T15 + T16;
        TG = KP559016994 * (Ty - TF);
        T1m = KP559016994 * (T1i - T1j);
        TK = Ty + TF;
        TL = ((TJ) - ((KP250000000) * (TK)));
        T1k = T1i + T1j;
        T1l = ((T1h) - ((KP250000000) * (T1k)));
        {
            E T17, T1a, TW, TX;
            T17 = T15 - T16;
            T1a = T18 - T19;
            T1b = ((KP587785252 * T17) - ((KP951056516) * (T1a)));
            T1P = (((KP951056516) * (T17)) + (KP587785252 * T1a));
            TW = Tu + Tx;
            TX = TB + TE;
            TY = (((KP951056516) * (TW)) + (KP587785252 * TX));
            T1w = ((KP587785252 * TW) - ((KP951056516) * (TX)));
        }
    }
    {
        E Tj, T2g, TN, T1H, T1U, T26, TZ, T1J, T1Q, T24, T1c, T1C, T1t, T29, T1o;
        E T1E, T1x, T2b, T20, T21, TM, T1S, TV;
        Tj = T3 + Ti;
        T2g = T1h + T1k;
        TM = TG + TL;
        TN = Tr + TM;
        T1H = TM - Tr;
        T1S = T1m + T1l;
        T1U = T1S - T1T;
        T26 = T1T + T1S;
        TV = TR + TU;
        TZ = TV - TY;
        T1J = TV + TY;
        {
            E T1O, T14, T1r, T1n, T1v;
            T1O = T13 + T12;
            T1Q = T1O + T1P;
            T24 = T1O - T1P;
            T14 = T12 - T13;
            T1c = T14 - T1b;
            T1C = T14 + T1b;
            T1r = TL - TG;
            T1t = T1r - T1s;
            T29 = T1s + T1r;
            T1n = T1l - T1m;
            T1o = T1g + T1n;
            T1E = T1n - T1g;
            T1v = TU - TR;
            T1x = T1v + T1w;
            T2b = T1v - T1w;
            {
                E T1X, T1Z, T1W, T1Y;
                T1X = TS + TT;
                T1Z = TJ + TK;
                T1W = W[9];
                T1Y = W[8];
                T20 = (((T1W) * (T1X)) + (T1Y * T1Z));
                T21 = ((T1Y * T1X) - ((T1W) * (T1Z)));
            }
        }
        {
            E T10, T2f, Tk, TO;
            Tk = W[0];
            TO = W[1];
            T10 = (((Tk) * (TN)) + (TO * TZ));
            T2f = ((Tk * TZ) - ((TO) * (TN)));
            Rp[0] = Tj - T10;
            Ip[0] = T2f + T2g;
            Rm[0] = Tj + T10;
            Im[0] = T2f - T2g;
        }
        {
            E T1V, T22, T1N, T1R;
            T1N = W[6];
            T1R = W[7];
            T1V = ((T1N * T1Q) - ((T1R) * (T1U)));
            T22 = (((T1R) * (T1Q)) + (T1N * T1U));
            Rp[(rs[2])] = T1V - T20;
            Ip[(rs[2])] = T21 + T22;
            Rm[(rs[2])] = T20 + T1V;
            Im[(rs[2])] = T21 - T22;
        }
        {
            E T1p, T1A, T1y, T1z;
            {
                E T11, T1d, T1q, T1u;
                T11 = W[2];
                T1d = W[3];
                T1p = ((T11 * T1c) - ((T1d) * (T1o)));
                T1A = (((T1d) * (T1c)) + (T11 * T1o));
                T1q = W[4];
                T1u = W[5];
                T1y = (((T1q) * (T1t)) + (T1u * T1x));
                T1z = ((T1q * T1x) - ((T1u) * (T1t)));
            }
            Rp[(rs[1])] = T1p - T1y;
            Ip[(rs[1])] = T1z + T1A;
            Rm[(rs[1])] = T1y + T1p;
            Im[(rs[1])] = T1z - T1A;
        }
        {
            E T1F, T1M, T1K, T1L;
            {
                E T1B, T1D, T1G, T1I;
                T1B = W[14];
                T1D = W[15];
                T1F = ((T1B * T1C) - ((T1D) * (T1E)));
                T1M = (((T1D) * (T1C)) + (T1B * T1E));
                T1G = W[16];
                T1I = W[17];
                T1K = (((T1G) * (T1H)) + (T1I * T1J));
                T1L = ((T1G * T1J) - ((T1I) * (T1H)));
            }
            Rp[(rs[4])] = T1F - T1K;
            Ip[(rs[4])] = T1L + T1M;
            Rm[(rs[4])] = T1K + T1F;
            Im[(rs[4])] = T1L - T1M;
        }
        {
            E T27, T2e, T2c, T2d;
            {
                E T23, T25, T28, T2a;
                T23 = W[10];
                T25 = W[11];
                T27 = ((T23 * T24) - ((T25) * (T26)));
                T2e = (((T25) * (T24)) + (T23 * T26));
                T28 = W[12];
                T2a = W[13];
                T2c = (((T28) * (T29)) + (T2a * T2b));
                T2d = ((T28 * T2b) - ((T2a) * (T29)));
            }
            Rp[(rs[3])] = T27 - T2c;
            Ip[(rs[3])] = T2d + T2e;
            Rm[(rs[3])] = T2c + T27;
            Im[(rs[3])] = T2d - T2e;
        }
    }
}

}
