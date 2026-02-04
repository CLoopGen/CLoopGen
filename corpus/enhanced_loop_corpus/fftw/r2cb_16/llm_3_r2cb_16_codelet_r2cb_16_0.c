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

    // Convert strided access into a flat consecutive buffer using local arrays
    E Cr_local[9], Ci_local[9], R0_local[9], R1_local[9];
    
    // Load data with stride into local consecutive arrays
    for (INT j = 0; j < 9; j++) {
        Cr_local[j] = Cr[csr[j]];
        Ci_local[j] = Ci[csi[j]];
    }

    {
        E T7, T8, TE, Tj, Tk, TF;
        T7 = Cr_local[2];
        T8 = Cr_local[6];
        TE = T7 - T8;
        Tj = Ci_local[2];
        Tk = Ci_local[6];
        TF = Tj + Tk;
        T9 = KP2_000000000 * (T7 + T8);
        TS = KP1_414213562 * (TE + TF);
        Tl = KP2_000000000 * (Tj - Tk);
        TG = KP1_414213562 * (TE - TF);
    }
    {
        E T5, TC, T3, TA;
        {
            E T4, TB, T1, T2;
            T4 = Cr_local[4];
            T5 = KP2_000000000 * T4;
            TB = Ci_local[4];
            TC = KP2_000000000 * TB;
            T1 = Cr_local[0];
            T2 = Cr_local[8];
            T3 = T1 + T2;
            TA = T1 - T2;
        }
        T6 = T3 + T5;
        TR = TA + TC;
        Ti = T3 - T5;
        TD = TA - TC;
    }
    {
        E TI, TM, TL, TJ;
        {
            E Tb, Tc, To, Tp;
            Tb = Cr_local[1];
            Tc = Cr_local[7];
            Td = Tb + Tc;
            TI = Tb - Tc;
            To = Ci_local[1];
            Tp = Ci_local[7];
            Tq = To - Tp;
            TM = To + Tp;
        }
        {
            E Te, Tf, Tr, Ts;
            Te = Cr_local[5];
            Tf = Cr_local[3];
            Tg = Te + Tf;
            TL = Te - Tf;
            Tr = Ci_local[5];
            Ts = Ci_local[3];
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

    // Compute results in local array
    {
        E Ta, Th, TT, TW;
        Ta = T6 + T9;
        Th = KP2_000000000 * (Td + Tg);
        R0_local[4] = Ta - Th;
        R0_local[0] = Ta + Th;
        TT = TR - TS;
        TW = ((KP765366864 * TU) - ((KP1_847759065) * (TV)));
        R1_local[5] = TT - TW;
        R1_local[1] = TT + TW;
    }
    {
        E TX, TY, Tm, Tv;
        TX = TR + TS;
        TY = (((KP1_847759065) * (TU)) + (KP765366864 * TV));
        R1_local[3] = TX - TY;
        R1_local[7] = TX + TY;
        Tm = Ti - Tl;
        Tv = KP1_414213562 * (Tn - Tu);
        R0_local[5] = Tm - Tv;
        R0_local[1] = Tm + Tv;
    }
    {
        E Tw, Tx, TH, TO;
        Tw = Ti + Tl;
        Tx = KP1_414213562 * (Tn + Tu);
        R0_local[3] = Tw - Tx;
        R0_local[7] = Tw + Tx;
        TH = TD + TG;
        TO = ((KP1_847759065 * TK) - ((KP765366864) * (TN)));
        R1_local[4] = TH - TO;
        R1_local[0] = TH + TO;
    }
    {
        E TP, TQ, Ty, Tz;
        TP = TD - TG;
        TQ = (((KP765366864) * (TK)) + (KP1_847759065 * TN));
        R1_local[2] = TP - TQ;
        R1_local[6] = TP + TQ;
        Ty = T6 - T9;
        Tz = KP2_000000000 * (Tt + Tq);
        R0_local[2] = Ty - Tz;
        R0_local[6] = Ty + Tz;
    }

    // Store results back with stride from local consecutive storage
    for (INT j = 0; j < 9; j++) {
        R0[rs[j]] = R0_local[j];
        R1[rs[j]] = R1_local[j];
    }
}
}
