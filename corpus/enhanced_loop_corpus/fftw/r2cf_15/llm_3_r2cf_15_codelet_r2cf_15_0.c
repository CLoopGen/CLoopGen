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
    const INT * restrict r_ptr = rs;
    const INT * restrict csr_ptr = csr;
    const INT * restrict csi_ptr = csi;
    E * restrict cr_base = Cr;
    E * restrict ci_base = Ci;
    E * restrict r0_base = R0;
    E * restrict r1_base = R1;
    {
        E TJ, Tg, Th, TK;
        TJ = r0_base[0];
        Tg = r0_base[r_ptr[5]];
        Th = r1_base[r_ptr[2]];
        TK = Th + Tg;
        Ti = Tg - Th;
        TR = TJ + TK;
        TL = ((TJ) - ((KP500000000) * (TK)));
    }
    {
        E Tm, Tt, Tw, Tp, T3, Tx, Ta, Tn, Td, Tq, T6, Tu;
        Tm = r1_base[r_ptr[1]];
        Tt = r0_base[r_ptr[3]];
        Tw = r1_base[r_ptr[4]];
        Tp = r0_base[r_ptr[6]];
        {
            E T1, T2, T8, T9;
            T1 = r0_base[r_ptr[7]];
            T2 = r0_base[r_ptr[2]];
            T3 = T1 - T2;
            Tx = T1 + T2;
            T8 = r1_base[r_ptr[6]];
            T9 = r0_base[r_ptr[4]];
            Ta = T8 - T9;
            Tn = T9 + T8;
        }
        {
            E Tb, Tc, T4, T5;
            Tb = r1_base[r_ptr[3]];
            Tc = r0_base[r_ptr[1]];
            Td = Tb - Tc;
            Tq = Tc + Tb;
            T4 = r1_base[0];
            T5 = r1_base[r_ptr[5]];
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
    ci_base[csi_ptr[5]] = KP866025403 * (Tf - Ti);
    {
        E TF, TP, TI, TM, TN, TQ, TO;
        TF = (((KP823639103) * (TD)) + (KP509036960 * TE));
        TP = ((KP823639103 * TE) - ((KP509036960) * (TD)));
        TI = KP559016994 * (TG - TH);
        TM = TG + TH;
        TN = ((TL) - ((KP250000000) * (TM)));
        cr_base[csr_ptr[5]] = TL + TM;
        TQ = TN - TI;
        cr_base[csr_ptr[2]] = TP + TQ;
        cr_base[csr_ptr[7]] = TQ - TP;
        TO = TI + TN;
        cr_base[csr_ptr[1]] = TF + TO;
        cr_base[csr_ptr[4]] = TO - TF;
    }
    {
        E T11, T12, T10, TY, TZ;
        T11 = TS - TT;
        T12 = TW - TV;
        ci_base[csi_ptr[3]] = (((KP587785252) * (T11)) + (KP951056516 * T12));
        ci_base[csi_ptr[6]] = ((KP587785252 * T12) - ((KP951056516) * (T11)));
        T10 = KP559016994 * (TU - TX);
        TY = TU + TX;
        TZ = ((TR) - ((KP250000000) * (TY)));
        cr_base[csr_ptr[3]] = TZ - T10;
        cr_base[0] = TR + TY;
        cr_base[csr_ptr[6]] = T10 + TZ;
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
            ci_base[csi_ptr[1]] = Tl - TA;
            ci_base[csi_ptr[7]] = TC - TB;
            ci_base[csi_ptr[4]] = Tl + TA;
            ci_base[csi_ptr[2]] = TB + TC;
        }
    }
}
}
