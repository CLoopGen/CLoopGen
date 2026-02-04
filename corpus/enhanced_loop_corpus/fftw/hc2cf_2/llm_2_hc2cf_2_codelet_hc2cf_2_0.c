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
    E T1, T8, T6, T7;
    INT idx_Rp = 0;
    INT idx_Ip = 0;
    INT idx_Rm = 0;
    INT idx_Im = 0;
    T1 = Rp[idx_Rp];
    T8 = Rm[idx_Rm];
    {
        E T3, T5, T2, T4;
        T3 = Ip[idx_Ip];
        T5 = Im[idx_Im];
        T2 = W[0];
        T4 = W[1];
        T6 = (((T2) * (T3)) + (T4 * T5));
        T7 = ((T2 * T5) - ((T4) * (T3)));
    }
    Rm[idx_Rm] = T1 - T6;
    Im[idx_Im] = T7 - T8;
    Rp[idx_Rp] = T1 + T6;
    Ip[idx_Ip] = T7 + T8;
}
}
