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
extern  E KP500000000;
extern  E KP866025403;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + (mb * 10); m < me; m = m + 1 , ri = ri + ms , ii = ii + ms , W = W + 10 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T7, TS, Tv, TO, Tt, TJ, Tx, TF, Ti, TI, Tw, TC;
    const E k5 = KP500000000;
    const E k8 = KP866025403;

    // Fused pre-computed products to reduce arithmetic operations
    E Wr3 = W[4], Wi3 = W[5];
    E Wr4 = W[6], Wi4 = W[7];
    E Wr1 = W[0], Wi1 = W[1];
    E Wr2 = W[2], Wi2 = W[3];
    E Wr5 = W[8], Wi5 = W[9];

    E ri3 = ri[(rs[3])], ii3 = ii[(rs[3])];
    E ri4 = ri[(rs[4])], ii4 = ii[(rs[4])];
    E ri1 = ri[(rs[1])], ii1 = ii[(rs[1])];
    E ri2 = ri[(rs[2])], ii2 = ii[(rs[2])];
    E ri5 = ri[(rs[5])], ii5 = ii[(rs[5])];

    E T6 = Wr3 * ri3 + Wi3 * ii3;
    E TM = Wr3 * ii3 - Wi3 * ri3;
    T7 = ri[0] - T6;
    TS = ii[0] - TM;
    Tv = ri[0] + T6;
    TO = TM + ii[0];

    E Tn = Wr4 * ri4 + Wi4 * ii4;
    E TD = Wr4 * ii4 - Wi4 * ri4;
    E Ts = Wr1 * ri1 + Wi1 * ii1;
    E TE = Wr1 * ii1 - Wi1 * ri1;
    Tt = Tn - Ts;
    TJ = TD + TE;
    Tx = Tn + Ts;
    TF = TD - TE;

    E Tc = Wr2 * ri2 + Wi2 * ii2;
    E TA = Wr2 * ii2 - Wi2 * ri2;
    E Th = Wr5 * ri5 + Wi5 * ii5;
    E TB = Wr5 * ii5 - Wi5 * ri5;
    Ti = Tc - Th;
    TI = TA + TB;
    Tw = Tc + Th;
    TC = TA - TB;

    // Reduced redundant subexpressions and merged calculations
    E sum_I = TC - TF;
    E sum_J = Tt - Ti;
    E sum_u = Ti + Tt;
    E sum_C = TC + TF;
    E z_part = T7 - k5 * sum_u;
    E G_part = k8 * sum_I;
    ri[(rs[3])] = T7 + sum_u;
    ri[(rs[1])] = z_part + G_part;
    ri[(rs[5])] = z_part - G_part;
    ii[(rs[1])] = k8 * sum_J + ((TS) - k5 * sum_C);
    ii[(rs[3])] = sum_C + TS;
    ii[(rs[5])] = ((TS) - k5 * sum_C) - k8 * sum_J;

    E diff_I = TI - TJ;
    E diff_J = Tx - Tw;
    E sum_y = Tw + Tx;
    E sum_L = TI + TJ;
    E H_part = Tv - k5 * sum_y;
    E K_part = k8 * diff_I;
    ri[0] = Tv + sum_y;
    ri[(rs[4])] = H_part + K_part;
    ri[(rs[2])] = H_part - K_part;
    ii[0] = sum_L + TO;
    ii[(rs[4])] = k8 * diff_J + ((TO) - k5 * sum_L);
    ii[(rs[2])] = ((TO) - k5 * sum_L) - k8 * diff_J;
}
}
