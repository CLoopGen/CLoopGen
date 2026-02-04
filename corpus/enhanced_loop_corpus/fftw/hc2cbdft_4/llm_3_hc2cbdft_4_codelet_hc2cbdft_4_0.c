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
    E * restrict rbase_p = Rp;
    E * restrict ibase_p = Ip;
    E * restrict rbase_m = Rm;
    E * restrict ibase_m = Im;
    const E * restrict wbase = W;
    {
        E Tf, Tc, T9, Ti;
        {
            E T1, T2, Ta, Tb;
            T1 = rbase_p[0];
            T2 = rbase_m[rs[1]];
            T3 = T1 + T2;
            Tf = T1 - T2;
            Ta = ibase_p[0];
            Tb = ibase_m[rs[1]];
            Tc = Ta + Tb;
            Tl = Ta - Tb;
        }
        {
            E T4, T5, Tg, Th;
            T4 = rbase_p[rs[1]];
            T5 = rbase_m[0];
            T6 = T4 + T5;
            T9 = T4 - T5;
            Tg = ibase_p[rs[1]];
            Th = ibase_m[0];
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
        T8 = wbase[0];
        Te = wbase[1];
        Tk = (((T8) * (Td)) + (Te * Tj));
        To = ((T8 * Tj) - ((Te) * (Td)));
        rbase_p[0] = T7 - Tk;
        ibase_p[0] = Tn + To;
        rbase_m[0] = T7 + Tk;
        ibase_m[0] = To - Tn;
    }
    {
        E Tt, Tz, Ty, TA;
        {
            E Tp, Tr, Tu, Tw;
            Tp = wbase[2];
            Tr = wbase[3];
            Tt = ((Tp * Tq) - ((Tr) * (Ts)));
            Tz = (((Tr) * (Tq)) + (Tp * Ts));
            Tu = wbase[4];
            Tw = wbase[5];
            Ty = (((Tu) * (Tv)) + (Tw * Tx));
            TA = ((Tu * Tx) - ((Tw) * (Tv)));
        }
        rbase_p[rs[1]] = Tt - Ty;
        ibase_p[rs[1]] = Tz + TA;
        rbase_m[rs[1]] = Tt + Ty;
        ibase_m[rs[1]] = TA - Tz;
    }
}
}
