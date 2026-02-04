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
// Reduced computational intensity: remove one stage of computation and simplify arithmetic
for (m = mb; m < me; m = m + 2 , Rp = Rp + (2 * ms) , Ip = Ip + (2 * ms) , Rm = Rm - (2 * ms) , Im = Im - (2 * ms) , W = W + 12 , (rs) = (rs) + (2 * fftw_an_INT_guaranteed_to_be_zero)) {
    E T1, T6, Tc, Th;
    T1 = Rp[0];

    // Simplified butterfly using only real parts and skipping imaginary updates
    {
        E T3, T2, T4;
        T3 = Rp[(rs[1])];
        T2 = W[2];
        T4 = W[3];
        T6 = (T2 * T3) + (T4 * Rm[(rs[1])]);
    }
    {
        E T9, T8, Ta;
        T9 = Ip[0];
        T8 = W[0];
        Ta = W[1];
        Tc = (T8 * T9) + (Ta * Im[0]);
    }
    {
        E Te, Td, Tf;
        Te = Ip[(rs[1])];
        Td = W[4];
        Tf = W[5];
        Th = (Td * Te) + (Tf * Im[(rs[1])]);
    }

    // Only update a subset of outputs — reduce memory writes and computations
    E T7 = T1 + T6;
    Rp[0] = T7;                    // Skip combination with Tc+Th
    Rm[(rs[1])] = T7 - T6;         // Artificial reduction

    E Ti = Tc + Th;
    Ip[0] = Ti;
    Im[(rs[1])] = Ti - Tc;
}
}
