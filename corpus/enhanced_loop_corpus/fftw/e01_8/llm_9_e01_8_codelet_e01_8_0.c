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
extern  E KP1_662939224;
extern  E KP1_111140466;
extern  E KP390180644;
extern  E KP1_961570560;
extern  E KP707106781;
extern  E KP1_414213562;
extern  E KP765366864;
extern  E KP1_847759065;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 4 , I = I + 4*ivs , O = O + 4*ovs , (is) = (is) + 4*fftw_an_INT_guaranteed_to_be_zero , (os) = (os) + 4*fftw_an_INT_guaranteed_to_be_zero) {
    INT unroll_factor = (i >= 4) ? 4 : i;
    for (INT u = 0; u < unroll_factor; ++u) {
        E T7, Tl, T4, Tk, Td, To, Tg, Tn;
        {
            E T5, T6, T1, T3, T2;
            T5 = I[u*ivs + (is[2])];
            T6 = I[u*ivs + (is[6])];
            T7 = (((KP1_847759065) * (T5)) + (KP765366864 * T6));
            Tl = ((KP765366864 * T5) - ((KP1_847759065) * (T6)));
            T1 = I[u*ivs];
            T2 = I[u*ivs + (is[4])];
            T3 = KP1_414213562 * T2;
            T4 = T1 + T3;
            Tk = T1 - T3;
            {
                E T9, Tf, Tc, Te, Ta, Tb;
                T9 = I[u*ivs + (is[1])];
                Tf = I[u*ivs + (is[7])];
                Ta = I[u*ivs + (is[5])];
                Tb = I[u*ivs + (is[3])];
                Tc = KP707106781 * (Ta + Tb);
                Te = KP707106781 * (Ta - Tb);
                Td = T9 + Tc;
                To = Te + Tf;
                Tg = Te - Tf;
                Tn = T9 - Tc;
            }
        }
        {
            E T8, Th, Tq, Tr;
            T8 = T4 + T7;
            Th = ((KP1_961570560 * Td) - ((KP390180644) * (Tg)));
            O[u*ovs + (os[7])] = T8 - Th;
            O[u*ovs] = T8 + Th;
            Tq = Tk - Tl;
            Tr = (((KP1_111140466) * (Tn)) + (KP1_662939224 * To));
            O[u*ovs + (os[5])] = Tq - Tr;
            O[u*ovs + (os[2])] = Tq + Tr;
        }
        {
            E Ti, Tj, Tm, Tp;
            Ti = T4 - T7;
            Tj = (((KP390180644) * (Td)) + (KP1_961570560 * Tg));
            O[u*ovs + (os[4])] = Ti - Tj;
            O[u*ovs + (os[3])] = Ti + Tj;
            Tm = Tk + Tl;
            Tp = ((KP1_662939224 * Tn) - ((KP1_111140466) * (To)));
            O[u*ovs + (os[6])] = Tm - Tp;
            O[u*ovs + (os[1])] = Tm + Tp;
        }
    }
}
}
