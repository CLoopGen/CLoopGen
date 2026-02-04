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
for (m = mb , W = W + ((mb - 1) * 2); m < me; m = m + 2 , Rp = Rp + 2*ms , Ip = Ip + 2*ms , Rm = Rm - 2*ms , Im = Im - 2*ms , W = W + 4 , (rs) = (rs) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    if (m + 1 >= me) break;
    E T3, T9, T7, Tb;
    E T3b, T9b, T7b, Tbb;
    {
        E T1, T2, T5, T6;
        T1 = Ip[0];
        T2 = Im[0];
        T3 = T1 - T2;
        T9 = T1 + T2;
        T5 = Rm[0];
        T6 = Rp[0];
        T7 = T5 - T6;
        Tb = T6 + T5;
    }
    {
        E Ta, Tc, T4, T8;
        T4 = W[0];
        T8 = W[1];
        Ta = ((T4 * T7) - ((T8) * (T9)));
        Tc = (((T8) * (T7)) + (T4 * T9));
        Ip[0] = KP500000000 * (T3 + Ta);
        Rp[0] = KP500000000 * (Tb + Tc);
        Im[0] = KP500000000 * (Ta - T3);
        Rm[0] = KP500000000 * (Tb - Tc);
    }
    {
        E T1b, T2b, T5b, T6b;
        T1b = Ip[ms];
        T2b = Im[-ms];
        T3b = T1b - T2b;
        T9b = T1b + T2b;
        T5b = Rm[-ms];
        T6b = Rp[ms];
        T7b = T5b - T6b;
        Tbb = T6b + T5b;
    }
    {
        E Tab, Tcb, T4b, T8b;
        T4b = W[2];
        T8b = W[3];
        Tab = ((T4b * T7b) - ((T8b) * (T9b)));
        Tcb = (((T8b) * (T7b)) + (T4b * T9b));
        Ip[ms] = KP500000000 * (T3b + Tab);
        Rp[ms] = KP500000000 * (Tbb + Tcb);
        Im[-ms] = KP500000000 * (Tab - T3b);
        Rm[-ms] = KP500000000 * (Tbb - Tcb);
    }
}
}
