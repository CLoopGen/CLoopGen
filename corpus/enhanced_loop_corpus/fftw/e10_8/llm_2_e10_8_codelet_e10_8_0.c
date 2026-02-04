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
    const INT * restrict isp = is;
    R * restrict Ip = I;
    R * restrict Op = O;
    {
        E T1, T2, Td, Te;
        T1 = Ip[0];
        T2 = Ip[isp[7]];
        T3 = T1 - T2;
        Tj = T1 + T2;
        Td = Ip[isp[4]];
        Te = Ip[isp[3]];
        Tf = Td - Te;
        Tk = Td + Te;
        {
            E T4, T5, T6, T7, T8, T9;
            T4 = Ip[isp[2]];
            T5 = Ip[isp[5]];
            T6 = T4 - T5;
            T7 = Ip[isp[1]];
            T8 = Ip[isp[6]];
            T9 = T7 - T8;
            Ta = KP707106781 * (T6 + T9);
            Tn = T7 + T8;
            Tc = KP707106781 * (T6 - T9);
            Tm = T4 + T5;
        }
    }
    {
        const INT * restrict osp = os;
        E Tb, Tg, Tp, Tq;
        Tb = T3 - Ta;
        Tg = Tc - Tf;
        Op[osp[3]] = ((KP1_662939224 * Tb) - ((KP1_111140466) * (Tg)));
        Op[osp[5]] = (((KP1_662939224) * (Tg)) + (KP1_111140466 * Tb));
        Tp = Tj + Tk;
        Tq = Tm + Tn;
        Op[osp[4]] = KP1_414213562 * (Tp - Tq);
        Op[0] = KP2_000000000 * (Tp + Tq);
    }
    {
        const INT * restrict osp = os;
        E Th, Ti, Tl, To;
        Th = T3 + Ta;
        Ti = Tf + Tc;
        Op[osp[1]] = ((KP1_961570560 * Th) - ((KP390180644) * (Ti)));
        Op[osp[7]] = (((KP1_961570560) * (Ti)) + (KP390180644 * Th));
        Tl = Tj - Tk;
        To = Tm - Tn;
        Op[osp[2]] = ((KP1_847759065 * Tl) - ((KP765366864) * (To)));
        Op[osp[6]] = (((KP765366864) * (Tl)) + (KP1_847759065 * To));
    }
}
}
