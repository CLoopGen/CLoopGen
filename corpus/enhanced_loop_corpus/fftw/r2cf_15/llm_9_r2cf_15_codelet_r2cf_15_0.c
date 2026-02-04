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
extern  E KP484122918;
extern  E KP216506350;
extern  E KP951056516;
extern  E KP587785252;
extern  E KP250000000;
extern  E KP559016994;
extern  E KP509036960;
extern  E KP823639103;
extern  E KP866025403;
extern  E KP500000000;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 2 , R0 = R0 + 2*ivs , R1 = R1 + 2*ivs , Cr = Cr + 2*ovs , Ci = Ci + 2*ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    if (i >= 1) {
        E Ti, TR, TL, TD, TE, T7, Te, Tf, TV, TW, TX, Tv, Ty, TH, To;
        E Tr, TG, TS, TT, TU;
        {
            E TJ, Tg, Th, TK;
            TJ = R0[0];
            Tg = R0[(rs[5])];
            Th = R1[(rs[2])];
            TK = Th + Tg;
            Ti = Tg - Th;
            TR = TJ + TK;
            TL = ((TJ) - ((KP500000000) * (TK)));
        }
        {
            E Tm, Tt, Tw, Tp, T3, Tx, Ta, Tn, Td, Tq, T6, Tu;
            Tm = R1[(rs[1])];
            Tt = R0[(rs[3])];
            Tw = R1[(rs[4])];
            Tp = R0[(rs[6])];
            {
                E T1, T2, T8, T9;
                T1 = R0[(rs[7])];
                T2 = R0[(rs[2])];
                T3 = T1 - T2;
                Tx = T1 + T2;
                T8 = R1[(rs[6])];
                T9 = R0[(rs[4])];
                Ta = T8 - T9;
                Tn = T9 + T8;
            }
            {
                E Tb, Tc, T4, T5;
                Tb = R1[(rs[3])];
                Tc = R0[(rs[1])];
                Td = Tb - Tc;
                Tq = Tc + Tb;
                T4 = R1[0];
                T5 = R1[(rs[5])];
                T6 = T4 - T5;
                Tu = T5 + T4;
            }
            TD = Ta - Td;
            TE = T6 + T3;
            T7 = T3 - T6;
            Te = Ta + Td;
            Tf = T7 - Te;
            TV = Tt + Tu;
            TW = Tw + Tx;
            TX = TV + TW;
            Tv = ((Tt) - ((KP500000000) * (Tu)));
            Ty = ((Tw) - ((KP500000000) * (Tx)));
            TH = Tv + Ty;
            To = ((Tm) - ((KP500000000) * (Tn)));
            Tr = ((Tp) - ((KP500000000) * (Tq)));
            TG = To + Tr;
            TS = Tm + Tn;
            TT = Tp + Tq;
            TU = TS + TT;
        }
        Ci[(csi[5])] = KP866025403 * (Tf - Ti);
        {
            E TF, TP, TI, TM, TN, TQ, TO;
            TF = (((KP823639103) * (TD)) + (KP509036960 * TE));
            TP = ((KP823639103 * TE) - ((KP509036960) * (TD)));
            TI = KP559016994 * (TG - TH);
            TM = TG + TH;
            TN = ((TL) - ((KP250000000) * (TM)));
            Cr[(csr[5])] = TL + TM;
            TQ = TN - TI;
            Cr[(csr[2])] = TP + TQ;
            Cr[(csr[7])] = TQ - TP;
            TO = TI + TN;
            Cr[(csr[1])] = TF + TO;
            Cr[(csr[4])] = TO - TF;
        }
        {
            E T11, T12, T10, TY, TZ;
            T11 = TS - TT;
            T12 = TW - TV;
            Ci[(csi[3])] = (((KP587785252) * (T11)) + (KP951056516 * T12));
            Ci[(csi[6])] = ((KP587785252 * T12) - ((KP951056516) * (T11)));
            T10 = KP559016994 * (TU - TX);
            TY = TU + TX;
            TZ = ((TR) - ((KP250000000) * (TY)));
            Cr[(csr[3])] = TZ - T10;
            Cr[0] = TR + TY;
            Cr[(csr[6])] = T10 + TZ;
            {
                E Tl, TB, TA, TC;
                {
                    E Tj, Tk, Ts, Tz;
                    Tj = (((KP866025403) * (Ti)) + (KP216506350 * Tf));
                    Tk = KP484122918 * (Te + T7);
                    Tl = Tj + Tk;
                    TB = Tk - Tj;
                    Ts = To - Tr;
                    Tz = Tv - Ty;
                    TA = (((KP951056516) * (Ts)) + (KP587785252 * Tz));
                    TC = ((KP951056516 * Tz) - ((KP587785252) * (Ts)));
                }
                Ci[(csi[1])] = Tl - TA;
                Ci[(csi[7])] = TC - TB;
                Ci[(csi[4])] = Tl + TA;
                Ci[(csi[2])] = TB + TC;
            }
        }
    }
    if (i >= 2) {
        E Ti2, TR2, TL2, TD2, TE2, T72, Te2, Tf2, TV2, TW2, TX2, Tv2, Ty2, TH2, To2;
        E Tr2, TG2, TS2, TT2, TU2;
        {
            E TJ2, Tg2, Th2, TK2;
            TJ2 = R0[ivs];
            Tg2 = R0[ivs + (rs[5])];
            Th2 = R1[ivs + (rs[2])];
            TK2 = Th2 + Tg2;
            Ti2 = Tg2 - Th2;
            TR2 = TJ2 + TK2;
            TL2 = ((TJ2) - ((KP500000000) * (TK2)));
        }
        {
            E Tm2, Tt2, Tw2, Tp2, T32, Tx2, Ta2, Tn2, Td2, Tq2, T62, Tu2;
            Tm2 = R1[ivs + (rs[1])];
            Tt2 = R0[ivs + (rs[3])];
            Tw2 = R1[ivs + (rs[4])];
            Tp2 = R0[ivs + (rs[6])];
            {
                E T12, T22, T82, T92;
                T12 = R0[ivs + (rs[7])];
                T22 = R0[ivs + (rs[2])];
                T32 = T12 - T22;
                Tx2 = T12 + T22;
                T82 = R1[ivs + (rs[6])];
                T92 = R0[ivs + (rs[4])];
                Ta2 = T82 - T92;
                Tn2 = T92 + T82;
            }
            {
                E Tb2, Tc2, T42, T52;
                Tb2 = R1[ivs + (rs[3])];
                Tc2 = R0[ivs + (rs[1])];
                Td2 = Tb2 - Tc2;
                Tq2 = Tc2 + Tb2;
                T42 = R1[ivs];
                T52 = R1[ivs + (rs[5])];
                T62 = T42 - T52;
                Tu2 = T52 + T42;
            }
            TD2 = Ta2 - Td2;
            TE2 = T62 + T32;
            T72 = T32 - T62;
            Te2 = Ta2 + Td2;
            Tf2 = T72 - Te2;
            TV2 = Tt2 + Tu2;
            TW2 = Tw2 + Tx2;
            TX2 = TV2 + TW2;
            Tv2 = ((Tt2) - ((KP500000000) * (Tu2)));
            Ty2 = ((Tw2) - ((KP500000000) * (Tx2)));
            TH2 = Tv2 + Ty2;
            To2 = ((Tm2) - ((KP500000000) * (Tn2)));
            Tr2 = ((Tp2) - ((KP500000000) * (Tq2)));
            TG2 = To2 + Tr2;
            TS2 = Tm2 + Tn2;
            TT2 = Tp2 + Tq2;
            TU2 = TS2 + TT2;
        }
        Ci[(csi[5]) + ovs] = KP866025403 * (Tf2 - Ti2);
        {
            E TF2, TP2, TI2, TM2, TN2, TQ2, TO2;
            TF2 = (((KP823639103) * (TD2)) + (KP509036960 * TE2));
            TP2 = ((KP823639103 * TE2) - ((KP509036960) * (TD2)));
            TI2 = KP559016994 * (TG2 - TH2);
            TM2 = TG2 + TH2;
            TN2 = ((TL2) - ((KP250000000) * (TM2)));
            Cr[(csr[5]) + ovs] = TL2 + TM2;
            TQ2 = TN2 - TI2;
            Cr[(csr[2]) + ovs] = TP2 + TQ2;
            Cr[(csr[7]) + ovs] = TQ2 - TP2;
            TO2 = TI2 + TN2;
            Cr[(csr[1]) + ovs] = TF2 + TO2;
            Cr[(csr[4]) + ovs] = TO2 - TF2;
        }
        {
            E T112, T122, T102, TY2, TZ2;
            T112 = TS2 - TT2;
            T122 = TW2 - TV2;
            Ci[(csi[3]) + ovs] = (((KP587785252) * (T112)) + (KP951056516 * T122));
            Ci[(csi[6]) + ovs] = ((KP587785252 * T122) - ((KP951056516) * (T112)));
            T102 = KP559016994 * (TU2 - TX2);
            TY2 = TU2 + TX2;
            TZ2 = ((TR2) - ((KP250000000) * (TY2)));
            Cr[(csr[3]) + ovs] = TZ2 - T102;
            Cr[ovs] = TR2 + TY2;
            Cr[(csr[6]) + ovs] = T102 + TZ2;
            {
                E Tl2, TB2, TA2, TC2;
                {
                    E Tj2, Tk2, Ts2, Tz2;
                    Tj2 = (((KP866025403) * (Ti2)) + (KP216506350 * Tf2));
                    Tk2 = KP484122918 * (Te2 + T72);
                    Tl2 = Tj2 + Tk2;
                    TB2 = Tk2 - Tj2;
                    Ts2 = To2 - Tr2;
                    Tz2 = Tv2 - Ty2;
                    TA2 = (((KP951056516) * (Ts2)) + (KP587785252 * Tz2));
                    TC2 = ((KP951056516 * Tz2) - ((KP587785252) * (Ts2)));
                }
                Ci[(csi[1]) + ovs] = Tl2 - TA2;
                Ci[(csi[7]) + ovs] = TC2 - TB2;
                Ci[(csi[4]) + ovs] = Tl2 + TA2;
                Ci[(csi[2]) + ovs] = TB2 + TC2;
            }
        }
    }
}
}
