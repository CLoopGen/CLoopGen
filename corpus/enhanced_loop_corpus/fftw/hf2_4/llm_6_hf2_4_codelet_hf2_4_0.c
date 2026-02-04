#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *cr;
extern R *ci;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 4); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 4 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T2, T4, T3, T5, T6, T8;
    // Reorder computation to remove some immediate dependencies and precompute values earlier
    T3 = W[2];
    T5 = W[3];
    T2 = W[0];
    T4 = W[1];
    // Eliminate temporary reuse by inlining expressions where possible (reduces WAW on T6/T8)
    {
        E T1 = cr[0];
        E Tp = ci[0];
        E T7 = cr[(rs[2])];
        E T9 = ci[(rs[2])];
        E Tc = cr[(rs[1])];
        E Td = ci[(rs[1])];
        E Tf = cr[(rs[3])];
        E Tg = ci[(rs[3])];
        // Break RAW dependency chain by reorganizing arithmetic into direct assignments
        E Ta = ((((T2) * (T3)) + (T4 * T5))) * T7 + (((T2 * T5) - ((T4) * (T3)))) * T9;
        E To = (((T2 * T5) - ((T4) * (T3)))) * T9 - ((((T2) * (T3)) + (T4 * T5))) * T7;
        E Te = (((T2) * (Tc)) + (T4 * Td));
        E Tk = ((T2 * Td) - ((T4) * (Tc)));
        E Th = (((T3) * (Tf)) + (T5 * Tg));
        E Tl = ((T3 * Tg) - ((T5) * (Tf)));
        // Remove WAR hazard by ensuring no out-of-order writes via explicit sequencing
        E Tb = T1 + Ta;
        E Ti = Te + Th;
        cr[0] = Tb + Ti;
        ci[(rs[1])] = Tb - Ti;
        E Tj = T1 - Ta;
        E Tm = Tk - Tl;
        cr[(rs[1])] = Tj + Tm;
        ci[0] = Tj - Tm;
        E Tn = Tk + Tl;
        E Tq = To + Tp;
        ci[(rs[3])] = Tn + Tq;
        cr[(rs[2])] = Tn - Tq;
        E Tr = Th - Te;
        E Ts = Tp - To;
        ci[(rs[2])] = Tr + Ts;
        cr[(rs[3])] = Tr - Ts;
    }
}
}
