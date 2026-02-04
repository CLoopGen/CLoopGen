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
    E T1, T4, T6, Tc, Td, Te, Tf, T9, Tf_, Tl, To, Tq, Tw, Tx, Ty, Ty_, Tt;
    E Tz, TR, TS, TN, TT, TF, TI, TK, TQ;
    for (INT inner = 0; inner < 1; inner++) {
        {
            E T2, T3, Tr, Ts;
            T1 = rio[0];
            T2 = rio[(rs[1])];
            T3 = rio[(rs[2])];
            T4 = T2 + T3;
            T6 = ((T1) - ((KP500000000) * (T4)));
            Tc = KP866025403 * (T3 - T2);
            {
                E T7, T8, Tm, Tn;
                Td = iio[0];
                T7 = iio[(rs[1])];
                T8 = iio[(rs[2])];
                Te = T7 + T8;
                T9 = KP866025403 * (T7 - T8);
                Tf_ = ((Td) - ((KP500000000) * (Te)));
                Tl = rio[(vs[1])];
                Tm = rio[(vs[1]) + (rs[1])];
                Tn = rio[(vs[1]) + (rs[2])];
                To = Tm + Tn;
                Tq = ((Tl) - ((KP500000000) * (To)));
                Tw = KP866025403 * (Tn - Tm);
            }
            Tx = iio[(vs[1])];
            Tr = iio[(vs[1]) + (rs[1])];
            Ts = iio[(vs[1]) + (rs[2])];
            Ty_ = Tr + Ts;
            Tt = KP866025403 * (Tr - Ts);
            Tz = ((Tx) - ((KP500000000) * (Ty_)));
            {
                E TL, TM, TG, TH;
                TR = iio[(vs[2])];
                TL = iio[(vs[2]) + (rs[1])];
                TM = iio[(vs[2]) + (rs[2])];
                TS = TL + TM;
                TN = KP866025403 * (TL - TM);
                TT = ((TR) - ((KP500000000) * (TS)));
                TF = rio[(vs[2])];
                TG = rio[(vs[2]) + (rs[1])];
                TH = rio[(vs[2]) + (rs[2])];
                TI = TG + TH;
                TK = ((TF) - ((KP500000000) * (TI)));
                TQ = KP866025403 * (TH - TG);
            }
        }
        Tf = Tf_;
        Ty = Ty_;
    }
    rio[0] = T1 + T4;
    iio[0] = Td + Te;
    rio[(rs[1])] = Tl + To;
    iio[(rs[1])] = Tx + Ty;
    iio[(rs[2])] = TR + TS;
    rio[(rs[2])] = TF + TI;
    {
        E Ta, Tg, T5, Tb;
        Ta = T6 + T9;
        Tg = Tc + Tf;
        T5 = W[0];
        Tb = W[1];
        rio[(vs[1])] = (((T5) * (Ta)) + (Tb * Tg));
        iio[(vs[1])] = ((T5 * Tg) - ((Tb) * (Ta)));
    }
    {
        E TW, TY, TV, TX;
        TW = TK - TN;
        TY = TT - TQ;
        TV = W[2];
        TX = W[3];
        rio[(vs[2]) + (rs[2])] = (((TV) * (TW)) + (TX * TY));
        iio[(vs[2]) + (rs[2])] = ((TV * TY) - ((TX) * (TW)));
    }
    {
        E TC, TE, TB, TD;
        TC = Tq - Tt;
        TE = Tz - Tw;
        TB = W[2];
        TD = W[3];
        rio[(vs[2]) + (rs[1])] = (((TB) * (TC)) + (TD * TE));
        iio[(vs[2]) + (rs[1])] = ((TB * TE) - ((TD) * (TC)));
    }
    {
        E Tu, TA, Tp, Tv;
        Tu = Tq + Tt;
        TA = Tw + Tz;
        Tp = W[0];
        Tv = W[1];
        rio[(vs[1]) + (rs[1])] = (((Tp) * (Tu)) + (Tv * TA));
        iio[(vs[1]) + (rs[1])] = ((Tp * TA) - ((Tv) * (Tu)));
    }
    {
        E TO, TU, TJ, TP;
        TO = TK + TN;
        TU = TQ + TT;
        TJ = W[0];
        TP = W[1];
        rio[(vs[1]) + (rs[2])] = (((TJ) * (TO)) + (TP * TU));
        iio[(vs[1]) + (rs[2])] = ((TJ * TU) - ((TP) * (TO)));
    }
    {
        E Ti, Tk, Th, Tj;
        Ti = T6 - T9;
        Tk = Tf - Tc;
        Th = W[2];
        Tj = W[3];
        rio[(vs[2])] = (((Th) * (Ti)) + (Tj * Tk));
        iio[(vs[2])] = ((Th * Tk) - ((Tj) * (Ti)));
    }
}
}
