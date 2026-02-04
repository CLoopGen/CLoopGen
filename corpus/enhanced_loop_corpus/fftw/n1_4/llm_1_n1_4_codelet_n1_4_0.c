#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern  R *ri;
extern  R *ii;
extern R *ro;
extern R *io;
extern stride is;
extern stride os;
extern INT v;
extern INT ivs;
extern INT ovs;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (v > 0) {
    for (i = v; i > 0; i = i - 1, ri = ri + ivs, ii = ii + ivs, ro = ro + ovs, io = io + ovs, (is) = (is) + fftw_an_INT_guaranteed_to_be_zero, (os) = (os) + fftw_an_INT_guaranteed_to_be_zero) {
        E T3, Tb, T9, Tf, T6, Ta, Te, Tg;
        {
            E T1, T2, T7, T8;
            T1 = ri[0];
            T2 = ri[(is[2])];
            T3 = T1 + T2;
            Tb = T1 - T2;
            T7 = ii[0];
            T8 = ii[(is[2])];
            T9 = T7 - T8;
            Tf = T7 + T8;
        }
        {
            E T4, T5, Tc, Td;
            T4 = ri[(is[1])];
            T5 = ri[(is[3])];
            T6 = T4 + T5;
            Ta = T4 - T5;
            Tc = ii[(is[1])];
            Td = ii[(is[3])];
            Te = Tc - Td;
            Tg = Tc + Td;
        }
        ro[(os[2])] = T3 - T6;
        io[(os[2])] = Tf - Tg;
        ro[0] = T3 + T6;
        io[0] = Tf + Tg;
        io[(os[1])] = T9 - Ta;
        ro[(os[1])] = Tb + Te;
        io[(os[3])] = Ta + T9;
        ro[(os[3])] = Tb - Te;

        if (i > 1) {
            E T3b, Tbb, T9b, Tfb, T6b, Tab, Teb, Tgb;
            const R *rib = ri + ivs;
            const R *iib = ii + ivs;
            R *rob = ro + ovs;
            R *iob = io + ovs;
            {
                E T1, T2, T7, T8;
                T1 = rib[0];
                T2 = rib[(is[2])];
                T3b = T1 + T2;
                Tbb = T1 - T2;
                T7 = iib[0];
                T8 = iib[(is[2])];
                T9b = T7 - T8;
                Tfb = T7 + T8;
            }
            {
                E T4, T5, Tc, Td;
                T4 = rib[(is[1])];
                T5 = rib[(is[3])];
                T6b = T4 + T5;
                Tab = T4 - T5;
                Tc = iib[(is[1])];
                Td = iib[(is[3])];
                Teb = Tc - Td;
                Tgb = Tc + Td;
            }
            rob[(os[2])] = T3b - T6b;
            iob[(os[2])] = Tfb - Tgb;
            rob[0] = T3b + T6b;
            iob[0] = Tfb + Tgb;
            iob[(os[1])] = T9b - Tab;
            rob[(os[1])] = Tbb + Teb;
            iob[(os[3])] = Tab + T9b;
            rob[(os[3])] = Tbb - Teb;
        }
    }
}
}
