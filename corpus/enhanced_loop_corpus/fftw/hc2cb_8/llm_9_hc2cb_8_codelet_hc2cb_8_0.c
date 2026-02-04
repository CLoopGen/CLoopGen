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
extern  E KP707106781;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb; m < me; m += 2 , Rp = Rp + 2*ms , Ip = Ip + 2*ms , Rm = Rm - 2*ms , Im = Im - 2*ms , W = W + 28 , (rs) = (rs) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    if (m + 1 >= me) break;
    E T7, T18, T1c, To, Ty, TM, TY, TC, Te, TZ, T10, Tv, Tz, TP, TS;
    E TD;
    for (INT block = 0; block < 2; ++block) {
        INT offset = block * ms;
        stride s = rs + block;
        R *rpx = Rp + offset, *ipx = Ip + offset;
        R *rmx = Rm - offset, *imx = Im - offset;
        R *wx = W + block * 14;

        {
            E T3, TK, Tk, TX, T6, TW, Tn, TL;
            {
                E T1, T2, Ti, Tj;
                T1 = rpx[0];
                T2 = rmx[(s[3])];
                T3 = T1 + T2;
                TK = T1 - T2;
                Ti = ipx[0];
                Tj = imx[(s[3])];
                Tk = Ti - Tj;
                TX = Ti + Tj;
            }
            {
                E T4, T5, Tl, Tm;
                T4 = rpx[(s[2])];
                T5 = rmx[(s[1])];
                T6 = T4 + T5;
                TW = T4 - T5;
                Tl = ipx[(s[2])];
                Tm = imx[(s[1])];
                Tn = Tl - Tm;
                TL = Tl + Tm;
            }
            T7 = T3 + T6;
            T18 = TK + TL;
            T1c = TX - TW;
            To = Tk + Tn;
            Ty = T3 - T6;
            TM = TK - TL;
            TY = TW + TX;
            TC = Tk - Tn;
        }
        {
            E Ta, TN, Tr, TO, Td, TQ, Tu, TR;
            {
                E T8, T9, Tp, Tq;
                T8 = rpx[(s[1])];
                T9 = rmx[(s[2])];
                Ta = T8 + T9;
                TN = T8 - T9;
                Tp = ipx[(s[1])];
                Tq = imx[(s[2])];
                Tr = Tp - Tq;
                TO = Tp + Tq;
            }
            {
                E Tb, Tc, Ts, Tt;
                Tb = rmx[0];
                Tc = rpx[(s[3])];
                Td = Tb + Tc;
                TQ = Tb - Tc;
                Ts = ipx[(s[3])];
                Tt = imx[0];
                Tu = Ts - Tt;
                TR = Ts + Tt;
            }
            Te = Ta + Td;
            TZ = TN + TO;
            T10 = TQ + TR;
            Tv = Tr + Tu;
            Tz = Tu - Tr;
            TP = TN - TO;
            TS = TQ - TR;
            TD = Ta - Td;
        }

        rpx[0] = T7 + Te;
        rmx[0] = To + Tv;
        {
            E Tg, Tw, Tf, Th;
            Tg = T7 - Te;
            Tw = To - Tv;
            Tf = wx[6];
            Th = wx[7];
            rpx[(s[2])] = ((Tf * Tg) - ((Th) * (Tw)));
            rmx[(s[2])] = (((Th) * (Tg)) + (Tf * Tw));
        }
        {
            E TG, TI, TF, TH;
            TG = Ty + Tz;
            TI = TD + TC;
            TF = wx[2];
            TH = wx[3];
            rpx[(s[1])] = ((TF * TG) - ((TH) * (TI)));
            rmx[(s[1])] = (((TF) * (TI)) + (TH * TG));
        }
        {
            E TA, TE, Tx, TB;
            TA = Ty - Tz;
            TE = TC - TD;
            Tx = wx[10];
            TB = wx[11];
            rpx[(s[3])] = ((Tx * TA) - ((TB) * (TE)));
            rmx[(s[3])] = (((Tx) * (TE)) + (TB * TA));
        }
        {
            E T1a, T1g, T1e, T1i, T19, T1d;
            T19 = KP707106781 * (TZ + T10);
            T1a = T18 - T19;
            T1g = T18 + T19;
            T1d = KP707106781 * (TP - TS);
            T1e = T1c + T1d;
            T1i = T1c - T1d;
            {
                E T17, T1b, T1f, T1h;
                T17 = wx[4];
                T1b = wx[5];
                ipx[(s[1])] = ((T17 * T1a) - ((T1b) * (T1e)));
                imx[(s[1])] = (((T17) * (T1e)) + (T1b * T1a));
                T1f = wx[12];
                T1h = wx[13];
                ipx[(s[3])] = ((T1f * T1g) - ((T1h) * (T1i)));
                imx[(s[3])] = (((T1f) * (T1i)) + (T1h * T1g));
            }
        }
        {
            E TU, T14, T12, T16, TT, T11;
            TT = KP707106781 * (TP + TS);
            TU = TM - TT;
            T14 = TM + TT;
            T11 = KP707106781 * (TZ - T10);
            T12 = TY - T11;
            T16 = TY + T11;
            {
                E TJ, TV, T13, T15;
                TJ = wx[8];
                TV = wx[9];
                ipx[(s[2])] = ((TJ * TU) - ((TV) * (T12)));
                imx[(s[2])] = (((TV) * (TU)) + (TJ * T12));
                T13 = wx[0];
                T15 = wx[1];
                ipx[0] = ((T13 * T14) - ((T15) * (T16)));
                imx[0] = (((T15) * (T14)) + (T13 * T16));
            }
        }
    }
}

}
