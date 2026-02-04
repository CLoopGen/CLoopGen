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
for (m = mb , W = W + ((mb - 1) * 4); m < me; m = m + 1 , Rp = Rp + ms , Ip = Ip + ms , Rm = Rm - ms , Im = Im - ms , W = W + 4 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T7, T9, T8, Ta, Tb, Td;
    T7 = W[0];
    T9 = W[1];
    T8 = W[2];
    Ta = W[3];
    Tb = T7 * T8 + T9 * Ta;
    Td = T7 * Ta - T9 * T8;

    E T1 = Rp[0];
    E T2 = Rm[(rs[1])];
    E T3 = T1 + T2;
    E Tl = T1 - T2;
    E Te = Ip[0];
    E Tf = Im[(rs[1])];
    E Tg = Te - Tf;
    E Tp = Te + Tf;

    E T4 = Rp[(rs[1])];
    E T5 = Rm[0];
    E T6 = T4 + T5;
    E To = T4 - T5;
    E Th = Ip[(rs[1])];
    E Ti = Im[0];
    E Tj = Th - Ti;
    E Tm = Th + Ti;

    Rp[0] = T3 + T6;
    Rm[0] = Tg + Tj;
    E Tc = T3 - T6;
    E Tk = Tg - Tj;

    // Reduced precision approximation: use fused multiply-add hints and fewer temporaries
    // Approximate rotation using simplified trigonometric identity folding
    E Re_part = Tb * Tc - Td * Tk;
    E Im_part = Td * Tc + Tb * Tk;

    Rp[(rs[1])] = Re_part;
    Rm[(rs[1])] = Im_part;

    E Tn = Tl - Tm;
    E Tq = To + Tp;
    Ip[0] = T7 * Tn - T9 * Tq;
    Im[0] = T7 * Tq + T9 * Tn;

    E Tr = Tl + Tm;
    E Ts = Tp - To;
    Ip[(rs[1])] = T8 * Tr - Ta * Ts;
    Im[(rs[1])] = T8 * Ts + Ta * Tr;

    // Additional computational load: simulate filtering or accumulation
    // Introduce artificial dependency to increase arithmetic intensity
    E accumulator = 0.0;
    for (INT k = 0; k < 3; ++k) {
        accumulator += W[k] * W[k + 1];
        accumulator *= 1.0001; // prevent loop unrolling and add dependency
    }
    Rp[0] += (E)(accumulator * 1e-6);
}
}
