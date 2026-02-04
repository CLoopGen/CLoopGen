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
for (m = mb , W = W + ((mb - 1) * 2); m < me; m = m + 1 , Rp = Rp + ms , Ip = Ip + ms , Rm = Rm - ms , Im = Im - ms , W = W + 2 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, T9, T7, Tb;
    {
        E T1, T2, T5, T6;
        T1 = Ip[0];
        T2 = Im[0];
        T3 = T1 - T2;
        T9 = T1 + T2;
        T5 = Rp[0];
        T6 = Rm[0];
        T7 = T5 - T6;
        Tb = T5 + T6;
    }
    {
        E Ta, Tc, T4, T8;
        T4 = W[0];
        T8 = W[1];
        Ta = ((T4 * T7) - ((T8) * (T9)));
        Tc = (((T8) * (T7)) + (T4 * T9));
        Ip[0] = T3 + Ta;
        Rp[0] = Tb - Tc;
        Im[0] = Ta - T3;
        Rm[0] = Tb + Tc;
    }
}

}
