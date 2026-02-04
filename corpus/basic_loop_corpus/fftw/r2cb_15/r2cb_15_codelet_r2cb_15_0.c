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
extern  E KP1_902113032;
extern  E KP1_175570504;
extern  E KP500000000;
extern  E KP866025403;
extern  E KP2_000000000;
extern  E KP1_732050807;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ovs , R1 = R1 + ovs , Cr = Cr + ivs , Ci = Ci + ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, Tu, Ti, TB, TZ, T10, TE, TG, TJ, Tn, Tv, Ts, Tw, T8, Td;
    E Te;
    {
        E Th, T1, T2, Tf, Tg;
        Tg = Ci[(csi[5])];
        Th = KP1_732050807 * Tg;
        T1 = Cr[0];
        T2 = Cr[(csr[5])];
        Tf = T1 - T2;
        T3 = (((KP2_000000000) * (T2)) + (T1));
        Tu = Tf - Th;
        Ti = Tf + Th;
    }
    {
        E T4, TD, T9, TI, T5, T6, T7, Ta, Tb, Tc, Tr, TH, Tm, TC, Tj;
        E To;
        T4 = Cr[(csr[3])];
        TD = Ci[(csi[3])];
        T9 = Cr[(csr[6])];
        TI = Ci[(csi[6])];
        T5 = Cr[(csr[7])];
        T6 = Cr[(csr[2])];
        T7 = T5 + T6;
        Ta = Cr[(csr[4])];
        Tb = Cr[(csr[1])];
        Tc = Ta + Tb;
        {
            E Tp, Tq, Tk, Tl;
            Tp = Ci[(csi[4])];
            Tq = Ci[(csi[1])];
            Tr = KP866025403 * (Tp + Tq);
            TH = Tp - Tq;
            Tk = Ci[(csi[7])];
            Tl = Ci[(csi[2])];
            Tm = KP866025403 * (Tk - Tl);
            TC = Tk + Tl;
        }
        TB = KP866025403 * (T5 - T6);
        TZ = TD - TC;
        T10 = TI - TH;
        TE = (((KP500000000) * (TC)) + (TD));
        TG = KP866025403 * (Ta - Tb);
        TJ = (((KP500000000) * (TH)) + (TI));
        Tj = ((T4) - ((KP500000000) * (T7)));
        Tn = Tj - Tm;
        Tv = Tj + Tm;
        To = ((T9) - ((KP500000000) * (Tc)));
        Ts = To - Tr;
        Tw = To + Tr;
        T8 = T4 + T7;
        Td = T9 + Tc;
        Te = T8 + Td;
    }
    R0[0] = (((KP2_000000000) * (Te)) + (T3));
    {
        E T11, T13, TY, T12, TW, TX;
        T11 = ((KP1_175570504 * TZ) - ((KP1_902113032) * (T10)));
        T13 = (((KP1_902113032) * (TZ)) + (KP1_175570504 * T10));
        TW = ((T3) - ((KP500000000) * (Te)));
        TX = KP1_118033988 * (T8 - Td);
        TY = TW - TX;
        T12 = TX + TW;
        R0[(rs[6])] = TY - T11;
        R1[(rs[4])] = T12 + T13;
        R1[(rs[1])] = TY + T11;
        R0[(rs[3])] = T12 - T13;
    }
    {
        E TP, Tt, TO, TT, TV, TR, TS, TU, TQ;
        TP = KP1_118033988 * (Tn - Ts);
        Tt = Tn + Ts;
        TO = ((Ti) - ((KP500000000) * (Tt)));
        TR = TE - TB;
        TS = TJ - TG;
        TT = ((KP1_175570504 * TR) - ((KP1_902113032) * (TS)));
        TV = (((KP1_902113032) * (TR)) + (KP1_175570504 * TS));
        R1[(rs[2])] = (((KP2_000000000) * (Tt)) + (Ti));
        TU = TP + TO;
        R1[(rs[5])] = TU - TV;
        R0[(rs[7])] = TU + TV;
        TQ = TO - TP;
        R0[(rs[1])] = TQ - TT;
        R0[(rs[4])] = TQ + TT;
    }
    {
        E Tz, Tx, Ty, TL, TN, TF, TK, TM, TA;
        Tz = KP1_118033988 * (Tv - Tw);
        Tx = Tv + Tw;
        Ty = ((Tu) - ((KP500000000) * (Tx)));
        TF = TB + TE;
        TK = TG + TJ;
        TL = ((KP1_175570504 * TF) - ((KP1_902113032) * (TK)));
        TN = (((KP1_902113032) * (TF)) + (KP1_175570504 * TK));
        R0[(rs[5])] = (((KP2_000000000) * (Tx)) + (Tu));
        TM = Tz + Ty;
        R1[0] = TM - TN;
        R0[(rs[2])] = TM + TN;
        TA = Ty - Tz;
        R1[(rs[3])] = TA - TL;
        R1[(rs[6])] = TA + TL;
    }
}

}
