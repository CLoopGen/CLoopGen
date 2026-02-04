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
extern  E KP1_118033988;
extern  E KP500000000;
extern  E KP1_902113032;
extern  E KP1_175570504;
extern  E KP2_000000000;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
INT j;
for (i = v; i > 0; i = i - 2 , R0 = R0 + 2*ovs , R1 = R1 + 2*ovs , Cr = Cr + 2*ivs , Ci = Ci + 2*ivs , (rs) = (rs) + 2*fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + 2*fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    if (i < 1) break;

    for (j = 0; j < 2 && (i + j) > 0; ++j) {
        INT idx_r0 = j * ovs;
        INT idx_r1 = j * ovs;
        INT idx_cr = j * ivs;
        INT idx_ci = j * ivs;

        E T6, TF, Tm, Tt, TQ, T1n, T1f, T12, T1m, TV, T13, T1c, Td, Tk, Tl;
        E Ty, TD, TE, Tn, To, Tp, TG, TH, TI;
        {
            E T5, Ts, T3, Tq;
            {
                E T4, Tr, T1, T2;
                T4 = Cr[idx_cr + (csr[5])];
                T5 = KP2_000000000 * T4;
                Tr = Ci[idx_ci + (csi[5])];
                Ts = KP2_000000000 * Tr;
                T1 = Cr[idx_cr + 0];
                T2 = Cr[idx_cr + (csr[10])];
                T3 = T1 + T2;
                Tq = T1 - T2;
            }
            T6 = T3 - T5;
            TF = Tq - Ts;
            Tm = T3 + T5;
            Tt = Tq + Ts;
        }
        {
            E T9, Tu, TO, T1b, Tc, T1a, Tx, TP, Tg, Tz, TT, T1e, Tj, T1d, TC;
            E TU;
            {
                E T7, T8, TM, TN;
                T7 = Cr[idx_cr + (csr[4])];
                T8 = Cr[idx_cr + (csr[6])];
                T9 = T7 + T8;
                Tu = T7 - T8;
                TM = Ci[idx_ci + (csi[4])];
                TN = Ci[idx_ci + (csi[6])];
                TO = TM - TN;
                T1b = TM + TN;
            }
            {
                E Ta, Tb, Tv, Tw;
                Ta = Cr[idx_cr + (csr[9])];
                Tb = Cr[idx_cr + (csr[1])];
                Tc = Ta + Tb;
                T1a = Ta - Tb;
                Tv = Ci[idx_ci + (csi[9])];
                Tw = Ci[idx_ci + (csi[1])];
                Tx = Tv + Tw;
                TP = Tv - Tw;
            }
            {
                E Te, Tf, TR, TS;
                Te = Cr[idx_cr + (csr[8])];
                Tf = Cr[idx_cr + (csr[2])];
                Tg = Te + Tf;
                Tz = Te - Tf;
                TR = Ci[idx_ci + (csi[8])];
                TS = Ci[idx_ci + (csi[2])];
                TT = TR - TS;
                T1e = TR + TS;
            }
            {
                E Th, Ti, TA, TB;
                Th = Cr[idx_cr + (csr[7])];
                Ti = Cr[idx_cr + (csr[3])];
                Tj = Th + Ti;
                T1d = Th - Ti;
                TA = Ci[idx_ci + (csi[7])];
                TB = Ci[idx_ci + (csi[3])];
                TC = TA + TB;
                TU = TB - TA;
            }
            TQ = TO - TP;
            T1n = T1e - T1d;
            T1f = T1d + T1e;
            T12 = TP + TO;
            T1m = T1b - T1a;
            TV = TT - TU;
            T13 = TU + TT;
            T1c = T1a + T1b;
            Td = T9 - Tc;
            Tk = Tg - Tj;
            Tl = Td + Tk;
            Ty = Tu + Tx;
            TD = Tz - TC;
            TE = Ty + TD;
            Tn = T9 + Tc;
            To = Tg + Tj;
            Tp = Tn + To;
            TG = Tu - Tx;
            TH = Tz + TC;
            TI = TG + TH;
        }
        R0[idx_r0 + (rs[5])] = (((KP2_000000000) * (Tl)) + (T6));
        R1[idx_r1 + (rs[7])] = (((KP2_000000000) * (TE)) + (Tt));
        R1[idx_r1 + (rs[2])] = (((KP2_000000000) * (TI)) + (TF));
        R0[idx_r0 + 0] = (((KP2_000000000) * (Tp)) + (Tm));
        {
            E TW, TY, TL, TX, TJ, TK;
            TW = ((KP1_175570504 * TQ) - ((KP1_902113032) * (TV)));
            TY = (((KP1_902113032) * (TQ)) + (KP1_175570504 * TV));
            TJ = ((T6) - ((KP500000000) * (Tl)));
            TK = KP1_118033988 * (Td - Tk);
            TL = TJ - TK;
            TX = TK + TJ;
            R0[idx_r0 + (rs[1])] = TL - TW;
            R0[idx_r0 + (rs[7])] = TX + TY;
            R0[idx_r0 + (rs[9])] = TL + TW;
            R0[idx_r0 + (rs[3])] = TX - TY;
        }
        {
            E T1g, T1i, T19, T1h, T17, T18;
            T1g = ((KP1_175570504 * T1c) - ((KP1_902113032) * (T1f)));
            T1i = (((KP1_902113032) * (T1c)) + (KP1_175570504 * T1f));
            T17 = ((TF) - ((KP500000000) * (TI)));
            T18 = KP1_118033988 * (TG - TH);
            T19 = T17 - T18;
            T1h = T18 + T17;
            R1[idx_r1 + (rs[8])] = T19 - T1g;
            R1[idx_r1 + (rs[4])] = T1h + T1i;
            R1[idx_r1 + (rs[6])] = T19 + T1g;
            R1[idx_r1 + 0] = T1h - T1i;
        }
        {
            E T1o, T1q, T1l, T1p, T1j, T1k;
            T1o = ((KP1_175570504 * T1m) - ((KP1_902113032) * (T1n)));
            T1q = (((KP1_902113032) * (T1m)) + (KP1_175570504 * T1n));
            T1j = ((Tt) - ((KP500000000) * (TE)));
            T1k = KP1_118033988 * (Ty - TD);
            T1l = T1j - T1k;
            T1p = T1k + T1j;
            R1[idx_r1 + (rs[3])] = T1l - T1o;
            R1[idx_r1 + (rs[9])] = T1p + T1q;
            R1[idx_r1 + (rs[1])] = T1l + T1o;
            R1[idx_r1 + (rs[5])] = T1p - T1q;
        }
        {
            E T14, T16, T11, T15, TZ, T10;
            T14 = ((KP1_175570504 * T12) - ((KP1_902113032) * (T13)));
            T16 = (((KP1_902113032) * (T12)) + (KP1_175570504 * T13));
            TZ = ((Tm) - ((KP500000000) * (Tp)));
            T10 = KP1_118033988 * (Tn - To);
            T11 = TZ - T10;
            T15 = T10 + TZ;
            R0[idx_r0 + (rs[6])] = T11 - T14;
            R0[idx_r0 + (rs[2])] = T15 + T16;
            R0[idx_r0 + (rs[4])] = T11 + T14;
            R0[idx_r0 + (rs[8])] = T15 - T16;
        }
    }
}
}
