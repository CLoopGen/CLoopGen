#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *rio;
extern R *iio;
extern  R *W;
extern stride rs;
extern stride vs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP866025403;
extern  E KP500000000;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + (mb * 4); m < me; m = m + 1 , rio = rio + ms , iio = iio + ms , W = W + 4 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (vs) = (vs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, T4, T6, Tc, Td, Te, T9, Tf, Tl, To, Tq, Tw, Tx, Ty, Tt;
    E Tz, TR, TS, TN, TT, TF, TI, TK, TQ;
    const INT r1 = rs[1], r2 = rs[2];
    const INT v1 = vs[1], v2 = vs[2];
    E * restrict rbase = rio;
    E * restrict ibase = iio;
    E * restrict wptr = W;
    {
        E T2, T3, Tr, Ts;
        T1 = rbase[0];
        T2 = rbase[r1];
        T3 = rbase[r2];
        T4 = T2 + T3;
        T6 = T1 - KP500000000 * T4;
        Tc = KP866025403 * (T3 - T2);
        {
            E T7, T8, Tm, Tn;
            Td = ibase[0];
            T7 = ibase[r1];
            T8 = ibase[r2];
            Te = T7 + T8;
            T9 = KP866025403 * (T7 - T8);
            Tf = Td - KP500000000 * Te;
            Tl = rbase[v1];
            Tm = rbase[v1 + r1];
            Tn = rbase[v1 + r2];
            To = Tm + Tn;
            Tq = Tl - KP500000000 * To;
            Tw = KP866025403 * (Tn - Tm);
        }
        Tx = ibase[v1];
        Tr = ibase[v1 + r1];
        Ts = ibase[v1 + r2];
        Ty = Tr + Ts;
        Tt = KP866025403 * (Tr - Ts);
        Tz = Tx - KP500000000 * Ty;
        {
            E TL, TM, TG, TH;
            TR = ibase[v2];
            TL = ibase[v2 + r1];
            TM = ibase[v2 + r2];
            TS = TL + TM;
            TN = KP866025403 * (TL - TM);
            TT = TR - KP500000000 * TS;
            TF = rbase[v2];
            TG = rbase[v2 + r1];
            TH = rbase[v2 + r2];
            TI = TG + TH;
            TK = TF - KP500000000 * TI;
            TQ = KP866025403 * (TH - TG);
        }
    }
    rbase[0] = T1 + T4;
    ibase[0] = Td + Te;
    rbase[r1] = Tl + To;
    ibase[r1] = Tx + Ty;
    ibase[r2] = TR + TS;
    rbase[r2] = TF + TI;
    {
        E Ta, Tg, T5, Tb;
        Ta = T6 + T9;
        Tg = Tc + Tf;
        T5 = wptr[0];
        Tb = wptr[1];
        rbase[v1] = T5 * Ta + Tb * Tg;
        ibase[v1] = T5 * Tg - Tb * Ta;
    }
    {
        E TW, TY, TV, TX;
        TW = TK - TN;
        TY = TT - TQ;
        TV = wptr[2];
        TX = wptr[3];
        rbase[v2 + r2] = TV * TW + TX * TY;
        ibase[v2 + r2] = TV * TY - TX * TW;
    }
    {
        E TC, TE, TB, TD;
        TC = Tq - Tt;
        TE = Tz - Tw;
        TB = wptr[2];
        TD = wptr[3];
        rbase[v2 + r1] = TB * TC + TD * TE;
        ibase[v2 + r1] = TB * TE - TD * TC;
    }
    {
        E Tu, TA, Tp, Tv;
        Tu = Tq + Tt;
        TA = Tw + Tz;
        Tp = wptr[0];
        Tv = wptr[1];
        rbase[v1 + r1] = Tp * Tu + Tv * TA;
        ibase[v1 + r1] = Tp * TA - Tv * Tu;
    }
    {
        E TO, TU, TJ, TP;
        TO = TK + TN;
        TU = TQ + TT;
        TJ = wptr[0];
        TP = wptr[1];
        rbase[v1 + r2] = TJ * TO + TP * TU;
        ibase[v1 + r2] = TJ * TU - TP * TO;
    }
    {
        E Ti, Tk, Th, Tj;
        Ti = T6 - T9;
        Tk = Tf - Tc;
        Th = wptr[2];
        Tj = wptr[3];
        rbase[v2] = Th * Ti + Tj * Tk;
        ibase[v2] = Th * Tk - Tj * Ti;
    }
}
}
