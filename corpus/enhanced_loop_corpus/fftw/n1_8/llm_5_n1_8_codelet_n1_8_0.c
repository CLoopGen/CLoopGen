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
extern  E KP707106781;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , ri = ri + ivs , ii = ii + ivs , ro = ro + ovs , io = io + ovs , (is) = (is) + fftw_an_INT_guaranteed_to_be_zero , (os) = (os) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, Tn, Ti, TC, T6, TB, Tl, To, Td, TN, Tz, TH, Ta, TM, Tu;
    E TG;

    E T1 = ri[0];
    E T2 = ri[(is[4])];
    T3 = T1 + T2;
    Tn = T1 - T2;

    E Tg = ii[0];
    E Th = ii[(is[4])];
    Ti = Tg + Th;
    TC = Tg - Th;

    E T4 = ri[(is[2])];
    E T5 = ri[(is[6])];
    T6 = T4 + T5;
    TB = T4 - T5;

    E Tj = ii[(is[2])];
    E Tk = ii[(is[6])];
    Tl = Tj + Tk;
    To = Tj - Tk;

    if (TC >= 0) {
        E Tb = ri[(is[7])];
        E Tc = ri[(is[3])];
        E Tv = Tb - Tc;
        E Tw = ii[(is[7])];
        E Tx = ii[(is[3])];
        E Ty = Tw - Tx;
        Td = Tb + Tc;
        TN = Tw + Tx;
        Tz = Tv - Ty;
        TH = Tv + Ty;

        E T8 = ri[(is[1])];
        E T9 = ri[(is[5])];
        E Tq = T8 - T9;
        E Tr = ii[(is[1])];
        E Ts = ii[(is[5])];
        E Tt = Tr - Ts;
        Ta = T8 + T9;
        TM = Tr + Ts;
        Tu = Tq + Tt;
        TG = Tt - Tq;
    } else {
        Td = 0;
        TN = 0;
        Tz = 0;
        TH = 0;
        Ta = 0;
        TM = 0;
        Tu = 0;
        TG = 0;
    }

    E T7 = T3 + T6;
    E Te = Ta + Td;
    ro[(os[4])] = T7 - Te;
    ro[0] = T7 + Te;

    E TP = Ti + Tl;
    E TQ = TM + TN;
    io[(os[4])] = TP - TQ;
    io[0] = TP + TQ;

    E Tf = Td - Ta;
    E Tm = Ti - Tl;
    io[(os[2])] = Tf + Tm;
    io[(os[6])] = Tm - Tf;

    E TL = T3 - T6;
    E TO = TM - TN;
    ro[(os[6])] = TL - TO;
    ro[(os[2])] = TL + TO;

    if (v % 2 == 0) {
        E Tp = Tn + To;
        E TA = KP707106781 * (Tu + Tz);
        ro[(os[5])] = Tp - TA;
        ro[(os[1])] = Tp + TA;

        E TJ = TC - TB;
        E TK = KP707106781 * (TG + TH);
        io[(os[5])] = TJ - TK;
        io[(os[1])] = TJ + TK;
    } else {
        ro[(os[1])] = Tn;
        io[(os[1])] = TC;
        ro[(os[5])] = To;
        io[(os[5])] = TB;
    }

    E TD = TB + TC;
    E TE = KP707106781 * (Tz - Tu);
    io[(os[7])] = TD - TE;
    io[(os[3])] = TD + TE;

    E TF = Tn - To;
    E TI = KP707106781 * (TG - TH);
    ro[(os[7])] = TF - TI;
    ro[(os[3])] = TF + TI;
}
}
