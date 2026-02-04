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
for (i = v; i > 0; i = i - 1 , ri += 5*ivs , ii += 5*ivs , ro += 5*ovs , io += 5*ovs , (is) = (is) + fftw_an_INT_guaranteed_to_be_zero , (os) = (os) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, To, T8, Tt, T9, Ts, Te, Tp, Th, Tn;
    // Use consecutive memory layout by unrolling and accessing adjacent elements
    // Assume input is now packed in groups of 5: [0], [ivs], [2*ivs], [3*ivs], [4*ivs]
    // Access them consecutively via offset arithmetic

    const R * restrict rip = (const R * restrict)(ri);
    const R * restrict iip = (const R * restrict)(ii);
    R * restrict rop = (R * restrict)(ro);
    R * restrict iop = (R * restrict)(io);

    T1 = rip[0];
    To = iip[0];

    {
        E T2 = rip[ivs], T3 = rip[4*ivs], T4 = T2 + T3;
        E T5 = rip[2*ivs], T6 = rip[3*ivs], T7 = T5 + T6;
        T8 = T4 + T7;
        Tt = T5 - T6;
        T9 = KP559016994 * (T4 - T7);
        Ts = T2 - T3;
    }

    {
        E Tc = iip[ivs], Td = iip[4*ivs], Tl = Tc + Td;
        E Tf = iip[2*ivs], Tg = iip[3*ivs], Tm = Tf + Tg;
        Te = Tc - Td;
        Tp = Tl + Tm;
        Th = Tf - Tg;
        Tn = KP559016994 * (Tl - Tm);
    }

    rop[0] = T1 + T8;
    iop[0] = To + Tp;

    {
        E Ti = (KP951056516 * Te) + (KP587785252 * Th);
        E Tk = (KP951056516 * Th) - (KP587785252 * Te);
        E Ta = T1 - (KP250000000 * T8);
        E Tb = T9 + Ta;
        E Tj = Ta - T9;

        rop[4*ovs] = Tb - Ti;
        rop[3*ovs] = Tj + Tk;
        rop[1*ovs] = Tb + Ti;
        rop[2*ovs] = Tj - Tk;
    }

    {
        E Tu = (KP951056516 * Ts) + (KP587785252 * Tt);
        E Tv = (KP951056516 * Tt) - (KP587785252 * Ts);
        E Tq = To - (KP250000000 * Tp);
        E Tr = Tn + Tq;
        E Tw = Tq - Tn;

        iop[1*ovs] = Tr - Tu;
        iop[3*ovs] = Tw - Tv;
        iop[4*ovs] = Tu + Tr;
        iop[2*ovs] = Tv + Tw;
    }
}
}
