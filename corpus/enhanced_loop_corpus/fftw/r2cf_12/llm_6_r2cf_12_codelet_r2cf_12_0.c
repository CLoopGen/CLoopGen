#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *R0;
extern R *R1;
extern R *Cr;
extern R *Ci;
extern stride rs;
extern stride csr;
extern stride csi;
extern INT v;
extern INT ivs;
extern INT ovs;
extern  E KP866025403;
extern  E KP500000000;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 2 , R0 = R0 + 2*ivs , R1 = R1 + 2*ivs , Cr = Cr + 2*ovs , Ci = Ci + 2*ovs , (rs) = (rs) + 2*fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + 2*fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    if (i < 2) break;
    E T5, Tp, Tb, Tn, Ty, Tt, Ta, Tq, Tc, Ti, Tz, Tu, Td, To;
    E T5b, Tpb, Tbb, Tnb, Tyb, Ttb, Tab, Tqb, Tcb, Tib, Tzb, Tub, Tdb, Tob;

    // First iteration (original)
    {
        E T1, T2, T3, T4;
        T1 = R0[0];
        T2 = R0[(rs[2])];
        T3 = R0[(rs[4])];
        T4 = T2 + T3;
        T5 = T1 + T4;
        Tp = ((T1) - ((KP500000000) * (T4)));
        Tb = T3 - T2;
    }
    {
        E Tj, Tk, Tl, Tm;
        Tj = R1[(rs[1])];
        Tk = R1[(rs[3])];
        Tl = R1[(rs[5])];
        Tm = Tk + Tl;
        Tn = ((Tj) - ((KP500000000) * (Tm)));
        Ty = Tl - Tk;
        Tt = Tj + Tm;
    }
    {
        E T6, T7, T8, T9;
        T6 = R0[(rs[3])];
        T7 = R0[(rs[5])];
        T8 = R0[(rs[1])];
        T9 = T7 + T8;
        Ta = T6 + T9;
        Tq = ((T6) - ((KP500000000) * (T9)));
        Tc = T8 - T7;
    }
    {
        E Te, Tf, Tg, Th;
        Te = R1[(rs[4])];
        Tf = R1[0];
        Tg = R1[(rs[2])];
        Th = Tf + Tg;
        Ti = ((Te) - ((KP500000000) * (Th)));
        Tz = Tg - Tf;
        Tu = Te + Th;
    }
    Cr[(csr[3])] = T5 - Ta;
    Ci[(csi[3])] = Tt - Tu;
    Td = KP866025403 * (Tb - Tc);
    To = Ti - Tn;
    Ci[(csi[1])] = Td + To;
    Ci[(csi[5])] = To - Td;
    {
        E Tx, TA, Tv, Tw;
        Tx = Tp - Tq;
        TA = KP866025403 * (Ty - Tz);
        Cr[(csr[5])] = Tx - TA;
        Cr[(csr[1])] = Tx + TA;
        Tv = T5 + Ta;
        Tw = Tt + Tu;
        Cr[(csr[6])] = Tv - Tw;
        Cr[0] = Tv + Tw;
    }
    {
        E Tr, Ts, TB, TC;
        Tr = Tp + Tq;
        Ts = Tn + Ti;
        Cr[(csr[2])] = Tr - Ts;
        Cr[(csr[4])] = Tr + Ts;
        TB = Ty + Tz;
        TC = Tb + Tc;
        Ci[(csi[2])] = KP866025403 * (TB - TC);
        Ci[(csi[4])] = KP866025403 * (TC + TB);
    }

    // Second iteration (unrolled)
    {
        E T1, T2, T3, T4;
        T1 = R0[ivs];
        T2 = R0[(rs[2]) + ivs];
        T3 = R0[(rs[4]) + ivs];
        T4 = T2 + T3;
        T5b = T1 + T4;
        Tpb = ((T1) - ((KP500000000) * (T4)));
        Tbb = T3 - T2;
    }
    {
        E Tj, Tk, Tl, Tm;
        Tj = R1[(rs[1]) + ivs];
        Tk = R1[(rs[3]) + ivs];
        Tl = R1[(rs[5]) + ivs];
        Tm = Tk + Tl;
        Tnb = ((Tj) - ((KP500000000) * (Tm)));
        Tyb = Tl - Tk;
        Ttb = Tj + Tm;
    }
    {
        E T6, T7, T8, T9;
        T6 = R0[(rs[3]) + ivs];
        T7 = R0[(rs[5]) + ivs];
        T8 = R0[(rs[1]) + ivs];
        T9 = T7 + T8;
        Tab = T6 + T9;
        Tqb = ((T6) - ((KP500000000) * (T9)));
        Tcb = T8 - T7;
    }
    {
        E Te, Tf, Tg, Th;
        Te = R1[(rs[4]) + ivs];
        Tf = R1[ivs];
        Tg = R1[(rs[2]) + ivs];
        Th = Tf + Tg;
        Tib = ((Te) - ((KP500000000) * (Th)));
        Tzb = Tg - Tf;
        Tub = Te + Th;
    }
    Cr[(csr[3]) + ovs] = T5b - Tab;
    Ci[(csi[3]) + ovs] = Ttb - Tub;
    Tdb = KP866025403 * (Tbb - Tcb);
    Tob = Tib - Tnb;
    Ci[(csi[1]) + ovs] = Tdb + Tob;
    Ci[(csi[5]) + ovs] = Tob - Tdb;
    {
        E Tx, TA, Tv, Tw;
        Tx = Tpb - Tqb;
        TA = KP866025403 * (Tyb - Tzb);
        Cr[(csr[5]) + ovs] = Tx - TA;
        Cr[(csr[1]) + ovs] = Tx + TA;
        Tv = T5b + Tab;
        Tw = Ttb + Tub;
        Cr[(csr[6]) + ovs] = Tv - Tw;
        Cr[ovs] = Tv + Tw;
    }
    {
        E Tr, Ts, TB, TC;
        Tr = Tpb + Tqb;
        Ts = Tnb + Tib;
        Cr[(csr[2]) + ovs] = Tr - Ts;
        Cr[(csr[4]) + ovs] = Tr + Ts;
        TB = Tyb + Tzb;
        TC = Tbb + Tcb;
        Ci[(csi[2]) + ovs] = KP866025403 * (TB - TC);
        Ci[(csi[4]) + ovs] = KP866025403 * (TC + TB);
    }
}
}
