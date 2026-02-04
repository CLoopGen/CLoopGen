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
    // Variant introduces artificial loop-carried dependency via accumulator
    static E acc_T5 = 0.0, acc_TP = 0.0;
    E TS, T1O, T5_base, TP_base, T1N, TI, TH, Te, T17, T2h, T1y, T1V, T10, T2g, T1x;
    E T1S, Tz, Ty, Tn, T1m, T2e, T1B, T22, T1f, T2d, T1A, T1Z, TQ, TR;

    TQ = Ci[(csi[2])];
    TR = Ci[(csi[7])];
    TS = ((KP1_902113032 * TQ) - ((KP1_175570504) * (TR))) + acc_T5; // Feed previous state
    T1O = (((KP1_902113032) * (TR)) + (KP1_175570504 * TQ)) + acc_TP;

    // Break RAW by precomputing all loads early and storing in temporaries
    E cr_loads[13], ci_loads[12];
    for (INT j = 0; j < 13; ++j) cr_loads[j] = Cr[(csr[j])];
    for (INT j = 0; j < 12; ++j) ci_loads[j] = Ci[(csi[j])];

    {
        E T1 = cr_loads[12];
        E T2 = cr_loads[7];
        E T3 = cr_loads[2];
        E T4 = T2 + T3;
        E TN = KP1_118033988 * (T3 - T2);
        T5_base = (((KP2_000000000) * (T4)) + (T1));
        E TO = (((KP500000000) * (T4)) - (T1));
        TP_base = TN - TO;
        T1N = TO + TN;
    }

    {
        E T6 = cr_loads[11];
        TI = ci_loads[11];
        E T7 = cr_loads[6];
        E T8 = cr_loads[8];
        E T9 = T7 + T8;
        E Ta = cr_loads[1];
        E Tb = cr_loads[3];
        E Tc = Ta + Tb;
        E Td = T9 + Tc;
        E T15 = Ta - Tb;
        E TU = KP559016994 * (Tc - T9);
        E T14 = T8 - T7;

        E TB = ci_loads[6];
        E TC = ci_loads[8];
        E TD = TB - TC;
        E TE = ci_loads[1];
        E TF = ci_loads[3];
        E TG = TE - TF;
        TH = TD + TG;
        E T11 = KP559016994 * (TD - TG);
        E TX = TB + TC;
        E TY = TE + TF;

        Te = T6 + Td;

        E T16 = (((KP587785252) * (T14)) + (KP951056516 * T15));
        E T1T = ((KP951056516 * T14) - ((KP587785252) * (T15)));
        E T12 = ((TI) - ((KP250000000) * (TH)));
        E T13 = T11 - T12;
        E T1U = T11 + T12;
        T17 = T13 - T16;
        T2h = T1T - T1U;
        T1y = T16 + T13;
        T1V = T1T + T1U;

        E TZ = ((KP587785252 * TX) - ((KP951056516) * (TY)));
        E T1R = (((KP951056516) * (TX)) + (KP587785252 * TY));
        E TV = (((KP250000000) * (Td)) - (T6));
        E TW = TU - TV;
        E T1Q = TV + TU;
        T10 = TW + TZ;
        T2g = T1Q + T1R;
        T1x = TZ - TW;
        T1S = T1Q - T1R;
    }

    {
        E Tf = cr_loads[10];
        Tz = ci_loads[10];
        E Tg = cr_loads[5];
        E Th = cr_loads[9];
        E Ti = Tg + Th;
        E Tj = cr_loads[0];
        E Tk = cr_loads[4];
        E Tl = Tj + Tk;
        E Tm = Ti + Tl;
        E T1k = Tj - Tk;
        E T19 = KP559016994 * (Tl - Ti);
        E T1j = Th - Tg;
        Tn = Tf + Tm;

        E Ts = ci_loads[4];
        E Tt = ci_loads[0];
        E Tu = Ts - Tt;
        E Tv = ci_loads[5];
        E Tw = ci_loads[9];
        E Tx = Tv - Tw;
        Ty = Tu - Tx;
        E T1g = KP559016994 * (Tx + Tu);
        E T1c = Tv + Tw;
        E T1d = Tt + Ts;

        E T1l = (((KP587785252) * (T1j)) + (KP951056516 * T1k));
        E T20 = ((KP951056516 * T1j) - ((KP587785252) * (T1k)));
        E T1h = (((KP250000000) * (Ty)) + (Tz));
        E T1i = T1g - T1h;
        E T21 = T1g + T1h;
        T1m = T1i - T1l;
        T2e = T21 - T20;
        T1B = T1l + T1i;
        T22 = T20 + T21;

        E T1e = ((KP587785252 * T1c) - ((KP951056516) * (T1d)));
        E T1Y = (((KP951056516) * (T1c)) + (KP587785252 * T1d));
        E T1a = (((KP250000000) * (Tm)) - (Tf));
        E T1b = T19 - T1a;
        E T1X = T1a + T19;
        T1f = T1b + T1e;
        T2d = T1X + T1Y;
        T1A = T1e - T1b;
        T1Z = T1X - T1Y;
    }

    // Use accumulated values to create loop-carried dependency
    E T5 = T5_base + acc_T5;
    E TP = TP_base + acc_TP;

    {
        E Tq = KP1_118033988 * (Tn - Te);
        E To = Te + Tn;
        E Tp = (((KP500000000) * (To)) - (T5));
        E TA = Ty - Tz;
        E TJ = TH + TI;
        E TK = ((KP1_175570504 * TA) - ((KP1_902113032) * (TJ)));
        E TM = (((KP1_175570504) * (TJ)) + (KP1_902113032 * TA));
        R0[0] = (((KP2_000000000) * (To)) + (T5));
        E TL = Tq - Tp;
        R0[(rs[5])] = TL + TM;
        R1[(rs[7])] = TM - TL;
        E Tr = Tp + Tq;
        R1[(rs[2])] = Tr + TK;
        R0[(rs[10])] = TK - Tr;
    }

    {
        E T2o = ((KP425779291 * T2e) - ((KP904827052) * (T2d)));
        E T2p = ((KP844327925 * T2g) - ((KP535826794) * (T2h)));
        E T2q = ((KP1_175570504 * T2o) - ((KP1_902113032) * (T2p)));
        E T2s = (((KP1_175570504) * (T2p)) + (KP1_902113032 * T2o));
        E T2k = T1N + T1O;
        E T2f = (((KP425779291) * (T2d)) + (KP904827052 * T2e));
        E T2i = (((KP535826794) * (T2g)) + (KP844327925 * T2h));
        E T2j = T2f - T2i;
        E T2l = (((KP500000000) * (T2j)) + (T2k));
        E T2m = KP1_118033988 * (T2i + T2f);
        R0[(rs[2])] = (((KP2_000000000) * (T2j)) - (T2k));
        E T2r = T2m - T2l;
        R0[(rs[7])] = T2r + T2s;
        R1[(rs[9])] = T2s - T2r;
        E T2n = T2l + T2m;
        R1[(rs[4])] = T2n + T2q;
        R0[(rs[12])] = T2q - T2n;
    }

    {
        E T1s = (((KP481753674) * (T10)) + (KP876306680 * T17));
        E T1t = (((KP844327925) * (T1f)) + (KP535826794 * T1m));
        E T1u = (((KP1_902113032) * (T1s)) + (KP1_175570504 * T1t));
        E T1w = ((KP1_902113032 * T1t) - ((KP1_175570504) * (T1s)));
        E TT = TP - TS;
        E T18 = ((KP876306680 * T10) - ((KP481753674) * (T17)));
        E T1n = ((KP535826794 * T1f) - ((KP844327925) * (T1m)));
        E T1o = T18 + T1n;
        E T1p = (((KP500000000) * (T1o)) - (TT));
        E T1q = KP1_118033988 * (T1n - T18);
        R0[(rs[1])] = (((KP2_000000000) * (T1o)) + (TT));
        E T1v = T1q - T1p;
        R0[(rs[6])] = T1v + T1w;
        R1[(rs[8])] = T1w - T1v;
        E T1r = T1p + T1q;
        R1[(rs[3])] = T1r + T1u;
        R0[(rs[11])] = T1u - T1r;
    }

    {
        E T1F = ((KP998026728 * T1A) - ((KP062790519) * (T1B)));
        E T1G = ((KP728968627 * T1y) - ((KP684547105) * (T1x)));
        E T1H = ((KP1_175570504 * T1F) - ((KP1_902113032) * (T1G)));
        E T1L = (((KP1_175570504) * (T1G)) + (KP1_902113032 * T1F));
        E T1E = TP + TS;
        E T1z = (((KP728968627) * (T1x)) + (KP684547105 * T1y));
        E T1C = (((KP062790519) * (T1A)) + (KP998026728 * T1B));
        E T1D = T1z + T1C;
        E T1I = (((KP500000000) * (T1D)) + (T1E));
        E T1J = KP1_118033988 * (T1C - T1z);
        R1[(rs[1])] = (((KP2_000000000) * (T1D)) - (T1E));
        E T1M = T1J - T1I;
        R0[(rs[9])] = T1L - T1M;
        R1[(rs[6])] = T1L + T1M;
        E T1K = T1I + T1J;
        R1[(rs[11])] = T1H - T1K;
        R0[(rs[4])] = T1H + T1K;
    }

    {
        E T28 = (((KP248689887) * (T1S)) + (KP968583161 * T1V));
        E T29 = (((KP481753674) * (T1Z)) + (KP876306680 * T22));
        E T2a = (((KP1_902113032) * (T28)) + (KP1_175570504 * T29));
        E T2c = ((KP1_902113032 * T29) - ((KP1_175570504) * (T28)));
        E T1P = T1N - T1O;
        E T1W = ((KP968583161 * T1S) - ((KP248689887) * (T1V)));
        E T23 = ((KP876306680 * T1Z) - ((KP481753674) * (T22)));
        E T24 = T1W + T23;
        E T25 = (((KP500000000) * (T24)) - (T1P));
        E T26 = KP1_118033988 * (T23 - T1W);
        R1[0] = (((KP2_000000000) * (T24)) + (T1P));
        E T2b = T26 - T25;
        R1[(rs[5])] = T2b + T2c;
        R0[(rs[8])] = T2c - T2b;
        E T27 = T25 + T26;
        R0[(rs[3])] = T27 + T2a;
        R1[(rs[10])] = T2a - T27;
    }

    // Update accumulators for next iteration (loop-carried dependency introduced)
    acc_T5 = T5_base * 0.1;
    acc_TP = TP_base * 0.1;
}
}
