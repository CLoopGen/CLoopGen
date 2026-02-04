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
extern  E KP1_847759065;
extern  E KP765366864;
extern  E KP1_414213562;
extern  E KP2_000000000;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ovs , R1 = R1 + ovs , Cr = Cr + ivs , Ci = Ci + ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T9, TS, Tl, TG, T6, TR, Ti, TD, Td, Tq, Tg, Tt, Tn, Tu, TV;
    E TU, TN, TK;

    // Introduce artificial loop-carried dependency via static accumulator
    static E acc_T9 = 0.0, acc_T6 = 0.0;
    E base_T9, base_T6;

    {
        E T7, T8, TE, Tj, Tk, TF;
        T7 = Cr[(csr[2])];
        T8 = Cr[(csr[6])];
        TE = T7 - T8;
        Tj = Ci[(csi[2])];
        Tk = Ci[(csi[6])];
        TF = Tj + Tk;
        base_T9 = KP2_000000000 * (T7 + T8);
        T9 = base_T9 + acc_T9;  // WAW and loop-carried dependency introduced
        TS = KP1_414213562 * (TE + TF);
        Tl = KP2_000000000 * (Tj - Tk);
        TG = KP1_414213562 * (TE - TF);

        acc_T9 = base_T9 * 0.1; // Feedback for next iteration
    }
    {
        E T5, TC, T3, TA;
        {
            E T4, TB, T1, T2;
            T4 = Cr[(csr[4])];
            T5 = KP2_000000000 * T4;
            TB = Ci[(csi[4])];
            TC = KP2_000000000 * TB;
            T1 = Cr[0];
            T2 = Cr[(csr[8])];
            T3 = T1 + T2;
            TA = T1 - T2;
        }
        base_T6 = T3 + T5;
        T6 = base_T6 + acc_T6;  // Additional loop-carried dependency
        TR = TA + TC;
        Ti = T3 - T5;
        TD = TA - TC;

        acc_T6 = base_T6 * 0.1;
    }
    {
        E TI, TM, TL, TJ;
        {
            E Tb, Tc, To, Tp;
            Tb = Cr[(csr[1])];
            Tc = Cr[(csr[7])];
            Td = Tb + Tc;
            TI = Tb - Tc;
            To = Ci[(csi[1])];
            Tp = Ci[(csi[7])];
            Tq = To - Tp;
            TM = To + Tp;
        }
        {
            E Te, Tf, Tr, Ts;
            Te = Cr[(csr[5])];
            Tf = Cr[(csr[3])];
            Tg = Te + Tf;
            TL = Te - Tf;
            Tr = Ci[(csi[5])];
            Ts = Ci[(csi[3])];
            Tt = Tr - Ts;
            TJ = Tr + Ts;
        }
        Tn = Td - Tg;
        Tu = Tq - Tt;
        TV = TM - TL;
        TU = TI + TJ;
        TN = TL + TM;
        TK = TI - TJ;
    }
    {
        E Ta, Th, TT, TW;
        Ta = T6 + T9;
        Th = KP2_000000000 * (Td + Tg);
        R0[(rs[4])] = Ta - Th;
        R0[0] = Ta + Th;
        TT = TR - TS;
        TW = ((KP765366864 * TU) - ((KP1_847759065) * (TV)));
        R1[(rs[5])] = TT - TW;
        R1[(rs[1])] = TT + TW;
    }
    {
        E TX, TY, Tm, Tv;
        TX = TR + TS;
        TY = (((KP1_847759065) * (TU)) + (KP765366864 * TV));
        R1[(rs[3])] = TX - TY;
        R1[(rs[7])] = TX + TY;
        Tm = Ti - Tl;
        Tv = KP1_414213562 * (Tn - Tu);
        R0[(rs[5])] = Tm - Tv;
        R0[(rs[1])] = Tm + Tv;
    }
    {
        E Tw, Tx, TH, TO;
        Tw = Ti + Tl;
        Tx = KP1_414213562 * (Tn + Tu);
        R0[(rs[3])] = Tw - Tx;
        R0[(rs[7])] = Tw + Tx;
        TH = TD + TG;
        TO = ((KP1_847759065 * TK) - ((KP765366864) * (TN)));
        R1[(rs[4])] = TH - TO;
        R1[0] = TH + TO;
    }
    {
        E TP, TQ, Ty, Tz;
        TP = TD - TG;
        TQ = (((KP765366864) * (TK)) + (KP1_847759065 * TN));
        R1[(rs[2])] = TP - TQ;
        R1[(rs[6])] = TP + TQ;
        Ty = T6 - T9;
        Tz = KP2_000000000 * (Tt + Tq);
        R0[(rs[2])] = Ty - Tz;
        R0[(rs[6])] = Ty + Tz;
    }
}
}
