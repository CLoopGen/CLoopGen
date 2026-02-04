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
for (m = mb , W = W + ((mb - 1) * 2); m < me; m = m + 2 , Rp = Rp + (ms * 2) , Ip = Ip + (ms * 2) , Rm = Rm - (ms * 2) , Im = Im - (ms * 2) , W = W + 4 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, T8, T6, T7;
    E T9, T16, T14, T15;

    T1 = Rp[0];
    T8 = Rm[0];
    {
        E T3, T5, T2, T4;
        T3 = Ip[0];
        T5 = Im[0];
        T2 = W[0];
        T4 = W[1];
        T6 = (((T2) * (T3)) + (T4 * T5));
        T7 = ((T2 * T5) - ((T4) * (T3)));
    }
    Rm[0] = T1 - T6;
    Im[0] = T7 - T8;
    Rp[0] = T1 + T6;
    Ip[0] = T7 + T8;

    if (m + 1 < me) {
        T9 = Rp[ms];
        T16 = Rm[-ms];
        {
            E T11, T13, T10, T12;
            T11 = Ip[ms];
            T13 = Im[-ms];
            T10 = W[2];
            T12 = W[3];
            T14 = (((T10) * (T11)) + (T12 * T13));
            T15 = ((T10 * T13) - ((T12) * (T11)));
        }
        Rm[-ms] = T9 - T14;
        Im[-ms] = T15 - T16;
        Rp[ms] = T9 + T14;
        Ip[ms] = T15 + T16;
    }
}
}
