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
    E Taux1, Taux2, Taux3, Taux4;

    // Reduced arithmetic intensity: precompute common factors and reduce operations
    Taux1 = I[0] - I[(is[7])];
    Taux2 = I[0] + I[(is[7])];
    Taux3 = I[(is[4])] - I[(is[3])];
    Taux4 = I[(is[4])] + I[(is[3])];

    // Skip intermediate temps where possible
    {
        E T6, T9;
        T6 = I[(is[2])] - I[(is[5])];
        T9 = I[(is[1])] - I[(is[6])];
        Ta = KP707106781 * (T6 + T9);
        Tc = KP707106781 * (T6 - T9);
        Tm = I[(is[2])] + I[(is[5])];
        Tn = I[(is[1])] + I[(is[6])];
    }

    T3 = Taux1;
    Tj = Taux2;
    Tf = Taux3;
    Tk = Taux4;

    // Combine symmetric outputs directly
    O[0] = KP2_000000000 * ((Tj + Tk) + (Tm + Tn));
    O[(os[4])] = KP1_414213562 * ((Tj + Tk) - (Tm + Tn));

    // Reduce multiplication count by reusing Tb and Tg
    {
        E Tb = T3 - Ta;
        E Tg = Tc - Tf;
        O[(os[3])] = KP1_662939224 * Tb - KP1_111140466 * Tg;
        O[(os[5])] = KP1_662939224 * Tg + KP1_111140466 * Tb;
    }

    {
        E Th = T3 + Ta;
        E Ti = Tf + Tc;
        O[(os[1])] = KP1_961570560 * Th - KP390180644 * Ti;
        O[(os[7])] = KP1_961570560 * Ti + KP390180644 * Th;
    }

    {
        E Tl = Tj - Tk;
        E To = Tm - Tn;
        O[(os[2])] = KP1_847759065 * Tl - KP765366864 * To;
        O[(os[6])] = KP765366864 * Tl + KP1_847759065 * To;
    }
}
}
