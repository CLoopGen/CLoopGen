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

    // Change memory access pattern to use indirect addressing via pointer arrays to simulate irregular access
    const R* restrict cr_ptr_base = Cr;
    const R* restrict ci_ptr_base = Ci;
    R* restrict r0_ptr = R0;
    R* restrict r1_ptr = R1;

    // Simulate indirect access: build a local table of effective addresses
    const R* cr_ptrs[13] = {
        &cr_ptr_base[0],
        &cr_ptr_base[csr[1]],   &cr_ptr_base[csr[2]],   &cr_ptr_base[csr[3]],
        &cr_ptr_base[csr[4]],   &cr_ptr_base[csr[5]],   &cr_ptr_base[csr[6]],
        &cr_ptr_base[csr[7]],   &cr_ptr_base[csr[8]],   &cr_ptr_base[csr[9]],
        &cr_ptr_base[csr[10]],  &cr_ptr_base[csr[11]],  &cr_ptr_base[csr[12]]
    };
    const R* ci_ptrs[12] = {
        &ci_ptr_base[0],
        &ci_ptr_base[csi[1]],   &ci_ptr_base[csi[2]],   &ci_ptr_base[csi[3]],
        &ci_ptr_base[csi[4]],   &ci_ptr_base[csi[5]],   &ci_ptr_base[csi[6]],
        &ci_ptr_base[csi[7]],   &ci_ptr_base[csi[8]],   &ci_ptr_base[csi[9]],
        &ci_ptr_base[csi[10]],  &ci_ptr_base[csi[11]]
    };
    R* r0_out[13] = {
        &r0_ptr[0],             &r0_ptr[rs[1]],         &r0_ptr[rs[2]],
        &r0_ptr[rs[3]],         &r0_ptr[rs[4]],         &r0_ptr[rs[5]],
        &r0_ptr[rs[6]],         &r0_ptr[rs[7]],         &r0_ptr[rs[8]],
        &r0_ptr[rs[9]],         &r0_ptr[rs[10]],        &r0_ptr[rs[11]],
        &r0_ptr[rs[12]]
    };
    R* r1_out[13] = {
        &r1_ptr[0],             &r1_ptr[rs[1]],         &r1_ptr[rs[2]],
        &r1_ptr[rs[3]],         &r1_ptr[rs[4]],         &r1_ptr[rs[5]],
        &r1_ptr[rs[6]],         &r1_ptr[rs[7]],         &r1_ptr[rs[8]],
        &r1_ptr[rs[9]],         &r1_ptr[rs[10]],        &r1_ptr[rs[11]],
        NULL, NULL
    };

    TQ = *(ci_ptrs[2]);
    TR = *(ci_ptrs[7]);
    TS = ((KP1_902113032 * TQ) - ((KP1_175570504) * (TR)));
    T1O = (((KP1_902113032) * (TR)) + (KP1_175570504 * TQ));
    {
        E T1, T4, TN, T2, T3, TO;
        T1 = *(cr_ptrs[12]);
        T2 = *(cr_ptrs[7]);
        T3 = *(cr_ptrs[2]);
        T4 = T2 + T3;
        TN = KP1_118033988 * (T3 - T2);
        T5 = (((KP2_000000000) * (T4)) + (T1));
        TO = (((KP500000000) * (T4)) - (T1));
        TP = TN - TO;
        T1N = TO + TN;
    }
    {
        E T6, Td, T15, TU, T14, T11, TX, TY;
        T6 = *(cr_ptrs[11]);
        TI = *(ci_ptrs[11]);
        {
            E T7, T8, T9, Ta, Tb, Tc;
            T7 = *(cr_ptrs[6]);
            T8 = *(cr_ptrs[8]);
            T9 = T7 + T8;
            Ta = *(cr_ptrs[1]);
            Tb = *(cr_ptrs[3]);
            Tc = Ta + Tb;
            Td = T9 + Tc;
            T15 = Ta - Tb;
            TU = KP559016994 * (Tc - T9);
            T14 = T8 - T7;
        }
        {
            E TB, TC, TD, TE, TF, TG;
            TB = *(ci_ptrs[6]);
            TC = *(ci_ptrs[8]);
            TD = TB - TC;
            TE = *(ci_ptrs[1]);
            TF = *(ci_ptrs[3]);
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
        Tf = *(cr_ptrs[10]);
        Tz = *(ci_ptrs[10]);
        {
            E Tg, Th, Ti, Tj, Tk, Tl;
            Tg = *(cr_ptrs[5]);
            Th = *(cr_ptrs[9]);
            Ti = Tg + Th;
            Tj = *(cr_ptrs[0]);
            Tk = *(cr_ptrs[4]);
            Tl = Tj + Tk;
            Tm = Ti + Tl;
            T1k = Tj - Tk;
            T19 = KP559016994 * (Tl - Ti);
            T1j = Th - Tg;
        }
        {
            E Ts, Tt, Tu, Tv, Tw, Tx;
            Ts = *(ci_ptrs[4]);
            Tt = *(ci_ptrs[0]);
            Tu = Ts - Tt;
            Tv = *(ci_ptrs[5]);
            Tw = *(ci_ptrs[9]);
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
        *r0_out[0] = (((KP2_000000000) * (To)) + (T5));
        TL = Tq - Tp;
        *r0_out[5] = TL + TM;
        r1_out[7][0] = TM - TL;
        Tr = Tp + Tq;
        r1_out[2][0] = Tr + TK;
        r0_out[10][0] = TK - Tr;
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
        r0_out[2][0] = (((KP2_000000000) * (T2j)) - (T2k));
        T2r = T2m - T2l;
        r0_out[7][0] = T2r + T2s;
        r1_out[9][0] = T2s - T2r;
        T2n = T2l + T2m;
        r1_out[4][0] = T2n + T2q;
        r0_out[12][0] = T2q - T2n;
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
        r0_out[1][0] = (((KP2_000000000) * (T1o)) + (TT));
        T1v = T1q - T1p;
        r0_out[6][0] = T1v + T1w;
        r1_out[8][0] = T1w - T1v;
        T1r = T1p + T1q;
        r1_out[3][0] = T1r + T1u;
        r0_out[11][0] = T1u - T1r;
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
        r1_out[1][0] = (((KP2_000000000) * (T1D)) - (T1E));
        T1M = T1J - T1I;
        r0_out[9][0] = T1L - T1M;
        r1_out[6][0] = T1L + T1M;
        T1K = T1I + T1J;
        r1_out[11][0] = T1H - T1K;
        r0_out[4][0] = T1H + T1K;
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
        r1_out[0][0] = (((KP2_000000000) * (T24)) + (T1P));
        T2b = T26 - T25;
        r1_out[5][0] = T2b + T2c;
        r0_out[8][0] = T2c - T2b;
        T27 = T25 + T26;
        r0_out[3][0] = T27 + T2a;
        r1_out[10][0] = T2a - T27;
    }
}
}
