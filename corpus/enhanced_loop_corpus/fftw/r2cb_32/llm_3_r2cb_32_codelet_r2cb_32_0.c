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
extern  E KP1_662939224;
extern  E KP1_111140466;
extern  E KP1_961570560;
extern  E KP390180644;
extern  E KP765366864;
extern  E KP1_847759065;
extern  E KP707106781;
extern  E KP1_414213562;
extern  E KP2_000000000;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 += ovs , R1 += ovs , Cr += ivs , Ci += ivs) {
    E T9, T2c, TB, T1y, T6, T2b, Ty, T1v, Th, T2e, T2f, TD, TK, T1C, T1F;
    E T1h, Tp, T2i, T2m, TN, T13, T1K, T1Y, T1k, Tw, TU, T1l, TW, T1V, T2j;
    E T1R, T2l;
    E *Cr_ptr = Cr;
    E *Ci_ptr = Ci;
    INT rs_val = rs[0]; // Assume base stride is zero-offset for consecutive access simulation
    {
        E T7 = Cr_ptr[4], T8 = Cr_ptr[12], T1w, Tz = Ci_ptr[4], TA = Ci_ptr[12], T1x;
        T1w = T7 - T8;
        T1x = Tz + TA;
        T9 = KP2_000000000 * (T7 + T8);
        T2c = KP1_414213562 * (T1w + T1x);
        TB = KP2_000000000 * (Tz - TA);
        T1y = KP1_414213562 * (T1w - T1x);
    }
    {
        E T5, T1u, T3, T1s;
        {
            E T4 = Cr_ptr[8], T1t = Ci_ptr[8], T1 = Cr_ptr[0], T2 = Cr_ptr[16];
            T5 = KP2_000000000 * T4;
            T1u = KP2_000000000 * T1t;
            T3 = T1 + T2;
            T1s = T1 - T2;
        }
        T6 = T3 + T5;
        T2b = T1s + T1u;
        Ty = T3 - T5;
        T1v = T1s - T1u;
    }
    {
        E Td, T1A, TG, T1E, Tg, T1D, TJ, T1B;
        {
            E Tb = Cr_ptr[2], Tc = Cr_ptr[14];
            Td = Tb + Tc;
            T1A = Tb - Tc;
            E TE = Ci_ptr[2], TF = Ci_ptr[14];
            TG = TE - TF;
            T1E = TE + TF;
        }
        {
            E Te = Cr_ptr[10], Tf = Cr_ptr[6];
            Tg = Te + Tf;
            T1D = Te - Tf;
            E TH = Ci_ptr[10], TI = Ci_ptr[6];
            TJ = TH - TI;
            T1B = TH + TI;
        }
        Th = KP2_000000000 * (Td + Tg);
        T2e = T1A + T1B;
        T2f = T1E - T1D;
        TD = Td - Tg;
        TK = TG - TJ;
        T1C = T1A - T1B;
        T1F = T1D + T1E;
        T1h = KP2_000000000 * (TJ + TG);
    }
    {
        E Tl, T1I, TZ, T1X, To, T1W, T12, T1J;
        {
            E Tj = Cr_ptr[1], Tk = Cr_ptr[15];
            Tl = Tj + Tk;
            T1I = Tj - Tk;
            E TX = Ci_ptr[1], TY = Ci_ptr[15];
            TZ = TX - TY;
            T1X = TX + TY;
        }
        {
            E Tm = Cr_ptr[9], Tn = Cr_ptr[7];
            To = Tm + Tn;
            T1W = Tm - Tn;
            E T10 = Ci_ptr[9], T11 = Ci_ptr[7];
            T12 = T10 - T11;
            T1J = T10 + T11;
        }
        Tp = Tl + To;
        T2i = T1I + T1J;
        T2m = T1X - T1W;
        TN = Tl - To;
        T13 = TZ - T12;
        T1K = T1I - T1J;
        T1Y = T1W + T1X;
        T1k = T12 + TZ;
    }
    {
        E Ts, T1L, TT, T1M, Tv, T1O, TQ, T1P;
        {
            E Tq = Cr_ptr[5], Tr = Cr_ptr[11];
            Ts = Tq + Tr;
            T1L = Tq - Tr;
            E TR = Ci_ptr[5], TS = Ci_ptr[11];
            TT = TR - TS;
            T1M = TR + TS;
        }
        {
            E Tt = Cr_ptr[3], Tu = Cr_ptr[13];
            Tv = Tt + Tu;
            T1O = Tt - Tu;
            E TO = Ci_ptr[13], TP = Ci_ptr[3];
            TQ = TO - TP;
            T1P = TP + TO;
        }
        Tw = Ts + Tv;
        TU = TQ - TT;
        T1l = TT + TQ;
        TW = Ts - Tv;
        {
            E T1T = T1L + T1M, T1U = T1O + T1P;
            T1V = KP707106781 * (T1T - T1U);
            T2j = KP707106781 * (T1T + T1U);
            E T1N = T1L - T1M, T1Q = T1O - T1P;
            T1R = KP707106781 * (T1N + T1Q);
            T2l = KP707106781 * (T1N - T1Q);
        }
    }
    {
        E Tx = KP2_000000000 * (Tp + Tw), T1r = KP2_000000000 * (T1l + T1k), Ti, T1q, Ta = T6 + T9;
        Ti = Ta + Th;
        T1q = Ta - Th;
        R0[8*rs_val] = Ti - Tx;
        R0[12*rs_val] = T1q + T1r;
        R0[0] = Ti + Tx;
        R0[4*rs_val] = T1q - T1r;
    }
    {
        E T1g = T6 - T9, T1i, T1o, T1j = Tp - Tw, T1m = T1k - T1l, T1n, T1p;
        T1i = T1g - T1h;
        T1o = T1g + T1h;
        T1n = KP1_414213562 * (T1j - T1m);
        T1p = KP1_414213562 * (T1j + T1m);
        R0[10*rs_val] = T1i - T1n;
        R0[14*rs_val] = T1o + T1p;
        R0[2*rs_val] = T1i + T1n;
        R0[6*rs_val] = T1o - T1p;
    }
    {
        E TM, T16, T15, T17;
        {
            E TC = Ty - TB, TL = KP1_414213562 * (TD - TK), TV = TN + TU, T14 = TW + T13;
            TM = TC + TL;
            T16 = TC - TL;
            T15 = (KP1_847759065 * TV) - (KP765366864 * T14);
            T17 = (KP765366864 * TV) + (KP1_847759065 * T14);
        }
        R0[9*rs_val] = TM - T15;
        R0[13*rs_val] = T16 + T17;
        R0[1*rs_val] = TM + T15;
        R0[5*rs_val] = T16 - T17;
    }
    {
        E T2r = T2b + T2c, T2s = (KP1_847759065 * T2e) + (KP765366864 * T2f), T2t = T2r - T2s, T2x = T2r + T2s;
        E T2u = T2i + T2j, T2v = T2m - T2l, T2w = (KP390180644 * T2u) - (KP1_961570560 * T2v), T2y = (KP1_961570560 * T2u) + (KP390180644 * T2v);
        R1[11*rs_val] = T2t - T2w;
        R1[15*rs_val] = T2x + T2y;
        R1[3*rs_val] = T2t + T2w;
        R1[7*rs_val] = T2x - T2y;
    }
    {
        E T18 = Ty + TB, T19 = KP1_414213562 * (TD + TK), T1a = T18 - T19, T1e = T18 + T19;
        E T1b = TN - TU, T1c = T13 - TW, T1d = (KP765366864 * T1b) - (KP1_847759065 * T1c), T1f = (KP1_847759065 * T1b) + (KP765366864 * T1c);
        R0[11*rs_val] = T1a - T1d;
        R0[15*rs_val] = T1e + T1f;
        R0[3*rs_val] = T1a + T1d;
        R0[7*rs_val] = T1e - T1f;
    }
    {
        E T23 = T1v - T1y, T24 = (KP765366864 * T1C) + (KP1_847759065 * T1F), T25 = T23 - T24, T29 = T23 + T24;
        E T26 = T1K - T1R, T27 = T1Y - T1V, T28 = (KP1_111140466 * T26) - (KP1_662939224 * T27), T2a = (KP1_662939224 * T26) + (KP1_111140466 * T27);
        R1[10*rs_val] = T25 - T28;
        R1[14*rs_val] = T29 + T2a;
        R1[2*rs_val] = T25 + T28;
        R1[6*rs_val] = T29 - T2a;
    }
    {
        E T2d = T2b - T2c, T2g = (KP765366864 * T2e) - (KP1_847759065 * T2f), T2h = T2d + T2g, T2p = T2d - T2g;
        E T2k = T2i - T2j, T2n = T2l + T2m, T2o = (KP1_662939224 * T2k) - (KP1_111140466 * T2n), T2q = (KP1_111140466 * T2k) + (KP1_662939224 * T2n);
        R1[9*rs_val] = T2h - T2o;
        R1[13*rs_val] = T2p + T2q;
        R1[1*rs_val] = T2h + T2o;
        R1[5*rs_val] = T2p - T2q;
    }
    {
        E T1z = T1v + T1y, T1G = (KP1_847759065 * T1C) - (KP765366864 * T1F), T1H = T1z + T1G, T21 = T1z - T1G;
        E T1S = T1K + T1R, T1Z = T1V + T1Y, T20 = (KP1_961570560 * T1S) - (KP390180644 * T1Z), T22 = (KP390180644 * T1S) + (KP1_961570560 * T1Z);
        R1[8*rs_val] = T1H - T20;
        R1[12*rs_val] = T21 + T22;
        R1[0] = T1H + T20;
        R1[4*rs_val] = T21 - T22;
    }
}
}
