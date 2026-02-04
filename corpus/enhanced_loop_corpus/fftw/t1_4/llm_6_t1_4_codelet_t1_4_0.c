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
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + (mb * 6); m < me; m = m + 1 , ri = ri + ms , ii = ii + ms , W = W + 6 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, Tp, T6, To, Tc, Tk, Th, Tl;
    T1 = ri[0];
    Tp = ii[0];

    // Introduce temporary variables to break and restructure dependencies
    E W2 = W[2], W3 = W[3], W0 = W[0], W1 = W[1], W4 = W[4], W5 = W[5];
    E ri2 = ri[(rs[2])], ii2 = ii[(rs[2])];
    E ri1 = ri[(rs[1])], ii1 = ii[(rs[1])];
    E ri3 = ri[(rs[3])], ii3 = ii[(rs[3])];

    // Restructure computations to remove immediate RAW dependencies
    T6 = (W2 * ri2) + (W3 * ii2);
    To = (W2 * ii2) - (W3 * ri2);

    Tc = (W0 * ri1) + (W1 * ii1);
    Tk = (W0 * ii1) - (W1 * ri1);

    Th = (W4 * ri3) + (W5 * ii3);
    Tl = (W4 * ii3) - (W5 * ri3);

    // Regroup final updates with modified dependency order
    E sum_T1_T6 = T1 + T6;
    E sum_Tc_Th = Tc + Th;
    ri[(rs[2])] = sum_T1_T6 - sum_Tc_Th;
    ri[0] = sum_T1_T6 + sum_Tc_Th;

    E sum_Tk_Tl = Tk + Tl;
    E sum_To_Tp = To + Tp;
    ii[0] = sum_Tk_Tl + sum_To_Tp;
    ii[(rs[2])] = sum_To_Tp - sum_Tk_Tl;

    E diff_T1_T6 = T1 - T6;
    E diff_Tk_Tl = Tk - Tl;
    ri[(rs[3])] = diff_T1_T6 - diff_Tk_Tl;
    ri[(rs[1])] = diff_T1_T6 + diff_Tk_Tl;

    E diff_Tp_To = Tp - To;
    E diff_Tc_Th = Tc - Th;
    ii[(rs[1])] = diff_Tp_To - diff_Tc_Th;
    ii[(rs[3])] = diff_Tc_Th + diff_Tp_To;
}
}
