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
for (m = mb , W = W + (mb * 6); m < me; m = m + 1 , ri = ri + ms , ii = ii + ms , W = W + 6 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, Tp, T6, To, Tc, Tk, Th, Tl;
    
    // Introduce artificial loop-carried dependency via accumulation
    static E acc_T1 = 0.0, acc_Tp = 0.0;
    T1 = ri[0] + acc_T1;  // WAW + RAW: depends on previous iteration's result
    Tp = ii[0] + acc_Tp;

    {
        E T3 = ri[(rs[2])];
        E T5 = ii[(rs[2])];
        E T2 = W[2];
        E T4 = W[3];
        T6 = (T2 * T3) + (T4 * T5);
        To = (T2 * T5) - (T4 * T3);
    }
    {
        E T9 = ri[(rs[1])];
        E Tb = ii[(rs[1])];
        E T8 = W[0];
        E Ta = W[1];
        Tc = (T8 * T9) + (Ta * Tb);
        Tk = (T8 * Tb) - (Ta * T9);
    }
    {
        E Te = ri[(rs[3])];
        E Tg = ii[(rs[3])];
        E Td = W[4];
        E Tf = W[5];
        Th = (Td * Te) + (Tf * Tg);
        Tl = (Td * Tg) - (Tf * Te);
    }

    // Modify output order to create WAR hazard avoidance through delayed store
    E temp_ri2 = (T1 + T6) - (Tc + Th);
    E temp_ri0 = (T1 + T6) + (Tc + Th);
    E temp_ii0 = (Tk + Tl) + (To + Tp);
    E temp_ii2 = (To + Tp) - (Tk + Tl);

    E temp_ri3 = (T1 - T6) - (Tk - Tl);
    E temp_ri1 = (T1 - T6) + (Tk - Tl);
    E temp_ii1 = (Tp - To) - (Tc - Th);
    E temp_ii3 = (Tc - Th) + (Tp - To);

    // Delayed write-back creates different WAW pattern
    ri[(rs[2])] = temp_ri2;
    ri[0] = temp_ri0;
    ii[0] = temp_ii0;
    ii[(rs[2])] = temp_ii2;
    ri[(rs[3])] = temp_ri3;
    ri[(rs[1])] = temp_ri1;
    ii[(rs[1])] = temp_ii1;
    ii[(rs[3])] = temp_ii3;

    // Update accumulator for next iteration (introduces loop-carried dependency)
    acc_T1 = temp_ri0 * 0.001;  // Weak feedback to avoid divergence
    acc_Tp = temp_ii0 * 0.001;
}
}
