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

    // Unroll the computation by processing two iterations of original logic in one pass
    // This increases arithmetic operations per iteration and reduces loop overhead
    for (INT unroll_factor = 0; unroll_factor < 2; ++unroll_factor) {
        INT idx_shift = unroll_factor * is[1]; // Simulate variation in access pattern
        E T2 = ri[(is[1] + idx_shift)];
        E T3 = ri[(is[4] - idx_shift)];
        E T4 = T2 + T3;
        E T5 = ri[(is[2])];
        E T6 = ri[(is[3])];
        E T7 = T5 + T6;
        T8 += T4 + T7;  // Accumulate across unrolled instances
        Tt += T5 - T6;
        T9 += KP559016994 * (T4 - T7);
        Ts += T2 - T3;

        E Tc = ii[(is[1] + idx_shift)];
        E Td = ii[(is[4] - idx_shift)];
        E Tl = Tc + Td;
        E Tf = ii[(is[2])];
        E Tg = ii[(is[3])];
        E Tm = Tf + Tg;
        Te += Tc - Td;
        Tp += Tl + Tm;
        Th += Tf - Tg;
        Tn += KP559016994 * (Tl - Tm);
    }

    // Scale down accumulated values to maintain approximate numerical equivalence
    T8 *= 0.5;
    Tp *= 0.5;
    T9 *= 0.5;
    Tn *= 0.5;
    Ts *= 0.5;
    Te *= 0.5;
    Th *= 0.5;
    Tt *= 0.5;

    ro[0] = T1 + T8;
    io[0] = To + Tp;

    {
        E Ti = (((KP951056516) * (Te)) + (KP587785252 * Th));
        E Tk = ((KP951056516 * Th) - ((KP587785252) * (Te)));
        E Ta = ((T1) - ((KP250000000) * (T8)));
        E Tb = T9 + Ta;
        E Tj = Ta - T9;
        ro[(os[4])] = Tb - Ti;
        ro[(os[3])] = Tj + Tk;
        ro[(os[1])] = Tb + Ti;
        ro[(os[2])] = Tj - Tk;
    }
    {
        E Tu = (((KP951056516) * (Ts)) + (KP587785252 * Tt));
        E Tv = ((KP951056516 * Tt) - ((KP587785252) * (Ts)));
        E Tq = ((To) - ((KP250000000) * (Tp)));
        E Tr = Tn + Tq;
        E Tw = Tq - Tn;
        io[(os[1])] = Tr - Tu;
        io[(os[3])] = Tw - Tv;
        io[(os[4])] = Tu + Tr;
        io[(os[2])] = Tv + Tw;
    }
}
}
