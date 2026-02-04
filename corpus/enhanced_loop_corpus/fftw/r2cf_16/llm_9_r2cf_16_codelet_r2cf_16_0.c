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
extern  E KP923879532;
extern  E KP382683432;
extern  E KP707106781;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v / 4; i > 0; i = i - 1 , R0 = R0 + 4*ivs , R1 = R1 + 4*ovs , Cr = Cr + 4*ovs , Ci = Ci + 4*ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    INT j;
    for (j = 0; j < 4; ++j) {
        E T3, T6, T7, Tz, Ti, Ta, Td, Te, TA, Th, Tq, TV, TF, TP, Tx;
        E TU, TE, TM, Tg, Tf, TJ, TQ;
        INT idx_r0 = j * ivs;
        INT idx_r1 = j * ivs;
        INT idx_cr = j * ovs;
        INT idx_ci = j * ovs;

        {
            E T1, T2, T4, T5;
            T1 = R0[idx_r0 + 0];
            T2 = R0[idx_r0 + (rs[4])];
            T3 = T1 + T2;
            T4 = R0[idx_r0 + (rs[2])];
            T5 = R0[idx_r0 + (rs[6])];
            T6 = T4 + T5;
            T7 = T3 + T6;
            Tz = T1 - T2;
            Ti = T4 - T5;
        }
        {
            E T8, T9, Tb, Tc;
            T8 = R0[idx_r0 + (rs[1])];
            T9 = R0[idx_r0 + (rs[5])];
            Ta = T8 + T9;
            Tg = T8 - T9;
            Tb = R0[idx_r0 + (rs[7])];
            Tc = R0[idx_r0 + (rs[3])];
            Td = Tb + Tc;
            Tf = Tb - Tc;
        }
        Te = Ta + Td;
        TA = KP707106781 * (Tg + Tf);
        Th = KP707106781 * (Tf - Tg);
        {
            E Tm, TN, Tp, TO;
            {
                E Tk, Tl, Tn, To;
                Tk = R1[idx_r1 + (rs[7])];
                Tl = R1[idx_r1 + (rs[3])];
                Tm = Tk - Tl;
                TN = Tk + Tl;
                Tn = R1[idx_r1 + (rs[1])];
                To = R1[idx_r1 + (rs[5])];
                Tp = Tn - To;
                TO = Tn + To;
            }
            Tq = ((KP382683432 * Tm) - ((KP923879532) * (Tp)));
            TV = TN + TO;
            TF = (((KP923879532) * (Tm)) + (KP382683432 * Tp));
            TP = TN - TO;
        }
        {
            E Tt, TK, Tw, TL;
            {
                E Tr, Ts, Tu, Tv;
                Tr = R1[idx_r1 + 0];
                Ts = R1[idx_r1 + (rs[4])];
                Tt = Tr - Ts;
                TK = Tr + Ts;
                Tu = R1[idx_r1 + (rs[2])];
                Tv = R1[idx_r1 + (rs[6])];
                Tw = Tu - Tv;
                TL = Tu + Tv;
            }
            Tx = (((KP382683432) * (Tt)) + (KP923879532 * Tw));
            TU = TK + TL;
            TE = ((KP923879532 * Tt) - ((KP382683432) * (Tw)));
            TM = TK - TL;
        }
        Cr[(csr[4]) + idx_cr] = T7 - Te;
        Ci[(csi[4]) + idx_ci] = TV - TU;
        {
            E Tj, Ty, TD, TG;
            Tj = Th - Ti;
            Ty = Tq - Tx;
            Ci[(csi[1]) + idx_ci] = Tj + Ty;
            Ci[(csi[7]) + idx_ci] = Ty - Tj;
            TD = Tz + TA;
            TG = TE + TF;
            Cr[(csr[7]) + idx_cr] = TD - TG;
            Cr[(csr[1]) + idx_cr] = TD + TG;
        }
        {
            E TB, TC, TH, TI;
            TB = Tz - TA;
            TC = Tx + Tq;
            Cr[(csr[5]) + idx_cr] = TB - TC;
            Cr[(csr[3]) + idx_cr] = TB + TC;
            TH = Ti + Th;
            TI = TF - TE;
            Ci[(csi[3]) + idx_ci] = TH + TI;
            Ci[(csi[5]) + idx_ci] = TI - TH;
        }
        TJ = T3 - T6;
        TQ = KP707106781 * (TM + TP);
        Cr[(csr[6]) + idx_cr] = TJ - TQ;
        Cr[(csr[2]) + idx_cr] = TJ + TQ;
        {
            E TR, TS, TT, TW;
            TR = Td - Ta;
            TS = KP707106781 * (TP - TM);
            Ci[(csi[2]) + idx_ci] = TR + TS;
            Ci[(csi[6]) + idx_ci] = TS - TR;
            TT = T7 + Te;
            TW = TU + TV;
            Cr[(csr[8]) + idx_cr] = TT - TW;
            Cr[idx_cr] = TT + TW;
        }
    }
}
}
