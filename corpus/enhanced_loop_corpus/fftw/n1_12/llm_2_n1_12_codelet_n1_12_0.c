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
    E Tl, T1f, T6, T9, Th, Tk, Tc, Tf, Tt, Tw, T1b, T1c;
    INT idx[12];
    
    // Precompute indirect indices using strides to enable consecutive access pattern
    for (INT j = 0; j < 12; ++j) {
        idx[j] = is[j];
    }

    // Access all array elements using precomputed index array to simulate indirect addressing
    {
        E T1, T2, T3, T4;
        T1 = ri[0];
        T2 = ri[idx[4]];
        T3 = ri[idx[8]];
        T4 = T2 + T3;
        T5 = T1 + T4;
        TR = T1 - KP500000000 * T4;
        TA = KP866025403 * (T3 - T2);
    }
    {
        E To, Tp, Tq, Tr;
        To = ii[0];
        Tp = ii[idx[4]];
        Tq = ii[idx[8]];
        Tr = Tp + Tq;
        Ts = To + Tr;
        TS = KP866025403 * (Tp - Tq);
        Tz = To - KP500000000 * Tr;
    }
    {
        T6 = ri[idx[6]];
        T9 = ri[idx[10]] + ri[idx[2]];
        Ta = T6 + T9;
        TU = T6 - KP500000000 * T9;
        TD = KP866025403 * (ri[idx[2]] - ri[idx[10]]);
    }
    {
        Tt = ii[idx[6]];
        Tw = ii[idx[10]] + ii[idx[2]];
        Tx = Tt + Tw;
        TV = KP866025403 * (ii[idx[10]] - ii[idx[2]]);
        TC = Tt - KP500000000 * Tw;
    }
    {
        Tc = ri[idx[3]];
        Tf = ri[idx[7]] + ri[idx[11]];
        Tg = Tc + Tf;
        T1a = KP866025403 * (ri[idx[11]] - ri[idx[7]]);
        TG = Tc - KP500000000 * Tf;
    }
    {
        T1b = ii[idx[3]];
        T1c = ii[idx[7]] + ii[idx[11]];
        TJ = KP866025403 * (ii[idx[7]] - ii[idx[11]]);
        T1u = T1b + T1c;
        T1d = T1b - KP500000000 * T1c;
    }
    {
        Th = ri[idx[9]];
        Tk = ri[idx[1]] + ri[idx[5]];
        Tl = Th + Tk;
        T1f = KP866025403 * (ri[idx[5]] - ri[idx[1]]);
        TL = Th - KP500000000 * Tk;
    }
    {
        E T1g = ii[idx[9]];
        E T1h = ii[idx[1]] + ii[idx[5]];
        TO = KP866025403 * (ii[idx[1]] - ii[idx[5]]);
        T1v = T1g + T1h;
        T1i = T1g - KP500000000 * T1h;
    }

    {
        E Tb = T5 + Ta;
        E Tm = Tg + Tl;
        ro[os[6]] = Tb - Tm;
        ro[0] = Tb + Tm;

        {
            E T1x = Ts + Tx;
            E T1y = T1u + T1v;
            io[os[6]] = T1x - T1y;
            io[0] = T1x + T1y;
            E Tn = Tg - Tl;
            E Ty = Ts - Tx;
            io[os[3]] = Tn + Ty;
            io[os[9]] = Ty - Tn;
        }

        E T1t = T5 - Ta;
        E T1w = T1u - T1v;
        ro[os[3]] = T1t - T1w;
        ro[os[9]] = T1t + T1w;

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

            io[os[1]] = T11 - T14;
            ro[os[1]] = T19 + T1k;
            io[os[7]] = T11 + T14;
            ro[os[7]] = T19 - T1k;
            ro[os[10]] = T17 - T18;
            io[os[10]] = T1l - T1m;
            ro[os[4]] = T17 + T18;
            io[os[4]] = T1l + T1m;
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

            io[os[5]] = TF - TQ;
            ro[os[5]] = T1n + T1q;
            io[os[11]] = TF + TQ;
            ro[os[11]] = T1n - T1q;
            ro[os[2]] = TX - TY;
            io[os[2]] = T1r - T1s;
            ro[os[8]] = TX + TY;
            io[os[8]] = T1r + T1s;
        }
    }
}
}
