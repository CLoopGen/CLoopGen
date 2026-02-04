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
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 6); m < me; m = m + 1 , Rp = Rp + ms , Ip = Ip + ms , Rm = Rm - ms , Im = Im - ms , W = W + 6 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, Tl, T6, Tm, Td, Tj, Tx, Tv, Ts, Tq;
    INT idx1 = 0;
    INT idx2 = rs[1];
    {
        E Tf, Tc, T9, Ti;
        {
            E T1, T2, Ta, Tb;
            T1 = Rp[idx1];
            T2 = Rm[idx2];
            T3 = T1 + T2;
            Tf = T1 - T2;
            Ta = Ip[idx1];
            Tb = Im[idx2];
            Tc = Ta + Tb;
            Tl = Ta - Tb;
        }
        {
            E T4, T5, Tg, Th;
            T4 = Rp[idx2];
            T5 = Rm[idx1];
            T6 = T4 + T5;
            T9 = T4 - T5;
            Tg = Ip[idx2];
            Th = Im[idx1];
            Ti = Tg + Th;
            Tm = Tg - Th;
        }
        Td = T9 + Tc;
        Tj = Tf - Ti;
        Tx = Tf + Ti;
        Tv = Tc - T9;
        Ts = Tl - Tm;
        Tq = T3 - T6;
    }
    {
        E T7, Tn, Tk, To, T8, Te;
        T7 = T3 + T6;
        Tn = Tl + Tm;
        T8 = W[0];
        Te = W[1];
        Tk = (((T8) * (Td)) + (Te * Tj));
        To = ((T8 * Tj) - ((Te) * (Td)));
        Rp[idx1] = T7 - Tk;
        Ip[idx1] = Tn + To;
        Rm[idx1] = T7 + Tk;
        Im[idx1] = To - Tn;
    }
    {
        E Tt, Tz, Ty, TA;
        {
            E Tp, Tr, Tu, Tw;
            Tp = W[2];
            Tr = W[3];
            Tt = ((Tp * Tq) - ((Tr) * (Ts)));
            Tz = (((Tr) * (Tq)) + (Tp * Ts));
            Tu = W[4];
            Tw = W[5];
            Ty = (((Tu) * (Tv)) + (Tw * Tx));
            TA = ((Tu * Tx) - ((Tw) * (Tv)));
        }
        Rp[idx2] = Tt - Ty;
        Ip[idx2] = Tz + TA;
        Rm[idx2] = Tt + Ty;
        Im[idx2] = TA - Tz;
    }
}
}
