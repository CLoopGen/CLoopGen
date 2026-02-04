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
extern  E KP1_996053456;
extern  E KP062790519;
extern  E KP125581039;
extern  E KP998026728;
extern  E KP1_369094211;
extern  E KP728968627;
extern  E KP963507348;
extern  E KP876306680;
extern  E KP497379774;
extern  E KP968583161;
extern  E KP1_457937254;
extern  E KP684547105;
extern  E KP1_752613360;
extern  E KP481753674;
extern  E KP1_937166322;
extern  E KP248689887;
extern  E KP992114701;
extern  E KP250666467;
extern  E KP1_809654104;
extern  E KP425779291;
extern  E KP1_541026485;
extern  E KP637423989;
extern  E KP1_688655851;
extern  E KP535826794;
extern  E KP851558583;
extern  E KP904827052;
extern  E KP1_984229402;
extern  E KP125333233;
extern  E KP1_274847979;
extern  E KP770513242;
extern  E KP844327925;
extern  E KP1_071653589;
extern  E KP293892626;
extern  E KP475528258;
extern  E KP250000000;
extern  E KP587785252;
extern  E KP951056516;
extern  E KP559016994;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E TE, TR, T2i, T1z, TL, TS, TB, T2d, T1l, T1i, T2c, T9, T23, TZ, TW;
    E T22, Ti, T26, T16, T13, T25, Ts, T2a, T1e, T1b, T29, TP, TQ;
    {
        E TK, T1y, TH, T1x;
        TE = R0[0];
        {
            E TI, TJ, TF, TG;
            TI = R0[(rs[10])];
            TJ = R1[(rs[2])];
            TK = TI - TJ;
            T1y = TI + TJ;
            TF = R0[(rs[5])];
            TG = R1[(rs[7])];
            TH = TF - TG;
            T1x = TF + TG;
        }
        TR = KP559016994 * (TH - TK);
        T2i = ((KP951056516 * T1y) - ((KP587785252) * (T1x)));
        T1z = (((KP951056516) * (T1x)) + (KP587785252 * T1y));
        TL = TH + TK;
        TS = ((TE) - ((KP250000000) * (TL)));
    }
    {
        E Tt, Tw, Tz, TA, T1k, T1j, T1g, T1h;
        Tt = R0[(rs[3])];
        {
            E Tu, Tv, Tx, Ty;
            Tu = R0[(rs[8])];
            Tv = R1[(rs[10])];
            Tw = Tu - Tv;
            Tx = R1[0];
            Ty = R1[(rs[5])];
            Tz = Tx + Ty;
            TA = Tw - Tz;
            T1k = Ty - Tx;
            T1j = Tu + Tv;
        }
        TB = Tt + TA;
        T2d = ((KP475528258 * T1k) - ((KP293892626) * (T1j)));
        T1l = (((KP475528258) * (T1j)) + (KP293892626 * T1k));
        T1g = ((Tt) - ((KP250000000) * (TA)));
        T1h = KP559016994 * (Tw + Tz);
        T1i = T1g + T1h;
        T2c = T1g - T1h;
    }
    {
        E T1, T4, T7, T8, TY, TX, TU, TV;
        T1 = R0[(rs[1])];
        {
            E T2, T3, T5, T6;
            T2 = R0[(rs[6])];
            T3 = R1[(rs[8])];
            T4 = T2 - T3;
            T5 = R0[(rs[11])];
            T6 = R1[(rs[3])];
            T7 = T5 - T6;
            T8 = T4 + T7;
            TY = T5 + T6;
            TX = T2 + T3;
        }
        T9 = T1 + T8;
        T23 = ((KP475528258 * TY) - ((KP293892626) * (TX)));
        TZ = (((KP475528258) * (TX)) + (KP293892626 * TY));
        TU = KP559016994 * (T4 - T7);
        TV = ((T1) - ((KP250000000) * (T8)));
        TW = TU + TV;
        T22 = TV - TU;
    }
    {
        E Ta, Td, Tg, Th, T15, T14, T11, T12;
        Ta = R0[(rs[4])];
        {
            E Tb, Tc, Te, Tf;
            Tb = R0[(rs[9])];
            Tc = R1[(rs[11])];
            Td = Tb - Tc;
            Te = R1[(rs[1])];
            Tf = R1[(rs[6])];
            Tg = Te + Tf;
            Th = Td - Tg;
            T15 = Tf - Te;
            T14 = Tb + Tc;
        }
        Ti = Ta + Th;
        T26 = ((KP475528258 * T15) - ((KP293892626) * (T14)));
        T16 = (((KP475528258) * (T14)) + (KP293892626 * T15));
        T11 = ((Ta) - ((KP250000000) * (Th)));
        T12 = KP559016994 * (Td + Tg);
        T13 = T11 + T12;
        T25 = T11 - T12;
    }
    {
        E Tk, Tn, Tq, Tr, T1d, T1c, T19, T1a;
        Tk = R0[(rs[2])];
        {
            E Tl, Tm, To, Tp;
            Tl = R0[(rs[7])];
            Tm = R1[(rs[9])];
            Tn = Tl - Tm;
            To = R0[(rs[12])];
            Tp = R1[(rs[4])];
            Tq = To - Tp;
            Tr = Tn + Tq;
            T1d = To + Tp;
            T1c = Tl + Tm;
        }
        Ts = Tk + Tr;
        T2a = ((KP475528258 * T1d) - ((KP293892626) * (T1c)));
        T1e = (((KP475528258) * (T1c)) + (KP293892626 * T1d));
        T19 = KP559016994 * (Tn - Tq);
        T1a = ((Tk) - ((KP250000000) * (Tr)));
        T1b = T19 + T1a;
        T29 = T1a - T19;
    }
    TP = TB - Ts;
    TQ = T9 - Ti;
    Ci[(csi[2])] = ((KP587785252 * TP) - ((KP951056516) * (TQ)));
    Ci[(csi[7])] = (((KP587785252) * (TQ)) + (KP951056516 * TP));
    {
        E TM, TD, TN, Tj, TC, TO;
        TM = TE + TL;
        Tj = T9 + Ti;
        TC = Ts + TB;
        TD = KP559016994 * (Tj - TC);
        TN = Tj + TC;
        Cr[(csr[12])] = TM + TN;
        TO = ((TM) - ((KP250000000) * (TN)));
        Cr[(csr[2])] = TD + TO;
        Cr[(csr[7])] = TO - TD;
    }
}
}
