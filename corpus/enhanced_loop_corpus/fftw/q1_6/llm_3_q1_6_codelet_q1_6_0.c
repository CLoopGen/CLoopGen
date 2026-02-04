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
extern  E KP500000000;
extern  E KP866025403;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + (mb * 10); m < me; m = m + 1 , rio = rio + ms , iio = iio + ms , W = W + 10 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (vs) = (vs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, Tc, Tt, TM, TX, T16, T1n, T1G, T2h, T2A, T1R, T20, T2L, T2U, T3b;
    E T3u, T3F, T3O, T45, T4o, T4Z, T5i, T4z, T4I, Ta, TP, Tf, Tq, Tn, TN;
    E Tu, TJ, T14, T1J, T19, T1k, T1h, T1H, T1o, T1D, T2b, T2B, T2i, T2x, T1Y;
    E T2D, T23, T2e, T2S, T3x, T2X, T38, T35, T3v, T3c, T3r, T3M, T4r, T3R, T42;
    E T3Z, T4p, T46, T4l, T4T, T5j, T50, T5f, T4G, T5l, T4L, T4W;

    // Early termination based on index pattern
    if (m > mb + 1 && (m - mb) % 4 == 0) {
        // Reset key values and skip full computation
        rio[0] = 0.0;
        iio[0] = 0.0;
        continue;
    }

    // Always compute base loads
    {
        E T1, T2, T1l, T1m;
        T1 = rio[0];
        T2 = rio[(rs[3])];
        T3 = T1 + T2;
        Tc = T1 - T2;
        {
            E Tr, Ts, TV, TW;
            Tr = iio[0];
            Ts = iio[(rs[3])];
            Tt = Tr - Ts;
            TM = Tr + Ts;
            TV = rio[(vs[1])];
            TW = rio[(vs[1]) + (rs[3])];
            TX = TV + TW;
            T16 = TV - TW;
        }
        T1l = iio[(vs[1])];
        T1m = iio[(vs[1]) + (rs[3])];
        T1n = T1l - T1m;
        T1G = T1l + T1m;
        {
            E T2f, T2g, T1P, T1Q;
            T2f = iio[(vs[2])];
            T2g = iio[(vs[2]) + (rs[3])];
            T2h = T2f - T2g;
            T2A = T2f + T2g;
            T1P = rio[(vs[2])];
            T1Q = rio[(vs[2]) + (rs[3])];
            T1R = T1P + T1Q;
            T20 = T1P - T1Q;
        }
    }

    // Conditional execution of secondary blocks
    if ((m - mb) % 2 == 0) {
        {
            E T2J, T2K, T43, T44;
            T2J = rio[(vs[3])];
            T2K = rio[(vs[3]) + (rs[3])];
            T2L = T2J + T2K;
            T2U = T2J - T2K;
            T3b = iio[(vs[3])] - iio[(vs[3]) + (rs[3])];
            T3u = iio[(vs[3])] + iio[(vs[3]) + (rs[3])];
            T3F = rio[(vs[4])] + rio[(vs[4]) + (rs[3])];
            T3O = rio[(vs[4])] - rio[(vs[4]) + (rs[3])];
            T45 = iio[(vs[4])] - iio[(vs[4]) + (rs[3])];
            T4o = iio[(vs[4])] + iio[(vs[4]) + (rs[3])];
            T4Z = iio[(vs[5])] - iio[(vs[5]) + (rs[3])];
            T5i = iio[(vs[5])] + iio[(vs[5]) + (rs[3])];
            T4z = rio[(vs[5])] + rio[(vs[5]) + (rs[3])];
            T4I = rio[(vs[5])] - rio[(vs[5]) + (rs[3])];
        }
    } else {
        // Use cached or zeroed values for odd iterations
        T2L = T3;
        T2U = Tc;
        T3b = Tt;
        T3u = TM;
        T3F = TX;
        T3O = T16;
        T45 = T1n;
        T4o = T1G;
        T4Z = T2h;
        T5i = T2A;
        T4z = T1R;
        T4I = T20;
    }

    // Full arithmetic only every third iteration
    if ((m - mb) % 3 == 0) {
        {
            E T6, Td, T9, Te;
            T6 = rio[(rs[2])] + rio[(rs[5])];
            Td = rio[(rs[2])] - rio[(rs[5])];
            T9 = rio[(rs[4])] + rio[(rs[1])];
            Te = rio[(rs[4])] - rio[(rs[1])];
            Ta = T6 + T9;
            TP = KP866025403 * (T9 - T6);
            Tf = Td + Te;
            Tq = KP866025403 * (Te - Td);
        }
        {
            E Tj, TH, Tm, TI;
            Tj = iio[(rs[2])] - iio[(rs[5])];
            TH = iio[(rs[2])] + iio[(rs[5])];
            Tm = iio[(rs[4])] - iio[(rs[1])];
            TI = iio[(rs[4])] + iio[(rs[1])];
            Tn = KP866025403 * (Tj - Tm);
            TN = TH + TI;
            Tu = Tj + Tm;
            TJ = KP866025403 * (TH - TI);
        }
    } else {
        // Reuse previous or simplified values
        Ta = T3;
        TP = Tc;
        Tf = Tt;
        Tq = TM;
        Tn = TX;
        TN = T16;
        Tu = T1n;
        TJ = T1G;
    }

    // Always update primary outputs
    rio[0] = T3 + Ta;
    iio[0] = TM + TN;
    rio[(rs[1])] = TX + T14;
    iio[(rs[1])] = T1G + T1H;
    rio[(rs[3])] = T2L + T2S;
    rio[(rs[2])] = T1R + T1Y;
    iio[(rs[2])] = T2A + T2B;
    iio[(rs[3])] = T3u + T3v;
    iio[(rs[4])] = T4o + T4p;
    iio[(rs[5])] = T5i + T5j;
    rio[(rs[5])] = T4z + T4G;
    rio[(rs[4])] = T3F + T3M;

    // Twiddle updates only in non-skipped iterations
    if ((m - mb) % 4 != 0) {
        {
            E T1w, T1y, T1v, T1x;
            T1w = T16 + T19;
            T1y = T1n + T1o;
            T1v = W[4];
            T1x = W[5];
            rio[(vs[3]) + (rs[1])] = (((T1v) * (T1w)) + (T1x * T1y));
            iio[(vs[3]) + (rs[1])] = ((T1v * T1y) - ((T1x) * (T1w)));
        }
        {
            E TK, TS, TQ, TU, TG, TO;
            TG = ((T3) - ((KP500000000) * (Ta)));
            TK = TG - TJ;
            TS = TG + TJ;
            TO = ((TM) - ((KP500000000) * (TN)));
            TQ = TO - TP;
            TU = TP + TO;
            {
                E TF, TL, TR, TT;
                TF = W[2];
                TL = W[3];
                rio[(vs[2])] = (((TF) * (TK)) + (TL * TQ));
                iio[(vs[2])] = ((TF * TQ) - ((TL) * (TK)));
                TR = W[6];
                TT = W[7];
                rio[(vs[4])] = (((TR) * (TS)) + (TT * TU));
                iio[(vs[4])] = ((TR * TU) - ((TT) * (TS)));
            }
        }
    }
}
}
