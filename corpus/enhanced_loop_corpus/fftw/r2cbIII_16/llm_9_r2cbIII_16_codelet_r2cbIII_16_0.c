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
extern  E KP1_961570560;
extern  E KP390180644;
extern  E KP1_111140466;
extern  E KP1_662939224;
extern  E KP707106781;
extern  E KP1_414213562;
extern  E KP765366864;
extern  E KP1_847759065;
extern  E KP2_000000000;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v / 2; i > 0; i = i - 1 , R0 = R0 + 2*ovs , R1 = R1 + 2*ovs , Cr = Cr + 2*ivs , Ci = Ci + 2*ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T7a, TWa, T13a, Tja, TDa, TKa, TPa, THa, Tea, TXa, T12a, Toa, Tta, Txa, TSa;
    E Twa, TTx, TYx;
    E T7b, TWb, T13b, Tjb, TDb, TKb, TPb, THb, Teb, TXb, T12b, Tob, Ttb, Txb, TSb;
    E Twb, TTb, TYb;

    // First half computation
    {
        E T3, Tf, TC, TV, T6, Tz, Ti, TU;
        {
            E T1, T2, TA, TB;
            T1 = Cr[0];
            T2 = Cr[(csr[7])];
            T3 = T1 + T2;
            Tf = T1 - T2;
            TA = Ci[0];
            TB = Ci[(csi[7])];
            TC = TA + TB;
            TV = TB - TA;
        }
        {
            E T4, T5, Tg, Th;
            T4 = Cr[(csr[4])];
            T5 = Cr[(csr[3])];
            T6 = T4 + T5;
            Tz = T4 - T5;
            Tg = Ci[(csi[4])];
            Th = Ci[(csi[3])];
            Ti = Tg + Th;
            TU = Tg - Th;
        }
        T7a = T3 + T6;
        TWa = TU + TV;
        T13a = TV - TU;
        Tja = Tf - Ti;
        TDa = Tz + TC;
        TKa = Tz - TC;
        TPa = T3 - T6;
        THa = Tf + Ti;
    }
    {
        E Ta, Tk, Tn, TR, Td, Tp, Ts, TQ;
        {
            E T8, T9, Tl, Tm;
            T8 = Cr[(csr[2])];
            T9 = Cr[(csr[5])];
            Ta = T8 + T9;
            Tk = T8 - T9;
            Tl = Ci[(csi[2])];
            Tm = Ci[(csi[5])];
            Tn = Tl + Tm;
            TR = Tl - Tm;
        }
        {
            E Tb, Tc, Tq, Tr;
            Tb = Cr[(csr[1])];
            Tc = Cr[(csr[6])];
            Td = Tb + Tc;
            Tp = Tb - Tc;
            Tq = Ci[(csi[1])];
            Tr = Ci[(csi[6])];
            Ts = Tq + Tr;
            TQ = Tr - Tq;
        }
        Tea = Ta + Td;
        TXa = Ta - Td;
        T12a = TR + TQ;
        Toa = Tk - Tn;
        Tta = Tp - Ts;
        Txa = Tp + Ts;
        TSa = TQ - TR;
        Twa = Tk + Tn;
    }

    // Second half computation (offset by ivs)
    {
        E T3, Tf, TC, TV, T6, Tz, Ti, TU;
        {
            E T1, T2, TA, TB;
            T1 = Cr[ivs];
            T2 = Cr[ivs + (csr[7])];
            T3 = T1 + T2;
            Tf = T1 - T2;
            TA = Ci[ivs];
            TB = Ci[ivs + (csi[7])];
            TC = TA + TB;
            TV = TB - TA;
        }
        {
            E T4, T5, Tg, Th;
            T4 = Cr[ivs + (csr[4])];
            T5 = Cr[ivs + (csr[3])];
            T6 = T4 + T5;
            Tz = T4 - T5;
            Tg = Ci[ivs + (csi[4])];
            Th = Ci[ivs + (csi[3])];
            Ti = Tg + Th;
            TU = Tg - Th;
        }
        T7b = T3 + T6;
        TWb = TU + TV;
        T13b = TV - TU;
        Tjb = Tf - Ti;
        TDb = Tz + TC;
        TKb = Tz - TC;
        TPb = T3 - T6;
        THb = Tf + Ti;
    }
    {
        E Ta, Tk, Tn, TR, Td, Tp, Ts, TQ;
        {
            E T8, T9, Tl, Tm;
            T8 = Cr[ivs + (csr[2])];
            T9 = Cr[ivs + (csr[5])];
            Ta = T8 + T9;
            Tk = T8 - T9;
            Tl = Ci[ivs + (csi[2])];
            Tm = Ci[ivs + (csi[5])];
            Tn = Tl + Tm;
            TR = Tl - Tm;
        }
        {
            E Tb, Tc, Tq, Tr;
            Tb = Cr[ivs + (csr[1])];
            Tc = Cr[ivs + (csr[6])];
            Td = Tb + Tc;
            Tp = Tb - Tc;
            Tq = Ci[ivs + (csi[1])];
            Tr = Ci[ivs + (csi[6])];
            Ts = Tq + Tr;
            TQ = Tr - Tq;
        }
        Teb = Ta + Td;
        TXb = Ta - Td;
        T12b = TR + TQ;
        Tob = Tk - Tn;
        Ttb = Tp - Ts;
        Txb = Tp + Ts;
        TSb = TQ - TR;
        Twb = Tk + Tn;
    }

    // Store results for first half
    R0[0] = KP2_000000000 * (T7a + Tea);
    R0[(rs[4])] = KP2_000000000 * (T13a - T12a);
    TTx = TPa + TSa;
    TYx = TWa - TXa;
    R0[(rs[1])] = (((KP1_847759065) * (TTx)) + (KP765366864 * TYx));
    R0[(rs[5])] = ((KP1_847759065 * TYx) - ((KP765366864) * (TTx)));
    {
        E T11, T14, TZ, T10;
        T11 = T7a - Tea;
        T14 = T12a + T13a;
        R0[(rs[2])] = KP1_414213562 * (T11 + T14);
        R0[(rs[6])] = KP1_414213562 * (T14 - T11);
        TZ = TPa - TSa;
        T10 = TXa + TWa;
        R0[(rs[3])] = (((KP765366864) * (TZ)) + (KP1_847759065 * T10));
        R0[(rs[7])] = ((KP765366864 * T10) - ((KP1_847759065) * (TZ)));
    }
    {
        E TJ, TN, TM, TO, TI, TL;
        TI = KP707106781 * (Twa + Txa);
        TJ = THa - TI;
        TN = THa + TI;
        TL = KP707106781 * (Toa - Tta);
        TM = TKa - TL;
        TO = TL + TKa;
        R1[(rs[1])] = (((KP1_662939224) * (TJ)) + (KP1_111140466 * TM));
        R1[(rs[7])] = ((KP390180644 * TO) - ((KP1_961570560) * (TN)));
        R1[(rs[5])] = ((KP1_662939224 * TM) - ((KP1_111140466) * (TJ)));
        R1[(rs[3])] = (((KP390180644) * (TN)) + (KP1_961570560 * TO));
    }
    {
        E Tv, TF, TE, TG, Tu, Ty;
        Tu = KP707106781 * (Toa + Tta);
        Tv = Tja + Tu;
        TF = Tja - Tu;
        Ty = KP707106781 * (Twa - Txa);
        TE = Ty + TDa;
        TG = Ty - TDa;
        R1[0] = ((KP1_961570560 * Tv) - ((KP390180644) * (TE)));
        R1[(rs[6])] = ((KP1_111140466 * TG) - ((KP1_662939224) * (TF)));
        R1[(rs[4])] = -((((KP390180644) * (Tv)) + (KP1_961570560 * TE)));
        R1[(rs[2])] = (((KP1_111140466) * (TF)) + (KP1_662939224 * TG));
    }

    // Store results for second half
    R0[ovs] = KP2_000000000 * (T7b + Teb);
    R0[ovs + (rs[4])] = KP2_000000000 * (T13b - T12b);
    TTb = TPb + TSb;
    TYb = TWb - TXb;
    R0[ovs + (rs[1])] = (((KP1_847759065) * (TTb)) + (KP765366864 * TYb));
    R0[ovs + (rs[5])] = ((KP1_847759065 * TYb) - ((KP765366864) * (TTb)));
    {
        E T11, T14, TZ, T10;
        T11 = T7b - Teb;
        T14 = T12b + T13b;
        R0[ovs + (rs[2])] = KP1_414213562 * (T11 + T14);
        R0[ovs + (rs[6])] = KP1_414213562 * (T14 - T11);
        TZ = TPb - TSb;
        T10 = TXb + TWb;
        R0[ovs + (rs[3])] = (((KP765366864) * (TZ)) + (KP1_847759065 * T10));
        R0[ovs + (rs[7])] = ((KP765366864 * T10) - ((KP1_847759065) * (TZ)));
    }
    {
        E TJ, TN, TM, TO, TI, TL;
        TI = KP707106781 * (Twb + Txb);
        TJ = THb - TI;
        TN = THb + TI;
        TL = KP707106781 * (Tob - Ttb);
        TM = TKb - TL;
        TO = TL + TKb;
        R1[ovs + (rs[1])] = (((KP1_662939224) * (TJ)) + (KP1_111140466 * TM));
        R1[ovs + (rs[7])] = ((KP390180644 * TO) - ((KP1_961570560) * (TN)));
        R1[ovs + (rs[5])] = ((KP1_662939224 * TM) - ((KP1_111140466) * (TJ)));
        R1[ovs + (rs[3])] = (((KP390180644) * (TN)) + (KP1_961570560 * TO));
    }
    {
        E Tv, TF, TE, TG, Tu, Ty;
        Tu = KP707106781 * (Tob + Ttb);
        Tv = Tjb + Tu;
        TF = Tjb - Tu;
        Ty = KP707106781 * (Twb - Txb);
        TE = Ty + TDb;
        TG = Ty - TDb;
        R1[ovs] = ((KP1_961570560 * Tv) - ((KP390180644) * (TE)));
        R1[ovs + (rs[6])] = ((KP1_111140466 * TG) - ((KP1_662939224) * (TF)));
        R1[ovs + (rs[4])] = -((((KP390180644) * (Tv)) + (KP1_961570560 * TE)));
        R1[ovs + (rs[2])] = (((KP1_111140466) * (TF)) + (KP1_662939224 * TG));
    }
}
}
