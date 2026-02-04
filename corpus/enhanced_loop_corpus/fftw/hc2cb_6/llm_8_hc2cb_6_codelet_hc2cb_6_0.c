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
for (m = mb , W = W + ((mb - 1) * 10); m < me; m = m + 2 , Rp = Rp + (ms * 2) , Ip = Ip + (ms * 2) , Rm = Rm - (ms * 2) , Im = Im - (ms * 2) , W = W + 20 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, Ty, Td, TE, Ta, TO, Tr, TB, Tk, TL, Tn, TH;
    E T3b, Tyb, Tdb, TEb, Tab, TOb, Trb, TBb, Tkb, TLb, Tnb, THb;

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

    if (m + 1 < me) {
        {
            E T1, T2, Tb, Tc;
            T1 = Rp[ms];
            T2 = Rm[(rs[2])];
            T3b = T1 + T2;
            Tyb = T1 - T2;
            Tb = Ip[ms];
            Tc = Im[(rs[2])];
            Tdb = Tb - Tc;
            TEb = Tb + Tc;
        }
        {
            E T6, Tz, T9, TA;
            {
                E T4, T5, T7, T8;
                T4 = Rp[ms + (rs[2])];
                T5 = Rm[0];
                T6 = T4 + T5;
                Tz = T4 - T5;
                T7 = Rm[(rs[1])];
                T8 = Rp[ms + (rs[1])];
                T9 = T7 + T8;
                TA = T7 - T8;
            }
            Tab = T6 + T9;
            TOb = KP866025403 * (Tz - TA);
            Trb = KP866025403 * (T6 - T9);
            TBb = Tz + TA;
        }
        {
            E Tg, TG, Tj, TF;
            {
                E Te, Tf, Th, Ti;
                Te = Ip[ms + (rs[2])];
                Tf = Im[0];
                Tg = Te - Tf;
                TG = Te + Tf;
                Th = Ip[ms + (rs[1])];
                Ti = Im[(rs[1])];
                Tj = Th - Ti;
                TF = Th + Ti;
            }
            Tkb = Tg + Tj;
            TLb = KP866025403 * (TG + TF);
            Tnb = KP866025403 * (Tj - Tg);
            THb = TF - TG;
        }

        Rp[ms] = T3b + Tab;
        Rm[0] = Tdb + Tkb;
        {
            E TC, TI, Tx, TD;
            TC = Tyb + TBb;
            TI = TEb - THb;
            Tx = W[14];
            TD = W[15];
            Ip[ms + (rs[1])] = ((Tx * TC) - ((TD) * (TI)));
            Im[ms + (rs[1])] = (((TD) * (TC)) + (Tx * TI));
        }
        {
            E Tob, Tub, Tsb, Twb, Tmb, Tqb;
            Tmb = ((T3b) - ((KP500000000) * (Tab)));
            Tob = Tmb - Tnb;
            Tub = Tmb + Tnb;
            Tqb = ((Tdb) - ((KP500000000) * (Tkb)));
            Tsb = Tqb - Trb;
            Twb = Trb + Tqb;
            {
                E Tl, Tp, Tt, Tv;
                Tl = W[12];
                Tp = W[13];
                Rp[ms + (rs[1])] = ((Tl * Tob) - ((Tp) * (Tsb)));
                Rm[ms + (rs[1])] = (((Tl) * (Tsb)) + (Tp * Tob));
                Tt = W[16];
                Tv = W[17];
                Rp[ms + (rs[2])] = ((Tt * Tub) - ((Tv) * (Twb)));
                Rm[ms + (rs[2])] = (((Tt) * (Twb)) + (Tv * Tub));
            }
        }
        {
            E TMb, TSb, TQb, TUb, TKb, TPb;
            TKb = ((Tyb) - ((KP500000000) * (TBb)));
            TMb = TKb - TLb;
            TSb = TKb + TLb;
            TPb = (((KP500000000) * (THb)) + (TEb));
            TQb = TOb + TPb;
            TUb = TPb - TOb;
            {
                E TJ, TN, TR, TT;
                TJ = W[10];
                TN = W[11];
                Ip[ms] = ((TJ * TMb) - ((TN) * (TQb)));
                Im[ms] = (((TN) * (TMb)) + (TJ * TQb));
                TR = W[18];
                TT = W[19];
                Ip[ms + (rs[2])] = ((TR * TSb) - ((TT) * (TUb)));
                Im[ms + (rs[2])] = (((TT) * (TSb)) + (TR * TUb));
            }
        }
    }
}
}
