#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *Rp;
extern R *Ip;
extern R *Rm;
extern R *Im;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 6); m < me; m = m + 1 , Rp = Rp + ms , Ip = Ip + ms , Rm = Rm - ms , Im = Im - ms , W = W + 6 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, Tp, T6, To, Tc, Tk, Th, Tl;
    T1 = Rp[0];
    Tp = Rm[0];

    // Introduce temporary variables to break and restructure RAW/WAW dependencies
    // Use delayed assignment to create new dependency chains

    E T2 = W[2], T4 = W[3], T3 = Rp[(rs[1])], T5 = Rm[(rs[1])];
    E T8 = W[0], Ta = W[1], T9 = Ip[0], Tb = Im[0];
    E Td = W[4], Tf = W[5], Te = Ip[(rs[1])], Tg = Im[(rs[1])];

    // Regroup computations to change evaluation order while preserving semantics
    E T6_part1 = T2 * T3;
    E T6_part2 = T4 * T5;
    T6 = T6_part1 + T6_part2;
    E To_part1 = T2 * T5;
    E To_part2 = T4 * T3;
    To = To_part1 - To_part2;

    E Tc_part1 = T8 * T9;
    E Tc_part2 = Ta * Tb;
    Tc = Tc_part1 + Tc_part2;
    E Tk_part1 = T8 * Tb;
    E Tk_part2 = Ta * T9;
    Tk = Tk_part1 - Tk_part2;

    E Th_part1 = Td * Te;
    E Th_part2 = Tf * Tg;
    Th = Th_part1 + Th_part2;
    E Tl_part1 = Td * Tg;
    E Tl_part2 = Tf * Te;
    Tl = Tl_part1 - Tl_part2;

    // Delayed updates with intermediate sums to alter data flow
    E sum_T1_T6 = T1 + T6;
    E sum_Tc_Th = Tc + Th;
    E sum_Tk_Tl = Tk + Tl;
    E sum_To_Tp = To + Tp;

    Rm[(rs[1])] = sum_T1_T6 - sum_Tc_Th;
    Rp[0] = sum_T1_T6 + sum_Tc_Th;
    Im[(rs[1])] = sum_Tk_Tl - sum_To_Tp;
    Ip[0] = sum_Tk_Tl + sum_To_Tp;

    E diff_T1_T6 = T1 - T6;
    E diff_Tk_Tl = Tk - Tl;
    E diff_Th_Tc = Th - Tc;
    E diff_Tp_To = Tp - To;

    Rm[0] = diff_T1_T6 - diff_Tk_Tl;
    Rp[(rs[1])] = diff_T1_T6 + diff_Tk_Tl;
    Im[0] = diff_Th_Tc - diff_Tp_To;
    Ip[(rs[1])] = diff_Th_Tc + diff_Tp_To;
}
}
