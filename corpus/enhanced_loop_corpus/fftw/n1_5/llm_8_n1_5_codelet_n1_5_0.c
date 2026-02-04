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
// Variant with reduced loop-carried dependencies and expanded independent computation
INT idx_load[5], idx_store[5];
// Precompute indices outside arithmetic blocks to decouple memory from computation
for (i = v; i > 0; i = i - 1 , ri = ri + ivs , ii = ii + ivs , ro = ro + ovs , io = io + ovs , (is) = (is) + fftw_an_INT_guaranteed_to_be_zero , (os) = (os) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, To, T8, Tt, T9, Ts, Te, Tp, Th, Tn;
    T1 = ri[0];
    To = ii[0];

    // Eliminate redundant indirections by precomputing array index offsets
    idx_load[1] = is[1]; idx_load[2] = is[2]; idx_load[3] = is[3]; idx_load[4] = is[4];
    idx_store[1] = os[1]; idx_store[2] = os[2]; idx_store[3] = os[3]; idx_store[4] = os[4];

    // Restructure to remove some RAW dependencies via parallel evaluation
    E r1 = ri[idx_load[1]], r2 = ri[idx_load[2]], r3 = ri[idx_load[3]], r4 = ri[idx_load[4]];
    E i1 = ii[idx_load[1]], i2 = ii[idx_load[2]], i3 = ii[idx_load[3]], i4 = ii[idx_load[4]];

    // Independent calculations with no interleaving (reducing false dependencies)
    E T4 = r1 + r4;
    E T7 = r2 + r3;
    T8 = T4 + T7;
    Tt = r2 - r3;
    T9 = KP559016994 * (T4 - T7);
    Ts = r1 - r4;

    E Tl = i1 + i4;
    E Tm = i2 + i3;
    Te = i1 - i4;
    Tp = Tl + Tm;
    Th = i2 - i3;
    Tn = KP559016994 * (Tl - Tm);

    ro[0] = T1 + T8;
    io[0] = To + Tp;

    // Reorder operations to allow compiler to better pipeline
    E Ta = T1 - (KP250000000 * T8);
    E Tb = T9 + Ta;
    E Tj = Ta - T9;
    E Ti = (KP951056516 * Te) + (KP587785252 * Th);
    E Tk = (KP951056516 * Th) - (KP587785252 * Te);

    ro[idx_store[4]] = Tb - Ti;
    ro[idx_store[3]] = Tj + Tk;
    ro[idx_store[1]] = Tb + Ti;
    ro[idx_store[2]] = Tj - Tk;

    E Tq = To - (KP250000000 * Tp);
    E Tr = Tn + Tq;
    E Tw = Tq - Tn;
    E Tu = (KP951056516 * Ts) + (KP587785252 * Tt);
    E Tv = (KP951056516 * Tt) - (KP587785252 * Ts);

    io[idx_store[1]] = Tr - Tu;
    io[idx_store[3]] = Tw - Tv;
    io[idx_store[4]] = Tu + Tr;
    io[idx_store[2]] = Tv + Tw;
}

}
