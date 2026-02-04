#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *ri;
extern R *ii;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP250000000;
extern  E KP559016994;
extern  E KP587785252;
extern  E KP951056516;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Variant: Use indirect array access through pointer arrays for full stride indirection
E * restrict rptr[5], * restrict iptr[5];
for (m = mb , W = W + (mb * 4); m < me; m = m + 1 , ri = ri + ms , ii = ii + ms , W = W + 4 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T2, T4, T7, T9, Tb, Tl, Tf, Tj;
    {
        E T8, Te, Ta, Td;
        T2 = W[0];
        T4 = W[1];
        T7 = W[2];
        T9 = W[3];
        T8 = T2 * T7;
        Te = T4 * T7;
        Ta = T4 * T9;
        Td = T2 * T9;
        Tb = T8 - Ta;
        Tl = Td - Te;
        Tf = Td + Te;
        Tj = T8 + Ta;
    }

    // Precompute indirect pointers using stride table (rs) to enable scattered access
    rptr[0] = &ri[0];
    iptr[0] = &ii[0];
    rptr[1] = &ri[rs[1]]; iptr[1] = &ii[rs[1]];
    rptr[2] = &ri[rs[2]]; iptr[2] = &ii[rs[2]];
    rptr[3] = &ri[rs[3]]; iptr[3] = &ii[rs[3]];
    rptr[4] = &ri[rs[4]]; iptr[4] = &ii[rs[4]];

    {
        E T1 = *rptr[0], TI = *iptr[0];
        E T6, Tw, Tq, TA, Th, Tx, Tn, Tz;
        {
            E T3 = *rptr[1], T5 = *iptr[1];
            T6 = T2 * T3 + T4 * T5;
            Tw = T2 * T5 - T4 * T3;

            E To = *rptr[3], Tp = *iptr[3];
            Tq = T7 * To + T9 * Tp;
            TA = T7 * Tp - T9 * To;
        }
        {
            E Tc = *rptr[4], Tg = *iptr[4];
            Th = Tb * Tc + Tf * Tg;
            Tx = Tb * Tg - Tf * Tc;

            E Tk = *rptr[2], Tm = *iptr[2];
            Tn = Tj * Tk + Tl * Tm;
            Tz = Tj * Tm - Tl * Tk;
        }

        E Ty = Tw - Tx, TB = Tz - TA, TN = Tn - Tq, TM = T6 - Th;
        E TF = Tw + Tx, TG = Tz + TA, TH = TF + TG;
        E Ti = T6 + Th, Tr = Tn + Tq, Ts = Ti + Tr;

        *rptr[0] = T1 + Ts;
        *iptr[0] = TH + TI;

        {
            E TC = KP951056516 * Ty + KP587785252 * TB;
            E TE = KP951056516 * TB - KP587785252 * Ty;
            E Tt = KP559016994 * (Ti - Tr);
            E Tu = T1 - KP250000000 * Ts;
            E Tv = Tt + Tu, TD = Tu - Tt;

            *rptr[4] = Tv - TC;
            *rptr[3] = TD + TE;
            *rptr[1] = Tv + TC;
            *rptr[2] = TD - TE;
        }
        {
            E TO = KP951056516 * TM + KP587785252 * TN;
            E TP = KP951056516 * TN - KP587785252 * TM;
            E TJ = KP559016994 * (TF - TG);
            E TK = TI - KP250000000 * TH;
            E TL = TJ + TK, TQ = TK - TJ;

            *iptr[1] = TL - TO;
            *iptr[3] = TQ - TP;
            *iptr[4] = TO + TL;
            *iptr[2] = TP + TQ;
        }
    }
}
}
