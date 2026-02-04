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
for (m = mb , W = W + ((mb - 1) * 10); m < me; m = m + 1 , Rp = Rp + ms , Ip = Ip + ms , Rm = Rm - ms , Im = Im - ms , W = W + 10 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    for (INT inner = 0; inner < 1; inner++) {
        E T3, Ty, Td, TE, Ta, TO, Tr, TB, Tk, TL, Tn, TH;
        {
            E T1, T2, Tb, Tc;
            T1 = Rp[0];
            T2 = Rm[(rs[2])];
            T3 = T1 + T2;
            Ty = T1 - T2;
            Tb = Ip[0];
            Tc = Im[(rs[2])];
            Td = Tb - Tc;
            TE = Tb + Tc;
        }
        {
            E T6, Tz, T9, TA;
            {
                E T4, T5, T7, T8;
                T4 = Rp[(rs[2])];
                T5 = Rm[0];
                T6 = T4 + T5;
                Tz = T4 - T5;
                T7 = Rm[(rs[1])];
                T8 = Rp[(rs[1])];
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
                Te = Ip[(rs[2])];
                Tf = Im[0];
                Tg = Te - Tf;
                TG = Te + Tf;
                Th = Ip[(rs[1])];
                Ti = Im[(rs[1])];
                Tj = Th - Ti;
                TF = Th + Ti;
            }
            Tk = Tg + Tj;
            TL = KP866025403 * (TG + TF);
            Tn = KP866025403 * (Tj - Tg);
            TH = TF - TG;
        }
        Rp[0] = T3 + Ta;
        Rm[0] = Td + Tk;
        {
            E TC, TI, Tx, TD;
            TC = Ty + TB;
            TI = TE - TH;
            Tx = W[4];
            TD = W[5];
            Ip[(rs[1])] = ((Tx * TC) - ((TD) * (TI)));
            Im[(rs[1])] = (((TD) * (TC)) + (Tx * TI));
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
                Rp[(rs[1])] = ((Tl * To) - ((Tp) * (Ts)));
                Rm[(rs[1])] = (((Tl) * (Ts)) + (Tp * To));
                Tt = W[6];
                Tv = W[7];
                Rp[(rs[2])] = ((Tt * Tu) - ((Tv) * (Tw)));
                Rm[(rs[2])] = (((Tt) * (Tw)) + (Tv * Tu));
            }
        }
        {
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
                Ip[0] = ((TJ * TM) - ((TN) * (TQ)));
                Im[0] = (((TN) * (TM)) + (TJ * TQ));
                TR = W[8];
                TT = W[9];
                Ip[(rs[2])] = ((TR * TS) - ((TT) * (TU)));
                Im[(rs[2])] = (((TT) * (TS)) + (TR * TU));
            }
        }
    }
}
}
