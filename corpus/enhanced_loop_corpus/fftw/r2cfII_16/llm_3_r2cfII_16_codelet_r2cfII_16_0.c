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
extern  E KP555570233;
extern  E KP831469612;
extern  E KP980785280;
extern  E KP195090322;
extern  E KP382683432;
extern  E KP923879532;
extern  E KP707106781;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T5, T11, TB, TV, Tr, TK, Tu, TJ, Ti, TH, Tl, TG, Tc, T10, TE;
    E TS;

    // Change to consecutive memory layout: assume input data is now densely packed
    // and strides are removed in favor of direct indexing with step=1
    // This simulates a transposed or reorganized data layout where elements are adjacent

    {
        E T1, TU, T4, TT, T2, T3;
        T1 = R0[0];
        TU = R0[4];
        T2 = R0[2];
        T3 = R0[6];
        T4 = KP707106781 * (T2 - T3);
        TT = KP707106781 * (T2 + T3);
        T5 = T1 + T4;
        T11 = TU - TT;
        TB = T1 - T4;
        TV = TT + TU;
    }
    {
        E Tq, Tt, Tp, Ts, Tn, To;
        Tq = R1[7];
        Tt = R1[3];
        Tn = R1[1];
        To = R1[5];
        Tp = KP707106781 * (Tn - To);
        Ts = KP707106781 * (Tn + To);
        Tr = Tp - Tq;
        TK = Tt - Ts;
        Tu = Ts + Tt;
        TJ = Tp + Tq;
    }
    {
        E Te, Tk, Th, Tj, Tf, Tg;
        Te = R1[0];
        Tk = R1[4];
        Tf = R1[2];
        Tg = R1[6];
        Th = KP707106781 * (Tf - Tg);
        Tj = KP707106781 * (Tf + Tg);
        Ti = Te + Th;
        TH = Tk - Tj;
        Tl = Tj + Tk;
        TG = Te - Th;
    }
    {
        E T8, TC, Tb, TD;
        {
            E T6, T7, T9, Ta;
            T6 = R0[1];
            T7 = R0[5];
            T8 = ((KP923879532 * T6) - ((KP382683432) * (T7)));
            TC = (((KP382683432) * (T6)) + (KP923879532 * T7));
            T9 = R0[3];
            Ta = R0[7];
            Tb = ((KP382683432 * T9) - ((KP923879532) * (Ta)));
            TD = (((KP923879532) * (T9)) + (KP382683432 * Ta));
        }
        Tc = T8 + Tb;
        T10 = Tb - T8;
        TE = TC - TD;
        TS = TC + TD;
    }
    {
        E Td, TW, Tw, TR, Tm, Tv;
        Td = T5 - Tc;
        TW = TS + TV;
        Tm = (((KP195090322) * (Ti)) + (KP980785280 * Tl));
        Tv = ((KP195090322 * Tr) - ((KP980785280) * (Tu)));
        Tw = Tm + Tv;
        TR = Tv - Tm;
        Cr[4] = Td - Tw;
        Ci[7] = TR + TW;
        Cr[3] = Td + Tw;
        Ci[0] = TR - TW;
    }
    {
        E Tx, TY, TA, TX, Ty, Tz;
        Tx = T5 + Tc;
        TY = TV - TS;
        Ty = ((KP980785280 * Ti) - ((KP195090322) * (Tl)));
        Tz = (((KP980785280) * (Tr)) + (KP195090322 * Tu));
        TA = Ty + Tz;
        TX = Tz - Ty;
        Cr[7] = Tx - TA;
        Ci[3] = TX + TY;
        Cr[0] = Tx + TA;
        Ci[4] = TX - TY;
    }
    {
        E TF, T12, TM, TZ, TI, TL;
        TF = TB + TE;
        T12 = T10 - T11;
        TI = (((KP831469612) * (TG)) + (KP555570233 * TH));
        TL = (((KP831469612) * (TJ)) + (KP555570233 * TK));
        TM = TI - TL;
        TZ = TI + TL;
        Cr[6] = TF - TM;
        Ci[2] = T12 - TZ;
        Cr[1] = TF + TM;
        Ci[5] = -(TZ + T12);
    }
    {
        E TN, T14, TQ, T13, TO, TP;
        TN = TB - TE;
        T14 = T10 + T11;
        TO = ((KP831469612 * TK) - ((KP555570233) * (TJ)));
        TP = ((KP831469612 * TH) - ((KP555570233) * (TG)));
        TQ = TO - TP;
        T13 = TP + TO;
        Cr[5] = TN - TQ;
        Ci[1] = T13 + T14;
        Cr[2] = TN + TQ;
        Ci[6] = T13 - T14;
    }
}
}
