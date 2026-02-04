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
    
    // Reorder independent computations to eliminate false loop-carried dependencies
    // Load all inputs first, then compute — increases instruction-level parallelism

    E ri_is1 = ri[(is[1])], ri_is6 = ri[(is[6])];
    E ii_is1 = ii[(is[1])], ii_is6 = ii[(is[6])];
    E ri_is2 = ri[(is[2])], ri_is5 = ri[(is[5])];
    E ii_is2 = ii[(is[2])], ii_is5 = ii[(is[5])];
    E ri_is3 = ri[(is[3])], ri_is4 = ri[(is[4])];
    E ii_is3 = ii[(is[3])], ii_is4 = ii[(is[4])];

    T1 = ri[0];
    Tu = ii[0];

    // Now compute derived values without interleaving loads
    T4 = ri_is1 + ri_is6;
    Tq = ri_is6 - ri_is1;
    Te = ii_is1 - ii_is6;
    Tx = ii_is1 + ii_is6;

    T7 = ri_is2 + ri_is5;
    Ts = ri_is5 - ri_is2;
    Tk = ii_is2 - ii_is5;
    Tv = ii_is2 + ii_is5;

    Ta = ri_is3 + ri_is4;
    Tr = ri_is4 - ri_is3;
    Th = ii_is3 - ii_is4;
    Tw = ii_is3 + ii_is4;

    ro[0] = T1 + T4 + T7 + Ta;
    io[0] = Tu + Tx + Tv + Tw;

    // Further break WAR/WAW hazards by reordering store operations
    // Use temporaries to decouple computation from memory writes
    E tB_val, tL_val, tC_val, tB_store5, tB_store2;
    E tM_val, tn_val, tA_store1, tz_store1, tA_store6, tz_store6;
    E to_val, tp_val, ty_val, tt_val, to_store3, to_store4, ty_store3, ty_store4;

    tL_val = ((KP974927912 * Te) - ((KP781831482) * (Th))) - (KP433883739 * Tk);
    tB_val = (((KP623489801) * (Ta)) + (T1)) + (-(((KP900968867) * (T7)) + (KP222520933 * T4)));
    tB_store5 = tB_val - tL_val;
    tB_store2 = tB_val + tL_val;

    tn_val = (((KP781831482) * (Te)) + (KP974927912 * Tk)) + (KP433883739 * Th);
    tM_val = (((KP623489801) * (T4)) + (T1)) + (-(((KP900968867) * (Ta)) + (KP222520933 * T7)));
    tA_store1 = tM_val + tn_val;
    tz_store1 = (((KP781831482) * (Tq)) + (KP974927912 * Ts)) + (KP433883739 * Tr);
    tA_store6 = tM_val - tn_val;
    tz_store6 = (((KP781831482) * (Tq)) + (KP974927912 * Ts)) + (KP433883739 * Tr); // Note: same as above due to symmetry

    tp_val = (((KP433883739) * (Te)) + (KP974927912 * Th)) - (KP781831482 * Tk);
    to_val = (((KP623489801) * (T7)) + (T1)) + (-(((KP222520933) * (Ta)) + (KP900968867 * T4)));
    to_store3 = to_val + tp_val;
    to_store4 = to_val - tp_val;

    tC_val = (((KP623489801) * (Tw)) + (Tu)) + (-(((KP900968867) * (Tv)) + (KP222520933 * Tx)));
    tt_val = (((KP433883739) * (Tq)) + (KP974927912 * Tr)) - (KP781831482 * Ts);
    ty_val = (((KP623489801) * (Tv)) + (Tu)) + (-(((KP222520933) * (Tw)) + (KP900968867 * Tx)));
    ty_store3 = tt_val + ty_val;
    ty_store4 = ty_val - tt_val;

    // Perform all stores at the end to reduce memory dependency chains
    ro[(os[5])] = tB_store5;
    ro[(os[2])] = tB_store2;
    ro[(os[6])] = tA_store6;
    ro[(os[1])] = tA_store1;
    ro[(os[4])] = to_store4;
    ro[(os[3])] = to_store3;

    io[(os[2])] = tz_store1 + tC_val;
    io[(os[5])] = tC_val - tz_store1;
    io[(os[1])] = tz_store1 + (((KP623489801) * (Tx)) + (Tu)) + (-(((KP900968867) * (Tw)) + (KP222520933 * Tv)));
    io[(os[6])] = (((KP623489801) * (Tx)) + (Tu)) + (-(((KP900968867) * (Tw)) + (KP222520933 * Tv))) - tz_store6;
    io[(os[3])] = ty_store3;
    io[(os[4])] = ty_store4;
}
}
