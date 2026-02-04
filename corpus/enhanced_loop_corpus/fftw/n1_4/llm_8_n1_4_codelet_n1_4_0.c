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
for (i = v; i > 0; i = i - 2 , ri = ri + 2*ivs , ii = ii + 2*ivs , ro = ro + 2*ovs , io = io + 2*ovs , (is) = (is) + fftw_an_INT_guaranteed_to_be_zero , (os) = (os) + fftw_an_INT_guaranteed_to_be_zero) {
    if (i == 1) {
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
        break;
    }

    E T3a, Tba, T9a, Tfa, T6a, Taa, Tea, Tga;
    E T3b, Tbb, T9b, Tfb, T6b, Tab, Teb, Tgb;

    {
        E T1a, T2a, T7a, T8a;
        T1a = ri[0];
        T2a = ri[(is[2])];
        T3a = T1a + T2a;
        Tba = T1a - T2a;
        T7a = ii[0];
        T8a = ii[(is[2])];
        T9a = T7a - T8a;
        Tfa = T7a + T8a;

        E T1b, T2b, T7b, T8b;
        T1b = ri[ivs];
        T2b = ri[ivs + (is[2])];
        T3b = T1b + T2b;
        Tbb = T1b - T2b;
        T7b = ii[ivs];
        T8b = ii[ivs + (is[2])];
        T9b = T7b - T8b;
        Tfb = T7b + T8b;
    }
    {
        E T4a, T5a, Tca, Tda;
        T4a = ri[(is[1])];
        T5a = ri[(is[3])];
        T6a = T4a + T5a;
        Taa = T4a - T5a;
        Tca = ii[(is[1])];
        Tda = ii[(is[3])];
        Tea = Tca - Tda;
        Tga = Tca + Tda;

        E T4b, T5b, Tcb, Tdb;
        T4b = ri[ivs + (is[1])];
        T5b = ri[ivs + (is[3])];
        T6b = T4b + T5b;
        Tab = T4b - T5b;
        Tcb = ii[ivs + (is[1])];
        Tdb = ii[ivs + (is[3])];
        Teb = Tcb - Tdb;
        Tgb = Tcb + Tdb;
    }

    ro[(os[2])] = T3a - T6a;
    io[(os[2])] = Tfa - Tga;
    ro[0] = T3a + T6a;
    io[0] = Tfa + Tga;
    io[(os[1])] = T9a - Taa;
    ro[(os[1])] = Tba + Tea;
    io[(os[3])] = Taa + T9a;
    ro[(os[3])] = Tba - Tea;

    ro[ovs + (os[2])] = T3b - T6b;
    io[ovs + (os[2])] = Tfb - Tgb;
    ro[ovs] = T3b + T6b;
    io[ovs] = Tfb + Tgb;
    io[ovs + (os[1])] = T9b - Tab;
    ro[ovs + (os[1])] = Tbb + Teb;
    io[ovs + (os[3])] = Tab + T9b;
    ro[ovs + (os[3])] = Tbb - Teb;
}
}
