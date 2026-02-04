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
    E T7, T9, T8, Ta, Tb, Td;
    // Move some computations earlier and reorder independent operations
    // Eliminate partial WAW and WAR hazards by renaming temporaries
    T8 = W[2];  // Reordered
    T7 = W[0];
    Ta = W[3];  // Moved up
    T9 = W[1];
    Tb = (T7 * T8 + T9 * Ta);
    Td = (T7 * Ta - T9 * T8);

    // Split accumulation into separate phase using local accumulators to break RAW chain
    E acc_cr0 = 0, acc_ci0 = 0;
    E acc_cr2 = 0, acc_ci2 = 0;
    E acc_cr1 = 0, acc_ci1 = 0;
    E acc_cr3 = 0, acc_ci3 = 0;

    {
        E T1 = cr[0];
        E T2 = ci[(rs[1])];
        E T3 = T1 + T2;
        E Tl = T1 - T2;
        E T4 = cr[(rs[1])];
        E T5 = ci[0];
        E T6 = T4 + T5;
        E To = T4 - T5;

        E Te = ci[(rs[3])];
        E Tf = cr[(rs[2])];
        E Tg = Te - Tf;
        E Tp = Te + Tf;
        E Th = ci[(rs[2])];
        E Ti = cr[(rs[3])];
        E Tj = Th - Ti;
        E Tm = Th + Ti;

        // Accumulate results without immediate store
        acc_cr0 += T3 + T6;
        acc_ci0 += Tg + Tj;
        E Tc = T3 - T6;
        E Tk = Tg - Tj;
        acc_cr2 += Tb * Tc - Td * Tk;
        acc_ci2 += Td * Tc + Tb * Tk;

        E Tn = Tl - Tm;
        E Tq = To + Tp;
        acc_cr1 += T7 * Tn - T9 * Tq;
        acc_ci1 += T7 * Tq + T9 * Tn;

        E Tr = Tl + Tm;
        E Ts = Tp - To;
        acc_cr3 += T8 * Tr - Ta * Ts;
        acc_ci3 += T8 * Ts + Ta * Tr;
    }

    // Finalize all stores at the end of the iteration to reduce intra-iteration dependencies
    cr[0] = acc_cr0;
    ci[0] = acc_ci0;
    cr[(rs[1])] = acc_cr1;
    ci[(rs[1])] = acc_ci1;
    cr[(rs[2])] = acc_cr2;
    ci[(rs[2])] = acc_ci2;
    cr[(rs[3])] = acc_cr3;
    ci[(rs[3])] = acc_ci3;
}
}
