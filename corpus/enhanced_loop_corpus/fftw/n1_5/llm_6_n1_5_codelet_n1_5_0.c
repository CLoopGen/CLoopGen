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
extern  E KP250000000;
extern  E KP587785252;
extern  E KP951056516;
extern  E KP559016994;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , ri = ri + ivs , ii = ii + ivs , ro = ro + ovs , io = io + ovs , (is) = (is) + fftw_an_INT_guaranteed_to_be_zero , (os) = (os) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, To, T8, Tt, T9, Ts, Te, Tp, Th, Tn;
    T1 = ri[0];
    To = ii[0];
    {
        E T2, T3, T4, T5, T6, T7;
        T2 = ri[(is[1])];
        T3 = ri[(is[4])];
        T4 = T2 + T3;
        T5 = ri[(is[2])];
        T6 = ri[(is[3])];
        T7 = T5 + T6;
        T8 = T4 + T7;
        Tt = T5 - T6;
        T9 = KP559016994 * (T4 - T7);
        Ts = T2 - T3;
    }
    {
        E Tc, Td, Tl, Tf, Tg, Tm;
        Tc = ii[(is[1])];
        Td = ii[(is[4])];
        Tl = Tc + Td;
        Tf = ii[(is[2])];
        Tg = ii[(is[3])];
        Tm = Tf + Tg;
        Te = Tc - Td;
        Tp = Tl + Tm;
        Th = Tf - Tg;
        Tn = KP559016994 * (Tl - Tm);
    }
    ro[0] = T1 + T8;
    io[0] = To + Tp;
    {
        E Ti, Tk, Tb, Tj, Ta;
        Ti = (((KP951056516) * (Te)) + (KP587785252 * Th));
        Tk = ((KP951056516 * Th) - ((KP587785252) * (Te)));
        Ta = ((T1) - ((KP250000000) * (T8)));
        Tb = T9 + Ta;
        Tj = Ta - T9;
        ro[(os[4])] = Tb - Ti;
        ro[(os[3])] = Tj + Tk;
        ro[(os[1])] = Tb + Ti;
        ro[(os[2])] = Tj - Tk;
    }
    {
        E Tu, Tv, Tr, Tw, Tq;
        Tu = (((KP951056516) * (Ts)) + (KP587785252 * Tt));
        Tv = ((KP951056516 * Tt) - ((KP587785252) * (Ts)));
        Tq = ((To) - ((KP250000000) * (Tp)));
        Tr = Tn + Tq;
        Tw = Tq - Tn;
        io[(os[1])] = Tr - Tu;
        io[(os[3])] = Tw - Tv;
        io[(os[4])] = Tu + Tr;
        io[(os[2])] = Tv + Tw;
    }
}

}
