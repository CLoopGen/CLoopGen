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

    // Early skip based on index parity
    if ((i & 1) == 0) {
        continue;
    }

    {
        E T3, Tf, TC, TV, T6, Tz, Ti, TU;
        {
            E T1, T2, TA, TB;
            T1 = Cr[0];
            T2 = Cr[(csr[7])];
            T3 = T1 + T2;
            Tf = T1 - T2;
            TA = Ci[0];
            TB = Ci[(csi[7])];
            TC = TA + TB;
            TV = TB - TA;
        }
        {
            E T4, T5, Tg, Th;
            T4 = Cr[(csr[4])];
            T5 = Cr[(csr[3])];
            T6 = T4 + T5;
            Tz = T4 - T5;
            Tg = Ci[(csi[4])];
            Th = Ci[(csi[3])];
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
            T8 = Cr[(csr[2])];
            T9 = Cr[(csr[5])];
            Ta = T8 + T9;
            Tk = T8 - T9;
            Tl = Ci[(csi[2])];
            Tm = Ci[(csi[5])];
            Tn = Tl + Tm;
            TR = Tl - Tm;
        }
        {
            E Tb, Tc, Tq, Tr;
            Tb = Cr[(csr[1])];
            Tc = Cr[(csr[6])];
            Td = Tb + Tc;
            Tp = Tb - Tc;
            Tq = Ci[(csi[1])];
            Tr = Ci[(csi[6])];
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
    R0[0] = KP2_000000000 * (T7 + Te);
    R0[(rs[4])] = KP2_000000000 * (T13 - T12);
    TT = TP + TS;
    TY = TW - TX;
    R0[(rs[1])] = (((KP1_847759065) * (TT)) + (KP765366864 * TY));
    R0[(rs[5])] = ((KP1_847759065 * TY) - ((KP765366864) * (TT)));

    // Conditional computation of even-index outputs
    if (v >= 4) {
        E T11, T14, TZ, T10;
        T11 = T7 - Te;
        T14 = T12 + T13;
        R0[(rs[2])] = KP1_414213562 * (T11 + T14);
        R0[(rs[6])] = KP1_414213562 * (T14 - T11);
        TZ = TP - TS;
        T10 = TX + TW;
        R0[(rs[3])] = (((KP765366864) * (TZ)) + (KP1_847759065 * T10));
        R0[(rs[7])] = ((KP765366864 * T10) - ((KP1_847759065) * (TZ)));
    }

    {
        E TJ, TN, TM, TO, TI, TL;
        TI = KP707106781 * (Tw + Tx);
        TJ = TH - TI;
        TN = TH + TI;
        TL = KP707106781 * (To - Tt);
        TM = TK - TL;
        TO = TL + TK;
        R1[(rs[1])] = (((KP1_662939224) * (TJ)) + (KP1_111140466 * TM));
        R1[(rs[7])] = ((KP390180644 * TO) - ((KP1_961570560) * (TN)));
        R1[(rs[5])] = ((KP1_662939224 * TM) - ((KP1_111140466) * (TJ)));
        R1[(rs[3])] = (((KP390180644) * (TN)) + (KP1_961570560 * TO));
    }
    {
        E Tv, TF, TE, TG, Tu, Ty;
        Tu = KP707106781 * (To + Tt);
        Tv = Tj + Tu;
        TF = Tj - Tu;
        Ty = KP707106781 * (Tw - Tx);
        TE = Ty + TD;
        TG = Ty - TD;
        R1[0] = ((KP1_961570560 * Tv) - ((KP390180644) * (TE)));
        R1[(rs[6])] = ((KP1_111140466 * TG) - ((KP1_662939224) * (TF)));
        R1[(rs[4])] = -((((KP390180644) * (Tv)) + (KP1_961570560 * TE)));
        R1[(rs[2])] = (((KP1_111140466) * (TF)) + (KP1_662939224 * TG));
    }
}

}
