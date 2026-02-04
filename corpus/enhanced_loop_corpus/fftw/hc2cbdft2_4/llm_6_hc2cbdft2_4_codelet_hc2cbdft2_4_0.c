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
    E temp_Rp0, temp_Rm1, temp_Ip0, temp_Im1;
    {
        E Tf, Tc, T9, Ti;
        {
            E T1, T2, Ta, Tb;
            T1 = Rp[0];
            T2 = Rm[(rs[1])];
            temp_Rp0 = T1; // Introduce temporary to modify RAW dependency
            temp_Rm1 = T2;
            T3 = T1 + T2;
            Tf = T1 - T2;
            Ta = Ip[0];
            Tb = Im[(rs[1])];
            temp_Ip0 = Ta;
            temp_Im1 = Tb;
            Tc = Ta + Tb;
            Tl = Ta - Tb;
        }
        {
            E T4, T5, Tg, Th;
            T4 = Rp[(rs[1])];
            T5 = Rm[0];
            T6 = T4 + T5;
            T9 = T4 - T5;
            Tg = Ip[(rs[1])];
            Th = Im[0];
            Ti = Tg + Th;
            Tm = Tg - Th;
        }
        Td = T9 + Tc;
        Tj = Tf - Ti;
        Tx = Tf + Ti;
        Tv = Tc - T9;
        Ts = Tl - Tm;
        Tq = temp_Rp0 - T6; // Reuse temp_Rp0: introduces artificial RAW delay
    }
    {
        E T7, Tn, Tk, To, T8, Te;
        T7 = T3 + T6;
        Tn = Tl + Tm;
        T8 = W[0];
        Te = W[1];
        Tk = (((T8) * (Td)) + (Te * Tj));
        To = ((T8 * Tj) - ((Te) * (Td)));
        Rp[0] = T7 - Tk;
        Ip[0] = Tn + To;
        Rm[0] = T7 + Tk;
        Im[0] = To - Tn;
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
        Rp[(rs[1])] = Tt - Ty;
        Ip[(rs[1])] = Tz + TA;
        Rm[(rs[1])] = Tt + Ty;
        Im[(rs[1])] = TA - Tz;
    }
}

}
