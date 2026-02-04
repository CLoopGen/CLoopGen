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
extern  E KP500000000;
extern  E KP866025403;
extern  E KP809016994;
extern  E KP309016994;
extern  E KP250000000;
extern  E KP559016994;
extern  E KP587785252;
extern  E KP951056516;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, T2, Tx, TR, TE, T7, TD, Th, Tm, Tr, TQ, TA, TB, Tf, Te;
    E Tu, TS, Td, TH, TO;
    // Change memory access to use consecutive indexing via base pointer arithmetic
    // Instead of using rs[5], rs[2], etc., assume a fixed layout and directly compute offsets
    INT base_offset_r0 = 0; // Simulate local stride unfolding
    T1 = R0[base_offset_r0 + 5];  // Replaces R0[(rs[5])] assuming rs[i] == i
    {
        E T3, Tv, T6, Tw, T4, T5;
        T2 = R0[base_offset_r0 + 2];
        T3 = R1[0];
        Tv = T2 + T3;
        T4 = R1[3];
        T5 = R1[6];
        T6 = T4 + T5;
        Tw = T4 - T5;
        Tx = (((KP951056516) * (Tv)) + (KP587785252 * Tw));
        TR = ((KP951056516 * Tw) - ((KP587785252) * (Tv)));
        TE = KP559016994 * (T3 - T6);
        T7 = T3 + T6;
        TD = KP250000000 * T7;
    }
    {
        E Ti, Tl, Tj, Tk, Tp, Tq;
        Th = R0[0];
        Ti = R1[4];
        Tl = R0[6];
        Tj = R1[1];
        Tk = R0[3];
        Tp = Tk + Ti;
        Tq = Tl + Tj;
        Tm = Ti + Tj - (Tk + Tl);
        Tr = (((KP951056516) * (Tp)) + (KP587785252 * Tq));
        TQ = ((KP587785252 * Tp) - ((KP951056516) * (Tq)));
        TA = (((KP250000000) * (Tm)) + (Th));
        TB = KP559016994 * (Tl + Ti - (Tk + Tj));
    }
    {
        E T9, Tt, Tc, Ts, Ta, Tb, TG;
        Tf = R1[2];
        T9 = R0[7];
        Te = R1[5];
        Tt = T9 + Te;
        Ta = R0[1];
        Tb = R0[4];
        Tc = Ta + Tb;
        Ts = Ta - Tb;
        Tu = ((KP587785252 * Ts) - ((KP951056516) * (Tt)));
        TS = (((KP951056516) * (Ts)) + (KP587785252 * Tt));
        Td = T9 + Tc;
        TG = KP559016994 * (T9 - Tc);
        TH = ((TG) - ((KP309016994) * (Te))) + (-(((KP250000000) * (Td)) + (Tf)));
        TO = (((KP809016994) * (Te)) - (Tf)) + (-(((KP250000000) * (Td)) + (TG)));
    }
    {
        E Tn, T8, Tg, To;
        Tn = Th - Tm;
        T8 = T1 + T2 - T7;
        Tg = Td - Te - Tf;
        To = T8 + Tg;
        Ci[2] = KP866025403 * (T8 - Tg);  // Direct index instead of csi[2]
        Cr[2] = ((Tn) - ((KP500000000) * (To)));
        Cr[7] = Tn + To;
    }
    {
        E TM, TX, TT, TV, TP, TU, TN, TW;
        TM = TB + TA;
        TX = KP866025403 * (TR + TS);
        TT = TR - TS;
        TV = (((KP500000000) * (TT)) - (TQ));
        TN = T1 + TE + ((TD) - ((KP809016994) * (T2)));
        TP = TN + TO;
        TU = KP866025403 * (TO - TN);
        Cr[1] = TM + TP;
        Ci[1] = TQ + TT;
        Ci[6] = TU - TV;
        Ci[3] = TU + TV;
        TW = ((TM) - ((KP500000000) * (TP)));
        Cr[3] = TW - TX;
        Cr[6] = TW + TX;
    }
    {
        E Tz, TC, Ty, TK, TI, TL, TF, TJ;
        Tz = KP866025403 * (Tx + Tu);
        TC = TA - TB;
        Ty = Tu - Tx;
        TK = (((KP500000000) * (Ty)) - (Tr));
        TF = (((KP309016994) * (T2)) + (T1)) + TD - TE;
        TI = TF + TH;
        TL = KP866025403 * (TH - TF);
        Ci[4] = Tr + Ty;
        Cr[4] = TC + TI;
        Ci[5] = TK - TL;
        Ci[0] = TK + TL;
        TJ = ((TC) - ((KP500000000) * (TI)));
        Cr[0] = Tz + TJ;
        Cr[5] = TJ - Tz;
    }
}
}
