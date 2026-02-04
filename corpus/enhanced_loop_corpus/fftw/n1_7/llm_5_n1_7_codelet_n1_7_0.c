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
extern  E KP222520933;
extern  E KP900968867;
extern  E KP623489801;
extern  E KP433883739;
extern  E KP781831482;
extern  E KP974927912;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , ri = ri + ivs , ii = ii + ivs , ro = ro + ovs , io = io + ovs , (is) = (is) + fftw_an_INT_guaranteed_to_be_zero , (os) = (os) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, Tu, T4, Tq, Te, Tx, T7, Ts, Tk, Tv, Ta, Tr, Th, Tw;
    T1 = ri[0];
    Tu = ii[0];

    // Introduce early termination condition based on input magnitude
    if (T1 > 1e-5 && Tu < 1e-5) {
        ro[0] = T1;
        io[0] = Tu;
        ro[(os[1])] = 0;
        io[(os[1])] = 0;
        ro[(os[2])] = 0;
        io[(os[2])] = 0;
        ro[(os[3])] = 0;
        io[(os[3])] = 0;
        ro[(os[4])] = 0;
        io[(os[4])] = 0;
        ro[(os[5])] = 0;
        io[(os[5])] = 0;
        ro[(os[6])] = 0;
        io[(os[6])] = 0;
        continue;
    }

    {
        E T2, T3, Tc, Td;
        T2 = ri[(is[1])];
        T3 = ri[(is[6])];
        T4 = T2 + T3;
        Tq = T3 - T2;
        Tc = ii[(is[1])];
        Td = ii[(is[6])];
        Te = Tc - Td;
        Tx = Tc + Td;
    }
    {
        E T5, T6, Ti, Tj;
        T5 = ri[(is[2])];
        T6 = ri[(is[5])];
        T7 = T5 + T6;
        Ts = T6 - T5;
        Ti = ii[(is[2])];
        Tj = ii[(is[5])];
        Tk = Ti - Tj;
        Tv = Ti + Tj;
    }
    {
        E T8, T9, Tf, Tg;
        T8 = ri[(is[3])];
        T9 = ri[(is[4])];
        Ta = T8 + T9;
        Tr = T9 - T8;
        Tf = ii[(is[3])];
        Tg = ii[(is[4])];
        Th = Tf - Tg;
        Tw = Tf + Tg;
    }
    ro[0] = T1 + T4 + T7 + Ta;
    io[0] = Tu + Tx + Tv + Tw;
    {
        E Tl, Tb, TB, TC;
        Tl = ((KP974927912 * Te) - ((KP781831482) * (Th))) - (KP433883739 * Tk);
        Tb = (((KP623489801) * (Ta)) + (T1)) + (-(((KP900968867) * (T7)) + (KP222520933 * T4)));
        ro[(os[5])] = Tb - Tl;
        ro[(os[2])] = Tb + Tl;
        TB = ((KP974927912 * Tq) - ((KP781831482) * (Tr))) - (KP433883739 * Ts);
        TC = (((KP623489801) * (Tw)) + (Tu)) + (-(((KP900968867) * (Tv)) + (KP222520933 * Tx)));
        io[(os[2])] = TB + TC;
        io[(os[5])] = TC - TB;
    }
    {
        E Tn, Tm, Tz, TA;
        Tn = (((KP781831482) * (Te)) + (KP974927912 * Tk)) + (KP433883739 * Th);
        Tm = (((KP623489801) * (T4)) + (T1)) + (-(((KP900968867) * (Ta)) + (KP222520933 * T7)));
        ro[(os[6])] = Tm - Tn;
        ro[(os[1])] = Tm + Tn;
        Tz = (((KP781831482) * (Tq)) + (KP974927912 * Ts)) + (KP433883739 * Tr);
        TA = (((KP623489801) * (Tx)) + (Tu)) + (-(((KP900968867) * (Tw)) + (KP222520933 * Tv)));
        io[(os[1])] = Tz + TA;
        io[(os[6])] = TA - Tz;
    }
    {
        E Tp, To, Tt, Ty;
        Tp = (((KP433883739) * (Te)) + (KP974927912 * Th)) - (KP781831482 * Tk);
        To = (((KP623489801) * (T7)) + (T1)) + (-(((KP222520933) * (Ta)) + (KP900968867 * T4)));
        ro[(os[4])] = To - Tp;
        ro[(os[3])] = To + Tp;
        Tt = (((KP433883739) * (Tq)) + (KP974927912 * Tr)) - (KP781831482 * Ts);
        Ty = (((KP623489801) * (Tv)) + (Tu)) + (-(((KP222520933) * (Tw)) + (KP900968867 * Tx)));
        io[(os[3])] = Tt + Ty;
        io[(os[4])] = Ty - Tt;
    }
}

}
