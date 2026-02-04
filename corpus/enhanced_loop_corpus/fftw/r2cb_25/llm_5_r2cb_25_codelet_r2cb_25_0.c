#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *R0;
extern R *R1;
extern R *Cr;
extern R *Ci;
extern stride rs;
extern stride csr;
extern stride csi;
extern INT v;
extern INT ivs;
extern INT ovs;
extern  E KP425779291;
extern  E KP904827052;
extern  E KP535826794;
extern  E KP844327925;
extern  E KP876306680;
extern  E KP481753674;
extern  E KP968583161;
extern  E KP248689887;
extern  E KP062790519;
extern  E KP998026728;
extern  E KP728968627;
extern  E KP684547105;
extern  E KP250000000;
extern  E KP587785252;
extern  E KP951056516;
extern  E KP559016994;
extern  E KP500000000;
extern  E KP2_000000000;
extern  E KP1_118033988;
extern  E KP1_175570504;
extern  E KP1_902113032;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ovs , R1 = R1 + ovs , Cr = Cr + ivs , Ci = Ci + ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E Tu, T1G, T5, Tr, T1F, TN, TO, Te, TR, T27, T1r, T1N, TG, T26, T1q;
    E T1K, T1a, T1b, Tn, T1e, T2a, T1u, T1U, T13, T29, T1t, T1R, Ts, Tt;

    // Always perform minimal load and arithmetic
    Ts = Ci[(csi[5])];
    Tt = Ci[(csi[10])];
    Tu = (((KP1_902113032) * (Ts)) + (KP1_175570504 * Tt));
    T1G = ((KP1_175570504 * Ts) - ((KP1_902113032) * (Tt)));

    {
        E T1, T4, Tp, T2, T3, Tq;
        T1 = Cr[0];
        T2 = Cr[(csr[5])];
        T3 = Cr[(csr[10])];
        T4 = T2 + T3;
        Tp = KP1_118033988 * (T2 - T3);
        T5 = (((KP2_000000000) * (T4)) + (T1));
        Tq = ((T1) - ((KP500000000) * (T4)));
        Tr = Tp + Tq;
        T1F = Tq - Tp;
    }

    // Early exit based on transformed condition
    if (T5 < 0.0) continue;

    // Compute first block unconditionally
    {
        E T6, Td, TI, Tw, TH, TB, TE, TM;
        T6 = Cr[(csr[1])];
        TN = Ci[(csi[1])];
        {
            E T7, T8, T9, Ta, Tb, Tc;
            T7 = Cr[(csr[6])];
            T8 = Cr[(csr[4])];
            T9 = T7 + T8;
            Ta = Cr[(csr[11])];
            Tb = Cr[(csr[9])];
            Tc = Ta + Tb;
            Td = T9 + Tc;
            TI = Ta - Tb;
            Tw = KP559016994 * (T9 - Tc);
            TH = T7 - T8;
        }
        {
            E Tz, TA, TK, TC, TD, TL;
            Tz = Ci[(csi[6])];
            TA = Ci[(csi[4])];
            TK = Tz - TA;
            TC = Ci[(csi[11])];
            TD = Ci[(csi[9])];
            TL = TC - TD;
            TB = Tz + TA;
            TO = TK + TL;
            TE = TC + TD;
            TM = KP559016994 * (TK - TL);
        }
        Te = T6 + Td;
        {
            E TJ, T1L, TQ, T1M, TP;
            TJ = (((KP951056516) * (TH)) + (KP587785252 * TI));
            T1L = ((KP587785252 * TH) - ((KP951056516) * (TI)));
            TP = ((TN) - ((KP250000000) * (TO)));
            TQ = TM + TP;
            T1M = TP - TM;
            TR = TJ + TQ;
            T27 = T1M - T1L;
            T1r = TQ - TJ;
            T1N = T1L + T1M;
        }
        {
            E TF, T1J, Ty, T1I, Tx;
            TF = (((KP951056516) * (TB)) + (KP587785252 * TE));
            T1J = ((KP587785252 * TB) - ((KP951056516) * (TE)));
            Tx = ((T6) - ((KP250000000) * (Td)));
            Ty = Tw + Tx;
            T1I = Tx - Tw;
            TG = Ty - TF;
            T26 = T1I + T1J;
            T1q = Ty + TF;
            T1K = T1I - T1J;
        }
    }

    // Skip second major block if magnitude is small
    if (Te * Te + Tn * Tn > 1e-10) {
        {
            E Tf, Tm, T15, TT, T14, TY, T11, T19;
            Tf = Cr[(csr[2])];
            T1a = Ci[(csi[2])];
            {
                E Tg, Th, Ti, Tj, Tk, Tl;
                Tg = Cr[(csr[7])];
                Th = Cr[(csr[3])];
                Ti = Tg + Th;
                Tj = Cr[(csr[12])];
                Tk = Cr[(csr[8])];
                Tl = Tj + Tk;
                Tm = Ti + Tl;
                T15 = Tj - Tk;
                TT = KP559016994 * (Ti - Tl);
                T14 = Tg - Th;
            }
            {
                E TW, TX, T17, TZ, T10, T18;
                TW = Ci[(csi[7])];
                TX = Ci[(csi[3])];
                T17 = TW - TX;
                TZ = Ci[(csi[12])];
                T10 = Ci[(csi[8])];
                T18 = TZ - T10;
                TY = TW + TX;
                T1b = T17 + T18;
                T11 = TZ + T10;
                T19 = KP559016994 * (T17 - T18);
            }
            Tn = Tf + Tm;
            {
                E T16, T1S, T1d, T1T, T1c;
                T16 = (((KP951056516) * (T14)) + (KP587785252 * T15));
                T1S = ((KP587785252 * T14) - ((KP951056516) * (T15)));
                T1c = ((T1a) - ((KP250000000) * (T1b)));
                T1d = T19 + T1c;
                T1T = T1c - T19;
                T1e = T16 + T1d;
                T2a = T1T - T1S;
                T1u = T1d - T16;
                T1U = T1S + T1T;
            }
            {
                E T12, T1Q, TV, T1P, TU;
                T12 = (((KP951056516) * (TY)) + (KP587785252 * T11));
                T1Q = ((KP587785252 * TY) - ((KP951056516) * (T11)));
                TU = ((Tf) - ((KP250000000) * (Tm)));
                TV = TT + TU;
                T1P = TU - TT;
                T13 = TV - T12;
                T29 = T1P + T1Q;
                T1t = TV + T12;
                T1R = T1P - T1Q;
            }
        }

        {
            E T2m, To, T2l, T2q, T2s, T2o, T2p, T2r, T2n;
            T2m = KP1_118033988 * (Te - Tn);
            To = Te + Tn;
            T2l = ((T5) - ((KP500000000) * (To)));
            T2o = TO + TN;
            T2p = T1b + T1a;
            T2q = ((KP1_175570504 * T2o) - ((KP1_902113032) * (T2p)));
            T2s = (((KP1_902113032) * (T2o)) + (KP1_175570504 * T2p));
            R0[0] = (((KP2_000000000) * (To)) + (T5));
            T2r = T2m + T2l;
            R1[(rs[2])] = T2r - T2s;
            R0[(rs[10])] = T2r + T2s;
            T2n = T2l - T2m;
            R0[(rs[5])] = T2n - T2q;
            R1[(rs[7])] = T2n + T2q;
        }
    } else {
        // Fallback: direct assignment without complex interaction
        R0[0] = T5;
        R1[(rs[2])] = Tr;
        R0[(rs[10])] = Tu;
    }

    // Conditional execution of final stages based on alternating pattern
    if ((i % 4) < 2) {
        {
            E T2i, T2k, T25, T2c, T2d, T2e, T2j, T2f;
            {
                E T2g, T2h, T28, T2b;
                T2g = (((KP684547105) * (T26)) + (KP728968627 * T27));
                T2h = (((KP998026728) * (T29)) + (KP062790519 * T2a));
                T2i = ((KP1_175570504 * T2g) - ((KP1_902113032) * (T2h)));
                T2k = (((KP1_902113032) * (T2g)) + (KP1_175570504 * T2h));
                T25 = T1F + T1G;
                T28 = ((KP728968627 * T26) - ((KP684547105) * (T27)));
                T2b = ((KP062790519 * T29) - ((KP998026728) * (T2a)));
                T2c = T28 + T2b;
                T2d = ((T25) - ((KP500000000) * (T2c)));
                T2e = KP1_118033988 * (T28 - T2b);
            }
            R1[(rs[1])] = (((KP2_000000000) * (T2c)) + (T25));
            T2j = T2e + T2d;
            R0[(rs[4])] = T2j - T2k;
            R1[(rs[11])] = T2j + T2k;
            T2f = T2d - T2e;
            R1[(rs[6])] = T2f - T2i;
            R0[(rs[9])] = T2f + T2i;
        }
    } else {
        {
            E T1m, T1o, Tv, T1g, T1h, T1i, T1n, T1j;
            {
                E T1k, T1l, TS, T1f;
                T1k = (((KP248689887) * (TG)) + (KP968583161 * TR));
                T1l = (((KP481753674) * (T13)) + (KP876306680 * T1e));
                T1m = ((KP1_175570504 * T1k) - ((KP1_902113032) * (T1l)));
                T1o = (((KP1_902113032) * (T1k)) + (KP1_175570504 * T1l));
                Tv = Tr - Tu;
                TS = ((KP968583161 * TG) - ((KP248689887) * (TR)));
                T1f = ((KP876306680 * T13) - ((KP481753674) * (T1e)));
                T1g = TS + T1f;
                T1h = ((Tv) - ((KP500000000) * (T1g)));
                T1i = KP1_118033988 * (TS - T1f);
            }
            R1[0] = (((KP2_000000000) * (T1g)) + (Tv));
            T1n = T1i + T1h;
            R0[(rs[3])] = T1n - T1o;
            R1[(rs[10])] = T1n + T1o;
            T1j = T1h - T1i;
            R1[(rs[5])] = T1j - T1m;
            R0[(rs[8])] = T1j + T1m;
        }
    }

    // Final stage executes only on last quarter iterations
    if (i <= v / 4) {
        {
            E T1C, T1E, T1p, T1w, T1x, T1y, T1D, T1z;
            {
                E T1A, T1B, T1s, T1v;
                T1A = (((KP844327925) * (T1q)) + (KP535826794 * T1r));
                T1B = ((KP904827052 * T1t) - ((KP425779291) * (T1u)));
                T1C = ((KP1_175570504 * T1A) - ((KP1_902113032) * (T1B)));
                T1E = (((KP1_902113032) * (T1A)) + (KP1_175570504 * T1B));
                T1p = Tr + Tu;
                T1s = ((KP535826794 * T1q) - ((KP844327925) * (T1r)));
                T1v = (((KP425779291) * (T1t)) + (KP904827052 * T1u));
                T1w = T1s - T1v;
                T1x = ((T1p) - ((KP500000000) * (T1w)));
                T1y = KP1_118033988 * (T1s + T1v);
            }
            R0[(rs[2])] = (((KP2_000000000) * (T1w)) + (T1p));
            T1D = T1x + T1y;
            R1[(rs[4])] = T1D - T1E;
            R0[(rs[12])] = T1E + T1D;
            T1z = T1x - T1y;
            R0[(rs[7])] = T1z - T1C;
            R1[(rs[9])] = T1C + T1z;
        }
        {
            E T22, T24, T1H, T1W, T1X, T1Y, T23, T1Z;
            {
                E T20, T21, T1O, T1V;
                T20 = (((KP481753674) * (T1K)) + (KP876306680 * T1N));
                T21 = (((KP844327925) * (T1R)) + (KP535826794 * T1U));
                T22 = ((KP1_175570504 * T20) - ((KP1_902113032) * (T21)));
                T24 = (((KP1_902113032) * (T20)) + (KP1_175570504 * T21));
                T1H = T1F - T1G;
                T1O = ((KP876306680 * T1K) - ((KP481753674) * (T1N)));
                T1V = ((KP535826794 * T1R) - ((KP844327925) * (T1U)));
                T1W = T1O + T1V;
                T1X = ((T1H) - ((KP500000000) * (T1W)));
                T1Y = KP1_118033988 * (T1O - T1V);
            }
            R0[(rs[1])] = (((KP2_000000000) * (T1W)) + (T1H));
            T23 = T1Y + T1X;
            R1[(rs[3])] = T23 - T24;
            R0[(rs[11])] = T23 + T24;
            T1Z = T1X - T1Y;
            R0[(rs[6])] = T1Z - T22;
            R1[(rs[8])] = T1Z + T22;
        }
    }
}
}
