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
extern  E KP1_007074065;
extern  E KP227708958;
extern  E KP531932498;
extern  E KP774781170;
extern  E KP265966249;
extern  E KP516520780;
extern  E KP151805972;
extern  E KP503537032;
extern  E KP166666666;
extern  E KP600925212;
extern  E KP500000000;
extern  E KP256247671;
extern  E KP156891391;
extern  E KP348277202;
extern  E KP1_150281458;
extern  E KP300238635;
extern  E KP011599105;
extern  E KP1_732050807;
extern  E KP2_000000000;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 += ovs , R1 += ovs , Cr += ivs , Ci += ivs) {
    E TG, TS, TR, T15, TJ, TT, T1, Tm, Tc, Td, Tg, Tj, Tk, Tn, To;
    E Tp;
    {
        E Ts, Tv, Tw, TE, TC, TB, Tz, TD, TA, TF;
        {
            E Tt, Tu, Tx, Ty;
            Ts = Ci[csi[1]];
            Tt = Ci[csi[3]];
            Tu = Ci[csi[4]];
            Tv = Tt - Tu;
            Tw = (((KP2_000000000) * (Ts)) - (Tv));
            TE = KP1_732050807 * (Tt + Tu);
            TC = Ci[csi[5]];
            Tx = Ci[csi[6]];
            Ty = Ci[csi[2]];
            TB = Tx - Ty;
            Tz = KP1_732050807 * (Tx + Ty);
            TD = ((KP2_000000000) * (TC)) - (TB);
        }
        TA = Tw - Tz;
        TF = TD + TE;
        TG = (((KP011599105) * (TA)) + (KP300238635 * TF));
        TS = ((KP300238635 * TA) - ((KP011599105) * (TF)));
        {
            E TP, TQ, TH, TI;
            TP = Ts - Tv;
            TQ = TB - TC;
            TR = ((KP1_150281458 * TP) - ((KP348277202) * (TQ)));
            T15 = (((KP348277202) * (TP)) + (KP1_150281458 * TQ));
            TH = Tw + Tz;
            TI = TE - TD;
            TJ = (((KP156891391) * (TH)) + (KP256247671 * TI));
            TT = ((KP156891391 * TI) - ((KP256247671) * (TH)));
        }
    }
    {
        E Tb, Ti, Tf, T6, Th, Te;
        T1 = Cr[0];
        {
            E T7, T8, T9, Ta;
            T7 = Cr[csr[5]];
            T8 = Cr[csr[2]];
            T9 = Cr[csr[6]];
            Ta = T8 - T9;
            Tb = T7 - Ta;
            Ti = ((T7) - ((KP500000000) * (Ta)));
            Tf = T8 + T9;
        }
        {
            E T2, T3, T4, T5;
            T2 = Cr[csr[1]];
            T3 = Cr[csr[3]];
            T4 = Cr[csr[4]];
            T5 = T3 - T4;
            T6 = T2 - T5;
            Th = ((T2) - ((KP500000000) * (T5)));
            Te = T3 + T4;
        }
        Tm = KP600925212 * (T6 + Tb);
        Tc = T6 - Tb;
        Td = ((T1) - ((KP166666666) * (Tc)));
        Tg = Te - Tf;
        Tj = Th - Ti;
        Tk = (((KP503537032) * (Tg)) + (KP151805972 * Tj));
        Tn = Th + Ti;
        To = Te + Tf;
        Tp = ((KP516520780 * Tn) - ((KP265966249) * (To)));
    }
    R0[0] = (((KP2_000000000) * (Tc)) + (T1));
    {
        E TK, T1b, TV, T12, T16, T18, TO, T1a, Tr, T17, T11, T13;
        {
            E TU, T14, TM, TN;
            TK = KP1_732050807 * (TG - TJ);
            T1b = KP1_732050807 * (TS + TT);
            TU = TS - TT;
            TV = TR + TU;
            T12 = (((KP2_000000000) * (TU)) - (TR));
            T14 = TG + TJ;
            T16 = (((KP2_000000000) * (T14)) + (T15));
            T18 = T14 - T15;
            TM = (((KP774781170) * (To)) + (KP531932498 * Tn));
            TN = ((KP227708958 * Tg) - ((KP1_007074065) * (Tj)));
            TO = TM + TN;
            T1a = TM - TN;
            {
                E Tl, Tq, TZ, T10;
                Tl = Td + Tk;
                Tq = Tm + Tp;
                Tr = Tl + Tq;
                T17 = Tq - Tl;
                TZ = (((KP2_000000000) * (Tk)) - (Td));
                T10 = (((KP2_000000000) * (Tp)) - (Tm));
                T11 = TZ + T10;
                T13 = T10 - TZ;
            }
        }
        R1[rs[2]] = T11 + T12;
        R0[rs[6]] = T13 + T16;
        R1[0] = T13 - T16;
        R0[rs[4]] = T11 - T12;
        {
            E TL, TW, T19, T1c;
            TL = Tr + TK;
            TW = TO + TV;
            R1[rs[3]] = TL + TW;
            R0[rs[1]] = TL - TW;
            T19 = T17 + T18;
            T1c = T1a - T1b;
            R1[rs[1]] = T19 + T1c;
            R1[rs[4]] = T1c - T19;
        }
        {
            E T1d, T1e, TX, TY;
            T1d = T1a + T1b;
            T1e = T17 - T18;
            R0[rs[2]] = T1d - T1e;
            R0[rs[5]] = T1e + T1d;
            TX = Tr - TK;
            TY = TO - TV;
            R0[rs[3]] = TX + TY;
            R1[rs[5]] = TX - TY;
        }
    }
}
}
