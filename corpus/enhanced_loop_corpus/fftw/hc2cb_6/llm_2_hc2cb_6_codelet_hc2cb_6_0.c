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
    E T3, Ty, Td, TE, Ta, TO, Tr, TB, Tk, TL, Tn, TH;
    const INT rs0 = rs[0], rs1 = rs[1], rs2 = rs[2];
    E * restrict rbase_p = Rp;
    E * restrict ibase_p = Ip;
    E * restrict rbase_m = Rm;
    E * restrict ibase_m = Im;
    E * restrict wbase = W;

    {
        E T1, T2, Tb, Tc;
        T1 = rbase_p[0];
        T2 = rbase_m[rs2];
        T3 = T1 + T2;
        Ty = T1 - T2;
        Tb = ibase_p[0];
        Tc = ibase_m[rs2];
        Td = Tb - Tc;
        TE = Tb + Tc;
    }
    {
        E T6, Tz, T9, TA;
        {
            E T4, T5, T7, T8;
            T4 = rbase_p[rs2];
            T5 = rbase_m[0];
            T6 = T4 + T5;
            Tz = T4 - T5;
            T7 = rbase_m[rs1];
            T8 = rbase_p[rs1];
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
            Te = ibase_p[rs2];
            Tf = ibase_m[0];
            Tg = Te - Tf;
            TG = Te + Tf;
            Th = ibase_p[rs1];
            Ti = ibase_m[rs1];
            Tj = Th - Ti;
            TF = Th + Ti;
        }
        Tk = Tg + Tj;
        TL = KP866025403 * (TG + TF);
        Tn = KP866025403 * (Tj - Tg);
        TH = TF - TG;
    }
    rbase_p[0] = T3 + Ta;
    rbase_m[0] = Td + Tk;
    {
        E TC, TI, Tx, TD;
        TC = Ty + TB;
        TI = TE - TH;
        Tx = wbase[4];
        TD = wbase[5];
        ibase_p[rs1] = ((Tx * TC) - ((TD) * (TI)));
        ibase_m[rs1] = (((TD) * (TC)) + (Tx * TI));
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
            Tl = wbase[2];
            Tp = wbase[3];
            rbase_p[rs1] = ((Tl * To) - ((Tp) * (Ts)));
            rbase_m[rs1] = (((Tl) * (Ts)) + (Tp * To));
            Tt = wbase[6];
            Tv = wbase[7];
            rbase_p[rs2] = ((Tt * Tu) - ((Tv) * (Tw)));
            rbase_m[rs2] = (((Tt) * (Tw)) + (Tv * Tu));
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
            TJ = wbase[0];
            TN = wbase[1];
            ibase_p[0] = ((TJ * TM) - ((TN) * (TQ)));
            ibase_m[0] = (((TN) * (TM)) + (TJ * TQ));
            TR = wbase[8];
            TT = wbase[9];
            ibase_p[rs2] = ((TR * TS) - ((TT) * (TU)));
            ibase_m[rs2] = (((TT) * (TS)) + (TR * TU));
        }
    }
}
}
