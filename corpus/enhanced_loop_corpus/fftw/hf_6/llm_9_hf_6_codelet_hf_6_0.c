#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *cr;
extern R *ci;
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
for (m = mb , W = W + ((mb - 1) * 10); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 10 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T7, TS, Tv, TO, Tt, TJ, Tx, TF, Ti, TI, Tw, TC;
    E Taux1, Taux2, Taux3, Taux4, Taux5;

    // Reduced arithmetic: precompute common factors
    const E k5 = KP500000000;
    const E k866 = KP866025403;

    T7 = cr[0] - (W[4]*cr[rs[3]] + W[5]*ci[rs[3]]);
    TS = (W[4]*ci[rs[3]] - W[5]*cr[rs[3]]) + ci[0];
    Tv = cr[0] + (W[4]*cr[rs[3]] + W[5]*ci[rs[3]]);
    TO = ci[0] - (W[4]*ci[rs[3]] - W[5]*cr[rs[3]]);

    Tt = (W[6]*cr[rs[4]] + W[7]*ci[rs[4]]) - (W[0]*cr[rs[1]] + W[1]*ci[rs[1]]);
    TJ = (W[6]*ci[rs[4]] - W[7]*cr[rs[4]]) + (W[0]*ci[rs[1]] - W[1]*cr[rs[1]]);
    Tx = (W[6]*cr[rs[4]] + W[7]*ci[rs[4]]) + (W[0]*cr[rs[1]] + W[1]*ci[rs[1]]);
    TF = (W[0]*ci[rs[1]] - W[1]*cr[rs[1]]) - (W[6]*ci[rs[4]] - W[7]*cr[rs[4]]);

    Ti = (W[2]*cr[rs[2]] + W[3]*ci[rs[2]]) - (W[8]*cr[rs[5]] + W[9]*ci[rs[5]]);
    TI = (W[2]*ci[rs[2]] - W[3]*cr[rs[2]]) + (W[8]*ci[rs[5]] - W[9]*cr[rs[5]]);
    Tw = (W[2]*cr[rs[2]] + W[3]*ci[rs[2]]) + (W[8]*cr[rs[5]] + W[9]*ci[rs[5]]);
    TC = (W[2]*ci[rs[2]] - W[3]*cr[rs[2]]) - (W[8]*ci[rs[5]] - W[9]*cr[rs[5]]);

    // Fused computation with fewer temporaries
    Taux1 = TC + TF;
    Taux2 = Ti + Tt;
    Taux3 = T7 - k5 * Taux2;
    ci[(rs[2])] = T7 + Taux2;
    cr[(rs[1])] = Taux3 + k866 * Taux1;
    ci[0] = Taux3 - k866 * Taux1;

    Taux4 = Tw + Tx;
    Taux5 = Tv - k5 * Taux4;
    cr[0] = Tv + Taux4;
    ci[(rs[1])] = Taux5 + k866 * (TI - TJ);
    cr[(rs[2])] = Taux5 - k866 * (TI - TJ);

    Taux1 = Tt - Ti;
    Taux2 = TF - TC;
    Taux3 = k5 * Taux2 + TO;
    cr[(rs[3])] = Taux2 - TO;
    ci[(rs[4])] = k866 * Taux1 + Taux3;
    cr[(rs[5])] = k866 * Taux1 - Taux3;

    Taux1 = Tw - Tx;
    Taux2 = TI + TJ;
    Taux3 = TS - k5 * Taux2;
    cr[(rs[4])] = k866 * Taux1 - Taux3;
    ci[(rs[5])] = Taux2 + TS;
    ci[(rs[3])] = k866 * Taux1 + Taux3;
}
}
