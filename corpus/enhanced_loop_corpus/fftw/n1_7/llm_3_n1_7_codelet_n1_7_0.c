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
    const INT idx_r[7] = {0, is[1], is[2], is[3], is[4], is[5], is[6]};
    const INT idx_i[7] = {0, is[1], is[2], is[3], is[4], is[5], is[6]};
    const INT idx_o[7] = {0, os[1], os[2], os[3], os[4], os[5], os[6]};
    {
        E T2, T3, Tc, Td;
        T2 = ri[idx_r[1]];
        T3 = ri[idx_r[6]];
        T4 = T2 + T3;
        Tq = T3 - T2;
        Tc = ii[idx_i[1]];
        Td = ii[idx_i[6]];
        Te = Tc - Td;
        Tx = Tc + Td;
    }
    {
        E T5, T6, Ti, Tj;
        T5 = ri[idx_r[2]];
        T6 = ri[idx_r[5]];
        T7 = T5 + T6;
        Ts = T6 - T5;
        Ti = ii[idx_i[2]];
        Tj = ii[idx_i[5]];
        Tk = Ti - Tj;
        Tv = Ti + Tj;
    }
    {
        E T8, T9, Tf, Tg;
        T8 = ri[idx_r[3]];
        T9 = ri[idx_r[4]];
        Ta = T8 + T9;
        Tr = T9 - T8;
        Tf = ii[idx_i[3]];
        Tg = ii[idx_i[4]];
        Th = Tf - Tg;
        Tw = Tf + Tg;
    }
    ro[idx_o[0]] = T1 + T4 + T7 + Ta;
    io[idx_o[0]] = Tu + Tx + Tv + Tw;
    {
        E Tl, Tb, TB, TC;
        Tl = ((KP974927912 * Te) - ((KP781831482) * (Th))) - (KP433883739 * Tk);
        Tb = (((KP623489801) * (Ta)) + (T1)) + (-(((KP900968867) * (T7)) + (KP222520933 * T4)));
        ro[idx_o[5]] = Tb - Tl;
        ro[idx_o[2]] = Tb + Tl;
        TB = ((KP974927912 * Tq) - ((KP781831482) * (Tr))) - (KP433883739 * Ts);
        TC = (((KP623489801) * (Tw)) + (Tu)) + (-(((KP900968867) * (Tv)) + (KP222520933 * Tx)));
        io[idx_o[2]] = TB + TC;
        io[idx_o[5]] = TC - TB;
    }
    {
        E Tn, Tm, Tz, TA;
        Tn = (((KP781831482) * (Te)) + (KP974927912 * Tk)) + (KP433883739 * Th);
        Tm = (((KP623489801) * (T4)) + (T1)) + (-(((KP900968867) * (Ta)) + (KP222520933 * T7)));
        ro[idx_o[6]] = Tm - Tn;
        ro[idx_o[1]] = Tm + Tn;
        Tz = (((KP781831482) * (Tq)) + (KP974927912 * Ts)) + (KP433883739 * Tr);
        TA = (((KP623489801) * (Tx)) + (Tu)) + (-(((KP900968867) * (Tw)) + (KP222520933 * Tv)));
        io[idx_o[1]] = Tz + TA;
        io[idx_o[6]] = TA - Tz;
    }
    {
        E Tp, To, Tt, Ty;
        Tp = (((KP433883739) * (Te)) + (KP974927912 * Th)) - (KP781831482 * Tk);
        To = (((KP623489801) * (T7)) + (T1)) + (-(((KP222520933) * (Ta)) + (KP900968867 * T4)));
        ro[idx_o[4]] = To - Tp;
        ro[idx_o[3]] = To + Tp;
        Tt = (((KP433883739) * (Tq)) + (KP974927912 * Tr)) - (KP781831482 * Ts);
        Ty = (((KP623489801) * (Tv)) + (Tu)) + (-(((KP222520933) * (Tw)) + (KP900968867 * Tx)));
        io[idx_o[3]] = Tt + Ty;
        io[idx_o[4]] = Ty - Tt;
    }
}
}
