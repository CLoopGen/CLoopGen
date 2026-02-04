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
    E T4, Tv, Tr, TL, Tb, Tc, Ty, TP, To, TB, Tj, TQ, Tp, Tq, TE;
    E TM;
    for (INT inner = 0; inner < 1; inner++) {
        {
            E Ta, Tx, T7, Tw, T2, T3;
            T2 = Rp[0];
            T3 = Rm[(rs[2])];
            T4 = T2 + T3;
            Tv = T2 - T3;
            {
                E T8, T9, T5, T6;
                T8 = Rm[(rs[1])];
                T9 = Rp[(rs[1])];
                Ta = T8 + T9;
                Tx = T8 - T9;
                T5 = Rp[(rs[2])];
                T6 = Rm[0];
                T7 = T5 + T6;
                Tw = T5 - T6;
            }
            Tr = KP866025403 * (T7 - Ta);
            TL = KP866025403 * (Tw - Tx);
            Tb = T7 + Ta;
            Tc = ((T4) - ((KP500000000) * (Tb)));
            Ty = Tw + Tx;
            TP = ((Tv) - ((KP500000000) * (Ty)));
        }
        {
            E Tf, TC, Ti, TD, Td, Te;
            Td = Ip[(rs[1])];
            Te = Im[(rs[1])];
            Tf = Td - Te;
            TC = Te + Td;
            {
                E Tm, Tn, Tg, Th;
                Tm = Ip[0];
                Tn = Im[(rs[2])];
                To = Tm - Tn;
                TB = Tm + Tn;
                Tg = Ip[(rs[2])];
                Th = Im[0];
                Ti = Tg - Th;
                TD = Tg + Th;
            }
            Tj = KP866025403 * (Tf - Ti);
            TQ = KP866025403 * (TC + TD);
            Tp = Tf + Ti;
            Tq = ((To) - ((KP500000000) * (Tp)));
            TE = TC - TD;
            TM = (((KP500000000) * (TE)) + (TB));
        }
        {
            E TJ, TT, TS, TU;
            TJ = T4 + Tb;
            TT = To + Tp;
            {
                E TN, TR, TK, TO;
                TN = TL + TM;
                TR = TP - TQ;
                TK = W[0];
                TO = W[1];
                TS = (((TK) * (TN)) + (TO * TR));
                TU = ((TK * TR) - ((TO) * (TN)));
            }
            Rp[0] = TJ - TS;
            Ip[0] = TT + TU;
            Rm[0] = TJ + TS;
            Im[0] = TU - TT;
        }
        {
            E TZ, T15, T14, T16;
            {
                E TW, TY, TV, TX;
                TW = Tc + Tj;
                TY = Tr + Tq;
                TV = W[6];
                TX = W[7];
                TZ = ((TV * TW) - ((TX) * (TY)));
                T15 = (((TX) * (TW)) + (TV * TY));
            }
            {
                E T11, T13, T10, T12;
                T11 = TM - TL;
                T13 = TP + TQ;
                T10 = W[8];
                T12 = W[9];
                T14 = (((T10) * (T11)) + (T12 * T13));
                T16 = ((T10 * T13) - ((T12) * (T11)));
            }
            Rp[(rs[2])] = TZ - T14;
            Ip[(rs[2])] = T15 + T16;
            Rm[(rs[2])] = TZ + T14;
            Im[(rs[2])] = T16 - T15;
        }
        {
            E Tt, TH, TG, TI;
            {
                E Tk, Ts, T1, Tl;
                Tk = Tc - Tj;
                Ts = Tq - Tr;
                T1 = W[3];
                Tl = W[2];
                Tt = (((T1) * (Tk)) + (Tl * Ts));
                TH = ((Tl * Tk) - ((T1) * (Ts)));
            }
            {
                E Tz, TF, Tu, TA;
                Tz = Tv + Ty;
                TF = TB - TE;
                Tu = W[4];
                TA = W[5];
                TG = ((Tu * Tz) - ((TA) * (TF)));
                TI = (((TA) * (Tz)) + (Tu * TF));
            }
            Ip[(rs[1])] = Tt + TG;
            Rp[(rs[1])] = TH - TI;
            Im[(rs[1])] = TG - Tt;
            Rm[(rs[1])] = TH + TI;
        }
    }
}
}
