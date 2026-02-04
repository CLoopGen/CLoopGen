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
for (i = v; i > 0; i = i - 1 , ri = ri + ivs , ii = ii + ivs , ro = ro + ovs , io = io + ovs , (is) = (is) + fftw_an_INT_guaranteed_to_be_zero , (os) = (os) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, Tb, Tq, Tx, T6, Tc, T9, Td, Ta, Te, Ti, Tu, Tl, Tv, Tr;
    E Ty;
    const INT * restrict isp = is;
    R * restrict rip = ri;
    R * restrict iip = ii;
    R * restrict rop = ro;
    R * restrict iop = io;

    {
        E T1, T2, To, Tp;
        T1 = rip[0];
        T2 = rip[isp[3]];
        T3 = T1 - T2;
        Tb = T1 + T2;
        To = iip[0];
        Tp = iip[isp[3]];
        Tq = To - Tp;
        Tx = To + Tp;
    }
    {
        E T4, T5, T7, T8;
        T4 = rip[isp[2]];
        T5 = rip[isp[5]];
        T6 = T4 - T5;
        Tc = T4 + T5;
        T7 = rip[isp[4]];
        T8 = rip[isp[1]];
        T9 = T7 - T8;
        Td = T7 + T8;
    }
    Ta = T6 + T9;
    Te = Tc + Td;
    {
        E Tg, Th, Tj, Tk;
        Tg = iip[isp[2]];
        Th = iip[isp[5]];
        Ti = Tg - Th;
        Tu = Tg + Th;
        Tj = iip[isp[4]];
        Tk = iip[isp[1]];
        Tl = Tj - Tk;
        Tv = Tj + Tk;
    }
    Tr = Ti + Tl;
    Ty = Tu + Tv;
    rop[isp[3]] = T3 + Ta;
    iop[isp[3]] = Tq + Tr;
    rop[0] = Tb + Te;
    iop[0] = Tx + Ty;
    {
        E Tf, Tm, Tn, Ts;
        Tf = ((T3) - ((KP500000000) * (Ta)));
        Tm = KP866025403 * (Ti - Tl);
        rop[isp[5]] = Tf - Tm;
        rop[isp[1]] = Tf + Tm;
        Tn = KP866025403 * (T9 - T6);
        Ts = ((Tq) - ((KP500000000) * (Tr)));
        iop[isp[1]] = Tn + Ts;
        iop[isp[5]] = Ts - Tn;
    }
    {
        E Tt, Tw, Tz, TA;
        Tt = ((Tb) - ((KP500000000) * (Te)));
        Tw = KP866025403 * (Tu - Tv);
        rop[isp[2]] = Tt - Tw;
        rop[isp[4]] = Tt + Tw;
        Tz = ((Tx) - ((KP500000000) * (Ty)));
        TA = KP866025403 * (Td - Tc);
        iop[isp[2]] = Tz - TA;
        iop[isp[4]] = TA + Tz;
    }
}
}
