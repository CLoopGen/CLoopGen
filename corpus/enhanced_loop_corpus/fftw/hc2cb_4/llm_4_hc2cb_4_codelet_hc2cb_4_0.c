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
    E T3, Ti, Tc, Tn, T6, Tm, Tf, Tj;
    E temp_Rp0, temp_Rm1, temp_Ip0, temp_Im1;
    // Introduce local temporaries to break immediate RAW/WAW dependencies
    // and reorder operations with delayed store

    temp_Rp0 = Rp[0];
    temp_Rm1 = Rm[(rs[1])];
    temp_Ip0 = Ip[0];
    temp_Im1 = Im[(rs[1])];

    T3 = temp_Rp0 + temp_Rm1;
    Ti = temp_Rp0 - temp_Rm1;
    Tc = temp_Ip0 - temp_Im1;
    Tn = temp_Ip0 + temp_Im1;

    {
        E T4 = Rp[(rs[1])];
        E T5 = Rm[0];
        T6 = T4 + T5;
        Tm = T4 - T5;
        E Td = Ip[(rs[1])];
        E Te = Im[0];
        Tf = Td - Te;
        Tj = Td + Te;
    }

    // Delayed write to eliminate early WAW on Rp[0] and Rm[0]
    E result_Rp0 = T3 + T6;
    E result_Rm0 = Tc + Tf;

    {
        E T8 = T3 - T6;
        E Tg = Tc - Tf;
        E T7 = W[2];
        E T9 = W[3];
        Rp[(rs[1])] = (T7 * T8) - (T9 * Tg);
        Rm[(rs[1])] = (T9 * T8) + (T7 * Tg);
    }
    Rp[0] = result_Rp0;
    Rm[0] = result_Rm0;

    {
        E Tk = Ti - Tj;
        E To = Tm + Tn;
        E Th = W[0];
        E Tl = W[1];
        Ip[0] = (Th * Tk) - (Tl * To);
        Im[0] = (Th * To) + (Tl * Tk);
    }
    {
        E Tq = Ti + Tj;
        E Ts = Tn - Tm;
        E Tp = W[4];
        E Tr = W[5];
        Ip[(rs[1])] = (Tp * Tq) - (Tr * Ts);
        Im[(rs[1])] = (Tp * Ts) + (Tr * Tq);
    }
}
}
