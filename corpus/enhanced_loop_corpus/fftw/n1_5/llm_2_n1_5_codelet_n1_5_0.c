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
    const INT * restrict isp = is;
    R * restrict rip = ri;
    R * restrict iip = ii;
    R * restrict rop = ro;
    R * restrict iop = io;

    T1 = rip[0];
    To = iip[0];
    {
        E T2, T3, T4, T5, T6, T7;
        T2 = rip[isp[1]];
        T3 = rip[isp[4]];
        T4 = T2 + T3;
        T5 = rip[isp[2]];
        T6 = rip[isp[3]];
        T7 = T5 + T6;
        T8 = T4 + T7;
        Tt = T5 - T6;
        T9 = KP559016994 * (T4 - T7);
        Ts = T2 - T3;
    }
    {
        E Tc, Td, Tl, Tf, Tg, Tm;
        Tc = iip[isp[1]];
        Td = iip[isp[4]];
        Tl = Tc + Td;
        Tf = iip[isp[2]];
        Tg = iip[isp[3]];
        Tm = Tf + Tg;
        Te = Tc - Td;
        Tp = Tl + Tm;
        Th = Tf - Tg;
        Tn = KP559016994 * (Tl - Tm);
    }
    rop[0] = T1 + T8;
    iop[0] = To + Tp;
    {
        E Ti, Tk, Tb, Tj, Ta;
        Ti = (((KP951056516) * (Te)) + (KP587785252 * Th));
        Tk = ((KP951056516 * Th) - ((KP587785252) * (Te)));
        Ta = ((T1) - ((KP250000000) * (T8)));
        Tb = T9 + Ta;
        Tj = Ta - T9;
        rop[isp[4]*ovs] = Tb - Ti;
        rop[isp[3]*ovs] = Tj + Tk;
        rop[isp[1]*ovs] = Tb + Ti;
        rop[isp[2]*ovs] = Tj - Tk;
    }
    {
        E Tu, Tv, Tr, Tw, Tq;
        Tu = (((KP951056516) * (Ts)) + (KP587785252 * Tt));
        Tv = ((KP951056516 * Tt) - ((KP587785252) * (Ts)));
        Tq = ((To) - ((KP250000000) * (Tp)));
        Tr = Tn + Tq;
        Tw = Tq - Tn;
        iop[isp[1]*ovs] = Tr - Tu;
        iop[isp[3]*ovs] = Tw - Tv;
        iop[isp[4]*ovs] = Tu + Tr;
        iop[isp[2]*ovs] = Tv + Tw;
    }
}
}
