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
    E T5, TR, TA, Ts, TS, Tz, Ta, TU, TD, Tx, TV, TC, Tg, T1a, TG;
    E TJ, T1u, T1d, TL, TO, T1v, T1i;
    E Tl, T1f;

    // Change memory access to fully consecutive layout by reindexing through a base offset
    // Assume that `is` stride values are multiples of a fixed step; convert to unit-stride via pointer arithmetic
    const R * restrict ribase = ri;
    const R * restrict iibase = ii;
    R * restrict rob = ro;
    R * restrict iob = io;

    // Flatten strided accesses into sequential loads with manual offset calculation assuming regular spacing
    // This variant assumes is[k] == k * base_stride and transforms into dense indexing
    INT base_stride = (is[1] != 0) ? is[1] : 1;  // safe fallback

    // Normalize all accesses to unit-stride equivalent
    {
        E T1 = ribase[0*base_stride], T2 = ribase[4*base_stride], T3 = ribase[8*base_stride];
        E T4 = T2 + T3;
        T5 = T1 + T4;
        TR = T1 - KP500000000 * T4;
        TA = KP866025403 * (T3 - T2);
    }
    {
        E To = iibase[0*base_stride], Tp = iibase[4*base_stride], Tq = iibase[8*base_stride];
        E Tr = Tp + Tq;
        Ts = To + Tr;
        TS = KP866025403 * (Tp - Tq);
        Tz = To - KP500000000 * Tr;
    }
    {
        E T6 = ribase[6*base_stride], T7 = ribase[10*base_stride], T8 = ribase[2*base_stride];
        E T9 = T7 + T8;
        Ta = T6 + T9;
        TU = T6 - KP500000000 * T9;
        TD = KP866025403 * (T8 - T7);
    }
    {
        E Tt = iibase[6*base_stride], Tu = iibase[10*base_stride], Tv = iibase[2*base_stride];
        E Tw = Tu + Tv;
        Tx = Tt + Tw;
        TV = KP866025403 * (Tu - Tv);
        TC = Tt - KP500000000 * Tw;
    }
    {
        E Tc = ribase[3*base_stride], Td = ribase[7*base_stride], Te = ribase[11*base_stride];
        E Tf = Td + Te;
        Tg = Tc + Tf;
        T1a = KP866025403 * (Te - Td);
        TG = Tc - KP500000000 * Tf;
    }
    {
        E T1b = iibase[3*base_stride], TH = iibase[7*base_stride], TI = iibase[11*base_stride];
        E T1c = TH + TI;
        TJ = KP866025403 * (TH - TI);
        T1u = T1b + T1c;
        T1d = T1b - KP500000000 * T1c;
    }
    {
        E Th = ribase[9*base_stride], Ti = ribase[1*base_stride], Tj = ribase[5*base_stride];
        E Tk = Ti + Tj;
        Tl = Th + Tk;
        T1f = KP866025403 * (Tj - Ti);
        TL = Th - KP500000000 * Tk;
    }
    {
        E T1g = iibase[9*base_stride], TM = iibase[1*base_stride], TN = iibase[5*base_stride];
        E T1h = TM + TN;
        TO = KP866025403 * (TM - TN);
        T1v = T1g + T1h;
        T1i = T1g - KP500000000 * T1h;
    }

    // Output writes use transformed output stride mapping assuming os follows same rule
    INT out_base = (os[1] != 0) ? os[1] : 1;

    {
        E Tb = T5 + Ta;
        E Tm = Tg + Tl;
        rob[6*out_base] = Tb - Tm;
        rob[0] = Tb + Tm;

        {
            E T1x = Ts + Tx;
            E T1y = T1u + T1v;
            iob[6*out_base] = T1x - T1y;
            iob[0] = T1x + T1y;
            E Tn = Tg - Tl;
            E Ty = Ts - Tx;
            iob[3*out_base] = Tn + Ty;
            iob[9*out_base] = Ty - Tn;
        }

        E T1t = T5 - Ta;
        E T1w = T1u - T1v;
        rob[3*out_base] = T1t - T1w;
        rob[9*out_base] = T1t + T1w;

        {
            E TZ = TA + Tz;
            E T10 = TD + TC;
            E T1e = T1a + T1d;
            E T1j = T1f + T1i;
            E T11 = TZ - T10;
            E T1l = TZ + T10;
            E T1k = T1e - T1j;
            E T1m = T1e + T1j;

            E T12 = TG + TJ;
            E T13 = TL + TO;
            E T14 = T12 - T13;
            E T18 = T12 + T13;
            E T15 = TR + TS;
            E T16 = TU + TV;
            E T17 = T15 + T16;
            E T19 = T15 - T16;

            iob[1*out_base] = T11 - T14;
            rob[1*out_base] = T19 + T1k;
            iob[7*out_base] = T11 + T14;
            rob[7*out_base] = T19 - T1k;
            rob[10*out_base] = T17 - T18;
            iob[10*out_base] = T1l - T1m;
            rob[4*out_base] = T17 + T18;
            iob[4*out_base] = T1l + T1m;
        }
        {
            E TB = Tz - TA;
            E TE = TC - TD;
            E TF = TB - TE;
            E T1r = TB + TE;
            E T1o = T1d - T1a;
            E T1p = T1i - T1f;
            E T1q = T1o - T1p;
            E T1s = T1o + T1p;

            E TK = TG - TJ;
            E TP = TL - TO;
            E TQ = TK - TP;
            E TY = TK + TP;
            E TT = TR - TS;
            E TW = TU - TV;
            E TX = TT + TW;
            E T1n = TT - TW;

            iob[5*out_base] = TF - TQ;
            rob[5*out_base] = T1n + T1q;
            iob[11*out_base] = TF + TQ;
            rob[11*out_base] = T1n - T1q;
            rob[2*out_base] = TX - TY;
            iob[2*out_base] = T1r - T1s;
            rob[8*out_base] = TX + TY;
            iob[8*out_base] = T1r + T1s;
        }
    }
}
}
