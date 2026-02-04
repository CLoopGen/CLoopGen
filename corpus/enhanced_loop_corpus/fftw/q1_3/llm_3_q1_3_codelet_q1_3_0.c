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
extern  E KP866025403;
extern  E KP500000000;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + (mb * 4); m < me; m = m + 1 , rio += ms , iio += ms , W += 4) {
    E T1, T4, T6, Tc, Td, Te, T9, Tf, Tl, To, Tq, Tw, Tx, Ty, Tt;
    E Tz, TR, TS, TN, TT, TF, TI, TK, TQ;
    E temp_r[6], temp_i[6];
    const INT idx_r1 = rs[1], idx_r2 = rs[2];
    const INT idx_v1 = vs[1], idx_v2 = vs[2];
    const INT offsets[6] = {0, idx_r1, idx_r2, idx_v1, idx_v1 + idx_r1, idx_v1 + idx_r2};
    const INT offsets2[6] = {0, idx_r1, idx_r2, idx_v2, idx_v2 + idx_r1, idx_v2 + idx_r2};

    for (INT k = 0; k < 6; ++k) {
        temp_r[k] = rio[offsets[k]];
        temp_i[k] = iio[offsets[k]];
    }
    for (INT k = 3; k < 6; ++k) {
        temp_r[k+3] = rio[idx_v2 + offsets[k-3]];
        temp_i[k+3] = iio[idx_v2 + offsets[k-3]];
    }

    T1 = temp_r[0]; T4 = temp_r[1] + temp_r[2];
    T6 = T1 - KP500000000 * T4;
    Tc = KP866025403 * (temp_r[2] - temp_r[1]);
    Td = temp_i[0]; Te = temp_i[1] + temp_i[2];
    T9 = KP866025403 * (temp_i[1] - temp_i[2]);
    Tf = Td - KP500000000 * Te;
    Tl = temp_r[3]; To = temp_r[4] + temp_r[5];
    Tq = Tl - KP500000000 * To;
    Tw = KP866025403 * (temp_r[5] - temp_r[4]);
    Tx = temp_i[3]; Ty = temp_i[4] + temp_i[5];
    Tt = KP866025403 * (temp_i[4] - temp_i[5]);
    Tz = Tx - KP500000000 * Ty;
    TR = temp_i[6]; TS = temp_i[7] + temp_i[8];
    TN = KP866025403 * (temp_i[7] - temp_i[8]);
    TT = TR - KP500000000 * TS;
    TF = temp_r[6]; TI = temp_r[7] + temp_r[8];
    TK = TF - KP500000000 * TI;
    TQ = KP866025403 * (temp_r[8] - temp_r[7]);

    rio[0] = T1 + T4;
    iio[0] = Td + Te;
    rio[idx_r1] = temp_r[4] + temp_r[5];
    iio[idx_r1] = temp_i[4] + temp_i[5];
    iio[idx_r2] = temp_i[7] + temp_i[8];
    rio[idx_r2] = temp_r[7] + temp_r[8];

    {
        E Ta = T6 + T9, Tg = Tc + Tf;
        rio[idx_v1] = W[0] * Ta + W[1] * Tg;
        iio[idx_v1] = W[0] * Tg - W[1] * Ta;
    }
    {
        E TW = TK - TN, TY = TT - TQ;
        rio[idx_v2 + idx_r2] = W[2] * TW + W[3] * TY;
        iio[idx_v2 + idx_r2] = W[2] * TY - W[3] * TW;
    }
    {
        E TC = Tq - Tt, TE = Tz - Tw;
        rio[idx_v2 + idx_r1] = W[2] * TC + W[3] * TE;
        iio[idx_v2 + idx_r1] = W[2] * TE - W[3] * TC;
    }
    {
        E Tu = Tq + Tt, TA = Tw + Tz;
        rio[idx_v1 + idx_r1] = W[0] * Tu + W[1] * TA;
        iio[idx_v1 + idx_r1] = W[0] * TA - W[1] * Tu;
    }
    {
        E TO = TK + TN, TU = TQ + TT;
        rio[idx_v1 + idx_r2] = W[0] * TO + W[1] * TU;
        iio[idx_v1 + idx_r2] = W[0] * TU - W[1] * TO;
    }
    {
        E Ti = T6 - T9, Tk = Tf - Tc;
        rio[idx_v2] = W[2] * Ti + W[3] * Tk;
        iio[idx_v2] = W[2] * Tk - W[3] * Ti;
    }
}
}
