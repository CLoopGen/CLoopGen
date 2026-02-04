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
    INT idx_csr[9], idx_csi[9], idx_rs[9];

    // Precompute indirect indices for consecutive memory layout access
    for (INT j = 0; j < 9; j++) {
        idx_csr[j] = csr[j];
        idx_csi[j] = csi[j];
        idx_rs[j] = rs[j];
    }

    {
        E T7, T8, TE, Tj, Tk, TF;
        T7 = Cr[idx_csr[2]];
        T8 = Cr[idx_csr[6]];
        TE = T7 - T8;
        Tj = Ci[idx_csi[2]];
        Tk = Ci[idx_csi[6]];
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
            T4 = Cr[idx_csr[4]];
            T5 = KP2_000000000 * T4;
            TB = Ci[idx_csi[4]];
            TC = KP2_000000000 * TB;
            T1 = Cr[0];
            T2 = Cr[idx_csr[8]];
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
            Tb = Cr[idx_csr[1]];
            Tc = Cr[idx_csr[7]];
            Td = Tb + Tc;
            TI = Tb - Tc;
            To = Ci[idx_csi[1]];
            Tp = Ci[idx_csi[7]];
            Tq = To - Tp;
            TM = To + Tp;
        }
        {
            E Te, Tf, Tr, Ts;
            Te = Cr[idx_csr[5]];
            Tf = Cr[idx_csr[3]];
            Tg = Te + Tf;
            TL = Te - Tf;
            Tr = Ci[idx_csi[5]];
            Ts = Ci[idx_csi[3]];
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
        R0[idx_rs[4]] = Ta - Th;
        R0[0] = Ta + Th;
        TT = TR - TS;
        TW = ((KP765366864 * TU) - ((KP1_847759065) * (TV)));
        R1[idx_rs[5]] = TT - TW;
        R1[idx_rs[1]] = TT + TW;
    }
    {
        E TX, TY, Tm, Tv;
        TX = TR + TS;
        TY = (((KP1_847759065) * (TU)) + (KP765366864 * TV));
        R1[idx_rs[3]] = TX - TY;
        R1[idx_rs[7]] = TX + TY;
        Tm = Ti - Tl;
        Tv = KP1_414213562 * (Tn - Tu);
        R0[idx_rs[5]] = Tm - Tv;
        R0[idx_rs[1]] = Tm + Tv;
    }
    {
        E Tw, Tx, TH, TO;
        Tw = Ti + Tl;
        Tx = KP1_414213562 * (Tn + Tu);
        R0[idx_rs[3]] = Tw - Tx;
        R0[idx_rs[7]] = Tw + Tx;
        TH = TD + TG;
        TO = ((KP1_847759065 * TK) - ((KP765366864) * (TN)));
        R1[idx_rs[4]] = TH - TO;
        R1[0] = TH + TO;
    }
    {
        E TP, TQ, Ty, Tz;
        TP = TD - TG;
        TQ = (((KP765366864) * (TK)) + (KP1_847759065 * TN));
        R1[idx_rs[2]] = TP - TQ;
        R1[idx_rs[6]] = TP + TQ;
        Ty = T6 - T9;
        Tz = KP2_000000000 * (Tt + Tq);
        R0[idx_rs[2]] = Ty - Tz;
        R0[idx_rs[6]] = Ty + Tz;
    }
}
}
