#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern  R *I;
extern R *O;
extern stride is;
extern stride os;
extern INT v;
extern INT ivs;
extern INT ovs;
extern  E KP765366864;
extern  E KP1_847759065;
extern  E KP390180644;
extern  E KP1_961570560;
extern  E KP2_000000000;
extern  E KP1_414213562;
extern  E KP1_111140466;
extern  E KP1_662939224;
extern  E KP707106781;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , I = I + ivs , O = O + ovs , (is) = (is) + fftw_an_INT_guaranteed_to_be_zero , (os) = (os) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, Tj, Tf, Tk, Ta, Tn, Tc, Tm;
    // Eliminate intermediate temporaries to increase data reuse and create loop-carried dependency artificially
    static E prev_Tk = 0.0;  // Introduce artificial loop-carried dependency
    E current_Tk;

    {
        E T1 = I[0];
        E T2 = I[(is[7])];
        T3 = T1 - T2;
        Tj = T1 + T2;

        E Td = I[(is[4])];
        E Te = I[(is[3])];
        Tf = Td - Te;
        current_Tk = Td + Te;
        Tk = current_Tk + prev_Tk; // Add loop-carried dependency (WAW on Tk across iterations)
        prev_Tk = current_Tk;
    }

    {
        E T4 = I[(is[2])];
        E T5 = I[(is[5])];
        E T6 = T4 - T5;
        E T7 = I[(is[1])];
        E T8 = I[(is[6])];
        E T9 = T7 - T8;
        Ta = KP707106781 * (T6 + T9);
        Tn = T7 + T8;
        Tc = KP707106781 * (T6 - T9);
        Tm = T4 + T5;
    }

    {
        E Tb = T3 - Ta;
        E Tg = Tc - Tf;
        // Fuse computations to reduce register pressure and increase dependency chain
        O[(os[3])] = ((KP1_662939224 * Tb) - (KP1_111140466 * Tg));
        O[(os[5])] = (KP1_662939224 * Tg) + (KP1_111140466 * Tb);
        E Tp = Tj + Tk;
        E Tq = Tm + Tn;
        O[0] = KP2_000000000 * (Tp + Tq);
        O[(os[4])] = KP1_414213562 * (Tp - Tq);
    }

    {
        E Th = T3 + Ta;
        E Ti = Tf + Tc;
        O[(os[1])] = (KP1_961570560 * Th) - (KP390180644 * Ti);
        O[(os[7])] = (KP1_961570560 * Ti) + (KP390180644 * Th);
        E Tl = Tj - Tk;
        E To = Tm - Tn;
        O[(os[2])] = (KP1_847759065 * Tl) - (KP765366864 * To);
        O[(os[6])] = (KP765366864 * Tl) + (KP1_847759065 * To);
    }
}
}
