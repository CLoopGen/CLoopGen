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
for (m = mb , W = W + (mb * 8); m < me; m = m + 1 , ri += ms , ii += ms , W += 8) {
    E T1, TE, Tu, Tx, TJ, TI, TB, TC, TD, Tc, Tn, To;

    const R * restrict rptr = (const R * restrict)(ri);
    const R * restrict iptr = (const R * restrict)(ii);
    const R * restrict wptr = (const R * restrict)(W);
    R * restrict roptr = (R * restrict)(ri);
    R * restrict ioptr = (R * restrict)(ii);

    T1 = rptr[0];
    TE = iptr[0];

    E T6 = wptr[0]*rptr[rs[1]] + wptr[1]*iptr[rs[1]];
    E Ts = wptr[0]*iptr[rs[1]] - wptr[1]*rptr[rs[1]];

    E Tm = wptr[4]*rptr[rs[3]] + wptr[5]*iptr[rs[3]];
    E Tw = wptr[4]*iptr[rs[3]] - wptr[5]*rptr[rs[3]];

    E Tb = wptr[6]*rptr[rs[4]] + wptr[7]*iptr[rs[4]];
    E Tt = wptr[6]*iptr[rs[4]] - wptr[7]*rptr[rs[4]];

    E Th = wptr[2]*rptr[rs[2]] + wptr[3]*iptr[rs[2]];
    E Tv = wptr[2]*iptr[rs[2]] - wptr[3]*rptr[rs[2]];

    Tu = Ts - Tt;
    Tx = Tv - Tw;
    TJ = Th - Tm;
    TI = T6 - Tb;
    TB = Ts + Tt;
    TC = Tv + Tw;
    TD = TB + TC;
    Tc = T6 + Tb;
    Tn = Th + Tm;
    To = Tc + Tn;

    roptr[0] = T1 + To;
    ioptr[0] = TD + TE;

    E Ty = KP951056516*Tu + KP587785252*Tx;
    E TA = KP951056516*Tx - KP587785252*Tu;
    E Tp = KP559016994*(Tc - Tn);
    E Tq = T1 - KP250000000*To;
    E Tr = Tp + Tq;
    E Tz = Tq - Tp;

    roptr[rs[4]] = Tr - Ty;
    roptr[rs[3]] = Tz + TA;
    roptr[rs[1]] = Tr + Ty;
    roptr[rs[2]] = Tz - TA;

    E TK = KP951056516*TI + KP587785252*TJ;
    E TL = KP951056516*TJ - KP587785252*TI;
    E TF = KP559016994*(TB - TC);
    E TG = TE - KP250000000*TD;
    E TH = TF + TG;
    E TM = TG - TF;

    ioptr[rs[1]] = TH - TK;
    ioptr[rs[3]] = TM - TL;
    ioptr[rs[4]] = TK + TH;
    ioptr[rs[2]] = TL + TM;
}
}
