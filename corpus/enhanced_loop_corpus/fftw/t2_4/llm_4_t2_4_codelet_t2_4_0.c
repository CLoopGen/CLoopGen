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
for (m = mb , W = W + (mb * 4); m < me; m = m + 1 , ri = ri + ms , ii = ii + ms , W = W + 4 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T2, T4, T3, T5, T6, T8;
    T2 = W[0];
    T4 = W[1];
    T3 = W[2];
    T5 = W[3];
    T6 = (((T2) * (T3)) + (T4 * T5));
    T8 = ((T2 * T5) - ((T4) * (T3)));
    {
        E T1 = ri[0];
        E Tp = ii[0];
        E T7 = ri[(rs[2])];
        E T9 = ii[(rs[2])];
        E Ta = (((T6) * (T7)) + (T8 * T9));
        E To = ((T6 * T9) - ((T8) * (T7)));
        E Tc = ri[(rs[1])];
        E Td = ii[(rs[1])];
        E Te = (((T2) * (Tc)) + (T4 * Td));
        E Tk = ((T2 * Td) - ((T4) * (Tc)));
        E Tf = ri[(rs[3])];
        E Tg = ii[(rs[3])];
        E Th = (((T3) * (Tf)) + (T5 * Tg));
        E Tl = ((T3 * Tg) - ((T5) * (Tf)));
        E Tb = T1 + Ta;
        E Ti = Te + Th;
        E Tn = Tk + Tl;
        E Tq = To + Tp;
        E Tj = T1 - Ta;
        E Tm = Tk - Tl;
        E Tr = Tp - To;
        E Ts = Te - Th;

        // Introduce artificial WAW and WAR dependencies via temporary accumulation
        // This creates a new loop-carried dependency on dummy variables
        static E acc_ri0 = 0.0, acc_ii0 = 0.0;
        acc_ri0 = ri[0];  // Read before write to create WAR-like pattern
        acc_ii0 = ii[0];
        ri[(rs[2])] = Tb - Ti;
        ri[0] = Tb + Ti + acc_ri0;  // WAW: write after prior write through accumulator
        ii[0] = Tn + Tq + acc_ii0;
        ii[(rs[2])] = Tq - Tn;

        ri[(rs[3])] = Tj - Tm;
        ri[(rs[1])] = Tj + Tm;
        ii[(rs[1])] = Tr - Ts;
        ii[(rs[3])] = Ts + Tr;

        // Update accumulators for next iteration (loop-carried dependency introduced)
        acc_ri0 = ri[0];
        acc_ii0 = ii[0];
    }
}
}
