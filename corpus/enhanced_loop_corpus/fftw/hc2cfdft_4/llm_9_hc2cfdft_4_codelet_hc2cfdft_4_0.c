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
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb; m < me; m += 2 , Rp = Rp + 2*ms , Ip = Ip + 2*ms , Rm = Rm - 2*ms , Im = Im - 2*ms , W = W + 12 , (rs) = (rs) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    if (m + 1 >= me) break;

    // First iteration (m)
    {
        E Tc, Tr, Tk, Tx, T9, Ts, Tp, Tw;
        E Ta = Ip[0], Tb = Im[0];
        E Tj = Ta + Tb;
        E Tf = Rm[0], Tg = Rp[0], Th = Tf - Tg;
        Tc = Ta - Tb;
        Tr = Tg + Tf;
        E Te = W[0], Ti = W[1];
        Tk = Te * Th - Ti * Tj;
        Tx = Ti * Th + Te * Tj;

        E T4 = Ip[rs[1]] - Im[rs[1]];
        E To = Ip[rs[1]] + Im[rs[1]];
        E T8 = Rp[rs[1]] + Rm[rs[1]];
        E Tm = Rp[rs[1]] - Rm[rs[1]];

        E T1 = W[2], T5 = W[3];
        T9 = T1 * T4 - T5 * T8;
        Ts = T1 * T8 + T5 * T4;
        E Tl = W[4], Tn = W[5];
        Tp = Tl * Tm + Tn * To;
        Tw = Tl * To - Tn * Tm;

        E Td = T9 + Tc, Tq = Tk - Tp;
        Ip[0] = KP500000000 * (Td + Tq);
        Im[rs[1]] = KP500000000 * (Tq - Td);
        E Tz = Tr + Ts, TA = Tw + Tx;
        Rm[rs[1]] = KP500000000 * (Tz - TA);
        Rp[0] = KP500000000 * (Tz + TA);

        E Tt = Tr - Ts, Tu = Tp + Tk;
        Rm[0] = KP500000000 * (Tt - Tu);
        Rp[rs[1]] = KP500000000 * (Tt + Tu);
        E Tv = Tc - T9, Ty = Tw - Tx;
        Ip[rs[1]] = KP500000000 * (Tv + Ty);
        Im[0] = KP500000000 * (Ty - Tv);
    }

    // Second iteration (m+1), offset by stride
    {
        E Tc, Tr, Tk, Tx, T9, Ts, Tp, Tw;
        E *Ip1 = Ip + ms, *Im1 = Im - ms, *Rp1 = Rp + ms, *Rm1 = Rm - ms;
        E *W1 = W + 6;

        E Ta = Ip1[0], Tb = Im1[0];
        E Tj = Ta + Tb;
        E Tf = Rm1[0], Tg = Rp1[0], Th = Tf - Tg;
        Tc = Ta - Tb;
        Tr = Tg + Tf;
        E Te = W1[0], Ti = W1[1];
        Tk = Te * Th - Ti * Tj;
        Tx = Ti * Th + Te * Tj;

        E T4 = Ip1[rs[1]] - Im1[rs[1]];
        E To = Ip1[rs[1]] + Im1[rs[1]];
        E T8 = Rp1[rs[1]] + Rm1[rs[1]];
        E Tm = Rp1[rs[1]] - Rm1[rs[1]];

        E T1 = W1[2], T5 = W1[3];
        T9 = T1 * T4 - T5 * T8;
        Ts = T1 * T8 + T5 * T4;
        E Tl = W1[4], Tn = W1[5];
        Tp = Tl * Tm + Tn * To;
        Tw = Tl * To - Tn * Tm;

        E Td = T9 + Tc, Tq = Tk - Tp;
        Ip1[0] = KP500000000 * (Td + Tq);
        Im1[rs[1]] = KP500000000 * (Tq - Td);
        E Tz = Tr + Ts, TA = Tw + Tx;
        Rm1[rs[1]] = KP500000000 * (Tz - TA);
        Rp1[0] = KP500000000 * (Tz + TA);

        E Tt = Tr - Ts, Tu = Tp + Tk;
        Rm1[0] = KP500000000 * (Tt - Tu);
        Rp1[rs[1]] = KP500000000 * (Tt + Tu);
        E Tv = Tc - T9, Ty = Tw - Tx;
        Ip1[rs[1]] = KP500000000 * (Tv + Ty);
        Im1[0] = KP500000000 * (Ty - Tv);
    }
}

}
