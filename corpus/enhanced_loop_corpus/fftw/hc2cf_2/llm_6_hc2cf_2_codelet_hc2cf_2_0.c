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
    // Introduce temporary variables to break WAW and WAR dependencies
    // and reorder operations to change data flow without altering semantics
    E new_Rm0 = T1 - T6;
    E new_Im0 = T7 - T8;
    E new_Rp0 = T1 + T6;
    E new_Ip0 = T7 + T8;

    Rm[0] = new_Rm0;
    Im[0] = new_Im0;
    Rp[0] = new_Rp0;
    Ip[0] = new_Ip0;
}
}
