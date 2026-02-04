#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *ri;
extern R *ii;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Variant with indirect memory access using index arrays to simulate gather operations
// Assume rs array defines non-unit strides; we create an index vector for indirect access
for (m = mb , W = W + (mb * 4); m < me; m = m + 1 , ri = ri + ms , ii = ii + ms , W = W + 4 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T2, T4, T3, T5, T6, T8;
    T2 = W[0];
    T4 = W[1];
    T3 = W[2];
    T5 = W[3];
    T6 = (T2 * T3) + (T4 * T5);
    T8 = (T2 * T5) - (T4 * T3);
    
    // Precompute effective indices to simulate indirect addressing
    INT idx0 = 0;
    INT idx1 = rs[1];
    INT idx2 = rs[2];
    INT idx3 = rs[3];

    // Gather all required data using computed indices
    E T1 = ri[idx0], Tp = ii[idx0];
    E T7 = ri[idx2], T9 = ii[idx2];
    E Tc = ri[idx1], Td = ii[idx1];
    E Tf = ri[idx3], Tg = ii[idx3];

    E Ta = (T6 * T7) + (T8 * T9);
    E To = (T6 * T9) - (T8 * T7);
    E Te = (T2 * Tc) + (T4 * Td);
    E Tk = (T2 * Td) - (T4 * Tc);
    E Th = (T3 * Tf) + (T5 * Tg);
    E Tl = (T3 * Tg) - (T5 * Tf);

    // Compute outputs
    E Tb = T1 + Ta;
    E Ti = Te + Th;
    E Tn = Tk + Tl;
    E Tq = To + Tp;

    // Scatter results back through indirect indexing
    ri[idx2] = Tb - Ti;
    ri[idx0] = Tb + Ti;
    ii[idx0] = Tn + Tq;
    ii[idx2] = Tq - Tn;

    E Tj = T1 - Ta;
    E Tm = Tk - Tl;
    ri[idx3] = Tj - Tm;
    ri[idx1] = Tj + Tm;

    E Tr = Tp - To;
    E Ts = Te - Th;
    ii[idx1] = Tr - Ts;
    ii[idx3] = Ts + Tr;
}
}
