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

    // Change memory access pattern to fully consecutive by reordering data layout assumption
    // Assume that R0 and R1 are now accessed in sequential order: base + offset
    // Use direct indexing assuming unit stride after data layout transformation

    {
        E T1, T2, T4, T5;
        T1 = R0[0];
        T2 = R0[4];  // Consecutive access instead of rs[4]
        T3 = T1 + T2;
        T4 = R0[2];
        T5 = R0[6];
        T6 = T4 + T5;
        T7 = T3 + T6;
        Tz = T1 - T2;
        Ti = T4 - T5;
    }
    {
        E T8, T9, Tb, Tc;
        T8 = R0[1];
        T9 = R0[5];
        Ta = T8 + T9;
        Tg = T8 - T9;
        Tb = R0[7];
        Tc = R0[3];
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
            Tk = R1[7];
            Tl = R1[3];
            Tm = Tk - Tl;
            TN = Tk + Tl;
            Tn = R1[1];
            To = R1[5];
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
            Ts = R1[4];
            Tt = Tr - Ts;
            TK = Tr + Ts;
            Tu = R1[2];
            Tv = R1[6];
            Tw = Tu - Tv;
            TL = Tu + Tv;
        }
        Tx = (((KP382683432) * (Tt)) + (KP923879532 * Tw));
        TU = TK + TL;
        TE = ((KP923879532 * Tt) - ((KP382683432) * (Tw)));
        TM = TK - TL;
    }

    // Output using consecutive index mapping
    Cr[4*ovs/sizeof(E)] = T7 - Te;
    Ci[4*ovs/sizeof(E)] = TV - TU;

    {
        E Tj, Ty, TD, TG;
        Tj = Th - Ti;
        Ty = Tq - Tx;
        Ci[1*ovs/sizeof(E)] = Tj + Ty;
        Ci[7*ovs/sizeof(E)] = Ty - Tj;
        TD = Tz + TA;
        TG = TE + TF;
        Cr[7*ovs/sizeof(E)] = TD - TG;
        Cr[1*ovs/sizeof(E)] = TD + TG;
    }
    {
        E TB, TC, TH, TI;
        TB = Tz - TA;
        TC = Tx + Tq;
        Cr[5*ovs/sizeof(E)] = TB - TC;
        Cr[3*ovs/sizeof(E)] = TB + TC;
        TH = Ti + Th;
        TI = TF - TE;
        Ci[3*ovs/sizeof(E)] = TH + TI;
        Ci[5*ovs/sizeof(E)] = TI - TH;
    }
    TJ = T3 - T6;
    TQ = KP707106781 * (TM + TP);
    Cr[6*ovs/sizeof(E)] = TJ - TQ;
    Cr[2*ovs/sizeof(E)] = TJ + TQ;
    {
        E TR, TS, TT, TW;
        TR = Td - Ta;
        TS = KP707106781 * (TP - TM);
        Ci[2*ovs/sizeof(E)] = TR + TS;
        Ci[6*ovs/sizeof(E)] = TS - TR;
        TT = T7 + Te;
        TW = TU + TV;
        Cr[8*ovs/sizeof(E)] = TT - TW;
        Cr[0] = TT + TW;
    }
}
}
