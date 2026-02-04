#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *Rp;
extern R *Ip;
extern R *Rm;
extern R *Im;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP500000000;
extern  E KP866025403;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 10); m < me; m = m + 1 , Rp += ms , Ip += ms , Rm -= ms , Im -= ms , W += 10 , (rs) += fftw_an_INT_guaranteed_to_be_zero) {
    E T3, Ty, Td, TE, Ta, TO, Tr, TB, Tk, TL, Tn, TH;
    E *rptr[3], *iptr[3], *rmtr[3], *imtr[3];
    const INT i0 = 0, i1 = rs[1], i2 = rs[2];

    rptr[0] = Rp;     iptr[0] = Ip;     rmtr[0] = Rm;     imtr[0] = Im;
    rptr[1] = Rp+i1;  iptr[1] = Ip+i1;  rmtr[1] = Rm-i1;  imtr[1] = Im-i1;
    rptr[2] = Rp+i2;  iptr[2] = Ip+i2;  rmtr[2] = Rm-i2;  imtr[2] = Im-i2;

    {
        E T1, T2, Tb, Tc;
        T1 = rptr[0][0];
        T2 = rmtr[2][0];
        T3 = T1 + T2;
        Ty = T1 - T2;
        Tb = iptr[0][0];
        Tc = imtr[2][0];
        Td = Tb - Tc;
        TE = Tb + Tc;
    }
    {
        E T6, Tz, T9, TA;
        {
            E T4, T5, T7, T8;
            T4 = rptr[2][0];
            T5 = rmtr[0][0];
            T6 = T4 + T5;
            Tz = T4 - T5;
            T7 = rmtr[1][0];
            T8 = rptr[1][0];
            T9 = T7 + T8;
            TA = T7 - T8;
        }
        Ta = T6 + T9;
        TO = KP866025403 * (Tz - TA);
        Tr = KP866025403 * (T6 - T9);
        TB = Tz + TA;
    }
    {
        E Tg, TG, Tj, TF;
        {
            E Te, Tf, Th, Ti;
            Te = iptr[2][0];
            Tf = imtr[0][0];
            Tg = Te - Tf;
            TG = Te + Tf;
            Th = iptr[1][0];
            Ti = imtr[1][0];
            Tj = Th - Ti;
            TF = Th + Ti;
        }
        Tk = Tg + Tj;
        TL = KP866025403 * (TG + TF);
        Tn = KP866025403 * (Tj - Tg);
        TH = TF - TG;
    }

    rptr[0][0] = T3 + Ta;
    rmtr[0][0] = Td + Tk;

    {
        E TC, TI, Tx, TD;
        TC = Ty + TB;
        TI = TE - TH;
        Tx = W[4];
        TD = W[5];
        iptr[1][0] = (Tx * TC) - (TD * TI);
        imtr[1][0] = (TD * TC) + (Tx * TI);
    }

    {
        E To, Tu, Ts, Tw, Tm, Tq;
        Tm = T3 - (KP500000000 * Ta);
        To = Tm - Tn;
        Tu = Tm + Tn;
        Tq = Td - (KP500000000 * Tk);
        Ts = Tq - Tr;
        Tw = Tr + Tq;

        E Tl = W[2], Tp = W[3], Tt = W[6], Tv = W[7];
        rptr[1][0] = (Tl * To) - (Tp * Ts);
        rmtr[1][0] = (Tl * Ts) + (Tp * To);
        rptr[2][0] = (Tt * Tu) - (Tv * Tw);
        rmtr[2][0] = (Tt * Tw) + (Tv * Tu);
    }

    {
        E TM, TS, TQ, TU, TK, TP;
        TK = Ty - (KP500000000 * TB);
        TM = TK - TL;
        TS = TK + TL;
        TP = (KP500000000 * TH) + TE;
        TQ = TO + TP;
        TU = TP - TO;

        E TJ = W[0], TN = W[1], TR = W[8], TT = W[9];
        iptr[0][0] = (TJ * TM) - (TN * TQ);
        imtr[0][0] = (TN * TM) + (TJ * TQ);
        iptr[2][0] = (TR * TS) - (TT * TU);
        imtr[2][0] = (TT * TS) + (TR * TU);
    }
}
}
