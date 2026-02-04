#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern  R *ri;
extern  R *ii;
extern R *ro;
extern R *io;
extern stride is;
extern stride os;
extern INT v;
extern INT ivs;
extern INT ovs;
extern  E KP939692620;
extern  E KP342020143;
extern  E KP984807753;
extern  E KP173648177;
extern  E KP642787609;
extern  E KP766044443;
extern  E KP500000000;
extern  E KP866025403;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v / 2; i > 0; i = i - 1 , ri = ri + 2*ivs , ii = ii + 2*ivs , ro = ro + 2*ovs , io = io + 2*ovs , (is) = (is) + 2*fftw_an_INT_guaranteed_to_be_zero , (os) = (os) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    // Unrolled version: process two iterations at once to increase computational intensity

    // First iteration (original index)
    E T5_1, TO_1, Th_1, Tk_1, T1g_1, TR_1, Ta_1, T1c_1, Tq_1, TW_1, Tv_1, TX_1, Tf_1, T1d_1, TB_1;
    E T10_1, TG_1, TZ_1;
    {
        E T1 = ri[0], T2 = ri[(is[3])], T3 = ri[(is[6])];
        E T4 = T2 + T3;
        T5_1 = T1 + T4;
        TO_1 = KP866025403 * (T3 - T2);
        Th_1 = T1 - KP500000000 * T4;
    }
    {
        E TP = ii[0], Ti = ii[(is[3])], Tj = ii[(is[6])];
        E TQ = Ti + Tj;
        Tk_1 = KP866025403 * (Ti - Tj);
        T1g_1 = TP + TQ;
        TR_1 = TP - KP500000000 * TQ;
    }
    {
        E T6 = ri[(is[1])], Ts = ii[(is[1])];
        E T7 = ri[(is[4])], T8 = ri[(is[7])];
        E T9 = T7 + T8;
        E Tr = KP866025403 * (T8 - T7);
        E Tn = ii[(is[4])], To = ii[(is[7])];
        E Tp = KP866025403 * (Tn - To);
        E Tt = Tn + To;
        Ta_1 = T6 + T9;
        T1c_1 = Ts + Tt;
        E Tm = T6 - KP500000000 * T9;
        Tq_1 = Tm + Tp;
        TW_1 = Tm - Tp;
        E Tu = Ts - KP500000000 * Tt;
        Tv_1 = Tr + Tu;
        TX_1 = Tu - Tr;
    }
    {
        E Tb = ri[(is[2])], TD = ii[(is[2])];
        E Tc = ri[(is[5])], Td = ri[(is[8])];
        E Te = Tc + Td;
        E TC = KP866025403 * (Td - Tc);
        E Ty = ii[(is[5])], Tz = ii[(is[8])];
        E TA = KP866025403 * (Ty - Tz);
        E TE = Ty + Tz;
        Tf_1 = Tb + Te;
        T1d_1 = TD + TE;
        E Tx = Tb - KP500000000 * Te;
        TB_1 = Tx + TA;
        T10_1 = Tx - TA;
        E TF = TD - KP500000000 * TE;
        TG_1 = TC + TF;
        TZ_1 = TF - TC;
    }

    // Second iteration (next vector element)
    E T5_2, TO_2, Th_2, Tk_2, T1g_2, TR_2, Ta_2, T1c_2, Tq_2, TW_2, Tv_2, TX_2, Tf_2, T1d_2, TB_2;
    E T10_2, TG_2, TZ_2;
    {
        E T1 = ri[ivs], T2 = ri[ivs + (is[3])], T3 = ri[ivs + (is[6])];
        E T4 = T2 + T3;
        T5_2 = T1 + T4;
        TO_2 = KP866025403 * (T3 - T2);
        Th_2 = T1 - KP500000000 * T4;
    }
    {
        E TP = ii[ivs], Ti = ii[ivs + (is[3])], Tj = ii[ivs + (is[6])];
        E TQ = Ti + Tj;
        Tk_2 = KP866025403 * (Ti - Tj);
        T1g_2 = TP + TQ;
        TR_2 = TP - KP500000000 * TQ;
    }
    {
        E T6 = ri[ivs + (is[1])], Ts = ii[ivs + (is[1])];
        E T7 = ri[ivs + (is[4])], T8 = ri[ivs + (is[7])];
        E T9 = T7 + T8;
        E Tr = KP866025403 * (T8 - T7);
        E Tn = ii[ivs + (is[4])], To = ii[ivs + (is[7])];
        E Tp = KP866025403 * (Tn - To);
        E Tt = Tn + To;
        Ta_2 = T6 + T9;
        T1c_2 = Ts + Tt;
        E Tm = T6 - KP500000000 * T9;
        Tq_2 = Tm + Tp;
        TW_2 = Tm - Tp;
        E Tu = Ts - KP500000000 * Tt;
        Tv_2 = Tr + Tu;
        TX_2 = Tu - Tr;
    }
    {
        E Tb = ri[ivs + (is[2])], TD = ii[ivs + (is[2])];
        E Tc = ri[ivs + (is[5])], Td = ri[ivs + (is[8])];
        E Te = Tc + Td;
        E TC = KP866025403 * (Td - Tc);
        E Ty = ii[ivs + (is[5])], Tz = ii[ivs + (is[8])];
        E TA = KP866025403 * (Ty - Tz);
        E TE = Ty + Tz;
        Tf_2 = Tb + Te;
        T1d_2 = TD + TE;
        E Tx = Tb - KP500000000 * Te;
        TB_2 = Tx + TA;
        T10_2 = Tx - TA;
        E TF = TD - KP500000000 * TE;
        TG_2 = TC + TF;
        TZ_2 = TF - TC;
    }

    // Output first iteration
    {
        E T1e = KP866025403 * (T1c_1 - T1d_1);
        E Tg = Ta_1 + Tf_1;
        E T1b = T5_1 - KP500000000 * Tg;
        ro[0] = T5_1 + Tg;
        ro[(os[3])] = T1b + T1e;
        ro[(os[6])] = T1b - T1e;
        E T1f = KP866025403 * (Tf_1 - Ta_1);
        E T1h = T1c_1 + T1d_1;
        E T1i = T1g_1 - KP500000000 * T1h;
        io[(os[3])] = T1f + T1i;
        io[0] = T1g_1 + T1h;
        io[(os[6])] = T1i - T1f;
    }
    {
        E Tl = Th_1 + Tk_1, TS = TO_1 + TR_1;
        E Tw = KP766044443 * Tq_1 + KP642787609 * Tv_1;
        E TH = KP173648177 * TB_1 + KP984807753 * TG_1;
        E TI = Tw + TH;
        E TN = KP866025403 * (TH - Tw);
        E TK = KP766044443 * Tv_1 - KP642787609 * Tq_1;
        E TL = KP173648177 * TG_1 - KP984807753 * TB_1;
        E TM = KP866025403 * (TK - TL);
        E TT = TK + TL;
        ro[(os[1])] = Tl + TI;
        io[(os[1])] = TS + TT;
        E TJ = Tl - KP500000000 * TI;
        ro[(os[7])] = TJ - TM;
        ro[(os[4])] = TJ + TM;
        E TU = TS - KP500000000 * TT;
        io[(os[4])] = TN + TU;
        io[(os[7])] = TU - TN;
    }
    {
        E TV = Th_1 - Tk_1, T14 = TR_1 - TO_1;
        E TY = KP173648177 * TW_1 + KP984807753 * TX_1;
        E T11 = KP342020143 * TZ_1 - KP939692620 * T10_1;
        E T12 = TY + T11;
        E T13 = KP866025403 * (T11 - TY);
        E T15 = KP173648177 * TX_1 - KP984807753 * TW_1;
        E T16 = KP342020143 * T10_1 + KP939692620 * TZ_1;
        E T17 = T15 - T16;
        E T1a = KP866025403 * (T15 + T16);
        ro[(os[2])] = TV + T12;
        io[(os[2])] = T14 + T17;
        E T18 = T14 - KP500000000 * T17;
        io[(os[5])] = T13 + T18;
        io[(os[8])] = T18 - T13;
        E T19 = TV - KP500000000 * T12;
        ro[(os[8])] = T19 - T1a;
        ro[(os[5])] = T19 + T1a;
    }

    // Output second iteration
    {
        E T1e = KP866025403 * (T1c_2 - T1d_2);
        E Tg = Ta_2 + Tf_2;
        E T1b = T5_2 - KP500000000 * Tg;
        ro[ovs] = T5_2 + Tg;
        ro[ovs + (os[3])] = T1b + T1e;
        ro[ovs + (os[6])] = T1b - T1e;
        E T1f = KP866025403 * (Tf_2 - Ta_2);
        E T1h = T1c_2 + T1d_2;
        E T1i = T1g_2 - KP500000000 * T1h;
        io[ovs + (os[3])] = T1f + T1i;
        io[ovs] = T1g_2 + T1h;
        io[ovs + (os[6])] = T1i - T1f;
    }
    {
        E Tl = Th_2 + Tk_2, TS = TO_2 + TR_2;
        E Tw = KP766044443 * Tq_2 + KP642787609 * Tv_2;
        E TH = KP173648177 * TB_2 + KP984807753 * TG_2;
        E TI = Tw + TH;
        E TN = KP866025403 * (TH - Tw);
        E TK = KP766044443 * Tv_2 - KP642787609 * Tq_2;
        E TL = KP173648177 * TG_2 - KP984807753 * TB_2;
        E TM = KP866025403 * (TK - TL);
        E TT = TK + TL;
        ro[ovs + (os[1])] = Tl + TI;
        io[ovs + (os[1])] = TS + TT;
        E TJ = Tl - KP500000000 * TI;
        ro[ovs + (os[7])] = TJ - TM;
        ro[ovs + (os[4])] = TJ + TM;
        E TU = TS - KP500000000 * TT;
        io[ovs + (os[4])] = TN + TU;
        io[ovs + (os[7])] = TU - TN;
    }
    {
        E TV = Th_2 - Tk_2, T14 = TR_2 - TO_2;
        E TY = KP173648177 * TW_2 + KP984807753 * TX_2;
        E T11 = KP342020143 * TZ_2 - KP939692620 * T10_2;
        E T12 = TY + T11;
        E T13 = KP866025403 * (T11 - TY);
        E T15 = KP173648177 * TX_2 - KP984807753 * TW_2;
        E T16 = KP342020143 * T10_2 + KP939692620 * TZ_2;
        E T17 = T15 - T16;
        E T1a = KP866025403 * (T15 + T16);
        ro[ovs + (os[2])] = TV + T12;
        io[ovs + (os[2])] = T14 + T17;
        E T18 = T14 - KP500000000 * T17;
        io[ovs + (os[5])] = T13 + T18;
        io[ovs + (os[8])] = T18 - T13;
        E T19 = TV - KP500000000 * T12;
        ro[ovs + (os[8])] = T19 - T1a;
        ro[ovs + (os[5])] = T19 + T1a;
    }
}
}
