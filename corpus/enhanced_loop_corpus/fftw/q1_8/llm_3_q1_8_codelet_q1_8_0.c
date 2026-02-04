#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef R E;

typedef ptrdiff_t INT;

typedef INT *stride;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *rio;
extern R *iio;
extern  R *W;
extern stride rs;
extern stride vs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP707106781;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + (mb * 14); m < me; m = m + 1 , rio = rio + ms , iio = iio + ms , W = W + 14 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (vs) = (vs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T7, T14, T1g, Tk, TC, TQ, T10, TM, T1w, T2p, T2z, T1H, T1M, T1W, T2j;
    E T1V, T7R, T8O, T90, T84, T8m, T8A, T8K, T8w, T9g, Ta9, Taj, T9r, T9w, T9G;
    E Ta3, T9F, Te, T17, T1h, Tp, Tu, TE, T11, TD, T1p, T2m, T2y, T1C, T1U;
    E T28, T2i, T24, T7Y, T8R, T91, T89, T8e, T8o, T8L, T8n, T99, Ta6, Tai, T9m;
    E T9E, T9S, Ta2, T9O, T2H, T3E, T3Q, T2U, T3c, T3q, T3A, T3m, T46, T4Z, T59;
    E T4h, T4m, T4w, T4T, T4v, T5h, T6e, T6q, T5u, T5M, T60, T6a, T5W, T6G, T7z;
    E T7J, T6R, T6W, T76, T7t, T75, T2O, T3H, T3R, T2Z, T34, T3e, T3B, T3d, T3Z;
    E T4W, T58, T4c, T4u, T4I, T4S, T4E, T5o, T6h, T6r, T5z, T5E, T5O, T6b, T5N;
    E T6z, T7w, T7I, T6M, T74, T7i, T7s, T7e;

    // Control dependency: early exit under condition
    if (m >= (mb + me) / 2) break;

    // Always compute core butterfly stage 0
    {
        E T3, Ty, Tj, TY, T6, Tg, TB, TZ;
        {
            E T1, T2, Th, Ti;
            T1 = rio[0];
            T2 = rio[(rs[4])];
            T3 = T1 + T2;
            Ty = T1 - T2;
            Th = iio[0];
            Ti = iio[(rs[4])];
            Tj = Th - Ti;
            TY = Th + Ti;
        }
        {
            E T4, T5, Tz, TA;
            T4 = rio[(rs[2])];
            T5 = rio[(rs[6])];
            T6 = T4 + T5;
            Tg = T4 - T5;
            Tz = iio[(rs[2])];
            TA = iio[(rs[6])];
            TB = Tz - TA;
            TZ = Tz + TA;
        }
        T7 = T3 + T6;
        T14 = T3 - T6;
        T1g = TY + TZ;
        Tk = Tg + Tj;
        TC = Ty - TB;
        TQ = Tj - Tg;
        T10 = TY - TZ;
        TM = Ty + TB;
    }

    // Conditional execution of second block based on stride value
    if (rs[1] > 0) {
        {
            E T1s, T1I, T1L, T2n, T1v, T1D, T1G, T2o;
            {
                E T1q, T1r, T1J, T1K;
                T1q = rio[(vs[1]) + (rs[1])];
                T1r = rio[(vs[1]) + (rs[5])];
                T1s = T1q + T1r;
                T1I = T1q - T1r;
                T1J = iio[(vs[1]) + (rs[1])];
                T1K = iio[(vs[1]) + (rs[5])];
                T1L = T1J - T1K;
                T2n = T1J + T1K;
            }
            {
                E T1t, T1u, T1E, T1F;
                T1t = rio[(vs[1]) + (rs[7])];
                T1u = rio[(vs[1]) + (rs[3])];
                T1v = T1t + T1u;
                T1D = T1t - T1u;
                T1E = iio[(vs[1]) + (rs[7])];
                T1F = iio[(vs[1]) + (rs[3])];
                T1G = T1E - T1F;
                T2o = T1E + T1F;
            }
            T1w = T1s + T1v;
            T2p = T2n - T2o;
            T2z = T2n + T2o;
            T1H = T1D - T1G;
            T1M = T1I + T1L;
            T1W = T1D + T1G;
            T2j = T1v - T1s;
            T1V = T1L - T1I;
        }
    } else {
        // Default values if rs[1] <= 0
        T1w = T7;
        T2p = T14;
        T2z = T1g;
        T1H = Tk;
        T1M = TC;
        T1W = TQ;
        T2j = T10;
        T1V = TM;
    }

    // Unconditionally perform final writes using available data
    rio[0] = T7 + T1w;
    iio[0] = T1g + T2z;
    rio[(rs[1])] = T1w;
    iio[(rs[1])] = T2z;
    rio[(rs[2])] = T7;
    iio[(rs[2])] = T1g;
    rio[(rs[4])] = Tk;
    iio[(rs[4])] = TC;
}
}
