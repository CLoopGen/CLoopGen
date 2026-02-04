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
for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E Ti, TR, TL, TD, TE, T7, Te, Tf, TV, TW, TX, Tv, Ty, TH, To;
    E Tr, TG, TS, TT, TU;
    INT idx_r[8], idx_csr[8], idx_csi[8];
    for (INT j = 0; j < 8; ++j) {
        idx_r[j] = rs[j];
        idx_csr[j] = csr[j];
        idx_csi[j] = csi[j];
    }
    {
        E TJ, Tg, Th, TK;
        TJ = R0[0];
        Tg = R0[idx_r[5]];
        Th = R1[idx_r[2]];
        TK = Th + Tg;
        Ti = Tg - Th;
        TR = TJ + TK;
        TL = ((TJ) - ((KP500000000) * (TK)));
    }
    {
        E Tm, Tt, Tw, Tp, T3, Tx, Ta, Tn, Td, Tq, T6, Tu;
        Tm = R1[idx_r[1]];
        Tt = R0[idx_r[3]];
        Tw = R1[idx_r[4]];
        Tp = R0[idx_r[6]];
        {
            E T1, T2, T8, T9;
            T1 = R0[idx_r[7]];
            T2 = R0[idx_r[2]];
            T3 = T1 - T2;
            Tx = T1 + T2;
            T8 = R1[idx_r[6]];
            T9 = R0[idx_r[4]];
            Ta = T8 - T9;
            Tn = T9 + T8;
        }
        {
            E Tb, Tc, T4, T5;
            Tb = R1[idx_r[3]];
            Tc = R0[idx_r[1]];
            Td = Tb - Tc;
            Tq = Tc + Tb;
            T4 = R1[0];
            T5 = R1[idx_r[5]];
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
    Ci[idx_csi[5]] = KP866025403 * (Tf - Ti);
    {
        E TF, TP, TI, TM, TN, TQ, TO;
        TF = (((KP823639103) * (TD)) + (KP509036960 * TE));
        TP = ((KP823639103 * TE) - ((KP509036960) * (TD)));
        TI = KP559016994 * (TG - TH);
        TM = TG + TH;
        TN = ((TL) - ((KP250000000) * (TM)));
        Cr[idx_csr[5]] = TL + TM;
        TQ = TN - TI;
        Cr[idx_csr[2]] = TP + TQ;
        Cr[idx_csr[7]] = TQ - TP;
        TO = TI + TN;
        Cr[idx_csr[1]] = TF + TO;
        Cr[idx_csr[4]] = TO - TF;
    }
    {
        E T11, T12, T10, TY, TZ;
        T11 = TS - TT;
        T12 = TW - TV;
        Ci[idx_csi[3]] = (((KP587785252) * (T11)) + (KP951056516 * T12));
        Ci[idx_csi[6]] = ((KP587785252 * T12) - ((KP951056516) * (T11)));
        T10 = KP559016994 * (TU - TX);
        TY = TU + TX;
        TZ = ((TR) - ((KP250000000) * (TY)));
        Cr[idx_csr[3]] = TZ - T10;
        Cr[0] = TR + TY;
        Cr[idx_csr[6]] = T10 + TZ;
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
            Ci[idx_csi[1]] = Tl - TA;
            Ci[idx_csi[7]] = TC - TB;
            Ci[idx_csi[4]] = Tl + TA;
            Ci[idx_csi[2]] = TB + TC;
        }
    }
}
}
