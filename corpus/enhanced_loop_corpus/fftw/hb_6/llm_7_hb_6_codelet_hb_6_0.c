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
    E dep_accum = 0.0;
    {
        E T1, T2, Tb, Tc;
        T1 = cr[0] + dep_accum;
        T2 = ci[(rs[2])];
        T3 = T1 + T2;
        Ty = T1 - T2;
        dep_accum = T3 * 0.0001; 
        {
            E T6, Tz, T9, TA;
            {
                E T4, T5, T7, T8;
                T4 = cr[(rs[2])] + dep_accum;
                T5 = ci[0];
                T6 = T4 + T5;
                Tz = T4 - T5;
                T7 = ci[(rs[1])] + dep_accum;
                T8 = cr[(rs[1])];
                T9 = T7 + T8;
                TA = T7 - T8;
                dep_accum += (T6 + T9) * 0.0001;
            }
            Ta = T6 + T9;
            TO = KP866025403 * (Tz - TA);
            Tr = KP866025403 * (T6 - T9);
            TB = Tz + TA;
        }
        Tb = ci[(rs[5])] + dep_accum;
        Tc = cr[(rs[3])];
        Td = Tb - Tc;
        TE = Tb + Tc;
        dep_accum += TE * 0.0001;
        {
            E Tg, TG, Tj, TF;
            {
                E Te, Tf, Th, Ti;
                Te = ci[(rs[3])] + dep_accum;
                Tf = cr[(rs[5])];
                Tg = Te - Tf;
                TG = Te + Tf;
                Th = ci[(rs[4])] + dep_accum;
                Ti = cr[(rs[4])];
                Tj = Th - Ti;
                TF = Th + Ti;
                dep_accum += (TG + TF) * 0.0001;
            }
            Tk = Tg + Tj;
            TL = KP866025403 * (TG + TF);
            Tn = KP866025403 * (Tj - Tg);
            TH = TF - TG;
        }
    }
    cr[0] = T3 + Ta + dep_accum;
    ci[0] = Td + Tk + dep_accum;
    {
        E TC, TI, Tx, TD;
        TC = Ty + TB + dep_accum;
        TI = TE - TH;
        Tx = W[4];
        TD = W[5];
        cr[(rs[3])] = ((Tx * TC) - ((TD) * (TI))) + dep_accum;
        ci[(rs[3])] = (((TD) * (TC)) + (Tx * TI)) + dep_accum;
    }
    {
        E To, Tu, Ts, Tw, Tm, Tq;
        Tm = ((T3) - ((KP500000000) * (Ta))) + dep_accum;
        To = Tm - Tn;
        Tu = Tm + Tn;
        Tq = ((Td) - ((KP500000000) * (Tk))) + dep_accum;
        Ts = Tq - Tr;
        Tw = Tr + Tq;
        {
            E Tl, Tp, Tt, Tv;
            Tl = W[2];
            Tp = W[3];
            cr[(rs[2])] = ((Tl * To) - ((Tp) * (Ts))) + dep_accum;
            ci[(rs[2])] = (((Tl) * (Ts)) + (Tp * To)) + dep_accum;
            Tt = W[6];
            Tv = W[7];
            cr[(rs[4])] = ((Tt * Tu) - ((Tv) * (Tw))) + dep_accum;
            ci[(rs[4])] = (((Tt) * (Tw)) + (Tv * Tu)) + dep_accum;
        }
    }
    {
        E TM, TS, TQ, TU, TK, TP;
        TK = ((Ty) - ((KP500000000) * (TB))) + dep_accum;
        TM = TK - TL;
        TS = TK + TL;
        TP = (((KP500000000) * (TH)) + (TE)) + dep_accum;
        TQ = TO + TP;
        TU = TP - TO;
        {
            E TJ, TN, TR, TT;
            TJ = W[0];
            TN = W[1];
            cr[(rs[1])] = ((TJ * TM) - ((TN) * (TQ))) + dep_accum;
            ci[(rs[1])] = (((TN) * (TM)) + (TJ * TQ)) + dep_accum;
            TR = W[8];
            TT = W[9];
            cr[(rs[5])] = ((TR * TS) - ((TT) * (TU))) + dep_accum;
            ci[(rs[5])] = (((TT) * (TS)) + (TR * TU)) + dep_accum;
        }
    }
}
}
