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
for (i = v; i > 0; i = i - 2 , R0 = R0 + 2*ivs , R1 = R1 + 2*ivs , Cr = Cr + 2*ovs , Ci = Ci + 2*ovs , (rs) = (rs) + 2*fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + 2*fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    if (i < 1) break;

    E TE, TR, T2i, T1z, TL, TS, TB, T2d, T1l, T1i, T2c, T9, T23, TZ, TW;
    E T22, Ti, T26, T16, T13, T25, Ts, T2a, T1e, T1b, T29, TP, TQ;
    E TE2, TR2, T2i2, T1z2, TL2, TS2, TB2, T2d2, T1l2, T1i2, T2c2, T92, T232, TZ2, TW2;
    E T222, Ti2, T262, T162, T132, T252, Ts2, T2a2, T1e2, T1b2, T292, TP2, TQ2;

    // First iteration (original offset)
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

    // Second iteration (offset by 1 step in data streams)
    {
        E TK2, T1y2, TH2, T1x2;
        TE2 = R0[ivs];
        {
            E TI2, TJ2, TF2, TG2;
            TI2 = R0[(rs[10]) + ivs];
            TJ2 = R1[(rs[2]) + ivs];
            TK2 = TI2 - TJ2;
            T1y2 = TI2 + TJ2;
            TF2 = R0[(rs[5]) + ivs];
            TG2 = R1[(rs[7]) + ivs];
            TH2 = TF2 - TG2;
            T1x2 = TF2 + TG2;
        }
        TR2 = KP559016994 * (TH2 - TK2);
        T2i2 = ((KP951056516 * T1y2) - ((KP587785252) * (T1x2)));
        T1z2 = (((KP951056516) * (T1x2)) + (KP587785252 * T1y2));
        TL2 = TH2 + TK2;
        TS2 = ((TE2) - ((KP250000000) * (TL2)));
    }
    {
        E Tt2, Tw2, Tz2, TA2, T1k2, T1j2, T1g2, T1h2;
        Tt2 = R0[(rs[3]) + ivs];
        {
            E Tu2, Tv2, Tx2, Ty2;
            Tu2 = R0[(rs[8]) + ivs];
            Tv2 = R1[(rs[10]) + ivs];
            Tw2 = Tu2 - Tv2;
            Tx2 = R1[ivs];
            Ty2 = R1[(rs[5]) + ivs];
            Tz2 = Tx2 + Ty2;
            TA2 = Tw2 - Tz2;
            T1k2 = Ty2 - Tx2;
            T1j2 = Tu2 + Tv2;
        }
        TB2 = Tt2 + TA2;
        T2d2 = ((KP475528258 * T1k2) - ((KP293892626) * (T1j2)));
        T1l2 = (((KP475528258) * (T1j2)) + (KP293892626 * T1k2));
        T1g2 = ((Tt2) - ((KP250000000) * (TA2)));
        T1h2 = KP559016994 * (Tw2 + Tz2);
        T1i2 = T1g2 + T1h2;
        T2c2 = T1g2 - T1h2;
    }
    {
        E T12, T42, T72, T82, TY2, TX2, TU2, TV2;
        T12 = R0[(rs[1]) + ivs];
        {
            E T22_val, T32, T52, T62;
            T22_val = R0[(rs[6]) + ivs];
            T32 = R1[(rs[8]) + ivs];
            T42 = T22_val - T32;
            T52 = R0[(rs[11]) + ivs];
            T62 = R1[(rs[3]) + ivs];
            T72 = T52 - T62;
            T82 = T42 + T72;
            TY2 = T52 + T62;
            TX2 = T22_val + T32;
        }
        T92 = T12 + T82;
        T232 = ((KP475528258 * TY2) - ((KP293892626) * (TX2)));
        TZ2 = (((KP475528258) * (TX2)) + (KP293892626 * TY2));
        TU2 = KP559016994 * (T42 - T72);
        TV2 = ((T12) - ((KP250000000) * (T82)));
        TW2 = TU2 + TV2;
        T222 = TV2 - TU2;
    }
    {
        E Ta2, Td2, Tg2, Th2, T152, T142, T112, T122;
        Ta2 = R0[(rs[4]) + ivs];
        {
            E Tb2, Tc2, Te2, Tf2;
            Tb2 = R0[(rs[9]) + ivs];
            Tc2 = R1[(rs[11]) + ivs];
            Td2 = Tb2 - Tc2;
            Te2 = R1[(rs[1]) + ivs];
            Tf2 = R1[(rs[6]) + ivs];
            Tg2 = Te2 + Tf2;
            Th2 = Td2 - Tg2;
            T152 = Tf2 - Te2;
            T142 = Tb2 + Tc2;
        }
        Ti2 = Ta2 + Th2;
        T262 = ((KP475528258 * T152) - ((KP293892626) * (T142)));
        T162 = (((KP475528258) * (T142)) + (KP293892626 * T152));
        T112 = ((Ta2) - ((KP250000000) * (Th2)));
        T122 = KP559016994 * (Td2 + Tg2);
        T132 = T112 + T122;
        T252 = T112 - T122;
    }
    {
        E Tk2, Tn2, Tq2, Tr2, T1d2, T1c2, T192, T1a2;
        Tk2 = R0[(rs[2]) + ivs];
        {
            E Tl2, Tm2, To2, Tp2;
            Tl2 = R0[(rs[7]) + ivs];
            Tm2 = R1[(rs[9]) + ivs];
            Tn2 = Tl2 - Tm2;
            To2 = R0[(rs[12]) + ivs];
            Tp2 = R1[(rs[4]) + ivs];
            Tq2 = To2 - Tp2;
            Tr2 = Tn2 + Tq2;
            T1d2 = To2 + Tp2;
            T1c2 = Tl2 + Tm2;
        }
        Ts2 = Tk2 + Tr2;
        T2a2 = ((KP475528258 * T1d2) - ((KP293892626) * (T1c2)));
        T1e2 = (((KP475528258) * (T1c2)) + (KP293892626 * T1d2));
        T192 = KP559016994 * (Tn2 - Tq2);
        T1a2 = ((Tk2) - ((KP250000000) * (Tr2)));
        T1b2 = T192 + T1a2;
        T292 = T1a2 - T192;
    }
    TP2 = TB2 - Ts2;
    TQ2 = T92 - Ti2;
    Ci[(csi[2]) + ovs] = ((KP587785252 * TP2) - ((KP951056516) * (TQ2)));
    Ci[(csi[7]) + ovs] = (((KP587785252) * (TQ2)) + (KP951056516 * TP2));
    {
        E TM2, TD2, TN2, Tj2, TC2, TO2;
        TM2 = TE2 + TL2;
        Tj2 = T92 + Ti2;
        TC2 = Ts2 + TB2;
        TD2 = KP559016994 * (Tj2 - TC2);
        TN2 = Tj2 + TC2;
        Cr[(csr[12]) + ovs] = TM2 + TN2;
        TO2 = ((TM2) - ((KP250000000) * (TN2)));
        Cr[(csr[2]) + ovs] = TD2 + TO2;
        Cr[(csr[7]) + ovs] = TO2 - TD2;
    }
}
}
