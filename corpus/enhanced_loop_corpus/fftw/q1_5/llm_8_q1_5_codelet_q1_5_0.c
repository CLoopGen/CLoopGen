#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *rio;
extern R *iio;
extern  R *W;
extern stride rs;
extern stride vs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP250000000;
extern  E KP587785252;
extern  E KP951056516;
extern  E KP559016994;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb; m < me; m++, rio += ms, iio += ms, W += 8) {
    E T1 = rio[0];
    E T5 = rio[rs[2]], T6 = rio[rs[3]];
    E T4 = rio[rs[1]] + rio[rs[4]];
    E T7 = T5 + T6;
    E T8 = T4 + T7;
    E Tb = T1 - KP250000000 * T8;
    E Ta = KP559016994 * (T4 - T7);
    E Tu = T5 - T6;
    E Tt = rio[rs[1]] - rio[rs[4]];
    E TG = KP951056516 * Tu - KP587785252 * Tt;
    E Tv = KP951056516 * Tt + KP587785252 * Tu;

    E Tp = iio[0];
    E Tg = iio[rs[2]], Th = iio[rs[3]];
    E Tm = Tg + Th;
    E Tn = Tg - Th;
    E Td = iio[rs[1]], Te = iio[rs[4]];
    E Tf = Td - Te;
    E Tq = Td + Te;
    E Tr = Tp - KP250000000 * Tq;
    E To = KP559016994 * (Tm - Tn);
    E Tj = KP951056516 * Tf + KP587785252 * Tn;
    E TD = KP951056516 * Tn - KP587785252 * Tf;

    rio[0] = T1 + T8;
    iio[0] = Tp + Tq;

    E Tc = Ta + Tb;
    E Tk = Tc + Tj;
    E Ty = Tc - Tj;
    E Ts = To + Tr;
    E Tw = Ts - Tv;
    E TA = Tv + Ts;

    rio[vs[1]] = W[0] * Tk + W[1] * Tw;
    iio[vs[1]] = W[0] * Tw - W[1] * Tk;
    rio[vs[4]] = W[6] * Ty + W[7] * TA;
    iio[vs[4]] = W[6] * TA - W[7] * Ty;

    E TC = Tb - Ta;
    E TE = TC - TD;
    E TK = TC + TD;
    E TH = Tr - To;
    E TI = TG + TH;
    E TM = TH - TG;

    rio[vs[2]] = W[2] * TE + W[3] * TI;
    iio[vs[2]] = W[2] * TI - W[3] * TE;
    rio[vs[3]] = W[4] * TK + W[5] * TM;
    iio[vs[3]] = W[4] * TM - W[5] * TK;
}
}
