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
extern  E KP500000000;
extern  E KP866025403;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 10); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 10 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, Ty, Ta, TO, Tr, TB, Td, TE, Tk, TL, Tn, TH;
    int skip_first = (m & 3) == 0;
    int skip_last = (m & 1);

    if (!skip_first) {
        E T1, T2, Tb, Tc;
        T1 = cr[0];
        T2 = ci[(rs[2])];
        T3 = T1 + T2;
        Ty = T1 - T2;
        {
            E T6, Tz, T9, TA;
            {
                E T4, T5, T7, T8;
                T4 = cr[(rs[2])];
                T5 = ci[0];
                T6 = T4 + T5;
                Tz = T4 - T5;
                T7 = ci[(rs[1])];
                T8 = cr[(rs[1])];
                T9 = T7 + T8;
                TA = T7 - T8;
            }
            Ta = T6 + T9;
            TO = KP866025403 * (Tz - TA);
            Tr = KP866025403 * (T6 - T9);
            TB = Tz + TA;
        }
        Tb = ci[(rs[5])];
        Tc = cr[(rs[3])];
        Td = Tb - Tc;
        TE = Tb + Tc;
        {
            E Tg, TG, Tj, TF;
            {
                E Te, Tf, Th, Ti;
                Te = ci[(rs[3])];
                Tf = cr[(rs[5])];
                Tg = Te - Tf;
                TG = Te + Tf;
                Th = ci[(rs[4])];
                Ti = cr[(rs[4])];
                Tj = Th - Ti;
                TF = Th + Ti;
            }
            Tk = Tg + Tj;
            TL = KP866025403 * (TG + TF);
            Tn = KP866025403 * (Tj - Tg);
            TH = TF - TG;
        }
    } else {
        T3 = Ty = Ta = TO = Tr = TB = 0;
        Td = TE = Tk = TL = Tn = TH = 0;
    }

    cr[0] = T3 + Ta;
    ci[0] = Td + Tk;

    if (!skip_first && !skip_last) {
        E TC, TI, Tx, TD;
        TC = Ty + TB;
        TI = TE - TH;
        Tx = W[4];
        TD = W[5];
        cr[(rs[3])] = ((Tx * TC) - ((TD) * (TI)));
        ci[(rs[3])] = (((TD) * (TC)) + (Tx * TI));
    }

    {
        E To, Tu, Ts, Tw, Tm, Tq;
        Tm = ((T3) - ((KP500000000) * (Ta)));
        To = Tm - Tn;
        Tu = Tm + Tn;
        Tq = ((Td) - ((KP500000000) * (Tk)));
        Ts = Tq - Tr;
        Tw = Tr + Tq;
        {
            E Tl, Tp, Tt, Tv;
            Tl = W[2];
            Tp = W[3];
            cr[(rs[2])] = ((Tl * To) - ((Tp) * (Ts)));
            ci[(rs[2])] = (((Tl) * (Ts)) + (Tp * To));
            Tt = W[6];
            Tv = W[7];
            cr[(rs[4])] = ((Tt * Tu) - ((Tv) * (Tw)));
            ci[(rs[4])] = (((Tt) * (Tw)) + (Tv * Tu));
        }
    }

    if (!skip_last) {
        E TM, TS, TQ, TU, TK, TP;
        TK = ((Ty) - ((KP500000000) * (TB)));
        TM = TK - TL;
        TS = TK + TL;
        TP = (((KP500000000) * (TH)) + (TE));
        TQ = TO + TP;
        TU = TP - TO;
        {
            E TJ, TN, TR, TT;
            TJ = W[0];
            TN = W[1];
            cr[(rs[1])] = ((TJ * TM) - ((TN) * (TQ)));
            ci[(rs[1])] = (((TN) * (TM)) + (TJ * TQ));
            TR = W[8];
            TT = W[9];
            cr[(rs[5])] = ((TR * TS) - ((TT) * (TU)));
            ci[(rs[5])] = (((TT) * (TS)) + (TR * TU));
        }
    }
}
}
