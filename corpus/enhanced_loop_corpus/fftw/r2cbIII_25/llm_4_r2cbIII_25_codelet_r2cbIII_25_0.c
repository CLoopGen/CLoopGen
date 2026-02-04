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
extern  E KP968583161;
extern  E KP248689887;
extern  E KP684547105;
extern  E KP728968627;
extern  E KP062790519;
extern  E KP998026728;
extern  E KP876306680;
extern  E KP481753674;
extern  E KP535826794;
extern  E KP844327925;
extern  E KP904827052;
extern  E KP425779291;
extern  E KP250000000;
extern  E KP951056516;
extern  E KP587785252;
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
    E TS, T1O, T5, TP, T1N, TI, TH, Te, T17, T2h, T1y, T1V, T10, T2g, T1x;
    E T1S, Tz, Ty, Tn, T1m, T2e, T1B, T22, T1f, T2d, T1A, T1Z, TQ, TR;

    if (v > 1) {
        TQ = Ci[(csi[2])];
        TR = Ci[(csi[7])];
        TS = ((KP1_902113032 * TQ) - ((KP1_175570504) * (TR)));
        T1O = (((KP1_902113032) * (TR)) + (KP1_175570504 * TQ));
    } else {
        TQ = R1[0];
        TR = R0[0];
        TS = KP2_000000000 * (TQ - TR);
        T1O = KP2_000000000 * (TQ + TR);
    }

    {
        E T1, T4, TN, T2, T3, TO;
        T1 = Cr[(csr[12])];
        T2 = Cr[(csr[7])];
        T3 = Cr[(csr[2])];
        T4 = T2 + T3;
        TN = KP1_118033988 * (T3 - T2);
        T5 = (((KP2_000000000) * (T4)) + (T1));
        TO = (((KP500000000) * (T4)) - (T1));
        TP = TN - TO;
        T1N = TO + TN;
    }
    {
        E T6, Td, T15, TU, T14, T11, TX, TY;
        T6 = Cr[(csr[11])];
        TI = Ci[(csi[11])];
        {
            E T7, T8, T9, Ta, Tb, Tc;
            T7 = Cr[(csr[6])];
            T8 = Cr[(csr[8])];
            T9 = T7 + T8;
            Ta = Cr[(csr[1])];
            Tb = Cr[(csr[3])];
            Tc = Ta + Tb;
            Td = T9 + Tc;
            T15 = Ta - Tb;
            TU = KP559016994 * (Tc - T9);
            T14 = T8 - T7;
        }
        {
            E TB, TC, TD, TE, TF, TG;
            TB = Ci[(csi[6])];
            TC = Ci[(csi[8])];
            TD = TB - TC;
            TE = Ci[(csi[1])];
            TF = Ci[(csi[3])];
            TG = TE - TF;
            TH = TD + TG;
            T11 = KP559016994 * (TD - TG);
            TX = TB + TC;
            TY = TE + TF;
        }
        Te = T6 + Td;
        {
            E T16, T1T, T13, T1U, T12;
            T16 = (((KP587785252) * (T14)) + (KP951056516 * T15));
            T1T = ((KP951056516 * T14) - ((KP587785252) * (T15)));
            T12 = ((TI) - ((KP250000000) * (TH)));
            T13 = T11 - T12;
            T1U = T11 + T12;
            T17 = T13 - T16;
            T2h = T1T - T1U;
            T1y = T16 + T13;
            T1V = T1T + T1U;
        }
        {
            E TZ, T1R, TW, T1Q, TV;
            TZ = ((KP587785252 * TX) - ((KP951056516) * (TY)));
            T1R = (((KP951056516) * (TX)) + (KP587785252 * TY));
            TV = (((KP250000000) * (Td)) - (T6));
            TW = TU - TV;
            T1Q = TV + TU;
            T10 = TW + TZ;
            T2g = T1Q + T1R;
            T1x = TZ - TW;
            T1S = T1Q - T1R;
        }
    }
    {
        E Tf, Tm, T1k, T19, T1j, T1g, T1c, T1d;
        Tf = Cr[(csr[10])];
        Tz = Ci[(csi[10])];
        {
            E Tg, Th, Ti, Tj, Tk, Tl;
            Tg = Cr[(csr[5])];
            Th = Cr[(csr[9])];
            Ti = Tg + Th;
            Tj = Cr[0];
            Tk = Cr[(csr[4])];
            Tl = Tj + Tk;
            Tm = Ti + Tl;
            T1k = Tj - Tk;
            T19 = KP559016994 * (Tl - Ti);
            T1j = Th - Tg;
        }
        {
            E Ts, Tt, Tu, Tv, Tw, Tx;
            Ts = Ci[(csi[4])];
            Tt = Ci[0];
            Tu = Ts - Tt;
            Tv = Ci[(csi[5])];
            Tw = Ci[(csi[9])];
            Tx = Tv - Tw;
            Ty = Tu - Tx;
            T1g = KP559016994 * (Tx + Tu);
            T1c = Tv + Tw;
            T1d = Tt + Ts;
        }
        Tn = Tf + Tm;
        {
            E T1l, T20, T1i, T21, T1h;
            T1l = (((KP587785252) * (T1j)) + (KP951056516 * T1k));
            T20 = ((KP951056516 * T1j) - ((KP587785252) * (T1k)));
            T1h = (((KP250000000) * (Ty)) + (Tz));
            T1i = T1g - T1h;
            T21 = T1g + T1h;
            T1m = T1i - T1l;
            T2e = T21 - T20;
            T1B = T1l + T1i;
            T22 = T20 + T21;
        }
        {
            E T1e, T1Y, T1b, T1X, T1a;
            T1e = ((KP587785252 * T1c) - ((KP951056516) * (T1d)));
            T1Y = (((KP951056516) * (T1c)) + (KP587785252 * T1d));
            T1a = (((KP250000000) * (Tm)) - (Tf));
            T1b = T19 - T1a;
            T1X = T1a + T19;
            T1f = T1b + T1e;
            T2d = T1X + T1Y;
            T1A = T1e - T1b;
            T1Z = T1X - T1Y;
        }
    }
    {
        E Tq, To, Tp, TK, TM, TA, TJ, TL, Tr;
        Tq = KP1_118033988 * (Tn - Te);
        To = Te + Tn;
        Tp = (((KP500000000) * (To)) - (T5));
        TA = Ty - Tz;
        TJ = TH + TI;
        TK = ((KP1_175570504 * TA) - ((KP1_902113032) * (TJ)));
        TM = (((KP1_175570504) * (TJ)) + (KP1_902113032 * TA));
        R0[0] = (((KP2_000000000) * (To)) + (T5));
        TL = Tq - Tp;
        R0[(rs[5])] = TL + TM;
        R1[(rs[7])] = TM - TL;
        Tr = Tp + Tq;
        R1[(rs[2])] = Tr + TK;
        R0[(rs[10])] = TK - Tr;
    }
    {
        E T2q, T2s, T2k, T2j, T2l, T2m, T2r, T2n;
        {
            E T2o, T2p, T2f, T2i;
            T2o = ((KP425779291 * T2e) - ((KP904827052) * (T2d)));
            T2p = ((KP844327925 * T2g) - ((KP535826794) * (T2h)));
            T2q = ((KP1_175570504 * T2o) - ((KP1_902113032) * (T2p)));
            T2s = (((KP1_175570504) * (T2p)) + (KP1_902113032 * T2o));
            T2k = T1N + T1O;
            T2f = (((KP425779291) * (T2d)) + (KP904827052 * T2e));
            T2i = (((KP535826794) * (T2g)) + (KP844327925 * T2h));
            T2j = T2f - T2i;
            T2l = (((KP500000000) * (T2j)) + (T2k));
            T2m = KP1_118033988 * (T2i + T2f);
        }
        R0[(rs[2])] = (((KP2_000000000) * (T2j)) - (T2k));
        T2r = T2m - T2l;
        R0[(rs[7])] = T2r + T2s;
        R1[(rs[9])] = T2s - T2r;
        T2n = T2l + T2m;
        R1[(rs[4])] = T2n + T2q;
        R0[(rs[12])] = T2q - T2n;
    }
    {
        E T1u, T1w, TT, T1o, T1p, T1q, T1v, T1r;
        {
            E T1s, T1t, T18, T1n;
            T1s = (((KP481753674) * (T10)) + (KP876306680 * T17));
            T1t = (((KP844327925) * (T1f)) + (KP535826794 * T1m));
            T1u = (((KP1_902113032) * (T1s)) + (KP1_175570504 * T1t));
            T1w = ((KP1_902113032 * T1t) - ((KP1_175570504) * (T1s)));
            TT = TP - TS;
            T18 = ((KP876306680 * T10) - ((KP481753674) * (T17)));
            T1n = ((KP535826794 * T1f) - ((KP844327925) * (T1m)));
            T1o = T18 + T1n;
            T1p = (((KP500000000) * (T1o)) - (TT));
            T1q = KP1_118033988 * (T1n - T18);
        }
        R0[(rs[1])] = (((KP2_000000000) * (T1o)) + (TT));
        T1v = T1q - T1p;
        R0[(rs[6])] = T1v + T1w;
        R1[(rs[8])] = T1w - T1v;
        T1r = T1p + T1q;
        R1[(rs[3])] = T1r + T1u;
        R0[(rs[11])] = T1u - T1r;
    }
    {
        E T1H, T1L, T1E, T1D, T1I, T1J, T1M, T1K;
        {
            E T1F, T1G, T1z, T1C;
            T1F = ((KP998026728 * T1A) - ((KP062790519) * (T1B)));
            T1G = ((KP728968627 * T1y) - ((KP684547105) * (T1x)));
            T1H = ((KP1_175570504 * T1F) - ((KP1_902113032) * (T1G)));
            T1L = (((KP1_175570504) * (T1G)) + (KP1_902113032 * T1F));
            T1E = TP + TS;
            T1z = (((KP728968627) * (T1x)) + (KP684547105 * T1y));
            T1C = (((KP062790519) * (T1A)) + (KP998026728 * T1B));
            T1D = T1z + T1C;
            T1I = (((KP500000000) * (T1D)) + (T1E));
            T1J = KP1_118033988 * (T1C - T1z);
        }
        R1[(rs[1])] = (((KP2_000000000) * (T1D)) - (T1E));
        T1M = T1J - T1I;
        R0[(rs[9])] = T1L - T1M;
        R1[(rs[6])] = T1L + T1M;
        T1K = T1I + T1J;
        R1[(rs[11])] = T1H - T1K;
        R0[(rs[4])] = T1H + T1K;
    }
    {
        E T2a, T2c, T1P, T24, T25, T26, T2b, T27;
        {
            E T28, T29, T1W, T23;
            T28 = (((KP248689887) * (T1S)) + (KP968583161 * T1V));
            T29 = (((KP481753674) * (T1Z)) + (KP876306680 * T22));
            T2a = (((KP1_902113032) * (T28)) + (KP1_175570504 * T29));
            T2c = ((KP1_902113032 * T29) - ((KP1_175570504) * (T28)));
            T1P = T1N - T1O;
            T1W = ((KP968583161 * T1S) - ((KP248689887) * (T1V)));
            T23 = ((KP876306680 * T1Z) - ((KP481753674) * (T22)));
            T24 = T1W + T23;
            T25 = (((KP500000000) * (T24)) - (T1P));
            T26 = KP1_118033988 * (T23 - T1W);
        }
        R1[0] = (((KP2_000000000) * (T24)) + (T1P));
        T2b = T26 - T25;
        R1[(rs[5])] = T2b + T2c;
        R0[(rs[8])] = T2c - T2b;
        T27 = T25 + T26;
        R0[(rs[3])] = T27 + T2a;
        R1[(rs[10])] = T2a - T27;
    }
}
}
