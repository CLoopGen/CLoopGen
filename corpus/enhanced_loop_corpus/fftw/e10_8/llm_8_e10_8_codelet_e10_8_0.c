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
for (i = v; i > 0; i = i - 2 , I = I + 2*ivs , O = O + 2*ovs , (is) = (is) + 2*fftw_an_INT_guaranteed_to_be_zero , (os) = (os) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    if (i < 2) break;
    E T3, Tj, Tf, Tk, Ta, Tn, Tc, Tm;
    E T3b, Tjb, Tfb, Tkb, Tab, Tnb, Tcb, Tmb;

    // First iteration (original body)
    {
        E T1, T2, Td, Te;
        T1 = I[0];
        T2 = I[(is[7])];
        T3 = T1 - T2;
        Tj = T1 + T2;
        Td = I[(is[4])];
        Te = I[(is[3])];
        Tf = Td - Te;
        Tk = Td + Te;
        {
            E T4, T5, T6, T7, T8, T9;
            T4 = I[(is[2])];
            T5 = I[(is[5])];
            T6 = T4 - T5;
            T7 = I[(is[1])];
            T8 = I[(is[6])];
            T9 = T7 - T8;
            Ta = KP707106781 * (T6 + T9);
            Tn = T7 + T8;
            Tc = KP707106781 * (T6 - T9);
            Tm = T4 + T5;
        }
    }
    {
        E Tb, Tg, Tp, Tq;
        Tb = T3 - Ta;
        Tg = Tc - Tf;
        O[(os[3])] = ((KP1_662939224 * Tb) - ((KP1_111140466) * (Tg)));
        O[(os[5])] = (((KP1_662939224) * (Tg)) + (KP1_111140466 * Tb));
        Tp = Tj + Tk;
        Tq = Tm + Tn;
        O[(os[4])] = KP1_414213562 * (Tp - Tq);
        O[0] = KP2_000000000 * (Tp + Tq);
    }
    {
        E Th, Ti, Tl, To;
        Th = T3 + Ta;
        Ti = Tf + Tc;
        O[(os[1])] = ((KP1_961570560 * Th) - ((KP390180644) * (Ti)));
        O[(os[7])] = (((KP1_961570560) * (Ti)) + (KP390180644 * Th));
        Tl = Tj - Tk;
        To = Tm - Tn;
        O[(os[2])] = ((KP1_847759065 * Tl) - ((KP765366864) * (To)));
        O[(os[6])] = (((KP765366864) * (Tl)) + (KP1_847759065 * To));
    }

    // Second iteration (unrolled instance)
    {
        E T1, T2, Td, Te;
        T1 = I[ivs];
        T2 = I[ivs + (is[7])];
        T3b = T1 - T2;
        Tjb = T1 + T2;
        Td = I[ivs + (is[4])];
        Te = I[ivs + (is[3])];
        Tfb = Td - Te;
        Tkb = Td + Te;
        {
            E T4, T5, T6, T7, T8, T9;
            T4 = I[ivs + (is[2])];
            T5 = I[ivs + (is[5])];
            T6 = T4 - T5;
            T7 = I[ivs + (is[1])];
            T8 = I[ivs + (is[6])];
            T9 = T7 - T8;
            Tab = KP707106781 * (T6 + T9);
            Tnb = T7 + T8;
            Tcb = KP707106781 * (T6 - T9);
            Tmb = T4 + T5;
        }
    }
    {
        E Tb, Tg, Tp, Tq;
        Tb = T3b - Tab;
        Tg = Tcb - Tfb;
        O[ovs + (os[3])] = ((KP1_662939224 * Tb) - ((KP1_111140466) * (Tg)));
        O[ovs + (os[5])] = (((KP1_662939224) * (Tg)) + (KP1_111140466 * Tb));
        Tp = Tjb + Tkb;
        Tq = Tmb + Tnb;
        O[ovs + (os[4])] = KP1_414213562 * (Tp - Tq);
        O[ovs] = KP2_000000000 * (Tp + Tq);
    }
    {
        E Th, Ti, Tl, To;
        Th = T3b + Tab;
        Ti = Tfb + Tcb;
        O[ovs + (os[1])] = ((KP1_961570560 * Th) - ((KP390180644) * (Ti)));
        O[ovs + (os[7])] = (((KP1_961570560) * (Ti)) + (KP390180644 * Th));
        Tl = Tjb - Tkb;
        To = Tmb - Tnb;
        O[ovs + (os[2])] = ((KP1_847759065 * Tl) - ((KP765366864) * (To)));
        O[ovs + (os[6])] = (((KP765366864) * (Tl)) + (KP1_847759065 * To));
    }
}
}
