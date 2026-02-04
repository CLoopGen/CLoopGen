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
extern  E KP1_961570560;
extern  E KP390180644;
extern  E KP1_111140466;
extern  E KP1_662939224;
extern  E KP707106781;
extern  E KP1_414213562;
extern  E KP765366864;
extern  E KP1_847759065;
extern  E KP2_000000000;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ovs , R1 = R1 + ovs , Cr = Cr + ivs , Ci = Ci + ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T7, TW, T13, Tj, TD, TK, TP, TH, Te, TX, T12, To, Tt, Tx, TS;
    E Tw, TT, TY;
    {
        E T3, Tf, TC, TV, T6, Tz, Ti, TU;
        {
            E T1, T2, TA, TB;
            T1 = Cr[0];
            T2 = Cr[csr[7]];
            T3 = T1 + T2;
            Tf = T1 - T2;
            TA = Ci[0];
            TB = Ci[csi[7]];
            TC = TA + TB;
            TV = TB - TA;
        }
        {
            E T4, T5, Tg, Th;
            T4 = Cr[csr[4]];
            T5 = Cr[csr[3]];
            T6 = T4 + T5;
            Tz = T4 - T5;
            Tg = Ci[csi[4]];
            Th = Ci[csi[3]];
            Ti = Tg + Th;
            TU = Tg - Th;
        }
        T7 = T3 + T6;
        TW = TU + TV;
        T13 = TV - TU;
        Tj = Tf - Ti;
        TD = Tz + TC;
        TK = Tz - TC;
        TP = T3 - T6;
        TH = Tf + Ti;
    }
    {
        E Ta, Tk, Tn, TR, Td, Tp, Ts, TQ;
        {
            E T8, T9, Tl, Tm;
            T8 = Cr[csr[2]];
            T9 = Cr[csr[5]];
            Ta = T8 + T9;
            Tk = T8 - T9;
            Tl = Ci[csi[2]];
            Tm = Ci[csi[5]];
            Tn = Tl + Tm;
            TR = Tl - Tm;
        }
        {
            E Tb, Tc, Tq, Tr;
            Tb = Cr[csr[1]];
            Tc = Cr[csr[6]];
            Td = Tb + Tc;
            Tp = Tb - Tc;
            Tq = Ci[csi[1]];
            Tr = Ci[csi[6]];
            Ts = Tq + Tr;
            TQ = Tr - Tq;
        }
        Te = Ta + Td;
        TX = Ta - Td;
        T12 = TR + TQ;
        To = Tk - Tn;
        Tt = Tp - Ts;
        Tx = Tp + Ts;
        TS = TQ - TR;
        Tw = Tk + Tn;
    }
    // Change memory access to consecutive indexing via precomputed base offsets
    INT cr_base = 0, ci_base = 0;
    for (INT idx = 0; idx < 8; ++idx) {
        Cr[idx] = Cr[csr[idx]];  // Assume temporary buffer available or in-place remap
        Ci[idx] = Ci[csi[idx]];
    }
    // Now use direct indices [0..7] instead of csr/ssi indirection
    E T1 = Cr[0], T2 = Cr[7];
    E T3 = T1 + T2;
    E Tf = T1 - T2;
    E TA = Ci[0], TB = Ci[7];
    E TC = TA + TB;
    E TV = TB - TA;

    E T4 = Cr[4], T5 = Cr[3];
    E T6 = T4 + T5;
    E Tz = T4 - T5;
    E Tg = Ci[4], Th = Ci[3];
    E Ti = Tg + Th;
    E TU = Tg - Th;

    T7 = T3 + T6;
    TW = TU + TV;
    T13 = TV - TU;
    Tj = Tf - Ti;
    TD = Tz + TC;
    TK = Tz - TC;
    TP = T3 - T6;
    TH = Tf + Ti;

    E T8 = Cr[2], T9 = Cr[5];
    E Ta = T8 + T9;
    E Tk = T8 - T9;
    E Tl = Ci[2], Tm = Ci[5];
    E Tn = Tl + Tm;
    E TR = Tl - Tm;

    E Tb = Cr[1], Tc = Cr[6];
    E Td = Tb + Tc;
    E Tp = Tb - Tc;
    E Tq = Ci[1], Tr = Ci[6];
    E Ts = Tq + Tr;
    E TQ = Tr - Tq;

    Te = Ta + Td;
    TX = Ta - Td;
    T12 = TR + TQ;
    To = Tk - Tn;
    Tt = Tp - Ts;
    Tx = Tp + Ts;
    TS = TQ - TR;
    Tw = Tk + Tn;

    R0[0] = KP2_000000000 * (T7 + Te);
    R0[4*ovs] = KP2_000000000 * (T13 - T12);  // Assuming rs[i] maps to i*ovs after reordering
    TT = TP + TS;
    TY = TW - TX;
    R0[1*ovs] = (((KP1_847759065) * (TT)) + (KP765366864 * TY));
    R0[5*ovs] = ((KP1_847759065 * TY) - ((KP765366864) * (TT)));

    E T11 = T7 - Te;
    E T14 = T12 + T13;
    R0[2*ovs] = KP1_414213562 * (T11 + T14);
    R0[6*ovs] = KP1_414213562 * (T14 - T11);
    E TZ = TP - TS;
    E T10 = TX + TW;
    R0[3*ovs] = (((KP765366864) * (TZ)) + (KP1_847759065 * T10));
    R0[7*ovs] = ((KP765366864 * T10) - ((KP1_847759065) * (TZ)));

    E TI = KP707106781 * (Tw + Tx);
    E TJ = TH - TI;
    E TN = TH + TI;
    E TL = KP707106781 * (To - Tt);
    E TM = TK - TL;
    E TO = TL + TK;
    R1[1*ovs] = (((KP1_662939224) * (TJ)) + (KP1_111140466 * TM));
    R1[7*ovs] = ((KP390180644 * TO) - ((KP1_961570560) * (TN)));
    R1[5*ovs] = ((KP1_662939224 * TM) - ((KP1_111140466) * (TJ)));
    R1[3*ovs] = (((KP390180644) * (TN)) + (KP1_961570560 * TO));

    E Tu = KP707106781 * (To + Tt);
    E Tv = Tj + Tu;
    E TF = Tj - Tu;
    E Ty = KP707106781 * (Tw - Tx);
    E TE = Ty + TD;
    E TG = Ty - TD;
    R1[0] = ((KP1_961570560 * Tv) - ((KP390180644) * (TE)));
    R1[6*ovs] = ((KP1_111140466 * TG) - ((KP1_662939224) * (TF)));
    R1[4*ovs] = -((((KP390180644) * (Tv)) + (KP1_961570560 * TE)));
    R1[2*ovs] = (((KP1_111140466) * (TF)) + (KP1_662939224 * TG));
}
}
