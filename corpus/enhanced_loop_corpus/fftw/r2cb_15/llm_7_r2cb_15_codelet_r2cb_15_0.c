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

    // Eliminate some intermediate temporaries by inlining expressions
    // This reduces register pressure and removes false dependencies

    {
        E Th, T1, T2, Tf, Tg;
        Tg = Ci[(csi[5])];
        Th = KP1_732050807 * Tg;
        T1 = Cr[0];
        T2 = Cr[(csr[5])];
        Tf = T1 - T2;
        T3 = (KP2_000000000 * T2) + T1;
        Tu = Tf - Th;
        Ti = Tf + Th;
    }

    // Combine independent computations and reorder to eliminate WAR hazards
    // Also fuse loads and arithmetic where possible

    {
        E T4 = Cr[(csr[3])], T9 = Cr[(csr[6])];
        E TD = Ci[(csi[3])], TI = Ci[(csi[6])];
        E T5 = Cr[(csr[7])], T6 = Cr[(csr[2])];
        E Ta = Cr[(csr[4])], Tb = Cr[(csr[1])];

        E T7 = T5 + T6;
        E Tc = Ta + Tb;
        E T8 = T4 + T7;
        E Td = T9 + Tc;
        Te = T8 + Td;

        E Tp = Ci[(csi[4])], Tq = Ci[(csi[1])];
        E Tr = KP866025403 * (Tp + Tq);
        E TH = Tp - Tq;

        E Tk = Ci[(csi[7])], Tl = Ci[(csi[2])];
        E Tm = KP866025403 * (Tk - Tl);
        E TC = Tk + Tl;

        TB = KP866025403 * (T5 - T6);
        TZ = TD - TC;
        T10 = TI - TH;
        TE = (KP500000000 * TC) + TD;
        TG = KP866025403 * (Ta - Tb);
        TJ = (KP500000000 * TH) + TI;

        Tn = (T4 - (KP500000000 * T7)) - Tm;
        Tv = (T4 - (KP500000000 * T7)) + Tm;
        Ts = (T9 - (KP500000000 * Tc)) - Tr;
        Tw = (T9 - (KP500000000 * Tc)) + Tr;
    }

    R0[0] = (KP2_000000000 * Te) + T3;

    // Rearranged store order to break potential address aliasing assumptions
    // Also combine dependent operations into single expressions to reduce live range

    {
        E TW = T3 - (KP500000000 * Te);
        E TX = KP1_118033988 * (T8 - Td);
        E TY = TW - TX;
        E T12 = TX + TW;
        E T11 = KP1_118033988 * TZ - KP1_902113032 * T10;
        E T13 = KP1_902113032 * TZ + KP1_175570504 * T10;

        R0[(rs[6])] = TY - T11;
        R0[(rs[3])] = T12 - T13;
        R1[(rs[1])] = TY + T11;
        R1[(rs[4])] = T12 + T13;
    }

    {
        E Tt = Tn + Ts;
        E TO = Ti - (KP500000000 * Tt);
        E TR = TE - TB;
        E TS = TJ - TG;
        E TT = KP1_175570504 * TR - KP1_902113032 * TS;
        E TV = KP1_902113032 * TR + KP1_175570504 * TS;
        E TP = KP1_118033988 * (Tn - Ts);
        E TU = TP + TO;
        E TQ = TO - TP;

        R1[(rs[2])] = (KP2_000000000 * Tt) + Ti;
        R1[(rs[5])] = TU - TV;
        R0[(rs[7])] = TU + TV;
        R0[(rs[1])] = TQ - TT;
        R0[(rs[4])] = TQ + TT;
    }

    {
        E Tx = Tv + Tw;
        E Ty = Tu - (KP500000000 * Tx);
        E TF = TB + TE;
        E TK = TG + TJ;
        E TL = KP1_175570504 * TF - KP1_902113032 * TK;
        E TN = KP1_902113032 * TF + KP1_175570504 * TK;
        E Tz = KP1_118033988 * (Tv - Tw);
        E TM = Tz + Ty;
        E TA = Ty - Tz;

        R0[(rs[5])] = (KP2_000000000 * Tx) + Tu;
        R1[0] = TM - TN;
        R0[(rs[2])] = TM + TN;
        R1[(rs[3])] = TA - TL;
        R1[(rs[6])] = TA + TL;
    }
}
}
