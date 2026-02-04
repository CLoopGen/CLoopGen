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
extern  E KP923879532;
extern  E KP382683432;
extern  E KP707106781;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, T6, T7, Tz, Ti, Ta, Td, Te, TA, Th, Tq, TV, TF, TP, Tx;
    E TU, TE, TM, Tg, Tf, TJ, TQ;
    INT idx_r[8], idx_csr[9], idx_csi[9];
    
    // Precompute indirect indices for consecutive logical access with strided physical layout
    for (INT j = 0; j < 8; j++) {
        idx_r[j] = rs[j];
    }
    for (INT j = 0; j < 9; j++) {
        idx_csr[j] = csr[j];
        idx_csi[j] = csi[j];
    }

    {
        E T1, T2, T4, T5;
        T1 = R0[0];
        T2 = R0[idx_r[4]];
        T3 = T1 + T2;
        T4 = R0[idx_r[2]];
        T5 = R0[idx_r[6]];
        T6 = T4 + T5;
        T7 = T3 + T6;
        Tz = T1 - T2;
        Ti = T4 - T5;
    }
    {
        E T8, T9, Tb, Tc;
        T8 = R0[idx_r[1]];
        T9 = R0[idx_r[5]];
        Ta = T8 + T9;
        Tg = T8 - T9;
        Tb = R0[idx_r[7]];
        Tc = R0[idx_r[3]];
        Td = Tb + Tc;
        Tf = Tb - Tc;
    }
    Te = Ta + Td;
    TA = KP707106781 * (Tg + Tf);
    Th = KP707106781 * (Tf - Tg);
    {
        E Tm, TN, Tp, TO;
        {
            E Tk, Tl, Tn, To;
            Tk = R1[idx_r[7]];
            Tl = R1[idx_r[3]];
            Tm = Tk - Tl;
            TN = Tk + Tl;
            Tn = R1[idx_r[1]];
            To = R1[idx_r[5]];
            Tp = Tn - To;
            TO = Tn + To;
        }
        Tq = ((KP382683432 * Tm) - ((KP923879532) * (Tp)));
        TV = TN + TO;
        TF = (((KP923879532) * (Tm)) + (KP382683432 * Tp));
        TP = TN - TO;
    }
    {
        E Tt, TK, Tw, TL;
        {
            E Tr, Ts, Tu, Tv;
            Tr = R1[0];
            Ts = R1[idx_r[4]];
            Tt = Tr - Ts;
            TK = Tr + Ts;
            Tu = R1[idx_r[2]];
            Tv = R1[idx_r[6]];
            Tw = Tu - Tv;
            TL = Tu + Tv;
        }
        Tx = (((KP382683432) * (Tt)) + (KP923879532 * Tw));
        TU = TK + TL;
        TE = ((KP923879532 * Tt) - ((KP382683432) * (Tw)));
        TM = TK - TL;
    }
    Cr[idx_csr[4]] = T7 - Te;
    Ci[idx_csi[4]] = TV - TU;
    {
        E Tj, Ty, TD, TG;
        Tj = Th - Ti;
        Ty = Tq - Tx;
        Ci[idx_csi[1]] = Tj + Ty;
        Ci[idx_csi[7]] = Ty - Tj;
        TD = Tz + TA;
        TG = TE + TF;
        Cr[idx_csr[7]] = TD - TG;
        Cr[idx_csr[1]] = TD + TG;
    }
    {
        E TB, TC, TH, TI;
        TB = Tz - TA;
        TC = Tx + Tq;
        Cr[idx_csr[5]] = TB - TC;
        Cr[idx_csr[3]] = TB + TC;
        TH = Ti + Th;
        TI = TF - TE;
        Ci[idx_csi[3]] = TH + TI;
        Ci[idx_csi[5]] = TI - TH;
    }
    TJ = T3 - T6;
    TQ = KP707106781 * (TM + TP);
    Cr[idx_csr[6]] = TJ - TQ;
    Cr[idx_csr[2]] = TJ + TQ;
    {
        E TR, TS, TT, TW;
        TR = Td - Ta;
        TS = KP707106781 * (TP - TM);
        Ci[idx_csi[2]] = TR + TS;
        Ci[idx_csi[6]] = TS - TR;
        TT = T7 + Te;
        TW = TU + TV;
        Cr[idx_csr[8]] = TT - TW;
        Cr[0] = TT + TW;
    }
}
}
