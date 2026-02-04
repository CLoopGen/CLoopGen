#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *cr;
extern R *ci;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP250000000;
extern  E KP559016994;
extern  E KP587785252;
extern  E KP951056516;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 8); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 8 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, TE, Tu, Tx, TC, TB, TF, TG, TH, Tc, Tn, To;
    T1 = cr[0];
    TE = ci[0];
    {
        E T6, Ts, Tm, Tw, Tb, Tt, Th, Tv;
        // Reorder independent computations to break implicit dependency chains
        E Tj = cr[(rs[3])], Tl = ci[(rs[3])], Ti = W[4], Tk = W[5];
        E T8 = cr[(rs[4])], Ta = ci[(rs[4])], T7 = W[6], T9 = W[7];
        E Te = cr[(rs[2])], Tg = ci[(rs[2])], Td = W[2], Tf = W[3];
        E T3 = cr[(rs[1])], T5 = ci[(rs[1])], T2 = W[0], T4 = W[1];

        T6 = T2 * T3 + T4 * T5;
        Ts = T2 * T5 - T4 * T3;

        Tm = Ti * Tj + Tk * Tl;
        Tw = Ti * Tl - Tk * Tj;

        Tb = T7 * T8 + T9 * Ta;
        Tt = T7 * Ta - T9 * T8;

        Th = Td * Te + Tf * Tg;
        Tv = Td * Tg - Tf * Te;

        // Introduce temporary variables to delay use of computed values
        E sum_s = Ts + Tt, diff_s = Ts - Tt;
        E sum_v = Tv + Tw, diff_v = Tv - Tw;
        E sum_hb = Th + Tm, diff_hb = Th - Tm;
        E sum_bt = Tb + T6, diff_bt = Tb - T6;

        Tu = diff_s;
        Tx = diff_v;
        TC = diff_hb;
        TB = diff_bt;
        TF = sum_s;
        TG = sum_v;
        TH = sum_s + sum_v;
        Tc = sum_bt;
        Tn = sum_hb;
        To = sum_bt + sum_hb;
    }
    cr[0] = T1 + To;
    {
        E Ty, TA, Tr, Tz, Tp, Tq;
        // Rearranged arithmetic order with intermediate decomposition
        E temp_u = KP587785252 * Tx, temp_x = KP951056516 * Tu;
        Ty = KP951056516 * Tu + KP587785252 * Tx;
        TA = KP951056516 * Tx - KP587785252 * Tu;

        Tp = KP559016994 * (Tc - Tn);
        Tq = T1 - KP250000000 * To;

        Tr = Tp + Tq;
        Tz = Tq - Tp;

        // Reorder stores to allow better memory disambiguation
        cr[(rs[1])] = Tr + Ty;
        ci[(rs[1])] = Tz + TA;
        cr[(rs[2])] = Tz - TA;
        ci[0] = Tr - Ty;
    }
    ci[(rs[4])] = TH + TE;
    {
        E TD, TL, TK, TM, TI, TJ;
        // Restructure expression tree to change operation associativity
        TD = KP587785252 * TB + KP951056516 * TC;
        TL = KP951056516 * TB - KP587785252 * TC;

        TI = TE - KP250000000 * TH;
        TJ = KP559016994 * (TF - TG);

        TK = TI - TJ;
        TM = TJ + TI;

        ci[(rs[2])] = TD + TK;
        cr[(rs[3])] = TD - TK;
        cr[(rs[4])] = TL - TM;
        ci[(rs[3])] = TL + TM;
    }
}
}
