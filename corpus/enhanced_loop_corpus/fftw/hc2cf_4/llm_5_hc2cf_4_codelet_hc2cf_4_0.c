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
    E T1, Tp, T6, To, Tc, Tk, Th, Tl;

    T1 = Rp[0];
    Tp = Rm[0];

    if (W[0] >= 0.0) {
        E T3 = Rp[(rs[1])];
        E T5 = Rm[(rs[1])];
        T6 = (W[2] * T3) + (W[3] * T5);
        To = (W[2] * T5) - (W[3] * T3);

        E T9 = Ip[0];
        E Tb = Im[0];
        Tc = (W[0] * T9) + (W[1] * Tb);
        Tk = (W[0] * Tb) - (W[1] * T9);

        E Te = Ip[(rs[1])];
        E Tg = Im[(rs[1])];
        Th = (W[4] * Te) + (W[5] * Tg);
        Tl = (W[4] * Tg) - (W[5] * Te);
    } else {
        E T3 = Rp[(rs[1])];
        E T5 = Rm[(rs[1])];
        T6 = (W[3] * T3) - (W[2] * T5);
        To = (W[3] * T5) + (W[2] * T3);

        E T9 = Ip[0];
        E Tb = Im[0];
        Tc = (W[1] * T9) - (W[0] * Tb);
        Tk = (W[1] * Tb) + (W[0] * T9);

        E Te = Ip[(rs[1])];
        E Tg = Im[(rs[1])];
        Th = (W[5] * Te) - (W[4] * Tg);
        Tl = (W[5] * Tg) + (W[4] * Te);
    }

    {
        E T7 = T1 + T6;
        E Ti = Tc + Th;
        Rm[(rs[1])] = T7 - Ti;
        Rp[0] = T7 + Ti;

        E Tn = Tk + Tl;
        E Tq = To + Tp;
        Im[(rs[1])] = Tn - Tq;
        Ip[0] = Tn + Tq;
    }
    {
        E Tj = T1 - T6;
        E Tm = Tk - Tl;
        Rm[0] = Tj - Tm;
        Rp[(rs[1])] = Tj + Tm;

        E Tr = Th - Tc;
        E Ts = Tp - To;
        Im[0] = Tr - Ts;
        Ip[(rs[1])] = Tr + Ts;
    }
}
}
