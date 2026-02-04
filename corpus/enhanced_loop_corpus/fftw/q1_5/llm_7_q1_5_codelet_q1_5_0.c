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
for (m = mb; m < me; m += 2, rio = rio + (2 * ms), iio = iio + (2 * ms), W = W + 16, (rs) = (rs) + (2 * fftw_an_INT_guaranteed_to_be_zero), (vs) = (vs) + (2 * fftw_an_INT_guaranteed_to_be_zero)) {
    if (m + 1 >= me) break;

    for (INT inner = 0; inner < 2; ++inner) {
        INT offset = inner * ms;
        R *rio_local = rio + offset;
        R *iio_local = iio + offset;
        stride rs_local = rs;
        stride vs_local = vs;
        E *W_local = W + (inner * 8);

        E T1, Ta, TG, Tv, T8, Tb, Tp, Tj, TD, To, Tq, Tr, TN, TW, T1s;
        E T1h, TU, TX, T1b, T15, T1p, T1a, T1c, T1d, T1z, T1I, T2e, T23, T1G, T1J;
        E T1X, T1R, T2b, T1W, T1Y, T1Z, T3v, T3p, T3J, T3u, T3w, T3x, T37, T3g, T3M;
        E T3B, T3e, T3h, T2l, T2u, T30, T2P, T2s, T2v, T2J, T2D, T2X, T2I, T2K, T2L;

        T1 = rio_local[0];
        {
            E T5 = rio_local[rs_local[2]];
            E T6 = rio_local[rs_local[3]];
            E T7 = T5 + T6;
            E Tu = T5 - T6;
            E T2 = rio_local[rs_local[1]];
            E T3 = rio_local[rs_local[4]];
            E T4 = T2 + T3;
            E Tt = T2 - T3;
            Ta = KP559016994 * (T4 - T7);
            TG = (KP951056516 * Tu) - (KP587785252 * Tt);
            Tv = (KP951056516 * Tt) + (KP587785252 * Tu);
            T8 = T4 + T7;
            Tb = T1 - (KP250000000 * T8);
        }

        Tp = iio_local[0];
        {
            E Tg = iio_local[rs_local[2]];
            E Th = iio_local[rs_local[3]];
            E Ti = Tg - Th;
            E Tn = Tg + Th;
            E Td = iio_local[rs_local[1]];
            E Te = iio_local[rs_local[4]];
            E Tf = Td - Te;
            E Tm = Td + Te;
            Tj = (KP951056516 * Tf) + (KP587785252 * Ti);
            TD = (KP951056516 * Ti) - (KP587785252 * Tf);
            To = KP559016994 * (Tm - Tn);
            Tq = Tm + Tn;
            Tr = Tp - (KP250000000 * Tq);
        }

        rio_local[0] = T1 + T8;
        iio_local[0] = Tp + Tq;

        {
            E Tc = Ta + Tb;
            E Tk = Tc + Tj;
            E Ty = Tc - Tj;
            E Ts = To + Tr;
            E Tw = Ts - Tv;
            E TA = Tv + Ts;
            E T9 = W_local[0], Tl = W_local[1];
            E Tx = W_local[6], Tz = W_local[7];
            rio_local[vs_local[1]] = T9 * Tk + Tl * Tw;
            iio_local[vs_local[1]] = T9 * Tw - Tl * Tk;
            rio_local[vs_local[4]] = Tx * Ty + Tz * TA;
            iio_local[vs_local[4]] = Tx * TA - Tz * Ty;
        }

        {
            E TC = Tb - Ta;
            E TE = TC - TD;
            E TK = TC + TD;
            E TH = Tr - To;
            E TI = TG + TH;
            E TM = TH - TG;
            E TB = W_local[2], TF = W_local[3];
            E TJ = W_local[4], TL = W_local[5];
            rio_local[vs_local[2]] = TB * TE + TF * TI;
            iio_local[vs_local[2]] = TB * TI - TF * TE;
            rio_local[vs_local[3]] = TJ * TK + TL * TM;
            iio_local[vs_local[3]] = TJ * TM - TL * TK;
        }
    }
}
}
