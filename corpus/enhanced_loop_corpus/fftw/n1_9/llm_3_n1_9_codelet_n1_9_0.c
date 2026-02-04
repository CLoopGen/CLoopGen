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
for (i = v; i > 0; i = i - 1 , ri += ivs*9 , ii += ivs*9 , ro += ovs*9 , io += ovs*9) {
    E T5, TO, Th, Tk, T1g, TR, Ta, T1c, Tq, TW, Tv, TX, Tf, T1d, TB;
    E T10, TG, TZ;
    INT j;
    R *rbase = ri;
    R *ibase = ii;
    R *obase_r = ro;
    R *obase_i = io;

    for (j = 0; j < 9; ++j) {
        rbase[j] = ri[is[j]];
        ibase[j] = ii[is[j]];
    }

    {
        E T1, T2, T3, T4;
        T1 = rbase[0];
        T2 = rbase[3];
        T3 = rbase[6];
        T4 = T2 + T3;
        T5 = T1 + T4;
        TO = KP866025403 * (T3 - T2);
        Th = T1 - KP500000000 * T4;
    }
    {
        E TP, Ti, Tj, TQ;
        TP = ibase[0];
        Ti = ibase[3];
        Tj = ibase[6];
        TQ = Ti + Tj;
        Tk = KP866025403 * (Ti - Tj);
        T1g = TP + TQ;
        TR = TP - KP500000000 * TQ;
    }
    {
        E T6, Ts, T9, Tr, Tp, Tt, Tm, Tu;
        T6 = rbase[1];
        Ts = ibase[1];
        {
            E T7, T8, Tn, To;
            T7 = rbase[4];
            T8 = rbase[7];
            T9 = T7 + T8;
            Tr = KP866025403 * (T8 - T7);
            Tn = ibase[4];
            To = ibase[7];
            Tp = KP866025403 * (Tn - To);
            Tt = Tn + To;
        }
        Ta = T6 + T9;
        T1c = Ts + Tt;
        Tm = T6 - KP500000000 * T9;
        Tq = Tm + Tp;
        TW = Tm - Tp;
        Tu = Ts - KP500000000 * Tt;
        Tv = Tr + Tu;
        TX = Tu - Tr;
    }
    {
        E Tb, TD, Te, TC, TA, TE, Tx, TF;
        Tb = rbase[2];
        TD = ibase[2];
        {
            E Tc, Td, Ty, Tz;
            Tc = rbase[5];
            Td = rbase[8];
            Te = Tc + Td;
            TC = KP866025403 * (Td - Tc);
            Ty = ibase[5];
            Tz = ibase[8];
            TA = KP866025403 * (Ty - Tz);
            TE = Ty + Tz;
        }
        Tf = Tb + Te;
        T1d = TD + TE;
        Tx = Tb - KP500000000 * Te;
        TB = Tx + TA;
        T10 = Tx - TA;
        TF = TD - KP500000000 * TE;
        TG = TC + TF;
        TZ = TF - TC;
    }
    {
        E T1e, Tg, T1b, T1f, T1h, T1i;
        T1e = KP866025403 * (T1c - T1d);
        Tg = Ta + Tf;
        T1b = T5 - KP500000000 * Tg;
        obase_r[0] = T5 + Tg;
        obase_r[3] = T1b + T1e;
        obase_r[6] = T1b - T1e;
        T1f = KP866025403 * (Tf - Ta);
        T1h = T1c + T1d;
        T1i = T1g - KP500000000 * T1h;
        obase_i[3] = T1f + T1i;
        obase_i[0] = T1g + T1h;
        obase_i[6] = T1i - T1f;
    }
    {
        E Tl, TS, TI, TN, TM, TT, TJ, TU;
        Tl = Th + Tk;
        TS = TO + TR;
        {
            E Tw, TH, TK, TL;
            Tw = KP766044443 * Tq + KP642787609 * Tv;
            TH = KP173648177 * TB + KP984807753 * TG;
            TI = Tw + TH;
            TN = KP866025403 * (TH - Tw);
            TK = KP766044443 * Tv - KP642787609 * Tq;
            TL = KP173648177 * TG - KP984807753 * TB;
            TM = KP866025403 * (TK - TL);
            TT = TK + TL;
        }
        obase_r[1] = Tl + TI;
        obase_i[1] = TS + TT;
        TJ = Tl - KP500000000 * TI;
        obase_r[7] = TJ - TM;
        obase_r[4] = TJ + TM;
        TU = TS - KP500000000 * TT;
        obase_i[4] = TN + TU;
        obase_i[7] = TU - TN;
    }
    {
        E TV, T14, T12, T13, T17, T1a, T18, T19;
        TV = Th - Tk;
        T14 = TR - TO;
        {
            E TY, T11, T15, T16;
            TY = KP173648177 * TW + KP984807753 * TX;
            T11 = KP342020143 * TZ - KP939692620 * T10;
            T12 = TY + T11;
            T13 = KP866025403 * (T11 - TY);
            T15 = KP173648177 * TX - KP984807753 * TW;
            T16 = KP342020143 * T10 + KP939692620 * TZ;
            T17 = T15 - T16;
            T1a = KP866025403 * (T15 + T16);
        }
        obase_r[2] = TV + T12;
        obase_i[2] = T14 + T17;
        T18 = T14 - KP500000000 * T17;
        obase_i[5] = T13 + T18;
        obase_i[8] = T18 - T13;
        T19 = TV - KP500000000 * T12;
        obase_r[8] = T19 - T1a;
        obase_r[5] = T19 + T1a;
    }
}
}
