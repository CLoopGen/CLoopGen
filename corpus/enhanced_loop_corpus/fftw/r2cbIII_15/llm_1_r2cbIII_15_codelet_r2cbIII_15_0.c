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
extern  E KP1_732050807;
extern  E KP433012701;
extern  E KP968245836;
extern  E KP587785252;
extern  E KP951056516;
extern  E KP250000000;
extern  E KP1_647278207;
extern  E KP1_018073920;
extern  E KP559016994;
extern  E KP500000000;
extern  E KP2_000000000;
extern  E KP1_118033988;
extern  E KP1_175570504;
extern  E KP1_902113032;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ovs , R1 = R1 + ovs , Cr = Cr + ivs , Ci = Ci + ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    for (INT unroll_factor = 0; unroll_factor < 1; ++unroll_factor) {
        E Tv, TD, T5, Ts, TC, T6, Tf, TW, TK, Td, Tg, TP, To, TN, TA;
        E TO, TQ, Tt, Tu, T12, Te, T11;
        Tt = Ci[(csi[4])];
        Tu = Ci[(csi[1])];
        Tv = (((KP1_902113032) * (Tt)) + (KP1_175570504 * Tu));
        TD = ((KP1_902113032 * Tu) - ((KP1_175570504) * (Tt)));
        {
            E T1, T4, Tq, T2, T3, Tr;
            T1 = Cr[(csr[7])];
            T2 = Cr[(csr[4])];
            T3 = Cr[(csr[1])];
            T4 = T2 + T3;
            Tq = KP1_118033988 * (T2 - T3);
            T5 = (((KP2_000000000) * (T4)) + (T1));
            Tr = ((T1) - ((KP500000000) * (T4)));
            Ts = Tq + Tr;
            TC = Tr - Tq;
        }
        {
            E Tc, TJ, T9, TI;
            T6 = Cr[(csr[2])];
            {
                E Ta, Tb, T7, T8;
                Ta = Cr[(csr[3])];
                Tb = Cr[(csr[6])];
                Tc = Ta + Tb;
                TJ = Ta - Tb;
                T7 = Cr[0];
                T8 = Cr[(csr[5])];
                T9 = T7 + T8;
                TI = T7 - T8;
            }
            Tf = KP559016994 * (T9 - Tc);
            TW = ((KP1_018073920 * TI) - ((KP1_647278207) * (TJ)));
            TK = (((KP1_647278207) * (TI)) + (KP1_018073920 * TJ));
            Td = T9 + Tc;
            Tg = ((T6) - ((KP250000000) * (Td)));
        }
        {
            E Tn, TM, Tk, TL;
            TP = Ci[(csi[2])];
            {
                E Tl, Tm, Ti, Tj;
                Tl = Ci[(csi[3])];
                Tm = Ci[(csi[6])];
                Tn = Tl - Tm;
                TM = Tl + Tm;
                Ti = Ci[0];
                Tj = Ci[(csi[5])];
                Tk = Ti + Tj;
                TL = Ti - Tj;
            }
            To = (((KP951056516) * (Tk)) + (KP587785252 * Tn));
            TN = KP968245836 * (TL - TM);
            TA = ((KP951056516 * Tn) - ((KP587785252) * (Tk)));
            TO = TL + TM;
            TQ = (((KP433012701) * (TO)) + (KP1_732050807 * TP));
        }
        T12 = KP1_732050807 * (TP - TO);
        Te = T6 + Td;
        T11 = Te - T5;
        R0[0] = (((KP2_000000000) * (Te)) + (T5));
        R0[(rs[5])] = T12 - T11;
        R1[(rs[2])] = T11 + T12;
        {
            E TE, TG, TB, TF, TY, T10, Tz, TX, TV, TZ;
            TE = TC - TD;
            TG = TC + TD;
            Tz = Tg - Tf;
            TB = Tz + TA;
            TF = TA - Tz;
            TX = TN + TQ;
            TY = TW - TX;
            T10 = TW + TX;
            R0[(rs[6])] = (((KP2_000000000) * (TB)) + (TE));
            R1[(rs[1])] = (((KP2_000000000) * (TF)) - (TG));
            TV = TE - TB;
            R0[(rs[1])] = TV + TY;
            R1[(rs[3])] = TY - TV;
            TZ = TF + TG;
            R0[(rs[4])] = TZ - T10;
            R1[(rs[6])] = -(TZ + T10);
        }
        {
            E Tw, Ty, Tp, Tx, TS, TU, Th, TR, TH, TT;
            Tw = Ts - Tv;
            Ty = Ts + Tv;
            Th = Tf + Tg;
            Tp = Th + To;
            Tx = Th - To;
            TR = TN - TQ;
            TS = TK + TR;
            TU = TR - TK;
            R1[(rs[4])] = -((((KP2_000000000) * (Tp)) + (Tw)));
            R0[(rs[3])] = (((KP2_000000000) * (Tx)) + (Ty));
            TH = Tx - Ty;
            R1[(rs[5])] = TH - TS;
            R1[0] = TH + TS;
            TT = Tw - Tp;
            R0[(rs[2])] = TT - TU;
            R0[(rs[7])] = TT + TU;
        }
    }
}
}
