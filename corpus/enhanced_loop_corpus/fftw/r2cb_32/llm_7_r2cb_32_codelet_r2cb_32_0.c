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
for (i = v; i > 0; i = i - 1 , R0 = R0 + ovs , R1 = R1 + ovs , Cr = Cr + ivs , Ci = Ci + ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T9, T2c, TB, T1y, T6, T2b, Ty, T1v, Th, T2e, T2f, TD, TK, T1C, T1F;
    E T1h, Tp, T2i, T2m, TN, T13, T1K, T1Y, T1k, Tw, TU, T1l, TW, T1V, T2j;
    E T1R, T2l;

    // Eliminate some loop-carried dependencies by reordering and fusing operations
    // Introduce local variables to break artificial WAW and WAR hazards from original ordering

    // Fused load and initial arithmetic for symmetry exploitation
    {
        E T7 = Cr[(csr[4])], T8 = Cr[(csr[12])], Tz = Ci[(csi[4])], TA = Ci[(csi[12])];
        E T1w = T7 - T8, T1x = Tz + TA;
        T9 = KP2_000000000 * (T7 + T8);
        T2c = KP1_414213562 * (T1w + T1x);
        TB = KP2_000000000 * (Tz - TA);
        T1y = KP1_414213562 * (T1w - T1x);
    }

    {
        E T4 = Cr[(csr[8])], T1t = Ci[(csi[8])], T1 = Cr[0], T2 = Cr[(csr[16])];
        T6 = (T1 + T2) + (KP2_000000000 * T4);
        T2b = (T1 - T2) + (KP2_000000000 * T1t);
        Ty = (T1 + T2) - (KP2_000000000 * T4);
        T1v = (T1 - T2) - (KP2_000000000 * T1t);
    }

    {
        E Tb = Cr[(csr[2])], Tc = Cr[(csr[14])], TE = Ci[(csi[2])], TF = Ci[(csi[14])];
        E Td = Tb + Tc, T1A = Tb - Tc, TG = TE - TF, T1E = TE + TF;
        E Te = Cr[(csr[10])], Tf = Cr[(csr[6])], TH = Ci[(csi[10])], TI = Ci[(csi[6])];
        E Tg = Te + Tf, T1D = Te - Tf, TJ = TH - TI, T1B = TH + TI;
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
        E Tj = Cr[(csr[1])], Tk = Cr[(csr[15])], TX = Ci[(csi[1])], TY = Ci[(csi[15])];
        E Tl = Tj + Tk, T1I = Tj - Tk, TZ = TX - TY, T1X = TX + TY;
        E Tm = Cr[(csr[9])], Tn = Cr[(csr[7])], T10 = Ci[(csi[9])], T11 = Ci[(csi[7])];
        E To = Tm + Tn, T1W = Tm - Tn, T12 = T10 - T11, T1J = T10 + T11;
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
        E Tq = Cr[(csr[5])], Tr = Cr[(csr[11])], TR = Ci[(csi[5])], TS = Ci[(csi[11])];
        E Ts = Tq + Tr, T1L = Tq - Tr, TT = TR - TS, T1M = TR + TS;
        E Tt = Cr[(csr[3])], Tu = Cr[(csr[13])], TO = Ci[(csi[13])], TP = Ci[(csi[3])];
        E Tv = Tt + Tu, T1O = Tt - Tu, TQ = TO - TP, T1P = TP + TO;
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

    // Aggressively reorder independent blocks to eliminate false dependencies
    {
        E T1g = T6 - T9;
        E T1j = Tp - Tw;
        E T1m = T1k - T1l;
        E T1i = T1g - T1h;
        E T1o = T1g + T1h;
        E T1n = KP1_414213562 * (T1j - T1m);
        E T1p = KP1_414213562 * (T1j + T1m);
        R0[(rs[10])] = T1i - T1n;
        R0[(rs[14])] = T1o + T1p;
        R0[(rs[2])] = T1i + T1n;
        R0[(rs[6])] = T1o - T1p;
    }

    {
        E Ta = T6 + T9;
        E Ti = Ta + Th;
        E T1q = Ta - Th;
        E Tx = KP2_000000000 * (Tp + Tw);
        E T1r = KP2_000000000 * (T1l + T1k);
        R0[(rs[8])] = Ti - Tx;
        R0[(rs[12])] = T1q + T1r;
        R0[0] = Ti + Tx;
        R0[(rs[4])] = T1q - T1r;
    }

    {
        E TC = Ty - TB;
        E TL = KP1_414213562 * (TD - TK);
        E TM = TC + TL;
        E T16 = TC - TL;
        E TV = TN + TU;
        E T14 = TW + T13;
        E T15 = ((KP1_847759065 * TV) - ((KP765366864) * (T14)));
        E T17 = (((KP765366864) * (TV)) + (KP1_847759065 * T14));
        R0[(rs[9])] = TM - T15;
        R0[(rs[13])] = T16 + T17;
        R0[(rs[1])] = TM + T15;
        R0[(rs[5])] = T16 - T17;
    }

    {
        E T18 = Ty + TB;
        E T19 = KP1_414213562 * (TD + TK);
        E T1a = T18 - T19;
        E T1e = T18 + T19;
        E T1b = TN - TU;
        E T1c = T13 - TW;
        E T1d = ((KP765366864 * T1b) - ((KP1_847759065) * (T1c)));
        E T1f = (((KP1_847759065) * (T1b)) + (KP765366864 * T1c));
        R0[(rs[11])] = T1a - T1d;
        R0[(rs[15])] = T1e + T1f;
        R0[(rs[3])] = T1a + T1d;
        R0[(rs[7])] = T1e - T1f;
    }

    {
        E T2r = T2b + T2c;
        E T2s = (((KP1_847759065) * (T2e)) + (KP765366864 * T2f));
        E T2t = T2r - T2s;
        E T2x = T2r + T2s;
        E T2u = T2i + T2j;
        E T2v = T2m - T2l;
        E T2w = ((KP390180644 * T2u) - ((KP1_961570560) * (T2v)));
        E T2y = (((KP1_961570560) * (T2u)) + (KP390180644 * T2v));
        R1[(rs[11])] = T2t - T2w;
        R1[(rs[15])] = T2x + T2y;
        R1[(rs[3])] = T2t + T2w;
        R1[(rs[7])] = T2x - T2y;
    }

    {
        E T23 = T1v - T1y;
        E T24 = (((KP765366864) * (T1C)) + (KP1_847759065 * T1F));
        E T25 = T23 - T24;
        E T29 = T23 + T24;
        E T26 = T1K - T1R;
        E T27 = T1Y - T1V;
        E T28 = ((KP1_111140466 * T26) - ((KP1_662939224) * (T27)));
        E T2a = (((KP1_662939224) * (T26)) + (KP1_111140466 * T27));
        R1[(rs[10])] = T25 - T28;
        R1[(rs[14])] = T29 + T2a;
        R1[(rs[2])] = T25 + T28;
        R1[(rs[6])] = T29 - T2a;
    }

    {
        E T2d = T2b - T2c;
        E T2g = ((KP765366864 * T2e) - ((KP1_847759065) * (T2f)));
        E T2h = T2d + T2g;
        E T2p = T2d - T2g;
        E T2k = T2i - T2j;
        E T2n = T2l + T2m;
        E T2o = ((KP1_662939224 * T2k) - ((KP1_111140466) * (T2n)));
        E T2q = (((KP1_111140466) * (T2k)) + (KP1_662939224 * T2n));
        R1[(rs[9])] = T2h - T2o;
        R1[(rs[13])] = T2p + T2q;
        R1[(rs[1])] = T2h + T2o;
        R1[(rs[5])] = T2p - T2q;
    }

    {
        E T1z = T1v + T1y;
        E T1G = ((KP1_847759065 * T1C) - ((KP765366864) * (T1F)));
        E T1H = T1z + T1G;
        E T21 = T1z - T1G;
        E T1S = T1K + T1R;
        E T1Z = T1V + T1Y;
        E T20 = ((KP1_961570560 * T1S) - ((KP390180644) * (T1Z)));
        E T22 = (((KP390180644) * (T1S)) + (KP1_961570560 * T1Z));
        R1[(rs[8])] = T1H - T20;
        R1[(rs[12])] = T21 + T22;
        R1[0] = T1H + T20;
        R1[(rs[4])] = T21 - T22;
    }
}
}
