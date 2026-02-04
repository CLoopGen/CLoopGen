#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *ri;
extern R *ii;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP250000000;
extern  E KP559016994;
extern  E KP587785252;
extern  E KP951056516;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + (mb * 8); m < me; m = m + 1 , ri = ri + ms , ii = ii + ms , W = W + 8 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, TE, Tu, Tx, TJ, TI, TB, TC, TD, Tc, Tn, To;
    T1 = ri[0];
    TE = ii[0];
    {
        E T6, Ts, Tm, Tw, Tb, Tt, Th, Tv;
        {
            E T3, T5, T2, T4;
            T3 = ri[(rs[1])];
            T5 = ii[(rs[1])];
            T2 = W[0];
            T4 = W[1];
            T6 = (((T2) * (T3)) + (T4 * T5));
            Ts = ((T2 * T5) - ((T4) * (T3)));
        }
        {
            E Tj, Tl, Ti, Tk;
            Tj = ri[(rs[3])];
            Tl = ii[(rs[3])];
            Ti = W[4];
            Tk = W[5];
            Tm = (((Ti) * (Tj)) + (Tk * Tl));
            Tw = ((Ti * Tl) - ((Tk) * (Tj)));
        }
        {
            E T8, Ta, T7, T9;
            T8 = ri[(rs[4])];
            Ta = ii[(rs[4])];
            T7 = W[6];
            T9 = W[7];
            Tb = (((T7) * (T8)) + (T9 * Ta));
            Tt = ((T7 * Ta) - ((T9) * (T8)));
        }
        {
            E Te, Tg, Td, Tf;
            Te = ri[(rs[2])];
            Tg = ii[(rs[2])];
            Td = W[2];
            Tf = W[3];
            Th = (((Td) * (Te)) + (Tf * Tg));
            Tv = ((Td * Tg) - ((Tf) * (Te)));
        }
        Tu = Ts - Tt;
        Tx = Tv - Tw;
        TJ = Th - Tm;
        TI = T6 - Tb;
        TB = Ts + Tt;
        TC = Tv + Tw;
        TD = TB + TC;
        Tc = T6 + Tb;
        Tn = Th + Tm;
        To = Tc + Tn;
    }
    ri[0] = T1 + To;
    ii[0] = TD + TE;
    {
        E Ty, TA, Tr, Tz, Tp, Tq;
        Ty = (((KP951056516) * (Tu)) + (KP587785252 * Tx));
        TA = ((KP951056516 * Tx) - ((KP587785252) * (Tu)));
        Tp = KP559016994 * (Tc - Tn);
        Tq = ((T1) - ((KP250000000) * (To)));
        Tr = Tp + Tq;
        Tz = Tq - Tp;
        ri[(rs[4])] = Tr - Ty;
        ri[(rs[3])] = Tz + TA;
        ri[(rs[1])] = Tr + Ty;
        ri[(rs[2])] = Tz - TA;
    }
    {
        E TK, TL, TH, TM, TF, TG;
        TK = (((KP951056516) * (TI)) + (KP587785252 * TJ));
        TL = ((KP951056516 * TJ) - ((KP587785252) * (TI)));
        TF = KP559016994 * (TB - TC);
        TG = ((TE) - ((KP250000000) * (TD)));
        TH = TF + TG;
        TM = TG - TF;
        ii[(rs[1])] = TH - TK;
        ii[(rs[3])] = TM - TL;
        ii[(rs[4])] = TK + TH;
        ii[(rs[2])] = TL + TM;
    }
}

}
