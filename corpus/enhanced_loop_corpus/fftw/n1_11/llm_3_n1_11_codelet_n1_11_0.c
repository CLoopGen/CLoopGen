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
extern  E KP654860733;
extern  E KP142314838;
extern  E KP959492973;
extern  E KP415415013;
extern  E KP841253532;
extern  E KP989821441;
extern  E KP909631995;
extern  E KP281732556;
extern  E KP540640817;
extern  E KP755749574;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , ri += ivs , ii += ivs , ro += ovs , io += ovs) {
    E T1, TM, T4, TG, Tk, TR, Tw, TN, T7, TK, Ta, TH, Tn, TQ, Td;
    E TJ, Tq, TO, Tt, TP, Tg, TI;
    E temp_real[11], temp_imag[11];
    const INT idx[] = {0, is[1], is[2], is[3], is[4], is[5], is[6], is[7], is[8], is[9], is[10]};
    
    for (INT j = 0; j < 11; ++j) {
        temp_real[j] = ri[idx[j]];
        temp_imag[j] = ii[idx[j]];
    }

    {
        E T2, T3, Ti, Tj;
        T1 = temp_real[0];
        TM = temp_imag[0];
        T2 = temp_real[1];
        T3 = temp_real[10];
        T4 = T2 + T3;
        TG = T3 - T2;
        Ti = temp_imag[1];
        Tj = temp_imag[10];
        Tk = Ti - Tj;
        TR = Ti + Tj;
        {
            E Tu, Tv, T5, T6;
            Tu = temp_imag[2];
            Tv = temp_imag[9];
            Tw = Tu - Tv;
            TN = Tu + Tv;
            T5 = temp_real[2];
            T6 = temp_real[9];
            T7 = T5 + T6;
            TK = T6 - T5;
        }
    }
    {
        E T8, T9, To, Tp;
        T8 = temp_real[3];
        T9 = temp_real[8];
        Ta = T8 + T9;
        TH = T9 - T8;
        {
            E Tl, Tm, Tb, Tc;
            Tl = temp_imag[3];
            Tm = temp_imag[8];
            Tn = Tl - Tm;
            TQ = Tl + Tm;
            Tb = temp_real[4];
            Tc = temp_real[7];
            Td = Tb + Tc;
            TJ = Tc - Tb;
        }
        To = temp_imag[4];
        Tp = temp_imag[7];
        Tq = To - Tp;
        TO = To + Tp;
        {
            E Tr, Ts, Te, Tf;
            Tr = temp_imag[5];
            Ts = temp_imag[6];
            Tt = Tr - Ts;
            TP = Tr + Ts;
            Te = temp_real[5];
            Tf = temp_real[6];
            Tg = Te + Tf;
            TI = Tf - Te;
        }
    }
    {
        E Tx, Th, TZ, T10;
        ro[0] = T1 + T4 + T7 + Ta + Td + Tg;
        io[0] = TM + TR + TN + TQ + TO + TP;
        Tx = (((KP755749574) * (Tk)) + (KP540640817 * Tn)) + ((KP281732556 * Tq) - ((KP909631995) * (Tt))) - (KP989821441 * Tw);
        Th = (((KP841253532) * (Ta)) + (T1)) + ((KP415415013 * Tg) - ((KP959492973) * (Td))) + (-(((KP142314838) * (T7)) + (KP654860733 * T4)));
        ro[os[7]] = Th - Tx;
        ro[os[4]] = Th + Tx;
        TZ = (((KP755749574) * (TG)) + (KP540640817 * TH)) + ((KP281732556 * TJ) - ((KP909631995) * (TI))) - (KP989821441 * TK);
        T10 = (((KP841253532) * (TQ)) + (TM)) + ((KP415415013 * TP) - ((KP959492973) * (TO))) + (-(((KP142314838) * (TN)) + (KP654860733 * TR)));
        io[os[4]] = TZ + T10;
        io[os[7]] = T10 - TZ;
        {
            E TX, TY, Tz, Ty;
            TX = (((KP909631995) * (TG)) + (KP755749574 * TK)) + (-(((KP540640817) * (TI)) + (KP989821441 * TJ))) - (KP281732556 * TH);
            TY = (((KP415415013) * (TR)) + (TM)) + ((KP841253532 * TP) - ((KP142314838) * (TO))) + (-(((KP959492973) * (TQ)) + (KP654860733 * TN)));
            io[os[2]] = TX + TY;
            io[os[9]] = TY - TX;
            Tz = (((KP909631995) * (Tk)) + (KP755749574 * Tw)) + (-(((KP540640817) * (Tt)) + (KP989821441 * Tq))) - (KP281732556 * Tn);
            Ty = (((KP415415013) * (T4)) + (T1)) + ((KP841253532 * Tg) - ((KP142314838) * (Td))) + (-(((KP959492973) * (Ta)) + (KP654860733 * T7)));
            ro[os[9]] = Ty - Tz;
            ro[os[2]] = Ty + Tz;
        }
    }
    {
        E TB, TA, TT, TU;
        TB = (((KP540640817) * (Tk)) + (KP909631995 * Tw)) + (((KP989821441) * (Tn)) + (KP755749574 * Tq)) + (KP281732556 * Tt);
        TA = (((KP841253532) * (T4)) + (T1)) + ((KP415415013 * T7) - ((KP959492973) * (Tg))) + (-(((KP654860733) * (Td)) + (KP142314838 * Ta)));
        ro[os[10]] = TA - TB;
        ro[os[1]] = TA + TB;
        {
            E TV, TW, TD, TC;
            TV = (((KP540640817) * (TG)) + (KP909631995 * TK)) + (((KP989821441) * (TH)) + (KP755749574 * TJ)) + (KP281732556 * TI);
            TW = (((KP841253532) * (TR)) + (TM)) + ((KP415415013 * TN) - ((KP959492973) * (TP))) + (-(((KP654860733) * (TO)) + (KP142314838 * TQ)));
            io[os[1]] = TV + TW;
            io[os[10]] = TW - TV;
            TD = (((KP989821441) * (Tk)) + (KP540640817 * Tq)) + ((KP755749574 * Tt) - ((KP909631995) * (Tn))) - (KP281732556 * Tw);
            TC = (((KP415415013) * (Ta)) + (T1)) + ((KP841253532 * Td) - ((KP654860733) * (Tg))) + (-(((KP959492973) * (T7)) + (KP142314838 * T4)));
            ro[os[8]] = TC - TD;
            ro[os[3]] = TC + TD;
        }
        TT = (((KP989821441) * (TG)) + (KP540640817 * TJ)) + ((KP755749574 * TI) - ((KP909631995) * (TH))) - (KP281732556 * TK);
        TU = (((KP415415013) * (TQ)) + (TM)) + ((KP841253532 * TO) - ((KP654860733) * (TP))) + (-(((KP959492973) * (TN)) + (KP142314838 * TR)));
        io[os[3]] = TT + TU;
        io[os[8]] = TU - TT;
        {
            E TL, TS, TF, TE;
            TL = (((KP281732556) * (TG)) + (KP755749574 * TH)) + ((KP989821441 * TI) - ((KP909631995) * (TJ))) - (KP540640817 * TK);
            TS = (((KP841253532) * (TN)) + (TM)) + ((KP415415013 * TO) - ((KP142314838) * (TP))) + (-(((KP654860733) * (TQ)) + (KP959492973 * TR)));
            io[os[5]] = TL + TS;
            io[os[6]] = TS - TL;
            TF = (((KP281732556) * (Tk)) + (KP755749574 * Tn)) + ((KP989821441 * Tt) - ((KP909631995) * (Tq))) - (KP540640817 * Tw);
            TE = (((KP841253532) * (T7)) + (T1)) + ((KP415415013 * Td) - ((KP142314838) * (Tg))) + (-(((KP654860733) * (Ta)) + (KP959492973 * T4)));
            ro[os[6]] = TE - TF;
            ro[os[5]] = TE + TF;
        }
    }
}
}
