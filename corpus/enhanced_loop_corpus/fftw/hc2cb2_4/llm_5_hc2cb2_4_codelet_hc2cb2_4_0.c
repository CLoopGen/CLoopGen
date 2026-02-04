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
    // Move W[] loads later to reduce false dependency on W base pointer early
    // Eliminate common subexpressions and fuse computations to change data flow
    Tb = 0.0;
    Td = 0.0;
    // Reorder and delay W[] access to break RAW dependency pattern
    {
        E T1, T2, T4, T5, Te, Tf, Th, Ti;
        T1 = Rp[0];
        T2 = Rm[(rs[1])];
        T4 = Rp[(rs[1])];
        T5 = Rm[0];
        Te = Ip[0];
        Tf = Im[(rs[1])];
        Th = Ip[(rs[1])];
        Ti = Im[0];

        // Compute linear combinations first without full use of W
        E T3 = T1 + T2;
        E T6 = T4 + T5;
        E Tl = T1 - T2;
        E To = T4 - T5;
        E Tg = Te - Tf;
        E Tj = Th - Ti;
        E Tp = Te + Tf;
        E Tm = Th + Ti;

        // Now load W and compute rotation factors — moved deeper to allow register reuse
        T7 = W[0];
        T9 = W[1];
        T8 = W[2];
        Ta = W[3];
        Tb = T7*T8 + T9*Ta;
        Td = T7*Ta - T9*T8;

        // Update outputs with combined arithmetic, reducing intermediate storage
        Rp[0] = T3 + T6;
        Rm[0] = Tg + Tj;
        E Tc = T3 - T6;
        E Tk = Tg - Tj;
        Rp[(rs[1])] = Tb * Tc - Td * Tk;
        Rm[(rs[1])] = Td * Tc + Tb * Tk;

        // Use fused multiply-add like patterns (emulated)
        Ip[0] = T7*(Tl - Tm) - T9*(To + Tp);
        Im[0] = T7*(To + Tp) + T9*(Tl - Tm);
        Ip[(rs[1])] = T8*(Tl + Tm) - Ta*(Tp - To);
        Im[(rs[1])] = T8*(Tp - To) + Ta*(Tl + Tm);
    }
}
}
