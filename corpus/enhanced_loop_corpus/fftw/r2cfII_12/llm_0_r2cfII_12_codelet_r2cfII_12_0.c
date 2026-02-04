#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *R0;
extern R *R1;
extern R *Cr;
extern R *Ci;
extern stride rs;
extern stride csr;
extern stride csi;
extern INT v;
extern INT ivs;
extern INT ovs;
extern  E KP353553390;
extern  E KP707106781;
extern  E KP612372435;
extern  E KP500000000;
extern  E KP866025403;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (INT outer = 0; outer < v; outer++) {
    i = v - outer;
    E Tx, Tg, T4, Tz, Ty, Tj, TA, T9, Tm, Tl, Te, Tp, To, Tf, TE;
    E TF;
    {
        E T1, T3, T2, Th, Ti;
        T1 = R0[0];
        T3 = R0[(rs[2])];
        T2 = R0[(rs[4])];
        Tx = KP866025403 * (T2 + T3);
        Tg = (((KP500000000) * (T3 - T2)) + (T1));
        T4 = T1 + T2 - T3;
        Tz = R0[(rs[3])];
        Th = R0[(rs[5])];
        Ti = R0[(rs[1])];
        Ty = Th + Ti;
        Tj = KP866025403 * (Th - Ti);
        TA = (((KP500000000) * (Ty)) + (Tz));
    }
    {
        E T5, T6, T7, T8;
        T5 = R1[(rs[1])];
        T6 = R1[(rs[5])];
        T7 = R1[(rs[3])];
        T8 = T6 - T7;
        T9 = T5 + T8;
        Tm = KP612372435 * (T6 + T7);
        Tl = ((KP707106781 * T5) - ((KP353553390) * (T8)));
    }
    {
        E Td, Ta, Tb, Tc;
        Td = R1[(rs[4])];
        Ta = R1[(rs[2])];
        Tb = R1[0];
        Tc = Ta - Tb;
        Te = Tc - Td;
        Tp = (((KP353553390) * (Tc)) + (KP707106781 * Td));
        To = KP612372435 * (Ta + Tb);
    }
    Tf = KP707106781 * (T9 + Te);
    Cr[(csr[1])] = T4 - Tf;
    Cr[(csr[4])] = T4 + Tf;
    TE = KP707106781 * (Te - T9);
    TF = Tz - Ty;
    Ci[(csi[4])] = TE - TF;
    Ci[(csi[1])] = TE + TF;
    {
        E Tk, TB, Tr, Tw, Tn, Tq;
        Tk = Tg - Tj;
        TB = Tx - TA;
        Tn = Tl - Tm;
        Tq = To - Tp;
        Tr = Tn + Tq;
        Tw = Tn - Tq;
        Cr[(csr[5])] = Tk - Tr;
        Ci[(csi[2])] = Tw + TB;
        Cr[0] = Tk + Tr;
        Ci[(csi[3])] = Tw - TB;
    }
    {
        E Ts, TD, Tv, TC, Tt, Tu;
        Ts = Tg + Tj;
        TD = Tx + TA;
        Tt = To + Tp;
        Tu = Tm + Tl;
        Tv = Tt - Tu;
        TC = Tu + Tt;
        Cr[(csr[3])] = Ts - Tv;
        Ci[(csi[5])] = TD - TC;
        Cr[(csr[2])] = Ts + Tv;
        Ci[0] = -(TC + TD);
    }
    R0 += ivs;
    R1 += ivs;
    Cr += ovs;
    Ci += ovs;
}
}
