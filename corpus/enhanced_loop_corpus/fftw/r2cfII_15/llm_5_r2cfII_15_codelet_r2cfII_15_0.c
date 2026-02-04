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

    int skip_first = (i % 3 == 0);
    int skip_second = (i % 5 == 0);

    if (!skip_first) {
        T1 = R0[(rs[5])];
        T2 = R0[(rs[2])];
        E T3 = R1[0];
        E T4 = R1[(rs[3])];
        E T5 = R1[(rs[6])];
        E Tv = T2 + T3;
        E Tw = T4 - T5;
        Tx = (((KP951056516) * (Tv)) + (KP587785252 * Tw));
        TR = ((KP951056516 * Tw) - ((KP587785252) * (Tv)));
        TE = KP559016994 * (T3 - (T4 + T5));
        T7 = T3 + T4 + T5;
        TD = KP250000000 * T7;
    }

    if (!skip_second) {
        Th = R0[0];
        E Ti = R1[(rs[4])];
        E Tj = R1[(rs[1])];
        E Tk = R0[(rs[3])];
        E Tl = R0[(rs[6])];
        E Tp = Ti + Tj;
        E Tq = Tk + Tl;
        Tm = Tp - Tq;
        Tr = (((KP951056516) * (Tp)) + (KP587785252 * Tq));
        TQ = ((KP587785252 * Tp) - ((KP951056516) * (Tq)));
        TA = (((KP250000000) * (Tm)) + (Th));
        TB = KP559016994 * (Tl + Ti - Tq);
    }

    Tf = R1[(rs[2])];
    E T9 = R0[(rs[7])];
    E Ta = R0[(rs[1])];
    E Tb = R0[(rs[4])];
    E Tc = Ta + Tb;
    E Ts = Ta - Tb;
    Te = R1[(rs[5])];
    E Tt = T9 + Te;
    Tu = ((KP587785252 * Ts) - ((KP951056516) * (Tt)));
    TS = (((KP951056516) * (Ts)) + (KP587785252 * Tt));
    Td = T9 + Tc;
    E TG = KP559016994 * (T9 - Tc);
    TH = ((TG) - ((KP309016994) * (Te))) + (-(((KP250000000) * (Td)) + (Tf)));
    TO = (((KP809016994) * (Te)) - (Tf)) + (-(((KP250000000) * (Td)) + (TG)));

    if (skip_first || skip_second) {
        continue;
    }

    E Tn = Th - Tm;
    E T8 = T1 + T2 - T7;
    E Tg = Td - Te - Tf;
    E To = T8 + Tg;
    Ci[(csi[2])] = KP866025403 * (T8 - Tg);
    Cr[(csr[2])] = ((Tn) - ((KP500000000) * (To)));
    Cr[(csr[7])] = Tn + To;

    E TM = TB + TA;
    E TX = KP866025403 * (TR + TS);
    E TT = TR - TS;
    E TV = (((KP500000000) * (TT)) - (TQ));
    E TN = T1 + TE + ((TD) - ((KP809016994) * (T2)));
    E TP = TN + TO;
    E TU = KP866025403 * (TO - TN);
    Cr[(csr[1])] = TM + TP;
    Ci[(csi[1])] = TQ + TT;
    Ci[(csi[6])] = TU - TV;
    Ci[(csi[3])] = TU + TV;
    E TW = ((TM) - ((KP500000000) * (TP)));
    Cr[(csr[3])] = TW - TX;
    Cr[(csr[6])] = TW + TX;

    E Tz = KP866025403 * (Tx + Tu);
    E TC = TA - TB;
    E Ty = Tu - Tx;
    E TK = (((KP500000000) * (Ty)) - (Tr));
    E TF = (((KP309016994) * (T2)) + (T1)) + TD - TE;
    E TI = TF + TH;
    E TL = KP866025403 * (TH - TF);
    Ci[(csi[4])] = Tr + Ty;
    Cr[(csr[4])] = TC + TI;
    Ci[(csi[5])] = TK - TL;
    Ci[0] = TK + TL;
    E TJ = ((TC) - ((KP500000000) * (TI)));
    Cr[0] = Tz + TJ;
    Cr[(csr[5])] = TJ - Tz;
}
}
