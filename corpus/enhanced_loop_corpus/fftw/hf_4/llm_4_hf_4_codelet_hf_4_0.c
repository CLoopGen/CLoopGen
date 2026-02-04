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
for (m = mb , W = W + ((mb - 1) * 6); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 6 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, Tp, T6, To, Tc, Tk, Th, Tl;
    T1 = cr[0];
    Tp = ci[0];

    // Introduce temporary variables to break and rewire dependencies
    E temp_cr2, temp_ci2, temp_cr1, temp_ci1, temp_cr3, temp_ci3;
    temp_cr2 = cr[(rs[2])]; temp_ci2 = ci[(rs[2])];
    temp_cr1 = cr[(rs[1])]; temp_ci1 = ci[(rs[1])];
    temp_cr3 = cr[(rs[3])]; temp_ci3 = ci[(rs[3])];

    // Reorder computations to change data dependency chains (RAW/WAR)
    // Use temporaries to remove direct loop-carried dependencies on memory
    {
        E T8 = W[0], Ta = W[1];
        Tc = T8 * temp_cr1 + Ta * temp_ci1;
        Tk = T8 * temp_ci1 - Ta * temp_cr1;
    }
    {
        E T2 = W[2], T4 = W[3];
        T6 = T2 * temp_cr2 + T4 * temp_ci2;
        To = T2 * temp_ci2 - T4 * temp_cr2;
    }
    {
        E Td = W[4], Tf = W[5];
        Th = Td * temp_cr3 + Tf * temp_ci3;
        Tl = Td * temp_ci3 - Tf * temp_cr3;
    }

    // Regroup final updates with modified write order to alter WAW dependencies
    E T7 = T1 + T6;
    E Ti = Tc + Th;
    cr[0] = T7 + Ti;
    ci[(rs[1])] = T7 - Ti;

    E Tj = T1 - T6;
    E Tm = Tk - Tl;
    cr[(rs[1])] = Tj + Tm;
    ci[0] = Tj - Tm;

    E Tn = Tk + Tl;
    E Tq = To + Tp;
    ci[(rs[3])] = Tn + Tq;
    cr[(rs[2])] = Tn - Tq;

    E Tr = Th - Tc;
    E Ts = Tp - To;
    ci[(rs[2])] = Tr + Ts;
    cr[(rs[3])] = Tr - Ts;
}
}
