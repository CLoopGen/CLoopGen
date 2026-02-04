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
const INT stride_factor = 2;
for (m = mb , W = W + ((mb - 1) * 2); m < me; m = m + stride_factor , Rp = Rp + (ms * stride_factor) , Ip = Ip + (ms * stride_factor) , Rm = Rm - (ms * stride_factor) , Im = Im - (ms * stride_factor) , W = W + (2 * stride_factor) , (rs) = (rs) + (fftw_an_INT_guaranteed_to_be_zero * stride_factor)) {
    if (m + 1 >= me) break;
    E T3, T9, T7, Tb;
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
        E T3n, T9n, T7n, Tbn;
        E T1n, T2n, T5n, T6n;
        T1n = Ip[ms];
        T2n = Im[-ms];
        T3n = T1n - T2n;
        T9n = T1n + T2n;
        T5n = Rm[-ms];
        T6n = Rp[ms];
        T7n = T5n - T6n;
        Tbn = T6n + T5n;

        E Tan, Tcn, T4n, T8n;
        T4n = W[2];
        T8n = W[3];
        Tan = ((T4n * T7n) - (T8n * T9n));
        Tcn = (T8n * T7n) + (T4n * T9n);

        Ip[ms] = KP500000000 * (T3n + Tan);
        Rp[ms] = KP500000000 * (Tbn + Tcn);
        Im[-ms] = KP500000000 * (Tan - T3n);
        Rm[-ms] = KP500000000 * (Tbn - Tcn);
    }
}
}
