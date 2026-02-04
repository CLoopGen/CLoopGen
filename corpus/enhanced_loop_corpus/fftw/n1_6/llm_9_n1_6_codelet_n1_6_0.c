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
extern  E KP866025403;
extern  E KP500000000;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 2 , ri = ri + 2*ivs , ii = ii + 2*ivs , ro = ro + 2*ovs , io = io + 2*ovs , (is) = (is) + 2*fftw_an_INT_guaranteed_to_be_zero , (os) = (os) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    if (i < 1) break;
    E T3, Tb, Tq, Tx, T6, Tc, T9, Td, Ta, Te, Ti, Tu, Tl, Tv, Tr;
    E Ty;
    E T3b, Tbb, Tqb, Txb, T6b, Tcb, T9b, Tdb, Tab, Teb, Tib, Tub, Tlb, Tvb, Trb;
    E Tyb;

    // First iteration (original body)
    {
        E T1, T2, To, Tp;
        T1 = ri[0];
        T2 = ri[(is[3])];
        T3 = T1 - T2;
        Tb = T1 + T2;
        To = ii[0];
        Tp = ii[(is[3])];
        Tq = To - Tp;
        Tx = To + Tp;
    }
    {
        E T4, T5, T7, T8;
        T4 = ri[(is[2])];
        T5 = ri[(is[5])];
        T6 = T4 - T5;
        Tc = T4 + T5;
        T7 = ri[(is[4])];
        T8 = ri[(is[1])];
        T9 = T7 - T8;
        Td = T7 + T8;
    }
    Ta = T6 + T9;
    Te = Tc + Td;
    {
        E Tg, Th, Tj, Tk;
        Tg = ii[(is[2])];
        Th = ii[(is[5])];
        Ti = Tg - Th;
        Tu = Tg + Th;
        Tj = ii[(is[4])];
        Tk = ii[(is[1])];
        Tl = Tj - Tk;
        Tv = Tj + Tk;
    }
    Tr = Ti + Tl;
    Ty = Tu + Tv;
    ro[(os[3])] = T3 + Ta;
    io[(os[3])] = Tq + Tr;
    ro[0] = Tb + Te;
    io[0] = Tx + Ty;
    {
        E Tf, Tm, Tn, Ts;
        Tf = ((T3) - ((KP500000000) * (Ta)));
        Tm = KP866025403 * (Ti - Tl);
        ro[(os[5])] = Tf - Tm;
        ro[(os[1])] = Tf + Tm;
        Tn = KP866025403 * (T9 - T6);
        Ts = ((Tq) - ((KP500000000) * (Tr)));
        io[(os[1])] = Tn + Ts;
        io[(os[5])] = Ts - Tn;
    }
    {
        E Tt, Tw, Tz, TA;
        Tt = ((Tb) - ((KP500000000) * (Te)));
        Tw = KP866025403 * (Tu - Tv);
        ro[(os[2])] = Tt - Tw;
        ro[(os[4])] = Tt + Tw;
        Tz = ((Tx) - ((KP500000000) * (Ty)));
        TA = KP866025403 * (Td - Tc);
        io[(os[2])] = Tz - TA;
        io[(os[4])] = TA + Tz;
    }

    // Second iteration (unrolled copy with offset adjustments)
    {
        E T1, T2, To, Tp;
        T1 = ri[ivs];
        T2 = ri[ivs + (is[3])];
        T3b = T1 - T2;
        Tbb = T1 + T2;
        To = ii[ivs];
        Tp = ii[ivs + (is[3])];
        Tqb = To - Tp;
        Txb = To + Tp;
    }
    {
        E T4, T5, T7, T8;
        T4 = ri[ivs + (is[2])];
        T5 = ri[ivs + (is[5])];
        T6b = T4 - T5;
        Tcb = T4 + T5;
        T7 = ri[ivs + (is[4])];
        T8 = ri[ivs + (is[1])];
        T9b = T7 - T8;
        Tdb = T7 + T8;
    }
    Tab = T6b + T9b;
    Teb = Tcb + Tdb;
    {
        E Tg, Th, Tj, Tk;
        Tg = ii[ivs + (is[2])];
        Th = ii[ivs + (is[5])];
        Tib = Tg - Th;
        Tub = Tg + Th;
        Tj = ii[ivs + (is[4])];
        Tk = ii[ivs + (is[1])];
        Tlb = Tj - Tk;
        Tvb = Tj + Tk;
    }
    Trb = Tib + Tlb;
    Tyb = Tub + Tvb;
    ro[ovs + (os[3])] = T3b + Tab;
    io[ovs + (os[3])] = Tqb + Trb;
    ro[ovs] = Tbb + Teb;
    io[ovs] = Txb + Tyb;
    {
        E Tf, Tm, Tn, Ts;
        Tf = ((T3b) - ((KP500000000) * (Tab)));
        Tm = KP866025403 * (Tib - Tlb);
        ro[ovs + (os[5])] = Tf - Tm;
        ro[ovs + (os[1])] = Tf + Tm;
        Tn = KP866025403 * (T9b - T6b);
        Ts = ((Tqb) - ((KP500000000) * (Trb)));
        io[ovs + (os[1])] = Tn + Ts;
        io[ovs + (os[5])] = Ts - Tn;
    }
    {
        E Tt, Tw, Tz, TA;
        Tt = ((Tbb) - ((KP500000000) * (Teb)));
        Tw = KP866025403 * (Tub - Tvb);
        ro[ovs + (os[2])] = Tt - Tw;
        ro[ovs + (os[4])] = Tt + Tw;
        Tz = ((Txb) - ((KP500000000) * (Tyb)));
        TA = KP866025403 * (Tdb - Tcb);
        io[ovs + (os[2])] = Tz - TA;
        io[ovs + (os[4])] = TA + Tz;
    }
}
}
